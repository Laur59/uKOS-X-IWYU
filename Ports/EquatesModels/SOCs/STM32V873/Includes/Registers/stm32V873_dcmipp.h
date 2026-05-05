/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_dcmipp equates.
 */
#pragma once

#include    <stdint.h>

// DCMIPP address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    IPGR1;
    volatile    uint32_t    IPGR2;
    volatile    uint32_t    IPGR3;
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    IPGR8;
    volatile    uint32_t    IPC1R1;
    volatile    uint32_t    IPC1R2;
    volatile    uint32_t    IPC1R3;
    volatile    uint32_t    RESERVED1[54];
    volatile    uint32_t    PRCR;
    volatile    uint32_t    PRESCR;
    volatile    uint32_t    PRESUR;
    volatile    uint32_t    RESERVED2[57];
    volatile    uint32_t    PRIER;
    volatile    uint32_t    PRSR;
    volatile    uint32_t    PRFCR;
    volatile    uint32_t    RESERVED3;
    volatile    uint32_t    CMCR;
    volatile    uint32_t    CMFRCR;
    volatile    uint32_t    RESERVED4[121];
    volatile    uint32_t    CMIER;
    volatile    uint32_t    CMSR1;
    volatile    uint32_t    CMSR2;
    volatile    uint32_t    CMFCR;
    volatile    uint32_t    RESERVED5;
    volatile    uint32_t    P0FSCR;
    volatile    uint32_t    RESERVED6[62];
    volatile    uint32_t    P0FCTCR;
    volatile    uint32_t    P0SCSTR;
    volatile    uint32_t    P0SCSZR;
    volatile    uint32_t    RESERVED7[41];
    volatile    uint32_t    P0DCCNTR;
    volatile    uint32_t    P0DCLMTR;
    volatile    uint32_t    RESERVED8[2];
    volatile    uint32_t    P0PPCR;
    volatile    uint32_t    P0PPM0AR1;
    volatile    uint32_t    P0PPM0AR2;
    volatile    uint32_t    RESERVED9;
    volatile    uint32_t    P0STM0AR;
    volatile    uint32_t    RESERVED10[8];
    volatile    uint32_t    P0IER;
    volatile    uint32_t    P0SR;
    volatile    uint32_t    P0FCR;
    volatile    uint32_t    RESERVED11[64];
    volatile    uint32_t    P0CFCTCR;
    volatile    uint32_t    P0CSCSTR;
    volatile    uint32_t    P0CSCSZR;
    volatile    uint32_t    RESERVED12[45];
    volatile    uint32_t    P0CPPCR;
    volatile    uint32_t    P0CPPM0AR1;
    volatile    uint32_t    P0CPPM0AR2;
} DCMIPP_TypeDef;

#if (defined(__cplusplus))
#define DCMIPP_NS   reinterpret_cast<DCMIPP_TypeDef *>(0x48002000u)
#define DCMIPP_S    reinterpret_cast<DCMIPP_TypeDef *>(0x58002000u)

#else
#define DCMIPP_NS   ((DCMIPP_TypeDef *)0x48002000u)
#define DCMIPP_S    ((DCMIPP_TypeDef *)0x58002000u)
#endif

// IPGR1 Configuration

#define DCMIPP_IPGR1_QOS_MODE           (0x1u<<24)
#define DCMIPP_IPGR1_MEMORYPAGE         (0x7u<<0)
#define DCMIPP_IPGR1_MEMORYPAGE_0       (0x1u<<0)

#define DCMIPP_IPGR1_MEMORYPAGE_B_0X0   (0x0u<<0)
#define DCMIPP_IPGR1_MEMORYPAGE_B_0X1   (0x1u<<0)

// IPGR2 Configuration

#define DCMIPP_IPGR2_PSTART             (0x1u<<0)

#define DCMIPP_IPGR2_PSTART_B_0X0       (0x0u<<0)
#define DCMIPP_IPGR2_PSTART_B_0X1       (0x1u<<0)

// IPGR3 Configuration

#define DCMIPP_IPGR3_IDLE               (0x1u<<0)

#define DCMIPP_IPGR3_IDLE_B_0X0         (0x0u<<0)
#define DCMIPP_IPGR3_IDLE_B_0X1         (0x1u<<0)

