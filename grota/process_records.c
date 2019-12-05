#include "grota.h"

uint16_t tab_ctrlc_timer;

#ifdef AUDIO_ENABLE
float tab_ctrlc_timer_song[][2] = SONG(UNICODE_WINDOWS);
#endif

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

    case KC_MEDIA_DOWN: {
      uint8_t key = SHIFT_IS_PRESSED ? KC_VOLD : KC_BRID;
      (record->event.pressed) ? register_code(key) : unregister_code(key);
      return false;
    }

    case KC_MEDIA_UP: {
      uint8_t key = SHIFT_IS_PRESSED ? KC_VOLU : KC_BRIU;
      (record->event.pressed) ? register_code(key) : unregister_code(key);
      return false;
    }

    case KC_ARROW: {
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
    }

    case KC_TAB_CTRLC:
      if(record->event.pressed){
        tab_ctrlc_timer = timer_read();
      } else {
        if (timer_elapsed(tab_ctrlc_timer) > TAPPING_TERM) {
          register_code(KC_LCTL);
          tap_code(KC_C);
          unregister_code(KC_LCTL);
#ifdef AUDIO_ENABLE
        PLAY_SONG(tab_ctrlc_timer_song);
#endif
        } else {
          tap_code(KC_TAB);
        }
      }
      return false;

    default:
      return true;
  }
  return process_record_keymap(keycode, record);
}
