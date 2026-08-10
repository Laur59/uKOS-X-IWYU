/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32L4R5_pwr equates.
 */

#pragma once

#include    <stdint.h>

// PWR address definitions
// -----------------------

typedef struct {
    volatile    uint32_t    CR1;
    volatile    uint32_t    CR2;
    volatile    uint32_t    CR3;
    volatile    uint32_t    CR4;
    volatile    uint32_t    SR1;
    volatile    uint32_t    SR2;
    volatile    uint32_t    SCR;
    volatile    uint32_t    RESERVED0;
    volatile    uint32_t    PUCRA;
    volatile    uint32_t    PDCRA;
    volatile    uint32_t    PUCRB;
    volatile    uint32_t    PDCRB;
    volatile    uint32_t    PUCRC;
    volatile    uint32_t    PDCRC;
    volatile    uint32_t    PUCRD;
    volatile    uint32_t    PDCRD;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    PDCRE;
    volatile    uint32_t    PUCRF;
    volatile    uint32_t    PDCRF;
    volatile    uint32_t    PUCRG;
    volatile    uint32_t    PDCRG;
    volatile    uint32_t    PUCRH;
    volatile    uint32_t    PDCRH;
    volatile    uint32_t    PUCRI;
    volatile    uint32_t    PDCRI;
    volatile    uint32_t    RESERVED2[6];
    volatile    uint32_t    CR5;
} PWR_TypeDef;

#ifdef __cplusplus
#define PWR reinterpret_cast<PWR_TypeDef *>(0x40007000U)

#else
#define PWR ((PWR_TypeDef *)0x40007000U)
#endif

// CR1 Configuration

#define PWR_CR1_LPR                 (0x1U<<14U)
#define PWR_CR1_VOS                 (0x3U<<9U)
#define PWR_CR1_VOS_0               (0x1U<<9U)
#define PWR_CR1_DBP                 (0x1U<<8U)
#define PWR_CR1_RRSTP               (0x1U<<4U)
#define PWR_CR1_LPMS                (0x7U<<0U)
#define PWR_CR1_LPMS_0              (0x1U<<0U)
#define PWR_CR1_VOS_B_0X0           (0x0U<<9U)
#define PWR_CR1_VOS_B_0X1           (0x1U<<9U)
#define PWR_CR1_VOS_B_0X2           (0x2U<<9U)
#define PWR_CR1_VOS_B_0X3           (0x3U<<9U)
#define PWR_CR1_DBP_B_0X0           (0x0U<<8U)
#define PWR_CR1_DBP_B_0X1           (0x1U<<8U)
#define PWR_CR1_RRSTP_B_0X0         (0x0U<<4U)
#define PWR_CR1_RRSTP_B_0X1         (0x1U<<4U)
#define PWR_CR1_LPMS_B_0X0          (0x0U<<0U)
#define PWR_CR1_LPMS_B_0X1          (0x1U<<0U)
#define PWR_CR1_LPMS_B_0X2          (0x2U<<0U)
#define PWR_CR1_LPMS_B_0X3          (0x3U<<0U)

// CR2 Configuration

#define PWR_CR2_USV                 (0x1U<<10U)
#define PWR_CR2_IOSV                (0x1U<<9U)
#define PWR_CR2_PVME4               (0x1U<<7U)
#define PWR_CR2_PVME3               (0x1U<<6U)
#define PWR_CR2_PVME2               (0x1U<<5U)
#define PWR_CR2_PVME1               (0x1U<<4U)
#define PWR_CR2_PLS                 (0x7U<<1U)
#define PWR_CR2_PLS_0               (0x1U<<1U)
#define PWR_CR2_PVDE                (0x1U<<0U)
#define PWR_CR2_USV_B_0X0           (0x0U<<10U)
#define PWR_CR2_USV_B_0X1           (0x1U<<10U)
#define PWR_CR2_IOSV_B_0X0          (0x0U<<9U)
#define PWR_CR2_IOSV_B_0X1          (0x1U<<9U)
#define PWR_CR2_PVME4_B_0X0         (0x0U<<7U)
#define PWR_CR2_PVME4_B_0X1         (0x1U<<7U)
#define PWR_CR2_PVME3_B_0X0         (0x0U<<6U)
#define PWR_CR2_PVME3_B_0X1         (0x1U<<6U)
#define PWR_CR2_PVME2_B_0X0         (0x0U<<5U)
#define PWR_CR2_PVME2_B_0X1         (0x1U<<5U)
#define PWR_CR2_PVME1_B_0X0         (0x0U<<4U)
#define PWR_CR2_PVME1_B_0X1         (0x1U<<4U)
#define PWR_CR2_PLS_B_0X0           (0x0U<<1U)
#define PWR_CR2_PLS_B_0X1           (0x1U<<1U)
#define PWR_CR2_PLS_B_0X2           (0x2U<<1U)
#define PWR_CR2_PLS_B_0X3           (0x3U<<1U)
#define PWR_CR2_PLS_B_0X4           (0x4U<<1U)
#define PWR_CR2_PLS_B_0X5           (0x5U<<1U)
#define PWR_CR2_PLS_B_0X6           (0x6U<<1U)
#define PWR_CR2_PLS_B_0X7           (0x7U<<1U)
#define PWR_CR2_PVDE_B_0X0          (0x0U<<0U)
#define PWR_CR2_PVDE_B_0X1          (0x1U<<0U)

