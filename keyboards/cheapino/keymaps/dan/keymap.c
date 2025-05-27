#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#  include "keymap.h"
#endif

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  switch (keycode) {
    // Left hand bigrams
    case KC_R: return KC_L;
    case KC_S: return KC_C;
    case KC_G: return KC_S;

    case KC_W: return KC_S;

    // Right hand bigrams
    case KC_H: return KC_Y;
    case KC_E: return KC_U;

    case KC_P: return KC_H;

    case KC_F: return KC_Y;
    case KC_O: return KC_A;
    case KC_U: return KC_E;

    // Special alt repeat keycodes
    case KC_A:
    case KC_C: return ALT_TION;
    case KC_B: return ALT_EFORE;
    case KC_J: return ALT_UST;
    case KC_M: return ALT_ENT;
    case KC_T: return ALT_MENT;
    case KC_Q: return ALT_UEN;
    case KC_N: return ALT_ION;
    case KC_I: return ALT_ON;
    case KC_D: return ALT_ITION;
    case KC_V: return ALT_ER;
    case KC_Z:
    case KC_L: return ALT_ATION;
    case KC_SPC: return ALT_THE;
  }

  return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TION: SEND_STRING_ON_PRESS("tion");
    case ALT_THE: SEND_STRING_ON_PRESS("the");
    case ALT_EFORE: SEND_STRING_ON_PRESS("efore");
    case ALT_UST: SEND_STRING_ON_PRESS("ust");
    case ALT_ENT: SEND_STRING_ON_PRESS("ent");
    case ALT_MENT: SEND_STRING_ON_PRESS("ment");
    case ALT_UEN: SEND_STRING_ON_PRESS("uen");
    case ALT_ION: SEND_STRING_ON_PRESS("ion");
    case ALT_ON: SEND_STRING_ON_PRESS("on");
    case ALT_ITION: SEND_STRING_ON_PRESS("ition");
    case ALT_ER: SEND_STRING_ON_PRESS("er");
    case ALT_ATION: SEND_STRING_ON_PRESS("ation");
  }

  return true;
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Graphite] = LAYOUT_split_3x5_3(
        KC_B, KC_L, KC_D, KC_W, KC_Z, KC_QUOT, KC_F, KC_O, KC_U, KC_J,
        KC_N, KC_R, KC_T, KC_S, KC_G, KC_Y, KC_H, KC_A, KC_E, KC_I,
        LCTL_T(KC_Q), LSFT_T(KC_X), KC_M, KC_C, KC_V, KC_K, KC_P, KC_COMM, RSFT_T(KC_DOT), RCTL_T(KC_SLSH),
        KC_LGUI, KC_SPC, MO(Cmds_Symb), MO(Nav_Numbers), KC_ENT, QK_AREP
    ),
    [QWERTY] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        KC_NO, KC_SPC, MO(Cmds_Symb), MO(Nav_Numbers), KC_ENT, TO(0)
    ),
    [Cmds_Symb] = LAYOUT_split_3x5_3(
        KC_ESC, KC_TAB, LCTL(KC_A), KC_NO, LCTL(KC_F), KC_GRV, KC_NO, KC_LBRC, KC_RBRC, KC_BSPC,
        TO(QWERTY), TO(OS_FNum), KC_NO, TO(Macros), TO(Gaming), KC_NO, KC_SCLN, KC_LPRN, KC_RPRN, KC_BSLS,
        LCTL_T(KC_NO), LSFT_T(KC_NO), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, RSFT_T(KC_EQL), RCTL_T(KC_NO),
        KC_LGUI, KC_LALT, KC_TRNS, KC_NO, KC_ENT, KC_RALT
    ),
    [Nav_Numbers] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_HOME, KC_END, KC_PGUP, KC_NO, KC_7, KC_8, KC_9, KC_BSPC,
        KC_NO, KC_LEFT, KC_UP, KC_RGHT, KC_PGDN, KC_NO, KC_4, KC_5, KC_6, KC_NO,
        LCTL_T(KC_NO), LSFT_T(KC_NO), KC_DOWN, KC_NO, KC_NO, KC_0, KC_1, KC_2, RSFT_T(KC_3), RCTL_T(KC_NO),
        KC_LGUI, KC_SPC, KC_NO, KC_TRNS, KC_ENT, KC_RALT
    ),
    [OS_FNum] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_VOLU, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_NO, KC_NO, RGB_VAI, KC_SLEP, KC_VOLD, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11,
        RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_MPLY, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,
        KC_LGUI, KC_SPC, TO(0), KC_NO, KC_ENT, KC_RALT
    ),
    [Macros] = LAYOUT_split_3x5_3(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO
    ),
    [Gaming] = LAYOUT_split_3x5_3(
        KC_B, KC_L, KC_D, KC_W, KC_Z, KC_QUOT, KC_F, KC_O, KC_U, KC_J,
        KC_N, KC_LEFT, KC_UP, KC_RGHT, KC_G, KC_Y, KC_H, KC_A, KC_E, KC_I,
        KC_F3, KC_X, KC_DOWN, KC_C, KC_V, KC_K, KC_P, KC_COMM, KC_DOT, KC_SLSH,
        KC_NO, KC_SPC, KC_NO, KC_ESC, KC_ENT, TO(0)
    )
};
// clang-format on

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
