/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; stm32N657_dcmi.
; ===============

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     stm32N657_dcmi equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
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
#define DCMI_NS reinterpret_cast<DCMI_TypeDef *>(0x48028400U)
#define DCMI_S  reinterpret_cast<DCMI_TypeDef *>(0x58028400U)

#else
#define DCMI_NS ((DCMI_TypeDef *)0x48028400U)
#define DCMI_S  ((DCMI_TypeDef *)0x58028400U)
#endif

// CR Configuration

#define DCMI_CR_OELS                    (0x1U<<20)
#define DCMI_CR_LSM                     (0x1U<<19)
#define DCMI_CR_OEBS                    (0x1U<<18)
#define DCMI_CR_BSM                     (0x3U<<16)
#define DCMI_CR_BSM_0                   (0x1U<<16)
#define DCMI_CR_ENABLE                  (0x1U<<14)
#define DCMI_CR_EDM                     (0x3U<<10)
#define DCMI_CR_EDM_0                   (0x1U<<10)
#define DCMI_CR_FCRC                    (0x3U<<8)
#define DCMI_CR_FCRC_0                  (0x1U<<8)
#define DCMI_CR_VSPOL                   (0x1U<<7)
#define DCMI_CR_HSPOL                   (0x1U<<6)
#define DCMI_CR_PCKPOL                  (0x1U<<5)
#define DCMI_CR_ESS                     (0x1U<<4)
#define DCMI_CR_JPEG                    (0x1U<<3)
#define DCMI_CR_CROP                    (0x1U<<2)
#define DCMI_CR_CM                      (0x1U<<1)
#define DCMI_CR_CAPTURE                 (0x1U<<0)

#define DCMI_CR_OELS_B_0X0              (0x0U<<20)
#define DCMI_CR_OELS_B_0X1              (0x1U<<20)
#define DCMI_CR_LSM_B_0X0               (0x0U<<19)
#define DCMI_CR_LSM_B_0X1               (0x1U<<19)
#define DCMI_CR_OEBS_B_0X0              (0x0U<<18)
#define DCMI_CR_OEBS_B_0X1              (0x1U<<18)
#define DCMI_CR_BSM_B_0X0               (0x0U<<16)
#define DCMI_CR_BSM_B_0X1               (0x1U<<16)
#define DCMI_CR_BSM_B_0X2               (0x2U<<16)
#define DCMI_CR_BSM_B_0X3               (0x3U<<16)
#define DCMI_CR_ENABLE_B_0X0            (0x0U<<14)
#define DCMI_CR_ENABLE_B_0X1            (0x1U<<14)
#define DCMI_CR_EDM_B_0X0               (0x0U<<10)
#define DCMI_CR_EDM_B_0X1               (0x1U<<10)
#define DCMI_CR_EDM_B_0X2               (0x2U<<10)
#define DCMI_CR_EDM_B_0X3               (0x3U<<10)
#define DCMI_CR_FCRC_B_0X0              (0x0U<<8)
#define DCMI_CR_FCRC_B_0X1              (0x1U<<8)
#define DCMI_CR_FCRC_B_0X2              (0x2U<<8)
#define DCMI_CR_VSPOL_B_0X0             (0x0U<<7)
#define DCMI_CR_VSPOL_B_0X1             (0x1U<<7)
#define DCMI_CR_HSPOL_B_0X0             (0x0U<<6)
#define DCMI_CR_HSPOL_B_0X1             (0x1U<<6)
#define DCMI_CR_PCKPOL_B_0X0            (0x0U<<5)
#define DCMI_CR_PCKPOL_B_0X1            (0x1U<<5)
#define DCMI_CR_ESS_B_0X0               (0x0U<<4)
#define DCMI_CR_ESS_B_0X1               (0x1U<<4)
#define DCMI_CR_JPEG_B_0X0              (0x0U<<3)
#define DCMI_CR_JPEG_B_0X1              (0x1U<<3)
#define DCMI_CR_CROP_B_0X0              (0x0U<<2)
#define DCMI_CR_CROP_B_0X1              (0x1U<<2)
#define DCMI_CR_CM_B_0X0                (0x0U<<1)
#define DCMI_CR_CM_B_0X1                (0x1U<<1)
#define DCMI_CR_CAPTURE_B_0X0           (0x0U<<0)
#define DCMI_CR_CAPTURE_B_0X1           (0x1U<<0)

