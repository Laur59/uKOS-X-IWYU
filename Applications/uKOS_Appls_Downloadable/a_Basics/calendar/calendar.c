/*
; calendar.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Every 1000-ms
 *					- Display some time manipulations on the KSYST manager
 *					- Toggle LED 1
 *
 *			Note: KSYST is the default I/O channel defined by the PROCESS MACROS.
 *				  In this case, it is used the channel defined by the father
 *
 */

#include	<inttypes.h>
#include	<stdint.h>
#include	<stdio.h>
#include	<time.h>

#include	<sys/time.h>

#include	"crt0.h"
#include	"calendar/calendar.h"
#include	"serial/serial.h"
#include	"kern/kern.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"macros_core_stackFrame.h"
#include	"memo/memo.h"
#include	"led/led.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"record/record.h"
#include	"types.h"

#ifndef _CLOCKS_PER_SEC_
#error "_CLOCKS_PER_SEC_ is not defined"
#endif

#define CLOCKS_PER_SEC_CHECK(x) ((x) == 1000000)
static_assert(CLOCKS_PER_SEC_CHECK(_CLOCKS_PER_SEC_), "_CLOCKS_PER_SEC_ must be 1000000");

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"calendar     Example of how to use time.h functions.   (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  calendar\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	NULL,								// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,								// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Display some time manipulations on the KSYST manager
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
			time_t		now, newTime;
			clock_t		tic1, toc1;
			timeval_t	tic2, toc2;
			uint64_t	unixTime;
			float64_t	totalTime;
			tm_t		localTime, currentTime;
	static	char_t		formattedTime[100];

	UNUSED(argument);

// Time now (uinxtime)

	now = time(NULL);
	(void)dprintf(KSYST, "\nTime now = %"PRId64"\n", now);

// Convert to local time

	localtime_r(&now, &localTime);
	(void)dprintf(KSYST, "Local time: %s", asctime(&localTime));

// Calculate a new time (add 1 minute)

	localTime.tm_min += 1;
	newTime = mktime(&localTime);
	(void)dprintf(KSYST, "New timestamp (1 minute later): %"PRId64"\n", newTime);

// Format the time

	strftime(formattedTime, sizeof(formattedTime), "%I %p", &localTime);
	(void)dprintf(KSYST, "Formatted time: %s\n", formattedTime);

// Measure the execution time
// !!! This is the measure of the time used by the cpu

	tic1 = clock();
	kern_suspendProcess(1234U);
	toc1 = clock();

	totalTime = (float64_t)(toc1 - tic1) / CLOCKS_PER_SEC;
	(void)dprintf(KSYST, "Execution time: %.6f seconds\n", totalTime);

// Measure the real time
// !!! This is the measure of the real time

	gettimeofday(&tic2, NULL);
	kern_suspendProcess(1234U);
	gettimeofday(&toc2, NULL);

	totalTime = (double)(toc2.tv_sec - tic2.tv_sec) + (double)(toc2.tv_usec - tic2.tv_usec) / 1e6;
	(void)dprintf(KSYST, "Execution time: %.6f seconds\n", totalTime);

// Generate the new Unix time 64-bits with 1us

	currentTime.tm_year	 = 2025U - 1900U;
	currentTime.tm_mon	 = 3U - 1U;
	currentTime.tm_mday	 = 31U;
	currentTime.tm_hour	 = 16U;
	currentTime.tm_min	 = 07U;
	currentTime.tm_sec	 = 0U;
	currentTime.tm_isdst = 1U;

	now = mktime(&currentTime);
	if (now == -1 ) { (void)dprintf(KSYST, "Error: unable to make time using mktime\n\n"); }
	else {
		unixTime = (uint64_t)(now * CLOCKS_PER_SEC);
		calendar_writeUnixTime(unixTime);
		(void)dprintf(KSYST, "New Unix time 64-bits= %"PRId64"\n\n", unixTime);
	}

	while (true) {
		kern_suspendProcess(1000U);

		now = time(NULL);
		localtime_r(&now, &localTime);
		(void)dprintf(KSYST, "Local time: %s", asctime(&localTime));
		led_toggle(KLED_0);
	}
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	proc_t	*process_0;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
