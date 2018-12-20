#pragma once

#if defined(RGB_MATRIX_ENABLE)
  #include "rgb_matrix.h"
#endif

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))

enum userspace_layers {
  _BASE = 0,
  _FN_AND_MOUSE,
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE, // can always be here
  KC_RGB_LYR_IND,
};

typedef union {
  uint32_t raw;
  struct {
    bool rgb_layer_change :1;
  };
} userspace_config_t;
extern userspace_config_t userspace_config;
