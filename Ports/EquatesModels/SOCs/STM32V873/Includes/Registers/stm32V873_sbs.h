/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_sbs equates.
 */
#pragma once

#include    <stdint.h>

// SBS address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    HDPLCR;
    volatile    uint32_t    HDPLSR;
    volatile    uint32_t    OBKHDPLCR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    DBGCR;
    volatile    uint32_t    DBGLOCKR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    RSSCMDR;
    volatile    uint32_t    RESERVED3[39];
    volatile    uint32_t    EPOCHSELCR;
    volatile    uint32_t    RESERVED4[7];
    volatile    uint32_t    SECCFGR;
    volatile    uint32_t    PRIVCFGR;
    volatile    uint32_t    RCFGLOCKR;
    volatile    uint32_t    PMCR;
    volatile    uint32_t    FPUIMR;
    volatile    uint32_t    RESERVED5[2];
    volatile    uint32_t    CCCSR;
    volatile    uint32_t    CCVALR;
    volatile    uint32_t    CCSWCR;
    volatile    uint32_t    KEYR;
    volatile    uint32_t    CFGR2;
    volatile    uint32_t    RESERVED6[8];
    volatile    uint32_t    CLCKR;
    volatile    uint32_t    SCLCKR;
    volatile    uint32_t    FMC_RETIMECR;
    volatile    uint32_t    RESERVED7[12];
    volatile    uint32_t    IER;
    volatile    uint32_t    RESERVED8;
    volatile    uint32_t    ISR;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    ICR;
    volatile    uint32_t    RESERVED10;
    volatile    uint32_t    BESR;
} SBS_TypeDef;

#if (defined(__cplusplus))
#define SBS_NS  reinterpret_cast<SBS_TypeDef *>(0x46025C00u)
#define SBS_S   reinterpret_cast<SBS_TypeDef *>(0x56025C00u)

#else
#define SBS_NS  ((SBS_TypeDef *)0x46025C00u)
#define SBS_S   ((SBS_TypeDef *)0x56025C00u)
#endif

// HDPLCR Configuration

#define SBS_HDPLCR_INCR_HDPL                    (0xFFu<<0)
#define SBS_HDPLCR_INCR_HDPL_0                  (0x1u<<0)

#define SBS_HDPLCR_INCR_HDPL_B_0XB4             (0xB4u<<0)
#define SBS_HDPLCR_INCR_HDPL_B_0X6A             (0x6Au<<0)

// HDPLSR Configuration

#define SBS_HDPLSR_HDPL                         (0xFFu<<0)
#define SBS_HDPLSR_HDPL_0                       (0x1u<<0)

#define SBS_HDPLSR_HDPL_B_0XB4                  (0xB4u<<0)
#define SBS_HDPLSR_HDPL_B_0X51                  (0x51u<<0)
#define SBS_HDPLSR_HDPL_B_0X8A                  (0x8Au<<0)
#define SBS_HDPLSR_HDPL_B_0X6F                  (0x6Fu<<0)

// OBKHDPLCR Configuration

#define SBS_OBKHDPLCR_NEXTHDPL                  (0x3u<<0)
#define SBS_OBKHDPLCR_NEXTHDPL_0                (0x1u<<0)

// DBGCR Configuration

#define SBS_DBGCR_DBG_AUTH_SEC                  (0xFFu<<24)
#define SBS_DBGCR_DBG_AUTH_SEC_0                (0x1u<<24)
#define SBS_DBGCR_DBG_AUTH_HDPL                 (0xFFu<<16)
#define SBS_DBGCR_DBG_AUTH_HDPL_0               (0x1u<<16)
#define SBS_DBGCR_DBG_UNLOCK                    (0xFFu<<8)
#define SBS_DBGCR_DBG_UNLOCK_0                  (0x1u<<8)
#define SBS_DBGCR_AP_UNLOCK                     (0xFFu<<0)
#define SBS_DBGCR_AP_UNLOCK_0                   (0x1u<<0)

#define SBS_DBGCR_DBG_AUTH_HDPL_B_0X51          (0x51u<<16)
#define SBS_DBGCR_DBG_AUTH_HDPL_B_0X8A          (0x8Au<<16)
#define SBS_DBGCR_DBG_AUTH_HDPL_B_0X6F          (0x6Fu<<16)

// DBGLOCKR Configuration

#define SBS_DBGLOCKR_DBGCFG_LOCK                (0xFFu<<0)
#define SBS_DBGLOCKR_DBGCFG_LOCK_0              (0x1u<<0)

