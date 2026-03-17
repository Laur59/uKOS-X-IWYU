/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; temperature.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     temperature manager.
;
;-----
;------------------------------------------------------------------------
*/

#include    "temperature.h"

#include    <stdint.h>
#include    <stdlib.h>

#include    "kern/kern.h"
#include    "macros.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "modules.h"
#include    "os_errors.h"
#include    "record/record.h"
#include    "types.h"

#ifdef CONFIG_MAN_TEMPERATURE_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) = "temperature  temperature manager.                      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])        = "temperature manager\n"
                                    "===================\n\n"

                                    "This manager ...\n\n"

                                    "Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
    Temperature,                    // Module name (the first letter has to be upper case)
    KID_FAM_PERIPHERALS,            // Family (defined in the module.h)
    KNUM_TEMPERATURE,               // Module identifier (defined in the module.h)
    nullptr,                        // Address of the initialisation code (early pre-init)
    nullptr,                        // Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
    nullptr,                        // Address of the clean code (clean the module)
    " 1.0",                         // Revision string (major . minor)
    (1U<<BSHOW),                    // Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
    0                               // Execution cores
);

// Library specific
// ================

static  mutx_t      *vMutex_Reserve[KNB_CORES];

// Prototypes

static  int32_t     local_init(void);

/*
 * \brief Reserve the temperature manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = temperature_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    temperature_xyz();
 *    ....
 *    status = temperature_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode             Any mode
 * \param[in]   timeout                 Timeout (1-ms of resolution)
 * \param[in]   -                       KWAIT_INFINITY, waiting forever
 * \param[in]   -                       KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_TEMPERATURE_NOERR  The manager is reserved
 * \return      KERR_TEMPERATURE_GEERR  General error
 * \return      KERR_TEMPERATURE_CHBSY  The manager is busy
 *
 */
int32_t temperature_reserve(reserveMode_t reserveMode, uint32_t timeout) {
    int32_t     status;
    uint32_t    core;

    UNUSED(reserveMode);

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_TEMPERATURE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = kern_lockMutex(vMutex_Reserve[core], timeout);
    if (status != KERR_KERN_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_TEMPERATURE_CHBSY;
    }

    PRIVILEGE_RESTORE;
    return KERR_TEMPERATURE_NOERR;
}

/*
 * \brief Release the temperature manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = temperature_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode             Any mode
 * \return      KERR_TEMPERATURE_NOERR  OK
 * \return      KERR_TEMPERATURE_GEERR  General error
 * \return      KERR_TEMPERATURE_CAREL  Cannot release the manager
 *
 */
int32_t temperature_release(reserveMode_t reserveMode) {
    int32_t     status;
    uint32_t    core;

    UNUSED(reserveMode);

    core = GET_RUNNING_CORE;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_TEMPERATURE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = kern_unlockMutex(vMutex_Reserve[core]);
    if (status != KERR_KERN_NOERR) {
        PRIVILEGE_RESTORE;
        return KERR_TEMPERATURE_CAREL;
    }

    PRIVILEGE_RESTORE;
    return KERR_TEMPERATURE_NOERR;
}

/*
 * \brief Get the temperature (K)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    temperature;
 *
 *    status = temperature_read(&temperature);
 *
 *    (void)dprintf(KSYST, "Temp = %f\n", temperature);
 * \endcode
 *
 * \param[out]  *temperature            Ptr on the temperature
 * \return      KERR_TEMPERATURE_NOERR  OK
 * \return      KERR_TEMPERATURE_GEERR  General error
 *
 */
int32_t temperature_read(float64_t *temperature) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_TEMPERATURE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_temperature_read(temperature);
    PRIVILEGE_RESTORE;
    return status;
}

/*
 * \brief Set the temperature (K)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    temperature = 37.7 - KTEMPERATURE_ZERO_KELVIN;
 *
 *    status = temperature_write(temperature);
 * \endcode
 *
 * \param[in]   temperature             The temperature
 * \return      KERR_TEMPERATURE_NOERR  OK
 * \return      KERR_TEMPERATURE_GEERR  General error
 *
 */
int32_t temperature_write(float64_t temperature) {
    int32_t     status;

    PRIVILEGE_ELEVATE;
    status = local_init();
    if (status != KERR_TEMPERATURE_NOERR) { PRIVILEGE_RESTORE; return status; }

    status = stub_temperature_write(temperature);
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
            int32_t     status = KERR_TEMPERATURE_NOERR;
            uint32_t    core;
    static  bool        vInit[KNB_CORES] = MCSET(false);

    core = GET_RUNNING_CORE;

    INTERRUPTION_OFF;
    if (!vInit[core]) {
        vInit[core] = true;

        if (kern_createMutex(KTEMPERATURE_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "temperature: create mutx"); exit(EXIT_OS_PANIC); }

        status = stub_temperature_init();
    }
    RETURN_INT_RESTORE(status);
}

#endif
