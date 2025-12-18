/*
; imgk.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		imgk manager.
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

#include	"imgk.h"
#include	"OV2640.h"

#include	<math.h>
#include	<stdint.h>
#include	<stdlib.h>

#include	"Registers/K210_dvp.h"
#include	"Registers/K210_plic.h"
#include	"Registers/soc_vectors.h"
#include	"clockTree.h"
#include	"kern/kern.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"macros_soc.h"
#include	"memo/memo.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"record/record.h"
#include	"types.h"

extern				void		(*vExce_extIntVectors[KNB_CORES][KNB_EXT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
static				uint16_t	*vImageE0 = NULL;
static				uint16_t	*vImageE1 = NULL;
static				sema_t		*vSeHandleAQ;
static				sema_t		*vSeHandleIM;
static				mutx_t		*vMutex;
static	volatile	uint8_t		vPage = 1U;

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"imgk         imgk manager.                             (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "imgk manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	Imgk,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KIMGK_NUM,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1U<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

// See tables 12-13 of the OV2640
// Initialisation table proposed in the document OV2640 Camera Module
// Software Application Note, chapter 13.2 RGB 565 Referce setting
// Mclk = 24-MHz, SVGA RGB565, output 25-fps

static	const	ov2640_t	aOV2640_Cnf[] = {
								{ 0xFFU, 0x01U },
								{ 0x12U, 0x80U },
								{ 0xFFU, 0x00U },
								{ 0x2CU, 0xFFU },
								{ 0x2EU, 0xDFU },
								{ 0xFFU, 0x01U },
								{ 0x3CU, 0x32U },
								{ 0x11U, 0x00U },
								{ 0x09U, 0x02U },
								{ 0x04U, 0x28U },
								{ 0x13U, 0xE5U },
								{ 0x14U, 0x48U },
								{ 0x2CU, 0x0CU },
								{ 0x33U, 0x78U },
								{ 0x3AU, 0x33U },
								{ 0x3BU, 0xFBU },
								{ 0x3EU, 0x00U },
								{ 0x43U, 0x11U },
								{ 0x16U, 0x10U },
								{ 0x39U, 0x92U },
								{ 0x35U, 0xDAU },
								{ 0x22U, 0x1AU },
								{ 0x37U, 0xC3U },
								{ 0x23U, 0x00U },
								{ 0x34U, 0xC0U },
								{ 0x36U, 0x1AU },
								{ 0x06U, 0x88U },
								{ 0x07U, 0xC0U },
								{ 0x0DU, 0x87U },
								{ 0x0EU, 0x41U },
								{ 0x4CU, 0x00U },
								{ 0x48U, 0x00U },
								{ 0x5BU, 0x00U },
								{ 0x42U, 0x03U },
								{ 0x4AU, 0x81U },
								{ 0x21U, 0x99U },
								{ 0x24U, 0x40U },
								{ 0x25U, 0x38U },
								{ 0x26U, 0x82U },
								{ 0x5CU, 0x00U },
								{ 0x63U, 0x00U },
								{ 0x46U, 0x22U },
								{ 0x0CU, 0x3CU },
								{ 0x61U, 0x70U },
								{ 0x62U, 0x80U },
								{ 0x7CU, 0x05U },
								{ 0x20U, 0x80U },
								{ 0x28U, 0x30U },
								{ 0x6CU, 0x00U },
								{ 0x6DU, 0x80U },
								{ 0x6EU, 0x00U },
								{ 0x70U, 0x02U },
								{ 0x71U, 0x94U },
								{ 0x73U, 0xC1U },
								{ 0x12U, 0x40U },
								{ 0x17U, 0x11U },
								{ 0x18U, 0x43U },
								{ 0x19U, 0x00U },
								{ 0x1AU, 0x4BU },
								{ 0x32U, 0x09U },
								{ 0x37U, 0xC0U },
								{ 0x4FU, 0xCAU },
								{ 0x50U, 0xA8U },
								{ 0x5AU, 0x23U },
								{ 0x6DU, 0x00U },
								{ 0x3DU, 0x38U },
								{ 0xFFU, 0x00U },
								{ 0xE5U, 0x7FU },
								{ 0xF9U, 0xC0U },
								{ 0x41U, 0x24U },
								{ 0xE0U, 0x14U },
								{ 0x76U, 0xFFU },
								{ 0x33U, 0xA0U },
								{ 0x42U, 0x20U },
								{ 0x43U, 0x18U },
								{ 0x4CU, 0x00U },
								{ 0x87U, 0xD5U },
								{ 0x88U, 0x3FU },
								{ 0xD7U, 0x03U },
								{ 0xD9U, 0x10U },
								{ 0xD3U, 0x82U },
								{ 0xC8U, 0x08U },
								{ 0xC9U, 0x80U },
								{ 0x7CU, 0x00U },
								{ 0x7DU, 0x00U },
								{ 0x7CU, 0x03U },
								{ 0x7DU, 0x48U },
								{ 0x7DU, 0x48U },
								{ 0x7CU, 0x08U },
								{ 0x7DU, 0x20U },
								{ 0x7DU, 0x10U },
								{ 0x7DU, 0x0EU },
								{ 0x90U, 0x00U },
								{ 0x91U, 0x0EU },
								{ 0x91U, 0x1AU },
								{ 0x91U, 0x31U },
								{ 0x91U, 0x5AU },
								{ 0x91U, 0x69U },
								{ 0x91U, 0x75U },
								{ 0x91U, 0x7EU },
								{ 0x91U, 0x88U },
								{ 0x91U, 0x8FU },
								{ 0x91U, 0x96U },
								{ 0x91U, 0xA3U },
								{ 0x91U, 0xAFU },
								{ 0x91U, 0xC4U },
								{ 0x91U, 0xD7U },
								{ 0x91U, 0xE8U },
								{ 0x91U, 0x20U },
								{ 0x92U, 0x00U },
								{ 0x93U, 0x06U },
								{ 0x93U, 0xE3U },
								{ 0x93U, 0x05U },
								{ 0x93U, 0x05U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x04U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x93U, 0x00U },
								{ 0x96U, 0x00U },
								{ 0x97U, 0x08U },
								{ 0x97U, 0x19U },
								{ 0x97U, 0x02U },
								{ 0x97U, 0x0CU },
								{ 0x97U, 0x24U },
								{ 0x97U, 0x30U },
								{ 0x97U, 0x28U },
								{ 0x97U, 0x26U },
								{ 0x97U, 0x02U },
								{ 0x97U, 0x98U },
								{ 0x97U, 0x80U },
								{ 0x97U, 0x00U },
								{ 0x97U, 0x00U },
								{ 0xC3U, 0xEDU },
								{ 0xA4U, 0x00U },
								{ 0xA8U, 0x00U },
								{ 0xC5U, 0x11U },
								{ 0xC6U, 0x51U },
								{ 0xBFU, 0x80U },
								{ 0xC7U, 0x10U },
								{ 0xB6U, 0x66U },
								{ 0xB8U, 0xA5U },
								{ 0xB7U, 0x64U },
								{ 0xB9U, 0x7CU },
								{ 0xB3U, 0xAFU },
								{ 0xB4U, 0x97U },
								{ 0xB5U, 0xFFU },
								{ 0xB0U, 0xC5U },
								{ 0xB1U, 0x94U },
								{ 0xB2U, 0x0FU },
								{ 0xC4U, 0x5CU },
								{ 0xC0U, 0x64U },
								{ 0xC1U, 0x4BU },
								{ 0x8CU, 0x00U },
								{ 0x86U, 0x3DU },
								{ 0x50U, 0x00U },
								{ 0x51U, 0xC8U },
								{ 0x52U, 0x96U },
								{ 0x53U, 0x00U },
								{ 0x54U, 0x00U },
								{ 0x55U, 0x00U },
								{ 0x5AU, 0xC8U },
								{ 0x5BU, 0x96U },
								{ 0x5CU, 0x00U },
								{ 0xD3U, 0x82U },
								{ 0xC3U, 0xEDU },
								{ 0x7FU, 0x00U },
								{ 0xDAU, 0x08U },
								{ 0xE5U, 0x1FU },
								{ 0xE1U, 0x67U },
								{ 0xE0U, 0x00U },
								{ 0xDDU, 0x7FU },
								{ 0x05U, 0x00U }
							};

#define	KNBCNF		(sizeof(aOV2640_Cnf) / sizeof(ov2640_t))

// Prototypes

static	int32_t	local_init(void);
static	void	local_initCKRate(const cnfImgk_t *configure);
static	void	local_initImages(const cnfImgk_t *configure);
static	void	local_initOV2640(const cnfImgk_t *configure);
		void	local_DVP_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief Reserve the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    imgk_xyz();
 *    ....
 *    status = imgk_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \return		KERR_IMGK_NOERR	The manager is reserved
 * \return		KERR_IMGK_GEERR	General error
 * \return	  	KERR_IMGK_CHBSY	The manager is busy
 *
 */
