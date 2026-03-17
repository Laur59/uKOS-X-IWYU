/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; clockTree.
; ==========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Clock tree definitions.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

// This header contains only compile-time macros.
// It is not meant to contain function or variable declarations.
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wempty-translation-unit"
#endif

// Main system clocks
// ------------------

#define KCRYSTAL            12000000U                                   // Quartz crystal resonator
#define KFREQUENCY_AHB      150000000U                                  // AHB bus frequency of 150-MHz
#define KFREQUENCY_TIM      1000000U                                    // Timers frequency of 1-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency
