/*
; stm32V873.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873 equates.
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

#pragma once

// IWYU pragma: begin_exports

#include    "Registers/soc_vectors.h"
#include    "Registers/stm32V873_adc1.h"
#include    "Registers/stm32V873_adc1.h"
#include    "Registers/stm32V873_adc12.h"
#include    "Registers/stm32V873_adc2.h"
#include    "Registers/stm32V873_adc2.h"
#include    "Registers/stm32V873_adc3.h"
#include    "Registers/stm32V873_adc3.h"
#include    "Registers/stm32V873_adcc12.h"
#include    "Registers/stm32V873_adcc3.h"
#include    "Registers/stm32V873_adcc3.h"
#include    "Registers/stm32V873_adf.h"
#include    "Registers/stm32V873_ccb.h"
#include    "Registers/stm32V873_cec.h"
#include    "Registers/stm32V873_cordic.h"
#include    "Registers/stm32V873_crc.h"
#include    "Registers/stm32V873_crs.h"
#include    "Registers/stm32V873_cryp.h"
#include    "Registers/stm32V873_dac.h"
#include    "Registers/stm32V873_dbgmcu.h"
#include    "Registers/stm32V873_dcmipp.h"
#include    "Registers/stm32V873_dlyb.h"
#include    "Registers/stm32V873_dma2d.h"
#include    "Registers/stm32V873_dts.h"
#include    "Registers/stm32V873_eth.h"
#include    "Registers/stm32V873_exti.h"
#include    "Registers/stm32V873_fdcan.h"
#include    "Registers/stm32V873_fmac.h"
#include    "Registers/stm32V873_fmc.h"
#include    "Registers/stm32V873_gfxmmu.h"
#include    "Registers/stm32V873_gfxtim.h"
#include    "Registers/stm32V873_gpdma.h"
#include    "Registers/stm32V873_gpio.h"
#include    "Registers/stm32V873_hash.h"
#include    "Registers/stm32V873_hpdma.h"
#include    "Registers/stm32V873_hrtim.h"
#include    "Registers/stm32V873_hsem.h"
#include    "Registers/stm32V873_i2c.h"
#include    "Registers/stm32V873_i3c.h"
#include    "Registers/stm32V873_iac.h"
#include    "Registers/stm32V873_iwdg.h"
#include    "Registers/stm32V873_jpeg.h"
#include    "Registers/stm32V873_lptim1.h"
#include    "Registers/stm32V873_lptim2.h"
#include    "Registers/stm32V873_lptim3.h"
#include    "Registers/stm32V873_lptim4.h"
#include    "Registers/stm32V873_lptim5.h"
#include    "Registers/stm32V873_lpuart.h"
#include    "Registers/stm32V873_ltdc.h"
#include    "Registers/stm32V873_mce.h"
#include    "Registers/stm32V873_mdf.h"
#include    "Registers/stm32V873_mdios.h"
#include    "Registers/stm32V873_nvm.h"
#include    "Registers/stm32V873_otg.h"
#include    "Registers/stm32V873_otg_fs.h"
#include    "Registers/stm32V873_pka.h"
#include    "Registers/stm32V873_pssi.h"
#include    "Registers/stm32V873_pwr.h"
#include    "Registers/stm32V873_ramcfg.h"
#include    "Registers/stm32V873_rcc.h"
#include    "Registers/stm32V873_rifsc.h"
#include    "Registers/stm32V873_risab.h"
#include    "Registers/stm32V873_risaf.h"
#include    "Registers/stm32V873_rng.h"
#include    "Registers/stm32V873_rtc.h"
#include    "Registers/stm32V873_saes.h"
#include    "Registers/stm32V873_sai.h"
#include    "Registers/stm32V873_sbs.h"
#include    "Registers/stm32V873_sdmmc.h"
#include    "Registers/stm32V873_spdifrx.h"
#include    "Registers/stm32V873_spi.h"
#include    "Registers/stm32V873_tamp.h"
#include    "Registers/stm32V873_tim1.h"
#include    "Registers/stm32V873_tim1.h"
#include    "Registers/stm32V873_tim10.h"
#include    "Registers/stm32V873_tim10.h"
#include    "Registers/stm32V873_tim12.h"
#include    "Registers/stm32V873_tim12.h"
#include    "Registers/stm32V873_tim13.h"
#include    "Registers/stm32V873_tim13.h"
#include    "Registers/stm32V873_tim14.h"
#include    "Registers/stm32V873_tim14.h"
#include    "Registers/stm32V873_tim15.h"
#include    "Registers/stm32V873_tim15.h"
#include    "Registers/stm32V873_tim16.h"
#include    "Registers/stm32V873_tim16.h"
#include    "Registers/stm32V873_tim17.h"
#include    "Registers/stm32V873_tim17.h"
#include    "Registers/stm32V873_tim2.h"
#include    "Registers/stm32V873_tim2.h"
#include    "Registers/stm32V873_tim20.h"
#include    "Registers/stm32V873_tim20.h"
#include    "Registers/stm32V873_tim3.h"
#include    "Registers/stm32V873_tim3.h"
#include    "Registers/stm32V873_tim4.h"
#include    "Registers/stm32V873_tim4.h"
#include    "Registers/stm32V873_tim5.h"
#include    "Registers/stm32V873_tim5.h"
#include    "Registers/stm32V873_tim6.h"
#include    "Registers/stm32V873_tim6.h"
#include    "Registers/stm32V873_tim7.h"
#include    "Registers/stm32V873_tim7.h"
#include    "Registers/stm32V873_tim8.h"
#include    "Registers/stm32V873_tim8.h"
#include    "Registers/stm32V873_tim9.h"
#include    "Registers/stm32V873_tim9.h"
#include    "Registers/stm32V873_ucpd.h"
#include    "Registers/stm32V873_usart.h"
#include    "Registers/stm32V873_usbphyc.h"
#include    "Registers/stm32V873_vrefbuf.h"
#include    "Registers/stm32V873_wwdg.h"
#include    "Registers/stm32V873_xspi.h"
#include    "Registers/stm32V873_xspim.h"
#include    "Registers/soc_addendum.h"

// IWYU pragma: end_exports
