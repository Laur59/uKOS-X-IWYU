/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X MAiXDUiNO_K210 module.
;
;			!!! This code HAS not to contain static data.
;			!!! It is called before to copy and to initialise
;			!!! the variable into the RAM.
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

#include	"board.h"
#include	"macros.h"
#include	"macros_core.h"
#include	"macros_soc.h"
#include	"modules.h"
#include	"soc_reg.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"init         First hardware initializations.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Init\n"
									"====\n\n"

									"This code places in a quite state the hardware resources.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

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

typedef	struct	mainGpio	mainGpio_t;

struct	mainGpio {
			uint32_t	IOxx    : 8;		// IO number (IO00 .. IO47)
			uint32_t	ch_sel  : 8;		// Channel select from 256 input
			uint32_t	ds      : 4;		// Driving selector
			uint32_t	oe_en   : 1;		// Static output enable, will AND with OE_INV
			uint32_t	oe_inv  : 1;		// Invert output enable
			uint32_t	do_sel  : 1;		// Data output select: 0 for DO, 1 for OE
			uint32_t	do_inv  : 1;		// Invert the result of data output select (DO_SEL)
			uint32_t	pu      : 1;		// Pull up enable. 0 for nothing, 1 for pull up
			uint32_t	pd      : 1;		// Pull down enable. 0 for nothing, 1 for pull down
			uint32_t	resv0   : 1;		// Reserved bits
			uint32_t	sl      : 1;		// Slew rate control enable
			uint32_t	ie_en   : 1;		// Static input enable, will AND with IE_INV
			uint32_t	ie_inv  : 1;		// Invert input enable
			uint32_t	di_inv  : 1;		// Invert Data input
			uint32_t	st      : 1;		// Schmitt trigger
			uint32_t	tie_en  : 1;		// Input tie enable, 1 for enable, 0 for disable
			uint32_t	tie_val : 1;		// Input tie value, 1 for high, 0 for low
			uint32_t	resv1   : 5;		// Reserved bits
			uint32_t	pad_di  : 1;		// Read current PAD's data input
		};

