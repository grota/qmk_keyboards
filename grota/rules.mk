SRC += grota.c \
       process_records.c

ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += $(USER_PATH)/audio_stuff.c
endif

ifeq ($(strip $(HAPTIC_ENABLE)), yes)
  SRC += $(USER_PATH)/haptic_stuff.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += $(USER_PATH)/rgb_stuff.c
endif

ifeq ($(strip $(LEADER_ENABLE)), yes)
  SRC += $(USER_PATH)/leader_stuff.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += $(USER_PATH)/tap_dance.c
endif
