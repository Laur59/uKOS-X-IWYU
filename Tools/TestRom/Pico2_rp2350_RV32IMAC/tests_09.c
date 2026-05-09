/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of TIMER0 alarm 0 (core 0) and alarm 1 (core 1) interrupts
 * using Hazard3 vectored interrupts (mtvec.MODE = 1) on both cores.
 *
 * Both cores point mtvec at the same vector_table_C0 — the trap
 * dispatcher in first_riscv.c is core-aware (handlers read
 * GET_RUNNING_CORE and dispatch through vExce_indIntVectors[core]),
 * so a single table serves both. A per-core vector_table_C1 can be
 * introduced later if a test needs different handlers on core 1.
 *
 * Expected on hardware:
 * - RED    (GPIO13) toggles every 1 s    (core 0 main-loop heartbeat)
 * - GREEN  (GPIO12) toggles every 500 ms (core 0, TIMER0 alarm 0)
 * - SYSTEM (GPIO25) toggles every 100 ms (core 1 main-loop heartbeat)
 * - YELLOW (GPIO11) toggles every 100 ms (core 1, TIMER0 alarm 1)
 */

#include    <stdint.h>

#include    "board.h"
#include    "clockTree.h"
#include    "cmns.h"
#include    "core.h"
#include    "first_riscv.h"
#include    "init.h"
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

static  void    local_TIM0_0_IRQHandler(void);
static  void    local_TIM0_1_IRQHandler(void);

extern  uint8_t     linker_topStackFirst_C1[];

// CORE 1
// ======

/*
 * \brief local_CodeCore_1
 *
 * - Blink the SYSTEM Led
 *
 */
static  void    local_codeCore_1(void) {

    __asm volatile ("la sp,linker_topStackFirst_C1");
    __asm volatile (
        ".option push            \n"
        ".option norelax         \n"
        "la     gp,__global_pointer$  \n"
        ".option pop             \n"
    );

// Switch core 1 to vectored mode (mtvec.MODE = 1)
// Shares vector_table_C0 with core 0; the trap dispatcher is core-aware

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)vector_table_C0) | 0x1u);

// Initialise the TIM0 Alarme 1 to generate an interruption every 100-ms

    REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;

    INTERRUPT_VECTOR(TIMER0_IRQ_1_C1_IRQn, local_TIM0_1_IRQHandler);
    core_enableExternalIRQ(TIMER0_IRQ_1_C1_IRQn);
    core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

// Waiting for the TIM0 Alarme 1 interruption

    INTERRUPTION_ON_HARD;

    while (true) {
        cmns_wait(100000);
        LED_SYSTEM_TOGGLE;
    }
}

/*
 * \brief local_TIM0_1_IRQHandler
 *
 * - Blink the YELLOW Led
 *
 */
static  void    local_TIM0_1_IRQHandler(void) {

// Acknowledge the TIM0 Alarme 1 interruption

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_1) != 0u) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_1;

        REG(TIMER0)->ALARM1 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_1;
        LED_YELLOW_TOGGLE;
    }
}

// CORE 0
// ======

/*
 * \brief test_09
 *
 * - Test of the TIM0 Alarme 0 (core 0) & 1 (core 1) interruption
 *
 */
static  void    test_09(void) {

// Switch core 0 to vectored mode (mtvec.MODE = 1)
// Safe to do here because mstatus.MIE is still cleared

    core_putCSR(RV_CSR_MTVEC, ((uint32_t)vector_table_C0) | 0x1u);

// Reset of the device

    REG(RESETS)->RESET &= ~RESETS_RESET_TIMER0;
    while ((REG(RESETS)->RESET_DONE & RESETS_RESET_TIMER0) != RESETS_RESET_TIMER0) { }

    REG(TIMER0)->INTR = 0xFFFFFFFFu;

// Enable both alarms in INTE before launching core 1 (avoids R-M-W race)

    REG(TIMER0)->INTE = TIMER_INTE_ALARM_0 | TIMER_INTE_ALARM_1;

    init_launchCore_1(local_codeCore_1);

// Initialise the TIM0 Alarme 0 to generate an interruption every 500-ms
    REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;

    INTERRUPT_VECTOR(TIMER0_IRQ_0_C0_IRQn, local_TIM0_0_IRQHandler);
    core_enableExternalIRQ(TIMER0_IRQ_0_C0_IRQn);
    core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

// Waiting for the TIM0 Alarme 0 interruption

    INTERRUPTION_ON_HARD;

    while (true) {
        cmns_wait(1000000);
        LED_RED_TOGGLE;
    }
}

/*
 * \brief local_TIM0_0_IRQHandler
 *
 * - Blink the GREEN Led
 *
 */
static  void    local_TIM0_0_IRQHandler(void) {

// Acknowledge the TIM0 Alarme 0 interruption

    if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_0) != 0u) {
        REG(TIMER0)->INTR = TIMER_INTR_ALARM_0;

        REG(TIMER0)->ALARM0 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
        LED_GREEN_TOGGLE;
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_09();
}
