#pragma once

/* Usage:
 *   1 Include this file in `keymap.c`
 *   2 Create an `autoshift.def` file in your keymaps folder.
 *   3 Add your autoshift configuration:
 *     - AS_DEF(key)
 *     - AS_KEY(key, unshifted, shifted)
 *     - AS_STR(key, unshifted, SEND_STRING macro)
 *
 * Examples:
 *   To define a key as autoshifted without overriding behaviour:
 *     AS_DEF(SE_E)
 *
 *   To override the shifted variant with another key:
 *     AS_KEY(SE_COMM, KC_SCLN, KC_COMM)
 *
 *   To override the shifted variant with a string macro:
 *     AS_STR(SE_LCBR, KC_LCBR, "{}" SS_TAP(X_LEFT))
 */

#ifndef AUTOSHIFT_DEF
#define AUTOSHIFT_DEF "autoshift.def"
#endif

#define AS_CASE(KEY) \
  case KEY:          \
    return true;

#undef AS_DEF
#define AS_DEF(KEY) AS_CASE(KEY)
#undef AS_KEY
#define AS_KEY(KEY, UNSHIFTED, SHIFTED) AS_CASE(KEY)
#undef AS_STR
#define AS_STR(KEY, UNSHIFTED, ...) AS_CASE(KEY)

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    #include AUTOSHIFT_DEF
  }
  return false;
}

/* Autoshift key presses */

#define P_KEY(KEY, UNSHIFTED, SHIFTED)                 \
  case KEY:                                            \
    register_code16(is_shifted ? SHIFTED : UNSHIFTED); \
    break;

#define P_STR(KEY, UNSHIFTED, ...)    \
  case KEY:                           \
    if (is_shifted) {                 \
      send_string((const char*)__VA_ARGS__);     \
    } else {                          \
      register_code16(UNSHIFTED);     \
    }                                 \
    break;

#undef AS_DEF
#define AS_DEF(KEY)
#undef AS_KEY
#define AS_KEY(KEY, UNSHIFTED, SHIFTED) P_KEY(KEY, UNSHIFTED, SHIFTED)
#undef AS_STR
#define AS_STR(KEY, UNSHIFTED, ...) P_STR(KEY, UNSHIFTED, __VA_ARGS__)
void autoshift_press_user(uint16_t keycode, bool is_shifted, keyrecord_t *record) {
  switch (keycode) {
    #include AUTOSHIFT_DEF
    default:
      if (is_shifted) {
        add_weak_mods(MOD_BIT(KC_LSFT));
      }
      register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
      break;
  }
}

/* Autoshift key releases */
#define R_KEY(KEY, UNSHIFTED, SHIFTED)                   \
  case KEY:                                              \
    unregister_code16(is_shifted ? SHIFTED : UNSHIFTED); \
    break;

#define R_STR(KEY, UNSHIFTED)  \
  case KEY:                         \
    if (!is_shifted) {              \
      unregister_code16(UNSHIFTED); \
    }                               \
    break;

#undef AS_DEF
#define AS_DEF(KEY)
#undef AS_KEY
#define AS_KEY(KEY, UNSHIFTED, SHIFTED) R_KEY(KEY, UNSHIFTED, SHIFTED)
#undef AS_STR
#define AS_STR(KEY, UNSHIFTED, ...) R_STR(KEY, UNSHIFTED)
void autoshift_release_user(uint16_t keycode, bool is_shifted, keyrecord_t *record) {
  switch (keycode) {
    #include AUTOSHIFT_DEF
    default:
      unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
      break;
  }
}
