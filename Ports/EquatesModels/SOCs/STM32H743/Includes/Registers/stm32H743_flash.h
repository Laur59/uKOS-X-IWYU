/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_flash equates.
 */

#pragma once

#include    <stdint.h>

// FLASH address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    ACR;
    volatile    uint32_t    KEYR1;
    volatile    uint32_t    OPTKEYR;
    volatile    uint32_t    CR1;
    volatile    uint32_t    SR1;
    volatile    uint32_t    CCR1;
    volatile    uint32_t    OPTCR;
    volatile    uint32_t    OPTSR_CUR;
    volatile    uint32_t    OPTSR_PRG;
    volatile    uint32_t    OPTCCR;
    volatile    uint32_t    PRAR_CUR1;
    volatile    uint32_t    PRAR_PRG1;
    volatile    uint32_t    SCAR_CUR1;
    volatile    uint32_t    SCAR_PRG1;
    volatile    uint32_t    WPSN_CUR1R;
    volatile    uint32_t    WPSN_PRG1R;
    volatile    uint32_t    BOOT_CURR;
    volatile    uint32_t    BOOT_PRGR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    CRCCR1;
    volatile    uint32_t    CRCSADD1R;
    volatile    uint32_t    CRCEADD1R;
    volatile    uint32_t    CRCDATAR;
    volatile    uint32_t    ECC_FA1R;
    volatile    uint32_t    RESERVED1[39];
    volatile    uint32_t    ACR_;
    volatile    uint32_t    KEYR2;
    volatile    uint32_t    OPTKEYR_;
    volatile    uint32_t    CR2;
    volatile    uint32_t    SR2;
    volatile    uint32_t    CCR2;
    volatile    uint32_t    OPTCR_;
    volatile    uint32_t    OPTSR_CUR_;
    volatile    uint32_t    OPTSR_PRG_;
    volatile    uint32_t    OPTCCR_;
    volatile    uint32_t    PRAR_CUR2;
    volatile    uint32_t    PRAR_PRG2;
    volatile    uint32_t    SCAR_CUR2;
    volatile    uint32_t    SCAR_PRG2;
    volatile    uint32_t    WPSN_CUR2R;
    volatile    uint32_t    WPSN_PRG2R;
    volatile    uint32_t    BOOT_CURR_;
    volatile    uint32_t    BOOT_PRGR_;
    volatile    uint32_t    RESERVED2[2];
    volatile    uint32_t    CRCCR2;
    volatile    uint32_t    CRCSADD2R;
    volatile    uint32_t    CRCEADD2R;
    volatile    uint32_t    CRCDATAR_;
    volatile    uint32_t    ECC_FA2R;
} FLASH_TypeDef;

#ifdef __cplusplus
#define FLASH   reinterpret_cast<FLASH_TypeDef *>(0x52002000U)

#else
#define FLASH   ((FLASH_TypeDef *)0x52002000U)
#endif

// ACR Configuration

#define FLASH_ACR_WRHIGHFREQ                (0x3U<<4U)
#define FLASH_ACR_WRHIGHFREQ_0              (0x1U<<4U)
#define FLASH_ACR_LATENCY                   (0xFU<<0U)
#define FLASH_ACR_LATENCY_0                 (0x1U<<0U)

// KEYR1 Configuration

#define FLASH_KEYR1_KEY1R                   (0xFFFFFFFFU<<0U)
#define FLASH_KEYR1_KEY1R_0                 (0x1U<<0U)

// OPTKEYR Configuration

#define FLASH_OPTKEYR_OPTKEYR               (0xFFFFFFFFU<<0U)
#define FLASH_OPTKEYR_OPTKEYR_0             (0x1U<<0U)

// CR1 Configuration

