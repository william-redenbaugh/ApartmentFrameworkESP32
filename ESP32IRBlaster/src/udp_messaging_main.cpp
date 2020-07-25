#include "udp_messaging_main.h"

#define UDP_MESSAGE_THREAD_STACK_SIZE 4096

// Structure that will hold the TCB of the task being created.
StaticTask_t xTaskBuffer;
// Stack buffer set asside somewhere.
StackType_t xStack[UDP_MESSAGE_THREAD_STACK_SIZE];

extern void start_udp_server_thread_subroutines(void);

/*
* @brief Udp server thread that sets up and uses our server stuff.  
*/
static void udp_server_thread(void *parameters){

    // Can the compiler stop throwing errors for one seccond plz 
    (void)parameters;
    for(;;){
        thdDelayMs(1000);
    }
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