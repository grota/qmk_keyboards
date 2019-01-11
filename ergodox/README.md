# Overview

Just my ergodox-ez keymap, it is and always will be a work in progress (most of the keys are quite stable though).

Most of the things have been copied from `drashna` and `hacker_dvorak`.

## RGB matrix layers

There is a custom rgb layer indicator that I can cycle through with the other effects and that also shows how to target the color of specific keys (see `rgb_stuff.c`).

### ErgoDox EZ RGB matrix led indices.

These are the indices used in the various `rgb_matrix_*` functions for the ergodox.

```
,--------------------------------------------------.  ,--------------------------------------------------.
|        |  28  |  27  |  26  |  25  |  24  |      |  |      |   0  |   1  |   2  |   3  |   4  |        |
|--------+------+------+------+------+-------------|  |------+------+------+------+------+------+--------|
|        |  33  |  32  |  31  |  30  |  29  |      |  |      |   5  |   6  |   7  |   8  |   9  |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |  38  |  37  |  36  |  35  |  34  |------|  |------|  10  |  11  |  12  |  13  |  14  |        |
|--------+------+------+------+------+------|      |  |      |------+------+------+------+------+--------|
|        |  43  |  42  |  41  |  40  |  39  |      |  |      |  15  |  16  |  17  |  18  |  19  |        |
`--------+------+------+------+------+-------------'  `-------------+------+------+------+------+--------'
  |      |  47  |  46  |  45  |  44  |                              |  20  |  21  |  22  |  23  |      |
  `----------------------------------'                              `----------------------------------'
```

## Tap dances

1. `TD_LEAD_MOVE_TO_LAYER_LALT` is `KC_LEAD` on single tap, moves to second layer on double tap, and `KC_LALT` when held.

2. `TD_COLON_SEMI_CTRL` is `KC_SCOLON` on single tap, `Shift+KC_SCOLON` on double tap, and `KC_RCTL` when held. (See `TAP_DANCE_KC1_ON_TAP_SHIFT_KC1_ON_DOUBLETAP_MOD_ON_HOLD(kc1, kc_mod, tap_specific_tapping_term)`).

3. `[` and `]` double tapped will get you `{` and `}`.

My tap dances uses a slightly modified utility function to get the tapdance status, that can prefer a hold state when interrupted, see `current_dance_status(qk_tap_dance_state_t *state, bool prefer_hold)`.

For the first tapdance `TD_LEAD_MOVE_TO_LAYER_LALT` I also check the value of the keycode that interrupts, in order to give priority to the held state (`KC_LALT`) or the single tap (`KC_LEAD`).

Only with these two features in place the tap dances started working for me (aka stopped driving me crazy :)).

## Leader sequences

Look into `leader_stuff.c` for the sequences defined.