#define FLASH_CR1_CRCRDERRIE1               (0x1U<<28U)
#define FLASH_CR1_CRCENDIE1                 (0x1U<<27U)
#define FLASH_CR1_DBECCERRIE1               (0x1U<<26U)
#define FLASH_CR1_SNECCERR1                 (0x1U<<25U)
#define FLASH_CR1_RDSERRIE1                 (0x1U<<24U)
#define FLASH_CR1_RDPERRIE1                 (0x1U<<23U)
#define FLASH_CR1_OPERRIE1                  (0x1U<<22U)
#define FLASH_CR1_INCERRIE1                 (0x1U<<21U)
#define FLASH_CR1_STRBERRIE1                (0x1U<<19U)
#define FLASH_CR1_PGSERRIE1                 (0x1U<<18U)
#define FLASH_CR1_WRPERRIE1                 (0x1U<<17U)
#define FLASH_CR1_EOPIE1                    (0x1U<<16U)
#define FLASH_CR1_CRC_EN                    (0x1U<<15U)
#define FLASH_CR1_SNB1                      (0x7U<<8U)
#define FLASH_CR1_SNB1_0                    (0x1U<<8U)
#define FLASH_CR1_START1                    (0x1U<<7U)
#define FLASH_CR1_FW1                       (0x1U<<6U)
#define FLASH_CR1_PSIZE1                    (0x3U<<4U)
#define FLASH_CR1_PSIZE1_0                  (0x1U<<4U)
#define FLASH_CR1_BER1                      (0x1U<<3U)
#define FLASH_CR1_SER1                      (0x1U<<2U)
#define FLASH_CR1_PG1                       (0x1U<<1U)
#define FLASH_CR1_LOCK1                     (0x1U<<0U)

// SR1 Configuration

#define FLASH_SR1_CRCRDERR1                 (0x1U<<28U)
#define FLASH_SR1_CRCEND1                   (0x1U<<27U)
#define FLASH_SR1_DBECCERR1                 (0x1U<<26U)
#define FLASH_SR1_SNECCERR                  (0x1U<<25U)
#define FLASH_SR1_RDSERR1                   (0x1U<<24U)
#define FLASH_SR1_RDPERR1                   (0x1U<<23U)
#define FLASH_SR1_OPERR1                    (0x1U<<22U)
#define FLASH_SR1_INCERR1                   (0x1U<<21U)
#define FLASH_SR1_STRBERR1                  (0x1U<<19U)
#define FLASH_SR1_PGSERR1                   (0x1U<<18U)
#define FLASH_SR1_WRPERR1                   (0x1U<<17U)
#define FLASH_SR1_EOP1                      (0x1U<<16U)
#define FLASH_SR1_CRC_BUSY1                 (0x1U<<3U)
#define FLASH_SR1_QW1                       (0x1U<<2U)
#define FLASH_SR1_WBNE1                     (0x1U<<1U)
#define FLASH_SR1_BSY1                      (0x1U<<0U)

// CCR1 Configuration

#define FLASH_CCR1_CLR_CRCRDERR1            (0x1U<<28U)
#define FLASH_CCR1_CLR_CRCEND1              (0x1U<<27U)
#define FLASH_CCR1_CLR_DBECCERR1            (0x1U<<26U)
#define FLASH_CCR1_CLR_SNECCERR1            (0x1U<<25U)
#define FLASH_CCR1_CLR_RDSERR1              (0x1U<<24U)
#define FLASH_CCR1_CLR_RDPERR1              (0x1U<<23U)
#define FLASH_CCR1_CLR_OPERR1               (0x1U<<22U)
#define FLASH_CCR1_CLR_INCERR1              (0x1U<<21U)
#define FLASH_CCR1_CLR_STRBERR1             (0x1U<<19U)
#define FLASH_CCR1_CLR_PGSERR1              (0x1U<<18U)
#define FLASH_CCR1_CLR_WRPERR1              (0x1U<<17U)
#define FLASH_CCR1_CLR_EOP1                 (0x1U<<16U)

// OPTCR Configuration

#define FLASH_OPTCR_SWAP_BANK               (0x1U<<31U)
#define FLASH_OPTCR_OPTCHANGEERRIE          (0x1U<<30U)
#define FLASH_OPTCR_MER                     (0x1U<<4U)
#define FLASH_OPTCR_OPTSTART                (0x1U<<1U)
#define FLASH_OPTCR_OPTLOCK                 (0x1U<<0U)

// OPTSR_CUR Configuration

