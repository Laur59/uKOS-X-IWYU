/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Exercise the core-dump capture infrastructure of the uKOS-X uKernel.
 */

/*!
 * \file
 * \ingroup app_special
 * \brief Intentionally triggers a UsageFault to exercise the core-dump infrastructure.
 *
 *          Launch 0 processes:
 *
 *          - main: - Log a message announcing the fault
 *                  - Execute UDF #0 (undefined instruction) -> UsageFault / HardFault
 *                  - (System halted; the core-dump handler takes over)
 *
 *          Expected output on the serial console:
 *
 *          System dead! Core DUMP!!
 *          ========================
 *
 *          Exception: UsageFault_IRQHandler  (or HardFault if UsageFault not enabled)
 *          Routine:   ...
 *          Process:   ...
 *
 *          CFSR     = 0x00010000 UNDEFINSTR
 *
 *          CPU registers: (PC after the fault instruction)
 *          psp = ...  msp = ...
 *          r00 = ...  ...
 *          ...
 *
 */

#include    <stdint.h>

#include    "crt0.h"
#include    "kern/kern.h"
#include    "macros.h"
#include    "modules.h"
#include    "record/record.h"
#include    "types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "coredump     Exercise the core-dump capture.            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
                                    "===============================\n\n"

                                    "This user function module executes a UDF #0 (undefined instruction)\n"
                                    "to exercise the uKOS-X core-dump infrastructure. On ARM Cortex-M\n"
                                    "this raises UsageFault UNDEFINSTR, which escalates to HardFault if\n"
                                    "UsageFault is not separately enabled. The core-dump handler then\n"
                                    "prints the complete CPU/FPU register state and the faulting stack\n"
                                    "to the serial console.\n\n"

                                    "Input format:  coredump\n"
                                    "Output format: System dead! Core DUMP!! [register dump]\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#ifdef ROMABLE_S

static  int32_t     prgm(uint32_t argc, const char_t *argv[]);

MODULE(
    Coredump,                           // Module name (the first letter has to be upper case)
    KID_FAM_CLI,                        // Family (defined in the module.h)
    KNUM_ROMABLE_0,                     // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    prgm,                               // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);

#else
MODULE(
    UserAppl,                           // Module name (the first letter has to be upper case)
    KID_FAM_APPLICATIONS,               // Family (defined in the module.h)
    KNUM_APPLICATION,                   // Module identifier (defined in the module.h)
    nullptr,                            // Address of the initialisation code (early pre-init)
    aStart,                             // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                            // Address of the clean code (clean the module)
    " 1.0",                             // Revision string (major . minor)
    ((1U<<BSHOW) | (1U<<BEXE_CONSOLE)), // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                                   // Execution cores
);
#endif

/*
 * \brief main
 *
 * - Log the intent
 * - Execute UDF #0 to trigger UsageFault UNDEFINSTR (escalates to HardFault)
 * - The core-dump handler takes over and prints the full register dump
 *
 */
MAIN_ENTRY(argc, argv[]) {

    LOG(KINFO_USER, "Triggering UDF #0 -> UsageFault UNDEFINSTR");

// Undefined instruction: guaranteed UsageFault UNDEFINSTR on all ARM Cortex-M

    __asm volatile("udf #0");

    return EXIT_OS_SUCCESS_CLI;
}
