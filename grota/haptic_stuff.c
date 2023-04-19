#include "haptic_stuff.h"
#include "qmk_firmware/quantum/keycodes.h"

#ifdef GROTA_CUSTOM_DATA_SYNC
#include <stdio.h>
extern char str2[32];
#endif

bool get_haptic_enabled_key(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
  bool is_master = is_keyboard_master();
  uprintf("%s get_haptic_enabled_key: kc: 0x%04X\n",
          is_master ? "Master" : "Slave", keycode);
#endif
  switch (keycode) {
  case QK_MOD_TAP ... QK_MOD_TAP_MAX:
  case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    uprintf("mod/layer tap count: %d\n", record->tap.count);
    return record->tap.count;

  default:
    break;
  }
  bool row_is_ours =
      row_belongs_to_current_keyboard_hand(record->event.key.row);
  uprintf("row_belongs_to_current_keyboard_hand gives %1d\n", row_is_ours);
  return row_is_ours;
}
