#include "grota/grota.h"
#include "grota/tap_dance.h"
#include "qmk_firmware/quantum/keycodes.h"
#include QMK_KEYBOARD_H
// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER_BASE] = LAYOUT_5x7_sym(
//    ┌───┬──────────┬──────────┬───────────┬────────────┬────────┬─────────┐   ┌────────┬────────┬────────────┬───────────┬──────────┬──────────┬────────┐
//    │   │   1 F1   │   2 F2   │   3 F3    │    4 F4    │  5 F5  │  6 F6   │   │  7 F7  │  8 F8  │    9 F9    │   0 F10   │   F11    │   F12    │        │
//    ├───┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├────────┼────────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │   │    Q     │    F     │     W     │     R      │  = +   │  ﱜ /   │   │ ﱛ /   │  DEL   │     H      │     J     │    K     │    L     │        │
//    ├───┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├────────┼────────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │   │ Gui_T(A) │ Alt_T(S) │ Ctrl_T(D) │ Shift_T(G) │   X    │         │   │        │   Y    │ Shift_T(C) │ Ctrl_T(E) │ Alt_T(I) │ Gui_T(O) │ Page  │
//    ├───┼──────────┼──────────┼───────────┼────────────┼────────┼─────────┤   ├────────┼────────┼────────────┼───────────┼──────────┼──────────┼────────┤
//    │   │    Z     │    T     │     M     │ AltGr_T(V) │  ; :   │  HOME   │   │  END   │  , <   │ AltGr_T(N) │     P     │    B     │    U     │ Page  │
//    ├───┼──────────┼──────────┼───────────┼────────────┴────────┴─────────┘   └────────┴────────┴────────────┼───────────┼──────────┼──────────┼────────┤
//    │   │          │          │           │                                                                  │           │          │          │        │
//    └───┴──────────┴──────────┴───────────┼────────────┬────────┐                      ┌────────┬────────────┼───────────┴──────────┴──────────┴────────┘
//                                          │           │      │                      │  ⏎    │     ␣      │                                           
//                                          └────────────┼────────┼─────────┐   ┌────────┼────────┼────────────┘                                           
//                                                       │ Esc   │ LCTL(C) │   │        │  '    │                                                        
//                                                       ├────────┼─────────┤   ├────────┼────────┤                                                        
//                                                       │ Page  │ Page   │   │ Page  │ Page  │                                                        
//                                                       └────────┴─────────┘   └────────┴────────┘                                                        
  KC_NO , KC_C_1       , KC_C_2       , KC_C_3       , KC_C_4       , KC_C_5         , KC_C_6        ,     KC_C_7      , KC_C_8           , KC_C_9       , KC_C_0       , KC_F11       , KC_F12       , KC_NO  ,
  KC_NO , KC_Q         , KC_F         , KC_W         , KC_R         , KC_EQUAL       , KC_MEDIA_DOWN ,     KC_MEDIA_UP , KC_DELETE        , KC_H         , KC_J         , KC_K         , KC_L         , KC_NO  ,
  KC_NO , LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_G) , KC_X           , KC_NO         ,     KC_NO       , KC_Y             , RSFT_T(KC_C) , RCTL_T(KC_E) , LALT_T(KC_I) , RGUI_T(KC_O) , KC_PGUP,
  KC_NO , KC_Z         , KC_T         , KC_M         , RALT_T(KC_V) , KC_SCLN        , KC_HOME       ,     KC_END      , KC_COMMA         , RALT_T(KC_N) , KC_P         , KC_B         , KC_U         , KC_PGDN,
  KC_NO , KC_NO        , KC_NO        , KC_NO        ,                                                                                                     KC_NO        , KC_NO        , KC_NO        , KC_NO  ,
                                                       KC_BACKSPACE , LT_TAB_SYMBOLS ,                                   LT_ENTER_NUMBERS , KC_SPACE                                                           ,
                                                                      LT_ESC_MOUSE   , LCTL(KC_C)    ,     KC_NO       , LT_QUOTE_MEDIA                                                                        ,
                                                                      KC_PGDN        , KC_PGUP       ,     KC_PGDN     , KC_PGUP                                                                               
),

