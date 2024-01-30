#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"
#include "keycodes.h"

/* KEYMAPS */
enum custom_keycodes {
  SE_COMM = SAFE_RANGE,
  SE_DOT,
  SE_SLSH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *   Y   C   L   M   K        Z   F   U   ,   <-
   *   I   S   R   T   G        P   N   E   A   O
   *   Q   V   W   D   J        B   H   /   .   X
   *               _   Sft      L2  L1
   */
  [_BASE] = LAYOUT(
    KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,
    KC_I,    SE_S,    SE_R,    SE_T,    KC_G,
    KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,
                               SE_SPC,  OS_SHFT,

    KC_Z,    KC_F,    KC_U,    SE_COMM, KC_BSPC,
    KC_P,    SE_N,    SE_E,    SE_A,    KC_O,
    KC_B,    KC_H,    SE_SLSH, SE_DOT,  KC_X,
    SE_NUM,  SE_SYM
  ),

  /* Symbols */
  [_SYM] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_UNDS, SE_LCBR, SE_MINS, SE_PIPE, KC_DQUO,
    KC_GRV,  KC_EQL,  KC_PLUS, KC_QUES, KC_QUOT,
                               SE_BASE, OS_SHFT,

    KC_CIRC, KC_AMPR, KC_ASTR, KC_SCLN, KC_BSPC,
    KC_BSLS, SE_RABK, SE_LABK, SE_RCBR, KC_TILD,
    KC_RBRC, KC_RPRN, KC_LPRN, KC_LBRC, SE_FUN,
    _______, _______
  ),

  /* Navigation */
  [_NAV] = LAYOUT(
    SE_LOCK, KC_WH_L, KC_MS_U, KC_WH_R, xxxxxxx,
    KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, xxxxxxx,
    G(KC_Q), KC_TILD, KC_WH_U, KC_WH_D, KC_BTN2,
                               SE_BASE, KC_LCMD,

    WWW_PRV, TAB_PRV, TAB_NXT, WWW_NXT, KC_DEL,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx,
    KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, SE_FUN,
    KC_ROPT, _______
  ),

  /* Numbers */
  [_NUM] = LAYOUT(
    xxxxxxx, KC_MPLY, KC_MPRV, KC_MNXT, KC_UNDS,
    xxxxxxx, KC_MUTE, KC_VOLD, KC_VOLU, KC_COMM,
    KC_GRV,  xxxxxxx, KC_BRID, KC_BRIU, KC_DOT,
                               SE_BASE, _______,

    KC_MINS, KC_7,    KC_8,    KC_9,    KC_ASTR,
    KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PLUS,
    KC_0,    KC_1,    KC_2,    KC_3,    SE_FUN,
    _______, _______
  ),

  [_FUN] = LAYOUT(
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, DM_REC1,
    xxxxxxx, OS_LCTL, OS_LOPT, OS_LGUI, DM_PLY1,
    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, DM_RSTP,
                               SE_BASE, KC_LCMD,

    xxxxxxx, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    xxxxxxx, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    xxxxxxx, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SE_RCBR:
    case SE_LCBR:
    case SE_LABK:
    case SE_RABK:
    case SE_PIPE:
      if (record->tap.count) {
        add_weak_mods(MOD_MASK_SHIFT);
      }
      break;
  }
  return true;
}

/* Auto-shift overrides */

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SE_S:
    case SE_R:
    case SE_T:
    case SE_N:
    case SE_E:
    case SE_A:
    case SE_COMM:
    case SE_DOT:
    case SE_SLSH:
      return true;
    default:
      return false;
  }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch (keycode) {
    case SE_COMM:
      register_code16(shifted ? KC_SCLN : KC_COMM);
      break;
    case SE_DOT:
      register_code16(shifted ? KC_UNDS : KC_DOT);
      break;
    case SE_SLSH:
      register_code16(shifted ? KC_COLN : KC_SLSH);
      break;
    default:
      if (shifted) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
  switch (keycode) {
    case SE_COMM:
      unregister_code16(shifted ? KC_SCLN : KC_COMM);
      break;
    case SE_DOT:
      unregister_code16(shifted ? KC_UNDS : KC_DOT);
      break;
    case SE_SLSH:
      unregister_code16(shifted ? KC_COLN : KC_SLSH);
      break;
    default:
      unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

// vim: ts=2 sw=2 et eventignore=BufWritePre
