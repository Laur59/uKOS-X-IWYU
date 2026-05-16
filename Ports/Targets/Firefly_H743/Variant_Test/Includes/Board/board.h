/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Board mapping.
 */

#pragma once

#ifndef Firefly_H743_S
#define Firefly_H743_S
#endif

#include    "soc_reg.h"

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m7 H"
#define KCONTROLLER         "STM32H743"
#define KBOARD              "Firefly H743 (Variant_Test)"
#define KTARGET             "Firefly_H743"

// GPIO settings
// -------------

#define KNB_LED             2U                                  // Number of LEDs

// PORTs

#define BLED_0              0U                                  // PORT B 0, LED
#define BLED_1              1U                                  // PORT B 1, LED
#define BSW_0               0U                                  // PORT A 0, SW0 (WK_UP)
#define BSW_1               1U                                  // PORT A 1, SW1 (KEY0)
