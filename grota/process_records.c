#include "grota.h"
#include "qmk_firmware/quantum/keycodes.h"

// clang-format off
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
// clang-format on

#ifdef GROTA_DEFINE_PRINT_HAPTIC
uint8_t haptic_get_dwell(void);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(RGB_MATRIX_ENABLE)
  if (!process_record_user_rgb(keycode, record)) {
    return false;
  }
#endif
#if defined(GROTA_ENABLE_ESC_GRAVE) || defined(GROTA_ENABLE_NUMBERS_FN_KC) ||  \
    defined(GROTA_CUSTOM_MEDIA_KC) || defined(GROTA_DEFINE_ARROW) ||           \
    defined(GROTA_DEFINE_PRINT_HAPTIC)
  uint8_t modifiers = get_mods();
  uint8_t weak_mods = get_weak_mods();
#ifndef NO_ACTION_ONESHOT
  uint8_t one_shot = get_oneshot_mods();
#endif
#endif
  bool row_is_ours =
      row_belongs_to_current_keyboard_hand(record->event.key.row);
  switch (keycode) {
  case QK_BOOT:
    if (row_is_ours) {
      reset_keyboard();
    }
    return false;
  case EE_CLR: {
    if (row_is_ours) {
      eeconfig_disable();
      soft_reset_keyboard();
    }
    return false;
  }
#ifdef GROTA_ENABLE_ESC_GRAVE
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
#endif

#ifdef GROTA_ENABLE_NUMBERS_FN_KC
  // clang-format off
  // 1,2,3...9,0 normally and F1,F2,F3...F9,F10 when RALT_IS_PRESSED && !SHIFT_IS_PRESSED.
  // clang-format on
  case KC_C_1 ... KC_C_0: {
    uint8_t key = ((RALT_IS_PRESSED) && (!(SHIFT_IS_PRESSED)))
                      ? keycode - (KC_C_1 - KC_F1)
                      : keycode - (KC_C_1 - KC_1);
    if (record->event.pressed) {
      register_code(key);
    } else {
      unregister_code(key);
    }
    return false;
  }
#endif

#ifdef GROTA_CUSTOM_MEDIA_KC
  case KC_MEDIA_DOWN: {
    uint8_t key = SHIFT_IS_PRESSED ? KC_AUDIO_VOL_DOWN : KC_BRIGHTNESS_DOWN;
    (record->event.pressed) ? register_code(key) : unregister_code(key);
    return true;
  }

  case KC_MEDIA_UP: {
    uint8_t key = SHIFT_IS_PRESSED ? KC_AUDIO_VOL_UP : KC_BRIGHTNESS_UP;
    (record->event.pressed) ? register_code(key) : unregister_code(key);
    return true;
  }
#endif

#ifdef GROTA_DEFINE_ARROW
  case KC_ARROW: {
    if (record->event.pressed) {
      SEND_STRING("->");
    }
    return false;
  }
#endif // #ifdef GROTA_DEFINE_ARROW

#ifdef GROTA_DEFINE_PRINT_HAPTIC
  // Prints haptic dwell time, similar to QK_DYNAMIC_TAPPING_TERM_PRINT
  case KC_PRNT_HPT: {
    if (record->event.pressed) {
      const char *dwell_time_str = get_u16_str(haptic_get_dwell(), ' ');
      // Skip padding spaces.
      while (*dwell_time_str == ' ') {
        dwell_time_str++;
      }
      send_string(dwell_time_str);
      return false;
    }
  }
#endif // #ifdef GROTA_DEFINE_PRINT_HAPTIC
  }    // END switch keycode
  return process_record_keymap(keycode, record);
}
