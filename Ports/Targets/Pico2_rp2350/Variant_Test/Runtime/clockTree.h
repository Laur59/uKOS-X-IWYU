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

#define KCRYSTAL            12000000U                                   // Quartz crystal resonator
#define KFREQUENCY_PLLSYS   150000000U                                  // PLL SYS frequency of 150-MHz
#define KFREQUENCY_PLLUSB   48000000U                                   // PLL USB frequency of 48-MHz
#define KFREQUENCY_AHB      150000000U                           // AHB bus frequency of 150-MHz
#define KFREQUENCY_TIM      1000000U                                    // Timers frequency of 1-MHz
#define KFREQUENCY_1GHz     1000000000U                          // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                             // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          KCRYSTAL                                    // f(ck in), XOSC (12-MHz)
#define KPLL_FREF_MIN       5000000U                                    // f(ref) min, 5-MHz
#define KPLL_FVCO_MIN       750000000U                                  // FVCO min, 750-MHz
#define KPLL_FVCO_MAX       1600000000U                                 // FVCO max, 1600-MHz
#define KPLL_FREF(r)        (KPLL_CK_IN / (r))                          // f(ref) = f(ck in) / REFDIV
#define KPLL_FVCO(r, fb)    (((uint64_t)KPLL_CK_IN * (fb)) / (r))       // f(vco) = f(ck in) * (FBDIV / REFDIV)

// Compile-time checks of a PLL configuration (RP2350 datasheet)

#define KPLL_STATIC_CHECKS(x, r, fb, pd1, pd2)                                                                                          \
    static_assert(((r) >= 1U) && ((r) <= 63U), "PLL_" #x ": REFDIV shall be in 1..63");                                                 \
    static_assert(((fb) >= 16U) && ((fb) <= 320U), "PLL_" #x ": FBDIV shall be in 16..320");                                            \
    static_assert(((pd1) >= 1U) && ((pd1) <= 7U), "PLL_" #x ": POSTDIV1 shall be in 1..7");                                             \
    static_assert(((pd2) >= 1U) && ((pd2) <= 7U), "PLL_" #x ": POSTDIV2 shall be in 1..7");                                             \
    static_assert(KPLL_FREF(r) >= KPLL_FREF_MIN, "PLL_" #x ": f(ref) out of range");                                                    \
    static_assert((KPLL_FVCO(r, fb) / ((uint64_t)(pd1) * (pd2))) == KFREQUENCY_PLL##x, "PLL_" #x ": configuration does not match KFREQUENCY_PLL" #x)

#define KPLL_STATIC_CHECK_FVCO(x, r, fb)                                                                                                \
    static_assert((KPLL_FVCO(r, fb) >= KPLL_FVCO_MIN) && (KPLL_FVCO(r, fb) <= KPLL_FVCO_MAX), "PLL_" #x ": FVCO out of range")

// PLL SYS

#define KCFG_PLLSYS_REFDIV  1U                                          // REFDIV = 1, f(ref) = 12-MHz
#define KCFG_PLLSYS_FBDIV   125U                                        // FBDIV = 125, f(vco) = 1500-MHz
#define KCFG_PLLSYS_POSTDIV1    5U                                      // VCO / 5
#define KCFG_PLLSYS_POSTDIV2    2U                                      // VCO / (5 * 2), 150-MHz

// PLL USB

#define KCFG_PLLUSB_REFDIV  1U                                          // REFDIV = 1, f(ref) = 12-MHz
#define KCFG_PLLUSB_FBDIV   40U                                         // FBDIV = 40, f(vco) = 480-MHz
#define KCFG_PLLUSB_POSTDIV1    5U                                      // VCO / 5
#define KCFG_PLLUSB_POSTDIV2    2U                                      // VCO / (5 * 2), 48-MHz
