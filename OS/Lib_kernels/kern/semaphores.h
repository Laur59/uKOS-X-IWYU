/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Semaphore management.
 *
 *           This module implements the semaphore primitives.
 *
 *           Semaphore system calls
 *           ----------------------
 *
 *           void    semaphores_init(void) *
 *           int32_t kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle) *
 *           int32_t kern_signalSemaphore(sema_t *handle) *
 *           int32_t kern_waitSemaphore(sema_t *handle, uint32_t timeout) *
 *           int32_t kern_killSemaphore(sema_t *handle) *
 *           int32_t kern_restartSemaphore(sema_t *handle) *
 *           int32_t kern_getSemaphoreById(const char_t identifier, sema_t **handle) *
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup semaphores Semaphores
 *
 * \brief Semaphores
 *
 * Semaphore management
 *
 * @{
 */

#include    <stdint.h>

#include    "kern_types.h"  // IWYU pragma: keep
#include    "types.h"

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    semaphores_init(void);

/*!
 * \brief Create a generic semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          int32_t    iniCounter = 5;
 *          int32_t    maxCounter = 1;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_createSemaphore(identifier, iniCounter, maxCounter, &semaphore);
 * \endcode
 *
 * \param[in]   *identifier     Ptr on the semaphore identifier (nullptr = anonymous)
 * \param[in]   iniCounter      Initial counter value
 * \param[in]   maxCounter      Max counter value
 * \param[out]  **handle        Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_SEFUL No more semaphore
 * \return      KERR_KERN_IDSEM The semaphore identifier is already used
 *
 */
extern  int32_t kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);

/*!
 * \brief Signal a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_signalSemaphore(semaphore);
 * \endcode
 *
 * - counter++
 * - If (counter <= 0)
 *   - Then disconnect the first process from the semaphore list (accordingly to the number of events)
 *   - Connect the process to the execution list
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOSEM The semaphore does not exist
 * \return      KERR_KERN_SETME The semaphore counts too many events
 *
 */
extern  int32_t kern_signalSemaphore(sema_t *handle);

/*!
 * \brief Wait for a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_waitSemaphore(semaphore, timeout);
 * \endcode
 *
 * - counter -= 1
 * - If (counter < 0)
 *   - Then suspend the process
 *
 * \param[in]   *handle         Ptr on the handle
 * \param[in]   timeout         Timeout (1-ms of resolution)
 * \param[in]   -               KWAIT_INFINITY, waiting forever
 * \param[in]   -               KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOSEM The semaphore does not exist
 * \return      KERR_KERN_SETME The semaphore counts too many events
 * \return      KERR_KERN_SEKIL The semaphore has been killed (with processes in its list)
 * \return      KERR_KERN_TIMEO Timeout
 *
 */
extern  int32_t kern_waitSemaphore(sema_t *handle, uint32_t timeout);

/*!
 * \brief Kill the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_killSemaphore(semaphore);
 * \endcode
 *
 * - If (process still connected to the semaphore list)
 *   - Then return error
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOSEM The semaphore does not exist
 *
 */
extern  int32_t kern_killSemaphore(sema_t *handle);

/*!
 * \brief Restart the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_restartSemaphore(semaphore);
 * \endcode
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOSEM The semaphore does not exist
 *
 */
extern  int32_t kern_restartSemaphore(sema_t *handle);

/*!
 * \brief Get the handle of a semaphore by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_getSemaphoreById(identifier, &semaphore);
 * \endcode
 *
 * - This function returns the handle of the semaphore
 *
 * \param[in]   *identifier     Ptr on the semaphore identifier
 * \param[out]  **handle        Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOSEM The semaphore does not exist
 *
 */
extern  int32_t kern_getSemaphoreById(const char_t *identifier, sema_t **handle);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
