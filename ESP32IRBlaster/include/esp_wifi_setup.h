#ifndef _ESP_WIFI_SETUP_H
#define _ESP_WIFI_SETUP_H

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

// ESP32 spi flash and self libraries. 
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "tcpip_adapter.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

// General Lwip stack libraries 
#include "lwip/err.h"
#include "lwip/sockets.h"
#include "lwip/sys.h"
#include <lwip/netdb.h>

#endif