int32_t	imgk_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	UNUSED(reserveMode);

	int32_t		status;

	status = local_init();
	if (status != KERR_IMGK_NOERR) { return (status); }

	status = kern_lockMutex(vMutex, timeout);
	if (status != KERR_IMGK_NOERR) {
		return (KERR_IMGK_CHBSY);
	}
	return (KERR_IMGK_NOERR);
}

/*!
 * \brief Release the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_CAREL	Cannot release the manager
 *
 */
int32_t	imgk_release(reserveMode_t reserveMode) {
	UNUSED(reserveMode);

	int32_t		status;

	status = local_init();
	if (status != KERR_IMGK_NOERR) { return (status); }

	status = kern_unlockMutex(vMutex);
	if (status != KERR_IMGK_NOERR) {
		return (KERR_IMGK_CAREL);
	}
	return (KERR_IMGK_NOERR);
}

/*
 * \brief Configure the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * // Example of table concerns the OV2640 imager
 * // See tables 12-13 of the OV2640
 * // Initialisation table proposed in the document OV2640 Camera Module
 * // Software Application Note, chapter 13.2 RGB 565 Referce setting
 * // Mclk = 24-MHz, SVGA RGB565, output 25-fps
 *
 * static    const    ov2640_t    aOV2640_Cnf[] = {
 *                                      { 0xFF, 0x01 }, { 0x12, 0x80 }, { 0xFF, 0x00 }, { 0x2C, 0xFF }, { 0x2E, 0xDF }, { 0xFF, 0x01 }, { 0x3C, 0x32 }, { 0x11, 0x00 },
 *                                      { 0x09, 0x02 }, { 0x04, 0x28 }, { 0x13, 0xE5 }, { 0x14, 0x48 }, { 0x2C, 0x0C }, { 0x33, 0x78 }, { 0x3A, 0x33 }, { 0x3B, 0xFB },
 *                                      { 0x3E, 0x00 }, { 0x43, 0x11 }, { 0x16, 0x10 }, { 0x39, 0x92 }, { 0x35, 0xDA }, { 0x22, 0x1A }, { 0x37, 0xC3 }, { 0x23, 0x00 },
 *                                      { 0x34, 0xC0 }, { 0x36, 0x1A }, { 0x06, 0x88 }, { 0x07, 0xC0 }, { 0x0D, 0x87 }, { 0x0E, 0x41 }, { 0x4C, 0x00 }, { 0x48, 0x00 },
 *                                      { 0x5B, 0x00 }, { 0x42, 0x03 }, { 0x4A, 0x81 }, { 0x21, 0x99 }, { 0x24, 0x40 }, { 0x25, 0x38 }, { 0x26, 0x82 }, { 0x5C, 0x00 },
 *                                      { 0x63, 0x00 }, { 0x46, 0x22 }, { 0x0C, 0x3C }, { 0x61, 0x70 }, { 0x62, 0x80 }, { 0x7C, 0x05 }, { 0x20, 0x80 }, { 0x28, 0x30 },
 *                                      { 0x6C, 0x00 }, { 0x6D, 0x80 }, { 0x6E, 0x00 }, { 0x70, 0x02 }, { 0x71, 0x94 }, { 0x73, 0xC1 }, { 0x12, 0x40 }, { 0x17, 0x11 },
 *                                      { 0x18, 0x43 }, { 0x19, 0x00 }, { 0x1A, 0x4B }, { 0x32, 0x09 }, { 0x37, 0xC0 }, { 0x4F, 0xCA }, { 0x50, 0xA8 }, { 0x5A, 0x23 },
 *                                      { 0x6D, 0x00 }, { 0x3D, 0x38 }, { 0xFF, 0x00 }, { 0xE5, 0x7F }, { 0xF9, 0xC0 }, { 0x41, 0x24 }, { 0xE0, 0x14 }, { 0x76, 0xFF },
 *                                      { 0x33, 0xA0 }, { 0x42, 0x20 }, { 0x43, 0x18 }, { 0x4C, 0x00 }, { 0x87, 0xD5 }, { 0x88, 0x3F }, { 0xD7, 0x03 }, { 0xD9, 0x10 },
 *                                      { 0xD3, 0x82 }, { 0xC8, 0x08 }, { 0xC9, 0x80 }, { 0x7C, 0x00 }, { 0x7D, 0x00 }, { 0x7C, 0x03 }, { 0x7D, 0x48 }, { 0x7D, 0x48 },
 *                                      { 0x7C, 0x08 }, { 0x7D, 0x20 }, { 0x7D, 0x10 }, { 0x7D, 0x0E }, { 0x90, 0x00 }, { 0x91, 0x0E }, { 0x91, 0x1A }, { 0x91, 0x31 },
 *                                      { 0x91, 0x5A }, { 0x91, 0x69 }, { 0x91, 0x75 }, { 0x91, 0x7E }, { 0x91, 0x88 }, { 0x91, 0x8F }, { 0x91, 0x96 }, { 0x91, 0xA3 },
 *                                      { 0x91, 0xAF }, { 0x91, 0xC4 }, { 0x91, 0xD7 }, { 0x91, 0xE8 }, { 0x91, 0x20 }, { 0x92, 0x00 }, { 0x93, 0x06 }, { 0x93, 0xE3 },
 *                                      { 0x93, 0x05 }, { 0x93, 0x05 }, { 0x93, 0x00 }, { 0x93, 0x04 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 },
 *                                      { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x96, 0x00 }, { 0x97, 0x08 }, { 0x97, 0x19 }, { 0x97, 0x02 }, { 0x97, 0x0C },
 *                                      { 0x97, 0x24 }, { 0x97, 0x30 }, { 0x97, 0x28 }, { 0x97, 0x26 }, { 0x97, 0x02 }, { 0x97, 0x98 }, { 0x97, 0x80 }, { 0x97, 0x00 },
 *                                      { 0x97, 0x00 }, { 0xC3, 0xED }, { 0xA4, 0x00 }, { 0xA8, 0x00 }, { 0xC5, 0x11 }, { 0xC6, 0x51 }, { 0xBF, 0x80 }, { 0xC7, 0x10 },
 *                                      { 0xB6, 0x66 }, { 0xB8, 0xA5 }, { 0xB7, 0x64 }, { 0xB9, 0x7C }, { 0xB3, 0xAF }, { 0xB4, 0x97 }, { 0xB5, 0xFF }, { 0xB0, 0xC5 },
 *                                      { 0xB1, 0x94 }, { 0xB2, 0x0F }, { 0xC4, 0x5C }, { 0xC0, 0x64 }, { 0xC1, 0x4B }, { 0x8C, 0x00 }, { 0x86, 0x3D }, { 0x50, 0x00 },
 *                                      { 0x51, 0xC8 }, { 0x52, 0x96 }, { 0x53, 0x00 }, { 0x54, 0x00 }, { 0x55, 0x00 }, { 0x5A, 0xC8 }, { 0x5B, 0x96 }, { 0x5C, 0x00 },
 *                                      { 0xD3, 0x82 }, { 0xC3, 0xED }, { 0x7F, 0x00 }, { 0xDA, 0x08 }, { 0xE5, 0x1F }, { 0xE1, 0x67 }, { 0xE0, 0x00 }, { 0xDD, 0x7F },
 *                                      { 0x05, 0x00 }
 *                                 };
 *
 * int32_t    status;
 * const      cnfImgk_t    configure = {
 *                             .oPixMode  = PIX8BITS;
 *                             .oNbRows   = 60;
 *                             .oNbCols   = 60;
 *                         };
 *
 *    status = imgk_configure(&configure);
 *
 * static    void    _myRoutine(void) {
 *
 * }
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_TIMEO	Timeout error
 * \return		KERR_IMGK_NOMEM	Not enough memory
 *
 */
