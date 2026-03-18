/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32F217_rtc equates.
 */

#pragma once

#include    <stdint.h>

// RTC address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    TR;
    volatile    uint32_t    DR;
    volatile    uint32_t    CR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    PRER;
    volatile    uint32_t    WUTR;
    volatile    uint32_t    CALIBR;
    volatile    uint32_t    ALRMAR;
    volatile    uint32_t    ALRMBR;
    volatile    uint32_t    WPR;
    volatile    uint32_t    RESERVED0[2];
    volatile    uint32_t    TSTR;
    volatile    uint32_t    TSDR;
    volatile    uint32_t    RESERVED1[2];
    volatile    uint32_t    TAFCR;
    volatile    uint32_t    RESERVED2[3];
    volatile    uint32_t    BKP0R;
    volatile    uint32_t    BKP1R;
    volatile    uint32_t    BKP2R;
    volatile    uint32_t    BKP3R;
    volatile    uint32_t    BKP4R;
    volatile    uint32_t    BKP5R;
    volatile    uint32_t    BKP6R;
    volatile    uint32_t    BKP7R;
    volatile    uint32_t    BKP8R;
    volatile    uint32_t    BKP9R;
    volatile    uint32_t    BKP10R;
    volatile    uint32_t    BKP11R;
    volatile    uint32_t    BKP12R;
    volatile    uint32_t    BKP13R;
    volatile    uint32_t    BKP14R;
    volatile    uint32_t    BKP15R;
    volatile    uint32_t    BKP16R;
    volatile    uint32_t    BKP17R;
    volatile    uint32_t    BKP18R;
    volatile    uint32_t    BKP19R;
} RTC_TypeDef;

#ifdef __cplusplus
#define RTC reinterpret_cast<RTC_TypeDef *>(0x40002800U)

#else
#define RTC ((RTC_TypeDef *)0x40002800U)
#endif

// TR Configuration

#define RTC_TR_SU               (0xFU<<0)
#define RTC_TR_SU_0             (0x1U<<0)
#define RTC_TR_ST               (0x7U<<4)
#define RTC_TR_ST_0             (0x1U<<4)
#define RTC_TR_MNU              (0xFU<<8)
#define RTC_TR_MNU_0            (0x1U<<8)
#define RTC_TR_MNT              (0x7U<<12)
#define RTC_TR_MNT_0            (0x1U<<12)
#define RTC_TR_HU               (0xFU<<16)
#define RTC_TR_HU_0             (0x1U<<16)
#define RTC_TR_HT               (0x3U<<20)
#define RTC_TR_HT_0             (0x1U<<20)
#define RTC_TR_PM               (0x1U<<22)

// DR Configuration

#define RTC_DR_DU               (0xFU<<0)
#define RTC_DR_DU_0             (0x1U<<0)
#define RTC_DR_DT               (0x3U<<4)
#define RTC_DR_DT_0             (0x1U<<4)
#define RTC_DR_MU               (0xFU<<8)
#define RTC_DR_MU_0             (0x1U<<8)
#define RTC_DR_MT               (0x1U<<12)
#define RTC_DR_WDU              (0x7U<<13)
#define RTC_DR_WDU_0            (0x1U<<13)
#define RTC_DR_YU               (0xFU<<16)
#define RTC_DR_YU_0             (0x1U<<16)
#define RTC_DR_YT               (0xFU<<20)
#define RTC_DR_YT_0             (0x1U<<20)

// CR Configuration

#define RTC_CR_WCKSEL           (0x7U<<0)
#define RTC_CR_WCKSEL_0         (0x1U<<0)
#define RTC_CR_TSEDGE           (0x1U<<3)
#define RTC_CR_REFCKON          (0x1U<<4)
#define RTC_CR_FMT              (0x1U<<6)
#define RTC_CR_DCE              (0x1U<<7)
#define RTC_CR_ALRAE            (0x1U<<8)
#define RTC_CR_ALRBE            (0x1U<<9)
#define RTC_CR_WUTE             (0x1U<<10)
#define RTC_CR_TSE              (0x1U<<11)
#define RTC_CR_ALRAIE           (0x1U<<12)
#define RTC_CR_ALRBIE           (0x1U<<13)
#define RTC_CR_WUTIE            (0x1U<<14)
#define RTC_CR_TSIE             (0x1U<<15)
#define RTC_CR_ADD1H            (0x1U<<16)
#define RTC_CR_SUB1H            (0x1U<<17)
#define RTC_CR_BKP              (0x1U<<18)
#define RTC_CR_POL              (0x1U<<20)
#define RTC_CR_OSEL             (0x3U<<21)
#define RTC_CR_OSEL_0           (0x1U<<21)
#define RTC_CR_COE              (0x1U<<23)