#define SBS_DBGLOCKR_DBGCFG_LOCK_B_0XC3         (0xC3u<<0)
#define SBS_DBGLOCKR_DBGCFG_LOCK_B_0XB4         (0xB4u<<0)

// RSSCMDR Configuration

#define SBS_RSSCMDR_RSSCMD                      (0xFFFFu<<0)
#define SBS_RSSCMDR_RSSCMD_0                    (0x1u<<0)

// EPOCHSELCR Configuration

#define SBS_EPOCHSELCR_EPOCH_SEL                (0xFFu<<0)
#define SBS_EPOCHSELCR_EPOCH_SEL_0              (0x1u<<0)

#define SBS_EPOCHSELCR_EPOCH_SEL_B_0XD4         (0xD4u<<0)
#define SBS_EPOCHSELCR_EPOCH_SEL_B_0X59         (0x59u<<0)

// SECCFGR Configuration

#define SBS_SECCFGR_BRIDGE                      (0x1u<<7)
#define SBS_SECCFGR_FMCRETIME                   (0x1u<<6)
#define SBS_SECCFGR_FPU                         (0x1u<<3)
#define SBS_SECCFGR_CLASSB                      (0x1u<<1)
#define SBS_SECCFGR_SBS                         (0x1u<<0)

#define SBS_SECCFGR_BRIDGE_B_0X0                (0x0u<<7)
#define SBS_SECCFGR_BRIDGE_B_0X1                (0x1u<<7)
#define SBS_SECCFGR_FMCRETIME_B_0X0             (0x0u<<6)
#define SBS_SECCFGR_FMCRETIME_B_0X1             (0x1u<<6)
#define SBS_SECCFGR_FPU_B_0X0                   (0x0u<<3)
#define SBS_SECCFGR_FPU_B_0X1                   (0x1u<<3)
#define SBS_SECCFGR_CLASSB_B_0X0                (0x0u<<1)
#define SBS_SECCFGR_CLASSB_B_0X1                (0x1u<<1)
#define SBS_SECCFGR_SBS_B_0X0                   (0x0u<<0)
#define SBS_SECCFGR_SBS_B_0X1                   (0x1u<<0)

// PRIVCFGR Configuration

#define SBS_PRIVCFGR_BRIDGE                     (0x1u<<7)
#define SBS_PRIVCFGR_FMCRETIME                  (0x1u<<6)
#define SBS_PRIVCFGR_PM                         (0x1u<<4)
#define SBS_PRIVCFGR_CLASSB                     (0x1u<<1)
#define SBS_PRIVCFGR_SBS                        (0x1u<<0)

#define SBS_PRIVCFGR_BRIDGE_B_0X0               (0x0u<<7)
#define SBS_PRIVCFGR_BRIDGE_B_0X1               (0x1u<<7)
#define SBS_PRIVCFGR_FMCRETIME_B_0X0            (0x0u<<6)
#define SBS_PRIVCFGR_FMCRETIME_B_0X1            (0x1u<<6)
#define SBS_PRIVCFGR_PM_B_0X0                   (0x0u<<4)
#define SBS_PRIVCFGR_PM_B_0X1                   (0x1u<<4)
#define SBS_PRIVCFGR_CLASSB_B_0X0               (0x0u<<1)
#define SBS_PRIVCFGR_CLASSB_B_0X1               (0x1u<<1)
#define SBS_PRIVCFGR_SBS_B_0X0                  (0x0u<<0)
#define SBS_PRIVCFGR_SBS_B_0X1                  (0x1u<<0)

// RCFGLOCKR Configuration

#define SBS_RCFGLOCKR_BRIDGE                    (0x1u<<7)
#define SBS_RCFGLOCKR_FMCRETIME                 (0x1u<<6)
#define SBS_RCFGLOCKR_PM                        (0x1u<<4)
#define SBS_RCFGLOCKR_FPU                       (0x1u<<3)
#define SBS_RCFGLOCKR_CLASSB                    (0x1u<<1)
#define SBS_RCFGLOCKR_SBS                       (0x1u<<0)

