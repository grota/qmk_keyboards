#pragma once

//how long before a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 150

#undef DEBOUNCE
#define DEBOUNCE 4

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 15

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 14

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 60

#ifdef CONSOLE_ENABLE
#define NO_DEBUG
#define USER_PRINT
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
