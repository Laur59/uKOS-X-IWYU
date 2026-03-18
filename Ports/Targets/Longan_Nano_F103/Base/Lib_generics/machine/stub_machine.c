/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "machine" manager module.
 */

#include    "machine/machine.h"

#include    <stddef.h>
#include    <stdint.h>

#include    "macros.h"
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
//  mepc                            -> pcOffset += 1
//  mcause                          -> pcOffset += 1
//  mstatus                         -> pcOffset += 1
//  ECLIC-mth                       -> pcOffset += 1
//  t6..t3                          -> pcOffset += ((6 - 3) + 1)
//  s11..s2                         -> pcOffset += ((11 - 2) + 1)
//  a6..a0                          -> pcOffset += ((6 - 0) + 1)
//  s1..s0                          -> pcOffset += ((1 - 0) + 1)
//  tp2..tp0                        -> pcOffset += ((2 - 0) + 1)
//  tp                              -> pcOffset += 1
//  gp                              -> pcOffset += 1
//  ra                              -> pcOffset += 1
//  x0 (void)                       -> pcOffset  = 0

//               x0   ra   gp   tp     tp2..tp0        s1..s0         a6..a0         s11..s2        t6..t3      ECLIC  mstatus   mcause     mepc
//               --   --   --   --    ----------     ----------     ----------     -----------     ----------   -----  -------   ------     ----
    pcOffset +=  +1U  +1U  +1U  +1U  +((2U-0U)+1U)  +((1U-0U)+1U)  +((6U-0U)+1U)  +((11U-2U)+1U)  +((6U-3U)+1U)  +1U     +1U       +1U      +1U;

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
