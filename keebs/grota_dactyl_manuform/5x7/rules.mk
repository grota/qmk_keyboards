MCU = atmega32u4
BOOTLOADER = caterina

MOUSEKEY_ENABLE            = yes
SPLIT_KEYBOARD             = yes
RGBLIGHT_ENABLE            = yes
LTO_ENABLE                 = yes
# AUDIO_ENABLE is 17% of the firmware.
AUDIO_ENABLE               = yes
NO_USB_STARTUP_CHECK       = yes
HAPTIC_ENABLE              = yes
EXTRAKEY_ENABLE            = yes
PROGRAMMABLE_BUTTON_ENABLE = yes
KEY_OVERRIDE_ENABLE        = yes
HAPTIC_DRIVER              = SOLENOID
#DEBOUNCE_TYPE        = sym_eager_pk

CONSOLE_ENABLE    = no
TAP_DANCE_ENABLE  = no
LEADER_ENABLE     = no
COMMAND_ENABLE    = no
SWAP_HANDS_ENABLE = no
BOOTMAGIC_ENABLE  = no
MAGIC_ENABLE      = no
BACKLIGHT_ENABLE  = no
MIDI_ENABLE       = no
UNICODE_ENABLE    = no
BLUETOOTH_ENABLE  = no
SLEEP_LED_ENABLE  = no
GRAVE_ESC_ENABLE  = no

# https://docs.qmk.fm/#/feature_split_keyboard?id=custom-data-sync
GROTA_CUSTOM_DATA_SYNC = no
ifeq ($(strip $(GROTA_CUSTOM_DATA_SYNC)), yes)
  OPT_DEFS += -DGROTA_CUSTOM_DATA_SYNC
	SRC += data_sync_3str.c
endif

GROTA_DISABLE_MUSIC_MODE = yes
ifeq ($(strip $(GROTA_DISABLE_MUSIC_MODE)), yes)
  OPT_DEFS += -DNO_MUSIC_MODE
  # The following does not seem to have an effect (the define above is enough)
  # but I'll leave this because this seems like a bug in qmk core to me.
  MUSIC_ENABLE = no
endif

GROTA_PRINT_MESSAGES = DISABLE_ALL
ifeq ($(strip $(GROTA_PRINT_MESSAGES)), DISABLE_ALL)
  OPT_DEFS += -DNO_DEBUG
  OPT_DEFS += -DNO_PRINT
else ifeq ($(strip $(GROTA_PRINT_MESSAGES)), LEAVE_ONLY_USER_MESSAGES)
  OPT_DEFS += -DNO_DEBUG
  OPT_DEFS += -DUSER_PRINT
endif
