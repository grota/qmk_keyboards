#include "tap_dance.h"

tap_dance_action_t tap_dance_actions[] = {
#ifdef GROTA_TAPDANCE_SQUARE_BRAKETS
    [TD_SQUARE_BRACKET_L] =
        ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_LEFT_CURLY_BRACE),
    [TD_SQUARE_BRACKET_R] =
        ACTION_TAP_DANCE_DOUBLE(KC_RBRACKET, KC_RIGHT_CURLY_BRACE),
#endif
};
