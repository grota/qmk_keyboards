#include "tap_dance.h"
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

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SQBRKTL] = {
    .fn = { NULL, dance_shifted_version_finish, dance_shifted_version_reset },
    .user_data = (void *)&((qk_tap_dance_pair_t) { KC_LBRACKET, KC_LBRACKET }),
  },
  [TD_SQBRKTR] = {
    .fn = { NULL, dance_shifted_version_finish, dance_shifted_version_reset },
    .user_data = (void *)&((qk_tap_dance_pair_t) { KC_RBRACKET, KC_RBRACKET }),
  },
};
