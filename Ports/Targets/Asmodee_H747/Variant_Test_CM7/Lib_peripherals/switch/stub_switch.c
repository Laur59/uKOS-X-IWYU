/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "switch" manager module.
 */

#include    "switch/switch.h"

#include    <stdint.h>

#include    "Registers/stm32H747_CM7_gpio.h"
#include    "board.h"
#include    "macros_core.h"
#include    "macros_soc.h"      // IWYU pragma: keep (for symbol KNVIC_PRIORITY_SHIFT)
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
    switches |= ((GPIOB->IDR>>8U)  & 0x01U);
    switches |= ((GPIOB->IDR>>13U) & 0x02U);
    switches |= ((GPIOB->IDR>>13U) & 0x04U);
    switches |= ((GPIOB->IDR<<1U)  & 0x08U);
    switches |= ((GPIOA->IDR & (1U<<BPUSH_0)) == 0U) ? 0x10U : 0U;
    *mode = (switches & 0x1FU);
    RETURN_INT_RESTORE(KERR_SWITCH_NOERR);
}