// IPGR8 Configuration

#define DCMIPP_IPGR8_IPPID              (0xFFu<<24)
#define DCMIPP_IPGR8_IPPID_0            (0x1u<<24)
#define DCMIPP_IPGR8_ARCHIID            (0x1Fu<<16)
#define DCMIPP_IPGR8_ARCHIID_0          (0x1u<<16)
#define DCMIPP_IPGR8_REVID              (0x1Fu<<8)
#define DCMIPP_IPGR8_REVID_0            (0x1u<<8)
#define DCMIPP_IPGR8_DID                (0x3Fu<<0)
#define DCMIPP_IPGR8_DID_0              (0x1u<<0)

// IPC1R1 Configuration

#define DCMIPP_IPC1R1_OTR               (0x3u<<8)
#define DCMIPP_IPC1R1_OTR_0             (0x1u<<8)
#define DCMIPP_IPC1R1_TRAFFIC           (0x7u<<0)
#define DCMIPP_IPC1R1_TRAFFIC_0         (0x1u<<0)

#define DCMIPP_IPC1R1_OTR_B_0X0         (0x0u<<8)
#define DCMIPP_IPC1R1_OTR_B_0X1         (0x1u<<8)
#define DCMIPP_IPC1R1_TRAFFIC_B_0X0     (0x0u<<0)
#define DCMIPP_IPC1R1_TRAFFIC_B_0X1     (0x1u<<0)

// IPC1R2 Configuration

#define DCMIPP_IPC1R2_WLRU              (0xFu<<16)
#define DCMIPP_IPC1R2_WLRU_0            (0x1u<<16)
#define DCMIPP_IPC1R2_SVCMAPPING        (0xFu<<8)
#define DCMIPP_IPC1R2_SVCMAPPING_0      (0x1u<<8)

#define DCMIPP_IPC1R2_WLRU_B_0X0        (0x0u<<16)
#define DCMIPP_IPC1R2_WLRU_B_0X1        (0x1u<<16)

// IPC1R3 Configuration

#define DCMIPP_IPC1R3_DPREGEND          (0x1Fu<<16)
#define DCMIPP_IPC1R3_DPREGEND_0        (0x1u<<16)
#define DCMIPP_IPC1R3_DPREGSTART        (0x1Fu<<0)
#define DCMIPP_IPC1R3_DPREGSTART_0      (0x1u<<0)

// PRCR Configuration

#define DCMIPP_PRCR_SWAPBITS            (0x1u<<26)
#define DCMIPP_PRCR_SWAPCYCLES          (0x1u<<25)
#define DCMIPP_PRCR_FORMAT              (0xFFu<<16)
#define DCMIPP_PRCR_FORMAT_0            (0x1u<<16)
#define DCMIPP_PRCR_ENABLE              (0x1u<<14)
#define DCMIPP_PRCR_EDM                 (0x7u<<10)
#define DCMIPP_PRCR_EDM_0               (0x1u<<10)
#define DCMIPP_PRCR_VSPOL               (0x1u<<7)
#define DCMIPP_PRCR_HSPOL               (0x1u<<6)
#define DCMIPP_PRCR_PCKPOL              (0x1u<<5)
#define DCMIPP_PRCR_ESS                 (0x1u<<4)

