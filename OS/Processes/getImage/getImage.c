/*
; getImage.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		imager process; continuous acquisition of an image.
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

#include	<stdint.h>
#include	<stdlib.h>

#include	"MT9V03x/MT9V03x.h"
#include	"cdc0/cdc0.h"
#include	"serial/serial.h"
#include	"imager/imager.h"
#include	"kern/kern.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"led/led.h"
// memo/memo.h is required for PROCESS_STACKMALLOC
#include	"memo/memo.h"		// IWYU pragma: keep
#include	"modules.h"
#include	"os_errors.h"
#include	"record/record.h"
#include	"types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"getImage    get image process: image acquisition.     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "getImage process\n"
									"=================\n\n"

									"Acquisition of an image\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		imager_clean(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);
static	void		local_transfer(void);

// This process has to run on the following cores:

#define	KEXECUTION_CORE		(1U<<BCORE_0)

MODULE(
	GetImage,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_IMAGER,					// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	imager_clean,					// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1U<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Process specific
// ================

#define	KTIME_ACQ	100U
#define	KLED_XFER	KLED_3

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_getImage";
STRG_LOC_CONST(aStrText[]) = "Process getImage: image acquisition.     (c) EFr-2026";

// Image 328 x 248
// Fixed exposure
//
static	const	mt9v03x_t	aTab328248F[] = {
								{ 1U,	0x00D9U }, { 2U,	0x007DU }, { 3U,	0x00F8U }, { 4U,	0x0149U }, { 5U,	0x016BU }, { 6U,	0x0032U }, { 7U,	0x0388U }, { 8U,	0x01E0U },
								{ 9U,	0x01E0U }, { 10U,	0x0164U }, { 11U,	0x0007U }, { 16U,	0x002DU }, { 21U,	0x8032U }, { 32U,	0x03D5U }, { 33U,	0x0012U }, { 34U,	0x0028U },
								{ 40U,	0x0016U }, { 41U,	0x0018U }, { 43U,	0x0003U }, { 44U,	0x0006U }, { 46U,	0x0004U }, { 47U,	0x0003U }, { 70U,	0x1606U }, { 71U,	0x8081U },
								{ 72U,	0x007FU }, { 104U,	0xE5F9U }, { 105U,	0x65D7U }, { 106U,	0x2950U }, { 107U,	0xA040U }, { 112U,	0x0032U }, { 114U,	0x0001U }, { 115U,	0x0307U },
								{ 116U,	0x0000U }, { 128U,	0x00F4U }, { 129U,	0x0004U }, { 130U,	0x0004U }, { 131U,	0x0004U }, { 132U,	0x0004U }, { 133U,	0x0004U }, { 134U,	0x0004U },
								{ 135U,	0x0004U }, { 136U,	0x0004U }, { 137U,	0x0004U }, { 138U,	0x0004U }, { 139U,	0x0004U }, { 140U,	0x0004U }, { 141U,	0x0004U }, { 142U,	0x0004U },
								{ 143U,	0x0004U }, { 144U,	0x0004U }, { 145U,	0x0004U }, { 146U,	0x0004U }, { 147U,	0x0004U }, { 148U,	0x0004U }, { 149U,	0x0004U }, { 150U,	0x0004U },
								{ 151U,	0x0004U }, { 152U,	0x0004U }, { 154U,	0x013FU }, { 155U,	0x02F0U }, { 156U,	0x02F0U }, { 157U,	0x02F0U }, { 160U,	0x00EFU }, { 161U,	0x01E0U },
								{ 162U,	0x01E0U }, { 163U,	0x01E0U }, { 165U,	0x0020U }, { 166U,	0x0008U }, { 168U,	0x0001U }, { 169U,	0x0008U }, { 171U,	0x0001U }, { 175U,	0x0001U },
								{ 176U,	0x2400U }, { 189U,	0x0120U }, { 194U,	0x0850U }, { 0U,	0x0000U }
							};

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	uint32_t	core;
	proc_t		*process;

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "imager: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "getImage: process imager launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief imager_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	imager_clean(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Image acquisition
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
	volatile		void			*image;
			const	bool			*killRequest;
	static	const	imagerCnf_t	configureIMG0 = {
										.oAcqMode  = KIMAGER_SNAP,
										.oPixMode  = KIMAGER_PIX_8_BITS,
										.oStRows   = 0U,
										.oStCols   = 0U,
										.oNbRows   = KIMAGER_NB_ROWS_QVGA,
										.oNbCols   = KIMAGER_NB_COLS_QVGA,
										.oKernSync = 0U,
										.oImgCnf   = aTab328248F,
										.oHSync    = NULL,
										.oFrame    = NULL,
										.oVSync	   = local_transfer,
										.oDMAEc    = NULL,
									};

	IMG0_reserve(KMODE_READ_WRITE, KWAIT_INFINITY);

// Waiting for 20s before starting

	killRequest	= (const bool *)argument;
	kern_suspendProcess(20000U);

	if (imager_configure(&configureIMG0) != KERR_IMAGER_NOERR) {
		LOG(KFATAL_SYSTEM, "getImage: imager configure");
		exit(EXIT_OS_PANIC);
	}

// Turn on the LED and start with the acquisitions

	imager_read(&image);
	imager_ctrlLeds(0b00000001u);
	imager_acquisition();

	while (*killRequest == false) {
		kern_suspendProcess(KTIME_ACQ);
		serial_write(KCDC0, (uint8_t *)(image), KIMAGER_NB_ROWS_QVGA * KIMAGER_NB_COLS_QVGA);
		imager_acquisition();
	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	IMG0_release(KMODE_READ_WRITE);

	led_off(KLED_XFER);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_transfer
 *
 * - Indicate that an image is ready
 *
 * - !!! This is an interrupt call-back function.
 *       Not all the system calls are allowed inside this portion of code.
 *
 */
static	void	local_transfer(void) {

	led_toggle(KLED_XFER);
}
