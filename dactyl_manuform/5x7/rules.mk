.PHONY: asciiart

asciiart:
	keymapviz -k dactyl_manuform5x7 -t fancy -r dactyl_manuform/5x7/keymap.c -c dactyl_manuform/5x7/keymapviz.labels

RGBLIGHT_ENABLE = yes
DEBUG = no
DEBOUNCE_TYPE = eager_pk
LTO_ENABLE = yes
AUDIO_ENABLE = yes           # Audio output on port C6
NO_USB_STARTUP_CHECK = yes

TAP_DANCE_ENABLE = no
LEADER_ENABLE = no
COMMAND_ENABLE   = no
CONSOLE_ENABLE   = no

SWAP_HANDS_ENABLE = no
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
