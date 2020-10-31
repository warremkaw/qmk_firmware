#include QMK_KEYBOARD_H

#define _QWERTY        0
#define _LOWER         1
#define _NPAD          2
#define _RAISE         3
#define _ARROWS        4
#define _LR            5
#define _RAWTHERAPEE   6

#define SFT OSM(MOD_LSFT)

enum planck_keycodes {
    K_PAREN = SAFE_RANGE,
    K_BRACE,
    K_CBRAC,
    K_ARROW,
    K_RAWTHERAPEE,
    RT_PREV,
    RT_NEXT,
    RT_DEL,
    RT_1,
    RT_2,
    RT_3,
    RT_4,
    RT_5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,   KC_Y,   KC_U,        KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,        KC_G,   KC_H,   KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,   KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
  KC_LCTL, _______, KC_LALT, KC_LGUI, MO(_LOWER),  KC_SPC, KC_SPC, MO(_RAISE),  KC_RGUI, K_RAWTHERAPEE, MO(_ARROWS), MO(_NPAD)  \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, \
  _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, K_ARROW, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_NPAD] = LAYOUT_ortho_4x12( \
  KC_NUMLOCK, KC_PLUS, KC_P7,    KC_P8,    KC_P9, _______, _______, _______, _______, _______, _______, _______, \
  _______,    KC_MINS, KC_P4,    KC_P5,    KC_P6, _______, _______, _______, _______, _______, _______, _______, \
  _______,    KC_ASTR, KC_P1,    KC_P2,    KC_P3, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
  _______,    KC_SLSH, _______, _______,   KC_P0, _______, _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_PLUS, KC_7,    KC_8,    KC_9, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,  _______, \
  _______, KC_MINS, KC_4,    KC_5,    KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, _______, \
  _______, KC_ASTR, KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
  _______, KC_SLSH, _______, _______, KC_0, _______, _______, _______, _______, _______, _______, _______  \
),

[_ARROWS] = LAYOUT_ortho_4x12( \
  _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
),

[_LR] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_UNDS, KC_PLUS, _______, \
  _______, K_PAREN, K_PAREN, K_BRACE, K_BRACE, K_PAREN, K_PAREN, K_CBRAC, K_CBRAC,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______ \
),

[_RAWTHERAPEE] = LAYOUT_ortho_4x12( \
  _______, RT_DEL,  _______, _______, _______, _______, _______, _______, _______, _______,  _______, RT_DEL, \
  _______, RT_1,    RT_2,    RT_3,    RT_4,    RT_5,    RT_PREV, RT_NEXT, RT_PREV, RT_NEXT,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______  \
)

};

void matrix_init_user(void) {
    // todo remove when retarded bug is fixed
    keymap_config.raw = eeconfig_read_keymap();
    keymap_config.swap_lctl_lgui = false;
    eeconfig_update_keymap(keymap_config.raw);
    #ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
    #endif
    if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
        register_code(KC_NUMLOCK);
        unregister_code(KC_NUMLOCK);
    }
}

void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(0, 255, 10);
    #endif
}

uint8_t rand8(uint8_t min, uint8_t max) {
    return (rand() % (max - min)) + min;
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _LR);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_noeeprom(rand8(0, 230), rand8(180, 255), 10);
    #endif
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        #ifdef RGBLIGHT_ENABLE
        case MO(_NPAD):
            rgblight_toggle_noeeprom();
            return true;
        #endif

        case K_ARROW:
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                SEND_STRING(SS_UP(X_LSHIFT) "=>" SS_DOWN(X_LSHIFT));
                return false;
            }

            SEND_STRING("->");
            return false;

        case K_PAREN:
            SEND_STRING("()" SS_TAP(X_LEFT));
            return false;

        case K_BRACE:
            SEND_STRING("[]" SS_TAP(X_LEFT));
            return false;

        case K_CBRAC:
            SEND_STRING("{}" SS_TAP(X_LEFT));
            return false;

        case KC_P:
            if (get_mods() == MOD_BIT(KC_LGUI)) {
                SEND_STRING(SS_UP(X_LGUI) SS_LCTRL("v") SS_DOWN(X_LGUI));
                return false;
            }

            break;

        case KC_BSPC:
            if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                SEND_STRING(SS_UP(X_LSHIFT) SS_TAP(X_DELETE) SS_DOWN(X_LSHIFT));
                return false;
            }

            break;

        case K_RAWTHERAPEE:
            if (!layer_state_is(_RAWTHERAPEE)) {
                layer_state_set(1U << (_QWERTY | _RAWTHERAPEE));
                return false;
            }

            layer_state_set(1U << _QWERTY);
            return false;

        case RT_PREV:
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_F3) SS_UP(X_LSHIFT));
            return false;
        case RT_NEXT:
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_1:
            SEND_STRING(SS_TAP(X_Y) SS_DOWN(X_LSHIFT) SS_TAP(X_1) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_2:
            SEND_STRING(SS_TAP(X_Y) SS_DOWN(X_LSHIFT) SS_TAP(X_2) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_3:
            SEND_STRING(SS_TAP(X_Y) SS_DOWN(X_LSHIFT) SS_TAP(X_3) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_4:
            SEND_STRING(SS_TAP(X_Y) SS_DOWN(X_LSHIFT) SS_TAP(X_4) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_5:
            SEND_STRING(SS_TAP(X_Y) SS_DOWN(X_LSHIFT) SS_TAP(X_5) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
        case RT_DEL:
            SEND_STRING(SS_TAP(X_Y) SS_TAP(X_DELETE) SS_DOWN(X_LSHIFT) SS_TAP(X_F4) SS_UP(X_LSHIFT));
            return false;
    }

    return true;
}
