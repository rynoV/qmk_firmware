#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
/* #include "keymap_german.h" */
/* #include "keymap_nordic.h" */
/* #include "keymap_french.h" */
/* #include "keymap_spanish.h" */
/* #include "keymap_hungarian.h" */
/* #include "keymap_swedish.h" */
/* #include "keymap_br_abnt2.h" */
/* #include "keymap_canadian_multilingual.h" */
/* #include "keymap_german_ch.h" */
/* #include "keymap_jp.h" */
/* #include "keymap_korean.h" */
/* #include "keymap_bepo.h" */
/* #include "keymap_italian.h" */
/* #include "keymap_slovenian.h" */
/* #include "keymap_lithuanian_azerty.h" */
/* #include "keymap_danish.h" */
/* #include "keymap_norwegian.h" */
/* #include "keymap_portuguese.h" */
/* #include "keymap_contributions.h" */
/* #include "keymap_czech.h" */
/* #include "keymap_romanian.h" */
/* #include "keymap_russian.h" */
/* #include "keymap_uk.h" */
/* #include "keymap_estonian.h" */
/* #include "keymap_belgian.h" */
/* #include "keymap_us_international.h" */
/* #include "keymap_croatian.h" */
/* #include "keymap_turkish_q.h" */
/* #include "keymap_slovak.h" */

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum planck_keycodes {
  RGB_SLD = SAFE_RANGE,
  EMAIL,
  EMAIL_SCHOOL,
  EMAIL_WORK,
  NAME,
  PHONE,
  HTML_FOLDABLE,
  ALT_S_L,
  CTRL_TAB,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _DVORAK,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPC,
    MT(MOD_LCTL, KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,      KC_QUOTE,
    SC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_RSFT, KC_ENTER),
    KC_MEH,         KC_HYPR,        KC_LGUI,        KC_LALT,        LOWER,          LT(4,KC_SPACE), KC_NO,          RAISE,          TD(DANCE_0),    QK_DYNAMIC_MACRO_PLAY_1,QK_DYNAMIC_MACRO_RECORD_START_1, QK_DYNAMIC_MACRO_RECORD_STOP
                               ),

  [_LOWER] = LAYOUT_planck_grid(
    CTRL_TAB, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,
    KC_TRANSPARENT, KC_PIPE,        KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_HOME,        KC_PGDN,      KC_PGUP,        KC_END,         KC_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ALT_S_L, RCS(KC_P), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,
    KC_TRANSPARENT, KC_BSLS,      KC_MINUS,       KC_EQUAL,       KC_LBRC,    KC_RBRC,    TD(DANCE_1),    KC_DOWN,        KC_UP,          TD(DANCE_2),    KC_GRAVE,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_UNDO, KC_CUT, KC_COPY,       KC_PASTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCR, TG(_DVORAK),
    KC_TRANSPARENT, KC_TRANSPARENT, AU_ON,          AU_OFF,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, QK_BOOT,
    KC_TRANSPARENT, AC_TOGG, QK_MUSIC_ON,          QK_MUSIC_OFF,         QK_MUSIC_TOGGLE,         QK_MUSIC_MODE_NEXT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, WEBUSB_PAIR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_TRANSPARENT, KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    KC_TRANSPARENT, EMAIL, EMAIL_SCHOOL, EMAIL_WORK, NAME, PHONE, KC_MS_ACCEL0,   KC_MS_BTN1,     KC_MS_BTN2,     KC_MS_ACCEL1,   KC_MS_ACCEL2,   KC_TRANSPARENT,
    KC_TRANSPARENT, HTML_FOLDABLE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_DVORAK] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_F,   KC_G,     KC_C,     KC_R,   KC_L,   KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D,     KC_H,     KC_T,       KC_N,    KC_S, KC_SLASH,
    KC_TRANSPARENT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B,  KC_M,  KC_W,    KC_V, KC_Z, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CTRL_TAB:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_TAB);
      } else {
        // We unregister ctrl when the layer is released (handled in
        // layer_state_set_user). This isn't perfect, because ctrl will be
        // applied to any other keys pressed while the layer is active after
        // pressing tab, but it's good enough for now.
        unregister_code(KC_TAB);
      }
      break;
    case EMAIL:
      if (record->event.pressed) {
        SEND_STRING("sieppertcalum@gmail.com");
      }
      break;
    case EMAIL_SCHOOL:
      if (record->event.pressed) {
        SEND_STRING("calum.sieppert@ucalgary.ca");
      }
      break;
    case EMAIL_WORK:
      if (record->event.pressed) {
        SEND_STRING("calum@mlabs.city");
      }
      break;
    case NAME:
      if (record->event.pressed) {
        SEND_STRING("Calum Sieppert");
      }
      break;
    case PHONE:
      if (record->event.pressed) {
        SEND_STRING("5874352258");
      }
      break;
    case HTML_FOLDABLE:
      if (record->event.pressed) {
        SEND_STRING("<details>\n<summary></summary>\n\n</details>");
      }
      break;
    case ALT_S_L:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("s")"l");
      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

