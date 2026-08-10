/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef Nucleo_N657_S
#define Nucleo_N657_S
#endif

#include    "macros_core.h" // IWYU pragma: keep (required for REG)
#include    "soc_reg.h"     // IWYU pragma: keep (required for GPIOG)
#include    "Registers/stm32N657_gpiog.h"   // IWYU pragma: export (for GPIOG_S)

// GPIO settings
// -------------

#define LED_BLUE_ON         (REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_1))     //
#define LED_BLUE_OFF        (REG(GPIOG)->ODR |=            (1<<BLED_1))     //
#define LED_BLUE_TOGGLE     (REG(GPIOG)->ODR ^=            (1<<BLED_1))     //
#define LED_RED_ON          (REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_2))     //
#define LED_RED_OFF         (REG(GPIOG)->ODR |=            (1<<BLED_2))     //
#define LED_RED_TOGGLE      (REG(GPIOG)->ODR ^=            (1<<BLED_2))     //
#define LED_GREEN_ON        (REG(GPIOG)->ODR &= (uint32_t)~(1<<BLED_3))     //
#define LED_GREEN_OFF       (REG(GPIOG)->ODR |=            (1<<BLED_3))     //
#define LED_GREEN_TOGGLE    (REG(GPIOG)->ODR ^=            (1<<BLED_3))     // Led macros

#define ANALYSER_ON         (REG(GPIOG)->ODR &= (uint32_t)~(1<<BANALYSER))  //
#define ANALYSER_OFF        (REG(GPIOG)->ODR |=            (1<<BANALYSER))  //
#define ANALYSER_TOGGLE     do { \
                                REG(GPIOG)->ODR ^= (1U<<BANALYSER);  \
                                (void)(REG(GPIOG)->ODR);            \
                            } while (0)                                     // Analyser macros

#define KNB_LED             4U                                              // Number of LEDs

// PORTs

#define BLED_0              15U                                             // PORT E 15, LED
#define BLED_1              8U                                              // PORT G 8, LED
#define BLED_2              10U                                             // PORT G 10, LED
#define BLED_3              0U                                              // PORT G 0, LED
#define BANALYSER           1U                                              // PORT G 1, Analyser
#define BSW_0               13U                                             // PORT C 13, SW1
