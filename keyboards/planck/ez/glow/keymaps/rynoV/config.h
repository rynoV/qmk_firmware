#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef IGNORE_MOD_TAP_INTERRUPT

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 900000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 200

#define HOLD_ON_OTHER_KEY_PRESS
#define FIRMWARE_VERSION u8"BzKJQ/ADDyo"
#define RGB_MATRIX_STARTUP_SPD 60

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