int32_t	imgk_configure(const cnfImgk_t *configure) {
	UNUSED(configure);

	uint32_t	current;
	int32_t		status = KERR_IMGK_NOERR;

	status = local_init();
	if (status != KERR_IMGK_NOERR) { return (status); }

// Set the format

	current = dvp->dvp_cfg & (~DVP_CFG_FORMAT_MASK);
	dvp->dvp_cfg = current | DVP_CFG_RGB_FORMAT;

// Set the size

	current  = dvp->dvp_cfg & ~(DVP_CFG_HREF_BURST_NUM_MASK | DVP_CFG_LINE_NUM_MASK);
	current |= DVP_CFG_LINE_NUM(KIMAGER_NB_ROWS_QVGA);

	current |= ((dvp->dvp_cfg & DVP_CFG_BURST_SIZE_4BEATS) != 0U) ? (DVP_CFG_HREF_BURST_NUM(KIMAGER_NB_COLS_QVGA / 8U / 4U)) : (DVP_CFG_HREF_BURST_NUM(KIMAGER_NB_COLS_QVGA / 8 / 1));
	dvp->dvp_cfg = current;

// Reserve the memory

	if (vImageE0 != NULL) { memo_free(vImageE0); }
	if (vImageE1 != NULL) { memo_free(vImageE1); }

	vPage	  = 1U;
	vImageE0  = (uint16_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KIMAGER_NB_COLS_QVGA * (size_t)KIMAGER_NB_ROWS_QVGA * sizeof(uint16_t)), "imgk");
	vImageE1  = (uint16_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KIMAGER_NB_COLS_QVGA * (size_t)KIMAGER_NB_ROWS_QVGA * sizeof(uint16_t)), "imgk");
	if (vImageE0 == NULL) { status = KERR_IMGK_NOMEM; }
	if (vImageE1 == NULL) { status = KERR_IMGK_NOMEM; }

	dvp->rgb_addr = (uint32_t)((uintptr_t)vImageE0);
	return (status);
}

