#pragma once
#include "grota.h"

bool process_record_prepare_space_cadet_var(uint16_t keycode, keyrecord_t *record);

void matrix_scan_play_audio_when_mods_are_hold(void);

void layer_state_set_play_audio_based_on_layer(layer_state_t state);
