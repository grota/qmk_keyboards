#include "grota/grota.h"
#include "grota/process_records.h"
#include "grota/tap_dance.h"
#include "qmk_firmware/quantum/keycodes.h"
#include QMK_KEYBOARD_H
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER_BASE] = LAYOUT_5x7_sym(
//    ┌───┬──────────┬──────────┬────────────┬────────────┬──────┬─────────┐   ┌──────┬──────┬────────────┬────────────┬──────────┬──────────┬───┐
//    │   │   1 F1   │   2 F2   │    3 F3    │    4 F4    │ 5 F5 │  6 F6   │   │ 7 F7 │ 8 F8 │    9 F9    │   0 F10    │   F11    │   F12    │   │
//    ├───┼──────────┼──────────┼────────────┼────────────┼──────┼─────────┤   ├──────┼──────┼────────────┼────────────┼──────────┼──────────┼───┤
//    │   │    Q     │    F     │     W      │     R      │ = +  │         │   │      │ DEL  │     H      │     J      │    K     │    L     │   │
//    ├───┼──────────┼──────────┼────────────┼────────────┼──────┼─────────┤   ├──────┼──────┼────────────┼────────────┼──────────┼──────────┼───┤
//    │   │ Gui_T(A) │ Alt_T(S) │ Shift_T(D) │ Ctrl_T(G)  │  X   │         │   │      │  Y   │ Ctrl_T(C)  │ Shift_T(E) │ Alt_T(I) │ Gui_T(O) │   │
//    ├───┼──────────┼──────────┼────────────┼────────────┼──────┼─────────┤   ├──────┼──────┼────────────┼────────────┼──────────┼──────────┼───┤
//    │   │    Z     │    T     │     M      │ AltGr_T(V) │ ; :  │  HOME   │   │ END  │ , <  │ AltGr_T(N) │     P      │    B     │    U     │   │
//    ├───┼──────────┼──────────┼────────────┼────────────┴──────┴─────────┘   └──────┴──────┴────────────┼────────────┼──────────┼──────────┼───┤
//    │   │          │          │            │                                                            │            │          │          │   │
//    └───┴──────────┴──────────┴────────────┼────────────┬──────┐                    ┌──────┬────────────┼────────────┴──────────┴──────────┴───┘
//                                           │          │    │                    │ ⏎  󱔁 │     ␣      │                                       
//                                           └────────────┼──────┼─────────┐   ┌──────┼──────┼────────────┘                                       
//                                                        │ 󱊷   │ LCTL(C) │   │      │ '   │                                                    
//                                                        ├──────┼─────────┤   ├──────┼──────┤                                                    
//                                                        │      │         │   │      │      │                                                    
//                                                        └──────┴─────────┘   └──────┴──────┘                                                    
  KC_NO , KC_C_1       , KC_C_2       , KC_C_3       , KC_C_4       , KC_C_5     , KC_C_6     ,     KC_C_7 , KC_C_8      , KC_C_9       , KC_C_0       , KC_F11       , KC_F12       , KC_NO,
  KC_NO , KC_Q         , KC_F         , KC_W         , KC_R         , KC_EQUAL   , KC_NO      ,     KC_NO  , KC_DELETE   , KC_H         , KC_J         , KC_K         , KC_L         , KC_NO,
  KC_NO , LGUI_T(KC_A) , LALT_T(KC_S) , LSFT_T(KC_D) , LCTL_T(KC_G) , KC_X       , KC_NO      ,     KC_NO  , KC_Y        , RCTL_T(KC_C) , RSFT_T(KC_E) , LALT_T(KC_I) , RGUI_T(KC_O) , KC_NO,
  KC_NO , KC_Z         , KC_T         , KC_M         , RALT_T(KC_V) , KC_SCLN    , KC_HOME    ,     KC_END , KC_COMMA    , RALT_T(KC_N) , KC_P         , KC_B         , KC_U         , KC_NO,
  KC_NO , KC_NO        , KC_NO        , KC_NO        ,                                                                                    KC_NO        , KC_NO        , KC_NO        , KC_NO,
                                                       BSPC_MOUSE   , TAB_SYM1   ,                           ENTER_SYM2  , KC_SPACE                                                         ,
                                                                      ESC_NUMPAD , LCTL(KC_C) ,     KC_NO  , QUOTE_MEDIA                                                                    ,
                                                                      KC_NO      , KC_NO      ,     KC_NO  , KC_NO                                                                          
),

