/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; battery_common.
; ===============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     battery_common equates.
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
 * \defgroup batx_commun Batx_commun
 *
 * \brief Batx_commun
 *
 * Batx_commun management
 *
 * @{
 */

#include    <stdint.h>

#include    "types.h"

// Battery info structure
// ----------------------

typedef struct  batteryInfo batteryInfo_t;

struct batteryInfo {
            float64_t   oVoltage;                               // Battery voltage [V]
            float64_t   oCurrent;                               // Battery average current (- = charging current) [mA]
            float64_t   oTemperature;                           // Battery temperature [K]
            float64_t   oFullChargedCapacity;                   // Battery full charged capacity [mAh]
            float64_t   oRemainingCapacity;                     // Battery remaining capacity [mAh]
            uint16_t    oTimeToEmpty;                           // Time to battery empty [m]
            uint16_t    oCycles;                                // Number of cycles [-]
};

/**@}*/
/**@}*/
