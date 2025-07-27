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

// qmk compile -kb aki27/cocot38mini/v2 -km vial_rs-custom

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

#define MS_BTN1 KC_MS_BTN1
#define MS_BTN2 KC_MS_BTN2
#define MS_BTN3 KC_MS_BTN3

#define COCOT_SCROLL_INV_DEFAULT false

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
    FULL_SCREEN,
    CENTER_SCREEN,
    LEFT_SCREEN,
    RIGHT_SCREEN,
    LAUNCH_RAYCAST,
  };

#define NUMS   MO(_NUMS)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define TRACK  MO(_TRACK)
#define MACRO  MO(_MACRO)
#define ADJUST MO(_ADJUST)

#define L1_TGL  TG(NUMS)
#define L2_EN   LT(LOWER, KC_LNG2)
#define L3_JP   LT(RAISE, KC_LNG1)
#define L3_0    LT(RAISE, KC_0)
#define L4_BTN2 LT(SCRL_MO, MS_BTN2)
#define L5_ESC  LT(MACRO, KC_ESC)
#define L6_EN   LT(ADJUST, KC_LNG2)
#define L6_JP   LT(ADJUST, KC_LNG1)
#define ALT_ESC  RALT_T(KC_ESC)
#define SHT_MINS RSFT_T(KC_MINS)
#define SHT_SPC  LSFT_T(KC_SPC)
#define CTL_ENT  RCTL_T(KC_ENT)

#define PREV_H  PREV_HISTORY
#define NEXT_H  NEXT_HISTORY
#define PREV_S  PREV_SCREEN
#define NEXT_S  NEXT_SCREEN
#define M_CTRL  MISSION_CONTROL
#define S_DESK  SHOW_DESKTOP
#define F_SCR   FULL_SCREEN
#define C_SCR   CENTER_SCREEN
#define L_SCR   LEFT_SCREEN
#define R_SCR   RIGHT_SCREEN
#define RAYCAST LAUNCH_RAYCAST

// NOTE:
// https://github.com/vial-kb/vial-qmk/issues/766
// vialではFWコンパイル時にキーマップでcomboを定義できないため、
// FWを書き込み後にvialのGUIでcomboを定義する必要がある。
// ↓以下設定メモ
// KC_D + KC_F --> MO(1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_Q,   KC_W,   KC_E,    KC_R,   KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
        KC_A,   KC_S,   KC_D,    KC_F,   KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,   KC_BSPC,
        KC_Z,   KC_X,   KC_C,    KC_V,   KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT, SHT_MINS,
                        KC_LGUI, L2_EN,  SHT_SPC,  L4_BTN2, MS_BTN1,  CTL_ENT, L3_JP,   ALT_ESC
    ),
    [_NUMS] = LAYOUT(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,   KC_8,   KC_9,   KC_DEL,
        KC_LCTL, XXXXXXX, L1_TGL,  KC_TAB,  XXXXXXX,                   KC_DOT,  KC_4,   KC_5,   KC_6,   KC_BSPC,
        KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_1,   KC_2,   KC_3,   SHT_MINS,
                           KC_LGUI, L2_EN,  _______, XXXXXXX, XXXXXXX, _______, L3_0,   KC_COMM
    ),
    [_LOWER] = LAYOUT(
        KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                  KC_CIRC, KC_AMPR, KC_ASTR, KC_SLSH, KC_QUES,
        KC_F1,   KC_F2, KC_F3,   KC_F4,  KC_F5,                    KC_GRV,  KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT,
        KC_F6,   KC_F7, KC_F8,   KC_F9,  KC_F10,                   KC_TILD, KC_UNDS, KC_PLUS, KC_COLN, KC_DQUO,
                        KC_LGUI, L2_EN,  RAYCAST,  KC_F11, KC_F12, KC_BSLS, L6_JP,   KC_PIPE
    ),
    [_RAISE] = LAYOUT(
        KC_TAB,  KC_BTN1, KC_MS_U, KC_BTN2, KC_LPRN,                    KC_RPRN, KC_HOME, KC_UP,   KC_END,  KC_DEL,
        KC_LCTL, KC_MS_L, KC_MS_D, KC_MS_R, KC_LBRC,                    KC_RBRC, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX, KC_LCBR,                    KC_RCBR, MACRO,   KC_PGUP, KC_PGDN, _______,
                           KC_LGUI, L6_EN,   KC_SPC,  XXXXXXX, XXXXXXX, KC_ENT,  L3_JP,   XXXXXXX
    ),
    [_TRACK] = LAYOUT(
        KC_Q,   KC_W,   KC_E,    KC_R,  KC_T,                      M_CTRL,  S_DESK, KC_I,    KC_O,   KC_P,
        KC_A,   KC_S,   KC_D,    KC_F,  KC_G,                      PREV_H,  NEXT_H, KC_K,    KC_L,   KC_BSPC,
        KC_Z,   KC_X,   KC_C,    KC_V,  KC_B,                      PREV_S,  NEXT_S, KC_COMM, KC_DOT, XXXXXXX,
                        KC_LGUI, L2_EN, SHT_SPC, SCRL_MO, MS_BTN1, CTL_ENT, L3_JP,  ALT_ESC
    ),
    [_MACRO] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, L_SCR,   R_SCR,   C_SCR,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, F_SCR,   MACRO,   XXXXXXX
    ),
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, L1_TGL,  KC_CAPS, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [7] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    [1] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [2] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [3] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [4] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [5] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [6] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
    [7] =   { ENCODER_CCW_CW(XXXXXXX, XXXXXXX) },
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



#ifdef RGB_MATRIX_ENABLE

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    int is_layer = get_highest_layer(layer_state|default_layer_state);
    HSV hsv = {0, 255, rgblight_get_val()};
    if (is_layer == 1) {
      hsv.h = 11; //CORAL
    } else if (is_layer == 2)  {
      hsv.h = 85; //GREEN
    } else if (is_layer == 3)  {
      hsv.h = 43; //YELLOW
    } else if (is_layer == 4)  {
      hsv.h = 0; //RED
    } else if (is_layer == 5)  {
      hsv.h = 191; //PURPLE
    } else if (is_layer == 6)  {
      hsv.h = 64; //CHARTREUSE
    } else if (is_layer == 7)  {
      hsv.h = 224;
    } else {
      hsv.h = 128; //CYAN
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i <= led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) {
          rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
};

#endif


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L2_EN:
        case L3_JP:
        case L3_0:
        case L5_ESC:
        case L4_BTN2:
        case L6_EN:
        case L6_JP:
        case ALT_ESC:
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
        case F_SCR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                tap_code(KC_ENT);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        case C_SCR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                tap_code(KC_SLSH);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        case L_SCR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                tap_code(KC_LEFT);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        case R_SCR:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LGUI);
                tap_code(KC_RGHT);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        case RAYCAST:
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_SPC);
                unregister_code(KC_LALT);
            }
            return false;
        default:
            return true;
    }
}