#define DCMIPP_PRCR_SWAPBITS_B_0X0      (0x0u<<26)
#define DCMIPP_PRCR_SWAPBITS_B_0X1      (0x1u<<26)
#define DCMIPP_PRCR_SWAPCYCLES_B_0X0    (0x0u<<25)
#define DCMIPP_PRCR_SWAPCYCLES_B_0X1    (0x1u<<25)
#define DCMIPP_PRCR_FORMAT_B_0X1E       (0x1Eu<<16)
#define DCMIPP_PRCR_FORMAT_B_0X22       (0x22u<<16)
#define DCMIPP_PRCR_FORMAT_B_0X24       (0x24u<<16)
#define DCMIPP_PRCR_FORMAT_B_0X2A       (0x2Au<<16)
#define DCMIPP_PRCR_FORMAT_B_0X2B       (0x2Bu<<16)
#define DCMIPP_PRCR_FORMAT_B_0X2C       (0x2Cu<<16)
#define DCMIPP_PRCR_FORMAT_B_0X2D       (0x2Du<<16)
#define DCMIPP_PRCR_FORMAT_B_0X4A       (0x4Au<<16)
#define DCMIPP_PRCR_FORMAT_B_0X4B       (0x4Bu<<16)
#define DCMIPP_PRCR_FORMAT_B_0X4C       (0x4Cu<<16)
#define DCMIPP_PRCR_FORMAT_B_0X4D       (0x4Du<<16)
#define DCMIPP_PRCR_FORMAT_B_0X5A       (0x5Au<<16)
#define DCMIPP_PRCR_ENABLE_B_0X0        (0x0u<<14)
#define DCMIPP_PRCR_ENABLE_B_0X1        (0x1u<<14)
#define DCMIPP_PRCR_EDM_B_0X0           (0x0u<<10)
#define DCMIPP_PRCR_EDM_B_0X1           (0x1u<<10)
#define DCMIPP_PRCR_EDM_B_0X2           (0x2u<<10)
#define DCMIPP_PRCR_EDM_B_0X3           (0x3u<<10)
#define DCMIPP_PRCR_EDM_B_0X4           (0x4u<<10)
#define DCMIPP_PRCR_VSPOL_B_0X0         (0x0u<<7)
#define DCMIPP_PRCR_VSPOL_B_0X1         (0x1u<<7)
#define DCMIPP_PRCR_HSPOL_B_0X0         (0x0u<<6)
#define DCMIPP_PRCR_HSPOL_B_0X1         (0x1u<<6)
#define DCMIPP_PRCR_PCKPOL_B_0X0        (0x0u<<5)
#define DCMIPP_PRCR_PCKPOL_B_0X1        (0x1u<<5)
#define DCMIPP_PRCR_ESS_B_0X0           (0x0u<<4)
#define DCMIPP_PRCR_ESS_B_0X1           (0x1u<<4)

// PRESCR Configuration

#define DCMIPP_PRESCR_FEC               (0xFFu<<24)
#define DCMIPP_PRESCR_FEC_0             (0x1u<<24)
#define DCMIPP_PRESCR_LEC               (0xFFu<<16)
#define DCMIPP_PRESCR_LEC_0             (0x1u<<16)
#define DCMIPP_PRESCR_LSC               (0xFFu<<8)
#define DCMIPP_PRESCR_LSC_0             (0x1u<<8)
#define DCMIPP_PRESCR_FSC               (0xFFu<<0)
#define DCMIPP_PRESCR_FSC_0             (0x1u<<0)

// PRESUR Configuration

#define DCMIPP_PRESUR_FEU               (0xFFu<<24)
#define DCMIPP_PRESUR_FEU_0             (0x1u<<24)
#define DCMIPP_PRESUR_LEU               (0xFFu<<16)
#define DCMIPP_PRESUR_LEU_0             (0x1u<<16)
#define DCMIPP_PRESUR_LSU               (0xFFu<<8)
#define DCMIPP_PRESUR_LSU_0             (0x1u<<8)
#define DCMIPP_PRESUR_FSU               (0xFFu<<0)
#define DCMIPP_PRESUR_FSU_0             (0x1u<<0)

#define DCMIPP_PRESUR_FEU_B_0X0         (0x0u<<24)
#define DCMIPP_PRESUR_FEU_B_0X1         (0x1u<<24)
#define DCMIPP_PRESUR_LEU_B_0X0         (0x0u<<16)
#define DCMIPP_PRESUR_LEU_B_0X1         (0x1u<<16)
#define DCMIPP_PRESUR_LSU_B_0X0         (0x0u<<8)
#define DCMIPP_PRESUR_LSU_B_0X1         (0x1u<<8)
#define DCMIPP_PRESUR_FSU_B_0X0         (0x0u<<0)
#define DCMIPP_PRESUR_FSU_B_0X1         (0x1u<<0)

// PRIER Configuration

#define DCMIPP_PRIER_ERRIE              (0x1u<<6)

#define DCMIPP_PRIER_ERRIE_B_0X0        (0x0u<<6)
#define DCMIPP_PRIER_ERRIE_B_0X1        (0x1u<<6)

// PRSR Configuration

