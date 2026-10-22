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
#define KFREQUENCY_PLLP     34285714U                                   // PLL P bus frequency of 34.29-MHz
#define KFREQUENCY_PLLQ     40000000U                                   // PLL Q bus frequency of 40-MHz
#define KFREQUENCY_PLLR     120000000U                                  // PLL R bus frequency of 120-MHz
#define KFREQUENCY_AHB      120000000U                                  // AHB bus frequency of 120-MHz
#define KFREQUENCY_APB2     120000000U                                  // APB2 periph bus frequency of 120-MHz
#define KFREQUENCY_APB1     120000000U                                  // APB1 periph bus frequency of 120-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          16000000U                                   // f(ck in), PLLSRC = HSI16 (16-MHz)
#define KPLL_FREF_MIN       2660000U                                    // f(ref) min, 2.66-MHz
#define KPLL_FREF_MAX       16000000U                                   // f(ref) max, 16-MHz
#define KPLL_FVCO_MIN       64000000U                                   // FVCO min, 64-MHz
#define KPLL_FVCO_MAX       344000000U                                  // FVCO max, 344-MHz
#define KPLL_FREF(m)        (KPLL_CK_IN / (m))                          // f(ref) = f(ck in) / M
#define KPLL_FVCO(m, n)     (((uint64_t)KPLL_CK_IN * (n)) / (m))        // f(vco) = f(ck in) * (N / M)

// Compile-time checks of the main PLL configuration (RM0432)

#define KPLL_STATIC_CHECKS(m, n, p, q, r)                                                                                               \
    static_assert(((m) >= 1U) && ((m) <= 16U), "PLL: PLLM shall be in 1..16");                                                          \
    static_assert(((n) >= 8U) && ((n) <= 127U), "PLL: PLLN shall be in 8..127");                                                        \
    static_assert(((p) == 7U) || ((p) == 17U), "PLL: PLLP shall be 7 or 17 (PLLPDIV not used)");                                        \
    static_assert(((q) == 2U) || ((q) == 4U) || ((q) == 6U) || ((q) == 8U), "PLL: PLLQ shall be 2, 4, 6 or 8");                         \
    static_assert(((r) == 2U) || ((r) == 4U) || ((r) == 6U) || ((r) == 8U), "PLL: PLLR shall be 2, 4, 6 or 8");                         \
    static_assert((KPLL_FREF(m) >= KPLL_FREF_MIN) && (KPLL_FREF(m) <= KPLL_FREF_MAX), "PLL: f(ref) out of range");                      \
    static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL: FVCO out of range");                  \
    static_assert((KPLL_FVCO(m, n) / (p)) == KFREQUENCY_PLLP, "PLL: configuration does not match KFREQUENCY_PLLP");                     \
    static_assert((KPLL_FVCO(m, n) / (q)) == KFREQUENCY_PLLQ, "PLL: configuration does not match KFREQUENCY_PLLQ");                     \
    static_assert((KPLL_FVCO(m, n) / (r)) == KFREQUENCY_PLLR, "PLL: configuration does not match KFREQUENCY_PLLR")

// Main PLL

#define KCFG_PLLDIVM        2U                                          // M = 2, f(ref) = 8-MHz
#define KCFG_PLLDIVN        30U                                         // N = 30, f(vco) = 240-MHz
#define KCFG_PLLDIVP        7U                                          // VCO / 7, 34.29-MHz
#define KCFG_PLLDIVQ        6U                                          // VCO / 6, 40-MHz
#define KCFG_PLLDIVR        2U                                          // VCO / 2, 120-MHz
