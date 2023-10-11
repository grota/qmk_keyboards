#include "grota/grota.h"
#include "grota/process_records.h"
#include "grota/tap_dance.h"
#include "qmk_firmware/quantum/keycodes.h"
#include "qmk_firmware/quantum/keymap_extras/keymap_us.h"
#include QMK_KEYBOARD_H
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER_BASE] = LAYOUT_5x7_sym(
//    ┌───┬──────────┬──────────┬───────────┬────────────┬──────┬───┐   ┌───┬──────┬────────────┬───────────┬──────────┬──────────┬───┐
//    │   │          │          │           │            │      │   │   │   │      │            │           │          │          │   │
//    ├───┼──────────┼──────────┼───────────┼────────────┼──────┼───┤   ├───┼──────┼────────────┼───────────┼──────────┼──────────┼───┤
//    │   │    Q     │    F     │     W     │     R      │ = +  │   │   │   │ - _  │     H      │     J     │    K     │    L     │   │
//    ├───┼──────────┼──────────┼───────────┼────────────┼──────┼───┤   ├───┼──────┼────────────┼───────────┼──────────┼──────────┼───┤
//    │   │ Gui_T(A) │ Alt_T(S) │ Ctrl_T(D) │ Shift_T(G) │  X   │   │   │   │  Y   │ Shift_T(C) │ Ctrl_T(E) │ Alt_T(I) │ Gui_T(O) │   │
//    ├───┼──────────┼──────────┼───────────┼────────────┼──────┼───┤   ├───┼──────┼────────────┼───────────┼──────────┼──────────┼───┤
//    │   │    Z     │    T     │     M     │ AltGr_T(V) │ , <  │   │   │   │ . >  │ AltGr_T(N) │     P     │    B     │    U     │   │
//    ├───┼──────────┼──────────┼───────────┼────────────┴──────┴───┘   └───┴──────┴────────────┼───────────┼──────────┼──────────┼───┤
//    │   │          │  Page   │  Page    │                                                   │  Page    │  Page   │          │   │
//    └───┴──────────┴──────────┴───────────┼────────────┬──────┐           ┌──────┬────────────┼───────────┴──────────┴──────────┴───┘
//                                          │    󰁮  󰍽    │ 󰌒   │           │ ⏎  󱔁 │    ␣      │                                      
//                                          └────────────┼──────┼───┐   ┌───┼──────┼────────────┘                                      
//                                                       │ 󱊷   │   │   │   │ '  󰃠 │                                                   
//                                                       ├──────┼───┤   ├───┼──────┤                                                   
//                                                       │      │   │   │   │      │                                                   
//                                                       └──────┴───┘   └───┴──────┘                                                   
  KC_NO , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO      , KC_NO ,     KC_NO , KC_NO       , KC_NO        , KC_NO        , KC_NO        , KC_NO        , KC_NO,
  KC_NO , KC_Q         , KC_F         , KC_W         , KC_R         , KC_EQUAL   , KC_NO ,     KC_NO , KC_MINUS    , KC_H         , KC_J         , KC_K         , KC_L         , KC_NO,
  KC_NO , LGUI_T(KC_A) , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_G) , KC_X       , KC_NO ,     KC_NO , KC_Y        , RSFT_T(KC_C) , RCTL_T(KC_E) , LALT_T(KC_I) , RGUI_T(KC_O) , KC_NO,
  KC_NO , KC_Z         , KC_T         , KC_M         , RALT_T(KC_V) , KC_COMMA   , KC_NO ,     KC_NO , KC_DOT      , RALT_T(KC_N) , KC_P         , KC_B         , KC_U         , KC_NO,
  KC_NO , KC_NO        , KC_PGUP      , KC_PGDN      ,                                                                              KC_PGUP      , KC_PGDN      , KC_NO        , KC_NO,
                                                       BSPC_MOUSE   , TAB_SYM1   ,                     ENTER_SYM2  , SPACE_NAV                                                        ,
                                                                      ESC_NUMPAD , KC_NO ,     KC_NO , QUOTE_MEDIA                                                                    ,
                                                                      KC_NO      , KC_NO ,     KC_NO , KC_NO                                                                          
),

