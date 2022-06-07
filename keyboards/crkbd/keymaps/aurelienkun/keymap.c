/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_french.h>
#include <keymap_bepo.h>
#include <aurelienkun.h>

#define SPC_LALT LALT_T(KC_SPC)       // Tap: space   Hold: alt
#define TAB_LSFT SFT_T(KC_TAB)        // Tap: tab     Hold: shift
#define ENT_NAV LT(_NAVI, KC_ENT)   // Tap: enter   Hold: layer navigation

enum custom_layers {
    _AZERTY,
    _NUMBERS,
    _NAVI,
};

#ifdef COMBO_ENABLE
enum combos { 
  R_T_LPRN,
  Y_U_RPRN,
  F_G_LCBR,
  H_J_RCBR,
  V_B_LBRC,
  N_COMM_RBRC,
  Y_N_PIPE,
  T_B_PIPE,
  B_N_MINS,
  W_EXLM_UNDS,
  E_U_EURO,
  E_T_AMPR,
  T_F_B_LABK,
  Y_J_N_RABK,
  U_S_DLR,
  T_L_TILD,
  A_T_AT,
  E_COMM_EACU,
  E_SCLN_EGRV,
  A_SCLN_AGRV,
  U_SCLN_UGRV,
  C_COMM_CCED,
  W_F_I_WIFI,
  P_A_S_PASS,
};

const uint16_t PROGMEM r_t_lprn[] = { FR_R, FR_T, COMBO_END};
const uint16_t PROGMEM y_u_rprn[] = { FR_Y, FR_U, COMBO_END};
const uint16_t PROGMEM f_g_lcbr[] = { FR_F, FR_G, COMBO_END};
const uint16_t PROGMEM h_j_rcbr[] = { FR_H, FR_J, COMBO_END};
const uint16_t PROGMEM v_b_lbrc[] = { FR_V, FR_B, COMBO_END};
const uint16_t PROGMEM n_comm_rbrc[] = { FR_N, FR_COMM, COMBO_END};
const uint16_t PROGMEM y_n_pipe[] = { FR_Y, FR_N, COMBO_END};
const uint16_t PROGMEM t_b_pipe[] = { FR_T, FR_B, COMBO_END};
const uint16_t PROGMEM b_n_mins[] = { FR_B, FR_N, COMBO_END};
const uint16_t PROGMEM w_exlm_unds[] = { FR_W, FR_EXLM, COMBO_END};
const uint16_t PROGMEM e_u_euro[] = { FR_E, FR_U, COMBO_END};
const uint16_t PROGMEM e_t_ampr[] = { FR_E, FR_T, COMBO_END};
const uint16_t PROGMEM t_f_b_labk[] = { FR_T, FR_F, FR_B, COMBO_END};
const uint16_t PROGMEM y_j_n_rabk[] = { FR_Y, FR_J, FR_N, COMBO_END};
const uint16_t PROGMEM u_s_dlr[] = { FR_U, FR_S, COMBO_END};
const uint16_t PROGMEM t_l_tild[] = { FR_E, FR_T, COMBO_END};
const uint16_t PROGMEM a_t_at[] = { FR_A, FR_T, COMBO_END};
const uint16_t PROGMEM e_comm_eacu[] = { FR_E, FR_COMM, COMBO_END};
const uint16_t PROGMEM e_scln_egrv[] = { FR_E, FR_SCLN, COMBO_END};
const uint16_t PROGMEM u_scln_ugrv[] = { FR_U, FR_SCLN, COMBO_END};
const uint16_t PROGMEM a_scln_agrv[] = { FR_A, FR_SCLN, COMBO_END};
const uint16_t PROGMEM c_comm_cced[] = { FR_C, FR_COMM, COMBO_END};
const uint16_t PROGMEM w_f_i_wifi[] = { FR_W, FR_F, FR_I, COMBO_END};
const uint16_t PROGMEM p_a_s_pass[] = { FR_P, FR_A, FR_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [R_T_LPRN]    = COMBO(r_t_lprn, FR_LPRN),    // (
    [Y_U_RPRN]    = COMBO(y_u_rprn, FR_RPRN),    // )
    [F_G_LCBR]    = COMBO(f_g_lcbr, FR_LCBR),    // {
    [H_J_RCBR]    = COMBO(h_j_rcbr, FR_RCBR),    // }
    [V_B_LBRC]    = COMBO(v_b_lbrc, FR_LBRC),    // [
    [N_COMM_RBRC] = COMBO(n_comm_rbrc, FR_RBRC), // ]
    [Y_N_PIPE]    = COMBO(y_n_pipe, FR_PIPE),    // |
    [T_B_PIPE]    = COMBO(t_b_pipe, FR_PIPE),    // |
    [B_N_MINS]    = COMBO(b_n_mins, FR_MINS),    // -
    [W_EXLM_UNDS] = COMBO(w_exlm_unds, FR_UNDS), // _
    [E_T_AMPR]    = COMBO(e_t_ampr, FR_AMPR),    // &
    [T_F_B_LABK]  = COMBO(t_f_b_labk, FR_LABK),  // <
    [Y_J_N_RABK]  = COMBO(y_j_n_rabk, FR_RABK),  // >
    [E_U_EURO]    = COMBO(e_u_euro, FR_EURO),    // €
    [U_S_DLR]     = COMBO(u_s_dlr, FR_DLR),      // $
    [T_L_TILD]    = COMBO(t_l_tild, FR_TILD),    // ~
    [A_T_AT]      = COMBO(a_t_at, FR_AT),        // @
    [E_COMM_EACU] = COMBO(e_comm_eacu, FR_EACU), // é
    [E_SCLN_EGRV] = COMBO(e_scln_egrv, FR_EGRV), // è
    [A_SCLN_AGRV] = COMBO(a_scln_agrv, FR_AGRV), // à
    [U_SCLN_UGRV] = COMBO(u_scln_ugrv, FR_UGRV), // ù
    [C_COMM_CCED] = COMBO(c_comm_cced, FR_CCED), // ç
    [W_F_I_WIFI]  = COMBO_ACTION(w_f_i_wifi),    // wifi
    [P_A_S_PASS]  = COMBO_ACTION(p_a_s_pass),    // pass
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case W_F_I_WIFI:
      if (pressed) {
        SEND_STRING(WIFI_PASS);
      }
      break;
    case P_A_S_PASS:
      if (pressed) {
        SEND_STRING(LOGIN_PASS);
      }
      break;
  }
}
#endif // COMBO_ENABLE