// Note that these colours are in HSV, and the values need to be
// mapped to the range 0 to 255 because they're stored with a single
// byte. This link has some examples:
// https://github.com/qmk/qmk_firmware/blob/0379d1f59e58cefa18cdb72ba1b77507d1108ae6/quantum/color.h#L53
#define NULL_C {0,0,0}
#define MAIN_C {HSV_PURPLE} // Colour for the main characters/symbols
#define MAIN_BORDER_C {HSV_PURPLE} // Colour for the edges of the board, modifiers etc
#define MOVE_C {66,67,190} // Colour for movement keys, up/down etc
#define FUNC_C {152,115,172} // Colour for function/system function keys
#define AUDIO_C {10,117,208} // Colour for keyboard audio controls
#define LIGHT_C {28,104,235} // Colour for keyboard backlight controls
#define DANGER_C {0,245,245} // Colour for dangerous keyboard controls, eg reset
#define MUSIC_C {253,125,191} // Colour for keyboard music controls
#define KEYBRD_C {10,117,208} // Colour for keyboard specific controls, eg oryx key

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = {
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C
    },

    [1] = {
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, MAIN_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, FUNC_C, FUNC_C, NULL_C, NULL_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [2] = {
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MAIN_BORDER_C,
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, MAIN_C, NULL_C,
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [3] = {
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, NULL_C, NULL_C, FUNC_C, FUNC_C,
      NULL_C, NULL_C, AUDIO_C, AUDIO_C, NULL_C, NULL_C, NULL_C, LIGHT_C, LIGHT_C, LIGHT_C, NULL_C, DANGER_C,
      NULL_C, FUNC_C, MUSIC_C, MUSIC_C, MUSIC_C, MUSIC_C, NULL_C, LIGHT_C, LIGHT_C, LIGHT_C, NULL_C, KEYBRD_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [4] = {
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, MAIN_C, MAIN_C, MAIN_C, NULL_C, NULL_C,
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, MAIN_C, MAIN_C, MAIN_C, NULL_C, NULL_C,
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, MAIN_C, MAIN_C, MAIN_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MAIN_C, NULL_C, NULL_C, NULL_C
    },

    [5] = {
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, FUNC_C, MAIN_BORDER_C, MAIN_BORDER_C, FUNC_C, FUNC_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MUSIC_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [6] = {
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, NULL_C, MAIN_BORDER_C, MUSIC_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C
    },
};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        // Limit the brightness based on the current config (changeable by keybinds)
        if (hsv.v > rgb_matrix_get_val()) {
          hsv.v = rgb_matrix_get_val();
        }
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  if (!rgb_matrix_is_enabled()) {
    rgb_matrix_set_color_all(0, 0, 0);
    return true;
  }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    // Using & here checks that ctrl is one of the modifiers active. This code
    // is to support my custom CTRL_TAB key in the lower layer, which acts like
    // the ctrl key is being held while I'm holding the layer key.
    if (!layer_state_cmp(state, _LOWER) && (get_mods() & MOD_BIT(KC_LCTL))) {
      unregister_code(KC_LCTL);
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
    }
    if(state->count > 3) {
        tap_code16(KC_APPLICATION);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: layer_move(5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_APPLICATION); register_code16(KC_APPLICATION);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: layer_off(5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(RCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
    switch (dance_state[2].step) {
    case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    case SINGLE_HOLD: unregister_code16(RCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
  [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
  [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
  [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