// ISR Configuration

#define RTC_ISR_ALRAWF          (0x1U<<0)
#define RTC_ISR_ALRBWF          (0x1U<<1)
#define RTC_ISR_WUTWF           (0x1U<<2)
#define RTC_ISR_INITS           (0x1U<<4)
#define RTC_ISR_RSF             (0x1U<<5)
#define RTC_ISR_INITF           (0x1U<<6)
#define RTC_ISR_INIT            (0x1U<<7)
#define RTC_ISR_ALRAF           (0x1U<<8)
#define RTC_ISR_ALRBF           (0x1U<<9)
#define RTC_ISR_WUTF            (0x1U<<10)
#define RTC_ISR_TSF             (0x1U<<11)
#define RTC_ISR_TSOVF           (0x1U<<12)
#define RTC_ISR_TAMP1F          (0x1U<<13)

// PRER Configuration

#define RTC_PRER_PREDIV_S       (0x1FFFU<<0)
#define RTC_PRER_PREDIV_S_0     (0x1U<<0)
#define RTC_PRER_PREDIV_A       (0x7FU<<16)
#define RTC_PRER_PREDIV_A_0     (0x1U<<16)

// WUTR Configuration

#define RTC_WUTR_WUT            (0xFFFFU<<0)
#define RTC_WUTR_WUT_0          (0x1U<<0)

// CALIBR Configuration

#define RTC_CALIBR_DC           (0x1FU<<0)
#define RTC_CALIBR_DC_0         (0x1U<<0)
#define RTC_CALIBR_DCS          (0x1U<<7)

// ALRMAR Configuration

#define RTC_ALRMAR_SU           (0xFU<<0)
#define RTC_ALRMAR_SU_0         (0x1U<<0)
#define RTC_ALRMAR_ST           (0x7U<<4)
#define RTC_ALRMAR_ST_0         (0x1U<<4)
#define RTC_ALRMAR_MSK1         (0x1U<<7)
#define RTC_ALRMAR_MNU          (0xFU<<8)
#define RTC_ALRMAR_MNU_0        (0x1U<<8)
#define RTC_ALRMAR_MNT          (0x7U<<12)
#define RTC_ALRMAR_MNT_0        (0x1U<<12)
#define RTC_ALRMAR_MSK2         (0x1U<<15)
#define RTC_ALRMAR_HU           (0xFU<<16)
#define RTC_ALRMAR_HU_0         (0x1U<<16)
#define RTC_ALRMAR_HT           (0x3U<<20)
#define RTC_ALRMAR_HT_0         (0x1U<<20)
#define RTC_ALRMAR_PM           (0x1U<<22)
#define RTC_ALRMAR_MSK3         (0x1U<<23)
#define RTC_ALRMAR_DU           (0xFU<<24)
#define RTC_ALRMAR_DU_0         (0x1U<<24)
#define RTC_ALRMAR_DT           (0x3U<<28)
#define RTC_ALRMAR_DT_0         (0x1U<<28)
#define RTC_ALRMAR_WDSEL        (0x1U<<30)
#define RTC_ALRMAR_MSK4         (0x1U<<31)

// ALRMBR Configuration

#define RTC_ALRMBR_SU           (0xFU<<0)
#define RTC_ALRMBR_SU_0         (0x1U<<0)
#define RTC_ALRMBR_ST           (0x7U<<4)
#define RTC_ALRMBR_ST_0         (0x1U<<4)
#define RTC_ALRMBR_MSK1         (0x1U<<7)
#define RTC_ALRMBR_MNU          (0xFU<<8)
#define RTC_ALRMBR_MNU_0        (0x1U<<8)
#define RTC_ALRMBR_MNT          (0x7U<<12)
#define RTC_ALRMBR_MNT_0        (0x1U<<12)
#define RTC_ALRMBR_MSK2         (0x1U<<15)
#define RTC_ALRMBR_HU           (0xFU<<16)
#define RTC_ALRMBR_HU_0         (0x1U<<16)
#define RTC_ALRMBR_HT           (0x3U<<20)
#define RTC_ALRMBR_HT_0         (0x1U<<20)
#define RTC_ALRMBR_PM           (0x1U<<22)
#define RTC_ALRMBR_MSK3         (0x1U<<23)
#define RTC_ALRMBR_DU           (0xFU<<24)
#define RTC_ALRMBR_DU_0         (0x1U<<24)
#define RTC_ALRMBR_DT           (0x3U<<28)
#define RTC_ALRMBR_DT_0         (0x1U<<28)
#define RTC_ALRMBR_WDSEL        (0x1U<<30)
#define RTC_ALRMBR_MSK4         (0x1U<<31)

