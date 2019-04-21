/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#define TAPPING_TOGGLE  1

#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2, B6 }
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { F4, B5, B4, E6, D7, C6 }

#define USE_SERIAL

#undef MASTER_RIGHT
//#define MASTER_LEFT
//#define MASTER_RIGHT
#undef MASTER_LEFT
#define EE_HANDS

#define LAYOUT_6x6_sym(\
  L05, L04, L03, L02, L01, L00,                    R00, R01, R02, R03, R04, R05, \
  L15, L14, L13, L12, L11, L10,                    R10, R11, R12, R13, R14, R15, \
  L25, L24, L23, L22, L21, L20,                    R20, R21, R22, R23, R24, R25, \
  L35, L34, L33, L32, L31, L30,                    R30, R31, R32, R33, R34, R35, \
  L45, L44, L43, L42, L41, L40,                    R40, R41, R42, R43, R44, R45, \
            L53, L52,                                        R52, R53,           \
                      L51, L50,                    R50, R51,                     \
                             L61, L60,      R60, R61,                            \
                             L63, L62,      R62, R63                             \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L40, L41, L42, L43, L44, L45 }, \
    { L50, L51, L52, L53, KC_NO, KC_NO }, \
    { L60, L61, L62, L63, KC_NO, KC_NO }, \
\
    { R00, R01, R02, R03, R04, R05 },    \
    { R10, R11, R12, R13, R14, R15 },    \
    { R20, R21, R22, R23, R24, R25 },    \
    { R30, R31, R32, R33, R34, R35 },    \
    { R40, R41, R42, R43, R44, R45 },    \
    { R50, R51, R52, R53, KC_NO, KC_NO },\
    { R60, R61, R62, R63, KC_NO, KC_NO }, \
   }
