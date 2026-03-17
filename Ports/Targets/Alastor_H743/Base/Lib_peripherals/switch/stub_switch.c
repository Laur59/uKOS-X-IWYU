/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_switch
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the "switch" manager module.
;
;-----
;------------------------------------------------------------------------
*/

#include    "switch/switch.h"

#include    <stdint.h>

#include    "Registers/stm32H743_gpio.h"
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
    switches |= ((GPIOC->IDR>>10U) & 0x01U);
    switches |= ((GPIOC->IDR>>10U) & 0x02U);
    switches |= ((GPIOC->IDR>>10U) & 0x04U);
    switches |= ((GPIOC->IDR>>10U) & 0x08U);
    *mode = (switches & 0x0FU);
    RETURN_INT_RESTORE(KERR_SWITCH_NOERR);
}
