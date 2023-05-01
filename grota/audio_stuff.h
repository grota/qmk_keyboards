#pragma once
#include "grota.h"

bool process_record_prepare_space_cadet_var(uint16_t keycode,
                                            keyrecord_t *record);

void matrix_scan_play_audio_when_mods_are_hold(void);

void layer_state_set_play_audio_based_on_layer(layer_state_t state);

// Statically declare the number of lines to 2 (first [2]) in order to be able
// to call PLAY_SONG(layer_song_##LAYER_ID) from another compilation unit.
#define GROTA_X(LAYER_ID, DESC) float layer_song_##LAYER_ID[2][2];
REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