/*
 * \brief Acquisition of an image
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_acquisition();
 * \endcode
 *
 * \param[in]	-
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_TIMEO	Timeout error
 *
 */
int32_t	imgk_acquisition(void) {
	int32_t		status;

	status = local_init();
	if (status != KERR_IMGK_NOERR) { return (status); }

	kern_signalSemaphore(vSeHandleAQ);
	return (KERR_IMGK_NOERR);
}

/*
 * \brief Get the image pointer
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    *image;
 *
 *    status = imgk_getImage(&image);
 * \endcode
 *
 * \param[out]	**image			Ptr on the image
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 *
 */
int32_t	imgk_getImage(volatile void **image) {
	int32_t		status;

	status = local_init();
	if (status != KERR_IMGK_NOERR) { return (status); }

	if (vPage == 0U) { *image = vImageE0; return (KERR_IMGK_NOERR); }
					 { *image = vImageE1; return (KERR_IMGK_NOERR); }
}

// Local routines
// ==============

/*
 * \brief local_DVP_IRQHandler
 *
 * - Interruption end of acquisition
 *
 */
void	local_DVP_IRQHandler(uint32_t core, uint64_t parameter) {

// End-of-Frame interruption

	if ((dvp->sts & DVP_STS_FRAME_FINISH) != 0U) {
		if (vPage == 0U) { dvp->rgb_addr = (uint32_t)((uintptr_t)vImageE0); vPage = 1U; }
		else             { dvp->rgb_addr = (uint32_t)((uintptr_t)vImageE1); vPage = 0U; }

		kern_signalSemaphore(vSeHandleIM);
		dvp->sts = DVP_STS_FRAME_FINISH | DVP_STS_FRAME_FINISH_WE;
	}

// End-of-Start interruption
// Synchronize the end acquisition with the
// interruption End-of-Start

	if ((dvp->sts & DVP_STS_FRAME_START) != 0U) {
		if (kern_waitSemaphore(vSeHandleAQ, 0U) == KERR_KERN_NOERR) {
			dvp->sts = DVP_STS_DVP_EN | DVP_STS_DVP_EN_WE;
		}
		dvp->sts = DVP_STS_FRAME_START | DVP_STS_FRAME_START_WE;
	}

	plic->targets.target[core].claim_complete = (uint32_t)parameter;
}

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			uint32_t	core, current;
	static	bool		vInit = false;

	INTERRUPTION_OFF;
	if (!vInit) {
		vInit = true;

		if (kern_createMutex(KIMGK_MUTEX_RESERVE, &vMutex)				 != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "imgk: create mutx"); exit(EXIT_OS_PANIC); }
		if (kern_createSemaphore(KIMGK_SEMAPHORE_IM, 0, 1, &vSeHandleIM) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "imgk: create sema"); exit(EXIT_OS_PANIC); }
		if (kern_createSemaphore(KIMGK_SEMAPHORE_AQ, 0, 1, &vSeHandleAQ) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "imgk: create sema"); exit(EXIT_OS_PANIC); }

