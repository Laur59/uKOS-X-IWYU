/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     calendar manager.
 */

#pragma once

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup calendar Calendar
 *
 * \brief Calendar
 *
 * Calendar management
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"

// Modifiable in the makefile: default calendar parameters

#ifndef KCALENDAR_WITH_HW_RTC_S
#define KCALENDAR_WITH_HW_RTC_S     false
#endif

typedef enum {
            KFROM_TIMER = 0U,                                   // Time from the internal timer
            KFROM_RTC                                           // Time from the RTC
} calendarFromTimer_t;

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief Set UTC
 *
 * Call example in C:
 *
 * \code{.c}
 * char_t     utcLocation[] = { "CET+1"};
 * int32_t    status;
 *
 *    status = calendar_setUTCLocation(&utcLocation[0]);
 * \endcode
 *
 * \param[out]  *utcLocation        Ptr on the UTC location
 * \return      KERR_CALENDAR_NOERR OK
 *
 */
extern  int32_t calendar_setUTCLocation(const char_t *utcLocation);

/*!
 * \brief Write the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_writeUnixTime(unixTime);
 * \endcode
 *
 * \param[out]  unixTime            Unix time
 * \return      KERR_CALENDAR_NOERR OK
 *
 */
extern  int32_t calendar_writeUnixTime(uint64_t unixTime);

/*!
 * \brief Read the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_readUnixTime(KFROM_TIMER, &unixTime);
 * \endcode
 *
 * \param[in]   fromTimer           KFROM_TIMER, use the Unix time from the Timer (normal mode)
 *                                  KFROM_RTC, use the Unix time from the RTC (used for better precision)
 * \param[out]  *unixTime           Ptr on the Unix time
 * \return      KERR_CALENDAR_NOERR OK
 *
 */
extern  int32_t calendar_readUnixTime(calendarFromTimer_t fromTimer, uint64_t *unixTime);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
