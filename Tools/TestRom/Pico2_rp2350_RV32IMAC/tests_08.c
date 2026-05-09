/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of the core 1 boot. init_launchCore_1 sends the core 1 entry
 * function via the SIO FIFO mailbox protocol; core 0 stays on its own
 * loop afterwards. No traps are taken, so this test does not switch
 * mtvec to vectored mode.
 *
 * Expected on hardware:
 * - GREEN  (GPIO12) toggles every 50 ms  (core 1 loop)
 * - RED    (GPIO13) toggles every 1 s    (core 0 loop)
 * - SYSTEM (GPIO25) toggles every 1 s    (core 0 loop)
 */

#include    "board.h"
#include    "cmns.h"
#include    "init.h"
#include    "macros_soc.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

// Prototypes

/*
 * \brief local_CodeCore_1
 *
 * - Blink the GREEN Led
 *
 */
static  void    local_codeCore_1(void) {

    __asm volatile ("la sp,linker_topStackFirst_C1");

    while (true) {
        cmns_wait(50000);

        LED_GREEN_TOGGLE;
    }
}

/*
 * \brief test_08
 *
 * - Test of the boot of the core 1
 *
 */
static  void    test_08(void) {

    init_launchCore_1(local_codeCore_1);
    cmns_init();

    while (true) {
        cmns_wait(1000000);

        LED_RED_TOGGLE;
        LED_SYSTEM_TOGGLE;
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_08();
}