[_LAYER_SYM] = LAYOUT_5x7_sym(
//    ┌───┬──────┬───────────┬───────────┬───────────┬───┬───┐   ┌───┬─────┬───┬─────┬─────┬───┬───┐
//    │   │      │           │           │           │   │ ( │   │   │     │   │     │     │   │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │   │      │           │   TD(󰘚)   │   TD(󰍛)   │   │   │   │   │     │ { │ ` ~ │ \ | │ } │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │   │ LGUI │   LALT    │   LCTL    │   LSFT    │   │   │   │   │     │ ( │ , < │ . > │ ) │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │   │      │ TD(def_) │ TD(def_) │ TD(def_󰄮) │   │   │   │   │     │ [ │ - _ │ / ? │ ] │   │
//    ├───┼──────┼───────────┼───────────┼───────────┴───┴───┘   └───┴─────┴───┼─────┼─────┼───┼───┤
//    │   │      │           │          │                                     │    │ ; : │   │   │
//    └───┴──────┴───────────┴───────────┼───────────┬───┐           ┌─────┬───┼─────┴─────┴───┴───┘
//                                       │           │ 󰭃 │           │  ⏎  │ ␣ │                    
//                                       └───────────┼───┼───┐   ┌───┼─────┼───┘                    
//                                                   │   │   │   │   │ ' " │                        
//                                                   ├───┼───┤   ├───┼─────┤                        
//                                                   │   │   │   │   │     │                        
//                                                   └───┴───┘   └───┴─────┘                        
  KC_NO , KC_NO   , KC_NO                , KC_NO            , KC_NO             , KC_NO     , KC_LPRN ,     KC_NO , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO   , KC_NO,
  KC_NO , KC_NO   , KC_NO                , TD(TD_EE_CLR)    , TD(TD_BOOT)       , KC_NO     , KC_NO   ,     KC_NO , KC_NO    , KC_LCBR  , KC_GRAVE , KC_BSLS  , KC_RCBR , KC_NO,
  KC_NO , KC_LGUI , KC_LALT              , KC_LCTL          , KC_LSFT           , KC_NO     , KC_NO   ,     KC_NO , KC_NO    , KC_LPRN  , KC_COMMA , KC_DOT   , KC_RPRN , KC_NO,
  KC_NO , KC_NO   , TD(TD_DEF_L_NUMBERS) , TD(TD_DEF_L_SYM) , TD(TD_DEF_L_BASE) , KC_NO     , KC_NO   ,     KC_NO , KC_NO    , KC_LBRC  , KC_MINUS , KC_SLASH , KC_RBRC , KC_NO,
  KC_NO , KC_NO   , KC_NO                , KC_TAB           ,                                                                             KC_TAB   , KC_SCLN  , KC_NO   , KC_NO,
                                                              KC_NO             , KC_ORIGIN ,                       KC_ENTER , KC_SPACE                                        ,
                                                                                  KC_NO     , KC_NO   ,     KC_NO , KC_QUOTE                                                   ,
                                                                                  KC_NO     , KC_NO   ,     KC_NO , KC_NO                                                      
),

