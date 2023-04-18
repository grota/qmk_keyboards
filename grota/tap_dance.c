#include "tap_dance.h"
#include "grota/grota.h"
#include "qmk_firmware/quantum/action_layer.h"

#define GROTA_X(LAYER_NAME, LAYER_ID, DESC)                                    \
  void grota_td_fn_layer_##LAYER_NAME(tap_dance_state_t *state,                \
                                      void *user_data) {                       \
    if (state->count == 2) {                                                   \
      default_layer_set((layer_state_t)1 << LAYER_ID);                         \
    }                                                                          \
  }
REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}
void u_td_fn_clear_eeprom(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    eeconfig_disable();
    soft_reset_keyboard();
  }
}

tap_dance_action_t tap_dance_actions[] = {
#ifdef GROTA_TAPDANCE_SQUARE_BRAKETS
    [TD_SQUARE_BRACKET_L] =
        ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LEFT_CURLY_BRACE),
    [TD_SQUARE_BRACKET_R] =
        ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RIGHT_CURLY_BRACE),
#endif
#ifdef GROTA_TAPDANCE_BOOT
    [TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#endif
#ifdef GROTA_TAPDANCE_CLEAR_EEPROM
    [TD_EE_CLR] = ACTION_TAP_DANCE_FN(u_td_fn_clear_eeprom),
#endif
#ifdef GROTA_TAPDANCE_REBOOT
    [TD_REBOOT] = ACTION_TAP_DANCE_DOUBLE(KC_NO, QK_REBOOT),
#endif
#ifdef GROTA_TAPDANCE_SET_DEFAULT_LAYER
#define GROTA_X(LAYER_NAME, LAYER_ID, DESC)                                    \
  [TD_DEF_L_##LAYER_NAME] = ACTION_TAP_DANCE_FN(grota_td_fn_layer_##LAYER_NAME),
    REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
#endif
};
