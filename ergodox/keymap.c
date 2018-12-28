#include QMK_KEYBOARD_H
#include "version.h"
#include "grota.h"

#ifdef RGB_MATRIX_ENABLE
  #include "rgb_stuff.h"
#endif

#ifdef LEADER_ENABLE
#include "leader_stuff.h"
#else
#define KC_LEAD _______
#endif

#ifdef TAP_DANCE_ENABLE
#include "tap_dance.h"
#endif

userspace_config_t userspace_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Base
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |   6  |     |   7  |   8  | Left | Down |  Up  | Right|   \|   |
 * |--------+------+------+------+------+-------------|     |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   F  |   W  |   R  |   Y  | Home |     | End  |  `~  |  H   |  J   |  K   |  L   | PgUp   |
 * |--------+------+------+------+------+------|      |     |      |------+------+------+------+------+--------|
 * |   -_   |   A  |   S  |   D  |   G  |   X  |------|     |------|  ,<  |  C   |  E   |  I   |  O   | PgDown |
 * |--------+------+------+------+------+------|TD [{ |     |TD ]} |------+------+------+------+------+--------|
 * | *LShft |   Z  |   T  |   M  |   B  |   V  |      |     |      |  /?  |  N   |  P   |  .>  |  U   |=+/RShft|
 * `--------+------+------+------+------+-------------'     `-------------+------+------+------+------+--------'
 *   | Ctrl | Win  |      | Spcl | Bksp |                               |Spc/LAlt|;:Ctrl|  '"  |  0)  |  9(  |
 *   `----------------------------------'                               `------------------------------------'
 *                                       ,-------------.   ,-------------.
 *                                       | BRI- | BRI+ |   | Vol- | Vol+ |
 *                                ,------|------|------|   |------+------+------.
 *                                |      |      |      |   |*RAlt |      |      |
 *                                | C-c  | RAlt |------|   |------| TT1  |Enter |
 *                                |      |      | C-v  |   |  Del |      |      |
 *                                `--------------------'   `--------------------'
 */
[_BASE] = LAYOUT_ergodox_pretty(
  KC_ESCAPE,     KC_1,  KC_2,  KC_3,  KC_4,  KC_5,       KC_6,   KC_7,       KC_8,     KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_BSLASH,
  KC_TAB,        KC_Q,  KC_F,  KC_W,  KC_R,  KC_Y,    KC_HOME,   KC_END,     KC_GRAVE, KC_H,    KC_J,    KC_K,   KC_L,     KC_PGUP,
  KC_MINUS,      KC_A,  KC_S,  KC_D,  KC_G,  KC_X,                           KC_COMMA, KC_C,    KC_E,    KC_I,   KC_O,     KC_PGDOWN,
  OSM(MOD_LSFT), KC_Z,  KC_T,  KC_M,  KC_B,  KC_V, TD_SQBRKTL,   TD_SQBRKTR, KC_SLASH, KC_N,    KC_P,    KC_DOT, KC_U,     RSFT_T(KC_EQUAL),

       KC_LCTRL, KC_LGUI, _______, TD_SPECIAL_LEAD, KC_BSPACE,   LALT_T(KC_SPACE), TD_COLON_CTRL, KC_QUOTE, KC_0, KC_9,

                                             KC_BRID, KC_BRIU,   KC_VOLD, KC_VOLU,
                                                      _______,   OSM(MOD_RALT),
                              LCTL(KC_C), KC_RALT, LCTL(KC_V),   KC_DELETE, TT(_FN_AND_MOUSE), KC_ENTER
),

/* Layer 1: FN and Mouse
 * ,--------------------------------------------------.     ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |     |  F7  |  F8  |      |      |      | F11  |   F12  |
 * |--------+------+------+------+------+------+------|     |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | RGB  |     |Satur+|      |      | M_U  |      |WhelUp|        |
 * |--------+------+------+------+------+------| BRI+ |     |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|     |------|      | M_L  | M_D  | M_R  |WhelDn|        |
 * |--------+------+------+------+------+------| RGB  |     |Satur-|------+------+------+------+------+--------|
 * |        |      |      |      |      |      | BRI- |     |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+------+------'     `-------------+------+------+------+------+--------'
 *   |      |      |      |  TO0 |      |                                 |LftClk|RgtClk|MdlClk|  F10 |  F9  |
 *   `----------------------------------'                                 `----------------------------------'
 *                                       ,-------------.   ,-------------.
 *                                       |Animat| RESET|   |Toggle|Solid |
 *                                ,------|------|------|   |------+------+------.
 *                                |      |      |      |   | Hue+ |      |      |
 *                                | XXXX | XXXX |------|   |------| TO0  |      |
 *                                |      |      | XXXX |   | Hue- |      |      |
 *                                `--------------------'   `--------------------'
 */
[_FN_AND_MOUSE] = LAYOUT_ergodox_pretty(
 _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,     KC_F8,    _______,    _______,     _______,  KC_F11,  KC_F12,
 _______, _______, _______, _______, _______, _______, RGB_VAI,   RGB_SAI, _______,    _______,   KC_MS_UP,     _______, KC_WH_U, _______,
 _______, _______, _______, _______, _______, _______,                     _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D, _______,
 _______, _______, _______, _______, _______, _______, RGB_VAD,   RGB_SAD, _______,    _______,    _______,     _______, _______, _______,

                 _______, _______, _______, TO(_BASE), _______,   KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_F10, KC_F9,

                                       CUSTOM_RGB_CYCLE, RESET,   RGB_TOG, _______,
                                                       _______,   RGB_HUI,
                                     _______, _______, _______,   RGB_HUD, TO(_BASE), _______
),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#if defined(RGB_MATRIX_ENABLE)
    process_record_user_rgb(keycode, record);
#endif
  return true;
}


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  userspace_config.raw = eeconfig_read_user();
};

void eeconfig_init_user(void) {
  userspace_config.raw = 0;
  eeconfig_update_user(userspace_config.raw);
}

void matrix_scan_user(void) {
  static bool has_ran_yet;
  if (!has_ran_yet) {
    has_ran_yet = true;
    // defined as weak in quantum/quantum.c
    startup_user();
  }
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
#ifdef LEADER_ENABLE
  matrix_scan_user_leader();
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
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
