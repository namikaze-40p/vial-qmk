/*
Copyright 2024 aki27

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

// qmk compile -kb aki27/picot_o44 -km vial-custom

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

enum layer_names {
    _QWERTY,
    _NUMS,
    _LOWER,
    _RAISE,
    _TRACK,
    _MACRO,
    _ADJUST,
};

enum custom_keycodes {
  PREV_HISTORY = SAFE_RANGE,
  NEXT_HISTORY,
  PREV_SCREEN,
  NEXT_SCREEN,
  MISSION_CONTROL,
  SHOW_DESKTOP,
  ZOOM_TOGGLE,
};

#define NUMS   MO(_NUMS)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define TRACK  MO(_TRACK)
#define MACRO  MO(_MACRO)
#define ADJUST MO(_ADJUST)

#define L1_ESC  LT(NUMS, KC_ESC)
#define L1_TGL  TG(NUMS)
#define L2_EN   LT(LOWER, KC_LNG2)
#define L3_JP   LT(RAISE, KC_LNG1)
#define L3_0    LT(RAISE, KC_0)
#define L5_BTN2 LT(MACRO, KC_BTN2)
#define L6_EN   LT(ADJUST, KC_LNG2)
#define L6_JP   LT(ADJUST, KC_LNG1)
#define CTL_BKSP RCTL_T(KC_BSPC)
#define SHT_MINS RSFT_T(KC_MINS)
#define SHT_SPC  LSFT_T(KC_SPC)
#define CTL_ENT  RCTL_T(KC_ENT)

#define PREV_H  PREV_HISTORY
#define NEXT_H  NEXT_HISTORY
#define PREV_S  PREV_SCREEN
#define NEXT_S  NEXT_SCREEN
#define M_CTRL  MISSION_CONTROL
#define S_DESK  SHOW_DESKTOP
#define ZOOM_T  ZOOM_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    ZOOM_T,  SCRL_MO, KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                       KC_H,    KC_J,  KC_K,    KC_L,    CTL_BKSP,
        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                       KC_N,    KC_M,  KC_COMM, KC_DOT,  SHT_MINS,
        L1_ESC,  KC_LALT, KC_LGUI, L2_EN,  SHT_SPC, KC_BTN1, L5_BTN2, CTL_ENT, L3_JP, KC_LEFT, KC_RGHT, KC_DEL
    ),
    [_NUMS] = LAYOUT(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,  KC_8,    KC_9,   XXXXXXX,
        KC_LCTL, XXXXXXX, L1_TGL,  KC_TAB,  XXXXXXX,                    XXXXXXX, KC_4,  KC_5,    KC_6,   KC_BSPC,
        KC_LSFT, XXXXXXX, XXXXXXX, KC_LNG1, XXXXXXX,                    XXXXXXX, KC_1,  KC_2,    KC_3,   _______,
        _______, _______, _______, L2_EN,   _______, XXXXXXX, XXXXXXX, _______, L3_0,  KC_COMM, KC_DOT, _______
    ),
    [_LOWER] = LAYOUT(
        KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_QUES,
        KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,                      KC_GRV,  KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT,
        KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,                     KC_TILD, KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO,
        KC_F11,  KC_F12, _______, L2_EN,   KC_SPC,  XXXXXXX, XXXXXXX, KC_ENT,  L6_JP,   KC_BSLS, KC_PIPE, _______
    ),
    [_RAISE] = LAYOUT(
        KC_TAB,  KC_BTN1, KC_MS_U, KC_BTN2, KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_HOME, KC_UP,   KC_END,  XXXXXXX,
        KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_LBRC,                   KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        KC_LSFT, KC_WH_R, KC_BTN3, KC_WH_L, KC_LCBR,                   KC_RCBR, XXXXXXX, KC_PGUP, KC_PGDN, _______,
        _______, KC_LALT, _______, L6_EN,   KC_SPC,  XXXXXXX, XXXXXXX, KC_ENT,  L3_JP,   KC_WH_D, KC_WH_U, _______
    ),
    [_TRACK] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, SCRL_MO, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ESC,  KC_LALT, KC_LGUI, SCRL_MO, SHT_SPC, KC_BTN1, L5_BTN2, CTL_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MACRO] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  M_CTRL, S_DESK,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    PREV_H,  NEXT_H,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    PREV_S,  NEXT_S,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L5_BTN2,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_ADJUST] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, SCRL_SW, L1_TGL,  KC_CAPS, XXXXXXX,                    XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______
    ),
    [7] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [1] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [2] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [3] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [4] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [5] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [6] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [7] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX), ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
};
#endif

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
      case KC_LCTL:
        return true;
      case KC_LSFT:
        return true;
      case SCRL_MO:
        return true;
      default:
        return false;
    }
    return is_mouse_record_user(keycode, record);
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L1_ESC:
        case L2_EN:
        case L3_JP:
        case L3_0:
        case L5_BTN2:
        case L6_EN:
        case L6_JP:
        case CTL_BKSP:
        case SHT_MINS:
        case SHT_SPC:
        case CTL_ENT:
            // Imediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case PREV_H:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_LBRC);
                unregister_code(KC_LGUI);
            }
            return false;
        case NEXT_H:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                tap_code(KC_RBRC);
                unregister_code(KC_LGUI);
            }
            return false;
        case PREV_S:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_COMM);
                unregister_code(KC_LCTL);
            }
            return false;
        case NEXT_S:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_DOT);
                unregister_code(KC_LCTL);
            }
            return false;
        case M_CTRL:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                tap_code(KC_UP);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;
        case S_DESK:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                tap_code(KC_DOWN);
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            return false;
        case ZOOM_T:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                tap_code(KC_8);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        default:
            return true;
    }
}
