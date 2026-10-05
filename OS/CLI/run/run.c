/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Launch a function module.
 */

#include    <stdint.h>
#include    <stdio.h>
#include    <string.h>

#include    "linker.h"
#include    "macros.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "system/system.h"
#include    "types.h"

#if (defined(CACHE_D_S))
#include    "cache.h"
#include    "kern/kern.h"
#include    "macros_core.h"
#endif

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

// Prototypes

static  bool    local_isApplication(int32_t (*code)(uint32_t argc, const char_t *argv[]));
static  void    local_syncCode(void);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    int32_t     status, (*code)(uint32_t argc, const char_t *argv[]);

    (void)dprintf(KSYST, "Execute the downloaded application.\n");

    system_getDownloadCodeAddress((void **)&code);
    if (code == nullptr) {
        (void)dprintf(KSYST, "No application in the memory!\n\n");
        status = EXIT_OS_FAILURE;
    }

// A loader publishes an address even for a download that is not an application
// (an S-record terminator alone publishes the start of the user memory): verify
// that an application for this system is really there before jumping to it,
// and forget an address that is not one - the next run reports an empty memory

    else if (!local_isApplication(code)) {
        (void)dprintf(KSYST, "The downloaded code is not an application for this system!\n\n");
        system_setDownloadCodeAddress(nullptr);
        status = EXIT_OS_FAILURE;
    }
    else {
        (void)dprintf(KSYST, "Run the downloaded application...\n\n");
        system_setDownloadCodeAddress(nullptr);
        local_syncCode();
        status = (*code)(argc, argv);
    }
    return status;
}

// Local routines
// ==============

/*
 * \brief local_syncCode
 *
 * - Make the memory hold the code that is about to run
 *   - the code was written through the data cache, where part of it may
 *     still sit, while its instructions are fetched from the memory behind
 *   - the instruction cache may still hold an application that ran earlier
 *     from the same addresses
 *
 */
static  void    local_syncCode(void) {

#if (defined(CACHE_D_S))
    PRIVILEGE_ELEVATE;
    cache_I_D_Sync_Add((const void *)linker_stUMemo, (int32_t)(uintptr_t)linker_lnUMemo);
    PRIVILEGE_RESTORE;
#endif
}

/*
 * \brief local_isApplication
 *
 * - Verify that the user memory holds the application a loader announced
 *   - the header at the start of the user memory is marked KMEMU
 *   - the entry point it declares is the address that was published
 *   - its length fits in the user memory
 *   - the system signature lies inside the application itself: SRAM keeps
 *     its content across resets, so a stale copy may sit anywhere else
 *
 */
static  bool    local_isApplication(int32_t (*code)(uint32_t argc, const char_t *argv[])) {
            uKOS_header_t   header;
            size_t          ln, i = 0U;
    const   uint8_t         *ptr = (const uint8_t *)linker_stUMemo;
    const   char_t          *signature;

    memcpy(&header, (const void *)linker_stUMemo, sizeof(header));

    if ((header.oMemLocation != KMEMU) || (header.oStart != code)) {
        return false;
    }

    if ((header.oLnApplication == 0U) || (header.oLnApplication > (uintptr_t)linker_lnUMemo)) {
        return false;
    }

    system_getSystemSignature(&signature);

    for (ln = (size_t)header.oLnApplication; ln > 0U; --ln) {
        if (*ptr == (uint8_t)signature[i]) {
            i++;
            if (*ptr == 0U) {
                return true;
            }
        }
        else {

// A mismatch may still be the first character of the signature

            i = (*ptr == (uint8_t)signature[0]) ? 1U : 0U;
        }
        ptr++;
    }
    return false;
}
