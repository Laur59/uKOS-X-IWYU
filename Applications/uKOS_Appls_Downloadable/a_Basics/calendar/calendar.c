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
 *  Time now = 79
 *  Local time: Thu Jan  1 01:01:19 1970
 *  New timestamp (1 minute later): 139
 *  Formatted time: 01 AM
 *  Execution time: 0.000007 seconds
 *  Execution time: 1.233993 seconds
 *  New Unix time 64-bits= 1743430020000000
 *
 *  Local time: Mon Mar 31 16:07:01 2025
 *  Local time: Mon Mar 31 16:07:02 2025
 *  Local time: Mon Mar 31 16:07:03 2025
 *  Local time: Mon Mar 31 16:07:04 2025
 *  .....
 */

/*!
 * \file
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: Every 1000-ms
 *                  - Display some time manipulations on the KSYST manager
 *                  - Toggle LED 1
 *
 *          Note: KSYST is the default I/O channel defined by the PROCESS MACROS.
 *                In this case, it is used the channel defined by the father
 *
 */

#include    <inttypes.h>
#include    <stdint.h>
#include    <stdio.h>
#include    <time.h>

#include    <sys/time.h>

#include    "crt0.h"
#include    "calendar/calendar.h"
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

#ifndef _CLOCKS_PER_SEC_
#error "_CLOCKS_PER_SEC_ is not defined"
#endif

#define CLOCKS_PER_SEC_CHECK(x) ((x) == 1000000)
static_assert(CLOCKS_PER_SEC_CHECK(_CLOCKS_PER_SEC_), "_CLOCKS_PER_SEC_ must be 1000000");

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "calendar     Example of how to use time.h functions.   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  calendar\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Calendar,                           // Module name (the first letter has to be upper case)
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
 * - P0: Every 1000-ms
 *          - Display some time manipulations on the KSYST manager
 *
 */
[[noreturn]]
static void aProcess_0([[maybe_unused]] const void *argument) {
            time_t      now, newTime;
            clock_t     tic1, toc1;
            timeval_t   tic2, toc2;
            uint64_t    unixTime;
            float64_t   totalTime;
            tm_t        localTime, currentTime;
    static  char_t      formattedTime[100];

// Time now (uinxtime)

    now = time(nullptr);
    (void)dprintf(KSYST, "\nTime now = %"PRId64"\n", now);

// Convert to local time

    localtime_r(&now, &localTime);
    (void)dprintf(KSYST, "Local time: %s", asctime(&localTime));

// Calculate a new time (add 1 minute)

    localTime.tm_min += 1;
    newTime = mktime(&localTime);
    (void)dprintf(KSYST, "New timestamp (1 minute later): %"PRId64"\n", newTime);

// Format the time

// NOLINTBEGIN(cert-err33-c)
//
    strftime(formattedTime, sizeof(formattedTime), "%I %p", &localTime);

// NOLINTEND(cert-err33-c)
//
    (void)dprintf(KSYST, "Formatted time: %s\n", formattedTime);

// Measure the execution time
// !!! This is the measure of the time used by the cpu

    tic1 = clock();
    kern_suspendProcess(1234U);
    toc1 = clock();

    totalTime = (float64_t)(toc1 - tic1) / CLOCKS_PER_SEC;
    (void)dprintf(KSYST, "Execution time: %.6f seconds\n", totalTime);

// Measure the real time
// !!! This is the measure of the real time

    gettimeofday(&tic2, nullptr);
    kern_suspendProcess(1234U);
    gettimeofday(&toc2, nullptr);

    totalTime = (double)(toc2.tv_sec - tic2.tv_sec) + ((double)(toc2.tv_usec - tic2.tv_usec) / 1e6);
    (void)dprintf(KSYST, "Execution time: %.6f seconds\n", totalTime);

// Generate the new Unix time 64-bits with 1us

    currentTime.tm_year  = 2025U - 1900U;
    currentTime.tm_mon   = 3U - 1U;
    currentTime.tm_mday  = 31U;
    currentTime.tm_hour  = 16U;
    currentTime.tm_min   = 07U;
    currentTime.tm_sec   = 0U;
    currentTime.tm_isdst = 1U;

    now = mktime(&currentTime);
    if (now == -1 ) { (void)dprintf(KSYST, "Error: unable to make time using mktime\n\n"); }
    else {
        unixTime = (uint64_t)(now * CLOCKS_PER_SEC);
        calendar_writeUnixTime(unixTime);
        (void)dprintf(KSYST, "New Unix time 64-bits= %"PRId64"\n\n", unixTime);
    }

    while (true) {
        kern_suspendProcess(1000U);

        now = time(nullptr);
        localtime_r(&now, &localTime);
        (void)dprintf(KSYST, "Local time: %s", asctime(&localTime));
        led_toggle(KLED_1);
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

// Specifications for the processes

// Under LLVM libc a single dprintf("%f", ...) nests ~3.2 KB deep in the C library's own
// printf internals: decimal_digits() is a 472-byte frame and it then calls the 320-bit
// DyadicFloat exact-decimal routines (rounded_div 888 B, rounding_direction 456 B,
// round<640> 296 B). KKERN_SZ_STACK_LL's 2400 bytes cannot hold that, and the overflow
// destroys the magic word at the bottom of the stack, which the kernel reports as
// "stack underflow" at the next context switch. picolibc and newlib use lighter float
// printf implementations and stay well inside KKERN_SZ_STACK_LL.

    #ifdef CONFIG_MAN_LLVMLIBC_S
    #define KLOCAL_SZ_STACK_PROCESS     KKERN_SZ_STACK_XLIB
    #else
    #define KLOCAL_SZ_STACK_PROCESS     KKERN_SZ_STACK_LL
    #endif

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification_0,                    // Specifications (just use specification_x)
        aStrText_0,                         // Info string (nullptr if anonymous)
        KLOCAL_SZ_STACK_PROCESS,            // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess_0,                         // Code of the process
        aStrIden_0,                         // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_NORMAL_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}
