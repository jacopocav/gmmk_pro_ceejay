/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
   Copyright 2022 Andre Brait <andrebrait@gmail.com>

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

enum layers {
    WIN_BASE = 0,
    WIN_FN,
    MAC_BASE,
    MAC_FN
};

#define KC_TASK LWIN(KC_TAB)            // Open Task Manager
#define KC_FLXP LWIN(KC_E)              // Open File Explorer
#define DF_WINB DF(WIN_BASE)            // Switch to WIN_BASE layer
#define MO_WINF MO(WIN_FN)              // Toggle to WIN_FN layer
#define DF_MACB DF(MAC_BASE)            // Switch to MAX_BASE layer
#define MO_MACF MO(MAC_FN)              // Toggle to MAC_FN layer

#define WIN_BRU S(G(KC_EQL))             // Windows Brightness Up (win+shift+=)
#define WIN_BRD S(G(KC_MINS))            // Windows Brightness Down (win+shift+-)
#define WIN_LCK G(KC_L)                  // Windows Lockscreen (win+l)
#define MAC_LCK C(G(KC_Q))               // MacOS Lockscreen (ctrl+cmd+q)
#define MAC_SCR C(S(G(KC_4)))            // MacOS Screenshot (ctrl+cmd+shift+4)
#define CTLCAPS CTL_T(KC_CAPS)           // Caps Lock when tapped, LCtrl when held


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// The GMMK Pro default layout is:
//
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del          Rotary(Play/Pause)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    //
    // RGB and function keys are inspired by the Keychron Q1 layouts instead of using the default keys.
    // To clean the EEPROM, hold the ESC key while connecting the keyboard.

    [WIN_BASE] = LAYOUT(
        KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MPLY,
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_INS,
        CTLCAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PAUS,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT, MO_WINF, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WIN_FN] = LAYOUT(
        RGB_TOG, WIN_BRD,  WIN_BRU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR,          _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  EE_CLR,          _______,
        _______, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_PGUP,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, WIN_LCK, _______, _______,          _______,          KC_PGDN,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, DF_MACB, _______, _______, _______,          _______, KC_VOLU, KC_PWR,
        _______, _______,  _______,                            KC_MPLY,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [MAC_BASE] = LAYOUT(
        KC_ESC,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        CTLCAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCMD, KC_LCTL,  KC_LOPT,                            KC_SPC,                             KC_ROPT, MO_MACF, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT(
        RGB_TOG, KC_BRID,  KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, MAC_SCR,          _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  EE_CLR,          _______,
        _______, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          _______,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, MAC_LCK, _______, _______,          _______,          _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, DF_WINB, _______, _______, _______,          _______, KC_VOLU, KC_PWR,
        _______, _______,  _______,                            KC_MPLY,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    )
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_BASE] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN] =      { ENCODER_CCW_CW(WIN_BRD, WIN_BRU) },
    [MAC_BASE] =    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN] =      { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
};
#endif

/* To record user preferences */
typedef union {
    uint32_t raw;                           // set to 32-bit of size
    struct {
        bool rgb_enabled            :1;     // Artificial RGB ON/OFF flag (1 bit)
    };
} user_config_t;
user_config_t user_config;

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#ifdef RGB_MATRIX_ENABLE

#define CAPS_LOCK_COLOR     RGB_RED
#define WIN_BASE_COLOR      RGB_BLUE
#define WIN_FN_COLOR        RGB_BLUE
#define MAC_BASE_COLOR      RGB_WHITE
#define MAC_FN_COLOR        RGB_WHITE
#define UNKNOWN_LAYER_COLOR RGB_PINK
#define IMPORTANT_KEY_COLOR RGB_RED

/* The maximum effects duration */
#ifndef EFFECTS_DURATION
    #define EFFECTS_DURATION 1000
#endif
#if EFFECTS_DURATION <= 0 || EFFECTS_DURATION >= UINT16_MAX / 2
    #error "EFFECTS_DURATION must be a positive integer smaller than UINT16_MAX / 2"
#endif
/* The interval for the flashing effect */
#ifndef FLASHING_EFFECT_INTERVAL
    #define FLASHING_EFFECT_INTERVAL 250
#endif
#if FLASHING_EFFECT_INTERVAL <= 0 || FLASHING_EFFECT_INTERVAL >= UINT16_MAX / 2
    #error "FLASHING_EFFECT_INTERVAL must be a positive integer smaller than UINT16_MAX / 2"
#endif

static void set_rgb_layer_winfn(void);
static void set_rgb_layer_macfn(void);
static void set_rgb_caps_lock(void);

