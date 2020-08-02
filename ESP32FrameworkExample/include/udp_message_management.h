#ifndef _UDP_MESSAGE_MANAGEMENT_H
#define _UDP_MESSAGE_MANAGEMENT_H

#include <Arduino.h> 
#include <WiFi.h> 
#include <WiFiUdp.h> 
#include <lwip/sockets.h>
#include <lwip/netdb.h>
#include <errno.h>


// Constructor and destructor for our
// message management stuff!
void start_message_management(void);
void end_message_management_thread(void);

#endif 
