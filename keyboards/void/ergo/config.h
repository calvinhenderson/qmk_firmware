/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

// Show caps lock status on LED indicators
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define STATUS_LED_PIN B1
#define LED_PIN_ON_STATE 1
#define LED_BLINK_MS 1000

/* Split Configuration */
#define SOFT_SERIAL_PIN D2 // Serial communication
#define SPLIT_USB_DETECT   // Detect LH/RH from VBUS
#define SPLIT_MODS_ENABLE  // Transmit modifier state to slave

/* Watchdog to restart slave if connection fails */
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

/* Use 1000hz polling */
#define USB_POLLING_INTERVAL_MS 1
