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

#define KCRYSTAL            26000000U                                   // Quartz crystal resonator
#define KFREQUENCY_PLL0     806000000U                                  // PLL 0 frequency of 806-MHz
#define KFREQUENCY_PLL1     159714285U                                  // PLL 1 frequency of 159.7-MHz
#define KFREQUENCY_PLL2     45066666U                                   // PLL 2 frequency of 45.07-MHz
#define KFREQUENCY_AHB      403000000U                                  // AHB bus frequency of 403-MHz
#define KFREQUENCY_APB0     201500000U                                  // APB1 bus frequency of 201-MHz
#define KFREQUENCY_APB1     201500000U                                  // APB1 bus frequency of 201-MHz
#define KFREQUENCY_APB2     201500000U                                  // APB2 bus frequency of 201-MHz
#define KFREQUENCY_TIM      403000000U                                  // Timer clock 403-MHz
#define KFREQUENCY_UART     201500000U                                  // Uart clock 201-MHz
#define KFREQUENCY_SPI0     403000000U                                  // Spi0 clock 403-MHz
#define KFREQUENCY_SPI1     403000000U                                  // Spi1 clock 403-MHz
#define KFREQUENCY_SPI2     403000000U                                  // Spi2 clock 403-MHz
#define KFREQUENCY_SPI3     100750000U                                  // Spi3 clock 100-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          KCRYSTAL                                    // f(ck in), IN0 (26-MHz)
#define KPLL_FREF_MIN       13671900U                                   // f(ref) min, ~13.67-MHz
#define KPLL_FVCO_MIN       350000000U                                  // FVCO min, 350-MHz
#define KPLL_FVCO_MAX       1750000000U                                 // FVCO max, 1750-MHz
#define KPLL_FREF(r)        (KPLL_CK_IN / (r))                          // f(ref) = f(ck in) / R
#define KPLL_FVCO(r, f)     (((uint64_t)KPLL_CK_IN * (f)) / (r))        // f(vco) = f(ck in) * (F / R)

// Compile-time checks of a PLL configuration (limits from the Kendryte SDK, sysctl.c)
// Register fields hold the value - 1 (clkr = R - 1, clkf = F - 1, clkod = OD - 1, bwadj = F - 1)

#define KPLL_STATIC_CHECKS(x, r, f, od)                                                                                                 \
    static_assert(((r) >= 1U) && ((r) <= 16U), "PLL" #x ": R shall be in 1..16");                                                       \
    static_assert(((f) >= 1U) && ((f) <= 64U), "PLL" #x ": F shall be in 1..64");                                                       \
    static_assert(((od) >= 1U) && ((od) <= 16U), "PLL" #x ": OD shall be in 1..16");                                                    \
    static_assert(KPLL_FREF(r) >= KPLL_FREF_MIN, "PLL" #x ": f(ref) out of range");                                                     \
    static_assert((KPLL_FVCO(r, f) >= KPLL_FVCO_MIN) && (KPLL_FVCO(r, f) <= KPLL_FVCO_MAX), "PLL" #x ": FVCO out of range");            \
    static_assert((KPLL_FVCO(r, f) / (od)) == KFREQUENCY_PLL##x, "PLL" #x ": configuration does not match KFREQUENCY_PLL" #x)

// PLL 0

#define KCFG_PLL0DIVR       1U                                          // R = 1, f(ref) = 26-MHz
#define KCFG_PLL0DIVF       62U                                         // F = 62, f(vco) = 1612-MHz
#define KCFG_PLL0DIVOD      2U                                          // VCO / 2, 806-MHz

// PLL 1

#define KCFG_PLL1DIVR       1U                                          // R = 1, f(ref) = 26-MHz
#define KCFG_PLL1DIVF       43U                                         // F = 43, f(vco) = 1118-MHz
#define KCFG_PLL1DIVOD      7U                                          // VCO / 7, 159.7-MHz

// PLL 2

#define KCFG_PLL2DIVR       1U                                          // R = 1, f(ref) = 26-MHz
#define KCFG_PLL2DIVF       26U                                         // F = 26, f(vco) = 676-MHz
#define KCFG_PLL2DIVOD      15U                                         // VCO / 15, 45.07-MHz
