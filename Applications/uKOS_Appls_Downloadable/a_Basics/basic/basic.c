/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 */

#define P0_PERIOD 1000U
#define P1_PERIOD 1000U

/*!
 * \file
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 2 processes:
 *
 *          - P0: Every P0_PERIOD ms
 *                  - Display a message on the KSYST manager
 *                  - Toggle LED 1
 *
 *          - P1: Every P1_PERIOD ms
 *                  - Display a message on the KSYST manager
 *
 *          Note: KSYST is the default I/O channel defined by the PROCESS MACROS.
 *                In this case, it is used the channel defined by the father
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
#include    "led/led.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "basic        Example of how to use a multi printf.     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  basic\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Basic,                          // Module name (the first letter has to be upper case)
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
 * - P0: Every P0_PERIOD ms
 *          - Display a message on the KSYST manager
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
    int32_t     cpt = 0U;

    UNUSED(argument);

    while (true) {
        kern_suspendProcess(P0_PERIOD);

        (void)dprintf(KSYST, "output on the KSYST Serial Communication Manager (defined in the PROCESS macros) %"PRId32"\n", cpt++);
        led_toggle(KLED_1);
    }
}

/*
 * \brief aProcess 1
 *
 * - P1: Every P1_PERIOD ms
 *          - Display a message on the KSYST manager
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
    int32_t     cpt = 0U;

    UNUSED(argument);

    while (true) {
        kern_suspendProcess(P1_PERIOD);

        (void)dprintf(KSYST, "output on the KSYST Serial Communication Manager (defined in the PROCESS macros) %"PRId32"\n", cpt--);
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
    proc_t  *process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
    STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
    STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
    STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

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
        KKERN_PRIORITY_NORMAL_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    PROCESS_STACKMALLOC(
        1,                                  // Index
        specification_1,                    // Specifications (just use specification_x)
        aStrText_1,                         // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_1,                         // Code of the process
        aStrIden_1,                         // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_NORMAL_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }
    if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}
