/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Nucleo_H743 – Stub for the switch manager.
 */

#include    "switch/switch.h"

#include    <stdint.h>

#include    "Registers/stm32H743_gpio.h"
#include    "board.h"
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

    *mode = ((GPIOC->IDR & (1U<<BSW_0)) != 0U) ? 1U : 0U;
    return KERR_SWITCH_NOERR;
}
