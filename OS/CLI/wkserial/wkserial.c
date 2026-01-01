/*
; wkserial.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		wkserial tool.
;			This tool allows to operate with a communication device.
;
;			Possible actions:
;			wkserial {serialManager} -set {baudrate}
;			wkserial {serialManager} -write {byte}
;			wkserial {serialManager} -read
;
;			Examples:
;			wkserial urt0 -set 115200
;			wkserial urt1 -W 55
;			wkserial cdc0 -read
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

#include	"kern/kern.h"
#include	"macros.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"serial/serial.h"
#include	"serial_common.h"
#include	"text/text.h"
#include	"types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"wkserial     Work with a communication device.         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Operate with a communication device\n"
									"===================================\n\n"

									"This tool allows to operate with a communication device.\n\n"
									"wkserial {serialManager} -S {baudrate}\n"
									"wkserial {serialManager} -W {byte}\n"
									"wkserial {serialManager} -R\n\n"

									"Example\n"
									"   wkserial urt0 -S 460800      Set the urt0 @ 460800-b/s\n"
									"   wkserial urt1 -W 55          Write to the urt11 the byte 0x55\n"
									"   wkserial cdc0 -R             Read a byte from the cdc0\n\n"

									"Possible baudrates:\n"
									"   2400 4800 9600 19200 38400\n"
									"   57600 115200 230400 460800 500000\n"
									"   921600 1000000 1500000 1843200\n"
									"   2000000 2500000 3000000 [bit/s].\n\n"

									"IMPORTANT: All the parameters have to be entered in decimal\n"
									"           except the one used to represent DATA (hex without 0x)\n\n"

									"Input format:  wkserial {serialManager} -S {baudrate}\n"
									"Input format:  wkserial {serialManager} -W {byte}\n"
									"Input format:  wkserial {serialManager} -R\n\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_setBaudRate(serialManager_t serialManager, uint8_t baudRate);
static	void		local_getSerialManager(serialManager_t *serialManager, const char_t *string);

MODULE(
	Wkserial,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_WK_SERIAL,								// Module identifier (defined in the module.h)
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
	bool				equals;
	uint32_t			value = 0U;
	int32_t				status;
	serialManager_t		serialManager = KDEF0;
	uint32_t			baudRate = 460800U,  size;
	enum				{ KERR_NOT, KERR_OKR, KERR_OKW, KERR_OKS, KERR_INA, KERR_BSY, KERR_ORD, KERR_EMP, KERR_GEN } error = KERR_INA;

	(void)dprintf(KSYST, "wkserial operations.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
// Read mode
//  wkserial cdc0 -R
//
// Write mode
//  wkserial urt1 -W 55
//
// Set mode
//  wkserial urt0 -S 460800

	local_getSerialManager(&serialManager, argv[1]);
	if (serial_reserve(serialManager, KMODE_READ_WRITE, 2000U) == KERR_SERIAL_NOERR) {

		switch (argc) {

// Read mode
//  wkserial cdc0 -R

			case 3U: {
				text_checkAsciiBuffer(argv[2], "-R", &equals);
				if (equals) {
					size = 1U;
					status = serial_read(serialManager, (uint8_t *)&value, &size);

					switch (status) {
						case KERR_SERIAL_NOERR: { error = KERR_OKR; break; }
						case KERR_SERIAL_RBUEM: { error = KERR_EMP; break; }
						default:				{ error = KERR_GEN; break; }
					}
				}
				else {
					error = KERR_INA;
				}
				break;
			}

// Write mode
//  wkserial urt1 -W 55

			case 4U: {
				text_checkAsciiBuffer(argv[2], "-W", &equals);
				if (equals) {
					value = (uint32_t)strtol(argv[3], &dummy, 16U);
					size = 1U;
					status = serial_write(serialManager, (uint8_t *)&value, size);

					switch (status) {
						case KERR_SERIAL_NOERR: { error = KERR_OKW; break; }
						default:				{ error = KERR_GEN; break; }
					}
					break;
				}

// Set mode
//  wkserial urt0 -S 460800

				text_checkAsciiBuffer(argv[2], "-S", &equals);
				if (equals) {
					value = (uint32_t)strtol(argv[3], &dummy, 10U);

					switch (value) {
						case 2400U:	   { baudRate = 2400U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_2400);    break; }
						case 4800U:	   { baudRate = 4800U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_4800);    break; }
						case 9600U:	   { baudRate = 9600U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_9600);    break; }
						case 19200U:   { baudRate = 19200U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_19200);   break; }
						case 38400U:   { baudRate = 38400U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_38400);   break; }
						case 57600U:   { baudRate = 57600U;		local_setBaudRate(serialManager, KSERIAL_BAUDRATE_57600);   break; }
						case 115200U:  { baudRate = 115200U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_115200);  break; }
						case 230400U:  { baudRate = 230400U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_230400);  break; }
						case 460800U:  { baudRate = 460800U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_460800);  break; }
						case 500000U:  { baudRate = 500000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_500000);  break; }
						case 921600U:  { baudRate = 921600U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_921600);  break; }
						case 1000000U: { baudRate = 1000000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_1000000); break; }
						case 1500000U: { baudRate = 1500000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_1500000); break; }
						case 1843200U: { baudRate = 1843200U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_1843200); break; }
						case 2000000U: { baudRate = 2000000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_2000000); break; }
						case 2500000U: { baudRate = 2500000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_2500000); break; }
						case 3000000U: { baudRate = 3000000U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_3000000); break; }
						default:	   { baudRate = 460800U;	local_setBaudRate(serialManager, KSERIAL_BAUDRATE_460800);  break; }
					}
					error = KERR_OKS;
				}
				else {
					error = KERR_INA;
				}
				break;
			}
			default: {
				error = KERR_INA;
				break;
			}
		}
	serial_release(serialManager, KMODE_READ_WRITE);
	}
	else {
		error = KERR_BSY;
	}

	switch (error) {
		case KERR_OKW: { (void)dprintf(KSYST, "%s written 0x%02X\n\n", argv[1], (uint8_t)value); status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_OKR: { (void)dprintf(KSYST, "%s read 0x%02X\n\n", argv[1], (uint8_t)value);	 status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_OKS: { (void)dprintf(KSYST, "%s set to %"PRIu32"-b/s\n\n", argv[1], baudRate); status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_EMP: { (void)dprintf(KSYST, "%s receiver is empty\n\n", argv[1]);				 status = EXIT_OS_FAILURE;     break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");						 status = EXIT_OS_FAILURE;     break; }
		case KERR_GEN: { (void)dprintf(KSYST, "%s general problem\n\n", argv[1]);				 status = EXIT_OS_FAILURE;     break; }
		case KERR_BSY: { (void)dprintf(KSYST, "%s busy or not existent\n\n", argv[1]);			 status = EXIT_OS_FAILURE;     break; }
		default:	   {																		 status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_setBaudRate
 *
 * - Set a new baudrate
 *
 */
static	void	local_setBaudRate(serialManager_t serialManager, uint8_t baudRate) {
	urtxCnf_t	configure = {
					.oNBBits   = KSERIAL_NB_BITS_8,
					.oStopBits = KSERIAL_STOPBITS_1,
					.oParity   = KSERIAL_PARITY_NONE,
					.oBaudRate = baudRate,
					.oKernSync = ((uint32_t)1U<<(uint32_t)BSERIAL_SEMAPHORE_RX)
				};

	kern_suspendProcess(500U);
	serial_configure(serialManager, &configure);
}

/*
 * \brief local_getSerialManager
 *
 * - Get the Serial Communication Manager ID
 *
 */
static	void	local_getSerialManager(serialManager_t *serialManager, const char_t *string) {
	uint32_t	mmsb, mlsb, lmsb, llsb;

	mmsb = ((uint32_t)string[0]<<24U) & 0xFF000000U;
	mlsb = ((uint32_t)string[1]<<16U) & 0x00FF0000U;
	lmsb = ((uint32_t)string[2]<<8U)  & 0x0000FF00U;
	llsb = ((uint32_t)string[3]<<0U)  & 0x000000FFU;

	*serialManager = (serialManager_t)(mmsb | mlsb | lmsb | llsb);
}
