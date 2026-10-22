/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Clock tree definitions.
 */

#pragma once

// Main system clocks
// ------------------

#define KFREQUENCY_PLL      108000000U                                  // PLL frequency of 108-MHz
#define KFREQUENCY_AHB      108000000U                                  // AHB bus frequency of 108-MHz
#define KFREQUENCY_APB1     54000000U                                   // APB1 bus frequency of 54-MHz
#define KFREQUENCY_APB2     54000000U                                   // APB2 bus frequency of 54-MHz
#define KFREQUENCY_TIM      108000000U                                  // Timer clock 108-MHz (APB2 x 2)
#define KFREQUENCY_UART     54000000U                                   // Uart clock 54-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          4000000U                                    // f(ck in), PLLSEL = IRC8M / 2 (4-MHz)
#define KPLL_FOUT_MAX       108000000U                                  // CK_PLL max, 108-MHz
#define KPLL_PLLMF(mf)      (((mf) >= 17U) ? ((mf) - 1U) : (((mf) == 16U) ? 14U : ((mf) - 2U))) // PLLMF[4:0] encoding of x mf

// Compile-time checks of the PLL configuration (GD32VF103 user manual)
// PLLMF = 01101 is x 6.5, so x 15 is not available

#define KPLL_STATIC_CHECKS(mf)                                                                                                          \
    static_assert(((mf) >= 2U) && ((mf) <= 32U) && ((mf) != 15U), "PLL: PLLMF shall be in 2..14 or 16..32");                            \
    static_assert((KPLL_CK_IN * (mf)) <= KPLL_FOUT_MAX, "PLL: CK_PLL out of range");                                                    \
    static_assert((KPLL_CK_IN * (mf)) == KFREQUENCY_PLL, "PLL: configuration does not match KFREQUENCY_PLL")

// Main PLL

#define KCFG_PLLMF          27U                                         // CK_PLL = 4-MHz x 27 = 108-MHz
#define KCFG_USBFSPSC       3U                                          // CK_USBFS = CK_PLL / 2 (0: /1.5, 1: /1, 2: /2.5, 3: /2)
