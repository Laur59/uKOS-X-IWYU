/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     machine manager.
 */

#pragma once

#include    <stdint.h>

#include    "kern/kern.h"
#include    "types.h"

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup machine Machine
 *
 * \brief Machine
 *
 * Machine management
 *
 * @{
 */

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

extern  int32_t stub_machine_restart(void);
extern  int32_t stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc);
extern  int32_t stub_machine_readFunctionName(const uintptr_t pc, const char_t **function);

/*!
 * \brief Read the PC of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * proc_t       *process;
 * uintptr_t    pc;
 *
 *    status = machine_readPC(process, &pc);
 * \endcode
 *
 * - This function returns the PC of a process
 *
 * \param[in]   *handle             Ptr on the handle
 * \param[out]  *pc                 Ptr on the pc
 * \return      KERR_MACHINE_NOERR  OK
 *
 */
extern  int32_t machine_readPC(const proc_t *handle, uintptr_t *pc);

/*!
 * \brief Read the function name
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          uintptr_t    pc;
 * const    char_t       *functionName
 *
 *    status = machine_readFunctionName(pc, &functionName);
 * \endcode
 *
 * - This function returns the name of a function
 *
 * \param[in]   pc                  The pc
 * \param[out]  **function          Ptr on the function name
 * \return      KERR_MACHINE_NOERR  OK
 *
 */
extern  int32_t machine_readFunctionName(const uintptr_t pc, const char_t **function);

/*!
 * \brief Restart of the system
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = stub_machine_restart();
 * \endcode
 *
 * \param[in]   -
 * \return      KERR_SYSTEM_NOERR   OK
 *
 */
extern  int32_t machine_restart(void);

// Stub functions (target-specific implementations)
// -------------------------------------------------

int32_t stub_machine_restart(void);
int32_t stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc);
int32_t stub_machine_readFunctionName(const uintptr_t pc, const char_t **function);

#ifdef __cplusplus
}
#endif

/**@}*/
/**@}*/
