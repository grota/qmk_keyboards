#include "leader_stuff.h"

LEADER_EXTERNS();

void matrix_scan_user_leader(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_1) {
      SEND_STRING(SS_TAP(X_F1));
    }
    SEQ_ONE_KEY(KC_2) {
      SEND_STRING(SS_TAP(X_F2));
    }
    SEQ_ONE_KEY(KC_3) {
      SEND_STRING(SS_TAP(X_F3));
    }
    SEQ_ONE_KEY(KC_4) {
      SEND_STRING(SS_TAP(X_F4));
    }
    SEQ_ONE_KEY(KC_5) {
      SEND_STRING(SS_TAP(X_F5));
    }
    SEQ_ONE_KEY(KC_A) {
      SEND_STRING(SS_RALT("a"));
    }
    SEQ_ONE_KEY(KC_E) {
      SEND_STRING(SS_RALT("e"));
    }
    SEQ_ONE_KEY(KC_I) {
      SEND_STRING(SS_RALT("i"));
    }
    SEQ_ONE_KEY(KC_O) {
      SEND_STRING(SS_RALT("o"));
    }
    SEQ_ONE_KEY(KC_U) {
      SEND_STRING(SS_RALT("u"));
    }
    SEQ_ONE_KEY(KC_K) {
      SEND_STRING("$");
    }
    SEQ_ONE_KEY(KC_MINUS) {
      SEND_STRING("->");
    }
    SEQ_ONE_KEY(KC_9) {
      SEND_STRING("(");
    }
    SEQ_ONE_KEY(KC_0) {
      SEND_STRING(")");
    }
  }
}
