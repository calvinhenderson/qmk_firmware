#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define LCTLESC LCTL_T(KC_ESCAPE)
#define LOSPACE LT(_LOWER, KC_SPACE)
#define SFTENTR RSFT_T(KC_ENTER)
#define MACRO0 QK_MACRO_0

#define MACROR1 QK_DYNAMIC_MACRO_RECORD_START_1
#define MACROR2 QK_DYNAMIC_MACRO_RECORD_START_2
#define MACROP1 QK_DYNAMIC_MACRO_PLAY_1
#define MACROP2 QK_DYNAMIC_MACRO_PLAY_2
#define MACROST QK_DYNAMIC_MACRO_RECORD_STOP

/* KEYMAPS */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY */
  [_QWERTY] = LAYOUT(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
    LCTLESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TL_UPPR,
                               QK_REP,  KC_LOPT, KC_LCMD, LOSPACE,

             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFTENTR,
    TL_UPPR, TL_LOWR, KC_RCMD, QK_AREP
  ),

  /* LOWER */
  [_LOWER] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, KC_WH_D,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, MACROR1,
                               _______, _______, _______, _______,

             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_BSLS,
    MACROR2, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______
  ),
  /* RAISE */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
    KC_CAPS, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, MACROP1,
                               _______, _______, _______, _______,

             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
             KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO, _______,
    MACROP2, _______, _______, KC_LABK, KC_RABK, KC_QUES, _______,
    _______, _______, _______, _______
  ),
  /* ADJUST (LOWER + RAISE) */
  [_ADJUST] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   
    _______, KC_F11,  KC_F12,  _______, _______, _______,
    _______, _______, _______, CM_TOGG, _______, _______, MACROST,
                               _______, _______, _______, MACRO0,

             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
             KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, _______, _______,
    MACROST, _______, KC_BRID, KC_BRIU, _______, _______, _______,
    _______, _______, _______, _______
  ),
};

/* COMBOS */

// ( and )
const uint16_t PROGMEM left_paren[]  = { LOSPACE, KC_F, COMBO_END };
const uint16_t PROGMEM right_paren[] = { LOSPACE, KC_J, COMBO_END };

// [ and ]
const uint16_t PROGMEM left_bracket[]  = { LOSPACE, KC_D, COMBO_END };
const uint16_t PROGMEM right_bracket[] = { LOSPACE, KC_K, COMBO_END };

// { and }
const uint16_t PROGMEM left_curly[]  = { LOSPACE, KC_S, COMBO_END };
const uint16_t PROGMEM right_curly[] = { LOSPACE, KC_L, COMBO_END };

// < and >
const uint16_t PROGMEM less_than[]  = { LOSPACE, KC_A,    COMBO_END };
const uint16_t PROGMEM greater_than[] = { LOSPACE, KC_SCLN, COMBO_END };

// = and +
const uint16_t PROGMEM equal[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM plus[]  = { KC_K, KC_L, COMBO_END };

// - and _
const uint16_t PROGMEM dash[] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM unds[] = { KC_J, KC_K, COMBO_END };

// Media Prev and Next
const uint16_t PROGMEM media_prev[] = { KC_VOLD, KC_MPLY, COMBO_END };
const uint16_t PROGMEM media_next[] = { KC_VOLU, KC_MPLY, COMBO_END };

// Swap hands (left and right homerow)
const uint16_t PROGMEM swap_lh[] = { KC_A, KC_S, KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM swap_rh[] = { KC_J, KC_K, KC_L, KC_SCLN, COMBO_END };

// Leader keys
const uint16_t PROGMEM spotlight[] = { KC_LGUI, TL_LOWR, COMBO_END };

combo_t key_combos[] = {
  COMBO(left_paren,    KC_LPRN),
  COMBO(right_paren,   KC_RPRN),
  COMBO(left_bracket,  KC_LBRC),
  COMBO(right_bracket, KC_RBRC),
  COMBO(left_curly,    KC_LCBR),
  COMBO(right_curly,   KC_RCBR),
  COMBO(less_than,     KC_LABK),
  COMBO(greater_than,  KC_RABK),
  COMBO(equal,         KC_EQL),
  COMBO(plus,          KC_PLUS),
  COMBO(dash,          KC_MINS),
  COMBO(unds,          KC_UNDS),
  COMBO(media_prev,    KC_MPRV),
  COMBO(media_next,    KC_MNXT),
  COMBO(swap_lh,       SH_TOGG),
  COMBO(swap_rh,       SH_TOGG),
  COMBO(spotlight,     LCMD(KC_SPACE)),
};

#define COMBO_REF_DEFAULT _QWERTY

uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _ADJUST: return _ADJUST;
        default: return COMBO_REF_DEFAULT;
    }
    return layer;
}

/* SWAPPING HANDS */
#undef  _____
#define _____ {-1,-1}
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
  {{5,4}, {4,4}, {3,4}, {2,4}, {1,4}, {0,4}},
  {{5,5}, {4,5}, {3,5}, {2,5}, {1,5}, {0,5}},
  {{5,6}, {4,6}, {3,6}, {2,6}, {1,6}, {0,6}},
  {_____, {4,7}, {3,7}, {2,7}, {1,7}, {0,7}},

  {{5,0}, {4,0}, {3,0}, {2,0}, {1,0}, {0,0}},
  {{5,1}, {4,1}, {3,1}, {2,1}, {1,1}, {0,1}},
  {{5,2}, {4,2}, {3,2}, {2,2}, {1,2}, {0,2}},
  {{5,3}, {4,3}, {3,3}, {2,3}, {1,3}, _____},
};

/* PERMISSIVE HOLDS */
bool get_hold_on_other_key_press_per_key(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LCTLESC:
    case SFTENTR:
      return true;

    default:
      return false;
  }
}

// vim: ts=2 sw=2 et