#define DCMIPP_PRSR_VSYNC               (0x1u<<17)
#define DCMIPP_PRSR_HSYNC               (0x1u<<16)
#define DCMIPP_PRSR_ERRF                (0x1u<<6)

#define DCMIPP_PRSR_VSYNC_B_0X0         (0x0u<<17)
#define DCMIPP_PRSR_VSYNC_B_0X1         (0x1u<<17)
#define DCMIPP_PRSR_HSYNC_B_0X0         (0x0u<<16)
#define DCMIPP_PRSR_HSYNC_B_0X1         (0x1u<<16)
#define DCMIPP_PRSR_ERRF_B_0X0          (0x0u<<6)
#define DCMIPP_PRSR_ERRF_B_0X1          (0x1u<<6)

// PRFCR Configuration

#define DCMIPP_PRFCR_CERRF              (0x1u<<6)

// CMCR Configuration

#define DCMIPP_CMCR_CFC                 (0x1u<<4)

// CMFRCR Configuration

#define DCMIPP_CMFRCR_FRMCNT            (0xFFFFFFFFu<<0)
#define DCMIPP_CMFRCR_FRMCNT_0          (0x1u<<0)

// CMIER Configuration

#define DCMIPP_CMIER_P0OVRIE            (0x1u<<15)
#define DCMIPP_CMIER_P0LIMITIE          (0x1u<<14)
#define DCMIPP_CMIER_P0VSYNCIE          (0x1u<<10)
#define DCMIPP_CMIER_P0FRAMEIE          (0x1u<<9)
#define DCMIPP_CMIER_P0LINEIE           (0x1u<<8)
#define DCMIPP_CMIER_PRERRIE            (0x1u<<6)
#define DCMIPP_CMIER_ATXERRIE           (0x1u<<5)

#define DCMIPP_CMIER_P0OVRIE_B_0X0      (0x0u<<15)
#define DCMIPP_CMIER_P0OVRIE_B_0X1      (0x1u<<15)
#define DCMIPP_CMIER_P0LIMITIE_B_0X0    (0x0u<<14)
#define DCMIPP_CMIER_P0LIMITIE_B_0X1    (0x1u<<14)
#define DCMIPP_CMIER_P0VSYNCIE_B_0X0    (0x0u<<10)
#define DCMIPP_CMIER_P0VSYNCIE_B_0X1    (0x1u<<10)
#define DCMIPP_CMIER_P0FRAMEIE_B_0X0    (0x0u<<9)
#define DCMIPP_CMIER_P0FRAMEIE_B_0X1    (0x1u<<9)
#define DCMIPP_CMIER_P0LINEIE_B_0X0     (0x0u<<8)
#define DCMIPP_CMIER_P0LINEIE_B_0X1     (0x1u<<8)
#define DCMIPP_CMIER_PRERRIE_B_0X0      (0x0u<<6)
#define DCMIPP_CMIER_PRERRIE_B_0X1      (0x1u<<6)
#define DCMIPP_CMIER_ATXERRIE_B_0X0     (0x0u<<5)
#define DCMIPP_CMIER_ATXERRIE_B_0X1     (0x1u<<5)

// CMSR1 Configuration

#define DCMIPP_CMSR1_P0CPTACT           (0x1u<<15)
#define DCMIPP_CMSR1_PRVSYNC            (0x1u<<1)
#define DCMIPP_CMSR1_PRHSYNC            (0x1u<<0)

#define DCMIPP_CMSR1_P0CPTACT_B_0X0     (0x0u<<15)
#define DCMIPP_CMSR1_P0CPTACT_B_0X1     (0x1u<<15)
#define DCMIPP_CMSR1_PRVSYNC_B_0X0      (0x0u<<1)
#define DCMIPP_CMSR1_PRVSYNC_B_0X1      (0x1u<<1)
#define DCMIPP_CMSR1_PRHSYNC_B_0X0      (0x0u<<0)
#define DCMIPP_CMSR1_PRHSYNC_B_0X1      (0x1u<<0)

// CMSR2 Configuration

