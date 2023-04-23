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
#include "grota.h"
#include "qmk_firmware/quantum/quantum_keycodes.h"

#if defined(KEYMAP_SAFE_RANGE)
#define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

#define ALL_SPACE_CADET_KEYS                                                   \
  QK_SPACE_CADET_LEFT_CTRL_PARENTHESIS_OPEN... QK_SPACE_CADET_RIGHT_SHIFT_ENTER

enum userspace_custom_keycodes {
  KC_INITIAL = SAFE_RANGE,
#ifdef GROTA_ENABLE_ESC_GRAVE
  KC_ESC_GRAVE,
#endif

#ifdef GROTA_ENABLE_NUMBERS_FN_KC
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
#endif

#ifdef GROTA_ENABLE_INVERTED_SHIFT_US_ANSI
  KC_C_UNDS,
  KC_C_PLUS,
  KC_C_LCBR,
  KC_C_RCBR,
  KC_C_PIPE,
  KC_C_UNUSED_1,
  KC_C_COLN,
  KC_C_DQUO,
  KC_C_TILD,
  KC_C_LABK,
  KC_C_RABK,
  KC_C_QUES,
#endif

#ifdef GROTA_CUSTOM_MEDIA_KC
  KC_MEDIA_UP,
  KC_MEDIA_DOWN,
#endif
#ifdef GROTA_DEFINE_ARROW
  KC_ARROW,
#endif

#ifdef GROTA_DEFINE_PRINT_HAPTIC
  KC_PRNT_HPT,
#else
#define KC_PRNT_HPT KC_NO
#endif
};
