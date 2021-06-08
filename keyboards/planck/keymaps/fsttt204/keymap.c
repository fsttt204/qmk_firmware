#include QMK_KEYBOARD_H
#include "muse.h"
#include "rgblight.h"

enum planck_layers { _QWERTY, _LOWER, _RAISE, _ADJUST, _MEDIA };

enum planck_keycodes { QWERTY = SAFE_RANGE, BACKLIT, SONG_UP, SONG_DOWN, SONG_PLAY, SONG_STOP};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define DF_MEDIA DF(_MEDIA)
#define DF_QWERTY DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * | Esc/~|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SftEnt|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Knob | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT,
        DF_MEDIA, KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -/_ |  =/+ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |  [/{ |  ]/} |  \/| |  Ent |
     * |------+------+------+------+------+------+------+------+------+------ +------+------|
     * |      | HANJ |      |  HAN |      |    Space    |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_ENT,
        KC_TRNS, KC_HANJ, KC_TRNS, KC_HAEN, KC_TRNS, KC_SPC, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * | `/~  |      |      |      |      |      |      | PGUP |  UP  | PGDN | INS  |  DEL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Caps |      |      |      |      |      | HOME | LEFT | DOWN |RIGHT |  -/_ |  =/+ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |  END |      | PRSC | SLCK | PAUS |  Ent |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    Space    |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_UP, KC_PGDN, KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_SPC, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    ),

    /* Adjust (Lower + Raise)
     * ,-----------------------------------------------------------------------------------.
     * | Reset|RGB_TO|AU_TOG|MU_TOG|CK_TOG|      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Debug|RGB_VI|      |Voice+| CK_UP|      |      |      |      |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | RGB_T|RGB_VD|      |Voice-|CK_DWN|      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |RGB_MO|      |MU_MOD|      |             |      |SNG_ST|SNG_DW|SNG_UP|SNG_PL|
     * `-----------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        RESET, RGB_TOG, AU_TOG, MU_TOG, CK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DEBUG, RGB_VAI, KC_TRNS, MUV_IN, CK_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_M_T, RGB_VAD, KC_TRNS, MUV_DE, CK_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_MOD, KC_TRNS, MU_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SONG_STOP, SONG_DOWN, SONG_UP, SONG_PLAY
    ),

    /* Media
     * ,-----------------------------------------------------------------------------------.
     * |      | MS_1 | MS_U | MS_2 |      |      |      | PGUP |  UP  | PGDN | INS  |  DEL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | MS_L | MS_D | MS_R |      |      | HOME | LEFT | DOWN |RIGHT |  -/_ |  =/+ |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | MS_A0| MS_A1| MS_A2|      |      |  END |      | PRSC | SLCK | PAUS |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_MEDIA] = LAYOUT_planck_grid(
        KC_NO, KC_MS_BTN1, KC_MS_U, KC_MS_BTN2, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_INS, KC_DEL,
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,
        KC_NO, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_NO, KC_NO, KC_END, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS,
        DF_QWERTY, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
    )
};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);

void playMusic(uint8_t number);
#endif

void custom_tap_code(uint8_t code);

uint8_t last_music_count = 0;
bool music_play = false;

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void matrix_init_user(void) {
    last_music_count = 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
#ifdef AUDIO_ENABLE
        case SONG_STOP:
            if (record->event.pressed){
                music_play = false;
                stop_all_notes();
                return false;
            }
            break;
        case SONG_DOWN:
            if (record->event.pressed){
                stop_all_notes();
                last_music_count++;
                last_music_count %= MUSICS_SIZE;
                if(music_play) {
                    playMusic(last_music_count);
                }
                return false;
            }
            break;
        case SONG_UP:
            if (record->event.pressed){
                stop_all_notes();
                last_music_count = last_music_count == 0 ? MUSICS_SIZE - 1 : last_music_count - 1;
                if(music_play) {
                    playMusic(last_music_count);
                }
                return false;
            }
            break;
        case SONG_PLAY:
            if (record->event.pressed){
                music_play = true;
                stop_all_notes();
                playMusic(last_music_count);
                return false;
            }
            break;
        case KC_GESC:
            if (record->event.pressed) {
                stop_all_notes();
            }
        break;
#endif
    }
    return true;
}


#ifdef AUDIO_ENABLE
void playMusic(uint8_t number){
    switch(number) {
        case 1:
        {
            float song[][2] = MUSICS(1);
            PLAY_SONG(song);
        }
        break;
        case 2:
        {
            float song[][2] = MUSICS(2);
            PLAY_SONG(song);
        }
        break;
        case 3:
        {
            float song[][2] = MUSICS(3);
            PLAY_SONG(song);
        }
        break;
        case 4:
        {
            float song[][2] = MUSICS(4);
            PLAY_SONG(song);
        }
        break;
        case 5:
        {
            float song[][2] = MUSICS(5);
            PLAY_SONG(song);
        }
        break;
        default:
        {
            float song[][2] = MUSICS(0);
            PLAY_SONG(song);
        }
    }
}
#endif

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

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
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (IS_LAYER_ON(_LOWER)) {
            if (clockwise) {
                custom_tap_code(KC_VOLU);
            } else {
                custom_tap_code(KC_VOLD);
            }
        } else if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                custom_tap_code(KC_BRIU);
            } else {
                custom_tap_code(KC_BRID);
            }
        } else {
            if (clockwise) {
#ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_UP);
#else
                tap_code(KC_PGUP);
#endif
            } else {
#ifdef MOUSEKEY_ENABLE
                tap_code(KC_MS_WH_DOWN);
#else
                tap_code(KC_PGDN);
#endif
            }
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
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

void custom_tap_code(uint8_t code) {
    register_code(code);
    if (code == KC_CAPS) {
        wait_ms(80);
    } else {
        wait_ms(10);
    }
    unregister_code(code);
}
