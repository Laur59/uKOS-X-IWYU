/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 */

/*!
 * \file
 * \ingroup app_sema
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Get the semaphore "urt0 - RX char", handle
 *                Waiting for the semaphore "urt0 - RX char", timeout 500-ms
 *                  - if triggered
 *                      - pulse on the LED 1
 *                  - else (timeout)
 *                      - Waiting for the remaining time
 *                      - pulse on the LED 1
 *                      - pulse on the LED 2
 *
 */

#include    <stdint.h>

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
#include    "urt0/urt0.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "basic        Example of how to use semaphores.         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  basic\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Basic,                              // Module name (the first letter has to be upper case)
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
 * - P0: Get the semaphore "urt0 - RX char", handle
 *       Waiting for the semaphore "urt0 - RX char", timeout 500-ms
 *          - if triggered
 *              - pulse on the LED 1
 *          - else (timeout)
 *              - Waiting for the remaining time
 *              - pulse on the LED 1
 *              - pulse on the LED 2
 *
 */
[[noreturn]]
static void aProcess_0(const void *argument) {
    int32_t     status;
    sema_t      *semaphore;

    UNUSED(argument);

    while (kern_getSemaphoreById(KURT0_SEMAPHORE_RX, &semaphore) != KERR_KERN_NOERR) { kern_suspendProcess(1U); }

    while (true) {
        status = kern_waitSemaphore(semaphore, 500U);

// Maintains the sampling rate always @ 500-ms
// Thanks to the kern_suspendProcess(KWAIT_REMAINING_TIMEOUT);

        if (status == KERR_KERN_NOERR) {

// We got an event after xx-ms
// To maintain the sampling rate @ 500-ms, we should wait (500-xx)-ms
// Thanks to the kern_suspendProcess(KWAIT_REMAINING_TIMEOUT);

            kern_suspendProcess(KWAIT_REMAINING_TIMEOUT);
            led_on(KLED_1);
            led_on(KLED_2);
            kern_suspendProcess(50U);
            led_off(KLED_1);
            led_off(KLED_2);

        }
        else {

// Timeout of 500-ms (stable)

            led_on(KLED_1);
            kern_suspendProcess(50U);
            led_off(KLED_1);
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
                    proc_t      *process_0;
    static  const   urtxCnf_t   configureURTx = {
                                    .oNBBits   = KSERIAL_NB_BITS_8,
                                    .oStopBits = KSERIAL_STOPBITS_1,
                                    .oParity   = KSERIAL_PARITY_NONE,
                                    .oBaudRate = KSERIAL_BAUDRATE_DEFAULT,
                                    .oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX)
                                };

    kern_suspendProcess(100U);
    serial_configure(KURT0, &configureURTx);
    serial_flush(KURT0);

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
        KKERN_PRIORITY_LOW_01               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

// Do not return with "EXIT_OS_SUCCESS_CLI" because the "console" uses the KURT0

    LOG(KINFO_USER, "Application launched, kill the console");
    return EXIT_OS_SUCCESS;
}
