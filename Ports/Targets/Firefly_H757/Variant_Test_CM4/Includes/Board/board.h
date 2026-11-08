/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal: Board mapping.
 */

#pragma once

// GPIO settings
// -------------

#define KNB_LED             2U                                  // Number of LEDs

// PORTs

#define BLED_0              3U                                  // PORT A 3, LED
#define BLED_1              1U                                  // PORT B 1, LED
#define BSW_0               2U                                  // PORT A 2, SW0 (WK_UP)
#define BSW_1               8U                                  // PORT A 8, SW1 (KEY0)
#define BLCD_POWER          11U                                 // PORT I 11, LCD power
#define BLCD_RST            5U                                  // PORT H 5, LCD reset
#define BBL_CTRL            0U                                  // PORT B 0, LCD backlignt
