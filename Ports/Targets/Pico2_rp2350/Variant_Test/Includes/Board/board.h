/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef Pico2_rp2350_S
#define Pico2_rp2350_S
#endif

// System identifiers
// ------------------

#define KCPU                "ARM-Cortex m33 U"
#define KCONTROLLER         "rp2350"
#define KBOARD              "Pico2 rp2350 (Variant_Test)"
#define KTARGET             "Pico2_rp2350"

// GPIO settings
// -------------

#define LED_SYSTEM_ON       (REG(SIO)->GPIO_OUT_SET = (1<<BLED_s))      //
#define LED_SYSTEM_OFF      (REG(SIO)->GPIO_OUT_CLR = (1<<BLED_s))      //
#define LED_SYSTEM_TOGGLE   (REG(SIO)->GPIO_OUT_XOR = (1<<BLED_s))      // Led macros

#define LED_YELLOW_ON       (REG(SIO)->GPIO_OUT_SET = (1<<BLED_0))      //
#define LED_YELLOW_OFF      (REG(SIO)->GPIO_OUT_CLR = (1<<BLED_0))      //
#define LED_YELLOW_TOGGLE   (REG(SIO)->GPIO_OUT_XOR = (1<<BLED_0))      // Led macros

#define LED_GREEN_ON        (REG(SIO)->GPIO_OUT_SET = (1<<BLED_1))      //
#define LED_GREEN_OFF       (REG(SIO)->GPIO_OUT_CLR = (1<<BLED_1))      //
#define LED_GREEN_TOGGLE    (REG(SIO)->GPIO_OUT_XOR = (1<<BLED_1))      // Led macros

#define LED_RED_ON          (REG(SIO)->GPIO_OUT_SET = (1<<BLED_2))      //
#define LED_RED_OFF         (REG(SIO)->GPIO_OUT_CLR = (1<<BLED_2))      //
#define LED_RED_TOGGLE      (REG(SIO)->GPIO_OUT_XOR = (1<<BLED_2))      // Led macros

#define KNB_LED             4U                                          // Number of LEDs

// PORTs

#define BLED_s              25U                                         // GPIO25, LED system
#define BLED_0              11U                                         // GPIO11, LED yellow
#define BLED_1              12U                                         // GPIO12, LED green
#define BLED_2              13U                                         // GPIO13, LED red

#define BSW_0               21U                                         // GPIO21, SW1
