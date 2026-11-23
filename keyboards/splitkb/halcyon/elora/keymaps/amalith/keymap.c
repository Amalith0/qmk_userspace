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

    [_QWERTY] = LAYOUT(
     KC_GRAVE, KC_1 ,  KC_2   , KC_3  ,   KC_4     ,   KC_5 ,                                        KC_6 ,  KC_7 ,  KC_8 ,   KC_9 ,  KC_0 ,  KC_F5,
     KC_TAB  , KC_Q ,  KC_W   , KC_E  ,   KC_R     ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_QUOT,
     KC_LSFT , KC_A ,  KC_S   , KC_D  ,   KC_F     ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,KC_RSFT,
     KC_LCTL , KC_Z ,  KC_X   , KC_C  ,   KC_V     ,   KC_B , KC_LBRC, CW_TOGG,      KC_DEL , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_EQL,
                                QK_LEAD ,TT(_SYMBOLS), KC_SPC , QK_REP, KC_ESC,     TG(_GAME), KC_ENT ,KC_SPC, KC_BSPC, LSG(KC_S)
    ),

    [_GAME] = LAYOUT(
     _______  , _______ ,  _______   ,  _______  ,   _______ ,   _______ ,                                        _______ ,  _______ ,  _______ ,   _______ ,  _______ , _______ ,
     KC_T  ,KC_TAB,KC_Q,  KC_W,   KC_E ,   KC_R ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_LCTL , KC_LSFT ,  KC_A   ,  KC_S ,   KC_D ,   KC_F ,                                        _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
     KC_B ,KC_Z, KC_X   ,  KC_C  ,   KC_V ,   KC_G , QK_REP,SH_OS,     _______  , _______, _______,   _______ ,  _______ ,   _______ ,  _______ , _______,
                                 _______, _______, _______, KC_LALT , _______   ,     _______    , _______ ,_______, _______, _______
    ),

    [_SYMBOLS] = LAYOUT(
        LCTL(KC_Y) , C(S(KC_1))   ,  C(S(KC_2))    ,  C(S(KC_3))  ,   _______    ,   LALT(KC_F4) ,                                                 KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9  ,  KC_F10 , KC_HOME ,
        LCTL(KC_Z) , LCTL(KC_A)   ,  LCTL(KC_I)  ,     KC_UP     ,    LALT(KC_TAB)   ,   KC_F1 ,                                                 LSFT(KC_BSLS),   KC_KP_7,  KC_KP_8 ,   KC_KP_9 , LSG(KC_MINUS), KC_END,
        _______ , LCTL(KC_S)   ,  KC_LEFT    ,      KC_DOWN    ,   KC_RGHT    ,   KC_PAUSE ,                                                 KC_MINS,   KC_KP_4 ,  KC_KP_5 ,   KC_KP_6 , KC_BSLS , KC_TAB,
     _______    ,  _______  ,  LALT(KC_LSFT)    , LCTL(KC_C)       ,   LCTL(KC_V)    ,   LCTL(KC_F) , _______ , _______ ,   _______  , _______, LSFT(KC_MINS),   KC_KP_1 ,KC_KP_2, KC_KP_3 , KC_KP_0,_______,
                                            _______       ,   _______    ,   _______ , _______ , _______ ,   _______  , _______        ,_______, _______, LSG(KC_T)
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
#if defined (HALCYON_ENABLE)
const uint16_t left_halcyon_buttons[10][5] = {
    [_QWERTY] =     { MT(MOD_LALT, G(KC_TAB)), _______, _______, _______, _______ },
    [_GAME] =     { _______, _______, _______, _______, _______ },
    [_SYMBOLS] = { _______, _______, _______, _______, _______ }
};
const uint16_t right_halcyon_buttons[10][5] = {
    [_QWERTY] =     { KC_MPLY, _______, _______, _______, _______ },
    [_GAME] =     { _______, _______, _______, _______, _______ },
    [_SYMBOLS] = { _______, _______, _______, _______, _______ }
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
	{{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}}
};

#if defined(SWAP_HANDS_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 0, 1, 2 };
#endif

// RGB Lighting
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 83, 54, 231);
    }
    // Number keys
    for (uint8_t i = 31; i <= 35; i++) {
        rgb_matrix_set_color(i, 54, 113, 231);
    }
    for (uint8_t i = 68; i <= 72; i++) {
        rgb_matrix_set_color(i, 54, 113, 231);
    }
    // F5
    rgb_matrix_set_color(73, 218, 68, 100);
    // Ctrl, Shift, Tab
    rgb_matrix_set_color(61, 150, 31, 255);
    rgb_matrix_set_color(30, 150, 31, 255);
    rgb_matrix_set_color(24, 150, 31, 255);
    rgb_matrix_set_color(18, 150, 31, 255);
    // CW
    rgb_matrix_set_color(11, 150, 31, 255);
    // Leader
    rgb_matrix_set_color(10, 150, 31, 255);
    // Space
    rgb_matrix_set_color(8, 31, 229, 255);
    rgb_matrix_set_color(45, 31, 229, 255);
    // Layer
    rgb_matrix_set_color(9, 180, 207, 254);
    rgb_matrix_set_color(43, 180, 207, 254);
    // Repeat
    rgb_matrix_set_color(7, 0, 219, 86);
    // Enter
    rgb_matrix_set_color(44, 0, 219, 86);
    // Screenshot
    rgb_matrix_set_color(47, 0, 219, 86);
    // Esc, Del, Bksc
    rgb_matrix_set_color(6, 255, 0, 0);
    rgb_matrix_set_color(46, 255, 0, 0);
    rgb_matrix_set_color(48, 255, 0, 0);
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 2:
            // ALT-F4
            rgb_matrix_set_color(73, 255, 0, 0);
            // Undo Redo
            rgb_matrix_set_color(36, 255, 123, 122);
            rgb_matrix_set_color(30, 255, 123, 122);
            // WASD
            rgb_matrix_set_color(27, 15, 82, 186);
            rgb_matrix_set_color(20, 15, 82, 186);
            rgb_matrix_set_color(21, 15, 82, 186);
            rgb_matrix_set_color(22, 15, 82, 186);
            // Home End
            rgb_matrix_set_color(67, 15, 82, 186);
            rgb_matrix_set_color(73, 15, 82, 186);
            // Numpad
            rgb_matrix_set_color(63, 15, 82, 186);
            rgb_matrix_set_color(64, 15, 82, 186);
            rgb_matrix_set_color(65, 15, 82, 186);
            rgb_matrix_set_color(57, 15, 82, 186);
            rgb_matrix_set_color(58, 15, 82, 186);
            rgb_matrix_set_color(59, 15, 82, 186);
            rgb_matrix_set_color(51, 15, 82, 186);
            rgb_matrix_set_color(52, 15, 82, 186);
            rgb_matrix_set_color(53, 15, 82, 186);
            rgb_matrix_set_color(61, 15, 82, 186);
            rgb_matrix_set_color(54, 15, 82, 186);
            // Lang Keys
            rgb_matrix_set_color(33, 152, 236, 141);
            rgb_matrix_set_color(34, 152, 236, 141);
            rgb_matrix_set_color(35, 152, 236, 141);
            // Search Keys
            rgb_matrix_set_color(25, 241, 194, 136);
            rgb_matrix_set_color(19, 241, 194, 136);
            rgb_matrix_set_color(13, 241, 194, 136);
            // Shortcuts
            rgb_matrix_set_color(26, 255, 102, 183);
            rgb_matrix_set_color(28, 255, 102, 183);
            rgb_matrix_set_color(29, 255, 102, 183);
            rgb_matrix_set_color(23, 255, 102, 183);
            rgb_matrix_set_color(13, 255, 102, 183);
            rgb_matrix_set_color(14, 255, 102, 183);
            rgb_matrix_set_color(15, 255, 102, 183);
            rgb_matrix_set_color(16, 255, 102, 183);
            // Keycodes
            rgb_matrix_set_color(66, 54, 113, 231);
            rgb_matrix_set_color(62, 54, 113, 231);
            rgb_matrix_set_color(60, 54, 113, 231);
            rgb_matrix_set_color(56, 54, 113, 231);
            rgb_matrix_set_color(50, 54, 113, 231);
            //F Keys
            for (uint8_t i = 68; i <= 72; i++) {
                rgb_matrix_set_color(i, 234, 144, 165);
            }
            break;
        case 1:
            // WASD
            rgb_matrix_set_color(27, 95, 31, 168);
            rgb_matrix_set_color(20, 95, 31, 168);
            rgb_matrix_set_color(21, 95, 31, 168);
            rgb_matrix_set_color(22, 95, 31, 168);
            // LALT
            rgb_matrix_set_color(7, 150, 31, 255);
            //Shift, Ctrl
            rgb_matrix_set_color(23, 150, 31, 255);
            rgb_matrix_set_color(24, 150, 31, 255);
            // Swap
            rgb_matrix_set_color(11, 180, 207, 254);
            // Repeat
            rgb_matrix_set_color(12, 0, 219, 86);
            //Priority Keys
            rgb_matrix_set_color(25, 255, 102, 183);
            rgb_matrix_set_color(26, 255, 102, 183);
            rgb_matrix_set_color(28, 255, 102, 183);
            rgb_matrix_set_color(29, 255, 102, 183);
            rgb_matrix_set_color(19, 255, 102, 183);
            rgb_matrix_set_color(17, 255, 102, 183);
            rgb_matrix_set_color(18, 255, 102, 183);
            //Sub Keys
            for (uint8_t i = 13; i <= 16; i++) {
                rgb_matrix_set_color(i, 243, 133, 255);
            }
            break;
        default:
            break;
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

//Leader keycodes
void leader_end_user(void) {

}