#pragma once

enum layers { Graphite, QWERTY, Cmds_Symb, Nav_Numbers, OS_FNum, Macros, Gaming };

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
