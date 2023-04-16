#include "haptic_stuff.h"

#ifdef GROTA_CUSTOM_DATA_SYNC
#include <stdio.h>
extern char str2[32];
#endif

bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  bool is_master = is_keyboard_master();
  uprintf("%s get_haptic_enabled_key: kc: 0x%04X\n",
          is_master ? "Master" : "Slave", keycode);
#endif
  switch (keycode) {
  case KC_A ... KC_Z:
  case KC_1 ... KC_0:
  case KC_F1 ... KC_F12:
  case KC_C_1 ... KC_C_0:
  case KC_ENTER:
  case KC_ESCAPE:
  case KC_BACKSPACE:
  case KC_TAB:
  case KC_SPACE:
  case KC_MINUS:
  case KC_EQUAL:
  case KC_LEFT_BRACKET:
  case KC_RIGHT_BRACKET:
  case KC_BACKSLASH:
  case KC_SEMICOLON:
  case KC_QUOTE:
  case KC_GRAVE:
  case KC_COMMA:
  case KC_DOT:
  case KC_SLASH:
  case KC_DELETE:
  case KC_PAGE_DOWN:
  case KC_PAGE_UP:
  case KC_END:
  case KC_HOME:
  case KC_MEDIA_DOWN:
  case KC_MEDIA_UP:
#ifdef GROTA_DEFINE_ARROW
  case KC_ARROW:
#endif
  case LCTL(KC_C):
  case ALL_SPACE_CADET_KEYS:
    uprintf("generic pass\n");
    break;

  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    uprintf("mod tap count: %d\n", record->tap.count);
    return record->tap.count;

  default:
    uprintf("other, false\n");
    return false;
  }
  bool row_is_ours =
      row_belongs_to_current_keyboard_hand(record->event.key.row);
  uprintf("row_belongs_to_current_keyboard_hand gives %1d\n", row_is_ours);
  return row_is_ours;
}
