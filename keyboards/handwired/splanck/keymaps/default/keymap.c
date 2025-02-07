#include QMK_KEYBOARD_H

enum splanck_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |PrntScr|------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-------------+------+------+------+------|       /     \      |------+------+------+------+------+------'
     *        | LGUI | Menu | LAlt | LCTR |LOWER |Enter /       \Space|RAISE | RCTR | RAlt | Menu | RGUI |
     *        `----------------------------------------'         '---------------------------------------'
     */

    [_QWERTY] = LAYOUT(
         KC_ESC,    KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,                          KC_Y,     KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
         KC_TAB,    KC_A,    KC_S,    KC_D,     KC_F,     KC_G,                          KC_H,     KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,    KC_X,    KC_C,     KC_V,     KC_B, KC_MUTE,    KC_PSCR,     KC_N,     KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
        XXXXXXX, KC_LGUI,  KC_APP, KC_LALT, KC_LCTRL, KC_LOWER,  KC_ENT,     KC_SPC, KC_RAISE, KC_LCTRL, KC_LALT,  KC_APP, KC_LGUI, XXXXXXX
    ),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | F1   |  F2  |  F3  |   F4 |  F5  |  F6  |-------.    ,-------|      |   _  |   +  |   <  |   >  |      |
     * |------+------+------+------+------+------|  MUTE |    |PrntScr|------+------+------+------+------+------|
     * | F7   |  F8  |  F9  |  F10 | F11  | F12  |-------|    |-------|      |   #  |   |  | HOME | END  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *        | LGUI | Menu | LAlt | LCTR |LOWER |Enter /       \Space|RAISE | RCTR | RAlt | Menu | RGUI |
     *        `----------------------------------------'         '---------------------------------------'
     */
    [_LOWER] = LAYOUT(
        LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                LSFT(KC_6),    LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),   LSFT(KC_0), XXXXXXX,
               KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                   XXXXXXX, LSFT(KC_MINS),  LSFT(KC_EQL), LSFT(KC_COMM), LSFT(KC_DOT), XXXXXXX,
               KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,     KC_F12, _______, _______, XXXXXXX,    LSFT(KC_3), LSFT(KC_BSLS),       KC_HOME,       KC_END, XXXXXXX,
             XXXXXXX,    _______,    _______,    _______,    _______,    _______, _______, _______, _______,       _______,       _______,       _______,      _______, XXXXXXX
    ),
    /* RAISE
     * ,----------------------------------------.                     ,-----------------------------------------.
     * |  `   |  1   |  2   |  3   |  4   |  5   |                    |  6   |  7   |  8   |  9   |  0   | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS | Left |  Up  | Down | Right|      |-------.    ,-------|      |  -   |  =   |  [   |  ]   |      |
     * |------+------+------+------+------+------|  MUTE |    |PrntScr|------+------+------+------+------+------|
     * |      | Undo | Cut  | Copy | Paste|      |-------|    |-------|      |  #   |  \   |  {   |  }   |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *        | LGUI | Menu | LAlt | LCTR |LOWER |Enter /       \Space|RAISE | RCTR | RAlt | Menu | RGUI |
     *        `----------------------------------------'         '---------------------------------------'
     */
    [_RAISE] = LAYOUT(
         KC_GRV,    KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                      KC_6,       KC_7,    KC_8,          KC_9,          KC_0,  KC_DEL,
        KC_CAPS, KC_LEFT,   KC_UP, KC_DOWN, KC_RIGHT, XXXXXXX,                   XXXXXXX,    KC_MINS,  KC_EQL,       KC_LBRC,       KC_RBRC, XXXXXXX,
        XXXXXXX, KC_UNDO,  KC_CUT, KC_COPY, KC_PASTE, XXXXXXX, _______, _______, XXXXXXX, LSFT(KC_3), KC_BSLS, LSFT(KC_LBRC), LSFT(KC_RBRC), XXXXXXX,
        XXXXXXX, _______, _______, _______,  _______, _______, _______, _______, _______,    _______, _______,       _______,       _______, XXXXXXX
    ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |AltF4 |CtrlAltT                   |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |WinMac|Qwerty|NumPad| Calc | File |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *        | LGUI | Menu | LAlt | LCTR |LOWER |Enter /       \Space|RAISE | RCTR | RAlt | Menu | RGUI |
     *        `----------------------------------------'         '---------------------------------------'
     */
    [_ADJUST] = LAYOUT(
        QK_BOOT,   XXXXXXX,   XXXXXXX, XXXXXXX, LALT(KC_F4), LCTL(LALT(KC_T)),                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        CG_TOGG, KC_QWERTY,   XXXXXXX, KC_CALC,     KC_MYCM,          XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX,   XXXXXXX,   XXXXXXX, XXXXXXX,     XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX,   _______,   _______, _______,     _______,          _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX
    )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0};

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("  ,-o"), false);
    oled_write_ln_P(PSTR(">o.O<"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwert"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
