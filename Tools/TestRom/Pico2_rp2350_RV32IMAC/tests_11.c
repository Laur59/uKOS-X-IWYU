/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the SIO doorbell IRQ. Core 0 rings doorbell bit 0 once per
 * second and doorbell bit 1 every tenth ring; core 1 services
 * SIO_IRQ_BELL via Hazard3 vectored interrupts (mtvec.MODE = 1) and
 * toggles a different LED per bit. Hazard3 MEIPRA defaults to priority
 * 0 ("never taken") for SIO_IRQ_BELL — the test sets priority 1
 * explicitly via core_setExternalIRQPriority.
 *
 * Core 0 stays in direct mode: it never takes a trap (no external
 * IRQs enabled on core 0).
 *
 * Expected on hardware:
 * - RED    (GPIO13) toggles every 1 s   (core 0 main loop, each iteration
 *   also rings doorbell bit 0)
 * - SYSTEM (GPIO25) toggles every 100 ms (core 1 main-loop heartbeat)
 * - YELLOW (GPIO11) toggles every 1 s   (core 1 doorbell bit 0)
 * - GREEN  (GPIO12) toggles every 10 s  (core 1 doorbell bit 1, fired
 *   on every tenth core-0 iteration)
 */

#include    <stdint.h>

#include    "board.h"
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

// Prototypes

static  void    local_doorBell_IRQHandler(void);

extern  uint8_t     linker_topStackFirst_C1[];

// CORE 1
// ======

/*
 * \brief local_CodeCore_1
 *
 * - Service the doorbell IRQ; toggle YELLOW on bit 0, GREEN on bit 1
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

// Initialise the door bell interruption
// NOTE: Hazard3 MEIPRA defaults to priority 0 for SIO_IRQ_BELL,
//       which means "never taken". Explicit priority > 0 is required.

    INTERRUPT_VECTOR(SIO_IRQ_BELL_C1_IRQn, local_doorBell_IRQHandler);
    core_setExternalIRQPriority(SIO_IRQ_BELL_C1_IRQn, 1u);
    core_enableExternalIRQ(SIO_IRQ_BELL_C1_IRQn);
    core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

// Waiting for the door bell interruption

    INTERRUPTION_ON_HARD;

    while (true) {
        cmns_wait(100000);
        LED_SYSTEM_TOGGLE;
    }
}

/*
 * \brief local_doorBell_IRQHandler
 *
 * - Toggle YELLOW on bit 0, GREEN on bit 1
 *
 */
static  void    local_doorBell_IRQHandler(void) {

// Acknowledge the door bell interruption

    if ((REG(SIO)->DOORBELL_IN_CLR & 0x1u) != 0u) { REG(SIO)->DOORBELL_IN_CLR = 0x1u; LED_YELLOW_TOGGLE; }
    if ((REG(SIO)->DOORBELL_IN_CLR & 0x2u) != 0u) { REG(SIO)->DOORBELL_IN_CLR = 0x2u; LED_GREEN_TOGGLE;  }
}

// CORE 0
// ======

/*
 * \brief test_11
 *
 * - Test of the door bell
 *
 */
static  void    test_11(void) {
    uint32_t    cpt = 0u;

    init_launchCore_1(local_codeCore_1);

// Generate a door bell on the core 1

    INTERRUPTION_ON_HARD;

    while (true) {
        cpt++;
        cmns_wait(1000000);
        LED_RED_TOGGLE;
        REG(SIO)->DOORBELL_OUT_SET = 0x1u;
        if ((cpt % 10u) == 0u) { REG(SIO)->DOORBELL_OUT_SET = 0x2u; }
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_11();
}