/* Effects functions */
static float flashing_effect(const uint16_t delta_time);
static float static_effect(const uint16_t delta_time);

/* Effect variables and functions */
static uint16_t effect_started_time = 0;
static uint16_t effect_max_duration = EFFECTS_DURATION;
static uint8_t effect_r = 0x0, effect_g = 0x0, effect_b = 0x0;
static float (*effect_multiplier)(const uint16_t) = static_effect;
static void start_effects(
        const uint16_t max_duration,
        const uint8_t r_color,
        const uint8_t g_color,
        const uint8_t b_color,
        const float (*multiplier)(const uint16_t));
static void stop_effects(void);

#endif // RGB_MATRIX_ENABLE

void eeconfig_init_user(void) {                 // EEPROM is getting reset!
    user_config.raw = 0;
    user_config.rgb_enabled = true;             // We want this enabled by default
    eeconfig_update_user(user_config.raw);      // Write default value to EEPROM now
}

void keyboard_post_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
    // Enable the RGB matrix, if not enabled
    if (!rgb_matrix_is_enabled()) {
        rgb_matrix_enable();
    }
    // Set the flags to ALL, if not already set
    if (rgb_matrix_get_flags() != LED_FLAG_ALL) {
        rgb_matrix_set_flags(LED_FLAG_ALL);
    }
    #endif

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            if (record->event.pressed) {
                /* Set the default layout on the EEPROM, let the default layer change callback handle the rest */
                set_single_persistent_default_layer(QK_DEF_LAYER_GET_LAYER(keycode));
            }
            return false;
        #ifdef RGB_MATRIX_ENABLE
        #ifdef NKRO_ENABLE
        case NK_TOGG:
            if (record->event.pressed) {
                if (keymap_config.nkro) {
                    /* Turning NKRO OFF */
                    start_effects(EFFECTS_DURATION, RGB_RED, flashing_effect);
                } else {
                    /* Turning NKRO ON */
                    start_effects(EFFECTS_DURATION, RGB_GREEN, flashing_effect);
                }
            }
            break;
        #endif // NKRO_ENABLE
        case RGB_MOD:
        case RGB_RMOD:
        case RGB_HUI:
        case RGB_HUD:
        case RGB_SAI:
        case RGB_SAD:
        case RGB_VAI:
        case RGB_VAD:
        case RGB_SPI:
        case RGB_SPD:
            if (!user_config.rgb_enabled) {
                /* Ignore changes to RGB settings while only it's supposed to be OFF */
                return false;  // Skip all further processing of this key
            }
            break;
        case RGB_TOG:
            if (record->event.pressed) {
                user_config.rgb_enabled = !user_config.rgb_enabled;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        #endif // RGB_MATRIX_ENABLE
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE

/*
Effects when switching layers
*/

static uint8_t previous_layer = UINT8_MAX;

layer_state_t default_layer_state_set_user(layer_state_t state) {
    const uint8_t current_layer = get_highest_layer(state);
    if (previous_layer != current_layer) {
        // For some reason, setting the default layer alone doesn't change it fully
        layer_move(current_layer);
        switch (current_layer) {
            case WIN_BASE:
                start_effects(EFFECTS_DURATION, WIN_BASE_COLOR, flashing_effect);
                break;
            case MAC_BASE:
                start_effects(EFFECTS_DURATION, MAC_BASE_COLOR, flashing_effect);
                break;
            default:
                // This should not ever happen, but let's display something if it does!
                start_effects(EFFECTS_DURATION, UNKNOWN_LAYER_COLOR, static_effect);
                break;
        }
        previous_layer = current_layer;
    }
    return state;
}

static void start_effects(
        const uint16_t max_duration,
        const uint8_t r_color,
        const uint8_t g_color,
        const uint8_t b_color,
        const float (*multiplier)(const uint16_t)) {
    effect_r = r_color;
    effect_g = g_color;
    effect_b = b_color;
    effect_multiplier = multiplier;
    effect_max_duration = max_duration;
    effect_started_time = sync_timer_read();
}

static void stop_effects(void) {
    effect_r = 0x0;
    effect_g = 0x0;
    effect_b = 0x0;
    effect_multiplier = static_effect;
    effect_max_duration = EFFECTS_DURATION;
    effect_started_time = 0;
}

static float flashing_effect(const uint16_t delta_time) {
    return ((delta_time / FLASHING_EFFECT_INTERVAL) + 1) & 0x01;
}

static float static_effect(const uint16_t delta_time) {
    return 1.0;
}

bool rgb_matrix_indicators_user(void) {
    if (effect_started_time > 0) {
        const uint16_t delta_time = sync_timer_elapsed(effect_started_time);
        if (delta_time <= effect_max_duration) {
            /* Render effect */
            const float multiplier = effect_multiplier(delta_time);
            const uint8_t val_r = multiplier * effect_r;
            const uint8_t val_g = multiplier * effect_g;
            const uint8_t val_b = multiplier * effect_b;
            rgb_matrix_set_color_all(val_r, val_g, val_b);
            return false;
        } else {
            /* Effect duration is finished */
            stop_effects();
        }
    }
    if (host_keyboard_led_state().caps_lock) {
        set_rgb_caps_lock();
    } else if (!user_config.rgb_enabled) {
        rgb_matrix_set_color_all(RGB_OFF);
    }
    #ifdef ENABLE_RGB_HINTS
        switch (get_highest_layer(layer_state)) {
            case WIN_BASE:
            case MAC_BASE:
                break;
            case WIN_FN:
                set_rgb_layer_winfn();
                return false;
            case MAC_FN:
                set_rgb_layer_macfn();
                return false;
            default:
                // This should never happen, but if it does, let's display something!
                rgb_matrix_set_color_all(UNKNOWN_LAYER_COLOR);
                return false;
        }
    #endif // ENABLE_RGB_HINTS
    return true;
}

static void set_rgb_layer_winfn(void) {
    // switch to Mac
    rgb_matrix_set_color(LED_M, MAC_FN_COLOR);

    // function row
    rgb_matrix_set_color(LED_ESC, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F1, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F2, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F3, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F4, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F5, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F6, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F7, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F8, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F9, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F10, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F11, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F12, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_DEL, WIN_FN_COLOR);

    // RGB controls (Q/A, W/S, E/D, R/F)
    rgb_matrix_set_color(LED_Q, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_A, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_W, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_S, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_E, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_D, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_R, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_F, WIN_FN_COLOR);

    // N-key rollover
    rgb_matrix_set_color(LED_N, WIN_FN_COLOR);

    // Lockscreen
    rgb_matrix_set_color(LED_L, WIN_FN_COLOR);

    // PgUp/PgDn
    rgb_matrix_set_color(LED_PGUP, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_PGDN, WIN_FN_COLOR);

    // Clear EEPROM
    rgb_matrix_set_color(LED_BSPC, IMPORTANT_KEY_COLOR);
    // Bootloader
    rgb_matrix_set_color(LED_BSLS, IMPORTANT_KEY_COLOR);
    // Power off
    rgb_matrix_set_color(LED_END, IMPORTANT_KEY_COLOR);

    // Media controls
    rgb_matrix_set_color(LED_SPC, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_LEFT, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_UP, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_DOWN, WIN_FN_COLOR);
    rgb_matrix_set_color(LED_RIGHT, WIN_FN_COLOR);
}

static void set_rgb_layer_macfn(void) {
    // switch to Mac
    rgb_matrix_set_color(LED_M, WIN_FN_COLOR);

    // function row
    rgb_matrix_set_color(LED_ESC, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F1, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F2, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F3, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F4, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F5, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F6, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F7, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F8, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F9, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F10, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F11, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F12, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_DEL, MAC_FN_COLOR);

    // RGB controls (Q/A, W/S, E/D, R/F)
    rgb_matrix_set_color(LED_Q, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_A, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_W, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_S, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_E, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_D, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_R, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_F, MAC_FN_COLOR);

    // N-key rollover
    rgb_matrix_set_color(LED_N, MAC_FN_COLOR);

    // Lockscreen
    rgb_matrix_set_color(LED_L, MAC_FN_COLOR);

    // Media controls
    rgb_matrix_set_color(LED_SPC, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_LEFT, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_UP, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_DOWN, MAC_FN_COLOR);
    rgb_matrix_set_color(LED_RIGHT, MAC_FN_COLOR);

    // Clear EEPROM
    rgb_matrix_set_color(LED_BSPC, IMPORTANT_KEY_COLOR);
    // Bootloader
    rgb_matrix_set_color(LED_BSLS, IMPORTANT_KEY_COLOR);
    // Power off
    rgb_matrix_set_color(LED_END, IMPORTANT_KEY_COLOR);
}

static void set_rgb_caps_lock(void) {
    // caps LED
    rgb_matrix_set_color(LED_CAPS, CAPS_LOCK_COLOR);
    // left side LEDs
    rgb_matrix_set_color(LED_R1, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R2, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R3, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R4, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R5, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R6, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R7, CAPS_LOCK_COLOR);
    rgb_matrix_set_color(LED_R8, CAPS_LOCK_COLOR);
}

#endif // RGB_MATRIX_ENABLE
