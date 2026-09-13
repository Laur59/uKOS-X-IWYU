/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     stub for the "machine" manager module.
 */

#include    "machine/machine.h"

#include    <stdint.h>

#include    "macros_core.h"     // IWYU pragma: keep (for symbol core_getCSR)
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "soc_reg.h"
#include    "types.h"

/*
 * \brief stub_machine_restart
 *
 * - Disable all the system interruption
 * - Reset the SoC
 *
 */
int32_t stub_machine_restart(void) {

// Stop all the interruptions
//
// INTERRUPTION_OFF, which the Arm boards use here, only lowers the PLIC
// priority threshold on this SoC: MIE and MSTATUS.MIE stay set, so the timer
// and the software interruptions would still be taken between the trigger and
// the reset. INTERRUPTION_OFF_HARD clears both.

    INTERRUPTION_OFF_HARD;

// Let the writes still in flight (console flush, peripherals being stopped)
// reach the bus before the SoC goes down.

    DATA_SYNC_BARRIER;

// Reset the SoC
//
// SYSCTL soft_reset (0x30) bit 0 resets the whole SoC, both harts at once. It
// is not peri_reset (0x34), whose bit 0 resets the ROM only; the Linux
// dt-bindings header conflates the two in its comment. Assigning the bit field
// is a read-modify-write of the word, so the 31 reserved bits keep their value.
//
// The second hart is not parked first. If it were in the middle of a flash
// write, a DMAC transfer or an I2C frame, the SoC restarts but the external
// device does not, and it can be left in an odd state. A clean shutdown would
// signal hart 1 (CLINT MSIP), wait for it to stop and disable the DMAC.

    sysctl->soft_reset.soft_reset = 1U;

// The reset is not immediate. Do not let the core run arbitrary code during the
// assertion window.

    while (true) { WAITING_INTERRUPTION; }

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

    *pc = stackProcess[pcOffset];
    return KERR_SYSTEM_NOERR;
}

/*
 * \brief stub_machine_readFunctionName
 *
 * - Return the function name that belong to a given PC
 *
 */
int32_t stub_machine_readFunctionName([[maybe_unused]] const uintptr_t pc, const char_t **function) {

    *function = nullptr;
    return KERR_SYSTEM_NOERR;
}
