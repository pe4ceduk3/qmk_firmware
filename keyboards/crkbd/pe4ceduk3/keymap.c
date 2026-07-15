
#include QMK_KEYBOARD_H

// Определение слоев
enum custom_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE
};

// Названия клавиш переключения слоев для удобства читаемости кода
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
     * Слой 0: Базовый (QWERTY)
     * -----------------------------------------------------------------------------------------
     * | TAB  |  Q  |  W  |  E  |  R  |  T  |             |  Y  |  U  |  I  |  O  |  P  | BSPC |
     * | CTRL |  A  |  S  |  D  |  F  |  G  |             |  H  |  J  |  K  |  L  |  ;  |  '   |
     * | SHFT |  Z  |  X  |  C  |  V  |  B  |             |  N  |  M  |  ,  |  .  |  /  | ENT  |
     *                    | ALT | LOWER| SPC |             | ENT | RAISE| GUI |
     */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                   KC_LALT, LOWER,   KC_SPC,                    KC_ENT,  RAISE,   KC_LGUI
    ),

    /* 
     * Слой 1: LOWER (Цифры и знаки препинания) — активируется при зажатии левой клавиши под большим пальцем
     * -----------------------------------------------------------------------------------------
     * | ESC  |  1  |  2  |  3  |  4  |  5  |             |  6  |  7  |  8  |  9  |  0  | DEL  |
     * | TRNS |  !  |  @  |  #  |  $  |  %  |             |  ^  |  &  |  *  |  (  |  )  | TRNS |
     * | TRNS |  -  |  _  |  =  |  +  |  \  |             |  |  |  [  |  ]  |  {  |  }  | TRNS |
     *                    | TRNS| TRNS| TRNS|             | TRNS| TRNS| TRNS|
     */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_MINS, KC_UNDS, KC_EQL,  KC_PLUS, KC_BSLS,                   KC_PIPE, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* 
     * Слой 2: RAISE (Навигация и функциональные клавиши) — активируется при зажатии правой клавиши под большим пальцем
     * -----------------------------------------------------------------------------------------
     * | F1   |  F2 |  F3 |  F4 |  F5 |  F6 |             | HOME| PGDN| PGUP| END | TRNS| TRNS |
     * | F7   |  F8 |  F9 | F10 | F11 | F12 |             | LEFT| DOWN|  UP | RGHT| TRNS| TRNS |
     * | TRNS | MUTE| VOL-| VOL+| MNXT|MPLY |             | TRNS| TRNS| TRNS| TRNS| TRNS| TRNS |
     *                    | TRNS| TRNS| TRNS|             | TRNS| TRNS| TRNS|
     */
    [_RAISE] = LAYOUT_split_3x6_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, KC_TRNS,
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
    )
};
