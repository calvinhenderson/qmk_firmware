#pragma once
#include QMK_KEYBOARD_H

enum layers {
  _BASE = 0,
  _SYM,
  _NAV,
  _FUN,
};

#define xxxxxxx KC_NO

#define SE_BASE TO(_BASE)
#define SE_SYM  OSL(_SYM)
#define SE_FUN  OSL(_FUN)

#define SE_SPC  LT(_NAV, KC_SPACE)
#define OS_SHFT OSM(MOD_LSFT)

#define SE_I HYPR_T(KC_I)
#define SE_S LCTL_T(KC_S)
#define SE_R LOPT_T(KC_R)
#define SE_T LCMD_T(KC_T)
#define SE_N RCMD_T(KC_N)
#define SE_E ROPT_T(KC_E)
#define SE_A RCTL_T(KC_A)
#define SE_O HYPR_T(KC_O)

#define SE_GRV  HYPR_T(KC_GRV)
#define SE_LBRC LCTL_T(KC_LBRC)
#define SE_LCBR LOPT_T(KC_LCBR)
#define SE_EQL  LCMD_T(KC_EQL)
#define SE_MINS RCMD_T(KC_MINS)
#define SE_RCBR ROPT_T(KC_RCBR)
#define SE_RBRC RCTL_T(KC_RBRC)
#define SE_SCLN HYPR_T(KC_SCLN)

#define SE_LOCK G(C(KC_Q))

#define OS_LGUI OSM(MOD_MASK_CTRL)
#define OS_LOPT OSM(MOD_MASK_ALT)
#define OS_LCTL OSM(MOD_MASK_GUI)

#define CYC_APP G(KC_TAB)
#define CYC_WIN G(KC_GRAVE)
#define WWW_NXT G(KC_RBRC)
#define WWW_PRV G(KC_LBRC)
#define TAB_NXT C(KC_TAB)
#define TAB_PRV S(TAB_NXT)
// vim: ts=2 sw=2 et
