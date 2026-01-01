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
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
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

#include	"core.h"
#include	"core_reg.h"
#include	"soc_reg.h"


// Multicore macro
// ---------------

#define	KNB_CORES				2U
#define	KCORE_0					0U
#define	KCORE_1					1U

#ifndef GET_RUNNING_CORE
#define	GET_RUNNING_CORE		((uint32_t)(core_getCSR(RV_CSR_MHARTID) & 0x1u))
#endif

#ifndef MCSET
#if		(KNB_CORES == 1)
#define MCSET(v)				{ (v) }
#elif	(KNB_CORES == 2)
#define	MCSET(v)				{ (v), (v) }
#else
#error	"*** The number of cores (KNB_CORES) exceed 2"
#endif
#endif

// Baudrate macro
// --------------

[[maybe_unused]] static inline uint32_t BAUDRATE_H_val(uint32_t div) {
    return div >> 12;
}

[[maybe_unused]] static inline uint32_t BAUDRATE_L_val(uint32_t div) {
    return (div & 0xFFF) / 16;
}

[[maybe_unused]] static inline uint32_t BAUDRATE_F_val(uint32_t div) {
    return div & 0xF;
}

#define BAUDRATE(ck, baudrate, H, L, F)  do {						\
    uint32_t _div = (ck) / (baudrate);								\
    (H) = BAUDRATE_H_val(_div);										\
    (L) = BAUDRATE_L_val(_div);										\
    (F) = BAUDRATE_F_val(_div);										\
} while(0)

// Interruption macros
// -------------------

enum {

// Reserved names: all the possible levels
// Priorities used to set the PLIC. levels indicated with _KERNEL_
// are reserved for the uKernel (!!! do not change those values)

		KINT_LEVEL_ALL = 1U,
		KINT_LEVEL_KERNEL_PREEMPTION,
		KINT_LEVEL_KERNEL_TIMERS,
		KINT_LEVEL_PERIPHERALS,
		KINT_LEVEL_COMMUNICATIONS,
		KINT_LEVEL_KERNEL_SWI
};

// Reserved names: all the possible masks
// Masks used to filter some priorities
// KINT_IMASK_ALL				Allows all
// KINT_IMASK_KERNEL_PREEMPTION	Allows only NMI, SWI, communications, peripherals, kernel timers, kernel preemptions
// KINT_IMASK_PERIPHERALS		Allows only NMI, SWI, communications, peripherals
// KINT_IMASK_COMMUNICATIONS	Allows only NMI, SWI, communications
// KINT_IMASK_KERNEL_TIMERS		Allows only NMI, SWI, communications, peripherals, kernel timers
// KINT_IMASK_KERNEL_SWI		Allows only NMI, SWI
// KINT_IMASK_OFF				Allows only NMI, SWI

#define	KINT_IMASK_ALL					(KINT_LEVEL_ALL - 1U)
#define	KINT_IMASK_KERNEL_PREEMPTION	(KINT_LEVEL_KERNEL_PREEMPTION - 1U)
#define	KINT_IMASK_KERNEL_TIMERS		(KINT_LEVEL_KERNEL_TIMERS - 1U)
#define	KINT_IMASK_PERIPHERALS			(KINT_LEVEL_PERIPHERALS - 1U)
#define	KINT_IMASK_COMMUNICATIONS		(KINT_LEVEL_COMMUNICATIONS - 1U)
#define	KINT_IMASK_KERNEL_SWI			(KINT_LEVEL_KERNEL_SWI - 1U)
#define	KINT_IMASK_OFF					KINT_LEVEL_KERNEL_SWI

// Names for the user applications

#define	KHW_PRIORITY_LOW				KINT_LEVEL_KERNEL_PREEMPTION
#define	KHW_PRIORITY_MODERATE			KINT_LEVEL_KERNEL_TIMERS
#define	KHW_PRIORITY_HIGH				KINT_LEVEL_PERIPHERALS
#define	KHW_PRIORITY_VERY_HIGH			KINT_LEVEL_COMMUNICATIONS

// Pre-emption interruption
// GPIOHS0 Used for preemption (change the context)
// Pre-emption interruption (core 0)
// GPIOHS0 Used for preemption (change the context)
// Pre-emption interruption (core 1)
// GPIOHS1 Used for preemption (change the context)

#define	KKERN_PREEMPTION		EINT_GPIOHS0_INTERRUPT
#define	BKERN_PREEMPTION		0U
#define	KKERN_PREEMPTION_C0		EINT_GPIOHS0_INTERRUPT
#define	BKERN_PREEMPTION_C0		0U
#define	KKERN_PREEMPTION_C1		EINT_GPIOHS1_INTERRUPT
#define	BKERN_PREEMPTION_C1		1U

