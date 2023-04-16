#pragma once

#include "grota.h"
#include "process_keycode/process_tap_dance.h"
#include "qmk_firmware/quantum/action_layer.h"
#include "qmk_firmware/quantum/process_keycode/process_tap_dance.h"
#include "quantum.h"

enum tap_dances {
#ifdef GROTA_TAPDANCE_SQUARE_BRAKETS
  TD_SQUARE_BRACKET_L,
  TD_SQUARE_BRACKET_R,
#endif
#ifdef GROTA_TAPDANCE_BOOT
  TD_BOOT,
#endif
#ifdef GROTA_TAPDANCE_CLEAR_EEPROM
  TD_EE_CLR,
#endif
#ifdef GROTA_TAPDANCE_REBOOT
  TD_REBOOT,
#endif

#ifdef GROTA_TAPDANCE_SET_DEFAULT_LAYER
#define GROTA_X(LAYER_NAME, LAYER_ID, STRING) TD_DEF_L_##LAYER_NAME,
  REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
#endif
};