// CR3 Configuration

#define PWR_CR3_EIWUL               (0x1U<<15U)
#define PWR_CR3_DSIPDEN             (0x1U<<12U)
#define PWR_CR3_ENULP               (0x1U<<11U)
#define PWR_CR3_APC                 (0x1U<<10U)
#define PWR_CR3_RRS                 (0x3U<<8U)
#define PWR_CR3_RRS_0               (0x1U<<8U)
#define PWR_CR3_EWUP5               (0x1U<<4U)
#define PWR_CR3_EWUP4               (0x1U<<3U)
#define PWR_CR3_EWUP3               (0x1U<<2U)
#define PWR_CR3_EWUP2               (0x1U<<1U)
#define PWR_CR3_EWUP1               (0x1U<<0U)
#define PWR_CR3_EIWUL_B_0X0         (0x0U<<15U)
#define PWR_CR3_EIWUL_B_0X1         (0x1U<<15U)
#define PWR_CR3_DSIPDEN_B_0X1       (0x1U<<12U)
#define PWR_CR3_DSIPDEN_B_0X0       (0x0U<<12U)
#define PWR_CR3_RRS_B_0X0           (0x0U<<8U)
#define PWR_CR3_RRS_B_0X1           (0x1U<<8U)
#define PWR_CR3_RRS_B_0X2           (0x2U<<8U)

// CR4 Configuration

#define PWR_CR4_EXT_SMPS_ON         (0x1U<<13U)
#define PWR_CR4_VBRS                (0x1U<<9U)
#define PWR_CR4_VBE                 (0x1U<<8U)
#define PWR_CR4_WP5                 (0x1U<<4U)
#define PWR_CR4_WP4                 (0x1U<<3U)
#define PWR_CR4_WP3                 (0x1U<<2U)
#define PWR_CR4_WP2                 (0x1U<<1U)
#define PWR_CR4_WP1                 (0x1U<<0U)
#define PWR_CR4_EXT_SMPS_ON_B_0X0   (0x0U<<13U)
#define PWR_CR4_EXT_SMPS_ON_B_0X1   (0x1U<<13U)
#define PWR_CR4_VBRS_B_0X0          (0x0U<<9U)
#define PWR_CR4_VBRS_B_0X1          (0x1U<<9U)
#define PWR_CR4_VBE_B_0X0           (0x0U<<8U)
#define PWR_CR4_VBE_B_0X1           (0x1U<<8U)
#define PWR_CR4_WP5_B_0X0           (0x0U<<4U)
#define PWR_CR4_WP5_B_0X1           (0x1U<<4U)
#define PWR_CR4_WP4_B_0X0           (0x0U<<3U)
#define PWR_CR4_WP4_B_0X1           (0x1U<<3U)
#define PWR_CR4_WP3_B_0X0           (0x0U<<2U)
#define PWR_CR4_WP3_B_0X1           (0x1U<<2U)
#define PWR_CR4_WP2_B_0X0           (0x0U<<1U)
#define PWR_CR4_WP2_B_0X1           (0x1U<<1U)
#define PWR_CR4_WP1_B_0X0           (0x0U<<0U)
#define PWR_CR4_WP1_B_0X1           (0x1U<<0U)

// SR1 Configuration

