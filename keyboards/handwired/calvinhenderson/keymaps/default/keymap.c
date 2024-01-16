#include QMK_KEYBOARD_H

#define GRAVE_MODS  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define _______ KC_NO

enum layers {
    _BL, // Base layer
    _FL, // Function layer
    _CL, // Control layer
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // Detect the activation of both Shifts
    if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT)
    {
        // Toggle Caps_lock value
        tap_code(KC_CAPS);
    }

    // Keep processing like normal, don't do anything to prevent that
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        KC_ESCAPE,   KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,   KC_PSCR, KC_SCRL, KC_PAUSE,
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL, KC_BACKSPACE,   KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,     KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BACKSLASH,   KC_DEL,  KC_END,  KC_PGDN,
        KC_ESCAPE,    KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_QUOTE,   KC_ENTER,
        KC_LEFT_SHIFT,  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,   KC_RIGHT_SHIFT,             KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                  KC_SPACE,                KC_APP, KC_ROPT, MO(_FL), KC_RCTL,   KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FL] = LAYOUT(
        _______,    KC_MRWD, KC_MPLY, KC_MFFD, KC_MSTP,     KC_MUTE, KC_VOLD, KC_VOLU, _______,     NK_TOGG, _______, _______, _______,   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
        _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,
        _______,       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,               _______,            _______,
        _______, _______, _______,                                 _______,                        _______, _______, _______, _______,   _______, _______, _______
    ),
};
