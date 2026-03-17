/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_syscfg.
; =================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_syscfg equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// SYSCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    BOOTCR;
    volatile    uint32_t    CM55CR;
    volatile    uint32_t    CM55TCMCR;
    volatile    uint32_t    CM55RWMCR;
    volatile    uint32_t    INITSVTORCR;
    volatile    uint32_t    INITNSVTORCR;
    volatile    uint32_t    CM55RSTCR;
    volatile    uint32_t    CM55PAHBWPR;
    volatile    uint32_t    VENCRAMCR;
    volatile    uint32_t    POTTAMPRSTCR;
    volatile    uint32_t    RESERVED0[3];
    volatile    uint32_t    ICNEWRCR;
    volatile    uint32_t    ICNCGCR;
    volatile    uint32_t    ICNBWRCR;
    volatile    uint32_t    IOCR;
    volatile    uint32_t    VDDIO1CCCR;
    volatile    uint32_t    VDDIO1CCSR;
    volatile    uint32_t    VDDIO2CCCR;
    volatile    uint32_t    VDDIO2CCSR;
    volatile    uint32_t    VDDIO3CCCR;
    volatile    uint32_t    VDDIO3CCSR;
    volatile    uint32_t    VDDIO4CCCR;
    volatile    uint32_t    VDDIO4CCSR;
    volatile    uint32_t    VDDIOCCCR;
    volatile    uint32_t    VDDIOCCSR;
    volatile    uint32_t    CBR;
    volatile    uint32_t    SEC_AIDCR;
    volatile    uint32_t    FMC_RETIMECR;
    volatile    uint32_t    NPU_ICNCR;
    volatile    uint32_t    RESERVED1[33];
    volatile    uint32_t    BOOTSR;
    volatile    uint32_t    AHBWP_ERROR_SR;
    volatile    uint32_t    RESERVED2[190];
    volatile    uint32_t    SMPSHDPCR;
    volatile    uint32_t    RESERVED3[255];
    volatile    uint32_t    NONSEC_AIDCR;
} SYSCFG_TypeDef;

#ifdef __cplusplus
#define SYSCFG_NS   reinterpret_cast<SYSCFG_TypeDef *>(0x46008000U)
#define SYSCFG_S    reinterpret_cast<SYSCFG_TypeDef *>(0x56008000U)

#else
#define SYSCFG_NS   ((SYSCFG_TypeDef *)0x46008000U)
#define SYSCFG_S    ((SYSCFG_TypeDef *)0x56008000U)
#endif

// BOOTCR Configuration

#define SYSCFG_BOOTCR_BOOT1_PD                              (0x1U<<1)
#define SYSCFG_BOOTCR_BOOT0_PD                              (0x1U<<0)

#define SYSCFG_BOOTCR_BOOT1_PD_B_0X0                        (0x0U<<1)
#define SYSCFG_BOOTCR_BOOT1_PD_B_0X1                        (0x1U<<1)
#define SYSCFG_BOOTCR_BOOT0_PD_B_0X0                        (0x0U<<0)
#define SYSCFG_BOOTCR_BOOT0_PD_B_0X1                        (0x1U<<0)

// CM55CR Configuration

#define SYSCFG_CM55CR_LOCKDCAIC                             (0x1U<<21)
#define SYSCFG_CM55CR_LOCKSAU                               (0x1U<<20)
#define SYSCFG_CM55CR_LOCKNSMPU                             (0x1U<<19)
#define SYSCFG_CM55CR_LOCKSMPU                              (0x1U<<18)
#define SYSCFG_CM55CR_LOCKNSVTOR                            (0x1U<<17)
#define SYSCFG_CM55CR_LOCKSVTAIRCR                          (0x1U<<16)
#define SYSCFG_CM55CR_FPU_IT_EN                             (0x3FU<<0)
#define SYSCFG_CM55CR_FPU_IT_EN_0                           (0x1U<<0)

// CM55TCMCR Configuration

