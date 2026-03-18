/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef DevKit_nRF5340_S
#define DevKit_nRF5340_S
#endif

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m33"
#define KCONTROLLER         "nRF5340"
#define KBOARD              "DevKit_nRF5340 (Variant_Test_Net)"
#define KTARGET             "DevKit_nRF5340"

// GPIO settings
// -------------

#define KNB_LED             2U                                  // Number of LEDs

// PORTs

// The LEDs 2 & 3 and the Switches 2 & 3 are attributed to
// the Net cpu

#define BLED_0              30U                                 // P0.30, LED
#define BLED_1              31U                                 // P0.31, LED

#define BSW_0               8U                                  // P0.8,  SW2
#define BSW_1               9U                                  // P0.9,  SW3
