// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _GAME,
    _SYMBOLS,
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// There is an extra row added for the Halcyon modules. Currently only the Encoder module is
// supported but we reserve 5 keys per half for future expansion. Your personal keymap will also
// need to be updated to include this row, and the `LAYOUT` macro will need to be updated to
// `LAYOUT_elora_hlc` in order to compile.

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |CAPWRD|HOME  |  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | L2   | Space | LALT |ENTER|  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      |       |      |     |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_QWERTY] = LAYOUT_elora_hlc(
     KC_GRAVE, KC_1 ,  KC_2   , KC_3  ,   KC_4     ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 ,  KC_F5,
     KC_TAB  , KC_Q ,  KC_W   , KC_E  ,   KC_R     ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_QUOT,
     KC_LSFT , KC_A ,  KC_S   , KC_D  ,   KC_F     ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,KC_RSFT,
     KC_LCTL , KC_Z ,  KC_X   , KC_C  ,   KC_V     ,   KC_B , CW_TOGG, LCTL(KC_V),       LCTL(KC_C), KC_DEL, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, LSG(KC_S),
                                 QK_LOCK,TT(_SYMBOLS), KC_SPC , QK_REP, KC_ESC,     TG(_GAME), KC_ENT ,KC_SPC, KC_BSPC, LCTL(KC_I),
     MT(MOD_LALT, LALT(KC_TAB)), KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Base Layer: Dvorak
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   | ' "  | , <  | . >  |   P  |   Y  |                              |   F  |   G  |   C  |   R  |   L  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   O  |   E  |   U  |   I  |                              |   D  |   H  |   T  |   N  |   S  |Ctrl/- _|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | ; :  |   Q  |   J  |   K  |   X  | [ {  |CapsLk|  |F-keys|  ] } |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_GAME] = LAYOUT_elora_hlc(
     _______  , _______ ,  _______   ,  _______  ,   _______ ,   _______ ,                                        _______ ,  _______ ,  _______ ,   _______ ,  _______ , _______ ,
     KC_T  ,KC_TAB,KC_Q,  KC_W,   KC_E ,   KC_R ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_G , KC_LSFT ,  KC_A   ,  KC_S ,   KC_D ,   KC_F ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_B ,KC_LCTL, KC_Z   ,  KC_X  ,   KC_C ,   KC_V , _______,_______,     _______  , _______, _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
                                 _______, _______, _______, _______ , _______   ,     _______    , _______ ,_______, _______, _______,
     _______, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                _______, KC_NO, KC_NO, KC_NO, KC_NO
    ),

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYMBOLS] = LAYOUT_elora_hlc(
     _______    , _______   ,  _______    , LALT(KC_F4)   ,   _______    ,   _______ ,                                                 _______ ,  _______ ,  _______ ,   KC_LBRC ,  KC_RBRC , KC_HOME ,
        _______ , _______   ,  _______  ,    _______      ,   _______    ,   _______ ,                                                 KC_EQL,   KC_KP_7,  KC_KP_8 ,   KC_KP_9 , LSG(KC_MINUS), KC_END,
        _______ , LCTL(KC_S)   ,  KC_LEFT    , KC_UP         ,   KC_RGHT    ,   KC_PAUSE ,                                                 KC_MINS,   KC_KP_4 ,  KC_KP_5 ,   KC_KP_6 , KC_BSLS , _______,
     _______    , LCTL(KC_Y)   ,  LCTL(KC_Z)    , KC_DOWN       ,   _______    ,   _______ , _______ , _______ ,   _______  , _______, LSFT(KC_MINS),   KC_KP_1 ,KC_KP_2, KC_KP_3 , KC_KP_0,_______,
                                            _______       ,   _______    ,   _______ , KC_LALT , _______ ,   _______  , _______        ,_______, _______, _______,
     _______, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                _______, KC_NO, KC_NO, KC_NO, KC_NO
    ),

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(LSFT(KC_TAB), KC_TAB),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 2:
                rgb_matrix_set_color(i, 255,191,0);
                break;
            case 1:
                rgb_matrix_set_color(i, 15,82,186);
                break;
            default:
                rgb_matrix_set_color(i, 108,59,170);
                break;
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LALT, LALT(KC_TAB)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(LALT(KC_TAB)); 
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}