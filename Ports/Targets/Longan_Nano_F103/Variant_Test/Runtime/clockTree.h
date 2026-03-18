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

#define KFREQUENCY_AHB      108000000U                                  // AHB bus frequency of 108-MHz
#define KFREQUENCY_APB1     54000000U                                   // APB1 bus frequency of 54-MHz
#define KFREQUENCY_APB2     54000000U                                   // APB2 bus frequency of 54-MHz
#define KFREQUENCY_TIM      108000000U                                  // Timer clock 108-MHz (APB2 x 2)
#define KFREQUENCY_UART     54000000U                                   // Uart clock 54-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency
