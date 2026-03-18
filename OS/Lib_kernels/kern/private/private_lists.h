/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - List management.
 *
 *           Private uKernel variables.
 *
 *           A process descriptor
 *           --------------------
 *
 *           31                              0
 *           +-------------------------------+
 *           | Ptr on proper list            +
 *           +-------------------------------+
 *           | Ptr on the back process       +
 *           +-------------------------------+
 *           | Ptr on the forward process    +
 *           +-------------------------------+
 *           | Specifications                +
 *           +-------------------------------+
 *           | Internal                      +
 *           +-------------------------------+
 *           | Statistic                     +
 *           +-------------------------------+
 *           | Synchro                       +
 *           +-------------------------------+
 *
 *           A list ...
 *           ----------
 *
 *           31                              0
 *           +-------------------------------+
 *           | Ptr on the first process      +
 *           +-------------------------------+
 *           | Ptr on the last process       +
 *           +-------------------------------+
 *           | Ptr on the current process    +
 *           +-------------------------------+
 *           | Number of processes linked    +
 *           +-------------------------------+
 *
 *           Example of linked list ...
 *           --------------------------
 *
 *           31                                  0
 *           +-----------------------------------+ X
 *           | Ptr on the first process   = A    + ------+
 *           +-----------------------------------+       |
 *           | Ptr on the last process    = B    + ------|-------+
 *           +-----------------------------------+       |       |
 *           | Number of processes linked = 3    +       |       |
 *           +-----------------------------------+       |       |
 *                                                   <---+       |
 * Desc 1    +-----------------------------------+ A <-------+   |
 *           | Ptr on proper list         = X    +           |   |
 *           +-----------------------------------+           |   |
 *           | Ptr on the back process    = 0    +           |   |
 *           +-----------------------------------+           |   |
 *           | Ptr on the forward process = C    + ------+   |   |
 *           +-----------------------------------+       |   |   |
 *                                                   <---|---|---+
 * Desc 3    +-----------------------------------+ B <---|---|---+
 *           | Ptr on proper list         = X    +       |   |   |
 *           +-----------------------------------+       |   |   |
 *           | Ptr on the back process    = C    + ------|---|---|---+
 *           +-----------------------------------+       |   |   |   |
 *           | Ptr on the forward process = 0    +       |   |   |   |
 *           +-----------------------------------+       |   |   |   |
 *                                                   <---|   |   |   |
 * Desc 2    +-----------------------------------+ C <-------|---|---+
 *           | Ptr on proper list         = X    +           |   |
 *           +-----------------------------------+           |   |
 *           | Ptr on the back process    = A    + ----------+   |
 *           +-----------------------------------+               |
 *           | Ptr on the forward process = B    + --------------+
 *           +-----------------------------------+
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup lists
 * @{
 */

/*!
 * \defgroup private_lists Private Lists
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    "kern/kern.h"

// Prototypes

/*!
 * \brief Initialise a list
 *
 * \param[in]   *list   Ptr on the list
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  void    lists_initialise(list_t *list);

/*!
 * \brief Connect a process to a list
 *
 * 2 possible cases:
 * - Case 1: IF (The list is empty)
 *           - THEN connect the "process" at the begin of the "list"
 *
 * - Case 2: IF (The list is not empty)
 *           - THEN connect the "process" to the last "process" of the "list"
 *
 * \param[in]   *list       Ptr on the list
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  void    lists_connect(list_t *list, proc_t *handle);

/*!
 * \brief Disconnect a process from the list_d and connect it to the list_c
 *
 * Disconnect
 * ----------
 *
 * 4 possible cases:
 * - Case 1: IF (The process is alone)
 *           - THEN disconnect the "process" from the "list"
 *
 * - Case 2: IF (The process is the first)
 *           - THEN disconnect the "process" from the "list"
 *             the next "process" becomes the "first"
 *
 * - Case 3: IF (The process is in the middle)
 *           - THEN disconnect the "process" from the "list"
 *             connect the next "process" to the previous one
 *
 * - Case 4: IF (The process is at the end)
 *           - THEN disconnect the "process" from the "list"
 *             the previous "process" becomes the "last" one
 *
 * Connect
 * -------
 *
 * 2 possible cases:
 * - Case 1: IF (The list is empty)
 *           - THEN connect the "process" at the begin of the "list"
 *
 * - Case 2: IF (The list is not empty)
 *           - THEN connect the "process" to the last "process" of the "list"
 *
 * \param[in]   *list_d     Ptr on the list (disconnect)
 * \param[in]   *list_c     Ptr on the list (connect)
 * \param[in]   *handle     Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
extern  void    lists_disconnectConnect(list_t *list_d, list_t *list_c, proc_t *handle);

/**@}*/
/**@}*/
/**@}*/
