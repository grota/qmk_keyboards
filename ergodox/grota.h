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
  CUSTOM_RGB_CYCLE = SAFE_RANGE, // can always be here
};

typedef union {
  uint32_t raw;
  struct {
  };
} userspace_config_t;
extern userspace_config_t userspace_config;