#define FLASH_OPTSR_CUR_SWAP_BANK_OPT       (0x1U<<31U)
#define FLASH_OPTSR_CUR_OPTCHANGEERR        (0x1U<<30U)
#define FLASH_OPTSR_CUR_IO_HSLV             (0x1U<<29U)
#define FLASH_OPTSR_CUR_SECURITY            (0x1U<<21U)
#define FLASH_OPTSR_CUR_ST_RAM_SIZE         (0x3U<<19U)
#define FLASH_OPTSR_CUR_ST_RAM_SIZE_0       (0x1U<<19U)
#define FLASH_OPTSR_CUR_IWDG_FZ_SDBY        (0x1U<<18U)
#define FLASH_OPTSR_CUR_IWDG_FZ_STOP        (0x1U<<17U)
#define FLASH_OPTSR_CUR_RDP                 (0xFFU<<8U)
#define FLASH_OPTSR_CUR_RDP_0               (0x1U<<8U)
#define FLASH_OPTSR_CUR_NRST_STBY_D1        (0x1U<<7U)
#define FLASH_OPTSR_CUR_NRST_STOP_D1        (0x1U<<6U)
#define FLASH_OPTSR_CUR_IWDG1_SW            (0x1U<<4U)
#define FLASH_OPTSR_CUR_BOR_LEV             (0x3U<<2U)
#define FLASH_OPTSR_CUR_BOR_LEV_0           (0x1U<<2U)
#define FLASH_OPTSR_CUR_OPT_BUSY            (0x1U<<0U)

// OPTSR_PRG Configuration

#define FLASH_OPTSR_PRG_SWAP_BANK_OPT       (0x1U<<31U)
#define FLASH_OPTSR_PRG_IO_HSLV             (0x1U<<29U)
#define FLASH_OPTSR_PRG_SECURITY            (0x1U<<21U)
#define FLASH_OPTSR_PRG_ST_RAM_SIZE         (0x3U<<19U)
#define FLASH_OPTSR_PRG_ST_RAM_SIZE_0       (0x1U<<19U)
#define FLASH_OPTSR_PRG_IWDG_FZ_SDBY        (0x1U<<18U)
#define FLASH_OPTSR_PRG_IWDG_FZ_STOP        (0x1U<<17U)
#define FLASH_OPTSR_PRG_RDP                 (0xFFU<<8U)
#define FLASH_OPTSR_PRG_RDP_0               (0x1U<<8U)
#define FLASH_OPTSR_PRG_NRST_STBY_D1        (0x1U<<7U)
#define FLASH_OPTSR_PRG_NRST_STOP_D1        (0x1U<<6U)
#define FLASH_OPTSR_PRG_IWDG1_SW            (0x1U<<4U)
#define FLASH_OPTSR_PRG_BOR_LEV             (0x3U<<2U)
#define FLASH_OPTSR_PRG_BOR_LEV_0           (0x1U<<2U)

// OPTCCR Configuration

#define FLASH_OPTCCR_CLR_OPTCHANGEERR       (0x1U<<30U)

// PRAR_CUR1 Configuration

#define FLASH_PRAR_CUR1_DMEP1               (0x1U<<31U)
#define FLASH_PRAR_CUR1_PROT_AREA_END1      (0xFFFU<<16U)
#define FLASH_PRAR_CUR1_PROT_AREA_END1_0    (0x1U<<16U)
#define FLASH_PRAR_CUR1_PROT_AREA_START1    (0xFFFU<<0U)
#define FLASH_PRAR_CUR1_PROT_AREA_START1_0  (0x1U<<0U)

// PRAR_PRG1 Configuration

#define FLASH_PRAR_PRG1_DMEP1               (0x1U<<31U)
#define FLASH_PRAR_PRG1_PROT_AREA_END1      (0xFFFU<<16U)
#define FLASH_PRAR_PRG1_PROT_AREA_END1_0    (0x1U<<16U)
#define FLASH_PRAR_PRG1_PROT_AREA_START1    (0xFFFU<<0U)
#define FLASH_PRAR_PRG1_PROT_AREA_START1_0  (0x1U<<0U)

// SCAR_CUR1 Configuration

#define FLASH_SCAR_CUR1_DMES1               (0x1U<<31U)
#define FLASH_SCAR_CUR1_SEC_AREA_END1       (0xFFFU<<16U)
#define FLASH_SCAR_CUR1_SEC_AREA_END1_0     (0x1U<<16U)
#define FLASH_SCAR_CUR1_SEC_AREA_START1     (0xFFFU<<0U)
#define FLASH_SCAR_CUR1_SEC_AREA_START1_0   (0x1U<<0U)

// SCAR_PRG1 Configuration

