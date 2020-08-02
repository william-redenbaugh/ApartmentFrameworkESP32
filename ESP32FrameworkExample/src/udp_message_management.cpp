#include "udp_message_management.h"

// Constructor and destructor for our
// message management stuff!
void start_message_management(void);
void end_message_management_thread(void);

void create_udp_server(void);
void udp_management_thread(void *parameters); 
void check_new_data(void);

#define SERVER_PORT 4040

// To prevent ourselves from having too many local variables, we put them all 
// In a single struct
struct {
    TaskHandle_t task_handle;   // Handler for our udp reading task. 
    int socket_handle = -1;     // Handler ID for our UDP socket 
    uint8_t rx_buff[7000];      // Buffer of information that we store our socket info into. 
}msg_manage;

/* 
* @brief General call that will let us deal with all of our message management stuff
* @notes Should generally be called at begining of runtime, before other subsytems are generated. 
* params none
* returns none
*/
void start_message_management(void){
    
    create_udp_server();

    // Start up UDP Management thread!
    xTaskCreatePinnedToCore(
      udp_management_thread,        /* Function to implement the task */
      "Message Management Thread",  /* Name of the task */
      10000,                        /* Stack size in words */
      NULL,                         /* Task input parameter */
      32,                           /* Priority of the task */
      &msg_manage.task_handle,      /* Task handle. */
      1);                           /* Core where the task should run */
}

/* 
* @brief General call that will let us deal with all of our message management stuff
* @notes Should generally be called at begining of runtime, before other subsytems are generated. 
* params none
* returns none
*/
void create_udp_server(void){
    // Generate our socket
    if((msg_manage.socket_handle = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
        log_e("Socket couldn't be generated");
    }

    int yes = 1; 
    // Enable certain socket options
    if(setsockopt(msg_manage.socket_handle, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0){
        log_e("Couldn't set the socket option %d", errno);
        close(msg_manage.socket_handle);
    }

    // Set oursleves to any particular IP address!
    IPAddress address = IPAddress(INADDR_ANY); 
    // Createing our input socket stuff
    struct sockaddr_in addr;
    memset((char *) &addr, 0, sizeof(addr));
    
    // Putting all of our port and address information into the right spot 
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = (in_addr_t)address;
    
    // Bind our socket should everything work as expected. 
    if(bind(msg_manage.socket_handle , (struct sockaddr*)&addr, sizeof(addr)) == -1){
        log_e("could not bind socket: %d", errno);
        close(msg_manage.socket_handle);
        return;
    }
    // Manipulates our file descriptor of our UDP socket. 
    fcntl(msg_manage.socket_handle, F_SETFL, O_NONBLOCK);
}

/* 
* @brief General call that will let us deal with all of our message management stuff
* @notes Should generally be called at begining of runtime, before other subsytems are generated. 
* params none
* returns none
*/
void end_message_management(void){
    close(msg_manage.socket_handle);
    // Deletes the UDP server. 
    vTaskDelete(msg_manage.task_handle);
}
    
/* 
* @brief General call that will let us deal with all of our message management stuff
* @notes Should generally be called at begining of runtime, before other subsytems are generated. 
* params none
* returns none
*/
void udp_management_thread(void *parameters){
    TickType_t start_loop; 

    for(;;){
        start_loop = xTaskGetTickCount();

        check_new_data();

        // Let program run every 70 milliseconds
        vTaskDelayUntil(&start_loop, 100/portTICK_PERIOD_MS);
    }   
}

/* 
* @brief Whenever we are checking for new data, it's placed here 
* @notes Called in the thread. 
* params none
* returns none
*/
void check_new_data(void){
    struct sockaddr_in rev_addr; 
    int slen = 0; 
    int len = recvfrom( msg_manage.socket_handle,       // Handler that contains our Socket ID
                        msg_manage.rx_buff,             // Buffer that we will put our socket information into
                        sizeof(msg_manage.rx_buff),     // Size of the buffer that we are giving to the socket
                        MSG_DONTWAIT,                   // Don't block until message has received, just keep through
                        (struct sockaddr *) &rev_addr,  // Place where we can save the address that sends us our information
                        (socklen_t *)&slen);            // Length of the socket packet. 
    // Minimum message size is the messagedata header packet. 
    if(len >= 16){

    }
}