#include "tap_dance.h"
static uint8_t special_lead_state = 0;
static uint8_t colon_control_state = 0;

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SQUARE_BRACKET_L] = {
    .fn = { NULL, dance_shifted_version_finish, dance_shifted_version_reset },
    .user_data = (void *)&((qk_tap_dance_pair_t) { KC_LBRACKET, KC_LBRACKET }),
  },
  [TD_SQUARE_BRACKET_R] = {
    .fn = { NULL, dance_shifted_version_finish, dance_shifted_version_reset },
    .user_data = (void *)&((qk_tap_dance_pair_t) { KC_RBRACKET, KC_RBRACKET }),
  },
  [TD_SPECIAL_LEAD_MOVE_TO_LAYER] = {
    .fn = { NULL, special_lead_finished, special_lead_reset },
    .user_data = (void *)&((qk_tap_dance_dual_role_t) { KC_LALT, _FN_AND_MOUSE }),
    .custom_tapping_term = DANCING_TERM_SPECIAL_LEAD,
  },
  [TD_COLON_SEMI_CTRL] = {
    .fn = { NULL, td_colon_ctrl_finished, td_colon_ctrl_reset },
    .user_data = (void *)&((qk_tap_dance_pair_t) { KC_SCOLON, KC_RCTRL }),
    .custom_tapping_term = DANCING_TERM_COLON_CONTROL,
  }
};

void td_colon_ctrl_finished(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  colon_control_state = current_dance_status(state);
  switch (colon_control_state) {
    case SINGLE_TAP:
      register_code(pair->kc1);
      break;

    case SINGLE_HOLD:
      register_code(pair->kc2);
      break;

    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
      register_code (KC_RSFT);
      register_code(pair->kc1);
      break;
  }
}

void td_colon_ctrl_reset(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  switch (colon_control_state) {
    case SINGLE_TAP:
      unregister_code(pair->kc1);
      break;

    case SINGLE_HOLD:
      unregister_code(pair->kc2);
      break;

    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
      unregister_code (KC_RSFT);
      unregister_code(pair->kc1);
      break;
  }
  colon_control_state = 0;
}

void special_lead_finished(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_dual_role_t *pair = (qk_tap_dance_dual_role_t *)user_data;
  special_lead_state = current_dance_status(state);
  switch (special_lead_state) {
    case SINGLE_TAP:
      qk_leader_start();
      break;

    case SINGLE_HOLD:
      register_code(pair->kc);
      break;

    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
      layer_move (pair->layer);
      break;
  }
}

void special_lead_reset(qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_dual_role_t *pair = (qk_tap_dance_dual_role_t *)user_data;
  switch (special_lead_state) {
    case SINGLE_TAP:
      break;

    case SINGLE_HOLD:
      unregister_code(pair->kc);
      break;

    case DOUBLE_TAP:
    case DOUBLE_SINGLE_TAP:
      layer_move (pair->layer);
      break;
  }
  special_lead_state = 0;
}

uint8_t current_dance_status(qk_tap_dance_state_t *state) {
  uint8_t current_state = 0;
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      current_state = SINGLE_TAP;
    } else {
      current_state = SINGLE_HOLD;
    }
  } else if (state->count == 2) {
    if (state->interrupted) {
      current_state = DOUBLE_SINGLE_TAP;
    } else if (state->pressed) {
      current_state = DOUBLE_HOLD;
    } else {
      current_state = DOUBLE_TAP;
    }
  } else if (state->count == 3) {
    if (state->interrupted || !state->pressed) {
      current_state = TRIPLE_TAP;
    }
    else {
      current_state = TRIPLE_HOLD;
    }
  }
  return current_state;
}

void dance_shifted_version_finish (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  if (state->count == 1) {
    register_code (pair->kc1);
  } else {
    register_code (KC_RSFT);
    register_code (pair->kc2);
  }
}

void dance_shifted_version_reset (qk_tap_dance_state_t *state, void *user_data) {
  qk_tap_dance_pair_t *pair = (qk_tap_dance_pair_t *)user_data;
  if (state->count == 1) {
    unregister_code (pair->kc1);
  } else {
    unregister_code (KC_RSFT);
    unregister_code (pair->kc2);
  }
}
