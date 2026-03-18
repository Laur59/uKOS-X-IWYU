/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Launch a function module.
 */

#include    <stdint.h>
#include    <stdio.h>

#include    "macros.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "system/system.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "run          Run a downloaded code.                    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Launch a function module\n"
                                    "========================\n\n"

                                    "This tool runs a downloaded code.\n\n"

                                    "Input format:  run\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Run,                                        // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_RUN,                                   // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

#define KIDUSER ((KID_FAM_APPLICATIONS<<24U) | (KNUM_APPLICATION<<8U) | '_')

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    int32_t     status, (*code)(uint32_t argc, const char_t *argv[]);

    (void)dprintf(KSYST, "Execute the downloaded application.\n");

    system_getDownloadCodeAddress((void **)&code);
    if (code == nullptr) { (void)dprintf(KSYST, "No application in the memory!\n\n");     status = EXIT_OS_FAILURE;     }
    else              { (void)dprintf(KSYST, "Run the downloaded application...\n\n"); status = EXIT_OS_SUCCESS_CLI; }

    system_setDownloadCodeAddress(nullptr);

    status = (status == EXIT_OS_SUCCESS_CLI) ? ((*code)(argc, argv)) : status;
    return status;
}