#define SBS_RCFGLOCKR_BRIDGE_B_0X0              (0x0u<<7)
#define SBS_RCFGLOCKR_BRIDGE_B_0X1              (0x1u<<7)
#define SBS_RCFGLOCKR_FMCRETIME_B_0X0           (0x0u<<6)
#define SBS_RCFGLOCKR_FMCRETIME_B_0X1           (0x1u<<6)
#define SBS_RCFGLOCKR_PM_B_0X0                  (0x0u<<4)
#define SBS_RCFGLOCKR_PM_B_0X1                  (0x1u<<4)
#define SBS_RCFGLOCKR_FPU_B_0X0                 (0x0u<<3)
#define SBS_RCFGLOCKR_FPU_B_0X1                 (0x1u<<3)
#define SBS_RCFGLOCKR_CLASSB_B_0X0              (0x0u<<1)
#define SBS_RCFGLOCKR_CLASSB_B_0X1              (0x1u<<1)
#define SBS_RCFGLOCKR_SBS_B_0X0                 (0x0u<<0)
#define SBS_RCFGLOCKR_SBS_B_0X1                 (0x1u<<0)

// PMCR Configuration

#define SBS_PMCR_PB9_FMP                        (0x1u<<19)
#define SBS_PMCR_PB8_FMP                        (0x1u<<18)
#define SBS_PMCR_PB7_FMP                        (0x1u<<17)
#define SBS_PMCR_PB6_FMP                        (0x1u<<16)

#define SBS_PMCR_PB9_FMP_B_0X0                  (0x0u<<19)
#define SBS_PMCR_PB9_FMP_B_0X1                  (0x1u<<19)
#define SBS_PMCR_PB8_FMP_B_0X0                  (0x0u<<18)
#define SBS_PMCR_PB8_FMP_B_0X1                  (0x1u<<18)
#define SBS_PMCR_PB7_FMP_B_0X0                  (0x0u<<17)
#define SBS_PMCR_PB7_FMP_B_0X1                  (0x1u<<17)
#define SBS_PMCR_PB6_FMP_B_0X0                  (0x0u<<16)
#define SBS_PMCR_PB6_FMP_B_0X1                  (0x1u<<16)

// FPUIMR Configuration

#define SBS_FPUIMR_FPU_IE                       (0x3Fu<<0)
#define SBS_FPUIMR_FPU_IE_0                     (0x1u<<0)

// CCCSR Configuration

#define SBS_CCCSR_VDDXSPI2RDY                   (0x1u<<10)
#define SBS_CCCSR_VDDXSPI1RDY                   (0x1u<<9)
#define SBS_CCCSR_VDDRDY                        (0x1u<<8)
#define SBS_CCCSR_VDDXSPI2CS                    (0x1u<<5)
#define SBS_CCCSR_VDDXSPI2EN                    (0x1u<<4)
#define SBS_CCCSR_VDDXSPI1CS                    (0x1u<<3)
#define SBS_CCCSR_VDDXSPI1EN                    (0x1u<<2)
#define SBS_CCCSR_VDDCS                         (0x1u<<1)
#define SBS_CCCSR_VDDEN                         (0x1u<<0)

#define SBS_CCCSR_VDDXSPI2RDY_B_0X0             (0x0u<<10)
#define SBS_CCCSR_VDDXSPI2RDY_B_0X1             (0x1u<<10)
#define SBS_CCCSR_VDDXSPI1RDY_B_0X0             (0x0u<<9)
#define SBS_CCCSR_VDDXSPI1RDY_B_0X1             (0x1u<<9)
#define SBS_CCCSR_VDDRDY_B_0X0                  (0x0u<<8)
#define SBS_CCCSR_VDDRDY_B_0X1                  (0x1u<<8)
#define SBS_CCCSR_VDDXSPI2CS_B_0X0              (0x0u<<5)
#define SBS_CCCSR_VDDXSPI2CS_B_0X1              (0x1u<<5)
#define SBS_CCCSR_VDDXSPI2EN_B_0X0              (0x0u<<4)
#define SBS_CCCSR_VDDXSPI2EN_B_0X1              (0x1u<<4)
#define SBS_CCCSR_VDDXSPI1CS_B_0X0              (0x0u<<3)
#define SBS_CCCSR_VDDXSPI1CS_B_0X1              (0x1u<<3)
#define SBS_CCCSR_VDDXSPI1EN_B_0X0              (0x0u<<2)
#define SBS_CCCSR_VDDXSPI1EN_B_0X1              (0x1u<<2)
#define SBS_CCCSR_VDDCS_B_0X0                   (0x0u<<1)
#define SBS_CCCSR_VDDCS_B_0X1                   (0x1u<<1)
#define SBS_CCCSR_VDDEN_B_0X0                   (0x0u<<0)
#define SBS_CCCSR_VDDEN_B_0X1                   (0x1u<<0)

// CCVALR Configuration

