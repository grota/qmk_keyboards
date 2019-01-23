SRC = matrix.c

RGB_MATRIX_ENABLE = yes
TAP_DANCE_ENABLE = yes
LEADER_ENABLE = no
COMMAND_ENABLE   = no
CONSOLE_ENABLE   = no
RGBLIGHT_ENABLE = no

#OPT_DEFS += -DDISABLE_RGB_MATRIX_CYCLE_ALL

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += rgb_stuff.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
  SRC += leader_stuff.c
endif
