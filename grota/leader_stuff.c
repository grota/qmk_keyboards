#include "leader_stuff.h"

LEADER_EXTERNS();

void matrix_scan_user_leader(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

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
  }
}
