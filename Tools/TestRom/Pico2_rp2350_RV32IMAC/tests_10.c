/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the spin lock under cross-core contention. Both cores run a
 * TIMER0 alarm handler that alternates SPIN_LOCK / SPIN_UNLOCK on the
 * same vTest_10 lock; the test passes when neither core deadlocks and
 * the LEDs keep blinking at their expected cadence.
 *
 * Both cores run on the direct-mode trap dispatcher (first_handle_trap)
 * rather than the vectored MEI handler. The vectored MEI handler drains
 * MEINEXT in a loop, which can dispatch the same alarm twice per trap
 * if the INTR clear has not yet propagated to MEINEXT — that breaks the
 * "one handler call per alarm event" assumption this test relies on,
 * since the static spin flips on each call. Direct mode dispatches once
 * per trap and preserves the test design.
 *
 * Expected on hardware (the asymmetric blink IS the test passing —
 * it's the visual proof that contention is happening and the lock is
 * serialising the two cores):
 * - RED    (GPIO13) toggles every 1 s    (core 0 main-loop heartbeat,
 *   slightly perturbed by lock contention)
 * - GREEN  (GPIO12) toggles every 500 ms (core 0, TIMER0 alarm 0).
 *   Core 0 holds the lock between consecutive alarm-0 fires, so
 *   GREEN-on phases coincide with the lock-held half-cycles.
 * - During GREEN-off (lock released): core 1 runs freely. YELLOW
 *   (alarm 1) and SYSTEM (cmns_wait heartbeat) both blink at their
 *   100 ms cadence and appear synchronised (both pause/resume on the
 *   same half-cycles).
 * - During GREEN-on (lock held by core 0): core 1's alarm 1 IRQ
 *   fires and immediately blocks on SPIN_LOCK; core 1 is stuck in
 *   the handler with MIE=0, so YELLOW and SYSTEM both freeze.
 * - Full cycle (1 s period): GREEN off → YELLOW/SYSTEM each blink
 *   ~3 visible cycles → GREEN on → YELLOW/SYSTEM pause.
 *
 * If the spin lock is broken, one or both cores wedge inside the
 * handler and the corresponding LEDs stop blinking entirely.
 */

#include    <stdint.h>

#include    "board.h"
#include    "clockTree.h"
#include    "cmns.h"
#include    "core.h"
#include    "init.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "soc_reg.h"
#include    "spin.h"
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
static  spinlock_t  vTest_10 = SPIN_LOCK_INIT;

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
 * - Blink the YELLOW & GREEN Leds
 *
 */
static  void    local_TIM0_1_IRQHandler(void) {

    static  bool    spin = false;

    if (spin == false) { spin = true;  SPIN_LOCK(vTest_10);   }
    else               { spin = false; SPIN_UNLOCK(vTest_10); }

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
 * \brief test_10
 *
 * - Test of the spin lock
 *
 */
static  void    test_10(void) {

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
    static  bool    spin = false;

    if (spin == false) { spin = true;  SPIN_LOCK(vTest_10);   }
    else               { spin = false; SPIN_UNLOCK(vTest_10); }

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
    test_10();
}
