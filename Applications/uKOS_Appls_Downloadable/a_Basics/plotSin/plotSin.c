/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Demo of a C application.
 * This application shows how to operate with the uKOS-X uKernel.
 */

/*!
 * \file
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Every 10-ms
 *                  - Compute a noisy sinus
 *                  - Send it on the serial comm (using the Arduino format)
 *                  - Toggle LED 1 with decimation of 10
 *
 *          Used for the scope observation.
 *
 *          1. Use CoolTerm to display the results (using the Arduino format)
 *          2. Download a uKOS-X application (e.g. plotSin)
 *
 */

#include    <inttypes.h>
#include    <math.h>
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
#include    "random/random.h"
#include    "record/record.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "plotSin      Example of plot functions on CoolTerm2.   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  plotSin\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    PlotSin,                            // Module name (the first letter has to be upper case)
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

#ifndef M_PI
#define M_PI                3.14159265358979323846
#endif

#define KAMPLITUDE_BASIC    5.0
#define KAMPLITUDE_NOISE    2.0
#define KAMPLITUDE_FINAL    (400.0 / KAMPLITUDE_BASIC)

/*
 * \brief aProcess 0
 *
 * - P0: Every 10-ms
 *          - Compute a noisy sinus
 *          - Send it on the serial comm (using the Arduino format)
 *          - Toggle LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
    uint16_t    x;
    uint32_t    random;
    float64_t   y;
    uint32_t ledDecimationCounter = 0;

    UNUSED(argument);

// Wait a bit (to allow to switch CoolTerm2 in the right mode)

    kern_suspendProcess(10000U);

    while (true) {
        for (x = 0U; x < 360U; x += 1) {

// Compute the genuine sin
// Add a random noise
// Scale the final signal

            y = KAMPLITUDE_BASIC * sin(x * M_PI / 180.0);

            random_read(KRANDOM_SOFT, &random, 1u);
            y = y + ((((float64_t)random / KRAND_MAX) - 0.5) * KAMPLITUDE_NOISE);
            y = KAMPLITUDE_FINAL * y;

// Print the data using the Arduino format in CoolTerm2

            (void)dprintf(KSYST, "%"PRIu16"\t%5.2f\n", x, y);
            kern_suspendProcess(10U);
        }
        ledDecimationCounter++;
        if (ledDecimationCounter == 10U) {
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
    proc_t  *process_0;

    UNUSED(argc);
    UNUSED(argv);

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification_0,                    // Specifications (just use specification_x)
        nullptr,                            // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_0,                         // Code of the process
        nullptr,                            // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_MEDIUM_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

// Do not return with "EXIT_OS_SUCCESS_CLI" because the "console" uses the KURT0

    LOG(KINFO_USER, "Application launched, kill the console");
    return EXIT_OS_SUCCESS;
}
