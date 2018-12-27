#pragma once

#include "rgb_matrix.h"

enum rgb_matrix_effects_user {
  RGB_MATRIX_LAYER_INDICATOR = RGB_MATRIX_EFFECT_MAX,
  RGB_MATRIX_EFFECT_MAX_NEW
};

bool process_record_user_rgb(uint16_t keycode, keyrecord_t *record);
void eeconfig_update_rgb_matrix(uint32_t val);
uint8_t increment( uint8_t value, uint8_t step, uint8_t min, uint8_t max );
uint8_t decrement( uint8_t value, uint8_t step, uint8_t min, uint8_t max );
void rgb_matrix_layer_indicator_custom(void);
