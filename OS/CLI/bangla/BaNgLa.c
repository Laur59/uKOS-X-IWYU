/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Display the purpose of the Bangla team.
 */

#include    <stdint.h>
#include    <stdio.h>

#include    "macros.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "BaNgLa       The Lami - EPFL Bangla group.             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "The Bangla group\n"
                                    "================\n\n"

                                    "The purpose of the Lami - EPFL Bangla group is:\n"
                                    "   Eating a lot.\n"
                                    "   Playing the flipper on Amiga.\n"
                                    "   Having a good time.\n\n"

                                    "Input format:  BaNgLa\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    BaNgLa,                                     // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_BANGLA,                                // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BEXE_CONSOLE) | (1U<<BCONFIDENTIAL)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    STRG_LOC_CONST(aStrBangla[]) = "Lami - EPFL Bangla team for ever.\n\n"
                                   "- Edo. Franzi\n"
                                   "- Laurent Tettoni\n"
                                   "- Francesco Mondada\n"
                                   "- Yves Cheneval\n\n"
                                   "El trona en val culera e el rimbomba em mezz ai ciapp ....\n\n";

    (void)dprintf(KSYST, "Bangla team ...\n");
    (void)dprintf(KSYST, "%s", aStrBangla);
    return EXIT_OS_SUCCESS_CLI;
}
