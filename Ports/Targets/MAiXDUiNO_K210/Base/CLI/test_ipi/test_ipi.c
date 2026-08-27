/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Preliminary test of the ipi.
 *
 *           core 0                  core 1
 *           test_ipi -generate      counter[core 1]++
 *           counter[core 0]++       test_ipi -generate
 *
 *           test_ipi -display       test_ipi -display
 *           counter[core 0]         counter[core 1]
 */

#define     _POSIX_C_SOURCE     200809L

#include    <inttypes.h>
#include    <stdio.h>

#include    "Registers/K210_clint.h"
#include    "Registers/rv64_csr.h"
#include    "Registers/soc_vectors.h"
#include    "core.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "serial/serial.h"
#include    "text/text.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "test_ipi     preliminary ipi test.                     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Test of the cores\n"
                                    "=================\n\n"

                                    "This tool performs a preliminary ipi tests.\n\n"

                                    "Input format:  test_ipi -generate/-display\n"
                                    "Output format: [result]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static  int32_t     test_ipi_pre_init(uint32_t argc, const char_t *argv[]);
static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Test_ipi,                                   // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                                // Family (defined in the module.h)
    (((uint32_t)'_'<<8U)+(uint32_t)'M'),        // Module identifier (defined in the module.h)
    test_ipi_pre_init,                          // Address of the initialisation code (early pre-init)
    prgm,                                       // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                                    // Address of the clean code (clean the module)
    " 1.0",                                     // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),         // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                           // Execution cores
);

// CLI tool specific
// =================

static  volatile    uint8_t     vCounter[KNB_CORES] = MCSET(0U);
static  volatile    bool        vDataAvailable[KNB_CORES] = MCSET(false);

// Prototypes

static  void    local_machineSoftware_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief Main entry point
 *
 */
static  int32_t prgm(uint32_t argc, const char_t *argv[]) {
    uint32_t    core, destCore;
    bool        display = false, generate = false;

    core = GET_RUNNING_CORE;
    (void)dprintf(KSYST, "Ipi test.\n");

    switch (argc) {
        case 2: {
            text_checkAsciiBuffer(argv[1], "-display",  &display);
            if (display) {
                if (vDataAvailable[core]) {
                    vDataAvailable[core] = false;
                    (void)dprintf(KSYST, "Counter = %"PRIu8"\n", vCounter[core]);
                }
                else {
                    (void)dprintf(KSYST, "No data!\n");
                }
                break;
            }
            text_checkAsciiBuffer(argv[1], "-generate",  &generate);
            if (generate) {
                destCore = (core == KCORE_0) ? 1U : 0U;
                if (clint->msip[destCore].msip == 0U) {
                    clint->msip[destCore].msip = 1U;
                }
                else {
                    (void)dprintf(KSYST, "Channel busy!\n");
                }
                break;
            }
            break;
        }
        default: {

// Make MISRA happy :-)

            break;
        }
    }
    return EXIT_OS_SUCCESS_CLI;
}

/*
 * \brief test_ipi_pre_init
 *
 * - Initialise the interruption vector
 *
 */
static  int32_t test_ipi_pre_init([[maybe_unused]] uint32_t argc, [[maybe_unused]] const char_t *argv[]) {
    uint32_t    core;

    core = GET_RUNNING_CORE;

    INT_INTERRUPT_VECTOR(IINT_MACHINE_SOFTWARE, local_machineSoftware_IRQHandler);

    clint->msip[core].msip = 0U;
    core_setBitCSR(RV_CSR_MIE, ((uint64_t)1U<<(uint64_t)IINT_MACHINE_SOFTWARE));
    return EXIT_OS_SUCCESS;
}

/*
 * \brief local_machineSoftware_IRQHandler
 *
 * - Increment a counter
 *
 */
static  void    local_machineSoftware_IRQHandler(uint32_t core, [[maybe_unused]] uint64_t parameter) {

    clint->msip[core].msip = 0U;
    vCounter[core]++;
    vDataAvailable[core] = true;
}
