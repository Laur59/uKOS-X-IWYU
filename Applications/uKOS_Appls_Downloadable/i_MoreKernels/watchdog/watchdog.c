/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 * Expected results:
 *          Serial terminal output
 *          uKOS-X > run
 *          Execute the downloaded application.
 *          Run the downloaded application...
 *
 *  uKOS-X >
 *  Watchdog in automatic mode (trying for 10'000-ms)
 *  Watchdog in manual mode    (trying for 10'000-ms)
 *
 *  Now waiting 20-s for the watchdog restart
 *  Elapsed 0-s!
 *  Elapsed 1-s!
 *  Elapsed 2-s!
 *  Elapsed 3-s!
 *  Elapsed 4-s!
 *  Elapsed 5-s!
 *  Elapsed 6-s!
 *  Elapsed 7-s!
 *  Elapsed 8-s!
 *  Elapsed 9-s!
 *  Elapsed 10-s!
 *  Elapsed 11-s!
 *  Elapsed 12-s!
 *  Elapsed 13-s!
 *  Elapsed 14-s!
 *  Elapsed 15-s!
 *  Elapsed 16-s!
 *  Elapsed 17-s!
 *  Elapsed 18-s!
 *  Elapsed 19-s!
 *  Elapsed 20-s!
 */

/*!
 * \file
 * \ingroup app_moreKernel
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Set the watchdog in auto mode (1000-ms)
 *                Wait 10000-ms (The watchdog is maintained by a daemon)
 *                Repeat 100 times
 *                  - Set the watchdog in manual mode (100-ms)
 *                  - Wait 70-ms
 *                At the output of the loop the watchdog has to restart the system
 *
 */

#include    <inttypes.h>
#include    <stdio.h>

#include    "crt0.h"
#include    "serial/serial.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"
#include    "watchdog/watchdog.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "watchdog     Example of how to use the watchdog.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  watchdog\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Watchdog,                           // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                        // Family (defined in the module.h)
    KNUM_ROMABLE_0,                     // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    prgm,                               // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1u<<BSHOW) | (1u<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);

#else
MODULE(
    UserAppl,                           // Module name (the first letter has to be upper case)
    KID_FAM_APPLICATIONS,               // Family (defined in the module.h)
    KNUM_APPLICATION,                   // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    aStart,                             // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);
#endif

/*
 * \brief aProcess 0
 *
 * - P0: Set the watchdog in auto mode (1000-ms)
 *       Wait 10000-ms (The watchdog is maintained by a daemon)
 *       Repeat 100 times
 *          - Set the watchdog in manual mode (100-ms)
 *          - Wait 70-ms
 *       At the output of the loop the watchdog has to restart the system
 */
[[noreturn]]
static void aProcess_0(const void *argument) {
    uint16_t    i;

    UNUSED(argument);

    kern_suspendProcess(1000U);

// Watchdog in automatic mode

    (void)dprintf(KSYST, "\nWatchdog in automatic mode (trying for 10'000-ms)\n");
    watchdog_arm(1000U, KWATCHDOG_AUTO);

    kern_suspendProcess(10000U);

// Watchdog in manual mode

    (void)dprintf(KSYST, "Watchdog in manual mode    (trying for 10'000-ms)\n");
    for (i = 0U; i < 100U; i++) {
        kern_suspendProcess(60U);
        watchdog_arm(100U, KWATCHDOG_MANUAL);
    }

// Now relaunch the watchdog for 20-s and waiting for the restart

    watchdog_arm(20000U, KWATCHDOG_MANUAL);
    (void)dprintf(KSYST, "\nNow waiting 20-s for the watchdog restart\n");

    i = 0;
    while (true) {
        (void)dprintf(KSYST, "Elapsed %"PRIu16"-s!\n", i++);
        kern_suspendProcess(1000U);
    }
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
    proc_t  *process_0;

// ---------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
    STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";

    UNUSED(argc);
    UNUSED(argv);

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification_0,                    // Specifications (just use specification_x)
        aStrText_0,                         // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_0,                         // Code of the process
        aStrIden_0,                         // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_14               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}
