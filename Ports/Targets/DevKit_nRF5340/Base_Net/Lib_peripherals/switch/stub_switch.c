/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; stub_switch.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     stub for the "led" manager module.
;
;-----
;------------------------------------------------------------------------
*/

#include    "switch/switch.h"

#include    <stdint.h>

#include    "board.h"
#include    "macros_core.h"
#include    "os_errors.h"
#include    "soc_reg.h"

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

    *mode  = 0U;
    *mode |= ((REG(P0)->IN & (1U<<BSW_0)) != 0U) ? 0U : (1U<<0U);
    *mode |= ((REG(P0)->IN & (1U<<BSW_1)) != 0U) ? 0U : (1U<<1U);
    return KERR_SWITCH_NOERR;
}
