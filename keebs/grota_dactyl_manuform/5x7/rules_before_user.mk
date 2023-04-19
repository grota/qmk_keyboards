MOUSEKEY_ENABLE            ?= yes
RGBLIGHT_ENABLE            ?= yes
LTO_ENABLE                 ?= yes
# AUDIO_ENABLE is 17% of the firmware.
AUDIO_ENABLE               ?= yes
NO_USB_STARTUP_CHECK       ?= yes
HAPTIC_ENABLE              ?= yes
EXTRAKEY_ENABLE            ?= yes
HAPTIC_DRIVER              ?= SOLENOID
SPLIT_KEYBOARD             ?= yes
#DEBOUNCE_TYPE        = sym_eager_pk

AVR_USE_MINIMAL_PRINTF = yes
USER_NAME := grota

# key override is disabled for fimware size considerations: my process_record_user() is lighter and good enough for now.
KEY_OVERRIDE_ENABLE         ?= no
TAP_DANCE_ENABLE            ?= no
PROGRAMMABLE_BUTTON_ENABLE  ?= no
DYNAMIC_TAPPING_TERM_ENABLE ?= no
CONSOLE_ENABLE              ?= no
LEADER_ENABLE               ?= no
COMMAND_ENABLE              ?= no
SWAP_HANDS_ENABLE           ?= no
BOOTMAGIC_ENABLE            ?= no
MAGIC_ENABLE                ?= no
BACKLIGHT_ENABLE            ?= no
MIDI_ENABLE                 ?= no
UNICODE_ENABLE              ?= no
BLUETOOTH_ENABLE            ?= no
SLEEP_LED_ENABLE            ?= no
GRAVE_ESC_ENABLE            ?= no
SPACE_CADET_ENABLE          ?= no

GROTA_DISABLE_MUSIC_MODE ?= yes
GROTA_PRINT_MESSAGES     ?= DISABLE_ALL
GROTA_CUSTOM_DATA_SYNC   ?= no

# https://docs.qmk.fm/#/feature_split_keyboard?id=custom-data-sync
ifeq ($(strip $(GROTA_CUSTOM_DATA_SYNC)), yes)
  OPT_DEFS += -DGROTA_CUSTOM_DATA_SYNC
  SRC += data_sync_3str.c
endif