#define DCMIPP_CMSR2_P0OVRF             (0x1u<<15)
#define DCMIPP_CMSR2_P0LIMITF           (0x1u<<14)
#define DCMIPP_CMSR2_P0VSYNCF           (0x1u<<10)
#define DCMIPP_CMSR2_P0FRAMEF           (0x1u<<9)
#define DCMIPP_CMSR2_P0LINEF            (0x1u<<8)
#define DCMIPP_CMSR2_PRERRF             (0x1u<<6)
#define DCMIPP_CMSR2_ATXERRF            (0x1u<<5)

#define DCMIPP_CMSR2_P0OVRF_B_0X0       (0x0u<<15)
#define DCMIPP_CMSR2_P0OVRF_B_0X1       (0x1u<<15)
#define DCMIPP_CMSR2_P0FRAMEF_B_0X0     (0x0u<<9)
#define DCMIPP_CMSR2_P0FRAMEF_B_0X1     (0x1u<<9)
#define DCMIPP_CMSR2_PRERRF_B_0X0       (0x0u<<6)
#define DCMIPP_CMSR2_PRERRF_B_0X1       (0x1u<<6)
#define DCMIPP_CMSR2_ATXERRF_B_0X0      (0x0u<<5)
#define DCMIPP_CMSR2_ATXERRF_B_0X1      (0x1u<<5)

// CMFCR Configuration

#define DCMIPP_CMFCR_CP0OVRF            (0x1u<<15)
#define DCMIPP_CMFCR_CP0LIMITF          (0x1u<<14)
#define DCMIPP_CMFCR_CP0VSYNCF          (0x1u<<10)
#define DCMIPP_CMFCR_CP0FRAMEF          (0x1u<<9)
#define DCMIPP_CMFCR_CP0LINEF           (0x1u<<8)
#define DCMIPP_CMFCR_CPRERRF            (0x1u<<6)
#define DCMIPP_CMFCR_CATXERRF           (0x1u<<5)

// P0FSCR Configuration

#define DCMIPP_P0FSCR_PIPEN             (0x1u<<31)

#define DCMIPP_P0FSCR_PIPEN_B_0X0       (0x0u<<31)
#define DCMIPP_P0FSCR_PIPEN_B_0X1       (0x1u<<31)

// P0FCTCR Configuration

#define DCMIPP_P0FCTCR_CPTREQ           (0x1u<<3)
#define DCMIPP_P0FCTCR_CPTMODE          (0x1u<<2)
#define DCMIPP_P0FCTCR_FRATE            (0x3u<<0)
#define DCMIPP_P0FCTCR_FRATE_0          (0x1u<<0)

#define DCMIPP_P0FCTCR_CPTREQ_B_0X0     (0x0u<<3)
#define DCMIPP_P0FCTCR_CPTREQ_B_0X1     (0x1u<<3)
#define DCMIPP_P0FCTCR_CPTMODE_B_0X0    (0x0u<<2)
#define DCMIPP_P0FCTCR_CPTMODE_B_0X1    (0x1u<<2)
#define DCMIPP_P0FCTCR_FRATE_B_0X0      (0x0u<<0)
#define DCMIPP_P0FCTCR_FRATE_B_0X1      (0x1u<<0)
#define DCMIPP_P0FCTCR_FRATE_B_0X2      (0x2u<<0)
#define DCMIPP_P0FCTCR_FRATE_B_0X3      (0x3u<<0)

// P0SCSTR Configuration

#define DCMIPP_P0SCSTR_VSTART           (0xFFFu<<16)
#define DCMIPP_P0SCSTR_VSTART_0         (0x1u<<16)
#define DCMIPP_P0SCSTR_HSTART           (0xFFFu<<0)
#define DCMIPP_P0SCSTR_HSTART_0         (0x1u<<0)

// P0SCSZR Configuration

#define DCMIPP_P0SCSZR_ENABLE           (0x1u<<31)
#define DCMIPP_P0SCSZR_POSNEG           (0x1u<<30)
#define DCMIPP_P0SCSZR_VSIZE            (0xFFFu<<16)
#define DCMIPP_P0SCSZR_VSIZE_0          (0x1u<<16)
#define DCMIPP_P0SCSZR_HSIZE            (0xFFFu<<0)
#define DCMIPP_P0SCSZR_HSIZE_0          (0x1u<<0)

