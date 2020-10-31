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
    K_HACK = SAFE_RANGE,
    K_PULSE,
    K_LWR,
    K_RSE,
    K_PRINT,
    K_INSERT,
    K_END,
    K_PAUSE,
    K_DELETE,
    K_HOME,
    K_CIRCLE,
    K_CROSS,
    K_TRIANGLE,
    K_SQUARE,
    K_UP1,
    K_UP2,
    K_DOWN1,
    K_DOWN2,
    K_ESC,
    K_ALT,
    K_CTRL,
    K_SPACEU,
    K_SPACED,
    K_FACE1,
    K_FACE2,
    K_FACE3,
    K_FACE4,
    K_FACE5,
    K_FACE6,
    K_FACE7,
    K_FACE8,
    K_FACE9,
    K_SYM1,
    K_SYM2,
    K_SYM3,
    K_SYM4,
    K_SYM5,
    K_SYM6,
    K_SYM7,
    K_SYM8
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_4x12( \
        K_CIRCLE,   K_CROSS,  K_ESC,    K_FACE3, K_FACE6, K_FACE9, K_PRINT,  K_INSERT, K_SYM4, K_SYM8, K_RSE, KC_RIGHT, \
        K_TRIANGLE, K_SQUARE, K_ALT,    K_FACE2, K_FACE5, K_FACE8, K_END,    K_PAUSE, K_SYM3, K_SYM7, K_LWR, KC_UP, \
        K_UP2,      K_DOWN2,  K_CTRL,   K_FACE1, K_FACE4, K_FACE7, K_DELETE, K_HOME, K_SYM2, K_SYM6, K_PULSE, KC_DOWN, \
        K_UP1,      K_DOWN1,  K_SPACEU, _______, _______, _______, _______,  K_SPACED, K_SYM1, K_SYM5, K_HACK, KC_LEFT \
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
        case K_UP1:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_K);
            return false;

        case K_DOWN1:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_J);
            return false;

        case K_UP2:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_LSFT);
            key(record->event.pressed, KC_K);
            return true;

        case K_DOWN2:
            key(record->event.pressed, KC_LALT);
            key(record->event.pressed, KC_LSFT);
            key(record->event.pressed, KC_J);
            return true;
    }

    if (!record->event.pressed) {
        rgblight_disable_noeeprom();
        return true;
    }

    switch (keycode) {
        case K_TRIANGLE:
            SEND_STRING(COMBO(" "));
            light(HUE_ORANGE, SAT_HIGH, BRIGHT_HIGH);
            return false;

        case K_CIRCLE:
            SEND_STRING(COMBO("."));
            light(HUE_GREEN, SAT_HIGH, BRIGHT_MED);
            return false;

        case K_SQUARE:
            SEND_STRING(SS_LGUI("m"));
            light(HUE_RED, SAT_MED, BRIGHT_MED);
            return false;

        case K_CROSS:
            SEND_STRING(COMBO(","));
            light(HUE_PURPLE, SAT_MED, BRIGHT_MED);
            return false;

        case K_SPACEU:
            return false;

        case K_SPACED:
            return false;

        case K_CTRL:
            SEND_STRING(COMBO("!"));
            light(HUE_RED, SAT_MED, BRIGHT_MED);
            return false;

        case K_ALT:
            SEND_STRING(COMBO("@"));
            light(HUE_GREEN, SAT_MED, BRIGHT_MED);
            return false;

        case K_ESC:
            SEND_STRING(COMBO("#"));
            light(HUE_YELLOW, SAT_HIGH, BRIGHT_HIGH);
            return false;

        case K_FACE1:
            SEND_STRING(COMBO("a"));
            light(HUE_RED, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE2:
            SEND_STRING(COMBO("b"));
            light(HUE_GREEN, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE3:
            SEND_STRING(COMBO("c"));
            light(HUE_YELLOW, SAT_HIGH, BRIGHT_HIGH);
            return false;

        case K_FACE4:
            SEND_STRING(COMBO("d"));
            light(HUE_RED, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE5:
            SEND_STRING(COMBO("e"));
            light(HUE_GREEN, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE6:
            SEND_STRING(COMBO("f"));
            light(HUE_YELLOW, SAT_HIGH, BRIGHT_HIGH);
            return false;

        case K_FACE7:
            SEND_STRING(COMBO("g"));
            light(HUE_RED, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE8:
            SEND_STRING(COMBO("h"));
            light(HUE_GREEN, SAT_MED, BRIGHT_MED);
            return false;

        case K_FACE9:
            SEND_STRING(COMBO("i"));
            light(HUE_YELLOW, SAT_HIGH, BRIGHT_HIGH);
            return false;

        case K_DELETE:
            SEND_STRING(COMBO("$"));
            return false;

        case K_END:
            SEND_STRING(COMBO("%"));
            rgblight_disable_noeeprom();
            return false;

        case K_PRINT:
            SEND_STRING(COMBO("^"));
            return false;

        case K_HOME:
            SEND_STRING(COMBO("&"));
            return false;

        case K_PAUSE:
            SEND_STRING(COMBO("*"));
            return false;

        case K_INSERT:
            SEND_STRING(COMBO("-"));
            return false;

        case K_SYM1:
            SEND_STRING(COMBO("1"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM2:
            SEND_STRING(COMBO("2"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM3:
            SEND_STRING(COMBO("3"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM4:
            SEND_STRING(COMBO("4"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM5:
            SEND_STRING(COMBO("5"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM6:
            SEND_STRING(COMBO("6"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM7:
            SEND_STRING(COMBO("7"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_SYM8:
            SEND_STRING(COMBO("8"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_HACK:
            SEND_STRING(SS_LGUI("\n"));
            light(HUE_RED, SAT_NONE, BRIGHT_LOW);
            return false;

        case K_PULSE:
            return false;

        case K_LWR:
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_F1))));
            return false;

        case K_RSE:
            SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_F2))));
            return false;
    }

    return true;
}