// Set the priority
// Get current enable bit array by IRQ number
// Set enable bit in enable bit array
// Write back the enable bit array

		core = GET_RUNNING_CORE;
		EXT_INTERRUPT_VECTOR(EINT_DVP_INTERRUPT, local_DVP_IRQHandler);

		plic->source_priorities.priority[EINT_DVP_INTERRUPT] = (uint32_t)KINT_LEVEL_PERIPHERALS;
		current  = plic->target_enables.target[core].enable[(uint32_t)EINT_DVP_INTERRUPT / 32U];
		current |= (uint32_t)(1U<<((uint32_t)EINT_DVP_INTERRUPT % 32U));
		plic->target_enables.target[core].enable[(uint32_t)EINT_DVP_INTERRUPT / 32U] = current;

// Initialise the DVP
// Initialise the clock rate
// Initialise the image

		local_initCKRate(NULL);
		local_initImages(NULL);
		local_initOV2640(NULL);

		dvp->dvp_cfg &= ~DVP_CFG_AUTO_ENABLE;
		dvp->dvp_cfg |= DVP_CFG_START_INT_ENABLE | DVP_CFG_FINISH_INT_ENABLE;
	}
	RETURN_INT_RESTORE(KERR_IMGK_NOERR);
}

/*
 * \brief local_initCKRate
 *
 * - Initialise the clock rate
 *
 */
