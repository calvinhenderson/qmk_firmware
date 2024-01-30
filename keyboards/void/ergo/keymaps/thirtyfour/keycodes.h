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
#define SE_SYM OSL(_SYM)
#define SE_NUM OSL(_NUM)
#define SE_NAV TG(_NAV)
#define SE_FUN OSL(_FUN)

#define SE_SPC LT(_NAV, KC_SPACE)
#define OS_SHFT OSM(MOD_LSFT)
#define SE_S LCTL_T(KC_S)
#define SE_R LOPT_T(KC_R)
#define SE_T LCMD_T(KC_T)
#define SE_N RCMD_T(KC_N)
#define SE_E ROPT_T(KC_E)
#define SE_A RCTL_T(KC_A)

#define SE_MINS LOPT_T(KC_MINS)
#define SE_PIPE LCMD_T(KC_PIPE)
#define SE_LABK RCMD_T(KC_LABK)
#define SE_RABK ROPT_T(KC_RABK)
#define SE_LCBR LCTL_T(KC_LCBR)
#define SE_RCBR RCTL_T(KC_RCBR)

#define OS_LGUI OSM(MOD_MASK_CTRL)
#define OS_LOPT OSM(MOD_MASK_ALT)
#define OS_LCTL OSM(MOD_MASK_GUI)

#define WWW_NXT G(KC_RBRC)
#define WWW_PRV G(KC_LBRC)
#define TAB_NXT C(KC_TAB)
#define TAB_PRV S(TAB_NXT)
// vim: ts=2 sw=2 et
