
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
inline void setup_flash();

// Since the esp-idf is technically C and not cpp. 
extern "C" void app_main(void) {
    setup_esp32_subsystems();
}

inline void setup_esp32_subsystems(void){
    // Setting up flash module 
    setup_flash();

    // Setup ESP event loop defaults
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    // Setting up esp32 wifi subsystemss
    void setup_esp32_wifi(void);
}

inline void setup_flash(void){
    // Setting up our non volatile flash system in the esp32
    
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}