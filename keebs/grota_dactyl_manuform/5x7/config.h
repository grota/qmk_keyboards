/*
Copyright 2019 Giuseppe Rota <rota.giuseppe@gmail.com>

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
#endif // AUDIO_ENABLE

// make master/slave detection logic based on presence of USB communication.
// Have to try it again (to avoid master/slave logic based on handedness) but had problems in the past.
//#define SPLIT_USB_DETECT
//#define SPLIT_USB_TIMEOUT 40000
//#define SPLIT_USB_TIMEOUT_POLL 100
//#define SPLIT_WATCHDOG_ENABLE

#ifdef HAPTIC_ENABLE
  #define SOLENOID_PIN F4
  // If you define this then the slave does not enter in the following if inside process_haptic():
  // if (haptic_get_enable() && ((!HAPTIC_OFF_IN_LOW_POWER) || (usb_device_state == USB_DEVICE_STATE_CONFIGURED))) {
  // When you override protocol_init() to have
  // if (is_keyboard_master()) {
  //   protocol_pre_init();
  // }
  // Which I prefer since it is more in line with what qmk does on a normal split (only master enumerates on usb)
  // otherwise debugging via qmk console is harder.
  //#define HAPTIC_OFF_IN_LOW_POWER 1
  #define SOLENOID_DEFAULT_DWELL 10
  #define SOLENOID_MIN_DWELL 1
  #define SOLENOID_MAX_DWELL 10
  #define SOLENOID_DWELL_STEP_SIZE 1
#endif // HAPTIC_ENABLE

#ifdef GROTA_CUSTOM_DATA_SYNC
#define SPLIT_TRANSACTION_IDS_KB SYNC_SLAVE_MSG
#define RPC_S2M_BUFFER_SIZE 96
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN D3 // TX0
  #undef RGBLED_NUM
  #define RGBLED_NUM 60
  #define RGBLED_SPLIT { 30, 30 }
  #define RGBLIGHT_SPLIT
  #define RGBLIGHT_LIMIT_VAL 255

  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_DEFAULT_HUE 85
  #define RGBLIGHT_DEFAULT_VAL 240
#endif // RGBLIGHT_ENABLE
