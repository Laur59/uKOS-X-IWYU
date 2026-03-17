/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; cdc1.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     cdc1 manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \addtogroup Lib_serials
 */
/**@{*/

/*!
 * \defgroup cdc1 Usb0
 *
 * \brief Cdc1
 *
 * Cdc1 management
 *
 * @{
 */

#include    <stdint.h>

#include    "serial_common.h"
#include    "types.h"

// Semaphores
// ----------

#define KCDC1_SEMAPHORE_RX      "cdc1 - RX char"
#define KCDC1_SEMAPHORE_TX      "cdc1 - TX buff"
#define KCDC1_MUTEX_RESERVE_RX  "Reserve_cdc1_R"
#define KCDC1_MUTEX_RESERVE_TX  "Reserve_cdc1_T"

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief Reserve the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_reserve(KMODE_WRITE, 1234);
 *    ....
 *    cdc1_xyz();
 *    ....
 *    status = cdc1_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \param[in]   timeout             Timeout (1-ms of resolution)
 * \param[in]   -                   KWAIT_INFINITY, waiting forever
 * \param[in]   -                   KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_SERIAL_NOERR   The manager is reserved
 * \return      KERR_SERIAL_GEERR   General error
 * \return      KERR_SERIAL_CHBSY   The manager is busy
 *
 */
extern  int32_t cdc1_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]   reserveMode         KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \return      KERR_SERIAL_NOERR   OK
 * \return      KERR_SERIAL_GEERR   General error
 * \return      KERR_SERIAL_CAREL   Cannot release the manager
 *
 */
extern  int32_t cdc1_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    cdcxCnf_t    configure = {
 *                              .oKernSync = (1U<<BSERIAL_SEMAPHORE_RX),
 *                        };
 *
 *    status = cdc1_configure(&configure);
 * \endcode
 *
 * \param[in]   *configure          Ptr on the configuration buffer
 * \return      KERR_SERIAL_NOERR   OK
 * \return      KERR_SERIAL_GEERR   General error
 * \return      KERR_SERIAL_NOCNF   The configuration does not exist
 *
 */
extern  int32_t cdc1_configure(const cdcxCnf_t *configure);

/*!
 * \brief Write a buffer to the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    10
 *
 * uint8_t    buffer[KSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 * int32_t    status;
 *
 *    status = cdc1_write(buffer, KSIZE);
 * \endcode
 *
 * \param[in]   *buffer             Ptr on the buffer
 * \param[in]   size                Size of the buffer
 * \return      KERR_SERIAL_NOERR   OK
 * \return      KERR_SERIAL_GEERR   General error
 * \return      KERR_SERIAL_SEPRO   The sender is busy
 * \return      KERR_SERIAL_LNBUB   The buffer length is too big
 * \return      KERR_SERIAL_LNBU0   The buffer length is = 0
 *
 */
extern  int32_t cdc1_write(const uint8_t *buffer, uint32_t size);

/*!
 * \brief Read a buffer from the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t     buffer[1];
 * uint32_t    size;
 * int32_t     status;
 *
 *    size = 1;
 *    status = cdc1_read(buffer, &size);
 * \endcode
 *
 * \param[in]       *buffer             Ptr on the buffer
 * \param[in, out]  *size               Ptr on the size
 * \return          KERR_SERIAL_NOERR   OK
 * \return          KERR_SERIAL_GEERR   General error
 * \return          KERR_SERIAL_RBUEM   The receiver buffer is empty
 * \return          KERR_SERIAL_RBFUL   The receiver buffer is full
 * \return          KERR_SERIAL_EROVR   Overrun error
 * \return          KERR_SERIAL_ERNOI   Noise error
 * \return          KERR_SERIAL_ERFRA   Framing error
 * \return          KERR_SERIAL_ERPAR   Parity error
 *
 */
extern  int32_t cdc1_read(uint8_t *buffer, uint32_t *size);

/*!
 * \brief Get the semaphore identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier[2];
 *
 *    status = cdc1_getIdSemaphore(BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = cdc1_getIdSemaphore(BSERIAL_SEMAPHORE_TX, &identifier[1];
 *
 *    (void)dprintf(KSYST, "Semaphore ids: %s, ...%s\n", identifier[0], identifier[1]);
 * \endcode
 *
 * \param[in]   semaphore           RX or TX semaphore
 * \param[out]  **identifier        Ptr on the semaphore identifier
 * \return      KERR_SERIAL_NOERR   OK
 * \return      KERR_SERIAL_GEERR   General error
 * \return      KERR_SERIAL_SENOE   The semaphore does not exist
 *
 */
extern  int32_t cdc1_getIdSemaphore(uint8_t semaphore, char_t **identifier);

/*!
 * \brief Flush the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_flush();
 * \endcode
 *
 * \param[in]   -
 * \return      KERR_SERIAL_NOERR   OK
 * \return      KERR_SERIAL_GEERR   General error
 *
 */
extern  int32_t cdc1_flush(void);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
