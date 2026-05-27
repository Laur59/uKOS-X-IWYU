/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef Longan_Nano_F103_S
#define Longan_Nano_F103_S
#endif

// GPIO settings
// -------------

#define LED_RED_ON          (GPIOC->OCTL &= (uint32_t)~(1U<<BLED_2))    //
#define LED_RED_OFF         (GPIOC->OCTL |=            (1U<<BLED_2))    //
#define LED_RED_TOGGLE      (GPIOC->OCTL ^=            (1U<<BLED_2))    //
#define LED_BLUE_ON         (GPIOA->OCTL &= (uint32_t)~(1U<<BLED_1))    //
#define LED_BLUE_OFF        (GPIOA->OCTL |=            (1U<<BLED_1))    //
#define LED_BLUE_TOGGLE     (GPIOA->OCTL ^=            (1U<<BLED_1))    //
#define LED_GREEN_ON        (GPIOA->OCTL &= (uint32_t)~(1U<<BLED_0))    //
#define LED_GREEN_OFF       (GPIOA->OCTL |=            (1U<<BLED_0))    //
#define LED_GREEN_TOGGLE    (GPIOA->OCTL ^=            (1U<<BLED_0))    // Led macros

#define KNB_LED             3U                                          // Number of LEDs

// PORTs

#define BLED_0              1U                                          // PORT A 1, BLED_0
#define BLED_1              2U                                          // PORT A 2, BLED_1
#define BLED_2              13U                                         // PORT C 13, BLED_2
