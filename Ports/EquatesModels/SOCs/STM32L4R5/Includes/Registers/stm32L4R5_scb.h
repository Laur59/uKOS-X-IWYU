/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_scb equates.
 */

#pragma once

#include    <stdint.h>

// SCB address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CPUID;
    volatile    uint32_t    ICSR;
    volatile    uint32_t    VTOR;
    volatile    uint32_t    AIRCR;
    volatile    uint32_t    SCR;
    volatile    uint32_t    CCR;
    volatile    uint32_t    SHPR1;
    volatile    uint32_t    SHPR2;
    volatile    uint32_t    SHPR3;
    volatile    uint32_t    SHCSR;
    volatile    uint32_t    CFSR_UFSR_BFSR_MMFSR;
    volatile    uint32_t    HFSR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    MMFAR;
    volatile    uint32_t    BFAR;
    volatile    uint32_t    AFSR;
} SCB_TypeDef;

#ifdef __cplusplus
#define SCB reinterpret_cast<SCB_TypeDef *>(0xE000ED00U)

#else
#define SCB ((SCB_TypeDef *)0xE000ED00U)
#endif

// CPUID Configuration

#define SCB_CPUID_IMPLEMENTER                   (0xFFU<<24U)
#define SCB_CPUID_IMPLEMENTER_0                 (0x1U<<24U)
#define SCB_CPUID_VARIANT                       (0xFU<<20U)
#define SCB_CPUID_VARIANT_0                     (0x1U<<20U)
#define SCB_CPUID_CONSTANT                      (0xFU<<16U)
#define SCB_CPUID_CONSTANT_0                    (0x1U<<16U)
#define SCB_CPUID_PARTNO                        (0xFFFU<<4U)
#define SCB_CPUID_PARTNO_0                      (0x1U<<4U)
#define SCB_CPUID_REVISION                      (0xFU<<0U)
#define SCB_CPUID_REVISION_0                    (0x1U<<0U)

// ICSR Configuration

#define SCB_ICSR_NMIPENDSET                     (0x1U<<31U)
#define SCB_ICSR_PENDSVSET                      (0x1U<<28U)
#define SCB_ICSR_PENDSVCLR                      (0x1U<<27U)
#define SCB_ICSR_PENDSTSET                      (0x1U<<26U)
#define SCB_ICSR_PENDSTCLR                      (0x1U<<25U)
#define SCB_ICSR_ISRPENDING                     (0x1U<<22U)
#define SCB_ICSR_VECTPENDING                    (0x7FU<<12U)
#define SCB_ICSR_VECTPENDING_0                  (0x1U<<12U)
#define SCB_ICSR_RETTOBASE                      (0x1U<<11U)
#define SCB_ICSR_VECTACTIVE                     (0x1FFU<<0U)
#define SCB_ICSR_VECTACTIVE_0                   (0x1U<<0U)

// VTOR Configuration

#define SCB_VTOR_TBLOFF                         (0x1FFFFFU<<9U)
#define SCB_VTOR_TBLOFF_0                       (0x1U<<9U)

// AIRCR Configuration

#define SCB_AIRCR_VECTKEYSTAT                   (0xFFFFU<<16U)
#define SCB_AIRCR_VECTKEYSTAT_0                 (0x1U<<16U)
#define SCB_AIRCR_ENDIANESS                     (0x1U<<15U)
#define SCB_AIRCR_PRIGROUP                      (0x7U<<8U)
#define SCB_AIRCR_PRIGROUP_0                    (0x1U<<8U)
#define SCB_AIRCR_SYSRESETREQ                   (0x1U<<2U)
#define SCB_AIRCR_VECTCLRACTIVE                 (0x1U<<1U)
#define SCB_AIRCR_VECTRESET                     (0x1U<<0U)

// SCR Configuration

#define SCB_SCR_SEVEONPEND                      (0x1U<<4U)
#define SCB_SCR_SLEEPDEEP                       (0x1U<<2U)
#define SCB_SCR_SLEEPONEXIT                     (0x1U<<1U)

// CCR Configuration

#define SCB_CCR_STKALIGN                        (0x1U<<9U)
#define SCB_CCR_BFHFNMIGN                       (0x1U<<8U)
#define SCB_CCR_DIV_0_TRP                       (0x1U<<4U)
#define SCB_CCR_UNALIGN__TRP                    (0x1U<<3U)
#define SCB_CCR_USERSETMPEND                    (0x1U<<1U)
#define SCB_CCR_NONBASETHRDENA                  (0x1U<<0U)

