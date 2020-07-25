#ifndef _UDP_MESSAGING_MAIN_H
#define _UDP_MESSAGING_MAIN_H


// Data serializing and deserialization protobuffer stuff
#include "pb.h"
#include "pb_common.h"
#include "pb_encode.h"
#include "pb_decode.h"

// Our real time operating system stuff, quite a bit here huh
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/ringbuf.h"

// Standard IO libraries 
#include <stdio.h>
#include "sdkconfig.h"
#include <string.h>

// ESP32 spi flash and self libraries. 
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include <sys/param.h>
#include "nvs_flash.h"

// Webstack
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

// Our own libraries
#include "freertos_helper_funcs/freertos_helper_func.h"

extern void start_udp_server_thread_subroutines(void);

#endif