static	void	local_initCKRate(const cnfImgk_t *configure) {
	UNUSED(configure);

	uint32_t	period;
	uint32_t	current;

// Clock devided by 16, and clock enable

	dvp->cmos_cfg &= ~DVP_CMOS_CLK_DIV_MASK;
	dvp->cmos_cfg |= DVP_CMOS_CLK_DIV(3U) | DVP_CMOS_CLK_ENABLE;

// APB clock / 255

	current  = dvp->sccb_cfg & ~(DVP_SCCB_SCL_LCNT_MASK | DVP_SCCB_SCL_HCNT_MASK);
	current |= DVP_SCCB_SCL_LCNT(255U) | DVP_SCCB_SCL_HCNT(255U);
	dvp->sccb_cfg = current;

// Set the imager clock period
// Clock devided by KFREQUENCY_APB1 / (24000000 * 2.0), and clock enable

	period = (uint32_t)round(KFREQUENCY_APB1 / (24000000 * 2.0)) - 1;
	period = (period > 255U) ? (255U) : (period);

	dvp->cmos_cfg &= ~DVP_CMOS_CLK_DIV_MASK;
	dvp->cmos_cfg |= DVP_CMOS_CLK_DIV(period) | DVP_CMOS_CLK_ENABLE;

// Power-on the cmos imager

	dvp->cmos_cfg |= DVP_CMOS_POWER_DOWN;
	kern_suspendProcess(200U);
	dvp->cmos_cfg &= ~DVP_CMOS_POWER_DOWN;
	kern_suspendProcess(200U);
	dvp->cmos_cfg &= ~DVP_CMOS_RESET;
	kern_suspendProcess(200U);
	dvp->cmos_cfg |= DVP_CMOS_RESET;
	kern_suspendProcess(200U);

// Enable the burst
// Set the output enable

	dvp->dvp_cfg |= DVP_CFG_BURST_SIZE_4BEATS;
	dvp->axi	 &= (~DVP_AXI_GM_MLEN_MASK);
	dvp->axi	 |= DVP_AXI_GM_MLEN_4BYTE;

//	dvp->dvp_cfg |= DVP_CFG_AI_OUTPUT_ENABLE;
	dvp->dvp_cfg |= DVP_CFG_DISPLAY_OUTPUT_ENABLE;
}

