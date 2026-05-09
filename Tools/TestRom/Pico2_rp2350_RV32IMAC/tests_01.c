/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:    Test sending data via the cnms manager.
 *
 */

#include    "board.h"
#include    "cmns.h"
#include    "macros_soc.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

/*
 * \brief test_01
 *
 * - Test sending data via the cnms manager
 *
 */
static  void    test_01(void) {

    cmns_init();

    while (true) {
        cmns_wait(100000);
        LED_RED_TOGGLE;

        cmns_send(KURT0, "Nous sommes les petits Strumpfs, trala lala lala ...\n");
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_01();
}