[_LAYER_SYM1] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬────────┬─────┬───┐   ┌───┬─────┬─────┬─────┬─────┬───┬───┐
//    │  │  󰘚   │      │      │        │     │   │   │   │     │     │     │     │   │   │
//    ├───┼──────┼──────┼──────┼────────┼─────┼───┤   ├───┼─────┼─────┼─────┼─────┼───┼───┤
//    │  │      │ TD 󱔁 │ TD  │  TD   │     │   │   │   │  [  │ = + │ - _ │ > . │ ! │   │
//    ├───┼──────┼──────┼──────┼────────┼─────┼───┤   ├───┼─────┼─────┼─────┼─────┼───┼───┤
//    │   │ LGUI │ LALT │ LCTL │  LSFT  │     │   │   │   │  ^  │ , < │ . > │ : ; │ * │   │
//    ├───┼──────┼──────┼──────┼────────┼─────┼───┤   ├───┼─────┼─────┼─────┼─────┼───┼───┤
//    │   │      │      │ DEL  │ AltrGr │     │   │   │   │  ]  │ / ? │ \ | │ < , │ ~ │   │
//    ├───┼──────┼──────┼──────┼────────┴─────┴───┘   └───┴─────┴─────┼─────┼─────┼───┼───┤
//    │   │      │      │  󰌒   │                                      │  󰌒  │  +  │   │   │
//    └───┴──────┴──────┴──────┼────────┬─────┐           ┌─────┬─────┼─────┴─────┴───┴───┘
//                             │   󰁮    │  󰭃  │           │  ⏎  │  ␣  │                    
//                             └────────┼─────┼───┐   ┌───┼─────┼─────┘                    
//                                      │ ESC │   │   │   │ ' " │                          
//                                      ├─────┼───┤   ├───┼─────┤                          
//                                      │     │   │   │   │     │                          
//                                      └─────┴───┘   └───┴─────┘                          
  QK_BOOT   , EE_CLR  , KC_NO       , KC_NO       , KC_NO       , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_NO    , KC_NO    , KC_NO     , KC_NO      , KC_NO,
  QK_REBOOT , KC_NO   , TD_DEF_SYM2 , TD_DEF_SYM1 , TD_DEF_BASE , KC_NO     , KC_NO ,     KC_NO , KC_LBRC  , KC_EQUAL , KC_MINUS , KC_C_RABK , KC_EXCLAIM , KC_NO,
  KC_NO     , KC_LGUI , KC_LALT     , KC_LCTL     , KC_LSFT     , KC_NO     , KC_NO ,     KC_NO , KC_CIRC  , KC_COMMA , KC_DOT   , KC_C_COLN , KC_ASTR    , KC_NO,
  KC_NO     , KC_NO   , KC_NO       , KC_DELETE   , KC_RALT     , KC_NO     , KC_NO ,     KC_NO , KC_RBRC  , KC_SLASH , KC_BSLS  , KC_C_LABK , KC_TILDE   , KC_NO,
  KC_NO     , KC_NO   , KC_NO       , KC_TAB      ,                                                                     KC_TAB   , KC_PLUS   , KC_NO      , KC_NO,
                                                    KC_BSPC     , KC_ORIGIN ,                     KC_ENTER , KC_SPACE                                            ,
                                                                  KC_ESC    , KC_NO ,     KC_NO , KC_QUOTE                                                       ,
                                                                  KC_NO     , KC_NO ,     KC_NO , KC_NO                                                          
),

