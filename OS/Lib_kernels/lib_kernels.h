/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; lib_kernels.
; ============

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     lib_kernels system call interface module.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

/*!
 * \defgroup Lib_kernels Library for micro-kernel
 *
 * \brief uKernel manager system calls
 *
 * The Lib_kernels library introduces the kern manager, dedicated to real
 * time control. It brings the features of a modern RTOS into a single point.
 *
 * The kern manager schedules tasks with precision. Each process receives
 * its share of the processor, and deadlines are respected without delay.
 * It also handles synchronisation. Semaphores, queues, and events ensure that
 * tasks communicate safely, avoiding both conflict and starvation.
 *
 * Time itself is central. The kern manager measures ticks, waits, and
 * periods, so that actions occur exactly when they are required to happen.
 * A modern RTOS must adapt to change. The kern manager allows priorities
 * to be altered, resources to be reallocated, and systems to remain steady.
 *
 * With Lib_kernels, real time is no longer fragile. It becomes a framework
 * where reliability, responsiveness, and control move hand in hand.
 *
 * @{
 */

// IWYU pragma: begin_exports

#include    "modules.h"
#include    "kern/kern.h"

// IWYU pragma: end_exports

/**!@}*/
