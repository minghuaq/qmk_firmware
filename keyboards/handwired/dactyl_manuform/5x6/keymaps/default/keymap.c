#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLS,
                         KC_LBRC,KC_RBRC,                                                       KC_PLUS, KC_EQL,
                                         KC_SPC, RAISE,                          LOWER,  KC_ENT, 
                                         KC_TAB, KC_HOME,                        KC_END, KC_DEL,
                                         KC_BSPC,KC_GRV,                         KC_LGUI,KC_LALT
    ),

    [_LOWER] = LAYOUT_5x6(
        KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        RGB_RMOD,RGB_MOD,RGB_HUD,RGB_HUI,_______,RGB_TOG,
        _______,_______,_______,_______,_______,KC_LBRC,                        RGB_SAD,RGB_SAI,RGB_VAD,RGB_VAI,RGB_SPD,RGB_SPI,
        _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
        _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                                _______,KC_PSCR,            _______, KC_P0,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______

    ),

    // [_LOWER] = LAYOUT_5x6(
    //     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
    //     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
    //     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
    //     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
    //                                             _______,KC_PSCR,            _______, KC_P0,
    //                                             _______,_______,            _______,_______,
    //                                             _______,_______,            _______,_______,
    //                                             _______,_______,            _______,_______

    // ),

    [_RAISE] = LAYOUT_5x6(
          KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NUM,KC_INS ,KC_SCRL,KC_MUTE,
          _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
          _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
                                                  _______,_______,            KC_EQL ,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______,
                                                  _______,_______,            _______,_______
    )
};

#ifdef RGB_MATRIX_ENABLE

// LED Layout
// Columns
// 0   1   2   3   4   5   6   7   8   9   10  11  12  13
// Physical (Center: 112)
// 0   17  34  52  69  86  103 121 138 155 172 190 207 224
//                                                          Rows  Physical (Center: 32)
// 37  36  35  34  33  32          00  01  02  03  04  05   0     0
// 38  39  40  41  42  43          11  10  09  08  07  06   1     11
// 49  48  47  46  45  44          12  13  14  15  16  17   2     21
// 50  51  52  53  54  55          23  22  21  20  19  18   3     32
//     63  62          61  56  24  29      30  31           4     43
//                     60  57  25  28                       5     53
//                     59  58  26  27                       6     64


led_config_t g_led_config = { {

  // //Right 1-32
  // { 0,   1,   2,   3,   4,   5 },
  // { 11,  10,  9,   8,   7,   6 },
  // { 12,  13,  14,  15,  16,  17 },
  // { 23,  22,  21,  20,  19,  18, },
  // { 24,  29,  30,  31,  NO_LED,  NO_LED },
  // { 25,  28,  26,  27,  NO_LED,  NO_LED },
  // // Key Matrix to LED Index
  // //Left 1-32
  // { 37,  36,  35,  34,  33,  32 },
  // { 38,  39,  40,  41,  42,  43 },
  // { 49,  48,  47,  46,  45,  44 },
  // { 50,  51,  52,  53,  54,  55 },
  // { NO_LED,  NO_LED,  63,  62,  61,  56 },
  // { NO_LED,  NO_LED,  59,  58,  60,  57 },

  //Left 1-32
  { 5,   4,   3,   2,   1,   0 },
  { 6,   7,   8,   9,  10,  11 },
  { 17,  16,  15,  14,  13,  12 },
  { 18,  19,  20,  21,  22,  23 },
  { NO_LED,  NO_LED,  31,  30,  29,  24 },
  { NO_LED,  NO_LED,  27,  26,  28,  25 },
  // Key Matrix to LED Index
  //Right 1-32
  { 32,  33,  34,  35,  36,  37 },
  { 43,  42,  41,  40,  39,  38 },
  { 44,  45,  46,  47,  48,  49 },
  { 55,  54,  53,  52,  51,  50 },
  { 56,  61,  62,  63,  NO_LED,  NO_LED },
  { 57,  60,  58,  59,  NO_LED,  NO_LED },


}, {
  // LED Index to Physical Position
  
  //Left 1-32
  { 86,  0 }, { 69,  0 }, { 52,  0 }, { 34,  0 },{ 17,  0 }, { 0,  0 },
  { 0,  11 }, { 17,  11 }, { 34,  11 }, { 52,  11 },{ 69,  11 }, { 86,  11 },
  { 86,  21 }, { 69,  21 }, { 52,  21 }, { 34,  21 },{ 17,  21 }, { 0,  21 },
  { 0,  32 }, { 17,  32 }, { 34,  32 }, { 52,  32 },{ 69,  32 }, { 86,  32 },
  { 103,  43 }, { 103,  53 }, { 103,  64 }, { 86,  64 },{ 86,  53 }, { 86,  43 },
  { 34,  43 }, { 17,  43 },

  //Right 1-32
  { 138,  0 }, { 155,  0 }, { 172,  0 }, { 190,  0 },{ 207,  0 }, { 224,  0 },
  { 224,  11 }, { 207,  11 }, { 190,  11 }, { 172,  11 },{ 155,  11 }, { 138,  11 },
  { 138,  21 }, { 155,  21 }, { 172,  21 }, { 190,  21 },{ 207,  21 }, { 224,  21 },
  { 224,  32 }, { 207,  32 }, { 190,  32 }, { 172,  32 },{ 155,  32 }, { 138,  32 },
  { 121,  43 }, { 121,  53 }, { 121,  64 }, { 138,  64 },{ 138,  53 }, { 138,  43 },
  { 172,  43 }, { 190,  43 },

}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4,

  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4
} };
#endif
