#include QMK_KEYBOARD_H
#include "grota.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Base
 * ,--------------------------------------------------------.     ,-------------------------------------------------------.
 * | ESC ~ ` |  1 F1 | 2 F2  | 3 F3  | 4 F4  | 5 F5  | 6 F6 |     | 7 F7 | 8 F8  |  Left |  Down |  Up  | Right |   \|    |
 * |---------+-------+-------+-------+-------+--------------|     |------+-------+-------+-------+------+-------+---------|
 * |   Tab   |   Q   |   F   |   W   |   R   |   =+  | Home |     | End  |   '"  |   H   |   J   |  K   |   L   |   PgUp  |
 * |---------+-------+-------+-------+-------+-------|      |     |      |-------+-------+-------+------+-------+---------|
 * |   / ?   |   A   |   S   |   D   |   G   |   X   |------|     |------|   Y   |   C   |   E   |  I   |   O   |  PgDown |
 * |---------+-------+-------+-------+-------+-------|TD [{ |     | ]} TD|-------+-------+-------+------+-------+---------|
 * |  (LShft |   Z   |   T   |   M   |   V   |;: RAlt|      |     |      |,< Ralt|   N   |   P   |  B   |   U   |  RShft) |
 * `---------+-------+-------+-------+-------+-------+------'     `--------------+-------+-------+------+-------+---------'
 *    | Ctrl |  LAlt |  TT1  |   -_  |  Bksp |                                  |Spc/LAlt|  Ctrl |  .>  | 0 F10 | 9 F9 |
 *    `--------------------------------------'                                  `--------------------------------------'
 *                                            ,-------------.   ,-------------.
 *                                            | BRI- | BRI+ |   | Vol- | Vol+ |
 *                                     ,------|------|------|   |------+------+------.
 *                                     |      |      |MdlClk|   | LGui |      |      |
 *                                     | C-c  | Del  |------|   |------|      |Enter |
 *                                     |      |      | C-v  |   |S-C-V |S-C-C |      |
 *                                     `--------------------'   `--------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  KC_ESC_GRAVE, KC_C_1, KC_C_2, KC_C_3, KC_C_4, KC_C_5,                KC_C_6,   KC_C_7,     KC_C_8,           KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_BSLASH,
  KC_TAB,       KC_Q,   KC_F,   KC_W,   KC_R,   KC_EQUAL,             KC_HOME,   KC_END,     KC_QUOTE,         KC_H,    KC_J,    KC_K,  KC_L,     KC_PGUP,
  KC_SLASH,     KC_A,   KC_S,   KC_D,   KC_G,   KC_X,                                        KC_Y,             KC_C,    KC_E,    KC_I,  KC_O,     KC_PGDOWN,
  KC_LSPO,      KC_Z,   KC_T,   KC_M,   KC_V,   RALT_T(KC_SCOLON), TD_SQBRKTL,   TD_SQBRKTR, RALT_T(KC_COMMA), KC_N,    KC_P,    KC_B,  KC_U,     KC_RSPC,

                   KC_LCTRL, KC_LALT, TT(_FN_AND_MOUSE), KC_MINUS, KC_BSPACE,   LALT_T(KC_SPACE), KC_RCTL, KC_DOT, KC_C_0, KC_C_9,

                                                            KC_BRID, KC_BRIU,   KC_VOLD, KC_VOLU,
                                                                  KC_MS_BTN3,   KC_LGUI,
                                           LCTL(KC_C), KC_DELETE, LCTL(KC_V),   SFT_CTL(KC_V), SFT_CTL(KC_C), KC_ENTER
),

/* Layer 1: FN and Mouse
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * |        |EEP_RST|      |      |      |      |      |     |      |      |      |      |      | F11  |   F12  |
 * |--------+-------+------+------+------+------+------|     |------+------+------+------+------+------+--------|
 * |        |       |      |      |      |      | RGB  |     |Satur+|      |      | M_U  |      |WhelUp|        |
 * |--------+-------+------+------+------+------| BRI+ |     |      |------+------+------+------+------+--------|
 * |        |       |      |      |      |      |------|     |------|      | M_L  | M_D  | M_R  |WhelDn|        |
 * |--------+-------+------+------+------+------| RGB  |     |Satur-|------+------+------+------+------+--------|
 * |        |       |      |      |      |      | BRI- |     |      |      |      |      |      |      |        |
 * `--------+-------+------+------+------+------+------'     `-------------+------+------+------+------+--------'
 *   |      |       | TO0  |      |      |                                 |LftClk|RgtClk|MdlClk|      |      |
 *   `-----------------------------------'                                 `----------------------------------'
 *                                       ,-------------.   ,-------------.
 *                                       |Animat| RESET|   |Toggle|Solid |
 *                                ,------|------|------|   |------+------+------.
 *                                |      |      |      |   | Hue+ |      |      |
 *                                |      |      |------|   |------|      |      |
 *                                |      |      |      |   | Hue- |      |      |
 *                                `--------------------'   `--------------------'
 */
[_FN_AND_MOUSE] = LAYOUT_ergodox_pretty(
 _______, EEPROM_RESET, _______, _______, _______, _______, _______,   _______, _______,    _______,     _______,     _______,  KC_F11,  KC_F12,
 _______, _______,      _______, _______, _______, _______, RGB_VAI,   RGB_SAI, _______,    _______,    KC_MS_UP,     _______, KC_WH_U, _______,
 _______, _______,      _______, _______, _______, _______,                     _______, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, _______,
 _______, _______,      _______, _______, _______, _______, RGB_VAD,   RGB_SAD, _______,    _______,     _______,     _______, _______, _______,

                 _______, _______, TO(_BASE), _______, _______,   KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _______, _______,

                                       CUSTOM_RGB_CYCLE, RESET,   RGB_TOG, RESET  ,
                                                       _______,   RGB_HUI,
                                     _______, _______, _______,   RGB_HUD, _______, _______
),
};

void matrix_scan_keymap(void) {
  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();
  uint8_t weak_mods = get_weak_mods();
  ergodox_board_led_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  if (SHIFT_IS_PRESSED) {
    ergodox_right_led_2_on();
    ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
  }
  if (RALT_IS_PRESSED) {
    ergodox_right_led_3_on();
    ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
  }
  // On ez you won't see this.
  if (CTRL_IS_PRESSED) {
    ergodox_board_led_on();
  }
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_keymap(layer_state_t state) {
  ergodox_right_led_1_off();
  uint8_t layer = biton32(state);
  switch (layer) {
      case _FN_AND_MOUSE:
        ergodox_right_led_1_on();
        break;

      default:
        break;
    }

  return state;
};