[_LAYER_SYM2] = LAYOUT_5x7_sym(
//    ┌───┬─────┬─────┬─────┬─────┬─────┬───┐   ┌───┬─────┬────────┬──────┬──────┬──────┬───┐
//    │   │     │     │     │     │     │   │   │   │     │        │      │      │  󰘚   │  │
//    ├───┼─────┼─────┼─────┼─────┼─────┼───┤   ├───┼─────┼────────┼──────┼──────┼──────┼───┤
//    │   │ ` ~ │  (  │  )  │ ; : │  %  │   │   │   │     │  TD   │ TD 󱔁 │ TD  │      │  │
//    ├───┼─────┼─────┼─────┼─────┼─────┼───┤   ├───┼─────┼────────┼──────┼──────┼──────┼───┤
//    │   │  #  │  $  │ _ - │ " ' │ ' " │   │   │   │     │  LSFT  │ RCTL │ LALT │ RGUI │   │
//    ├───┼─────┼─────┼─────┼─────┼─────┼───┤   ├───┼─────┼────────┼──────┼──────┼──────┼───┤
//    │   │ | \ │ { [ │ } ] │ ? / │  @  │   │   │   │     │ AltrGr │      │      │      │   │
//    ├───┼─────┼─────┼─────┼─────┴─────┴───┘   └───┴─────┴────────┼──────┼──────┼──────┼───┤
//    │   │     │  &  │  ⏎  │                                      │  ⏎   │      │      │   │
//    └───┴─────┴─────┴─────┼─────┬─────┐           ┌─────┬────────┼──────┴──────┴──────┴───┘
//                          │  󰁮  │  󰌒  │           │  󰭃  │   ␣    │                         
//                          └─────┼─────┼───┐   ┌───┼─────┼────────┘                         
//                                │ ESC │   │   │   │ ' " │                                  
//                                ├─────┼───┤   ├───┼─────┤                                  
//                                │     │   │   │   │     │                                  
//                                └─────┴───┘   └───┴─────┘                                  
  KC_NO , KC_NO     , KC_NO     , KC_NO     , KC_NO     , KC_NO    , KC_NO ,     KC_NO , KC_NO     , KC_NO       , KC_NO       , KC_NO       , EE_CLR  , QK_BOOT  ,
  KC_NO , KC_GRAVE  , KC_LPRN   , KC_RPRN   , KC_SCLN   , KC_PERC  , KC_NO ,     KC_NO , KC_NO     , TD_DEF_BASE , TD_DEF_SYM2 , TD_DEF_SYM1 , KC_NO   , QK_REBOOT,
  KC_NO , KC_HASH   , KC_DOLLAR , KC_C_UNDS , KC_C_DQUO , KC_QUOTE , KC_NO ,     KC_NO , KC_NO     , KC_LSFT     , KC_RCTL     , KC_LALT     , KC_RGUI , KC_NO    ,
  KC_NO , KC_C_PIPE , KC_C_LCBR , KC_C_RCBR , KC_C_QUES , KC_AT    , KC_NO ,     KC_NO , KC_NO     , KC_RALT     , KC_NO       , KC_NO       , KC_NO   , KC_NO    ,
  KC_NO , KC_NO     , KC_AMPR   , KC_ENTER  ,                                                                      KC_ENTER    , KC_NO       , KC_NO   , KC_NO    ,
                                              KC_BSPC   , KC_TAB   ,                     KC_ORIGIN , KC_SPACE                                                     ,
                                                          KC_ESC   , KC_NO ,     KC_NO , KC_QUOTE                                                                 ,
                                                          KC_NO    , KC_NO ,     KC_NO , KC_NO                                                                    
),