#define DCMIPP_P0SCSZR_ENABLE_B_0X0     (0x0u<<31)
#define DCMIPP_P0SCSZR_ENABLE_B_0X1     (0x1u<<31)
#define DCMIPP_P0SCSZR_POSNEG_B_0X0     (0x0u<<30)
#define DCMIPP_P0SCSZR_POSNEG_B_0X1     (0x1u<<30)

// P0DCCNTR Configuration

#define DCMIPP_P0DCCNTR_CNT             (0x3FFFFFFu<<0)
#define DCMIPP_P0DCCNTR_CNT_0           (0x1u<<0)

// P0DCLMTR Configuration

#define DCMIPP_P0DCLMTR_ENABLE          (0x1u<<31)
#define DCMIPP_P0DCLMTR_LIMIT           (0xFFFFFFu<<0)
#define DCMIPP_P0DCLMTR_LIMIT_0         (0x1u<<0)

#define DCMIPP_P0DCLMTR_ENABLE_B_0X0    (0x0u<<31)
#define DCMIPP_P0DCLMTR_ENABLE_B_0X1    (0x1u<<31)

// P0PPCR Configuration

#define DCMIPP_P0PPCR_DBM               (0x1u<<16)
#define DCMIPP_P0PPCR_LINEMULT          (0x7u<<13)
#define DCMIPP_P0PPCR_LINEMULT_0        (0x1u<<13)
#define DCMIPP_P0PPCR_OELS              (0x1u<<11)
#define DCMIPP_P0PPCR_LSM               (0x1u<<10)
#define DCMIPP_P0PPCR_OEBS              (0x1u<<9)
#define DCMIPP_P0PPCR_BSM               (0x3u<<7)
#define DCMIPP_P0PPCR_BSM_0             (0x1u<<7)
#define DCMIPP_P0PPCR_PAD               (0x1u<<5)
#define DCMIPP_P0PPCR_SWAPYUV           (0x1u<<0)

#define DCMIPP_P0PPCR_DBM_B_0X0         (0x0u<<16)
#define DCMIPP_P0PPCR_DBM_B_0X1         (0x1u<<16)
#define DCMIPP_P0PPCR_LINEMULT_B_0X0    (0x0u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X1    (0x1u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X2    (0x2u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X3    (0x3u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X4    (0x4u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X5    (0x5u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X6    (0x6u<<13)
#define DCMIPP_P0PPCR_LINEMULT_B_0X7    (0x7u<<13)
#define DCMIPP_P0PPCR_OELS_B_0X0        (0x0u<<11)
#define DCMIPP_P0PPCR_OELS_B_0X1        (0x1u<<11)
#define DCMIPP_P0PPCR_LSM_B_0X0         (0x0u<<10)
#define DCMIPP_P0PPCR_LSM_B_0X1         (0x1u<<10)
#define DCMIPP_P0PPCR_OEBS_B_0X0        (0x0u<<9)
#define DCMIPP_P0PPCR_OEBS_B_0X1        (0x1u<<9)
#define DCMIPP_P0PPCR_BSM_B_0X0         (0x0u<<7)
#define DCMIPP_P0PPCR_BSM_B_0X1         (0x1u<<7)
#define DCMIPP_P0PPCR_BSM_B_0X2         (0x2u<<7)
#define DCMIPP_P0PPCR_BSM_B_0X3         (0x3u<<7)
#define DCMIPP_P0PPCR_PAD_B_0X0         (0x0u<<5)
#define DCMIPP_P0PPCR_PAD_B_0X1         (0x1u<<5)
#define DCMIPP_P0PPCR_SWAPYUV_B_0X0     (0x0u<<0)
#define DCMIPP_P0PPCR_SWAPYUV_B_0X1     (0x1u<<0)

// P0PPM0AR1 Configuration

#define DCMIPP_P0PPM0AR1_M0A            (0xFFFFFFFFu<<0)
#define DCMIPP_P0PPM0AR1_M0A_0          (0x1u<<0)

// P0PPM0AR2 Configuration

#define DCMIPP_P0PPM0AR2_M0A            (0xFFFFFFFFu<<0)
#define DCMIPP_P0PPM0AR2_M0A_0          (0x1u<<0)

// P0STM0AR Configuration

#define DCMIPP_P0STM0AR_M0A             (0xFFFFFFFFu<<0)
#define DCMIPP_P0STM0AR_M0A_0           (0x1u<<0)

