/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; board.
; ======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Board mapping.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// This header contains only board-specific compile-time macros.
// It is not meant to contain function or variable declarations.
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wempty-translation-unit"
#endif

#ifndef Nucleo_L4R5_S
#define Nucleo_L4R5_S
#endif

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m4 L"
#define KCONTROLLER         "STM32L4R5"
#define KBOARD              "Nucleo L4R5 (Variant_Test)"
#define KTARGET             "Nucleo_L4R5"

// GPIO settings
// -------------

#define KNB_LED             3U                                  // Number of LEDs

// PORTs

#define BLED_0              7U                                  // PORT B 7, LED
#define BLED_1              14U                                 // PORT B 14, LED
#define BLED_2              7U                                  // PORT C 7, LED

#define BSW_0               13U                                 // PORT C 13, SW1
