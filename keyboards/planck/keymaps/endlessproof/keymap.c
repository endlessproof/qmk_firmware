/* Layout Diagram: http://www.keyboard-layout-editor.com/#/gists/a57e47364364a1cc5d104502d56a7795
 */
 
#include "planck.h"
#include "action_layer.h" /*This is not in my QMK folder for the planck what does it do?*/
 
extern keymap_config_t keymap_config;
 
enum planck_layers {
  _MAIN,
  _FNSPC,
  _RAISE, //right hand fn key
  _LOWER, //left hand fn key
};
 
enum custom_keycodes {
    DBL0 = SAFE_RANGE,
};
 
#define FN_SPC LT(_FNSPC, KC_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TSKMAN LCTL(LSFT(KC_ESC))
#define ALT_TAB LALT(KC_TAB)
#define WIN_TAB LGUI(KC_TAB)
#define BSLSH KC_BSLASH
#define NUM_ON TO(_FNSPC)
#define NUM_OFF TO(_MAIN)
#define POUND HYPR(KC_F1)
#define DEGREE HYPR(KC_F2)
#define PLSMIN HYPR(KC_F3)
#define LESSTHN HYPR(KC_F4)
#define MORETHN HYPR(KC_F5)
#define EML HYPR(KC_F6)
#define PWD HYPR(KC_F7)
#define SNIP HYPR(KC_F8)
 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Hyp  |Lower |  Space/Fn   |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
 
[_MAIN] = {
  {KC_ESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_LCTL, KC_LGUI, KC_LALT, KC_HYPR, LOWER,   FN_SPC,  FN_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
// Center key is repeated to accommodate for both spacebar wiring positions

 
 
/* FnSpc (Fn When Held)
 * ,-----------------------------------------------------------------------------------.
 * |      | Home | End  | Email|  F5  |      |   /  |   7  |   8  |   9  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | PgDn | PgUp | Pword|  $   |      |   *  |   4  |   5  |   6  |   +  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  (   |  )   | Caps |  :   |      |  #   |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Left | Down | Up   | Right|      |             |   0  |  00  |   .  |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_FNSPC] = {
  {_______, KC_HOME, KC_END,  EML,     KC_F5,   XXXXXXX, KC_SLASH, KC_7,    KC_8,    KC_9,    KC_MINS, _______},
  {KC_DEL,  KC_PGDN, KC_PGUP, PWD,     KC_DLR,  XXXXXXX, KC_PAST,  KC_4,    KC_5,    KC_6,    KC_PLUS, KC_DEL},
  {NUM_OFF, KC_LPRN, KC_RPRN, KC_CAPS, _______, XXXXXXX, KC_HASH,  KC_1,    KC_2,    KC_3,    KC_EQL,  _______},
  {KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,  KC_0,    DBL0,    KC_DOT,  XXXXXXX, XXXXXXX}
},
 
 
 
/* Raise (Right)
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |wintab|      |      |      |      |      |      |      |   {  |   [  |   ]  |  }   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |   £  |   °  |   ±  |   ≤  |   ≥  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_RAISE] = {
  {KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {WIN_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_LBRC, KC_RCBR},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, POUND,   DEGREE,  PLSMIN,  LESSTHN, MORETHN, BSLSH,   _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},
 
 
 
/* Lower (Left)
 * ,-----------------------------------------------------------------------------------.
 * |TskMan|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |PrtScr|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Mute | Vol- | Vol+ |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Play | Prev | Next |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | BkLt | BL-  | BL+  |      |             |      |      |      |      |Reset |
 * `-----------------------------------------------------------------------------------'
 */
 
[_LOWER] = {
  {TSKMAN,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   SNIP,    _______},
  {_______, KC_MUTE, KC_VOLD, KC_VOLU, KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {NUM_ON,  KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {_______, BL_TOGG, BL_DEC,  BL_INC,  _______, _______, _______, _______, _______, _______, _______, RESET}
}
};
 
 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case DBL0:
        SEND_STRING("00");
        return false;
    }
  }
  return true;
}