[_LAYER_MOUSE] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬──────┬───┬───┐   ┌───┬────────┬────────┬────────┬────────┬───┬───┐
//    │  │  󰘚   │      │      │      │   │   │   │   │        │        │        │        │   │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼────────┼────────┼───┼───┤
//    │  │      │ TD  │ TD 󰍽 │ TD  │   │   │   │   │        │  󰍽󰠳 ↑  │  󰍽 ↑   │  󰍽󰠳 ↓  │   │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼────────┼────────┼───┼───┤
//    │   │ LGUI │ LALT │ LCTL │ LSFT │   │   │   │   │        │  󰍽 ←   │  󰍽 ↓   │  󰍽 →   │   │   │
//    ├───┼──────┼──────┼──────┼──────┼───┼───┤   ├───┼────────┼────────┼────────┼────────┼───┼───┤
//    │   │      │      │      │      │   │   │   │   │        │        │ Page  │ Page  │   │   │
//    ├───┼──────┼──────┼──────┼──────┴───┴───┘   └───┴────────┴────────┼────────┼────────┼───┼───┤
//    │   │      │      │  󰁮   │                                        │   󰁮    │        │   │   │
//    └───┴──────┴──────┴──────┼──────┬───┐           ┌────────┬────────┼────────┴────────┴───┴───┘
//                             │  󰭃   │   │           │ 󰍽 BTN2 │ 󰍽 BTN1 │                          
//                             └──────┼───┼───┐   ┌───┼────────┼────────┘                          
//                                    │   │   │   │   │ 󰍽 BTN3 │                                   
//                                    ├───┼───┤   ├───┼────────┤                                   
//                                    │   │   │   │   │        │                                   
//                                    └───┴───┘   └───┴────────┘                                   
  QK_BOOT   , EE_CLR  , KC_NO      , KC_NO        , KC_NO       , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_NO      , KC_NO        , KC_NO       , KC_NO , KC_NO,
  QK_REBOOT , KC_NO   , TD_DEF_NAV , TD_DEF_MOUSE , TD_DEF_BASE , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_WH_U    , KC_MS_UP     , KC_WH_D     , KC_NO , KC_NO,
  KC_NO     , KC_LGUI , KC_LALT    , KC_LCTL      , KC_LSFT     , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_MS_LEFT , KC_MS_DOWN   , KC_MS_RIGHT , KC_NO , KC_NO,
  KC_NO     , KC_NO   , KC_NO      , KC_NO        , KC_NO       , KC_NO , KC_NO ,     KC_NO , KC_NO      , KC_NO      , KC_PGUP      , KC_PGDN     , KC_NO , KC_NO,
  KC_NO     , KC_NO   , KC_NO      , KC_BACKSPACE ,                                                                     KC_BACKSPACE , KC_NO       , KC_NO , KC_NO,
                                                    KC_ORIGIN   , KC_NO ,                     KC_MS_BTN2 , KC_MS_BTN1                                             ,
                                                                  KC_NO , KC_NO ,     KC_NO , KC_MS_BTN3                                                          ,
                                                                  KC_NO , KC_NO ,     KC_NO , KC_NO                                                               
),

[_LAYER_NAV] = LAYOUT_5x7_sym(
//    ┌───┬───┬────────┬────────┬───┬─────┬───┐   ┌───┬───┬──────┬──────┬──────┬──────┬───┐
//    │   │   │        │        │   │     │   │   │   │   │      │      │      │  󰘚   │  │
//    ├───┼───┼────────┼────────┼───┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼──────┼───┤
//    │   │   │   󰞓    │   ↑    │ 󰞔 │     │   │   │   │   │ TD  │ TD  │ TD 󰍽 │      │  │
//    ├───┼───┼────────┼────────┼───┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼──────┼───┤
//    │   │   │   ←    │   ↓    │ → │     │   │   │   │   │ RSFT │ RCTL │ LALT │ LGUI │   │
//    ├───┼───┼────────┼────────┼───┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼──────┼───┤
//    │   │   │ Page  │ Page  │   │     │   │   │   │   │      │      │      │      │   │
//    ├───┼───┼────────┼────────┼───┴─────┴───┘   └───┴───┴──────┼──────┼──────┼──────┼───┤
//    │   │   │        │   ␣    │                                │  ␣   │      │      │   │
//    └───┴───┴────────┴────────┼───┬─────┐           ┌───┬──────┼──────┴──────┴──────┴───┘
//                              │ 󰁮 │  󰌒  │           │   │  󰭃   │                         
//                              └───┼─────┼───┐   ┌───┼───┼──────┘                         
//                                  │ ESC │   │   │   │   │                                
//                                  ├─────┼───┤   ├───┼───┤                                
//                                  │     │   │   │   │   │                                
//                                  └─────┴───┘   └───┴───┘                                
  KC_NO , KC_NO , KC_NO   , KC_NO    , KC_NO    , KC_NO  , KC_NO ,     KC_NO , KC_NO , KC_NO       , KC_NO      , KC_NO        , EE_CLR  , QK_BOOT  ,
  KC_NO , KC_NO , KC_HOME , KC_UP    , KC_END   , KC_NO  , KC_NO ,     KC_NO , KC_NO , TD_DEF_BASE , TD_DEF_NAV , TD_DEF_MOUSE , KC_NO   , QK_REBOOT,
  KC_NO , KC_NO , KC_LEFT , KC_DOWN  , KC_RIGHT , KC_NO  , KC_NO ,     KC_NO , KC_NO , KC_RSFT     , KC_RCTL    , KC_LALT      , KC_LGUI , KC_NO    ,
  KC_NO , KC_NO , KC_PGUP , KC_PGDN  , KC_NO    , KC_NO  , KC_NO ,     KC_NO , KC_NO , KC_NO       , KC_NO      , KC_NO        , KC_NO   , KC_NO    ,
  KC_NO , KC_NO , KC_NO   , KC_SPACE ,                                                               KC_SPACE   , KC_NO        , KC_NO   , KC_NO    ,
                                       KC_BSPC  , KC_TAB ,                     KC_NO , KC_ORIGIN                                                    ,
                                                  KC_ESC , KC_NO ,     KC_NO , KC_NO                                                                ,
                                                  KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                
),

