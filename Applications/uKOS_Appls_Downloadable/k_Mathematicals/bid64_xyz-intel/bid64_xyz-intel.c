/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Demo of a C application.
 * This application shows how to compute in decimal floating point with the
 * Intel Decimal Floating-Point Math Library (BID encoding, 64-bit format).
 * It is the counterpart of bid64_xyz, which uses the decNumber library.
 * Expected results:
 *          Serial terminal output
 *          uKOS-X > run
 *          Execute the downloaded application.
 *          Run the downloaded application...
 *
 *  uKOS-X >
 *  0.004565e-3 mul 1.747470e+4 = +7977200550E-11
 *
 *  0.004565e-3 div 1.747470e+4 = +2612348137593206E-25
 *
 *  Problem: Division by zero
 *  0.004565e-3 div 00000000000 = +Inf
 */

/*!
 * \file
 * \ingroup app_mathematic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *          Launch 1 processes:
 *
 *          - P0: - Compute some basic operator with the Intel math library
 *                - Display the result
 *                - Commit a suicide
 *
 */

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "crt0.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_core_stackFrame.h"
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "serial/serial.h"
#include    "types.h"

// The Intel headers; the library is built with their default configuration:
// arguments by value, the rounding mode as an argument and the exception
// flags through a pointer.

#include    "bid_conf.h"
#include    "bid_functions.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "bid64_intel  Example of how to use the Intel math lib. (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module is a C written application.\n\n"

                                    "Input format:  bid64_xyz-intel\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Bid64_intel,                        // Module name (the first letter has to be upper case)
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

static  char_t      vResult[128];
static  char_t      vN1[] = "0.004565e-3";
static  char_t      vN2[] = "1.747470e+4";
static  char_t      vZe[] = "00000000000";

// The exceptions reported as a problem; an inexact result is not one

#define KBID_ERRORS     ((_IDEC_flags)(BID_INVALID_EXCEPTION | BID_ZERO_DIVIDE_EXCEPTION | BID_OVERFLOW_EXCEPTION | BID_UNDERFLOW_EXCEPTION))

// Prototypes

static  void    local_printStatus(_IDEC_flags flags);

/*
 * \brief aProcess
 *
 * - Compute some basic operator with the Intel math library
 * - Display the result
 * - Commit a suicide
 *
 */
[[noreturn]]
static void aProcess([[maybe_unused]] const void *argument) {
    BID_UINT64      a, b, r;
    _IDEC_flags     flags;

    kern_suspendProcess(1000U);
    (void)dprintf(KSYST, "\n");

// Multiplication

    flags = 0U;
    a = bid64_from_string(vN1, BID_ROUNDING_TO_NEAREST, &flags);
    b = bid64_from_string(vN2, BID_ROUNDING_TO_NEAREST, &flags);
    r = bid64_mul(a, b, BID_ROUNDING_TO_NEAREST, &flags);
    bid64_to_string(vResult, r, &flags);
    local_printStatus(flags);

    (void)dprintf(KSYST, "%s mul %s = %s\n\n", vN1, vN2, vResult);

// Division (!= 0)

    flags = 0U;
    a = bid64_from_string(vN1, BID_ROUNDING_TO_NEAREST, &flags);
    b = bid64_from_string(vN2, BID_ROUNDING_TO_NEAREST, &flags);
    r = bid64_div(a, b, BID_ROUNDING_TO_NEAREST, &flags);
    bid64_to_string(vResult, r, &flags);
    local_printStatus(flags);

    (void)dprintf(KSYST, "%s div %s = %s\n\n", vN1, vN2, vResult);

// Division (= 0)

    flags = 0U;
    a = bid64_from_string(vN1, BID_ROUNDING_TO_NEAREST, &flags);
    b = bid64_from_string(vZe, BID_ROUNDING_TO_NEAREST, &flags);
    r = bid64_div(a, b, BID_ROUNDING_TO_NEAREST, &flags);
    bid64_to_string(vResult, r, &flags);
    local_printStatus(flags);

    (void)dprintf(KSYST, "%s div %s = %s\n\n", vN1, vZe, vResult);

    kern_suspendProcess(1000U);
    exit(EXIT_OS_SUCCESS);
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

// Specifications for the processes

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        aProcess,                           // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_MEDIUM_01            // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return EXIT_OS_FAILURE; }

    LOG(KINFO_USER, "Application launched");
    return EXIT_OS_SUCCESS_CLI;
}

// Local routines
// ==============

/*
 * \brief local_printStatus
 *
 * - Display the status of the operation
 *
 */
static  void    local_printStatus(_IDEC_flags flags) {

    if ((flags & KBID_ERRORS) == 0U) { return; }

    if ((flags & BID_INVALID_EXCEPTION)     != 0U) { (void)dprintf(KSYST, "Problem: Invalid operation\n"); }
    if ((flags & BID_ZERO_DIVIDE_EXCEPTION) != 0U) { (void)dprintf(KSYST, "Problem: Division by zero\n");  }
    if ((flags & BID_OVERFLOW_EXCEPTION)    != 0U) { (void)dprintf(KSYST, "Problem: Overflow\n");          }
    if ((flags & BID_UNDERFLOW_EXCEPTION)   != 0U) { (void)dprintf(KSYST, "Problem: Underflow\n");         }
}
