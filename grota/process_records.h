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
#include "grota.h"

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
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
  KC_MEDIA_UP,
  KC_MEDIA_DOWN,
  KC_TAB_CTRLC,
  KC_ARROW,
};
