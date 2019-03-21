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

#include "grota.h"

userspace_config_t userspace_config;

__attribute__ ((weak))
void matrix_init_keymap(void) {}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  userspace_config.raw = eeconfig_read_user();
  matrix_init_keymap();
};

void eeconfig_init_user(void) {
  userspace_config.raw = 0;
  eeconfig_update_user(userspace_config.raw);
}

__attribute__ ((weak))
void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
  static bool has_ran_yet;
  if (!has_ran_yet) {
    has_ran_yet = true;
    // defined as weak in quantum/quantum.c
    startup_user();
  }
#ifdef LEADER_ENABLE
  matrix_scan_user_leader();
#endif
  matrix_scan_keymap();
};

__attribute__ ((weak))
uint32_t layer_state_set_keymap (uint32_t state) {
  return state;
}

uint32_t layer_state_set_user(uint32_t state) {
  return layer_state_set_keymap (state);
}
