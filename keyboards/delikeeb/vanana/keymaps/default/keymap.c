/* Copyright 2020 noclew
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

#ifdef AUDIO_ENABLE
  float song_coin[][2]  = SONG(COIN_SOUND);
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BASE = SAFE_RANGE,
    LOWER,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * -------------------------------------------               -------------------------------------------
     * |   `  |   1  |   2  |   3  |   4  |   5  |               |   6  |   7  |   8  |   9  |   0  | Bksp |
     * -------------------------------------------               -------------------------------------------
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  |   \  |
     * -------------------------------------------   ---------  --------------------------------------------
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   | Bksp  |   |   H  |   J  |   K  |   L  |   ;  |Enter |
     * -------------------------------------------   ---------   -------------------------------------------
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   | Del   |   |   N  |   M  |   ,  |   .  |   /  |Sft(')|
     * -------------------------------------------   ---------   -------------------------------------------
     *        | GUI  |  Alt | Ctrl |Lower |Space |               |Space |Raise |Alt   | Left | Right|
     *        ------------------------------------               ------------------------------------
     */

    [_BASE] = LAYOUT(
    KC_GRV,     KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5  ,                 KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_BSPC,
    KC_TAB,     KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T  ,                 KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS,
    KC_ESC,     KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G  ,     KC_BSPC,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_ENT ,
    KC_LSFT,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B  ,     KC_DEL ,    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    RSFT_T(KC_QUOT),
                KC_LGUI,    KC_LALT,    KC_LCTL,    LOWER  ,    KC_SPC,                 KC_SPC ,    RAISE  ,    KC_RALT,    KC_LEFT,    KC_RGHT
    ),

    [_LOWER] = LAYOUT(
    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_F6  ,                KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,    KC_F12 ,
    KC_BSPC,    KC_SLSH,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PPLS,                KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_AT  ,    KC_EXLM,    _______,
    KC_EQL ,    KC_0   ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_MINS,    KC_LEFT,    KC_PIPE,    KC_LPRN,    KC_RPRN,    KC_HASH,    KC_DQUO,    _______,
    KC_ENT ,    KC_PAST,    KC_1   ,    KC_2   ,    KC_3   ,    KC_UNDS,    KC_RGHT,    KC_DLR ,    KC_LCBR,    KC_RCBR,    KC_AMPR,    KC_PERC,    _______,
                _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),

    [_RAISE] = LAYOUT(
    _______,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,                _______,    KC_HOME,    KC_BSPC,    KC_DEL ,    KC_END ,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_UP  ,    KC_LEFT,    KC_DOWN,    KC_UP  ,    KC_RGHT,    KC_QUOT,    _______,
    _______,    _______,    _______,    _______,    _______,    _______,    KC_DOWN,    _______,    KC_PGUP,    _______,    KC_PGDN,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    ),

    [_ADJUST] = LAYOUT(
    QK_BOOT,    _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______,    DB_TOGG,
    _______,    UG_TOGG,    UG_PREV,    UG_NEXT,    UG_VALD,    UG_VALU,                _______,    _______,    _______,    _______,    _______,    _______,
    KC_CAPS,    _______,    UG_HUED,    UG_HUEU,    UG_SATD,    UG_SATU,    KC_VOLU,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    AU_ON  ,    AU_OFF ,    _______,    _______,    _______,    KC_VOLD,    _______,    _______,    _______,    _______,    _______,    _______,
                _______,    _______,    _______,    _______,    _______,                _______,    _______,    _______,    _______,    _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;

        case QK_BOOT:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                #endif
            }
        return false;
    }
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    /* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        /* And with another if statement we can check the direction. */
        if (clockwise) {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_RIGHT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_LEFT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_UP);
            } else {
                tap_code(KC_VOLD);
            }
        }

    } else if (index == 1) { /* Second encoder. Only supported by Elite-C */
        if (clockwise) {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_RIGHT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_VOLU);
            }
        } else {
            if (IS_LAYER_ON(_LOWER)){
                tap_code(KC_LEFT);
            } else if (IS_LAYER_ON(_RAISE)){
                tap_code(KC_UP);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }
    return true;
}
