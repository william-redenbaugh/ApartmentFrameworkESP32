/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.2-dev */

#ifndef PB_RELAY_MSG_PB_H_INCLUDED
#define PB_RELAY_MSG_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _RelayMessage {
    bool en;
} RelayMessage;


/* Initializer values for message structs */
#define RelayMessage_init_default                {0}
#define RelayMessage_init_zero                   {0}

/* Field tags (for use in manual encoding/decoding) */
#define RelayMessage_en_tag                      1

/* Struct field encoding specification for nanopb */
#define RelayMessage_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     en,                1)
#define RelayMessage_CALLBACK NULL
#define RelayMessage_DEFAULT NULL

extern const pb_msgdesc_t RelayMessage_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define RelayMessage_fields &RelayMessage_msg

/* Maximum encoded size of messages (where known) */
#define RelayMessage_size                        2

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
