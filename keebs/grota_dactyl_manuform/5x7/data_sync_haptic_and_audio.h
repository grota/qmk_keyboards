#pragma once
#include "audio.h"
#include "haptic.h"
#include "quantum.h"
#include "transactions.h"

extern audio_config_t audio_config;
extern haptic_config_t haptic_config;

typedef struct _master_to_slave_t {
  uint8_t audioraw;
  uint32_t hapticraw;
} master_to_slave_t;
void haptic_and_audio_slave_handler(uint8_t in_buflen, const void *in_data,
                                    uint8_t out_buflen, void *out_data);

void send_to_slave_haptic_and_audio_state(void);
