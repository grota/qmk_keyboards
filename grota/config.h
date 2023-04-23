#pragma once

// clang-format off
#define SFT_CTL(kc)  (QK_LCTL | QK_LSFT | (kc))

#ifdef NO_ACTION_ONESHOT
#define SHIFT_IS_PRESSED (modifiers | weak_mods) & MOD_MASK_SHIFT
#define CTRL_IS_PRESSED ((modifiers | weak_mods) & MOD_MASK_CTRL)
#define LALT_IS_PRESSED ((modifiers | weak_mods) & MOD_BIT(KC_LALT))
#define GUI_IS_PRESSED ((modifiers | weak_mods) & MOD_MASK_GUI)
#define RALT_IS_PRESSED ((modifiers | weak_mods) & MOD_BIT(KC_RALT))
#else
#define SHIFT_IS_PRESSED ((modifiers | weak_mods | one_shot) & MOD_MASK_SHIFT)
#define CTRL_IS_PRESSED ((modifiers | weak_mods | one_shot) & MOD_MASK_CTRL)
#define LALT_IS_PRESSED ((modifiers | weak_mods | one_shot) & MOD_BIT(KC_LALT))
#define GUI_IS_PRESSED ((modifiers | weak_mods | one_shot) & MOD_MASK_GUI)
#define RALT_IS_PRESSED ((modifiers | weak_mods | one_shot) & MOD_BIT(KC_RALT))
#endif

#define TAPPING_TOGGLE 1

#ifdef MOUSEKEY_ENABLE

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

//#undef  MOUSEKEY_DELAY
  //#define MOUSEKEY_DELAY 0
  //#undef  MOUSEKEY_WHEEL_DELAY
  //#define MOUSEKEY_WHEEL_DELAY 2
  //#undef  MOUSEKEY_WHEEL_INTERVAL
  //#define MOUSEKEY_WHEEL_INTERVAL 25
  //#undef  MOUSEKEY_WHEEL_MAX_SPEED
  //#define MOUSEKEY_WHEEL_MAX_SPEED 9
  //#undef  MOUSEKEY_INTERVAL
  //#define MOUSEKEY_INTERVAL 13
  //#undef  MOUSEKEY_MAX_SPEED
  //#define MOUSEKEY_MAX_SPEED 10
  //#undef  MOUSEKEY_TIME_TO_MAX
  //#define MOUSEKEY_TIME_TO_MAX 40
  //#define MK_KINETIC_SPEED
  //#define MK_COMBINED
//#define MK_MOMENTARY_ACCEL
//#define MK_C_OFFSET_0 40
//#define MK_C_INTERVAL_0 3
//#            define MOUSEKEY_DELAY 300
//#            define MOUSEKEY_INTERVAL 20
//#            define MOUSEKEY_MOVE_DELTA 25
//#        define MOUSEKEY_MAX_SPEED 3
//#        define MOUSEKEY_TIME_TO_MAX 60
//#        define MOUSEKEY_INITIAL_SPEED 100
//#        define MOUSEKEY_BASE_SPEED 1000
//#        define MOUSEKEY_DECELERATED_SPEED 400
//#        define MOUSEKEY_ACCELERATED_SPEED 3000
//#        define MOUSEKEY_WHEEL_DELAY 15
//#        define MOUSEKEY_WHEEL_DELTA 1
//#        define MOUSEKEY_WHEEL_INTERVAL 50
//#        define MOUSEKEY_WHEEL_MAX_SPEED 8
//#        define MOUSEKEY_WHEEL_TIME_TO_MAX 80
//#        define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 8
//#        define MOUSEKEY_WHEEL_BASE_MOVEMENTS 48
//#        define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48
//#        define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8
#endif // MOUSEKEY_ENABLE

#ifdef RGBLIGHT_ENABLE
  #undef RGBLIGHT_EFFECT_BREATHING
  #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #undef RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #define RGBLIGHT_EFFECT_CHRISTMAS
  #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
  #undef RGBLIGHT_EFFECT_RGB_TEST
  #undef RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_TWINKLE
  // Instead of: #define RGBLIGHT_ANIMATIONS
  //let's define only the ones I like individually to save space.
  #undef RGBLIGHT_ANIMATIONS

  // To see the order of modes: quantum/rgblight/rgblight.h
  #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_TWINKLE + 5
  #define RGBLIGHT_EFFECT_BREATHE_MAX RGBLIGHT_LIMIT_VAL
#endif // RGBLIGHT_ENABLE


#ifdef RGB_MATRIX_ENABLE
  #define DISABLE_RGB_MATRIX_DIGITAL_RAIN
  #define DISABLE_RGB_MATRIX_ALPHAS_MODS
  #define DISABLE_RGB_MATRIX_CYCLE_ALL

  #define RGBLIGHT_SLEEP

  #undef RGBLIGHT_VAL_STEP
  #define RGBLIGHT_VAL_STEP 128
#endif

#ifdef LEADER_ENABLE
  #define LEADER_TIMEOUT 250
  // So far not needed, my leader mappings have one key only.
  //#define LEADER_PER_KEY_TIMING
#endif

#ifdef TAP_DANCE_ENABLE
  // Taps must happen in this interval to get recognized (and trigger move to layer 2 with 2 taps).
  // This can be huge due to the implementation.
  //#define DANCING_TERM_SPECIAL_LEAD 370
  // Taps must happen in this interval to get recognized (and trigger ? with 2 taps).
  //#define DANCING_TERM_SLASH_QUESTION_MARK_RALT 370
  // Taps must happen in this interval to get recognized (and trigger : with 2 taps).
  //#define DANCING_TERM_COLON_SEMI 370
#endif

#ifdef TAP_DANCE_ENABLE
  #define TD_SQBRKTL TD(TD_SQUARE_BRACKET_L)
  #define TD_SQBRKTR TD(TD_SQUARE_BRACKET_R)
#else
  #define TD_SQBRKTL KC_LEFT_BRACKET
  #define TD_SQBRKTR KC_RIGHT_BRACKET
#endif

// clang-format on
