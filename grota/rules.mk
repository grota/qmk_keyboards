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

GROTA_DEFINE_ARROW = no
ifeq ($(strip $(GROTA_DEFINE_ARROW)), yes)
  OPT_DEFS += -DGROTA_DEFINE_ARROW
endif

GROTA_DEFINE_PRINT_HAPTIC = no
ifeq ($(strip $(GROTA_DEFINE_PRINT_HAPTIC)), yes)
  OPT_DEFS += -DGROTA_DEFINE_PRINT_HAPTIC
endif

GROTA_TAPDANCE_SQUARE_BRAKETS = no
ifeq ($(strip $(GROTA_TAPDANCE_SQUARE_BRAKETS)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_SQUARE_BRAKETS
endif

GROTA_TAPDANCE_BOOT = no
ifeq ($(strip $(GROTA_TAPDANCE_BOOT)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_BOOT
endif

ifeq ($(strip $(GROTA_DISABLE_MUSIC_MODE)), yes)
  OPT_DEFS += -DNO_MUSIC_MODE
  # The following does not seem to have an effect (the define above is enough)
  # but I'll leave this because this seems like a bug in qmk core to me.
  MUSIC_ENABLE = no
endif

ifeq ($(strip $(GROTA_PRINT_MESSAGES)), DISABLE_ALL)
  OPT_DEFS += -DNO_DEBUG
  OPT_DEFS += -DNO_PRINT
else ifeq ($(strip $(GROTA_PRINT_MESSAGES)), LEAVE_ONLY_USER_MESSAGES)
  OPT_DEFS += -DNO_DEBUG
  OPT_DEFS += -DUSER_PRINT
endif
