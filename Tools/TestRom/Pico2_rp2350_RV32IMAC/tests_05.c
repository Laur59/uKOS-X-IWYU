/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the TIMER0 alarm 0 & 1 interrupts using Hazard3 vectored
 * interrupts (mtvec.MODE = 1).
 *
 * Expected on hardware:
 * - RED    (GPIO13) toggles every 100 ms (main-loop heartbeat)
 * - GREEN  (GPIO12) toggles every 500 ms (TIMER0 alarm 0)
 * - YELLOW (GPIO11) toggles every 100 ms (TIMER0 alarm 1)
 */

#include    <stdint.h>

#include    "board.h"
#include    "clockTree.h"
#include    "cmns.h"
#include    "core.h"
#include    "first_riscv.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

#define KTIM_ESAMPLING_0    ((float64_t)(0.5))                                  // 500-ms
#define KDELTA_TIME_0       ((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_0))     // Delta time

#define KTIM_ESAMPLING_1    ((float64_t)(0.1))                                  // 100-ms
#define KDELTA_TIME_1       ((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_1))     // Delta time

// Prototypes

static void local_TIM0_0_IRQHandler(void);
static void local_TIM0_1_IRQHandler(void);

/*
 * \brief test_05
 *
 * - Test of the TIM0 Alarme 0 & 1 interruptions
 *
 */
static void test_05(void) {

// Switch the trap entry to the local vector table (mtvec.MODE = 1)
// Safe to do here because mstatus.MIE is still cleared

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)vector_table_C0) | 0x1u);

// Reset of the device

    REG(RESETS)->RESET &= ~RESETS_RESET_TIMER0;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_TIMER0) != RESETS_RESET_TIMER0) { }

    REG(TIMER0)->INTR = 0xFFFFFFFFu;

// Initialise the TIM0 Alarme 0 to generate an interruption every 500-ms
// Initialise the TIM0 Alarme 1 to generate an interruption every 100-ms

    REG(TIMER0)->INTE   = REG(TIMER0)->INTE | TIMER_INTE_ALARM_0;
    REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
    REG(TIMER0)->INTE   = REG(TIMER0)->INTE | TIMER_INTE_ALARM_1;
    REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;

    INTERRUPT_VECTOR(TIMER0_IRQ_0_C0_IRQn, local_TIM0_0_IRQHandler);
    core_enableExternalIRQ(TIMER0_IRQ_0_C0_IRQn);

    INTERRUPT_VECTOR(TIMER0_IRQ_1_C0_IRQn, local_TIM0_1_IRQHandler);
    core_enableExternalIRQ(TIMER0_IRQ_1_C0_IRQn);

    core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

// Waiting for the TIM0 Alarme 0 & 1 interruption

    INTERRUPTION_ON_HARD;

    while (true) {
        cmns_wait(100000);
        LED_RED_TOGGLE;
    }
}

/*
 * \brief local_TIM0_0_IRQHandler
 *
 * - Blink the GREEN Led
 *
 */
static void local_TIM0_0_IRQHandler(void) {

// Acknowledge the TIM0 Alarme 0 interruption

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_0) != 0u) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_0;

        REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
        LED_GREEN_TOGGLE;
    }
}

/*
 * \brief local_TIM0_1_IRQHandler
 *
 * - Blink the YELLOW & GREEN Leds
 *
 */
static void local_TIM0_1_IRQHandler(void) {

// Acknowledge the TIM0 Alarme 1 interruption

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_1) != 0u) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_1;

        REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;
        LED_YELLOW_TOGGLE;
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_05();
}
