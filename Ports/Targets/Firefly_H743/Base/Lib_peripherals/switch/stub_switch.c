/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:        stub for the "switch" manager module.
 */

#include    "switch/switch.h"

#include    <stdint.h>

#include    "Registers/stm32H743_gpio.h"
#include    "board.h"
#include    "macros_core.h"
#include    "os_errors.h"

/*
 * \brief stub_switch_init
 *
 * - Initialise some specific hardware parts
 *
 */
int32_t stub_switch_init(void) {
    return KERR_SWITCH_NOERR;
}

/*
 * \brief stub_switch_read
 *
 * - Read the jumper configuration
 *
 */
int32_t stub_switch_read(uint32_t *mode) {
    uint32_t    switches = 0U;

    INTERRUPTION_OFF;
    switches |= ((GPIOB->IDR & (1u<<BSW_0)) == 0U) ? (0x1U) : 0U;
    switches |= ((GPIOB->IDR & (1u<<BSW_1)) == 0U) ? (0x2U) : 0U;
    *mode = (switches & 0x03U);
    RETURN_INT_RESTORE(KERR_SWITCH_NOERR);
}
