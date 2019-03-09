#pragma once

#if defined(RGB_MATRIX_ENABLE)
  #include "rgb_matrix.h"
#endif

#define SFT_CTL(kc)  (QK_LCTL | QK_LSFT | (kc))

#define SHIFT_IS_PRESSED modifiers & MOD_MASK_SHIFT || one_shot & MOD_MASK_SHIFT || weak_mods & MOD_MASK_SHIFT
#define RALT_IS_PRESSED modifiers & MOD_BIT(KC_RALT) || one_shot & MOD_BIT(KC_RALT) || weak_mods & MOD_BIT(KC_RALT)
#define CTRL_IS_PRESSED modifiers & MOD_MASK_CTRL || weak_mods & MOD_MASK_CTRL || one_shot & MOD_MASK_CTRL

#ifdef TAP_DANCE_ENABLE
#define TD_SQBRKTL TD(TD_SQUARE_BRACKET_L)
#define TD_SQBRKTR TD(TD_SQUARE_BRACKET_R)
//#define TD_SPECIAL_LEAD TD(TD_LEAD_MOVE_TO_LAYER_LALT)
//#define TD_COLON TD(TD_COLON_SEMI)
//#define TD_SLASH_RALT TD(TD_SLASH_QUESTION_MARK_RALT)
#endif

enum userspace_layers {
  _BASE = 0,
  _FN_AND_MOUSE,
};

enum custom_keycodes {
  CUSTOM_RGB_CYCLE = SAFE_RANGE, // can always be here
  KC_ESC_GRAVE,
  KC_C_1,
  KC_C_2,
  KC_C_3,
  KC_C_4,
  KC_C_5,
  KC_C_6,
  KC_C_7,
  KC_C_8,
  KC_C_9,
  KC_C_0,
};

typedef union {
  uint32_t raw;
  struct {
  };
} userspace_config_t;
extern userspace_config_t userspace_config;
