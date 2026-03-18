/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Omni vision OV2640 imager equates.
 */

#pragma once

#include    <stdint.h>

// Aptina initialisation table

typedef struct  ov2640  ov2640_t;

struct ov2640 {
            uint8_t     oRegNumber;                                     // Register number
            uint8_t     oValue;                                         // Value
};

// Max image size

#define KNBROWS                 480U                                    // Max 480 rows
#define KNBCOLS                 640U                                    // Max 640 cols

// I2c interface

#define KOV2640A                0x60U                                   // I2C Omni vision address
