/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Make a restart.
 */

#include    <stdint.h>
#include    <stdio.h>

#include    "kern/kern.h"
#include    "machine/machine.h"
#include    "macros.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "restart      Make a restart.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Make a restart\n"
                                    "==============\n\n"

                                    "This tool makes a restart.\n\n"

                                    "Input format:  restart\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Restart,                                    // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_RESTART,                               // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

#define KWAIT_05S   500U

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {

    (void)dprintf(KSYST, "System restart.\n");

    kern_suspendProcess(KWAIT_05S);
    machine_restart();
    return EXIT_OS_SUCCESS_CLI;
}