#define SBS_CCVALR_VDDXSPI2PSRC                 (0xFu<<20)
#define SBS_CCVALR_VDDXSPI2PSRC_0               (0x1u<<20)
#define SBS_CCVALR_VDDXSPI2NSRC                 (0xFu<<16)
#define SBS_CCVALR_VDDXSPI2NSRC_0               (0x1u<<16)
#define SBS_CCVALR_VDDXSPI1PSRC                 (0xFu<<12)
#define SBS_CCVALR_VDDXSPI1PSRC_0               (0x1u<<12)
#define SBS_CCVALR_VDDXSPI1NSRC                 (0xFu<<8)
#define SBS_CCVALR_VDDXSPI1NSRC_0               (0x1u<<8)
#define SBS_CCVALR_VDDPSRC                      (0xFu<<4)
#define SBS_CCVALR_VDDPSRC_0                    (0x1u<<4)
#define SBS_CCVALR_VDDNSRC                      (0xFu<<0)
#define SBS_CCVALR_VDDNSRC_0                    (0x1u<<0)

// CCSWCR Configuration

#define SBS_CCSWCR_VDDXSPI2PSRC                 (0xFu<<20)
#define SBS_CCSWCR_VDDXSPI2PSRC_0               (0x1u<<20)
#define SBS_CCSWCR_VDDXSPI2NSRC                 (0xFu<<16)
#define SBS_CCSWCR_VDDXSPI2NSRC_0               (0x1u<<16)
#define SBS_CCSWCR_VDDXSPI1PSRC                 (0xFu<<12)
#define SBS_CCSWCR_VDDXSPI1PSRC_0               (0x1u<<12)
#define SBS_CCSWCR_VDDXSPI1NSRC                 (0xFu<<8)
#define SBS_CCSWCR_VDDXSPI1NSRC_0               (0x1u<<8)
#define SBS_CCSWCR_VDDPSRC                      (0xFu<<4)
#define SBS_CCSWCR_VDDPSRC_0                    (0x1u<<4)
#define SBS_CCSWCR_VDDNSRC                      (0xFu<<0)
#define SBS_CCSWCR_VDDNSRC_0                    (0x1u<<0)

// KEYR Configuration

#define SBS_KEYR_KEY                            (0xFFFFFFFFu<<0)
#define SBS_KEYR_KEY_0                          (0x1u<<0)

// CFGR2 Configuration

#define SBS_CFGR2_LOCK                          (0x1u<<31)
#define SBS_CFGR2_AXIRAM1ECC                    (0x1u<<23)
#define SBS_CFGR2_AXIRAM6FLEXECC                (0x1u<<18)
#define SBS_CFGR2_AXIRAM6FIXECC                 (0x1u<<17)
#define SBS_CFGR2_ITCMECC                       (0x1u<<14)
#define SBS_CFGR2_DTCMECC                       (0x1u<<13)
#define SBS_CFGR2_DCACHEECC                     (0x1u<<11)
#define SBS_CFGR2_BKPRAMECC                     (0x1u<<7)
#define SBS_CFGR2_NVMECC                        (0x1u<<3)
#define SBS_CFGR2_PVD                           (0x1u<<2)
#define SBS_CFGR2_CL                            (0x1u<<0)

#define SBS_CFGR2_LOCK_B_0X0                    (0x0u<<31)
#define SBS_CFGR2_LOCK_B_0X1                    (0x1u<<31)
#define SBS_CFGR2_AXIRAM1ECC_B_0X0              (0x0u<<23)
#define SBS_CFGR2_AXIRAM1ECC_B_0X1              (0x1u<<23)
#define SBS_CFGR2_AXIRAM6FLEXECC_B_0X0          (0x0u<<18)
#define SBS_CFGR2_AXIRAM6FLEXECC_B_0X1          (0x1u<<18)
#define SBS_CFGR2_AXIRAM6FIXECC_B_0X0           (0x0u<<17)
#define SBS_CFGR2_AXIRAM6FIXECC_B_0X1           (0x1u<<17)
#define SBS_CFGR2_ITCMECC_B_0X0                 (0x0u<<14)
#define SBS_CFGR2_ITCMECC_B_0X1                 (0x1u<<14)
#define SBS_CFGR2_DTCMECC_B_0X0                 (0x0u<<13)
#define SBS_CFGR2_DTCMECC_B_0X1                 (0x1u<<13)
#define SBS_CFGR2_DCACHEECC_B_0X0               (0x0u<<11)
#define SBS_CFGR2_DCACHEECC_B_0X1               (0x1u<<11)
#define SBS_CFGR2_BKPRAMECC_B_0X0               (0x0u<<7)
#define SBS_CFGR2_BKPRAMECC_B_0X1               (0x1u<<7)
#define SBS_CFGR2_NVMECC_B_0X0                  (0x0u<<3)
#define SBS_CFGR2_NVMECC_B_0X1                  (0x1u<<3)
#define SBS_CFGR2_PVD_B_0X0                     (0x0u<<2)
#define SBS_CFGR2_PVD_B_0X1                     (0x1u<<2)
#define SBS_CFGR2_CL_B_0X0                      (0x0u<<0)
#define SBS_CFGR2_CL_B_0X1                      (0x1u<<0)

