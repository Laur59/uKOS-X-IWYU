/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; shared_spi0.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     For the shared_spi0 manager module.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "os_errors.h"

// Served managers
// ---------------

enum {
        KNOMANAGER = 0U,                        // No manager
        KIMU,                                   // imu manager
        KIMUA,                                  // Accelerometer imu manager
        KIMUM,                                  // Magnetometer imu manager
        KTEMPERATURE,                           // Temperature temperature manager
};

// Peripheral macro
// ----------------

#define RESERVE_SHARED_SPI0(manager)    shared_spi0_reserve(manager, KWAIT_INFINITY);
#define RELEASE_SHARED_SPI0             shared_spi0_release();

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  int32_t shared_spi0_reserve(uint32_t manager, uint32_t timeout);
extern  int32_t shared_spi0_release(void);
extern  int32_t shared_spi0_select(uint32_t manager);
extern  int32_t shared_spi0_deselect(uint32_t manager);
extern  int32_t shared_spi0_writeRead(uint8_t *data);

#ifdef __cplusplus
}
#endif

// Shared spi0 device errors & status
// ----------------------------------

#define KSHARED_SPI0_NOERR  KERR_SPI_NOERR      // No error
#define KSHARED_SPI0_CHBSY  KERR_SPI_CHBSY      // The manager is busy
#define KSHARED_SPI0_GEERR  KERR_SPI_GEERR      // General error
#define KSHARED_SPI0_TIMEO  KERR_SPI_TIMEO      // Timeout error
#define KSHARED_SPI0_SENOE  KERR_SPI_SENOE      // The semaphore does not exist
#define KSHARED_SPI0_CAREL  KERR_SPI_CAREL      // Cannot release the manager