#define PWR_SR1_WUFI                (0x1U<<15U)
#define PWR_SR1_EXT_SMPS_RDY        (0x1U<<13U)
#define PWR_SR1_SBF                 (0x1U<<8U)
#define PWR_SR1_WUF5                (0x1U<<4U)
#define PWR_SR1_WUF4                (0x1U<<3U)
#define PWR_SR1_WUF3                (0x1U<<2U)
#define PWR_SR1_WUF2                (0x1U<<1U)
#define PWR_SR1_WUF1                (0x1U<<0U)
#define PWR_SR1_EXT_SMPS_RDY_B_0X0  (0x0U<<13U)
#define PWR_SR1_EXT_SMPS_RDY_B_0X1  (0x1U<<13U)
#define PWR_SR1_SBF_B_0X0           (0x0U<<8U)
#define PWR_SR1_SBF_B_0X1           (0x1U<<8U)

// SR2 Configuration

#define PWR_SR2_PVMO4               (0x1U<<15U)
#define PWR_SR2_PVMO3               (0x1U<<14U)
#define PWR_SR2_PVMO2               (0x1U<<13U)
#define PWR_SR2_PVMO1               (0x1U<<12U)
#define PWR_SR2_PVDO                (0x1U<<11U)
#define PWR_SR2_VOSF                (0x1U<<10U)
#define PWR_SR2_REGLPF              (0x1U<<9U)
#define PWR_SR2_REGLPS              (0x1U<<8U)
#define PWR_SR2_PVMO4_B_0X0         (0x0U<<15U)
#define PWR_SR2_PVMO4_B_0X1         (0x1U<<15U)
#define PWR_SR2_PVMO3_B_0X0         (0x0U<<14U)
#define PWR_SR2_PVMO3_B_0X1         (0x1U<<14U)
#define PWR_SR2_PVMO2_B_0X0         (0x0U<<13U)
#define PWR_SR2_PVMO2_B_0X1         (0x1U<<13U)
#define PWR_SR2_PVMO1_B_0X0         (0x0U<<12U)
#define PWR_SR2_PVMO1_B_0X1         (0x1U<<12U)
#define PWR_SR2_PVDO_B_0X0          (0x0U<<11U)
#define PWR_SR2_PVDO_B_0X1          (0x1U<<11U)
#define PWR_SR2_VOSF_B_0X0          (0x0U<<10U)
#define PWR_SR2_VOSF_B_0X1          (0x1U<<10U)
#define PWR_SR2_REGLPF_B_0X0        (0x0U<<9U)
#define PWR_SR2_REGLPF_B_0X1        (0x1U<<9U)
#define PWR_SR2_REGLPS_B_0X0        (0x0U<<8U)
#define PWR_SR2_REGLPS_B_0X1        (0x1U<<8U)

// SCR Configuration

#define PWR_SCR_CSBF                (0x1U<<8U)
#define PWR_SCR_CWUF5               (0x1U<<4U)
#define PWR_SCR_CWUF4               (0x1U<<3U)
#define PWR_SCR_CWUF3               (0x1U<<2U)
#define PWR_SCR_CWUF2               (0x1U<<1U)
#define PWR_SCR_CWUF1               (0x1U<<0U)

// PUCRA Configuration

#define PWR_PUCRA_PU15              (0x1U<<15U)
#define PWR_PUCRA_PU13              (0x1U<<13U)
#define PWR_PUCRA_PU12              (0x1U<<12U)
#define PWR_PUCRA_PU11              (0x1U<<11U)
#define PWR_PUCRA_PU10              (0x1U<<10U)
#define PWR_PUCRA_PU9               (0x1U<<9U)
#define PWR_PUCRA_PU8               (0x1U<<8U)
#define PWR_PUCRA_PU7               (0x1U<<7U)
#define PWR_PUCRA_PU6               (0x1U<<6U)
#define PWR_PUCRA_PU5               (0x1U<<5U)
#define PWR_PUCRA_PU4               (0x1U<<4U)
#define PWR_PUCRA_PU3               (0x1U<<3U)
#define PWR_PUCRA_PU2               (0x1U<<2U)
#define PWR_PUCRA_PU1               (0x1U<<1U)
#define PWR_PUCRA_PU0               (0x1U<<0U)

// PDCRA Configuration

