/*
; wkspi.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		wkspi tool.
;			This tool allows to operate with an spi device.
;			For the moment this tool reserved for STM CPU32 SoCs!!
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
#include	<stdio.h>
#include	<stdlib.h>

#include	"macros.h"
#include	"macros_core.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"serial/serial.h"
#include	"soc_reg.h"
#include	"spi_common.h"
#include	"spi/spi.h"
#include	"text/text.h"
#include	"types.h"

#ifdef REG
#define	device		REG

#else
#define	device(x)	(x)
#endif

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"wkspi        Communicate with the spi x device.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Read/write on the spi x device (valid only for STM32 SoCs)\n"
									"==========================================================\n\n"

									"This tool allows to read/write data on the spi x device.\n"
									"wkspi {device} -csl port pin\n"
									"wkspi {device} -csh port pin\n"
									"wkspi {device} -set POL PHA Speed(Hz)\n"
									"wkspi {device} DATA\n\n"

									"Example\n"
									"   wkspi 0 -csl A 14            CS low, port A pin 14\n"
									"   wkspi 0 0xA6                 write/read\n"
									"   wkspi 0 0x26                 write/read\n"
									"   wkspi 0 0x00                 write/read\n"
									"   wkspi 0 -csh A 14            CS high, port A pin 14\n"
									"   wkspi 0 -S 1 0 5000000       spi 0 set, POL = 1, PHA = 0, Speed = 5-MHz\n\n"

									"IMPORTANT: All the parameters have to be entered in decimal\n"
									"           except the one used to represent DATA (hex without ox)\n\n"

									"Input format:  wkspi {device} {-csl..-csh}\n"
									"Input format:  wkspi {device} -S POL PHA Speed\n"
									"Input format:  wkspi {device} value\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Wkspi,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_WK_SPI,								// Module identifier (defined in the module.h)
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
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
				char_t			*dummy;
				int32_t			status;
				bool			equals;
				uint8_t			m, unit = 0U, valueW = 0U, valueR = 0U, pin = 0U, pol = 0U, pha = 0U;
				spiManager_t	spiManager;
				uint32_t		speed = 0U;
				enum			{ KCS_LOW, KCS_HIGH } mode = KCS_LOW;
				enum			{ KERR_NOT, KERR_OKX, KERR_OCS, KERR_SET, KERR_BSY, KERR_INA, KERR_GEN } error = KERR_INA;
	volatile	uint32_t		*port = NULL;
	static		spiCnf_t		configure = {
									.oSpeed    = 5000000U,
									.oMode     = (uint8_t)KSPI_MASTER,
									.oClock    = (1U<<(uint8_t)BSPI_POL) | (1U<<(uint8_t)BSPI_PHA)
								};

	(void)dprintf(KSYST, "wkspi operations.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
// Xfer mode
//  wkspi 1 32
//
// CS mode
//  wkspi 3 -csl A 12
//  wkspi 3 -csh A 12
//
// Set mode
//  wkspi 0 -set POL PHA Speed

	unit = (uint8_t)strtol(argv[1], &dummy, 10U);
	switch (unit) {
		default:
		case 0U: { spiManager = KSPI0; break; }
		case 1U: { spiManager = KSPI1; break; }
		case 2U: { spiManager = KSPI2; break; }
		case 3U: { spiManager = KSPI3; break; }
	}

	if (spi_reserve(spiManager, KMODE_READ_WRITE, 2000U) == KERR_SPI_NOERR) {
		spi_configure(spiManager, &configure);

		switch (argc) {

// Xfer mode
//  wkspi 1 32

			case 3U: {
				valueW = (uint8_t)strtol(argv[2], &dummy, 16U);
				valueR = valueW;
				status = spi_writeRead(spiManager, &valueR);

				switch (status) {
					case KERR_SPI_NOERR: { error = KERR_OKX; break; }
					default:			 { error = KERR_GEN; break; }
				}
				break;
			}

// CS mode
//  wkspi 3 -csl A 12
//  wkspi 3 -csh A 12

			case 5U: {
				text_checkAsciiBuffer(argv[2], "-csl", &equals); if (equals) { mode = KCS_LOW;  }
				text_checkAsciiBuffer(argv[2], "-csh", &equals); if (equals) { mode = KCS_HIGH; }

				#if (defined(GPIOA) || defined(GPIOA_S) || defined(GPIOA_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "A", &equals); if (equals) { port = &REG(GPIOA)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "A", &equals); if (equals) { port = &GPIOA->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOB) || defined(GPIOB_S) || defined(GPIOB_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "B", &equals); if (equals) { port = &REG(GPIOB)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "B", &equals); if (equals) { port = &GPIOB->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOC) || defined(GPIOC_S) || defined(GPIOC_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "C", &equals); if (equals) { port = &REG(GPIOC)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "C", &equals); if (equals) { port = &GPIOC->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOD) || defined(GPIOD_S) || defined(GPIOD_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "D", &equals); if (equals) { port = &REG(GPIOD)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "D", &equals); if (equals) { port = &GPIOD->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOE) || defined(GPIOE_S) || defined(GPIOE_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "E", &equals); if (equals) { port = &REG(GPIOE)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "E", &equals); if (equals) { port = &GPIOE->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOF) || defined(GPIOF_S) || defined(GPIOF_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "F", &equals); if (equals) { port = &REG(GPIOF)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "F", &equals); if (equals) { port = &GPIOF->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOG) || defined(GPIOG_S) || defined(GPIOG_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "G", &equals); if (equals) { port = &REG(GPIOG)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "G", &equals); if (equals) { port = &GPIOG->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOH) || defined(GPIOH_S) || defined(GPIOH_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "H", &equals); if (equals) { port = &REG(GPIOH)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "H", &equals); if (equals) { port = &GPIOH->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOI) || defined(GPIOI_S) || defined(GPIOI_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "I", &equals); if (equals) { port = &REG(GPIOI)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "I", &equals); if (equals) { port = &GPIOI->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOJ) || defined(GPIOJ_S) || defined(GPIOJ_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "J", &equals); if (equals) { port = &REG(GPIOJ)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "J", &equals); if (equals) { port = &GPIOJ->ODR;		 }
				#endif
				#endif

				#if (defined(GPIOK) || defined(GPIOK_S) || defined(GPIOK_NS))
				#ifdef REG
				text_checkAsciiBuffer(argv[3], "K", &equals); if (equals) { port = &REG(GPIOK)->ODR; }

				#else
				text_checkAsciiBuffer(argv[3], "K", &equals); if (equals) { port = &GPIOK->ODR;		 }
				#endif
				#endif

				m = (uint8_t)mode;
				if ((port != NULL) && ((m == (uint8_t)KCS_LOW) || (m == (uint8_t)KCS_HIGH))) {

					PRIVILEGE_ELEVATE;
					pin = (uint8_t)strtol(argv[4], &dummy, 10U);
					if (mode == KCS_HIGH) { *port |=			(1U<<(pin & 0xFU)); }
					if (mode == KCS_LOW)  { *port &= (uint32_t)~(1U<<(pin & 0xFU)); }
					PRIVILEGE_RESTORE;

					error = KERR_OCS;
				}
				else {
					error = KERR_INA;
				}
				break;
			}

// Set mode
//  wkspi 0 -S POL PHA Speed

			case 6U: {
				text_checkAsciiBuffer(argv[2], "-S", &equals);
				if (equals) {
					pol	  = (uint8_t) strtol(argv[3], &dummy, 10U);
					pha	  = (uint8_t) strtol(argv[4], &dummy, 10U);
					speed = (uint32_t)strtol(argv[5], &dummy, 10U);

					pol = pol & 0x1U; pha = pha & 0x1U;
					configure.oClock = 0;

					if (pol == 1U) { configure.oClock |= (1U<<(uint8_t)BSPI_POL); }
					if (pha == 1U) { configure.oClock |= (1U<<(uint8_t)BSPI_PHA); }

					configure.oSpeed = speed;
					spi_configure(spiManager, &configure);
					error = KERR_SET;
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
	spi_release(spiManager, KMODE_READ_WRITE);
	}
	else {
		error = KERR_BSY;
	}

	switch (error) {
		case KERR_OKX: { (void)dprintf(KSYST, "spi%d written 0x%02X read 0x%02X\n\n", unit, valueW, valueR);									  status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_SET: { (void)dprintf(KSYST, "spi%d configured with Pol %d, Pha %d speed %"PRIi32"-Hz\n\n", unit, pol, pha, speed);			  status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_OCS: { (void)dprintf(KSYST, "spi%d CS set to %d on the pin %d of the port %s\n\n", unit, ((uint8_t)mode & 0x1U), pin, argv[3]); status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");																		  status = EXIT_OS_FAILURE;     break; }
		case KERR_GEN: { (void)dprintf(KSYST, "spi%d general problem.\n\n", unit);																  status = EXIT_OS_FAILURE;     break; }
		case KERR_BSY: { (void)dprintf(KSYST, "spi%d busy\n\n", unit);																			  status = EXIT_OS_FAILURE;     break; }
		default:	   {																														  status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}
