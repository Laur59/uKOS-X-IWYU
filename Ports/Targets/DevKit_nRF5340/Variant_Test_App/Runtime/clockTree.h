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

// Main system clocks
// ------------------

#define KFREQUENCY_HFCLK    128000000U                                  // HFCLK bus frequency of 128-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_16MHz    16000000U                                   // Frequency of 16-MHz
#define KFREQUENCY_CORE     KFREQUENCY_HFCLK                            // CORE frequency
#define KFREQUENCY_TIM      KFREQUENCY_16MHz                            // TIM frequency
