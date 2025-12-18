/*
; viewer_uvc0_simule.
; ===================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Image viewer.
;			This tool allows to send a simulated image via the uvc0 manager.
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

#include	<inttypes.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"kern/kern.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"macros_core_stackFrame.h"
#include	"macros_soc.h"
#include	"memo/memo.h"
#include	"os_errors.h"
#include	"record/record.h"
#include	"serial/serial.h"
#include	"types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_GLB_CONST(aStrApplication[]) = "viewer       Send an image, via the uvc0 manager.      (c) EFr-2025";
STRG_GLB_CONST(aStrHelp[])		  = "Send a simulated image to the computer\n"
									"======================================\n\n"

								    "Input format:  viewer\n"
								    "Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

// Prototypes

		void	TinyUSB_video_init(void);
		void	TinyUSB_video_getImageSize(uint32_t *w, uint32_t *h);
		void	TinyUSB_video_sendImage(uint8_t *image, uint32_t w, uint32_t h);
static	void	aProcess(const void *argument);
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition);

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

/*
 * \brief viewer_uvc0
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int32_t	viewer_uvc0(uint32_t argc, const char_t *argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	uint32_t	core;
	proc_t		*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User";
	STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2025";

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

// Specifications for the processes

	PROCESS(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_05				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, &vKillRequest[core], &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "viewer: create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "viewer: application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief viewer_uvc0_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
int32_t	viewer_uvc0_clean(uint32_t argc, const char_t *argv[]) {
	UNUSED(argc);
	UNUSED(argv);

	uint32_t	core;

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief aProcess
 *
 * - Px: Repeat every xyz ms
 *			- Prepare an image
 *			- Send it over usb
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
			uint32_t	w, h, frame = 0U;
			float64_t	frameRate;
			uint8_t		*image_0, *image_1;
			uint64_t	time[2];
	const	bool		*killRequest;

	killRequest	= (const bool *)argument;

	PRIVILEGE_ELEVATE;

	TinyUSB_video_init();
	TinyUSB_video_getImageSize(&w, &h);

	image_0 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2U), "video");
	image_1 = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (w * h * 2U), "video");
	if ((image_0 == NULL) || (image_1 == NULL)) {
		LOG(KFATAL_USER, "viewer: out of memory");
		exit(EXIT_OS_FAILURE);
	}

	kern_readTickCount(&time[1]);
	while (!*killRequest) {
		time[0] = time[1];
		kern_readTickCount(&time[1]);

		frameRate = (1000000.0 / (float64_t)(time[1] - time[0])) * 2.0;

// Send it over usb
// Prepare the next image

		local_prepareImage(image_0, w, h, frame);
		TinyUSB_video_sendImage(image_0, w, h);
		frame++;

		local_prepareImage(image_1, w, h, frame);
		TinyUSB_video_sendImage(image_1, w, h);
		frame++;

		(void)dprintf(KSYST, "Image size: %"PRIu32" x %"PRIu32", Frame rate = %5.2f-fps\n", w, h, frameRate);
	}

// Kill the process & the ressources

	PRIVILEGE_RESTORE;

	INTERRUPTION_OFF;
	memo_free(image_0);
	memo_free(image_1);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_prepareImage
 *
 * - Prepare an image (vertical bars)
 *
 */
static	void	local_prepareImage(uint8_t *image, uint32_t w, uint32_t h, uint32_t startPosition) {
			size_t		i, j, idx;
			uint8_t		*p;
	const	size_t		half = (size_t)w / 2U;
	const	size_t		rowBytes = (size_t)w * 2U;
	const	size_t		span = ((size_t)w) / (2U * 8U);
	const	uint8_t		*end;


// EBU color bars: https://stackoverflow.com/questions/6939422

	static	const	uint8_t		aColorBars[8][4] = {

//		     Y,    U,    Y,    V
		{ 235U, 128U, 235U, 128U },		// 100% White
		{ 219U,  16U, 219U, 138U },		// Yellow
		{ 188U, 154U, 188U,  16U },		// Cyan
		{ 173U,  42U, 173U,  26U },		// Green
		{  78U, 214U,  78U, 230U },		// Magenta
		{  63U, 102U,  63U, 240U },		// Red
		{  32U, 240U,  32U, 118U },		// Blue
		{  16U, 128U,  16U, 128U },		// Black
	};

// Generate the 1st line

	end = &image[rowBytes];
	idx = (half - 1U) - ((size_t)startPosition % half);
	p = &image[idx * 4U];

	for (i = 0U; i < 8U; i++) {
		for (j = 0U; j < span; j++) {
			memcpy(p, &aColorBars[i][0], 4U);
			p += 4U;
			if (p == end) {
				p = image;
			}
		}
	}

// Duplicate the 1st line to the others

	p = &image[rowBytes];
	for (i = 1U; i < (size_t)h; i++) {

		memcpy(p, image, rowBytes);
		p = &p[rowBytes];
	}
}
