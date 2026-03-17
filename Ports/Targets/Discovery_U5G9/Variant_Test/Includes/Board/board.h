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

#ifndef Discovery_U5G9_S
#define Discovery_U5G9_S
#endif

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m33 U"
#define KCONTROLLER         "STM32U5G9"
#define KBOARD              "Discovery U5G9 (Variant_Test)"
#define KTARGET             "Discovery_U5G9"

// GPIO settings
// -------------

#define KNB_LED             2U                                  // Number of LEDs

// PORTs

#define BLED_0              0U                                  // PORT E 0, LED
#define BLED_1              1U                                  // PORT E 1, LED

#define BSW_0               13U                                 // PORT C 13, SW1

#define BDSI_PWRON          5U                                  // PORT I 5, DSI Power ON
#define BDSI_BL             6U                                  // PORT I 6, DSI Back light
#define BDSI_RESET          5U                                  // PORT D 5, DSI Reset