[_LAYER_NUMPAD] = LAYOUT_5x7_sym(
//    ┌───┬──────┬──────┬──────┬────────┬───┬───┐   ┌───┬─────┬──────┬───────┬──────┬─────┬───┐
//    │  │  󰘚   │      │      │        │   │   │   │   │     │      │       │      │     │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼───────┼──────┼─────┼───┤
//    │  │      │ TD 󰃠 │ TD  │  TD   │   │   │   │   │  (  │ 7 F7 │ 8 F8  │ 9 F9 │ / ? │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼───────┼──────┼─────┼───┤
//    │   │ LGUI │ LALT │ LCTL │  LSFT  │   │   │   │   │  )  │ 4 F4 │ 5 F5  │ 6 F6 │  *  │   │
//    ├───┼──────┼──────┼──────┼────────┼───┼───┤   ├───┼─────┼──────┼───────┼──────┼─────┼───┤
//    │   │      │      │      │ AltrGr │   │   │   │   │     │ 1 F1 │ 2 F2  │ 3 F3 │ - _ │   │
//    ├───┼──────┼──────┼──────┼────────┴───┴───┘   └───┴─────┴──────┼───────┼──────┼─────┼───┤
//    │   │      │      │ ESC  │                                     │ 0 F10 │ . >  │ + = │   │
//    └───┴──────┴──────┴──────┼────────┬───┐           ┌─────┬──────┼───────┴──────┴─────┴───┘
//                             │   󰁮    │ 󰌒 │           │  ⏎  │  ␣   │                         
//                             └────────┼───┼───┐   ┌───┼─────┼──────┘                         
//                                      │ 󰭃 │   │   │   │ ' " │                                
//                                      ├───┼───┤   ├───┼─────┤                                
//                                      │   │   │   │   │     │                                
//                                      └───┴───┘   └───┴─────┘                                
  QK_BOOT   , EE_CLR  , KC_NO        , KC_NO         , KC_NO        , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_NO    , KC_NO  , KC_NO  , KC_NO     , KC_NO,
  QK_REBOOT , KC_NO   , TD_DEF_MEDIA , TD_DEF_NUMPAD , TD_DEF_BASE  , KC_NO     , KC_NO ,     KC_NO , KC_LPRN  , KC_C_7   , KC_C_8 , KC_C_9 , KC_SLASH  , KC_NO,
  KC_NO     , KC_LGUI , KC_LALT      , KC_LCTL       , KC_LSFT      , KC_NO     , KC_NO ,     KC_NO , KC_RPRN  , KC_C_4   , KC_C_5 , KC_C_6 , KC_ASTR   , KC_NO,
  KC_NO     , KC_NO   , KC_NO        , KC_NO         , KC_RALT      , KC_NO     , KC_NO ,     KC_NO , KC_NO    , KC_C_1   , KC_C_2 , KC_C_3 , KC_MINUS  , KC_NO,
  KC_NO     , KC_NO   , KC_NO        , KC_ESC        ,                                                                      KC_C_0 , KC_DOT , KC_C_PLUS , KC_NO,
                                                       KC_BACKSPACE , KC_TAB    ,                     KC_ENTER , KC_SPACE                                      ,
                                                                      KC_ORIGIN , KC_NO ,     KC_NO , KC_QUOTE                                                 ,
                                                                      KC_NO     , KC_NO ,     KC_NO , KC_NO                                                    
),

