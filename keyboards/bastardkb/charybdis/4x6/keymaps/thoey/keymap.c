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

        MS_BTN1,   MS_BTN2,  KC_F2,    KC_ENT,  KC_LPRN, KC_RPRN,       XXXXXXX,    KC_7,    KC_ENT,    KC_9,    KC_0, TG(1),
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
       KC_LCTL,    PT_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LALT,

                                   KC_LGUI, KC_SPC,   LOWER,      RAISE,  KC_ENT,
                                           KC_LALT, KC_BSPC,     KC_DEL

  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RM_TOGG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      RM_PREV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______,
                                           XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX,
                                           _______, _______,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, PZOOM,   PVOLUME, PTABS,   DPI_MOD, S_D_MOD,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, PHIST,      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, CURSOR,  PBRIGHT,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  MS_BTN2, MS_BTN1, MS_BTN3,    XXXXXXX, XXXXXXX,
                                           XXXXXXX, MS_BTN2,    XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
