#include QMK_KEYBOARD_H

#define COMBO(string) SS_LCTRL(SS_LALT(SS_LGUI(string)))

const uint32_t HUE_RED = 0;
const uint32_t HUE_PINK = 306;
const uint32_t HUE_PURPLE = 287;
const uint32_t HUE_PURPLE_DARK = 274;
const uint32_t HUE_BLUE = 200;
const uint32_t HUE_BLUE_DARK = 239;
const uint32_t HUE_GREEN = 90;
const uint32_t HUE_YELLOW = 45;
const uint32_t HUE_ORANGE = 30;

const uint8_t SAT_NONE = 0;
const uint8_t SAT_LOW = 255;
const uint8_t SAT_MED = 255;
const uint8_t SAT_HIGH = 255;

const uint8_t BRIGHT_LOW = 10;
const uint8_t BRIGHT_MED = 50;
const uint8_t BRIGHT_HIGH = 100;
const uint8_t BRIGHT_FULL = 255;

enum planck_keycodes {
    K_1 = SAFE_RANGE,
    K_Q,     K_W,      K_E,      K_R,      K_T,      K_Y,      K_U,      K_I,     K_O,     K_P,     K_4,
    K_2,     K_A,     K_S,      K_D,      K_F,      K_G,      K_H,      K_J,      K_K,     K_L,     K_SEMI,  K_5,
    K_3,     K_Z,     K_X,      K_C,      K_V,      K_B,      K_N,      K_M,      K_COMMA, K_DOT,   K_SLASH, K_6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x12( \
        _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
        K_1,     K_Q,     K_W,      K_E,      K_R,      K_T,      K_Y,      K_U,      K_I,     K_O,     K_P,     K_4,
        K_2,     K_A,     K_S,      K_D,      K_F,      K_G,      K_H,      K_J,      K_K,     K_L,     K_SEMI,  K_5,
        K_3,     K_Z,     K_X,      K_C,      K_V,      K_B,      K_N,      K_M,      K_COMMA, K_DOT,   K_SLASH, K_6
    ),
};

void light(uint32_t h, uint8_t s, uint8_t v) {
    rgblight_enable_noeeprom();
    h = 255 * h / 360;
    rgblight_sethsv_noeeprom((uint8_t) h, s, v);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void key(bool p, uint16_t kc) {
    if (p) {
        register_code(kc);
        return;
    }
    unregister_code(kc);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case K_P:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_K);
            return false;

        case K_4:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_J);
            return false;
    }

    if (!record->event.pressed) {
        rgblight_disable_noeeprom();
        return true;
    }

    light(HUE_BLUE, SAT_HIGH, BRIGHT_HIGH);
    switch (keycode) {
        //case K_Q: SEND_STRING(COMBO("q")); return false;
        //case K_Q: SEND_STRING(COMBO("q")); return false;
        case K_1: SEND_STRING(COMBO("1")); return false;
        case K_Q: SEND_STRING(COMBO("q")); return false;
        case K_W: SEND_STRING(COMBO("w")); return false;
        case K_E: SEND_STRING(COMBO("e")); return false;
        case K_R: SEND_STRING(COMBO("r")); return false;
        case K_T: SEND_STRING(COMBO("t")); return false;
        case K_Y: SEND_STRING(COMBO("y")); return false;
        case K_U: SEND_STRING(COMBO("u")); return false;
        case K_I: SEND_STRING(COMBO("i")); return false;
        case K_O: SEND_STRING(COMBO("o")); return false;
        case K_P: SEND_STRING(COMBO("p")); return false;
        case K_4: SEND_STRING(COMBO("4")); return false;

        case K_2: SEND_STRING(COMBO("2")); return false;
        case K_A: SEND_STRING(COMBO("a")); return false;
        case K_S: SEND_STRING(COMBO("s")); return false;
        case K_D: SEND_STRING(COMBO("d")); return false;
        case K_F: SEND_STRING(COMBO("f")); return false;
        case K_G: SEND_STRING(COMBO("g")); return false;
        case K_H: SEND_STRING(COMBO("h")); return false;
        case K_J: SEND_STRING(COMBO("j")); return false;
        case K_K: SEND_STRING(COMBO("k")); return false;
        case K_L: SEND_STRING(COMBO("l")); return false;
        case K_SEMI: SEND_STRING(COMBO(";")); return false;
        case K_5: SEND_STRING(COMBO("5")); return false;

        case K_3: SEND_STRING(COMBO("3")); return false;
        case K_Z: SEND_STRING(COMBO("z")); return false;
        case K_X: SEND_STRING(COMBO("x")); return false;
        case K_C: SEND_STRING(COMBO("c")); return false;
        case K_V: SEND_STRING(COMBO("v")); return false;
        case K_B: SEND_STRING(COMBO("b")); return false;
        case K_N: SEND_STRING(COMBO("n")); return false;
        case K_M: SEND_STRING(COMBO("m")); return false;
        case K_COMMA: SEND_STRING(COMBO(",")); return false;
        case K_DOT: SEND_STRING(COMBO(".")); return false;
        case K_SLASH: SEND_STRING(COMBO("/")); return false;
        case K_6: SEND_STRING(COMBO("6")); return false;

    }

    return true;
}