[_LAYER_MEDIA] = LAYOUT_5x7_sym(
//    ┌───┬─────┬───────┬───────┬─────┬─────┬───┐   ┌───┬───┬──────┬──────┬──────┬───┬───┐
//    │   │     │       │       │     │     │   │   │   │   │      │      │      │ 󰘚 │  │
//    ├───┼─────┼───────┼───────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │   │     │  ←/→ │  󰃝/󰃠 │   │     │   │   │   │   │ TD  │ TD 󰃠 │ TD  │   │  │
//    ├───┼─────┼───────┼───────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │   │ 󰃠  │  󰃠   │  󰕾   │ 󰕾  │     │   │   │   │   │ RSFT │      │      │   │   │
//    ├───┼─────┼───────┼───────┼─────┼─────┼───┤   ├───┼───┼──────┼──────┼──────┼───┼───┤
//    │   │     │    │  󰚱   │   │     │   │   │   │   │      │      │      │   │   │
//    ├───┼─────┼───────┼───────┼─────┴─────┴───┘   └───┴───┴──────┼──────┼──────┼───┼───┤
//    │   │     │       │  ' "  │                                  │ ' "  │      │   │   │
//    └───┴─────┴───────┴───────┼─────┬─────┐           ┌───┬──────┼──────┴──────┴───┴───┘
//                              │  󰁮  │  󰌒  │           │   │      │                      
//                              └─────┼─────┼───┐   ┌───┼───┼──────┘                      
//                                    │ ESC │   │   │   │ 󰭃 │                             
//                                    ├─────┼───┤   ├───┼───┤                             
//                                    │     │   │   │   │   │                             
//                                    └─────┴───┘   └───┴───┘                             
  KC_NO , KC_NO   , KC_NO   , KC_NO    , KC_NO   , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO       , KC_NO        , KC_NO         , EE_CLR , QK_BOOT  ,
  KC_NO , KC_NO   , RGB_HUD , RGB_VAD  , RGB_MOD , KC_NO  , KC_NO ,     KC_NO , KC_NO     , TD_DEF_BASE , TD_DEF_MEDIA , TD_DEF_NUMPAD , KC_NO  , QK_REBOOT,
  KC_NO , KC_BRID , KC_BRIU , KC_VOLD  , KC_VOLU , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_RSFT     , KC_NO        , KC_NO         , KC_NO  , KC_NO    ,
  KC_NO , KC_NO   , AU_TOGG , HF_TOGG  , RGB_TOG , KC_NO  , KC_NO ,     KC_NO , KC_NO     , KC_NO       , KC_NO        , KC_NO         , KC_NO  , KC_NO    ,
  KC_NO , KC_NO   , KC_NO   , KC_QUOTE ,                                                                  KC_QUOTE     , KC_NO         , KC_NO  , KC_NO    ,
                                         KC_BSPC , KC_TAB ,                     KC_NO     , KC_NO                                                          ,
                                                   KC_ESC , KC_NO ,     KC_NO , KC_ORIGIN                                                                  ,
                                                   KC_NO  , KC_NO ,     KC_NO , KC_NO                                                                      
)
};
// clang-format on