#define PWR_PDCRA_PD14              (0x1U<<14U)
#define PWR_PDCRA_PD12              (0x1U<<12U)
#define PWR_PDCRA_PD11              (0x1U<<11U)
#define PWR_PDCRA_PD10              (0x1U<<10U)
#define PWR_PDCRA_PD9               (0x1U<<9U)
#define PWR_PDCRA_PD8               (0x1U<<8U)
#define PWR_PDCRA_PD7               (0x1U<<7U)
#define PWR_PDCRA_PD6               (0x1U<<6U)
#define PWR_PDCRA_PD5               (0x1U<<5U)
#define PWR_PDCRA_PD4               (0x1U<<4U)
#define PWR_PDCRA_PD3               (0x1U<<3U)
#define PWR_PDCRA_PD2               (0x1U<<2U)
#define PWR_PDCRA_PD1               (0x1U<<1U)
#define PWR_PDCRA_PD0               (0x1U<<0U)

// PUCRB Configuration

#define PWR_PUCRB_PU15              (0x1U<<15U)
#define PWR_PUCRB_PU14              (0x1U<<14U)
#define PWR_PUCRB_PU13              (0x1U<<13U)
#define PWR_PUCRB_PU12              (0x1U<<12U)
#define PWR_PUCRB_PU11              (0x1U<<11U)
#define PWR_PUCRB_PU10              (0x1U<<10U)
#define PWR_PUCRB_PU9               (0x1U<<9U)
#define PWR_PUCRB_PU8               (0x1U<<8U)
#define PWR_PUCRB_PU7               (0x1U<<7U)
#define PWR_PUCRB_PU6               (0x1U<<6U)
#define PWR_PUCRB_PU5               (0x1U<<5U)
#define PWR_PUCRB_PU4               (0x1U<<4U)
#define PWR_PUCRB_PU3               (0x1U<<3U)
#define PWR_PUCRB_PU2               (0x1U<<2U)
#define PWR_PUCRB_PU1               (0x1U<<1U)
#define PWR_PUCRB_PU0               (0x1U<<0U)

// PDCRB Configuration

#define PWR_PDCRB_PD15              (0x1U<<15U)
#define PWR_PDCRB_PD14              (0x1U<<14U)
#define PWR_PDCRB_PD13              (0x1U<<13U)
#define PWR_PDCRB_PD12              (0x1U<<12U)
#define PWR_PDCRB_PD11              (0x1U<<11U)
#define PWR_PDCRB_PD10              (0x1U<<10U)
#define PWR_PDCRB_PD9               (0x1U<<9U)
#define PWR_PDCRB_PD8               (0x1U<<8U)
#define PWR_PDCRB_PD7               (0x1U<<7U)
#define PWR_PDCRB_PD6               (0x1U<<6U)
#define PWR_PDCRB_PD5               (0x1U<<5U)
#define PWR_PDCRB_PD3               (0x1U<<3U)
#define PWR_PDCRB_PD2               (0x1U<<2U)
#define PWR_PDCRB_PD1               (0x1U<<1U)
#define PWR_PDCRB_PD0               (0x1U<<0U)

// PUCRC Configuration

#define PWR_PUCRC_PU15              (0x1U<<15U)
#define PWR_PUCRC_PU14              (0x1U<<14U)
#define PWR_PUCRC_PU13              (0x1U<<13U)
#define PWR_PUCRC_PU12              (0x1U<<12U)
#define PWR_PUCRC_PU11              (0x1U<<11U)
#define PWR_PUCRC_PU10              (0x1U<<10U)
#define PWR_PUCRC_PU9               (0x1U<<9U)
#define PWR_PUCRC_PU8               (0x1U<<8U)
#define PWR_PUCRC_PU7               (0x1U<<7U)
#define PWR_PUCRC_PU6               (0x1U<<6U)
#define PWR_PUCRC_PU5               (0x1U<<5U)
#define PWR_PUCRC_PU4               (0x1U<<4U)
#define PWR_PUCRC_PU3               (0x1U<<3U)
#define PWR_PUCRC_PU2               (0x1U<<2U)
#define PWR_PUCRC_PU1               (0x1U<<1U)
#define PWR_PUCRC_PU0               (0x1U<<0U)

// PDCRC Configuration

