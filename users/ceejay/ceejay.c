
/* Copyright 2021 Jonavin Eng @Jonavin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H
#include "ceejay.h"


#ifdef TD_LSFT_CAPSLOCK_ENABLE
  // Tap once for shift, twice for Caps Lock but only if Win Key in not disabled
    void dance_LSFT_finished(qk_tap_dance_state_t *state, void *user_data) {
        if (state->count == 1 || keymap_config.no_gui) {
            register_code16(KC_LSFT);
        } else {
            register_code(KC_CAPS);
        }
    }

    void dance_LSFT_reset(qk_tap_dance_state_t *state, void *user_data) {
        if (state->count == 1 || keymap_config.no_gui) {
            unregister_code16(KC_LSFT);
        } else {
            unregister_code(KC_CAPS);
        }
    }

    qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for shift, twice for Caps Lock
        [TD_LSFT_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
        [TD_LSFT_CAPS_WIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LSFT_finished, dance_LSFT_reset),
    };
#endif  // TD_LSFT_CAPSLOCK_ENABLE

// TIMEOUTS
#ifdef IDLE_TIMEOUT_ENABLE
    static uint16_t timeout_timer = 0;
    static uint16_t timeout_counter = 0;  //in minute intervals
    static uint16_t timeout_threshold = TIMEOUT_THRESHOLD_DEFAULT;
    static bool rgb_manual_toggle = true;

    uint16_t get_timeout_threshold(void) {
        return timeout_threshold;
    }

    void timeout_reset_timer(void) {
        timeout_timer = timer_read();
        timeout_counter = 0;
    };

    void timeout_update_threshold(bool increase) {
        if (increase && timeout_threshold < TIMEOUT_THRESHOLD_MAX) timeout_threshold++;
        if (!increase && timeout_threshold > 0) timeout_threshold--;
    };

    void timeout_tick_timer(void) {
        if (timeout_threshold > 0) {
            if (timer_elapsed(timeout_timer) >= 60000) { // 1 minute tick
                timeout_counter++;
                timeout_timer = timer_read();
            }
            #ifdef RGB_MATRIX_ENABLE
                if (timeout_threshold > 0 && timeout_counter >= timeout_threshold && rgb_manual_toggle) {
                    rgb_matrix_disable_noeeprom();
                }
            #endif
        } // timeout_threshold = 0 will disable timeout
    }

    __attribute__((weak)) void matrix_scan_keymap(void) {}

    void matrix_scan_user(void) {
        timeout_tick_timer();
        matrix_scan_keymap();
    }
#endif // IDLE_TIMEOUT_ENABLE


#if defined(ENCODER_ENABLE) && defined(ENCODER_DEFAULTACTIONS_ENABLE)       // Encoder Functionality
    #ifndef DYNAMIC_KEYMAP_LAYER_COUNT
        #define DYNAMIC_KEYMAP_LAYER_COUNT 4  //default in case this is not already defined elsewhere
    #endif
    #ifndef ENCODER_DEFAULTACTIONS_INDEX
        #define ENCODER_DEFAULTACTIONS_INDEX 0  // can select encoder index if there are multiple encoders
    #endif

uint8_t selected_layer = 0;

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) { return true; }

void change_brightness(bool clockwise) {
    uint8_t default_layer = biton32(default_layer_state);

    if (default_layer == _WIN) {
        tap_code16(SGUI(clockwise ? KC_PLUS : KC_MINUS)); // WIN + SHIFT + =/- (custom Windows hotkey)
    } else {
        tap_code16(clockwise ? KC_BRIU : KC_BRID); // Brightness Up/Down
    }
}

void change_volume(bool clockwise) {
    tap_code16(clockwise ? KC_VOLU : KC_VOLD);
}

// This function defines logic for the rotary knob
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) { return false; }
    if (index != ENCODER_DEFAULTACTIONS_INDEX) {return true;}  // exit if the index doesn't match


    switch(get_highest_layer(layer_state)){
        case _FNMAC:
        case _FNWIN:
                change_brightness(clockwise);
            break;
        case _CONFIG:
            #ifdef IDLE_TIMEOUT_ENABLE
                timeout_update_threshold(clockwise); // Increase timeout
            #else
                change_brightness(clockwise);
            #endif
            break;
        default:
            change_volume(clockwise);
            break;
    }

    return false;
}

#endif // ENCODER_ENABLE


// PROCESS KEY CODES
__attribute__ ((weak))  bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

uint8_t next_mac_layer(void) {
    switch (biton32(default_layer_state)) {
        case _MAC1:
            return _MAC2;
        case _MAC2:
            return _MAC3;
        default:
            return _MAC1;
    }
}

// Custom keycodes handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) { 
        return false; 
    }

    switch (keycode) {
        case KC_00:
            if (record->event.pressed) {
                // when keycode KC_00 is pressed
                SEND_STRING("00");
            } else {
                unregister_code16(keycode);
            }
            break;
        case KC_WINLCK:
            if (record->event.pressed) {
                keymap_config.no_gui = !keymap_config.no_gui; //toggle status
            } else {
                unregister_code16(keycode);
            }
            break;

        #ifdef IDLE_TIMEOUT_ENABLE
        case RGB_TOI:
            if(record->event.pressed) {
                timeout_update_threshold(true);
            } else {
                unregister_code16(keycode);
            }
            break;
        case RGB_TOD:
            if(record->event.pressed) {
                timeout_update_threshold(false);  //decrease timeout
            } else {
                unregister_code16(keycode);
            }
            break;
        case RGB_TOG:
            if(record->event.pressed) {
                rgb_manual_toggle = !rgblight_is_enabled();
            }
        break;
        #endif // IDLE_TIMEOUT_ENABLE
        case LAY_WIN:
            if(record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            } else {
                unregister_code16(keycode);
            }
            break;
        case LAY_MAC:
            if(record->event.pressed) {
                set_single_persistent_default_layer(next_mac_layer());
            } else {
                unregister_code16(keycode);
            }
            break;
        default:
            if (record->event.pressed) {
                #ifdef IDLE_TIMEOUT_ENABLE
                    if(rgb_manual_toggle) {
                        rgblight_enable();
                    }
                    timeout_reset_timer();  //reset activity timer
                #endif
            }
            break;
    }
    return true;
};


// Turn on/off NUM LOCK if current state is different
void activate_numlock(bool turn_on) {
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK) != turn_on) {
        tap_code(KC_NUMLOCK);
    }
}


// INITIAL STARTUP

__attribute__ ((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
    #ifdef STARTUP_NUMLOCK_ON
        activate_numlock(true); // turn on Num lock by default so that the numpad layer always has predictable results
    #endif // STARTUP_NUMLOC_ON
    #ifdef IDLE_TIMEOUT_ENABLE
        timeout_timer = timer_read(); // set inital time for ide timeout
    #endif
}

bool is_default_layer(uint8_t layer) {
    return biton32(default_layer_state) == layer;
}

bool is_macos_layer(void) {
    return !is_windows_layer();
}

bool is_windows_layer(void) {
    return is_default_layer(_WIN);
}