/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:    Test blink the RED, GREEN, YELLOW and system Leds.
 */

#include    "board.h"
#include    "cmns.h"
#include    "macros_soc.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

/*
 * \brief test_00
 *
 * - Test blink the RED, GREEN, YELLOW and system Leds
 *
 */
static void test_00(void) {

    while (true) {
        LED_SYSTEM_TOGGLE;
        cmns_wait(100000);

        LED_RED_TOGGLE;
        cmns_wait(100000);

        LED_GREEN_TOGGLE;
        cmns_wait(100000);

        LED_YELLOW_TOGGLE;
        cmns_wait(100000);
   }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_00();
}
