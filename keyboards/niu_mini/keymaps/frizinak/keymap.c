#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ARROWS 3
#define _LR     4
#define _GAME   5

#define SFT OSM(MOD_LSFT)

enum planck_keycodes {
    K_GAME = SAFE_RANGE,
    K_PAREN,
    K_BRACE,
    K_CBRAC,
    K_ARROW
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,   KC_Y,   KC_U,        KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,        KC_G,   KC_H,   KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,   KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
  KC_LCTL, _______, KC_LALT, KC_LGUI, MO(_LOWER),  KC_SPC, KC_SPC, MO(_RAISE),  KC_RGUI, K_GAME,  MO(_ARROWS), KC_RCTL  \
),

[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______, \
  _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, K_ARROW, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
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

[_GAME] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______  \
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
}

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _LR);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case K_GAME:
            if (!layer_state_is(_GAME)) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(song_mario_mush);
                #endif

                #ifdef RGBLIGHT_ENABLE
                rgblight_enable_noeeprom();
                rgblight_sethsv_noeeprom(255, 200, 73);
                rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                #endif

                layer_state_set(1U << (_QWERTY | _GAME));
                return false;
            }

            #ifdef RGBLIGHT_ENABLE
            rgblight_sethsv_noeeprom(245, 0, 30);
            #endif

            #ifdef AUDIO_ENABLE
            PLAY_SONG(song_down);
            #endif
            layer_state_set(1U << _QWERTY);
            return false;

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
    }

    return true;
}
