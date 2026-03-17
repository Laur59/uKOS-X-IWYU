/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; spi_commun.
; ===========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     spi_commun equates.
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
 * \defgroup spi_commun Spi_commun
 *
 * \brief Spi_commun
 *
 * Spi_commun management
 *
 * @{
 */

#include    <stdint.h>

// Configuration structure
// -----------------------

typedef struct  spiCnf  spiCnf_t;

struct spiCnf {
            uint32_t    oSpeed;                                 // SPI speed in bit/s
            uint8_t     oMode;                                  // Mode
            uint8_t     oClock;                                 // Clock format
};

// Mode (master/slave) (oMode)

enum {
            KSPI_MASTER = 0U,                                   // SPI master
            KSPI_SLAVE                                          // SPI slave
};

// Clock polarity (oClock)

enum {
            BSPI_POL = 0U,                                      // Polarity
            BSPI_PHA                                            // Phase
};

/**@}*/
/**@}*/