#define SYSCFG_CM55TCMCR_DTCMWSDISABLE                      (0x1U<<24)
#define SYSCFG_CM55TCMCR_ITCMWSDISABLE                      (0x1U<<23)
#define SYSCFG_CM55TCMCR_LOCKDTGU                           (0x1U<<18)
#define SYSCFG_CM55TCMCR_LOCKITGU                           (0x1U<<17)
#define SYSCFG_CM55TCMCR_LOCKTCM                            (0x1U<<16)
#define SYSCFG_CM55TCMCR_CFGDTCMSZ                          (0xFU<<4)
#define SYSCFG_CM55TCMCR_CFGDTCMSZ_0                        (0x1U<<4)
#define SYSCFG_CM55TCMCR_CFGITCMSZ                          (0xFU<<0)
#define SYSCFG_CM55TCMCR_CFGITCMSZ_0                        (0x1U<<0)

#define SYSCFG_CM55TCMCR_CFGDTCMSZ_B_0X8                    (0x8U<<4)
#define SYSCFG_CM55TCMCR_CFGDTCMSZ_B_0X9                    (0x9U<<4)
#define SYSCFG_CM55TCMCR_CFGITCMSZ_B_0X7                    (0x7U<<0)
#define SYSCFG_CM55TCMCR_CFGITCMSZ_B_0X8                    (0x8U<<0)
#define SYSCFG_CM55TCMCR_CFGITCMSZ_B_0X9                    (0x9U<<0)

// CM55RWMCR Configuration

#define SYSCFG_CM55RWMCR_BC2_CACHE                          (0x1U<<13)
#define SYSCFG_CM55RWMCR_BC1_CACHE                          (0x1U<<12)
#define SYSCFG_CM55RWMCR_RM_CACHE                           (0xFU<<8)
#define SYSCFG_CM55RWMCR_RM_CACHE_0                         (0x1U<<8)
#define SYSCFG_CM55RWMCR_RME_CACHE                          (0x1U<<7)
#define SYSCFG_CM55RWMCR_BC2_TCM                            (0x1U<<6)
#define SYSCFG_CM55RWMCR_BC1_TCM                            (0x1U<<5)
#define SYSCFG_CM55RWMCR_RM_TCM                             (0xFU<<1)
#define SYSCFG_CM55RWMCR_RM_TCM_0                           (0x1U<<1)
#define SYSCFG_CM55RWMCR_RME_TCM                            (0x1U<<0)

#define SYSCFG_CM55RWMCR_RME_CACHE_B_0X0                    (0x0U<<7)
#define SYSCFG_CM55RWMCR_RME_CACHE_B_0X1                    (0x1U<<7)
#define SYSCFG_CM55RWMCR_RME_TCM_B_0X0                      (0x0U<<0)
#define SYSCFG_CM55RWMCR_RME_TCM_B_0X1                      (0x1U<<0)

// INITSVTORCR Configuration

#define SYSCFG_INITSVTORCR_SVTOR_ADDR                       (0x1FFFFFFU<<7)
#define SYSCFG_INITSVTORCR_SVTOR_ADDR_0                     (0x1U<<7)

// INITNSVTORCR Configuration

#define SYSCFG_INITNSVTORCR_NSVTOR_ADDR                     (0x1FFFFFFU<<7)
#define SYSCFG_INITNSVTORCR_NSVTOR_ADDR_0                   (0x1U<<7)

// CM55RSTCR Configuration

#define SYSCFG_CM55RSTCR_LOCKUP_NMI_EN                      (0x1U<<2)
#define SYSCFG_CM55RSTCR_LOCKUP_RST_EN                      (0x1U<<1)
#define SYSCFG_CM55RSTCR_CORE_RESET_TYPE                    (0x1U<<0)

#define SYSCFG_CM55RSTCR_LOCKUP_NMI_EN_B_0X0                (0x0U<<2)
#define SYSCFG_CM55RSTCR_LOCKUP_NMI_EN_B_0X1                (0x1U<<2)
#define SYSCFG_CM55RSTCR_LOCKUP_RST_EN_B_0X0                (0x0U<<1)
#define SYSCFG_CM55RSTCR_LOCKUP_RST_EN_B_0X1                (0x1U<<1)
#define SYSCFG_CM55RSTCR_CORE_RESET_TYPE_B_0X0              (0x0U<<0)
#define SYSCFG_CM55RSTCR_CORE_RESET_TYPE_B_0X1              (0x1U<<0)

