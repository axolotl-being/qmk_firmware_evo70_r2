#include QMK_KEYBOARD_H

enum keymap_layout {
    VANILLA = 0,  // matches MF68 layout
    FUNC,         // 0x08
    SETTINGS,     // 0x10
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap VANILLA: (Base Layer) Default Layer
     * ,-----------------------------------------------------------------------------.
     * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12|  |Prnt|ScLk|Paus|
     * |-----------------------------------------------------------|  |--------------|
     * | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backsp |  | Ins|Home|PgUp|
     * |-----------------------------------------------------------|  |--------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|  | Del| End|PgDn|
     * |-----------------------------------------------------------|  `--------------'
     * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
     * |-----------------------------------------------------------|        ,----.
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |        | Up |
     * |-----------------------------------------------------------|   ,-------------.
     * |Ctrl|Gui |Alt |      Space            |ALT |GUI |Func|CTRL |   |Lft| Dn |Rig |
     * `-----------------------------------------------------------'   `-------------'
     */
    [VANILLA] = LAYOUT_tkl_ansi(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   LGUI(KC_D), KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,      KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                    KC_RSFT,               KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                KC_RALT, KC_RGUI, MO(FUNC), KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Keymap FUNCTION: Function Layer
     * ,-------------------------------------------------------------.  ,--------------.
     * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12  |  |Prnt|ScLk|Paus|
     * |-------------------------------------------------------------|  |--------------|
     * | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Delete   |  |    |    |    |
     * |-------------------------------------------------------------|  |--------------|
     * |Tab  |   |PgU|   |   |   |   |   | Up|   |   |   |   |       |  |    |    |    |
     * |-------------------------------------------------------------|  `--------------'
     * |Control|Hme|PgD|End|   |   |   |Lft|Dwn|Rgt|   |   |         |
     * |-------------------------------------------------------------|       ,----.
     * |Shift   |   |Del|   |   |   |   |Mute|V- |V+ |  |TG(SETTINGS)|       | Up |
     * |-------------------------------------------------------------'   ,-------------.
     * |Func|Win |Alt |        PgD           |Alt |Ctrl |Func |          |Lft| Dn |Rig |
     * `------------------------------------------------------'          `-------------'
     */
    [FUNC] = LAYOUT_tkl_ansi(
        KC_ESC,           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_PSCR, KC_SCRL, KC_PAUS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,            _______, _______, _______,
        XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           _______, _______, _______,
        _______, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,          XXXXXXX,
        _______, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,                   TG(SETTINGS),               _______,
        _______, _______, _______,                            KC_PGDN,                            _______, _______, _______, _______,           _______, _______, _______
    ),

    /* Keymap SETTINGS: Settings Layer
     * ,-----------------------------------------------------------.     ,-------------.
     * |Esc  |f1| f2| f3| f4|  | f5| f6| f7| f8|   | f9|f10|f11|f12  |  |Prnt|ScLk|Paus|
     * |-------------------------------------------------------------|  |--------------|
     * |FN0 |   |   |   |   |   |   |   |   |  |   |BL-|BL+|BL Togl|    |RGB Tog |Val+|
     * |-----------------------------------------------------------|    |-------------|
     * |MuMode|   |   |   |   |   |   |   |   |   |   |   |  |LEDTst|    |RGB Mode|Val-|
     * |-----------------------------------------------------------|    `-------------'
     * |AudTgl |Hz+|MS+|   |   |   |   |   |   |   |   |   |  RST  |
     * |-----------------------------------------------------------|      ,----.
     * |ClickTgl|Hz-|MS-|   |   |   |   |   |   |   |   |Layer Clr |      |Hue+|
     * |--------------------------------------------------------------------------.
     * |    |    |    |                       |    |    |    |     | |Sat-|Hue-|Sat+|
     * `----------------------------------------------------------------------------'
     */
    [SETTINGS] = LAYOUT_tkl_ansi(
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DOWN,      XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_DOWN, BL_UP,   BL_TOGG,      RGB_TOG, RGB_VAI, XXXXXXX,
        MU_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      RGB_MOD, RGB_VAD, XXXXXXX,
        AU_TOGG, KC_F1,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MU_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,               RGB_HUI,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, _______,      RGB_SAD, RGB_HUD, RGB_SAI
    )
};

void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if (eeconfig_read_default_layer() > 0) {
        set_single_persistent_default_layer(0);
    }
}
