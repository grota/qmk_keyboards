#include "tap_dance.h"
#include "audio_stuff.h"
#include "grota/grota.h"
#include "qmk_firmware/quantum/action_layer.h"

#ifdef AUDIO_ENABLE
#define GROTA_X(LAYER_ID, DESC)                                                \
  void grota_td_fn_layer_##LAYER_ID(tap_dance_state_t *state,                  \
                                    void *user_data) {                         \
    if (state->count == 2) {                                                   \
      PLAY_SONG(layer_song_##LAYER_ID);                                        \
      default_layer_set((layer_state_t)1 << LAYER_ID);                         \
    }                                                                          \
  }
#else
#define GROTA_X(LAYER_ID, DESC)                                                \
  void grota_td_fn_layer_##LAYER_ID(tap_dance_state_t *state,                  \
                                    void *user_data) {                         \
    if (state->count == 2) {                                                   \
      default_layer_set((layer_state_t)1 << LAYER_ID);                         \
    }                                                                          \
  }
#endif
REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X

// Cannot actually use a tap dance for QK_BOOT and EE_CLR because the TD
// finished cb is only executed on master so I would not be able to use those
// keys on the slave.
#if 0
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
#endif

tap_dance_action_t tap_dance_actions[] = {
#ifdef GROTA_TAPDANCE_SQUARE_BRAKETS
    [TD_SQUARE_BRACKET_L] =
        ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LEFT_CURLY_BRACE),
    [TD_SQUARE_BRACKET_R] =
        ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RIGHT_CURLY_BRACE),
#endif

#if 0
#ifdef GROTA_TAPDANCE_BOOT
    [TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#endif
#ifdef GROTA_TAPDANCE_CLEAR_EEPROM
    [TD_EE_CLR] = ACTION_TAP_DANCE_FN(u_td_fn_clear_eeprom),
#endif
#ifdef GROTA_TAPDANCE_REBOOT
    [TD_REBOOT] = ACTION_TAP_DANCE_DOUBLE(KC_NO, QK_REBOOT),
#endif
#endif

#ifdef GROTA_TAPDANCE_SET_DEFAULT_LAYER
#define GROTA_X(LAYER_ID, DESC)                                                \
  [DEF##LAYER_ID] = ACTION_TAP_DANCE_FN(grota_td_fn_layer_##LAYER_ID),
    REPEAT_GROTA_X_FOR_LAYERS
#undef GROTA_X
#endif
};
