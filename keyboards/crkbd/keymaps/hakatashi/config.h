/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

//#define TAPPING_FORCE_HOLD
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLED_NUM 54        // 左右でユニークな番号を使って制御
    #undef RGBLED_SPLIT
    #define RGBLED_SPLIT { 27, 27 }  // defaultだと{6, 6}バックライトLEDのみになっている
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define RGBLED_NUM       54 // Number of LEDs
#    define DRIVER_LED_TOTAL RGBLED_NUM
#    define RGB_MATRIX_SPLIT { 27, 27 }
#    define SPLIT_TRANSPORT_MIRROR

#    define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_MATRIX_LED_FLUSH_LIMIT 16
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#    define RGB_MATRIX_HUE_STEP 10
#    define RGB_MATRIX_SAT_STEP 17
#    define RGB_MATRIX_VAL_STEP 17
#    define RGB_MATRIX_SPD_STEP 10
#endif
