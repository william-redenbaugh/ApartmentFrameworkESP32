
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

// ESP32 spi flash and self libraries. 
#include "esp_system.h"
#include "esp_spi_flash.h"

// Since the esp-idf is technically C and not cpp. 
extern "C" void app_main(void) {
    
}