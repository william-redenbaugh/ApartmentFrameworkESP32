/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.2-dev */

#ifndef PB_TEMP_HUM_PB_H_INCLUDED
#define PB_TEMP_HUM_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _TempuratureHumidityMessage {
    float tempurature_c;
    float humiditiy_relative;
    bool valid_data;
} TempuratureHumidityMessage;


/* Initializer values for message structs */
#define TempuratureHumidityMessage_init_default  {0, 0, 0}
#define TempuratureHumidityMessage_init_zero     {0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define TempuratureHumidityMessage_tempurature_c_tag 1
#define TempuratureHumidityMessage_humiditiy_relative_tag 2
#define TempuratureHumidityMessage_valid_data_tag 3

/* Struct field encoding specification for nanopb */
#define TempuratureHumidityMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    tempurature_c,     1) \
X(a, STATIC,   SINGULAR, FLOAT,    humiditiy_relative,   2) \
X(a, STATIC,   SINGULAR, BOOL,     valid_data,        3)
#define TempuratureHumidityMessage_CALLBACK NULL
#define TempuratureHumidityMessage_DEFAULT NULL

extern const pb_msgdesc_t TempuratureHumidityMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define TempuratureHumidityMessage_fields &TempuratureHumidityMessage_msg

/* Maximum encoded size of messages (where known) */
#define TempuratureHumidityMessage_size          12

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif