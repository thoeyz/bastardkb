/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
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

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

//combos
const uint16_t PROGMEM pageup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM pagedn[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM alt[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ctl[] = {LSFT_T(KC_F), KC_D, COMBO_END};
const uint16_t PROGMEM alt1[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM alt2[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM lent[] = {LT(2,KC_A), KC_W, COMBO_END};
const uint16_t PROGMEM f2[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM rctl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM Llclick[] = {LSFT_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM Lrclick[] = {LT(2,KC_BSPC), KC_G, COMBO_END};
const uint16_t PROGMEM Rlclick[] = {KC_H, RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM Rrclick[] = {KC_H, KC_SPC, COMBO_END};
const uint16_t PROGMEM rpgup[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM rpgdn[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM tabcyclefwd[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM tabcyclebk[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM ralt1[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM ralt2[] = {KC_DOT, KC_M, COMBO_END};
const uint16_t PROGMEM layer5[] = {LT(3,KC_Z), LT(2,KC_BSPC), COMBO_END};
const uint16_t PROGMEM layer4[] = {LT(2,KC_A), LT(2,KC_BSPC), COMBO_END};
const uint16_t PROGMEM divide[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM gamei[] = {KC_F, KC_Z, COMBO_END};
const uint16_t PROGMEM gamef2[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM gamectl[] = {KC_X, KC_SPC, COMBO_END};
const uint16_t PROGMEM gameq[] = {KC_X, KC_3, COMBO_END};
const uint16_t PROGMEM gameo[] = {KC_ESC, KC_LSFT, COMBO_END};
const uint16_t PROGMEM gameleft[] = {KC_B, KC_3, COMBO_END};
const uint16_t PROGMEM gameright[] = {KC_B, KC_F, COMBO_END};
const uint16_t PROGMEM gameesc[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM gamefive[] = {KC_SPC, KC_Z, COMBO_END};


combo_t key_combos[] = {
    COMBO(pageup, KC_PGUP),
    COMBO(pagedn, KC_PGDN), 
    COMBO(alt, OSM(MOD_LALT)),
    COMBO(ctl, OSM(MOD_LCTL)),
    COMBO(alt1, A(KC_1)),
    COMBO(alt2, A(KC_2)),
    COMBO(lent, KC_ENT),
    COMBO(f2, KC_F2),
    COMBO(rctl, KC_RCTL),
    COMBO(Llclick, KC_MS_BTN1),
    COMBO(Lrclick, KC_MS_BTN2),
    COMBO(Rlclick, KC_MS_BTN1),
    COMBO(Rrclick, KC_MS_BTN2),
    COMBO(rpgup, KC_PGUP),
    COMBO(rpgdn, KC_PGDN),
    COMBO(tabcyclefwd, C(KC_PGDN)),
    COMBO(tabcyclebk, C(KC_PGUP)),
    COMBO(ralt1, A(KC_1)),
    COMBO(ralt2, A(KC_2)),
    COMBO(layer5, OSL(5)),
    COMBO(layer4, OSL(4)),
    COMBO(divide, KC_PSLS),
    COMBO(gamei, KC_I),
    COMBO(gamef2, KC_F2),
    COMBO(gamectl, KC_LCTL),
    COMBO(gameq, KC_Q),
    COMBO(gameo, KC_O),
    COMBO(gameleft, KC_LEFT),
    COMBO(gameright, KC_RGHT),
    COMBO(gameesc, KC_ESC),
    COMBO(gamefive, KC_5),

};

// Automatically enable sniping-mode on the pointer layer.
// #define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#define ESC_MED LT(LAYER_MEDIA, KC_ESC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_3(
       KC_Q,          KC_W,    KC_E,    KC_R,           KC_T,                    KC_Y,    KC_U,         KC_I,     KC_O,    KC_P,
       LT(2,KC_A),    KC_S,    KC_D,    LSFT_T(KC_F),   KC_G,                    KC_H,    RSFT_T(KC_J), KC_K,     KC_L,    KC_SCLN,
       LT(3,KC_Z),    KC_X,    KC_C,    KC_V,           KC_B,                    KC_N,    KC_M,         KC_COMM,  KC_DOT,  LT(3,PT_SLSH),
                       TG(1),   LCTL_T(KC_TAB), LT(2,KC_BSPC),                   KC_SPC,  LT(1,KC_ENT), RGB_TOG
  ),


  [LAYER_FUNCTION] = LAYOUT_split_3x5_3(
    KC_ESC,         KC_LSFT,  KC_W,        KC_C,    KC_R,             KC_MINS,   KC_7,   KC_8,   KC_9,  KC_F12,
    KC_E,           KC_A,     KC_S,        KC_D,    KC_G,             KC_PPLS,   KC_4,   KC_5,   KC_6,  KC_PAST,
    KC_X,           KC_3,     KC_B,        KC_F,    KC_Z,             KC_0,      KC_1,   KC_2,   KC_3,  KC_PSLS,
                                  TG(1),  KC_LALT, KC_SPC,            TG(1), XXXXXXX, XXXXXXX
  ),

  [LAYER_NAVIGATION] = LAYOUT_split_3x5_3(
    A(KC_LSFT), CW_TOGG,    KC_4,    KC_5,       KC_6,               KC_7,    KC_8,       KC_9,    KC_0,       KC_MINS,
    KC_RBRC,    KC_LEFT,    KC_UP,   KC_RGHT,    KC_HOME,            XXXXXXX, KC_MS_BTN1, KC_DOWN, KC_MS_BTN2, KC_QUOT,
    KC_ESC,     A(KC_LEFT), KC_DOWN, A(KC_RGHT), KC_END,             XXXXXXX, KC_HOME,    KC_PGDN, KC_PGUP,    KC_END,
                        XXXXXXX, C(KC_PGUP), C(KC_PGDN),             KC_EQL,  KC_LBRC,    KC_DEL
  ),


  [LAYER_MEDIA] = LAYOUT_split_3x5_3(
    QK_BOOT,      XXXXXXX,    XXXXXXX,    S(C(G(KC_B))), G(S(KC_RGHT)),               XXXXXXX, RGB_RMOD,   RGB_TOG,    RGB_MOD,     QK_BOOT,
    XXXXXXX,      KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,    DRGSCRL,                     XXXXXXX, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_MNXT,
    C(A(KC_DEL)), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,   DRGSCRL,                     XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, TG(1),
                                 XXXXXXX, C(A(KC_DEL)), XXXXXXX,                      KC_MS_BTN1, KC_MS_BTN2, KC_MUTE
  ),

  [LAYER_POINTER] = LAYOUT_split_3x5_3(
    KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,             S_D_MOD, DPI_MOD, XXXXXXX,  EE_CLR, QK_BOOT,
    KC_LGUI, KC_L,    KC_K,    KC_J,    KC_H,             XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    _______, DRGSCRL, KC_P,    KC_M,    KC_N,             XXXXXXX, KC_BTN3, SNIPING, DRGSCRL, _______,
                      KC_BTN3, KC_BSPC, KC_SPC,           KC_BTN1, KC_BTN2, KC_BTN3
  ),

  [LAYER_NUMERAL] = LAYOUT_split_3x5_3(
    KC_PAST,    KC_7,    KC_8,    KC_9,   KC_MINS,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_PSLS,    KC_4,    KC_5,    KC_6,   KC_PPLS,                XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
     KC_DOT,    KC_1,    KC_2,    KC_3,   KC_0,                   XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                          KC_DOT, KC_DOT, KC_0,                   XXXXXXX, _______, XXXXXXX
  ),


  [LAYER_SYMBOLS] = LAYOUT_split_3x5_3(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
                      KC_LPRN,  KC_GRV, KC_UNDS, _______, XXXXXXX, XXXXXXX
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE]       = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D),  ENCODER_CCW_CW(S(KC_MS_WH_DOWN), S(KC_MS_WH_UP))},
    [LAYER_FUNCTION]   = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT),    ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [LAYER_NAVIGATION] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_MEDIA] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RGB_HUD, RGB_HUI),  ENCODER_CCW_CW(RGB_SAD, RGB_SAI)},
    [LAYER_NUMERAL]    = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI),  ENCODER_CCW_CW(RGB_SPD, RGB_SPI)},
    [LAYER_SYMBOLS]    = {ENCODER_CCW_CW(RGB_RMOD, RGB_MOD), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE
