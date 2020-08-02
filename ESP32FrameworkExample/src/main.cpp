#include <Arduino.h>
#include "udp_message_management.h"
#include "wifi_setup.h"

void setup() {
  wifi_connect();
  start_message_management();
}

void loop() {
  vTaskDelete(NULL);
}