// WPR Configuration

#define RTC_WPR_KEY             (0xFFU<<0)
#define RTC_WPR_KEY_0           (0x1U<<0)

// TSTR Configuration

#define RTC_TSTR_PM             (0x1U<<22)
#define RTC_TSTR_HT             (0x3U<<20)
#define RTC_TSTR_HT_0           (0x1U<<20)
#define RTC_TSTR_HU             (0xFU<<16)
#define RTC_TSTR_HU_0           (0x1U<<16)
#define RTC_TSTR_MNT            (0x7U<<12)
#define RTC_TSTR_MNT_0          (0x1U<<12)
#define RTC_TSTR_MNU            (0xFU<<8)
#define RTC_TSTR_MNU_0          (0x1U<<8)
#define RTC_TSTR_ST             (0x7U<<4)
#define RTC_TSTR_ST_0           (0x1U<<4)
#define RTC_TSTR_SU             (0xFU<<0)
#define RTC_TSTR_SU_0           (0x1U<<0)

// TSDR Configuration

#define RTC_TSDR_DU             (0xFU<<0)
#define RTC_TSDR_DU_0           (0x1U<<0)
#define RTC_TSDR_DT             (0x3U<<4)
#define RTC_TSDR_DT_0           (0x1U<<4)
#define RTC_TSDR_MU             (0xFU<<8)
#define RTC_TSDR_MU_0           (0x1U<<8)
#define RTC_TSDR_MT             (0x1U<<12)
#define RTC_TSDR_WDU            (0x7U<<13)
#define RTC_TSDR_WDU_0          (0x1U<<13)

// TAFCR Configuration

#define RTC_TAFCR_TAMP1E        (0x1U<<0)
#define RTC_TAFCR_TAMP1TRG      (0x1U<<1)
#define RTC_TAFCR_TAMPIE        (0x1U<<2)
#define RTC_TAFCR_TAMP1INSEL    (0x1U<<16)
#define RTC_TAFCR_TSINSEL       (0x1U<<17)
#define RTC_TAFCR_ALARMOUTTYPE  (0x1U<<18)

// BKP0R Configuration

#define RTC_BKP0R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP0R_BKP_0         (0x1U<<0)

// BKP1R Configuration

#define RTC_BKP1R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP1R_BKP_0         (0x1U<<0)

// BKP2R Configuration

#define RTC_BKP2R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP2R_BKP_0         (0x1U<<0)

// BKP3R Configuration

#define RTC_BKP3R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP3R_BKP_0         (0x1U<<0)

// BKP4R Configuration

#define RTC_BKP4R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP4R_BKP_0         (0x1U<<0)

// BKP5R Configuration

#define RTC_BKP5R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP5R_BKP_0         (0x1U<<0)

// BKP6R Configuration

#define RTC_BKP6R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP6R_BKP_0         (0x1U<<0)

// BKP7R Configuration

#define RTC_BKP7R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP7R_BKP_0         (0x1U<<0)

// BKP8R Configuration

#define RTC_BKP8R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP8R_BKP_0         (0x1U<<0)

// BKP9R Configuration

#define RTC_BKP9R_BKP           (0xFFFFFFFFU<<0)
#define RTC_BKP9R_BKP_0         (0x1U<<0)

// BKP10R Configuration

#define RTC_BKP10R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP10R_BKP_0        (0x1U<<0)

// BKP11R Configuration

#define RTC_BKP11R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP11R_BKP_0        (0x1U<<0)

// BKP12R Configuration

#define RTC_BKP12R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP12R_BKP_0        (0x1U<<0)

// BKP13R Configuration

#define RTC_BKP13R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP13R_BKP_0        (0x1U<<0)

// BKP14R Configuration

#define RTC_BKP14R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP14R_BKP_0        (0x1U<<0)

// BKP15R Configuration

#define RTC_BKP15R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP15R_BKP_0        (0x1U<<0)

// BKP16R Configuration

#define RTC_BKP16R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP16R_BKP_0        (0x1U<<0)

// BKP17R Configuration

#define RTC_BKP17R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP17R_BKP_0        (0x1U<<0)

// BKP18R Configuration

#define RTC_BKP18R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP18R_BKP_0        (0x1U<<0)

// BKP19R Configuration

#define RTC_BKP19R_BKP          (0xFFFFFFFFU<<0)
#define RTC_BKP19R_BKP_0        (0x1U<<0)
