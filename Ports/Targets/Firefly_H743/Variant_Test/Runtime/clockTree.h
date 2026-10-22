/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Clock tree definitions.
 */

#pragma once

// Main system clocks
// ------------------

// SPI 1,2,3                                ck = PLL1 Q
// SPI 4,5                                  ck = rcc_pclk2 -> APB2
// SPI 6                                    ck = rcc_pclk4 -> APB4
// SDMM                                     ck = PLL1 Q
// QUAD SPI                                 ck = rcc_hclk3 -> AHB3
// I2C 1,2,3                                ck = rcc_pclk1 -> APB1
// I2C 4                                    ck = rcc_pclk4 -> APB4
// LPUSART 1                                ck = rcc_pclk4 -> APB4
// USART 1,6                                ck = rcc_pclk2 -> APB2
// USART 2,3,4,5,7,8                        ck = rcc_pclk1 -> APB1
// FMC                                      ck = rcc_hclk3 -> AHB3
// ADC 1,2,3                                ck = PLL2 P
// RNG                                      ck = PLL1 Q
// USB                                      ck = PLL3 Q
// LTDC                                     ck = PLL3 R
// LPTIM 1                                  ck = rcc_pclk1 -> APB1
// LPTIM 2,3,4,5                            ck = rcc_pclk4 -> APB4
// TIM 1,2,3,4,5,6,7,8,12,13,14,15,16,17    ck = ??? -> A??

#define KCRYSTAL            16000000U                                   // Quartz crystal resonator
#define KFREQUENCY_PLL1P    480000000U                                  // PLL 1 P bus frequency of 480-MHz
#define KFREQUENCY_PLL1Q    240000000U                                  // PLL 1 Q bus frequency of 240-MHz
#define KFREQUENCY_PLL1R    120000000U                                  // PLL 1 R bus frequency of 120-MHz
#define KFREQUENCY_PLL2P    100000000U                                  // PLL 2 P bus frequency of 100-MHz
#define KFREQUENCY_PLL2Q    50000000U                                   // PLL 2 Q bus frequency of 50-MHz
#define KFREQUENCY_PLL2R    25000000U                                   // PLL 2 R bus frequency of 25-MHz
#define KFREQUENCY_PLL3P    120000000U                                  // PLL 3 P bus frequency of 120-MHz
#define KFREQUENCY_PLL3Q    48000000U                                   // PLL 3 Q bus frequency of 48-MHz
#define KFREQUENCY_PLL3R    24000000U                                   // PLL 3 R bus frequency of 24-MHz

#define KD1CPRE             1U                                          // Div 1
#define KHPRE               2U                                          // Div 2
#define KD1PPRE             1U                                          // Div 1
#define KD2PPRE1            2U                                          // Div 2
#define KD2PPRE2            2U                                          // Div 2
#define KD3PPRE             2U                                          // Div 2
#define KTIMPRE             1U                                          // Div 1

#define KFREQUENCY_AHB      (KFREQUENCY_PLL1P / KD1CPRE)                // AHB bus frequency of 480-MHz
#define KFREQUENCY_APB      (KFREQUENCY_AHB / KHPRE)                    // APB bus frequency of 240-MHz

#define KFREQUENCY_AXI      KFREQUENCY_APB                              // AXI bus frequency of 240-MHz
#define KFREQUENCY_AHB1     KFREQUENCY_APB                              // AHB1 bus frequency of 240-MHz
#define KFREQUENCY_AHB2     KFREQUENCY_APB                              // AHB2 bus frequency of 240-MHz
#define KFREQUENCY_AHB3     KFREQUENCY_APB                              // AHB3 bus frequency of 240-MHz
#define KFREQUENCY_AHB4     KFREQUENCY_APB                              // AHB4 bus frequency of 240-MHz
#define KFREQUENCY_APB1     (KFREQUENCY_APB / KD2PPRE1)                 // APB1 bus frequency of 120-MHz
#define KFREQUENCY_APB2     (KFREQUENCY_APB / KD2PPRE2)                 // APB2 bus frequency of 120-MHz
#define KFREQUENCY_APB3     (KFREQUENCY_APB / KD1PPRE)                  // APB3 bus frequency of 240-MHz
#define KFREQUENCY_APB4     (KFREQUENCY_APB / KD3PPRE)                  // APB4 bus frequency of 120-MHz
#define KFREQUENCY_TIM      (KFREQUENCY_APB / KTIMPRE)                  // Timer clock 240-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency

// PLL settings
// ------------

#define KPLL_CK_IN          64000000U                                   // f(ck in), PLLSRC = HSI (64-MHz)
#define KPLL_FVCO_MIN       192000000U                                  // FVCO min, 192-MHz (wide VCO range)
#define KPLL_FVCO_MAX       960000000U                                  // FVCO max, 960-MHz (wide VCO range, VOS0)
#define KPLL_FREF(m)        (KPLL_CK_IN / (m))                          // f(ref) = f(ck in) / M
#define KPLL_FREF_MIN(rge)  (1000000u<<(rge))                           // f(ref) min for PLLxRGE, 1-MHz<<rge
#define KPLL_FREF_MAX(rge)  (2000000u<<(rge))                           // f(ref) max for PLLxRGE, 2-MHz<<rge
#define KPLL_FVCO(m, n)     (((uint64_t)KPLL_CK_IN * (n)) / (m))        // f(vco) = f(ck in) * (N / M)

// Compile-time checks of a PLL configuration (RM0433, integer mode)

#define KPLL_STATIC_CHECKS(x, m, rge, n, p, q, r)                                                                                       \
    static_assert(((m) >= 1U) && ((m) <= 63U), "PLL" #x ": DIVM shall be in 1..63");                                                    \
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

#define KCFG_PLL1DIVM       4U                                          // M = 4, f(ref) = 16-MHz
#define KCFG_PLL1RGE        3U                                          // f(ref) in 8-MHz..16-MHz
#define KCFG_PLL1DIVN       60U                                         // N = 60, f(vco) = 960-MHz
#define KCFG_PLL1DIVP       2U                                          // VCO / 2, 480-MHz
#define KCFG_PLL1DIVQ       4U                                          // VCO / 4, 240-MHz
#define KCFG_PLL1DIVR       8U                                          // VCO / 8, 120-MHz

// PLL 2

#define KCFG_PLL2DIVM       4U                                          // M = 4, f(ref) = 16-MHz
#define KCFG_PLL2RGE        3U                                          // f(ref) in 8-MHz..16-MHz
#define KCFG_PLL2DIVN       25U                                         // N = 25, f(vco) = 400-MHz
#define KCFG_PLL2DIVP       4U                                          // VCO / 4, 100-MHz
#define KCFG_PLL2DIVQ       8U                                          // VCO / 8, 50-MHz
#define KCFG_PLL2DIVR       16U                                         // VCO / 16, 25-MHz

// PLL 3

#define KCFG_PLL3DIVM       4U                                          // M = 4, f(ref) = 16-MHz
#define KCFG_PLL3RGE        3U                                          // f(ref) in 8-MHz..16-MHz
#define KCFG_PLL3DIVN       15U                                         // N = 15, f(vco) = 240-MHz
#define KCFG_PLL3DIVP       2U                                          // VCO / 2, 120-MHz
#define KCFG_PLL3DIVQ       5U                                          // VCO / 5, 48-MHz
#define KCFG_PLL3DIVR       10U                                         // VCO / 10, 24-MHz