#define FLASH_SCAR_PRG1_DMES1               (0x1U<<31U)
#define FLASH_SCAR_PRG1_SEC_AREA_END1       (0xFFFU<<16U)
#define FLASH_SCAR_PRG1_SEC_AREA_END1_0     (0x1U<<16U)
#define FLASH_SCAR_PRG1_SEC_AREA_START1     (0xFFFU<<0U)
#define FLASH_SCAR_PRG1_SEC_AREA_START1_0   (0x1U<<0U)

// WPSN_CUR1R Configuration

#define FLASH_WPSN_CUR1R_WRPSN1             (0xFFU<<0U)
#define FLASH_WPSN_CUR1R_WRPSN1_0           (0x1U<<0U)

// WPSN_PRG1R Configuration

#define FLASH_WPSN_PRG1R_WRPSN1             (0xFFU<<0U)
#define FLASH_WPSN_PRG1R_WRPSN1_0           (0x1U<<0U)

// BOOT_CURR Configuration

#define FLASH_BOOT_CURR_BOOT_ADD1           (0xFFFFU<<16U)
#define FLASH_BOOT_CURR_BOOT_ADD1_0         (0x1U<<16U)
#define FLASH_BOOT_CURR_BOOT_ADD0           (0xFFFFU<<0U)
#define FLASH_BOOT_CURR_BOOT_ADD0_0         (0x1U<<0U)

// BOOT_PRGR Configuration

#define FLASH_BOOT_PRGR_BOOT_ADD1           (0xFFFFU<<16U)
#define FLASH_BOOT_PRGR_BOOT_ADD1_0         (0x1U<<16U)
#define FLASH_BOOT_PRGR_BOOT_ADD0           (0xFFFFU<<0U)
#define FLASH_BOOT_PRGR_BOOT_ADD0_0         (0x1U<<0U)

// CRCCR1 Configuration

#define FLASH_CRCCR1_CRC_BURST              (0x3U<<20U)
#define FLASH_CRCCR1_CRC_BURST_0            (0x1U<<20U)
#define FLASH_CRCCR1_CLEAN_CRC              (0x1U<<17U)
#define FLASH_CRCCR1_START_CRC              (0x1U<<16U)
#define FLASH_CRCCR1_CLEAN_SECT             (0x1U<<10U)
#define FLASH_CRCCR1_ADD_SECT               (0x1U<<9U)
#define FLASH_CRCCR1_CRC_BY_SECT            (0x1U<<8U)
#define FLASH_CRCCR1_ALL_BANK               (0x1U<<7U)
#define FLASH_CRCCR1_CRC_SECT               (0x7U<<0U)
#define FLASH_CRCCR1_CRC_SECT_0             (0x1U<<0U)

// CRCSADD1R Configuration

#define FLASH_CRCSADD1R_CRC_START_ADDR      (0x3FFFFU<<2U)
#define FLASH_CRCSADD1R_CRC_START_ADDR_0    (0x1U<<2U)

// CRCEADD1R Configuration

#define FLASH_CRCEADD1R_CRC_END_ADDR        (0x3FFFFU<<2U)
#define FLASH_CRCEADD1R_CRC_END_ADDR_0      (0x1U<<2U)

// CRCDATAR Configuration

#define FLASH_CRCDATAR_CRC_DATA             (0xFFFFFFFFU<<0U)
#define FLASH_CRCDATAR_CRC_DATA_0           (0x1U<<0U)

// ECC_FA1R Configuration

#define FLASH_ECC_FA1R_FAIL_ECC_ADDR1       (0x7FFFU<<0U)
#define FLASH_ECC_FA1R_FAIL_ECC_ADDR1_0     (0x1U<<0U)

// ACR_ Configuration

#define FLASH_ACR__WRHIGHFREQ               (0x3U<<4U)
#define FLASH_ACR__WRHIGHFREQ_0             (0x1U<<4U)
#define FLASH_ACR__LATENCY                  (0xFU<<0U)
#define FLASH_ACR__LATENCY_0                (0x1U<<0U)

// KEYR2 Configuration

#define FLASH_KEYR2_KEYR2                   (0xFFFFFFFFU<<0U)
#define FLASH_KEYR2_KEYR2_0                 (0x1U<<0U)

// OPTKEYR_ Configuration

