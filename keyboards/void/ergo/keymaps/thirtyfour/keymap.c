#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"
#include "keycodes.h"

/* KEYMAPS */
enum custom_keycodes {
  SE_COMM = SAFE_RANGE,
  SE_DOT,
  SE_SLSH,
  SE_AT,
  SE_LPRN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Base layer
   *   Home Row Mods:
   *      I   S   R   T    N   E   A   O
   *    HYPR CTL OPT CMD  CMD OPT CTL HYPR
   *
   *   Base layer:
   *     Y   C   L   M   K        Z   F   U   ,   @
   *     I   S   R   T   G        P   N   E   A   O
   *     Q   V   W   D   J        B   H   /   .   X
   *                 _   Sft      L3  L1
   */
  [_BASE] = LAYOUT(
    KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,
    SE_I,    SE_S,    SE_R,    SE_T,    KC_G,
    KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,
                               SE_SPC,  OS_SHFT,

    KC_Z,    KC_F,    KC_U,    SE_COMM, SE_AT,
    KC_P,    SE_N,    SE_E,    SE_A,    SE_O,
    KC_B,    KC_H,    SE_SLSH, SE_DOT,  KC_X,
    SE_FUN,  SE_SYM
  ),

  /* Symbols */
  [_SYM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    SE_GRV,  SE_LBRC, SE_LCBR, SE_EQL,  KC_DQUO,
    KC_TILD, KC_BSLS, KC_PIPE, KC_PLUS, KC_QUOT,
                               _______, _______,

    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_MINS, SE_UNDS, SE_RCBR, SE_RBRC, SE_SCLN,
    KC_LABK, KC_RABK, SE_LPRN, KC_RPRN, KC_SLSH,
    _______, _______
  ),

  /* Navigation */
  [_NAV] = LAYOUT(
    SE_LOCK, KC_WH_L, KC_MS_U, KC_WH_R, xxxxxxx,
    KC_ESC,  KC_MS_L, KC_MS_D, KC_MS_R, xxxxxxx,
    G(KC_Q), KC_TILD, KC_WH_U, KC_WH_D, xxxxxxx,
                               _______, _______,

    WWW_PRV, TAB_PRV, TAB_NXT, WWW_NXT, KC_DEL,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx,
    xxxxxxx, KC_BTN1, KC_BTN2, xxxxxxx, SE_BASE,
    _______, _______
  ),

  [_FUN] = LAYOUT(
    xxxxxxx, KC_MPLY, KC_MPRV, KC_MNXT, DM_REC1,
    xxxxxxx, KC_MUTE, KC_VOLD, KC_VOLU, DM_PLY1,
    xxxxxxx, xxxxxxx, KC_BRID, KC_BRIU, DM_RSTP,
                               _______, _______,

    DM_REC2, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    DM_PLY2, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    DM_RSTP, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SE_RCBR:
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
    /* Auto-shift homerow modifiers */
    case SE_I:
    case SE_S:
    case SE_R:
    case SE_T:
    case SE_N:
    case SE_E:
    case SE_A:
    case SE_O:
    /* Override shifted variants */
    case SE_COMM:
    case SE_DOT:
    case SE_SLSH:
    case SE_AT:
    case SE_LPRN:
    case SE_LCBR:
    case SE_LBRC:
    case KC_PIPE:
    case KC_BSLS:
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
    case SE_AT:
      register_code16(shifted ? KC_DQUO : KC_AT);
      break;
    case SE_LPRN:
      if (shifted) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      } else {
        register_code16(KC_LPRN);
      }
      break;
    case KC_PIPE:
      if (shifted) {
        SEND_STRING("|>");
      } else {
        register_code16(KC_PIPE);
      }
      break;
    case KC_BSLS:
      if (shifted) {
        SEND_STRING("\\\\");
      } else {
        register_code16(KC_BSLS);
      }
      break;
    case SE_LBRC:
      if (shifted) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      } else {
        register_code(KC_LBRC);
      }
      break;
    case SE_LCBR:
      if (shifted) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
      } else {
        register_code16(KC_LCBR);
      }
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
    case SE_AT:
      unregister_code16(shifted ? KC_DQUO : KC_AT);
      break;
    case SE_LPRN:
    case SE_LBRC:
    case SE_LCBR:
    case KC_PIPE:
    case KC_BSLS:
      // Do nothing if a macro was executed.
      if (!shifted) {
        // Otherwise release the key
        unregister_code16(keycode);
      }
      break;
    default:
      unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
  }
}

// vim: ts=2 sw=2 et eventignore=BufWritePre
