#include "config_common.h"

#pragma once

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS \
    { B6, B2, B3, B1 }
#define MATRIX_COL_PINS \
    { F7, D4, C6, D7, E6, B4, B5 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 100
#define DEBOUNCE 5

/* encoder support */
#define ENCODERS_PAD_A \
    { F5 }
#define ENCODERS_PAD_B \
    { F4 }
#define ENCODERS_PAD_A_RIGHT \
    { F4 }
#define ENCODERS_PAD_B_RIGHT \
    { F5 }
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10

/* communication between sides */
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2
