/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "machine" manager module.
 */

#include    "machine/machine.h"

#include    <stdint.h>

#include    "Registers/RP2350_ticks.h"
#include    "Registers/RP2350_watchdog.h"
#include    "macros.h"
#include    "macros_core.h"
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
    REG(TICKS)->WATCHDOG_CTRL   = TICKS_WATCHDOG_CTRL_ENABLE;
    REG(TICKS)->WATCHDOG_CYCLES = 10U;

    INST_SYNC_BARRIER;
    REG(WATCHDOG)->CTRL = WATCHDOG_CTRL_ENABLE;
    REG(WATCHDOG)->LOAD = 10U;
    DATA_SYNC_BARRIER;
    while (true) { ; }

    return KERR_SYSTEM_NOERR;
}

/*
 * \brief stub_machine_readPC
 *
 * - Return the PC of the selected process
 *
 */
int32_t stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc) {
    uint8_t     pcOffset = 0U;
    uintptr_t   lr;

// uKOS-X stack frame:
//
//  xPSR
//  s15..s0
//  pc
//  lr (old)                        -> pcOffset += 1
//  r12                             -> pcOffset += 1
//  r3..r0                          -> pcOffset += ((3 - 0) + 1)
//  r11..r4                         -> pcOffset += ((11 - 4) + 1)
//  basepri                         -> pcOffset += 1
//  s31..s16 (if FPU)               -> pcOffset += ((31 - 16) + 1)
//  lr (new)                        -> pcOffset  = 0

    lr = stackProcess[0];

// If the FPU was used                        s31 to s16
//                                            -----------
    if ((lr & (1U<<4U)) == 0U) { pcOffset += ((31U-16U)+1U); }

//               lr (new) basepri       r11..r4         r3..r0      r12  lr (old)
//               -------- -------    -------------   -------------  ---  --------
    pcOffset +=      +1U    +1U      +((11U-4U)+1U)  +((3U-0U)+1U)  +1U    +1U;

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

    #ifndef __clang__
            intptr_t    offset, nameLen;
    const   uintptr_t   *ptr;

    ptr = (const uintptr_t *)((pc + 2U) & (~0x3U));

    for (offset = 1; (offset < (intptr_t)(16U * 1024U)) && ((uintptr_t)&ptr[-offset] > (uintptr_t)0x0U); ++offset) {
        if ((ptr[-offset] & (uintptr_t)0xFFFFFF00U) == (uintptr_t)0xFF000000U) {
            nameLen = (intptr_t)(ptr[-offset] & (uintptr_t)0xFFU);
            *function = &((const char_t *)&ptr[-offset])[-nameLen];
            return KERR_SYSTEM_NOERR;
        }

    }
    #endif

    *function = nullptr;
    return KERR_SYSTEM_NOERR;
}