// CM55PAHBWPR Configuration

#define SYSCFG_CM55PAHBWPR_PAHB_ERROR_ACK                   (0x1U<<0)

#define SYSCFG_CM55PAHBWPR_PAHB_ERROR_ACK_B_0X0             (0x0U<<0)
#define SYSCFG_CM55PAHBWPR_PAHB_ERROR_ACK_B_0X1             (0x1U<<0)

// VENCRAMCR Configuration

#define SYSCFG_VENCRAMCR_VENCRAM_EN                         (0x1U<<0)

#define SYSCFG_VENCRAMCR_VENCRAM_EN_B_0X0                   (0x0U<<0)
#define SYSCFG_VENCRAMCR_VENCRAM_EN_B_0X1                   (0x1U<<0)

// POTTAMPRSTCR Configuration

#define SYSCFG_POTTAMPRSTCR_POTTAMPERSETMASK                (0x1U<<0)

#define SYSCFG_POTTAMPRSTCR_POTTAMPERSETMASK_B_0X0          (0x0U<<0)
#define SYSCFG_POTTAMPRSTCR_POTTAMPERSETMASK_B_0X1          (0x1U<<0)

// ICNEWRCR Configuration

#define SYSCFG_ICNEWRCR_USB2_EARLY_WR_RSP_ENABLE            (0x1U<<3)
#define SYSCFG_ICNEWRCR_USB1_EARLY_WR_RSP_ENABLE            (0x1U<<2)
#define SYSCFG_ICNEWRCR_SDMMC2_EARLY_WR_RSP_ENABLE          (0x1U<<1)
#define SYSCFG_ICNEWRCR_SDMMC1_EARLY_WR_RSP_ENABLE          (0x1U<<0)

#define SYSCFG_ICNEWRCR_USB2_EARLY_WR_RSP_ENABLE_B_0X0      (0x0U<<3)
#define SYSCFG_ICNEWRCR_USB2_EARLY_WR_RSP_ENABLE_B_0X1      (0x1U<<3)
#define SYSCFG_ICNEWRCR_USB1_EARLY_WR_RSP_ENABLE_B_0X0      (0x0U<<2)
#define SYSCFG_ICNEWRCR_USB1_EARLY_WR_RSP_ENABLE_B_0X1      (0x1U<<2)
#define SYSCFG_ICNEWRCR_SDMMC2_EARLY_WR_RSP_ENABLE_B_0X0    (0x0U<<1)
#define SYSCFG_ICNEWRCR_SDMMC2_EARLY_WR_RSP_ENABLE_B_0X1    (0x1U<<1)
#define SYSCFG_ICNEWRCR_SDMMC1_EARLY_WR_RSP_ENABLE_B_0X0    (0x0U<<0)
#define SYSCFG_ICNEWRCR_SDMMC1_EARLY_WR_RSP_ENABLE_B_0X1    (0x1U<<0)

// ICNCGCR Configuration

#define SYSCFG_ICNCGCR_ICNCGCR                              (0xFFFFFFFFU<<0)
#define SYSCFG_ICNCGCR_ICNCGCR_0                            (0x1U<<0)

// ICNBWRCR Configuration

#define SYSCFG_ICNBWRCR_ICNBWRCR                            (0xFFFFFFFFU<<0)
#define SYSCFG_ICNBWRCR_ICNBWRCR_0                          (0x1U<<0)

// IOCR Configuration

#define SYSCFG_IOCR_IOCR                                    (0xFFFFFFFFU<<0)
#define SYSCFG_IOCR_IOCR_0                                  (0x1U<<0)

#define SYSCFG_IOCR_IOCR_B_0X0                              (0x0U<<0)
#define SYSCFG_IOCR_IOCR_B_0X1                              (0x1U<<0)

// VDDIO1CCCR Configuration

#define SYSCFG_VDDIO1CCCR_CS                                (0x1U<<9)
#define SYSCFG_VDDIO1CCCR_EN                                (0x1U<<8)
#define SYSCFG_VDDIO1CCCR_RAPSRC                            (0xFU<<4)
#define SYSCFG_VDDIO1CCCR_RAPSRC_0                          (0x1U<<4)
#define SYSCFG_VDDIO1CCCR_RANSRC                            (0xFU<<0)
#define SYSCFG_VDDIO1CCCR_RANSRC_0                          (0x1U<<0)

