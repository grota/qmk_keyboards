/*
Copyright 2019 Giuseppe Rota <rota.giuseppe@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "quantum.h"
#include "version.h"

#include "process_records.h"

#ifdef RGB_MATRIX_ENABLE
  #include "rgb_stuff.h"
#endif

#ifdef LEADER_ENABLE
#include "leader_stuff.h"
#endif

#ifdef TAP_DANCE_ENABLE
#include "tap_dance.h"
#endif

/* Define layer names */
enum userspace_layers {
  _BASE = 0,
  _FN_AND_MOUSE,
};

#define SFT_CTL(kc)  (QK_LCTL | QK_LSFT | (kc))

#define SHIFT_IS_PRESSED modifiers & MOD_MASK_SHIFT || one_shot & MOD_MASK_SHIFT || weak_mods & MOD_MASK_SHIFT
#define RALT_IS_PRESSED modifiers & MOD_BIT(KC_RALT) || one_shot & MOD_BIT(KC_RALT) || weak_mods & MOD_BIT(KC_RALT)
#define CTRL_IS_PRESSED modifiers & MOD_MASK_CTRL || weak_mods & MOD_MASK_CTRL || one_shot & MOD_MASK_CTRL

//how long before a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 150

#undef DEBOUNCE
#define DEBOUNCE 4

#define MOUSEKEY_DELAY       0
#define MOUSEKEY_WHEEL_DELAY 0

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 13

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 30

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 30

#ifdef CONSOLE_ENABLE
#define NO_DEBUG
#define USER_PRINT
#endif

#ifdef RGB_MATRIX_ENABLE
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_CYCLE_ALL

#define RGBLIGHT_SLEEP

#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 128
#endif

#ifdef LEADER_ENABLE
#define LEADER_TIMEOUT 250
// So far not needed, my leader mappings have one key only.
//#define LEADER_PER_KEY_TIMING
#endif

#ifdef TAP_DANCE_ENABLE
// Taps must happen in this interval to get recognized (and trigger move to layer 2 with 2 taps).
// This can be huge due to the implementation.
//#define DANCING_TERM_SPECIAL_LEAD 370
// Taps must happen in this interval to get recognized (and trigger ? with 2 taps).
//#define DANCING_TERM_SLASH_QUESTION_MARK_RALT 370
// Taps must happen in this interval to get recognized (and trigger : with 2 taps).
//#define DANCING_TERM_COLON_SEMI 370
#endif

#ifdef TAP_DANCE_ENABLE
#define TD_SQBRKTL TD(TD_SQUARE_BRACKET_L)
#define TD_SQBRKTR TD(TD_SQUARE_BRACKET_R)
//#define TD_SPECIAL_LEAD TD(TD_LEAD_MOVE_TO_LAYER_LALT)
//#define TD_COLON TD(TD_COLON_SEMI)
//#define TD_SLASH_RALT TD(TD_SLASH_QUESTION_MARK_RALT)
#endif

typedef union {
  uint32_t raw;
  struct {
  };
} userspace_config_t;
extern userspace_config_t userspace_config;
