#include "udp_messaging_main.h"

#define UDP_MESSAGE_THREAD_STACK_SIZE 4096
#define UDP_PORT 4050

static const char *TAG = "example";

// Structure that will hold the TCB of the task being created.
StaticTask_t xTaskBuffer;
// Stack buffer set asside somewhere.
StackType_t xStack[UDP_MESSAGE_THREAD_STACK_SIZE];

extern void start_udp_server_thread_subroutines(void);
inline sockaddr_in create_default_addr(void);

/*
* @brief Udp server thread that sets up and uses our server stuff.  
*/
static void udp_server_thread(void *parameters){
    char rx_buffer[128];
    char addr_str[128];
    int addr_family = AF_INET;
    int ip_protocol = IPPROTO_IP;
    
    struct sockaddr_in dest_addr = create_default_addr();
    inet_ntoa_r(dest_addr.sin_addr, addr_str, sizeof(addr_str) - 1);

    int sock = socket(addr_family, SOCK_DGRAM, ip_protocol);
        if (sock < 0) {
            ESP_LOGE(TAG, "Unable to create socket: errno %d", errno);
            sock = -1;
        }
        ESP_LOGI(TAG, "Socket created");

        int err = bind(sock, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (err < 0) {
            ESP_LOGE(TAG, "Socket unable to bind: errno %d", errno);
        }
        ESP_LOGI(TAG, "Socket bound, port %d", UDP_PORT);
   
    // Can the compiler stop throwing errors for one seccond plz 
    (void)parameters;
    for(;;){

        struct sockaddr_in6 source_addr; // Large enough for both IPv4 or IPv6
            socklen_t socklen = sizeof(source_addr);
            int len = recvfrom(sock, rx_buffer, sizeof(rx_buffer) - 1, 0, (struct sockaddr *)&source_addr, &socklen);

            // Error occurred during receiving
            if (len < 0) {
                ESP_LOGE(TAG, "recvfrom failed: errno %d", errno);
                break;
            }
            // Data received
            else {
                // Get the sender's ip address as string
                if (source_addr.sin6_family == PF_INET) {
                    inet_ntoa_r(((struct sockaddr_in *)&source_addr)->sin_addr.s_addr, addr_str, sizeof(addr_str) - 1);
                } else if (source_addr.sin6_family == PF_INET6) {
                    inet6_ntoa_r(source_addr.sin6_addr, addr_str, sizeof(addr_str) - 1);
                }

                rx_buffer[len] = 0; // Null-terminate whatever we received and treat like a string...
                ESP_LOGI(TAG, "Received %d bytes from %s:", len, addr_str);
                ESP_LOGI(TAG, "%s", rx_buffer);

                int err = sendto(sock, rx_buffer, len, 0, (struct sockaddr *)&source_addr, sizeof(source_addr));
                if (err < 0) {
                    ESP_LOGE(TAG, "Error occurred during sending: errno %d", errno);
                    break;
                }
            }
        thdDelayMs(1000);
    }

    if (sock != -1) {
            ESP_LOGE(TAG, "Shutting down socket and restarting...");
            shutdown(sock, 0);
            close(sock);
    }

    vTaskDelete(NULL);
}

/*
* @brief allows us to setup our udp server and our thread subroutines 
*/
extern void start_udp_server_thread_subroutines(void){
    // Generate our UDP control thread
    xTaskCreateStaticPinnedToCore(
        udp_server_thread, 
        "UDP Server Thread", 
        UDP_MESSAGE_THREAD_STACK_SIZE, 
        (void*)1, 
        tskIDLE_PRIORITY, 
        xStack, 
        &xTaskBuffer, 
        0);
}

inline sockaddr_in create_default_addr(void){
    struct sockaddr_in dest_addr;
    dest_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(UDP_PORT);
    return dest_addr;    
}