/*
 * \brief local_initImages
 *
 * - Initialise the image forrmats
 *
 */
static	void	local_initImages(const cnfImgk_t *configure) {
	UNUSED(configure);

	uint32_t	current;

// Set the format

	current = dvp->dvp_cfg & (~DVP_CFG_FORMAT_MASK);
	dvp->dvp_cfg = current | DVP_CFG_RGB_FORMAT;

// Set the size

	current = dvp->dvp_cfg & ~(DVP_CFG_HREF_BURST_NUM_MASK | DVP_CFG_LINE_NUM_MASK);
	current |= DVP_CFG_LINE_NUM(KIMAGER_NB_ROWS_QVGA);

	current |= ((dvp->dvp_cfg & DVP_CFG_BURST_SIZE_4BEATS) != 0U) ? (DVP_CFG_HREF_BURST_NUM(KIMAGER_NB_COLS_QVGA / 8U / 4U)) : (DVP_CFG_HREF_BURST_NUM(KIMAGER_NB_COLS_QVGA / 8 / 1));
	dvp->dvp_cfg = current;
}

/*
 * \brief local_initOV2640
 *
 * - Initialise the OV2640 (8-bit transfer)
 *
 */
static	void	local_sendData(uint8_t address, uint16_t location, uint8_t data) {
	uint32_t	current;

	current  = dvp->sccb_cfg & ~DVP_SCCB_BYTE_NUM_MASK;
	current |= DVP_SCCB_BYTE_NUM_3;
	dvp->sccb_cfg = current;

	dvp->sccb_ctl = (uint32_t)DVP_SCCB_WRITE_DATA_ENABLE | (uint32_t)DVP_SCCB_DEVICE_ADDRESS(address) | (uint32_t)DVP_SCCB_REG_ADDRESS(location) | (uint32_t)DVP_SCCB_WDATA_BYTE0(data);

// Transfer

	while ((dvp->sts & DVP_STS_SCCB_EN) != 0U) { kern_suspendProcess(1U); }
	dvp->sts = DVP_STS_SCCB_EN | DVP_STS_SCCB_EN_WE;
	while ((dvp->sts & DVP_STS_SCCB_EN) != 0U) { kern_suspendProcess(1U); }
}

static	void	local_initOV2640(const cnfImgk_t *configure) {
	UNUSED(configure);

	uint16_t	i;

	for (i = 0U; i < (uint16_t)KNBCNF; i++) {
		local_sendData(KOV2640A, aOV2640_Cnf[i].oRegNumber, aOV2640_Cnf[i].oValue);
	}
}
