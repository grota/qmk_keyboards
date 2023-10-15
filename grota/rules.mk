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

ifeq ($(strip $(ACHORDION_ENABLE)), yes)
  SRC += $(USER_PATH)/achordion.c
  OPT_DEFS += -DACHORDION_ENABLE
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  SRC += $(USER_PATH)/tap_dance.c
endif

ifeq ($(strip $(GROTA_DEFINE_ARROW)), yes)
  OPT_DEFS += -DGROTA_DEFINE_ARROW
endif

ifeq ($(strip $(GROTA_DEFINE_PRINT_HAPTIC)), yes)
  OPT_DEFS += -DGROTA_DEFINE_PRINT_HAPTIC
endif

ifeq ($(strip $(GROTA_CUSTOM_MEDIA_KC)), yes)
  OPT_DEFS += -DGROTA_CUSTOM_MEDIA_KC
endif

ifeq ($(strip $(GROTA_ENABLE_NUMBERS_FN_KC)), yes)
  OPT_DEFS += -DGROTA_ENABLE_NUMBERS_FN_KC
endif

ifeq ($(strip $(GROTA_ENABLE_INVERTED_SHIFT_US_ANSI)), yes)
  OPT_DEFS += -DGROTA_ENABLE_INVERTED_SHIFT_US_ANSI
endif

ifeq ($(strip $(GROTA_TAPDANCE_SQUARE_BRAKETS)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_SQUARE_BRAKETS
endif

ifeq ($(strip $(GROTA_TAPDANCE_BOOT)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_BOOT
endif
ifeq ($(strip $(GROTA_TAPDANCE_CLEAR_EEPROM)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_CLEAR_EEPROM
endif
ifeq ($(strip $(GROTA_TAPDANCE_REBOOT)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_REBOOT
endif

ifeq ($(strip $(GROTA_TAPDANCE_SET_DEFAULT_LAYER)), yes)
  OPT_DEFS += -DGROTA_TAPDANCE_SET_DEFAULT_LAYER
endif

ifeq ($(strip $(GROTA_ENABLE_ESC_GRAVE)), yes)
  OPT_DEFS += -DGROTA_ENABLE_ESC_GRAVE
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

update_achordion:
	curl -o grota/achordion.h https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.h
	curl -o grota/achordion.c https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.c
