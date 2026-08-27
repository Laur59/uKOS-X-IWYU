/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350_RV32IMAC – Exception and interrupt coreDump handler.
 *
 * Includes the four coreDump model fragments (tracing, generic, core, SOC).
 * NO_KERNEL_S gates out the record/log and process-name sections; the CSR
 * and register dump sections are fully active.
 *
 * Note: general-purpose register values in the stack-frame snapshot reflect
 * the dispatch level (first_handle_trap + first_dispatch_exception chain),
 * not the original fault-time values.  The CSR fields (mcause, mepc, …)
 * reported by local_printCore() are always accurate.
 */

#include    <stdint.h>

#include    "board.h"
#include    "cmns.h"
#include    "core.h"
#include    "crt0.h"
#include    "exce.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "soc_reg.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "exce         Exception management.                     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "Exce\n"
                                    "====\n\n"

                                    "This code manages the spurious exceptions.\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Exce,                           // Module name (the first letter has to be upper case)
    KID_FAM_STARTUPS,               // Family (defined in the module.h)
    KNUM_EXCE,                      // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Runtime specific
// ================

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

// Prototype (called by coreDump models at the end of the register dump)

[[noreturn]]
static  void    cb_signal(uint8_t mode);

/*
 * \brief cb_signal
 *
 * - Fault halt: all LEDs on, then blink one LED to distinguish type.
 *   - KEXCEPTION    → blink green LED (BLED_1)
 *   - KINTERRUPTION → blink red   LED (BLED_2)
 *
 * Called by the coreDump models after they have printed the full register dump.
 *
 */
[[noreturn]]
static void cb_signal(uint8_t mode) {
    uint32_t ledPin;

    switch (mode) {
        default:
        case KEXCEPTION: {
            LED_GREEN_OFF;
            ledPin = BLED_1;
            break;
        }
        case KINTERRUPTION: {
            LED_RED_OFF;
            ledPin = BLED_2;
            break;
        }
    }

    LED_SYSTEM_ON;
    LED_YELLOW_ON;
    LED_GREEN_ON;
    LED_RED_ON;

    while (true) {
        cmns_wait(1000000U);
        REG(SIO)->GPIO_OUT_CLR = (1U<<ledPin);
        cmns_wait(1000000U);
        REG(SIO)->GPIO_OUT_SET = (1U<<ledPin);
    }
}

#include    "model_coreDump_generic.c_inc"      // IWYU pragma: keep
#include    "model_coreDump_core.c_inc"         // IWYU pragma: keep

#ifdef __riscv

bool     vExce_isException[KNB_CORES] = MCSET(false);
#include    "model_coredump_soc_riscv.c_inc"    // IWYU pragma: keep

#include    "syscallDispatcher.h"

/*
 * \brief exce_init
 *
 * - Register coreDump handlers in all exception and interrupt vector slots
 *   for the running core.  Any unhandled exception or interrupt will produce
 *   a full register dump on the UART before halting with a blinking LED.
 *
 * \note This function does not return a value (None).
 *
 */
void    exce_init(void) {
    uint8_t     n;
    uint8_t     core = (uint8_t)GET_RUNNING_CORE;

    for (n = 0U; n < KNB_EXCEPTIONS;    n++) { vExce_indExcVectors[core][n] = model_coreDump_displayExceptions;    }
    for (n = 0U; n < KNB_INTERRUPTIONS; n++) { vExce_indIntVectors[core][n] = model_coreDump_displayInterruptions; }

    // Slot 11 = M-mode ecall; route to the syscall dispatcher, not coreDump.
    vExce_indExcVectors[core][11U] = syscallDispatcher;
}

#else

#include    "model_coredump_soc.c_inc"          // IWYU pragma: keep

/*
 * \brief exce_init
 *
 *
 * \note This function does not return a value (None).
 *
 */
void    exce_init(void) {
    uint8_t     nbExceptions, nbInterruptions;

    for (nbExceptions = 0U; nbExceptions < KNB_EXCEPTIONS; nbExceptions++) {
        vExce_indExcVectors[GET_RUNNING_CORE][nbExceptions] = nullptr;
    }

    for (nbInterruptions = 0U; nbInterruptions < KNB_INTERRUPTIONS; nbInterruptions++) {
        vExce_indIntVectors[GET_RUNNING_CORE][nbInterruptions] = nullptr;
    }

    core_setBASEPRI((uint32_t)KINT_LEVEL_PERIPHERALS<<(uint32_t)KNVIC_PRIORITY_SHIFT);
    REG(SCB)->AIRCR = SCB_AIRCR_VECTKEY_MASK | 0x0300U;

    REG(SCB)->SHCSR |= SCB_SHCSR_MEMFAULTENA | SCB_SHCSR_BUSFAULTENA | SCB_SHCSR_USGFAULTENA | SCB_SHCSR_SECUREFAULTENA;
}

#endif  // __riscv