#define PWR_PDCRC_PD15              (0x1U<<15U)
#define PWR_PDCRC_PD14              (0x1U<<14U)
#define PWR_PDCRC_PD13              (0x1U<<13U)
#define PWR_PDCRC_PD12              (0x1U<<12U)
#define PWR_PDCRC_PD11              (0x1U<<11U)
#define PWR_PDCRC_PD10              (0x1U<<10U)
#define PWR_PDCRC_PD9               (0x1U<<9U)
#define PWR_PDCRC_PD8               (0x1U<<8U)
#define PWR_PDCRC_PD7               (0x1U<<7U)
#define PWR_PDCRC_PD6               (0x1U<<6U)
#define PWR_PDCRC_PD5               (0x1U<<5U)
#define PWR_PDCRC_PD4               (0x1U<<4U)
#define PWR_PDCRC_PD3               (0x1U<<3U)
#define PWR_PDCRC_PD2               (0x1U<<2U)
#define PWR_PDCRC_PD1               (0x1U<<1U)
#define PWR_PDCRC_PD0               (0x1U<<0U)

// PUCRD Configuration

#define PWR_PUCRD_PU15              (0x1U<<15U)
#define PWR_PUCRD_PU14              (0x1U<<14U)
#define PWR_PUCRD_PU13              (0x1U<<13U)
#define PWR_PUCRD_PU12              (0x1U<<12U)
#define PWR_PUCRD_PU11              (0x1U<<11U)
#define PWR_PUCRD_PU10              (0x1U<<10U)
#define PWR_PUCRD_PU9               (0x1U<<9U)
#define PWR_PUCRD_PU8               (0x1U<<8U)
#define PWR_PUCRD_PU7               (0x1U<<7U)
#define PWR_PUCRD_PU6               (0x1U<<6U)
#define PWR_PUCRD_PU5               (0x1U<<5U)
#define PWR_PUCRD_PU4               (0x1U<<4U)
#define PWR_PUCRD_PU3               (0x1U<<3U)
#define PWR_PUCRD_PU2               (0x1U<<2U)
#define PWR_PUCRD_PU1               (0x1U<<1U)
#define PWR_PUCRD_PU0               (0x1U<<0U)

// PDCRD Configuration

#define PWR_PDCRD_PD15              (0x1U<<15U)
#define PWR_PDCRD_PD14              (0x1U<<14U)
#define PWR_PDCRD_PD13              (0x1U<<13U)
#define PWR_PDCRD_PD12              (0x1U<<12U)
#define PWR_PDCRD_PD11              (0x1U<<11U)
#define PWR_PDCRD_PD10              (0x1U<<10U)
#define PWR_PDCRD_PD9               (0x1U<<9U)
#define PWR_PDCRD_PD8               (0x1U<<8U)
#define PWR_PDCRD_PD7               (0x1U<<7U)
#define PWR_PDCRD_PD6               (0x1U<<6U)
#define PWR_PDCRD_PD5               (0x1U<<5U)
#define PWR_PDCRD_PD4               (0x1U<<4U)
#define PWR_PDCRD_PD3               (0x1U<<3U)
#define PWR_PDCRD_PD2               (0x1U<<2U)
#define PWR_PDCRD_PD1               (0x1U<<1U)
#define PWR_PDCRD_PD0               (0x1U<<0U)

// PDCRE Configuration

#define PWR_PDCRE_PD15              (0x1U<<15U)
#define PWR_PDCRE_PD14              (0x1U<<14U)
#define PWR_PDCRE_PD13              (0x1U<<13U)
#define PWR_PDCRE_PD12              (0x1U<<12U)
#define PWR_PDCRE_PD11              (0x1U<<11U)
#define PWR_PDCRE_PD10              (0x1U<<10U)
#define PWR_PDCRE_PD9               (0x1U<<9U)
#define PWR_PDCRE_PD8               (0x1U<<8U)
#define PWR_PDCRE_PD7               (0x1U<<7U)
#define PWR_PDCRE_PD6               (0x1U<<6U)
#define PWR_PDCRE_PD5               (0x1U<<5U)
#define PWR_PDCRE_PD4               (0x1U<<4U)
#define PWR_PDCRE_PD3               (0x1U<<3U)
#define PWR_PDCRE_PD2               (0x1U<<2U)
#define PWR_PDCRE_PD1               (0x1U<<1U)
#define PWR_PDCRE_PD0               (0x1U<<0U)

