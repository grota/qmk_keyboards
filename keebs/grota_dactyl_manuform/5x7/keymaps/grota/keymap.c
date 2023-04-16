#include QMK_KEYBOARD_H
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER_BASE] = LAYOUT_5x7_sym(
//    ┌──────┬──────────┬──────────┬───────────┬────────────┬────────┬─────────┐   ┌───────┬──────┬────────────┬───────────┬──────────┬──────────┬────────┐
//    │ ESC  │   1 F1   │   2 F2   │   3 F3    │    4 F4    │  5 F5  │  6 F6   │   │ 7 F7  │ 8 F8 │     ←      │     ↓     │    ↑     │    →     │  \ |   │
//    ├──────┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├───────┼──────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │ ` ~  │    Q     │    F     │     W     │     R      │  = +   │  ﱜ /   │   │ ﱛ /  │ ' "  │     H      │     J     │    K     │    L     │        │
//    ├──────┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├───────┼──────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │ - _  │ Gui_T(A) │ Alt_T(S) │ Ctrl_T(D) │ Shift_T(G) │   X    │   DEL   │   │ TT() │  Y   │ Shift_T(C) │ Ctrl_T(E) │ Alt_T(I) │ Gui_T(O) │ Page  │
//    ├──────┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├───────┼──────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │      │    Z     │    T     │     M     │ AltGr_T(V) │  ; :   │  HOME   │   │  end  │ , <  │ AltGr_T(N) │     P     │    B     │    U     │ Page  │
//    ├──────┼──────────┼──────────┼───────────┼────────────┴────────┴─────────┘   └───────┴──────┴────────────┼───────────┼──────────┼──────────┼────────┤
//    │ TD_[ │   TD_]   │ Ctrl(V)  │   TT()   │                                                               │    / ?    │   . >    │  0 F10   │  9 F9  │
//    └──────┴──────────┴──────────┴───────────┼────────────┬────────┐                     ┌──────┬────────────┼───────────┴──────────┴──────────┴────────┘
//                                             │           │       │                     │  ⏎   │     ␣      │                                           
//                                             └────────────┼────────┼─────────┐   ┌───────┼──────┼────────────┘                                           
//                                                          │  ( ↑   │ Ctrl(C) │   │  - _  │ ) ↑  │                                                        
//                                                          ├────────┼─────────┤   ├───────┼──────┤                                                        
//                                                          │ Page  │ Page   │   │ TD_[  │ TD_] │                                                        
//                                                          └────────┴─────────┘   └───────┴──────┘                                                        
  KC_ESC     , KC_C_1       , KC_C_2       , KC_C_3           , KC_C_4       , KC_C_5   , KC_C_6        ,     KC_C_7           , KC_C_8     , KC_LEFT      , KC_DOWN      , KC_UP        , KC_RIGHT     , KC_BSLS,
  KC_GRAVE   , KC_Q         , KC_F         , KC_W             , KC_R         , KC_EQUAL , KC_MEDIA_DOWN ,     KC_MEDIA_UP      , KC_QUOTE   , KC_H         , KC_J         , KC_K         , KC_L         , _______,
  KC_MINUS   , LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D)     , LSFT_T(KC_G) , KC_X     , KC_DELETE     ,     TT(_LAYER_MOUSE) , KC_Y       , RSFT_T(KC_C) , RCTL_T(KC_E) , LALT_T(KC_I) , RGUI_T(KC_O) , KC_PGUP,
  _______    , KC_Z         , KC_T         , KC_M             , RALT_T(KC_V) , KC_SCLN  , KC_HOME       ,     KC_END           , KC_COMMA   , RALT_T(KC_N) , KC_P         , KC_B         , KC_U         , KC_PGDN,
  TD_SQBRKTL , TD_SQBRKTR   , LCTL(KC_V)   , TT(_LAYER_MOUSE) ,                                                                                              KC_SLASH     , KC_DOT       , KC_C_0       , KC_C_9 ,
                                                                KC_BACKSPACE , KC_TAB   ,                                        KC_ENTER   , KC_SPACE                                                           ,
                                                                               SC_LSPO  , LCTL(KC_C)    ,     KC_MINUS         , SC_RSPC                                                                         ,
                                                                               KC_PGDN  , KC_PGUP       ,     TD_SQBRKTL       , TD_SQBRKTR                                                                      
),

