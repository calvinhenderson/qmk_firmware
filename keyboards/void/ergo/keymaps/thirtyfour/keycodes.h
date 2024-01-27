#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _SYM,
  _NAV,
  _NUM,
  _FUN,
};

#define SE_BASE TO(_BASE)
#define SE_SYM  TG(_SYM)
#define SE_NAV  TG(_NAV)
#define SE_NUM  TG(_NUM)
#define SE_FUN  TG(_FUN)

#define SE_SPC MT(MOD_MEH,KC_SPACE)
#define SE_SHFT OSM(MOD_LSFT)
#define SE_R LOPT_T(KC_R)
#define SE_T LCMD_T(KC_T)
#define SE_N RCMD_T(KC_N)
#define SE_E ROPT_T(KC_E)

#define SE_LABK LOPT_T(KC_LABK)
#define SE_RABK LCMD_T(KC_RABK)
#define SE_RCBR RCMD_T(KC_RCBR)
#define SE_LCBR ROPT_T(KC_LCBR)

#define OS_LGUI OSM(MOD_MASK_CTRL)
#define OS_LOPT OSM(MOD_MASK_ALT)
#define OS_LCTL OSM(MOD_MASK_GUI)

#define NXT_TAB C(KC_TAB)
#define PRV_TAB S(NXT_TAB)
// vim: ts=2 sw=2 et
