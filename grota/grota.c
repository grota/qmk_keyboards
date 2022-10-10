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

__attribute__ ((weak)) void matrix_init_keymap(void) {}

void matrix_init_user(void) {
  matrix_init_keymap();
};

__attribute__ ((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
#ifdef LEADER_ENABLE
  matrix_scan_user_leader();
#endif
  matrix_scan_keymap();
};

__attribute__ ((weak)) layer_state_t layer_state_set_keymap (layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return layer_state_set_keymap (state);
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
}

