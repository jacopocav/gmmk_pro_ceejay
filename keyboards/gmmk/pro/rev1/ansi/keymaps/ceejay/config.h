/* Copyright 2022 Andre Brait
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Setting DEBOUNCE to 8 to be a little conservative due to issues with Glorious' proprietary hot-swap sockets
#ifdef DEBOUNCE
    #undef DEBOUNCE
#endif
#define DEBOUNCE 8

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_TIMEOUT 300000     // 5 minutes (5 * 60 * 1000ms)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_BAND_VAL
    #define RGB_MATRIX_STARTUP_HUE RGB_WHITE

    // enable optional RGB effects
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS

    // disable needless RGB effects
    #define DISABLE_RGB_MATRIX_RAINDROPS
    #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #define DISABLE_RGB_MATRIX_BAND_SAT
    #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define DISABLE_RGB_MATRIX_SPLASH
    #define DISABLE_RGB_MATRIX_SOLID_SPLASH
    #define DISABLE_RGB_MATRIX_DIGITAL_RAIN

    // enable hint rgb lighting
    #define ENABLE_RGB_HINTS
#endif
