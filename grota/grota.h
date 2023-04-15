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

#define INITIAL_DEFAULT_ROW 100

/* Define layer names */
enum userspace_layers {
  _BASE = 0,
  _LAYER_MOUSE,
  _LAYER_MEDIA,
};

typedef union {
  uint32_t raw;
  struct {};
} userspace_config_t;
extern userspace_config_t userspace_config;

bool row_belongs_to_current_keyboard_hand(uint8_t row);
