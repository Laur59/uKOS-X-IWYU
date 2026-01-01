/*
; oct0.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi
; Modifs:	Laurent von Allmen
;
; Project:	uKOS-X
; Goal:		Octo SPI manager (for lcd).
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

#include	"oct0.h"

#include	<stdint.h>

#include	"Registers/K210_spi.h"
#include	"Registers/K210_sysctl.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"modules.h"

#undef		WITH_DMA_S

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"oct0         oct0 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "oct0 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Oct0,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KOCT0_NUM,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1U<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

#define	octoSpi0	((volatile	spi_t *)0x52000000u)

/*
 * \brief Initialise the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = oct0_init(void);
 * \endcode
 *
 * \param[in]	-
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
int32_t	oct0_init(void) {
	static	bool	vInit = false;

	if (!vInit) {
		vInit = true;

		sysctl->clk_en_cent.apb2_clk_en    = 1U;
		sysctl->clk_en_peri.spi0_clk_en    = 1U;
		sysctl->clk_th1.spi0_clk_threshold = 0U;

		octoSpi0->imr			= 0x00U;
		octoSpi0->dmacr			= 0x00U;
		octoSpi0->dmatdlr		= 0x00U;
		octoSpi0->dmardlr		= 0x00U;
		octoSpi0->ser			= 0x00U;
		octoSpi0->ssienr		= 0x00U;
		octoSpi0->ctrlr0		= ((uint32_t)SPI_WORK_MODE_0<<6U) | ((uint32_t)SPI_FF_OCTAL<<21U) | ((8U - 1U)<<16U);
		octoSpi0->spi_ctrlr0	= 0U;
		octoSpi0->endian		= 0U;
		octoSpi0->baudr			= 64U;
	}
	return (KERR_OCT0_NOERR);
}

/*
 * \brief Configure the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * const      cnfOctx_t    configure = {
 *                             .oMode     = KOCTAL,
 *                             .oNbBits   = 8,
 *                             .oXfer     = K8BITSAINC,
 *                             .oDevider  = KCLKDIV128,
 *                         };
 *
 *    status = oct0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
int32_t	oct0_configure(const cnfOctx_t *configure) {
	uint32_t	lnInst;

// The mode
// The number of bits

	switch (configure->oMode) {
		case KDUAL:   { octoSpi0->ctrlr0 = ((uint32_t)((uint32_t)SPI_WORK_MODE_0<<6U) | ((configure->oNbBits - 1U)<<16) | ((uint32_t)SPI_FF_DUAL<<21U));  break; }
		case KQUAD:   { octoSpi0->ctrlr0 = ((uint32_t)((uint32_t)SPI_WORK_MODE_0<<6U) | ((configure->oNbBits - 1U)<<16) | ((uint32_t)SPI_FF_QUAD<<21U));  break; }
		case KOCTAL:
		default:	  { octoSpi0->ctrlr0 = ((uint32_t)((uint32_t)SPI_WORK_MODE_0<<6U) | ((configure->oNbBits - 1U)<<16) | ((uint32_t)SPI_FF_OCTAL<<21U)); break; }
	}

// The divider factor

	switch (configure->oDevider) {
		case KCLKDIV2:   { octoSpi0->baudr = 2U;   break; }
		case KCLKDIV4:   { octoSpi0->baudr = 4U;   break; }
		case KCLKDIV8:   { octoSpi0->baudr = 8U;   break; }
		case KCLKDIV16:  { octoSpi0->baudr = 16U;  break; }
		case KCLKDIV32:  { octoSpi0->baudr = 32U;  break; }
		case KCLKDIV64:  { octoSpi0->baudr = 64U;  break; }
		case KCLKDIV128: { octoSpi0->baudr = 128U; break; }
		case KCLKDIV256: { octoSpi0->baudr = 256U; break; }
		default:		 { octoSpi0->baudr = 2U;   break; }
	}

	octoSpi0->spi_ctrlr0 = 0;
	octoSpi0->endian	 = 0;

// The instruction lenght

	switch (configure->oNbBits) {
		case 0U:  { lnInst = 0U; break; }
		case 4U:  { lnInst = 1U; break; }
		case 8U:  { lnInst = 2U; break; }
		case 16U: { lnInst = 3U; break; }
		default:  { lnInst = 2U; break; }
	}

	octoSpi0->spi_ctrlr0 = (0U<<11U) | (lnInst<<8U) | (0U<<2U) | (uint32_t)SPI_AITM_AS_FRAME_FORMAT;
	return (KERR_OCT0_NOERR);
}

#ifndef WITH_DMA_S
/*
 * \brief Write data to the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    chipSelect = 1;
 * uint8_t     buffer[3] =  { 0, 1, 2 };
 * uint32_t    xferMode = FILL;
 *
 *    status = oct0_write(chipSelect, buffer, 3, xferMode);
 * \endcode
 *
 * \param[in]	chipSelect		The chip select
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \param[in]	xferMode		Xfer mode (KFILL, KXFER8, KXFERT16)
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
int32_t	oct0_write(uint32_t chipSelect, const void *buffer, uint32_t szBuffer, uint32_t xferMode) {
			uint32_t	szFifo, value, i, j = 0U;
	const	uint8_t		*buffer_8;
	const	uint16_t	*buffer_16;

	value = octoSpi0->ctrlr0 & (uint32_t)~(3U<<8U);
	octoSpi0->ctrlr0 =  value | ((uint32_t)SPI_TMOD_TRANS<<8U);

	octoSpi0->ssienr = (1U<<(uint32_t)SPI_SSIENR_SSI_EN);
	octoSpi0->ser	 = (1U<<chipSelect);

	buffer_8  = (const uint8_t  *)buffer;
	buffer_16 = (const uint16_t *)buffer;

	while (szBuffer != 0U) {
		szFifo = 32U - octoSpi0->txflr;
		szFifo = (szFifo < szBuffer) ? (szFifo) : (szBuffer);

// Xfer of 8-bits
// Xfer of 16-bits
// Fill of 16-bits

		switch (xferMode) {
			case KXFER8:  { INTERRUPTION_OFF; for (i = 0U; i < szFifo; i++) { octoSpi0->dr[0] = buffer_8[j];  j++; } INTERRUPTION_RESTORE; break; }
			case KXFER16: {					  for (i = 0U; i < szFifo; i++) { octoSpi0->dr[0] = buffer_16[j]; j++; }					   break; }
			case KFILL:	  {					  for (i = 0U; i < szFifo; i++) { octoSpi0->dr[0] = buffer_16[0];	   }					   break; }
			default:	  {					  for (i = 0U; i < szFifo; i++) { octoSpi0->dr[0] = buffer_8[j];  j++; }					   break; }
		}
		szBuffer -= szFifo;
	}

	while ((octoSpi0->sr & ((1U<<(uint32_t)SPI_SR_TFE) | (1U<<(uint32_t)SPI_SR_BUSY))) != (1U<<(uint32_t)SPI_SR_TFE)) { }

	octoSpi0->ser	 = 0x00U;
	octoSpi0->ssienr = 0x00U;
	return (KERR_OCT0_NOERR);
}

#else
/*
 * \brief Write data to the oct0 manager by dma
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    chipSelect = 1;
 * uint8_t     buffer[3] =  { 0, 1, 2 };
 * uint32_t    xferMode = FILL;
 *
 *    status = oct0_writeDMA(chipSelect, buffer, 3, xferMode);
 * \endcode
 *
 * \param[in]	chipSelect		The chip select
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \param[in]	xferMode		Xfer mode (KFILL, KXFER8, KXFERT16)
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
static	bool	local_DMAIsIdle(dmac_channel_number_t channel_num) {
	dmac_chen_u_t	chen;
	bool			status;

	chen.data = *(volatile uint64_t *)(&dmac->chen);
	status = (((chen.data>>channel_num) & 0x1u) != 0U) ? (false) : (true);
	return (status);
}

static	void	local_DMAWaitIdle(dmac_channel_number_t channel_num) {

	while (local_DMAIsIdle(channel_num) == false) { }
	(*(volatile uint64_t *)(&dmac->channel[channel_num].intclear)) = 0xFFFFFFFFu;
}

int32_t		oct0_write(uint32_t chipSelect, const void *buffer, uint32_t szBuffer, uint32_t xferMode) {
	uint32_t			i, *buf, value;
	dmac_chen_u_t		chen;
	sysctl_dma_sel0_t	dma_sel0;
	dmac_cfg_u_t		dmac_cfg;
	dmac_ch_ctl_u_t		ctl;
	dmac_ch_cfg_u_t		cfg_u;

	value = octoSpi0->ctrlr0 & ~(3U<<8U);
	octoSpi0->ctrlr0 = value | ((uint32_t)SPI_TMOD_TRANS<<8U);

// Xfer of 8-bits
// Xfer of 16-bits
// Fill of 16-bits

	switch(xferMode) {
		case KXFER16: {
			buf  = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, (szBuffer * sizeof(uint32_t)), "oct0");
			for (i = 0U; i < szBuffer; i++) {
				buf[i] = ((uint16_t *)buffer)[i];
			break;
		}
		case KFILL: {
			buf = (uint32_t *)buffer;
			break;
		}
		default:
		case KXFER8: {
			buf  = (uint32_t *)memo_malloc(KMEMO_ALIGN_8, (szBuffer * sizeof(uint32_t)), "oct0");
	        for (i = 0U; i < szBuffer; i++) {
	            buf[i] = ((uint8_t *)buffer)[i];
	        }
	    	break;
		}
	}

	octoSpi0->dmacr  = 0x2u;
	octoSpi0->ssienr = (1U<<(uint32_t)SPI_SSIENR_SSI_EN);

// Select the DMA

	dma_sel0 = sysctl->dma_sel0;
	dma_sel0.dma_sel0 = SYSCTL_DMA_SELECT_SSI0_TX_REQ + SPI_DEVICE_0 * 2U;
	sysctl->dma_sel0 = dma_sel0;

// DMA in a single mode
// --------------------

	(*(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].intclear)) = 0xFFFFFFFFu;

// Disable the channel

	chen.data = *(volatile uint64_t *)(&dmac->chen);
	chen.dmac_chen.ch1_en    = 0U;
	chen.dmac_chen.ch1_en_we = 1U;
	(*(volatile uint64_t *)(&dmac->chen)) = chen.data;

// Waiting for the idle

	while (local_DMAIsIdle(DMAC_CHANNEL0) == 0U) { }
	(*(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].intclear)) = 0xFFFFFFFFu;

// Set the DMA channel

	cfg_u.data = *(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].cfg);
	cfg_u.ch_cfg.tt_fc			  = DMAC_MEM2PRF_DMA;
	cfg_u.ch_cfg.hs_sel_src		  = DMAC_HS_SOFTWARE;
	cfg_u.ch_cfg.hs_sel_dst		  = DMAC_HS_HARDWARE;
	cfg_u.ch_cfg.src_per		  = DMAC_CHANNEL0;
	cfg_u.ch_cfg.dst_per		  = DMAC_CHANNEL0;
	cfg_u.ch_cfg.src_multblk_type = 0U;
	cfg_u.ch_cfg.dst_multblk_type = 0U;
	(*(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].cfg)) = cfg_u.data;

	dmac->channel[DMAC_CHANNEL0].sar = (uint64_t)buf;
	dmac->channel[DMAC_CHANNEL0].dar = (uint64_t)(void *)(&octoSpi0->dr[0]);

	ctl.data = *(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].ctl);
	ctl.ch_ctl.sms			= DMAC_MASTER1;
	ctl.ch_ctl.dms			= DMAC_MASTER2;
	ctl.ch_ctl.sinc			= DMAC_ADDR_INCREMENT;
	ctl.ch_ctl.dinc			= DMAC_ADDR_NOCHANGE;
	ctl.ch_ctl.src_tr_width = DMAC_TRANS_WIDTH_32;
	ctl.ch_ctl.dst_tr_width = DMAC_TRANS_WIDTH_32;
	ctl.ch_ctl.src_msize	= DMAC_MSIZE_4;
	ctl.ch_ctl.dst_msize	= DMAC_MSIZE_4;
	(*(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].ctl)) = ctl.data;

	(*(volatile uint64_t *)(&dmac->channel[DMAC_CHANNEL0].block_ts)) = szBuffer - 1;

// Enable the DMA

	dmac_cfg.data = *(volatile uint64_t *)(&dmac->cfg);
	dmac_cfg.cfg.dmac_en = 1U;
	dmac_cfg.cfg.int_en  = 1U;
	(*(volatile uint64_t *)(&dmac->cfg)) = dmac_cfg.data;

// Enable the channel

	chen.data = *(volatile uint64_t *)(&dmac->chen);
	chen.dmac_chen.ch1_en    = 1U;
	chen.dmac_chen.ch1_en_we = 1U;
	(*(volatile uint64_t *)(&dmac->chen)) = chen.data;

	octoSpi0->ser = (1U<<chipSelect);

// Waiting for the idle

	local_DMAWaitIdle(DMAC_CHANNEL0);

	if (xferMode != KFILL) { memo_free((void *)buf); }

	while ((octoSpi0->sr & ((1U<<(uint32_t)SPI_SR_TFE) | (1U<<(uint32_t)SPI_SR_BUSY))) != (1U<<(uint32_t)SPI_SR_TFE));

	octoSpi0->ser	 = 0x00u;
	octoSpi0->ssienr = 0x00u;
	return (KERR_OCT0_NOERR);
}
#endif
