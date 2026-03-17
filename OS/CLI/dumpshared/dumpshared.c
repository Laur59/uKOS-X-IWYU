/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; dumpshared.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Display the shared area of the multicore system.
;
;-----
;------------------------------------------------------------------------
*/

#include    <inttypes.h>
#include    <stdio.h>

#include    "asmp/asmp.h"
#include    "macros.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "dumpshared   Dump the shared area of the multicore.    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Dump the shared area of the multicore\n"
                                    "=====================================\n\n"

                                    "This tool display the content of the shared ared\n"
                                    "of the multicore systems\n\n"

                                    "Input format:  dumpshared\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Dumpshared,                                 // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_DUMP_SHARED,                           // Module identifier (defined in the module.h)
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
    uint32_t    i;

    UNUSED(argc);
    UNUSED(argv);

    (void)dprintf(KSYST, "Shared dump.\n");

    (void)dprintf(KSYST, "\nASMPReady: 0x%02"PRIX8"\n\n", vAsmp_InterCore->oASMPReady);

    for (i = 0U; i < KASMP_NB_CORES; i++) {
        (void)dprintf(KSYST, "Core %"PRIu32", StatusRX: %s\n",          i, (vAsmp_InterCore->oStatusRX[i]) ? "LOCK" : "FREE");
        (void)dprintf(KSYST, "Core %"PRIu32", StatusTX: %s\n",          i, (vAsmp_InterCore->oStatusTX[i]) ? "LOCK" : "FREE");

        (void)dprintf(KSYST, "Core %"PRIu32", Sender:   %"PRIu32"\n",   i, vAsmp_InterCore->oSender[i]);
        (void)dprintf(KSYST, "Core %"PRIu32", Order:    %"PRIu32"\n",   i, vAsmp_InterCore->oOrder[i]);
        (void)dprintf(KSYST, "Core %"PRIu32", Size:     %"PRIu32"\n",   i, vAsmp_InterCore->oSize[i]);
        (void)dprintf(KSYST, "Core %"PRIu32", Buffer:   %s\n\n",        i, vAsmp_InterCore->oBuffer[i]);
    }
    return EXIT_OS_SUCCESS_CLI;
}
