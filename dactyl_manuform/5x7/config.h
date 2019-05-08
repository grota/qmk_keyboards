#pragma once

#define MATRIX_ROWS 12
#define MATRIX_COLS 7
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { D1, D0, D4, D7, E6, B4, B5 }

#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN D3 // TX0
  #undef RGBLED_NUM
  #define RGBLED_NUM 60
  #define RGBLED_SPLIT { 30, 30 }
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_LIMIT_VAL 130

  #define RGBLIGHT_SLEEP
  #undef RGBLIGHT_ANIMATIONS
#endif // RGBLIGHT_ENABLE

#define USE_SERIAL
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2 // RX1

#undef MASTER_RIGHT
#undef MASTER_LEFT
#undef EE_HANDS
#define EE_HANDS

#undef PRODUCT
#define PRODUCT Dactyl-Manuform 5x7 Hotswappable with RGBLight by grota

#define NO_MUSIC_MODE
#undef C6_AUDIO
#define C6_AUDIO
#undef B5_AUDIO
#undef B7_AUDIO
#define B6_AUDIO

#define LAYOUT_5x7_sym(\
  L06, L05, L04, L03, L02, L01, L00,                    R00, R01, R02, R03, R04, R05, R06, \
  L16, L15, L14, L13, L12, L11, L10,                    R10, R11, R12, R13, R14, R15, R16, \
  L26, L25, L24, L23, L22, L21, L20,                    R20, R21, R22, R23, R24, R25, R26, \
  L36, L35, L34, L33, L32, L31, L30,                    R30, R31, R32, R33, R34, R35, R36, \
  L46, L45, L44, L43,                                                  R43, R44, R45, R46, \
                      L42, L41,                              R41, R42,           \
                             L52, L50,      R50, R52,                            \
                             L53, L51,      R51, R53                             \
  ) \
  { \
    { L00,   L01, L02, L03, L04,   L05,   L06 },   \
    { L10,   L11, L12, L13, L14,   L15,   L16 },   \
    { L20,   L21, L22, L23, L24,   L25,   L26 },   \
    { L30,   L31, L32, L33, L34,   L35,   L36 },   \
    { KC_NO, L41, L42, L43, L44,   L45,   L46 },   \
    { L50,   L51, L52, L53, KC_NO, KC_NO, KC_NO }, \
\
    { R00,   R01, R02, R03, R04,   R05,   R06 },   \
    { R10,   R11, R12, R13, R14,   R15,   R16 },   \
    { R20,   R21, R22, R23, R24,   R25,   R26 },   \
    { R30,   R31, R32, R33, R34,   R35,   R36 },   \
    { KC_NO, R41, R42, R43, R44,   R45,   R46 },   \
    { R50,   R51, R52, R53, KC_NO, KC_NO, KC_NO }, \
   }