// SHPR1 Configuration

#define SCB_SHPR1_PRI_6                         (0xFFU<<16U)
#define SCB_SHPR1_PRI_6_0                       (0x1U<<16U)
#define SCB_SHPR1_PRI_5                         (0xFFU<<8U)
#define SCB_SHPR1_PRI_5_0                       (0x1U<<8U)
#define SCB_SHPR1_PRI_4                         (0xFFU<<0U)
#define SCB_SHPR1_PRI_4_0                       (0x1U<<0U)

// SHPR2 Configuration

#define SCB_SHPR2_PRI_11                        (0xFFU<<24U)
#define SCB_SHPR2_PRI_11_0                      (0x1U<<24U)

// SHPR3 Configuration

#define SCB_SHPR3_PRI_15                        (0xFFU<<24U)
#define SCB_SHPR3_PRI_15_0                      (0x1U<<24U)
#define SCB_SHPR3_PRI_14                        (0xFFU<<16U)
#define SCB_SHPR3_PRI_14_0                      (0x1U<<16U)

// SHCSR Configuration

#define SCB_SHCSR_USGFAULTENA                   (0x1U<<18U)
#define SCB_SHCSR_BUSFAULTENA                   (0x1U<<17U)
#define SCB_SHCSR_MEMFAULTENA                   (0x1U<<16U)
#define SCB_SHCSR_SVCALLPENDED                  (0x1U<<15U)
#define SCB_SHCSR_BUSFAULTPENDED                (0x1U<<14U)
#define SCB_SHCSR_MEMFAULTPENDED                (0x1U<<13U)
#define SCB_SHCSR_USGFAULTPENDED                (0x1U<<12U)
#define SCB_SHCSR_SYSTICKACT                    (0x1U<<11U)
#define SCB_SHCSR_PENDSVACT                     (0x1U<<10U)
#define SCB_SHCSR_MONITORACT                    (0x1U<<8U)
#define SCB_SHCSR_SVCALLACT                     (0x1U<<7U)
#define SCB_SHCSR_USGFAULTACT                   (0x1U<<3U)
#define SCB_SHCSR_BUSFAULTACT                   (0x1U<<1U)
#define SCB_SHCSR_MEMFAULTACT                   (0x1U<<0U)

// CFSR_UFSR_BFSR_MMFSR Configuration

#define SCB_CFSR_UFSR_BFSR_MMFSR_DIVBYZERO      (0x1U<<25U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_UNALIGNED      (0x1U<<24U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_NOCP           (0x1U<<19U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_INVPC          (0x1U<<18U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_INVSTATE       (0x1U<<17U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_UNDEFINSTR     (0x1U<<16U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_BFARVALID      (0x1U<<15U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_LSPERR         (0x1U<<13U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_STKERR         (0x1U<<12U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_UNSTKERR       (0x1U<<11U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_IMPRECISERR    (0x1U<<10U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_PRECISERR      (0x1U<<9U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_IBUSERR        (0x1U<<8U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_MMARVALID      (0x1U<<7U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_MLSPERR        (0x1U<<5U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_MSTKERR        (0x1U<<4U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_MUNSTKERR      (0x1U<<3U)
#define SCB_CFSR_UFSR_BFSR_MMFSR_IACCVIOL       (0x1U<<1U)

// HFSR Configuration

#define SCB_HFSR_DEBUG_VT                       (0x1U<<31U)
#define SCB_HFSR_FORCED                         (0x1U<<30U)
#define SCB_HFSR_VECTTBL                        (0x1U<<1U)

// MMFAR Configuration

#define SCB_MMFAR_MMFAR                         (0xFFFFFFFFU<<0U)
#define SCB_MMFAR_MMFAR_0                       (0x1U<<0U)

// BFAR Configuration

#define SCB_BFAR_BFAR                           (0xFFFFFFFFU<<0U)
#define SCB_BFAR_BFAR_0                         (0x1U<<0U)

// AFSR Configuration

#define SCB_AFSR_IMPDEF                         (0xFFFFFFFFU<<0U)
#define SCB_AFSR_IMPDEF_0                       (0x1U<<0U)
