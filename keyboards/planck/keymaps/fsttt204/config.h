#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND) \
                                    }

    #define DAC_SAMPLE_MAX 7000U

    #define MUSICS(n) MUSIC_##n
    #define MUSICS_SIZE 6

    #define MUSIC_0 SONG(ODE_TO_JOY)
    #define MUSIC_1 SONG(ROCK_A_BYE_BABY)
    #define MUSIC_2 SONG(CAMPANELLA)
    #define MUSIC_3 SONG(FANTASIE_IMPROMPTU)
    #define MUSIC_4 SONG(NOCTURNE_OP_9_NO_1)
    #define MUSIC_5 SONG(USSR_ANTHEM)

    #define AUDIO_CLICKY
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#ifdef RGB_DI_PIN
  #ifndef IOS_DEVICE_ENABLE
    #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
    #define RGBLIGHT_VAL_STEP 8
  #else
    #define RGBLIGHT_LIMIT_VAL 50
    #define RGBLIGHT_VAL_STEP 4
  #endif
#endif

#if defined(RGBLIGHT_ENABLE) && !defined(IOS_DEVICE_ENABLE)
// USB_MAX_POWER_CONSUMPTION value for treadstone32 keyboard
//  50  RGBoff
//  450  RGB 9
  #define USB_MAX_POWER_CONSUMPTION 500
#else
  // fix iPhone and iPad power adapter issue
  // iOS device need lessthan 100
  #define USB_MAX_POWER_CONSUMPTION 100
#endif