// P0IER Configuration

#define DCMIPP_P0IER_OVRIE              (0x1u<<7)
#define DCMIPP_P0IER_LIMITIE            (0x1u<<6)
#define DCMIPP_P0IER_VSYNCIE            (0x1u<<2)
#define DCMIPP_P0IER_FRAMEIE            (0x1u<<1)
#define DCMIPP_P0IER_LINEIE             (0x1u<<0)

#define DCMIPP_P0IER_OVRIE_B_0X0        (0x0u<<7)
#define DCMIPP_P0IER_OVRIE_B_0X1        (0x1u<<7)
#define DCMIPP_P0IER_LIMITIE_B_0X0      (0x0u<<6)
#define DCMIPP_P0IER_LIMITIE_B_0X1      (0x1u<<6)
#define DCMIPP_P0IER_VSYNCIE_B_0X0      (0x0u<<2)
#define DCMIPP_P0IER_VSYNCIE_B_0X1      (0x1u<<2)
#define DCMIPP_P0IER_FRAMEIE_B_0X0      (0x0u<<1)
#define DCMIPP_P0IER_FRAMEIE_B_0X1      (0x1u<<1)
#define DCMIPP_P0IER_LINEIE_B_0X0       (0x0u<<0)
#define DCMIPP_P0IER_LINEIE_B_0X1       (0x1u<<0)

// P0SR Configuration

#define DCMIPP_P0SR_CPTACT              (0x1u<<23)
#define DCMIPP_P0SR_OVRF                (0x1u<<7)
#define DCMIPP_P0SR_LIMITF              (0x1u<<6)
#define DCMIPP_P0SR_VSYNCF              (0x1u<<2)
#define DCMIPP_P0SR_FRAMEF              (0x1u<<1)
#define DCMIPP_P0SR_LINEF               (0x1u<<0)

#define DCMIPP_P0SR_CPTACT_B_0X0        (0x0u<<23)
#define DCMIPP_P0SR_CPTACT_B_0X1        (0x1u<<23)
#define DCMIPP_P0SR_OVRF_B_0X0          (0x0u<<7)
#define DCMIPP_P0SR_OVRF_B_0X1          (0x1u<<7)
#define DCMIPP_P0SR_FRAMEF_B_0X0        (0x0u<<1)
#define DCMIPP_P0SR_FRAMEF_B_0X1        (0x1u<<1)

// P0FCR Configuration

#define DCMIPP_P0FCR_COVRF              (0x1u<<7)
#define DCMIPP_P0FCR_CLIMITF            (0x1u<<6)
#define DCMIPP_P0FCR_CVSYNCF            (0x1u<<2)
#define DCMIPP_P0FCR_CFRAMEF            (0x1u<<1)
#define DCMIPP_P0FCR_CLINEF             (0x1u<<0)

// P0CFCTCR Configuration

#define DCMIPP_P0CFCTCR_CPTREQ          (0x1u<<3)
#define DCMIPP_P0CFCTCR_CPTMODE         (0x1u<<2)
#define DCMIPP_P0CFCTCR_FRATE           (0x3u<<0)
#define DCMIPP_P0CFCTCR_FRATE_0         (0x1u<<0)

#define DCMIPP_P0CFCTCR_CPTREQ_B_0X0    (0x0u<<3)
#define DCMIPP_P0CFCTCR_CPTREQ_B_0X1    (0x1u<<3)
#define DCMIPP_P0CFCTCR_CPTMODE_B_0X0   (0x0u<<2)
#define DCMIPP_P0CFCTCR_CPTMODE_B_0X1   (0x1u<<2)
#define DCMIPP_P0CFCTCR_FRATE_B_0X0     (0x0u<<0)
#define DCMIPP_P0CFCTCR_FRATE_B_0X1     (0x1u<<0)
#define DCMIPP_P0CFCTCR_FRATE_B_0X2     (0x2u<<0)
#define DCMIPP_P0CFCTCR_FRATE_B_0X3     (0x3u<<0)

// P0CSCSTR Configuration

