/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "machine" manager module.
 */

#include    "machine/machine.h"

#include    <stdint.h>

#include    "macros.h"
#include    "macros_core.h"     // IWYU pragma: keep (for symbol core_getCSR)
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "types.h"

/*
 * \brief stub_machine_restart
 *
 * - Disable all the system interruption
 * - Restart
 *
 */
int32_t stub_machine_restart(void) {

// Stop all the interruptions and restart

    INTERRUPTION_OFF;
    while (true) { ; }

    return KERR_MACHINE_NOERR;
}

/*
 * \brief stub_machine_readPC
 *
 * - Return the PC of the selected process
 *
 */
int32_t stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc) {
    uint8_t     pcOffset = 0U;

// uKOS-X stack frame:
//
//  ....
//  mepc                            -> pcOffset += 1
//  mcause                          -> pcOffset += 1
//  mstatus                         -> pcOffset += 1
//  core                            -> pcOffset += 1
//  PLIC-mth                        -> pcOffset  = 0

//               PLIC   core  mstatus   mcause    mepc
//               ----   ----  -------   ------    ----
    pcOffset +=  +0U    +1U    +1U       +1U      +1U;

    *pc = (stackProcess[pcOffset]);
    return KERR_SYSTEM_NOERR;
}

/*
 * \brief stub_machine_readFunctionName
 *
 * - Return the function name that belong to a given PC
 *
 */
int32_t stub_machine_readFunctionName(const uintptr_t pc, const char_t **function) {

    UNUSED(pc);

    *function = nullptr;
    return KERR_SYSTEM_NOERR;
}
