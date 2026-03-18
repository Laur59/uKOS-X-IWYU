/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_hrtim_master equates.
 */

#pragma once

#include    <stdint.h>

// HRTIM_MASTER address definitions
// --------------------------------

typedef struct {
    volatile    uint32_t    MCR;
    volatile    uint32_t    MISR;
    volatile    uint32_t    MICR;
    volatile    uint32_t    MDIER4;
    volatile    uint32_t    MCNTR;
    volatile    uint32_t    MPER;
    volatile    uint32_t    MREP;
    volatile    uint32_t    MCMP1R;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    MCMP2R;
    volatile    uint32_t    MCMP3R;
    volatile    uint32_t    MCMP4R;
} HRTIM_MASTER_TypeDef;

#ifdef __cplusplus
#define HRTIM_MASTER    reinterpret_cast<HRTIM_MASTER_TypeDef *>(0x40017400U)

#else
#define HRTIM_MASTER    ((HRTIM_MASTER_TypeDef *)0x40017400U)
#endif

// MCR Configuration

#define HRTIM_MASTER_MCR_CK_PSC     (0x7U<<0)
#define HRTIM_MASTER_MCR_CK_PSC_0   (0x1U<<0)
#define HRTIM_MASTER_MCR_CONT       (0x1U<<3)
#define HRTIM_MASTER_MCR_RETRIG     (0x1U<<4)
#define HRTIM_MASTER_MCR_HALF       (0x1U<<5)
#define HRTIM_MASTER_MCR_SYNC_IN    (0x3U<<8)
#define HRTIM_MASTER_MCR_SYNC_IN_0  (0x1U<<8)
#define HRTIM_MASTER_MCR_SYNCRSTM   (0x1U<<10)
#define HRTIM_MASTER_MCR_SYNCSTRTM  (0x1U<<11)
#define HRTIM_MASTER_MCR_SYNC_OUT   (0x3U<<12)
#define HRTIM_MASTER_MCR_SYNC_OUT_0 (0x1U<<12)
#define HRTIM_MASTER_MCR_SYNC_SRC   (0x3U<<14)
#define HRTIM_MASTER_MCR_SYNC_SRC_0 (0x1U<<14)
#define HRTIM_MASTER_MCR_MCEN       (0x1U<<16)
#define HRTIM_MASTER_MCR_TACEN      (0x1U<<17)
#define HRTIM_MASTER_MCR_TBCEN      (0x1U<<18)
#define HRTIM_MASTER_MCR_TCCEN      (0x1U<<19)
#define HRTIM_MASTER_MCR_TDCEN      (0x1U<<20)
#define HRTIM_MASTER_MCR_TECEN      (0x1U<<21)
#define HRTIM_MASTER_MCR_DACSYNC    (0x3U<<25)
#define HRTIM_MASTER_MCR_DACSYNC_0  (0x1U<<25)
#define HRTIM_MASTER_MCR_PREEN      (0x1U<<27)
#define HRTIM_MASTER_MCR_MREPU      (0x1U<<29)
#define HRTIM_MASTER_MCR_BRSTDMA    (0x3U<<30)
#define HRTIM_MASTER_MCR_BRSTDMA_0  (0x1U<<30)

// MISR Configuration

#define HRTIM_MASTER_MISR_MCMP1     (0x1U<<0)
#define HRTIM_MASTER_MISR_MCMP2     (0x1U<<1)
#define HRTIM_MASTER_MISR_MCMP3     (0x1U<<2)
#define HRTIM_MASTER_MISR_MCMP4     (0x1U<<3)
#define HRTIM_MASTER_MISR_MREP      (0x1U<<4)
#define HRTIM_MASTER_MISR_SYNC      (0x1U<<5)
#define HRTIM_MASTER_MISR_MUPD      (0x1U<<6)

// MICR Configuration

#define HRTIM_MASTER_MICR_MCMP1C    (0x1U<<0)
#define HRTIM_MASTER_MICR_MCMP2C    (0x1U<<1)
#define HRTIM_MASTER_MICR_MCMP3C    (0x1U<<2)
#define HRTIM_MASTER_MICR_MCMP4C    (0x1U<<3)
#define HRTIM_MASTER_MICR_MREPC     (0x1U<<4)
#define HRTIM_MASTER_MICR_SYNCC     (0x1U<<5)
#define HRTIM_MASTER_MICR_MUPDC     (0x1U<<6)

// MDIER4 Configuration

#define HRTIM_MASTER_MDIER4_MCMP1IE (0x1U<<0)
#define HRTIM_MASTER_MDIER4_MCMP2IE (0x1U<<1)
#define HRTIM_MASTER_MDIER4_MCMP3IE (0x1U<<2)
#define HRTIM_MASTER_MDIER4_MCMP4IE (0x1U<<3)
#define HRTIM_MASTER_MDIER4_MREPIE  (0x1U<<4)
#define HRTIM_MASTER_MDIER4_SYNCIE  (0x1U<<5)
#define HRTIM_MASTER_MDIER4_MUPDIE  (0x1U<<6)
#define HRTIM_MASTER_MDIER4_MCMP1DE (0x1U<<16)
#define HRTIM_MASTER_MDIER4_MCMP2DE (0x1U<<17)
#define HRTIM_MASTER_MDIER4_MCMP3DE (0x1U<<18)
#define HRTIM_MASTER_MDIER4_MCMP4DE (0x1U<<19)
#define HRTIM_MASTER_MDIER4_MREPDE  (0x1U<<20)
#define HRTIM_MASTER_MDIER4_SYNCDE  (0x1U<<21)
#define HRTIM_MASTER_MDIER4_MUPDDE  (0x1U<<22)

// MCNTR Configuration

#define HRTIM_MASTER_MCNTR_MCNT     (0xFFFFU<<0)
#define HRTIM_MASTER_MCNTR_MCNT_0   (0x1U<<0)

// MPER Configuration

#define HRTIM_MASTER_MPER_MPER      (0xFFFFU<<0)
#define HRTIM_MASTER_MPER_MPER_0    (0x1U<<0)

// MREP Configuration

#define HRTIM_MASTER_MREP_MREP      (0xFFU<<0)
#define HRTIM_MASTER_MREP_MREP_0    (0x1U<<0)

// MCMP1R Configuration

#define HRTIM_MASTER_MCMP1R_MCMP1   (0xFFFFU<<0)
#define HRTIM_MASTER_MCMP1R_MCMP1_0 (0x1U<<0)

// MCMP2R Configuration

#define HRTIM_MASTER_MCMP2R_MCMP2   (0xFFFFU<<0)
#define HRTIM_MASTER_MCMP2R_MCMP2_0 (0x1U<<0)

// MCMP3R Configuration

#define HRTIM_MASTER_MCMP3R_MCMP3   (0xFFFFU<<0)
#define HRTIM_MASTER_MCMP3R_MCMP3_0 (0x1U<<0)

// MCMP4R Configuration

#define HRTIM_MASTER_MCMP4R_MCMP4   (0xFFFFU<<0)
#define HRTIM_MASTER_MCMP4R_MCMP4_0 (0x1U<<0)
