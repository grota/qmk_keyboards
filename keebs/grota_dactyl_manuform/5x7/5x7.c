#include QMK_KEYBOARD_H

#include "grota.h"

#ifdef AUDIO_ENABLE
#include "audio_stuff.h"
#endif

#if defined(GROTA_CUSTOM_DATA_SYNC) && defined(HAPTIC_ENABLE)
#include "data_sync_3str.h"
#endif

/* RIGHT IS MASTER, LEFT IS SLAVE
 For power reasons we need to connect 2 usb cables, one for each split.
 I could also try defining SPLIT_USB_DETECT but I had problems in the past. */
bool is_keyboard_master(void) {
  return !is_keyboard_left();
}

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
bool should_process_keypress(void) {
  return true;
}

void keyboard_post_init_kb(void) {
  #if defined(GROTA_CUSTOM_DATA_SYNC) && defined(HAPTIC_ENABLE)
  transaction_register_rpc(SYNC_SLAVE_MSG, receive_msg_from_slave_cb);
  #endif
  keyboard_post_init_user();
}

uint8_t process_record_detected_row;
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    process_record_detected_row = record->event.key.row;
  }
  uprintf("process_record_kb: kc: 0x%04X, col: %2u, row: %2u, current: %1d, pressed: %1d, count: %u\n", keycode, record->event.key.col, record->event.key.row, row_belongs_to_current_keyboard_hand(record->event.key.row), record->event.pressed, record->tap.count);
  return
    #ifdef AUDIO_ENABLE
    process_record_prepare_space_cadet_var(keycode, record) &&
    #endif
    process_record_user(keycode, record);
}

/* Since `quantum_task()` (which calls `haptic_task()`) does not do anyhting on
 * the slave, here we leverage the `housekeeping_task_kb()` to call
 * `haptic_task()` on the slave. */
void housekeeping_task_kb(void) {
  #ifdef HAPTIC_ENABLE
  if (!is_keyboard_master()) {
    haptic_task();
  #ifdef GROTA_CUSTOM_DATA_SYNC
  } else {
    receive_msg_from_slave();
  #endif
  }
  #endif
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

/* This is called also on the slave right now since should_process_keypress=true */
layer_state_t layer_state_set_kb(layer_state_t state) {
  #ifdef AUDIO_ENABLE
  if (row_belongs_to_current_keyboard_hand(process_record_detected_row)) {
    layer_state_set_play_audio_based_on_layer(state);
  }
  #endif
  return layer_state_set_user(state);
}