[_LAYER_SYM1] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬──────┬─────┬───┐   ┌───┬─────┬───┬─────┬─────┬───┬───┐
//    │  │      │      │      │      │     │   │   │   │     │   │     │     │   │   │
//    ├───┼──────┼──────┼──────┼──────┼─────┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │ 󰘚 │      │ TD 󱔁 │ TD  │ TD  │     │   │   │   │     │ { │ ` ~ │ \ | │ } │   │
//    ├───┼──────┼──────┼──────┼──────┼─────┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │   │ LGUI │ LALT │ LSFT │ LCTL │     │   │   │   │     │ ( │ , < │ . > │ ) │   │
//    ├───┼──────┼──────┼──────┼──────┼─────┼───┤   ├───┼─────┼───┼─────┼─────┼───┼───┤
//    │   │      │      │      │      │     │   │   │   │     │ [ │ / ? │ - _ │ ] │   │
//    ├───┼──────┼──────┼──────┼──────┴─────┴───┘   └───┴─────┴───┼─────┼─────┼───┼───┤
//    │   │      │      │     │                                  │    │ ; : │   │   │
//    └───┴──────┴──────┴──────┼──────┬─────┐           ┌─────┬───┼─────┴─────┴───┴───┘
//                             │     │  󰭃  │           │  ⏎  │ ␣ │                    
//                             └──────┼─────┼───┐   ┌───┼─────┼───┘                    
//                                    │ ESC │   │   │   │ ' " │                        
//                                    ├─────┼───┤   ├───┼─────┤                        
//                                    │     │   │   │   │     │                        
//                                    └─────┴───┘   └───┴─────┘                        
  QK_BOOT , KC_NO   , KC_NO             , KC_NO             , KC_NO             , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_NO    , KC_NO    , KC_NO        , KC_NO   , KC_NO,
  EE_CLR  , KC_NO   , TD(TD_DEF_L_SYM2) , TD(TD_DEF_L_SYM1) , TD(TD_DEF_L_BASE) , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_LCBR  , KC_GRAVE , KC_BACKSLASH , KC_RCBR , KC_NO,
  KC_NO   , KC_LGUI , KC_LALT           , KC_LSFT           , KC_LCTL           , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_LPRN  , KC_COMMA , KC_DOT       , KC_RPRN , KC_NO,
  KC_NO   , KC_NO   , KC_NO             , KC_NO             , KC_NO             , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_LBRC  , KC_SLASH , KC_MINUS     , KC_RBRC , KC_NO,
  KC_NO   , KC_NO   , KC_NO             , KC_TAB            ,                                                                           KC_TAB   , KC_SCLN      , KC_NO   , KC_NO,
                                                              KC_BSPC           , KC_ORIGIN ,                     KC_ENTER , KC_SPACE                                            ,
                                                                                  KC_ESC    , KC_NO ,     KC_NO , KC_QUOTE                                                       ,
                                                                                  KC_NO     , KC_NO ,     KC_NO , KC_NO                                                          
),

[_LAYER_SYM2] = LAYOUT_5x7_sym(
//    ┌───┬───┬─────┬─────┬─────┬─────┬───┐   ┌───┬───┬────────┬────────┬────────┬──────┬───┐
//    │   │   │     │     │     │     │   │   │   │   │        │        │        │      │  │
//    ├───┼───┼─────┼─────┼─────┼─────┼───┤   ├───┼───┼────────┼────────┼────────┼──────┼───┤
//    │   │ % │ ? / │  $  │ | \ │     │   │   │   │   │  TD   │  TD 󱔁  │  TD   │      │ 󰘚 │
//    ├───┼───┼─────┼─────┼─────┼─────┼───┤   ├───┼───┼────────┼────────┼────────┼──────┼───┤
//    │   │ 󰭃 │  *  │ : ; │ " ' │     │   │   │   │   │  RCTL  │  RSFT  │  LALT  │ RGUI │   │
//    ├───┼───┼─────┼─────┼─────┼─────┼───┤   ├───┼───┼────────┼────────┼────────┼──────┼───┤
//    │   │ ^ │ > . │ _ - │ + = │     │   │   │   │   │ AltrGr │ Page  │ Page  │      │   │
//    ├───┼───┼─────┼─────┼─────┴─────┴───┘   └───┴───┴────────┼────────┼────────┼──────┼───┤
//    │   │   │     │  ⏎  │                                    │   ⏎    │        │      │   │
//    └───┴───┴─────┴─────┼─────┬─────┐           ┌───┬────────┼────────┴────────┴──────┴───┘
//                        │    │    │           │ 󰭃 │        │                             
//                        └─────┼─────┼───┐   ┌───┼───┼────────┘                             
//                              │ ESC │   │   │   │   │                                      
//                              ├─────┼───┤   ├───┼───┤                                      
//                              │     │   │   │   │   │                                      
//                              └─────┴───┘   └───┴───┘                                      
  KC_NO , KC_NO      , KC_NO     , KC_NO     , KC_NO     , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO             , KC_NO             , KC_NO   , QK_BOOT,
  KC_NO , KC_PERCENT , KC_C_QUES , KC_DOLLAR , KC_C_PIPE , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_DEF_L_BASE) , TD(TD_DEF_L_SYM2) , TD(TD_DEF_L_SYM1) , KC_NO   , EE_CLR ,
  KC_NO , KC_ORIGIN  , KC_ASTR   , KC_C_COLN , KC_C_DQUO , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_RCTL           , KC_RSFT           , KC_LALT           , KC_RGUI , KC_NO  ,
  KC_NO , KC_CIRC    , KC_C_RABK , KC_C_UNDS , KC_C_PLUS , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_RALT           , KC_PGDN           , KC_PGUP           , KC_NO   , KC_NO  ,
  KC_NO , KC_NO      , KC_NO     , KC_ENTER  ,                                                                          KC_ENTER          , KC_NO             , KC_NO   , KC_NO  ,
                                               KC_BSPC   , KC_TAB ,                     KC_ORIGIN , KC_NO                                                                        ,
                                                           KC_ESC , KC_NO ,     KC_NO , KC_NO                                                                                    ,
                                                           KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                                    
),

