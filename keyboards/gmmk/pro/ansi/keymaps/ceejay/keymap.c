/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2021 Jonavin

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
#include "rgb_matrix_map.h"
#include "ceejay.h"

#define SCR_APP S(G(KC_5))    // macOS: opens Screenshot app (shift+cmd+5)
#define SCR_SEL C(S(G(KC_4))) // macOS: screenshot by rectangular selection, saved to clipboard (ctrl+shift+cmd+4)
#define LOK_WIN G(KC_L)       // Windows: lock screen (win+L)
#define LOK_MAC C(G(KC_Q))    // macOS: lock screen (ctrl+cmd+Q)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Play/Pause)
//      `        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    [_WIN] = LAYOUT(
        LT(_CONFIG, KC_ESC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,          KC_INS,
        CTL_T(KC_CAPS),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_PAUSE,
        KC_LSFT,                       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,              KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FNWIN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC1] = LAYOUT(
        LT(_CONFIG, KC_ESC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,          KC_PGUP,
        CTL_T(KC_CAPS),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_PGDN,
        KC_LSFT,                       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
        KC_LCTL,              KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(_FNMAC), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC2] = LAYOUT(
        LT(_CONFIG, KC_ESC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,          KC_PGUP,
        CTL_T(KC_CAPS),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_PGDN,
        KC_LSFT,                       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
        KC_LGUI,              KC_LCTL, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FNMAC), KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_MAC3] = LAYOUT(
        LT(_CONFIG, KC_ESC),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,               KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,               KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS,          KC_PGUP,
        CTL_T(KC_CAPS),       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_PGDN,
        KC_LSFT,                       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,   KC_END,
        KC_LGUI,              KC_LALT, KC_LCTL,                            KC_SPC,                             KC_RCTL, MO(_FNMAC), KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FNWIN] = LAYOUT(
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_CALC, KC_PSCR,           KC_MSTP,
        KC_SLCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_MNXT,
        KC_NLCK, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_PGUP,
        _______, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, LOK_WIN, _______, _______,          _______,           KC_PGDN,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD,  KC_MPRV,
        _______, KC_WINLCK, _______,                          _______,                            _______, _______, _______, RGB_HUD, RGB_RMOD, RGB_HUI
    ),

    [_FNMAC] = LAYOUT(
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SCR_APP, SCR_SEL,           KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_MNXT,
        _______, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, LOK_MAC, _______, _______,          _______,           _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD,  KC_MPRV,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_HUD, RGB_RMOD, RGB_HUI
    ),

    [_CONFIG] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_WAKE,
        _______, _______, LAY_WIN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_SLEP,
        _______,          _______, _______, _______, _______, _______, _______, LAY_MAC, RGB_TOD, RGB_TOI, _______,          _______, _______, KC_PWR,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    )
};


