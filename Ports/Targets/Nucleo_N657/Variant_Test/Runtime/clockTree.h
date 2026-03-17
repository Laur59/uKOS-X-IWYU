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

// This header contains only variant-specific compile-time macros.
// It is not meant to contain function or variable declarations.
#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wempty-translation-unit"
#endif

// Main system clocks
// ------------------

// Constraints:
//
// Fcpu:            800-MHz     sysa_ck (ic1)
// Fnpu:            800-MHz     sysc_ck (ic6)
// Faxi:            400-MHz     sysb_ck (ic2)
// FaxiRAMNPU:      400-MHz     sysd_ck (1c11)
//
// !!! Some silicon limitations. PBx HAS to be = AHB
//
// Faxi, 400-MHz, FBusMax
// - Timer group 1, 100-MHz
// - Timer group 2, 100-MHz
// - sys_bus2_ck (pclkx), 100-MHz, Faxi / 4
//      - APB1,2,4,5, 100-MHz, sys_bus2_ck / 1
//
// Simple peripherals
// Fadc12,      pclk5 100-MHz
// Fi2cx,       pclk5 100-MHz (x=1, 2, 3 ,4)
// Fi3cx,       pclk5 100-MHz (x=1, 2)
// Fsaix,       pclk2 100-MHz (x=1, 2)
// Fspix,       pclk4 100-MHz (x=1, 2, 3, 4, 5, 6)
// Flptimx,     pclk4 100-MHz (x=1, 2, 3, 4, 5)
// Fusartx,     pclk1 100-MHz (x=1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
// Flpusartx,   pclk4 100-MHz (x=1, 2)
// Flpuartx,    pclk4 100-MHz (x=1)

#define KCRYSTAL            64000000U                                   // Quartz crystal resonator
#define KFREQUENCY_PLL1     800000000U                                  // PLL 1 CPU frequency of 800-MHz
#define KFREQUENCY_PLL2     800000000U                                  // PLL 2 NPU frequency of 800-MHz
#define KFREQUENCY_PLL3     400000000U                                  // PLL 3 AXI frequency of 400-MHz
#define KFREQUENCY_PLL4     400000000U                                  // PLL 4 PER frequency of 400-MHz

#define KTIMPRE             2U                                          // Div 4 (2^2)
#define KHPRE               2U                                          // Div 4 (2^2)
#define KPPRE1              0U                                          // Div 1 (2^0)
#define KPPRE2              0U                                          // Div 1 (2^0)
#define KPPRE4              0U                                          // Div 1 (2^0)
#define KPPRE5              0U                                          // Div 1 (2^0)

#define KFREQUENCY_CPU      KFREQUENCY_PLL1                             // CPU bus frequency of 800-MHz
#define KFREQUENCY_NPU      KFREQUENCY_PLL2                             // NPU bus frequency of 800-MHz
#define KFREQUENCY_AXI      KFREQUENCY_PLL3                             // AXI bus frequency of 400-MHz
#define KFREQUENCY_TIM      (KFREQUENCY_AXI / (1U<<KTIMPRE))            // TIM bus frequency of 100-MHz
#define KFREQUENCY_HCL      (KFREQUENCY_AXI / (1U<<KHPRE))              // HCL bus frequency of 100-MHz
#define KFREQUENCY_APB1     (KFREQUENCY_HCL / (1U<<KPPRE1))             // APB1 bus frequency of 100-MHz
#define KFREQUENCY_APB2     (KFREQUENCY_HCL / (1U<<KPPRE2))             // APB2 bus frequency of 100-MHz
#define KFREQUENCY_APB4     (KFREQUENCY_HCL / (1U<<KPPRE4))             // APB4 bus frequency of 100-MHz
#define KFREQUENCY_APB5     (KFREQUENCY_HCL / (1U<<KPPRE5))             // APB5 bus frequency of 100-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_CPU                              // CORE frequency
