#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "debug.h"
#include "version.h"

#define BASE 0  // default layer
#define QWER 1  // QWER layer
#define SYMB 2  // symbols
#define MDIA 3  // media keys

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
};

enum {
  TD_1_F1 = 0,
  TD_2_F2,
  TD_3_F3,
  TD_4_F4,
  TD_5_F5,
  TD_6_F6,
  TD_7_F7,
  TD_8_F8,
  TD_9_F9,
  TD_0_F10,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1_F1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [TD_2_F2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [TD_3_F3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [TD_4_F4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_5_F5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [TD_6_F6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [TD_7_F7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [TD_8_F8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [TD_9_F9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [TD_0_F10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    | 1    | 2    | 3    | 4    | 5    | LEFT |           | RIGHT| 6    | 7    | 8    | 9    | 0    |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  Esc |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Del    |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L3|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |  Alt | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  | Tab  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Esc   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,           KC_2,        KC_3,        KC_4,        KC_5,        KC_LEFT,
        KC_TAB,         KC_QUOT,        KC_COMM,     KC_DOT,      KC_P,        KC_Y,        KC_ESC,
        KC_DELT,        KC_A,           KC_O,        KC_E,        KC_U,        KC_I,
        KC_LSFT,        CTL_T(KC_SCLN), KC_Q,        KC_J,        KC_K,        KC_X,        KC_HYPR,
        GUI_T(KC_GRV),  KC_QUOT,        KC_LALT,     KC_LEFT,     KC_RGHT,

        // Left thumb cluster
        ALT_T(KC_APP),   KC_LGUI,
                         KC_HOME,
        KC_SPC, KC_BSPC, KC_END,

        // right hand
        KC_RGHT,  KC_6,        KC_7,        KC_8,        KC_9,        KC_0,           KC_BSLS,
        DF(QWER), KC_F,        KC_G,        KC_C,        KC_R,        KC_L,           KC_SLSH,
                  KC_D,        KC_H,        KC_T,        KC_N,        LT(MDIA, KC_S), KC_MINS,
        KC_MEH,   KC_B,        KC_M,        KC_W,        KC_V,        CTL_T(KC_Z),    KC_RSFT,
                               KC_UP,       KC_DOWN,     KC_LBRC,     KC_RBRC,        MO(SYMB),
        KC_LALT,  KC_TAB,
        KC_PGUP,
        KC_PGDN,  KC_ESC,      KC_ENT
    ),
/* Keymap 1: QWERTY layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    | 1/F1 | 2/F2 | 3/F3 | 4/F4 | 5/F5 | LEFT |           | RIGHT| 6/F6 | 7/F7 | 8/F8 | 9/F9 | 0/F10|   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q    | W    | E    | R    | T    |  Esc |           | L1   | Y    | U    | I    | O    | P    |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Del    | A    | S    | D    | F    | G    |------|           |------| H    | J    | K    | L    | ;/L3 |   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl| X    | C    | V    | B    |      |           |      | N    | M    | ,    | .    |'/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |GRV/L1|  '"  | Alt  | Left | Right|                                       | Up   | Down | [    |   ]  | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  | Tab  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Esc  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[QWER] = LAYOUT_ergodox(
        KC_EQL,       TD(TD_1_F1), TD(TD_2_F2), TD(TD_3_F3), TD(TD_4_F4), TD(TD_5_F5), KC_LEFT,
        KC_TAB,       KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_ESC,
        KC_DELT,      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,
        KC_LSFT,      CTL_T(KC_Z), KC_X,        KC_C,        KC_V,        KC_B,        KC_HYPR,
        GUI_T(KC_GRV),KC_QUOT,     KC_LALT,     KC_LEFT,     KC_RGHT,

        ALT_T(KC_APP),    KC_LGUI,
                          KC_HOME,
        KC_SPC,  KC_BSPC, KC_END,

        // right hand
        KC_RGHT,  TD(TD_6_F6), TD(TD_7_F7), TD(TD_8_F8), TD(TD_9_F9), TD(TD_0_F10),      KC_BSLS,
        DF(BASE), KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,              KC_SLSH,
                  KC_H,        KC_J,        KC_K,        KC_L,        LT(MDIA, KC_SCLN), KC_MINS,
        KC_MEH,   KC_N,        KC_M,        KC_COMM,     KC_DOT,      CTL_T(KC_QUOT),    KC_RSFT,
                               KC_UP,       KC_DOWN,     KC_LBRC,     KC_RBRC,           _______,
        KC_LALT, KC_TAB,
        KC_PGUP,
        KC_PGDN, KC_ESC, KC_ENT
    ),
/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |%/Ctrl|   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EEPROM|      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,     _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,     _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
  EEP_RST, _______, _______, _______, _______,                                         _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                               RGB_MOD, _______,     RGB_TOG, RGB_SLD,
                                                        _______,     _______,
                                      RGB_VAD, RGB_VAI, _______,     _______, RGB_HUD, RGB_HUI
),
/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                       _______, _______, _______, _______, _______, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, KC_WBAK
),
};
// clang-format on

#define OFF 0
#define DIM 7
#define BRIGHT 64

const uint8_t DEFAULT_LAYER_LEDS[][3] = {
    [BASE] = {OFF, OFF, OFF},
    [QWER] = {DIM, DIM, DIM},
};

const uint8_t LAYER_LEDS[][3] = {
    [SYMB] = {BRIGHT, OFF, OFF},
    [MDIA] = {OFF, BRIGHT, OFF},
};

void set_all_lights(const uint8_t leds[]) {
  if (leds[0] != OFF) {
    ergodox_right_led_1_on();
    ergodox_right_led_1_set(leds[0]);
  }
  if (leds[1] != OFF) {
    ergodox_right_led_2_on();
    ergodox_right_led_2_set(leds[1]);
  }
  if (leds[2] != OFF) {
    ergodox_right_led_3_on();
    ergodox_right_led_3_set(leds[2]);
  }
}

uint32_t previous_seen_state;
void set_lights(uint8_t layer) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  set_all_lights(DEFAULT_LAYER_LEDS[biton32(default_layer_state)]);
  set_all_lights(LAYER_LEDS[layer]);
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_lights(BASE);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  if (previous_seen_state != (layer_state | default_layer_state)) {
    previous_seen_state = layer_state | default_layer_state;
    set_lights(biton(layer_state));
  }
};

uint32_t layer_state_set_user(uint32_t state) {
  set_lights(biton32(state));
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      case RGB_SLD:
        rgblight_mode(1);
        return false;
    }
  }
  return true;
};
