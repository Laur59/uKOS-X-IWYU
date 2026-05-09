/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Stub for the machine manager.
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
 * - Restart via RP2350 watchdog
 *
 */
int32_t stub_machine_restart(void) {

    INTERRUPTION_OFF;
    REG(TICKS)->WATCHDOG_CTRL   = TICKS_WATCHDOG_CTRL_ENABLE;
    REG(TICKS)->WATCHDOG_CYCLES = 10U;

    REG(WATCHDOG)->CTRL = WATCHDOG_CTRL_ENABLE;
    REG(WATCHDOG)->LOAD = 10U;
    while (true) { ; }

    return KERR_SYSTEM_NOERR;
}

/*
 * \brief stub_machine_readPC
 *
 * - Return the PC of the selected process
 *
 * RV32IMAC KERN_SAVE_FRAME layout: sp[0] = mepc
 *
 */
int32_t stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc) {

    *pc = stackProcess[0];
    return KERR_SYSTEM_NOERR;
}

/*
 * \brief stub_machine_readFunctionName
 *
 * - Return the function name that belongs to a given PC
 *
 */
int32_t stub_machine_readFunctionName(const uintptr_t pc, const char_t **function) {

    UNUSED(pc);

    *function = nullptr;
    return KERR_SYSTEM_NOERR;
}
