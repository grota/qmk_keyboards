# Overview

Just my ergodox-ez keymap, it is and always will be a work in progress (most of the keys are quite stable though).

Most things have been copied from `drashna` and `hacker_dvorak`.

## RGB matrix layers

There is a custom rgb layer indicator that I can cycle through with the other effects and tha also shows how to target the color of specific keys.

## Tap dances

`[` and `]` double tapped will get you `{` and `}`.

`TD_SPECIAL_LEAD_MOVE_TO_LAYER` is `KC_LEAD` on single tap, `KC_LALT` when held, and moves to second layer on double tap.

`TD_COLON_SEMI_CTRL` is `;` on single tap, `:` on double tap and `KC_RCTRL` on held.

## Leader sequences

Look into `leader_stuff.c` for the sequences defined.

## Rgb matrix led indices.

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
