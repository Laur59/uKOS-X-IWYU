/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; i2c_commun.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     i2c_commun equates.
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
 * \defgroup i2c_commun I2c_commun
 *
 * \brief I2c_commun
 *
 * I2c_commun management
 *
 * @{
 */

#include    <stdint.h>

// Configuration structure
// -----------------------

typedef struct  i2cCnf  i2cCnf_t;

struct i2cCnf {
            uint32_t    oTimeout;                               // I2C bus timeout in ms
            uint32_t    oSpeed;                                 // I2C speed in bit/s
};

// Speed (oSpeed)

enum {
            KI2C_100KBPS =  100000U,                            // Sm, bus at 100-Kbit/s
            KI2C_400KBPS =  400000U,                            // Fm, bus at 400-Kbit/s
            KI2C_1MBPS   =  1000000U,                           // Fm+, bus at 1-Mbit/s
            KI2C_17MBPS  =  1700000U,                           // Hs, bus at 1.7-Mbit/s
            KI2C_34MBPS  =  3400000U,                           // Hs, bus at 3.4-Mbit/s
            KI2C_5MBPS   =  5000000U                            // UFm, bus at 5-Mbit/s
};

/**@}*/
/**@}*/
