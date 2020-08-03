#include <Arduino.h>
#include "udp_message_management.h"
#include "wifi_setup.h"
#include "LiquidCrystal_I2C.h"

void subroutine_test(MessageReq *msg_req_ptr){
  Serial.println("message recieved!");
}

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to wifi...");
  wifi_connect();
  Serial.println("connected!");

  Serial.print("Starting up message management thread...");
  start_message_management();
  Serial.println("complete!");

  add_subroutine_check(MessageData_MessageType_MATRIX_DATA, &subroutine_test);
}

void loop() {
  vTaskDelete(NULL);
}
