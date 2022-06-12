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
	uint16_t id;
	uint8_t is_processed;
} Circle;

static Circle circles[] = {
		{0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0},
		{0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0},
		{0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0},
		{0, _BASE, 0, 0, 0, 0}, {0, _BASE, 0, 0, 0, 0}};

static uint16_t newest_circle_id;

static uint8_t current_color = _BASE;

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
	for (uint8_t i = 0; i < sizeof(circles) / sizeof(circles[0]); i++) {
		circles[i].size = 0xff;
		circles[i].color = _BASE;
		circles[i].center_x = 0;
		circles[i].center_y = 0;
		circles[i].is_processed = 0;
		circles[i].id = 0;
	}
	current_color = _BASE;
	newest_circle_id = 0;
}

static void add_circle(uint8_t color, uint8_t size, uint8_t center_x,
											 uint8_t center_y) {
	uint8_t max_size = 0;
	uint8_t max_circle = 0;
	uint8_t max_circle_id = 0;
	for (uint8_t j = 0; j < sizeof(circles) / sizeof(circles[0]); j++) {
		if (max_size < circles[j].size ||
				(max_size == circles[j].size && max_circle_id > circles[j].id)) {
			max_size = circles[j].size;
			max_circle_id = circles[j].id;
			max_circle = j;
		}
	}

	circles[max_circle].color = color;
	circles[max_circle].size = size;
	circles[max_circle].center_x = center_x;
	circles[max_circle].center_y = center_y;
	circles[max_circle].id = ++newest_circle_id;
}

static bool hakatashi_effect_complex_run(effect_params_t* params) {
	RGB_MATRIX_USE_LIMITS(led_min, led_max);

	uint8_t new_color = get_highest_layer(layer_state | default_layer_state);
	uint8_t changed_key = 0;  // 0 => both, 1 => left, 2 => right

	switch (new_color) {
		case _BASE:
			if (current_color == _RAISE) {
				changed_key = 2;
			} else if (current_color == _LOWER) {
				changed_key = 1;
			}
			break;
		case _RAISE:
			if (current_color == _BASE) {
				changed_key = 2;
			} else if (current_color == _ADJUST) {
				changed_key = 1;
			}
			break;
		case _LOWER:
			if (current_color == _BASE) {
				changed_key = 1;
			} else if (current_color == _ADJUST) {
				changed_key = 2;
			}
			break;
		case _ADJUST:
			if (current_color == _RAISE) {
				changed_key = 1;
			} else if (current_color == _LOWER) {
				changed_key = 2;
			}
			break;
		default:
			break;
	}

	if (current_color != new_color) {
		if (changed_key == 0 || changed_key == 1) {
			add_circle(new_color, 0, 9, 6);
		}
		if (changed_key == 0 || changed_key == 2) {
			add_circle(new_color, 0, 21, 6);
		}
	}

	current_color = new_color;

	for (uint8_t i = 0; i < sizeof(circles) / sizeof(circles[0]); i++) {
		if (circles[i].size < 0xff) {
			circles[i].size++;
		}
	}

	HSV key_colors[54] = {};
	for (uint8_t i = led_min; i <= led_max; i++) {
		key_colors[i] = (HSV){HSV_OFF};
	}

	for (uint8_t i = 0; i < sizeof(circles) / sizeof(circles[0]); i++) {
		circles[i].is_processed = 0;
	}

	for (uint8_t i = 0; i < sizeof(circles) / sizeof(circles[0]); i++) {
		uint8_t max_size = 0;
		uint8_t max_circle = 0;
		uint8_t max_circle_id = 0;
		for (uint8_t j = 0; j < sizeof(circles) / sizeof(circles[0]); j++) {
			if (circles[j].is_processed == 0) {
				if (max_size < circles[j].size ||
						(max_size == circles[j].size && max_circle_id > circles[j].id)) {
					max_size = circles[j].size;
					max_circle_id = circles[j].id;
					max_circle = j;
				}
			}
		}

		for (uint8_t c = 0; c < MATRIX_COLS; c++) {
			for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
				uint8_t led = g_led_config.matrix_co[r][c];

				if (led == NO_LED) {
					continue;
				}

				uint8_t x, y;
				get_key_location(r, c, &x, &y);

				uint16_t dx = (uint16_t)x - (uint16_t)circles[max_circle].center_x;
				uint16_t dy = (uint16_t)y - (uint16_t)circles[max_circle].center_y;
				uint16_t dist = dx * dx + dy * dy;
				uint16_t c = (uint16_t)circles[max_circle].size *
										 (uint16_t)circles[max_circle].size;

				if (dist < c / 15) {
					switch (circles[max_circle].color) {
						case _BASE:
							key_colors[led] = (HSV){HSV_OFF};
							break;
						case _RAISE:
							key_colors[led] = (HSV){HSV_RED};
							break;
						case _LOWER:
							key_colors[led] = (HSV){HSV_BLUE};
							break;
						case _ADJUST:
							key_colors[led] = (HSV){HSV_WHITE};
							break;
						default:
							break;
					}
				}
			}
		}

		circles[max_circle].is_processed = 1;
	}

	for (uint8_t i = led_min; i <= led_max; i++) {
		HSV color = key_colors[i];
		set_color(i, color.h, color.s, color.v);
	}

	return rgb_matrix_check_finished_leds(led_max);
}

static bool hakatashi_effect(effect_params_t* params) {
	if (params->init) hakatashi_effect_complex_init(params);
	return hakatashi_effect_complex_run(params);
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
