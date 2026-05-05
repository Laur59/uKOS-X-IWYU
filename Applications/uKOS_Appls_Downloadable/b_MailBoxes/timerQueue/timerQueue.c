/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 */

/*!
 * \file
 * \ingroup app_lowLevel
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Define the switch ALLOW_HARDWARE_ACCESS_S to permit
 *          the hardware accesses
 *
 *          Launch 1 processes:
 *
 *          - P0: Get the mailbox "Queue tim" handle
 *                Waiting for a counter in the Queue "Queue tim" under timeout
 *                  - Display & verify the received counter
 *                  - Toggle LED 1
 *
 */

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>

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

#define ALLOW_HARDWARE_ACCESS_S         // define: elevate the privilege for permitting hardware accesses
                                        // undef: do not permit hardware accesses

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "timerQueue   Example of how to use interruptions.      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  timerQueue\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    TimerQueue,                         // Module name (the first letter has to be upper case)
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

// Application specific
// ====================

// Prototypes

extern  void    stub_intr_timer_init(void);

/*
 * \brief aProcess
 *
 * - P0: Get the semaphore "Queue tim" handle
 *       Waiting for a counter in the mailbox "Queue tim" under timeout
 *          - Display & verify the received counter
 *          - Toggle the LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
    uintptr_t   counter = 0U, expectedCounter = 0U;
    int32_t     status;
    mbox_t      *queue;
    mcnf_t      configure = {
                    .oNbMaxPacks = 10U,
                    .oDataEntrySize = 0U
                };
    uint32_t ledDecimationCounter = 0U;

    UNUSED(argument);

    #if(defined(ALLOW_HARDWARE_ACCESS_S))
    LOG(KWARNING_USER, "Direct hardware access permitted");

    PRIVILEGE_ELEVATE;
    stub_intr_timer_init();
    PRIVILEGE_RESTORE;

    #else
    LOG(KFATAL_USER, "Generate an Hard Fault, privilege violatio: System stopped");

    stub_intr_timer_init();
    #endif

    if (kern_createMailbox("Queue tim", &queue) != KERR_KERN_NOERR) {
        LOG(KFATAL_USER, "No queue!");
        exit(EXIT_OS_FAILURE);
    }

    if (kern_setMailbox(queue, &configure) != KERR_KERN_NOERR) {
        LOG(KFATAL_USER, "Configure queue");
        exit(EXIT_OS_FAILURE);
    }

    while (true) {
        status = kern_readQueue(queue, &counter, 1000U);
        if (status == KERR_KERN_TIMEO) {
            (void)dprintf(KSYST, "Timeout Error Mailbox\n");
        }
        else {
            if (counter == expectedCounter) {
                (void)dprintf(KSYST, "Counter = %"PRIuPTR"\n", counter);
                counter++;
                expectedCounter++;
            }
            else {
                LOG(KFATAL_USER, "Coherency problem!!");
                exit(EXIT_OS_FAILURE);
            }

        }
        record_trace("Test 2", 1);
        if (ledDecimationCounter++ == 100U) {
            led_toggle(KLED_1);
            ledDecimationCounter = 0U;
        }
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
    proc_t  *process;

// -------------------------------I-----------------------------------------I--------------I

    STRG_LOC_CONST(aStrIden[]) = "Process_User";
    STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2026";

    UNUSED(argc);
    UNUSED(argv);

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess,                           // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_14               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}
