/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     led manager.
 */

#ifdef CONFIG_MAN_LED_S

#include    "led.h"

#include    <stdint.h>

#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"      // IWYU pragma: keep (to get KNB_CORES)
#include    "modules.h"
#include    "os_errors.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "led          led manager.                              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "led manager\n"
                                    "===========\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Led,                            // Module name (the first letter has to be upper case)
    KID_FAM_PERIPHERALS,            // Family (defined in the module.h)
    KNUM_LED,                       // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Library specific
// ================

// Prototypes

static  int32_t     local_init(void);

/*
 * \brief Turn on a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *     status = led_on(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
int32_t led_on(uint8_t ledNb) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_LED_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_led_on(ledNb);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Turn off a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_off(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
int32_t led_off(uint8_t ledNb) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_LED_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_led_off(ledNb);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Change the state of a LED
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    ledNb;
 *
 *    status = led_toggle(ledNb);
 * \endcode
 *
 * \param[in]   ledNb           LED number
 * \return      KERR_LED_NOERR  OK
 * \return      KERR_LED_NODEV  The selected LED does not exist
 *
 */
int32_t led_toggle(uint8_t ledNb) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_LED_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_led_toggle(ledNb);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief General control of the LEDs
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = led_mute(true);  //
 *                              //
 *                              //
 *    status = led_mute(false); // Portion of code without any LED activity
 * \endcode
 *
 * \param[in]   mute            true -> turn off all the LEDs, false -> normal mode
 * \return      KERR_LED_NOERR  OK
 *
 */
int32_t led_mute(bool mute) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_LED_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_led_mute(mute);
    PRIVILEGE_RESTORE;
    return status;
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static  int32_t local_init(void) {
            int32_t     status = KERR_LED_NOERR;
            uint32_t    core;
    static  bool        vInit[KNB_CORES] = MCSET(false);

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;

        status = stub_led_init();
    }
    RETURN_INT_RESTORE(status);
}

#endif
