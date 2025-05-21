#pragma once

#define LT1_AREP LT(1, KC_0)

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
  if (keycode == LT1_AREP) {
    return false; // Ignore custom arep key so we don't repeat it
  }
  return true;
}

enum custom_keycodes {
  // Custom Alternate Repeat Keycodes
  ALT_TION = SAFE_RANGE,
  ALT_THE,
  ALT_EFORE,
  ALT_UST,
  ALT_ENT,
  ALT_MENT,
  ALT_UEN,
  ALT_ION,
  ALT_ON,
  ALT_ITION,
  ALT_ER,
  ALT_ATION,
};

#define ON_PRESS(x)            \
  if (record->event.pressed) { \
    x                          \
  }                            \
  return false;

#define SEND_STRING_ON_PRESS(x) ON_PRESS(SEND_STRING(x);)
