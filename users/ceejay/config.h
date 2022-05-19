/* Copyright 2021 Jonavin Eng
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

#define TAPPING_TOGGLE 2           // TT () set to two taps

/*  Handle GRAVESC combo keys */
#define GRAVE_ESC_ALT_OVERRIDE     // Always send Escape if Alt is pressed
#define GRAVE_ESC_CTRL_OVERRIDE    // Always send Escape if Control is pressed

#define TAPPING_TERM 180

#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED

    #define RGB_MATRIX_STARTUP_HUE 188

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
#endif
