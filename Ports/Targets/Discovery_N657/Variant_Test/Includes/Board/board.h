/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        Board mapping.
 */

#pragma once

#ifndef Discovery_N657_S
#define Discovery_N657_S
#endif

#include    "macros_core.h" // IWYU pragma: keep (required for REG)
#include    "soc_reg.h"     // IWYU pragma: keep (required for GPIOG)
#include    "Registers/stm32N657_gpiog.h"   // IWYU pragma: export (for GPIOG_S)

// GPIO settings
// -------------

#define LED_GREEN_ON        (REG(GPIOO)->ODR |=            (1<<BLED_0))     //
#define LED_GREEN_OFF       (REG(GPIOO)->ODR &= (uint32_t)~(1<<BLED_0))     //
#define LED_GREEN_TOGGLE    (REG(GPIOO)->ODR ^=            (1<<BLED_1))     //
#define LED_RED_ON          (REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_2))     //
#define LED_RED_OFF         (REG(GPIOG)->ODR |=            (1<<BLED_2))     //
#define LED_RED_TOGGLE      (REG(GPIOG)->ODR ^=            (1<<BLED_2))     //

#define KNB_LED             3U                                              // Number of LEDs

// PORTs

#define BLED_0              1U                                              // PORT O 1, LED
#define BLED_1              10U                                             // PORT G 10, LED
#define BLED_2              15U                                             // PORT E 15, LED
#define BSW_0               13U                                             // PORT C 13, SW1
#define BLCD_NRST           1U                                              // PORT E 1, LCD reset
#define BLCD_POWER          3U                                              // PORT Q 3, LCD power
#define BBL_CTRL            6U                                              // PORT Q 6, LCD backlignt
