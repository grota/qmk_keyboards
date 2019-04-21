#include "grota.h"
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(RGB_MATRIX_ENABLE)
    if (!process_record_user_rgb(keycode, record)) {
      return false;
    }
#endif
  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();
  uint8_t weak_mods = get_weak_mods();
  switch (keycode) {
    // ESC normally, ~ if SHIFT_IS_PRESSED, ` when RALT_IS_PRESSED.
    case KC_ESC_GRAVE: {
      if (RALT_IS_PRESSED) {
        SEND_STRING("`");
        return false;
      }
      uint8_t key = SHIFT_IS_PRESSED ? KC_GRAVE : KC_ESCAPE;
      (record->event.pressed) ? register_code(key) : unregister_code(key);
      return false;
    }
    // 1,2,3...9,0 normally and F1,F2,F3...F9,F10 when RALT_IS_PRESSED && !SHIFT_IS_PRESSED.
    case KC_C_1 ... KC_C_0: {
      uint8_t key = ((RALT_IS_PRESSED) && (!(SHIFT_IS_PRESSED))) ? keycode - (KC_C_1 - KC_F1) : keycode - (KC_C_1 - KC_1);
      if (record->event.pressed) {
        register_code(key);
      } else {
        unregister_code(key);
      }
      return false;
    }

    default:
      return true;
  }
  return process_record_keymap(keycode, record);
}
