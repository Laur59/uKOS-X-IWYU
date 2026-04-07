/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     idle daemon; run when all the other processes are suspended.
 */

#include    <stdint.h>
#if ((KKERN_WITH_STATISTICS_S == true) && (KDAEMONS_WITH_STACK_INT_S == true))
#include    <stdlib.h>
#endif

#include    "macros.h"
#include    "modules.h"
#if ((KKERN_WITH_STATISTICS_S == true) && (KDAEMONS_WITH_STACK_INT_S == true))
#include    "debug.h"
#include    "kern/kern.h"
#include    "kern/private/private_processes.h"
#include    "macros_core_stackFrame.h"
#include    "macros_soc.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "serial/serial.h"
#endif
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "stack        stack: verify the stack integrity.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "stack deamon\n"
                                    "============\n\n"

                                    "Install the stack deamon\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define KEXECUTION_CORE     ((1U<<BCORE_0) | (1U<<BCORE_1) | (1U<<BCORE_2) | (1U<<BCORE_3))

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Stack,                          // Module name (the first letter has to be upper case)
    KID_FAM_DAEMONS,                // Family (defined in the module.h)
    KNUM_STACK,                     // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    prgm,                           // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    KEXECUTION_CORE                 // Execution cores
);

// Daemon specific
// ===============

#if ((KKERN_WITH_STATISTICS_S == true) && (KDAEMONS_WITH_STACK_INT_S == true))

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Deamon_stack";
STRG_LOC_CONST(aStrText[]) = "Daemon stack: verify the stack integrity. (c) EFr-2026";

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

    VAR_DECLARED_ALIGN(static uintptr_t vStack[KNB_CORES][KKERN_SZ_STACK_MM], KSTACK_ALIGNMENT);

    DAEMON_PRIVILEGED(
        core,                               // Core
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        vStack,                             // Stack location
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        local_process,                      // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_01               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "stack: create proc"); exit(EXIT_OS_PANIC); }

    LOG(KINFO_SYSTEM, "stack: daemon stack launched");
    return EXIT_OS_SUCCESS_CLI;
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - This daemon is scheduled cyclically for verifying the stack
 *   integrity (if there is enough place)
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
            bool        terminate;
            uint16_t    i;
            uint32_t    core, stackSize, j;
    const   uintptr_t   *stackStart;

    UNUSED(argument);

    DEBUG_KERN_TRACE("entry: stack integrity daemon");
    core = GET_RUNNING_CORE;

    while (true) {
        kern_suspendProcess(KDAEMONS_TIME_STACK_INT);

        for (i = 0U; i < KKERN_NB_PROCESSES; i++) {
            if ((vKern_proc[core][i].oInternal.oState & (1U<<BPROC_INSTALLED)) != 0U) {
                stackStart = vKern_proc[core][i].oSpecification.oStackStart;
                stackSize  = vKern_proc[core][i].oSpecification.oStackSize;

// Compute the length of the available process stack in bytes

                j = 0U;
                terminate = false;
                do {
                    if (*(stackStart+j) != (uintptr_t)KMAGICSTACK) {
                        vKern_proc[core][i].oStatistic.oAvStack = j * 4U;
                        terminate = true;
                    }
                } while ((++j < stackSize) && (!terminate));

                #if (KDAEMONS_ALERT_STACK_INT_S == true)
                if (j < KKERN_CRITICAL_SZ_STACK) {
                    dprint(KSYST, "!!! Caution, process %"PRIu32" has a critical free stack room of %"PRIu32" bytes\n", i, (j * 4));
                }
                #endif
            }
        }
    }
}

#else
/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {

    UNUSED(argc);
    UNUSED(argv);

    return EXIT_OS_SUCCESS_CLI;
}
#endif