#define FLASH_OPTKEYR__OPTKEYR              (0xFFFFFFFFU<<0U)
#define FLASH_OPTKEYR__OPTKEYR_0            (0x1U<<0U)

// CR2 Configuration

#define FLASH_CR2_CRCRDERRIE2               (0x1U<<28U)
#define FLASH_CR2_CRCENDIE2                 (0x1U<<27U)
#define FLASH_CR2_DBECCERRIE2               (0x1U<<26U)
#define FLASH_CR2_SNECCERRIE2               (0x1U<<25U)
#define FLASH_CR2_RDSERRIE2                 (0x1U<<24U)
#define FLASH_CR2_RDPERRIE2                 (0x1U<<23U)
#define FLASH_CR2_OPERRIE2                  (0x1U<<22U)
#define FLASH_CR2_INCERRIE2                 (0x1U<<21U)
#define FLASH_CR2_STRBERRIE2                (0x1U<<19U)
#define FLASH_CR2_PGSERRIE2                 (0x1U<<18U)
#define FLASH_CR2_WRPERRIE2                 (0x1U<<17U)
#define FLASH_CR2_EOPIE2                    (0x1U<<16U)
#define FLASH_CR2_CRC_EN                    (0x1U<<15U)
#define FLASH_CR2_SPSS2                     (0x1U<<14U)
#define FLASH_CR2_SNB2                      (0x7U<<8U)
#define FLASH_CR2_SNB2_0                    (0x1U<<8U)
#define FLASH_CR2_START2                    (0x1U<<7U)
#define FLASH_CR2_FW2                       (0x1U<<6U)
#define FLASH_CR2_PSIZE2                    (0x3U<<4U)
#define FLASH_CR2_PSIZE2_0                  (0x1U<<4U)
#define FLASH_CR2_BER2                      (0x1U<<3U)
#define FLASH_CR2_SER2                      (0x1U<<2U)
#define FLASH_CR2_PG2                       (0x1U<<1U)
#define FLASH_CR2_LOCK2                     (0x1U<<0U)

// SR2 Configuration

#define FLASH_SR2_CRCEND2                   (0x1U<<27U)
#define FLASH_SR2_DBECCERR2                 (0x1U<<26U)
#define FLASH_SR2_SNECCERR2                 (0x1U<<25U)
#define FLASH_SR2_RDSERR2                   (0x1U<<24U)
#define FLASH_SR2_RDPERR2                   (0x1U<<23U)
#define FLASH_SR2_OPERR2                    (0x1U<<22U)
#define FLASH_SR2_INCERR2                   (0x1U<<21U)
#define FLASH_SR2_STRBERR2                  (0x1U<<19U)
#define FLASH_SR2_PGSERR2                   (0x1U<<18U)
#define FLASH_SR2_WRPERR2                   (0x1U<<17U)
#define FLASH_SR2_EOP2                      (0x1U<<16U)
#define FLASH_SR2_CRC_BUSY2                 (0x1U<<3U)
#define FLASH_SR2_QW2                       (0x1U<<2U)
#define FLASH_SR2_WBNE2                     (0x1U<<1U)
#define FLASH_SR2_BSY2                      (0x1U<<0U)

// CCR2 Configuration

#define FLASH_CCR2_CLR_CRCEND2              (0x1U<<27U)
#define FLASH_CCR2_CLR_DBECCERR1            (0x1U<<26U)
#define FLASH_CCR2_CLR_SNECCERR2            (0x1U<<25U)
#define FLASH_CCR2_CLR_RDSERR1              (0x1U<<24U)
#define FLASH_CCR2_CLR_RDPERR2              (0x1U<<23U)
#define FLASH_CCR2_CLR_OPERR2               (0x1U<<22U)
#define FLASH_CCR2_CLR_INCERR2              (0x1U<<21U)
#define FLASH_CCR2_CLR_STRBERR2             (0x1U<<19U)
#define FLASH_CCR2_CLR_PGSERR2              (0x1U<<18U)
#define FLASH_CCR2_CLR_WRPERR2              (0x1U<<17U)
#define FLASH_CCR2_CLR_EOP2                 (0x1U<<16U)

// OPTCR_ Configuration

#define FLASH_OPTCR__SWAP_BANK              (0x1U<<31U)
#define FLASH_OPTCR__OPTCHANGEERRIE         (0x1U<<30U)
#define FLASH_OPTCR__MER                    (0x1U<<4U)
#define FLASH_OPTCR__OPTSTART               (0x1U<<1U)
#define FLASH_OPTCR__OPTLOCK                (0x1U<<0U)