#define SYSCFG_VDDIO1CCCR_CS_B_0X0                          (0x0U<<9)
#define SYSCFG_VDDIO1CCCR_CS_B_0X1                          (0x1U<<9)
#define SYSCFG_VDDIO1CCCR_EN_B_0X0                          (0x0U<<8)
#define SYSCFG_VDDIO1CCCR_EN_B_0X1                          (0x1U<<8)

// VDDIO1CCSR Configuration

#define SYSCFG_VDDIO1CCSR_READY                             (0x1U<<8)
#define SYSCFG_VDDIO1CCSR_APSRC                             (0xFU<<4)
#define SYSCFG_VDDIO1CCSR_APSRC_0                           (0x1U<<4)
#define SYSCFG_VDDIO1CCSR_ANSRC                             (0xFU<<0)
#define SYSCFG_VDDIO1CCSR_ANSRC_0                           (0x1U<<0)

#define SYSCFG_VDDIO1CCSR_READY_B_0X0                       (0x0U<<8)
#define SYSCFG_VDDIO1CCSR_READY_B_0X1                       (0x1U<<8)

// VDDIO2CCCR Configuration

#define SYSCFG_VDDIO2CCCR_CS                                (0x1U<<9)
#define SYSCFG_VDDIO2CCCR_EN                                (0x1U<<8)
#define SYSCFG_VDDIO2CCCR_RAPSRC                            (0xFU<<4)
#define SYSCFG_VDDIO2CCCR_RAPSRC_0                          (0x1U<<4)
#define SYSCFG_VDDIO2CCCR_RANSRC                            (0xFU<<0)
#define SYSCFG_VDDIO2CCCR_RANSRC_0                          (0x1U<<0)

#define SYSCFG_VDDIO2CCCR_CS_B_0X0                          (0x0U<<9)
#define SYSCFG_VDDIO2CCCR_CS_B_0X1                          (0x1U<<9)
#define SYSCFG_VDDIO2CCCR_EN_B_0X0                          (0x0U<<8)
#define SYSCFG_VDDIO2CCCR_EN_B_0X1                          (0x1U<<8)

// VDDIO2CCSR Configuration

#define SYSCFG_VDDIO2CCSR_READY                             (0x1U<<8)
#define SYSCFG_VDDIO2CCSR_APSRC                             (0xFU<<4)
#define SYSCFG_VDDIO2CCSR_APSRC_0                           (0x1U<<4)
#define SYSCFG_VDDIO2CCSR_ANSRC                             (0xFU<<0)
#define SYSCFG_VDDIO2CCSR_ANSRC_0                           (0x1U<<0)

#define SYSCFG_VDDIO2CCSR_READY_B_0X0                       (0x0U<<8)
#define SYSCFG_VDDIO2CCSR_READY_B_0X1                       (0x1U<<8)

// VDDIO3CCCR Configuration

#define SYSCFG_VDDIO3CCCR_CS                                (0x1U<<9)
#define SYSCFG_VDDIO3CCCR_EN                                (0x1U<<8)
#define SYSCFG_VDDIO3CCCR_RAPSRC                            (0xFU<<4)
#define SYSCFG_VDDIO3CCCR_RAPSRC_0                          (0x1U<<4)
#define SYSCFG_VDDIO3CCCR_RANSRC                            (0xFU<<0)
#define SYSCFG_VDDIO3CCCR_RANSRC_0                          (0x1U<<0)

#define SYSCFG_VDDIO3CCCR_CS_B_0X0                          (0x0U<<9)
#define SYSCFG_VDDIO3CCCR_CS_B_0X1                          (0x1U<<9)
#define SYSCFG_VDDIO3CCCR_EN_B_0X0                          (0x0U<<8)
#define SYSCFG_VDDIO3CCCR_EN_B_0X1                          (0x1U<<8)

// VDDIO3CCSR Configuration

