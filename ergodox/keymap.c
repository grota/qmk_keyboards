#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SECOND 1 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_ESCAPE, KC_1,    KC_2,    KC_3,  KC_4,      KC_5, KC_6,          KC_7,       KC_8,     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_EQUAL,
  KC_TAB,    KC_Q,    KC_F,    KC_W,  KC_R,      KC_Y, _______,       KC_MS_BTN3, KC_GRAVE, KC_H,    KC_J,    KC_K,   KC_L,     KC_BSLASH,
  KC_MINUS,  KC_A,    KC_S,    KC_D,  KC_G,      KC_X,                            KC_COMMA, KC_C,    KC_E,    KC_I,   KC_O,     KC_RCTRL,
  KC_LSHIFT, KC_Z,    KC_T,    KC_M,  KC_B,      KC_V, KC_HOME,       KC_END,     KC_SLASH, KC_N,    KC_P,    KC_DOT, KC_U,     KC_RSHIFT,
  KC_LCTRL,  KC_RALT, KC_LALT, TT(1), KC_BSPACE,                                        KC_SPACE,    KC_RALT, TG(1),  KC_9,     KC_0,
                                        KC_LBRACKET, KC_RBRACKET,     KC_SCOLON, KC_QUOTE,
                                                          KC_LGUI,    _______,
                                  LCTL(KC_C), LCTL(KC_V), KC_PGUP,    KC_PGDOWN, KC_DELETE, KC_ENTER
),

/* Keymap 1: Symbol Layer
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[SECOND] = LAYOUT_ergodox_pretty(
      KC_ESCAPE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,              KC_F7,      KC_F8,      _______,    _______,  _______,     KC_F11,  KC_F12,
      _______,   _______, _______, _______, _______, _______, _______,            _______,    _______,    _______,    _______,  _______,     _______, _______,
      _______,   _______, _______, _______, _______, _______,                     _______,    KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______,
      _______,   _______, _______, _______, _______, _______, _______,            _______,    _______,    _______,    _______,  _______,     _______, _______,
                 _______, _______, _______, _______, _______,                     KC_MS_BTN1, KC_MS_BTN2, _______,    KC_F9,    KC_F10,

                                                            RGB_MOD,RESET,        RGB_TOG,    RGB_SLD,
                                                                  _______,        _______,
                                                    RGB_VAD,RGB_VAI,TO(0),        _______,    RGB_HUD,    RGB_HUI
),
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SECOND)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
//void matrix_init_user(void) {
//#ifdef RGBLIGHT_COLOR_LAYER_0
//  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
//#endif
//};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      //case 0:
      //  #ifdef RGBLIGHT_COLOR_LAYER_0
      //    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
      //  #else
      //  #ifdef RGBLIGHT_ENABLE
      //    rgblight_init();
      //  #endif
      //  #endif
      //  break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
