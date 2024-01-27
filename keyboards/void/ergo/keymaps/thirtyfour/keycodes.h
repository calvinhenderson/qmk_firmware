#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _SYM,
  _NAV,
  _NUM,
  _FUN,
};

#define xxxxxxx KC_NO

#define SE_BASE TO(_BASE)
#define SE_SYM  TG(_SYM)
#define SE_NAV  TG(_NAV)
#define SE_NUM  TG(_NUM)
#define SE_FUN  TG(_FUN)

#define SE_SPC MT(MOD_MEH,KC_SPACE)
#define OS_SHFT OSM(MOD_LSFT)
#define SE_R LOPT_T(KC_R)
#define SE_T LCMD_T(KC_T)
#define SE_N RCMD_T(KC_N)
#define SE_E ROPT_T(KC_E)

#define SE_MINS LOPT_T(KC_MINS)
#define SE_PIPE LCMD_T(KC_PIPE)
#define SE_LABK RCMD_T(KC_LABK)
#define SE_RABK ROPT_T(KC_RABK)

#define OS_LGUI OSM(MOD_MASK_CTRL)
#define OS_LOPT OSM(MOD_MASK_ALT)
#define OS_LCTL OSM(MOD_MASK_GUI)

#define NXT_TAB C(KC_TAB)
#define PRV_TAB S(NXT_TAB)
// vim: ts=2 sw=2 et
