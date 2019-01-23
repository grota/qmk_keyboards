#!/bin/sh
git submodule update --init --recursive
ln -sf qmk_firmware/* ./
rm readme.md
echo '/layouts/community/ergodox/grota' > .git/modules/qmk_firmware/info/exclude
ln -sf "$(pwd)"/ergodox layouts/community/ergodox/grota