[_LAYER_MOUSE] = LAYOUT_5x7_sym(
//    ┌─────┬─────┬───────┬─────────────────┬───────────┬────────┬─────┐   ┌─────────────────┬────────┬───────────┬───────┬───────┬─────────┬─────┐
//    │     │     │       │                 │ QK_REBOOT │ EE_CLR │    │   │                │ EE_CLR │ QK_REBOOT │       │       │   F11   │ F12 │
//    ├─────┼─────┼───────┼─────────────────┼───────────┼────────┼─────┤   ├─────────────────┼────────┼───────────┼───────┼───────┼─────────┼─────┤
//    │     │     │       │                 │           │        │     │   │                 │        │           │   ↑  │       │ WHEEL↑ │     │
//    ├─────┼─────┼───────┼─────────────────┼───────────┼────────┼─────┤   ├─────────────────┼────────┼───────────┼───────┼───────┼─────────┼─────┤
//    │   │     │ ACL0  │      ACL1       │   ACL2    │        │     │   │                 │        │     ←    │   ↓  │   →  │ WHEEL↓ │   │
//    ├─────┼─────┼───────┼─────────────────┼───────────┼────────┼─────┤   ├─────────────────┼────────┼───────────┼───────┼───────┼─────────┼─────┤
//    │   │   │  / │       ←/→      │           │        │     │   │      PB_3       │  PB_2  │   PB_1    │  ←/→ │  / │       │   │
//    ├─────┼─────┼───────┼─────────────────┼───────────┴────────┴─────┘   └─────────────────┴────────┴───────────┼───────┼───────┼─────────┼─────┤
//    │     │     │       │ TO(_LAYER_BASE) │                                                                     │       │       │         │     │
//    └─────┴─────┴───────┴─────────────────┼───────────┬────────┐                           ┌────────┬───────────┼───────┴───────┴─────────┴─────┘
//                                          │           │        │                           │  BTN2 │   BTN1   │                                
//                                          └───────────┼────────┼─────┐   ┌─────────────────┼────────┼───────────┘                                
//                                                      │        │     │   │      BTN3      │        │                                            
//                                                      ├────────┼─────┤   ├─────────────────┼────────┤                                            
//                                                      │        │     │   │ TO(_LAYER_BASE) │        │                                            
//                                                      └────────┴─────┘   └─────────────────┴────────┘                                            
  _______ , _______ , _______ , _______         , QK_REBOOT , QK_CLEAR_EEPROM , QK_BOOT ,     QK_BOOT         , QK_CLEAR_EEPROM , QK_REBOOT  , _______    , _______     , KC_F11  , KC_F12 ,
  _______ , _______ , _______ , _______         , _______   , _______         , _______ ,     _______         , _______         , _______    , KC_MS_UP   , _______     , KC_WH_U , _______,
  AU_TOGG , _______ , KC_ACL0 , KC_ACL1         , KC_ACL2   , _______         , _______ ,     _______         , _______         , KC_MS_LEFT , KC_MS_DOWN , KC_MS_RIGHT , KC_WH_D , AU_TOGG,
  RGB_TOG , RGB_MOD , RGB_VAD , RGB_HUD         , _______   , _______         , _______ ,     PB_3            , PB_2            , PB_1       , RGB_HUD    , RGB_VAD     , RGB_MOD , RGB_TOG,
  _______ , _______ , _______ , TO(_LAYER_BASE) ,                                                                                              _______    , _______     , _______ , _______,
                                                  _______   , _______         ,                                 KC_MS_BTN2      , KC_MS_BTN1                                               ,
                                                              _______         , _______ ,     KC_MS_BTN3      , _______                                                                    ,
                                                              _______         , _______ ,     TO(_LAYER_BASE) , _______                                                                    
)
};
// clang-format on
