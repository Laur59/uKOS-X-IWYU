/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Kern - Statistic management.
 *
 *           This module is responsible for computing the statistic of
 *           the uKernel.
 */

#pragma once

#include    <stdint.h>

#include    "kern_types.h"  // IWYU pragma: keep

#if (KKERN_WITH_STATISTICS_S == true)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup statistics Statistics
 *
 * \brief Statistics
 *
 * Statistic management
 *
 * @{
 */

// Prototypes

#ifdef __cplusplus
extern  "C" {
#endif

/*!
 * \brief statistics_statistic
 *
 *   time
 *
 *          uKernel   process                  uKernel
 *    ----+         +------------------------+         +-------------------------
 *        |         |                        |         |
 *        +---------+                        +---------+
 *                ^                            ^     ^
 *                LastStart                    Stop  Start
 *    ............--------------------------------->----------------------.......
 *                      backward                       forward
 *
 *    ..............---xx---xxxx----x-x----xx-..........---xx---xxx-------.......
 *                      exceptions
 *
 * Durations:
 *  - uKernel   time = Start - Stop
 *  - Process   time = Stop - LastStart
 *  - Exception time = Sum ( x )
 *
 * For each process:
 * - PMin PAvg PMax in [us] (P stand for Process)
 * - KMin KAvg KMax in [us] (K stand for uKernel)
 * - EMin EAvg EMax in [us] (E stand for Exception)
 *
 * - The average time is computed in this way:
 *   - KNMEAN = 3, 2^3 = 8
 *
 *                            x ------- 7 ------- +   1       / ---- 8 -----
 *   - PAvg[k+1] = ( (PAvg[k] x ((1U<<KNMEAN)-1)) + PIns[k] ) / (1U<<KNMEAN)
 *   - KAvg[k+1] = ( (KAvg[k] x ((1U<<KNMEAN)-1)) + KIns[k] ) / (1U<<KNMEAN)
 *   - EAvg[k+1] = ( (EAvg[k] x ((1U<<KNMEAN)-1)) + EIns[k] ) / (1U<<KNMEAN)
 *
 * \param[in]   *backwardProcess    Ptr on the backward process
 * \param[in]   timeStart           Time when the process was scheduled
 * \param[in]   timeStop            Time when the process was stopped
 * \param[in]   timeLastStart       Time when the process was started (previous cycle)
 * \param[in]   timeE               Time spent in the exceptions (int managers)
 *
 * \note This function does not return a value (None).
 *
 */
extern  void    statistics_statistic(proc_t *backwardProcess, uint32_t timeStart, uint32_t timeStop, uint32_t timeLastStart, uint32_t timeE);

#ifdef __cplusplus
}
#endif

#define TIC_EXCEPTION_TIME      uint64_t    tic, tac;                                       \
                                kern_readTickCount(&tic)

#define TAC_EXCEPTION_TIME(core)                                                            \
                                kern_readTickCount(&tac);                                   \
                                vKern_TimeException[core] += (uint32_t)(tac - tic);         \
                                (void)vKern_TimeException[core]

/**@}*/
/**@}*/

#else

#define TIC_EXCEPTION_TIME
#define TAC_EXCEPTION_TIME

#endif
