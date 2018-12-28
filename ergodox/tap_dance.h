#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
#include "grota.h"

enum tap_dances {
  TD_SQUARE_BRACKET_L,
  TD_SQUARE_BRACKET_R,
  TD_SPECIAL_LEAD_MOVE_TO_LAYER,
  TD_COLON_SEMI_CTRL,
};

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // Send two single taps.
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,
};

uint8_t current_dance_status (qk_tap_dance_state_t *state);
void special_lead_finished (qk_tap_dance_state_t *state, void *user_data);
void special_lead_reset (qk_tap_dance_state_t *state, void *user_data);
void dance_shifted_version_finish (qk_tap_dance_state_t *state, void *user_data);
void dance_shifted_version_reset (qk_tap_dance_state_t *state, void *user_data);
void special_lead_finished(qk_tap_dance_state_t *state, void *user_data);
void special_lead_reset(qk_tap_dance_state_t *state, void *user_data);
void td_colon_ctrl_finished(qk_tap_dance_state_t *state, void *user_data);
void td_colon_ctrl_reset(qk_tap_dance_state_t *state, void *user_data);
