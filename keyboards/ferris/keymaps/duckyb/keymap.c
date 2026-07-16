#include QMK_KEYBOARD_H

enum custom_keycodes {
    BOOT_L = SAFE_RANGE,
    BOOT_R,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BOOT_L:
        case BOOT_R:
            return false; // no action alone
    }
    return true;
}

enum combos {
    MO2_LSFT_BOOT,
    BOTH_CORNERS_BOOT,
};

const uint16_t PROGMEM mo2_lsft_combo[] = {MO(2), KC_LSFT, COMBO_END};
const uint16_t PROGMEM corners_boot_combo[] = {BOOT_L, BOOT_R, COMBO_END};

combo_t key_combos[] = {
    [MO2_LSFT_BOOT] = COMBO(mo2_lsft_combo, TO(5)),
    [BOTH_CORNERS_BOOT] = COMBO(corners_boot_combo, QK_BOOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(KC_Q, KC_W, KC_E, KC_R, KC_T,                      KC_Y, KC_U, KC_I, KC_O, KC_P,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                  KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K, KC_L, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                  KC_Z, KC_X, KC_C, KC_V, KC_B,                 KC_N, KC_M, KC_COMM, KC_DOT, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                MO(2), KC_LSFT,                 KC_SPC, OSL(1)
    ),

    [1] = LAYOUT_split_3x5_2(KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6, KC_7, KC_8, KC_9, KC_0, 
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                     KC_LT, KC_PERC, KC_LPRN, KC_LCBR, KC_LBRC,                 KC_EQL, KC_QUES, KC_QUOT, KC_PLUS, KC_ASTR,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                       KC_GT, KC_DLR, KC_RPRN, KC_RCBR, KC_RBRC,                KC_AT, KC_EXLM, KC_DQUO, KC_MINS, KC_SLSH,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                  MO(3), MO(4),                 KC_NO, KC_NO
    ),

    [2] = LAYOUT_split_3x5_2(KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_PGUP, KC_HOME, KC_UP, KC_END, KC_CAPS,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                   KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
        LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), KC_TAB, LCTL(KC_V),                 LCTL(KC_BSPC), KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                KC_NO, KC_TRNS,                 KC_ENT, MO(3)
    ),

    [3] = LAYOUT_split_3x5_2(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, 
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                    KC_LCTL, KC_LGUI, KC_LSFT, KC_LCTL, KC_RALT,                KC_F11, KC_F12, KC_PSCR, KC_TRNS, KC_TRNS,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                   KC_NO, KC_NO,                KC_NO, KC_NO
    ),

    [4] = LAYOUT_split_3x5_2(KC_CIRC, KC_UNDS, KC_DLR, KC_NO, KC_HASH,         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                    KC_QUOT, KC_TILD, KC_BSLS, KC_PIPE, KC_AMPR,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                    KC_NO, KC_NO,              KC_NO, KC_NO
    ),

    [5] = LAYOUT_split_3x5_2(BOOT_L, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, BOOT_R,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
//--------------------------------------------------------------       ----------------------------------------------------------------------------------
                                                    KC_NO, KC_NO,              KC_NO, KC_NO
    )
};

void eeconfig_init_user(void) {
    eeconfig_init();
}