// CLCKR Configuration

#define SBS_CLCKR_LOCKNSMPU                     (0x1u<<1)
#define SBS_CLCKR_LOCKNSVTOR                    (0x1u<<0)

#define SBS_CLCKR_LOCKNSMPU_B_0X0               (0x0u<<1)
#define SBS_CLCKR_LOCKNSMPU_B_0X1               (0x1u<<1)
#define SBS_CLCKR_LOCKNSVTOR_B_0X0              (0x0u<<0)
#define SBS_CLCKR_LOCKNSVTOR_B_0X1              (0x1u<<0)

// SCLCKR Configuration

#define SBS_SCLCKR_LOCKSAU                      (0x1u<<2)
#define SBS_SCLCKR_LOCKSMPU                     (0x1u<<1)
#define SBS_SCLCKR_LOCKSVTAIRCR                 (0x1u<<0)

#define SBS_SCLCKR_LOCKSAU_B_0X0                (0x0u<<2)
#define SBS_SCLCKR_LOCKSAU_B_0X1                (0x1u<<2)
#define SBS_SCLCKR_LOCKSMPU_B_0X0               (0x0u<<1)
#define SBS_SCLCKR_LOCKSMPU_B_0X1               (0x1u<<1)
#define SBS_SCLCKR_LOCKSVTAIRCR_B_0X0           (0x0u<<0)
#define SBS_SCLCKR_LOCKSVTAIRCR_B_0X1           (0x1u<<0)

// FMC_RETIMECR Configuration

#define SBS_FMC_RETIMECR_SDFBCLK_180            (0x1u<<2)
#define SBS_FMC_RETIMECR_CFG_RETIME_TX          (0x1u<<1)
#define SBS_FMC_RETIMECR_CFG_RETIME_RX          (0x1u<<0)

#define SBS_FMC_RETIMECR_SDFBCLK_180_B_0X0      (0x0u<<2)
#define SBS_FMC_RETIMECR_SDFBCLK_180_B_0X1      (0x1u<<2)
#define SBS_FMC_RETIMECR_CFG_RETIME_TX_B_0X0    (0x0u<<1)
#define SBS_FMC_RETIMECR_CFG_RETIME_TX_B_0X1    (0x1u<<1)
#define SBS_FMC_RETIMECR_CFG_RETIME_RX_B_0X0    (0x0u<<0)
#define SBS_FMC_RETIMECR_CFG_RETIME_RX_B_0X1    (0x1u<<0)

// IER Configuration

#define SBS_IER_BRIDGE                          (0x1u<<0)

#define SBS_IER_BRIDGE_B_0X0                    (0x0u<<0)
#define SBS_IER_BRIDGE_B_0X1                    (0x1u<<0)

// ISR Configuration

#define SBS_ISR_BRIDGE                          (0x1u<<0)

#define SBS_ISR_BRIDGE_B_0X0                    (0x0u<<0)
#define SBS_ISR_BRIDGE_B_0X1                    (0x1u<<0)

// ICR Configuration

#define SBS_ICR_BRIDGE                          (0x1u<<0)

#define SBS_ICR_BRIDGE_B_0X0                    (0x0u<<0)
#define SBS_ICR_BRIDGE_B_0X1                    (0x1u<<0)

// BESR Configuration

#define SBS_BESR_BRIDGEID                       (0x7u<<0)
#define SBS_BESR_BRIDGEID_0                     (0x1u<<0)

#define SBS_BESR_BRIDGEID_B_0X0                 (0x0u<<0)
#define SBS_BESR_BRIDGEID_B_0X1                 (0x1u<<0)
#define SBS_BESR_BRIDGEID_B_0X2                 (0x2u<<0)
#define SBS_BESR_BRIDGEID_B_0X3                 (0x3u<<0)
#define SBS_BESR_BRIDGEID_B_0X4                 (0x4u<<0)
#define SBS_BESR_BRIDGEID_B_0X5                 (0x5u<<0)
