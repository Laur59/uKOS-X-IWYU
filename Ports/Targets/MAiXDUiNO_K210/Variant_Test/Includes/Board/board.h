/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Board mapping.
 */

#pragma once

#ifndef MAiXDUiNO_K210_S
#define MAiXDUiNO_K210_S
#endif

// System identifiers
// ------------------

#define KCPU                "RISC-V RV64IMAFDC"
#define KCONTROLLER         "K210"
#define KBOARD              "MAiXDUiNO K210 RISC-V (Variant_Test)"
#define KTARGET             "MAiXDUiNO_K210"

// GPIOHS settings
// ---------------

#define LED_GREEN_OFF       (gpiohs->output_val.u32[0] |=            (1U<<BLED_0))  //
#define LED_GREEN_ON        (gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_0))  //
#define LED_GREEN_TOGGLE    (gpiohs->output_val.u32[0] ^=            (1U<<BLED_0))  //
#define LED_RED_OFF         (gpiohs->output_val.u32[0] |=            (1U<<BLED_1))  //
#define LED_RED_ON          (gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_1))  //
#define LED_RED_TOGGLE      (gpiohs->output_val.u32[0] ^=            (1U<<BLED_1))  //
#define LED_BLUE_OFF        (gpiohs->output_val.u32[0] |=            (1U<<BLED_2))  //
#define LED_BLUE_ON         (gpiohs->output_val.u32[0] &= (uint32_t)~(1U<<BLED_2))  //
#define LED_BLUE_TOGGLE     (gpiohs->output_val.u32[0] ^=            (1U<<BLED_2))  //
#define LED_1_TOGGLE        LED_RED_TOGGLE                                          //
#define LED_1_ON            LED_RED_ON                                              //
#define LED_1_OFF           LED_RED_OFF                                             // Led macros

#define KNB_LED             3U                                                      // Number of LEDs

// LEDs

#define BLED_0              8U                                                      // GPIO8  - IO12, BLED_0
#define BLED_1              9U                                                      // GPIO9  - IO13, BLED_1
#define BLED_2              10U                                                     // GPIO10 - IO14, BLED_2

// LCD

#define BLCD_DCX            2U                                                      // GPIO02 - IO38, BLCD_DCX
#define BLCD_RST            3U                                                      // GPIO03 - IO37, BLCD_RST
