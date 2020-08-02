#ifndef _PROTO_MSG_UNPACK_H
#define _PROTO_MSG_UNPACK_H

// Arduino standard library
#include <Arduino.h> 

// Nanopb serialization and deserialization stuff
#include <pb.h> 
#include <pb_common.h> 
#include <pb_decode.h> 
#include <pb_encode.h> 

// Our Protobuffer Messages!
#include "clock_program.pb.h"
#include "message_return_status.pb.h"
#include "messagedata.pb.h"
#include "relay_msg.pb.h"
#include "temp_hum.pb.h"

inline MessageData unpack_message_data(uint8_t *arr, uint32_t len);
inline TempuratureHumidityMessage unpack_temp_humd_data(uint8_t *arr, uint32_t len); 
inline RelayMessage unpack_relay_msg(uint8_t *arr, uint32_t len);

#endif 