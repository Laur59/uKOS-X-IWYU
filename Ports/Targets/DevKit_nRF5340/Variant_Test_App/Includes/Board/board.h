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

// GPIO settings
// -------------

#define KNB_LED             2U                                  // Number of LEDs

// PORTs

// The LEDs 2 & 3 and the Switches 2 & 3 are attributed to
// the Net cpu

#define BLED_0              28U                                 // P0.28, LED
#define BLED_1              29U                                 // P0.29, LED

#define BSW_0               23U                                 // P0.23, SW0
#define BSW_1               24U                                 // P0.24, SW1
