#include QMK_KEYBOARD_H
#include "grota.h"

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
     KC_ESC_GRAVE , ,                                        KC_HOME,                                    KC_END,           KC_C_7,  KC_C_8, KC_C_9,   KC_C_0,  KC_BSLASH,
     KC_C_1,  KC_C_2,   KC_C_3,  KC_C_4,    KC_C_5,  KC_C_6,                                             KC_LEFT,          KC_DOWN, KC_UP,  KC_RIGHT, KC_LGUI, SFT_CTL(KC_C),
     KC_SLASH     , KC_Q,    KC_F,     KC_W,    KC_R,      KC_EQUAL,                                     KC_QUOTE,         KC_H,    KC_J,   KC_K,     KC_L,    KC_MS_BTN3,
     KC_TAB       , KC_A,    KC_S,     KC_D,    KC_G,      KC_X,                                         KC_Y,             KC_C,    KC_E,   KC_I,     KC_O,    KC_WH_D,
     KC???        , KC_Z,    KC_T,     KC_M,    KC_V,      RALT_T(KC_SCOLON),                            RALT_T(KC_COMMA), KC_N,    KC_P,   KC_B,     KC_U,    KC_PGDOWN,
                         KC_LCTRL, TT(_FN_AND_MOUSE),                                                                                    TD_SQBRKTR,  KC_LALT,
                                             KC_BSPACE, LCTL(KC_C),                                     RCTL_T(KC_ENTER), LALT_T(KC_SPACE),
                                                          KC_LSPO, KC_LALT,             KC_MINUS, KC_RSPC,
                                                       TD_SQBRKTL, KC_PGUP,       LCTL(KC_V), KC_DOT
  ),
  [_FN_AND_MOUSE] = LAYOUT_6x6_sym(
       _______,KC_BRID,KC_BRIU,KC_VOLD,KC_VOLU,RESET  ,            _______, _______,    _______,    _______,     _______, _______,
       _______,_______,_______,_______,_______,_______,            _______, _______,    _______,    _______,      KC_F11,  KC_F12,
       _______,_______,_______,_______,_______,_______,            _______, _______,    KC_MS_UP,   _______,     _______, _______,
       _______,_______,_______,_______,_______,_______,            _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______,
       _______,_______,_______,_______,_______,_______,            _______, KC_WH_U,    KC_WH_D,    _______,     _______, _______,
                       _______,_______,                                                             _______,     _______,
                                              _______,  _______,           KC_MS_BTN1, KC_MS_BTN2,
                                                   _______, _______,    _______,   _______,
                                                   _______, TO(_BASE),  TO(_BASE), _______
  ),
};