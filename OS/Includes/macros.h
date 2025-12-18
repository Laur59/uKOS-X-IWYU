/*
; macros.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Important generic macros.
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

#include	<stdint.h>	// IWYU pragma: keep

#if (defined(UKOS_S))
#include	"types.h"			// IWYU pragma: keep (for char_t)
// Note: RESERVE/RELEASE macros use KWAIT_INFINITY from kern/temporal.h
// Users must include kern/temporal.h explicitly to use these macros
#endif

// System & compiler
// -----------------

#define	QUOTE(name)				#name
#define	STRG(macro)				QUOTE(macro)

#if (defined(__clang__))
#define uKOS_COMPILER			"clang " STRG(__clang_major__) "." STRG(__clang_minor__) "." STRG(__clang_patchlevel__)
#define uKOS_COMPILER_VERSION	((__clang_major__ * 10000) + (__clang_minor__ * 100) + (__clang_patchlevel__))

#else
#define uKOS_COMPILER			"gcc-" STRG(__GNUC__) "." STRG(__GNUC_MINOR__) "." STRG(__GNUC_PATCHLEVEL__)
#define uKOS_COMPILER_VERSION	((__GNUC__ * 10000) + (__GNUC_MINOR__ * 100) + (__GNUC_PATCHLEVEL__))
#endif

// Variable alignment macros for C99 & C11
// ---------------------------------------

#if (defined(__STDC_VERSION__)) && (__STDC_VERSION__ < 201112L)
#define	VAR_DECLARED_ALIGN(varDeclared, boundary)											\
								varDeclared __attribute__ ((aligned (boundary)))

#else
#define	VAR_DECLARED_ALIGN(varDeclared, boundary)											\
								alignas (boundary) varDeclared
#endif

// Device reserve/release macros
// -----------------------------

#define	RESERVE(device, reserveMode)														\
								device##_reserve(reserveMode, KWAIT_INFINITY)
#define	RELEASE(device, reserveMode)														\
								device##_release(reserveMode)

// Some useful macros
// ------------------

#define	GET_PTR_32(ptr)			(															\
								((uint32_t)((const uint8_t *)(ptr))[0]<<24U) |				\
								((uint32_t)((const uint8_t *)(ptr))[1]<<16U) |				\
								((uint32_t)((const uint8_t *)(ptr))[2]<<8U)  |				\
								((uint32_t)((const uint8_t *)(ptr))[3]<<0U))

#define	UNUSED(x)				(void)(x)

#define	STRG_LOC_CONST(aId)		VAR_DECLARED_ALIGN(static const char_t	aId, 4)
#define	STRG_LOC_STATI(aId)		VAR_DECLARED_ALIGN(static		char_t	aId, 4)
#define	STRG_GLB_CONST(aId)		VAR_DECLARED_ALIGN(const		char_t	aId, 4)

#define ALIGNED_PTR(type, ptr)	((type *)__builtin_assume_aligned((ptr), _Alignof(type)))

// Call suffix for Applications (downloadable) or Tools (romable application)
// --------------------------------------------------------------------------

// If application (downloadable):
// int	main(int argc, const char *argv[]);
//
// If tool (romable application):
// static	int32_t	prgm(uint32_t argc, const char_t *argv[]);

#if (defined(ROMABLE_S))
#define	MAIN_ENTRY(argc, argv)	static	int32_t prgm(uint32_t argc, const char_t *argv)

#else
#define	MAIN_ENTRY(argc, argv)			int main(int argc, const char *argv)
#endif
