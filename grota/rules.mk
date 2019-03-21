SRC += grota.c \
       process_records.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += rgb_stuff.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
  SRC += leader_stuff.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += tap_dance.c
endif
