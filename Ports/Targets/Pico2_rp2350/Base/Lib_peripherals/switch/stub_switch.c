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
; Goal:     stub for the "switch" manager module.
;
;-----
;------------------------------------------------------------------------
*/

#include    "switch/switch.h"

#include    <stdint.h>

#include    "Registers/RP2350_sio.h"
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

    *mode = ((REG(SIO)->GPIO_IN & (1U<<BSW_0)) != 0U) ? 1U : 0U;
    return KERR_SWITCH_NOERR;
}
