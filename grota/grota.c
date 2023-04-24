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

#include "grota.h"

// START: *_user functions call *_keymap functions.
// qmk core calls *_user functions, we call weak *_keymap functions to provide
// an extra layer of overrideability.
__attribute__((weak)) void matrix_init_keymap(void) {}

void matrix_init_user(void) { matrix_init_keymap(); };

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
#ifdef LEADER_ENABLE
  matrix_scan_user_leader();
#endif
  matrix_scan_keymap();
};

__attribute__((weak)) layer_state_t
layer_state_set_keymap(layer_state_t state) {
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return layer_state_set_keymap(state);
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void keyboard_post_init_user(void) { keyboard_post_init_keymap(); }
// END: *_user functions call *_keymap functions.

#ifdef SPLIT_KEYBOARD
__attribute__((weak)) bool row_belongs_to_current_keyboard_hand(uint8_t row) {
  bool is_left = is_keyboard_left();
#ifdef CONSOLE_ENABLE
  bool is_master = is_keyboard_master();
  static uint8_t printed_row = INITIAL_DEFAULT_ROW;
  if (is_master) {
    if (row != printed_row) {
      uprintf(
          "row_belongs_to_current_keyboard_hand, Master row: %2u isleft: %1d\n",
          row, is_left);
      printed_row = row;
    }
  } else {
#ifdef GROTA_DATA_SYNC_TESTS_DEBUG
    sprintf(str2, "belongstckh,SL: row: %2u left:%1d", row, is_left);
#endif
  }
#endif // CONSOLE_ENABLE
  return (is_left && row < (MATRIX_ROWS / 2) && row >= 0) ||
         (!is_left && row >= (MATRIX_ROWS / 2) && row < MATRIX_ROWS);
}
#endif
