#include QMK_KEYBOARD_H
#include "grota.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_6x6_sym(
     KC_ESC_GRAVE,  KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_HOME,                                      KC_END,         KC_C_7,    KC_C_8,  KC_C_9,  KC_C_0,   KC_BSLASH,
     SFT_CTL(KC_C), KC_C_1,  KC_C_2,   KC_C_3,  KC_C_4,    KC_C_5,                                       KC_C_6,        KC_LEFT,    KC_DOWN, KC_UP,   KC_RIGHT, SFT_CTL(KC_V),
     KC_TAB,        KC_Q,    KC_F,     KC_W,    KC_R,      KC_EQUAL,                                     KC_QUOTE,         KC_H,    KC_J,    KC_K,    KC_L,     KC_MS_BTN3,
     KC_SLASH,      KC_A,    KC_S,     KC_D,    KC_G,      KC_X,                                         KC_Y,             KC_C,    KC_E,    KC_I,    KC_O,     KC_WH_D,
     KC_LSPO,       KC_Z,    KC_T,     KC_M,    KC_V,      RALT_T(KC_SCOLON),                            RALT_T(KC_COMMA), KC_N,    KC_P,    KC_B,    KC_U,     KC_RSPC,
                         KC_LCTRL, KC_MINUS,                                                                                    KC_DOT,  KC_LALT,
                                                    KC_BSPACE, LCTL(KC_C),                         KC_ENTER, LCTL_T(KC_SPACE),
                                                               KC_PGUP, KC_LALT,           LCTL(KC_V), KC_PGDOWN,
                                                       TD_SQBRKTL, TT(_FN_AND_MOUSE),       KC_LGUI, TD_SQBRKTR
  ),
  [_FN_AND_MOUSE] = LAYOUT_6x6_sym(
       _______,_______,_______,       _______, _______,    RESET  ,            _______, _______,    _______,    _______,     _______, _______,
       _______,_______,_______,       _______, _______,    _______,            _______, _______,    _______,    _______,      KC_F11,  KC_F12,
       _______,_______,_______,      KC_MS_UP, _______,    _______,            _______, _______,    KC_MS_UP,   _______,     _______, _______,
       _______,_______,KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,_______,            _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______, _______,
       _______,_______,_______,_______,_______,_______,                        _______, KC_WH_U,    KC_WH_D,    _______,     _______, _______,
                      _______,_______,                                                              _______,    _______,
                                              _______,  _______,           KC_MS_BTN2, KC_MS_BTN1,
                                                   _______,_______,     _______,_______,
                                                   _______, TO(_BASE),  TO(_BASE),_______
  ),
};
