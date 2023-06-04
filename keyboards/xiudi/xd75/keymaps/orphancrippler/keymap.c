/* Copyright 2017 Wunder
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

enum layer_names {
    _QW,
    _HI,
    _LO,
    _ADJ
};

enum custom_keycodes {
    KC_QW,
    KC_HI,
    KC_LO,
    KC_ADJ
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | -      | `      | =      | 6      | 7      | 8      | 9      | 0      | BACKSP |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | [      | \      | ]      | Y      | U      | I      | O      | P      | '      |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | HOME   | DEL    | PG UP  | H      | J      | K      | L      | ;      | ENTER  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | END    | UP     | PG DN  | N      | M      | ,      | .      | /      | RSHIFT |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | LGUI   | LALT   | FN     | SPACE  | SPACE  | LEFT   | DOWN   | RIGHT  | SPACE  | SPACE  | FN     | RALT   | RGUI   | RCTRL  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_KP_7, KC_KP_8, KC_KP_9,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_KP_4, KC_KP_5, KC_KP_6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_KP_1, KC_KP_2, KC_KP_3,
        KC_LGUI, KC_APP,  KC_LALT, KC_LCTL, KC_LO,   KC_SPC,   KC_SPC,  KC_HI,   KC_RCTL, KC_RALT, KC_APP,  KC_RGUI, KC_KP_0, KC_PDOT, KC_ENT
    ),

    [_LO] = LAYOUT_ortho_5x15( /* Lower */
        KC_ESC,        KC_1,      KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,          KC_8,          KC_9,          KC_0,         KC_MINS, KC_EQL,  KC_GRV,  KC_BSPC,
        LSFT(KC_GRV), LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7),    LSFT(KC_8),    LSFT(KC_9),    LSFT(KC_0),   XXXXXXX, _______, _______, _______,
        KC_F1,        KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      XXXXXXX,    LSFT(KC_MINS), LSFT(KC_EQL),  LSFT(KC_COMM), LSFT(KC_DOT), XXXXXXX, _______, _______, _______,
        KC_F7,        KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     XXXXXXX,    LSFT(KC_3),    LSFT(KC_BSLS), KC_HOME,       KC_END,       XXXXXXX, _______, _______, _______,
        _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,       _______,       _______,      _______, _______, _______, _______
    ),

    [_HI] = LAYOUT_ortho_5x15( /* Raise */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,     KC_7,       KC_8,    KC_9,          KC_0,         KC_MINS, KC_EQL,  KC_GRV,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,     KC_6,     KC_7,       KC_8,    KC_9,          KC_0,         KC_BSLS, _______, _______, _______,
        KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, XXXXXXX,  XXXXXXX,  KC_MINS,    KC_EQL,  KC_LBRC,       KC_RBRC,      XXXXXXX, _______, _______, _______,
        XXXXXXX, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, XXXXXXX,  XXXXXXX, LSFT(KC_3), KC_BSLS, LSFT(KC_LBRC), LSFT(KC_RBRC), XXXXXXX, _______, _______, _______,
        _______, _______, _______, _______, _______,  _______,   _______, _______,    _______, _______,       _______,      _______, _______, _______, _______
    ),

    [_ADJ] = LAYOUT_ortho_5x15( /* Adjust */
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_NUM,
        XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, LALT(KC_F4), LCTL(LALT(KC_T)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC,     KC_MYCM,          XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______, _______, _______,     _______,          _______, _______, _______, _______, _______, _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QW:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QW);
            }
            return false;
        case KC_LO:
            if (record->event.pressed) {
                layer_on(_LO);
                update_tri_layer(_LO, _HI, _ADJ);
            } else {
                layer_off(_LO);
                update_tri_layer(_LO, _HI, _ADJ);
            }
            return false;
        case KC_HI:
            if (record->event.pressed) {
                layer_on(_HI);
                update_tri_layer(_LO, _HI, _ADJ);
            } else {
                layer_off(_HI);
                update_tri_layer(_LO, _HI, _ADJ);
            }
            return false;
        case KC_ADJ:
            if (record->event.pressed) {
                layer_on(_ADJ);
            } else {
                layer_off(_ADJ);
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
