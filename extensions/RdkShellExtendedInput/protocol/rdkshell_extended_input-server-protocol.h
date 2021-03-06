/**
* If not stated otherwise in this file or this component's LICENSE
* file the following copyright and licenses apply:
*
* Copyright 2020 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/


#ifndef RDKSHELL_EXTENDED_INPUT_SERVER_PROTOCOL_H
#define RDKSHELL_EXTENDED_INPUT_SERVER_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

struct wl_client;
struct wl_resource;

struct rdkshell_extended_input;

extern const struct wl_interface rdkshell_extended_input_interface;

#ifndef RDKSHELL_EXTENDED_INPUT_KEY_STATE_ENUM
#define RDKSHELL_EXTENDED_INPUT_KEY_STATE_ENUM
/**
 * rdkshell_extended_input_key_state - Describes the physical or virtual
 *	state of the key that produced the key event
 * @RDKSHELL_EXTENDED_INPUT_KEY_STATE_RELEASED: The key has been released
 * @RDKSHELL_EXTENDED_INPUT_KEY_STATE_PRESSED: The key has been pressed
 *	(you'll also get this for key repeats)
 * @RDKSHELL_EXTENDED_INPUT_KEY_STATE_VIRTUAL_RELEASE: The virtual key
 *	has been released (you'll also get this for key repeats) - produced by
 *	gesture recogniser
 * @RDKSHELL_EXTENDED_INPUT_KEY_STATE_VIRTUAL_PRESS: The virtual key has
 *	been pressed - produced by gesture recogniser
 *
 * There is not key repeat event, instead the shell will send multiple
 * pressed events for the key repeat. Virtual key events are generated by
 * the gesture recogniser if it is enabled for the given app.
 */
enum rdkshell_extended_input_key_state {
	RDKSHELL_EXTENDED_INPUT_KEY_STATE_RELEASED = 0,
	RDKSHELL_EXTENDED_INPUT_KEY_STATE_PRESSED = 1,
	RDKSHELL_EXTENDED_INPUT_KEY_STATE_VIRTUAL_RELEASE = 2,
	RDKSHELL_EXTENDED_INPUT_KEY_STATE_VIRTUAL_PRESS = 3,
};
#endif /* RDKSHELL_EXTENDED_INPUT_KEY_STATE_ENUM */

#ifndef RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_ENUM
#define RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_ENUM
/**
 * rdkshell_extended_input_touchpad_state - Describes the state of the
 *	touch pad when the event was generated
 * @RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_UP: end of touch event
 * @RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_DOWN: the start of a touch
 *	event
 * @RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_CLICK: the button beneath the
 *	touch pad has been pressed
 *
 * This is a tri-state describing the state of the touch pad at the time
 * that event was generated.
 */
enum rdkshell_extended_input_touchpad_state {
	RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_UP = 0,
	RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_DOWN = 1,
	RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_CLICK = 2,
};
#endif /* RDKSHELL_EXTENDED_INPUT_TOUCHPAD_STATE_ENUM */

#ifndef RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_ENUM
#define RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_ENUM
/**
 * rdkshell_extended_input_slider_state - Describes the state of the
 *	slider touch pad when the event was generated
 * @RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_UP: end of touch event
 * @RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_DOWN: the start of a touch event
 *
 * Describes the state of the slider touchpad when the event was
 * generated.
 */
enum rdkshell_extended_input_slider_state {
	RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_UP = 0,
	RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_DOWN = 1,
};
#endif /* RDKSHELL_EXTENDED_INPUT_SLIDER_STATE_ENUM */

#define RDKSHELL_EXTENDED_INPUT_KEY	0
#define RDKSHELL_EXTENDED_INPUT_TOUCHPAD	1
#define RDKSHELL_EXTENDED_INPUT_SLIDER	2

#define RDKSHELL_EXTENDED_INPUT_KEY_SINCE_VERSION	1
#define RDKSHELL_EXTENDED_INPUT_TOUCHPAD_SINCE_VERSION	1
#define RDKSHELL_EXTENDED_INPUT_SLIDER_SINCE_VERSION	1

static inline void
rdkshell_extended_input_send_key(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t device_id, int32_t key, uint32_t state)
{
	wl_resource_post_event(resource_, RDKSHELL_EXTENDED_INPUT_KEY, serial, time, device_id, key, state);
}

static inline void
rdkshell_extended_input_send_touchpad(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t device_id, int32_t x, int32_t y, uint32_t state)
{
	wl_resource_post_event(resource_, RDKSHELL_EXTENDED_INPUT_TOUCHPAD, serial, time, device_id, x, y, state);
}

static inline void
rdkshell_extended_input_send_slider(struct wl_resource *resource_, uint32_t serial, uint32_t time, uint32_t device_id, int32_t x, uint32_t state)
{
	wl_resource_post_event(resource_, RDKSHELL_EXTENDED_INPUT_SLIDER, serial, time, device_id, x, state);
}

#ifdef  __cplusplus
}
#endif

#endif
