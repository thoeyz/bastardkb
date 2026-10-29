/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
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

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#    include "timer.h"
#endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_POINTER,
    LAYER_ONEHANDED,
    LAYER_RNUM,
};

//combos
const uint16_t PROGMEM u[] = {RSFT_T(KC_J), LT(3,KC_K), COMBO_END};
const uint16_t PROGMEM y[] = {RALT_T(KC_N), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM y2[] = {LT(1,KC_SPC), RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM Rt[] = {RSFT_T(KC_F), KC_B, COMBO_END};
const uint16_t PROGMEM Rr[] = {RSFT_T(KC_F), KC_D, COMBO_END};
const uint16_t PROGMEM pageup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM pagedn[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM alt[] = {KC_Z,KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM ctrl[] = {KC_D, LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM ltabcycfwd[] = {KC_V, KC_C, COMBO_END};
const uint16_t PROGMEM ltabcycbk[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM f2[] = {KC_R, KC_E, COMBO_END};
const uint16_t PROGMEM rpgup[] = {KC_L, LT(3,KC_K), COMBO_END};
const uint16_t PROGMEM rpgdn[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM Ralt[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM f5[] = {MS_BTN1, MS_BTN2, COMBO_END};
const uint16_t PROGMEM esc[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM Resc[] = {RALT_T(KC_N), KC_M, COMBO_END};
const uint16_t PROGMEM layer4[] = {MO(2), LT(3,KC_A), COMBO_END};
const uint16_t PROGMEM Rlayer4[] = {LT(1,KC_SPC), LT(1,KC_SCLN), COMBO_END};
const uint16_t PROGMEM layer5[] = {MO(2), KC_Z, COMBO_END};
const uint16_t PROGMEM Rlayer5[] = {LT(1,KC_SPC), LT(3,KC_SLSH), COMBO_END};
const uint16_t PROGMEM Rlclick[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM Rrclick[] = {KC_DOT, LT(3,KC_SLSH), COMBO_END};



combo_t key_combos[] = {
    COMBO(u, KC_U),
    COMBO(y, KC_Y),
    COMBO(y2, KC_Y),
    COMBO(Rt, KC_T),
    COMBO(Rr, KC_R),
    COMBO(pageup, KC_PGUP),
    COMBO(pagedn, KC_PGDN), 
    COMBO(alt, OSM(MOD_LALT)),
    COMBO(ctrl, OSM(MOD_LCTL)),
    COMBO(ltabcycfwd, C(KC_PGDN)),
    COMBO(ltabcycbk, C(KC_PGUP)),
    COMBO(f2, KC_F2),
    COMBO(rpgup, KC_PGUP),
    COMBO(rpgdn, KC_PGDN),
    COMBO(Ralt, OSM(MOD_RALT)),
    COMBO(f5, KC_F5),
    COMBO(esc, KC_ESC),
    COMBO(Resc, KC_ESC),
    COMBO(layer4, OSL(4)),
    COMBO(Rlayer4, OSL(4)),
    COMBO(layer5, OSL(5)),
    COMBO(Rlayer5, OSL(5)),
    COMBO(Rlclick, MS_BTN1),
    COMBO(Rrclick, MS_BTN2),

};

/** \brief Automatically enable sniping-mode on the pointer layer. */
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(

        MS_BTN1,   MS_BTN2,     KC_F2,    KC_ENT,  KC_LPRN,        KC_RPRN,           XXXXXXX,        KC_7,            KC_ENT,        KC_9,    KC_0,          TG(1),
        CW_TOGG,   KC_Q,        KC_W,     KC_E,    KC_R,           KC_T,              KC_Y,           KC_U,            KC_I,          KC_O,    KC_P,          KC_BSLS,
        KC_Q,      LT(3,KC_A),  KC_S,     KC_D,    LSFT_T(KC_F),   KC_G,              KC_H,           RSFT_T(KC_J),    LT(3,KC_K),    KC_L,    LT(1,KC_SCLN), RALT(KC_P),
        KC_LGUI,   KC_Z,        KC_X,     KC_C,    KC_V,           KC_B,              RALT_T(KC_N),   KC_M,            KC_COMM,       KC_DOT,  LT(3,KC_SLSH), KC_ENT,

                                    LT(1,KC_TAB), LCTL_T(KC_BSPC), MO(2),             RCTL_T(KC_TAB), LT(1,KC_SPC),
                                                        MS_BTN1, MS_BTN2,             A(KC_LSFT)

  ),

  [LAYER_LOWER] = LAYOUT(

        KC_TAB,    KC_O,        KC_F2,    KC_I,    KC_LEFT,        KC_RGHT,           XXXXXXX,        XXXXXXX,         KC_ENT,        XXXXXXX, XXXXXXX,       KC_TRNS,
        KC_ENT,    KC_ESC,      KC_LSFT,  KC_W,    KC_C,           KC_R,              KC_MINS,        KC_7,            KC_8,          KC_9,    KC_RBRC,       KC_TAB,
        KC_LSFT,   KC_E,        KC_A,     KC_S,    KC_D,           KC_G,              KC_PPLS,        KC_4,            KC_5,          KC_6,    KC_PAST,       KC_BSPC,
        KC_LCTL,   KC_X,        KC_3,     KC_LSFT, KC_F,           KC_5,              KC_0,           KC_1,            KC_2,          KC_3,    KC_PSLS,       KC_DOT,

                                                  KC_Z, KC_SPC, KC_LALT,              KC_BSPC, KC_BSPC,
                                                        MS_BTN1, MS_BTN2,             KC_0

  ),

  [LAYER_RAISE] = LAYOUT(

        KC_TAB,    KC_O,        KC_F2,        KC_I,    KC_LEFT,        KC_RGHT,               XXXXXXX,        XXXXXXX,         KC_ENT,        XXXXXXX, XXXXXXX,       KC_TRNS,
        KC_ENT,    KC_ESC,      KC_LSFT,      KC_4,    KC_5,           KC_6,                  KC_7,           KC_8,            KC_9,          KC_0,    KC_MINS,       KC_TAB,
        KC_LSFT,   KC_RBRC,     KC_LEFT,      KC_UP,   KC_RGHT,        KC_HOME,               KC_PPLS,        KC_4,            KC_5,          KC_6,    KC_QUOT,       KC_BSPC,
        KC_LCTL,   KC_LCTL,     A(KC_LEFT),   KC_DOWN, A(KC_RGHT),     KC_END,                KC_0,           KC_1,            KC_2,          KC_3,    KC_PSLS,       KC_DOT,

                                                    XXXXXXX, XXXXXXX, XXXXXXX,                KC_EQL, KC_LBRC,
                                                             MS_BTN1, MS_BTN2,                XXXXXXX

  ),

  [LAYER_POINTER] = LAYOUT(

        KC_TAB,     KC_O,      KC_F2,     KC_I,       KC_LEFT,   KC_RGHT,               QK_BOOT,        XXXXXXX,         KC_ENT,        XXXXXXX,        KC_MPRV,       KC_MNXT,
        S_D_MOD,    DPI_MOD,   KC_WBAK,   MS_UP,      KC_WFWD,   KC_6,                  C(A(KC_DEL)),   C(KC_T),         XXXXXXX,       C(KC_W),        MS_BTN3,       KC_RGUI,
        KC_LSFT,    KC_RBRC,   MS_LEFT,   MS_DOWN,    MS_RGHT,   MS_WHLU,               C(KC_F),        MS_BTN1,         KC_HOME,       RSFT(MS_BTN2),  OSM(MOD_RCTL), OSM(MOD_RSFT),
        KC_LCTL,    KC_LCTL,   DRGSCRL,   SNIPING,    XXXXXXX,   MS_WHLD,               KC_F5,          KC_WFWD,         KC_END,        KC_WBAK,        KC_RSFT,       G(KC_D),

                                                MS_BTN2, MS_BTN1, MS_BTN3,              C(KC_PGUP), C(KC_PGDN),
                                                   C(KC_PGUP), C(KC_PGDN),              KC_HOME

  ),

 [LAYER_ONEHANDED] = LAYOUT(

        XXXXXXX,   XXXXXXX,     XXXXXXX,      KC_LGUI, XXXXXXX,        QK_BOOT,               QK_BOOT,        XXXXXXX,         KC_ENT,        XXXXXXX, XXXXXXX,       KC_TRNS,
        XXXXXXX,    KC_P,       KC_O,         KC_I,    KC_U,           KC_Y,                  KC_T,           KC_R,            KC_E,          KC_W,    KC_Q,          OSM(MOD_RALT),
        XXXXXXX,   XXXXXXX,     KC_L,         KC_K,    RSFT_T(KC_J),   KC_H,                  KC_G,           LSFT_T(KC_F),    KC_D,          KC_S,    KC_A,          KC_Q,
        XXXXXXX,   XXXXXXX,     XXXXXXX,      KC_P,    KC_M,           KC_N,                  KC_B,           KC_V,            KC_C,          KC_X,    KC_Z,          KC_BSPC,

                                                    KC_BSPC, KC_SPC, MS_BTN3,                 KC_BSPC, KC_SPC,
                                                            MS_BTN1, MS_BTN2,                 XXXXXXX
  ),

 [LAYER_RNUM] = LAYOUT(

        KC_TAB,    KC_O,        KC_F2,        KC_I,    KC_LEFT,        QK_BOOT,               QK_BOOT,        XXXXXXX,         KC_ENT,        XXXXXXX, XXXXXXX,       KC_TRNS,
        KC_ENT,    KC_ESC,      KC_LSFT,      KC_4,    KC_5,           KC_6,                  KC_7,           KC_8,            KC_9,          KC_0,    KC_MINS,       KC_TAB,
        KC_LSFT,   KC_RBRC,     KC_LEFT,      KC_UP,   KC_RGHT,        KC_HOME,               KC_MNXT,        KC_4,            KC_5,          KC_6,    KC_QUOT,       KC_BSPC,
        KC_LCTL,   KC_LCTL,     A(KC_LEFT),   KC_DOWN, A(KC_RGHT),     KC_END,                KC_MPRV,        KC_1,            KC_2,          KC_3,    KC_PSLS,       KC_DOT,

                                                    XXXXXXX, XXXXXXX, XXXXXXX,                KC_VOLU, KC_MUTE,
                                                             MS_BTN1, MS_BTN2,                KC_VOLD

  ),

};
// clang-format on


//AUTO SCROLL LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case LAYER_LOWER:
        charybdis_set_pointer_dragscroll_enabled(false);
        break;
    case LAYER_RAISE:
        charybdis_set_pointer_dragscroll_enabled(false);
        break;
    case LAYER_POINTER:
        charybdis_set_pointer_dragscroll_enabled(true);
        break;
    case LAYER_ONEHANDED:
        charybdis_set_pointer_dragscroll_enabled(false);
        break;
    default:
        charybdis_set_pointer_dragscroll_enabled(false);
        break;
    }
    return state;    
};