#define SYSCFG_VDDIO3CCSR_READY                             (0x1U<<8)
#define SYSCFG_VDDIO3CCSR_APSRC                             (0xFU<<4)
#define SYSCFG_VDDIO3CCSR_APSRC_0                           (0x1U<<4)
#define SYSCFG_VDDIO3CCSR_ANSRC                             (0xFU<<0)
#define SYSCFG_VDDIO3CCSR_ANSRC_0                           (0x1U<<0)

#define SYSCFG_VDDIO3CCSR_READY_B_0X0                       (0x0U<<8)
#define SYSCFG_VDDIO3CCSR_READY_B_0X1                       (0x1U<<8)

// VDDIO4CCCR Configuration

#define SYSCFG_VDDIO4CCCR_CS                                (0x1U<<9)
#define SYSCFG_VDDIO4CCCR_EN                                (0x1U<<8)
#define SYSCFG_VDDIO4CCCR_RAPSRC                            (0xFU<<4)
#define SYSCFG_VDDIO4CCCR_RAPSRC_0                          (0x1U<<4)
#define SYSCFG_VDDIO4CCCR_RANSRC                            (0xFU<<0)
#define SYSCFG_VDDIO4CCCR_RANSRC_0                          (0x1U<<0)

#define SYSCFG_VDDIO4CCCR_CS_B_0X0                          (0x0U<<9)
#define SYSCFG_VDDIO4CCCR_CS_B_0X1                          (0x1U<<9)
#define SYSCFG_VDDIO4CCCR_EN_B_0X0                          (0x0U<<8)
#define SYSCFG_VDDIO4CCCR_EN_B_0X1                          (0x1U<<8)

// VDDIO4CCSR Configuration

#define SYSCFG_VDDIO4CCSR_READY                             (0x1U<<8)
#define SYSCFG_VDDIO4CCSR_APSRC                             (0xFU<<4)
#define SYSCFG_VDDIO4CCSR_APSRC_0                           (0x1U<<4)
#define SYSCFG_VDDIO4CCSR_ANSRC                             (0xFU<<0)
#define SYSCFG_VDDIO4CCSR_ANSRC_0                           (0x1U<<0)

#define SYSCFG_VDDIO4CCSR_READY_B_0X0                       (0x0U<<8)
#define SYSCFG_VDDIO4CCSR_READY_B_0X1                       (0x1U<<8)

// VDDIOCCCR Configuration

#define SYSCFG_VDDIOCCCR_CS                                 (0x1U<<9)
#define SYSCFG_VDDIOCCCR_EN                                 (0x1U<<8)
#define SYSCFG_VDDIOCCCR_RAPSRC                             (0xFU<<4)
#define SYSCFG_VDDIOCCCR_RAPSRC_0                           (0x1U<<4)
#define SYSCFG_VDDIOCCCR_RANSRC                             (0xFU<<0)
#define SYSCFG_VDDIOCCCR_RANSRC_0                           (0x1U<<0)

#define SYSCFG_VDDIOCCCR_CS_B_0X0                           (0x0U<<9)
#define SYSCFG_VDDIOCCCR_CS_B_0X1                           (0x1U<<9)
#define SYSCFG_VDDIOCCCR_EN_B_0X0                           (0x0U<<8)
#define SYSCFG_VDDIOCCCR_EN_B_0X1                           (0x1U<<8)

// VDDIOCCSR Configuration

#define SYSCFG_VDDIOCCSR_READY                              (0x1U<<8)
#define SYSCFG_VDDIOCCSR_APSRC                              (0xFU<<4)
#define SYSCFG_VDDIOCCSR_APSRC_0                            (0x1U<<4)
#define SYSCFG_VDDIOCCSR_ANSRC                              (0xFU<<0)
#define SYSCFG_VDDIOCCSR_ANSRC_0                            (0x1U<<0)

#define SYSCFG_VDDIOCCSR_READY_B_0X0                        (0x0U<<8)
#define SYSCFG_VDDIOCCSR_READY_B_0X1                        (0x1U<<8)

// CBR Configuration

#define SYSCFG_CBR_CM55TCML                                 (0x1U<<6)
#define SYSCFG_CBR_CM55CACHEL                               (0x1U<<5)
#define SYSCFG_CBR_BKPRAML                                  (0x1U<<3)
#define SYSCFG_CBR_PVDL_LOCK                                (0x1U<<2)
#define SYSCFG_CBR_CM55L                                    (0x1U<<0)

