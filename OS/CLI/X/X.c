/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Control the temperature.
 */

#include    <stdint.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_soc.h"
#include    "memo/memo.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "X            Control the temperature.                  (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Control the temperature\n"
                                    "=======================\n\n"

                                    "This tool module allows to operate on the xtmp\n"
                                    "temperature manager\n\n"

                                    "Input format:  X\n"
                                    "Output format: x,t0,t1,t...t127\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    X,                                  // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                        // Family (defined in the module.h)
    KNUM_X,                             // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    prgm,                               // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);

// CLI tool specific
// =================

#define KNB_SAMPLES     128U            // Nb. of samples

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
            uint32_t    core, sizeRec;
            int32_t     status;
            uint16_t    *bufRec, i;
    static  uint16_t    vTemperature[KNB_CORES][KNB_SAMPLES];
    static  bool        vInitialised[KNB_CORES] = MCSET(false);
    static  mbox_t      *vMailBox[KNB_CORES];

    core = GET_RUNNING_CORE;

    if (!vInitialised[core]) {
        if (kern_getMailboxById("Temperature", &vMailBox[core]) != KERR_KERN_NOERR) {
            (void)dprintf(KSYST, "Process Temperature not installed!\n");
            return EXIT_OS_FAILURE;
        }

        vInitialised[core] = true;
    }

// Receive the message (wait until the FIFO is not empty)

    sizeRec = (KNB_SAMPLES * sizeof(uint16_t));
    status  = kern_readMailbox(vMailBox[core], (void **)&bufRec, &sizeRec, 10000U);

    switch (status) {
        case KERR_KERN_NOERR: {
            break;
        }
        case KERR_KERN_TIMEO:
        case KERR_KERN_MBKIL: {
            (void)dprintf(KSYST, "The process Temperature was killed!\n");
            vInitialised[core] = false;
            return EXIT_OS_FAILURE;
        }
        default: {

// Report the failure as a status. This runs in the process of the console that
// invoked the module, so exit(EXIT_OS_FAILURE) here reached crt0_exit's
// local_killProcess() and silently killed the console itself.
//
// Drop the cached handle as the timeout case does, so the next call re-runs
// kern_getMailboxById() instead of reusing a mailbox that has gone. Without this the
// module answers "mbox problem" for ever once the producer has been killed, even after
// it is restarted, because vMailBox still points at the mailbox that was destroyed.
//
// KERROR rather than KFATAL: nothing dies here any more, and a record above Info makes
// a post-flash health check report the board as failed.

            (void)dprintf(KSYST, "mbox problem\n");
            LOG(KERROR_USER, "x: mbox problem");
            vInitialised[core] = false;
            return EXIT_OS_FAILURE;
        }
    }

// Past this point the read succeeded, so bufRec is a real message. Neither error case
// above may fall through to it: kern_readMailbox() stores nullptr in bufRec whenever it
// returns an error, and the memcpy below would read from address 0.

// Copy it into the temperature buffer before to "free" the memory

    memcpy(&vTemperature[core][0], bufRec, (KNB_SAMPLES * sizeof(uint16_t)));
    memo_free(bufRec);

    (void)dprintf(KSYST, "x,");
    for (i = 0U; i < (KNB_SAMPLES - 1U); i++) {
        (void)dprintf(KSYST, "%d,",  vTemperature[core][i]);
    }
    (void)dprintf(KSYST, "%d\n", vTemperature[core][KNB_SAMPLES - 1U]);

    return EXIT_OS_SUCCESS_CLI;
}
