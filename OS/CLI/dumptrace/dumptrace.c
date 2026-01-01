/*
; dumptrace.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Display the trace fifo captured with record_trace().
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

#include	<inttypes.h>
#include	<stdint.h>	// NOLINT(misc-include-cleaner): Explicit include for IWYU compliance
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"kern/kern.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"macros_soc.h"
#include	"memo/memo.h"
#include	"modules.h"
#include	"record/private/private_record.h"
#include	"record/record.h"
#include	"serial/serial.h"
#include	"types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"dumptrace    Dump the trace buffer.                    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Dump the circular trace buffer\n"
									"==============================\n\n"

									"This tool display the content of the fifo trace\n\n"

									"Input format:  dumptrace {[core]}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_compose(const char_t *identifier, const char_t **idSpacer);

MODULE(
	Dumptrace,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DUMP_TRACE,							// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			char_t				*dummy;
			uint32_t			i, nbTraceWrites;
			uint32_t			core;
			recordTracing_t		*traceFifo, *rTraceFifo, *dst;
	const	recordTracing_t		*src;
	const	char_t				*identifier, *idSpacer;

	(void)dprintf(KSYST, "Trace dump.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// dumptrace
// dumptrace 0
// dumptrace n

	switch (argc) {
		case 1U: {
			core = 0U;
			break;
		}
		case 2U: {
			core = (uint32_t)strtol(argv[1], &dummy, 10U);
			if (core >= KNB_CORES) {
				core = 0U;
			}
			break;
		}
		default: {
			core = 0U;
			break;
		}
	}

	PRIVILEGE_ELEVATE;

// Reserve the necessary memory

	traceFifo = (recordTracing_t *)memo_malloc(KMEMO_ALIGN_8, (KRECORD_SZ_TRACE_FIFO * sizeof(recordTracing_t)), "dumptrace");
	if (traceFifo == NULL) {
		(void)dprintf(KSYST, "Not enough memory.\n");
		PRIVILEGE_RESTORE;

		return (EXIT_OS_FAILURE);
	}

// Copy the fifo into a memory (to ensure the coherence between the Fifo & the parameter)

	kern_criticalSection(KENTER_CRITICAL);

	dst = traceFifo;
	src = vRecord_traceFifo[core];
	memcpy(dst, src, KRECORD_SZ_TRACE_FIFO * sizeof(*dst));

	rTraceFifo    = (recordTracing_t *)(((uintptr_t)vRecord_RTraceFifo[core] - (uintptr_t)&vRecord_traceFifo[core][0]) + (uintptr_t)traceFifo);
	nbTraceWrites =	vRecord_NbTraceWrites[core];
	kern_criticalSection(KEXIT_CRITICAL);

	(void)dprintf(KSYST, "Trace provided by the core %"PRIu32"\n\n", core);
	(void)dprintf(KSYST, "      Time [us]   Parameter            Process or ISR identifier          Information\n\n");

	for (i = 0; i < nbTraceWrites; i++) {
		identifier = (rTraceFifo->oProcess == NULL) ? ("From ISR") : (rTraceFifo->oProcess->oSpecification.oIdentifier);
		local_compose(identifier, &idSpacer);
		(void)dprintf(KSYST, "%12lld-us   0x%016"PRIXPTR"   %s%s  %s\n", rTraceFifo->oTimeStamp, rTraceFifo->oParameter, identifier, idSpacer, rTraceFifo->oMessage);

		rTraceFifo = (rTraceFifo == &traceFifo[KRECORD_SZ_TRACE_FIFO]) ? (traceFifo) : (rTraceFifo + 1U);
	}
	(void)dprintf(KSYST, "\n");
	memo_delayedFree(traceFifo);
	PRIVILEGE_RESTORE;

	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_compose
 *
 * - input:  "1234567"
 * - output: "     "
 * - to accommodate "1234567     "
 * -                "            "
 *
 * \param[in]	*string		Ptr on a string
 * \param[out]	**spacer	Ptr on the final space
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_compose(const char_t *identifier, const char_t **idSpacer) {
	size_t	len;

// --------------------------------------|-------------------------------|---
//                                      "Process_to_count_the_number_xyztu";
	static	const	char_t	aSpacer[] = "                                 ";

	len = strlen(identifier);
	*idSpacer = (len <= (sizeof(aSpacer) - 1U)) ? (&aSpacer[len]) : (&aSpacer[0]);
}
