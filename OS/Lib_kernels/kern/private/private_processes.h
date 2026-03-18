/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Process management.
 *
 *           Private uKernel variables.
 */

#pragma once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup processes
 * @{
 */

/*!
 * \defgroup private_processes Private Processes
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#include    <stdint.h>

#include    "kern/kern.h"
#include    "macros_soc.h"

#define KPROC_ANONYMOUS_ID  "Proc_anonymous"
#define KPROC_ANONYMOUS_TX  "Process anonymous.                        (c) EFr-2026"

extern          void        (*vKern_codeRoutine[KNB_CORES])(uint8_t state);     // Ptr on the Code for the call-back routine
extern          proc_t      *vKern_runProc[KNB_CORES];                          // Ptr on the current process
extern          proc_t      *vKern_backwardProc[KNB_CORES];                     // Ptr on the backward process
extern          proc_t      vKern_frstProc[KNB_CORES];                          // First process,  identifier = 0
extern          proc_t      vKern_proc[KNB_CORES][KKERN_NB_PROCESSES];          // User processes, identifier = 1..2^31; identifier = IDLE if 1
extern          list_t      vKern_listFree[KNB_CORES];                          // Empty list (processes reserve)
extern          list_t      vKern_listExec[KNB_CORES];                          // Execution list for all the priorities
extern          uint16_t    vKern_nbProc[KNB_CORES];                            // Nb of used processes
extern          uint16_t    vKern_nbMaxProc[KNB_CORES];                         // Max number of used processes
extern  const   void        **vKern_ptrGlobal[KNB_CORES];                       // Save the Ptr on a global variable

/**@}*/
/**@}*/
/**@}*/
