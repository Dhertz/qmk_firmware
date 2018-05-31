/*
Copyright 2015 Jun Wako <wakojun@gmail.com>
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
#include "whitefox.h"
#include "dhertz.h"

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Backsp|Del|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Enter|PgU|
     * |------------------------------------------------------`    |---|
     * |SrCtl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  \|    |PgD|
     * |---------------------------------------------------------------|
     * |Shif|  #|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |Hom|
     * |---------------------------------------------------------------|
     * |NcCtl|  Alt| CTab|        LyrSpc       |CGv|Iso|CSL|Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP_ISO( \
        KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,    KC_DEL, \
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,             KC_PGUP,\
       SRCH_CTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,     KC_ENT, KC_PGDN,\
        KC_LSFT,HSH_TLD,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,  KC_HOME,\
        NC_CTL, KC_LALT,CMD_TAB_CMD,           LYR_SPC,          CMD_GRV_CMD,ISO_COUNTRY_CODE,CMD_SFT_L,     KC_LEFT,KC_DOWN,KC_RGHT \
    ),
    /* Layer 1: HHKB mode (Space)
     * ,---------------------------------------------------------------.
     * |  §| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| Backsp|Ins|
     * |---------------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus| Up|   |     |Del|
     * |------------------------------------------------------`    |---|
     * |      |VoD|VoU|Mut|   |   |   |Bsp|Del|CSL|Lef|Rig|  `|    |PgU|
     * |---------------------------------------------------------------|
     * |    |  `|   |   |CAC|   |   |   |   |   |   |Dow|      |PgU|PgD|
     * |---------------------------------------------------------------|
     * |     |     |     |                     |   |   |   |Hom|PgD|End|
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP_ISO( \
        KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12, KC_BSPC,    KC_INS, \
        KC_CAPS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,BL_INC, KC_TRNS,KC_TRNS,KC_PSCR,KC_SLCK,KC_TRNS,KC_PAUS,  KC_UP,             KC_DEL, \
        KC_TRNS,KC_VOLD,KC_VOLU,KC_MUTE,KC_TRNS,BL_TOGG,KC_TRNS,KC_BSPC,KC_DEL, CMD_SFT_L,KC_LEFT,KC_RGHT,KC_NUBS,   KC_PENT,KC_PGUP,\
        KC_TRNS,KC_NUBS,KC_TRNS,KC_TRNS,CMD_ALT_C, BL_DEC, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_DOWN,KC_TRNS,KC_TRNS,  KC_PGUP,KC_PGDN,\
        KC_TRNS,KC_TRNS,KC_TRNS,                        KC_TRNS,                KC_TRNS,KC_TRNS,KC_TRNS,     KC_HOME,KC_PGDN,KC_END  \
    ),
};
