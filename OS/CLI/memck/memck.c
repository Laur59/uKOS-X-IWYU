/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; memck.
; ======

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     This tool cyclically verify the memory integrity.
;
;-----
;------------------------------------------------------------------------
*/

#include    <inttypes.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core_stackFrame.h"
#include    "memo/memo.h"       // IWYU pragma: keep (for PROCESS_STACKMALLOC)
#include    "modules.h"
#include    "os_errors.h"
#include    "serial/serial.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "memck        Verify the memory integrity.              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Verify the memory integrity\n"
                                    "===========================\n\n"

                                    "This tool cyclically verify the memory integrity.\n\n"

                                    "Input format:  memck {hex_startAdd hex_endAdd time}\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);
static  void        local_process(const void *argument);

MODULE(
    Memck,                                          // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                    // Family (defined in the module.h)
    KNUM_MEM_CK,                                    // Module identifier (defined in the module.h)
    nullptr,                                        // Address of the initialisation code (early pre-init)
    prgm,                                           // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                        // Address of the clean code (clean the module)
    " 1.0",                                         // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),             // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                               // Execution cores
);

// CLI tool specific
// =================

typedef struct  memckPack   memckPack_t;

struct  memckPack {
            serialManager_t     oSerialManager;     // Serial Communication Manager
            uintptr_t           oStartAdd;          // Start memory address
            uintptr_t           oEndAdd;            // End memory address
            uint32_t            oTime;              // Cyclic test time
            bool                *oReleasePack;      // Release the pack
        };

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    char_t          *dummy;
    memckPack_t     pack;
    bool            releasePack = false;
    int32_t         status;
    uint32_t        time;
    uintptr_t       startAdd, endAdd;
    enum            { KERR_NOT, KERR_INA, KERR_NPR } error = KERR_NOT;
    proc_t          *process;

    kern_getProcessRun(&process);

    (void)dprintf(KSYST, "Test of the memory integrity.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// memck A0001234 A0011234 34

    if (argc != 4U) {
        error = KERR_INA;
    }
    else {
        startAdd = (uintptr_t)strtoul(argv[1], &dummy, 16U);
        endAdd   = (uintptr_t)strtoul(argv[2], &dummy, 16U);
        time     = (uint32_t) strtoul(argv[3], &dummy, 16U);

        kern_getSerialForProcess(process, &pack.oSerialManager);
        pack.oStartAdd    = startAdd;
        pack.oEndAdd      = endAdd;
        pack.oTime        = time;
        pack.oReleasePack = &releasePack;

        PROCESS_STACKMALLOC(
            0,                                  // Index
            specification,                      // Specifications (just use specification_x)
            nullptr,                            // Info string (nullptr if anonymous)
            KKERN_SZ_STACK_MM,                  // KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
            local_process,                      // Code of the process
            nullptr,                            // Identifier (nullptr if anonymous)
            KSYST,                              // Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
            KKERN_PRIORITY_LOW_14               // KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
        );

        if (kern_createProcess(&specification, &pack, &process) != KERR_KERN_NOERR) {
            error = KERR_NPR;
        }
    }

    switch (error) {
        case KERR_NOT: { (void)dprintf(KSYST, "Test is running.\n\n");     status = EXIT_OS_SUCCESS_CLI; break; }
        case KERR_NPR: { (void)dprintf(KSYST, "No more process.\n\n");     status = EXIT_OS_FAILURE;     break; }
        case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n"); status = EXIT_OS_FAILURE;     break; }
        default:       {                                                   status = EXIT_OS_FAILURE;     break; }
    }

// Let the time to the process "local_process" to run

    do { kern_suspendProcess(1U); } while ((!releasePack) && (error == KERR_NOT));
    return status;
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Check the memory integrity
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
            bool            *releasePack;
            uint32_t        i, nbBytes, time, ckSumm = 0U, newCkSumm;
            uintptr_t       startAdd, endAdd;
            proc_t          *process;
    const   uint8_t         *firstAdd;
    const   memckPack_t     *pack;

    kern_getProcessRun(&process);

// Recover the process arguments

    pack = (const memckPack_t *)argument;

    kern_setSerialForProcess(process, pack->oSerialManager);
    startAdd     = pack->oStartAdd;
    endAdd       = pack->oEndAdd;
    time         = pack->oTime;
    releasePack  = pack->oReleasePack;
    *releasePack = true;

// Compute the reference checksum

    nbBytes = (uint32_t)(endAdd - startAdd);
    firstAdd = (uint8_t *)startAdd;
    for (i = 0U; i < nbBytes; i++) {
        ckSumm += (uint32_t)*firstAdd;
        firstAdd++;
    }

    while (true) {
        kern_suspendProcess(time);

// Compute the checksum of the memory block

        nbBytes = (uint32_t)(endAdd - startAdd);
        firstAdd = (uint8_t *)startAdd;
        newCkSumm = 0U;
        for (i = 0U; i < nbBytes; i++) {
            newCkSumm += (uint32_t)*firstAdd;
            firstAdd++;
        }

// Verify the integrity
// If problem, then display the address boundary and re-initialise the checksum.

        if (ckSumm != newCkSumm) {
            (void)dprintf(KSYST, "Integrity problem! Block add = 0x%016"PRIXPTR" to 0x%016"PRIXPTR"\n", startAdd, endAdd);
            ckSumm = newCkSumm;
        }
    }
}
