/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Board mapping.
 */

#pragma once

#include    "macros_core.h"

// System identifiers
// ------------------

#define KCPU                "RISC-V Hazard3"
#define KCONTROLLER         "rp2350"
#define KBOARD              "Pico2 rp2350 RISC-V (Variant_Test)"
#define KTARGET             "Pico2_rp2350_RV32IMAC"

#define LED_SYSTEM_ON       (REG(SIO)->GPIO_OUT_SET = (1u<<BLED_s))
#define LED_SYSTEM_OFF      (REG(SIO)->GPIO_OUT_CLR = (1u<<BLED_s))
#define LED_SYSTEM_TOGGLE   (REG(SIO)->GPIO_OUT_XOR = (1u<<BLED_s))

#define LED_YELLOW_ON       (REG(SIO)->GPIO_OUT_SET = (1u<<BLED_0))
#define LED_YELLOW_OFF      (REG(SIO)->GPIO_OUT_CLR = (1u<<BLED_0))
#define LED_YELLOW_TOGGLE   (REG(SIO)->GPIO_OUT_XOR = (1u<<BLED_0))

#define LED_GREEN_ON        (REG(SIO)->GPIO_OUT_SET = (1u<<BLED_1))
#define LED_GREEN_OFF       (REG(SIO)->GPIO_OUT_CLR = (1u<<BLED_1))
#define LED_GREEN_TOGGLE    (REG(SIO)->GPIO_OUT_XOR = (1u<<BLED_1))

#define LED_RED_ON          (REG(SIO)->GPIO_OUT_SET = (1u<<BLED_2))
#define LED_RED_OFF         (REG(SIO)->GPIO_OUT_CLR = (1u<<BLED_2))
#define LED_RED_TOGGLE      (REG(SIO)->GPIO_OUT_XOR = (1u<<BLED_2))

#define KNB_LED             4u

// GPIO pin assignments

#define BLED_s              25u     // GPIO25, LED system
#define BLED_0              11u     // GPIO11, LED yellow
#define BLED_1              12u     // GPIO12, LED green
#define BLED_2              13u     // GPIO13, LED red

#define BSW_0               21u     // GPIO21, SW1
