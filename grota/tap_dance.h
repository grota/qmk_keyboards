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
#define GROTA_X(LAYER_ID, STRING) DEF##LAYER_ID,
  REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X

#define TD_DEF_BASE TD(DEF_LAYER_BASE)
#define TD_DEF_SYM1 TD(DEF_LAYER_SYM1)
#define TD_DEF_SYM2 TD(DEF_LAYER_SYM2)
#define TD_DEF_MOUSE TD(DEF_LAYER_MOUSE)
#define TD_DEF_NAV TD(DEF_LAYER_NAV)
#define TD_DEF_NUMPAD TD(DEF_LAYER_NUMPAD)
#define TD_DEF_MEDIA TD(DEF_LAYER_MEDIA)
#endif
};
