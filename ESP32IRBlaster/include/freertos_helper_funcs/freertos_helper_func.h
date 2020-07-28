#ifndef _FREERTOS_HELPER_FUNC_H
#define _FREERTOS_HELPER_FUNC_H

// General ESP32 OS and system stuff :)
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

// LWIP wifi stuff
#include "lwip/err.h"
#include "lwip/sys.h"

#define thdDelayMs(milliseconds) vTaskDelay(milliseconds/portTICK_PERIOD_MS)

/*
*   brief: allows us to delay our thread in the period of seconds
*   parametsr: seconds as an unsigned integer(of any size)
*/
#define thdDelayS(seccond) vTaskDelay((seconds * 1000)/portTICK_PERIOD_MS)

#endif