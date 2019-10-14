#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH,KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, \
    KC_LCTL, MO(1),   KC_LGUI,                           KC_SPC,                             KC_RGUI, MO(1),   KC_LALT, KC_RCTL
  ),

  [1] = LAYOUT(
    TG(2),   KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC,  \
    KC_DEL , _______, KC_7,    KC_8,   KC_9,    _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, \
    KC_CAPS, _______, KC_4,    KC_5,   KC_6,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, \
    _______, KC_0,    KC_1,    KC_2,   KC_3,    _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______,                            _______,                           _______, _______, _______, _______
  ),

  [2] = LAYOUT(
    TG(2), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, \
    _______, RGB_VAD, RGB_VAI, KC_BRID, KC_BRIU, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,  BL_TOGG, \
    _______, RGB_MOD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, KC_MUTE, _______, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______
  ),
};
