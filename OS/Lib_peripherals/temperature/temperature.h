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

#pragma once

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup temperature Temperature
 *
 * \brief Temperature
 *
 * Temperature management
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"

// Semaphores
// ----------

#define KTEMPERATURE_MUTEX_RESERVE  "Reserve_temperature"

#define KTEMPERATURE_ZERO_KELVIN    ((float64_t)(-273.16))

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

#define TEMPERATURE_reserve temperature_reserve
#define TEMPERATURE_release temperature_release

extern  int32_t stub_temperature_init(void);
extern  int32_t stub_temperature_read(float64_t *temperature);
extern  int32_t stub_temperature_write(float64_t temperature);

/*!
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
extern  int32_t temperature_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
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
extern  int32_t temperature_release(reserveMode_t reserveMode);

/*!
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
extern  int32_t temperature_read(float64_t *temperature);

/*!
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
extern  int32_t temperature_write(float64_t temperature);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
