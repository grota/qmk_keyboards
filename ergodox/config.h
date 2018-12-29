#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_CYCLE_ALL

#define RGBLIGHT_SLEEP

//https://www.reddit.com/r/ergodox/comments/9yt81q/oneshot_shift_key_releases_too_late_ergodoxez_glow/ea5dizg/
#define FORCE_NKRO

//how long before a tap becomes a hold
#define TAPPING_TERM 200

#define LEADER_TIMEOUT 250
// So far not needed, my leader mappings have one key only.
//#define LEADER_PER_KEY_TIMING

// Taps must happen in this interval to get recognized (and trigger move to layer 2 with 2 taps).
#define DANCING_TERM_SPECIAL_LEAD 200
// Taps must happen in this interval to get recognized (and trigger : with 2 taps).
#define DANCING_TERM_COLON_CONTROL 180

#undef DEBOUNCE
#define DEBOUNCE 5

#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 15

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 14

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 60

#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 128

#ifdef CONSOLE_ENABLE
#define NO_DEBUG
#define USER_PRINT
#endif
