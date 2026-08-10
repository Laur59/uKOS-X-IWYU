/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32N657_cryp equates.
 */

#pragma once

#include    <stdint.h>

// CRYP address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    DINR;
    volatile    uint32_t    DOUTR;
    volatile    uint32_t    DMACR;
    volatile    uint32_t    IMSCR;
    volatile    uint32_t    RISR;
    volatile    uint32_t    MISR;
    volatile    uint32_t    K0LR;
    volatile    uint32_t    K0RR;
    volatile    uint32_t    K1LR;
    volatile    uint32_t    K1RR;
    volatile    uint32_t    K2LR;
    volatile    uint32_t    K2RR;
    volatile    uint32_t    K3LR;
    volatile    uint32_t    K3RR;
    volatile    uint32_t    IV0LR;
    volatile    uint32_t    IV0RR;
    volatile    uint32_t    IV1LR;
    volatile    uint32_t    IV1RR;
    volatile    uint32_t    CSGCMCCM0R;
    volatile    uint32_t    CSGCMCCM1R;
    volatile    uint32_t    CSGCMCCM2R;
    volatile    uint32_t    CSGCMCCM3R;
    volatile    uint32_t    CSGCMCCM4R;
    volatile    uint32_t    CSGCMCCM5R;
    volatile    uint32_t    CSGCMCCM6R;
    volatile    uint32_t    CSGCMCCM7R;
    volatile    uint32_t    CSGCM0R;
    volatile    uint32_t    CSGCM1R;
    volatile    uint32_t    CSGCM2R;
    volatile    uint32_t    CSGCM3R;
    volatile    uint32_t    CSGCM4R;
    volatile    uint32_t    CSGCM5R;
    volatile    uint32_t    CSGCM6R;
    volatile    uint32_t    CSGCM7R;
} CRYP_TypeDef;

#ifdef __cplusplus
#define CRYP_NS reinterpret_cast<CRYP_TypeDef *>(0x44020800U)
#define CRYP_S  reinterpret_cast<CRYP_TypeDef *>(0x54020800U)

#else
#define CRYP_NS ((CRYP_TypeDef *)0x44020800U)
#define CRYP_S  ((CRYP_TypeDef *)0x54020800U)
#endif

// CR Configuration

#define CRYP_CR_IPRST               (0x1U<<31U)
#define CRYP_CR_KMOD                (0x3U<<24U)
#define CRYP_CR_KMOD_0              (0x1U<<24U)
#define CRYP_CR_NPBLB               (0xFU<<20U)
#define CRYP_CR_NPBLB_0             (0x1U<<20U)
#define CRYP_CR_ALGOMODE_1          (0x1U<<19U)
#define CRYP_CR_GCM_CCMPH           (0x3U<<16U)
#define CRYP_CR_GCM_CCMPH_0         (0x1U<<16U)
#define CRYP_CR_CRYPEN              (0x1U<<15U)
#define CRYP_CR_FFLUSH              (0x1U<<14U)
#define CRYP_CR_KEYSIZE             (0x3U<<8U)
#define CRYP_CR_KEYSIZE_0           (0x1U<<8U)
#define CRYP_CR_DATATYPE            (0x3U<<6U)
#define CRYP_CR_DATATYPE_0          (0x1U<<6U)
#define CRYP_CR_ALGOMODE            (0x7U<<3U)
#define CRYP_CR_ALGOMODE_0          (0x1U<<3U)
#define CRYP_CR_ALGODIR             (0x1U<<2U)

