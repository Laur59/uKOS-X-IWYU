/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; bench.
; ======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     System benches.
;
;           Launch 1 processes:
;
;           - P0: bench performance
;
;-----
;------------------------------------------------------------------------
*/

#include    "bench.h"

#include    <stdio.h>
#include    <stdint.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "bench        CPU core performance benches.             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "The CPU cores benches\n"
                                    "=====================\n\n"

                                    "This tool performs some benches to figure-out the real\n"
                                    "CPU performances\n\n"

                                    "Input format:  bench\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Bench,                                      // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_BENCH,                                 // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    priority_t  priority;
    proc_t      *process;

    UNUSED(argc);
    UNUSED(argv);

    PRIVILEGE_ELEVATE;

    (void)dprintf(KSYST, "System bench.\n");

// Save the priority & make the process realtime

    kern_getProcessRun(&process);
    kern_getPriority(process, &priority);
    kern_setPriority(process, KKERN_PRIORITY_HIGH_01);

    if (!bench_00()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }
    if (!bench_01()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }
    if (!bench_02()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }
    if (!bench_03()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }
    if (!bench_04()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }
    if (!bench_05()) { (void)dprintf(KSYST, "Not enough memory.\n"); return EXIT_OS_FAILURE; }

    kern_setPriority(process, priority);
    return EXIT_OS_SUCCESS_CLI;
}
