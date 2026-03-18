/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     ICB equates.
 */

#pragma once

// ICB address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    ICTR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    ACTLR;
    volatile    uint32_t    CPPWR;
} ICB_TypeDef;

#if (defined(__cplusplus))
#define ICB_S   reinterpret_cast<ICB_TypeDef *>(0xE000E004U)
#define ICB_NS  reinterpret_cast<ICB_TypeDef *>(0xE000E004U)

#else
#define ICB_S   ((ICB_TypeDef *)0xE000E004U)
#define ICB_NS  ((ICB_TypeDef *)0xE000E004U)
#endif

// ICTR Configuration

#define ICB_ICTR_INTLINESNUM        (0xFU<<0)
#define ICB_ICTR_INTLINESNUM_0      (0x1U<<0)

// ACTLR Configuration

#define ICB_ACTLR_DISCRITAXIRUW     (0x1U<<27)
#define ICB_ACTLR_DISDI             (0x3U<<16)
#define ICB_ACTLR_DISDI_0           (0x1U<<16)
#define ICB_ACTLR_DISCRITAXIRUR     (0x1U<<15)
#define ICB_ACTLR_EVENTBUSEN        (0x1U<<14)
#define ICB_ACTLR_EVENTBUSEN_S      (0x1U<<13)
#define ICB_ACTLR_DISITMATBFLUSH    (0x1U<<12)
#define ICB_ACTLR_DISNWAMODE        (0x1U<<11)
#define ICB_ACTLR_FPEXCODIS         (0x1U<<10)
#define ICB_ACTLR_DISOLAP           (0x1U<<7)
#define ICB_ACTLR_DISOLAPS          (0x1U<<6)
#define ICB_ACTLR_DISLOBR           (0x1U<<5)
#define ICB_ACTLR_DISLO             (0x1U<<4)
#define ICB_ACTLR_DISLOLEP          (0x1U<<3)
#define ICB_ACTLR_DISFOLD           (0x1U<<2)

// CPPWR Configuration

#define ICB_CPPWR_SUS11             (0x1U<<23)
#define ICB_CPPWR_SU11              (0x1U<<22)
#define ICB_CPPWR_SUS10             (0x1U<<21)
#define ICB_CPPWR_SU10              (0x1U<<20)
#define ICB_CPPWR_SUS7              (0x1U<<15)
#define ICB_CPPWR_SU7               (0x1U<<14)
#define ICB_CPPWR_SUS6              (0x1U<<13)
#define ICB_CPPWR_SU6               (0x1U<<12)
#define ICB_CPPWR_SUS5              (0x1U<<11)
#define ICB_CPPWR_SU5               (0x1U<<10)
#define ICB_CPPWR_SUS4              (0x1U<<9)
#define ICB_CPPWR_SU4               (0x1U<<8)
#define ICB_CPPWR_SUS3              (0x1U<<7)
#define ICB_CPPWR_SU3               (0x1U<<6)
#define ICB_CPPWR_SUS2              (0x1U<<5)
#define ICB_CPPWR_SU2               (0x1U<<4)
#define ICB_CPPWR_SUS1              (0x1U<<3)
#define ICB_CPPWR_SU1               (0x1U<<2)
#define ICB_CPPWR_SUS0              (0x1U<<1)
#define ICB_CPPWR_SU0               (0x1U<<0)