#define DCMIPP_P0CSCSTR_VSTART          (0xFFFu<<16)
#define DCMIPP_P0CSCSTR_VSTART_0        (0x1u<<16)
#define DCMIPP_P0CSCSTR_HSTART          (0xFFFu<<0)
#define DCMIPP_P0CSCSTR_HSTART_0        (0x1u<<0)

// P0CSCSZR Configuration

#define DCMIPP_P0CSCSZR_ENABLE          (0x1u<<31)
#define DCMIPP_P0CSCSZR_POSNEG          (0x1u<<30)
#define DCMIPP_P0CSCSZR_VSIZE           (0xFFFu<<16)
#define DCMIPP_P0CSCSZR_VSIZE_0         (0x1u<<16)
#define DCMIPP_P0CSCSZR_HSIZE           (0xFFFu<<0)
#define DCMIPP_P0CSCSZR_HSIZE_0         (0x1u<<0)

#define DCMIPP_P0CSCSZR_ENABLE_B_0X0    (0x0u<<31)
#define DCMIPP_P0CSCSZR_ENABLE_B_0X1    (0x1u<<31)
#define DCMIPP_P0CSCSZR_POSNEG_B_0X0    (0x0u<<30)
#define DCMIPP_P0CSCSZR_POSNEG_B_0X1    (0x1u<<30)

// P0CPPCR Configuration

#define DCMIPP_P0CPPCR_DBM              (0x1u<<16)
#define DCMIPP_P0CPPCR_LINEMULT         (0x7u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_0       (0x1u<<13)
#define DCMIPP_P0CPPCR_OELS             (0x1u<<11)
#define DCMIPP_P0CPPCR_LSM              (0x1u<<10)
#define DCMIPP_P0CPPCR_OEBS             (0x1u<<9)
#define DCMIPP_P0CPPCR_BSM              (0x3u<<7)
#define DCMIPP_P0CPPCR_BSM_0            (0x1u<<7)
#define DCMIPP_P0CPPCR_PAD              (0x1u<<5)
#define DCMIPP_P0CPPCR_SWAPYUV          (0x1u<<0)

#define DCMIPP_P0CPPCR_DBM_B_0X0        (0x0u<<16)
#define DCMIPP_P0CPPCR_DBM_B_0X1        (0x1u<<16)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X0   (0x0u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X1   (0x1u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X2   (0x2u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X3   (0x3u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X4   (0x4u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X5   (0x5u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X6   (0x6u<<13)
#define DCMIPP_P0CPPCR_LINEMULT_B_0X7   (0x7u<<13)
#define DCMIPP_P0CPPCR_OELS_B_0X0       (0x0u<<11)
#define DCMIPP_P0CPPCR_OELS_B_0X1       (0x1u<<11)
#define DCMIPP_P0CPPCR_LSM_B_0X0        (0x0u<<10)
#define DCMIPP_P0CPPCR_LSM_B_0X1        (0x1u<<10)
#define DCMIPP_P0CPPCR_OEBS_B_0X0       (0x0u<<9)
#define DCMIPP_P0CPPCR_OEBS_B_0X1       (0x1u<<9)
#define DCMIPP_P0CPPCR_BSM_B_0X0        (0x0u<<7)
#define DCMIPP_P0CPPCR_BSM_B_0X1        (0x1u<<7)
#define DCMIPP_P0CPPCR_BSM_B_0X2        (0x2u<<7)
#define DCMIPP_P0CPPCR_BSM_B_0X3        (0x3u<<7)
#define DCMIPP_P0CPPCR_PAD_B_0X0        (0x0u<<5)
#define DCMIPP_P0CPPCR_PAD_B_0X1        (0x1u<<5)
#define DCMIPP_P0CPPCR_SWAPYUV_B_0X0    (0x0u<<0)
#define DCMIPP_P0CPPCR_SWAPYUV_B_0X1    (0x1u<<0)

// P0CPPM0AR1 Configuration

#define DCMIPP_P0CPPM0AR1_M0A           (0xFFFFFFFFu<<0)
#define DCMIPP_P0CPPM0AR1_M0A_0         (0x1u<<0)

// P0CPPM0AR2 Configuration

#define DCMIPP_P0CPPM0AR2_M0A           (0xFFFFFFFFu<<0)
#define DCMIPP_P0CPPM0AR2_M0A_0         (0x1u<<0)
