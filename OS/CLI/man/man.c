/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Show the help of the module.
 */

#include    <stdint.h>
#include    <stdio.h>

#include    "ip.h"
#include    "macros.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "system/system.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "man          Show the help of the module.              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Show the help of the module\n"
                                    "===========================\n\n"

                                    "This tool displays the help for a\n"
                                    "selected module.\n\n"

                                    "Input format:  man [moduleName]\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Man,                                        // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_MAN,                                   // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

STRG_LOC_CONST(aStrLogo[])      = STRG_LOGO;
STRG_LOC_CONST(aStrCopyright[]) = STRG_COPYRIGHT_FRANZI;

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
            uint16_t        index;
            int32_t         status;
            uint32_t        idModule;
            bool            error = false;
    const   uKOS_module_t   *module;

    (void)dprintf(KSYST, "Module help.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// man
// man console

    if (argc == 2U) {

// man with parameters

        if (system_getModuleName(argv[1], &index, &module) != KERR_SYSTEM_NOERR) {
            error = true;
        }

        if (!error) {
            (void)dprintf(KSYST, "%s%s", module->oStrHelp, aStrCopyright);
        }
    }

// man without parameter
// Display the logo and the tool list

    else {
        (void)dprintf(KSYST, "%s", aStrLogo);

// List the CLI components

        (void)dprintf(KSYST, "CLI\n\n");
        index = 0U;
        while (system_getModuleFamily(KID_FAM_CLI, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
            if ((module->oFlag & (1U<<BSHOW)) != 0U) {
                (void)dprintf(KSYST, "%s\n", module->oStrApplication);
            }
            index++;
        }
    }

    if (!error) { (void)dprintf(KSYST, "\n");                  status = EXIT_OS_SUCCESS_CLI; }
    else                { (void)dprintf(KSYST, "Protocol error.\n\n"); status = EXIT_OS_FAILURE;     }
    return status;
}
