/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = {
    { KC_SLSH, KC_L, KC_R, KC_C, KC_G, KC_F },
    { KC_MINS, KC_S, KC_N, KC_T, KC_H, KC_D },
    { LM(2, MOD_LSFT), KC_Z, KC_V, KC_W, KC_M, KC_B },
    { KC_NO, KC_NO, KC_NO, KC_LALT, MO(4), KC_ENT },
    { KC_TAB, KC_AMPR, KC_COMM, KC_DOT, KC_P, KC_Y },
    { MO(6), KC_A, KC_O, KC_E, KC_U, KC_I },
    { LM(2, MOD_LSFT), KC_SCLN, KC_Q, KC_J, KC_K, KC_X },
    { KC_NO, KC_NO, KC_NO, KC_LCTL, MO(3), KC_SPC },
  },
  [1] = {
    { KC_LBRC, KC_P, KC_O, KC_I, KC_U, KC_Y },
    { KC_QUOT, KC_SCLN, KC_L, KC_K, KC_J, KC_H },
    { KC_RSFT, KC_SLSH, KC_DOT, KC_COMM, KC_M, KC_N },
    { KC_NO, KC_NO, KC_NO, KC_LALT, MO(4), KC_ENT },
    { KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T },
    { MO(6), KC_A, KC_S, KC_D, KC_F, KC_G },
    { KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B },
    { KC_NO, KC_NO, KC_NO, KC_LCTL, MO(3), KC_SPC },
  },
  [2] = {
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_RO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, MACRO00, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS },
  },
  [3] = {
    { KC_BSPC, KC_P0, KC_P9, KC_P8, KC_P7, KC_P6 },
    { KC_PMNS, KC_PIPE, KC_P6, KC_P5, KC_P4, KC_NLCK },
    { KC_NO, KC_KANA, KC_P3, KC_P2, KC_P1, KC_P0 },
    { KC_NO, KC_NO, KC_NO, KC_RALT, MO(5), KC_ENT },
    { KC_ESC, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5 },
    { KC_LCTL, KC_COLN, KC_LCBR, KC_UNDS, KC_DQUO, KC_JYEN },
    { KC_LSFT, KC_HANJ, KC_PSCR, KC_EQL, KC_SLSH, LSFT(KC_JYEN) },
    { KC_NO, KC_NO, KC_NO, KC_LCTL, KC_TRNS, KC_SPC },
  },
  [4] = {
    { KC_BSPC, KC_SLCK, KC_END, KC_PGUP, KC_PGDN, KC_HOME },
    { KC_NO, KC_ESC, KC_RGHT, KC_UP, KC_DOWN, KC_LEFT },
    { KC_NO, KC_NO, KC_DOT, KC_G, KC_NO, KC_NO },
    { KC_NO, KC_NO, KC_NO, KC_RALT, KC_TRNS, KC_ENT },
    { KC_TAB, KC_EXLM, KC_LBRC, KC_HASH, KC_DLR, KC_PERC },
    { KC_CAPS, KC_QUES, KC_RCBR, KC_PIPE, KC_ASTR, KC_LPRN },
    { KC_LSFT, KC_LGUI, KC_CIRC, KC_PLUS, KC_RBRC, KC_BSLS },
    { KC_NO, KC_NO, KC_NO, KC_LCTL, MO(5), KC_SPC },
  },
  [5] = {
    { KC_F12, KC_F11, KC_F10, KC_F9, KC_F8, KC_F7 },
    { KC_F13, KC_5, KC_4, KC_3, KC_2, KC_1 },
    { KC_NO, KC_0, KC_9, KC_8, KC_7, KC_6 },
    { KC_NO, KC_NO, KC_NO, KC_RALT, KC_TRNS, KC_ENT },
    { KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6 },
    { RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_K, KC_SLEP },
    { RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_B, KC_F24 },
    { KC_NO, KC_NO, KC_NO, KC_LCTL, KC_TRNS, KC_SPC },
  },
  [6] = {
    { KC_TRNS, KC_INS, KC_END, KC_PGUP, KC_PGDN, KC_HOME },
    { LCTL(LGUI(KC_RGHT)), LCTL(LGUI(KC_LEFT)), KC_RGHT, KC_UP, KC_DOWN, KC_LEFT },
    { KC_TRNS, KC_TRNS, KC_LPRN, KC_ASTR, LSFT(KC_F10), KC_TRNS },
    { KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_BTN1, KC_VOLU, KC_DEL, KC_TRNS, KC_TRNS },
    { KC_TRNS, KC_TRNS, KC_VOLD, KC_BSPC, KC_ESC, TG(1) },
    { KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, LCTL(KC_LBRC), KC_TRNS },
    { KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_MPLY },
  },
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
