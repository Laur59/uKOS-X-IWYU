/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:        Test reading & sending data via the cnms manager.
 */

#include    "board.h"
#include    "cmns.h"
#include    "macros_soc.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

/*
 * \brief test_02
 *
 * - Test reading & sending data via the cnms manager
 *
 */
static void test_02(void) {
    char_t  buffer[20] = "x - lala\n";

    cmns_init();

    while (true) {
        LED_RED_TOGGLE;
        cmns_receive(KURT0, &buffer[0]);

        if ((buffer[0] != '\n') && (buffer[0] != '\r') && (buffer[0] != '\0')) {
            cmns_send(KURT0, (const char_t *)buffer);
        }
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_02();
}
