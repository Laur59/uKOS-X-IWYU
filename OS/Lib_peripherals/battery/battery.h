/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     battery manager.
 */

#pragma once

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup battery Battery
 *
 * \brief Battery
 *
 * Battery management
 *
 * @{
 */

#include    <stdint.h>

#include    "battery_common.h"
#include    "types.h"

// Semaphores
// ----------

#define KBATTERY_MUTEX_RESERVE  "Reserve_battery"

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

#define BATTERY_reserve     battery_reserve
#define BATTERY_release     battery_release

extern  int32_t stub_battery_init(void);
extern  int32_t stub_battery_read(batteryInfo_t *infoBattery);

/*!
 * \brief Reserve the battery manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = battery_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    battery_xyz();
 *    ....
 *    status = battery_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \param[in]   timeout             Timeout (1-ms of resolution)
 * \return      KERR_BATTERY_NOERR  The manager is reserved
 * \return      KERR_BATTERY_GEERR  General error
 * \return      KERR_BATTERY_CHBSY  The manager is busy
 *
 */
extern  int32_t battery_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the battery manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = battery_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         Any mode
 * \return      KERR_BATTERY_NOERR  OK
 * \return      KERR_BATTERY_GEERR  General error
 * \return      KERR_BATTERY_CAREL  Cannot release the manager
 *
 */
extern  int32_t battery_release(reserveMode_t reserveMode);

/*!
 * \brief Read the battery information
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t           status;
 * batteryInfo_t    infoBattery;
 *
 *    status = battery_read(&infoBattery);
 * \endcode
 *
 * \param[out]  *infoBattery        Ptr on the battery info
 * \return      KERR_BATTERY_NOERR  OK
 * \return      KERR_BATTERY_GEERR  General error
 *
 */
extern  int32_t battery_read(batteryInfo_t *infoBattery);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