[_LAYER_MOUSE] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬──────┬───┬───┐   ┌───┬────────┬────────┬──────┬──────┬──────┬───┐
//    │  │      │      │      │      │   │   │   │   │        │        │      │      │      │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼──────┼──────┼──────┼───┤
//    │ 󰘚 │      │      │ TD  │ TD  │   │   │   │   │        │   ←    │  ↓   │  ↑   │  →   │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼──────┼──────┼──────┼───┤
//    │   │ LGUI │ LALT │ LSFT │ LCTL │   │   │   │   │        │   ←   │  ↓  │  ↑  │  →  │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼──────┼──────┼──────┼───┤
//    │   │      │      │      │      │   │   │   │   │        │  󰠳 ←  │ 󰠳 ↓ │ 󰠳 ↑ │ 󰠳 → │   │
//    ├───┼──────┼──────┼──────┼──────┴───┴───┘   └───┴────────┴────────┼──────┼──────┼──────┼───┤
//    │   │      │      │     │                                        │     │      │      │   │
//    └───┴──────┴──────┴──────┼──────┬───┐           ┌────────┬────────┼──────┴──────┴──────┴───┘
//                             │  󰭃   │   │           │  BTN2 │  BTN1 │                         
//                             └──────┼───┼───┐   ┌───┼────────┼────────┘                         
//                                    │   │   │   │   │  BTN3 │                                  
//                                    ├───┼───┤   ├───┼────────┤                                  
//                                    │   │   │   │   │        │                                  
//                                    └───┴───┘   └───┴────────┘                                  
  QK_BOOT , KC_NO   , KC_NO   , KC_NO              , KC_NO             , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_NO      , KC_NO        , KC_NO    , KC_NO       , KC_NO,
  EE_CLR  , KC_NO   , KC_NO   , TD(TD_DEF_L_MOUSE) , TD(TD_DEF_L_BASE) , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_LEFT    , KC_DOWN      , KC_UP    , KC_RIGHT    , KC_NO,
  KC_NO   , KC_LGUI , KC_LALT , KC_LSFT            , KC_LCTL           , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_MS_LEFT , KC_MS_DOWN   , KC_MS_UP , KC_MS_RIGHT , KC_NO,
  KC_NO   , KC_NO   , KC_NO   , KC_NO              , KC_NO             , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_WH_L    , KC_WH_D      , KC_WH_U  , KC_WH_R     , KC_NO,
  KC_NO   , KC_NO   , KC_NO   , KC_BACKSPACE       ,                                                                           KC_BACKSPACE , KC_NO    , KC_NO       , KC_NO,
                                                     KC_ORIGIN         , KC_NO ,                     KC_MS_BTN2 , KC_MS_BTN1                                                ,
                                                                         KC_NO , KC_NO ,     KC_NO , KC_MS_BTN3                                                             ,
                                                                         KC_NO , KC_NO ,     KC_NO , KC_NO                                                                  
),

