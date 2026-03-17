/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; watchdog.
; =========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     watchdog manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup watchdog Watchdog
 *
 * \brief Watchdog
 *
 * Watchdog management
 *
 * @{
 */

#include    <stdint.h>

// Watchdog modes
// --------------

enum {
        KWATCHDOG_AUTO = 0U,                                    // Mode auto (create a daemon to re-activate the watchdog)
        KWATCHDOG_MANUAL                                        // Mode manual (the user is responsible to re-activate the watchdog)
};

#define KWATCHDOG_MARGIN        (0.8)                           // Time margin for the watchdog process (timeProcessWatchdog = timeWatchdog * KWATCHDOG_MARGIN)
#define KWATCHDOG_MAX_TIME_MS   32767U                          // Time maximum (in ms) for the watchdog

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    stub_watchdog_arm(uint32_t time);

/*!
 * \brief Arm the watchdog
 *
 * \warning This function is hardware dependent
 *
 * Call example in C:
 *
 * \code{.c}
 * // KWATCHDOG_AUTO      -> Automatic mode (a daemon handles the watchdog)
 * // KWATCHDOG_MANUAL    -> Manual mode (the user handles the watchdog)
 *
 * #define    KWATCHDOG_TIME    10000    // Reset after 10000-ms
 *
 * int32_t    status;
 *
 *    status = watchdog_arm(KWATCHDOG_TIME, KWATCHDOG_AUTO);
 * \endcode
 *
 * - Generate a reset if the timer is not reactivated.
 *   The min-max time is hardware dependent (0 < time < 4294967296-ms)
 *   I.e for the stm32 series the min-max time is 8-ms < time < 32768-ms
 *   I.e for the gd32vf103 series the min-max time is 6.4 < time < 26214.4-ms
 *
 * \param[in]   time                Restart time if the watchdog is not re-activated
 * \param[in]   mode                KWATCHDOG_AUTO, create a daemon to re-activate the watchdog
 *              -                   KWATCHDOG_MANUAL, the user is responsible to re-activate the watchdog
 * \return      KERR_WATCHDOG_NOERR OK
 *
 */
extern  int32_t watchdog_arm(uint32_t time, uint8_t mode);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
