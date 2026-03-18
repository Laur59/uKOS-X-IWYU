/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     adc manager.
 */

#pragma once

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup adc Adc
 *
 * \brief Adc
 *
 * Adc management
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"

// Semaphores
// ----------

#define KADC_MUTEX_RESERVE      "Reserve_adc"

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

#define ADC_reserve     adc_reserve
#define ADC_release     adc_release

extern  int32_t stub_adc_init(void);
extern  int32_t stub_adc_read(uint8_t channel, float64_t *reference, float64_t *data);

/*!
 * \brief Reserve the adc manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = adc_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    adc_xyz();
 *    ....
 *    status = adc_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode     Any mode
 * \param[in]   timeout         Timeout (1-ms of resolution)
 * \param[in]   -               KWAIT_INFINITY, waiting forever
 * \param[in]   -               KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_ADC_NOERR  The manager is reserved
 * \return      KERR_ADC_GEERR  General error
 * \return      KERR_ADC_CHBSY  The manager is busy
 *
 */
extern  int32_t adc_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the adc manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = adc_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode     Any mode
 * \return      KERR_ADC_NOERR  OK
 * \return      KERR_ADC_GEERR  General error
 * \return      KERR_ADC_CAREL  Cannot release the manager
 *
 */
extern  int32_t adc_release(reserveMode_t reserveMode);

/*!
 * \brief Read an analog channel
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    reference, result[6];
 * uint8_t      channel;
 *
 *    for (channel = 0; channel < 6; channel++) {
 *        status = adc_read(channel, &reference, &result[channel]);
 *        if (status != KERR_ADC_NOERR) {
 *            return status;
 *        }
 *    }
 * \endcode
 *
 * \param[in]   channel         Channel (0..n)
 * \param[out]  *reference      Ptr on the reference of the A/D
 * \param[out]  *data           Ptr on the conversion result
 * \return      KERR_ADC_NOERR  OK
 * \return      KERR_ADC_GEERR  General error
 * \return      KERR_ADC_NODEV  The selected channel does not exist
 *
 */
extern  int32_t adc_read(uint8_t channel, float64_t *reference, float64_t *data);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
