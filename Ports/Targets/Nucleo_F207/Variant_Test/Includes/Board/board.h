/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

// This header contains only board-specific compile-time macros.
// It is not meant to contain function or variable declarations.
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wempty-translation-unit"
#endif

#ifndef Nucleo_F207_S
#define Nucleo_F207_S
#endif

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m3"
#define KCONTROLLER         "STM32F207"
#define KBOARD              "Nucleo F207 (Variant_Test)"
#define KTARGET             "Nucleo_F207"

// GPIO settings
// -------------

#define KNB_LED             3U                                  // Number of LEDs

// PORTs

#define BLED_0              14U                                 // PORT B 14, BLED_0
#define BLED_1              7U                                  // PORT B 7, BLED_1
#define BLED_2              9U                                  // PORT A 9, BLED_2

#define BSW_0               13U                                 // PORT C 13, SW1
