/* Copyright 2017 Fred Sundvik
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

#ifndef KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_
#define KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_

#include "visualizer.h"
#include "visualizer_keyframes.h"
#include "led.h"
#include "default_animations.h"
#include "led_backlight_keyframes.h"

static bool initial_update = true;

void initialize_user_visualizer(visualizer_state_t* state) {
    // The brightness will be dynamically adjustable in the future
    // But for now, change it here.

    initial_update = true;
    start_keyframe_animation(&default_startup_animation);
}

#ifdef WHITEFOX_FLASHY_VIZ

keyframe_animation_t resume_animation = {
    .num_frames = 2,
    .loop = false,
    .frame_lengths = {
        gfxMillisecondsToTicks(1000),
        gfxMillisecondsToTicks(4000)},
    .frame_functions = {
            led_backlight_keyframe_fade_out_all,
            led_backlight_keyframe_fade_in_all,
    },
};

#define CROSSFADE_TIME 1000
#define GRADIENT_TIME 3000

keyframe_animation_t led_sleep_animation = {
    .num_frames = 14,
    .loop = true,
    .frame_lengths = {
        gfxMillisecondsToTicks(1000), // fade out
        gfxMillisecondsToTicks(1000), // fade in
        gfxMillisecondsToTicks(1000), // no op (leds on)
        gfxMillisecondsToTicks(CROSSFADE_TIME), // crossfade
        gfxMillisecondsToTicks(GRADIENT_TIME), // left to rigt (outside in)
        gfxMillisecondsToTicks(CROSSFADE_TIME), // crossfade
        gfxMillisecondsToTicks(GRADIENT_TIME), // top_to_bottom
        0,           // mirror leds
        gfxMillisecondsToTicks(CROSSFADE_TIME), // crossfade
        gfxMillisecondsToTicks(GRADIENT_TIME), // left_to_right (mirrored, so inside out)
        gfxMillisecondsToTicks(CROSSFADE_TIME), // crossfade
        gfxMillisecondsToTicks(GRADIENT_TIME), // top_to_bottom
        0,           // normal leds
        gfxMillisecondsToTicks(CROSSFADE_TIME), // crossfade

    },
    .frame_functions = {
        led_backlight_keyframe_fade_out_all,
        led_backlight_keyframe_fade_in_all,
        keyframe_no_operation,
        led_backlight_keyframe_crossfade,
        led_backlight_keyframe_left_to_right_gradient,
        led_backlight_keyframe_crossfade,
        led_backlight_keyframe_top_to_bottom_gradient,
        led_backlight_keyframe_mirror_orientation,
        led_backlight_keyframe_crossfade,
        led_backlight_keyframe_left_to_right_gradient,
        led_backlight_keyframe_crossfade,
        led_backlight_keyframe_top_to_bottom_gradient,
        led_backlight_keyframe_normal_orientation,
        led_backlight_keyframe_crossfade,
    },
};

void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
    // Add more tests, change the colors and layer texts here
    // Usually you want to check the high bits (higher layers first)
    // because that's the order layers are processed for keypresses
    // You can for check for example:
    // state->status.layer
    // state->status.default_layer
    // state->status.leds (see led.h for available statuses)
}


void user_visualizer_suspend(visualizer_state_t* state) {
    start_keyframe_animation(&led_sleep_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
    stop_keyframe_animation(&led_sleep_animation);
    start_keyframe_animation(&resume_animation);
}

#else /* WHITEFOX_FLASH_VIZ not defined*/

void update_user_visualizer_state(visualizer_state_t* state, visualizer_keyboard_status_t* prev_status) {
    // Add more tests, change the colors and layer texts here
    // Usually you want to check the high bits (higher layers first)
    // because that's the order layers are processed for keypresses
    // You can for check for example:
    // state->status.layer
    // state->status.default_layer
    // state->status.leds (see led.h for available statuses)

    if (initial_update) { initial_update=false; start_keyframe_animation(&led_test_animation); }
}


void user_visualizer_suspend(visualizer_state_t* state) {
    start_keyframe_animation(&default_suspend_animation);
}

void user_visualizer_resume(visualizer_state_t* state) {
    initial_update = true;
    start_keyframe_animation(&default_startup_animation);
}

#endif /* WHITEFOX_FLASH_VIZ */

#endif /* KEYBOARDS_WHITEFOX_SIMPLE_VISUALIZER_H_ */
