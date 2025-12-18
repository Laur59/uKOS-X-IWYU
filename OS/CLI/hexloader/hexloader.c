/*
; hexloader.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Intel hex+ loader.
;			This tool allows to download a Intel hex+ format binary
;			to the memory and to execute it.
;			Here are the Intel hex+ format definitions:
;
;			- Everything is represented in ASCII.
;
;			- Block format:
;				Mark:					1 char
;				Length of the block:	an hex. number of 2 chars.
;				Address:				an hex. number of 4 chars.
;				Block type:				2 chars.
;				Data:					an hex. 2n chars.
;				Checksum:				an hex. number of 2 chars.
;
;			- Mark:
;				":"
;			- Block type:
;				"00" normal data record
;				"01" end of file record
;				"02" not supported
;				"03" not supported
;				"04" extended linear address (for 32-bit CPU)
;				"05" execution address
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

#include	<stdint.h>
#include	<stdio.h>
#include	<string.h>

#include	"kern/kern.h"
#include	"led/led.h"
#include	"linker.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"serial/serial.h"
#include	"system/system.h"
#include	"text/text.h"
#include	"types.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"hexloader    Intel hex+ (32-bit) loader.               (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "Intel hex+ (32-bit) loader\n"
									"==========================\n\n"

									"This tool downloads an executable code\n"
									"in a Intel hex+ format (32-bit address range).\n"
									"The arguments of the downloded application (module_name)\n"
									"can be passed via the hexloader; e.g:\n"
									"hexloader module_name p1 p2 pn.\n\n"

									"Input format:  hexloader [module_name p1 p2 pn][-run | -norun]\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		local_getCounter(uint8_t *counter, uint8_t *checksum);
static	int32_t		local_getType(uint8_t *type, uint8_t *checksum);
static	int32_t		local_getOffset(uintptr_t *offset, uint8_t *checksum);
static	int32_t		local_getExecAddress(uint8_t **address, uint8_t *checksum);
static	int32_t		local_getData(const uint8_t *counter, uint8_t *checksum, uint8_t *address);
static	int32_t		local_getHexValue(uint8_t *value);
static	int32_t		local_getByte(uint8_t *byte);
static	bool		local_checkSignature(void);

MODULE(
	Hexloader,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_HEX_LOADER,							// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1U<<BSHOW) | (1U<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_CHAR_BLINK	20U

enum {
		KERR_H_LOADER_NOT = 0U,
		KERR_H_LOADER_CHK,
		KERR_H_LOADER_BFU,
		KERR_H_LOADER_NOI,
		KERR_H_LOADER_FRA,
		KERR_H_LOADER_PAR
};

enum {
		KRUN = 0U,
		KRUN_NO
};

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint8_t			*address = NULL, byte, hexValue, type = 0U, checksum, counter;
	int32_t			status, error = KERR_H_LOADER_NOT, (*code)(uint32_t argc, const char_t *argv[]);
	uintptr_t		offset = 0U, page = 0U;
	bool			terminate = false, equals;
	uint8_t			run = KRUN;
	uKOS_header_t	ramHeader;

	(void)dprintf(KSYST, "Hex format Intel loader mode; waiting for the code.\n");

// Verify if the user memory is available
// --------------------------------------

	if (system_reserve(KMODE_READ_WRITE, 0U) != KERR_SYSTEM_NOERR) {
		(void)dprintf(KSYST, "\nHex: The user memory is busy.\n\n");
		return (EXIT_OS_FAILURE);
	}

	serial_reserve(KSYST, KMODE_READ, KWAIT_INFINITY);

// Analyse the command line
// ------------------------
//
// Example:
//
// hexloader
// hexloader -run
// hexloader -norun
// hexloader p0 p1 p2 ... px

	switch (argc) {
		case 2U: {
			text_checkAsciiBuffer(argv[1], "-norun", &equals); if (equals) { run = KRUN_NO;	}
			text_checkAsciiBuffer(argv[1], "-run",   &equals); if (equals) { run = KRUN;	}
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	while (!terminate) {

// Waiting for the mark ":"

		do { local_getByte(&byte); } while (byte != ':');

		error = local_getCounter(&counter, &checksum);
		if (error == KERR_H_LOADER_NOT) {
			error = local_getOffset(&offset, &checksum);
			if (error == KERR_H_LOADER_NOT) {
				error = local_getType(&type, &checksum);
				if (error == KERR_H_LOADER_NOT) {
					switch (type) {
						case 0U: {
							address = (uint8_t *)(page + offset);
							error = local_getData(&counter, &checksum, address); if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							error = local_getHexValue(&hexValue);				 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							if (hexValue != (uint8_t)(~checksum) + 1U)        	   { error  = KERR_H_LOADER_CHK;   terminate = true; break; }
							break;
						}
						case 1U: {
							error = local_getHexValue(&hexValue);				 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							if (hexValue != (uint8_t)(~checksum) + 1U)			   { error  = KERR_H_LOADER_CHK;   terminate = true; break; }
							terminate = true;
							break;
						}
						case 4U: {
							error = local_getOffset(&page, &checksum);			 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							page <<= 16U;
							if (page == 0U) { page = (uintptr_t)linker_stUMemo; }
							error = local_getHexValue(&hexValue);				 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							if (hexValue != (uint8_t)(~checksum) + 1U)			   { error  = KERR_H_LOADER_CHK;   terminate = true; break; }
							break;
						}
						case 5U: {
							error = local_getExecAddress(&address, &checksum);	 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							error = local_getHexValue(&hexValue);				 if (error != KERR_H_LOADER_NOT) { terminate = true; break; }
							if (hexValue != (uint8_t)(~checksum) + 1U)			   { error  = KERR_H_LOADER_CHK;   terminate = true; break; }
							break;
						}
						default: {

// Make	MISRA happy :-)

							break;
						}
					}
				}
				else {
					terminate = true;
				}
			}
			else {
				terminate = true;
			}
		}
		else {
			terminate = true;
		}
	}

// Terminated
// Waiting a bit to be sure that the flush
// operates when all the chars are received

	led_off(KLED_1);
	kern_suspendProcess(500U);
	serial_flush(KSYST);

	serial_release(KSYST, KMODE_READ);

	switch (error) {
		case KERR_H_LOADER_NOT: {
			(void)dprintf(KSYST, "\nHex: download terminated.\n\n");
			system_setDownloadCodeAddress(address);
			system_getDownloadCodeAddress((void **)&code);
			if (run == KRUN) {

// Invalidate the header to prevent another execution, like after the reset
// if the automatic execution from a debugger is installed.

				if (local_checkSignature()) {
					ramHeader.oMemLocation	  = KNO_MEM;
					ramHeader.oStart		  = NULL;
					ramHeader.oLnApplication  = 0U;
					ramHeader.oModule		  = NULL;
					memcpy((void *)linker_stUMemo, (const void *)&ramHeader, sizeof(ramHeader));
					return ((*code)(argc, argv));
				}

				(void)dprintf(KSYST, "\nHex: failed to find the application signature!\n");
				status = EXIT_OS_FAILURE;
				break;
			}
			status = EXIT_OS_SUCCESS_CLI;
			break;
		}
		case KERR_H_LOADER_CHK: { (void)dprintf(KSYST, "\nHex: wrong checksum.\n\n");	 status = EXIT_OS_FAILURE;	   break; }
		case KERR_H_LOADER_BFU: { (void)dprintf(KSYST, "\nHex: buffer full error.\n\n"); status = EXIT_OS_FAILURE;	   break; }
		case KERR_H_LOADER_NOI: { (void)dprintf(KSYST, "\nHex: noise error.\n\n");		 status = EXIT_OS_FAILURE;	   break; }
		case KERR_H_LOADER_FRA: { (void)dprintf(KSYST, "\nHex: framing error.\n\n");	 status = EXIT_OS_FAILURE;	   break; }
		case KERR_H_LOADER_PAR: { (void)dprintf(KSYST, "\nHex: parity error.\n\n");		 status = EXIT_OS_FAILURE;	   break; }
		default:				{														 status = EXIT_OS_FAILURE;	   break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_getByte
 *
 * - Read a Byte
 * - Try to read a burst of KSZ_BUFFER Bytes
 *
 */