[_LAYER_MOUSE] = LAYOUT_5x7_sym(
//    ┌───┬──────┬───────────┬───────────┬───────────┬───┬───┐   ┌───┬────────┬──────────┬──────────┬──────────┬──────────┬───┐
//    │   │      │           │           │           │   │   │   │   │        │          │          │          │          │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼────────┼──────────┼──────────┼──────────┼──────────┼───┤
//    │   │      │           │   TD(󰘚)   │   TD(󰍛)   │   │   │   │   │        │    ←     │    ↓     │    ↑     │    →     │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼────────┼──────────┼──────────┼──────────┼──────────┼───┤
//    │   │ LGUI │   LALT    │   LCTL    │   LSFT    │   │   │   │   │        │    ←    │    ↓    │    ↑    │    →    │   │
//    ├───┼──────┼───────────┼───────────┼───────────┼───┼───┤   ├───┼────────┼──────────┼──────────┼──────────┼──────────┼───┤
//    │   │      │ TD(def_) │ TD(def_) │ TD(def_󰄮) │   │   │   │   │        │  WHEEL← │  WHEEL↓ │  WHEEL↑ │  WHEEL→ │   │
//    ├───┼──────┼───────────┼───────────┼───────────┴───┴───┘   └───┴────────┴──────────┼──────────┼──────────┼──────────┼───┤
//    │   │      │           │    ESC    │                                               │   ESC    │          │          │   │
//    └───┴──────┴───────────┴───────────┼───────────┬───┐           ┌────────┬──────────┼──────────┴──────────┴──────────┴───┘
//                                       │           │   │           │  BTN2 │   BTN1  │                                     
//                                       └───────────┼───┼───┐   ┌───┼────────┼──────────┘                                     
//                                                   │ 󰭃 │   │   │   │  BTN3 │                                                
//                                                   ├───┼───┤   ├───┼────────┤                                                
//                                                   │   │   │   │   │        │                                                
//                                                   └───┴───┘   └───┴────────┘                                                
  KC_NO , KC_NO   , KC_NO              , KC_NO              , KC_NO             , KC_NO     , KC_NO ,     KC_NO , KC_NO      , KC_NO      , KC_NO      , KC_NO    , KC_NO       , KC_NO,
  KC_NO , KC_NO   , KC_NO              , TD(TD_EE_CLR)      , TD(TD_BOOT)       , KC_NO     , KC_NO ,     KC_NO , KC_NO      , KC_LEFT    , KC_DOWN    , KC_UP    , KC_RIGHT    , KC_NO,
  KC_NO , KC_LGUI , KC_LALT            , KC_LCTL            , KC_LSFT           , KC_NO     , KC_NO ,     KC_NO , KC_NO      , KC_MS_LEFT , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT , KC_NO,
  KC_NO , KC_NO   , TD(TD_DEF_L_MEDIA) , TD(TD_DEF_L_MOUSE) , TD(TD_DEF_L_BASE) , KC_NO     , KC_NO ,     KC_NO , KC_NO      , KC_WH_L    , KC_WH_D    , KC_WH_U  , KC_WH_R     , KC_NO,
  KC_NO , KC_NO   , KC_NO              , KC_ESC             ,                                                                               KC_ESC     , KC_NO    , KC_NO       , KC_NO,
                                                              KC_NO             , KC_NO     ,                     KC_MS_BTN2 , KC_MS_BTN1                                              ,
                                                                                  KC_ORIGIN , KC_NO ,     KC_NO , KC_MS_BTN3                                                           ,
                                                                                  KC_NO     , KC_NO ,     KC_NO , KC_NO                                                                
),

[_LAYER_NUMBERS] = LAYOUT_5x7_sym(
//    ┌───┬───┬───┬───┬─────┬─────┬───┐   ┌───┬───┬───────────┬───────────┬───────────┬──────┬───┐
//    │   │   │   │   │     │     │   │   │   │   │           │           │           │      │   │
//    ├───┼───┼───┼───┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼──────┼───┤
//    │   │ 7 │ 8 │ 9 │  0  │     │   │   │   │   │   TD(󰍛)   │   TD(󰘚)   │           │      │   │
//    ├───┼───┼───┼───┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼──────┼───┤
//    │   │ 4 │ 5 │ 6 │ = + │     │   │   │   │   │   RSFT    │   RCTL    │   LALT    │ RGUI │   │
//    ├───┼───┼───┼───┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼──────┼───┤
//    │   │ 1 │ 2 │ 3 │     │     │   │   │   │   │ TD(def_󰄮) │ TD(def_) │ TD(def_) │      │   │
//    ├───┼───┼───┼───┼─────┴─────┴───┘   └───┴───┴───────────┼───────────┼───────────┼──────┼───┤
//    │   │   │   │ ⏎ │                                       │     ⏎     │           │      │   │
//    └───┴───┴───┴───┼─────┬─────┐           ┌───┬───────────┼───────────┴───────────┴──────┴───┘
//                    │    │    │           │ 󰭃 │           │                                   
//                    └─────┼─────┼───┐   ┌───┼───┼───────────┘                                   
//                          │ ESC │   │   │   │   │                                               
//                          ├─────┼───┤   ├───┼───┤                                               
//                          │     │   │   │   │   │                                               
//                          └─────┴───┘   └───┴───┘                                               
  KC_NO , KC_NO , KC_NO , KC_NO    , KC_NO        , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO                , KC_NO            , KC_NO   , KC_NO,
  KC_NO , KC_7  , KC_8  , KC_9     , KC_0         , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_BOOT)       , TD(TD_EE_CLR)        , KC_NO            , KC_NO   , KC_NO,
  KC_NO , KC_4  , KC_5  , KC_6     , KC_EQUAL     , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_RSFT           , KC_RCTL              , KC_LALT          , KC_RGUI , KC_NO,
  KC_NO , KC_1  , KC_2  , KC_3     , KC_NO        , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_DEF_L_BASE) , TD(TD_DEF_L_NUMBERS) , TD(TD_DEF_L_SYM) , KC_NO   , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_ENTER ,                                                                             KC_ENTER             , KC_NO            , KC_NO   , KC_NO,
                                     KC_BACKSPACE , KC_TAB ,                     KC_ORIGIN , KC_NO                                                                        ,
                                                    KC_ESC , KC_NO ,     KC_NO , KC_NO                                                                                    ,
                                                    KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                                    
),

