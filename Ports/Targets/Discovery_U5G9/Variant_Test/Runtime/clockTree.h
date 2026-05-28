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
#define KFREQUENCY_AHB      160000000U                                  // AHB bus frequency of 160-MHz
#define KFREQUENCY_APB3     80000000U                                   // APB3 periph bus frequency of 80-MHz
#define KFREQUENCY_APB2     80000000U                                   // APB2 periph bus frequency of 80-MHz
#define KFREQUENCY_APB1     80000000U                                   // APB1 periph bus frequency of 80-MHz
#define KFREQUENCY_1GHz     1000000000U                                 // Frequency of 1-GHz
#define KFREQUENCY_1MHz     1000000U                                    // Frequency of 1-MHz
#define KFREQUENCY_1KHz     1000U                                       // Frequency of 1-KHz
#define KFREQUENCY_CORE     KFREQUENCY_AHB                              // CORE frequency