[_LAYER_NUMPAD] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬────────┬───┬───┐   ┌───┬─────┬──────┬──────┬───────┬─────┬───┐
//    │  │      │      │      │        │   │   │   │   │     │      │      │       │     │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼──────┼───────┼─────┼───┤
//    │ 󰘚 │      │ TD  │ TD  │  TD   │   │   │   │   │     │ 7 F7 │ 8 F8 │ 9 F9  │ / ? │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼──────┼───────┼─────┼───┤
//    │   │ LGUI │ LALT │ LSFT │  LCTL  │   │   │   │   │     │ 4 F4 │ 5 F5 │ 6 F6  │  *  │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼──────┼───────┼─────┼───┤
//    │   │      │      │      │ AltrGr │   │   │   │   │     │ 1 F1 │ 2 F2 │ 3 F3  │ - _ │   │
//    ├───┼──────┼──────┼──────┼────────┴───┴───┘   └───┴─────┴──────┼──────┼───────┼─────┼───┤
//    │   │      │      │ ESC  │                                     │ ESC  │ 0 F10 │ + = │   │
//    └───┴──────┴──────┴──────┼────────┬───┐           ┌─────┬──────┼──────┴───────┴─────┴───┘
//                             │       │  │           │  ⏎  │  ␣   │                         
//                             └────────┼───┼───┐   ┌───┼─────┼──────┘                         
//                                      │ 󰭃 │   │   │   │ ' " │                                
//                                      ├───┼───┤   ├───┼─────┤                                
//                                      │   │   │   │   │     │                                
//                                      └───┴───┘   └───┴─────┘                                
  QK_BOOT , KC_NO   , KC_NO              , KC_NO               , KC_NO             , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_NO    , KC_NO  , KC_NO  , KC_NO     , KC_NO,
  EE_CLR  , KC_NO   , TD(TD_DEF_L_MEDIA) , TD(TD_DEF_L_NUMPAD) , TD(TD_DEF_L_BASE) , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_C_7   , KC_C_8 , KC_C_9 , KC_SLASH  , KC_NO,
  KC_NO   , KC_LGUI , KC_LALT            , KC_LSFT             , KC_LCTL           , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_C_4   , KC_C_5 , KC_C_6 , KC_ASTR   , KC_NO,
  KC_NO   , KC_NO   , KC_NO              , KC_NO               , KC_RALT           , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_C_1   , KC_C_2 , KC_C_3 , KC_MINUS  , KC_NO,
  KC_NO   , KC_NO   , KC_NO              , KC_ESC              ,                                                                           KC_ESC , KC_C_0 , KC_C_PLUS , KC_NO,
                                                                 KC_BACKSPACE      , KC_TAB    ,                     KC_ENTER , KC_SPACE                                      ,
                                                                                     KC_ORIGIN , KC_NO ,     KC_NO , KC_QUOTE                                                 ,
                                                                                     KC_NO     , KC_NO ,     KC_NO , KC_NO                                                    
),

[_LAYER_MEDIA] = LAYOUT_5x7_sym(
//    ┌───┬───────┬───────┬─────┬─────┬─────┬───┐   ┌───┬───┬──────┬──────┬──────┬───┬───┐
//    │   │       │       │  󰖁  │    │     │   │   │   │   │      │      │      │   │  │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │ 󰘚 │  󰚱   │  󰚱 ↓  │ 󰚱 ↑ │ 󰚱  │     │   │   │   │   │ TD  │ TD  │ TD  │   │ 󰘚 │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │   │  ←/→ │  / │   │   │     │   │   │   │   │      │ LSFT │      │   │   │
//    ├───┼───────┼───────┼─────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │   │      │      │  ﱜ  │  ﱛ  │     │   │   │   │   │      │      │      │   │   │
//    ├───┼───────┼───────┼─────┼─────┴─────┴───┘   └───┴───┴──────┼──────┼──────┼───┼───┤
//    │   │       │       │ ' " │                                  │ ' "  │      │   │   │
//    └───┴───────┴───────┴─────┼─────┬─────┐           ┌───┬──────┼──────┴──────┴───┴───┘
//                              │    │    │           │   │      │                      
//                              └─────┼─────┼───┐   ┌───┼───┼──────┘                      
//                                    │ ESC │   │   │   │ 󰭃 │                             
//                                    ├─────┼───┤   ├───┼───┤                             
//                                    │     │   │   │   │   │                             
//                                    └─────┴───┘   └───┴───┘                             
  KC_NO  , KC_NO       , KC_NO   , AU_OFF   , AU_ON   , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO              , KC_NO              , KC_NO , QK_BOOT,
  EE_CLR , KC_PRNT_HPT , HF_DWLD , HF_DWLU  , HF_TOGG , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD(TD_DEF_L_BASE) , TD(TD_DEF_L_MEDIA) , TD(TD_DEF_L_MOUSE) , KC_NO , EE_CLR ,
  KC_NO  , RGB_HUD     , RGB_VAD , RGB_MOD  , RGB_TOG , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_LSFT            , KC_NO              , KC_NO , KC_NO  ,
  KC_NO  , KC_BRID     , KC_BRIU , KC_VOLD  , KC_VOLU , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO             , KC_NO              , KC_NO              , KC_NO , KC_NO  ,
  KC_NO  , KC_NO       , KC_NO   , KC_QUOTE ,                                                                        KC_QUOTE           , KC_NO              , KC_NO , KC_NO  ,
                                              KC_BSPC , KC_TAB ,                     KC_NO     , KC_NO                                                                        ,
                                                        KC_ESC , KC_NO ,     KC_NO , KC_ORIGIN                                                                                ,
                                                        KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                                    
)
};
// clang-format on
