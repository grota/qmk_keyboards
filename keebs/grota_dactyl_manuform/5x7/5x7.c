#include "qmk_firmware/quantum/keycode_config.h"
#include "qmk_firmware/quantum/quantum_keycodes.h"
#include QMK_KEYBOARD_H

#include "grota.h"

#ifdef AUDIO_ENABLE
#include "audio_stuff.h"
#endif

#if defined(GROTA_DATA_SYNC_AUDIO_STATE)
#include "data_sync_audio.h"
#endif
#if defined(GROTA_DATA_SYNC_TESTS_DEBUG)
#include "data_sync_3str.h"
#endif

/* RIGHT IS MASTER, LEFT IS SLAVE
 For power reasons we need to connect 2 usb cables, one for each split.
 I could also try defining SPLIT_USB_DETECT but I had problems in the past. */
bool is_keyboard_master(void) { return !is_keyboard_left(); }

void protocol_pre_init(void);
void protocol_post_init(void);
void protocol_init(void) {
  // ONLY RIGHT/MASTER SETS UP USB
  if (is_keyboard_master()) {
    uprintf("calling protocol_pre_init\n");
    protocol_pre_init();
  }
  keyboard_init();
  protocol_post_init();
}

/* Returns true so that also the slave will be able to call the `process_*` code
 * along with `process_haptic()` */
bool should_process_keypress(void) { return true; }

void keyboard_post_init_kb(void) {
#if defined(GROTA_DATA_SYNC_AUDIO_STATE)
  transaction_register_rpc(SYNC_AUDIO,
                           audio_slave_handler);
#endif
#if defined(GROTA_DATA_SYNC_TESTS_DEBUG)
  transaction_register_rpc(SYNC_SLAVE_MSG, receive_msg_from_slave_cb);
#endif
  keyboard_post_init_user();
}

static uint8_t process_record_detected_row = INITIAL_DEFAULT_ROW;
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    process_record_detected_row = record->event.key.row;
  }
  // clang-format off
  uprintf("process_record_kb: kc: 0x%04X, col: %2u, row: %2u, current: %1d, pressed: %1d, count: %u\n",
      keycode,
      record->event.key.col,
      record->event.key.row,
      row_belongs_to_current_keyboard_hand(process_record_detected_row),
      record->event.pressed,
      record->tap.count
  );
  // clang-format on
  return
#ifdef AUDIO_ENABLE
#ifdef SPACE_CADET_ENABLE
      process_record_prepare_space_cadet_var(keycode, record) &&
#endif
#endif
      process_record_user(keycode, record);
}

/* As of today we don't need to call haptic_task() on the slave anymore like we
 * did in the past given that https://github.com/qmk/qmk_firmware/pull/21583
 * changed the flow so that it's keyboard_task() instead of quantum_task() to
 * call haptic_task().
 * And keyboard_task() is called also on the slave.
 *
 * Still we need to define SPLIT_HAPTIC_ENABLE otherwise both `haptic_task` and
 * `haptic_init` do not do anything on the slave.
 *
 * Defining SPLIT_HAPTIC_ENABLE brings its own problems: we need to patch its
 * slave callback haptic_handlers_slave() so that it does not call haptic_play().
 * Otherwise a solenoid trigger on the master is replicated on the slave.
 */
void housekeeping_task_kb(void) {
#ifdef HAPTIC_ENABLE
  if (is_keyboard_master()) {
#ifdef GROTA_DATA_SYNC_TESTS_DEBUG
    receive_msg_from_slave();
#endif
#endif
#if defined(GROTA_DATA_SYNC_AUDIO_STATE)
    send_to_slave_audio_state();
#endif
  }
  housekeeping_task_user();
}

/* This is called only on master */
void matrix_scan_kb(void) {
#ifdef AUDIO_ENABLE
  if (row_belongs_to_current_keyboard_hand(process_record_detected_row)) {
    matrix_scan_play_audio_when_mods_are_hold();
  }
#endif
  matrix_scan_user();
}

/* This is called only on slave */
void matrix_slave_scan_kb(void) {
#ifdef AUDIO_ENABLE
  if (row_belongs_to_current_keyboard_hand(process_record_detected_row)) {
    matrix_scan_play_audio_when_mods_are_hold();
  }
#endif
  matrix_slave_scan_user();
}

/* This is called also on the slave since should_process_keypress=true */
layer_state_t layer_state_set_kb(layer_state_t state) {
#ifdef AUDIO_ENABLE
  uprintf("layer_state_set_kb \n");
  if (row_belongs_to_current_keyboard_hand(process_record_detected_row)) {
    layer_state_set_play_audio_based_on_layer(state);
  }
#endif
  return layer_state_set_user(state);
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Only KC_E really needs to have QUICK_TAP_TERM enabled.
  case RCTL_T(KC_E):
  case BSPC_MOUSE:
  case SPACE_NAV:
    return QUICK_TAP_TERM;
  // When the user holds a key after tapping it, activate the hold function.
  // This removes the ability to auto-repeat of dual role keys.
  default:
    return 0;
  }
}

/* To save space */
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

/* To save space */
uint8_t mod_config(uint8_t mod) {
    return mod;
}

#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
  case KC_TAB:
  case KC_ESC:
  case KC_ENTER:
    return false;

  // Keycodes that continue Caps Word, without shifting.
  case KC_BSPC:
  case KC_DEL:
    return true;

  default:
    add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
    return true;
  }
}
#endif
