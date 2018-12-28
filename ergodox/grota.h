#pragma once

#if defined(RGB_MATRIX_ENABLE)
  #include "rgb_matrix.h"
#endif

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTRL)|MOD_BIT(KC_RCTRL))
#define SHIFT_IS_PRESSED modifiers & MODS_SHIFT_MASK || one_shot & MODS_SHIFT_MASK
#define RALT_IS_PRESSED modifiers & MOD_BIT(KC_RALT) || one_shot & MOD_BIT(KC_RALT) || weak_mods & MOD_BIT(KC_RALT)
#define CTRL_IS_PRESSED modifiers & MODS_CTRL_MASK || weak_mods & MODS_CTRL_MASK || one_shot & MODS_CTRL_MASK
#define TD_SQBRKTL TD(TD_SQUARE_BRACKET_L)
#define TD_SQBRKTR TD(TD_SQUARE_BRACKET_R)
#define TD_SPECIAL_LEAD TD(TD_SPECIAL_LEAD_MOVE_TO_LAYER)
#define TD_COLON_CTRL TD(TD_COLON_SEMI_CTRL)

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
