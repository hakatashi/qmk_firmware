#include "print.h"

RGB_MATRIX_EFFECT(hakatashi_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

enum layer_names {
	_BASE,
	_LOWER,
	_RAISE,
	_ADJUST,
};

typedef struct PACKED {
	uint8_t size;
	uint8_t color;
	uint8_t center_x;
	uint8_t center_y;
} Circle;

static Circle circle;

void set_color(int index, uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue) {
	HSV hsv = {hsvred, hsvgreen, hsvblue};
	if (hsv.v > rgb_matrix_get_val()) {
		hsv.v = rgb_matrix_get_val();
	}
	RGB rgb = hsv_to_rgb(hsv);
	rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

void set_color_all(uint8_t hsvred, uint8_t hsvgreen, uint8_t hsvblue) {
	HSV hsv = {hsvred, hsvgreen, hsvblue};
	if (hsv.v > rgb_matrix_get_val()) {
		hsv.v = rgb_matrix_get_val();
	}
	RGB rgb = hsv_to_rgb(hsv);
	rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

void get_key_location(uint8_t r, uint8_t c, uint8_t* x, uint8_t* y) {
	if (r < 4) {
		*y = r * 2;
		*x = c * 2;
		if (r == 3) {
			*x += 1;
		}
	} else {
		*y = (r - 4) * 2;
		*x = (15 - c) * 2;
		if (r == 7) {
			*x -= 1;
		}
	}
}

static void hakatashi_effect_complex_init(effect_params_t* params) {
	circle.size = 0;
	circle.color = _BASE;
	circle.center_x = 0;
	circle.center_y = 0;
}

static bool hakatashi_effect_complex_run(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

	switch (get_highest_layer(layer_state | default_layer_state)) {
		case _RAISE:
			if (circle.color != _RAISE) {
				circle.color = _RAISE;
				circle.size = 0;
				circle.center_x = 21;
				circle.center_y = 6;
			}
			break;
		case _LOWER:
			if (circle.color != _LOWER) {
				circle.color = _LOWER;
				circle.size = 0;
				circle.center_x = 9;
				circle.center_y = 6;
			}
			break;
		case _ADJUST:
			if (circle.color != _ADJUST) {
				circle.color = _ADJUST;
				circle.size = 0;
				circle.center_x = 21;
				circle.center_y = 6;
			}
			break;
		default:
			circle.color = _BASE;
			circle.size = 0;
			break;
	}

	if (circle.color != _BASE && circle.size < 0xff) {
		circle.size++;
	}

	for (uint8_t c = 0; c < MATRIX_COLS; c++) {
		for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
			uint8_t led = g_led_config.matrix_co[r][c];
			uint8_t x, y;
			get_key_location(r, c, &x, &y);

			uint16_t dx = (uint16_t)x - (uint16_t)circle.center_x;
			uint16_t dy = (uint16_t)y - (uint16_t)circle.center_y;
			uint16_t dist = dx * dx + dy * dy;
			uint16_t c = (uint16_t)circle.size * (uint16_t)circle.size;

			if (dist < c / 15) {
				switch(circle.color) {
					case _RAISE:
						set_color(led, HSV_RED);
						break;
					case _LOWER:
						set_color(led, HSV_BLUE);
						break;
					case _ADJUST:
						set_color(led, HSV_WHITE);
						break;
					default:
						break;
				}
			} else {
				set_color(led, HSV_OFF);
			}
		}
	}

	return rgb_matrix_check_finished_leds(led_max);
}

static bool hakatashi_effect(effect_params_t* params) {
	if (params->init) hakatashi_effect_complex_init(params);
	return hakatashi_effect_complex_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
