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
#define KFREQUENCY_PLL0     299000000U                                  // AHB bus frequency of 299-MHz
#define KFREQUENCY_PLL1     299000000U                                  // AHB bus frequency of 299-MHz
#define KFREQUENCY_PLL2     403000000U                                  // AHB bus frequency of 403-MHz
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
