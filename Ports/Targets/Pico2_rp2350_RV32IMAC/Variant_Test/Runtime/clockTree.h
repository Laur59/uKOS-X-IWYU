/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Clock tree definitions.
 */

#pragma once

#define KCRYSTAL            12000000u       // 12 MHz crystal
#define KFREQUENCY_AHB      150000000u      // AHB bus (150 MHz)
#define KFREQUENCY_TIM      1000000u        // Timer tick (1 MHz)
#define KFREQUENCY_CORE     KFREQUENCY_AHB  // Core clock = 150 MHz
