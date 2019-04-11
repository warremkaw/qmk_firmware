#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ARROWS 3
#define _ADJUST 4
#define _GAME   5

#define SFT OSM(MOD_LSFT)

enum planck_keycodes {
    K_GAME = SAFE_RANGE,
    K_S1,
    K_S2,
    K_S3,
    K_S4,
    K_S5,
    K_S6,
    K_S7,
    K_S8,
    K_S9,
    K_S10,
    K_U1,
    K_U2,
    K_U3,
    K_U4,
    K_U5,
    K_U6,
    K_U7,
    K_U8,
    K_U9,
    K_U10
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
  _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_RAISE] = LAYOUT_ortho_4x12( \
  _______, XXXXXXX, KC_7,    KC_8,    KC_9, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,  _______, \
  _______, XXXXXXX, KC_4,    KC_5,    KC_6, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12, _______, \
  _______, XXXXXXX, KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_0, _______, _______, _______, _______, _______, _______, _______  \
),

[_ARROWS] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
),

[_ADJUST] = LAYOUT_ortho_4x12( \
  _______, K_S1,    K_S2,    K_S3,    K_S4,    K_S5,    K_S6,    K_S7,    K_S8,    K_S9,     K_S10,   KC_DEL, \
  _______, MU_TOG,  MU_MOD,  _______, CK_TOGG, _______, _______, CK_DOWN, CK_UP,    _______, _______, _______, \
  _______, K_U1,    K_U2,    K_U3,    K_U4,    K_U5,    K_U6,    K_U7,    K_U8,    K_U9,     K_U10,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
),

[_GAME] = LAYOUT_ortho_4x12( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______  \
)

};

float song_mario_mush[][2] = SONG(MARIO_MUSHROOM);
float song_down[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
#define NLONG 16+8
#define NSHORT 16+8
#define NPAUSE 0
float song_mario[][2] = {
    {NOTE_E7, NLONG}, {NOTE_E7, NLONG}, {NPAUSE, NLONG}, {NOTE_E7, NLONG},
    {NPAUSE, NLONG}, {NOTE_C7, NLONG}, {NOTE_E7, NLONG}, {NPAUSE, NLONG},
    {NOTE_G7, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG},
    {NOTE_G6, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG},

    {NOTE_C7, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NOTE_G6, NLONG},
    {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NOTE_E6, NLONG}, {NPAUSE, NLONG},
    {NPAUSE, NLONG}, {NOTE_A6, NLONG}, {NPAUSE, NLONG}, {NOTE_B6, NLONG},
    {NPAUSE, NLONG}, {NOTE_AS6, NLONG}, {NOTE_A6, NLONG}, {NPAUSE, NLONG},

    {NOTE_G6, NSHORT}, {NOTE_E7, NSHORT}, {NOTE_G7, NSHORT},
    {NOTE_A7, NLONG}, {NPAUSE, NLONG}, {NOTE_F7, NLONG}, {NOTE_G7, NLONG},
    {NPAUSE, NLONG}, {NOTE_E7, NLONG}, {NPAUSE, NLONG}, {NOTE_C7, NLONG},
    {NOTE_D7, NLONG}, {NOTE_B6, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG},

    {NOTE_C7, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NOTE_G6, NLONG},
    {NPAUSE, NLONG}, {NPAUSE, NLONG}, {NOTE_E6, NLONG}, {NPAUSE, NLONG},
    {NPAUSE, NLONG}, {NOTE_A6, NLONG}, {NPAUSE, NLONG}, {NOTE_B6, NLONG},
    {NPAUSE, NLONG}, {NOTE_AS6, NLONG}, {NOTE_A6, NLONG}, {NPAUSE, NLONG},

    {NOTE_G6, NSHORT}, {NOTE_E7, NSHORT}, {NOTE_G7, NSHORT},
    {NOTE_A7, NLONG}, {NPAUSE, NLONG}, {NOTE_F7, NLONG}, {NOTE_G7, NLONG},
    {NPAUSE, NLONG}, {NOTE_E7, NLONG}, {NPAUSE, NLONG}, {NOTE_C7, NLONG},
    {NOTE_D7, NLONG}, {NOTE_B6, NLONG}, {NPAUSE, NLONG}, {NPAUSE, NLONG}

};

float s1[][2] = SONG(IMPERIAL_MARCH);
float s2[][2] = SONG(ONE_UP_SOUND);
float s3[][2] = SONG(CLOSE_ENCOUNTERS_5_NOTE);
float s4[][2] = SONG(MARIO_GAMEOVER);
float s5[][2] = SONG(MARIO_MUSHROOM);
float s6[][2] = SONG(MARIO_MUSHROOM);
float s7[][2] = SONG(ZELDA_PUZZLE);
float s8[][2] = SONG(ROCK_A_BYE_BABY);
float s9[][2] = SONG(CLUEBOARD_SOUND );
float s10[][2] = SONG(FF_PRELUDE);

void matrix_init_user(void) {
    #ifdef UNICODE_ENABLE
    set_unicode_input_mode(UC_LNX);
    #endif
};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case K_S1:
            PLAY_SONG(s1);
            return false;

        case K_S2:
            PLAY_SONG(s2);
            return false;

        case K_S3:
            PLAY_SONG(s3);
            return false;

        case K_S4:
            PLAY_SONG(s4);
            return false;

        case K_S5:
            PLAY_SONG(s5);
            return false;

        case K_S6:
            PLAY_SONG(s6);
            return false;

        case K_S7:
            PLAY_SONG(s7);
            return false;

        case K_S8:
            PLAY_SONG(s8);
            return false;

        case K_S9:
            PLAY_SONG(s9);
            return false;

        case K_S10:
            PLAY_SONG(s10);
            return false;

        case K_U1:
            // SEND_STRING("( ͡° ͜ʖ ͡°)");
            send_unicode_hex_string("0028 0020 0361 00B0 0020 035C 0296 0020 0361 00B0 0029");
            return false;

        case K_U2:
            // SEND_STRING("¯\\_(ツ)_/¯");
            send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
            return false;

        case K_U3:
            // SEND_STRING(" (╯°□°）╯︵ ┻━┻");
            send_unicode_hex_string("0020 0028 256F 00B0 25A1 00B0 FF09 256F FE35 0020 253B 2501 253B");
            return false;

        case K_U4:
            // SEND_STRING("(ಠ_ಠ)");
            send_unicode_hex_string("0028 0CA0 005F 0CA0 0029");
            return false;

        case K_U5:
            // SEND_STRING("(づ￣ ³￣)づ");
            send_unicode_hex_string("0028 3065 FFE3 0020 00B3 FFE3 0029 3065");
            return false;

        case K_U6:
            return false;

        case K_U7:
            return false;

        case K_U8:
            return false;

        case K_U9:
            return false;

        case K_U10:
            return false;

        case K_GAME:
            if (!layer_state_is(_GAME)) {
                #ifdef AUDIO_ENABLE
                PLAY_SONG(song_mario_mush);
                #endif
                layer_state_set(1U << (_QWERTY | _GAME));
                return false;
            }

            #ifdef AUDIO_ENABLE
            PLAY_SONG(song_down);
            #endif
            layer_state_set(1U << _QWERTY);
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
