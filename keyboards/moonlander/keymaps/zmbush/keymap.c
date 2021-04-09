/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE,  // default layer
    QWER,  // QWERTY layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Base Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    | 1    | 2    | 3    | 4    | 5    | LEFT |           | RIGHT| 6    | 7    | 8    | 9    | 0    |   \    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  Esc |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * | Del    |   A  |   O  |   E  |   U  |   I  | Hyper|           | Meh  |   D  |   H  |   T  |   N  |S / L3|   -    |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |                         |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
     * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
     *   |Win/`~|  '"  |  Alt | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |     L1      |       |   Page Up   |
     *                                 ,------|-------------|       |-------------|------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | Space|Backsp| Win  |       | PgDn | ESC  |Enter |
     *                                 |      |ace   |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [BASE] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_ESC,            DF(QWER),KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_DELT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HYPR,           KC_MEH,  KC_D,    KC_H,    KC_T,    KC_N,    LT(MDIA, KC_S), KC_MINS,
        KC_LSFT, LCTL_T(KC_SCLN),KC_Q,KC_J, KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    RCTL_T(KC_Z), KC_RSFT,
     GUI_T(KC_GRV),KC_QUOT,KC_LALT,KC_LEFT, KC_RGHT,         DF(QWER),           KC_PGUP,          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_END,            KC_PGDN, KC_ESC,  KC_ENT
    ),

    /* Keymap 1: QWERTY Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    | 1    | 2    | 3    | 4    | 5    | LEFT |           | RIGHT| 6    | 7    | 8    | 9    | 0    |   \    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Esc |           |  L0  |   Y  |   U  |   I  |   O  |   P  |   /    |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * | Del    |   A  |   S  |   D  |   F  |   G  | Hyper|           | Meh  |   H  |   J  |   K  |   L  |; / L3|   -    |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |                         |   N  |   M  |   ,  |   .  |'/Ctrl| RShift |
     * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
     *   |Win/`~|  '"  |  Alt | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |     L0      |       |   Page Up   |
     *                                 ,------|-------------|       |-------------|------.
     *                                 |      |      |      |       |      |      |      |
     *                                 | Space|Backsp| Win  |       | PgDn | ESC  |Enter |
     *                                 |      |ace   |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [QWER] = LAYOUT_moonlander(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,            DF(BASE),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH,
        KC_DELT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(MDIA, KC_SCLN), KC_MINS,
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_QUOT), KC_RSFT,
     GUI_T(KC_GRV),KC_QUOT,KC_LALT,KC_LEFT, KC_RGHT,         DF(BASE),           KC_PGUP,          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_PGDN, KC_ESC,  KC_ENT
    ),

    /* Keymap 2: Symbol Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |Version | F1   | F2   | F3   | F4   | F5   |      |           |      | F6   | F7   | F8   | F9   | F10  |   F11  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * |        |   #  |   $  |   (  |   )  |   `  |      |           |      | Down |   4  |   5  |   6  |  +   |        |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * |        |   %  |   ^  |   [  |   ]  |   ~  |                         |   &  |   1  |   2  |   3  |  \   |        |
     * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
     *   |Train |      |      |      |      |                                       |      |   .  |   0  |  =   |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Brightness+ |       | RGB Toggle  |
     *                                 ,------|-------------|       |-------------|------.
     *                                 |      |      |      |       | Layer|      |      |
     *                                 | Hue- |Bright| Hue+ |       | Color|      | Mode |
     *                                 |      |ness- |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [SYMB] = LAYOUT_moonlander(
        VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
    WEBUSB_PAIR, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, RGB_MOD
    ),

    /* Keymap 3: Media and Mouse keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | LED lev|      |      |      |      |      |      |           |      |      |      |      |      |      | Reset  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
     * |        |      |MsLeft|MsDown|MsRght|      |      |           |      |      |      |      |      |      |  Play  |
     * |--------+------+------+------+------+------|------'           `------|------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                         |      |      | Prev | Next |      |        |
     * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
     *   |      |      |      | Lclk | Rclk |                                       |VolUp | VolDn| Mute |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |             |       |             |
     *                                 ,------|-------------|       |-------------|------.
     *                                 |      |      |      |       |      |      |Brwser|
     *                                 |      |      |      |       |      |      | Back |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [MDIA] = LAYOUT_moonlander(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        CK_TOGG, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        CK_UP,   _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        CK_DOWN, _______, _______, KC_BTN1, KC_BTN2,          _______,           _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, KC_WBAK
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}

const bool DEFAULT_LAYER_LEDS[][6] = {
    [BASE] = {false, false, false, false, false},
    [QWER] = {true, true, true, false, false, false},
};

const bool LAYER_LEDS[][6] = {
    [SYMB] = {false, false, false, true, false, false},
    [MDIA] = {false, false, false, false, true, false},
};

void set_all_lights(const bool leds[]) {
    if (leds[0]) ML_LED_1(leds[0]);
    if (leds[1]) ML_LED_2(leds[1]);
    if (leds[2]) ML_LED_3(leds[2]);
    if (leds[3]) ML_LED_4(leds[3]);
    if (leds[4]) ML_LED_5(leds[4]);
    if (leds[5]) ML_LED_6(leds[5]);
}

void set_lights(layer_state_t state) {
    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

    set_all_lights(LAYER_LEDS[biton(state)]);
    set_all_lights(DEFAULT_LAYER_LEDS[biton32(default_layer_state)]);
}

uint32_t previous_seen_state;
void matrix_scan_user() {
    if (previous_seen_state != (layer_state | default_layer_state)) {
        previous_seen_state = layer_state | default_layer_state;
        set_lights(layer_state);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_lights(state);
    return state;
}