static	int32_t	local_getByte(uint8_t *byte) {
	#define	KSZ_BUFFER	32U
			uint32_t	core;
	static	uint8_t		vBuffer[KNB_CORES][KSZ_BUFFER], vCptBlinkLED[KNB_CORES] = MCSET(0U);
	static	uint32_t	vI[KNB_CORES] = MCSET(0U), vSize[KNB_CORES] = MCSET(0U);

	core = GET_RUNNING_CORE;
	*byte = 0U;

	if (vSize[core] == 0U) {
		vI[core] = 0U;
		do {
			kern_switchFast();
			vSize[core] = KSZ_BUFFER;

			switch (serial_read(KSYST, &vBuffer[core][0], &vSize[core])) {
				case KERR_SERIAL_RBFUL: { return (KERR_H_LOADER_BFU); }
				case KERR_SERIAL_ERNOI: { return (KERR_H_LOADER_NOI); }
				case KERR_SERIAL_ERFRA: { return (KERR_H_LOADER_FRA); }
				case KERR_SERIAL_ERPAR: { return (KERR_H_LOADER_PAR); }
				default: {

// Make MISRA happy :-)

					break;
				}
			}
		} while (vSize[core] == 0U);
	}

	if (vCptBlinkLED[core]++ >= KNB_CHAR_BLINK) {
		vCptBlinkLED[core] = 0U;
		led_toggle(KLED_1);
	}
	vSize[core]--;
	*byte = vBuffer[core][vI[core]];
	vI[core]++;
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getHexValue
 *
 * - Read a hexa value (2 chars)
 * - Ex. 31 is read as '3' (0x33) and '1' (0x31) 2-bytes
 *
 */
static	int32_t	local_getHexValue(uint8_t *value) {
					uint8_t		byte;
					int32_t		status;
	static	const	uint8_t		aTabAB[] = {
									0U,   1U,  2U,  3U,		// '0' '1' '2' '3'
									4U,   5U,  6U,  7U,		// '4' '5' '6' '7'
									8U,   9U,  0U,  0U,		// '8' '9' ':' ';'
									0U,   0U,  0U,  0U,		// '<' '=' '>' '?'
									0U,  10U, 11U, 12U,		// '@' 'A' 'B' 'C'
								   13U,  14U, 15U			// 'D' 'E' 'F'
								};

	*value = 0U;
	status = local_getByte(&byte);
	if (status != KERR_H_LOADER_NOT) {
		return (status);
	}

	if       ((byte >= '0') && (byte <= '9'))									   { *value  = (uint8_t)(aTabAB[byte - (uint8_t)'0']<<4U);						 }
	else if (((byte >= 'A') && (byte <= 'F')) || ((byte >= 'a') && (byte <= 'f'))) { *value  = (uint8_t)(aTabAB[(byte & (uint8_t)(~0x20U)) - (uint8_t)'0']<<4U); }
	else { }

	status = local_getByte(&byte);  if (status != KERR_H_LOADER_NOT) { return (status); }
	if       ((byte >= '0') && (byte <= '9'))									   { *value += (uint8_t)(aTabAB[byte - (uint8_t)'0']);							 }
	else if (((byte >= 'A') && (byte <= 'F')) || ((byte >= 'a') && (byte <= 'f'))) { *value += (uint8_t)(aTabAB[(byte & (uint8_t)(~0x20U)) - (uint8_t)'0']);	 }
	else { }

	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getCounter
 *
 * - Read the counter field
 *
 */
static	int32_t	local_getCounter(uint8_t *counter, uint8_t *checksum) {
	int32_t		status;

	status = local_getHexValue(counter);
	if (status != KERR_H_LOADER_NOT) {
		return (status);
	}

	*checksum = *counter;
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getOffset
 *
 * - Read the offset field
 *
 */
static	int32_t	local_getOffset(uintptr_t *offset, uint8_t *checksum) {
	uint8_t		i, hexValue;
	int32_t		status;

// Build the offset 16-bit wide

	*offset = 0U;
	for (i = 0U; i < 2U; i++) {
		status = local_getHexValue(&hexValue);
		if (status != KERR_H_LOADER_NOT) {
			return (status);
		}

		*offset = (*offset<<8U) + (uint32_t)hexValue;
		*checksum = (uint8_t)(*checksum + hexValue);
	}
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getExecAddress
 *
 * - Read the execution address field
 *
 */
static	int32_t	local_getExecAddress(uint8_t **address, uint8_t *checksum) {
	uint8_t		i, hexValue;
	int32_t		status;
	uintptr_t	field = 0U;

// Build the address 32-bit wide

	for (i = 0U; i < 4U; i++) {
		status = local_getHexValue(&hexValue);
		if (status != KERR_H_LOADER_NOT) {
			return (status);
		}

		field = (field<<8U) + (uintptr_t)hexValue;
		*checksum = (uint8_t)(*checksum + hexValue);
	}
	*address = (uint8_t *)field;
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getType
 *
 * - Read the type field
 *
 */
static	int32_t	local_getType(uint8_t *type, uint8_t *checksum) {
	int32_t		status;

	status = local_getHexValue(type);
	if (status != KERR_H_LOADER_NOT) {
		return (status);
	}

	*checksum += *type;
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_getData
 *
 * - Read the data field
 *
 */
static	int32_t	local_getData(const uint8_t *counter, uint8_t *checksum, uint8_t *address) {
	uint8_t		i, hexValue, *load;
	int32_t		status;

	load = address;
	for (i = 0U; i < (*counter); i++) {
		status = local_getHexValue(&hexValue);
		if (status != KERR_H_LOADER_NOT) {
			return (status);
		}

		*load = hexValue;
		load++;
		*checksum = (uint8_t)(*checksum + hexValue);
	}
	return (KERR_H_LOADER_NOT);
}

/*
 * \brief local_checkSignature
 *
 * Search for the signature string, which should also be within the loaded application.
 * If the application has the same signature, launching it may be dangerous, as the
 * function entry-points will no longer be matching.
 *
 */
static	bool	local_checkSignature(void) {
			size_t		ln, i = 0U;
	const	uint8_t		*ptr = (uint8_t *)linker_stUMemo;
	const	char_t		*signature;

	system_getSystemSignature(&signature);

	for (ln = (size_t)linker_lnUMemo; ln > 0U; --ln ) {
		if (*ptr == signature[i]) {
			i++;
			if (*ptr == 0U) {
				return (true);
			}

		}
		else {
			i = 0U;
		}
		ptr++;
	}
	return (false);
}
