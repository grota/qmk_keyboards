#pragma once

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"
#include "grota.h"

#define TAP_DANCE_KC1_ON_TAP_SHIFT_KC1_ON_DOUBLETAP_MOD_ON_HOLD(kc1, kc_mod, tap_specific_tapping_term) { \
  .fn = { td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_each_tap, td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_finished, td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_reset }, \
  .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc_mod }), \
  .custom_tapping_term = tap_specific_tapping_term, \
}

typedef struct
{
  uint16_t kc1;
  uint16_t kc2;
  uint16_t kc3;
} qk_tap_dance_three_kcs_t;

#define TAP_DANCE_KC1_ON_TAP_KC2_ON_DOUBLETAP_MOD_ON_HOLD(kc1, kc2, kc_mod, tap_specific_tapping_term) { \
    .fn = { NULL, td_kc1_on_tap_kc2_on_doubletap_mod_on_hold_finished, td_kc1_on_tap_kc2_on_doubletap_mod_on_hold_reset }, \
    .user_data = (void *)&((qk_tap_dance_three_kcs_t) { kc1, kc2, kc_mod }), \
    .custom_tapping_term = tap_specific_tapping_term, \
}

enum tap_dances {
  TD_SQUARE_BRACKET_L,
  TD_SQUARE_BRACKET_R,
  //TD_LEAD_MOVE_TO_LAYER_LALT,
  //TD_COLON_SEMI,
  //TD_SLASH_QUESTION_MARK_RALT,
};

#if 0
enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // Send two single taps.
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,
};

uint8_t current_dance_status (qk_tap_dance_state_t *state, bool prefer_hold);
void special_lead_finished (qk_tap_dance_state_t *state, void *user_data);
void special_lead_reset (qk_tap_dance_state_t *state, void *user_data);
void special_lead_finished(qk_tap_dance_state_t *state, void *user_data);
void special_lead_reset(qk_tap_dance_state_t *state, void *user_data);
void td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_each_tap (qk_tap_dance_state_t *state, void *user_data);
void td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void td_kc1_on_tap_shift_kc1_on_doubletap_mod_on_hold_reset(qk_tap_dance_state_t *state, void *user_data);
void td_kc1_on_tap_kc2_on_doubletap_mod_on_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void td_kc1_on_tap_kc2_on_doubletap_mod_on_hold_reset(qk_tap_dance_state_t *state, void *user_data);
#endif
