/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     startUp process; execute some important initialisations
 *           before jumping to the selected function.
 */

#include    "startUp/startUp.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "serial/serial.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core_stackFrame.h"
// memo/memo.h is required for PROCESS_STACKMALLOC
#include    "memo/memo.h"       // IWYU pragma: keep
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "startUp      StartUp process of the system.            (c) EFr-2026";
#define aStrHelp    aStartUp_StrHelp

// This process has to run on the following cores:

#define KEXECUTION_CORE     ((1U<<BCORE_1) | (1U<<BCORE_0))

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    StartUp,                        // Module name (the first letter has to be upper case)
    KID_FAM_PROCESSES,              // Family (defined in the module.h)
    KNUM_STARTUP,                   // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    prgm,                           // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    KEXECUTION_CORE                 // Execution cores
);

// Process specific
// ================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_startUp";
STRG_LOC_CONST(aStrText[]) = "Process startUp: start of the system.     (c) EFr-2026";

// Prototypes

static  void    local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    proc_t  *process;

    UNUSED(argc);
    UNUSED(argv);

    PROCESS_STACKMALLOC(
        0,                                  // Index
        specification,                      // Specifications (just use specification_x)
        aStrText,                           // Info string (nullptr if anonymous)
        KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
        local_process,                      // Code of the process
        aStrIden,                           // Identifier (nullptr if anonymous)
        KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
        KKERN_PRIORITY_LOW_14               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
    );

    if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "startup: reate proc"); exit(EXIT_OS_PANIC); }

    LOG(KINFO_SYSTEM, "startup: process start-up launched");
    return EXIT_OS_SUCCESS_CLI;
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Start-up of the system
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {

    UNUSED(argument);

    stub_startUp_launch();
    exit(EXIT_OS_SUCCESS);
}
