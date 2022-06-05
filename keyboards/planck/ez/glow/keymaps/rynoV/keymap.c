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
  RGB_SLD = EZ_SAFE_RANGE,
  EMAIL,
  EMAIL_SCHOOL,
  EMAIL_WORK,
  NAME,
  PHONE,
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
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSPACE,
    MT(MOD_LCTL, KC_ESCAPE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_LSPO,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       MT(MOD_RSFT, KC_ENTER),
    KC_MEH,         KC_HYPR,        KC_LGUI,        KC_LALT,        LOWER,          LT(4,KC_SPACE), KC_NO,          RAISE,          TD(DANCE_0),    DYN_MACRO_PLAY1,DYN_REC_START1, DYN_REC_STOP
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DELETE,
    KC_TRANSPARENT, KC_PIPE,        KC_UNDS,        KC_PLUS,        KC_LCBR,        KC_RCBR,        KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_TILD,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,
    KC_TRANSPARENT, KC_BSLASH,      KC_MINUS,       KC_EQUAL,       KC_LBRACKET,    KC_RBRACKET,    TD(DANCE_1),    KC_DOWN,        KC_UP,          TD(DANCE_2),    KC_GRAVE,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, AU_ON,          AU_OFF,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG,        RGB_VAD,        RGB_VAI,        KC_TRANSPARENT, RESET,
    KC_TRANSPARENT, KC_TRANSPARENT, MU_ON,          MU_OFF,         MU_MOD,         KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD,        RGB_HUI,        RGB_HUD,        KC_TRANSPARENT, WEBUSB_PAIR,
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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

// Note that these colours are in HSV
#define NULL_C {0,0,0}
#define MAIN_C {157,71,64} // Colour for the main characters/symbols
#define MAIN_BORDER_C {157,72,106} // Colour for the edges of the board, modifiers etc
#define MOVE_C {66,67,190} // Colour for movement keys, up/down etc
#define FUNC_C {152,115,172} // Colour for function/system function keys
#define AUDIO_C {10,117,208} // Colour for keyboard audio controls
#define LIGHT_C {28,104,235} // Colour for keyboard backlight controls
#define DANGER_C {0,245,245} // Colour for dangerous keyboard controls, eg reset
#define MUSIC_C {253,125,191} // Colour for keyboard music controls
#define KEYBRD_C {10,117,208} // Colour for keyboard specific controls, eg oryx key

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = {
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C,
      MAIN_BORDER_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, NULL_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C, MAIN_BORDER_C
    },

    [1] = {
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_BORDER_C,
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, MAIN_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [2] = {
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, MAIN_BORDER_C,
      NULL_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MAIN_C, MOVE_C, MOVE_C, MOVE_C, MOVE_C, MAIN_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C,
      NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C, NULL_C
    },

    [3] = {
      NULL_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, FUNC_C, NULL_C, NULL_C, NULL_C, NULL_C, FUNC_C, NULL_C,
      NULL_C, NULL_C, AUDIO_C, AUDIO_C, NULL_C, NULL_C, NULL_C, LIGHT_C, LIGHT_C, LIGHT_C, NULL_C, DANGER_C,
      NULL_C, NULL_C, MUSIC_C, MUSIC_C, MUSIC_C, NULL_C, NULL_C, LIGHT_C, LIGHT_C, LIGHT_C, NULL_C, KEYBRD_C,
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
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
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

uint32_t layer_state_set_user(uint32_t state) {
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

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
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


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
        tap_code16(KC_APPLICATION);
    }
    if(state->count > 3) {
        tap_code16(KC_APPLICATION);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: layer_on(5); break;
        case DOUBLE_TAP: layer_move(5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_APPLICATION); register_code16(KC_APPLICATION);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
        case SINGLE_HOLD: layer_off(5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_APPLICATION); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(KC_LEFT); register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
        tap_code16(KC_RIGHT);
    }
    if(state->count > 3) {
        tap_code16(KC_RIGHT);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_RIGHT); break;
        case SINGLE_HOLD: register_code16(RCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: register_code16(KC_RIGHT); register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RIGHT); register_code16(KC_RIGHT);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_RIGHT); break;
        case SINGLE_HOLD: unregister_code16(RCTL(KC_RIGHT)); break;
        case DOUBLE_TAP: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RIGHT); break;
    }
    dance_state[2].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
