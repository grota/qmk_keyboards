#include "haptic_stuff.h"

#ifdef GROTA_CUSTOM_DATA_SYNC2
extern char str2[32];
#endif
__attribute__ ((weak)) bool row_belongs_to_current_keyboard_hand(uint8_t row) {
  bool is_left = is_keyboard_left();
  #ifdef CONSOLE_ENABLE
  bool is_master = is_keyboard_master();
  if (is_master) {
    uprintf("row_belongs_to_current_keyboard_hand, Master row: %2u isleft: %1d\n", row, is_left);
  #ifdef GROTA_CUSTOM_DATA_SYNC2
  } else {
    sprintf(str2, "belongstckh,SL: row: %2u left:%1d", row, is_left);
  #endif
  }
  #endif // CONSOLE_ENABLE
  return (is_left && row < (MATRIX_ROWS / 2))
    || (!is_left && row >= (MATRIX_ROWS / 2));
}

bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
  bool is_master = is_keyboard_master();
  uprintf("%s get_haptic_enabled_key: kc: 0x%04X\n", is_master ? "Master" : "Slave", keycode);
  #endif
  switch (keycode) {
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_F1 ... KC_F12:
    case KC_C_1 ... KC_C_0:
    case KC_ENTER:
    case KC_ESCAPE:
    case KC_BACKSPACE:
    case KC_SPACE:
    case KC_MINUS:
    case KC_EQUAL:
    case KC_LEFT_BRACKET:
    case KC_RIGHT_BRACKET:
    case KC_BACKSLASH:
    case KC_NONUS_HASH:
    case KC_SEMICOLON:
    case KC_QUOTE:
    case KC_GRAVE:
    case KC_COMMA:
    case KC_SLASH:
    case KC_DOT:
    case KC_NONUS_BACKSLASH:
    case KC_PRINT_SCREEN:
    case KC_PAUSE:
    case KC_INSERT:
    case KC_DELETE:
    case KC_PAGE_DOWN:
    case KC_PAGE_UP:
    case KC_END:
    case KC_HOME:
    case KC_MEDIA_DOWN:
    case KC_MEDIA_UP:
    case KC_ARROW:
    case KC_LSPO ... KC_SFTENT:
    case KC_LCPO ... KC_RAPC:
      uprintf("break\n");
      break;
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      if (record->tap.count == 0) {
        uprintf("mod tap false\n");
        return false;
      }
      break;

    default:
      uprintf("other false\n");
      return false;
  }
  bool a = row_belongs_to_current_keyboard_hand(record->event.key.row);
  uprintf("row_belongs_to_current_keyboard_hand gives %1d\n", a);
  return a;
}

