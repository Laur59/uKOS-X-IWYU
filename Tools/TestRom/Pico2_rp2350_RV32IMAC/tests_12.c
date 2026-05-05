/*
; tests_12.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:   Laurent von Allmen  The 2026-04-28
; Modifs:
;
; Project:  uKOS-X
; Goal:     Standalone Machine Software Interrupt (MSIP) probe.
;
; Mirrors the pattern of tests_03/04 (peripheral IRQ via Hazard3 MEINEXT) but for
; MSIP — the IRQ that the kernel uses for the first context switch
; (raised by GOTO_KERN_I -> SET_MESSAGE -> REG(SIO)->RISCV_SOFTIRQ).
;
; If the YELLOW LED toggles on cold boot, the MSIP wiring (mcause = 3
; dispatch via vExce_indIntVectors[core][3]) is alive end-to-end and the
; remaining Variant_Test scheduler bug is in the assembly trap-frame
; macros (KERN_SAVE_FRAME / local_MSIP_IRQHandler / KERN_NEW_FRAME),
; not in MSIP delivery itself. If YELLOW stays off, MSIP delivery is
; broken at the lower level.
;
; The RED LED toggles in the main loop as a "we're alive and the
; scheduler-free polling code is running" sanity light.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#include    <stdint.h>

#include    "Registers/soc_vectors.h"
#include    "board.h"
#include    "cmns.h"
#include    "core.h"
#include    "macros_core.h"
#include    "soc_reg.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

static  volatile    uint32_t    vMsipCount = 0U;

// Prototypes

static  void    local_MSIP_Handler(void);

/*
 * \brief test_12
 *
 * - Install MSIP handler in the software dispatch table
 * - Enable MSIE in mie, then enable global interrupts
 * - Poll: every 250 ms, raise MSIP and toggle the RED LED
 *   The MSIP handler should run between the trigger and the next
 *   iteration, toggling YELLOW.
 *
 */
static  void    test_12(void) {

// Install MSIP handler at vExce_indIntVectors[core][3]
// (MSIP_C0_IRQn == MSIP_IRQn == 3, the RISC-V mcause code for
//  machine software interrupt — see soc_vectors.h)

    INTERRUPT_VECTOR(MSIP_C0_IRQn, local_MSIP_Handler);

// Enable Machine Software Interrupt at the core level (mie.MSIE)

    core_setBitCSR(RV_CSR_MIE, MIE_MSIE);

// Enable global interrupts (mstatus.MIE)

    INTERRUPTION_ON_HARD;

// Light SYSTEM as a "test_12 has reached the loop" indicator

    LED_SYSTEM_ON;

    while (true) {

// Raise MSIP for this core via SIO

        REG(SIO)->RISCV_SOFTIRQ = SIO_RISCV_SOFTIRQ_CORE0_SET;

// Sanity blink so we know the main loop is still alive

        LED_RED_TOGGLE;
        cmns_wait(250000U);
    }
}

/*
 * \brief local_MSIP_Handler
 *
 * - Toggles YELLOW so we can see MSIP firing
 * - Clears the SIO RISCV_SOFTIRQ bit so the IRQ does not re-trigger
 *   immediately (otherwise the handler would re-enter as soon as we
 *   re-enable interrupts on return)
 *
 */
static  void    local_MSIP_Handler(void) {

    // Clear MSIP for this core (CORE0_CLR is bit 8 in SIO_RISCV_SOFTIRQ).
    // Writing the SET bit (bit 0) here would re-assert the IRQ and the
    // handler would re-enter forever — exactly what local_newContextPRE
    // in model_kernel_tim_0_a0_a1_msip_C0.c_inc does today (BUG to fix).
    REG(SIO)->RISCV_SOFTIRQ = SIO_RISCV_SOFTIRQ_CORE0_CLR;
    vMsipCount++;
    LED_YELLOW_TOGGLE;
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_12();
}
