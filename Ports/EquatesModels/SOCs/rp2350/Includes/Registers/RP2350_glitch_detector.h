/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     RP2350_glitch_detector equates.
 */

#pragma once

#include    <stdint.h>

// GLITCH_DETECTOR address definitions
// -----------------------------------

typedef struct {
    volatile    uint32_t    ARM;
    volatile    uint32_t    DISARM;
    volatile    uint32_t    SENSITIVITY;
    volatile    uint32_t    LOCK;
    volatile    uint32_t    TRIG_STATUS;
    volatile    uint32_t    TRIG_FORCE;
} GLITCH_DETECTOR_TypeDef;

#ifdef __cplusplus
#define GLITCH_DETECTOR_NS  reinterpret_cast<GLITCH_DETECTOR_TypeDef *>(0x40158000U)
#define GLITCH_DETECTOR_S   reinterpret_cast<GLITCH_DETECTOR_TypeDef *>(0x40158000U)
#else
#define GLITCH_DETECTOR_NS  ((GLITCH_DETECTOR_TypeDef *)0x40158000U)
#define GLITCH_DETECTOR_S   ((GLITCH_DETECTOR_TypeDef *)0x40158000U)
#endif

// ARM Configuration

#define GLITCH_DETECTOR_ARM_ARM                     (0xFFFFU<<0)
#define GLITCH_DETECTOR_ARM_ARM_0                   (0x1U<<0)
#define GLITCH_DETECTOR_ARM_ARM_NO                  (0x5BADU<<0)
#define GLITCH_DETECTOR_ARM_ARM_YES                 (0x0U<<0)

// DISARM Configuration

#define GLITCH_DETECTOR_DISARM_DISARM               (0xFFFFU<<0)
#define GLITCH_DETECTOR_DISARM_DISARM_0             (0x1U<<0)
#define GLITCH_DETECTOR_DISARM_DISARM_NO            (0x0U<<0)
#define GLITCH_DETECTOR_DISARM_DISARM_YES           (0xDCAFU<<0)

// SENSITIVITY Configuration

#define GLITCH_DETECTOR_SENSITIVITY_DET0            (0x3U<<0)
#define GLITCH_DETECTOR_SENSITIVITY_DET0_0          (0x1U<<0)
#define GLITCH_DETECTOR_SENSITIVITY_DET1            (0x3U<<2)
#define GLITCH_DETECTOR_SENSITIVITY_DET1_0          (0x1U<<2)
#define GLITCH_DETECTOR_SENSITIVITY_DET2            (0x3U<<4)
#define GLITCH_DETECTOR_SENSITIVITY_DET2_0          (0x1U<<4)
#define GLITCH_DETECTOR_SENSITIVITY_DET3            (0x3U<<6)
#define GLITCH_DETECTOR_SENSITIVITY_DET3_0          (0x1U<<6)
#define GLITCH_DETECTOR_SENSITIVITY_DET0_INV        (0x3U<<8)
#define GLITCH_DETECTOR_SENSITIVITY_DET0_INV_0      (0x1U<<8)
#define GLITCH_DETECTOR_SENSITIVITY_DET1_INV        (0x3U<<10)
#define GLITCH_DETECTOR_SENSITIVITY_DET1_INV_0      (0x1U<<10)
#define GLITCH_DETECTOR_SENSITIVITY_DET2_INV        (0x3U<<12)
#define GLITCH_DETECTOR_SENSITIVITY_DET2_INV_0      (0x1U<<12)
#define GLITCH_DETECTOR_SENSITIVITY_DET3_INV        (0x3U<<14)
#define GLITCH_DETECTOR_SENSITIVITY_DET3_INV_0      (0x1U<<14)
#define GLITCH_DETECTOR_SENSITIVITY_DEFAULT         (0xFFU<<24)
#define GLITCH_DETECTOR_SENSITIVITY_DEFAULT_0       (0x1U<<24)
#define GLITCH_DETECTOR_SENSITIVITY_DEFAULT_YES     (0x0U<<24)
#define GLITCH_DETECTOR_SENSITIVITY_DEFAULT_NO      (0xDEU<<24)

// LOCK Configuration

#define GLITCH_DETECTOR_LOCK_LOCK                   (0xFFU<<0)
#define GLITCH_DETECTOR_LOCK_LOCK_0                 (0x1U<<0)

// TRIG_STATUS Configuration

#define GLITCH_DETECTOR_TRIG_STATUS_DET0            (0x1U<<0)
#define GLITCH_DETECTOR_TRIG_STATUS_DET1            (0x1U<<1)
#define GLITCH_DETECTOR_TRIG_STATUS_DET2            (0x1U<<2)
#define GLITCH_DETECTOR_TRIG_STATUS_DET3            (0x1U<<3)

// TRIG_FORCE Configuration

#define GLITCH_DETECTOR_TRIG_FORCE_TRIG_FORCE       (0xFU<<0)
#define GLITCH_DETECTOR_TRIG_FORCE_TRIG_FORCE_0     (0x1U<<0)
