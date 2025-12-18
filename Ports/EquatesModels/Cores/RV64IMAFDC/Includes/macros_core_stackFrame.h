/*
; macros_core_stackFrame.
; =======================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Stack frame management macros.
;			This file conains the most sensitive macros
;			for the uKernel management
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

#include	<stdlib.h>		// IWYU pragma: keep (for exit)

#include	"Registers/rv64_csr.h"
#include	"crt0.h"		// IWYU pragma: keep (for exit_terminate)
#include	"kern/kern.h"
#include	"macros_soc.h"
#include	"memo/memo.h"		// IWYU pragma: keep for KMEMO_ALIGN_8
#include	"record/record.h"
#include	"types.h"		// IWYU pragma: keep (for EXIT_OS_PANIC_STACK_UNDERFLOW)

// For the stack sanity

#ifndef KMAGICSTACK
#define KMAGICSTACK				(((uint32_t)'u'<<24U) | ((uint32_t)'K'<<16U) | ((uint32_t)'O'<<8U) | (uint32_t)'S')
#endif

#ifndef BREAK_IFDEBUGGING
#define	BREAK_IFDEBUGGING
#endif

#ifndef KSTATUS
#define	KSTATUS					(MSTATUS64_SD | MSTATUS_FS | MSTATUS_MPP | MSTATUS_MPIE)
#endif

#ifndef CHECK_STACK_SANITY
extern				proc_t	*vKern_runProc[KNB_CORES];
#define CHECK_STACK_SANITY(core)																								\
								if ((vKern_runProc[core]->oInternal.oState != 0U) && 											\
									((vKern_runProc[core]->oInternal.oState & (1U<<BPROC_FIRST)) == 0U)) {						\
									if ((vKern_runProc[core]->oSpecification.oStackStart > vKern_stackProc[core]) ||			\
										(vKern_runProc[core]->oSpecification.oStackStart[core] != KMAGICSTACK)) {			  	\
										LOG(KFATAL_KERNEL, "kern: stack underflow");										  	\
										BREAK_IFDEBUGGING;															  			\
										exit(EXIT_OS_PANIC_STACK_UNDERFLOW);											  		\
									}																				  			\
								}
#endif

// Stack alignment (see processes.h)

#ifndef KSTACK_ALIGNMENT
#define	KSTACK_ALIGNMENT		(16U)
#define	KSTACK_ALIGNMENT_MASK	(~(KSTACK_ALIGNMENT - 1U))
#define	KSTACK_ALIGNMENT_MEMO	(KMEMO_ALIGN_16)
#endif

// Critical stack size when < (70+10) 32-bit words (stack frame + reserve)

#ifndef KKERN_CRITICAL_SZ_STACK
#define	KKERN_CRITICAL_SZ_STACK		(70U + 10U)
#endif

// Stack sizes (in machine words of 32-bit)

#ifndef KKERN_SZ_STACK_SS
#define	KKERN_SZ_STACK_SS			200U
#endif
#ifndef KKERN_SZ_STACK_MM
#define	KKERN_SZ_STACK_MM			400U
#endif
#ifndef KKERN_SZ_STACK_LL
#define	KKERN_SZ_STACK_LL			600U
#endif
#ifndef KKERN_SZ_STACK_XL
#define	KKERN_SZ_STACK_XL			1000U
#endif
#ifndef KKERN_SZ_STACK_MIN
#define	KKERN_SZ_STACK_MIN			300U
#endif
#ifndef KKERN_SZ_STACK_XLIB
#define	KKERN_SZ_STACK_XLIB			(400U + 1000U)
#endif
#ifndef KKERN_SZ_STACK_MPY
#define	KKERN_SZ_STACK_MPY			(400U + 1000U)
#endif

// Stack frame macros
// ------------------

#if ((!defined(__clang__)) && (__GNUC__ >= 14))
#include	"macros_core_stackFrame_gcc.h"			// IWYU pragma: export
#endif

#ifdef __clang__
#include	"macros_core_stackFrame_clang.h"		// IWYU pragma: export
#endif
