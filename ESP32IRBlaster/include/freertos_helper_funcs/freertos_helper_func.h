#ifndef _FREERTOS_HELPER_FUNC_H
#define _FREERTOS_HELPER_FUNC_H

// Our real time operating system stuff, quite a bit here huh
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"
#include "freertos/ringbuf.h"

/*
*   brief: allows us to delay our thread in the period of milliseconds
*   parametsr: milliseconds as an unsigned integer(of any size)
*/
#define thdDelayMs(milliseconds) vTaskDelay(milliseconds/portTICK_PERIOD_MS)

/*
*   brief: allows us to delay our thread in the period of seconds
*   parametsr: seconds as an unsigned integer(of any size)
*/
#define thdDelayS(seccond) vTaskDelay((seconds * 1000)/portTICK_PERIOD_MS)

#endif