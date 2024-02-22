#pragma once

// needed for layer names
#include "layout.h"

static uint8_t led_status = 0;

enum led_status_flags {
  LED_CAPSWORD = 1,
  LED_LAYER_ACTIVE = 2,
  LED_MACRO1 = 4,
  LED_MACRO2 = 8,
};

void update_left_led(void);
void update_right_led(void);

void dynamic_macro_record_start_user(int8_t direction) {
  if (direction == 1) {
      led_status = led_status | LED_MACRO1;
  }

  if (direction == -1) {
      led_status = led_status | LED_MACRO2;
  }
}

void dynamic_macro_record_end_user(int8_t direction) {
  if (direction == 1) {
      led_status = led_status & ~LED_MACRO1;
  }

  if (direction == -1) {
      led_status = led_status & ~LED_MACRO2;
  }
}

void caps_word_set_user(bool active) {
  // update capsword status
  led_status = active
    ? led_status | LED_CAPSWORD
    : led_status & ~LED_CAPSWORD;
}

void update_right_led(void) {
  if (is_keyboard_left()) return;

  switch (get_highest_layer(layer_state)) {
    case _SYM:
    case _FUN:
      led_status = led_status | LED_LAYER_ACTIVE;
      break;
    default:
      led_status = led_status & ~LED_LAYER_ACTIVE;
      break;
  }

  if (led_status & LED_LAYER_ACTIVE) {
    writePin(STATUS_LED_PIN, LED_PIN_ON_STATE);
  } else {
    writePin(STATUS_LED_PIN, !LED_PIN_ON_STATE);
  }
}

static int8_t is_left_on = 0;
void update_left_led(void) {
  if (!is_keyboard_left()) { return; }

  // left led
  if (led_status & LED_MACRO1 || led_status & LED_MACRO2) {
    writePin(STATUS_LED_PIN, is_left_on ? LED_PIN_ON_STATE : !LED_PIN_ON_STATE);
    is_left_on = !is_left_on;
  } else if (!(led_status & (LED_MACRO1 | LED_MACRO2)) && led_status & LED_CAPSWORD) {
    writePin(STATUS_LED_PIN, LED_PIN_ON_STATE);
  } else {
    writePin(STATUS_LED_PIN, !LED_PIN_ON_STATE);
  }
}

uint16_t led_timer = 0;
void blink_led_callback(void) {
  update_right_led();
  if (timer_elapsed(led_timer) > LED_BLINK_MS) {
    update_left_led();
    led_timer = timer_read();
  }
}
// vim: ts=2 sw=2 sts=2 et
