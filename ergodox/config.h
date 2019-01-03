/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_ALPHAS_MODS

#define RGBLIGHT_SLEEP

//https://www.reddit.com/r/ergodox/comments/9yt81q/oneshot_shift_key_releases_too_late_ergodoxez_glow/ea5dizg/
#define FORCE_NKRO

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

//#define ONESHOT_TIMEOUT 400
