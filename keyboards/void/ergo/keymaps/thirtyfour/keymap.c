#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"
#include "keycodes.h"

/* KEYMAPS */
enum custom_keycodes {
  NAV_Q = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *   Y   C   L   M   K        Z   F   U   ,   <-
   *   I   S   R   T   G        P   N   E   A   O
   *   Q   V   W   D   J        B   H   /   .   X
   *               _   +        ^   1
   */
  [_BASE] = LAYOUT(
    KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,
    KC_I,    KC_S,    SE_R,    SE_T,    KC_G,
    KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,
                               SE_SPC,  SE_SHFT,

    KC_Z,    KC_F,    KC_U,    KC_COMM, KC_BSPC,
    KC_P,    SE_N,    SE_E,    KC_A,    KC_O,
    KC_B,    KC_H,    KC_SLSH, KC_DOT,  KC_X,
    KC_LCTL, SE_SYM
  ),

  /* Symbols */
  [_SYM] = LAYOUT(
    KC_ESC,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_TAB,  KC_EQL,  SE_LABK, SE_RABK, KC_QUOT,
    KC_GRV,  _______, KC_COMM, KC_DOT,  KC_DQUO,
                               SE_BASE, SE_SHFT,

    KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_BSPC,
    KC_BSLS, SE_RCBR, SE_LCBR, KC_PIPE, KC_ENT,
    KC_RBRC, KC_RPRN, KC_LPRN, KC_LBRC, SE_NAV,
    KC_ROPT, SE_NUM
  ),

  /* Navigation */
  [_NAV] = LAYOUT(
    _______, KC_WH_L, KC_MS_U, KC_WH_R, NAV_Q,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_DEL,
    KC_TILD, KC_BTN2, KC_WH_U, KC_WH_D, _______,
                               SE_BASE, KC_LCMD,

    KC_WBAK, PRV_TAB, NXT_TAB, KC_WFWD, KC_BSPC,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
    KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, SE_FUN,
    KC_ROPT, SE_SYM
  ),

  /* Numbers */
  [_NUM] = LAYOUT(
    KC_ESC,  KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS,
    KC_TAB,  KC_MUTE, KC_VOLD, KC_VOLU, KC_PLUS,
    KC_GRV,  KC_AMPR, KC_BRID, KC_BRIU, KC_DOT,
                               SE_BASE, KC_LCMD,

    KC_MINS, KC_7,    KC_8,    KC_9,    KC_BSPC,
    KC_EQL,  KC_4,    KC_5,    KC_6,    KC_ENT,
    KC_0,    KC_1,    KC_2,    KC_3,    SE_FUN,
    KC_ROPT, SE_SYM
  ),

  [_FUN] = LAYOUT(
    _______, _______, _______, _______, DM_REC1,
    _______, OS_LCTL, OS_LOPT, OS_LGUI, DM_PLY1,
    _______, _______, _______, _______, DM_RSTP,
                               SE_BASE, KC_LCMD,

    _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,
    KC_ROPT, SE_NUM
  )
};

/* Key overrides */

const key_override_t nav_q_override = ko_make_basic(MOD_MASK_SHIFT, KC_Q, G(KC_Q));

const key_override_t **key_overrides = (const key_override_t *[]){
  &nav_q_override,
  NULL
};

// vim: ts=2 sw=2 et
