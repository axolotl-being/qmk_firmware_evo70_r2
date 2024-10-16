#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT_numpad_6x4(
        KC_ESC,  KC_TAB,  KC_PEQL, MO(1),
        KC_LNUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,
            KC_P0,        KC_PDOT, KC_PENT
    ),

    /* RGB */
    [1] = LAYOUT_numpad_6x4(
        RGB_SAI, RGB_VAI, RGB_HUI, _______,
        RGB_SAD, RGB_VAD, RGB_HUD, _______,
        RGB_M_X, RGB_M_G, RGB_MOD,
        RGB_M_SW,RGB_M_SN,RGB_M_K, RGB_RMOD,
        RGB_M_P, RGB_M_B, RGB_M_R,
            XXXXXXX,      XXXXXXX, RGB_TOG
    )
};

void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if (eeconfig_read_default_layer() > 0) {
        set_single_persistent_default_layer(0);
    }
}
