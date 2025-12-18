/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Longan_Nano_F103 module.
;
;			!!! This code HAS not to contain static data.
;			!!! It is called before to copy and to initialise
;			!!! the variable into the RAM.
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

#include	"core.h"
#include	"core_reg.h"
#include	"linker.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"modules.h"
#include	"soc_reg.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"init         First hardware initializations.           (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "Init\n"
									"====\n\n"

									"This code places in a quite state the hardware resources.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	Init,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_INIT,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1U<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

bool	vExce_isException[KNB_CORES] = MCSET(false);

typedef	struct	gpio	gpio_t;

struct	gpio {
			uint8_t		oPort;				// Port
			uint8_t		oConfiguration;		// Configuration
			uint8_t		oOutputQuite;		// Output value in a quite state
		};

// Prototypes

static	void	local_GPIO_Configuration(void);
static	void	local_RCU_Configuration(void);
static	void	local_ECLIC_Configuration(void);

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, RTC
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_GPIO_Configuration();				// GPIO Config
	local_RCU_Configuration();				// Clock Config
	local_ECLIC_Configuration();			// ECLIC Config
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_PortConfigure(uint8_t configuration, uint8_t index, uint8_t pos, uint8_t out, volatile uint32_t *ctl, volatile uint32_t *octl) {

	index = index * 4U;

	switch (configuration) {
		case KIN_ANAOG:		{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x0U<<index);																	  break; }
		case KIN_FLOAT:		{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x4U<<index);																	  break; }
		case KIN_PULLD:		{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x8U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos));						  break; }
		case KIN_PULLU:		{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x8U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(0x1U<<pos); break; }
		case KOU_PUSHP_02:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x2U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_02:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x6U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_PUSHP_10:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x1U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_10:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x5U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_PUSHP_50:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x3U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_50:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x7U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_02:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0xAU<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_02:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0xEU<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_10:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0x9U<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_10:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0xDU<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_50:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0xBU<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_50:	{ *ctl = (*ctl & (uint32_t)~(0xFU<<index)) | (0xFU<<index); *octl = (*octl & (uint32_t)~(0x1U<<pos)) | (uint32_t)(out<<pos);  break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

static	void	local_GPIO_Configuration(void) {
		uint8_t		i;
static	const		gpio_t	aGPIO_Cnf[] = {
								{ (uint8_t)PA00, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA01, KOU_PUSHP_02, 1U },			// GPIO output	LED_G
								{ (uint8_t)PA02, KOU_PUSHP_02, 1U },			// GPIO output	LED_B
								{ (uint8_t)PA03, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA04, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA05, KAF_OPEND_50, 0U },			// SPI0_CLK		LCD_SCK
								{ (uint8_t)PA06, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA07, KAF_OPEND_50, 0U },			// SPI0_MOSI	LCD_SDA
								{ (uint8_t)PA08, KAF_PUSHP_50, 0U },			// GPIO output	(clock-out)(
								{ (uint8_t)PA09, KAF_PUSHP_50, 0U },			// USART_TX
								{ (uint8_t)PA10, KIN_PULLD,    0U },			// USART_RX
								{ (uint8_t)PA11, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA12, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PA13, KIN_PULLU,    0U },			// JTAG_TMS
								{ (uint8_t)PA14, KIN_PULLD,    0U },			// JTAG_TCK
								{ (uint8_t)PA15, KIN_PULLU,    0U },			// JTAG_TDI

								{ (uint8_t)PB00, KOU_PUSHP_50, 0U },			// GPIO output	LCD_RS
								{ (uint8_t)PB01, KOU_PUSHP_50, 0U },			// GPIO output	LCD_RST
								{ (uint8_t)PB02, KOU_PUSHP_50, 0U },			// GPIO output	LCD_CS
								{ (uint8_t)PB03, KAF_PUSHP_50, 0U },			// JTAG_TDO
								{ (uint8_t)PB04, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB05, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB06, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB07, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB08, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB09, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB10, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB11, KIN_PULLD,    0U },			// GPIO input
								{ (uint8_t)PB12, KOU_PUSHP_50, 0U },			// SDCARD_CS	SDCARD_CS
								{ (uint8_t)PB13, KAF_PUSHP_50, 0U },			// SPI1_CLK		SDCARD_SCK
								{ (uint8_t)PB14, KIN_PULLD,    0U },			// SPI1_MISO	SDCARD_MISO
								{ (uint8_t)PB15, KAF_PUSHP_50, 0U },			// SPI1_MOSI	SDCARD_MOSI

								{ (uint8_t)PC13, KOU_PUSHP_02, 1U },			// GPIO output	LED_R
								{ (uint8_t)PC14, KIN_FLOAT,    0U },			// 32K quartz
								{ (uint8_t)PC15, KIN_FLOAT,    0U },			// 32K quartz
							};

#define	KNBCNF		(sizeof(aGPIO_Cnf) / sizeof(gpio_t))

	RCU->APB2EN |= RCU_APB2EN_PAEN;				// Turn on the GPIOA
	RCU->APB2EN |= RCU_APB2EN_PBEN;				// Turn on the GPIOB
	RCU->APB2EN |= RCU_APB2EN_PCEN;				// Turn on the GPIOC

	for (i = 0U; i < (uint8_t)KNBCNF; i++) {

// Port A

		if (										 (aGPIO_Cnf[i].oPort <= (uint8_t)PA07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PA00), (aGPIO_Cnf[i].oPort - (uint8_t)PA00), aGPIO_Cnf[i].oOutputQuite, &GPIOA->CTL0, &GPIOA->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PA08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PA15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PA08), (aGPIO_Cnf[i].oPort - (uint8_t)PA00), aGPIO_Cnf[i].oOutputQuite, &GPIOA->CTL1, &GPIOA->OCTL); }

// Port B

		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PB00) && (aGPIO_Cnf[i].oPort <= (uint8_t)PB07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PB00), (aGPIO_Cnf[i].oPort - (uint8_t)PB00), aGPIO_Cnf[i].oOutputQuite, &GPIOB->CTL0, &GPIOB->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PB08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PB15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PB08), (aGPIO_Cnf[i].oPort - (uint8_t)PB00), aGPIO_Cnf[i].oOutputQuite, &GPIOB->CTL1, &GPIOB->OCTL); }

