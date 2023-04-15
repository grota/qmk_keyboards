#include QMK_KEYBOARD_H
#include "grota.h"
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * +---------------------------------------------+                                 +------------------------------------------------+
 * |   ` ~   | Bri- | Bri+ | Vol- | Vol+ |  Home |                                 |  End  |  7 F7  | 8 F8 | 9 F9 | 0 F10 |   \ |   |
 * |---------+------+------+------+------+-------|                                 |-------+--------+------+------+-------+---------|
 * | S+CTR+c | 1 F1 | 2 F2 | 3 F3 | 4 F4 |  5 F5 |                                 |  6 F6 |  Left  | Down |  Up  | Right | CTRL+v  |
 * +---------------------------------------------+                                 +------------------------------------------------+
 * |    /    |  Q   |  F   |  W   |  R   |  = +  |                                 |  ' "  |   H    |  J   |  K   |   L   | MdlClk  |
 * |---------+------+------+------+------+-------|                                 |-------+--------+------+------+-------+---------|
 * |   Tab   |  A   |  S   |  D   |  G   |   X   |                                 |   Y   |   C    |  E   |  I   |   O   | WhelDwn |
 * |---------+------+------+------+------+-------|                                 |-------+--------+------+------+-------+---------|
 * | ( LShft |  Z   |  T   |  M   |  V   |;: RAlt|                                 |,> Ralt|   N    |  P   |  B   |   U   | RShft ) |
 * +---------+------+------+------+--------------+                                 +----------------+------+------+-------+---------+
 *                  | CTRL |  -_  |                                                                 | . >  | LALT |
 *                  +-------------+--------------+                                 +----------------+-------------+
 *                                | Bksp | CTR+c |                                 | Enter |Spc/Ctrl|
 *                                +------+-------+                                 +-------+--------+
 *                                                +--------------+ +---------------+
 *                                                | PgUP  | LAlt | |  ESC  | PgDWN |
 *                                                |-------+------| |-------+-------|
 *                                                | TD [{ | TT1  | |  LGui | TD ]} |
 *                                                +--------------+ +---------------+
 */

  [_BASE] = LAYOUT_6x6_sym(
     KC_ESC,     KC_C_1,  KC_C_2,        KC_C_3,      KC_C_4,    KC_C_5,                                KC_C_6,           KC_C_7,  KC_C_8,   KC_C_9, KC_C_0,   TT(_LAYER_MOUSE),
     KC_GRAVE,   KC_Q,    KC_MEDIA_DOWN, KC_MEDIA_UP, KC_DELETE, KC_HOME,                             KC_END,           KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_BSLASH,
     KC_MS_BTN3, KC_A,    KC_F,          KC_W,        KC_R,      KC_EQUAL,                              KC_QUOTE,         KC_H,    KC_J,     KC_K,   KC_L,     KC_ARROW,
     KC_LGUI,    KC_Z,    KC_S,          KC_D,        KC_G,      KC_X,                                  KC_Y,             KC_C,    KC_E,     KC_I,   KC_O,     KC_PGUP,
     KC_LCTRL,   KC_LALT, KC_T,          KC_M,        KC_V,      RALT_T(KC_SCOLON),                     RALT_T(KC_COMMA), KC_N,    KC_P,     KC_B,   KC_U,     KC_PGDOWN,
                          LCTL(KC_V),    TT(_LAYER_MOUSE),                                                                      KC_SLASH, KC_DOT,

                                                             KC_BSPACE, LCTL_T(KC_TAB),                          RCTL_T(KC_ENTER), LALT_T(KC_SPACE),
                                                                           KC_LSPO, LCTL(KC_C),         KC_MINUS, KC_RSPC,
                                                                           KC_PGDOWN,  KC_PGUP,         TD_SQBRKTL, TD_SQBRKTR
  ),
  [_LAYER_MOUSE] = LAYOUT_6x6_sym(
       _______,_______,_______,_______,_______,  QK_BOOT,              QK_BOOT, _______,    _______,     KC_F11,     KC_F12,    TO(_BASE),
       _______,_______,_______,_______,_______,_______,            _______, _______,    _______,    _______,     _______,   _______,
       _______,_______,_______,_______,_______,_______,            _______, _______,    KC_MS_UP,   _______,     KC_WH_U,   _______,
       _______,_______,_______,_______,_______,_______,            _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_WH_D,   _______,
       _______,_______,_______,_______,_______,_______,            _______, _______,    _______,    _______,     _______,   _______,
                       _______,_______,                                                             KC_HOME,     KC_END,
                                              _______,  _______,           KC_MS_BTN2, KC_MS_BTN1,
                                                   _______, _______,    _______,   _______,
                                                   _______, _______,    _______,   _______
  ),
};
// clang-format on
