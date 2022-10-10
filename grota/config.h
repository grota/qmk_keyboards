#pragma once

#define SFT_CTL(kc)  (QK_LCTL | QK_LSFT | (kc))

#define SHIFT_IS_PRESSED modifiers & MOD_MASK_SHIFT || one_shot & MOD_MASK_SHIFT || weak_mods & MOD_MASK_SHIFT
#define RALT_IS_PRESSED modifiers & MOD_BIT(KC_RALT) || one_shot & MOD_BIT(KC_RALT) || weak_mods & MOD_BIT(KC_RALT)
#define CTRL_IS_PRESSED modifiers & MOD_MASK_CTRL || weak_mods & MOD_MASK_CTRL || one_shot & MOD_MASK_CTRL
#define LALT_IS_PRESSED modifiers & MOD_BIT(KC_LALT) || one_shot & MOD_BIT(KC_LALT) || weak_mods & MOD_BIT(KC_LALT)

#define TAPPING_TOGGLE 1

//how long before a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 140

//#undef DEBOUNCE
//#define DEBOUNCE 4

#ifdef MOUSEKEY_ENABLE

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
  // Instead of: #define RGBLIGHT_ANIMATIONS
  //let's define only the ones I like individually to save space.
  #undef RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_BREATHING
  #define RGBLIGHT_EFFECT_RAINBOW_MOOD
  #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
  #define RGBLIGHT_EFFECT_SNAKE
  #define RGBLIGHT_EFFECT_KNIGHT
  #undef RGBLIGHT_EFFECT_CHRISTMAS
  #define RGBLIGHT_EFFECT_STATIC_GRADIENT
  #undef RGBLIGHT_EFFECT_RGB_TEST
  #undef RGBLIGHT_EFFECT_ALTERNATING
  #define RGBLIGHT_EFFECT_TWINKLE

  #define RGBLIGHT_EFFECT_BREATHE_MAX RGBLIGHT_LIMIT_VAL
#endif // RGBLIGHT_ENABLE

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(GUITAR_SOUND)
#endif

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
  //#define TD_SPECIAL_LEAD TD(TD_LEAD_MOVE_TO_LAYER_LALT)
  //#define TD_COLON TD(TD_COLON_SEMI)
  //#define TD_SLASH_RALT TD(TD_SLASH_QUESTION_MARK_RALT)
#else
  #define TD_SQBRKTL KC_LBRACKET
  #define TD_SQBRKTR KC_RBRACKET
#endif