[_LAYER_MEDIA] = LAYOUT_5x7_sym(
//    ┌───┬───────┬───────┬─────┬─────┬─────┬───┐   ┌───┬───┬───────────┬───────────┬───────────┬───┬───┐
//    │   │       │       │  󰖁  │    │     │   │   │   │   │           │           │           │   │   │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼───┼───┤
//    │   │  󰚱   │  󰚱 ↓  │ 󰚱 ↑ │ 󰚱  │     │   │   │   │   │   TD(󰍛)   │   TD(󰘚)   │           │   │   │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼───┼───┤
//    │   │  ←/→ │  / │   │   │     │   │   │   │   │           │           │           │   │   │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼───────────┼───────────┼───────────┼───┼───┤
//    │   │      │      │  ﱜ  │  ﱛ  │     │   │   │   │   │ TD(def_󰄮) │ TD(def_) │ TD(def_) │   │   │
//    ├───┼───────┼───────┼─────┼─────┴─────┴───┘   └───┴───┴───────────┼───────────┼───────────┼───┼───┤
//    │   │       │       │ ' " │                                       │    ' "    │           │   │   │
//    └───┴───────┴───────┴─────┼─────┬─────┐           ┌───┬───────────┼───────────┴───────────┴───┴───┘
//                              │    │    │           │   │           │                                
//                              └─────┼─────┼───┐   ┌───┼───┼───────────┘                                
//                                    │ ESC │   │   │   │ 󰭃 │                                            
//                                    ├─────┼───┤   ├───┼───┤                                            
//                                    │     │   │   │   │   │                                            
//                                    └─────┴───┘   └───┴───┘                                            
  KC_NO , KC_NO       , KC_NO   , AU_OFF   , AU_ON        , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO              , KC_NO            , KC_NO , KC_NO,
  KC_NO , KC_PRNT_HPT , HF_DWLD , HF_DWLU  , HF_TOGG      , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_BOOT)       , TD(TD_EE_CLR)      , KC_NO            , KC_NO , KC_NO,
  KC_NO , RGB_HUD     , RGB_VAD , RGB_MOD  , RGB_TOG      , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO              , KC_NO            , KC_NO , KC_NO,
  KC_NO , KC_BRID     , KC_BRIU , KC_VOLD  , KC_VOLU      , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_DEF_L_BASE) , TD(TD_DEF_L_MEDIA) , TD(TD_DEF_L_SYM) , KC_NO , KC_NO,
  KC_NO , KC_NO       , KC_NO   , KC_QUOTE ,                                                                             KC_QUOTE           , KC_NO            , KC_NO , KC_NO,
                                             KC_BACKSPACE , KC_TAB ,                     KC_NO     , KC_NO                                                                    ,
                                                            KC_ESC , KC_NO ,     KC_NO , KC_ORIGIN                                                                            ,
                                                            KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                                
)
};
// clang-format on
