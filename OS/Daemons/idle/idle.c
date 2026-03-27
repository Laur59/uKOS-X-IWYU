/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     idle daemon; run when all the others processes are suspended.
 */

#include    <stdint.h>
#include    <stdlib.h>

#include    "debug.h"
#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "idle         Idle: run when the others are off.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "idle deamon\n"
                                    "===========\n\n"

                                    "Install the idle deamon\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define KEXECUTION_CORE     ((1u<<BCORE_0) | (1u<<BCORE_1) | (1u<<BCORE_2) | (1u<<BCORE_3))

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Idle,                           // Module name (the first letter has to be upper case)
    KID_FAM_DAEMONS,                // Family (defined in the module.h)
    KNUM_IDLE,                      // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    prgm,                           // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    KEXECUTION_CORE                 // Execution cores
);

// Daemon specific
// ===============

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Deamon_idle";
STRG_LOC_CONST(aStrText[]) = "Daemon idle: run when the others are off. (c) EFr-2026";

// Prototypes

static  void    local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    uint32_t    core;
    proc_t      *process;

    UNUSED(argc);
    UNUSED(argv);

    core = GET_RUNNING_CORE;

    VAR_DECLARED_ALIGN(static uintptr_t vStack[KNB_CORES][KKERN_SZ_STACK_SS], KSTACK_ALIGNMENT);

    DAEMON_PRIVILEGED(
        core,                               // Core
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        vStack,                             // Stack location
        KKERN_SZ_STACK_SS,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        local_process,                      // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_IDLE             // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "idle: create proc"); exit(EXIT_OS_PANIC); }

    LOG(KINFO_SYSTEM, "idle: daemon idle launched");
    return EXIT_OS_SUCCESS_CLI;
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - This daemon is scheduled only when the execution list is empty
 *   This occurs when all the system processes are in the waiting state
 *   (waiting for a time, for a sync, for a semaphore, etc.)
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
    void        (*code)(uint8_t state);
    uint32_t    core;

    UNUSED(argument);

    DEBUG_KERN_TRACE("entry: idle daemon");
    core = GET_RUNNING_CORE;

    while (true) {
        code = vKern_codeRoutine[core];

// Set the low power mode (if possible)

        if (code != nullptr) {
            vKern_runProc[core]->oInternal.oState |= (1U<<BPROC_LIKE_ISR);
            code(KKERN_IDLE_IN);
            vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1U<<BPROC_LIKE_ISR);
        }
        stub_kern_setLowPower(KKERN_CPU_MODE_STOP);
        if (code != nullptr) {
            vKern_runProc[core]->oInternal.oState |= (1U<<BPROC_LIKE_ISR);
            code(KKERN_IDLE_OUT);
            vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1U<<BPROC_LIKE_ISR);
        }
        kern_switchFast();
    }
}
