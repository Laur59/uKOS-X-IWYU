/*
; stm32V873_eth.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32V873_eth equates.
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

#include    <stdint.h>

// ETH address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    MACCR;
    volatile    uint32_t    MACECR;
    volatile    uint32_t    MACPFR;
    volatile    uint32_t    MACWJBTR;
    volatile    uint32_t    MACHT0R;
    volatile    uint32_t    MACHT1R;
    volatile    uint32_t    RESERVED0[14];
    volatile    uint32_t    MACVTCR;
    volatile    uint32_t    MACVTDR;
    volatile    uint32_t    MACVHTR;
    volatile    uint32_t    RESERVED1;
        union {
    volatile    uint32_t    MACVIR;
    volatile    uint32_t    MACVIR_ALTERNATE1;
        };
    volatile    uint32_t    MACIVIR;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    MACQ0TXFCR;
    volatile    uint32_t    RESERVED3[7];
    volatile    uint32_t    MACRXFCR;
    volatile    uint32_t    MACRXQCR;
    volatile    uint32_t    RESERVED4[2];
    volatile    uint32_t    MACRXQC0R;
    volatile    uint32_t    MACRXQC1R;
    volatile    uint32_t    MACRXQC2R;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    MACISR;
    volatile    uint32_t    MACIER;
    volatile    uint32_t    MACRXTXSR;
    volatile    uint32_t    RESERVED6;
    volatile    uint32_t    MACPCSR;
    volatile    uint32_t    MACRWKPFR;
    volatile    uint32_t    RESERVED7[2];
    volatile    uint32_t    MACLCSR;
    volatile    uint32_t    MACLTCR;
    volatile    uint32_t    MACLETR;
    volatile    uint32_t    MAC1USTCR;
    volatile    uint32_t    RESERVED8[6];
    volatile    uint32_t    MACPHYCSR;
    volatile    uint32_t    RESERVED9[5];
    volatile    uint32_t    MACVR;
    volatile    uint32_t    MACDR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    MACHWF0R;
    volatile    uint32_t    MACHWF1R;
    volatile    uint32_t    MACHWF2R;
    volatile    uint32_t    MACHWF3R;
    volatile    uint32_t    RESERVED11[53];
    volatile    uint32_t    MACMDIOAR;
        union {
    volatile    uint32_t    MACMDIODR;
    volatile    uint32_t    B10T1S_PLCA_CR;
    volatile    uint32_t    B10T1S_PLCA_NODECR;
    volatile    uint32_t    B10BT1S_PLCA_TMR;
    volatile    uint32_t    B10T1S_PLCA_SR;
    volatile    uint32_t    B10T1S_PCS_CR;
    volatile    uint32_t    B10T1S_PCS_SR;
    volatile    uint32_t    B10T1S_PCS_DIAG1;
    volatile    uint32_t    B10T1S_PCS_DIAG2;
    volatile    uint32_t    B10T1S_PCS_JBTMR;
    volatile    uint32_t    B10T1S_PMA_EXTABLTY;
    volatile    uint32_t    B10T1S_PMA_PMD_CR;
    volatile    uint32_t    B10T1S_PMA_CR;
    volatile    uint32_t    B10T1S_PMA_SR;
    volatile    uint32_t    B10T1S_PMA_TMCR;
    volatile    uint32_t    B10T1S_PMA_DR;
    volatile    uint32_t    B10T1S_XCVR_PHYID_LSB;
    volatile    uint32_t    B10T1S_XCVR_PHYID_MSB;
    volatile    uint32_t    B10T1S_XCVR_MIIMCTRL;
        };
    volatile    uint32_t    RESERVED12[2];
    volatile    uint32_t    MACARPAR;
    volatile    uint32_t    RESERVED13[3];
    volatile    uint32_t    MAC10BT1SCR;
    volatile    uint32_t    RESERVED14[3];
    volatile    uint32_t    MACCSRSWCR;
    volatile    uint32_t    MACFPECSR;
    volatile    uint32_t    RESERVED15[2];
    volatile    uint32_t    MACPRSTIMR;
    volatile    uint32_t    MACPRSTIMUR;
    volatile    uint32_t    RESERVED16[46];
    volatile    uint32_t    MACA0HR;
    volatile    uint32_t    MACA0LR;
    volatile    uint32_t    MACA1HR;
    volatile    uint32_t    MACA1LR;
    volatile    uint32_t    MACA2HR;
    volatile    uint32_t    MACA2LR;
    volatile    uint32_t    MACA3HR;
    volatile    uint32_t    MACA3LR;
    volatile    uint32_t    RESERVED17[248];
    volatile    uint32_t    MMC_CONTROL;
    volatile    uint32_t    MMC_RX_INTERRUPT;
    volatile    uint32_t    MMC_TX_INTERRUPT;
    volatile    uint32_t    MMC_RX_INTERRUPT_MASK;
    volatile    uint32_t    MMC_TX_INTERRUPT_MASK;
    volatile    uint32_t    TX_OCTET_COUNT_GOOD_BAD;
    volatile    uint32_t    TX_PACKET_COUNT_GOOD_BAD;
    volatile    uint32_t    TX_BROADCAST_PACKETS_GOOD;
    volatile    uint32_t    TX_MULTICAST_PACKETS_GOOD;
    volatile    uint32_t    TX_64OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_64TO127OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_128TO255OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_256TO511OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_512TO1023OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_UNICAST_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_MULTICAST_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_BROADCAST_PACKETS_GOOD_BAD;
    volatile    uint32_t    TX_UNDERFLOW_ERROR_PACKETS;
    volatile    uint32_t    TX_SINGLE_COLLISION_GOOD_PACKETS;
    volatile    uint32_t    TX_MULTIPLE_COLLISION_GOOD_PACKETS;
    volatile    uint32_t    TX_DEFERRED_PACKETS;
    volatile    uint32_t    TX_LATE_COLLISION_PACKETS;
    volatile    uint32_t    TX_EXCESSIVE_COLLISION_PACKETS;
    volatile    uint32_t    TX_CARRIER_ERROR_PACKETS;
    volatile    uint32_t    TX_OCTET_COUNT_GOOD;
    volatile    uint32_t    TX_PACKET_COUNT_GOOD;
    volatile    uint32_t    TX_EXCESSIVE_DEFERRAL_ERROR;
    volatile    uint32_t    TX_PAUSE_PACKETS;
    volatile    uint32_t    TX_VLAN_PACKETS_GOOD;
    volatile    uint32_t    TX_OSIZE_PACKETS_GOOD;
    volatile    uint32_t    RESERVED18;
    volatile    uint32_t    RX_PACKETS_COUNT_GOOD_BAD;
    volatile    uint32_t    RX_OCTET_COUNT_GOOD_BAD;
    volatile    uint32_t    RX_OCTET_COUNT_GOOD;
    volatile    uint32_t    RX_BROADCAST_PACKETS_GOOD;
    volatile    uint32_t    RX_MULTICAST_PACKETS_GOOD;
    volatile    uint32_t    RX_CRC_ERROR_PACKETS;
    volatile    uint32_t    RX_ALIGNMENT_ERROR_PACKETS;
    volatile    uint32_t    RX_RUNT_ERROR_PACKETS;
    volatile    uint32_t    RX_JABBER_ERROR_PACKETS;
    volatile    uint32_t    RX_UNDERSIZE_PACKETS_GOOD;
    volatile    uint32_t    RX_OVERSIZE_PACKETS_GOOD;
    volatile    uint32_t    RX_64OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_65TO127OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_128TO255OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_256TO511OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_512TO1023OCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_UNICAST_PACKETS_GOOD;
    volatile    uint32_t    RX_LENGTH_ERROR_PACKETS;
    volatile    uint32_t    RX_OUT_OF_RANGE_PACKETS;
    volatile    uint32_t    RX_PAUSE_PACKETS;
    volatile    uint32_t    RX_FIFO_OVERFLOW_PACKETS;
    volatile    uint32_t    RX_VLAN_PACKETS_GOOD_BAD;
    volatile    uint32_t    RX_WATCHDOG_ERROR_PACKETS;
    volatile    uint32_t    RX_RECEIVE_ERROR;
    volatile    uint32_t    RX_CONTROL_PACKETS_GOOD;
    volatile    uint32_t    RESERVED19;
    volatile    uint32_t    TX_LPI_USEC_CNTR;
    volatile    uint32_t    TX_LPI_TRAN_CNTR;
    volatile    uint32_t    RX_LPI_USEC_CNTR;
    volatile    uint32_t    RX_LPI_TRAN_CNTR;
    volatile    uint32_t    RESERVED20[41];
    volatile    uint32_t    MMC_FPE_TX_ISR;
    volatile    uint32_t    MMC_FPE_TX_IMR;
    volatile    uint32_t    MMC_FPE_TX_FCR;
    volatile    uint32_t    MMC_TX_HRCR;
    volatile    uint32_t    RESERVED21[4];
    volatile    uint32_t    MMC_FPE_RX_ISR;
    volatile    uint32_t    MMC_FPE_RX_IMR;
    volatile    uint32_t    RX_PACKET_ASM_ERR;
    volatile    uint32_t    RX_PACKET_SMD_ERR;
    volatile    uint32_t    RX_PACKET_ASM_OKR;
    volatile    uint32_t    RX_FPE_FRAG_CR;
    volatile    uint32_t    RESERVED22[10];
    volatile    uint32_t    MACL3L4C0R;
    volatile    uint32_t    MACL4A0R;
    volatile    uint32_t    RESERVED23[2];
    volatile    uint32_t    MACL3A00R;
    volatile    uint32_t    MACL3A10R;
    volatile    uint32_t    MACL3A20R;
    volatile    uint32_t    MACL3A30R;
    volatile    uint32_t    RESERVED24[4];
    volatile    uint32_t    MACL3L4C1R;
    volatile    uint32_t    MACL4A1R;
    volatile    uint32_t    RESERVED25[2];
    volatile    uint32_t    MACL3A01R;
    volatile    uint32_t    MACL3A11R;
    volatile    uint32_t    MACL3A21R;
    volatile    uint32_t    MACL3A31R;
    volatile    uint32_t    RESERVED26[72];
    volatile    uint32_t    MAC_IACR;
    volatile    uint32_t    MAC_TMRQR;
    volatile    uint32_t    RESERVED27[34];
    volatile    uint32_t    MACTSCR;
    volatile    uint32_t    MACSSIR;
    volatile    uint32_t    MACSTSR;
    volatile    uint32_t    MACSTNR;
    volatile    uint32_t    MACSTSUR;
    volatile    uint32_t    MACSTNUR;
    volatile    uint32_t    MACTSAR;
    volatile    uint32_t    RESERVED28;
    volatile    uint32_t    MACTSSR;
    volatile    uint32_t    MACRXDTI;
    volatile    uint32_t    MACTXDTI;
    volatile    uint32_t    RESERVED29;
    volatile    uint32_t    MACTXTSSNR;
    volatile    uint32_t    MACTXTSSSR;
    volatile    uint32_t    RESERVED30[2];
    volatile    uint32_t    MACACR;
    volatile    uint32_t    RESERVED31;
    volatile    uint32_t    MACATSNR;
    volatile    uint32_t    MACATSSR;
    volatile    uint32_t    MACTSIACR;
    volatile    uint32_t    MACTSEACR;
    volatile    uint32_t    MACTSICNR;
    volatile    uint32_t    MACTSECNR;
    volatile    uint32_t    RESERVED32[2];
    volatile    uint32_t    MACTSILR;
    volatile    uint32_t    MACTSELR;
        union {
    volatile    uint32_t    MACPPSCR;
    volatile    uint32_t    MACPPSCR_ALTERNATE1;
        };
    volatile    uint32_t    RESERVED33[3];
    volatile    uint32_t    MACPPSTTS0R;
    volatile    uint32_t    MACPPSTTN0R;
    volatile    uint32_t    MACPPSI0R;
    volatile    uint32_t    MACPPSW0R;
    volatile    uint32_t    MACPPSTTS1R;
    volatile    uint32_t    MACPPSTTN1R;
    volatile    uint32_t    MACPPSI1R;
    volatile    uint32_t    MACPPSW1R;
    volatile    uint32_t    RESERVED34[8];
    volatile    uint32_t    MACPOCR;
    volatile    uint32_t    MACSPI0R;
    volatile    uint32_t    MACSPI1R;
    volatile    uint32_t    MACSPI2R;
    volatile    uint32_t    MACLMIR;
    volatile    uint32_t    RESERVED35[11];
    volatile    uint32_t    MTLOMR;
    volatile    uint32_t    RESERVED36[7];
    volatile    uint32_t    MTLISR;
    volatile    uint32_t    RESERVED37[3];
    volatile    uint32_t    MTLRXQDMAMR;
    volatile    uint32_t    RESERVED38[3];
    volatile    uint32_t    MTLTBSCR;
    volatile    uint32_t    RESERVED39[3];
    volatile    uint32_t    MTLESTCR;
    volatile    uint32_t    MTLESTECR;
    volatile    uint32_t    MTLESTSR;
    volatile    uint32_t    RESERVED40;
    volatile    uint32_t    MTLESTSCHER;
    volatile    uint32_t    MTLESTFSER;
    volatile    uint32_t    MTLESTFSCR;
    volatile    uint32_t    RESERVED41;
    volatile    uint32_t    MTLESTIER;
    volatile    uint32_t    RESERVED42[3];
    volatile    uint32_t    MTLESTGCLCR;
    volatile    uint32_t    MTLESTGCLDR;
    volatile    uint32_t    RESERVED43[2];
    volatile    uint32_t    MTLFPECSR;
    volatile    uint32_t    MTLFPEAR;
    volatile    uint32_t    RESERVED44[26];
    volatile    uint32_t    MTLTXQ0OMR;
    volatile    uint32_t    MTLTXQ0UR;
    volatile    uint32_t    MTLTXQ0DR;
    volatile    uint32_t    RESERVED45[2];
    volatile    uint32_t    MTLTXQ0ESR;
    volatile    uint32_t    MTLTXQ0QWR;
    volatile    uint32_t    RESERVED46[4];
    volatile    uint32_t    MTLQ0ICSR;
    volatile    uint32_t    MTLRXQ0OMR;
    volatile    uint32_t    MTLRXQ0MPOCR;
    volatile    uint32_t    MTLRXQ0DR;
    volatile    uint32_t    MTLRXQ0CR;
    volatile    uint32_t    MTLTXQ1OMR;
    volatile    uint32_t    MTLTXQ1UR;
    volatile    uint32_t    MTLTXQ1DR;
    volatile    uint32_t    RESERVED47;
    volatile    uint32_t    MTLTXQ1ECR;
    volatile    uint32_t    MTLTXQ1ESR;
    volatile    uint32_t    MTLTXQ1QWR;
    volatile    uint32_t    MTLTXQ1SSCR;
    volatile    uint32_t    MTLTXQ1HCR;
    volatile    uint32_t    MTLTXQ1LCR;
    volatile    uint32_t    RESERVED48;
    volatile    uint32_t    MTLQ1ICSR;
    volatile    uint32_t    MTLRXQ1OMR;
    volatile    uint32_t    MTLRXQ1MPOCR;
    volatile    uint32_t    MTLRXQ1DR;
    volatile    uint32_t    MTLRXQ1CR;
    volatile    uint32_t    MTLTXQ2OMR;
    volatile    uint32_t    MTLTXQ2UR;
    volatile    uint32_t    MTLTXQ2DR;
    volatile    uint32_t    RESERVED49;
    volatile    uint32_t    MTLTXQ2ECR;
    volatile    uint32_t    MTLTXQ2ESR;
    volatile    uint32_t    MTLTXQ2QWR;
    volatile    uint32_t    MTLTXQ2SSCR;
    volatile    uint32_t    MTLTXQ2HCR;
    volatile    uint32_t    MTLTXQ2LCR;
    volatile    uint32_t    RESERVED50;
    volatile    uint32_t    MTLQ2ICSR;
    volatile    uint32_t    RESERVED51[4];
    volatile    uint32_t    MTLTXQ3OMR;
    volatile    uint32_t    MTLTXQ3UR;
    volatile    uint32_t    MTLTXQ3DR;
    volatile    uint32_t    RESERVED52;
    volatile    uint32_t    MTLTXQ3ECR;
    volatile    uint32_t    MTLTXQ3ESR;
    volatile    uint32_t    MTLTXQ3QWR;
    volatile    uint32_t    MTLTXQ3SSCR;
    volatile    uint32_t    MTLTXQ3HCR;
    volatile    uint32_t    MTLTXQ3LCR;
    volatile    uint32_t    RESERVED53;
    volatile    uint32_t    MTLQ3ICSR;
    volatile    uint32_t    RESERVED54[132];
    volatile    uint32_t    DMAMR;
    volatile    uint32_t    DMASBMR;
    volatile    uint32_t    DMAISR;
    volatile    uint32_t    DMADS1R;
    volatile    uint32_t    DMADS2R;
    volatile    uint32_t    RESERVED55[3];
    volatile    uint32_t    DMAA4TXACR;
    volatile    uint32_t    DMAA4RXACR;
    volatile    uint32_t    DMAA4DACR;
    volatile    uint32_t    RESERVED56[5];
    volatile    uint32_t    DMALPIEI;
    volatile    uint32_t    RESERVED57[3];
        union {
    volatile    uint32_t    DMATBSCTRL0R;
    volatile    uint32_t    DMATBSCTRL0R_ALTERNATE1;
        };
    volatile    uint32_t    DMATBSCTRL1R;
    volatile    uint32_t    DMATBSCTRL2R;
    volatile    uint32_t    DMATBSCTRL3R;
    volatile    uint32_t    RESERVED58[40];
    volatile    uint32_t    DMAC0CR;
    volatile    uint32_t    DMAC0TXCR;
    volatile    uint32_t    DMAC0RXCR;
    volatile    uint32_t    RESERVED59[2];
    volatile    uint32_t    DMAC0TXDLAR;
    volatile    uint32_t    RESERVED60;
    volatile    uint32_t    DMAC0RXDLAR;
    volatile    uint32_t    DMAC0TXDTPR;
    volatile    uint32_t    RESERVED61;
    volatile    uint32_t    DMAC0RXDTPR;
    volatile    uint32_t    DMAC0TXRLR;
    volatile    uint32_t    DMAC0RXRLR;
    volatile    uint32_t    DMAC0IER;
    volatile    uint32_t    DMAC0RXIWTR;
    volatile    uint32_t    DMAC0SFCSR;
    volatile    uint32_t    RESERVED62;
    volatile    uint32_t    DMAC0CATXDR;
    volatile    uint32_t    RESERVED63;
    volatile    uint32_t    DMAC0CARXDR;
    volatile    uint32_t    RESERVED64;
    volatile    uint32_t    DMAC0CATXBR;
    volatile    uint32_t    RESERVED65;
    volatile    uint32_t    DMAC0CARXBR;
    volatile    uint32_t    DMAC0SR;
    volatile    uint32_t    DMAC0MFCR;
    volatile    uint32_t    RESERVED66[6];
    volatile    uint32_t    DMAC1CR;
    volatile    uint32_t    DMAC1TXCR;
    volatile    uint32_t    DMAC1RXCR;
    volatile    uint32_t    RESERVED67[2];
    volatile    uint32_t    DMAC1TXDLAR;
    volatile    uint32_t    RESERVED68;
    volatile    uint32_t    DMAC1RXDLAR;
    volatile    uint32_t    DMAC1TXDTPR;
    volatile    uint32_t    RESERVED69;
    volatile    uint32_t    DMAC1RXDTPR;
    volatile    uint32_t    DMAC1TXRLR;
    volatile    uint32_t    DMAC1RXRLR;
    volatile    uint32_t    DMAC1IER;
    volatile    uint32_t    DMAC1RXIWTR;
    volatile    uint32_t    DMAC1SFCSR;
    volatile    uint32_t    RESERVED70;
    volatile    uint32_t    DMAC1CATXDR;
    volatile    uint32_t    RESERVED71;
    volatile    uint32_t    DMAC1CARXDR;
    volatile    uint32_t    RESERVED72;
    volatile    uint32_t    DMAC1CATXBR;
    volatile    uint32_t    RESERVED73;
    volatile    uint32_t    DMAC1CARXBR;
    volatile    uint32_t    DMAC1SR;
    volatile    uint32_t    DMAC1MFCR;
    volatile    uint32_t    RESERVED74[6];
    volatile    uint32_t    DMAC2CR;
    volatile    uint32_t    DMAC2TXCR;
    volatile    uint32_t    RESERVED75[3];
    volatile    uint32_t    DMAC2TXDLAR;
    volatile    uint32_t    RESERVED76[2];
    volatile    uint32_t    DMAC2TXDTPR;
    volatile    uint32_t    RESERVED77[2];
    volatile    uint32_t    DMAC2TXRLR;
    volatile    uint32_t    RESERVED78;
    volatile    uint32_t    DMAC2IER;
    volatile    uint32_t    RESERVED79;
    volatile    uint32_t    DMAC2SFCSR;
    volatile    uint32_t    RESERVED80;
    volatile    uint32_t    DMAC2CATXDR;
    volatile    uint32_t    RESERVED81[3];
    volatile    uint32_t    DMAC2CATXBR;
    volatile    uint32_t    RESERVED82[2];
    volatile    uint32_t    DMAC2SR;
    volatile    uint32_t    RESERVED83[7];
    volatile    uint32_t    DMAC3CR;
    volatile    uint32_t    DMAC3TXCR;
    volatile    uint32_t    RESERVED84[3];
    volatile    uint32_t    DMAC3TXDLAR;
    volatile    uint32_t    RESERVED85[2];
    volatile    uint32_t    DMAC3TXDTPR;
    volatile    uint32_t    RESERVED86[2];
    volatile    uint32_t    DMAC3TXRLR;
    volatile    uint32_t    RESERVED87;
    volatile    uint32_t    DMAC3IER;
    volatile    uint32_t    RESERVED88;
    volatile    uint32_t    DMAC3SFCSR;
    volatile    uint32_t    RESERVED89;
    volatile    uint32_t    DMAC3CATXDR;
    volatile    uint32_t    RESERVED90[3];
    volatile    uint32_t    DMAC3CATXBR;
    volatile    uint32_t    RESERVED91[2];
    volatile    uint32_t    DMAC3SR;
} ETH_TypeDef;

#if (defined(__cplusplus))
#define ETH_NS  reinterpret_cast<ETH_TypeDef *>(0x48036000u)
#define ETH_S   reinterpret_cast<ETH_TypeDef *>(0x58036000u)

#else
#define ETH_NS  ((ETH_TypeDef *)0x48036000u)
#define ETH_S   ((ETH_TypeDef *)0x58036000u)
#endif

// MACCR Configuration

#define ETH_MACCR_ARPEN                                             (0x1u<<31)
#define ETH_MACCR_SARC                                              (0x7u<<28)
#define ETH_MACCR_SARC_0                                            (0x1u<<28)
#define ETH_MACCR_IPC                                               (0x1u<<27)
#define ETH_MACCR_IPG                                               (0x7u<<24)
#define ETH_MACCR_IPG_0                                             (0x1u<<24)
#define ETH_MACCR_GPSLCE                                            (0x1u<<23)
#define ETH_MACCR_S2KP                                              (0x1u<<22)
#define ETH_MACCR_CST                                               (0x1u<<21)
#define ETH_MACCR_ACS                                               (0x1u<<20)
#define ETH_MACCR_WD                                                (0x1u<<19)
#define ETH_MACCR_BE                                                (0x1u<<18)
#define ETH_MACCR_JD                                                (0x1u<<17)
#define ETH_MACCR_JE                                                (0x1u<<16)
#define ETH_MACCR_PS                                                (0x1u<<15)
#define ETH_MACCR_FES                                               (0x1u<<14)
#define ETH_MACCR_DM                                                (0x1u<<13)
#define ETH_MACCR_LM                                                (0x1u<<12)
#define ETH_MACCR_ECRSFD                                            (0x1u<<11)
#define ETH_MACCR_DO                                                (0x1u<<10)
#define ETH_MACCR_DCRS                                              (0x1u<<9)
#define ETH_MACCR_DR                                                (0x1u<<8)
#define ETH_MACCR_BL                                                (0x3u<<5)
#define ETH_MACCR_BL_0                                              (0x1u<<5)
#define ETH_MACCR_DC                                                (0x1u<<4)
#define ETH_MACCR_PRELEN                                            (0x3u<<2)
#define ETH_MACCR_PRELEN_0                                          (0x1u<<2)
#define ETH_MACCR_TE                                                (0x1u<<1)
#define ETH_MACCR_RE                                                (0x1u<<0)

#define ETH_MACCR_SARC_B_0X2                                        (0x2u<<28)
#define ETH_MACCR_SARC_B_0X3                                        (0x3u<<28)
#define ETH_MACCR_SARC_B_0X6                                        (0x6u<<28)
#define ETH_MACCR_SARC_B_0X7                                        (0x7u<<28)
#define ETH_MACCR_IPG_B_0X0                                         (0x0u<<24)
#define ETH_MACCR_IPG_B_0X1                                         (0x1u<<24)
#define ETH_MACCR_IPG_B_0X2                                         (0x2u<<24)
#define ETH_MACCR_IPG_B_0X7                                         (0x7u<<24)
#define ETH_MACCR_PS_B_0X0                                          (0x0u<<15)
#define ETH_MACCR_PS_B_0X1                                          (0x1u<<15)
#define ETH_MACCR_FES_B_0X0                                         (0x0u<<14)
#define ETH_MACCR_FES_B_0X1                                         (0x1u<<14)
#define ETH_MACCR_BL_B_0X0                                          (0x0u<<5)
#define ETH_MACCR_BL_B_0X1                                          (0x1u<<5)
#define ETH_MACCR_BL_B_0X2                                          (0x2u<<5)
#define ETH_MACCR_BL_B_0X3                                          (0x3u<<5)
#define ETH_MACCR_PRELEN_B_0X0                                      (0x0u<<2)
#define ETH_MACCR_PRELEN_B_0X1                                      (0x1u<<2)
#define ETH_MACCR_PRELEN_B_0X2                                      (0x2u<<2)
#define ETH_MACCR_PRELEN_B_0X3                                      (0x3u<<2)

// MACECR Configuration

#define ETH_MACECR_APDIM                                            (0x1u<<30)
#define ETH_MACECR_EIPG                                             (0x1Fu<<25)
#define ETH_MACECR_EIPG_0                                           (0x1u<<25)
#define ETH_MACECR_EIPGEN                                           (0x1u<<24)
#define ETH_MACECR_USP                                              (0x1u<<18)
#define ETH_MACECR_SPEN                                             (0x1u<<17)
#define ETH_MACECR_DCRCC                                            (0x1u<<16)
#define ETH_MACECR_GPSL                                             (0x3FFFu<<0)
#define ETH_MACECR_GPSL_0                                           (0x1u<<0)

// MACPFR Configuration

#define ETH_MACPFR_RA                                               (0x1u<<31)
#define ETH_MACPFR_DNTU                                             (0x1u<<21)
#define ETH_MACPFR_IPFE                                             (0x1u<<20)
#define ETH_MACPFR_VTFE                                             (0x1u<<16)
#define ETH_MACPFR_HPF                                              (0x1u<<10)
#define ETH_MACPFR_SAF                                              (0x1u<<9)
#define ETH_MACPFR_SAIF                                             (0x1u<<8)
#define ETH_MACPFR_PCF                                              (0x3u<<6)
#define ETH_MACPFR_PCF_0                                            (0x1u<<6)
#define ETH_MACPFR_DBF                                              (0x1u<<5)
#define ETH_MACPFR_PM                                               (0x1u<<4)
#define ETH_MACPFR_DAIF                                             (0x1u<<3)
#define ETH_MACPFR_HMC                                              (0x1u<<2)
#define ETH_MACPFR_HUC                                              (0x1u<<1)
#define ETH_MACPFR_PR                                               (0x1u<<0)

#define ETH_MACPFR_PCF_B_0X0                                        (0x0u<<6)
#define ETH_MACPFR_PCF_B_0X1                                        (0x1u<<6)
#define ETH_MACPFR_PCF_B_0X2                                        (0x2u<<6)
#define ETH_MACPFR_PCF_B_0X3                                        (0x3u<<6)

// MACWJBTR Configuration

#define ETH_MACWJBTR_PJE                                            (0x1u<<24)
#define ETH_MACWJBTR_JTO                                            (0xFu<<16)
#define ETH_MACWJBTR_JTO_0                                          (0x1u<<16)
#define ETH_MACWJBTR_PWE                                            (0x1u<<8)
#define ETH_MACWJBTR_WTO                                            (0xFu<<0)
#define ETH_MACWJBTR_WTO_0                                          (0x1u<<0)

#define ETH_MACWJBTR_JTO_B_0X0                                      (0x0u<<16)
#define ETH_MACWJBTR_JTO_B_0X1                                      (0x1u<<16)
#define ETH_MACWJBTR_JTO_B_0X2                                      (0x2u<<16)
#define ETH_MACWJBTR_JTO_B_0X3                                      (0x3u<<16)
#define ETH_MACWJBTR_JTO_B_0XC                                      (0xCu<<16)
#define ETH_MACWJBTR_JTO_B_0XD                                      (0xDu<<16)
#define ETH_MACWJBTR_JTO_B_0XE                                      (0xEu<<16)
#define ETH_MACWJBTR_JTO_B_0XF                                      (0xFu<<16)
#define ETH_MACWJBTR_WTO_B_0X0                                      (0x0u<<0)
#define ETH_MACWJBTR_WTO_B_0X1                                      (0x1u<<0)
#define ETH_MACWJBTR_WTO_B_0X2                                      (0x2u<<0)
#define ETH_MACWJBTR_WTO_B_0X3                                      (0x3u<<0)
#define ETH_MACWJBTR_WTO_B_0XC                                      (0xCu<<0)
#define ETH_MACWJBTR_WTO_B_0XD                                      (0xDu<<0)
#define ETH_MACWJBTR_WTO_B_0XE                                      (0xEu<<0)
#define ETH_MACWJBTR_WTO_B_0XF                                      (0xFu<<0)

// MACHT0R Configuration

#define ETH_MACHT0R_HT31T0                                          (0xFFFFFFFFu<<0)
#define ETH_MACHT0R_HT31T0_0                                        (0x1u<<0)

// MACHT1R Configuration

#define ETH_MACHT1R_HT63T32                                         (0xFFFFFFFFu<<0)
#define ETH_MACHT1R_HT63T32_0                                       (0x1u<<0)

// MACVTCR Configuration

#define ETH_MACVTCR_EIVLRXS                                         (0x1u<<31)
#define ETH_MACVTCR_EIVLS                                           (0x3u<<28)
#define ETH_MACVTCR_EIVLS_0                                         (0x1u<<28)
#define ETH_MACVTCR_ERIVLT                                          (0x1u<<27)
#define ETH_MACVTCR_EDVLP                                           (0x1u<<26)
#define ETH_MACVTCR_VTHM                                            (0x1u<<25)
#define ETH_MACVTCR_EVLRXS                                          (0x1u<<24)
#define ETH_MACVTCR_EVLS                                            (0x3u<<21)
#define ETH_MACVTCR_EVLS_0                                          (0x1u<<21)
#define ETH_MACVTCR_DOVLTC                                          (0x1u<<20)
#define ETH_MACVTCR_ERSVLM                                          (0x1u<<19)
#define ETH_MACVTCR_ESVL                                            (0x1u<<18)
#define ETH_MACVTCR_VTIM                                            (0x1u<<17)
#define ETH_MACVTCR_ETV                                             (0x1u<<16)
#define ETH_MACVTCR_OFS                                             (0x3u<<2)
#define ETH_MACVTCR_OFS_0                                           (0x1u<<2)
#define ETH_MACVTCR_CT                                              (0x1u<<1)
#define ETH_MACVTCR_OB                                              (0x1u<<0)

#define ETH_MACVTCR_EIVLS_B_0X0                                     (0x0u<<28)
#define ETH_MACVTCR_EIVLS_B_0X1                                     (0x1u<<28)
#define ETH_MACVTCR_EIVLS_B_0X2                                     (0x2u<<28)
#define ETH_MACVTCR_EIVLS_B_0X3                                     (0x3u<<28)
#define ETH_MACVTCR_EVLS_B_0X0                                      (0x0u<<21)
#define ETH_MACVTCR_EVLS_B_0X1                                      (0x1u<<21)
#define ETH_MACVTCR_EVLS_B_0X2                                      (0x2u<<21)
#define ETH_MACVTCR_EVLS_B_0X3                                      (0x3u<<21)
#define ETH_MACVTCR_OFS_B_0X0                                       (0x0u<<2)
#define ETH_MACVTCR_OFS_B_0X1                                       (0x1u<<2)
#define ETH_MACVTCR_OFS_B_0X2                                       (0x2u<<2)
#define ETH_MACVTCR_OFS_B_0X3                                       (0x3u<<2)

// MACVTDR Configuration

#define ETH_MACVTDR_DMACHN                                          (0x1u<<25)
#define ETH_MACVTDR_DMACHEN                                         (0x1u<<24)
#define ETH_MACVTDR_ERIVLT                                          (0x1u<<20)
#define ETH_MACVTDR_ERSVLM                                          (0x1u<<19)
#define ETH_MACVTDR_DOVLTC                                          (0x1u<<18)
#define ETH_MACVTDR_ETV                                             (0x1u<<17)
#define ETH_MACVTDR_VEN                                             (0x1u<<16)
#define ETH_MACVTDR_VID                                             (0xFFFFu<<0)
#define ETH_MACVTDR_VID_0                                           (0x1u<<0)

#define ETH_MACVTDR_ETV_B_0X0                                       (0x0u<<17)
#define ETH_MACVTDR_ETV_B_0X1                                       (0x1u<<17)

// MACVHTR Configuration

#define ETH_MACVHTR_VLHT                                            (0xFFFFu<<0)
#define ETH_MACVHTR_VLHT_0                                          (0x1u<<0)

// MACVIR Configuration

#define ETH_MACVIR_BUSY                                             (0x1u<<31)
#define ETH_MACVIR_RDWR                                             (0x1u<<30)
#define ETH_MACVIR_ADDR1                                            (0x1u<<25)
#define ETH_MACVIR_ADDR0                                            (0x1u<<24)
#define ETH_MACVIR_CBTI                                             (0x1u<<21)
#define ETH_MACVIR_VLTI                                             (0x1u<<20)
#define ETH_MACVIR_CSVL                                             (0x1u<<19)
#define ETH_MACVIR_VLP                                              (0x1u<<18)
#define ETH_MACVIR_VLC                                              (0x3u<<16)
#define ETH_MACVIR_VLC_0                                            (0x1u<<16)
#define ETH_MACVIR_VLT                                              (0xFFFFu<<0)
#define ETH_MACVIR_VLT_0                                            (0x1u<<0)

#define ETH_MACVIR_ADDR1_B_0X0                                      (0x0u<<25)
#define ETH_MACVIR_ADDR1_B_0X1                                      (0x1u<<25)
#define ETH_MACVIR_ADDR0_B_0X0                                      (0x0u<<24)
#define ETH_MACVIR_ADDR0_B_0X1                                      (0x1u<<24)
#define ETH_MACVIR_CSVL_B_0X0                                       (0x0u<<19)
#define ETH_MACVIR_CSVL_B_0X1                                       (0x1u<<19)
#define ETH_MACVIR_VLC_B_0X0                                        (0x0u<<16)
#define ETH_MACVIR_VLC_B_0X1                                        (0x1u<<16)
#define ETH_MACVIR_VLC_B_0X2                                        (0x2u<<16)
#define ETH_MACVIR_VLC_B_0X3                                        (0x3u<<16)

// MACVIR_ALTERNATE1 Configuration

#define ETH_MACVIR_ALTERNATE1_CSVL                                  (0x1u<<19)
#define ETH_MACVIR_ALTERNATE1_VLT                                   (0xFFFFu<<0)
#define ETH_MACVIR_ALTERNATE1_VLT_0                                 (0x1u<<0)

#define ETH_MACVIR_ALTERNATE1_CSVL_B_0X0                            (0x0u<<19)
#define ETH_MACVIR_ALTERNATE1_CSVL_B_0X1                            (0x1u<<19)

// MACIVIR Configuration

#define ETH_MACIVIR_VLTI                                            (0x1u<<20)
#define ETH_MACIVIR_CSVL                                            (0x1u<<19)
#define ETH_MACIVIR_VLP                                             (0x1u<<18)
#define ETH_MACIVIR_VLC                                             (0x3u<<16)
#define ETH_MACIVIR_VLC_0                                           (0x1u<<16)
#define ETH_MACIVIR_VLT                                             (0xFFFFu<<0)
#define ETH_MACIVIR_VLT_0                                           (0x1u<<0)

#define ETH_MACIVIR_CSVL_B_0X0                                      (0x0u<<19)
#define ETH_MACIVIR_CSVL_B_0X1                                      (0x1u<<19)
#define ETH_MACIVIR_VLC_B_0X0                                       (0x0u<<16)
#define ETH_MACIVIR_VLC_B_0X1                                       (0x1u<<16)
#define ETH_MACIVIR_VLC_B_0X2                                       (0x2u<<16)
#define ETH_MACIVIR_VLC_B_0X3                                       (0x3u<<16)

// MACQ0TXFCR Configuration

#define ETH_MACQ0TXFCR_PT                                           (0xFFFFu<<16)
#define ETH_MACQ0TXFCR_PT_0                                         (0x1u<<16)
#define ETH_MACQ0TXFCR_DZPQ                                         (0x1u<<7)
#define ETH_MACQ0TXFCR_PLT                                          (0x7u<<4)
#define ETH_MACQ0TXFCR_PLT_0                                        (0x1u<<4)
#define ETH_MACQ0TXFCR_TFE                                          (0x1u<<1)
#define ETH_MACQ0TXFCR_FCB_BPA                                      (0x1u<<0)

#define ETH_MACQ0TXFCR_PLT_B_0X0                                    (0x0u<<4)
#define ETH_MACQ0TXFCR_PLT_B_0X1                                    (0x1u<<4)
#define ETH_MACQ0TXFCR_PLT_B_0X2                                    (0x2u<<4)
#define ETH_MACQ0TXFCR_PLT_B_0X3                                    (0x3u<<4)
#define ETH_MACQ0TXFCR_PLT_B_0X4                                    (0x4u<<4)
#define ETH_MACQ0TXFCR_PLT_B_0X5                                    (0x5u<<4)

// MACRXFCR Configuration

#define ETH_MACRXFCR_UP                                             (0x1u<<1)
#define ETH_MACRXFCR_RFE                                            (0x1u<<0)

// MACRXQCR Configuration

#define ETH_MACRXQCR_VFFQ                                           (0x1u<<17)
#define ETH_MACRXQCR_VFFQE                                          (0x1u<<16)
#define ETH_MACRXQCR_MFFQ                                           (0x1u<<9)
#define ETH_MACRXQCR_MFFQE                                          (0x1u<<8)
#define ETH_MACRXQCR_UFFQ                                           (0x1u<<1)
#define ETH_MACRXQCR_UFFQE                                          (0x1u<<0)

#define ETH_MACRXQCR_VFFQ_B_0X0                                     (0x0u<<17)
#define ETH_MACRXQCR_VFFQ_B_0X1                                     (0x1u<<17)
#define ETH_MACRXQCR_VFFQE_B_0X0                                    (0x0u<<16)
#define ETH_MACRXQCR_VFFQE_B_0X1                                    (0x1u<<16)
#define ETH_MACRXQCR_MFFQ_B_0X0                                     (0x0u<<9)
#define ETH_MACRXQCR_MFFQ_B_0X1                                     (0x1u<<9)
#define ETH_MACRXQCR_UFFQ_B_0X0                                     (0x0u<<1)
#define ETH_MACRXQCR_UFFQ_B_0X1                                     (0x1u<<1)

// MACRXQC0R Configuration

#define ETH_MACRXQC0R_RXQ1EN                                        (0x3u<<2)
#define ETH_MACRXQC0R_RXQ1EN_0                                      (0x1u<<2)
#define ETH_MACRXQC0R_RXQ0EN                                        (0x3u<<0)
#define ETH_MACRXQC0R_RXQ0EN_0                                      (0x1u<<0)

#define ETH_MACRXQC0R_RXQ1EN_B_0X0                                  (0x0u<<2)
#define ETH_MACRXQC0R_RXQ1EN_B_0X1                                  (0x1u<<2)
#define ETH_MACRXQC0R_RXQ1EN_B_0X2                                  (0x2u<<2)
#define ETH_MACRXQC0R_RXQ1EN_B_0X3                                  (0x3u<<2)
#define ETH_MACRXQC0R_RXQ0EN_B_0X0                                  (0x0u<<0)
#define ETH_MACRXQC0R_RXQ0EN_B_0X1                                  (0x1u<<0)
#define ETH_MACRXQC0R_RXQ0EN_B_0X2                                  (0x2u<<0)
#define ETH_MACRXQC0R_RXQ0EN_B_0X3                                  (0x3u<<0)

// MACRXQC1R Configuration

#define ETH_MACRXQC1R_TBRQE                                         (0x1u<<29)
#define ETH_MACRXQC1R_OMCBCQ                                        (0x1u<<28)
#define ETH_MACRXQC1R_FPRQ2                                         (0x1u<<26)
#define ETH_MACRXQC1R_FPRQ1                                         (0x1u<<25)
#define ETH_MACRXQC1R_FPRQ0                                         (0x1u<<24)
#define ETH_MACRXQC1R_TPQC                                          (0x3u<<22)
#define ETH_MACRXQC1R_TPQC_0                                        (0x1u<<22)
#define ETH_MACRXQC1R_TACPQE                                        (0x1u<<21)
#define ETH_MACRXQC1R_MCBCQEN                                       (0x1u<<20)
#define ETH_MACRXQC1R_MCBCQ                                         (0x7u<<16)
#define ETH_MACRXQC1R_MCBCQ_0                                       (0x1u<<16)
#define ETH_MACRXQC1R_UPQ                                           (0x7u<<12)
#define ETH_MACRXQC1R_UPQ_0                                         (0x1u<<12)
#define ETH_MACRXQC1R_PTPQ                                          (0x7u<<4)
#define ETH_MACRXQC1R_PTPQ_0                                        (0x1u<<4)
#define ETH_MACRXQC1R_AVCPQ2                                        (0x1u<<2)
#define ETH_MACRXQC1R_AVCPQ1                                        (0x1u<<1)
#define ETH_MACRXQC1R_AVCPQ0                                        (0x1u<<0)

#define ETH_MACRXQC1R_OMCBCQ_B_0X1                                  (0x1u<<28)
#define ETH_MACRXQC1R_OMCBCQ_B_0X0                                  (0x0u<<28)
#define ETH_MACRXQC1R_FPRQ2_B_0X0                                   (0x0u<<26)
#define ETH_MACRXQC1R_FPRQ2_B_0X1                                   (0x1u<<26)
#define ETH_MACRXQC1R_FPRQ1_B_0X0                                   (0x0u<<25)
#define ETH_MACRXQC1R_FPRQ1_B_0X1                                   (0x1u<<25)
#define ETH_MACRXQC1R_FPRQ0_B_0X0                                   (0x0u<<24)
#define ETH_MACRXQC1R_FPRQ0_B_0X1                                   (0x1u<<24)
#define ETH_MACRXQC1R_TPQC_B_0X0                                    (0x0u<<22)
#define ETH_MACRXQC1R_TPQC_B_0X1                                    (0x1u<<22)
#define ETH_MACRXQC1R_TPQC_B_0X2                                    (0x2u<<22)
#define ETH_MACRXQC1R_MCBCQ_B_0X0                                   (0x0u<<16)
#define ETH_MACRXQC1R_MCBCQ_B_0X1                                   (0x1u<<16)
#define ETH_MACRXQC1R_UPQ_B_0X0                                     (0x0u<<12)
#define ETH_MACRXQC1R_UPQ_B_0X1                                     (0x1u<<12)
#define ETH_MACRXQC1R_PTPQ_B_0X0                                    (0x0u<<4)
#define ETH_MACRXQC1R_PTPQ_B_0X1                                    (0x1u<<4)
#define ETH_MACRXQC1R_AVCPQ2_B_0X0                                  (0x0u<<2)
#define ETH_MACRXQC1R_AVCPQ2_B_0X1                                  (0x1u<<2)
#define ETH_MACRXQC1R_AVCPQ1_B_0X0                                  (0x0u<<1)
#define ETH_MACRXQC1R_AVCPQ1_B_0X1                                  (0x1u<<1)
#define ETH_MACRXQC1R_AVCPQ0_B_0X0                                  (0x0u<<0)
#define ETH_MACRXQC1R_AVCPQ0_B_0X1                                  (0x1u<<0)

// MACRXQC2R Configuration

#define ETH_MACRXQC2R_PSRQ1                                         (0xFFu<<8)
#define ETH_MACRXQC2R_PSRQ1_0                                       (0x1u<<8)
#define ETH_MACRXQC2R_PSRQ0                                         (0xFFu<<0)
#define ETH_MACRXQC2R_PSRQ0_0                                       (0x1u<<0)

// MACISR Configuration

#define ETH_MACISR_B10T1SIS                                         (0x1u<<24)
#define ETH_MACISR_MFRIS                                            (0x1u<<20)
#define ETH_MACISR_MFTIS                                            (0x1u<<19)
#define ETH_MACISR_MDIOIS                                           (0x1u<<18)
#define ETH_MACISR_FPEIS                                            (0x1u<<17)
#define ETH_MACISR_RXSTSIS                                          (0x1u<<14)
#define ETH_MACISR_TXSTSIS                                          (0x1u<<13)
#define ETH_MACISR_TSIS                                             (0x1u<<12)
#define ETH_MACISR_MMCTXIS                                          (0x1u<<10)
#define ETH_MACISR_MMCRXIS                                          (0x1u<<9)
#define ETH_MACISR_MMCIS                                            (0x1u<<8)
#define ETH_MACISR_LPIIS                                            (0x1u<<5)
#define ETH_MACISR_PMTIS                                            (0x1u<<4)
#define ETH_MACISR_PHYIS                                            (0x1u<<3)
#define ETH_MACISR_RGSMIIIS                                         (0x1u<<0)

#define ETH_MACISR_B10T1SIS_B_0X0                                   (0x0u<<24)
#define ETH_MACISR_B10T1SIS_B_0X1                                   (0x1u<<24)

// MACIER Configuration

#define ETH_MACIER_B10T1SIE                                         (0x1u<<19)
#define ETH_MACIER_MDIOIE                                           (0x1u<<18)
#define ETH_MACIER_FPEIE                                            (0x1u<<17)
#define ETH_MACIER_RXSTSIE                                          (0x1u<<14)
#define ETH_MACIER_TXSTSIE                                          (0x1u<<13)
#define ETH_MACIER_TSIE                                             (0x1u<<12)
#define ETH_MACIER_LPIIE                                            (0x1u<<5)
#define ETH_MACIER_PMTIE                                            (0x1u<<4)
#define ETH_MACIER_PHYIE                                            (0x1u<<3)
#define ETH_MACIER_RGSMIIIE                                         (0x1u<<0)

#define ETH_MACIER_B10T1SIE_B_0X0                                   (0x0u<<19)
#define ETH_MACIER_B10T1SIE_B_0X1                                   (0x1u<<19)

// MACRXTXSR Configuration

#define ETH_MACRXTXSR_RWT                                           (0x1u<<8)
#define ETH_MACRXTXSR_EXCOL                                         (0x1u<<5)
#define ETH_MACRXTXSR_LCOL                                          (0x1u<<4)
#define ETH_MACRXTXSR_EXDEF                                         (0x1u<<3)
#define ETH_MACRXTXSR_LCARR                                         (0x1u<<2)
#define ETH_MACRXTXSR_NCARR                                         (0x1u<<1)
#define ETH_MACRXTXSR_TJT                                           (0x1u<<0)

// MACPCSR Configuration

#define ETH_MACPCSR_RWKFILTRST                                      (0x1u<<31)
#define ETH_MACPCSR_RWKPTR                                          (0x1Fu<<24)
#define ETH_MACPCSR_RWKPTR_0                                        (0x1u<<24)
#define ETH_MACPCSR_RWKPFE                                          (0x1u<<10)
#define ETH_MACPCSR_GLBLUCAST                                       (0x1u<<9)
#define ETH_MACPCSR_RWKPRCVD                                        (0x1u<<6)
#define ETH_MACPCSR_MGKPRCVD                                        (0x1u<<5)
#define ETH_MACPCSR_RWKPKTEN                                        (0x1u<<2)
#define ETH_MACPCSR_MGKPKTEN                                        (0x1u<<1)
#define ETH_MACPCSR_PWRDWN                                          (0x1u<<0)

// MACRWKPFR Configuration

#define ETH_MACRWKPFR_MACRWKPFR                                     (0xFFFFFFFFu<<0)
#define ETH_MACRWKPFR_MACRWKPFR_0                                   (0x1u<<0)

// MACLCSR Configuration

#define ETH_MACLCSR_LPITCSE                                         (0x1u<<21)
#define ETH_MACLCSR_LPITE                                           (0x1u<<20)
#define ETH_MACLCSR_LPITXA                                          (0x1u<<19)
#define ETH_MACLCSR_PLSEN                                           (0x1u<<18)
#define ETH_MACLCSR_PLS                                             (0x1u<<17)
#define ETH_MACLCSR_LPIEN                                           (0x1u<<16)
#define ETH_MACLCSR_RLPIST                                          (0x1u<<9)
#define ETH_MACLCSR_TLPIST                                          (0x1u<<8)
#define ETH_MACLCSR_RLPIEX                                          (0x1u<<3)
#define ETH_MACLCSR_RLPIEN                                          (0x1u<<2)
#define ETH_MACLCSR_TLPIEX                                          (0x1u<<1)
#define ETH_MACLCSR_TLPIEN                                          (0x1u<<0)

// MACLTCR Configuration

#define ETH_MACLTCR_LST                                             (0x3FFu<<16)
#define ETH_MACLTCR_LST_0                                           (0x1u<<16)
#define ETH_MACLTCR_TWT                                             (0xFFFFu<<0)
#define ETH_MACLTCR_TWT_0                                           (0x1u<<0)

// MACLETR Configuration

#define ETH_MACLETR_LPIET                                           (0xFFFFFu<<0)
#define ETH_MACLETR_LPIET_0                                         (0x1u<<0)

// MAC1USTCR Configuration

#define ETH_MAC1USTCR_TIC_1US_CNTR                                  (0xFFFu<<0)
#define ETH_MAC1USTCR_TIC_1US_CNTR_0                                (0x1u<<0)

// MACPHYCSR Configuration

#define ETH_MACPHYCSR_LNKSTS                                        (0x1u<<19)
#define ETH_MACPHYCSR_LNKSPEED                                      (0x3u<<17)
#define ETH_MACPHYCSR_LNKSPEED_0                                    (0x1u<<17)
#define ETH_MACPHYCSR_LNKMOD                                        (0x1u<<16)
#define ETH_MACPHYCSR_LUD                                           (0x1u<<1)
#define ETH_MACPHYCSR_TC                                            (0x1u<<0)

#define ETH_MACPHYCSR_LNKSTS_B_0X0                                  (0x0u<<19)
#define ETH_MACPHYCSR_LNKSTS_B_0X1                                  (0x1u<<19)
#define ETH_MACPHYCSR_LNKSPEED_B_0X0                                (0x0u<<17)
#define ETH_MACPHYCSR_LNKSPEED_B_0X1                                (0x1u<<17)
#define ETH_MACPHYCSR_LNKSPEED_B_0X2                                (0x2u<<17)
#define ETH_MACPHYCSR_LNKSPEED_B_0X3                                (0x3u<<17)
#define ETH_MACPHYCSR_LNKMOD_B_0X0                                  (0x0u<<16)
#define ETH_MACPHYCSR_LNKMOD_B_0X1                                  (0x1u<<16)
#define ETH_MACPHYCSR_LUD_B_0X0                                     (0x0u<<1)
#define ETH_MACPHYCSR_LUD_B_0X1                                     (0x1u<<1)

// MACVR Configuration

#define ETH_MACVR_USERVER                                           (0xFFu<<8)
#define ETH_MACVR_USERVER_0                                         (0x1u<<8)
#define ETH_MACVR_SNPSVER                                           (0xFFu<<0)
#define ETH_MACVR_SNPSVER_0                                         (0x1u<<0)

// MACDR Configuration

#define ETH_MACDR_TFCSTS                                            (0x3u<<17)
#define ETH_MACDR_TFCSTS_0                                          (0x1u<<17)
#define ETH_MACDR_TPESTS                                            (0x1u<<16)
#define ETH_MACDR_RFCFCSTS                                          (0x3u<<1)
#define ETH_MACDR_RFCFCSTS_0                                        (0x1u<<1)
#define ETH_MACDR_RPESTS                                            (0x1u<<0)

#define ETH_MACDR_TFCSTS_B_0X0                                      (0x0u<<17)
#define ETH_MACDR_TFCSTS_B_0X1                                      (0x1u<<17)
#define ETH_MACDR_TFCSTS_B_0X2                                      (0x2u<<17)
#define ETH_MACDR_TFCSTS_B_0X3                                      (0x3u<<17)

// MACHWF0R Configuration

#define ETH_MACHWF0R_ACTPHYSEL                                      (0x7u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_0                                    (0x1u<<28)
#define ETH_MACHWF0R_SAVLANINS                                      (0x1u<<27)
#define ETH_MACHWF0R_TSSTSSEL                                       (0x3u<<25)
#define ETH_MACHWF0R_TSSTSSEL_0                                     (0x1u<<25)
#define ETH_MACHWF0R_MACADR64SEL                                    (0x1u<<24)
#define ETH_MACHWF0R_MACADR32SEL                                    (0x1u<<23)
#define ETH_MACHWF0R_ADDMACADRSEL                                   (0x1Fu<<18)
#define ETH_MACHWF0R_ADDMACADRSEL_0                                 (0x1u<<18)
#define ETH_MACHWF0R_RXCOESEL                                       (0x1u<<16)
#define ETH_MACHWF0R_TXCOESEL                                       (0x1u<<14)
#define ETH_MACHWF0R_EEESEL                                         (0x1u<<13)
#define ETH_MACHWF0R_TSSEL                                          (0x1u<<12)
#define ETH_MACHWF0R_ARPOFFSEL                                      (0x1u<<9)
#define ETH_MACHWF0R_MMCSEL                                         (0x1u<<8)
#define ETH_MACHWF0R_MGKSEL                                         (0x1u<<7)
#define ETH_MACHWF0R_RWKSEL                                         (0x1u<<6)
#define ETH_MACHWF0R_SMASEL                                         (0x1u<<5)
#define ETH_MACHWF0R_VLHASH                                         (0x1u<<4)
#define ETH_MACHWF0R_PCSSEL                                         (0x1u<<3)
#define ETH_MACHWF0R_HDSEL                                          (0x1u<<2)
#define ETH_MACHWF0R_GMIISEL                                        (0x1u<<1)
#define ETH_MACHWF0R_MIISEL                                         (0x1u<<0)

#define ETH_MACHWF0R_ACTPHYSEL_B_0X0                                (0x0u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X1                                (0x1u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X2                                (0x2u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X3                                (0x3u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X4                                (0x4u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X5                                (0x5u<<28)
#define ETH_MACHWF0R_ACTPHYSEL_B_0X6                                (0x6u<<28)
#define ETH_MACHWF0R_TSSTSSEL_B_0X1                                 (0x1u<<25)
#define ETH_MACHWF0R_TSSTSSEL_B_0X2                                 (0x2u<<25)
#define ETH_MACHWF0R_TSSTSSEL_B_0X3                                 (0x3u<<25)
#define ETH_MACHWF0R_TSSTSSEL_B_0X0                                 (0x0u<<25)

// MACHWF1R Configuration

#define ETH_MACHWF1R_L3L4FNUM                                       (0xFu<<27)
#define ETH_MACHWF1R_L3L4FNUM_0                                     (0x1u<<27)
#define ETH_MACHWF1R_HASHTBLSZ                                      (0x3u<<24)
#define ETH_MACHWF1R_HASHTBLSZ_0                                    (0x1u<<24)
#define ETH_MACHWF1R_POUOST                                         (0x1u<<23)
#define ETH_MACHWF1R_RAVSEL                                         (0x1u<<21)
#define ETH_MACHWF1R_AVSEL                                          (0x1u<<20)
#define ETH_MACHWF1R_DBGMEMA                                        (0x1u<<19)
#define ETH_MACHWF1R_TSOEN                                          (0x1u<<18)
#define ETH_MACHWF1R_SPHEN                                          (0x1u<<17)
#define ETH_MACHWF1R_DCBEN                                          (0x1u<<16)
#define ETH_MACHWF1R_ADDR64                                         (0x3u<<14)
#define ETH_MACHWF1R_ADDR64_0                                       (0x1u<<14)
#define ETH_MACHWF1R_ADVTHWORD                                      (0x1u<<13)
#define ETH_MACHWF1R_PTOEN                                          (0x1u<<12)
#define ETH_MACHWF1R_OSTEN                                          (0x1u<<11)
#define ETH_MACHWF1R_TXFIFOSIZE                                     (0x1Fu<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_0                                   (0x1u<<6)
#define ETH_MACHWF1R_SPRAM                                          (0x1u<<5)
#define ETH_MACHWF1R_RXFIFOSIZE                                     (0x1Fu<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_0                                   (0x1u<<0)

#define ETH_MACHWF1R_L3L4FNUM_B_0X0                                 (0x0u<<27)
#define ETH_MACHWF1R_L3L4FNUM_B_0X1                                 (0x1u<<27)
#define ETH_MACHWF1R_L3L4FNUM_B_0X2                                 (0x2u<<27)
#define ETH_MACHWF1R_L3L4FNUM_B_0X8                                 (0x8u<<27)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X0                                (0x0u<<24)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X1                                (0x1u<<24)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X2                                (0x2u<<24)
#define ETH_MACHWF1R_HASHTBLSZ_B_0X3                                (0x3u<<24)
#define ETH_MACHWF1R_ADDR64_B_0X0                                   (0x0u<<14)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X0                               (0x0u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X1                               (0x1u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X2                               (0x2u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X3                               (0x3u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X4                               (0x4u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X5                               (0x5u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X6                               (0x6u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X7                               (0x7u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X8                               (0x8u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0X9                               (0x9u<<6)
#define ETH_MACHWF1R_TXFIFOSIZE_B_0XA                               (0xAu<<6)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X0                               (0x0u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X1                               (0x1u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X2                               (0x2u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X3                               (0x3u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X4                               (0x4u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X5                               (0x5u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X6                               (0x6u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X7                               (0x7u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X8                               (0x8u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0X9                               (0x9u<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0XA                               (0xAu<<0)
#define ETH_MACHWF1R_RXFIFOSIZE_B_0XB                               (0xBu<<0)

// MACHWF2R Configuration

#define ETH_MACHWF2R_AUXSNAPNUM                                     (0x7u<<28)
#define ETH_MACHWF2R_AUXSNAPNUM_0                                   (0x1u<<28)
#define ETH_MACHWF2R_PPSOUTNUM                                      (0x7u<<24)
#define ETH_MACHWF2R_PPSOUTNUM_0                                    (0x1u<<24)
#define ETH_MACHWF2R_TDCSZ                                          (0x3u<<22)
#define ETH_MACHWF2R_TDCSZ_0                                        (0x1u<<22)
#define ETH_MACHWF2R_TXCHCNT                                        (0xFu<<18)
#define ETH_MACHWF2R_TXCHCNT_0                                      (0x1u<<18)
#define ETH_MACHWF2R_RDCSZ                                          (0x3u<<16)
#define ETH_MACHWF2R_RDCSZ_0                                        (0x1u<<16)
#define ETH_MACHWF2R_RXCHCNT                                        (0xFu<<12)
#define ETH_MACHWF2R_RXCHCNT_0                                      (0x1u<<12)
#define ETH_MACHWF2R_TXQCNT                                         (0xFu<<6)
#define ETH_MACHWF2R_TXQCNT_0                                       (0x1u<<6)
#define ETH_MACHWF2R_RXQCNT                                         (0xFu<<0)
#define ETH_MACHWF2R_RXQCNT_0                                       (0x1u<<0)

#define ETH_MACHWF2R_AUXSNAPNUM_B_0X0                               (0x0u<<28)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X1                               (0x1u<<28)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X2                               (0x2u<<28)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X3                               (0x3u<<28)
#define ETH_MACHWF2R_AUXSNAPNUM_B_0X4                               (0x4u<<28)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X0                                (0x0u<<24)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X1                                (0x1u<<24)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X2                                (0x2u<<24)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X3                                (0x3u<<24)
#define ETH_MACHWF2R_PPSOUTNUM_B_0X4                                (0x4u<<24)
#define ETH_MACHWF2R_TDCSZ_B_0X0                                    (0x0u<<22)
#define ETH_MACHWF2R_TDCSZ_B_0X1                                    (0x1u<<22)
#define ETH_MACHWF2R_TDCSZ_B_0X2                                    (0x2u<<22)
#define ETH_MACHWF2R_TDCSZ_B_0X3                                    (0x3u<<22)
#define ETH_MACHWF2R_TXCHCNT_B_0X0                                  (0x0u<<18)
#define ETH_MACHWF2R_TXCHCNT_B_0X1                                  (0x1u<<18)
#define ETH_MACHWF2R_TXCHCNT_B_0X7                                  (0x7u<<18)
#define ETH_MACHWF2R_RDCSZ_B_0X0                                    (0x0u<<16)
#define ETH_MACHWF2R_RDCSZ_B_0X1                                    (0x1u<<16)
#define ETH_MACHWF2R_RDCSZ_B_0X2                                    (0x2u<<16)
#define ETH_MACHWF2R_RDCSZ_B_0X3                                    (0x3u<<16)
#define ETH_MACHWF2R_RXCHCNT_B_0X0                                  (0x0u<<12)
#define ETH_MACHWF2R_RXCHCNT_B_0X1                                  (0x1u<<12)
#define ETH_MACHWF2R_RXCHCNT_B_0X7                                  (0x7u<<12)
#define ETH_MACHWF2R_TXQCNT_B_0X0                                   (0x0u<<6)
#define ETH_MACHWF2R_TXQCNT_B_0X1                                   (0x1u<<6)
#define ETH_MACHWF2R_TXQCNT_B_0X7                                   (0x7u<<6)
#define ETH_MACHWF2R_RXQCNT_B_0X0                                   (0x0u<<0)
#define ETH_MACHWF2R_RXQCNT_B_0X1                                   (0x1u<<0)
#define ETH_MACHWF2R_RXQCNT_B_0X7                                   (0x7u<<0)

// MACHWF3R Configuration

#define ETH_MACHWF3R_ASP                                            (0x3u<<28)
#define ETH_MACHWF3R_ASP_0                                          (0x1u<<28)
#define ETH_MACHWF3R_TBSSEL                                         (0x1u<<27)
#define ETH_MACHWF3R_FPESEL                                         (0x1u<<26)
#define ETH_MACHWF3R_ESTWID                                         (0x3u<<20)
#define ETH_MACHWF3R_ESTWID_0                                       (0x1u<<20)
#define ETH_MACHWF3R_ESTDEP                                         (0x7u<<17)
#define ETH_MACHWF3R_ESTDEP_0                                       (0x1u<<17)
#define ETH_MACHWF3R_ESTSEL                                         (0x1u<<16)
#define ETH_MACHWF3R_FRPES                                          (0x3u<<13)
#define ETH_MACHWF3R_FRPES_0                                        (0x1u<<13)
#define ETH_MACHWF3R_FRPBS                                          (0x3u<<11)
#define ETH_MACHWF3R_FRPBS_0                                        (0x1u<<11)
#define ETH_MACHWF3R_FRPSEL                                         (0x1u<<10)
#define ETH_MACHWF3R_PDUPSEL                                        (0x1u<<9)
#define ETH_MACHWF3R_DVLAN                                          (0x1u<<5)
#define ETH_MACHWF3R_CBTISEL                                        (0x1u<<4)
#define ETH_MACHWF3R_NRVF                                           (0x7u<<0)
#define ETH_MACHWF3R_NRVF_0                                         (0x1u<<0)

#define ETH_MACHWF3R_ASP_B_0X0                                      (0x0u<<28)
#define ETH_MACHWF3R_ASP_B_0X1                                      (0x1u<<28)
#define ETH_MACHWF3R_ASP_B_0X2                                      (0x2u<<28)
#define ETH_MACHWF3R_ASP_B_0X3                                      (0x3u<<28)
#define ETH_MACHWF3R_ESTWID_B_0X0                                   (0x0u<<20)
#define ETH_MACHWF3R_ESTWID_B_0X1                                   (0x1u<<20)
#define ETH_MACHWF3R_ESTWID_B_0X2                                   (0x2u<<20)
#define ETH_MACHWF3R_ESTWID_B_0X3                                   (0x3u<<20)
#define ETH_MACHWF3R_ESTDEP_B_0X0                                   (0x0u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X1                                   (0x1u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X2                                   (0x2u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X3                                   (0x3u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X4                                   (0x4u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X5                                   (0x5u<<17)
#define ETH_MACHWF3R_ESTDEP_B_0X6                                   (0x6u<<17)
#define ETH_MACHWF3R_FRPES_B_0X0                                    (0x0u<<13)
#define ETH_MACHWF3R_FRPES_B_0X1                                    (0x1u<<13)
#define ETH_MACHWF3R_FRPES_B_0X2                                    (0x2u<<13)
#define ETH_MACHWF3R_FRPES_B_0X3                                    (0x3u<<13)
#define ETH_MACHWF3R_FRPBS_B_0X0                                    (0x0u<<11)
#define ETH_MACHWF3R_FRPBS_B_0X1                                    (0x1u<<11)
#define ETH_MACHWF3R_FRPBS_B_0X2                                    (0x2u<<11)
#define ETH_MACHWF3R_FRPBS_B_0X3                                    (0x3u<<11)
#define ETH_MACHWF3R_NRVF_B_0X0                                     (0x0u<<0)
#define ETH_MACHWF3R_NRVF_B_0X1                                     (0x1u<<0)
#define ETH_MACHWF3R_NRVF_B_0X2                                     (0x2u<<0)
#define ETH_MACHWF3R_NRVF_B_0X3                                     (0x3u<<0)
#define ETH_MACHWF3R_NRVF_B_0X4                                     (0x4u<<0)
#define ETH_MACHWF3R_NRVF_B_0X5                                     (0x5u<<0)

// MACMDIOAR Configuration

#define ETH_MACMDIOAR_PSE                                           (0x1u<<27)
#define ETH_MACMDIOAR_BTB                                           (0x1u<<26)
#define ETH_MACMDIOAR_PA                                            (0x1Fu<<21)
#define ETH_MACMDIOAR_PA_0                                          (0x1u<<21)
#define ETH_MACMDIOAR_RDA                                           (0x1Fu<<16)
#define ETH_MACMDIOAR_RDA_0                                         (0x1u<<16)
#define ETH_MACMDIOAR_NTC                                           (0x7u<<12)
#define ETH_MACMDIOAR_NTC_0                                         (0x1u<<12)
#define ETH_MACMDIOAR_CR                                            (0xFu<<8)
#define ETH_MACMDIOAR_CR_0                                          (0x1u<<8)
#define ETH_MACMDIOAR_SKAP                                          (0x1u<<4)
#define ETH_MACMDIOAR_GOC                                           (0x3u<<2)
#define ETH_MACMDIOAR_GOC_0                                         (0x1u<<2)
#define ETH_MACMDIOAR_C45E                                          (0x1u<<1)
#define ETH_MACMDIOAR_GB                                            (0x1u<<0)

#define ETH_MACMDIOAR_CR_B_0X0                                      (0x0u<<8)
#define ETH_MACMDIOAR_CR_B_0X1                                      (0x1u<<8)
#define ETH_MACMDIOAR_CR_B_0X2                                      (0x2u<<8)
#define ETH_MACMDIOAR_CR_B_0X3                                      (0x3u<<8)
#define ETH_MACMDIOAR_CR_B_0X4                                      (0x4u<<8)
#define ETH_MACMDIOAR_CR_B_0X5                                      (0x5u<<8)
#define ETH_MACMDIOAR_CR_B_0X6                                      (0x6u<<8)
#define ETH_MACMDIOAR_CR_B_0X7                                      (0x7u<<8)
#define ETH_MACMDIOAR_CR_B_0X8                                      (0x8u<<8)
#define ETH_MACMDIOAR_CR_B_0X9                                      (0x9u<<8)
#define ETH_MACMDIOAR_CR_B_0XA                                      (0xAu<<8)
#define ETH_MACMDIOAR_CR_B_0XB                                      (0xBu<<8)
#define ETH_MACMDIOAR_CR_B_0XC                                      (0xCu<<8)
#define ETH_MACMDIOAR_CR_B_0XD                                      (0xDu<<8)
#define ETH_MACMDIOAR_CR_B_0XE                                      (0xEu<<8)
#define ETH_MACMDIOAR_CR_B_0XF                                      (0xFu<<8)
#define ETH_MACMDIOAR_GOC_B_0X0                                     (0x0u<<2)
#define ETH_MACMDIOAR_GOC_B_0X1                                     (0x1u<<2)
#define ETH_MACMDIOAR_GOC_B_0X2                                     (0x2u<<2)
#define ETH_MACMDIOAR_GOC_B_0X3                                     (0x3u<<2)

// MACMDIODR Configuration

#define ETH_MACMDIODR_RA                                            (0xFFFFu<<16)
#define ETH_MACMDIODR_RA_0                                          (0x1u<<16)
#define ETH_MACMDIODR_GD                                            (0xFFFFu<<0)
#define ETH_MACMDIODR_GD_0                                          (0x1u<<0)

// B10T1S_PLCA_CR Configuration

#define ETH_B10T1S_PLCA_CR_PLCA_R                                   (0x1u<<15)
#define ETH_B10T1S_PLCA_CR_PLCA_EN                                  (0x1u<<14)
#define ETH_B10T1S_PLCA_CR_MAX_BC                                   (0xFFu<<0)
#define ETH_B10T1S_PLCA_CR_MAX_BC_0                                 (0x1u<<0)

#define ETH_B10T1S_PLCA_CR_PLCA_R_B_0X0                             (0x0u<<15)
#define ETH_B10T1S_PLCA_CR_PLCA_R_B_0X1                             (0x1u<<15)
#define ETH_B10T1S_PLCA_CR_PLCA_EN_B_0X0                            (0x0u<<14)
#define ETH_B10T1S_PLCA_CR_PLCA_EN_B_0X1                            (0x1u<<14)

// B10T1S_PLCA_NODECR Configuration

#define ETH_B10T1S_PLCA_NODECR_LNI                                  (0xFFu<<8)
#define ETH_B10T1S_PLCA_NODECR_LNI_0                                (0x1u<<8)
#define ETH_B10T1S_PLCA_NODECR_PNC                                  (0xFFu<<0)
#define ETH_B10T1S_PLCA_NODECR_PNC_0                                (0x1u<<0)

// 10BT1S_PLCA_TMR Configuration

#define ETH_10BT1S_PLCA_TMR_BT                                      (0xFFu<<8)
#define ETH_10BT1S_PLCA_TMR_BT_0                                    (0x1u<<8)
#define ETH_10BT1S_PLCA_TMR_TOT                                     (0xFFu<<0)
#define ETH_10BT1S_PLCA_TMR_TOT_0                                   (0x1u<<0)

// B10T1S_PLCA_SR Configuration

#define ETH_B10T1S_PLCA_SR_RXINTO                                   (0x1u<<3)
#define ETH_B10T1S_PLCA_SR_UNEXPB                                   (0x1u<<2)
#define ETH_B10T1S_PLCA_SR_BCNBFTO                                  (0x1u<<1)
#define ETH_B10T1S_PLCA_SR_PS                                       (0x1u<<0)

#define ETH_B10T1S_PLCA_SR_RXINTO_B_0X0                             (0x0u<<3)
#define ETH_B10T1S_PLCA_SR_RXINTO_B_0X1                             (0x1u<<3)
#define ETH_B10T1S_PLCA_SR_UNEXPB_B_0X0                             (0x0u<<2)
#define ETH_B10T1S_PLCA_SR_UNEXPB_B_0X1                             (0x1u<<2)
#define ETH_B10T1S_PLCA_SR_BCNBFTO_B_0X0                            (0x0u<<1)
#define ETH_B10T1S_PLCA_SR_BCNBFTO_B_0X1                            (0x1u<<1)
#define ETH_B10T1S_PLCA_SR_PS_B_0X1                                 (0x1u<<0)
#define ETH_B10T1S_PLCA_SR_PS_B_0X0                                 (0x0u<<0)

// B10T1S_PCS_CR Configuration

#define ETH_B10T1S_PCS_CR_PCS_R                                     (0x1u<<15)
#define ETH_B10T1S_PCS_CR_LB                                        (0x1u<<14)
#define ETH_B10T1S_PCS_CR_PCS_COL                                   (0x1u<<9)
#define ETH_B10T1S_PCS_CR_DM                                        (0x1u<<8)

#define ETH_B10T1S_PCS_CR_PCS_R_B_0X0                               (0x0u<<15)
#define ETH_B10T1S_PCS_CR_PCS_R_B_0X1                               (0x1u<<15)
#define ETH_B10T1S_PCS_CR_LB_B_0X0                                  (0x0u<<14)
#define ETH_B10T1S_PCS_CR_LB_B_0X1                                  (0x1u<<14)
#define ETH_B10T1S_PCS_CR_PCS_COL_B_0X0                             (0x0u<<9)
#define ETH_B10T1S_PCS_CR_PCS_COL_B_0X1                             (0x1u<<9)
#define ETH_B10T1S_PCS_CR_DM_B_0X0                                  (0x0u<<8)
#define ETH_B10T1S_PCS_CR_DM_B_0X1                                  (0x1u<<8)

// B10T1S_PCS_SR Configuration

#define ETH_B10T1S_PCS_SR_FAULT                                     (0x1u<<7)

#define ETH_B10T1S_PCS_SR_FAULT_B_0X0                               (0x0u<<7)
#define ETH_B10T1S_PCS_SR_FAULT_B_0X1                               (0x1u<<7)

// B10T1S_PCS_DIAG1 Configuration

#define ETH_B10T1S_PCS_DIAG1_RJC                                    (0xFFFFu<<0)
#define ETH_B10T1S_PCS_DIAG1_RJC_0                                  (0x1u<<0)

// B10T1S_PCS_DIAG2 Configuration

#define ETH_B10T1S_PCS_DIAG2_CTC                                    (0xFFFFu<<0)
#define ETH_B10T1S_PCS_DIAG2_CTC_0                                  (0x1u<<0)

// B10T1S_PCS_JBTMR Configuration

#define ETH_B10T1S_PCS_JBTMR_PJT                                    (0xFFFFu<<0)
#define ETH_B10T1S_PCS_JBTMR_PJT_0                                  (0x1u<<0)

// B10T1S_PMA_EXTABLTY Configuration

#define ETH_B10T1S_PMA_EXTABLTY_T1SA                                (0x1u<<3)

#define ETH_B10T1S_PMA_EXTABLTY_T1SA_B_0X1                          (0x1u<<3)
#define ETH_B10T1S_PMA_EXTABLTY_T1SA_B_0X0                          (0x0u<<3)

// B10T1S_PMA_PMD_CR Configuration

#define ETH_B10T1S_PMA_PMD_CR_MSCV                                  (0x1u<<14)
#define ETH_B10T1S_PMA_PMD_CR_TS                                    (0xFu<<0)
#define ETH_B10T1S_PMA_PMD_CR_TS_0                                  (0x1u<<0)

#define ETH_B10T1S_PMA_PMD_CR_MSCV_B_0X1                            (0x1u<<14)
#define ETH_B10T1S_PMA_PMD_CR_MSCV_B_0X0                            (0x0u<<14)
#define ETH_B10T1S_PMA_PMD_CR_TS_B_0X3                              (0x3u<<0)

// B10T1S_PMA_CR Configuration

#define ETH_B10T1S_PMA_CR_PMA_R                                     (0x1u<<15)
#define ETH_B10T1S_PMA_CR_TD                                        (0x1u<<14)
#define ETH_B10T1S_PMA_CR_LP                                        (0x1u<<11)
#define ETH_B10T1S_PMA_CR_MM                                        (0x1u<<10)
#define ETH_B10T1S_PMA_CR_EBRTH                                     (0x1Fu<<1)
#define ETH_B10T1S_PMA_CR_EBRTH_0                                   (0x1u<<1)
#define ETH_B10T1S_PMA_CR_LB                                        (0x1u<<0)

#define ETH_B10T1S_PMA_CR_PMA_R_B_0X1                               (0x1u<<15)
#define ETH_B10T1S_PMA_CR_PMA_R_B_0X0                               (0x0u<<15)
#define ETH_B10T1S_PMA_CR_TD_B_0X1                                  (0x1u<<14)
#define ETH_B10T1S_PMA_CR_TD_B_0X0                                  (0x0u<<14)
#define ETH_B10T1S_PMA_CR_LP_B_0X1                                  (0x1u<<11)
#define ETH_B10T1S_PMA_CR_LP_B_0X0                                  (0x0u<<11)
#define ETH_B10T1S_PMA_CR_MM_B_0X0                                  (0x0u<<10)
#define ETH_B10T1S_PMA_CR_MM_B_0X1                                  (0x1u<<10)
#define ETH_B10T1S_PMA_CR_LB_B_0X0                                  (0x0u<<0)
#define ETH_B10T1S_PMA_CR_LB_B_0X1                                  (0x1u<<0)

// B10T1S_PMA_SR Configuration

#define ETH_B10T1S_PMA_SR_LBA                                       (0x1u<<13)
#define ETH_B10T1S_PMA_SR_LPA                                       (0x1u<<11)
#define ETH_B10T1S_PMA_SR_MMA                                       (0x1u<<10)
#define ETH_B10T1S_PMA_SR_RFA                                       (0x1u<<9)
#define ETH_B10T1S_PMA_SR_RFD                                       (0x1u<<1)

#define ETH_B10T1S_PMA_SR_LBA_B_0X1                                 (0x1u<<13)
#define ETH_B10T1S_PMA_SR_LBA_B_0X0                                 (0x0u<<13)
#define ETH_B10T1S_PMA_SR_LPA_B_0X1                                 (0x1u<<11)
#define ETH_B10T1S_PMA_SR_LPA_B_0X0                                 (0x0u<<11)
#define ETH_B10T1S_PMA_SR_MMA_B_0X1                                 (0x1u<<10)
#define ETH_B10T1S_PMA_SR_MMA_B_0X0                                 (0x0u<<10)
#define ETH_B10T1S_PMA_SR_RFA_B_0X1                                 (0x1u<<9)
#define ETH_B10T1S_PMA_SR_RFA_B_0X0                                 (0x0u<<9)
#define ETH_B10T1S_PMA_SR_RFD_B_0X1                                 (0x1u<<1)
#define ETH_B10T1S_PMA_SR_RFD_B_0X0                                 (0x0u<<1)

// B10T1S_PMA_TMCR Configuration

#define ETH_B10T1S_PMA_TMCR_TMC                                     (0x7u<<13)
#define ETH_B10T1S_PMA_TMCR_TMC_0                                   (0x1u<<13)

#define ETH_B10T1S_PMA_TMCR_TMC_B_0X0                               (0x0u<<13)
#define ETH_B10T1S_PMA_TMCR_TMC_B_0X3                               (0x3u<<13)
#define ETH_B10T1S_PMA_TMCR_TMC_B_0X2                               (0x2u<<13)
#define ETH_B10T1S_PMA_TMCR_TMC_B_0X1                               (0x1u<<13)
#define ETH_B10T1S_PMA_TMCR_TMC_B_0X4                               (0x4u<<13)

// B10T1S_PMA_DR Configuration

#define ETH_B10T1S_PMA_DR_PDB                                       (0x1u<<1)
#define ETH_B10T1S_PMA_DR_PSB                                       (0x1u<<0)

#define ETH_B10T1S_PMA_DR_PDB_B_0X0                                 (0x0u<<1)
#define ETH_B10T1S_PMA_DR_PDB_B_0X1                                 (0x1u<<1)
#define ETH_B10T1S_PMA_DR_PSB_B_0X0                                 (0x0u<<0)
#define ETH_B10T1S_PMA_DR_PSB_B_0X1                                 (0x1u<<0)

// B10T1S_XCVR_PHYID_LSB Configuration

#define ETH_B10T1S_XCVR_PHYID_LSB_PHY_ID_LSB                        (0xFFFFu<<0)
#define ETH_B10T1S_XCVR_PHYID_LSB_PHY_ID_LSB_0                      (0x1u<<0)

// B10T1S_XCVR_PHYID_MSB Configuration

#define ETH_B10T1S_XCVR_PHYID_MSB_PHY_ID_MSB                        (0xFFFFu<<0)
#define ETH_B10T1S_XCVR_PHYID_MSB_PHY_ID_MSB_0                      (0x1u<<0)

// B10T1S_XCVR_MIIMCTRL Configuration

#define ETH_B10T1S_XCVR_MIIMCTRL_RESET                              (0x1u<<15)
#define ETH_B10T1S_XCVR_MIIMCTRL_LOOPBACK                           (0x1u<<14)

// MACARPAR Configuration

#define ETH_MACARPAR_ARPPA                                          (0xFFFFFFFFu<<0)
#define ETH_MACARPAR_ARPPA_0                                        (0x1u<<0)

// MAC10BT1SCR Configuration

#define ETH_MAC10BT1SCR_TS                                          (0x7u<<16)
#define ETH_MAC10BT1SCR_TS_0                                        (0x1u<<16)
#define ETH_MAC10BT1SCR_LWS                                         (0x1u<<9)
#define ETH_MAC10BT1SCR_RWS                                         (0x1u<<8)
#define ETH_MAC10BT1SCR_RCF                                         (0x3u<<6)
#define ETH_MAC10BT1SCR_RCF_0                                       (0x1u<<6)
#define ETH_MAC10BT1SCR_WKPT                                        (0x7u<<2)
#define ETH_MAC10BT1SCR_WKPT_0                                      (0x1u<<2)
#define ETH_MAC10BT1SCR_LPRC                                        (0x1u<<1)
#define ETH_MAC10BT1SCR_RAT                                         (0x1u<<0)

#define ETH_MAC10BT1SCR_TS_B_0X0                                    (0x0u<<16)
#define ETH_MAC10BT1SCR_TS_B_0X1                                    (0x1u<<16)
#define ETH_MAC10BT1SCR_TS_B_0X2                                    (0x2u<<16)
#define ETH_MAC10BT1SCR_TS_B_0X3                                    (0x3u<<16)
#define ETH_MAC10BT1SCR_TS_B_0X4                                    (0x4u<<16)
#define ETH_MAC10BT1SCR_RCF_B_0X0                                   (0x0u<<6)
#define ETH_MAC10BT1SCR_RCF_B_0X1                                   (0x1u<<6)
#define ETH_MAC10BT1SCR_RCF_B_0X2                                   (0x2u<<6)
#define ETH_MAC10BT1SCR_RCF_B_0X3                                   (0x3u<<6)
#define ETH_MAC10BT1SCR_WKPT_B_0X0                                  (0x0u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X1                                  (0x1u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X2                                  (0x2u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X3                                  (0x3u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X4                                  (0x4u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X5                                  (0x5u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X6                                  (0x6u<<2)
#define ETH_MAC10BT1SCR_WKPT_B_0X7                                  (0x7u<<2)
#define ETH_MAC10BT1SCR_RAT_B_0X0                                   (0x0u<<0)
#define ETH_MAC10BT1SCR_RAT_B_0X1                                   (0x1u<<0)

// MACCSRSWCR Configuration

#define ETH_MACCSRSWCR_SEEN                                         (0x1u<<8)
#define ETH_MACCSRSWCR_RCWE                                         (0x1u<<0)

// MACFPECSR Configuration

#define ETH_MACFPECSR_TRSP                                          (0x1u<<19)
#define ETH_MACFPECSR_TVER                                          (0x1u<<18)
#define ETH_MACFPECSR_RRSP                                          (0x1u<<17)
#define ETH_MACFPECSR_RVER                                          (0x1u<<16)
#define ETH_MACFPECSR_ARV                                           (0x1u<<3)
#define ETH_MACFPECSR_SRSP                                          (0x1u<<2)
#define ETH_MACFPECSR_SVER                                          (0x1u<<1)
#define ETH_MACFPECSR_EFPE                                          (0x1u<<0)

// MACPRSTIMR Configuration

#define ETH_MACPRSTIMR_MPTN                                         (0xFFFFFFFFu<<0)
#define ETH_MACPRSTIMR_MPTN_0                                       (0x1u<<0)

// MACPRSTIMUR Configuration

#define ETH_MACPRSTIMUR_MPTU                                        (0xFFFFFFFFu<<0)
#define ETH_MACPRSTIMUR_MPTU_0                                      (0x1u<<0)

// MACA0HR Configuration

#define ETH_MACA0HR_AE                                              (0x1u<<31)
#define ETH_MACA0HR_DCS                                             (0x1u<<16)
#define ETH_MACA0HR_ADDRHI                                          (0xFFFFu<<0)
#define ETH_MACA0HR_ADDRHI_0                                        (0x1u<<0)

#define ETH_MACA0HR_DCS_B_0X0                                       (0x0u<<16)
#define ETH_MACA0HR_DCS_B_0X1                                       (0x1u<<16)

// MACA0LR Configuration

#define ETH_MACA0LR_ADDRLO                                          (0xFFFFFFFFu<<0)
#define ETH_MACA0LR_ADDRLO_0                                        (0x1u<<0)

// MACA1HR Configuration

#define ETH_MACA1HR_AE                                              (0x1u<<31)
#define ETH_MACA1HR_SA                                              (0x1u<<30)
#define ETH_MACA1HR_MBC                                             (0x3Fu<<24)
#define ETH_MACA1HR_MBC_0                                           (0x1u<<24)
#define ETH_MACA1HR_DCS                                             (0x1u<<16)
#define ETH_MACA1HR_ADDRHI                                          (0xFFFFu<<0)
#define ETH_MACA1HR_ADDRHI_0                                        (0x1u<<0)

#define ETH_MACA1HR_SA_B_0X0                                        (0x0u<<30)
#define ETH_MACA1HR_SA_B_0X1                                        (0x1u<<30)
#define ETH_MACA1HR_DCS_B_0X0                                       (0x0u<<16)
#define ETH_MACA1HR_DCS_B_0X1                                       (0x1u<<16)

// MACA1LR Configuration

#define ETH_MACA1LR_ADDRLO                                          (0xFFFFFFFFu<<0)
#define ETH_MACA1LR_ADDRLO_0                                        (0x1u<<0)

// MACA2HR Configuration

#define ETH_MACA2HR_AE                                              (0x1u<<31)
#define ETH_MACA2HR_SA                                              (0x1u<<30)
#define ETH_MACA2HR_MBC                                             (0x3Fu<<24)
#define ETH_MACA2HR_MBC_0                                           (0x1u<<24)
#define ETH_MACA2HR_DCS                                             (0x1u<<16)
#define ETH_MACA2HR_ADDRHI                                          (0xFFFFu<<0)
#define ETH_MACA2HR_ADDRHI_0                                        (0x1u<<0)

#define ETH_MACA2HR_SA_B_0X0                                        (0x0u<<30)
#define ETH_MACA2HR_SA_B_0X1                                        (0x1u<<30)
#define ETH_MACA2HR_DCS_B_0X0                                       (0x0u<<16)
#define ETH_MACA2HR_DCS_B_0X1                                       (0x1u<<16)

// MACA2LR Configuration

#define ETH_MACA2LR_ADDRLO                                          (0xFFFFFFFFu<<0)
#define ETH_MACA2LR_ADDRLO_0                                        (0x1u<<0)

// MACA3HR Configuration

#define ETH_MACA3HR_AE                                              (0x1u<<31)
#define ETH_MACA3HR_SA                                              (0x1u<<30)
#define ETH_MACA3HR_MBC                                             (0x3Fu<<24)
#define ETH_MACA3HR_MBC_0                                           (0x1u<<24)
#define ETH_MACA3HR_DCS                                             (0x1u<<16)
#define ETH_MACA3HR_ADDRHI                                          (0xFFFFu<<0)
#define ETH_MACA3HR_ADDRHI_0                                        (0x1u<<0)

#define ETH_MACA3HR_SA_B_0X0                                        (0x0u<<30)
#define ETH_MACA3HR_SA_B_0X1                                        (0x1u<<30)
#define ETH_MACA3HR_DCS_B_0X0                                       (0x0u<<16)
#define ETH_MACA3HR_DCS_B_0X1                                       (0x1u<<16)

// MACA3LR Configuration

#define ETH_MACA3LR_ADDRLO                                          (0xFFFFFFFFu<<0)
#define ETH_MACA3LR_ADDRLO_0                                        (0x1u<<0)

// MMC_CONTROL Configuration

#define ETH_MMC_CONTROL_UCDBC                                       (0x1u<<8)
#define ETH_MMC_CONTROL_CNTPRSTLVL                                  (0x1u<<5)
#define ETH_MMC_CONTROL_CNTPRST                                     (0x1u<<4)
#define ETH_MMC_CONTROL_CNTFREEZ                                    (0x1u<<3)
#define ETH_MMC_CONTROL_RSTONRD                                     (0x1u<<2)
#define ETH_MMC_CONTROL_CNTSTOPRO                                   (0x1u<<1)
#define ETH_MMC_CONTROL_CNTRST                                      (0x1u<<0)

// MMC_RX_INTERRUPT Configuration

#define ETH_MMC_RX_INTERRUPT_RXLPITRCIS                             (0x1u<<27)
#define ETH_MMC_RX_INTERRUPT_RXLPIUSCIS                             (0x1u<<26)
#define ETH_MMC_RX_INTERRUPT_RXCTRLPIS                              (0x1u<<25)
#define ETH_MMC_RX_INTERRUPT_RXRCVERRPIS                            (0x1u<<24)
#define ETH_MMC_RX_INTERRUPT_RXWDOGPIS                              (0x1u<<23)
#define ETH_MMC_RX_INTERRUPT_RXVLANGBPIS                            (0x1u<<22)
#define ETH_MMC_RX_INTERRUPT_RXFOVPIS                               (0x1u<<21)
#define ETH_MMC_RX_INTERRUPT_RXPAUSPIS                              (0x1u<<20)
#define ETH_MMC_RX_INTERRUPT_RXORANGEPIS                            (0x1u<<19)
#define ETH_MMC_RX_INTERRUPT_RXLENERPIS                             (0x1u<<18)
#define ETH_MMC_RX_INTERRUPT_RXUCGPIS                               (0x1u<<17)
#define ETH_MMC_RX_INTERRUPT_RX1024TMAXOCTGBPIS                     (0x1u<<16)
#define ETH_MMC_RX_INTERRUPT_RX512T1023OCTGBPIS                     (0x1u<<15)
#define ETH_MMC_RX_INTERRUPT_RX256T511OCTGBPIS                      (0x1u<<14)
#define ETH_MMC_RX_INTERRUPT_RX128T255OCTGBPIS                      (0x1u<<13)
#define ETH_MMC_RX_INTERRUPT_RX65T127OCTGBPIS                       (0x1u<<12)
#define ETH_MMC_RX_INTERRUPT_RX64OCTGBPIS                           (0x1u<<11)
#define ETH_MMC_RX_INTERRUPT_RXOSIZEGPIS                            (0x1u<<10)
#define ETH_MMC_RX_INTERRUPT_RXUSIZEGPIS                            (0x1u<<9)
#define ETH_MMC_RX_INTERRUPT_RXJABERPIS                             (0x1u<<8)
#define ETH_MMC_RX_INTERRUPT_RXRUNTPIS                              (0x1u<<7)
#define ETH_MMC_RX_INTERRUPT_RXALGNERPIS                            (0x1u<<6)
#define ETH_MMC_RX_INTERRUPT_RXCRCERPIS                             (0x1u<<5)
#define ETH_MMC_RX_INTERRUPT_RXMCGPIS                               (0x1u<<4)
#define ETH_MMC_RX_INTERRUPT_RXBCGPIS                               (0x1u<<3)
#define ETH_MMC_RX_INTERRUPT_RXGOCTIS                               (0x1u<<2)
#define ETH_MMC_RX_INTERRUPT_RXGBOCTIS                              (0x1u<<1)
#define ETH_MMC_RX_INTERRUPT_RXGBPKTIS                              (0x1u<<0)

// MMC_TX_INTERRUPT Configuration

#define ETH_MMC_TX_INTERRUPT_TXLPITRCIS                             (0x1u<<27)
#define ETH_MMC_TX_INTERRUPT_TXLPIUSCIS                             (0x1u<<26)
#define ETH_MMC_TX_INTERRUPT_TXOSIZEGPIS                            (0x1u<<25)
#define ETH_MMC_TX_INTERRUPT_TXVLANGPIS                             (0x1u<<24)
#define ETH_MMC_TX_INTERRUPT_TXPAUSPIS                              (0x1u<<23)
#define ETH_MMC_TX_INTERRUPT_TXEXDEFPIS                             (0x1u<<22)
#define ETH_MMC_TX_INTERRUPT_TXGPKTIS                               (0x1u<<21)
#define ETH_MMC_TX_INTERRUPT_TXGOCTIS                               (0x1u<<20)
#define ETH_MMC_TX_INTERRUPT_TXCARERPIS                             (0x1u<<19)
#define ETH_MMC_TX_INTERRUPT_TXEXCOLPIS                             (0x1u<<18)
#define ETH_MMC_TX_INTERRUPT_TXLATCOLPIS                            (0x1u<<17)
#define ETH_MMC_TX_INTERRUPT_TXDEFPIS                               (0x1u<<16)
#define ETH_MMC_TX_INTERRUPT_TXMCOLGPIS                             (0x1u<<15)
#define ETH_MMC_TX_INTERRUPT_TXSCOLGPIS                             (0x1u<<14)
#define ETH_MMC_TX_INTERRUPT_TXUFLOWERPIS                           (0x1u<<13)
#define ETH_MMC_TX_INTERRUPT_TXBCGBPIS                              (0x1u<<12)
#define ETH_MMC_TX_INTERRUPT_TXMCGBPIS                              (0x1u<<11)
#define ETH_MMC_TX_INTERRUPT_TXUCGBPIS                              (0x1u<<10)
#define ETH_MMC_TX_INTERRUPT_TX1024TMAXOCTGBPIS                     (0x1u<<9)
#define ETH_MMC_TX_INTERRUPT_TX512T1023OCTGBPIS                     (0x1u<<8)
#define ETH_MMC_TX_INTERRUPT_TX256T511OCTGBPIS                      (0x1u<<7)
#define ETH_MMC_TX_INTERRUPT_TX128T255OCTGBPIS                      (0x1u<<6)
#define ETH_MMC_TX_INTERRUPT_TX65T127OCTGBPIS                       (0x1u<<5)
#define ETH_MMC_TX_INTERRUPT_TX64OCTGBPIS                           (0x1u<<4)
#define ETH_MMC_TX_INTERRUPT_TXMCGPIS                               (0x1u<<3)
#define ETH_MMC_TX_INTERRUPT_TXBCGPIS                               (0x1u<<2)
#define ETH_MMC_TX_INTERRUPT_TXGBPKTIS                              (0x1u<<1)
#define ETH_MMC_TX_INTERRUPT_TXGBOCTIS                              (0x1u<<0)

// MMC_RX_INTERRUPT_MASK Configuration

#define ETH_MMC_RX_INTERRUPT_MASK_RXLPITRCIM                        (0x1u<<27)
#define ETH_MMC_RX_INTERRUPT_MASK_RXLPIUSCIM                        (0x1u<<26)
#define ETH_MMC_RX_INTERRUPT_MASK_RXCTRLPIM                         (0x1u<<25)
#define ETH_MMC_RX_INTERRUPT_MASK_RXRCVERRPIM                       (0x1u<<24)
#define ETH_MMC_RX_INTERRUPT_MASK_RXWDOGPIM                         (0x1u<<23)
#define ETH_MMC_RX_INTERRUPT_MASK_RXVLANGBPIM                       (0x1u<<22)
#define ETH_MMC_RX_INTERRUPT_MASK_RXFOVPIM                          (0x1u<<21)
#define ETH_MMC_RX_INTERRUPT_MASK_RXPAUSPIM                         (0x1u<<20)
#define ETH_MMC_RX_INTERRUPT_MASK_RXORANGEPIM                       (0x1u<<19)
#define ETH_MMC_RX_INTERRUPT_MASK_RXLENERPIM                        (0x1u<<18)
#define ETH_MMC_RX_INTERRUPT_MASK_RXUCGPIM                          (0x1u<<17)
#define ETH_MMC_RX_INTERRUPT_MASK_RX1024TMAXOCTGBPIM                (0x1u<<16)
#define ETH_MMC_RX_INTERRUPT_MASK_RX512T1023OCTGBPIM                (0x1u<<15)
#define ETH_MMC_RX_INTERRUPT_MASK_RX256T511OCTGBPIM                 (0x1u<<14)
#define ETH_MMC_RX_INTERRUPT_MASK_RX128T255OCTGBPIM                 (0x1u<<13)
#define ETH_MMC_RX_INTERRUPT_MASK_RX65T127OCTGBPIM                  (0x1u<<12)
#define ETH_MMC_RX_INTERRUPT_MASK_RX64OCTGBPIM                      (0x1u<<11)
#define ETH_MMC_RX_INTERRUPT_MASK_RXOSIZEGPIM                       (0x1u<<10)
#define ETH_MMC_RX_INTERRUPT_MASK_RXUSIZEGPIM                       (0x1u<<9)
#define ETH_MMC_RX_INTERRUPT_MASK_RXJABERPIM                        (0x1u<<8)
#define ETH_MMC_RX_INTERRUPT_MASK_RXRUNTPIM                         (0x1u<<7)
#define ETH_MMC_RX_INTERRUPT_MASK_RXALGNERPIM                       (0x1u<<6)
#define ETH_MMC_RX_INTERRUPT_MASK_RXCRCERPIM                        (0x1u<<5)
#define ETH_MMC_RX_INTERRUPT_MASK_RXMCGPIM                          (0x1u<<4)
#define ETH_MMC_RX_INTERRUPT_MASK_RXBCGPIM                          (0x1u<<3)
#define ETH_MMC_RX_INTERRUPT_MASK_RXGOCTIM                          (0x1u<<2)
#define ETH_MMC_RX_INTERRUPT_MASK_RXGBOCTIM                         (0x1u<<1)
#define ETH_MMC_RX_INTERRUPT_MASK_RXGBPKTIM                         (0x1u<<0)

// MMC_TX_INTERRUPT_MASK Configuration

#define ETH_MMC_TX_INTERRUPT_MASK_TXLPITRCIM                        (0x1u<<27)
#define ETH_MMC_TX_INTERRUPT_MASK_TXLPIUSCIM                        (0x1u<<26)
#define ETH_MMC_TX_INTERRUPT_MASK_TXOSIZEGPIM                       (0x1u<<25)
#define ETH_MMC_TX_INTERRUPT_MASK_TXVLANGPIM                        (0x1u<<24)
#define ETH_MMC_TX_INTERRUPT_MASK_TXPAUSPIM                         (0x1u<<23)
#define ETH_MMC_TX_INTERRUPT_MASK_TXEXDEFPIM                        (0x1u<<22)
#define ETH_MMC_TX_INTERRUPT_MASK_TXGPKTIM                          (0x1u<<21)
#define ETH_MMC_TX_INTERRUPT_MASK_TXGOCTIM                          (0x1u<<20)
#define ETH_MMC_TX_INTERRUPT_MASK_TXCARERPIM                        (0x1u<<19)
#define ETH_MMC_TX_INTERRUPT_MASK_TXEXCOLPIM                        (0x1u<<18)
#define ETH_MMC_TX_INTERRUPT_MASK_TXLATCOLPIM                       (0x1u<<17)
#define ETH_MMC_TX_INTERRUPT_MASK_TXDEFPIM                          (0x1u<<16)
#define ETH_MMC_TX_INTERRUPT_MASK_TXMCOLGPIM                        (0x1u<<15)
#define ETH_MMC_TX_INTERRUPT_MASK_TXSCOLGPIM                        (0x1u<<14)
#define ETH_MMC_TX_INTERRUPT_MASK_TXUFLOWERPIM                      (0x1u<<13)
#define ETH_MMC_TX_INTERRUPT_MASK_TXBCGBPIM                         (0x1u<<12)
#define ETH_MMC_TX_INTERRUPT_MASK_TXMCGBPIM                         (0x1u<<11)
#define ETH_MMC_TX_INTERRUPT_MASK_TXUCGBPIM                         (0x1u<<10)
#define ETH_MMC_TX_INTERRUPT_MASK_TX1024TMAXOCTGBPIM                (0x1u<<9)
#define ETH_MMC_TX_INTERRUPT_MASK_TX512T1023OCTGBPIM                (0x1u<<8)
#define ETH_MMC_TX_INTERRUPT_MASK_TX256T511OCTGBPIM                 (0x1u<<7)
#define ETH_MMC_TX_INTERRUPT_MASK_TX128T255OCTGBPIM                 (0x1u<<6)
#define ETH_MMC_TX_INTERRUPT_MASK_TX65T127OCTGBPIM                  (0x1u<<5)
#define ETH_MMC_TX_INTERRUPT_MASK_TX64OCTGBPIM                      (0x1u<<4)
#define ETH_MMC_TX_INTERRUPT_MASK_TXMCGPIM                          (0x1u<<3)
#define ETH_MMC_TX_INTERRUPT_MASK_TXBCGPIM                          (0x1u<<2)
#define ETH_MMC_TX_INTERRUPT_MASK_TXGBPKTIM                         (0x1u<<1)
#define ETH_MMC_TX_INTERRUPT_MASK_TXGBOCTIM                         (0x1u<<0)

// TX_OCTET_COUNT_GOOD_BAD Configuration

#define ETH_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB                         (0xFFFFFFFFu<<0)
#define ETH_TX_OCTET_COUNT_GOOD_BAD_TXOCTGB_0                       (0x1u<<0)

// TX_PACKET_COUNT_GOOD_BAD Configuration

#define ETH_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB                        (0xFFFFFFFFu<<0)
#define ETH_TX_PACKET_COUNT_GOOD_BAD_TXPKTGB_0                      (0x1u<<0)

// TX_BROADCAST_PACKETS_GOOD Configuration

#define ETH_TX_BROADCAST_PACKETS_GOOD_TXBCASTG                      (0xFFFFFFFFu<<0)
#define ETH_TX_BROADCAST_PACKETS_GOOD_TXBCASTG_0                    (0x1u<<0)

// TX_MULTICAST_PACKETS_GOOD Configuration

#define ETH_TX_MULTICAST_PACKETS_GOOD_TXMCASTG                      (0xFFFFFFFFu<<0)
#define ETH_TX_MULTICAST_PACKETS_GOOD_TXMCASTG_0                    (0x1u<<0)

// TX_64OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB                  (0xFFFFFFFFu<<0)
#define ETH_TX_64OCTETS_PACKETS_GOOD_BAD_TX64OCTGB_0                (0x1u<<0)

// TX_64TO127OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_64TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB         (0xFFFFFFFFu<<0)
#define ETH_TX_64TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_0       (0x1u<<0)

// TX_128TO255OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB       (0xFFFFFFFFu<<0)
#define ETH_TX_128TO255OCTETS_PACKETS_GOOD_BAD_TX128_255OCTGB_0     (0x1u<<0)

// TX_256TO511OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB       (0xFFFFFFFFu<<0)
#define ETH_TX_256TO511OCTETS_PACKETS_GOOD_BAD_TX256_511OCTGB_0     (0x1u<<0)

// TX_512TO1023OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB     (0xFFFFFFFFu<<0)
#define ETH_TX_512TO1023OCTETS_PACKETS_GOOD_BAD_TX512_1023OCTGB_0   (0x1u<<0)

// TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB     (0xFFFFFFFFu<<0)
#define ETH_TX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_TX1024_MAXOCTGB_0   (0x1u<<0)

// TX_UNICAST_PACKETS_GOOD_BAD Configuration

#define ETH_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB                   (0xFFFFFFFFu<<0)
#define ETH_TX_UNICAST_PACKETS_GOOD_BAD_TXUCASTGB_0                 (0x1u<<0)

// TX_MULTICAST_PACKETS_GOOD_BAD Configuration

#define ETH_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB                 (0xFFFFFFFFu<<0)
#define ETH_TX_MULTICAST_PACKETS_GOOD_BAD_TXMCASTGB_0               (0x1u<<0)

// TX_BROADCAST_PACKETS_GOOD_BAD Configuration

#define ETH_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB                 (0xFFFFFFFFu<<0)
#define ETH_TX_BROADCAST_PACKETS_GOOD_BAD_TXBCASTGB_0               (0x1u<<0)

// TX_UNDERFLOW_ERROR_PACKETS Configuration

#define ETH_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW                    (0xFFFFFFFFu<<0)
#define ETH_TX_UNDERFLOW_ERROR_PACKETS_TXUNDRFLW_0                  (0x1u<<0)

// TX_SINGLE_COLLISION_GOOD_PACKETS Configuration

#define ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG             (0xFFFFFFFFu<<0)
#define ETH_TX_SINGLE_COLLISION_GOOD_PACKETS_TXSNGLCOLG_0           (0x1u<<0)

// TX_MULTIPLE_COLLISION_GOOD_PACKETS Configuration

#define ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG           (0xFFFFFFFFu<<0)
#define ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS_TXMULTCOLG_0         (0x1u<<0)

// TX_DEFERRED_PACKETS Configuration

#define ETH_TX_DEFERRED_PACKETS_TXDEFRD                             (0xFFFFFFFFu<<0)
#define ETH_TX_DEFERRED_PACKETS_TXDEFRD_0                           (0x1u<<0)

// TX_LATE_COLLISION_PACKETS Configuration

#define ETH_TX_LATE_COLLISION_PACKETS_TXLATECOL                     (0xFFFFFFFFu<<0)
#define ETH_TX_LATE_COLLISION_PACKETS_TXLATECOL_0                   (0x1u<<0)

// TX_EXCESSIVE_COLLISION_PACKETS Configuration

#define ETH_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL                 (0xFFFFFFFFu<<0)
#define ETH_TX_EXCESSIVE_COLLISION_PACKETS_TXEXSCOL_0               (0x1u<<0)

// TX_CARRIER_ERROR_PACKETS Configuration

#define ETH_TX_CARRIER_ERROR_PACKETS_TXCARR                         (0xFFFFFFFFu<<0)
#define ETH_TX_CARRIER_ERROR_PACKETS_TXCARR_0                       (0x1u<<0)

// TX_OCTET_COUNT_GOOD Configuration

#define ETH_TX_OCTET_COUNT_GOOD_TXOCTG                              (0xFFFFFFFFu<<0)
#define ETH_TX_OCTET_COUNT_GOOD_TXOCTG_0                            (0x1u<<0)

// TX_PACKET_COUNT_GOOD Configuration

#define ETH_TX_PACKET_COUNT_GOOD_TXPKTG                             (0xFFFFFFFFu<<0)
#define ETH_TX_PACKET_COUNT_GOOD_TXPKTG_0                           (0x1u<<0)

// TX_EXCESSIVE_DEFERRAL_ERROR Configuration

#define ETH_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF                    (0xFFFFFFFFu<<0)
#define ETH_TX_EXCESSIVE_DEFERRAL_ERROR_TXEXSDEF_0                  (0x1u<<0)

// TX_PAUSE_PACKETS Configuration

#define ETH_TX_PAUSE_PACKETS_TXPAUSE                                (0xFFFFFFFFu<<0)
#define ETH_TX_PAUSE_PACKETS_TXPAUSE_0                              (0x1u<<0)

// TX_VLAN_PACKETS_GOOD Configuration

#define ETH_TX_VLAN_PACKETS_GOOD_TXVLANG                            (0xFFFFFFFFu<<0)
#define ETH_TX_VLAN_PACKETS_GOOD_TXVLANG_0                          (0x1u<<0)

// TX_OSIZE_PACKETS_GOOD Configuration

#define ETH_TX_OSIZE_PACKETS_GOOD_TXOSIZG                           (0xFFFFFFFFu<<0)
#define ETH_TX_OSIZE_PACKETS_GOOD_TXOSIZG_0                         (0x1u<<0)

// RX_PACKETS_COUNT_GOOD_BAD Configuration

#define ETH_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB                       (0xFFFFFFFFu<<0)
#define ETH_RX_PACKETS_COUNT_GOOD_BAD_RXPKTGB_0                     (0x1u<<0)

// RX_OCTET_COUNT_GOOD_BAD Configuration

#define ETH_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB                         (0xFFFFFFFFu<<0)
#define ETH_RX_OCTET_COUNT_GOOD_BAD_RXOCTGB_0                       (0x1u<<0)

// RX_OCTET_COUNT_GOOD Configuration

#define ETH_RX_OCTET_COUNT_GOOD_RXOCTG                              (0xFFFFFFFFu<<0)
#define ETH_RX_OCTET_COUNT_GOOD_RXOCTG_0                            (0x1u<<0)

// RX_BROADCAST_PACKETS_GOOD Configuration

#define ETH_RX_BROADCAST_PACKETS_GOOD_RXBCASTG                      (0xFFFFFFFFu<<0)
#define ETH_RX_BROADCAST_PACKETS_GOOD_RXBCASTG_0                    (0x1u<<0)

// RX_MULTICAST_PACKETS_GOOD Configuration

#define ETH_RX_MULTICAST_PACKETS_GOOD_RXMCASTG                      (0xFFFFFFFFu<<0)
#define ETH_RX_MULTICAST_PACKETS_GOOD_RXMCASTG_0                    (0x1u<<0)

// RX_CRC_ERROR_PACKETS Configuration

#define ETH_RX_CRC_ERROR_PACKETS_RXCRCERR                           (0xFFFFFFFFu<<0)
#define ETH_RX_CRC_ERROR_PACKETS_RXCRCERR_0                         (0x1u<<0)

// RX_ALIGNMENT_ERROR_PACKETS Configuration

#define ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR                    (0xFFFFFFFFu<<0)
#define ETH_RX_ALIGNMENT_ERROR_PACKETS_RXALGNERR_0                  (0x1u<<0)

// RX_RUNT_ERROR_PACKETS Configuration

#define ETH_RX_RUNT_ERROR_PACKETS_RXRUNTERR                         (0xFFFFFFFFu<<0)
#define ETH_RX_RUNT_ERROR_PACKETS_RXRUNTERR_0                       (0x1u<<0)

// RX_JABBER_ERROR_PACKETS Configuration

#define ETH_RX_JABBER_ERROR_PACKETS_RXJABERR                        (0xFFFFFFFFu<<0)
#define ETH_RX_JABBER_ERROR_PACKETS_RXJABERR_0                      (0x1u<<0)

// RX_UNDERSIZE_PACKETS_GOOD Configuration

#define ETH_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG                    (0xFFFFFFFFu<<0)
#define ETH_RX_UNDERSIZE_PACKETS_GOOD_RXUNDERSZG_0                  (0x1u<<0)

// RX_OVERSIZE_PACKETS_GOOD Configuration

#define ETH_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG                      (0xFFFFFFFFu<<0)
#define ETH_RX_OVERSIZE_PACKETS_GOOD_RXOVERSZG_0                    (0x1u<<0)

// RX_64OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB                  (0xFFFFFFFFu<<0)
#define ETH_RX_64OCTETS_PACKETS_GOOD_BAD_RX64OCTGB_0                (0x1u<<0)

// RX_65TO127OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB         (0xFFFFFFFFu<<0)
#define ETH_RX_65TO127OCTETS_PACKETS_GOOD_BAD_TX65_127OCTGB_0       (0x1u<<0)

// RX_128TO255OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB       (0xFFFFFFFFu<<0)
#define ETH_RX_128TO255OCTETS_PACKETS_GOOD_BAD_RX128_255OCTGB_0     (0x1u<<0)

// RX_256TO511OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB       (0xFFFFFFFFu<<0)
#define ETH_RX_256TO511OCTETS_PACKETS_GOOD_BAD_RX256_511OCTGB_0     (0x1u<<0)

// RX_512TO1023OCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB     (0xFFFFFFFFu<<0)
#define ETH_RX_512TO1023OCTETS_PACKETS_GOOD_BAD_RX512_1023OCTGB_0   (0x1u<<0)

// RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD Configuration

#define ETH_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB     (0xFFFFFFFFu<<0)
#define ETH_RX_1024TOMAXOCTETS_PACKETS_GOOD_BAD_RX1024_MAXOCTGB_0   (0x1u<<0)

// RX_UNICAST_PACKETS_GOOD Configuration

#define ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG                        (0xFFFFFFFFu<<0)
#define ETH_RX_UNICAST_PACKETS_GOOD_RXUCASTG_0                      (0x1u<<0)

// RX_LENGTH_ERROR_PACKETS Configuration

#define ETH_RX_LENGTH_ERROR_PACKETS_RXLENERR                        (0xFFFFFFFFu<<0)
#define ETH_RX_LENGTH_ERROR_PACKETS_RXLENERR_0                      (0x1u<<0)

// RX_OUT_OF_RANGE_PACKETS Configuration

#define ETH_RX_OUT_OF_RANGE_PACKETS_RXOUTOFRNG                      (0xFFFFFFFFu<<0)
#define ETH_RX_OUT_OF_RANGE_PACKETS_RXOUTOFRNG_0                    (0x1u<<0)

// RX_PAUSE_PACKETS Configuration

#define ETH_RX_PAUSE_PACKETS_RXPAUSEPKT                             (0xFFFFFFFFu<<0)
#define ETH_RX_PAUSE_PACKETS_RXPAUSEPKT_0                           (0x1u<<0)

// RX_FIFO_OVERFLOW_PACKETS Configuration

#define ETH_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL                     (0xFFFFFFFFu<<0)
#define ETH_RX_FIFO_OVERFLOW_PACKETS_RXFIFOOVFL_0                   (0x1u<<0)

// RX_VLAN_PACKETS_GOOD_BAD Configuration

#define ETH_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB                    (0xFFFFFFFFu<<0)
#define ETH_RX_VLAN_PACKETS_GOOD_BAD_RXVLANPKTGB_0                  (0x1u<<0)

// RX_WATCHDOG_ERROR_PACKETS Configuration

#define ETH_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR                      (0xFFFFFFFFu<<0)
#define ETH_RX_WATCHDOG_ERROR_PACKETS_RXWDGERR_0                    (0x1u<<0)

// RX_RECEIVE_ERROR Configuration

#define ETH_RX_RECEIVE_ERROR_RXRCVERR                               (0xFFFFFFFFu<<0)
#define ETH_RX_RECEIVE_ERROR_RXRCVERR_0                             (0x1u<<0)

// RX_CONTROL_PACKETS_GOOD Configuration

#define ETH_RX_CONTROL_PACKETS_GOOD_RXCTRLG                         (0xFFFFFFFFu<<0)
#define ETH_RX_CONTROL_PACKETS_GOOD_RXCTRLG_0                       (0x1u<<0)

// TX_LPI_USEC_CNTR Configuration

#define ETH_TX_LPI_USEC_CNTR_TXLPIUSC                               (0xFFFFFFFFu<<0)
#define ETH_TX_LPI_USEC_CNTR_TXLPIUSC_0                             (0x1u<<0)

// TX_LPI_TRAN_CNTR Configuration

#define ETH_TX_LPI_TRAN_CNTR_TXLPITRC                               (0xFFFFFFFFu<<0)
#define ETH_TX_LPI_TRAN_CNTR_TXLPITRC_0                             (0x1u<<0)

// RX_LPI_USEC_CNTR Configuration

#define ETH_RX_LPI_USEC_CNTR_RXLPIUSC                               (0xFFFFFFFFu<<0)
#define ETH_RX_LPI_USEC_CNTR_RXLPIUSC_0                             (0x1u<<0)

// RX_LPI_TRAN_CNTR Configuration

#define ETH_RX_LPI_TRAN_CNTR_RXLPITRC                               (0xFFFFFFFFu<<0)
#define ETH_RX_LPI_TRAN_CNTR_RXLPITRC_0                             (0x1u<<0)

// MMC_FPE_TX_ISR Configuration

#define ETH_MMC_FPE_TX_ISR_HRCIS                                    (0x1u<<1)
#define ETH_MMC_FPE_TX_ISR_FCIS                                     (0x1u<<0)

// MMC_FPE_TX_IMR Configuration

#define ETH_MMC_FPE_TX_IMR_HRCIM                                    (0x1u<<1)
#define ETH_MMC_FPE_TX_IMR_FCIM                                     (0x1u<<0)

// MMC_FPE_TX_FCR Configuration

#define ETH_MMC_FPE_TX_FCR_TXFFC                                    (0xFFFFFFFFu<<0)
#define ETH_MMC_FPE_TX_FCR_TXFFC_0                                  (0x1u<<0)

// MMC_TX_HRCR Configuration

#define ETH_MMC_TX_HRCR_TXHRC                                       (0xFFFFFFFFu<<0)
#define ETH_MMC_TX_HRCR_TXHRC_0                                     (0x1u<<0)

// MMC_FPE_RX_ISR Configuration

#define ETH_MMC_FPE_RX_ISR_FCIS                                     (0x1u<<3)
#define ETH_MMC_FPE_RX_ISR_PAOCIS                                   (0x1u<<2)
#define ETH_MMC_FPE_RX_ISR_PSECIS                                   (0x1u<<1)
#define ETH_MMC_FPE_RX_ISR_PAECIS                                   (0x1u<<0)

// MMC_FPE_RX_IMR Configuration

#define ETH_MMC_FPE_RX_IMR_FCIM                                     (0x1u<<3)
#define ETH_MMC_FPE_RX_IMR_PAOCIM                                   (0x1u<<2)
#define ETH_MMC_FPE_RX_IMR_PSECIM                                   (0x1u<<1)
#define ETH_MMC_FPE_RX_IMR_PAECIM                                   (0x1u<<0)

// RX_PACKET_ASM_ERR Configuration

#define ETH_RX_PACKET_ASM_ERR_PAEC                                  (0xFFFFFFFFu<<0)
#define ETH_RX_PACKET_ASM_ERR_PAEC_0                                (0x1u<<0)

// RX_PACKET_SMD_ERR Configuration

#define ETH_RX_PACKET_SMD_ERR_PSEC                                  (0xFFFFFFFFu<<0)
#define ETH_RX_PACKET_SMD_ERR_PSEC_0                                (0x1u<<0)

// RX_PACKET_ASM_OKR Configuration

#define ETH_RX_PACKET_ASM_OKR_PAOC                                  (0xFFFFFFFFu<<0)
#define ETH_RX_PACKET_ASM_OKR_PAOC_0                                (0x1u<<0)

// RX_FPE_FRAG_CR Configuration

#define ETH_RX_FPE_FRAG_CR_FFC                                      (0xFFFFFFFFu<<0)
#define ETH_RX_FPE_FRAG_CR_FFC_0                                    (0x1u<<0)

// MACL3L4C0R Configuration

#define ETH_MACL3L4C0R_DMCHEN0                                      (0x1u<<28)
#define ETH_MACL3L4C0R_DMCHN0                                       (0x1u<<24)
#define ETH_MACL3L4C0R_L4DPIM0                                      (0x1u<<21)
#define ETH_MACL3L4C0R_L4DPM0                                       (0x1u<<20)
#define ETH_MACL3L4C0R_L4SPIM0                                      (0x1u<<19)
#define ETH_MACL3L4C0R_L4SPM0                                       (0x1u<<18)
#define ETH_MACL3L4C0R_L4PEN0                                       (0x1u<<16)
#define ETH_MACL3L4C0R_L3HDBM0                                      (0x1Fu<<11)
#define ETH_MACL3L4C0R_L3HDBM0_0                                    (0x1u<<11)
#define ETH_MACL3L4C0R_L3HSBM0                                      (0x1Fu<<6)
#define ETH_MACL3L4C0R_L3HSBM0_0                                    (0x1u<<6)
#define ETH_MACL3L4C0R_L3DAIM0                                      (0x1u<<5)
#define ETH_MACL3L4C0R_L3DAM0                                       (0x1u<<4)
#define ETH_MACL3L4C0R_L3SAIM0                                      (0x1u<<3)
#define ETH_MACL3L4C0R_L3SAM0                                       (0x1u<<2)
#define ETH_MACL3L4C0R_L3PEN0                                       (0x1u<<0)

#define ETH_MACL3L4C0R_DMCHN0_B_0X0                                 (0x0u<<24)
#define ETH_MACL3L4C0R_DMCHN0_B_0X1                                 (0x1u<<24)
#define ETH_MACL3L4C0R_L3HDBM0_B_0X0_IPV4_PACKETS                   (0x0u<<11)
#define ETH_MACL3L4C0R_L3HDBM0_B_0X1_IPV4_PACKETS                   (0x1u<<11)
#define ETH_MACL3L4C0R_L3HSBM0_B_0X0_IPV4_PACKETS                   (0x0u<<6)
#define ETH_MACL3L4C0R_L3HSBM0_B_0X1_IPV4_PACKETS                   (0x1u<<6)

// MACL4A0R Configuration

#define ETH_MACL4A0R_L4DP0                                          (0xFFFFu<<16)
#define ETH_MACL4A0R_L4DP0_0                                        (0x1u<<16)
#define ETH_MACL4A0R_L4SP0                                          (0xFFFFu<<0)
#define ETH_MACL4A0R_L4SP0_0                                        (0x1u<<0)

// MACL3A00R Configuration

#define ETH_MACL3A00R_L3A00                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A00R_L3A00_0                                       (0x1u<<0)

// MACL3A10R Configuration

#define ETH_MACL3A10R_L3A10                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A10R_L3A10_0                                       (0x1u<<0)

// MACL3A20R Configuration

#define ETH_MACL3A20R_L3A20                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A20R_L3A20_0                                       (0x1u<<0)

// MACL3A30R Configuration

#define ETH_MACL3A30R_L3A30                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A30R_L3A30_0                                       (0x1u<<0)

// MACL3L4C1R Configuration

#define ETH_MACL3L4C1R_DMCHEN1                                      (0x1u<<28)
#define ETH_MACL3L4C1R_DMCHN1                                       (0x1u<<24)
#define ETH_MACL3L4C1R_L4DPIM1                                      (0x1u<<21)
#define ETH_MACL3L4C1R_L4DPM1                                       (0x1u<<20)
#define ETH_MACL3L4C1R_L4SPIM1                                      (0x1u<<19)
#define ETH_MACL3L4C1R_L4SPM1                                       (0x1u<<18)
#define ETH_MACL3L4C1R_L4PEN1                                       (0x1u<<16)
#define ETH_MACL3L4C1R_L3HDBM1                                      (0x1Fu<<11)
#define ETH_MACL3L4C1R_L3HDBM1_0                                    (0x1u<<11)
#define ETH_MACL3L4C1R_L3HSBM1                                      (0x1Fu<<6)
#define ETH_MACL3L4C1R_L3HSBM1_0                                    (0x1u<<6)
#define ETH_MACL3L4C1R_L3DAIM1                                      (0x1u<<5)
#define ETH_MACL3L4C1R_L3DAM1                                       (0x1u<<4)
#define ETH_MACL3L4C1R_L3SAIM1                                      (0x1u<<3)
#define ETH_MACL3L4C1R_L3SAM1                                       (0x1u<<2)
#define ETH_MACL3L4C1R_L3PEN1                                       (0x1u<<0)

#define ETH_MACL3L4C1R_L3HDBM1_B_0X0_IPV4_PACKETS                   (0x0u<<11)
#define ETH_MACL3L4C1R_L3HDBM1_B_0X1_IPV4_PACKETS                   (0x1u<<11)
#define ETH_MACL3L4C1R_L3HSBM1_B_0X0_IPV4_PACKETS                   (0x0u<<6)
#define ETH_MACL3L4C1R_L3HSBM1_B_0X1_IPV4_PACKETS                   (0x1u<<6)

// MACL4A1R Configuration

#define ETH_MACL4A1R_L4DP1                                          (0xFFFFu<<16)
#define ETH_MACL4A1R_L4DP1_0                                        (0x1u<<16)
#define ETH_MACL4A1R_L4SP1                                          (0xFFFFu<<0)
#define ETH_MACL4A1R_L4SP1_0                                        (0x1u<<0)

// MACL3A01R Configuration

#define ETH_MACL3A01R_L3A01                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A01R_L3A01_0                                       (0x1u<<0)

// MACL3A11R Configuration

#define ETH_MACL3A11R_L3A11                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A11R_L3A11_0                                       (0x1u<<0)

// MACL3A21R Configuration

#define ETH_MACL3A21R_L3A21                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A21R_L3A21_0                                       (0x1u<<0)

// MACL3A31R Configuration

#define ETH_MACL3A31R_L3A31                                         (0xFFFFFFFFu<<0)
#define ETH_MACL3A31R_L3A31_0                                       (0x1u<<0)

// MAC_IACR Configuration

#define ETH_MAC_IACR_MSEL                                           (0xFu<<16)
#define ETH_MAC_IACR_MSEL_0                                         (0x1u<<16)
#define ETH_MAC_IACR_AOFF                                           (0xFFu<<8)
#define ETH_MAC_IACR_AOFF_0                                         (0x1u<<8)
#define ETH_MAC_IACR_AUTO                                           (0x1u<<5)
#define ETH_MAC_IACR_COM                                            (0x1u<<1)
#define ETH_MAC_IACR_OB                                             (0x1u<<0)

#define ETH_MAC_IACR_MSEL_B_0X0                                     (0x0u<<16)
#define ETH_MAC_IACR_MSEL_B_0X1                                     (0x1u<<16)
#define ETH_MAC_IACR_MSEL_B_0X2                                     (0x2u<<16)
#define ETH_MAC_IACR_MSEL_B_0X3                                     (0x3u<<16)
#define ETH_MAC_IACR_MSEL_B_0X4                                     (0x4u<<16)
#define ETH_MAC_IACR_MSEL_B_0X5                                     (0x5u<<16)
#define ETH_MAC_IACR_MSEL_B_0X6                                     (0x6u<<16)
#define ETH_MAC_IACR_MSEL_B_0X7                                     (0x7u<<16)
#define ETH_MAC_IACR_MSEL_B_0X8                                     (0x8u<<16)
#define ETH_MAC_IACR_MSEL_B_0X9                                     (0x9u<<16)
#define ETH_MAC_IACR_MSEL_B_0XA                                     (0xAu<<16)
#define ETH_MAC_IACR_MSEL_B_0XB                                     (0xBu<<16)
#define ETH_MAC_IACR_MSEL_B_0XC                                     (0xCu<<16)
#define ETH_MAC_IACR_MSEL_B_0XD                                     (0xDu<<16)
#define ETH_MAC_IACR_MSEL_B_0XE                                     (0xEu<<16)
#define ETH_MAC_IACR_MSEL_B_0XF                                     (0xFu<<16)
#define ETH_MAC_IACR_AOFF_B_0X0                                     (0x0u<<8)
#define ETH_MAC_IACR_AOFF_B_0X1                                     (0x1u<<8)
#define ETH_MAC_IACR_AOFF_B_0X7                                     (0x7u<<8)
#define ETH_MAC_IACR_AUTO_B_0X1                                     (0x1u<<5)
#define ETH_MAC_IACR_AUTO_B_0X0                                     (0x0u<<5)
#define ETH_MAC_IACR_COM_B_0X1                                      (0x1u<<1)
#define ETH_MAC_IACR_COM_B_0X0                                      (0x0u<<1)

// MAC_TMRQR Configuration

#define ETH_MAC_TMRQR_PFEX                                          (0x1u<<20)
#define ETH_MAC_TMRQR_TMRQ                                          (0x7u<<16)
#define ETH_MAC_TMRQR_TMRQ_0                                        (0x1u<<16)
#define ETH_MAC_TMRQR_TYP                                           (0xFFFFu<<0)
#define ETH_MAC_TMRQR_TYP_0                                         (0x1u<<0)

#define ETH_MAC_TMRQR_PFEX_B_0X0                                    (0x0u<<20)
#define ETH_MAC_TMRQR_PFEX_B_0X1                                    (0x1u<<20)

// MACTSCR Configuration

#define ETH_MACTSCR_AV8021ASMEN                                     (0x1u<<28)
#define ETH_MACTSCR_TXTSSTSM                                        (0x1u<<24)
#define ETH_MACTSCR_TSENMACADDR                                     (0x1u<<18)
#define ETH_MACTSCR_SNAPTYPSEL                                      (0x3u<<16)
#define ETH_MACTSCR_SNAPTYPSEL_0                                    (0x1u<<16)
#define ETH_MACTSCR_TSMSTRENA                                       (0x1u<<15)
#define ETH_MACTSCR_TSEVNTENA                                       (0x1u<<14)
#define ETH_MACTSCR_TSIPV4ENA                                       (0x1u<<13)
#define ETH_MACTSCR_TSIPV6ENA                                       (0x1u<<12)
#define ETH_MACTSCR_TSIPENA                                         (0x1u<<11)
#define ETH_MACTSCR_TSVER2ENA                                       (0x1u<<10)
#define ETH_MACTSCR_TSCTRLSSR                                       (0x1u<<9)
#define ETH_MACTSCR_TSENALL                                         (0x1u<<8)
#define ETH_MACTSCR_PTGE                                            (0x1u<<6)
#define ETH_MACTSCR_TSADDREG                                        (0x1u<<5)
#define ETH_MACTSCR_TSUPDT                                          (0x1u<<3)
#define ETH_MACTSCR_TSINIT                                          (0x1u<<2)
#define ETH_MACTSCR_TSCFUPDT                                        (0x1u<<1)
#define ETH_MACTSCR_TSENA                                           (0x1u<<0)

// MACSSIR Configuration

#define ETH_MACSSIR_SSINC                                           (0xFFu<<16)
#define ETH_MACSSIR_SSINC_0                                         (0x1u<<16)

// MACSTSR Configuration

#define ETH_MACSTSR_TSS                                             (0xFFFFFFFFu<<0)
#define ETH_MACSTSR_TSS_0                                           (0x1u<<0)

// MACSTNR Configuration

#define ETH_MACSTNR_TSSS                                            (0x7FFFFFFFu<<0)
#define ETH_MACSTNR_TSSS_0                                          (0x1u<<0)

// MACSTSUR Configuration

#define ETH_MACSTSUR_TSS                                            (0xFFFFFFFFu<<0)
#define ETH_MACSTSUR_TSS_0                                          (0x1u<<0)

// MACSTNUR Configuration

#define ETH_MACSTNUR_ADDSUB                                         (0x1u<<31)
#define ETH_MACSTNUR_TSSS                                           (0x7FFFFFFFu<<0)
#define ETH_MACSTNUR_TSSS_0                                         (0x1u<<0)

// MACTSAR Configuration

#define ETH_MACTSAR_TSAR                                            (0xFFFFFFFFu<<0)
#define ETH_MACTSAR_TSAR_0                                          (0x1u<<0)

// MACTSSR Configuration

#define ETH_MACTSSR_ATSNS                                           (0x1Fu<<25)
#define ETH_MACTSSR_ATSNS_0                                         (0x1u<<25)
#define ETH_MACTSSR_ATSSTM                                          (0x1u<<24)
#define ETH_MACTSSR_ATSSTN                                          (0xFu<<16)
#define ETH_MACTSSR_ATSSTN_0                                        (0x1u<<16)
#define ETH_MACTSSR_TXTSSIS                                         (0x1u<<15)
#define ETH_MACTSSR_TSTRGTERR1                                      (0x1u<<5)
#define ETH_MACTSSR_TSTARGT1                                        (0x1u<<4)
#define ETH_MACTSSR_TSTRGTERR0                                      (0x1u<<3)
#define ETH_MACTSSR_AUXTSTRIG                                       (0x1u<<2)
#define ETH_MACTSSR_TSTARGT0                                        (0x1u<<1)
#define ETH_MACTSSR_TSSOVF                                          (0x1u<<0)

// MACRXDTI Configuration

#define ETH_MACRXDTI_RXNS                                           (0xFFFFu<<16)
#define ETH_MACRXDTI_RXNS_0                                         (0x1u<<16)

// MACTXDTI Configuration

#define ETH_MACTXDTI_TXNS                                           (0xFFFFu<<16)
#define ETH_MACTXDTI_TXNS_0                                         (0x1u<<16)

// MACTXTSSNR Configuration

#define ETH_MACTXTSSNR_TXTSSMIS                                     (0x1u<<31)
#define ETH_MACTXTSSNR_TXTSSLO                                      (0x7FFFFFFFu<<0)
#define ETH_MACTXTSSNR_TXTSSLO_0                                    (0x1u<<0)

// MACTXTSSSR Configuration

#define ETH_MACTXTSSSR_TXTSSHI                                      (0xFFFFFFFFu<<0)
#define ETH_MACTXTSSSR_TXTSSHI_0                                    (0x1u<<0)

// MACACR Configuration

#define ETH_MACACR_ATSEN3                                           (0x1u<<7)
#define ETH_MACACR_ATSEN2                                           (0x1u<<6)
#define ETH_MACACR_ATSEN1                                           (0x1u<<5)
#define ETH_MACACR_ATSEN0                                           (0x1u<<4)
#define ETH_MACACR_ATSFC                                            (0x1u<<0)

// MACATSNR Configuration

#define ETH_MACATSNR_AUXTSLO                                        (0x7FFFFFFFu<<0)
#define ETH_MACATSNR_AUXTSLO_0                                      (0x1u<<0)

// MACATSSR Configuration

#define ETH_MACATSSR_AUXTSHI                                        (0xFFFFFFFFu<<0)
#define ETH_MACATSSR_AUXTSHI_0                                      (0x1u<<0)

// MACTSIACR Configuration

#define ETH_MACTSIACR_OSTIAC                                        (0xFFFFFFFFu<<0)
#define ETH_MACTSIACR_OSTIAC_0                                      (0x1u<<0)

// MACTSEACR Configuration

#define ETH_MACTSEACR_OSTEAC                                        (0xFFFFFFFFu<<0)
#define ETH_MACTSEACR_OSTEAC_0                                      (0x1u<<0)

// MACTSICNR Configuration

#define ETH_MACTSICNR_TSIC                                          (0xFFFFFFFFu<<0)
#define ETH_MACTSICNR_TSIC_0                                        (0x1u<<0)

// MACTSECNR Configuration

#define ETH_MACTSECNR_TSEC                                          (0xFFFFFFFFu<<0)
#define ETH_MACTSECNR_TSEC_0                                        (0x1u<<0)

// MACTSILR Configuration

#define ETH_MACTSILR_ITLNS                                          (0xFFFu<<16)
#define ETH_MACTSILR_ITLNS_0                                        (0x1u<<16)
#define ETH_MACTSILR_ITLSNS                                         (0xFFu<<8)
#define ETH_MACTSILR_ITLSNS_0                                       (0x1u<<8)

// MACTSELR Configuration

#define ETH_MACTSELR_ETLNS                                          (0xFFFu<<16)
#define ETH_MACTSELR_ETLNS_0                                        (0x1u<<16)
#define ETH_MACTSELR_ETLSNS                                         (0xFFu<<8)
#define ETH_MACTSELR_ETLSNS_0                                       (0x1u<<8)

// MACPPSCR Configuration

#define ETH_MACPPSCR_TIMESEL                                        (0x1u<<28)
#define ETH_MACPPSCR_MCGREN0                                        (0x1u<<7)
#define ETH_MACPPSCR_TRGTMODSEL0                                    (0x3u<<5)
#define ETH_MACPPSCR_TRGTMODSEL0_0                                  (0x1u<<5)
#define ETH_MACPPSCR_PPSEN0                                         (0x1u<<4)
#define ETH_MACPPSCR_PPSCTRL                                        (0xFu<<0)
#define ETH_MACPPSCR_PPSCTRL_0                                      (0x1u<<0)

#define ETH_MACPPSCR_MCGREN0_B_0X0                                  (0x0u<<7)
#define ETH_MACPPSCR_MCGREN0_B_0X1                                  (0x1u<<7)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X0                              (0x0u<<5)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X1                              (0x1u<<5)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X2                              (0x2u<<5)
#define ETH_MACPPSCR_TRGTMODSEL0_B_0X3                              (0x3u<<5)
#define ETH_MACPPSCR_PPSCTRL_B_0X1                                  (0x1u<<0)
#define ETH_MACPPSCR_PPSCTRL_B_0X2                                  (0x2u<<0)
#define ETH_MACPPSCR_PPSCTRL_B_0X3                                  (0x3u<<0)
#define ETH_MACPPSCR_PPSCTRL_B_0X4                                  (0x4u<<0)
#define ETH_MACPPSCR_PPSCTRL_B_0XF                                  (0xFu<<0)

// MACPPSCR_ALTERNATE1 Configuration

#define ETH_MACPPSCR_ALTERNATE1_TIMESEL                             (0x1u<<28)
#define ETH_MACPPSCR_ALTERNATE1_MCGREN1                             (0x1u<<15)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1                         (0x3u<<13)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1_0                       (0x1u<<13)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD1                             (0xFu<<8)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD1_0                           (0x1u<<8)
#define ETH_MACPPSCR_ALTERNATE1_MCGREN0                             (0x1u<<7)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0                         (0x3u<<5)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0_0                       (0x1u<<5)
#define ETH_MACPPSCR_ALTERNATE1_PPSEN0                              (0x1u<<4)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD                              (0xFu<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_0                            (0x1u<<0)

#define ETH_MACPPSCR_ALTERNATE1_MCGREN1_B_0X0                       (0x0u<<15)
#define ETH_MACPPSCR_ALTERNATE1_MCGREN1_B_0X1                       (0x1u<<15)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1_B_0X0                   (0x0u<<13)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1_B_0X1                   (0x1u<<13)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1_B_0X2                   (0x2u<<13)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL1_B_0X3                   (0x3u<<13)
#define ETH_MACPPSCR_ALTERNATE1_MCGREN0_B_0X0                       (0x0u<<7)
#define ETH_MACPPSCR_ALTERNATE1_MCGREN0_B_0X1                       (0x1u<<7)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0_B_0X0                   (0x0u<<5)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0_B_0X1                   (0x1u<<5)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0_B_0X2                   (0x2u<<5)
#define ETH_MACPPSCR_ALTERNATE1_TRGTMODSEL0_B_0X3                   (0x3u<<5)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X0                        (0x0u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X1                        (0x1u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X2                        (0x2u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X3                        (0x3u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X4                        (0x4u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X5                        (0x5u<<0)
#define ETH_MACPPSCR_ALTERNATE1_PPSCMD_B_0X6                        (0x6u<<0)

// MACPPSTTS0R Configuration

#define ETH_MACPPSTTS0R_TSTRH0                                      (0xFFFFFFFFu<<0)
#define ETH_MACPPSTTS0R_TSTRH0_0                                    (0x1u<<0)

// MACPPSTTN0R Configuration

#define ETH_MACPPSTTN0R_TRGTBUSY0                                   (0x1u<<31)
#define ETH_MACPPSTTN0R_TTSL0                                       (0x7FFFFFFFu<<0)
#define ETH_MACPPSTTN0R_TTSL0_0                                     (0x1u<<0)

// MACPPSI0R Configuration

#define ETH_MACPPSI0R_PPSINT0                                       (0xFFFFFFFFu<<0)
#define ETH_MACPPSI0R_PPSINT0_0                                     (0x1u<<0)

// MACPPSW0R Configuration

#define ETH_MACPPSW0R_PPSWIDTH0                                     (0xFFFFFFFFu<<0)
#define ETH_MACPPSW0R_PPSWIDTH0_0                                   (0x1u<<0)

// MACPPSTTS1R Configuration

#define ETH_MACPPSTTS1R_TSTRH0                                      (0xFFFFFFFFu<<0)
#define ETH_MACPPSTTS1R_TSTRH0_0                                    (0x1u<<0)

// MACPPSTTN1R Configuration

#define ETH_MACPPSTTN1R_TRGTBUSY0                                   (0x1u<<31)
#define ETH_MACPPSTTN1R_TTSL0                                       (0x7FFFFFFFu<<0)
#define ETH_MACPPSTTN1R_TTSL0_0                                     (0x1u<<0)

// MACPPSI1R Configuration

#define ETH_MACPPSI1R_PPSINT0                                       (0xFFFFFFFFu<<0)
#define ETH_MACPPSI1R_PPSINT0_0                                     (0x1u<<0)

// MACPPSW1R Configuration

#define ETH_MACPPSW1R_PPSWIDTH0                                     (0xFFFFFFFFu<<0)
#define ETH_MACPPSW1R_PPSWIDTH0_0                                   (0x1u<<0)

// MACPOCR Configuration

#define ETH_MACPOCR_DN                                              (0xFFu<<8)
#define ETH_MACPOCR_DN_0                                            (0x1u<<8)
#define ETH_MACPOCR_PDRDIS                                          (0x1u<<7)
#define ETH_MACPOCR_DRRDIS                                          (0x1u<<6)
#define ETH_MACPOCR_APDREQTRIG                                      (0x1u<<5)
#define ETH_MACPOCR_ASYNCTRIG                                       (0x1u<<4)
#define ETH_MACPOCR_APDREQEN                                        (0x1u<<2)
#define ETH_MACPOCR_ASYNCEN                                         (0x1u<<1)
#define ETH_MACPOCR_PTOEN                                           (0x1u<<0)

// MACSPI0R Configuration

#define ETH_MACSPI0R_SPI0                                           (0xFFFFFFFFu<<0)
#define ETH_MACSPI0R_SPI0_0                                         (0x1u<<0)

// MACSPI1R Configuration

#define ETH_MACSPI1R_SPI1                                           (0xFFFFFFFFu<<0)
#define ETH_MACSPI1R_SPI1_0                                         (0x1u<<0)

// MACSPI2R Configuration

#define ETH_MACSPI2R_SPI2                                           (0xFFFFu<<0)
#define ETH_MACSPI2R_SPI2_0                                         (0x1u<<0)

// MACLMIR Configuration

#define ETH_MACLMIR_LMPDRI                                          (0xFFu<<24)
#define ETH_MACLMIR_LMPDRI_0                                        (0x1u<<24)
#define ETH_MACLMIR_DRSYNCR                                         (0x7u<<8)
#define ETH_MACLMIR_DRSYNCR_0                                       (0x1u<<8)
#define ETH_MACLMIR_LSI                                             (0xFFu<<0)
#define ETH_MACLMIR_LSI_0                                           (0x1u<<0)

#define ETH_MACLMIR_DRSYNCR_B_0X0                                   (0x0u<<8)
#define ETH_MACLMIR_DRSYNCR_B_0X1                                   (0x1u<<8)

// MTLOMR Configuration

#define ETH_MTLOMR_CNTCLR                                           (0x1u<<9)
#define ETH_MTLOMR_CNTPRST                                          (0x1u<<8)
#define ETH_MTLOMR_SCHALG                                           (0x3u<<5)
#define ETH_MTLOMR_SCHALG_0                                         (0x1u<<5)
#define ETH_MTLOMR_RAA                                              (0x1u<<2)
#define ETH_MTLOMR_DTXSTS                                           (0x1u<<1)

#define ETH_MTLOMR_SCHALG_B_0X0                                     (0x0u<<5)
#define ETH_MTLOMR_SCHALG_B_0X3                                     (0x3u<<5)
#define ETH_MTLOMR_RAA_B_0X0                                        (0x0u<<2)
#define ETH_MTLOMR_RAA_B_0X1                                        (0x1u<<2)

// MTLISR Configuration

#define ETH_MTLISR_ESTIS                                            (0x1u<<18)
#define ETH_MTLISR_Q3IS                                             (0x1u<<3)
#define ETH_MTLISR_Q2IS                                             (0x1u<<2)
#define ETH_MTLISR_Q1IS                                             (0x1u<<1)
#define ETH_MTLISR_Q0IS                                             (0x1u<<0)

// MTLRXQDMAMR Configuration

#define ETH_MTLRXQDMAMR_Q1DDMACH                                    (0x1u<<12)
#define ETH_MTLRXQDMAMR_Q1MDMACH                                    (0x1u<<8)
#define ETH_MTLRXQDMAMR_Q0DDMACH                                    (0x1u<<4)
#define ETH_MTLRXQDMAMR_Q0MDMACH                                    (0x1u<<0)

#define ETH_MTLRXQDMAMR_Q1MDMACH_B_0X0                              (0x0u<<8)
#define ETH_MTLRXQDMAMR_Q1MDMACH_B_0X1                              (0x1u<<8)
#define ETH_MTLRXQDMAMR_Q0MDMACH_B_0X0                              (0x0u<<0)
#define ETH_MTLRXQDMAMR_Q0MDMACH_B_0X1                              (0x1u<<0)

// MTLTBSCR Configuration

#define ETH_MTLTBSCR_LEOS                                           (0xFFFFFFu<<8)
#define ETH_MTLTBSCR_LEOS_0                                         (0x1u<<8)
#define ETH_MTLTBSCR_LEGOS                                          (0x7u<<4)
#define ETH_MTLTBSCR_LEGOS_0                                        (0x1u<<4)
#define ETH_MTLTBSCR_LEOV                                           (0x1u<<1)
#define ETH_MTLTBSCR_ESTM                                           (0x1u<<0)

#define ETH_MTLTBSCR_LEOV_B_0X0                                     (0x0u<<1)
#define ETH_MTLTBSCR_LEOV_B_0X1                                     (0x1u<<1)
#define ETH_MTLTBSCR_ESTM_B_0X0                                     (0x0u<<0)
#define ETH_MTLTBSCR_ESTM_B_0X1                                     (0x1u<<0)

// MTLESTCR Configuration

#define ETH_MTLESTCR_PTOV                                           (0xFFu<<24)
#define ETH_MTLESTCR_PTOV_0                                         (0x1u<<24)
#define ETH_MTLESTCR_CTOV                                           (0xFFFu<<12)
#define ETH_MTLESTCR_CTOV_0                                         (0x1u<<12)
#define ETH_MTLESTCR_TILS                                           (0x7u<<8)
#define ETH_MTLESTCR_TILS_0                                         (0x1u<<8)
#define ETH_MTLESTCR_LCSE                                           (0x3u<<6)
#define ETH_MTLESTCR_LCSE_0                                         (0x1u<<6)
#define ETH_MTLESTCR_DFBS                                           (0x1u<<5)
#define ETH_MTLESTCR_DDBF                                           (0x1u<<4)
#define ETH_MTLESTCR_SSWL                                           (0x1u<<1)
#define ETH_MTLESTCR_EEST                                           (0x1u<<0)

#define ETH_MTLESTCR_TILS_B_0X0                                     (0x0u<<8)
#define ETH_MTLESTCR_TILS_B_0X1                                     (0x1u<<8)
#define ETH_MTLESTCR_TILS_B_0X2                                     (0x2u<<8)
#define ETH_MTLESTCR_TILS_B_0X4                                     (0x4u<<8)
#define ETH_MTLESTCR_LCSE_B_0X0                                     (0x0u<<6)
#define ETH_MTLESTCR_LCSE_B_0X1                                     (0x1u<<6)
#define ETH_MTLESTCR_LCSE_B_0X2                                     (0x2u<<6)
#define ETH_MTLESTCR_LCSE_B_0X3                                     (0x3u<<6)
#define ETH_MTLESTCR_DFBS_B_0X0                                     (0x0u<<5)
#define ETH_MTLESTCR_DFBS_B_0X1                                     (0x1u<<5)
#define ETH_MTLESTCR_DDBF_B_0X0                                     (0x0u<<4)
#define ETH_MTLESTCR_DDBF_B_0X1                                     (0x1u<<4)
#define ETH_MTLESTCR_EEST_B_0X0                                     (0x0u<<0)
#define ETH_MTLESTCR_EEST_B_0X1                                     (0x1u<<0)

// MTLESTECR Configuration

#define ETH_MTLESTECR_OVHD                                          (0x3Fu<<0)
#define ETH_MTLESTECR_OVHD_0                                        (0x1u<<0)

// MTLESTSR Configuration

#define ETH_MTLESTSR_CGSN                                           (0xFu<<16)
#define ETH_MTLESTSR_CGSN_0                                         (0x1u<<16)
#define ETH_MTLESTSR_BTRL                                           (0xFFu<<8)
#define ETH_MTLESTSR_BTRL_0                                         (0x1u<<8)
#define ETH_MTLESTSR_SWOL                                           (0x1u<<7)
#define ETH_MTLESTSR_CGCE                                           (0x1u<<4)
#define ETH_MTLESTSR_HLBS                                           (0x1u<<3)
#define ETH_MTLESTSR_HLBF                                           (0x1u<<2)
#define ETH_MTLESTSR_BTRE                                           (0x1u<<1)
#define ETH_MTLESTSR_SWLC                                           (0x1u<<0)

#define ETH_MTLESTSR_SWOL_B_0X0                                     (0x0u<<7)
#define ETH_MTLESTSR_SWOL_B_0X1                                     (0x1u<<7)
#define ETH_MTLESTSR_CGCE_B_0X0                                     (0x0u<<4)
#define ETH_MTLESTSR_CGCE_B_0X1                                     (0x1u<<4)
#define ETH_MTLESTSR_HLBS_B_0X0                                     (0x0u<<3)
#define ETH_MTLESTSR_HLBS_B_0X1                                     (0x1u<<3)
#define ETH_MTLESTSR_BTRE_B_0X0                                     (0x0u<<1)
#define ETH_MTLESTSR_BTRE_B_0X1                                     (0x1u<<1)
#define ETH_MTLESTSR_SWLC_B_0X0                                     (0x0u<<0)
#define ETH_MTLESTSR_SWLC_B_0X1                                     (0x1u<<0)

// MTLESTSCHER Configuration

#define ETH_MTLESTSCHER_SEQN                                        (0xFu<<0)
#define ETH_MTLESTSCHER_SEQN_0                                      (0x1u<<0)

// MTLESTFSER Configuration

#define ETH_MTLESTFSER_FEQN                                         (0xFu<<0)
#define ETH_MTLESTFSER_FEQN_0                                       (0x1u<<0)

// MTLESTFSCR Configuration

#define ETH_MTLESTFSCR_HBFQ                                         (0x3u<<16)
#define ETH_MTLESTFSCR_HBFQ_0                                       (0x1u<<16)
#define ETH_MTLESTFSCR_HBFS                                         (0x7FFFu<<0)
#define ETH_MTLESTFSCR_HBFS_0                                       (0x1u<<0)

// MTLESTIER Configuration

#define ETH_MTLESTIER_CGCE                                          (0x1u<<4)
#define ETH_MTLESTIER_IEHS                                          (0x1u<<3)
#define ETH_MTLESTIER_IEHF                                          (0x1u<<2)
#define ETH_MTLESTIER_IEBE                                          (0x1u<<1)
#define ETH_MTLESTIER_IECC                                          (0x1u<<0)

// MTLESTGCLCR Configuration

#define ETH_MTLESTGCLCR_ADDR                                        (0x3Fu<<8)
#define ETH_MTLESTGCLCR_ADDR_0                                      (0x1u<<8)
#define ETH_MTLESTGCLCR_DBGB                                        (0x1u<<5)
#define ETH_MTLESTGCLCR_DBGM                                        (0x1u<<4)
#define ETH_MTLESTGCLCR_GCRR                                        (0x1u<<2)
#define ETH_MTLESTGCLCR_R1W0                                        (0x1u<<1)
#define ETH_MTLESTGCLCR_SRWO                                        (0x1u<<0)

#define ETH_MTLESTGCLCR_ADDR_B_0X0_GCRR__EQUAL_1                    (0x0u<<8)
#define ETH_MTLESTGCLCR_ADDR_B_0X1_GCRR__EQUAL_1                    (0x1u<<8)
#define ETH_MTLESTGCLCR_ADDR_B_0X2_GCRR__EQUAL_1                    (0x2u<<8)
#define ETH_MTLESTGCLCR_ADDR_B_0X3_GCRR__EQUAL_1                    (0x3u<<8)
#define ETH_MTLESTGCLCR_ADDR_B_0X4_GCRR__EQUAL_1                    (0x4u<<8)
#define ETH_MTLESTGCLCR_ADDR_B_0X5_GCRR__EQUAL_1                    (0x5u<<8)
#define ETH_MTLESTGCLCR_DBGB_B_0X0                                  (0x0u<<5)
#define ETH_MTLESTGCLCR_DBGB_B_0X1                                  (0x1u<<5)
#define ETH_MTLESTGCLCR_R1W0_B_0X1                                  (0x1u<<1)
#define ETH_MTLESTGCLCR_R1W0_B_0X0                                  (0x0u<<1)
#define ETH_MTLESTGCLCR_SRWO_B_0X1                                  (0x1u<<0)

// MTLESTGCLDR Configuration

#define ETH_MTLESTGCLDR_GCD                                         (0xFFFFFFFFu<<0)
#define ETH_MTLESTGCLDR_GCD_0                                       (0x1u<<0)

// MTLFPECSR Configuration

#define ETH_MTLFPECSR_HRS                                           (0x1u<<28)
#define ETH_MTLFPECSR_PEC                                           (0xFu<<8)
#define ETH_MTLFPECSR_PEC_0                                         (0x1u<<8)
#define ETH_MTLFPECSR_LBHT                                          (0x1u<<7)
#define ETH_MTLFPECSR_AFSZ                                          (0x3u<<0)
#define ETH_MTLFPECSR_AFSZ_0                                        (0x1u<<0)

#define ETH_MTLFPECSR_HRS_B_0X1                                     (0x1u<<28)
#define ETH_MTLFPECSR_HRS_B_0X0                                     (0x0u<<28)

// MTLFPEAR Configuration

#define ETH_MTLFPEAR_RADV                                           (0xFFFFu<<16)
#define ETH_MTLFPEAR_RADV_0                                         (0x1u<<16)
#define ETH_MTLFPEAR_HADV                                           (0xFFFFu<<0)
#define ETH_MTLFPEAR_HADV_0                                         (0x1u<<0)

// MTLTXQ0OMR Configuration

#define ETH_MTLTXQ0OMR_TQS                                          (0x1Fu<<16)
#define ETH_MTLTXQ0OMR_TQS_0                                        (0x1u<<16)
#define ETH_MTLTXQ0OMR_TTC                                          (0x7u<<4)
#define ETH_MTLTXQ0OMR_TTC_0                                        (0x1u<<4)
#define ETH_MTLTXQ0OMR_TXQEN                                        (0x3u<<2)
#define ETH_MTLTXQ0OMR_TXQEN_0                                      (0x1u<<2)
#define ETH_MTLTXQ0OMR_TSF                                          (0x1u<<1)
#define ETH_MTLTXQ0OMR_FTQ                                          (0x1u<<0)

#define ETH_MTLTXQ0OMR_TTC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X4                                    (0x4u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X5                                    (0x5u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X6                                    (0x6u<<4)
#define ETH_MTLTXQ0OMR_TTC_B_0X7                                    (0x7u<<4)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X0                                  (0x0u<<2)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X1                                  (0x1u<<2)
#define ETH_MTLTXQ0OMR_TXQEN_B_0X2                                  (0x2u<<2)

// MTLTXQ0UR Configuration

#define ETH_MTLTXQ0UR_UFCNTOVF                                      (0x1u<<11)
#define ETH_MTLTXQ0UR_UFFRMCNT                                      (0x7FFu<<0)
#define ETH_MTLTXQ0UR_UFFRMCNT_0                                    (0x1u<<0)

// MTLTXQ0DR Configuration

#define ETH_MTLTXQ0DR_STXSTSF                                       (0x7u<<20)
#define ETH_MTLTXQ0DR_STXSTSF_0                                     (0x1u<<20)
#define ETH_MTLTXQ0DR_PTXQ                                          (0x7u<<16)
#define ETH_MTLTXQ0DR_PTXQ_0                                        (0x1u<<16)
#define ETH_MTLTXQ0DR_TXSTSFSTS                                     (0x1u<<5)
#define ETH_MTLTXQ0DR_TXQSTS                                        (0x1u<<4)
#define ETH_MTLTXQ0DR_TWCSTS                                        (0x1u<<3)
#define ETH_MTLTXQ0DR_TRCSTS                                        (0x3u<<1)
#define ETH_MTLTXQ0DR_TRCSTS_0                                      (0x1u<<1)
#define ETH_MTLTXQ0DR_TXQPAUSED                                     (0x1u<<0)

#define ETH_MTLTXQ0DR_TRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLTXQ0DR_TRCSTS_B_0X3                                  (0x3u<<1)

// MTLTXQ0ESR Configuration

#define ETH_MTLTXQ0ESR_ABS                                          (0xFFFFFFu<<0)
#define ETH_MTLTXQ0ESR_ABS_0                                        (0x1u<<0)

// MTLTXQ0QWR Configuration

#define ETH_MTLTXQ0QWR_ISCQW                                        (0x3FFFu<<0)
#define ETH_MTLTXQ0QWR_ISCQW_0                                      (0x1u<<0)

// MTLQ0ICSR Configuration

#define ETH_MTLQ0ICSR_RXOIE                                         (0x1u<<24)
#define ETH_MTLQ0ICSR_RXOVFIS                                       (0x1u<<16)
#define ETH_MTLQ0ICSR_ABPSIE                                        (0x1u<<9)
#define ETH_MTLQ0ICSR_TXUIE                                         (0x1u<<8)
#define ETH_MTLQ0ICSR_ABPSIS                                        (0x1u<<1)
#define ETH_MTLQ0ICSR_TXUNFIS                                       (0x1u<<0)

// MTLRXQ0OMR Configuration

#define ETH_MTLRXQ0OMR_RQS                                          (0xFu<<20)
#define ETH_MTLRXQ0OMR_RQS_0                                        (0x1u<<20)
#define ETH_MTLRXQ0OMR_RFD                                          (0x7u<<14)
#define ETH_MTLRXQ0OMR_RFD_0                                        (0x1u<<14)
#define ETH_MTLRXQ0OMR_RFA                                          (0x7u<<8)
#define ETH_MTLRXQ0OMR_RFA_0                                        (0x1u<<8)
#define ETH_MTLRXQ0OMR_EHFC                                         (0x1u<<7)
#define ETH_MTLRXQ0OMR_DIS_TCP_EF                                   (0x1u<<6)
#define ETH_MTLRXQ0OMR_RSF                                          (0x1u<<5)
#define ETH_MTLRXQ0OMR_FEP                                          (0x1u<<4)
#define ETH_MTLRXQ0OMR_FUP                                          (0x1u<<3)
#define ETH_MTLRXQ0OMR_RTC                                          (0x3u<<0)
#define ETH_MTLRXQ0OMR_RTC_0                                        (0x1u<<0)

#define ETH_MTLRXQ0OMR_RFD_B_0X0                                    (0x0u<<14)
#define ETH_MTLRXQ0OMR_RFD_B_0X1                                    (0x1u<<14)
#define ETH_MTLRXQ0OMR_RTC_B_0X0                                    (0x0u<<0)
#define ETH_MTLRXQ0OMR_RTC_B_0X1                                    (0x1u<<0)
#define ETH_MTLRXQ0OMR_RTC_B_0X2                                    (0x2u<<0)
#define ETH_MTLRXQ0OMR_RTC_B_0X3                                    (0x3u<<0)

// MTLRXQ0MPOCR Configuration

#define ETH_MTLRXQ0MPOCR_MISCNTOVF                                  (0x1u<<27)
#define ETH_MTLRXQ0MPOCR_MISPKTCNT                                  (0x7FFu<<16)
#define ETH_MTLRXQ0MPOCR_MISPKTCNT_0                                (0x1u<<16)
#define ETH_MTLRXQ0MPOCR_OVFCNTOVF                                  (0x1u<<11)
#define ETH_MTLRXQ0MPOCR_OVFPKTCNT                                  (0x7FFu<<0)
#define ETH_MTLRXQ0MPOCR_OVFPKTCNT_0                                (0x1u<<0)

// MTLRXQ0DR Configuration

#define ETH_MTLRXQ0DR_PRXQ                                          (0x3FFFu<<16)
#define ETH_MTLRXQ0DR_PRXQ_0                                        (0x1u<<16)
#define ETH_MTLRXQ0DR_RXQSTS                                        (0x3u<<4)
#define ETH_MTLRXQ0DR_RXQSTS_0                                      (0x1u<<4)
#define ETH_MTLRXQ0DR_RRCSTS                                        (0x3u<<1)
#define ETH_MTLRXQ0DR_RRCSTS_0                                      (0x1u<<1)
#define ETH_MTLRXQ0DR_RWCSTS                                        (0x1u<<0)

#define ETH_MTLRXQ0DR_RXQSTS_B_0X0                                  (0x0u<<4)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X1                                  (0x1u<<4)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X2                                  (0x2u<<4)
#define ETH_MTLRXQ0DR_RXQSTS_B_0X3                                  (0x3u<<4)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLRXQ0DR_RRCSTS_B_0X3                                  (0x3u<<1)

// MTLRXQ0CR Configuration

#define ETH_MTLRXQ0CR_RXQ_FRM_ARBIT                                 (0x1u<<3)
#define ETH_MTLRXQ0CR_RXQ_WEGT                                      (0x7u<<0)
#define ETH_MTLRXQ0CR_RXQ_WEGT_0                                    (0x1u<<0)

// MTLTXQ1OMR Configuration

#define ETH_MTLTXQ1OMR_TQS                                          (0x1Fu<<16)
#define ETH_MTLTXQ1OMR_TQS_0                                        (0x1u<<16)
#define ETH_MTLTXQ1OMR_TTC                                          (0x7u<<4)
#define ETH_MTLTXQ1OMR_TTC_0                                        (0x1u<<4)
#define ETH_MTLTXQ1OMR_TXQEN                                        (0x3u<<2)
#define ETH_MTLTXQ1OMR_TXQEN_0                                      (0x1u<<2)
#define ETH_MTLTXQ1OMR_TSF                                          (0x1u<<1)
#define ETH_MTLTXQ1OMR_FTQ                                          (0x1u<<0)

#define ETH_MTLTXQ1OMR_TTC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X4                                    (0x4u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X5                                    (0x5u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X6                                    (0x6u<<4)
#define ETH_MTLTXQ1OMR_TTC_B_0X7                                    (0x7u<<4)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X0                                  (0x0u<<2)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X1                                  (0x1u<<2)
#define ETH_MTLTXQ1OMR_TXQEN_B_0X2                                  (0x2u<<2)

// MTLTXQ1UR Configuration

#define ETH_MTLTXQ1UR_UFCNTOVF                                      (0x1u<<11)
#define ETH_MTLTXQ1UR_UFFRMCNT                                      (0x7FFu<<0)
#define ETH_MTLTXQ1UR_UFFRMCNT_0                                    (0x1u<<0)

// MTLTXQ1DR Configuration

#define ETH_MTLTXQ1DR_STXSTSF                                       (0x7u<<20)
#define ETH_MTLTXQ1DR_STXSTSF_0                                     (0x1u<<20)
#define ETH_MTLTXQ1DR_PTXQ                                          (0x7u<<16)
#define ETH_MTLTXQ1DR_PTXQ_0                                        (0x1u<<16)
#define ETH_MTLTXQ1DR_TXSTSFSTS                                     (0x1u<<5)
#define ETH_MTLTXQ1DR_TXQSTS                                        (0x1u<<4)
#define ETH_MTLTXQ1DR_TWCSTS                                        (0x1u<<3)
#define ETH_MTLTXQ1DR_TRCSTS                                        (0x3u<<1)
#define ETH_MTLTXQ1DR_TRCSTS_0                                      (0x1u<<1)
#define ETH_MTLTXQ1DR_TXQPAUSED                                     (0x1u<<0)

#define ETH_MTLTXQ1DR_TRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLTXQ1DR_TRCSTS_B_0X3                                  (0x3u<<1)

// MTLTXQ1ECR Configuration

#define ETH_MTLTXQ1ECR_SLC                                          (0x7u<<4)
#define ETH_MTLTXQ1ECR_SLC_0                                        (0x1u<<4)
#define ETH_MTLTXQ1ECR_CC                                           (0x1u<<3)
#define ETH_MTLTXQ1ECR_AVALG                                        (0x1u<<2)

#define ETH_MTLTXQ1ECR_SLC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ1ECR_SLC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ1ECR_SLC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ1ECR_SLC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ1ECR_SLC_B_0X4                                    (0x4u<<4)

// MTLTXQ1ESR Configuration

#define ETH_MTLTXQ1ESR_ABS                                          (0xFFFFFFu<<0)
#define ETH_MTLTXQ1ESR_ABS_0                                        (0x1u<<0)

// MTLTXQ1QWR Configuration

#define ETH_MTLTXQ1QWR_ISCQW                                        (0x3FFFu<<0)
#define ETH_MTLTXQ1QWR_ISCQW_0                                      (0x1u<<0)

// MTLTXQ1SSCR Configuration

#define ETH_MTLTXQ1SSCR_SSC                                         (0x3FFFu<<0)
#define ETH_MTLTXQ1SSCR_SSC_0                                       (0x1u<<0)

// MTLTXQ1HCR Configuration

#define ETH_MTLTXQ1HCR_HC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ1HCR_HC_0                                         (0x1u<<0)

// MTLTXQ1LCR Configuration

#define ETH_MTLTXQ1LCR_LC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ1LCR_LC_0                                         (0x1u<<0)

// MTLQ1ICSR Configuration

#define ETH_MTLQ1ICSR_RXOIE                                         (0x1u<<24)
#define ETH_MTLQ1ICSR_RXOVFIS                                       (0x1u<<16)
#define ETH_MTLQ1ICSR_ABPSIE                                        (0x1u<<9)
#define ETH_MTLQ1ICSR_TXUIE                                         (0x1u<<8)
#define ETH_MTLQ1ICSR_ABPSIS                                        (0x1u<<1)
#define ETH_MTLQ1ICSR_TXUNFIS                                       (0x1u<<0)

// MTLRXQ1OMR Configuration

#define ETH_MTLRXQ1OMR_RQS                                          (0xFu<<20)
#define ETH_MTLRXQ1OMR_RQS_0                                        (0x1u<<20)
#define ETH_MTLRXQ1OMR_RFD                                          (0x7u<<14)
#define ETH_MTLRXQ1OMR_RFD_0                                        (0x1u<<14)
#define ETH_MTLRXQ1OMR_RFA                                          (0x7u<<8)
#define ETH_MTLRXQ1OMR_RFA_0                                        (0x1u<<8)
#define ETH_MTLRXQ1OMR_EHFC                                         (0x1u<<7)
#define ETH_MTLRXQ1OMR_DIS_TCP_EF                                   (0x1u<<6)
#define ETH_MTLRXQ1OMR_RSF                                          (0x1u<<5)
#define ETH_MTLRXQ1OMR_FEP                                          (0x1u<<4)
#define ETH_MTLRXQ1OMR_FUP                                          (0x1u<<3)
#define ETH_MTLRXQ1OMR_RTC                                          (0x3u<<0)
#define ETH_MTLRXQ1OMR_RTC_0                                        (0x1u<<0)

#define ETH_MTLRXQ1OMR_RFD_B_0X0                                    (0x0u<<14)
#define ETH_MTLRXQ1OMR_RFD_B_0X1                                    (0x1u<<14)
#define ETH_MTLRXQ1OMR_RTC_B_0X0                                    (0x0u<<0)
#define ETH_MTLRXQ1OMR_RTC_B_0X1                                    (0x1u<<0)
#define ETH_MTLRXQ1OMR_RTC_B_0X2                                    (0x2u<<0)
#define ETH_MTLRXQ1OMR_RTC_B_0X3                                    (0x3u<<0)

// MTLRXQ1MPOCR Configuration

#define ETH_MTLRXQ1MPOCR_MISCNTOVF                                  (0x1u<<27)
#define ETH_MTLRXQ1MPOCR_MISPKTCNT                                  (0x7FFu<<16)
#define ETH_MTLRXQ1MPOCR_MISPKTCNT_0                                (0x1u<<16)
#define ETH_MTLRXQ1MPOCR_OVFCNTOVF                                  (0x1u<<11)
#define ETH_MTLRXQ1MPOCR_OVFPKTCNT                                  (0x7FFu<<0)
#define ETH_MTLRXQ1MPOCR_OVFPKTCNT_0                                (0x1u<<0)

// MTLRXQ1DR Configuration

#define ETH_MTLRXQ1DR_PRXQ                                          (0x3FFFu<<16)
#define ETH_MTLRXQ1DR_PRXQ_0                                        (0x1u<<16)
#define ETH_MTLRXQ1DR_RXQSTS                                        (0x3u<<4)
#define ETH_MTLRXQ1DR_RXQSTS_0                                      (0x1u<<4)
#define ETH_MTLRXQ1DR_RRCSTS                                        (0x3u<<1)
#define ETH_MTLRXQ1DR_RRCSTS_0                                      (0x1u<<1)
#define ETH_MTLRXQ1DR_RWCSTS                                        (0x1u<<0)

#define ETH_MTLRXQ1DR_RXQSTS_B_0X0                                  (0x0u<<4)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X1                                  (0x1u<<4)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X2                                  (0x2u<<4)
#define ETH_MTLRXQ1DR_RXQSTS_B_0X3                                  (0x3u<<4)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLRXQ1DR_RRCSTS_B_0X3                                  (0x3u<<1)

// MTLRXQ1CR Configuration

#define ETH_MTLRXQ1CR_RXQ_FRM_ARBIT                                 (0x1u<<3)
#define ETH_MTLRXQ1CR_RXQ_WEGT                                      (0x7u<<0)
#define ETH_MTLRXQ1CR_RXQ_WEGT_0                                    (0x1u<<0)

// MTLTXQ2OMR Configuration

#define ETH_MTLTXQ2OMR_TQS                                          (0x1Fu<<16)
#define ETH_MTLTXQ2OMR_TQS_0                                        (0x1u<<16)
#define ETH_MTLTXQ2OMR_TTC                                          (0x7u<<4)
#define ETH_MTLTXQ2OMR_TTC_0                                        (0x1u<<4)
#define ETH_MTLTXQ2OMR_TXQEN                                        (0x3u<<2)
#define ETH_MTLTXQ2OMR_TXQEN_0                                      (0x1u<<2)
#define ETH_MTLTXQ2OMR_TSF                                          (0x1u<<1)
#define ETH_MTLTXQ2OMR_FTQ                                          (0x1u<<0)

#define ETH_MTLTXQ2OMR_TTC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X4                                    (0x4u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X5                                    (0x5u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X6                                    (0x6u<<4)
#define ETH_MTLTXQ2OMR_TTC_B_0X7                                    (0x7u<<4)
#define ETH_MTLTXQ2OMR_TXQEN_B_0X0                                  (0x0u<<2)
#define ETH_MTLTXQ2OMR_TXQEN_B_0X1                                  (0x1u<<2)
#define ETH_MTLTXQ2OMR_TXQEN_B_0X2                                  (0x2u<<2)

// MTLTXQ2UR Configuration

#define ETH_MTLTXQ2UR_UFCNTOVF                                      (0x1u<<11)
#define ETH_MTLTXQ2UR_UFFRMCNT                                      (0x7FFu<<0)
#define ETH_MTLTXQ2UR_UFFRMCNT_0                                    (0x1u<<0)

// MTLTXQ2DR Configuration

#define ETH_MTLTXQ2DR_STXSTSF                                       (0x7u<<20)
#define ETH_MTLTXQ2DR_STXSTSF_0                                     (0x1u<<20)
#define ETH_MTLTXQ2DR_PTXQ                                          (0x7u<<16)
#define ETH_MTLTXQ2DR_PTXQ_0                                        (0x1u<<16)
#define ETH_MTLTXQ2DR_TXSTSFSTS                                     (0x1u<<5)
#define ETH_MTLTXQ2DR_TXQSTS                                        (0x1u<<4)
#define ETH_MTLTXQ2DR_TWCSTS                                        (0x1u<<3)
#define ETH_MTLTXQ2DR_TRCSTS                                        (0x3u<<1)
#define ETH_MTLTXQ2DR_TRCSTS_0                                      (0x1u<<1)
#define ETH_MTLTXQ2DR_TXQPAUSED                                     (0x1u<<0)

#define ETH_MTLTXQ2DR_TRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLTXQ2DR_TRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLTXQ2DR_TRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLTXQ2DR_TRCSTS_B_0X3                                  (0x3u<<1)

// MTLTXQ2ECR Configuration

#define ETH_MTLTXQ2ECR_SLC                                          (0x7u<<4)
#define ETH_MTLTXQ2ECR_SLC_0                                        (0x1u<<4)
#define ETH_MTLTXQ2ECR_CC                                           (0x1u<<3)
#define ETH_MTLTXQ2ECR_AVALG                                        (0x1u<<2)

#define ETH_MTLTXQ2ECR_SLC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ2ECR_SLC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ2ECR_SLC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ2ECR_SLC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ2ECR_SLC_B_0X4                                    (0x4u<<4)

// MTLTXQ2ESR Configuration

#define ETH_MTLTXQ2ESR_ABS                                          (0xFFFFFFu<<0)
#define ETH_MTLTXQ2ESR_ABS_0                                        (0x1u<<0)

// MTLTXQ2QWR Configuration

#define ETH_MTLTXQ2QWR_ISCQW                                        (0x3FFFu<<0)
#define ETH_MTLTXQ2QWR_ISCQW_0                                      (0x1u<<0)

// MTLTXQ2SSCR Configuration

#define ETH_MTLTXQ2SSCR_SSC                                         (0x3FFFu<<0)
#define ETH_MTLTXQ2SSCR_SSC_0                                       (0x1u<<0)

// MTLTXQ2HCR Configuration

#define ETH_MTLTXQ2HCR_HC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ2HCR_HC_0                                         (0x1u<<0)

// MTLTXQ2LCR Configuration

#define ETH_MTLTXQ2LCR_LC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ2LCR_LC_0                                         (0x1u<<0)

// MTLQ2ICSR Configuration

#define ETH_MTLQ2ICSR_RXOIE                                         (0x1u<<24)
#define ETH_MTLQ2ICSR_RXOVFIS                                       (0x1u<<16)
#define ETH_MTLQ2ICSR_ABPSIE                                        (0x1u<<9)
#define ETH_MTLQ2ICSR_TXUIE                                         (0x1u<<8)
#define ETH_MTLQ2ICSR_ABPSIS                                        (0x1u<<1)
#define ETH_MTLQ2ICSR_TXUNFIS                                       (0x1u<<0)

// MTLTXQ3OMR Configuration

#define ETH_MTLTXQ3OMR_TQS                                          (0x1Fu<<16)
#define ETH_MTLTXQ3OMR_TQS_0                                        (0x1u<<16)
#define ETH_MTLTXQ3OMR_TTC                                          (0x7u<<4)
#define ETH_MTLTXQ3OMR_TTC_0                                        (0x1u<<4)
#define ETH_MTLTXQ3OMR_TXQEN                                        (0x3u<<2)
#define ETH_MTLTXQ3OMR_TXQEN_0                                      (0x1u<<2)
#define ETH_MTLTXQ3OMR_TSF                                          (0x1u<<1)
#define ETH_MTLTXQ3OMR_FTQ                                          (0x1u<<0)

#define ETH_MTLTXQ3OMR_TTC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X4                                    (0x4u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X5                                    (0x5u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X6                                    (0x6u<<4)
#define ETH_MTLTXQ3OMR_TTC_B_0X7                                    (0x7u<<4)
#define ETH_MTLTXQ3OMR_TXQEN_B_0X0                                  (0x0u<<2)
#define ETH_MTLTXQ3OMR_TXQEN_B_0X1                                  (0x1u<<2)
#define ETH_MTLTXQ3OMR_TXQEN_B_0X2                                  (0x2u<<2)

// MTLTXQ3UR Configuration

#define ETH_MTLTXQ3UR_UFCNTOVF                                      (0x1u<<11)
#define ETH_MTLTXQ3UR_UFFRMCNT                                      (0x7FFu<<0)
#define ETH_MTLTXQ3UR_UFFRMCNT_0                                    (0x1u<<0)

// MTLTXQ3DR Configuration

#define ETH_MTLTXQ3DR_STXSTSF                                       (0x7u<<20)
#define ETH_MTLTXQ3DR_STXSTSF_0                                     (0x1u<<20)
#define ETH_MTLTXQ3DR_PTXQ                                          (0x7u<<16)
#define ETH_MTLTXQ3DR_PTXQ_0                                        (0x1u<<16)
#define ETH_MTLTXQ3DR_TXSTSFSTS                                     (0x1u<<5)
#define ETH_MTLTXQ3DR_TXQSTS                                        (0x1u<<4)
#define ETH_MTLTXQ3DR_TWCSTS                                        (0x1u<<3)
#define ETH_MTLTXQ3DR_TRCSTS                                        (0x3u<<1)
#define ETH_MTLTXQ3DR_TRCSTS_0                                      (0x1u<<1)
#define ETH_MTLTXQ3DR_TXQPAUSED                                     (0x1u<<0)

#define ETH_MTLTXQ3DR_TRCSTS_B_0X0                                  (0x0u<<1)
#define ETH_MTLTXQ3DR_TRCSTS_B_0X1                                  (0x1u<<1)
#define ETH_MTLTXQ3DR_TRCSTS_B_0X2                                  (0x2u<<1)
#define ETH_MTLTXQ3DR_TRCSTS_B_0X3                                  (0x3u<<1)

// MTLTXQ3ECR Configuration

#define ETH_MTLTXQ3ECR_SLC                                          (0x7u<<4)
#define ETH_MTLTXQ3ECR_SLC_0                                        (0x1u<<4)
#define ETH_MTLTXQ3ECR_CC                                           (0x1u<<3)
#define ETH_MTLTXQ3ECR_AVALG                                        (0x1u<<2)

#define ETH_MTLTXQ3ECR_SLC_B_0X0                                    (0x0u<<4)
#define ETH_MTLTXQ3ECR_SLC_B_0X1                                    (0x1u<<4)
#define ETH_MTLTXQ3ECR_SLC_B_0X2                                    (0x2u<<4)
#define ETH_MTLTXQ3ECR_SLC_B_0X3                                    (0x3u<<4)
#define ETH_MTLTXQ3ECR_SLC_B_0X4                                    (0x4u<<4)

// MTLTXQ3ESR Configuration

#define ETH_MTLTXQ3ESR_ABS                                          (0xFFFFFFu<<0)
#define ETH_MTLTXQ3ESR_ABS_0                                        (0x1u<<0)

// MTLTXQ3QWR Configuration

#define ETH_MTLTXQ3QWR_ISCQW                                        (0x3FFFu<<0)
#define ETH_MTLTXQ3QWR_ISCQW_0                                      (0x1u<<0)

// MTLTXQ3SSCR Configuration

#define ETH_MTLTXQ3SSCR_SSC                                         (0x3FFFu<<0)
#define ETH_MTLTXQ3SSCR_SSC_0                                       (0x1u<<0)

// MTLTXQ3HCR Configuration

#define ETH_MTLTXQ3HCR_HC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ3HCR_HC_0                                         (0x1u<<0)

// MTLTXQ3LCR Configuration

#define ETH_MTLTXQ3LCR_LC                                           (0x1FFFFFFFu<<0)
#define ETH_MTLTXQ3LCR_LC_0                                         (0x1u<<0)

// MTLQ3ICSR Configuration

#define ETH_MTLQ3ICSR_RXOIE                                         (0x1u<<24)
#define ETH_MTLQ3ICSR_RXOVFIS                                       (0x1u<<16)
#define ETH_MTLQ3ICSR_ABPSIE                                        (0x1u<<9)
#define ETH_MTLQ3ICSR_TXUIE                                         (0x1u<<8)
#define ETH_MTLQ3ICSR_ABPSIS                                        (0x1u<<1)
#define ETH_MTLQ3ICSR_TXUNFIS                                       (0x1u<<0)

// DMAMR Configuration

#define ETH_DMAMR_INTM                                              (0x3u<<16)
#define ETH_DMAMR_INTM_0                                            (0x1u<<16)
#define ETH_DMAMR_TXPR                                              (0x1u<<11)
#define ETH_DMAMR_DSPW                                              (0x1u<<8)
#define ETH_DMAMR_TAA2                                              (0x1u<<4)
#define ETH_DMAMR_TAA1                                              (0x1u<<3)
#define ETH_DMAMR_TAA0                                              (0x1u<<2)
#define ETH_DMAMR_SWR                                               (0x1u<<0)

#define ETH_DMAMR_DSPW_B_0X0                                        (0x0u<<8)
#define ETH_DMAMR_DSPW_B_0X1                                        (0x1u<<8)
#define ETH_DMAMR_TAA2_B_0X0                                        (0x0u<<4)
#define ETH_DMAMR_TAA2_B_0X1                                        (0x1u<<4)
#define ETH_DMAMR_TAA1_B_0X0                                        (0x0u<<3)
#define ETH_DMAMR_TAA1_B_0X1                                        (0x1u<<3)
#define ETH_DMAMR_TAA0_B_0X0                                        (0x0u<<2)
#define ETH_DMAMR_TAA0_B_0X1                                        (0x1u<<2)

// DMASBMR Configuration

#define ETH_DMASBMR_EN_LPI                                          (0x1u<<31)
#define ETH_DMASBMR_LPI_XIT_PKT                                     (0x1u<<30)
#define ETH_DMASBMR_WR_OSR_LMT                                      (0x3u<<24)
#define ETH_DMASBMR_WR_OSR_LMT_0                                    (0x1u<<24)
#define ETH_DMASBMR_RD_OSR_LMT                                      (0x3u<<16)
#define ETH_DMASBMR_RD_OSR_LMT_0                                    (0x1u<<16)
#define ETH_DMASBMR_ONEKBBE                                         (0x1u<<13)
#define ETH_DMASBMR_AAL                                             (0x1u<<12)
#define ETH_DMASBMR_AALE                                            (0x1u<<10)
#define ETH_DMASBMR_BLEN256                                         (0x1u<<7)
#define ETH_DMASBMR_BLEN128                                         (0x1u<<6)
#define ETH_DMASBMR_BLEN64                                          (0x1u<<5)
#define ETH_DMASBMR_BLEN32                                          (0x1u<<4)
#define ETH_DMASBMR_BLEN16                                          (0x1u<<3)
#define ETH_DMASBMR_BLEN8                                           (0x1u<<2)
#define ETH_DMASBMR_BLEN4                                           (0x1u<<1)
#define ETH_DMASBMR_FB                                              (0x1u<<0)

// DMAISR Configuration

#define ETH_DMAISR_MACIS                                            (0x1u<<17)
#define ETH_DMAISR_MTLIS                                            (0x1u<<16)
#define ETH_DMAISR_DC3IS                                            (0x1u<<3)
#define ETH_DMAISR_DC2IS                                            (0x1u<<2)
#define ETH_DMAISR_DC1IS                                            (0x1u<<1)
#define ETH_DMAISR_DC0IS                                            (0x1u<<0)

// DMADS1R Configuration

#define ETH_DMADS1R_TPS2                                            (0xFu<<28)
#define ETH_DMADS1R_TPS2_0                                          (0x1u<<28)
#define ETH_DMADS1R_TPS1                                            (0xFu<<20)
#define ETH_DMADS1R_TPS1_0                                          (0x1u<<20)
#define ETH_DMADS1R_RPS1                                            (0xFu<<16)
#define ETH_DMADS1R_RPS1_0                                          (0x1u<<16)
#define ETH_DMADS1R_TPS0                                            (0xFu<<12)
#define ETH_DMADS1R_TPS0_0                                          (0x1u<<12)
#define ETH_DMADS1R_RPS0                                            (0xFu<<8)
#define ETH_DMADS1R_RPS0_0                                          (0x1u<<8)
#define ETH_DMADS1R_AXRHSTS                                         (0x1u<<1)
#define ETH_DMADS1R_AXWHSTS                                         (0x1u<<0)

#define ETH_DMADS1R_TPS0_B_0X0                                      (0x0u<<12)
#define ETH_DMADS1R_TPS0_B_0X1                                      (0x1u<<12)
#define ETH_DMADS1R_TPS0_B_0X2                                      (0x2u<<12)
#define ETH_DMADS1R_TPS0_B_0X3                                      (0x3u<<12)
#define ETH_DMADS1R_TPS0_B_0X4                                      (0x4u<<12)
#define ETH_DMADS1R_TPS0_B_0X5                                      (0x5u<<12)
#define ETH_DMADS1R_TPS0_B_0X6                                      (0x6u<<12)
#define ETH_DMADS1R_TPS0_B_0X7                                      (0x7u<<12)
#define ETH_DMADS1R_RPS0_B_0X0                                      (0x0u<<8)
#define ETH_DMADS1R_RPS0_B_0X1                                      (0x1u<<8)
#define ETH_DMADS1R_RPS0_B_0X2                                      (0x2u<<8)
#define ETH_DMADS1R_RPS0_B_0X3                                      (0x3u<<8)
#define ETH_DMADS1R_RPS0_B_0X4                                      (0x4u<<8)
#define ETH_DMADS1R_RPS0_B_0X5                                      (0x5u<<8)
#define ETH_DMADS1R_RPS0_B_0X6                                      (0x6u<<8)
#define ETH_DMADS1R_RPS0_B_0X7                                      (0x7u<<8)

// DMADS2R Configuration

#define ETH_DMADS2R_TPS3                                            (0xFu<<4)
#define ETH_DMADS2R_TPS3_0                                          (0x1u<<4)

// DMAA4TXACR Configuration

#define ETH_DMAA4TXACR_THC                                          (0xFu<<16)
#define ETH_DMAA4TXACR_THC_0                                        (0x1u<<16)
#define ETH_DMAA4TXACR_TEC                                          (0xFu<<8)
#define ETH_DMAA4TXACR_TEC_0                                        (0x1u<<8)
#define ETH_DMAA4TXACR_TDRC                                         (0xFu<<0)
#define ETH_DMAA4TXACR_TDRC_0                                       (0x1u<<0)

// DMAA4RXACR Configuration

#define ETH_DMAA4RXACR_RDC                                          (0xFu<<24)
#define ETH_DMAA4RXACR_RDC_0                                        (0x1u<<24)
#define ETH_DMAA4RXACR_RHC                                          (0xFu<<16)
#define ETH_DMAA4RXACR_RHC_0                                        (0x1u<<16)
#define ETH_DMAA4RXACR_RPC                                          (0xFu<<8)
#define ETH_DMAA4RXACR_RPC_0                                        (0x1u<<8)
#define ETH_DMAA4RXACR_RDWC                                         (0xFu<<0)
#define ETH_DMAA4RXACR_RDWC_0                                       (0x1u<<0)

// DMAA4DACR Configuration

#define ETH_DMAA4DACR_RDRC                                          (0xFu<<8)
#define ETH_DMAA4DACR_RDRC_0                                        (0x1u<<8)
#define ETH_DMAA4DACR_TDWD                                          (0x3u<<4)
#define ETH_DMAA4DACR_TDWD_0                                        (0x1u<<4)
#define ETH_DMAA4DACR_TDWC                                          (0xFu<<0)
#define ETH_DMAA4DACR_TDWC_0                                        (0x1u<<0)

// DMALPIEI Configuration

#define ETH_DMALPIEI_LPIEI                                          (0xFu<<0)
#define ETH_DMALPIEI_LPIEI_0                                        (0x1u<<0)

// DMATBSCTRL0R Configuration

#define ETH_DMATBSCTRL0R_FTOS                                       (0xFFFFFFu<<8)
#define ETH_DMATBSCTRL0R_FTOS_0                                     (0x1u<<8)
#define ETH_DMATBSCTRL0R_FGOS                                       (0x7u<<4)
#define ETH_DMATBSCTRL0R_FGOS_0                                     (0x1u<<4)
#define ETH_DMATBSCTRL0R_FTOV                                       (0x1u<<0)

#define ETH_DMATBSCTRL0R_FTOV_B_0X0                                 (0x0u<<0)
#define ETH_DMATBSCTRL0R_FTOV_B_0X1                                 (0x1u<<0)

// DMATBSCTRL0R_ALTERNATE1 Configuration

#define ETH_DMATBSCTRL0R_ALTERNATE1_FTOS                            (0xFFFFFFu<<8)
#define ETH_DMATBSCTRL0R_ALTERNATE1_FTOS_0                          (0x1u<<8)
#define ETH_DMATBSCTRL0R_ALTERNATE1_FGOS                            (0x7u<<4)
#define ETH_DMATBSCTRL0R_ALTERNATE1_FGOS_0                          (0x1u<<4)
#define ETH_DMATBSCTRL0R_ALTERNATE1_FTOV                            (0x1u<<0)

#define ETH_DMATBSCTRL0R_ALTERNATE1_FTOV_B_0X0                      (0x0u<<0)
#define ETH_DMATBSCTRL0R_ALTERNATE1_FTOV_B_0X1                      (0x1u<<0)

// DMATBSCTRL1R Configuration

#define ETH_DMATBSCTRL1R_FTOS                                       (0xFFFFFFu<<8)
#define ETH_DMATBSCTRL1R_FTOS_0                                     (0x1u<<8)
#define ETH_DMATBSCTRL1R_FGOS                                       (0x7u<<4)
#define ETH_DMATBSCTRL1R_FGOS_0                                     (0x1u<<4)
#define ETH_DMATBSCTRL1R_FTOV                                       (0x1u<<0)

#define ETH_DMATBSCTRL1R_FTOV_B_0X0                                 (0x0u<<0)
#define ETH_DMATBSCTRL1R_FTOV_B_0X1                                 (0x1u<<0)

// DMATBSCTRL2R Configuration

#define ETH_DMATBSCTRL2R_FTOS                                       (0xFFFFFFu<<8)
#define ETH_DMATBSCTRL2R_FTOS_0                                     (0x1u<<8)
#define ETH_DMATBSCTRL2R_FGOS                                       (0x7u<<4)
#define ETH_DMATBSCTRL2R_FGOS_0                                     (0x1u<<4)
#define ETH_DMATBSCTRL2R_FTOV                                       (0x1u<<0)

#define ETH_DMATBSCTRL2R_FTOV_B_0X0                                 (0x0u<<0)
#define ETH_DMATBSCTRL2R_FTOV_B_0X1                                 (0x1u<<0)

// DMATBSCTRL3R Configuration

#define ETH_DMATBSCTRL3R_FTOS                                       (0xFFFFFFu<<8)
#define ETH_DMATBSCTRL3R_FTOS_0                                     (0x1u<<8)
#define ETH_DMATBSCTRL3R_FGOS                                       (0x7u<<4)
#define ETH_DMATBSCTRL3R_FGOS_0                                     (0x1u<<4)
#define ETH_DMATBSCTRL3R_FTOV                                       (0x1u<<0)

#define ETH_DMATBSCTRL3R_FTOV_B_0X0                                 (0x0u<<0)
#define ETH_DMATBSCTRL3R_FTOV_B_0X1                                 (0x1u<<0)

// DMAC0CR Configuration

#define ETH_DMAC0CR_DSL                                             (0x7u<<18)
#define ETH_DMAC0CR_DSL_0                                           (0x1u<<18)
#define ETH_DMAC0CR_PBLX8                                           (0x1u<<16)
#define ETH_DMAC0CR_MSS                                             (0x3FFFu<<0)
#define ETH_DMAC0CR_MSS_0                                           (0x1u<<0)

// DMAC0TXCR Configuration

#define ETH_DMAC0TXCR_TFSEL1                                        (0x1u<<30)
#define ETH_DMAC0TXCR_TFSEL0                                        (0x1u<<29)
#define ETH_DMAC0TXCR_EDSE                                          (0x1u<<28)
#define ETH_DMAC0TXCR_TQOS                                          (0xFu<<24)
#define ETH_DMAC0TXCR_TQOS_0                                        (0x1u<<24)
#define ETH_DMAC0TXCR_TXPBL                                         (0x3Fu<<16)
#define ETH_DMAC0TXCR_TXPBL_0                                       (0x1u<<16)
#define ETH_DMAC0TXCR_IPBL                                          (0x1u<<15)
#define ETH_DMAC0TXCR_TSE                                           (0x1u<<12)
#define ETH_DMAC0TXCR_OSF                                           (0x1u<<4)
#define ETH_DMAC0TXCR_TCW                                           (0x7u<<1)
#define ETH_DMAC0TXCR_TCW_0                                         (0x1u<<1)
#define ETH_DMAC0TXCR_ST                                            (0x1u<<0)

#define ETH_DMAC0TXCR_TFSEL1_B_0X0                                  (0x0u<<30)
#define ETH_DMAC0TXCR_TFSEL1_B_0X1                                  (0x1u<<30)
#define ETH_DMAC0TXCR_TFSEL0_B_0X0                                  (0x0u<<29)
#define ETH_DMAC0TXCR_TFSEL0_B_0X1                                  (0x1u<<29)

// DMAC0RXCR Configuration

#define ETH_DMAC0RXCR_RPF                                           (0x1u<<31)
#define ETH_DMAC0RXCR_RQOS                                          (0xFu<<24)
#define ETH_DMAC0RXCR_RQOS_0                                        (0x1u<<24)
#define ETH_DMAC0RXCR_RXPBL                                         (0x3Fu<<16)
#define ETH_DMAC0RXCR_RXPBL_0                                       (0x1u<<16)
#define ETH_DMAC0RXCR_RBSZ                                          (0x3FFFu<<1)
#define ETH_DMAC0RXCR_RBSZ_0                                        (0x1u<<1)
#define ETH_DMAC0RXCR_SR                                            (0x1u<<0)

// DMAC0TXDLAR Configuration

#define ETH_DMAC0TXDLAR_TDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC0TXDLAR_TDESLA_0                                    (0x1u<<0)

// DMAC0RXDLAR Configuration

#define ETH_DMAC0RXDLAR_RDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC0RXDLAR_RDESLA_0                                    (0x1u<<0)

// DMAC0TXDTPR Configuration

#define ETH_DMAC0TXDTPR_TDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC0TXDTPR_TDT_0                                       (0x1u<<0)

// DMAC0RXDTPR Configuration

#define ETH_DMAC0RXDTPR_RDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC0RXDTPR_RDT_0                                       (0x1u<<0)

// DMAC0TXRLR Configuration

#define ETH_DMAC0TXRLR_TDRL                                         (0x3FFu<<0)
#define ETH_DMAC0TXRLR_TDRL_0                                       (0x1u<<0)

// DMAC0RXRLR Configuration

#define ETH_DMAC0RXRLR_ARBS                                         (0x7Fu<<17)
#define ETH_DMAC0RXRLR_ARBS_0                                       (0x1u<<17)
#define ETH_DMAC0RXRLR_RDRL                                         (0x3FFu<<0)
#define ETH_DMAC0RXRLR_RDRL_0                                       (0x1u<<0)

// DMAC0IER Configuration

#define ETH_DMAC0IER_NIE                                            (0x1u<<15)
#define ETH_DMAC0IER_AIE                                            (0x1u<<14)
#define ETH_DMAC0IER_CDEE                                           (0x1u<<13)
#define ETH_DMAC0IER_FBEE                                           (0x1u<<12)
#define ETH_DMAC0IER_ERIE                                           (0x1u<<11)
#define ETH_DMAC0IER_ETIE                                           (0x1u<<10)
#define ETH_DMAC0IER_RWTE                                           (0x1u<<9)
#define ETH_DMAC0IER_RSE                                            (0x1u<<8)
#define ETH_DMAC0IER_RBUE                                           (0x1u<<7)
#define ETH_DMAC0IER_RIE                                            (0x1u<<6)
#define ETH_DMAC0IER_TBUE                                           (0x1u<<2)
#define ETH_DMAC0IER_TXSE                                           (0x1u<<1)
#define ETH_DMAC0IER_TIE                                            (0x1u<<0)

// DMAC0RXIWTR Configuration

#define ETH_DMAC0RXIWTR_RWTU                                        (0x3u<<16)
#define ETH_DMAC0RXIWTR_RWTU_0                                      (0x1u<<16)
#define ETH_DMAC0RXIWTR_RWT                                         (0xFFu<<0)
#define ETH_DMAC0RXIWTR_RWT_0                                       (0x1u<<0)

#define ETH_DMAC0RXIWTR_RWTU_B_0X0                                  (0x0u<<16)
#define ETH_DMAC0RXIWTR_RWTU_B_0X1                                  (0x1u<<16)
#define ETH_DMAC0RXIWTR_RWTU_B_0X2                                  (0x2u<<16)
#define ETH_DMAC0RXIWTR_RWTU_B_0X3                                  (0x3u<<16)

// DMAC0SFCSR Configuration

#define ETH_DMAC0SFCSR_RSN                                          (0xFu<<16)
#define ETH_DMAC0SFCSR_RSN_0                                        (0x1u<<16)
#define ETH_DMAC0SFCSR_SIV                                          (0xFFFu<<4)
#define ETH_DMAC0SFCSR_SIV_0                                        (0x1u<<4)
#define ETH_DMAC0SFCSR_ASC                                          (0x1u<<1)
#define ETH_DMAC0SFCSR_ESC                                          (0x1u<<0)

// DMAC0CATXDR Configuration

#define ETH_DMAC0CATXDR_CURTDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC0CATXDR_CURTDESAPTR_0                               (0x1u<<0)

// DMAC0CARXDR Configuration

#define ETH_DMAC0CARXDR_CURRDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC0CARXDR_CURRDESAPTR_0                               (0x1u<<0)

// DMAC0CATXBR Configuration

#define ETH_DMAC0CATXBR_CURTBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC0CATXBR_CURTBUFAPTR_0                               (0x1u<<0)

// DMAC0CARXBR Configuration

#define ETH_DMAC0CARXBR_CURRBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC0CARXBR_CURRBUFAPTR_0                               (0x1u<<0)

// DMAC0SR Configuration

#define ETH_DMAC0SR_REB                                             (0x7u<<19)
#define ETH_DMAC0SR_REB_0                                           (0x1u<<19)
#define ETH_DMAC0SR_TEB                                             (0x7u<<16)
#define ETH_DMAC0SR_TEB_0                                           (0x1u<<16)
#define ETH_DMAC0SR_NIS                                             (0x1u<<15)
#define ETH_DMAC0SR_AIS                                             (0x1u<<14)
#define ETH_DMAC0SR_CDE                                             (0x1u<<13)
#define ETH_DMAC0SR_FBE                                             (0x1u<<12)
#define ETH_DMAC0SR_ERI                                             (0x1u<<11)
#define ETH_DMAC0SR_ETI                                             (0x1u<<10)
#define ETH_DMAC0SR_RWT                                             (0x1u<<9)
#define ETH_DMAC0SR_RPS                                             (0x1u<<8)
#define ETH_DMAC0SR_RBU                                             (0x1u<<7)
#define ETH_DMAC0SR_RI                                              (0x1u<<6)
#define ETH_DMAC0SR_TBU                                             (0x1u<<2)
#define ETH_DMAC0SR_TPS                                             (0x1u<<1)
#define ETH_DMAC0SR_TI                                              (0x1u<<0)

// DMAC0MFCR Configuration

#define ETH_DMAC0MFCR_MFCO                                          (0x1u<<15)
#define ETH_DMAC0MFCR_MFC                                           (0x7FFu<<0)
#define ETH_DMAC0MFCR_MFC_0                                         (0x1u<<0)

// DMAC1CR Configuration

#define ETH_DMAC1CR_DSL                                             (0x7u<<18)
#define ETH_DMAC1CR_DSL_0                                           (0x1u<<18)
#define ETH_DMAC1CR_PBLX8                                           (0x1u<<16)
#define ETH_DMAC1CR_MSS                                             (0x3FFFu<<0)
#define ETH_DMAC1CR_MSS_0                                           (0x1u<<0)

// DMAC1TXCR Configuration

#define ETH_DMAC1TXCR_TFSEL1                                        (0x1u<<30)
#define ETH_DMAC1TXCR_TFSEL0                                        (0x1u<<29)
#define ETH_DMAC1TXCR_EDSE                                          (0x1u<<28)
#define ETH_DMAC1TXCR_TQOS                                          (0xFu<<24)
#define ETH_DMAC1TXCR_TQOS_0                                        (0x1u<<24)
#define ETH_DMAC1TXCR_TXPBL                                         (0x3Fu<<16)
#define ETH_DMAC1TXCR_TXPBL_0                                       (0x1u<<16)
#define ETH_DMAC1TXCR_IPBL                                          (0x1u<<15)
#define ETH_DMAC1TXCR_TSE                                           (0x1u<<12)
#define ETH_DMAC1TXCR_OSF                                           (0x1u<<4)
#define ETH_DMAC1TXCR_TCW                                           (0x7u<<1)
#define ETH_DMAC1TXCR_TCW_0                                         (0x1u<<1)
#define ETH_DMAC1TXCR_ST                                            (0x1u<<0)

#define ETH_DMAC1TXCR_TFSEL1_B_0X0                                  (0x0u<<30)
#define ETH_DMAC1TXCR_TFSEL1_B_0X1                                  (0x1u<<30)
#define ETH_DMAC1TXCR_TFSEL0_B_0X0                                  (0x0u<<29)
#define ETH_DMAC1TXCR_TFSEL0_B_0X1                                  (0x1u<<29)

// DMAC1RXCR Configuration

#define ETH_DMAC1RXCR_RPF                                           (0x1u<<31)
#define ETH_DMAC1RXCR_RQOS                                          (0xFu<<24)
#define ETH_DMAC1RXCR_RQOS_0                                        (0x1u<<24)
#define ETH_DMAC1RXCR_RXPBL                                         (0x3Fu<<16)
#define ETH_DMAC1RXCR_RXPBL_0                                       (0x1u<<16)
#define ETH_DMAC1RXCR_RBSZ                                          (0x3FFFu<<1)
#define ETH_DMAC1RXCR_RBSZ_0                                        (0x1u<<1)
#define ETH_DMAC1RXCR_SR                                            (0x1u<<0)

// DMAC1TXDLAR Configuration

#define ETH_DMAC1TXDLAR_TDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC1TXDLAR_TDESLA_0                                    (0x1u<<0)

// DMAC1RXDLAR Configuration

#define ETH_DMAC1RXDLAR_RDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC1RXDLAR_RDESLA_0                                    (0x1u<<0)

// DMAC1TXDTPR Configuration

#define ETH_DMAC1TXDTPR_TDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC1TXDTPR_TDT_0                                       (0x1u<<0)

// DMAC1RXDTPR Configuration

#define ETH_DMAC1RXDTPR_RDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC1RXDTPR_RDT_0                                       (0x1u<<0)

// DMAC1TXRLR Configuration

#define ETH_DMAC1TXRLR_TDRL                                         (0x3FFu<<0)
#define ETH_DMAC1TXRLR_TDRL_0                                       (0x1u<<0)

// DMAC1RXRLR Configuration

#define ETH_DMAC1RXRLR_ARBS                                         (0x7Fu<<17)
#define ETH_DMAC1RXRLR_ARBS_0                                       (0x1u<<17)
#define ETH_DMAC1RXRLR_RDRL                                         (0x3FFu<<0)
#define ETH_DMAC1RXRLR_RDRL_0                                       (0x1u<<0)

// DMAC1IER Configuration

#define ETH_DMAC1IER_NIE                                            (0x1u<<15)
#define ETH_DMAC1IER_AIE                                            (0x1u<<14)
#define ETH_DMAC1IER_CDEE                                           (0x1u<<13)
#define ETH_DMAC1IER_FBEE                                           (0x1u<<12)
#define ETH_DMAC1IER_ERIE                                           (0x1u<<11)
#define ETH_DMAC1IER_ETIE                                           (0x1u<<10)
#define ETH_DMAC1IER_RWTE                                           (0x1u<<9)
#define ETH_DMAC1IER_RSE                                            (0x1u<<8)
#define ETH_DMAC1IER_RBUE                                           (0x1u<<7)
#define ETH_DMAC1IER_RIE                                            (0x1u<<6)
#define ETH_DMAC1IER_TBUE                                           (0x1u<<2)
#define ETH_DMAC1IER_TXSE                                           (0x1u<<1)
#define ETH_DMAC1IER_TIE                                            (0x1u<<0)

// DMAC1RXIWTR Configuration

#define ETH_DMAC1RXIWTR_RWTU                                        (0x3u<<16)
#define ETH_DMAC1RXIWTR_RWTU_0                                      (0x1u<<16)
#define ETH_DMAC1RXIWTR_RWT                                         (0xFFu<<0)
#define ETH_DMAC1RXIWTR_RWT_0                                       (0x1u<<0)

#define ETH_DMAC1RXIWTR_RWTU_B_0X0                                  (0x0u<<16)
#define ETH_DMAC1RXIWTR_RWTU_B_0X1                                  (0x1u<<16)
#define ETH_DMAC1RXIWTR_RWTU_B_0X2                                  (0x2u<<16)
#define ETH_DMAC1RXIWTR_RWTU_B_0X3                                  (0x3u<<16)

// DMAC1SFCSR Configuration

#define ETH_DMAC1SFCSR_RSN                                          (0xFu<<16)
#define ETH_DMAC1SFCSR_RSN_0                                        (0x1u<<16)
#define ETH_DMAC1SFCSR_SIV                                          (0xFFFu<<4)
#define ETH_DMAC1SFCSR_SIV_0                                        (0x1u<<4)
#define ETH_DMAC1SFCSR_ASC                                          (0x1u<<1)
#define ETH_DMAC1SFCSR_ESC                                          (0x1u<<0)

// DMAC1CATXDR Configuration

#define ETH_DMAC1CATXDR_CURTDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC1CATXDR_CURTDESAPTR_0                               (0x1u<<0)

// DMAC1CARXDR Configuration

#define ETH_DMAC1CARXDR_CURRDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC1CARXDR_CURRDESAPTR_0                               (0x1u<<0)

// DMAC1CATXBR Configuration

#define ETH_DMAC1CATXBR_CURTBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC1CATXBR_CURTBUFAPTR_0                               (0x1u<<0)

// DMAC1CARXBR Configuration

#define ETH_DMAC1CARXBR_CURRBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC1CARXBR_CURRBUFAPTR_0                               (0x1u<<0)

// DMAC1SR Configuration

#define ETH_DMAC1SR_REB                                             (0x7u<<19)
#define ETH_DMAC1SR_REB_0                                           (0x1u<<19)
#define ETH_DMAC1SR_TEB                                             (0x7u<<16)
#define ETH_DMAC1SR_TEB_0                                           (0x1u<<16)
#define ETH_DMAC1SR_NIS                                             (0x1u<<15)
#define ETH_DMAC1SR_AIS                                             (0x1u<<14)
#define ETH_DMAC1SR_CDE                                             (0x1u<<13)
#define ETH_DMAC1SR_FBE                                             (0x1u<<12)
#define ETH_DMAC1SR_ERI                                             (0x1u<<11)
#define ETH_DMAC1SR_ETI                                             (0x1u<<10)
#define ETH_DMAC1SR_RWT                                             (0x1u<<9)
#define ETH_DMAC1SR_RPS                                             (0x1u<<8)
#define ETH_DMAC1SR_RBU                                             (0x1u<<7)
#define ETH_DMAC1SR_RI                                              (0x1u<<6)
#define ETH_DMAC1SR_TBU                                             (0x1u<<2)
#define ETH_DMAC1SR_TPS                                             (0x1u<<1)
#define ETH_DMAC1SR_TI                                              (0x1u<<0)

// DMAC1MFCR Configuration

#define ETH_DMAC1MFCR_MFCO                                          (0x1u<<15)
#define ETH_DMAC1MFCR_MFC                                           (0x7FFu<<0)
#define ETH_DMAC1MFCR_MFC_0                                         (0x1u<<0)

// DMAC2CR Configuration

#define ETH_DMAC2CR_DSL                                             (0x7u<<18)
#define ETH_DMAC2CR_DSL_0                                           (0x1u<<18)
#define ETH_DMAC2CR_PBLX8                                           (0x1u<<16)
#define ETH_DMAC2CR_MSS                                             (0x3FFFu<<0)
#define ETH_DMAC2CR_MSS_0                                           (0x1u<<0)

// DMAC2TXCR Configuration

#define ETH_DMAC2TXCR_TFSEL1                                        (0x1u<<30)
#define ETH_DMAC2TXCR_TFSEL0                                        (0x1u<<29)
#define ETH_DMAC2TXCR_EDSE                                          (0x1u<<28)
#define ETH_DMAC2TXCR_TQOS                                          (0xFu<<24)
#define ETH_DMAC2TXCR_TQOS_0                                        (0x1u<<24)
#define ETH_DMAC2TXCR_TXPBL                                         (0x3Fu<<16)
#define ETH_DMAC2TXCR_TXPBL_0                                       (0x1u<<16)
#define ETH_DMAC2TXCR_IPBL                                          (0x1u<<15)
#define ETH_DMAC2TXCR_TSE                                           (0x1u<<12)
#define ETH_DMAC2TXCR_OSF                                           (0x1u<<4)
#define ETH_DMAC2TXCR_TCW                                           (0x7u<<1)
#define ETH_DMAC2TXCR_TCW_0                                         (0x1u<<1)
#define ETH_DMAC2TXCR_ST                                            (0x1u<<0)

#define ETH_DMAC2TXCR_TFSEL1_B_0X0                                  (0x0u<<30)
#define ETH_DMAC2TXCR_TFSEL1_B_0X1                                  (0x1u<<30)
#define ETH_DMAC2TXCR_TFSEL0_B_0X0                                  (0x0u<<29)
#define ETH_DMAC2TXCR_TFSEL0_B_0X1                                  (0x1u<<29)

// DMAC2TXDLAR Configuration

#define ETH_DMAC2TXDLAR_TDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC2TXDLAR_TDESLA_0                                    (0x1u<<0)

// DMAC2TXDTPR Configuration

#define ETH_DMAC2TXDTPR_TDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC2TXDTPR_TDT_0                                       (0x1u<<0)

// DMAC2TXRLR Configuration

#define ETH_DMAC2TXRLR_TDRL                                         (0x3FFu<<0)
#define ETH_DMAC2TXRLR_TDRL_0                                       (0x1u<<0)

// DMAC2IER Configuration

#define ETH_DMAC2IER_NIE                                            (0x1u<<15)
#define ETH_DMAC2IER_AIE                                            (0x1u<<14)
#define ETH_DMAC2IER_CDEE                                           (0x1u<<13)
#define ETH_DMAC2IER_FBEE                                           (0x1u<<12)
#define ETH_DMAC2IER_ERIE                                           (0x1u<<11)
#define ETH_DMAC2IER_ETIE                                           (0x1u<<10)
#define ETH_DMAC2IER_RWTE                                           (0x1u<<9)
#define ETH_DMAC2IER_RSE                                            (0x1u<<8)
#define ETH_DMAC2IER_RBUE                                           (0x1u<<7)
#define ETH_DMAC2IER_RIE                                            (0x1u<<6)
#define ETH_DMAC2IER_TBUE                                           (0x1u<<2)
#define ETH_DMAC2IER_TXSE                                           (0x1u<<1)
#define ETH_DMAC2IER_TIE                                            (0x1u<<0)

// DMAC2SFCSR Configuration

#define ETH_DMAC2SFCSR_RSN                                          (0xFu<<16)
#define ETH_DMAC2SFCSR_RSN_0                                        (0x1u<<16)
#define ETH_DMAC2SFCSR_SIV                                          (0xFFFu<<4)
#define ETH_DMAC2SFCSR_SIV_0                                        (0x1u<<4)
#define ETH_DMAC2SFCSR_ASC                                          (0x1u<<1)
#define ETH_DMAC2SFCSR_ESC                                          (0x1u<<0)

// DMAC2CATXDR Configuration

#define ETH_DMAC2CATXDR_CURTDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC2CATXDR_CURTDESAPTR_0                               (0x1u<<0)

// DMAC2CATXBR Configuration

#define ETH_DMAC2CATXBR_CURTBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC2CATXBR_CURTBUFAPTR_0                               (0x1u<<0)

// DMAC2SR Configuration

#define ETH_DMAC2SR_REB                                             (0x7u<<19)
#define ETH_DMAC2SR_REB_0                                           (0x1u<<19)
#define ETH_DMAC2SR_TEB                                             (0x7u<<16)
#define ETH_DMAC2SR_TEB_0                                           (0x1u<<16)
#define ETH_DMAC2SR_NIS                                             (0x1u<<15)
#define ETH_DMAC2SR_AIS                                             (0x1u<<14)
#define ETH_DMAC2SR_CDE                                             (0x1u<<13)
#define ETH_DMAC2SR_FBE                                             (0x1u<<12)
#define ETH_DMAC2SR_ERI                                             (0x1u<<11)
#define ETH_DMAC2SR_ETI                                             (0x1u<<10)
#define ETH_DMAC2SR_RWT                                             (0x1u<<9)
#define ETH_DMAC2SR_RPS                                             (0x1u<<8)
#define ETH_DMAC2SR_RBU                                             (0x1u<<7)
#define ETH_DMAC2SR_RI                                              (0x1u<<6)
#define ETH_DMAC2SR_TBU                                             (0x1u<<2)
#define ETH_DMAC2SR_TPS                                             (0x1u<<1)
#define ETH_DMAC2SR_TI                                              (0x1u<<0)

// DMAC3CR Configuration

#define ETH_DMAC3CR_DSL                                             (0x7u<<18)
#define ETH_DMAC3CR_DSL_0                                           (0x1u<<18)
#define ETH_DMAC3CR_PBLX8                                           (0x1u<<16)
#define ETH_DMAC3CR_MSS                                             (0x3FFFu<<0)
#define ETH_DMAC3CR_MSS_0                                           (0x1u<<0)

// DMAC3TXCR Configuration

#define ETH_DMAC3TXCR_TFSEL1                                        (0x1u<<30)
#define ETH_DMAC3TXCR_TFSEL0                                        (0x1u<<29)
#define ETH_DMAC3TXCR_EDSE                                          (0x1u<<28)
#define ETH_DMAC3TXCR_TQOS                                          (0xFu<<24)
#define ETH_DMAC3TXCR_TQOS_0                                        (0x1u<<24)
#define ETH_DMAC3TXCR_TXPBL                                         (0x3Fu<<16)
#define ETH_DMAC3TXCR_TXPBL_0                                       (0x1u<<16)
#define ETH_DMAC3TXCR_IPBL                                          (0x1u<<15)
#define ETH_DMAC3TXCR_TSE                                           (0x1u<<12)
#define ETH_DMAC3TXCR_OSF                                           (0x1u<<4)
#define ETH_DMAC3TXCR_TCW                                           (0x7u<<1)
#define ETH_DMAC3TXCR_TCW_0                                         (0x1u<<1)
#define ETH_DMAC3TXCR_ST                                            (0x1u<<0)

#define ETH_DMAC3TXCR_TFSEL1_B_0X0                                  (0x0u<<30)
#define ETH_DMAC3TXCR_TFSEL1_B_0X1                                  (0x1u<<30)
#define ETH_DMAC3TXCR_TFSEL0_B_0X0                                  (0x0u<<29)
#define ETH_DMAC3TXCR_TFSEL0_B_0X1                                  (0x1u<<29)

// DMAC3TXDLAR Configuration

#define ETH_DMAC3TXDLAR_TDESLA                                      (0xFFFFFFFFu<<0)
#define ETH_DMAC3TXDLAR_TDESLA_0                                    (0x1u<<0)

// DMAC3TXDTPR Configuration

#define ETH_DMAC3TXDTPR_TDT                                         (0xFFFFFFFFu<<0)
#define ETH_DMAC3TXDTPR_TDT_0                                       (0x1u<<0)

// DMAC3TXRLR Configuration

#define ETH_DMAC3TXRLR_TDRL                                         (0x3FFu<<0)
#define ETH_DMAC3TXRLR_TDRL_0                                       (0x1u<<0)

// DMAC3IER Configuration

#define ETH_DMAC3IER_NIE                                            (0x1u<<15)
#define ETH_DMAC3IER_AIE                                            (0x1u<<14)
#define ETH_DMAC3IER_CDEE                                           (0x1u<<13)
#define ETH_DMAC3IER_FBEE                                           (0x1u<<12)
#define ETH_DMAC3IER_ERIE                                           (0x1u<<11)
#define ETH_DMAC3IER_ETIE                                           (0x1u<<10)
#define ETH_DMAC3IER_RWTE                                           (0x1u<<9)
#define ETH_DMAC3IER_RSE                                            (0x1u<<8)
#define ETH_DMAC3IER_RBUE                                           (0x1u<<7)
#define ETH_DMAC3IER_RIE                                            (0x1u<<6)
#define ETH_DMAC3IER_TBUE                                           (0x1u<<2)
#define ETH_DMAC3IER_TXSE                                           (0x1u<<1)
#define ETH_DMAC3IER_TIE                                            (0x1u<<0)

// DMAC3SFCSR Configuration

#define ETH_DMAC3SFCSR_RSN                                          (0xFu<<16)
#define ETH_DMAC3SFCSR_RSN_0                                        (0x1u<<16)
#define ETH_DMAC3SFCSR_SIV                                          (0xFFFu<<4)
#define ETH_DMAC3SFCSR_SIV_0                                        (0x1u<<4)
#define ETH_DMAC3SFCSR_ASC                                          (0x1u<<1)
#define ETH_DMAC3SFCSR_ESC                                          (0x1u<<0)

// DMAC3CATXDR Configuration

#define ETH_DMAC3CATXDR_CURTDESAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC3CATXDR_CURTDESAPTR_0                               (0x1u<<0)

// DMAC3CATXBR Configuration

#define ETH_DMAC3CATXBR_CURTBUFAPTR                                 (0xFFFFFFFFu<<0)
#define ETH_DMAC3CATXBR_CURTBUFAPTR_0                               (0x1u<<0)

// DMAC3SR Configuration

#define ETH_DMAC3SR_REB                                             (0x7u<<19)
#define ETH_DMAC3SR_REB_0                                           (0x1u<<19)
#define ETH_DMAC3SR_TEB                                             (0x7u<<16)
#define ETH_DMAC3SR_TEB_0                                           (0x1u<<16)
#define ETH_DMAC3SR_NIS                                             (0x1u<<15)
#define ETH_DMAC3SR_AIS                                             (0x1u<<14)
#define ETH_DMAC3SR_CDE                                             (0x1u<<13)
#define ETH_DMAC3SR_FBE                                             (0x1u<<12)
#define ETH_DMAC3SR_ERI                                             (0x1u<<11)
#define ETH_DMAC3SR_ETI                                             (0x1u<<10)
#define ETH_DMAC3SR_RWT                                             (0x1u<<9)
#define ETH_DMAC3SR_RPS                                             (0x1u<<8)
#define ETH_DMAC3SR_RBU                                             (0x1u<<7)
#define ETH_DMAC3SR_RI                                              (0x1u<<6)
#define ETH_DMAC3SR_TBU                                             (0x1u<<2)
#define ETH_DMAC3SR_TPS                                             (0x1u<<1)
#define ETH_DMAC3SR_TI                                              (0x1u<<0)