#define CRYP_CR_KMOD_B_0X0          (0x0U<<24U)
#define CRYP_CR_KMOD_B_0X2          (0x2U<<24U)
#define CRYP_CR_NPBLB_B_0X0         (0x0U<<20U)
#define CRYP_CR_NPBLB_B_0X1         (0x1U<<20U)
#define CRYP_CR_NPBLB_B_0XF         (0xFU<<20U)
#define CRYP_CR_GCM_CCMPH_B_0X0     (0x0U<<16U)
#define CRYP_CR_GCM_CCMPH_B_0X1     (0x1U<<16U)
#define CRYP_CR_GCM_CCMPH_B_0X2     (0x2U<<16U)
#define CRYP_CR_GCM_CCMPH_B_0X3     (0x3U<<16U)
#define CRYP_CR_CRYPEN_B_0X0        (0x0U<<15U)
#define CRYP_CR_CRYPEN_B_0X1        (0x1U<<15U)
#define CRYP_CR_FFLUSH_B_0X0        (0x0U<<14U)
#define CRYP_CR_FFLUSH_B_0X1        (0x1U<<14U)
#define CRYP_CR_KEYSIZE_B_0X0       (0x0U<<8U)
#define CRYP_CR_KEYSIZE_B_0X1       (0x1U<<8U)
#define CRYP_CR_KEYSIZE_B_0X2       (0x2U<<8U)
#define CRYP_CR_DATATYPE_B_0X0      (0x0U<<6U)
#define CRYP_CR_DATATYPE_B_0X1      (0x1U<<6U)
#define CRYP_CR_DATATYPE_B_0X2      (0x2U<<6U)
#define CRYP_CR_DATATYPE_B_0X3      (0x3U<<6U)
#define CRYP_CR_ALGOMODE_B_0X4      (0x4U<<3U)
#define CRYP_CR_ALGOMODE_B_0X5      (0x5U<<3U)
#define CRYP_CR_ALGOMODE_B_0X6      (0x6U<<3U)
#define CRYP_CR_ALGOMODE_B_0X7      (0x7U<<3U)
#define CRYP_CR_ALGODIR_B_0X0       (0x0U<<2U)
#define CRYP_CR_ALGODIR_B_0X1       (0x1U<<2U)

// SR Configuration

#define CRYP_SR_KEYVALID            (0x1U<<7U)
#define CRYP_SR_KERF                (0x1U<<6U)
#define CRYP_SR_BUSY                (0x1U<<4U)
#define CRYP_SR_OFFU                (0x1U<<3U)
#define CRYP_SR_OFNE                (0x1U<<2U)
#define CRYP_SR_IFNF                (0x1U<<1U)
#define CRYP_SR_IFEM                (0x1U<<0U)

#define CRYP_SR_KEYVALID_B_0X0      (0x0U<<7U)
#define CRYP_SR_KEYVALID_B_0X1      (0x1U<<7U)
#define CRYP_SR_KERF_B_0X0          (0x0U<<6U)
#define CRYP_SR_KERF_B_0X1          (0x1U<<6U)
#define CRYP_SR_BUSY_B_0X0          (0x0U<<4U)
#define CRYP_SR_BUSY_B_0X1          (0x1U<<4U)
#define CRYP_SR_OFFU_B_0X0          (0x0U<<3U)
#define CRYP_SR_OFFU_B_0X1          (0x1U<<3U)
#define CRYP_SR_OFNE_B_0X0          (0x0U<<2U)
#define CRYP_SR_OFNE_B_0X1          (0x1U<<2U)
#define CRYP_SR_IFNF_B_0X0          (0x0U<<1U)
#define CRYP_SR_IFNF_B_0X1          (0x1U<<1U)
#define CRYP_SR_IFEM_B_0X0          (0x0U<<0U)
#define CRYP_SR_IFEM_B_0X1          (0x1U<<0U)

// DINR Configuration

#define CRYP_DINR_DIN               (0xFFFFFFFFU<<0U)
#define CRYP_DINR_DIN_0             (0x1U<<0U)

// DOUTR Configuration

#define CRYP_DOUTR_DOUT             (0xFFFFFFFFU<<0U)
#define CRYP_DOUTR_DOUT_0           (0x1U<<0U)

// DMACR Configuration

#define CRYP_DMACR_DOEN             (0x1U<<1U)
#define CRYP_DMACR_DIEN             (0x1U<<0U)

#define CRYP_DMACR_DOEN_B_0X0       (0x0U<<1U)
#define CRYP_DMACR_DOEN_B_0X1       (0x1U<<1U)
#define CRYP_DMACR_DIEN_B_0X0       (0x0U<<0U)
#define CRYP_DMACR_DIEN_B_0X1       (0x1U<<0U)

// IMSCR Configuration

#define CRYP_IMSCR_OUTIM            (0x1U<<1U)
#define CRYP_IMSCR_INIM             (0x1U<<0U)

#define CRYP_IMSCR_OUTIM_B_0X0      (0x0U<<1U)
#define CRYP_IMSCR_OUTIM_B_0X1      (0x1U<<1U)
#define CRYP_IMSCR_INIM_B_0X0       (0x0U<<0U)
#define CRYP_IMSCR_INIM_B_0X1       (0x1U<<0U)

// RISR Configuration

#define CRYP_RISR_OUTRIS            (0x1U<<1U)
#define CRYP_RISR_INRIS             (0x1U<<0U)

