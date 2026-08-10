/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_dcmi equates.
 */

#pragma once

#include    <stdint.h>

// DCMI address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    RIS;
    volatile    uint32_t    IER;
    volatile    uint32_t    MIS;
    volatile    uint32_t    ICR;
    volatile    uint32_t    ESCR;
    volatile    uint32_t    ESUR;
    volatile    uint32_t    CWSTRT;
    volatile    uint32_t    CWSIZE;
    volatile    uint32_t    DR;
} DCMI_TypeDef;

#ifdef __cplusplus
#define DCMI    reinterpret_cast<DCMI_TypeDef *>(0x48020000U)

#else
#define DCMI    ((DCMI_TypeDef *)0x48020000U)
#endif

// CR Configuration

#define DCMI_CR_CAPTURE         (0x1U<<0U)
#define DCMI_CR_CM              (0x1U<<1U)
#define DCMI_CR_CROP            (0x1U<<2U)
#define DCMI_CR_JPEG            (0x1U<<3U)
#define DCMI_CR_ESS             (0x1U<<4U)
#define DCMI_CR_PCKPOL          (0x1U<<5U)
#define DCMI_CR_HSPOL           (0x1U<<6U)
#define DCMI_CR_VSPOL           (0x1U<<7U)
#define DCMI_CR_FCRC            (0x3U<<8U)
#define DCMI_CR_FCRC_0          (0x1U<<8U)
#define DCMI_CR_EDM             (0x3U<<10U)
#define DCMI_CR_EDM_0           (0x1U<<10U)
#define DCMI_CR_ENABLE          (0x1U<<14U)
#define DCMI_CR_BSM             (0x3U<<16U)
#define DCMI_CR_BSM_0           (0x1U<<16U)
#define DCMI_CR_OEBS            (0x1U<<18U)
#define DCMI_CR_LSM             (0x1U<<19U)
#define DCMI_CR_OELS            (0x1U<<20U)

// SR Configuration

#define DCMI_SR_HSYNC           (0x1U<<0U)
#define DCMI_SR_VSYNC           (0x1U<<1U)
#define DCMI_SR_FNE             (0x1U<<2U)

// RIS Configuration

#define DCMI_RIS_FRAME_RIS      (0x1U<<0U)
#define DCMI_RIS_OVR_RIS        (0x1U<<1U)
#define DCMI_RIS_ERR_RIS        (0x1U<<2U)
#define DCMI_RIS_VSYNC_RIS      (0x1U<<3U)
#define DCMI_RIS_LINE_RIS       (0x1U<<4U)

// IER Configuration

#define DCMI_IER_FRAME_IE       (0x1U<<0U)
#define DCMI_IER_OVR_IE         (0x1U<<1U)
#define DCMI_IER_ERR_IE         (0x1U<<2U)
#define DCMI_IER_VSYNC_IE       (0x1U<<3U)
#define DCMI_IER_LINE_IE        (0x1U<<4U)

// MIS Configuration

#define DCMI_MIS_FRAME_MIS      (0x1U<<0U)
#define DCMI_MIS_OVR_MIS        (0x1U<<1U)
#define DCMI_MIS_ERR_MIS        (0x1U<<2U)
#define DCMI_MIS_VSYNC_MIS      (0x1U<<3U)
#define DCMI_MIS_LINE_MIS       (0x1U<<4U)

// ICR Configuration

#define DCMI_ICR_FRAME_ISC      (0x1U<<0U)
#define DCMI_ICR_OVR_ISC        (0x1U<<1U)
#define DCMI_ICR_ERR_ISC        (0x1U<<2U)
#define DCMI_ICR_VSYNC_ISC      (0x1U<<3U)
#define DCMI_ICR_LINE_ISC       (0x1U<<4U)

// ESCR Configuration

#define DCMI_ESCR_FSC           (0xFFU<<0U)
#define DCMI_ESCR_FSC_0         (0x1U<<0U)
#define DCMI_ESCR_LSC           (0xFFU<<8U)
#define DCMI_ESCR_LSC_0         (0x1U<<8U)
#define DCMI_ESCR_LEC           (0xFFU<<16U)
#define DCMI_ESCR_LEC_0         (0x1U<<16U)
#define DCMI_ESCR_FEC           (0xFFU<<24U)
#define DCMI_ESCR_FEC_0         (0x1U<<24U)

// ESUR Configuration

#define DCMI_ESUR_FSU           (0xFFU<<0U)
#define DCMI_ESUR_FSU_0         (0x1U<<0U)
#define DCMI_ESUR_LSU           (0xFFU<<8U)
#define DCMI_ESUR_LSU_0         (0x1U<<8U)
#define DCMI_ESUR_LEU           (0xFFU<<16U)
#define DCMI_ESUR_LEU_0         (0x1U<<16U)
#define DCMI_ESUR_FEU           (0xFFU<<24U)
#define DCMI_ESUR_FEU_0         (0x1U<<24U)

// CWSTRT Configuration

#define DCMI_CWSTRT_HOFFCNT     (0x3FFFU<<0U)
#define DCMI_CWSTRT_HOFFCNT_0   (0x1U<<0U)
#define DCMI_CWSTRT_VST         (0x1FFFU<<16U)
#define DCMI_CWSTRT_VST_0       (0x1U<<16U)

// CWSIZE Configuration

#define DCMI_CWSIZE_CAPCNT      (0x3FFFU<<0U)
#define DCMI_CWSIZE_CAPCNT_0    (0x1U<<0U)
#define DCMI_CWSIZE_VLINE       (0x3FFFU<<16U)
#define DCMI_CWSIZE_VLINE_0     (0x1U<<16U)

// DR Configuration

#define DCMI_DR_BYTE0           (0xFFU<<0U)
#define DCMI_DR_BYTE0_0         (0x1U<<0U)
#define DCMI_DR_BYTE1           (0xFFU<<8U)
#define DCMI_DR_BYTE1_0         (0x1U<<8U)
#define DCMI_DR_BYTE2           (0xFFU<<16U)
#define DCMI_DR_BYTE2_0         (0x1U<<16U)
#define DCMI_DR_BYTE3           (0xFFU<<24U)
#define DCMI_DR_BYTE3_0         (0x1U<<24U)
