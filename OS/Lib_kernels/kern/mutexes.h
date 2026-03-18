/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Mutex management.
 *
 *           This module implements the mutex primitives.
 *
 *           Mutex system calls
 *           ------------------
 *
 *           void    mutexes_init(void) *
 *           int32_t kern_createMutex(const char_t *identifier, mutx_t **handle) *
 *           int32_t kern_unlockMutex(mutx_t *handle) *
 *           int32_t kern_lockMutex(mutx_t *handle, uint32_t timeout) *
 *           int32_t kern_killMutex(mutx_t *handle) *
 *           int32_t kern_restartMutex(mutx_t *handle) *
 *           int32_t kern_getMutexById(const char_t identifier, mutx_t **handle) *
 */

#pragma once

#include    <stdint.h>

#include    "kern_types.h"  // IWYU pragma: keep
#include    "types.h"

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup mutexes Mutexes
 *
 * \brief Mutexes
 *
 * Mutex management
 *
 * @{
 */

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    mutexes_init(void);

/*!
 * \brief Create a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mutx_t     *mutex;
 * const    char_t     identifier[] = ”Mutex 0”;
 *
 *    status = kern_createMutex(identifier, &mutex);
 * \endcode
 *
 * \param[in]   *identifier     Ptr on the mutex identifier (nullptr = anonymous)
 * \param[out]  **handle        Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_MUFUL No more mutex
 * \return      KERR_KERN_IDMUT The mutex identifier is already used
 *
 */
extern  int32_t kern_createMutex(const char_t *identifier, mutx_t **handle);

/*!
 * \brief Unlock a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_lockMutex(mutex);
 *    // Atomic access code portion
 *    status = kern_unlockMutex(mutex);
 * \endcode
 *
 * - counter++
 * - If (counter <= 0)
 *   - Then disconnect the first process from the mutex list (accordingly to the number of events)
 *   - Connect the process to the execution list
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOMUT The mutex does not exist
 * \return      KERR_KERN_MUTME The mutex counts too many events
 * \return      KERR_KERN_MUNOW The process is not the owner of the mutex
 * \return      KERR_KERN_FRISR Execution from ISR
 *
 */
extern  int32_t kern_unlockMutex(mutx_t *handle);

/*!
 * \brief lock a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_lockMutex(mutex);
 *    // Atomic access code portion
 *    status = kern_unlockMutex(mutex);
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
 * \return      KERR_KERN_NOMUT The mutex does not exist
 * \return      KERR_KERN_MUTME The mutex counts too many events
 * \return      KERR_KERN_MUKIL The mutex has been killed (with processes in its list)
 * \return      KERR_KERN_TIMEO Timeout
 * \return      KERR_KERN_FRISR Execution from ISR
 *
 */
extern  int32_t kern_lockMutex(mutx_t *handle, uint32_t timeout);

/*!
 * \brief Kill the mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_killMutex(mutex);
 * \endcode
 *
 * - If (process still connected to the mutex list)
 *   - Then return error
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOMUT The mutex does not exist
 *
 */
extern  int32_t kern_killMutex(mutx_t *handle);

/*!
 * \brief Restart the mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_restartMutex(mutex);
 * \endcode
 *
 * \param[in]   *handle         Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOMUT The mutex does not exist
 *
 */
extern  int32_t kern_restartMutex(mutx_t *handle);

/*!
 * \brief Get the handle of a mutex by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mutx_t     *mutex;
 * const    char_t     identifier[] = ”Mutex 0”;
 *
 *    status = kern_getMutexById(identifier, &mutex);
 * \endcode
 *
 * - This function returns the handle of the mutex
 *
 * \param[in]   *identifier     Ptr on the mutex identifier
 * \param[out]  **handle        Ptr on the handle
 * \return      KERR_KERN_NOERR OK
 * \return      KERR_KERN_NOMUT The mutex does not exist
 *
 */
extern  int32_t kern_getMutexById(const char_t *identifier, mutx_t **handle);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
