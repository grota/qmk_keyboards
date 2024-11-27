# Overview

## Current Status

- On the right side the black the buzzer and its connection need to be fixed (audio is disabled).
- The right solenoid probably needs its position fixed.

This repo contains the firmware for my [qmk](https://qmk.fm) enabled 5x7 dactyl-manuform using a customized miryoku keymap.

Clone and launch [install.sh](install.sh) to symlink the layout where qmk expects it to be, then launch one of:

- `qmk generate-compilation-database -kb grota_dactyl_manuform/5x7 -km light_miryoku`
- `make grota_dactyl_manuform/5x7:light_miryoku:flash`

## Other useful commands

- `make grota_dactyl_manuform/5x7:light_miryoku:avrdude-split-right`
- `make grota_dactyl_manuform/5x7:light_miryoku:avrdude-split-left`
- `git diff A B -- ':!keyboards*' ':!users*' ':!layouts/*' ':!drivers/*' ':!tests/*' ':!lib/*' ':!platforms/*' ':!docs/*' ':!.github'`
- `make grota_dactyl_manuform/5x7:light_miryoku:update_achordion`