extern	void	(*vExce_intIntVectors[KNB_CORES][KNB_INT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vExce_intExcVectors[KNB_CORES][KNB_INT_EXCEPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vExce_extIntVectors[KNB_CORES][KNB_EXT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vMsgs_process[KNB_CORES])(uint32_t core, uint64_t message);

// Runtime specific
// ================

// Prototypes

static	void	local_GPIO_Configuration(void);
static	void	local_RCU_Configuration(void);
static	void	local_wait_100n(uint32_t n);
extern	void	first_handle_MachineExternal(uint32_t core, uint64_t parameter);
extern	void	first_handle_EnvironmentalCallM(uint32_t core, uint64_t parameter);
extern	void	first_handle_trap(void);

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, SDRAM
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_GPIO_Configuration();				// GPIO Config
	local_RCU_Configuration();				// Clock Config
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {
			uint16_t		i;
			uint32_t		ioxx;
			fpioa_tie_t		tie = { 0 };
	static	const			mainGpio_t	aGPIO_Cnf[] = {

//			  .IOxx  .ch_sel,				.ds,              .oe_en, .oe_inv, .do_sel, .do_inv, .pu, .pd, .resv1, .sl, .ie_en, .ie_inv, .di_inv, .st, .tie_en, .tie_val, .resv0, .pad_di

			{ 0U,     FUNC_JTAG_TCLK,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 1U,     FUNC_JTAG_TDI,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 2U,     FUNC_JTAG_TMS,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 3U,     FUNC_JTAG_TDO,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 4U,     FUNC_UART2_RX,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 5U,     FUNC_UART2_TX,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },

			{ 6U,     FUNC_UART3_RX,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 7U,     FUNC_UART3_TX,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 8U,     FUNC_GPIOHS0,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 9U,     FUNC_GPIOHS1,			FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 10U,    FUNC_UART1_RX,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 11U,    FUNC_UART1_TX,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },

			{ 12U,    FUNC_GPIOHS8,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 13U,    FUNC_GPIOHS9,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 14U,    FUNC_GPIOHS10,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 15U,    FUNC_GPIOHS5,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 16U,    FUNC_GPIOHS6,			FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 17U,    FUNC_GPIOHS7,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },

			{ 36U,    FUNC_SPI0_SS3,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 37U,    FUNC_GPIOHS3,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 38U,    FUNC_GPIOHS2,			FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 39U,    FUNC_SPI0_SCLK,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },

			{ 40U,    FUNC_SCCB_SDA,		FPIOA_DRIVING_0,  1U,      1U,       0U,       0U,       1U,   0U,   0U,      1U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 41U,    FUNC_SCCB_SCLK,		FPIOA_DRIVING_0,  1U,      1U,       0U,       0U,       1U,   0U,   0U,      1U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 42U,    FUNC_CMOS_RST,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 43U,    FUNC_CMOS_VSYNC,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 44U,    FUNC_CMOS_PWDN,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 45U,    FUNC_CMOS_HREF,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U },
			{ 46U,    FUNC_CMOS_XCLK,		FPIOA_DRIVING_15, 1U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    0U,     0U,       0U,       0U,   0U,       0U,        0U,      0U },
			{ 47U,    FUNC_CMOS_PCLK,		FPIOA_DRIVING_0,  0U,      0U,       0U,       0U,       0U,   0U,   0U,      0U,    1U,     0U,       0U,       1U,   0U,       0U,        0U,      0U }
		};

#define	KNBCNF		(sizeof(aGPIO_Cnf)/sizeof(mainGpio_t))

	sysctl->clk_en_cent.apb0_clk_en  = 1U;			// Turn on APB0
	sysctl->clk_en_peri.fpioa_clk_en = 1U;			// Turn on the FPIOA
	local_wait_100n(1U);							//

	sysctl->misc.spi_dvp_data_enable = 1U;			//
	sysctl->clk_en_peri.dvp_clk_en	 = 1U;			// Enable the spi0-dvp
	local_wait_100n(1U);							//

	sysctl->peri_reset.dvp_reset = 1U;				//
	local_wait_100n(100U);							//
	sysctl->peri_reset.dvp_reset = 0U;				// Reset the dvp
	local_wait_100n(100U);							//

// Initialise tie
// Set tie enable and tie value
// 1 seems necessary only for SPIs

	for (i = 0; i < (uint16_t)FUNC_MAX; i++) {
		tie.en[i  / 32U] = 0U;
		tie.val[i / 32U] = 0U;
	}

	tie.en[(uint32_t)FUNC_SPI0_ARB  / 32U] |= (uint32_t)1U<<((uint32_t)FUNC_SPI0_ARB % 32U);
	tie.val[(uint32_t)FUNC_SPI0_ARB / 32U] |= (uint32_t)1U<<((uint32_t)FUNC_SPI0_ARB % 32U);
	tie.en[(uint32_t)FUNC_SPI1_ARB  / 32U] |= (uint32_t)1U<<((uint32_t)FUNC_SPI1_ARB % 32U);
	tie.val[(uint32_t)FUNC_SPI1_ARB / 32U] |= (uint32_t)1U<<((uint32_t)FUNC_SPI1_ARB % 32U);

// Atomic write every 32-bit register to fpioa function

	for (i = 0U; i < (uint16_t)((uint32_t)FUNC_MAX / 32U); i++) {
		fpioa->tie.val[i] = tie.val[i];
		fpioa->tie.en[i]  = tie.en[i];
	}

// Initialise the GPIO
// First, for all the PAD attribute the FUNC_RESV0 function
// Then, scann the table to customize the PADs

	for (i = 0U; i < FPIOA_NUM_IO; i++) {
		fpioa->io[i].ch_sel = FUNC_RESV0;
		fpioa->io[i].ds     = 0U;
		fpioa->io[i].oe_en  = 0U;
		fpioa->io[i].oe_inv = 0U;
		fpioa->io[i].do_sel = 0U;
		fpioa->io[i].do_inv = 0U;
		fpioa->io[i].pu     = 0U;
		fpioa->io[i].pd     = 0U;
		fpioa->io[i].sl     = 0U;
		fpioa->io[i].ie_en  = 0U;
		fpioa->io[i].ie_inv = 0U;
		fpioa->io[i].di_inv = 0U;
		fpioa->io[i].st     = 0U;
	}

	for (i = 0U; i < (uint16_t)KNBCNF; i++) {
		ioxx = aGPIO_Cnf[i].IOxx;

		fpioa->io[ioxx].ch_sel = aGPIO_Cnf[i].ch_sel;
		fpioa->io[ioxx].ds     = aGPIO_Cnf[i].ds;
		fpioa->io[ioxx].oe_en  = aGPIO_Cnf[i].oe_en;
		fpioa->io[ioxx].oe_inv = aGPIO_Cnf[i].oe_inv;
		fpioa->io[ioxx].do_sel = aGPIO_Cnf[i].do_sel;
		fpioa->io[ioxx].do_inv = aGPIO_Cnf[i].do_inv;
		fpioa->io[ioxx].pu     = aGPIO_Cnf[i].pu;
		fpioa->io[ioxx].pd     = aGPIO_Cnf[i].pd;
		fpioa->io[ioxx].sl     = aGPIO_Cnf[i].sl;
		fpioa->io[ioxx].ie_en  = aGPIO_Cnf[i].ie_en;
		fpioa->io[ioxx].ie_inv = aGPIO_Cnf[i].ie_inv;
		fpioa->io[ioxx].di_inv = aGPIO_Cnf[i].di_inv;
		fpioa->io[ioxx].st     = aGPIO_Cnf[i].st;
	}

// Port 6 & 7 & 1.8-V (dvp & spi)
// SYSCTL_POWER_V18 = 1, SYSCTL_POWER_V33 = 0

	*((volatile uint32_t *)(&sysctl->power_sel)) |= (1U<<(uint32_t)SYSCTL_POWER_BANK6);
	*((volatile uint32_t *)(&sysctl->power_sel)) |= (1U<<(uint32_t)SYSCTL_POWER_BANK7);

// Power the outputs

	gpiohs->output_en.u32[0] |= (1U<<BLED_0)
							 |  (1U<<BLED_1)
							 |  (1U<<BLED_2)
							 |  (1U<<BLCD_RST)
							 |  (1U<<BLCD_DCX);
}

/*
 * \brief local_RCU_Configuration
 *
 * - Main PLLs: sysctl_pll_set_freq(SYSCTL_PLL0, 800000000)
 *			    sysctl_pll_set_freq(SYSCTL_PLL1, 160000000)
 *			    sysctl_pll_set_freq(SYSCTL_PLL2,  45158400)
 *
 */
static	void	local_RCU_Configuration(void) {
				sysctl_pll0_t			pll0;
				sysctl_pll1_t			pll1;
				sysctl_pll2_t			pll2;
	volatile	sysctl_general_pll_t	*v_pll_t0, *v_pll_t1, *v_pll_t2;

	v_pll_t0 = (volatile sysctl_general_pll_t *)(&sysctl->pll0);
	v_pll_t1 = (volatile sysctl_general_pll_t *)(&sysctl->pll1);
	v_pll_t2 = (volatile sysctl_general_pll_t *)(&sysctl->pll2);

// 1. Change CPU CLK to XTAL

	sysctl->clk_sel0.aclk_sel = (uint32_t)SYSCTL_SOURCE_IN0 & 0x01U;

// 2. Disable PLLs output

	v_pll_t0->pll_out_en = 0U;
	v_pll_t1->pll_out_en = 0U;
	v_pll_t2->pll_out_en = 0U;

// 3. Turn off PLLs

	v_pll_t0->pll_pwrd = 0U;
	v_pll_t1->pll_pwrd = 0U;
	v_pll_t2->pll_pwrd = 0U;

// 4. Set PLL new value
//    Read the registers from the bus
//    Set registers values (printed by a test)
//    Write registers back to bus

	pll0 = sysctl->pll0;
	pll1 = sysctl->pll1;
	pll2 = sysctl->pll2;

// Values for sysctl_pll_set_freq(SYSCTL_PLL0, 800000000)

	pll0.clkr0  = 0x00U;
	pll0.clkf0  = 0x3DU;
	pll0.clkod0 = 0x01U;
	pll0.bwadj0 = 0x3DU;

// Values for sysctl_pll_set_freq(SYSCTL_PLL1, 160000000)

	pll1.clkr1  = 0x00U;
	pll1.clkf1  = 0x2AU;
	pll1.clkod1 = 0x06U;
	pll1.bwadj1 = 0x2AU;

// Values for sysctl_pll_set_freq(SYSCTL_PLL2,  45158400)

	pll2.clkr2  = 0x00U;
	pll2.clkf2  = 0x19U;
	pll2.clkod2 = 0x0EU;
	pll2.bwadj2 = 0x19U;

	sysctl->pll0 = pll0;
	sysctl->pll1 = pll1;
	sysctl->pll2 = pll2;

// 5. Power on PLLs

	v_pll_t0->pll_pwrd = 1U;
	v_pll_t1->pll_pwrd = 1U;
	v_pll_t2->pll_pwrd = 1U;
	local_wait_100n(1U);

// 6. Reset PLLs then Release Reset

	v_pll_t0->pll_reset = 0U;
	v_pll_t1->pll_reset = 0U;
	v_pll_t2->pll_reset = 0U;
	v_pll_t0->pll_reset = 1U;
	v_pll_t1->pll_reset = 1U;
	v_pll_t2->pll_reset = 1U;
	local_wait_100n(1U);

	v_pll_t0->pll_reset = 0U;
	v_pll_t1->pll_reset = 0U;
	v_pll_t2->pll_reset = 0U;

// 7. Get lock status, waiting for the PLLs stable

	while ((sysctl->pll_lock.pll_lock0 & 3U) == 0U) {
		sysctl->pll_lock.pll_slip_clear0 = 1U;
	}
	while ((sysctl->pll_lock.pll_lock1 & 1U) == 0U) {
		sysctl->pll_lock.pll_slip_clear1 = 1U;
	}
	while ((sysctl->pll_lock.pll_lock2 & 1U) == 0U) {
		sysctl->pll_lock.pll_slip_clear2 = 1U;
	}

// 8. Enable PLLs output

	v_pll_t0->pll_out_en = 1U;
	v_pll_t1->pll_out_en = 1U;
	v_pll_t2->pll_out_en = 1U;

// 9. Change CPU CLK to PLL

	sysctl->clk_sel0.aclk_sel = (uint32_t)SYSCTL_SOURCE_PLL0 & 0x01U;
}

/*
 * \brief local_wait_100n
 *
 * - Waiting n x 100-ns
 *
 */
static	void	local_wait_100n(uint32_t n) {
	uint32_t	i, j;

	for (j = 0U; j < n; j++) {
		for (i = 0; i < 1000U; i++) { NOP; }
	}
}
