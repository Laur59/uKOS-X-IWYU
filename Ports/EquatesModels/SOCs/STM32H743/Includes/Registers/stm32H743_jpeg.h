/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H743_jpeg equates.
 */

#pragma once

#include    <stdint.h>

// JPEG address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    CONFR0;
    volatile    uint32_t    CONFR1;
    volatile    uint32_t    CONFR2;
    volatile    uint32_t    CONFR3;
    volatile    uint32_t    CONFRN1;
    volatile    uint32_t    CONFRN2;
    volatile    uint32_t    CONFRN3;
    volatile    uint32_t    CONFRN4;
    volatile    uint32_t    RESERVED0[4];
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    CFR;
    volatile    uint32_t    RESERVED1;
    volatile    uint32_t    DIR;
    volatile    uint32_t    DOR;
} JPEG_TypeDef;

#ifdef __cplusplus
#define JPEG    reinterpret_cast<JPEG_TypeDef *>(0x52003000U)

#else
#define JPEG    ((JPEG_TypeDef *)0x52003000U)
#endif

// CONFR0 Configuration

#define JPEG_CONFR0_START           (0x1U<<0U)

// CONFR1 Configuration

#define JPEG_CONFR1_YSIZE           (0xFFFFU<<16U)
#define JPEG_CONFR1_YSIZE_0         (0x1U<<16U)
#define JPEG_CONFR1_HDR             (0x1U<<8U)
#define JPEG_CONFR1_NS              (0x3U<<6U)
#define JPEG_CONFR1_NS_0            (0x1U<<6U)
#define JPEG_CONFR1_COLORSPACE      (0x3U<<4U)
#define JPEG_CONFR1_COLORSPACE_0    (0x1U<<4U)
#define JPEG_CONFR1_DE              (0x1U<<3U)
#define JPEG_CONFR1_NF              (0x3U<<0U)
#define JPEG_CONFR1_NF_0            (0x1U<<0U)

// CONFR2 Configuration

#define JPEG_CONFR2_NMCU            (0x3FFFFFFU<<0U)
#define JPEG_CONFR2_NMCU_0          (0x1U<<0U)

// CONFR3 Configuration

#define JPEG_CONFR3_XSIZE           (0xFFFFU<<16U)
#define JPEG_CONFR3_XSIZE_0         (0x1U<<16U)

// CONFRN1 Configuration

#define JPEG_CONFRN1_HSF            (0xFU<<12U)
#define JPEG_CONFRN1_HSF_0          (0x1U<<12U)
#define JPEG_CONFRN1_VSF            (0xFU<<8U)
#define JPEG_CONFRN1_VSF_0          (0x1U<<8U)
#define JPEG_CONFRN1_NB             (0xFU<<4U)
#define JPEG_CONFRN1_NB_0           (0x1U<<4U)
#define JPEG_CONFRN1_QT             (0x3U<<2U)
#define JPEG_CONFRN1_QT_0           (0x1U<<2U)
#define JPEG_CONFRN1_HA             (0x1U<<1U)
#define JPEG_CONFRN1_HD             (0x1U<<0U)

// CONFRN2 Configuration

#define JPEG_CONFRN2_HSF            (0xFU<<12U)
#define JPEG_CONFRN2_HSF_0          (0x1U<<12U)
#define JPEG_CONFRN2_VSF            (0xFU<<8U)
#define JPEG_CONFRN2_VSF_0          (0x1U<<8U)
#define JPEG_CONFRN2_NB             (0xFU<<4U)
#define JPEG_CONFRN2_NB_0           (0x1U<<4U)
#define JPEG_CONFRN2_QT             (0x3U<<2U)
#define JPEG_CONFRN2_QT_0           (0x1U<<2U)
#define JPEG_CONFRN2_HA             (0x1U<<1U)
#define JPEG_CONFRN2_HD             (0x1U<<0U)

// CONFRN3 Configuration

#define JPEG_CONFRN3_HSF            (0xFU<<12U)
#define JPEG_CONFRN3_HSF_0          (0x1U<<12U)
#define JPEG_CONFRN3_VSF            (0xFU<<8U)
#define JPEG_CONFRN3_VSF_0          (0x1U<<8U)
#define JPEG_CONFRN3_NB             (0xFU<<4U)
#define JPEG_CONFRN3_NB_0           (0x1U<<4U)
#define JPEG_CONFRN3_QT             (0x3U<<2U)
#define JPEG_CONFRN3_QT_0           (0x1U<<2U)
#define JPEG_CONFRN3_HA             (0x1U<<1U)
#define JPEG_CONFRN3_HD             (0x1U<<0U)

// CONFRN4 Configuration

#define JPEG_CONFRN4_HSF            (0xFU<<12U)
#define JPEG_CONFRN4_HSF_0          (0x1U<<12U)
#define JPEG_CONFRN4_VSF            (0xFU<<8U)
#define JPEG_CONFRN4_VSF_0          (0x1U<<8U)
#define JPEG_CONFRN4_NB             (0xFU<<4U)
#define JPEG_CONFRN4_NB_0           (0x1U<<4U)
#define JPEG_CONFRN4_QT             (0x3U<<2U)
#define JPEG_CONFRN4_QT_0           (0x1U<<2U)
#define JPEG_CONFRN4_HA             (0x1U<<1U)
#define JPEG_CONFRN4_HD             (0x1U<<0U)

// CR Configuration

#define JPEG_CR_OFF                 (0x1U<<14U)
#define JPEG_CR_IFF                 (0x1U<<13U)
#define JPEG_CR_ODMAEN              (0x1U<<12U)
#define JPEG_CR_IDMAEN              (0x1U<<11U)
#define JPEG_CR_HPDIE               (0x1U<<6U)
#define JPEG_CR_EOCIE               (0x1U<<5U)
#define JPEG_CR_OFNEIE              (0x1U<<4U)
#define JPEG_CR_OFTIE               (0x1U<<3U)
#define JPEG_CR_IFNFIE              (0x1U<<2U)
#define JPEG_CR_IFTIE               (0x1U<<1U)
#define JPEG_CR_JCEN                (0x1U<<0U)

// SR Configuration

#define JPEG_SR_COF                 (0x1U<<7U)
#define JPEG_SR_HPDF                (0x1U<<6U)
#define JPEG_SR_EOCF                (0x1U<<5U)
#define JPEG_SR_OFNEF               (0x1U<<4U)
#define JPEG_SR_OFTF                (0x1U<<3U)
#define JPEG_SR_IFNFF               (0x1U<<2U)
#define JPEG_SR_IFTF                (0x1U<<1U)

// CFR Configuration

#define JPEG_CFR_CHPDF              (0x1U<<6U)
#define JPEG_CFR_CEOCF              (0x1U<<5U)

// DIR Configuration

#define JPEG_DIR_DATAIN             (0xFFFFFFFFU<<0U)
#define JPEG_DIR_DATAIN_0           (0x1U<<0U)

// DOR Configuration

#define JPEG_DOR_DATAOUT            (0xFFFFFFFFU<<0U)
#define JPEG_DOR_DATAOUT_0          (0x1U<<0U)
