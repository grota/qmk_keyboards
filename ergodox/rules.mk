SRC = matrix.c
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
COMMAND_ENABLE   = no
#CONSOLE_ENABLE   = yes
OPT_DEFS += -DDISABLE_RGB_MATRIX_CYCLE_ALL

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += rgb_stuff.c
endif
