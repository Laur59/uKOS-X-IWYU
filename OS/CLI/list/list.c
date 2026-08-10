/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     List the system modules.
 */

#include    <stdint.h>
#include    <stdio.h>

#include    "macros.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "system/system.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "list         List the system modules.                  (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "List the system modules\n"
                                    "=======================\n\n"

                                    "This tool displays the modules of the system.\n"
                                    "All the family modules will be displayed.\n\n"

                                    "Input format:  list [IDfamily]\n"
                                    "Output format: IDfamily    name    comment    revision \n\n"

                                    "IDfamily:\n"
                                    "   'C' for Communication Manager family\n"
                                    "   'D' for Daemon family\n"
                                    "   'F' for Company family\n"
                                    "   'G' for Shared manager family\n"
                                    "   'K' for Kernel manager family\n"
                                    "   'L' for Generic manager family\n"
                                    "   'M' for Storage family\n"
                                    "   'N' for Neural manager family\n"
                                    "   'P' for Peripheral manager family\n"
                                    "   'Q' for Cryptographic manager family\n"
                                    "   'S' for StartUp family\n"
                                    "   'T' for Process family\n"
                                    "   'U' for Application family\n"
                                    "   'X' for CLI family\n"
                                    "   'Z' for Third Party family\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    List,                                       // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    KNUM_LIST,                                  // Module identifier (defined in the module.h)
    nullptr,                                    // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

// Prototypes

static  bool    local_listModule(uint8_t idFamily);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
                    uint8_t     i, idModule;
                    int32_t     status;
                    bool        error = false;
            const   char_t      *str;
    static  const   uint8_t     aFamilies[] = {
                                    KID_FAM_STARTUPS, KID_FAM_DAEMONS, KID_FAM_PROCESSES,
                                    KID_FAM_CLI, KID_FAM_KERNELS,
                                    KID_FAM_CRYPTOGRAPHICS, KID_FAM_NEURALS, KID_FAM_GENERICS, KID_FAM_STORAGE, KID_FAM_PERIPHERALS,
                                    KID_FAM_SERIALS, KID_FAM_COMPANY, KID_FAM_SHARED,
                                    KID_FAM_THIRD_PARTIES,
                                };

    (void)dprintf(KSYST, "uKOS-X module list.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// list
// list P

    if (argc == 2U) {

// List of the selected family module

        str = argv[1];
        idModule = (uint8_t)str[0];
        error = !local_listModule(idModule);
    }

// List of all the module families

    else {
        for (i = 0U; i < (uint8_t)(sizeof(aFamilies) / sizeof(uint8_t)); i++) {
            local_listModule(aFamilies[i]);
        }
    }

    if (!error) {                                                          status = EXIT_OS_SUCCESS_CLI; }
    else                { (void)dprintf(KSYST, "This family does not exist.\n\n"); status = EXIT_OS_FAILURE;     }
    return status;
}

// Local routines
// ==============

/*
 * \brief local_listModule
 *
 * - List a family modules
 *
 */
static  bool    local_listModule(uint8_t idFamily) {
            uint16_t        i, index = 0U;
            uint32_t        idModule;
            bool            found = false;
            char_t          bufIdent[4 + 1];
    const   char_t          *idIdentifier;
    const   uKOS_module_t   *module;

// List inside memx

    while (system_getModuleFamily(idFamily, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
        if ((module->oFlag & (1U<<BCONFIDENTIAL)) == 0) {
            found = true;

// Find a family code; display its identifier
//   The format is:
//   FLASH___nn___XYZT__rev__name_________Comment

            idIdentifier = (char_t *)&idModule;

            #ifdef BIG_ENDIAN_S
            for (i = 0U; i < 4U; i++) { bufIdent[i] = *(idIdentifier + i);        }

            #else
            for (i = 0U; i < 4U; i++) { bufIdent[i] = *(idIdentifier + (3U - i)); }
            #endif

            bufIdent[4] = '\0';

            (void)dprintf(KSYST, "%s %3d  %s  v%s   %s\n", "FLASH", index, bufIdent, module->oStrRevision, module->oStrApplication);
        }
        index++;
    }
    if (found) { (void)dprintf(KSYST, "\n"); }
    return found;
}