#define CRYP_RISR_OUTRIS_B_0X0      (0x0U<<1U)
#define CRYP_RISR_OUTRIS_B_0X1      (0x1U<<1U)
#define CRYP_RISR_INRIS_B_0X0       (0x0U<<0U)
#define CRYP_RISR_INRIS_B_0X1       (0x1U<<0U)

// MISR Configuration

#define CRYP_MISR_OUTMIS            (0x1U<<1U)
#define CRYP_MISR_INMIS             (0x1U<<0U)

#define CRYP_MISR_OUTMIS_B_0X0      (0x0U<<1U)
#define CRYP_MISR_OUTMIS_B_0X1      (0x1U<<1U)
#define CRYP_MISR_INMIS_B_0X0       (0x0U<<0U)
#define CRYP_MISR_INMIS_B_0X1       (0x1U<<0U)

// K0LR Configuration

#define CRYP_K0LR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K0LR_K_0               (0x1U<<0U)

// K0RR Configuration

#define CRYP_K0RR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K0RR_K_0               (0x1U<<0U)

// K1LR Configuration

#define CRYP_K1LR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K1LR_K_0               (0x1U<<0U)

// K1RR Configuration

#define CRYP_K1RR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K1RR_K_0               (0x1U<<0U)

// K2LR Configuration

#define CRYP_K2LR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K2LR_K_0               (0x1U<<0U)

// K2RR Configuration

#define CRYP_K2RR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K2RR_K_0               (0x1U<<0U)

// K3LR Configuration

#define CRYP_K3LR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K3LR_K_0               (0x1U<<0U)

// K3RR Configuration

#define CRYP_K3RR_K                 (0xFFFFFFFFU<<0U)
#define CRYP_K3RR_K_0               (0x1U<<0U)

// IV0LR Configuration

#define CRYP_IV0LR_IVI              (0xFFFFFFFFU<<0U)
#define CRYP_IV0LR_IVI_0            (0x1U<<0U)

// IV0RR Configuration

#define CRYP_IV0RR_IVI              (0xFFFFFFFFU<<0U)
#define CRYP_IV0RR_IVI_0            (0x1U<<0U)

// IV1LR Configuration

#define CRYP_IV1LR_IVI              (0xFFFFFFFFU<<0U)
#define CRYP_IV1LR_IVI_0            (0x1U<<0U)

// IV1RR Configuration

#define CRYP_IV1RR_IVI              (0xFFFFFFFFU<<0U)
#define CRYP_IV1RR_IVI_0            (0x1U<<0U)

// CSGCMCCM0R Configuration

#define CRYP_CSGCMCCM0R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM0R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM1R Configuration

#define CRYP_CSGCMCCM1R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM1R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM2R Configuration

#define CRYP_CSGCMCCM2R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM2R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM3R Configuration

#define CRYP_CSGCMCCM3R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM3R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM4R Configuration

#define CRYP_CSGCMCCM4R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM4R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM5R Configuration

#define CRYP_CSGCMCCM5R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM5R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM6R Configuration

#define CRYP_CSGCMCCM6R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM6R_CSGCMCCM_0  (0x1U<<0U)

// CSGCMCCM7R Configuration

#define CRYP_CSGCMCCM7R_CSGCMCCM    (0xFFFFFFFFU<<0U)
#define CRYP_CSGCMCCM7R_CSGCMCCM_0  (0x1U<<0U)

// CSGCM0R Configuration

#define CRYP_CSGCM0R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM0R_CSGCM_0        (0x1U<<0U)

// CSGCM1R Configuration

#define CRYP_CSGCM1R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM1R_CSGCM_0        (0x1U<<0U)

// CSGCM2R Configuration

#define CRYP_CSGCM2R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM2R_CSGCM_0        (0x1U<<0U)

// CSGCM3R Configuration

#define CRYP_CSGCM3R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM3R_CSGCM_0        (0x1U<<0U)

// CSGCM4R Configuration

#define CRYP_CSGCM4R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM4R_CSGCM_0        (0x1U<<0U)

// CSGCM5R Configuration

#define CRYP_CSGCM5R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM5R_CSGCM_0        (0x1U<<0U)

// CSGCM6R Configuration

#define CRYP_CSGCM6R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM6R_CSGCM_0        (0x1U<<0U)

// CSGCM7R Configuration

#define CRYP_CSGCM7R_CSGCM          (0xFFFFFFFFU<<0U)
#define CRYP_CSGCM7R_CSGCM_0        (0x1U<<0U)
