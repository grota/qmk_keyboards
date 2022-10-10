#!/bin/sh
git submodule update --init --recursive
ln -sf qmk_firmware/* ./
rm readme.md
echo '/users/grota' > .git/modules/qmk_firmware/info/exclude
echo '/layouts/community/ergodox/grota' >> .git/modules/qmk_firmware/info/exclude
echo '/keyboards/grota_dactyl_manuform' >> .git/modules/qmk_firmware/info/exclude
ln -sfT "$(pwd)"/grota users/grota
ln -sfT "$(pwd)"/ergodox layouts/community/ergodox/grota
ln -sfT "$(pwd)"/keebs/grota_dactyl_manuform keyboards/grota_dactyl_manuform
ln -sf ~/Dropbox/Docs/Notes_keyboards.txt .
rm ./*.hex ./*.bin