#ifdef RGB_MATRIX_ENABLE
    // Active default layer color
    #define RGB_ACTIVE RGB_RED
    // Hint color (i.e. for FN/CONFIG keys bound to something)
    #define RGB_HINT RGB_WHITE
    // Reset button color
    #define RGB_RESET RGB_ORANGE
    // Layer side lighting color
    #define RGB_LAYER RGB_RED
    // Num/Scroll/Caps/Win lock color
    #define RGB_LOCK RGB_RED

    // Color that highlights the position of the CTRL keys
    #define RGB_CTL RGB_GREEN
    // Color that highlights the position of the GUI (WIN/CMD) keys
    #define RGB_GUI RGB_BLUE
    // Color that highlights the position of the ALT/OPTION keys
    #define RGB_ALT RGB_YELLOW

    void rgb_show_default_layer(void) {
        switch(biton32(default_layer_state)) {
            case _WIN:
                rgb_matrix_set_color(LED_W, RGB_ACTIVE);
                #ifdef ENABLE_RGB_HINTS
                rgb_matrix_set_color(LED_M, RGB_HINT);
                rgb_matrix_set_color(LED_CAPS, RGB_CTL);
                rgb_matrix_set_color(LED_LCTL, RGB_CTL);
                rgb_matrix_set_color(LED_LWIN, RGB_GUI);
                rgb_matrix_set_color(LED_LALT, RGB_ALT);
                rgb_matrix_set_color(LED_RALT, RGB_ALT);
                rgb_matrix_set_color(LED_RCTL, RGB_CTL);
                #endif
                break;
            case _MAC1:
                rgb_matrix_set_color(LED_M, RGB_ACTIVE);
                #ifdef ENABLE_RGB_HINTS
                rgb_matrix_set_color(LED_W, RGB_HINT);
                rgb_matrix_set_color(LED_CAPS, RGB_CTL);
                rgb_matrix_set_color(LED_LCTL, RGB_CTL);
                rgb_matrix_set_color(LED_LWIN, RGB_ALT);
                rgb_matrix_set_color(LED_LALT, RGB_GUI);
                rgb_matrix_set_color(LED_RALT, RGB_GUI);
                rgb_matrix_set_color(LED_RCTL, RGB_CTL);
                #endif
                break;
            case _MAC2:
                rgb_matrix_set_color(LED_M, RGB_ACTIVE);
                rgb_matrix_set_color(LED_N, RGB_ACTIVE);
                #ifdef ENABLE_RGB_HINTS
                rgb_matrix_set_color(LED_W, RGB_HINT);
                rgb_matrix_set_color(LED_CAPS, RGB_CTL);
                rgb_matrix_set_color(LED_LCTL, RGB_GUI);
                rgb_matrix_set_color(LED_LWIN, RGB_CTL);
                rgb_matrix_set_color(LED_LALT, RGB_ALT);
                rgb_matrix_set_color(LED_RALT, RGB_ALT);
                rgb_matrix_set_color(LED_RCTL, RGB_GUI);
                #endif
                break;
            case _MAC3:
                rgb_matrix_set_color(LED_M, RGB_ACTIVE);
                rgb_matrix_set_color(LED_N, RGB_ACTIVE);
                rgb_matrix_set_color(LED_B, RGB_ACTIVE);
                #ifdef ENABLE_RGB_HINTS
                rgb_matrix_set_color(LED_W, RGB_HINT);
                rgb_matrix_set_color(LED_CAPS, RGB_CTL);
                rgb_matrix_set_color(LED_LCTL, RGB_GUI);
                rgb_matrix_set_color(LED_LWIN, RGB_ALT);
                rgb_matrix_set_color(LED_LALT, RGB_CTL);
                rgb_matrix_set_color(LED_RALT, RGB_CTL);
                rgb_matrix_set_color(LED_RCTL, RGB_GUI);
                #endif
                break;
        }
    }

    #ifdef ENABLE_RGB_HINTS
    void rgb_show_config_hints(uint8_t r, uint8_t g, uint8_t b) {
        rgb_matrix_set_color(LED_HOME, r, g, b);
        rgb_matrix_set_color(LED_PGUP, r, g, b);
        rgb_matrix_set_color(LED_PGDN, r, g, b);
        rgb_matrix_set_color(LED_END, r, g, b);
        rgb_matrix_set_color(LED_COMM, r, g, b);
        rgb_matrix_set_color(LED_DOT, r, g, b);
    }

    void rgb_show_common_fn_hints(uint8_t r, uint8_t g, uint8_t b) {
        rgb_matrix_set_color(LED_ESC, r, g, b);
        rgb_matrix_set_color(LED_GRV, r, g, b);
        rgb_matrix_set_color(LED_TAB, r, g, b);
        rgb_matrix_set_color(LED_Q, r, g, b);
        rgb_matrix_set_color(LED_W, r, g, b);
        rgb_matrix_set_color(LED_E, r, g, b);
        rgb_matrix_set_color(LED_A, r, g, b);
        rgb_matrix_set_color(LED_S, r, g, b);
        rgb_matrix_set_color(LED_D, r, g, b);
        rgb_matrix_set_color(LED_N, r, g, b);
        rgb_matrix_set_color(LED_L, r, g, b);
        rgb_matrix_set_color(LED_F12, r, g, b);
        rgb_matrix_set_color(LED_DEL, r, g, b);
        rgb_matrix_set_color(LED_UP, r, g, b);
        rgb_matrix_set_color(LED_DOWN, r, g, b);
        rgb_matrix_set_color(LED_LEFT, r, g, b);
        rgb_matrix_set_color(LED_RIGHT, r, g, b);
        rgb_matrix_set_color(LED_END, r, g, b);
        rgb_matrix_set_color(LED_HOME, r, g, b);
    }
    #endif

    #ifdef IDLE_TIMEOUT_ENABLE
    void rbg_show_timeout(void) {
        // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row;  larger numbers using 16bit code
        uint16_t timeout_threshold = get_timeout_threshold();
        if (timeout_threshold <= 10) rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_RED);
        else if (timeout_threshold < 140) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_RED);
            rgb_matrix_set_color(LED_LIST_NUMROW[(timeout_threshold % 10)], RGB_RED);
        } else { // >= 140 minutes, just show these 3 lights
            rgb_matrix_set_color(LED_LIST_NUMROW[10], RGB_RED);
            rgb_matrix_set_color(LED_LIST_NUMROW[11], RGB_RED);
            rgb_matrix_set_color(LED_LIST_NUMROW[12], RGB_RED);
        }
    }
    #endif

    // Capslock, Scroll lock and Numlock  indicator on Left side lights.
    void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        if (is_windows_layer() && IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
            rgb_matrix_set_color(LED_L1, RGB_LOCK);
            rgb_matrix_set_color(LED_L2, RGB_LOCK);
        }
        if (is_windows_layer() && !IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {   // on if NUM lock is OFF
            rgb_matrix_set_color(LED_L3, RGB_LOCK);
            rgb_matrix_set_color(LED_L4, RGB_LOCK);
        }
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
            if (is_macos_layer()) {
                rgb_matrix_set_color(LED_L1, RGB_LOCK);
                rgb_matrix_set_color(LED_L2, RGB_LOCK);
                rgb_matrix_set_color(LED_L3, RGB_LOCK);
                rgb_matrix_set_color(LED_L4, RGB_LOCK);
            }
            rgb_matrix_set_color(LED_L5, RGB_LOCK);
            rgb_matrix_set_color(LED_L6, RGB_LOCK);
            rgb_matrix_set_color(LED_L7, RGB_LOCK);
            rgb_matrix_set_color(LED_L8, RGB_LOCK);
        }
        if (is_windows_layer() && keymap_config.no_gui) {
            rgb_matrix_set_color(LED_LWIN, RGB_LOCK);  //light up Win key when disabled
        }
        switch(get_highest_layer(layer_state)) {
            case _FNWIN:
                #ifdef ENABLE_RGB_HINTS
                rgb_matrix_set_color(LED_LWIN, RGB_HINT);
                rgb_matrix_set_color(LED_PGDN, RGB_HINT);
                rgb_matrix_set_color(LED_PGUP, RGB_HINT);
                #endif
                // passthrough intended
            case _FNMAC:
                rgb_matrix_set_color(LED_R2, RGB_LAYER);
                rgb_matrix_set_color(LED_R3, RGB_LAYER);
                rgb_matrix_set_color(LED_R4, RGB_LAYER);
                rgb_matrix_set_color(LED_FN, RGB_LAYER); //FN key

                #ifdef ENABLE_RGB_HINTS
                rgb_show_common_fn_hints(RGB_HINT);
                #endif
            break;
            case _CONFIG:
                rgb_matrix_set_color(LED_R4, RGB_LAYER);
                rgb_matrix_set_color(LED_R5, RGB_LAYER);
                rgb_matrix_set_color(LED_R6, RGB_LAYER);

                #ifdef ENABLE_RGB_HINTS
                rgb_show_config_hints(RGB_HINT);
                rgb_matrix_set_color(LED_BSLS, RGB_RESET);
                #endif

                rgb_show_default_layer();

                #ifdef IDLE_TIMEOUT_ENABLE
                rbg_show_timeout();
                #endif
            break;
        }
    }

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }
#endif
