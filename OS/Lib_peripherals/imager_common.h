/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; imager_commun.
; ==============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     imager_commun equates.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup imager_commun Imager_commun
 *
 * \brief Imager_commun
 *
 * Imager_commun management
 *
 * @{
 */

#define     KIMAGER_SINGLE_BUFFER   0x80U                       // Single buffer
#define     KIMAGER_NB_ROWS_QVGA    240U                        // Number of rows (QVGA)
#define     KIMAGER_NB_COLS_QVGA    320U                        // Number of columns (QVGA)

// Configuration structure
// -----------------------

typedef struct  imagerCnf   imagerCnf_t;

struct imagerCnf {
            uint8_t     oAcqMode;                               // Acquisition mode
            uint8_t     oPixMode;                               // Pixel mode
            uint16_t    oStRows;                                // Start of rows
            uint16_t    oNbRows;                                // Number of rows
            uint16_t    oStCols;                                // Start of cols
            uint16_t    oNbCols;                                // Number of cols
            uint8_t     oKernSync;                              // uKernel synchro
            void        *oImgCnf;                               // Imager configuration table
            void        (*oHSync)(void);                        // Ptr on the callback HSync routine
            void        (*oFrame)(void);                        // Ptr on the callback Frame routine
            void        (*oVSync)(void);                        // Ptr on the callback VSync routine
            void        (*oDMAEc)(void);                        // Ptr on the callback DMAEc routine
};

// Pixel mode (Bits per pixel) (oPixMode)

enum {
            KIMAGER_PIX_8_BITS = 0U,                            // 8-bit resolution
            KIMAGER_PIX_10_BITS,                                // 10-bit resolution
            KIMAGER_PIX_12_BITS,                                // 12-bit resolution
            KIMAGER_PIX_14_BITS                                 // 14-bit resolution
};

// Kernel synchro semaphores

enum {
            BIMAGER_SEMAPHORE_IM = 0U,                          // IM semaphore
            BIMAGER_SEMAPHORE_VS                                // Vertical synchro semaphore
};

// Acquisition modes

enum {
            KIMAGER_CONT = 0U,                                  // Continuous mode
            KIMAGER_SNAP,                                       // Snapshot mode
            KIMAGER_SYNC                                        // Sync mode
};

// Operation modes

enum {
            KIMAGER_OPERATE = 0U,                               // Imager in a normal mode (run)
            KIMAGER_STANDBY                                     // Imager in standby
};

/**@}*/
/**@}*/
