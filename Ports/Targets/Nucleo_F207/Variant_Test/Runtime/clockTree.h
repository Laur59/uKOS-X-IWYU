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

#define KCRYSTAL            16000000U                                   // Quartz crystal resonator
#define KFREQUENCY_PLLP     120000000U                                  // PLL P bus frequency of 120-MHz
#define KFREQUENCY_PLLQ     48000000U                                   // PLL Q bus frequency of 48-MHz
#define KFREQUENCY_AHB      120000000U                                  // AHB bus frequency of 120-MHz
#define KFREQUENCY_APB2     60000000U                                   // APB2 periph bus frequency of 60-MHz
#define KFREQUENCY_APB1     30000000U                                   // APB1 periph bus frequency of 30-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          16000000U                                   // f(ck in), PLLSRC = HSI (16-MHz)
#define KPLL_FVCO_MIN       192000000U                                  // FVCO min, 192-MHz
#define KPLL_FVCO_MAX       432000000U                                  // FVCO max, 432-MHz
#define KPLL_FVCO(m, n)     (((uint64_t)KPLL_CK_IN * (n)) / (m))        // f(vco) = f(ck in) * (N / M)

// Compile-time checks of the main PLL configuration (RM0033)

#define KPLL_STATIC_CHECKS(m, n, p, q)                                                                                                  \
    static_assert(((m) >= 2U) && ((m) <= 63U), "PLL: PLLM shall be in 2..63");                                                          \
    static_assert(((n) >= 2U) && ((n) <= 432U), "PLL: PLLN shall be in 2..432");                                                        \
    static_assert(((p) == 2U) || ((p) == 4U) || ((p) == 6U) || ((p) == 8U), "PLL: PLLP shall be 2, 4, 6 or 8");                         \
    static_assert(((q) >= 2U) && ((q) <= 15U), "PLL: PLLQ shall be in 2..15");                                                          \
    static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL: FVCO out of range");                  \
    static_assert((KPLL_FVCO(m, n) / (p)) == KFREQUENCY_PLLP, "PLL: configuration does not match KFREQUENCY_PLLP");                     \
    static_assert((KPLL_FVCO(m, n) / (q)) == KFREQUENCY_PLLQ, "PLL: configuration does not match KFREQUENCY_PLLQ")

// Main PLL

#define KCFG_PLLDIVM        4U                                          // M = 4, f(ref) = 4-MHz
#define KCFG_PLLDIVN        60U                                         // N = 60, f(vco) = 240-MHz
#define KCFG_PLLDIVP        2U                                          // VCO / 2, 120-MHz
#define KCFG_PLLDIVQ        5U                                          // VCO / 5, 48-MHz
