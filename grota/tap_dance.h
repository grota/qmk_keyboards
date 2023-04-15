#pragma once

#include "grota.h"
#include "process_keycode/process_tap_dance.h"
#include "quantum.h"

enum tap_dances {
#ifdef GROTA_TAPDANCE_SQUARE_BRAKETS
  TD_SQUARE_BRACKET_L,
  TD_SQUARE_BRACKET_R,
#endif
};