// PUCRF Configuration

#define PWR_PUCRF_PU15              (0x1U<<15U)
#define PWR_PUCRF_PU14              (0x1U<<14U)
#define PWR_PUCRF_PU13              (0x1U<<13U)
#define PWR_PUCRF_PU12              (0x1U<<12U)
#define PWR_PUCRF_PU11              (0x1U<<11U)
#define PWR_PUCRF_PU10              (0x1U<<10U)
#define PWR_PUCRF_PU9               (0x1U<<9U)
#define PWR_PUCRF_PU8               (0x1U<<8U)
#define PWR_PUCRF_PU7               (0x1U<<7U)
#define PWR_PUCRF_PU6               (0x1U<<6U)
#define PWR_PUCRF_PU5               (0x1U<<5U)
#define PWR_PUCRF_PU4               (0x1U<<4U)
#define PWR_PUCRF_PU3               (0x1U<<3U)
#define PWR_PUCRF_PU2               (0x1U<<2U)
#define PWR_PUCRF_PU1               (0x1U<<1U)
#define PWR_PUCRF_PU0               (0x1U<<0U)

// PDCRF Configuration

#define PWR_PDCRF_PD15              (0x1U<<15U)
#define PWR_PDCRF_PD14              (0x1U<<14U)
#define PWR_PDCRF_PD13              (0x1U<<13U)
#define PWR_PDCRF_PD12              (0x1U<<12U)
#define PWR_PDCRF_PD11              (0x1U<<11U)
#define PWR_PDCRF_PD10              (0x1U<<10U)
#define PWR_PDCRF_PD9               (0x1U<<9U)
#define PWR_PDCRF_PD8               (0x1U<<8U)
#define PWR_PDCRF_PD7               (0x1U<<7U)
#define PWR_PDCRF_PD6               (0x1U<<6U)
#define PWR_PDCRF_PD5               (0x1U<<5U)
#define PWR_PDCRF_PD4               (0x1U<<4U)
#define PWR_PDCRF_PD3               (0x1U<<3U)
#define PWR_PDCRF_PD2               (0x1U<<2U)
#define PWR_PDCRF_PD1               (0x1U<<1U)
#define PWR_PDCRF_PD0               (0x1U<<0U)

// PUCRG Configuration

#define PWR_PUCRG_PU15              (0x1U<<15U)
#define PWR_PUCRG_PU14              (0x1U<<14U)
#define PWR_PUCRG_PU13              (0x1U<<13U)
#define PWR_PUCRG_PU12              (0x1U<<12U)
#define PWR_PUCRG_PU11              (0x1U<<11U)
#define PWR_PUCRG_PU10              (0x1U<<10U)
#define PWR_PUCRG_PU9               (0x1U<<9U)
#define PWR_PUCRG_PU8               (0x1U<<8U)
#define PWR_PUCRG_PU7               (0x1U<<7U)
#define PWR_PUCRG_PU6               (0x1U<<6U)
#define PWR_PUCRG_PU5               (0x1U<<5U)
#define PWR_PUCRG_PU4               (0x1U<<4U)
#define PWR_PUCRG_PU3               (0x1U<<3U)
#define PWR_PUCRG_PU2               (0x1U<<2U)
#define PWR_PUCRG_PU1               (0x1U<<1U)
#define PWR_PUCRG_PU0               (0x1U<<0U)

// PDCRG Configuration

#define PWR_PDCRG_PD15              (0x1U<<15U)
#define PWR_PDCRG_PD14              (0x1U<<14U)
#define PWR_PDCRG_PD13              (0x1U<<13U)
#define PWR_PDCRG_PD12              (0x1U<<12U)
#define PWR_PDCRG_PD11              (0x1U<<11U)
#define PWR_PDCRG_PD10              (0x1U<<10U)
#define PWR_PDCRG_PD9               (0x1U<<9U)
#define PWR_PDCRG_PD8               (0x1U<<8U)
#define PWR_PDCRG_PD7               (0x1U<<7U)
#define PWR_PDCRG_PD6               (0x1U<<6U)
#define PWR_PDCRG_PD5               (0x1U<<5U)
#define PWR_PDCRG_PD4               (0x1U<<4U)
#define PWR_PDCRG_PD3               (0x1U<<3U)
#define PWR_PDCRG_PD2               (0x1U<<2U)
#define PWR_PDCRG_PD1               (0x1U<<1U)
#define PWR_PDCRG_PD0               (0x1U<<0U)

