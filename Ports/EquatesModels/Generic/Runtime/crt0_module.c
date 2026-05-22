/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * uKOS-X module registration for the crt0 runtime.
 * Split out of crt0.c so that the C-runtime bootstrap stays independent
 * of the module registration mechanism (modules.h / man discovery).
 */

#include    "macros.h"
#include    "modules.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "crt0         Runtime crt0.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "crt0\n"
                                    "====\n\n"

                                    "Runtime crt0 of the system ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Crt0,                           // Module name (the first letter has to be upper case)
    KID_FAM_STARTUPS,               // Family (defined in the module.h)
    KNUM_CRT0,                      // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);
