/*
 * SPDX-License-Identifier: MIT
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
#include    <stdbool.h>

#include    "board.h"
#include    "cmns.h"
#include    "core.h"
#include    "crt0.h"
#include    "exce.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "syscallDispatcher.h"

// Runtime specific
// ================

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool     vExce_isException[KNB_CORES] = MCSET(false);

// Prototype (called by coreDump models at the end of the register dump)

static  void __attribute__ ((noreturn)) cb_signal(uint8_t mode);

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
static void __attribute__ ((noreturn)) cb_signal(uint8_t mode) {
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
        REG(SIO)->GPIO_OUT_CLR = (1u << ledPin);
        cmns_wait(1000000U);
        REG(SIO)->GPIO_OUT_SET = (1u << ledPin);
    }
}

#include    "model_coreDump_tracing.c_inc"      // IWYU pragma: keep
#include    "model_coreDump_generic.c_inc"      // IWYU pragma: keep
#include    "model_coreDump_core.c_inc"         // IWYU pragma: keep
#include    "model_coredump_soc_riscv.c_inc"    // IWYU pragma: keep

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
