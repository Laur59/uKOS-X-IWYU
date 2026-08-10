/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     stm32U5Gx_fmac equates.
 */

#pragma once

#include    <stdint.h>

// FMAC address definitions
// ------------------------

typedef struct {
    volatile    uint32_t    X1BUFCFG;
    volatile    uint32_t    X2BUFCFG;
    volatile    uint32_t    YBUFCFG;
    volatile    uint32_t    PARAM;
    volatile    uint32_t    CR;
    volatile    uint32_t    SR;
    volatile    uint32_t    WDATA;
    volatile    uint32_t    RDATA;
} FMAC_TypeDef;

#ifdef __cplusplus
#define FMAC_NS reinterpret_cast<FMAC_TypeDef *>(0x40021400U)
#define FMAC_S  reinterpret_cast<FMAC_TypeDef *>(0x50021400U)

#else
#define FMAC_NS ((FMAC_TypeDef *)0x40021400U)
#define FMAC_S  ((FMAC_TypeDef *)0x50021400U)
#endif

// X1BUFCFG Configuration

#define FMAC_X1BUFCFG_FULL_WM       (0x3U<<24U)
#define FMAC_X1BUFCFG_FULL_WM_0     (0x1U<<24U)
#define FMAC_X1BUFCFG_X1_BUF_SIZE   (0xFFU<<8U)
#define FMAC_X1BUFCFG_X1_BUF_SIZE_0 (0x1U<<8U)
#define FMAC_X1BUFCFG_X1_BASE       (0xFFU<<0U)
#define FMAC_X1BUFCFG_X1_BASE_0     (0x1U<<0U)

// X2BUFCFG Configuration

#define FMAC_X2BUFCFG_X2_BUF_SIZE   (0xFFU<<8U)
#define FMAC_X2BUFCFG_X2_BUF_SIZE_0 (0x1U<<8U)
#define FMAC_X2BUFCFG_X2_BASE       (0xFFU<<0U)
#define FMAC_X2BUFCFG_X2_BASE_0     (0x1U<<0U)

// YBUFCFG Configuration

#define FMAC_YBUFCFG_EMPTY_WM       (0x3U<<24U)
#define FMAC_YBUFCFG_EMPTY_WM_0     (0x1U<<24U)
#define FMAC_YBUFCFG_Y_BUF_SIZE     (0xFFU<<8U)
#define FMAC_YBUFCFG_Y_BUF_SIZE_0   (0x1U<<8U)
#define FMAC_YBUFCFG_Y_BASE         (0xFFU<<0U)
#define FMAC_YBUFCFG_Y_BASE_0       (0x1U<<0U)

// PARAM Configuration

#define FMAC_PARAM_P                (0xFFU<<0U)
#define FMAC_PARAM_P_0              (0x1U<<0U)
#define FMAC_PARAM_Q                (0xFFU<<8U)
#define FMAC_PARAM_Q_0              (0x1U<<8U)
#define FMAC_PARAM_R                (0xFFU<<16U)
#define FMAC_PARAM_R_0              (0x1U<<16U)
#define FMAC_PARAM_FUNC             (0x7FU<<24U)
#define FMAC_PARAM_FUNC_0           (0x1U<<24U)
#define FMAC_PARAM_START            (0x1U<<31U)

// CR Configuration

#define FMAC_CR_RIEN                (0x1U<<0U)
#define FMAC_CR_WIEN                (0x1U<<1U)
#define FMAC_CR_OVFLIEN             (0x1U<<2U)
#define FMAC_CR_UNFLIEN             (0x1U<<3U)
#define FMAC_CR_SATIEN              (0x1U<<4U)
#define FMAC_CR_DMAREN              (0x1U<<8U)
#define FMAC_CR_DMAWEN              (0x1U<<9U)
#define FMAC_CR_CLIPEN              (0x1U<<15U)
#define FMAC_CR_RESET               (0x1U<<16U)

// SR Configuration

#define FMAC_SR_SAT                 (0x1U<<10U)
#define FMAC_SR_UNFL                (0x1U<<9U)
#define FMAC_SR_OVFL                (0x1U<<8U)
#define FMAC_SR_X1FULL              (0x1U<<1U)
#define FMAC_SR_YEMPTY              (0x1U<<0U)

// WDATA Configuration

#define FMAC_WDATA_WDATA            (0xFFFFU<<0U)
#define FMAC_WDATA_WDATA_0          (0x1U<<0U)

// RDATA Configuration

#define FMAC_RDATA_RDATA            (0xFFFFU<<0U)
#define FMAC_RDATA_RDATA_0          (0x1U<<0U)
