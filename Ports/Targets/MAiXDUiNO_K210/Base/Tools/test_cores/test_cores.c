/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Some core tests.
 */

// uKOS-X specific headers
#define     _POSIX_C_SOURCE     200809L

#include    <inttypes.h>
#include    <stdbool.h>
#include    <stdint.h>
#include    <stdio.h>

#include    "serial/serial.h"
#include    "core.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "test_cores   Some core tests.                          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Test of the cores\n"
                                    "=================\n\n"

                                    "This tool performs some core tests.\n\n"

                                    "Input format:  test_core\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Test_cores,                                 // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    (((uint32_t)'_'<<8u)+(uint32_t)'C'),        // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

extern  volatile    uint8_t     vVector[];
extern              spinlock_t  vLockVector;

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

            uint32_t    core;
            uint8_t     i, first;
    static  bool        vError[KNB_CORES] = MCSET(false);

    UNUSED(argc);
    UNUSED(argv);

    core = GET_RUNNING_CORE;
    (void)dprintf(KSYST, "Core tests.\n");

// If the vector coherence verification failed, then, stop printing

    if (vError[core] == true) { return EXIT_OS_SUCCESS_CLI; }

// Print the vector

    (void)dprintf(KSYST, "Size = %"PRIu8", core = %"PRIu8", Vector = ", vVector[0], vVector[1]);

    SPIN_LOCK(vLockVector);
    for (i = 2u; i < vVector[0]; i++) {
        (void)dprintf(KSYST, "%"PRIu8" ", vVector[i]);
    }

// Verify the vector coherence

    first = vVector[2];
    for (i = 2u; i < vVector[0]; i++) {
        if (first++ != vVector[i]) {
            (void)dprintf(KSYST, "Problem\n");
            vError[core] = true;
        }
    }
    SPIN_UNLOCK(vLockVector);

    (void)dprintf(KSYST, "\n");
    return EXIT_OS_SUCCESS_CLI;
}
