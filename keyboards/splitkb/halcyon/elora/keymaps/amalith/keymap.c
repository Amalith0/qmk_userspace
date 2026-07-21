// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// List of layers
enum layers {
    _QWERTY = 0,
    _GAME,
    _SYMBOLS,
};

// Layer keybinds
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//    - - - - - -         - - - - - -
//    - - - - - -         - - - - - -
//    - - - - - -         - - - - - -
//    - - - - - -         - - - - - -
//            - - - - - - - -

    [_QWERTY] = LAYOUT_elora_hlc(
     KC_GRAVE, KC_1 ,  KC_2   , KC_3  ,   KC_4     ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 ,  KC_F5,
     KC_TAB  , KC_Q ,  KC_W   , KC_E  ,   KC_R     ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_QUOT,
     KC_LSFT , KC_A ,  KC_S   , KC_D  ,   KC_F     ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,KC_RSFT,
     KC_LCTL , KC_Z ,  KC_X   , KC_C  ,   KC_V     ,   KC_B , KC_LBRC, CW_TOGG,      KC_DEL , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_EQL,
                                 QK_LOCK,TT(_SYMBOLS), KC_SPC , QK_REP, KC_ESC,     TG(_GAME), KC_ENT ,KC_SPC, KC_BSPC, LSG(KC_S),
     MT(MOD_LALT, G(KC_TAB)), KC_NO,  KC_NO, KC_NO, KC_NO,                                                                KC_MPLY, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_GAME] = LAYOUT_elora_hlc(
     _______  , _______ ,  _______   ,  _______  ,   _______ ,   _______ ,                                        _______ ,  _______ ,  _______ ,   _______ ,  _______ , _______ ,
     KC_T  ,KC_TAB,KC_Q,  KC_W,   KC_E ,   KC_R ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_LCTL , KC_LSFT ,  KC_A   ,  KC_S ,   KC_D ,   KC_F ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_B ,KC_Z, KC_X   ,  KC_C  ,   KC_V ,   KC_G , QK_REP,SH_OS,     _______  , _______, _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
                                 _______, _______, _______, KC_LALT , _______   ,     _______    , _______ ,_______, _______, _______,
     _______, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                _______, KC_NO, KC_NO, KC_NO, KC_NO
    ),

    [_SYMBOLS] = LAYOUT_elora_hlc(
        LCTL(KC_Y) , C(S(KC_1))   ,  C(S(KC_2))    ,  C(S(KC_3))  ,   _______    ,   LALT(KC_F4) ,                                                 KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9  ,  KC_F10 , KC_HOME ,
        LCTL(KC_Z) , LCTL(KC_A)   ,  LCTL(KC_I)  ,     KC_UP     ,    LALT(KC_TAB)   ,   KC_F1 ,                                                 _______,   KC_KP_7,  KC_KP_8 ,   KC_KP_9 , LSG(KC_MINUS), KC_END,
        _______ , LCTL(KC_S)   ,  KC_LEFT    ,      KC_DOWN    ,   KC_RGHT    ,   KC_PAUSE ,                                                 KC_MINS,   KC_KP_4 ,  KC_KP_5 ,   KC_KP_6 , KC_BSLS , _______,
     _______    ,  _______  ,  LALT(KC_LSFT)    , LCTL(KC_C)       ,   LCTL(KC_V)    ,   LCTL(KC_F) , _______ , _______ ,   _______  , _______, LSFT(KC_MINS),   KC_KP_1 ,KC_KP_2, KC_KP_3 , KC_KP_0,_______,
                                            _______       ,   _______    ,   _______ , _______ , _______ ,   _______  , _______        ,_______, _______, _______,
     _______, KC_NO,  KC_NO, KC_NO, KC_NO,                                                                _______, KC_NO, KC_NO, KC_NO, KC_NO
    ),

};

// Encoders
// Soldered left, halycon left, soldered right, halycon right
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(LSFT(KC_TAB), KC_TAB),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif


// Swap ignoring thumb keys and encoders
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
	{{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
	{{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
	{{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},
	{{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}},
	{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
	{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
	{{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
	{{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 11}},
};

#if defined(SWAP_HANDS_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 0, 1, 2, 3 };
#endif

// RGB Lighting
// TODO: add more granular RGB once keymaps are settled.
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

// Keycode overrides
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Make mod-tap modifier work.
        case MT(MOD_LALT, G(KC_TAB)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_TAB)); 
                return false;
            }
            break;
    }
    return true;
}