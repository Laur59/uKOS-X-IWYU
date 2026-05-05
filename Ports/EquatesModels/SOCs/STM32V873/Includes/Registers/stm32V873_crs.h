/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_crs equates.
 */
#pragma once

#include    <stdint.h>

// CRS address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    CFGR;
    volatile    uint32_t    ISR;
    volatile    uint32_t    ICR;
} CRS_TypeDef;

#if (defined(__cplusplus))
#define CRS_NS  reinterpret_cast<CRS_TypeDef *>(0x40008400u)
#define CRS_S   reinterpret_cast<CRS_TypeDef *>(0x50008400u)

#else
#define CRS_NS  ((CRS_TypeDef *)0x40008400u)
#define CRS_S   ((CRS_TypeDef *)0x50008400u)
#endif

// CR Configuration

#define CRS_CR_TRIM                 (0x7Fu<<8)
#define CRS_CR_TRIM_0               (0x1u<<8)
#define CRS_CR_SWSYNC               (0x1u<<7)
#define CRS_CR_AUTOTRIMEN           (0x1u<<6)
#define CRS_CR_CEN                  (0x1u<<5)
#define CRS_CR_ESYNCIE              (0x1u<<3)
#define CRS_CR_ERRIE                (0x1u<<2)
#define CRS_CR_SYNCWARNIE           (0x1u<<1)
#define CRS_CR_SYNCOKIE             (0x1u<<0)

#define CRS_CR_SWSYNC_B_0X0         (0x0u<<7)
#define CRS_CR_SWSYNC_B_0X1         (0x1u<<7)
#define CRS_CR_AUTOTRIMEN_B_0X0     (0x0u<<6)
#define CRS_CR_AUTOTRIMEN_B_0X1     (0x1u<<6)
#define CRS_CR_CEN_B_0X0            (0x0u<<5)
#define CRS_CR_CEN_B_0X1            (0x1u<<5)
#define CRS_CR_ESYNCIE_B_0X0        (0x0u<<3)
#define CRS_CR_ESYNCIE_B_0X1        (0x1u<<3)
#define CRS_CR_ERRIE_B_0X0          (0x0u<<2)
#define CRS_CR_ERRIE_B_0X1          (0x1u<<2)
#define CRS_CR_SYNCWARNIE_B_0X0     (0x0u<<1)
#define CRS_CR_SYNCWARNIE_B_0X1     (0x1u<<1)
#define CRS_CR_SYNCOKIE_B_0X0       (0x0u<<0)
#define CRS_CR_SYNCOKIE_B_0X1       (0x1u<<0)

// CFGR Configuration

#define CRS_CFGR_SYNCPOL            (0x1u<<31)
#define CRS_CFGR_SYNCSRC            (0x3u<<28)
#define CRS_CFGR_SYNCSRC_0          (0x1u<<28)
#define CRS_CFGR_SYNCDIV            (0x7u<<24)
#define CRS_CFGR_SYNCDIV_0          (0x1u<<24)
#define CRS_CFGR_FELIM              (0xFFu<<16)
#define CRS_CFGR_FELIM_0            (0x1u<<16)
#define CRS_CFGR_RELOAD             (0xFFFFu<<0)
#define CRS_CFGR_RELOAD_0           (0x1u<<0)

#define CRS_CFGR_SYNCPOL_B_0X0      (0x0u<<31)
#define CRS_CFGR_SYNCPOL_B_0X1      (0x1u<<31)
#define CRS_CFGR_SYNCSRC_B_0X0      (0x0u<<28)
#define CRS_CFGR_SYNCSRC_B_0X1      (0x1u<<28)
#define CRS_CFGR_SYNCSRC_B_0X2      (0x2u<<28)
#define CRS_CFGR_SYNCSRC_B_0X3      (0x3u<<28)
#define CRS_CFGR_SYNCDIV_B_0X0      (0x0u<<24)
#define CRS_CFGR_SYNCDIV_B_0X1      (0x1u<<24)
#define CRS_CFGR_SYNCDIV_B_0X2      (0x2u<<24)
#define CRS_CFGR_SYNCDIV_B_0X3      (0x3u<<24)
#define CRS_CFGR_SYNCDIV_B_0X4      (0x4u<<24)
#define CRS_CFGR_SYNCDIV_B_0X5      (0x5u<<24)
#define CRS_CFGR_SYNCDIV_B_0X6      (0x6u<<24)
#define CRS_CFGR_SYNCDIV_B_0X7      (0x7u<<24)

// ISR Configuration

#define CRS_ISR_FECAP               (0xFFFFu<<16)
#define CRS_ISR_FECAP_0             (0x1u<<16)
#define CRS_ISR_FEDIR               (0x1u<<15)
#define CRS_ISR_TRIMOVF             (0x1u<<10)
#define CRS_ISR_SYNCMISS            (0x1u<<9)
#define CRS_ISR_SYNCERR             (0x1u<<8)
#define CRS_ISR_ESYNCF              (0x1u<<3)
#define CRS_ISR_ERRF                (0x1u<<2)
#define CRS_ISR_SYNCWARNF           (0x1u<<1)
#define CRS_ISR_SYNCOKF             (0x1u<<0)

#define CRS_ISR_FEDIR_B_0X0         (0x0u<<15)
#define CRS_ISR_FEDIR_B_0X1         (0x1u<<15)
#define CRS_ISR_TRIMOVF_B_0X0       (0x0u<<10)
#define CRS_ISR_TRIMOVF_B_0X1       (0x1u<<10)
#define CRS_ISR_SYNCMISS_B_0X0      (0x0u<<9)
#define CRS_ISR_SYNCMISS_B_0X1      (0x1u<<9)
#define CRS_ISR_SYNCERR_B_0X0       (0x0u<<8)
#define CRS_ISR_SYNCERR_B_0X1       (0x1u<<8)
#define CRS_ISR_ESYNCF_B_0X0        (0x0u<<3)
#define CRS_ISR_ESYNCF_B_0X1        (0x1u<<3)
#define CRS_ISR_ERRF_B_0X0          (0x0u<<2)
#define CRS_ISR_ERRF_B_0X1          (0x1u<<2)
#define CRS_ISR_SYNCWARNF_B_0X0     (0x0u<<1)
#define CRS_ISR_SYNCWARNF_B_0X1     (0x1u<<1)
#define CRS_ISR_SYNCOKF_B_0X0       (0x0u<<0)
#define CRS_ISR_SYNCOKF_B_0X1       (0x1u<<0)

// ICR Configuration

#define CRS_ICR_ESYNCC              (0x1u<<3)
#define CRS_ICR_ERRC                (0x1u<<2)
#define CRS_ICR_SYNCWARNC           (0x1u<<1)
#define CRS_ICR_SYNCOKC             (0x1u<<0)