#ifdef TAP_DANCE_ENABLE
enum {
    TD_QT_DQT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_QT_DQT] = ACTION_TAP_DANCE_DOUBLE(FR_QUOT, FR_DQUO),
};
#endif // TAP_DANCE_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,                         FR_Y,    FR_U,    FR_I,    FR_O,   FR_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     TAB_LSFT,    FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,                         FR_H,    FR_J,    FR_K,    FR_L,   FR_M,  FR_CIRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    FR_W,    FR_X,    FR_C,    FR_V,    FR_B,                         FR_N, FR_COMM, FR_SCLN, FR_COLN, FR_EXLM,TD(TD_QT_DQT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),SPC_LALT,    ENT_NAV, TO(1), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),
  [_NUMBERS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      FR_SLSH,    FR_7,    FR_8,    FR_9, FR_MINS, FR_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      FR_ASTR,    FR_4,    FR_5,    FR_6,    FR_M, FR_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_F11,  KC_F12, KC_VOLD, KC_VOLU, KC_MUTE,                      FR_COMM,    FR_1,    FR_2,    FR_3,  FR_DOT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS,  FR_EQL,    FR_0
                                      //`--------------------------'  `--------------------------'

  ),
  [_NAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, XXXXXXX, XXXXXXX,  BL_INC, RGB_VAI, KC_VOLU,                      KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLEP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, XXXXXXX, XXXXXXX,  BL_DEC, RGB_VAD, KC_VOLD,                      KC_PGUP, KC_HOME,   KC_UP,  KC_END, XXXXXXX,  KC_PWR,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_PSCR, KC_HOME, BL_TOGG, RGB_TOG, KC_MUTE,                      KC_PGDN, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,KC_TRNS,     KC_TRNS, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
