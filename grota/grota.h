/*
Copyright 2023 Giuseppe Rota <rota.giuseppe@gmail.com>

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

#ifdef SPLIT_KEYBOARD
#define INITIAL_DEFAULT_ROW 100

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)
#define REPEAT_GROTA_X_FOR_LAYERS                                              \
  GROTA_X(BASE, _LAYER_BASE, "Base")                                           \
  GROTA_X(MOUSE, _LAYER_MOUSE, "Mouse")                                        \
  GROTA_X(SYM, _LAYER_SYM, "Symbols")                                          \
  GROTA_X(MEDIA, _LAYER_MEDIA, "Media")                                        \
  GROTA_X(NUMBERS, _LAYER_NUMBERS, "Numbers")
#endif

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
#define GROTA_X(LAYER_NAME, LAYER_ID, DESC) LAYER_ID,
  REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
};

#define LT_TAB_SYMBOLS LT(_LAYER_SYM, KC_TAB)
#define LT_ESC_MOUSE LT(_LAYER_MOUSE, KC_ESC)
#define LT_ENTER_NUMBERS LT(_LAYER_NUMBERS, KC_ENTER)
#define LT_QUOTE_MEDIA LT(_LAYER_MEDIA, KC_QUOTE)

#define KC_ORIGIN KC_NO

bool row_belongs_to_current_keyboard_hand(uint8_t row);