// PUCRH Configuration

#define PWR_PUCRH_PU15              (0x1U<<15U)
#define PWR_PUCRH_PU14              (0x1U<<14U)
#define PWR_PUCRH_PU13              (0x1U<<13U)
#define PWR_PUCRH_PU12              (0x1U<<12U)
#define PWR_PUCRH_PU11              (0x1U<<11U)
#define PWR_PUCRH_PU10              (0x1U<<10U)
#define PWR_PUCRH_PU9               (0x1U<<9U)
#define PWR_PUCRH_PU8               (0x1U<<8U)
#define PWR_PUCRH_PU7               (0x1U<<7U)
#define PWR_PUCRH_PU6               (0x1U<<6U)
#define PWR_PUCRH_PU5               (0x1U<<5U)
#define PWR_PUCRH_PU4               (0x1U<<4U)
#define PWR_PUCRH_PU3               (0x1U<<3U)
#define PWR_PUCRH_PU2               (0x1U<<2U)
#define PWR_PUCRH_PU1               (0x1U<<1U)
#define PWR_PUCRH_PU0               (0x1U<<0U)

// PDCRH Configuration

#define PWR_PDCRH_PD15              (0x1U<<15U)
#define PWR_PDCRH_PD14              (0x1U<<14U)
#define PWR_PDCRH_PD13              (0x1U<<13U)
#define PWR_PDCRH_PD12              (0x1U<<12U)
#define PWR_PDCRH_PD11              (0x1U<<11U)
#define PWR_PDCRH_PD10              (0x1U<<10U)
#define PWR_PDCRH_PD9               (0x1U<<9U)
#define PWR_PDCRH_PD8               (0x1U<<8U)
#define PWR_PDCRH_PD7               (0x1U<<7U)
#define PWR_PDCRH_PD6               (0x1U<<6U)
#define PWR_PDCRH_PD5               (0x1U<<5U)
#define PWR_PDCRH_PD4               (0x1U<<4U)
#define PWR_PDCRH_PD3               (0x1U<<3U)
#define PWR_PDCRH_PD2               (0x1U<<2U)
#define PWR_PDCRH_PD1               (0x1U<<1U)
#define PWR_PDCRH_PD0               (0x1U<<0U)

// PUCRI Configuration

#define PWR_PUCRI_PU11              (0x1U<<11U)
#define PWR_PUCRI_PU10              (0x1U<<10U)
#define PWR_PUCRI_PU9               (0x1U<<9U)
#define PWR_PUCRI_PU8               (0x1U<<8U)
#define PWR_PUCRI_PU7               (0x1U<<7U)
#define PWR_PUCRI_PU6               (0x1U<<6U)
#define PWR_PUCRI_PU5               (0x1U<<5U)
#define PWR_PUCRI_PU4               (0x1U<<4U)
#define PWR_PUCRI_PU3               (0x1U<<3U)
#define PWR_PUCRI_PU2               (0x1U<<2U)
#define PWR_PUCRI_PU1               (0x1U<<1U)
#define PWR_PUCRI_PU0               (0x1U<<0U)

// PDCRI Configuration

#define PWR_PDCRI_PD11              (0x1U<<11U)
#define PWR_PDCRI_PD10              (0x1U<<10U)
#define PWR_PDCRI_PD9               (0x1U<<9U)
#define PWR_PDCRI_PD8               (0x1U<<8U)
#define PWR_PDCRI_PD7               (0x1U<<7U)
#define PWR_PDCRI_PD6               (0x1U<<6U)
#define PWR_PDCRI_PD5               (0x1U<<5U)
#define PWR_PDCRI_PD4               (0x1U<<4U)
#define PWR_PDCRI_PD3               (0x1U<<3U)
#define PWR_PDCRI_PD2               (0x1U<<2U)
#define PWR_PDCRI_PD1               (0x1U<<1U)
#define PWR_PDCRI_PD0               (0x1U<<0U)

// CR5 Configuration

#define PWR_CR5_R1MODE              (0x1U<<8U)
#define PWR_CR5_R1MODE_B_0X0        (0x0U<<8U)
#define PWR_CR5_R1MODE_B_0X1        (0x1U<<8U)