// SR Configuration

#define DCMI_SR_FNE                     (0x1U<<2)
#define DCMI_SR_VSYNC                   (0x1U<<1)
#define DCMI_SR_HSYNC                   (0x1U<<0)

#define DCMI_SR_FNE_B_0X1               (0x1U<<2)
#define DCMI_SR_FNE_B_0X0               (0x0U<<2)
#define DCMI_SR_VSYNC_B_0X0             (0x0U<<1)
#define DCMI_SR_VSYNC_B_0X1             (0x1U<<1)
#define DCMI_SR_HSYNC_B_0X0             (0x0U<<0)
#define DCMI_SR_HSYNC_B_0X1             (0x1U<<0)

// RIS Configuration

#define DCMI_RIS_LINE_RIS               (0x1U<<4)
#define DCMI_RIS_VSYNC_RIS              (0x1U<<3)
#define DCMI_RIS_ERR_RIS                (0x1U<<2)
#define DCMI_RIS_OVR_RIS                (0x1U<<1)
#define DCMI_RIS_FRAME_RIS              (0x1U<<0)

#define DCMI_RIS_ERR_RIS_B_0X0          (0x0U<<2)
#define DCMI_RIS_ERR_RIS_B_0X1          (0x1U<<2)
#define DCMI_RIS_OVR_RIS_B_0X0          (0x0U<<1)
#define DCMI_RIS_OVR_RIS_B_0X1          (0x1U<<1)
#define DCMI_RIS_FRAME_RIS_B_0X0        (0x0U<<0)
#define DCMI_RIS_FRAME_RIS_B_0X1        (0x1U<<0)

// IER Configuration

#define DCMI_IER_LINE_IE                (0x1U<<4)
#define DCMI_IER_VSYNC_IE               (0x1U<<3)
#define DCMI_IER_ERR_IE                 (0x1U<<2)
#define DCMI_IER_OVR_IE                 (0x1U<<1)
#define DCMI_IER_FRAME_IE               (0x1U<<0)

#define DCMI_IER_LINE_IE_B_0X0          (0x0U<<4)
#define DCMI_IER_LINE_IE_B_0X1          (0x1U<<4)
#define DCMI_IER_VSYNC_IE_B_0X0         (0x0U<<3)
#define DCMI_IER_VSYNC_IE_B_0X1         (0x1U<<3)
#define DCMI_IER_ERR_IE_B_0X0           (0x0U<<2)
#define DCMI_IER_ERR_IE_B_0X1           (0x1U<<2)
#define DCMI_IER_OVR_IE_B_0X0           (0x0U<<1)
#define DCMI_IER_OVR_IE_B_0X1           (0x1U<<1)
#define DCMI_IER_FRAME_IE_B_0X0         (0x0U<<0)
#define DCMI_IER_FRAME_IE_B_0X1         (0x1U<<0)

// MIS Configuration

#define DCMI_MIS_LINE_MIS               (0x1U<<4)
#define DCMI_MIS_VSYNC_MIS              (0x1U<<3)
#define DCMI_MIS_ERR_MIS                (0x1U<<2)
#define DCMI_MIS_OVR_MIS                (0x1U<<1)
#define DCMI_MIS_FRAME_MIS              (0x1U<<0)

#define DCMI_MIS_LINE_MIS_B_0X0         (0x0U<<4)
#define DCMI_MIS_LINE_MIS_B_0X1         (0x1U<<4)
#define DCMI_MIS_VSYNC_MIS_B_0X0        (0x0U<<3)
#define DCMI_MIS_VSYNC_MIS_B_0X1        (0x1U<<3)
#define DCMI_MIS_ERR_MIS_B_0X0          (0x0U<<2)
#define DCMI_MIS_ERR_MIS_B_0X1          (0x1U<<2)
#define DCMI_MIS_OVR_MIS_B_0X0          (0x0U<<1)
#define DCMI_MIS_OVR_MIS_B_0X1          (0x1U<<1)
#define DCMI_MIS_FRAME_MIS_B_0X0        (0x0U<<0)
#define DCMI_MIS_FRAME_MIS_B_0X1        (0x1U<<0)

// ICR Configuration

