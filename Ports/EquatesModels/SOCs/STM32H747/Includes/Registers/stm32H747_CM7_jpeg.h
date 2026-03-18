/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32H747_CM7_jpeg equates.
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

#define JPEG_CONFR0_START           (0x1U<<0)

// CONFR1 Configuration

#define JPEG_CONFR1_YSIZE           (0xFFFFU<<16)
#define JPEG_CONFR1_YSIZE_0         (0x1U<<16)
#define JPEG_CONFR1_HDR             (0x1U<<8)
#define JPEG_CONFR1_NS              (0x3U<<6)
#define JPEG_CONFR1_NS_0            (0x1U<<6)
#define JPEG_CONFR1_COLORSPACE      (0x3U<<4)
#define JPEG_CONFR1_COLORSPACE_0    (0x1U<<4)
#define JPEG_CONFR1_DE              (0x1U<<3)
#define JPEG_CONFR1_NF              (0x3U<<0)
#define JPEG_CONFR1_NF_0            (0x1U<<0)

// CONFR2 Configuration

#define JPEG_CONFR2_NMCU            (0x3FFFFFFU<<0)
#define JPEG_CONFR2_NMCU_0          (0x1U<<0)

// CONFR3 Configuration

#define JPEG_CONFR3_XSIZE           (0xFFFFU<<16)
#define JPEG_CONFR3_XSIZE_0         (0x1U<<16)

// CONFRN1 Configuration

#define JPEG_CONFRN1_HSF            (0xFU<<12)
#define JPEG_CONFRN1_HSF_0          (0x1U<<12)
#define JPEG_CONFRN1_VSF            (0xFU<<8)
#define JPEG_CONFRN1_VSF_0          (0x1U<<8)
#define JPEG_CONFRN1_NB             (0xFU<<4)
#define JPEG_CONFRN1_NB_0           (0x1U<<4)
#define JPEG_CONFRN1_QT             (0x3U<<2)
#define JPEG_CONFRN1_QT_0           (0x1U<<2)
#define JPEG_CONFRN1_HA             (0x1U<<1)
#define JPEG_CONFRN1_HD             (0x1U<<0)

// CONFRN2 Configuration

#define JPEG_CONFRN2_HSF            (0xFU<<12)
#define JPEG_CONFRN2_HSF_0          (0x1U<<12)
#define JPEG_CONFRN2_VSF            (0xFU<<8)
#define JPEG_CONFRN2_VSF_0          (0x1U<<8)
#define JPEG_CONFRN2_NB             (0xFU<<4)
#define JPEG_CONFRN2_NB_0           (0x1U<<4)
#define JPEG_CONFRN2_QT             (0x3U<<2)
#define JPEG_CONFRN2_QT_0           (0x1U<<2)
#define JPEG_CONFRN2_HA             (0x1U<<1)
#define JPEG_CONFRN2_HD             (0x1U<<0)

// CONFRN3 Configuration

#define JPEG_CONFRN3_HSF            (0xFU<<12)
#define JPEG_CONFRN3_HSF_0          (0x1U<<12)
#define JPEG_CONFRN3_VSF            (0xFU<<8)
#define JPEG_CONFRN3_VSF_0          (0x1U<<8)
#define JPEG_CONFRN3_NB             (0xFU<<4)
#define JPEG_CONFRN3_NB_0           (0x1U<<4)
#define JPEG_CONFRN3_QT             (0x3U<<2)
#define JPEG_CONFRN3_QT_0           (0x1U<<2)
#define JPEG_CONFRN3_HA             (0x1U<<1)
#define JPEG_CONFRN3_HD             (0x1U<<0)

// CONFRN4 Configuration

#define JPEG_CONFRN4_HSF            (0xFU<<12)
#define JPEG_CONFRN4_HSF_0          (0x1U<<12)
#define JPEG_CONFRN4_VSF            (0xFU<<8)
#define JPEG_CONFRN4_VSF_0          (0x1U<<8)
#define JPEG_CONFRN4_NB             (0xFU<<4)
#define JPEG_CONFRN4_NB_0           (0x1U<<4)
#define JPEG_CONFRN4_QT             (0x3U<<2)
#define JPEG_CONFRN4_QT_0           (0x1U<<2)
#define JPEG_CONFRN4_HA             (0x1U<<1)
#define JPEG_CONFRN4_HD             (0x1U<<0)

// CR Configuration

#define JPEG_CR_OFF                 (0x1U<<14)
#define JPEG_CR_IFF                 (0x1U<<13)
#define JPEG_CR_ODMAEN              (0x1U<<12)
#define JPEG_CR_IDMAEN              (0x1U<<11)
#define JPEG_CR_HPDIE               (0x1U<<6)
#define JPEG_CR_EOCIE               (0x1U<<5)
#define JPEG_CR_OFNEIE              (0x1U<<4)
#define JPEG_CR_OFTIE               (0x1U<<3)
#define JPEG_CR_IFNFIE              (0x1U<<2)
#define JPEG_CR_IFTIE               (0x1U<<1)
#define JPEG_CR_JCEN                (0x1U<<0)

// SR Configuration

#define JPEG_SR_COF                 (0x1U<<7)
#define JPEG_SR_HPDF                (0x1U<<6)
#define JPEG_SR_EOCF                (0x1U<<5)
#define JPEG_SR_OFNEF               (0x1U<<4)
#define JPEG_SR_OFTF                (0x1U<<3)
#define JPEG_SR_IFNFF               (0x1U<<2)
#define JPEG_SR_IFTF                (0x1U<<1)

// CFR Configuration

#define JPEG_CFR_CHPDF              (0x1U<<6)
#define JPEG_CFR_CEOCF              (0x1U<<5)

// DIR Configuration

#define JPEG_DIR_DATAIN             (0xFFFFFFFFU<<0)
#define JPEG_DIR_DATAIN_0           (0x1U<<0)

// DOR Configuration

#define JPEG_DOR_DATAOUT            (0xFFFFFFFFU<<0)
#define JPEG_DOR_DATAOUT_0          (0x1U<<0)
