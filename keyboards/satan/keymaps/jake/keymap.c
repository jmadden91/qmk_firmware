#include "satan.h"


// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _QWERTY		0
#define _FUNCTION 	1
#define _ARROWS 	2

#define _______ KC_TRNS

#define MACRO_BREATH_TOGGLE             21
#define MACRO_BREATH_SPEED_INC          23
#define MACRO_BREATH_SPEED_DEC          24
#define MACRO_BREATH_DEFAULT            25



#define M_BRTOG             M(MACRO_BREATH_TOGGLE)
#define M_BSPDU             M(MACRO_BREATH_SPEED_INC)
#define M_BSPDD             M(MACRO_BREATH_SPEED_DEC)
#define M_BDFLT             M(MACRO_BREATH_DEFAULT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 

/* Keymap _QWERTY: Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |CAPS/F1|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |    |ALT |GUI |F2   |
   * `-----------------------------------------------------------'
   */
[_QWERTY] = KEYMAP(
  F(0),    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, \
  F(3),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,            KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,   KC_SLSH,            KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,          KC_SPC,                                       KC_TRNS,  KC_RALT,  KC_RGUI,  F(1)),







 /* Keymap _FUNTION: Function Layer
   * ,-----------------------------------------------------------.
   * |SLP| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|V- |V+ |Delete |
   * |-----------------------------------------------------------|
   * |     |   |   |   |RGB|MOD|   |   |Up |   |   |   |tst| TEST|
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |Lef|Dwn|Rig|   |   |        |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |BL |BL-|BL+|BLf|BLs|BLt|          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |DFU |
   * `-----------------------------------------------------------'
   */

[_FUNCTION] = KEYMAP(
  KC_SLEP,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,   KC_F9,     KC_F10,    KC_VOLD,   KC_VOLU,   KC_DEL,  \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_MOD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_LGUI,   KC_LGUI, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN, KC_RGHT,   KC_TRNS,   KC_TRNS,              KC_TRNS, \
  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BL_TOGG,  BL_DEC,   BL_INC,  M_BSPDD,   M_BSPDU,   M_BRTOG,              KC_TRNS, \
  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,                                                        KC_TRNS,   KC_TRNS,   KC_TRNS,   RESET),
 





/* Keymap 3: Arrows Mode - with chrome tab switching
   * ,-----------------------------------------------------------.
   * |FTmd|T1| T2| T3| T4| T5| T6| T7| T8| T9|T10| Z-| Z+|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \|
   * |-----------------------------------------------------------|
   * |       |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|UP |Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Lft |Dwn |Rgt |F2   |
   * `-----------------------------------------------------------'
   */

[_ARROWS] = KEYMAP( 
  M(12),   M(0),   M(1),   M(2),   M(3),   M(4),   M(5),   M(6),   M(7),   M(8),   M(9),     M(10),    M(11),    KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, \
  KC_TRNS,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,  KC_QUOT,            KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,   KC_UP,              KC_RSFT, \
  KC_NO,   KC_NO,  KC_NO,         KC_TRNS,                                         KC_LEFT,  KC_DOWN,  KC_RGHT,  F(2)),
 






};

enum function_id {
    SHIFT_ESC,


};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
  [1]  = ACTION_LAYER_ON(_ARROWS, ON_PRESS),
  [2]  = ACTION_LAYER_OFF(_ARROWS, ON_PRESS),
  [3]  = ACTION_LAYER_TAP_KEY(_FUNCTION, KC_CAPS),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case SHIFT_ESC:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
        break;


    break;


    




  }
}




/*    Still working on...
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (id) {
    
    case _ARROWS:
      if (record->event.pressed) {
        layer_on(_ARROWS);
        breathing_speed_set(3);
        breathing_toggle();
      } else {
        breathing_speed_set(1);
        breathing_self_disable();
        layer_off(_ARROWS);
      }
      return false;
      break;
  }
  return true;
}
*/

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
case 0:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(1) , U(LCTL),  END ) :MACRO( END ));
          break;
case 1:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(2) , U(LCTL),  END ) :MACRO( END ));
          break;
case 2:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(3) , U(LCTL),  END ) :MACRO( END ));
          break;
case 3:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(4) , U(LCTL),  END ) :MACRO( END ));
          break;
case 4:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(5) , U(LCTL),  END ) :MACRO( END ));
          break;
case 5:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(6) , U(LCTL),  END ) :MACRO( END ));
          break;
case 6:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(7) , U(LCTL),  END ) :MACRO( END ));
          break;
case 7:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(8) , U(LCTL),  END ) :MACRO( END ));
          break;
case 8:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(9) , U(LCTL),  END ) :MACRO( END ));
          break;
case 9:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(0) , U(LCTL),  END ) :MACRO( END ));
          break;
case 10:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(MINS) , U(LCTL),  END ) :MACRO( END ));
          break;
case 11:
          return (record->event.pressed ? MACRO( D(LCTL) ,T(EQL) , U(LCTL),  END ) :MACRO( END ));
          break;
case 12:
          return (record->event.pressed ? MACRO( D(LGUI) ,T(R) , U(LGUI),   END ) :MACRO( END ));
          break;

case MACRO_BREATH_TOGGLE:
        if (record->event.pressed)
        {
            breathing_toggle();
        }
        break;

case MACRO_BREATH_SPEED_INC:
        if (record->event.pressed)
        {
            breathing_speed_inc(1);
        }
        break;

case MACRO_BREATH_SPEED_DEC:
        if (record->event.pressed)
        {
            breathing_speed_dec(1);
        }
        break;

case MACRO_BREATH_DEFAULT:
        if (record->event.pressed)
        {
            breathing_defaults();
        }
        break;

      }
    return MACRO_NONE;


};

