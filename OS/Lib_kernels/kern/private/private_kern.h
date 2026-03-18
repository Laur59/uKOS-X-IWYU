/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - misc management.
 *
 *           Private uKernel variables.
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup kern
 * @{
 */

/*!
 * \defgroup private_kern Private Kern
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    <stdint.h>

#include    "macros_soc.h"

// Have to be used with the macros
// GOTO_KERN_I and GOTO_KERN_M

// For the uKernel basic services

#define KKERN_MSG_NO_PARAM          (0x0000u<<16U)                  // Message without parameters
#define KKERN_MSG_JUMP_KERN         (KKERN_MSG_NO_PARAM + 0x0000u)  // Message: jump to the uKernel
#define KKERN_MSG_WAIT_TIME         (KKERN_MSG_NO_PARAM + 0x0001u)  // Message: waiting for a time
#define KKERN_MSG_WAIT_SIGN         (KKERN_MSG_NO_PARAM + 0x0002u)  // Message: waiting for a signal

// For the uKernel semaphore synchronizations
// For the uKernel mutex synchronizations

#define KKERN_MSG_WAIT_SEMA_SYN     (0x0001u<<16U)                  // Message: waiting for a semaphore
#define KKERN_MSG_WAIT_MUTX_SYN     (0x0002u<<16U)                  // Message: waiting for a mutex

// For the uKernel mailbox synchronizations

#define KKERN_MSG_WAIT_MBOX_E       (0x0003u<<16U)                  // Message: waiting for an mbox empty
#define KKERN_MSG_WAIT_MBOX_F       (0x0004u<<16U)                  // Message: waiting for an mbox full

extern  uint32_t    vKern_nbIntImbrications[KNB_CORES];             // Nb of interruptions imbrications

/**@}*/
/**@}*/
/**@}*/
