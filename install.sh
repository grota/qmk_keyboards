#!/bin/sh
git submodule update --init --recursive
ln -sf qmk_firmware/* ./
rm readme.md
echo '/users/grota' > .git/modules/qmk_firmware/info/exclude
echo '/layouts/community/ergodox/grota' >> .git/modules/qmk_firmware/info/exclude
echo '/keyboards/handwired/dactyl_manuform/6x6/keymaps/grota' >> .git/modules/qmk_firmware/info/exclude
ln -sfT "$(pwd)"/grota users/grota
ln -sfT "$(pwd)"/ergodox layouts/community/ergodox/grota
ln -sfT "$(pwd)"/dactyl_manuform/6x6 keyboards/handwired/dactyl_manuform/6x6/keymaps/grota
ln -sf ~/Dropbox/Docs/Notes_keyboards.txt .
rm ./*.hex ./*.bin
