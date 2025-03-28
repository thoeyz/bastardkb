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
    LAYER_TEST,
};

//combos
const uint16_t PROGMEM pageup[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM pagedn[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM alt[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM alt1[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM alt2[] = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM lent[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM f2[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM rpgup[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM rpgdn[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM tabcyclefwd[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM tabcyclebk[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM ralt1[] = {KC_H, KC_K, COMBO_END};
const uint16_t PROGMEM ralt2[] = {KC_DOT, KC_M, COMBO_END};



combo_t key_combos[] = {
    COMBO(pageup, KC_PGUP),
    COMBO(pagedn, KC_PGDN), 
    COMBO(alt, OSM(MOD_LALT)),
    COMBO(alt1, A(KC_1)),
    COMBO(alt2, A(KC_2)),
    COMBO(lent, KC_ENT),
    COMBO(f2, KC_F2),
    COMBO(rpgup, KC_PGUP),
    COMBO(rpgdn, KC_PGDN),
    COMBO(tabcyclefwd, C(KC_PGDN)),
    COMBO(tabcyclebk, C(KC_PGUP)),
    COMBO(ralt1, A(KC_1)),
    COMBO(ralt2, A(KC_2)),

};

/** \brief Automatically enable sniping-mode on the pointer layer. */


//#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_POINTER

#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1500
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 6
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE


#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(

        KC_MS_BTN1, KC_MS_BTN2, KC_F2, KC_ENT, S(KC_9),      S(KC_0),               CW_TOGG,  KC_7,          KC_ENT,   RGB_TOG, TG(3),   TG(1),
        KC_TAB,     KC_LALT,    KC_W,  KC_E,   KC_R,         KC_T,                  KC_Y,     KC_U,          KC_I,     KC_O,    KC_P,    KC_BSLS,
        KC_Q,       LT(3,KC_A), KC_S,  KC_D,   LSFT_T(KC_F), KC_G,                  KC_H,     RSFT_T(KC_J),  KC_K,     KC_L,    KC_SCLN, LCTL_T(KC_P),
        DRGSCRL,    KC_Z,       KC_X,  KC_C,   KC_V,         KC_B,                  KC_N,     KC_M,          KC_COMM,  KC_DOT,  KC_SLSH, DRGSCRL,
  
                       LT(1,KC_ESC), LCTL_T(KC_BSPC), LT(2,KC_TAB),                 RAISE, LT(1,KC_SPC),
                                           C(KC_PGUP), C(KC_PGDN),                  A(KC_LSFT)
  ),

  [LAYER_LOWER] = LAYOUT(
       KC_TAB,  KC_O,   KC_F2,   KC_I,    KC_LEFT, KC_RGHT,          KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_TRNS, KC_TRNS,
       KC_LCTL, KC_ESC, KC_LSFT, KC_W,    KC_C,    KC_R,             KC_MINS,   KC_7,    KC_8,    KC_9,    KC_RBRC, KC_TAB,
       KC_LSFT, KC_E,   KC_A,    KC_S,    KC_D,    KC_G,             KC_PPLS,   KC_4,    KC_5,    KC_6,    KC_PAST, KC_ENT,
       XXXXXXX, KC_X,   KC_3,    KC_LSFT, KC_F,    KC_5,             KC_0,      KC_1,    KC_2,    KC_3,    KC_PSLS, KC_DOT,
  
                                  KC_Z, KC_SPC, KC_LALT,        XXXXXXX, _______,
                                           KC_B, XXXXXXX,       KC_P0
  
  ),

  [LAYER_RAISE] = LAYOUT(

       KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,          KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       KC_MNXT, XXXXXXX, XXXXXXX, KC_4, KC_5, KC_6,                  KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_VOLU,
       KC_MPLY, KC_RBRC,  KC_LEFT, KC_UP, KC_RGHT, KC_HOME,          XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_QUOT, KC_MUTE,
       QK_BOOT, KC_HOME, A(KC_LEFT), KC_DOWN,  A(KC_RGHT), KC_END,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,

                                  _______, _______, XXXXXXX,    KC_EQL, KC_LBRC,
                                           _______, _______,    XXXXXXX
  
  ),

  [LAYER_POINTER] = LAYOUT(
  
       KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_RGUI, XXXXXXX,
       DRGSCRL, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, _______, DRGSCRL,
  
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           DRGSCRL, SNIPING,    KC_BTN2
  //                            
  ),

 [LAYER_TEST] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT,  EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,  EE_CLR,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DPI_MOD, S_D_MOD,    S_D_MOD, DPI_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, _______, DRGSCRL, SNIPING, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, SNIPING, DRGSCRL, _______, XXXXXXX,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN1, KC_BTN3,    KC_BTN3, KC_BTN1,
                                           XXXXXXX, KC_BTN2,    KC_BTN2
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on

#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef RGB_MATRIX_ENABLE
// Forward-declare this helper function since it is defined in rgb_matrix.c.
void rgb_matrix_update_pwm_buffers(void);
#endif
