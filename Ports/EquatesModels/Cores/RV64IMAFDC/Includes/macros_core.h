/*
; macros_core.
; ============

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

#include	"core.h"	// IWYU pragma: keep
#include	"macros_soc.h"

// uKernel macros
// --------------

// Core machine in bits

#define	KMACHINE_BITS			(64U)

// Preemptions

#ifndef KSTATUS
#define	KSTATUS					(MSTATUS64_SD | MSTATUS_FS | MSTATUS_MPP | MSTATUS_MPIE)
#endif

#ifndef PREEMPTION_THRESHOLD
#define	PREEMPTION_THRESHOLD(core)																								\
								do {																							\
									extern	proc_t	*vKern_runProc[KNB_CORES]; 													\
																																\
									if (vKern_runProc[(uint32_t)core]->oSpecification.oPriority > KKERN_PRIORITY_LOW_00) {		\
										PREEMPTION;																				\
									}																							\
								} while (0)
#endif

// Elevation macros
// ----------------

#ifndef PRIVILEGE_ELEVATE
#define	PRIVILEGE_ELEVATE
#endif

#ifndef PRIVILEGE_RESTORE
#define	PRIVILEGE_RESTORE
#endif

#ifndef RIGHTS_ELEVATION
#define	RIGHTS_ELEVATION
#endif

#ifndef SET_USER_MODE
#define	SET_USER_MODE
#endif

#ifndef SET_PRIVILEGED_MODE
#define	SET_PRIVILEGED_MODE
#endif

#ifndef GET_ADDRESS_ELEVATION_CALLER
#define GET_ADDRESS_ELEVATION_CALLER
#endif

#ifndef GET_ADDRESS_CALLER
#define GET_ADDRESS_CALLER(address)
#endif

#ifndef CALL_FNCT_ELEVATION
#define CALL_FNCT_ELEVATION(function)
#endif

#ifndef KERN_RETURN_ELEVATION
#define	KERN_RETURN_ELEVATION
#endif

// Interruption macros
// -------------------

#ifndef KPROCESS_INIT_MCAUSE
#define	KPROCESS_INIT_MCAUSE	(MCAUSE_INTERRUPT | 11U)
#endif

#ifndef RETURN_INT_RESTORE
#define	RETURN_INT_RESTORE(status)																								\
								INTERRUPTION_RESTORE;																			\
								return (status)
#endif


#ifndef WAITING_INTERRUPTION
#define	WAITING_INTERRUPTION	__asm volatile ("																			 \n \
								wfi"																							\
								)
#endif

#ifndef GET_CURRENT_PROCESS_STACK
#define GET_CURRENT_PROCESS_STACK(stack)										 												\
								__asm volatile ("																			 \n \
								add			%0,x0,sp"																			\
								: "=r" (stack)																					\
								:																								\
								:																								\
								)
#endif

// Vector registration macros
// --------------------------
// Moved from macros_soc.h for IWYU compliance (eliminates circular dependency)
// K210 has PLIC-based interrupt architecture with three types of vectors
// (extern declarations remain in K210 macros_soc.h as they use SoC-specific constants)

#define	INT_EXCEPTION_VECTOR(vectorNb, address)																					\
								vExce_intExcVectors[GET_RUNNING_CORE][vectorNb] = address

#define	INT_INTERRUPT_VECTOR(vectorNb, address)																					\
								vExce_intIntVectors[GET_RUNNING_CORE][vectorNb] = address

#define	EXT_INTERRUPT_VECTOR(vectorNb, address)																					\
								vExce_extIntVectors[GET_RUNNING_CORE][vectorNb] = address

// Misc assembler macro
// --------------------

#ifndef NOP
#define	NOP 					__asm volatile ("																			 \n \
								nop"																							\
								)
#endif

#ifndef JUMP_FNCT
#define JUMP_FNCT(function)																										\
								__asm volatile ("																			 \n \
								j			"#function																			\
								)
#endif