#define DCMI_ICR_LINE_ISC               (0x1U<<4)
#define DCMI_ICR_VSYNC_ISC              (0x1U<<3)
#define DCMI_ICR_ERR_ISC                (0x1U<<2)
#define DCMI_ICR_OVR_ISC                (0x1U<<1)
#define DCMI_ICR_FRAME_ISC              (0x1U<<0)

// ESCR Configuration

#define DCMI_ESCR_FEC                   (0xFFU<<24)
#define DCMI_ESCR_FEC_0                 (0x1U<<24)
#define DCMI_ESCR_LEC                   (0xFFU<<16)
#define DCMI_ESCR_LEC_0                 (0x1U<<16)
#define DCMI_ESCR_LSC                   (0xFFU<<8)
#define DCMI_ESCR_LSC_0                 (0x1U<<8)
#define DCMI_ESCR_FSC                   (0xFFU<<0)
#define DCMI_ESCR_FSC_0                 (0x1U<<0)

// ESUR Configuration

#define DCMI_ESUR_FEU                   (0xFFU<<24)
#define DCMI_ESUR_FEU_0                 (0x1U<<24)
#define DCMI_ESUR_LEU                   (0xFFU<<16)
#define DCMI_ESUR_LEU_0                 (0x1U<<16)
#define DCMI_ESUR_LSU                   (0xFFU<<8)
#define DCMI_ESUR_LSU_0                 (0x1U<<8)
#define DCMI_ESUR_FSU                   (0xFFU<<0)
#define DCMI_ESUR_FSU_0                 (0x1U<<0)

#define DCMI_ESUR_FEU_B_0X0             (0x0U<<24)
#define DCMI_ESUR_FEU_B_0X1             (0x1U<<24)
#define DCMI_ESUR_LEU_B_0X0             (0x0U<<16)
#define DCMI_ESUR_LEU_B_0X1             (0x1U<<16)
#define DCMI_ESUR_LSU_B_0X0             (0x0U<<8)
#define DCMI_ESUR_LSU_B_0X1             (0x1U<<8)
#define DCMI_ESUR_FSU_B_0X0             (0x0U<<0)
#define DCMI_ESUR_FSU_B_0X1             (0x1U<<0)

// CWSTRT Configuration

#define DCMI_CWSTRT_VST                 (0x1FFFU<<16)
#define DCMI_CWSTRT_VST_0               (0x1U<<16)
#define DCMI_CWSTRT_HOFFCNT             (0x3FFFU<<0)
#define DCMI_CWSTRT_HOFFCNT_0           (0x1U<<0)

#define DCMI_CWSTRT_VST_B_0X0000        (0x0U<<16)
#define DCMI_CWSTRT_VST_B_0X0001        (0x1U<<16)
#define DCMI_CWSTRT_VST_B_0X0002        (0x2U<<16)

// CWSIZE Configuration

#define DCMI_CWSIZE_VLINE               (0x3FFFU<<16)
#define DCMI_CWSIZE_VLINE_0             (0x1U<<16)
#define DCMI_CWSIZE_CAPCNT              (0x3FFFU<<0)
#define DCMI_CWSIZE_CAPCNT_0            (0x1U<<0)

#define DCMI_CWSIZE_VLINE_B_0X0000      (0x0U<<16)
#define DCMI_CWSIZE_VLINE_B_0X0001      (0x1U<<16)
#define DCMI_CWSIZE_VLINE_B_0X0002      (0x2U<<16)
#define DCMI_CWSIZE_CAPCNT_B_0X0000     (0x0U<<0)
#define DCMI_CWSIZE_CAPCNT_B_0X0001     (0x1U<<0)
#define DCMI_CWSIZE_CAPCNT_B_0X0002     (0x2U<<0)

// DR Configuration

#define DCMI_DR_BYTE3                   (0xFFU<<24)
#define DCMI_DR_BYTE3_0                 (0x1U<<24)
#define DCMI_DR_BYTE2                   (0xFFU<<16)
#define DCMI_DR_BYTE2_0                 (0x1U<<16)
#define DCMI_DR_BYTE1                   (0xFFU<<8)
#define DCMI_DR_BYTE1_0                 (0x1U<<8)
#define DCMI_DR_BYTE0                   (0xFFU<<0)
#define DCMI_DR_BYTE0_0                 (0x1U<<0)
