/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     spi_commun equates.
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

// Bound of a single-byte transfer (spiN_writeRead), in ms. A byte takes
// microseconds at any speed; a transfer that has not completed within this time
// never will, and waiting forever hung the caller - the whole console when that
// was wkspi. Keep it at least one kernel tick: shorter rounds down to no wait.

#define KSPI_TIMEOUT_WRITEREAD      1000U

/**@}*/
/**@}*/
