
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

void setup_esp32_subsystems(void);

// Since the esp-idf is technically C and not cpp. 
extern "C" void app_main(void) {
    
}

inline void setup_esp32_subsystems(void){
    // Setting up our non volatile flash system in the esp32
    ESP_ERROR_CHECK(nvs_flash_init());
    tcpip_adapter_init();
    ESP_ERROR_CHECK(esp_event_loop_create_default());
}