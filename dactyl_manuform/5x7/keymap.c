#include QMK_KEYBOARD_H
#include "grota.h"

#ifdef AUDIO_ENABLE
float shift_pressed_song[][2] = SONG(NUM_LOCK_ON_SOUND);
float ralt_pressed_song[][2]  = SONG(AG_NORM_SOUND);
float layer0_song[][2]        = SONG(GOODBYE_SOUND);
float layer1_song[][2]        = SONG(STARTUP_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_5x7_sym(
     KC_ESC,           KC_C_1,   KC_C_2,  KC_C_3,            KC_C_4, KC_C_5,            KC_C_6,                    KC_C_7,            KC_C_8, KC_LEFT,   KC_DOWN,     KC_UP, KC_RIGHT,  KC_BSLASH,
     KC_GRAVE,         KC_Q,     KC_F,    KC_W,              KC_R,   KC_EQUAL,          KC_HOME,                   KC_END,          KC_QUOTE,    KC_H,      KC_J,      KC_K,     KC_L,    KC_PGUP,
     KC_MS_BTN3,       KC_A,     KC_S,    KC_D,              KC_G,   KC_X,              KC_MEDIA_DOWN,        KC_MEDIA_UP,              KC_Y,    KC_C,      KC_E,      KC_I,     KC_O,  KC_PGDOWN,
     LSFT_T(KC_SLASH), KC_Z,     KC_T,    KC_M,              KC_V,   RALT_T(KC_SCOLON), TD_SQBRKTL,             TD_SQBRKTR, RALT_T(KC_COMMA),    KC_N,      KC_P,      KC_B,     KC_U,    KC_LGUI,
     KC_NO,            KC_LCTRL, KC_LALT, TT(_FN_AND_MOUSE),                                                                                   TT(_FN_AND_MOUSE),    KC_DOT,   KC_C_0,     KC_C_9,

                                                                    KC_BSPACE, CTRL_C_c,                                    RCTL_T(KC_ENTER), LALT_T(KC_SPACE),
                                                                                    KC_LSPO,  KC_TAB,               KC_MINUS, KC_RSPC,
                                                                                  KC_PGDOWN, KC_PGUP,             LCTL(KC_V), KC_DELETE
  ),

  [_FN_AND_MOUSE] = LAYOUT_5x7_sym(
   _______, _______, _______, _______, _______, _______,   RESET,   RESET,   _______,    _______,    _______,     _______,  KC_F11,  KC_F12,
   _______, _______, _______, _______, _______, _______, _______,   _______, _______,    _______,   KC_MS_UP,     _______, KC_WH_U, _______,
   _______, _______, _______, _______, _______, _______, KC_BRID,   KC_BRIU, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, _______,
   RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,   _______, _______,    _______,    _______,     _______, _______, _______,
   RGB_TOG, _______, _______, TO(_BASE),                                                           TO(_BASE),     _______, _______, _______,

                                _______, _______,                          KC_MS_BTN2, KC_MS_BTN1,
                                        _______, _______,   _______, KC_MS_BTN3,
                                        _______, _______,   _______, _______
  ),
};

void matrix_scan_keymap(void) {
#ifdef AUDIO_ENABLE
  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();
  uint8_t weak_mods = get_weak_mods();

  static bool detected_shift_pressed = false;
  if (!detected_shift_pressed && (SHIFT_IS_PRESSED)) {
    detected_shift_pressed = true;
    PLAY_SONG(shift_pressed_song);
  }
  if (detected_shift_pressed && !(SHIFT_IS_PRESSED)) {
    detected_shift_pressed = false;
  }

  static bool detected_ralt_pressed = false;
  if (!detected_ralt_pressed && (RALT_IS_PRESSED)) {
    detected_ralt_pressed = true;
    PLAY_SONG(ralt_pressed_song);
  }
  if (detected_ralt_pressed && !(RALT_IS_PRESSED)) {
    detected_ralt_pressed = false;
  }
#endif
}

uint32_t layer_state_set_keymap(uint32_t state) {
#ifdef AUDIO_ENABLE
  uint8_t layer = biton32(state);
  switch (layer) {
      case _BASE:
        PLAY_SONG(layer0_song);
        break;

      case _FN_AND_MOUSE:
        PLAY_SONG(layer1_song);
        break;

      default:
        break;
    }

  return state;
#endif
}