// OPTSR_CUR_ Configuration

#define FLASH_OPTSR_CUR__SWAP_BANK_OPT      (0x1U<<31U)
#define FLASH_OPTSR_CUR__OPTCHANGEERR       (0x1U<<30U)
#define FLASH_OPTSR_CUR__IO_HSLV            (0x1U<<29U)
#define FLASH_OPTSR_CUR__SECURITY           (0x1U<<21U)
#define FLASH_OPTSR_CUR__ST_RAM_SIZE        (0x3U<<19U)
#define FLASH_OPTSR_CUR__ST_RAM_SIZE_0      (0x1U<<19U)
#define FLASH_OPTSR_CUR__IWDG_FZ_SDBY       (0x1U<<18U)
#define FLASH_OPTSR_CUR__IWDG_FZ_STOP       (0x1U<<17U)
#define FLASH_OPTSR_CUR__RDP                (0xFFU<<8U)
#define FLASH_OPTSR_CUR__RDP_0              (0x1U<<8U)
#define FLASH_OPTSR_CUR__NRST_STBY_D1       (0x1U<<7U)
#define FLASH_OPTSR_CUR__NRST_STOP_D1       (0x1U<<6U)
#define FLASH_OPTSR_CUR__IWDG1_SW           (0x1U<<4U)
#define FLASH_OPTSR_CUR__BOR_LEV            (0x3U<<2U)
#define FLASH_OPTSR_CUR__BOR_LEV_0          (0x1U<<2U)
#define FLASH_OPTSR_CUR__OPT_BUSY           (0x1U<<0U)

// OPTSR_PRG_ Configuration

#define FLASH_OPTSR_PRG__SWAP_BANK_OPT      (0x1U<<31U)
#define FLASH_OPTSR_PRG__IO_HSLV            (0x1U<<29U)
#define FLASH_OPTSR_PRG__SECURITY           (0x1U<<21U)
#define FLASH_OPTSR_PRG__ST_RAM_SIZE        (0x3U<<19U)
#define FLASH_OPTSR_PRG__ST_RAM_SIZE_0      (0x1U<<19U)
#define FLASH_OPTSR_PRG__FZ_IWDG_SDBY       (0x1U<<18U)
#define FLASH_OPTSR_PRG__FZ_IWDG_STOP       (0x1U<<17U)
#define FLASH_OPTSR_PRG__RDP                (0xFFU<<8U)
#define FLASH_OPTSR_PRG__RDP_0              (0x1U<<8U)
#define FLASH_OPTSR_PRG__NRST_STDY          (0x1U<<7U)
#define FLASH_OPTSR_PRG__NRST_STOP          (0x1U<<6U)
#define FLASH_OPTSR_PRG__IWDG1_SW           (0x1U<<4U)
#define FLASH_OPTSR_PRG__BOR_LEV            (0x3U<<2U)
#define FLASH_OPTSR_PRG__BOR_LEV_0          (0x1U<<2U)

// OPTCCR_ Configuration

#define FLASH_OPTCCR__CLR_OPTCHANGEERR      (0x1U<<30U)

// PRAR_CUR2 Configuration

#define FLASH_PRAR_CUR2_DMEP2               (0x1U<<31U)
#define FLASH_PRAR_CUR2_PROT_AREA_END2      (0xFFFU<<16U)
#define FLASH_PRAR_CUR2_PROT_AREA_END2_0    (0x1U<<16U)
#define FLASH_PRAR_CUR2_PROT_AREA_START2    (0xFFFU<<0U)
#define FLASH_PRAR_CUR2_PROT_AREA_START2_0  (0x1U<<0U)

// PRAR_PRG2 Configuration

#define FLASH_PRAR_PRG2_DMEP2               (0x1U<<31U)
#define FLASH_PRAR_PRG2_PROT_AREA_END2      (0xFFFU<<16U)
#define FLASH_PRAR_PRG2_PROT_AREA_END2_0    (0x1U<<16U)
#define FLASH_PRAR_PRG2_PROT_AREA_START2    (0xFFFU<<0U)
#define FLASH_PRAR_PRG2_PROT_AREA_START2_0  (0x1U<<0U)