#define KEXCEPTION				0U
#define KINTERRUPTION			1U

extern	bool					vExce_isException[KNB_CORES];
extern	void					(*vExce_intIntVectors[KNB_CORES][KNB_INT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void					(*vExce_intExcVectors[KNB_CORES][KNB_INT_EXCEPTIONS])(uint32_t core, uint64_t parameter);
extern	void					(*vExce_extIntVectors[KNB_CORES][KNB_EXT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void					(*vMsgs_process[KNB_CORES])(uint32_t core, uint64_t message);

#ifndef KERN_SAVE_PRIORITY
#define	KERN_SAVE_PRIORITY		threshold = (uint64_t)plic->targets.target[core].priority_threshold & 0x00000000000000FFu
#endif

#ifndef KERN_NEW_PRIORITY
#define	KERN_NEW_PRIORITY		plic->targets.target[core].priority_threshold = (uint32_t)(threshold & 0x00000000000000FFu)
#endif

#ifndef INTERRUPTION_SET
#define	INTERRUPTION_SET		plic->targets.target[GET_RUNNING_CORE].priority_threshold = KINT_IMASK_ALL
#endif

#ifndef INTERRUPTION_SET_PERIPH
#define	INTERRUPTION_SET_PERIPH	plic->targets.target[GET_RUNNING_CORE].priority_threshold = KINT_IMASK_PERIPHERALS
#endif

#ifndef INTERRUPTION_OFF_HARD
#define	INTERRUPTION_OFF_HARD	core_clrBitCSR(RV_CSR_MIE, (uint64_t)MIP_MEIP);												   	\
								core_clrBitCSR(RV_CSR_MSTATUS, (uint64_t)MSTATUS_MIE)
#endif

#ifndef INTERRUPTION_ON_HARD
#define	INTERRUPTION_ON_HARD	core_setBitCSR(RV_CSR_MIE, (uint64_t)MIP_MEIP);												  	\
								core_setBitCSR(RV_CSR_MSTATUS, (uint64_t)MSTATUS_MIE)

#endif

#ifndef INTERRUPTION_OFF
#define	INTERRUPTION_OFF		volatile	uint32_t	__savePLIC_msk __attribute__ ((unused));  								\
								__savePLIC_msk = plic->targets.target[GET_RUNNING_CORE].priority_threshold;						\
								(void)__savePLIC_msk;																			\
								plic->targets.target[GET_RUNNING_CORE].priority_threshold = KINT_IMASK_OFF
#endif

#ifndef INTERRUPTION_RESTORE
#define	INTERRUPTION_RESTORE																									\
								do {																							\
									typeof(__savePLIC_msk)	const	msk_  = (__savePLIC_msk);									\
									typeof(plic)			const	plic_ = (plic);												\
								    plic_->targets.target[GET_RUNNING_CORE].priority_threshold = msk_;							\
								} while (0)
#endif

#ifndef INTERRUPTION_OFF_CRITICAL
#define	INTERRUPTION_OFF_CRITICAL(savemMask)																					\
								savemMask = plic->targets.target[GET_RUNNING_CORE].priority_threshold;							\
								plic->targets.target[0].priority_threshold = KINT_IMASK_OFF
#endif

#ifndef INTERRUPTION_RESTORE_CRITICAL
#define	INTERRUPTION_RESTORE_CRITICAL(savemMask)											   						   			\
								plic->targets.target[0].priority_threshold = savemMask
#endif

#ifndef IS_EXCEPTION
#define	IS_EXCEPTION			(vExce_isException[core])
#endif

#ifndef PREEMPTION
#define	PREEMPTION				if (GET_RUNNING_CORE == 0U) {																	\
									gpiohs->rise_ie.u32[0]   |= (1U<<BKERN_PREEMPTION_C0);										\
									gpiohs->input_val.u32[0] |= (1U<<BKERN_PREEMPTION_C0);										\
								}																								\
								else {																							\
									gpiohs->rise_ie.u32[0]   |= (1U<<BKERN_PREEMPTION_C1);										\
									gpiohs->input_val.u32[0] |= (1U<<BKERN_PREEMPTION_C1);										\
								}
#endif

// INT_EXCEPTION_VECTOR, INT_INTERRUPT_VECTOR, and EXT_INTERRUPT_VECTOR macros
// moved to macros_core.h for IWYU compliance
