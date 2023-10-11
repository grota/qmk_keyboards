/*
Copyright 2023 Giuseppe Rota <rota.giuseppe@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// How long before a tap becomes a hold.
// Too many mods => increase tapping term.
// Too many taps => lower tapping term.
#define TAPPING_TERM 250

// If you press a dual-role key, tap another key (press and release) and then
// release the dual-role key, even if within the tapping term, then perform the
// hold action.
#define PERMISSIVE_HOLD

// Make it possible to define a get_quick_tap_term() func to specify, per key,
// what is the interval of time within which the user must tap then hold the key
// to trigger auto repeat.
// My get_quick_tap_term() says 0 for every key except RCTL_T(KC_E).
#define QUICK_TAP_TERM_PER_KEY

// Holding and releasing a dual-function key without pressing another key will
// send the original keycode even if it is outside the tapping term.
// #define RETRO_TAPPING

// The last mod-tap hold will be converted to the corresponding mod-tap tap if
// another key on the same hand is tapped during the hold, unless a key on the
// other hand is tapped first.
#define BILATERAL_COMBINATIONS

#define DYNAMIC_TAPPING_TERM_INCREMENT 10

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

#undef USE_I2C
#define USE_SERIAL
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2 // RX1

#undef MASTER_RIGHT
#undef MASTER_LEFT
#define EE_HANDS

#ifdef AUDIO_ENABLE
#define AUDIO_PIN C6
#define AUDIO_PIN_ALT B6
#endif

// make master/slave detection logic based on presence of USB communication.
// Have to try it again (to avoid master/slave logic based on handedness) but
// had problems in the past.
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 40000
// #define SPLIT_USB_TIMEOUT_POLL 100
// #define SPLIT_WATCHDOG_ENABLE

#ifdef HAPTIC_ENABLE
#define SOLENOID_PIN F4
#define SOLENOID_DEFAULT_DWELL 10
#define SOLENOID_MIN_DWELL 1
#define SOLENOID_MAX_DWELL 30
#define SOLENOID_DWELL_STEP_SIZE 1
#endif // HAPTIC_ENABLE

#ifdef GROTA_DATA_SYNC_AUDIO_STATE
#define SPLIT_TRANSACTION_IDS_KB SYNC_AUDIO
// 8+32 is the sum of the 2 unions.
#define RPC_M2S_BUFFER_SIZE 40
#endif

#ifdef GROTA_DATA_SYNC_TESTS_DEBUG
#define SPLIT_TRANSACTION_IDS_KB SYNC_SLAVE_MSG
#define RPC_S2M_BUFFER_SIZE 96
#endif

#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLED_NUM 60
// clang-format off
#define RGBLED_SPLIT { 30, 30 }
// clang-format on
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LIMIT_VAL 255

#define RGBLIGHT_SLEEP
#define RGBLIGHT_DEFAULT_HUE 85
#define RGBLIGHT_DEFAULT_VAL 240
#endif // RGBLIGHT_ENABLE
