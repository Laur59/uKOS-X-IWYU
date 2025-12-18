/*
; macros_soc.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Important macros.
;
;   © 2025-2026, Edo. Franzi
;   ------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma	once

#include	<stdint.h>

// Multicore macro
// ---------------

#define	KNB_CORES				1U
#define	KCORE_0					0U

#ifndef GET_RUNNING_CORE
#define	GET_RUNNING_CORE		0U
#endif

#ifndef MCSET
#if		(KNB_CORES == 1)
#define MCSET(v)				{ (v) }
#else
#error	"*** The number of cores (KNB_CORES) exceed 1"
#endif
#endif

// Baudrate macro
// --------------

[[maybe_unused]] static inline uint32_t BAUDRATE_LP(uint32_t ck, uint32_t baudrate) {
	return (uint32_t)((256 * (uint64_t)ck) / baudrate);
}
[[maybe_unused]] static inline uint32_t BAUDRATE(uint32_t ck, uint32_t baudrate) {
    return ck / baudrate;
}

// Interruption macros
// -------------------

enum {

// Reserved names: all the possible levels
// Priorities used to set the NVIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

		KINT_LEVEL_KERNEL_SWI = 1U,
		KINT_LEVEL_COMMUNICATIONS,
		KINT_LEVEL_PERIPHERALS,
		KINT_LEVEL_KERNEL_TIMERS,
		KINT_LEVEL_KERNEL_PREEMPTION,
		KINT_LEVEL_ALL
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_OFF				Allows only NMI, SWI
// KINT_IMASK_KERNEL_SWI		Allows only NMI, SWI
// KINT_IMASK_COMMUNICATIONS	Allows only NMI, SWI, communications
// KINT_IMASK_PERIPHERALS		Allows only NMI, SWI, communications, peripherals
// KINT_IMASK_KERNEL_TIMERS		Allows only NMI, SWI, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_PREEMPTION	Allows only NMI, SWI, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_ALL				Allows all

#define	KINT_IMASK_OFF					(KINT_LEVEL_KERNEL_SWI + 1U)
#define	KINT_IMASK_KERNEL_SWI			(KINT_LEVEL_KERNEL_SWI + 1U)
#define	KINT_IMASK_COMMUNICATIONS		(KINT_LEVEL_COMMUNICATIONS + 1U)
#define	KINT_IMASK_PERIPHERALS			(KINT_LEVEL_PERIPHERALS + 1U)
#define	KINT_IMASK_KERNEL_TIMERS		(KINT_LEVEL_KERNEL_TIMERS + 1U)
#define	KINT_IMASK_KERNEL_PREEMPTION	(KINT_LEVEL_KERNEL_PREEMPTION + 1U)
#define	KINT_IMASK_ALL					(KINT_LEVEL_ALL + 1U)

// Names for the user applications

#define	KHW_PRIORITY_LOW				KINT_LEVEL_KERNEL_PREEMPTION
#define	KHW_PRIORITY_MODERATE			KINT_LEVEL_KERNEL_TIMERS
#define	KHW_PRIORITY_HIGH				KINT_LEVEL_PERIPHERALS
#define	KHW_PRIORITY_VERY_HIGH			KINT_LEVEL_COMMUNICATIONS

// 2^4 priority levels
// Priority shift inside the NVIC->PR (P3 P2 P1 P0 x x x x) !!! Vendor specific

#define	KNVIC_PRIORITY_BITS		4U
#define	KNVIC_PRIORITY_SHIFT	(8U - KNVIC_PRIORITY_BITS)

// PENDSVSET used for preemption (change the context)

#define	BKERN_PREEMPTION		28U

// EXCEPTION_VECTOR and INTERRUPT_VECTOR macros moved to macros_core.h for IWYU compliance