// Port C

		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PC00) && (aGPIO_Cnf[i].oPort <= (uint8_t)PC07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PC00), (aGPIO_Cnf[i].oPort - (uint8_t)PC00), aGPIO_Cnf[i].oOutputQuite, &GPIOC->CTL0, &GPIOC->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PC08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PC15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PC08), (aGPIO_Cnf[i].oPort - (uint8_t)PC00), aGPIO_Cnf[i].oOutputQuite, &GPIOC->CTL1, &GPIOC->OCTL); }
	}
}

/*
 * \brief local_RCU_Configuration
 *
 * - RCU configuration
 * 		For f(ck in) = 8 / 2 = 4-MHz
 * 		CK_SYS  = 108-MHz -> factor = 108 / 4 = 27 (108-MHz to permit the USB 54-MHz clock !!)
 * 		CK AHB  = 108-MHz
 * 		CK APB1 = 54-MHz
 * 		CK APB2 = 54-MHz
 * 		CK USB  = 54-MHz
 *
 */
static	void	local_RCU_Configuration(void) {

// Remap for clock observation (clockout on PA8)

	AFIO->PCF0 = (0x3U<<6U);

// Main PLL CPU

// For f(ck in) = 8 / 2 = 4-MHz
//		CK_SYS  = 108-MHz -> factor = 108 / 4 = 27 (108-MHz to permit the USB 54-MHz clock !!)
//		CK AHB  = 108-MHz
//		CK APB1 = 54-MHz
//		CK APB2 = 54-MHz
//		CK USB  = 54-MHz

	RCU->CFG0 = (0x1U<<29U)									// PLLMF4 for 27 (1 1010)
			  | (0x0U<<28U)									// ADCPSC
			  | (0x4U<<24U)									// CLOCKOUT = CKSYS
			  | (0x3U<<22U)									// 54-MHz = CK_PLL / 2
			  | (0xAU<<18U)									// PLLMF3-0 for 27 (1 1010)
			  | (0x0U<<17U)									// PREDIV0 not used
			  | (0x0U<<16U)									// PLLSEL = IRC8M / 2
			  | (0x0U<<14U)									// ADC clock = CK_APB2 / 2
			  | (0x4U<<11U)									// APB2 = CK_AHB / 2 = 54-MHz
			  | (0x4U<<8U)									// APB1 = CK_AHB / 2 = 54-MHz
			  | (0x0U<<4U)									// AHB  = CK_SYS / 1 = 108-MHz
			  | (0x2U<<0U);									// CK_PLL as the CK_SYS source

	RCU->CTL |= (0x0U<<28U)									// PLL2 off
			  | (0x0U<<26U)									// PLL1 off
			  | (0x1U<<24U)									// PLL on
			  | (0x0U<<19U)									// Clock monitor disable
			  | (0x0U<<18U)									// HXTAL bypassed
			  | (0x0U<<16U);								// RC 8-MHz enable

	RCU->AHBEN |= RCU_AHBEN_USBFSEN;						// USBFS clock enable

	while ((RCU->CTL & RCU_CTL_PLLSTB) == 0U) { }			// Waiting for PLL stable

// Turn on the 40-KHz clock

	RCU->RSTSCK |= RCU_RSTSCK_IRC40KEN;
}

/*
 * \brief local_ECLIC_Configuration
 *
 * - ECLIC configuration
 *
 */
static	void	local_ECLIC_Configuration(void) {
	uint32_t	i;

// Disable the interruptions

	core_clrBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE);
	core_clrBitCSR(RVBB_CSR_MMISC_CTL, (1U<<9U));

// Configure the ECLIC
// Initialise the ECLIC

	core_putCSR(RV_CSR_MTVEC, (uint32_t)linker_stVECTORS | (uint32_t)0x3U);
	core_putCSR(RVBB_CSR_MTVT, (uint32_t)linker_stVECTORS);

	for (i = 0U; i < KNB_INTERRUPTIONS; i++) {
		ECLIC->CLICINT[i].IE = 0U;
		ECLIC->CLICINT[i].IP = 0U;
	}
	ECLIC->MTH = KINT_IMASK_ALL;

// nlbit = 3 (LEVEL3) -> LLL1 1111 (set by default at the start-up)
//
// LLLH HHHH means that the possible interruption level should be:
//
// 000H HHHH	31
// 001H HHHH	63
// 010H HHHH	95
// 011H HHHH	127
// 100H HHHH	159
// 101H HHHH	191
// 110H HHHH	223
// 111H HHHH	255

	ECLIC->CLICCFG = (uint8_t)((ECLIC->CLICCFG & ~ECLIC_CFG_NLBITS_MASK) | ECLIC_GROUP_LEVEL3_PRIO1);
}