// SCAR_CUR2 Configuration

#define FLASH_SCAR_CUR2_DMES2               (0x1U<<31U)
#define FLASH_SCAR_CUR2_SEC_AREA_END2       (0xFFFU<<16U)
#define FLASH_SCAR_CUR2_SEC_AREA_END2_0     (0x1U<<16U)
#define FLASH_SCAR_CUR2_SEC_AREA_START2     (0xFFFU<<0U)
#define FLASH_SCAR_CUR2_SEC_AREA_START2_0   (0x1U<<0U)

// SCAR_PRG2 Configuration

#define FLASH_SCAR_PRG2_DMES2               (0x1U<<31U)
#define FLASH_SCAR_PRG2_SEC_AREA_END2       (0xFFFU<<16U)
#define FLASH_SCAR_PRG2_SEC_AREA_END2_0     (0x1U<<16U)
#define FLASH_SCAR_PRG2_SEC_AREA_START2     (0xFFFU<<0U)
#define FLASH_SCAR_PRG2_SEC_AREA_START2_0   (0x1U<<0U)

// WPSN_CUR2R Configuration

#define FLASH_WPSN_CUR2R_WRPSN2             (0xFFU<<0U)
#define FLASH_WPSN_CUR2R_WRPSN2_0           (0x1U<<0U)

// WPSN_PRG2R Configuration

#define FLASH_WPSN_PRG2R_WRPSN2             (0xFFU<<0U)
#define FLASH_WPSN_PRG2R_WRPSN2_0           (0x1U<<0U)

// BOOT_CURR_ Configuration

#define FLASH_BOOT_CURR__BOOT_ADD1          (0xFFFFU<<16U)
#define FLASH_BOOT_CURR__BOOT_ADD1_0        (0x1U<<16U)
#define FLASH_BOOT_CURR__BOOT_ADD0          (0xFFFFU<<0U)
#define FLASH_BOOT_CURR__BOOT_ADD0_0        (0x1U<<0U)

// BOOT_PRGR_ Configuration

#define FLASH_BOOT_PRGR__BOOT_ADD1          (0xFFFFU<<16U)
#define FLASH_BOOT_PRGR__BOOT_ADD1_0        (0x1U<<16U)
#define FLASH_BOOT_PRGR__BOOT_ADD0          (0xFFFFU<<0U)
#define FLASH_BOOT_PRGR__BOOT_ADD0_0        (0x1U<<0U)

// CRCCR2 Configuration

#define FLASH_CRCCR2_CRC_BURST              (0x3U<<20U)
#define FLASH_CRCCR2_CRC_BURST_0            (0x1U<<20U)
#define FLASH_CRCCR2_CLEAN_CRC              (0x1U<<17U)
#define FLASH_CRCCR2_START_CRC              (0x1U<<16U)
#define FLASH_CRCCR2_CLEAN_SECT             (0x1U<<10U)
#define FLASH_CRCCR2_ADD_SECT               (0x1U<<9U)
#define FLASH_CRCCR2_CRC_BY_SECT            (0x1U<<8U)
#define FLASH_CRCCR2_ALL_BANK               (0x1U<<7U)
#define FLASH_CRCCR2_CRC_SECT               (0x7U<<0U)
#define FLASH_CRCCR2_CRC_SECT_0             (0x1U<<0U)

// CRCSADD2R Configuration

#define FLASH_CRCSADD2R_CRC_START_ADDR      (0x3FFFFU<<2U)
#define FLASH_CRCSADD2R_CRC_START_ADDR_0    (0x1U<<2U)

// CRCEADD2R Configuration

#define FLASH_CRCEADD2R_CRC_END_ADDR        (0x3FFFFU<<2U)
#define FLASH_CRCEADD2R_CRC_END_ADDR_0      (0x1U<<2U)

// CRCDATAR_ Configuration

#define FLASH_CRCDATAR__CRC_DATA            (0xFFFFFFFFU<<0U)
#define FLASH_CRCDATAR__CRC_DATA_0          (0x1U<<0U)

// ECC_FA2R Configuration

#define FLASH_ECC_FA2R_FAIL_ECC_ADDR2       (0x7FFFU<<0U)
#define FLASH_ECC_FA2R_FAIL_ECC_ADDR2_0     (0x1U<<0U)