#define SYSCFG_CBR_CM55TCML_B_0X0                           (0x0U<<6)
#define SYSCFG_CBR_CM55TCML_B_0X1                           (0x1U<<6)
#define SYSCFG_CBR_CM55CACHEL_B_0X0                         (0x0U<<5)
#define SYSCFG_CBR_CM55CACHEL_B_0X1                         (0x1U<<5)
#define SYSCFG_CBR_BKPRAML_B_0X0                            (0x0U<<3)
#define SYSCFG_CBR_BKPRAML_B_0X1                            (0x1U<<3)
#define SYSCFG_CBR_PVDL_LOCK_B_0X0                          (0x0U<<2)
#define SYSCFG_CBR_PVDL_LOCK_B_0X1                          (0x1U<<2)
#define SYSCFG_CBR_CM55L_B_0X0                              (0x0U<<0)
#define SYSCFG_CBR_CM55L_B_0X1                              (0x1U<<0)

// SEC_AIDCR Configuration

#define SYSCFG_SEC_AIDCR_DMACID_SEC                         (0x7U<<0)
#define SYSCFG_SEC_AIDCR_DMACID_SEC_0                       (0x1U<<0)

// FMC_RETIMECR Configuration

#define SYSCFG_FMC_RETIMECR_SDFBCLK_180                     (0x1U<<2)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_TX                   (0x1U<<1)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_RX                   (0x1U<<0)

#define SYSCFG_FMC_RETIMECR_SDFBCLK_180_B_0X0               (0x0U<<2)
#define SYSCFG_FMC_RETIMECR_SDFBCLK_180_B_0X1               (0x1U<<2)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_TX_B_0X0             (0x0U<<1)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_TX_B_0X1             (0x1U<<1)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_RX_B_0X0             (0x0U<<0)
#define SYSCFG_FMC_RETIMECR_CFG_RETIME_RX_B_0X1             (0x1U<<0)

// NPU_ICNCR Configuration

#define SYSCFG_NPU_ICNCR_INTERLEAVING_ACTIVE                (0x1U<<0)

#define SYSCFG_NPU_ICNCR_INTERLEAVING_ACTIVE_B_0X0          (0x0U<<0)
#define SYSCFG_NPU_ICNCR_INTERLEAVING_ACTIVE_B_0X1          (0x1U<<0)

// BOOTSR Configuration

#define SYSCFG_BOOTSR_BOOT1                                 (0x1U<<1)
#define SYSCFG_BOOTSR_BOOT0                                 (0x1U<<0)

#define SYSCFG_BOOTSR_BOOT1_B_0X0                           (0x0U<<1)
#define SYSCFG_BOOTSR_BOOT1_B_0X1                           (0x1U<<1)
#define SYSCFG_BOOTSR_BOOT0_B_0X0                           (0x0U<<0)
#define SYSCFG_BOOTSR_BOOT0_B_0X1                           (0x1U<<0)

// AHBWP_ERROR_SR Configuration

#define SYSCFG_AHBWP_ERROR_SR_PAHB_ERROR_ADDR               (0xFFFFFFFFU<<0)
#define SYSCFG_AHBWP_ERROR_SR_PAHB_ERROR_ADDR_0             (0x1U<<0)

// SMPSHDPCR Configuration

#define SYSCFG_SMPSHDPCR_SMPSHDPSEL                         (0xFU<<0)
#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_0                       (0x1U<<0)

#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_B_0X0                   (0x0U<<0)
#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_B_0XC                   (0xCU<<0)
#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_B_0XD                   (0xDU<<0)
#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_B_0XE                   (0xEU<<0)
#define SYSCFG_SMPSHDPCR_SMPSHDPSEL_B_0XF                   (0xFU<<0)

// NONSEC_AIDCR Configuration

#define SYSCFG_NONSEC_AIDCR_DMACID_NONSEC                   (0x7U<<0)
#define SYSCFG_NONSEC_AIDCR_DMACID_NONSEC_0                 (0x1U<<0)
