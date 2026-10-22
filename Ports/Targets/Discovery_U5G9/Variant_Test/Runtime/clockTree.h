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
#define KFREQUENCY_PLL1P    160000000U                                  // PLL 1 P bus frequency of 160-MHz
#define KFREQUENCY_PLL1Q    160000000U                                  // PLL 1 Q bus frequency of 160-MHz
#define KFREQUENCY_PLL1R    160000000U                                  // PLL 1 R bus frequency of 160-MHz
#define KFREQUENCY_PLL3P    20833333U                                   // PLL 3 P bus frequency of 20.83-MHz
#define KFREQUENCY_PLL3Q    250000000U                                  // PLL 3 Q bus frequency of 250-MHz
#define KFREQUENCY_PLL3R    20833333U                                   // PLL 3 R bus frequency of 20.83-MHz
#define KFREQUENCY_AHB      160000000U                                  // AHB bus frequency of 160-MHz
#define KFREQUENCY_APB3     80000000U                                   // APB3 periph bus frequency of 80-MHz
#define KFREQUENCY_APB2     80000000U                                   // APB2 periph bus frequency of 80-MHz
#define KFREQUENCY_APB1     80000000U                                   // APB1 periph bus frequency of 80-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          16000000U                                   // f(ck in), PLLxSRC = HSI16 (16-MHz)
#define KPLL_FVCO_MIN       128000000U                                  // FVCO min, 128-MHz
#define KPLL_FVCO_MAX       544000000U                                  // FVCO max, 544-MHz
#define KPLL_FREF(m)        (KPLL_CK_IN / (m))                          // f(ref) = f(ck in) / M
#define KPLL_FREF_MIN(rge)  (((rge) == 0u) ? 4000000U : 8000000U)       // f(ref) min for PLLxRGE (0: 4-MHz, 3: 8-MHz)
#define KPLL_FREF_MAX(rge)  (((rge) == 0u) ? 8000000U : 16000000U)      // f(ref) max for PLLxRGE (0: 8-MHz, 3: 16-MHz)
#define KPLL_FVCO(m, n)     (((uint64_t)KPLL_CK_IN * (n)) / (m))        // f(vco) = f(ck in) * (N / M)

// Compile-time checks of a PLL configuration (RM0456, integer mode)

#define KPLL_STATIC_CHECKS(x, m, rge, n, p, q, r)                                                                                       \
    static_assert(((m) >= 1U) && ((m) <= 16U), "PLL" #x ": DIVM shall be in 1..16");                                                    \
    static_assert(((rge) == 0U) || ((rge) == 3U), "PLL" #x ": RGE shall be 0 or 3");                                                    \
    static_assert(((n) >= 4U) && ((n) <= 512U), "PLL" #x ": DIVN shall be in 4..512");                                                  \
    static_assert(((p) >= 1U) && ((p) <= 128U), "PLL" #x ": DIVP shall be in 1..128");                                                  \
    static_assert(((q) >= 1U) && ((q) <= 128U), "PLL" #x ": DIVQ shall be in 1..128");                                                  \
    static_assert(((r) >= 1U) && ((r) <= 128U), "PLL" #x ": DIVR shall be in 1..128");                                                  \
    static_assert((KPLL_FREF(m) >= KPLL_FREF_MIN(rge)) && (KPLL_FREF(m) <= KPLL_FREF_MAX(rge)), "PLL" #x ": f(ref) out of the PLLxRGE range");  \
    static_assert((KPLL_FVCO(m, n) >= KPLL_FVCO_MIN) && (KPLL_FVCO(m, n) <= KPLL_FVCO_MAX), "PLL" #x ": FVCO out of range");            \
    static_assert((KPLL_FVCO(m, n) / (p)) == KFREQUENCY_PLL##x##P, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "P");    \
    static_assert((KPLL_FVCO(m, n) / (q)) == KFREQUENCY_PLL##x##Q, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "Q");    \
    static_assert((KPLL_FVCO(m, n) / (r)) == KFREQUENCY_PLL##x##R, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x "R")

// PLL 1

#define KCFG_PLL1DIVM       1U                                          // M = 1, f(ref) = 16-MHz
#define KCFG_PLL1RGE        3U                                          // f(ref) in 8-MHz..16-MHz
#define KCFG_PLL1DIVN       20U                                         // N = 20, f(vco) = 320-MHz
#define KCFG_PLL1DIVP       2U                                          // VCO / 2, 160-MHz
#define KCFG_PLL1DIVQ       2U                                          // VCO / 2, 160-MHz
#define KCFG_PLL1DIVR       2U                                          // VCO / 2, 160-MHz

// PLL 3

#define KCFG_PLL3DIVM       4U                                          // M = 4, f(ref) = 4-MHz
#define KCFG_PLL3RGE        0U                                          // f(ref) in 4-MHz..8-MHz
#define KCFG_PLL3DIVN       125U                                        // N = 125, f(vco) = 500-MHz
#define KCFG_PLL3DIVP       24U                                         // VCO / 24, 20.83-MHz
#define KCFG_PLL3DIVQ       2U                                          // VCO / 2, 250-MHz
#define KCFG_PLL3DIVR       24U                                         // VCO / 24, 20.83-MHz
