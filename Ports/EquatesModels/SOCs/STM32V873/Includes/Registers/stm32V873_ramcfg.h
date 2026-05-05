/*
 * SPDX-License-Identifier: MIT
 *
 * Goal:     stm32V873_ramcfg equates.
 */
#pragma once

#include    <stdint.h>

// RAMCFG address definitions
// --------------------------

typedef struct {
    volatile    uint32_t    M0CR;
    volatile    uint32_t    M0IER;
    volatile    uint32_t    M0ISR;
    volatile    uint32_t    M0SEAR;
    volatile    uint32_t    M0DEAR;
    volatile    uint32_t    M0ICR;
    volatile    uint32_t    M0ECCKEYR;
    volatile    uint32_t    M0ERKEYR;
    volatile    uint32_t    RESERVED0[8];
    volatile    uint32_t    M1CR;
    volatile    uint32_t    M1IER;
    volatile    uint32_t    M1ISR;
    volatile    uint32_t    M1SEAR;
    volatile    uint32_t    M1DEAR;
    volatile    uint32_t    M1ICR;
    volatile    uint32_t    M1ECCKEYR;
    volatile    uint32_t    RESERVED1[73];
    volatile    uint32_t    M6CR;
    volatile    uint32_t    M6IER;
    volatile    uint32_t    M6ISR;
    volatile    uint32_t    M6SEAR;
    volatile    uint32_t    M6DEAR;
    volatile    uint32_t    M6ICR;
    volatile    uint32_t    M6ECCKEYR;
    volatile    uint32_t    M6ERKEYR;
    volatile    uint32_t    M6ERRSTKEYR;
    volatile    uint32_t    RESERVED2[7];
    volatile    uint32_t    M7CR;
    volatile    uint32_t    M7IER;
    volatile    uint32_t    M7ISR;
    volatile    uint32_t    M7SEAR;
    volatile    uint32_t    M7DEAR;
    volatile    uint32_t    M7ICR;
    volatile    uint32_t    M7ECCKEYR;
} RAMCFG_TypeDef;

#if (defined(__cplusplus))
#define RAMCFG_NS   reinterpret_cast<RAMCFG_TypeDef *>(0x46027000u)
#define RAMCFG_S    reinterpret_cast<RAMCFG_TypeDef *>(0x56027000u)

#else
#define RAMCFG_NS   ((RAMCFG_TypeDef *)0x46027000u)
#define RAMCFG_S    ((RAMCFG_TypeDef *)0x56027000u)
#endif

// M0CR Configuration

#define RAMCFG_M0CR_WSC                     (0x3u<<16)
#define RAMCFG_M0CR_WSC_0                   (0x1u<<16)
#define RAMCFG_M0CR_SRAMERRST               (0x1u<<9)
#define RAMCFG_M0CR_SRAMER                  (0x1u<<8)
#define RAMCFG_M0CR_ALE                     (0x1u<<4)
#define RAMCFG_M0CR_ECCE                    (0x1u<<0)

#define RAMCFG_M0CR_WSC_B_0X0               (0x0u<<16)
#define RAMCFG_M0CR_WSC_B_0X1               (0x1u<<16)
#define RAMCFG_M0CR_SRAMERRST_B_0X0         (0x0u<<9)
#define RAMCFG_M0CR_SRAMERRST_B_0X1         (0x1u<<9)
#define RAMCFG_M0CR_SRAMER_B_0X0            (0x0u<<8)
#define RAMCFG_M0CR_SRAMER_B_0X1            (0x1u<<8)
#define RAMCFG_M0CR_ALE_B_0X0               (0x0u<<4)
#define RAMCFG_M0CR_ALE_B_0X1               (0x1u<<4)
#define RAMCFG_M0CR_ECCE_B_0X0              (0x0u<<0)
#define RAMCFG_M0CR_ECCE_B_0X1              (0x1u<<0)

// M0IER Configuration

#define RAMCFG_M0IER_ECCNMI                 (0x1u<<3)
#define RAMCFG_M0IER_DEIE                   (0x1u<<1)
#define RAMCFG_M0IER_SEIE                   (0x1u<<0)

#define RAMCFG_M0IER_ECCNMI_B_0X0           (0x0u<<3)
#define RAMCFG_M0IER_ECCNMI_B_0X1           (0x1u<<3)
#define RAMCFG_M0IER_DEIE_B_0X0             (0x0u<<1)
#define RAMCFG_M0IER_DEIE_B_0X1             (0x1u<<1)
#define RAMCFG_M0IER_SEIE_B_0X0             (0x0u<<0)
#define RAMCFG_M0IER_SEIE_B_0X1             (0x1u<<0)

// M0ISR Configuration

#define RAMCFG_M0ISR_SRAMBUSY               (0x1u<<8)
#define RAMCFG_M0ISR_DED                    (0x1u<<1)
#define RAMCFG_M0ISR_SEDC                   (0x1u<<0)

#define RAMCFG_M0ISR_SRAMBUSY_B_0X0         (0x0u<<8)
#define RAMCFG_M0ISR_SRAMBUSY_B_0X1         (0x1u<<8)
#define RAMCFG_M0ISR_DED_B_0X0              (0x0u<<1)
#define RAMCFG_M0ISR_DED_B_0X1              (0x1u<<1)
#define RAMCFG_M0ISR_SEDC_B_0X0             (0x0u<<0)
#define RAMCFG_M0ISR_SEDC_B_0X1             (0x1u<<0)

// M0SEAR Configuration

#define RAMCFG_M0SEAR_ESEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M0SEAR_ESEA_0                (0x1u<<0)

// M0DEAR Configuration

#define RAMCFG_M0DEAR_EDEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M0DEAR_EDEA_0                (0x1u<<0)

// M0ICR Configuration

#define RAMCFG_M0ICR_CDED                   (0x1u<<1)
#define RAMCFG_M0ICR_CSEDC                  (0x1u<<0)

// M0ECCKEYR Configuration

#define RAMCFG_M0ECCKEYR_ECCKEY             (0xFFu<<0)
#define RAMCFG_M0ECCKEYR_ECCKEY_0           (0x1u<<0)

// M0ERKEYR Configuration

#define RAMCFG_M0ERKEYR_ERASEKEY            (0xFFu<<0)
#define RAMCFG_M0ERKEYR_ERASEKEY_0          (0x1u<<0)

// M1CR Configuration

#define RAMCFG_M1CR_WSC                     (0x3u<<16)
#define RAMCFG_M1CR_WSC_0                   (0x1u<<16)
#define RAMCFG_M1CR_SRAMERRST               (0x1u<<9)
#define RAMCFG_M1CR_SRAMER                  (0x1u<<8)
#define RAMCFG_M1CR_ALE                     (0x1u<<4)
#define RAMCFG_M1CR_ECCE                    (0x1u<<0)

#define RAMCFG_M1CR_WSC_B_0X0               (0x0u<<16)
#define RAMCFG_M1CR_WSC_B_0X1               (0x1u<<16)
#define RAMCFG_M1CR_SRAMERRST_B_0X0         (0x0u<<9)
#define RAMCFG_M1CR_SRAMERRST_B_0X1         (0x1u<<9)
#define RAMCFG_M1CR_SRAMER_B_0X0            (0x0u<<8)
#define RAMCFG_M1CR_SRAMER_B_0X1            (0x1u<<8)
#define RAMCFG_M1CR_ALE_B_0X0               (0x0u<<4)
#define RAMCFG_M1CR_ALE_B_0X1               (0x1u<<4)
#define RAMCFG_M1CR_ECCE_B_0X0              (0x0u<<0)
#define RAMCFG_M1CR_ECCE_B_0X1              (0x1u<<0)

// M1IER Configuration

#define RAMCFG_M1IER_ECCNMI                 (0x1u<<3)
#define RAMCFG_M1IER_DEIE                   (0x1u<<1)
#define RAMCFG_M1IER_SEIE                   (0x1u<<0)

#define RAMCFG_M1IER_ECCNMI_B_0X0           (0x0u<<3)
#define RAMCFG_M1IER_ECCNMI_B_0X1           (0x1u<<3)
#define RAMCFG_M1IER_DEIE_B_0X0             (0x0u<<1)
#define RAMCFG_M1IER_DEIE_B_0X1             (0x1u<<1)
#define RAMCFG_M1IER_SEIE_B_0X0             (0x0u<<0)
#define RAMCFG_M1IER_SEIE_B_0X1             (0x1u<<0)

// M1ISR Configuration

#define RAMCFG_M1ISR_SRAMBUSY               (0x1u<<8)
#define RAMCFG_M1ISR_DED                    (0x1u<<1)
#define RAMCFG_M1ISR_SEDC                   (0x1u<<0)

#define RAMCFG_M1ISR_SRAMBUSY_B_0X0         (0x0u<<8)
#define RAMCFG_M1ISR_SRAMBUSY_B_0X1         (0x1u<<8)
#define RAMCFG_M1ISR_DED_B_0X0              (0x0u<<1)
#define RAMCFG_M1ISR_DED_B_0X1              (0x1u<<1)
#define RAMCFG_M1ISR_SEDC_B_0X0             (0x0u<<0)
#define RAMCFG_M1ISR_SEDC_B_0X1             (0x1u<<0)

// M1SEAR Configuration

#define RAMCFG_M1SEAR_ESEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M1SEAR_ESEA_0                (0x1u<<0)

// M1DEAR Configuration

#define RAMCFG_M1DEAR_EDEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M1DEAR_EDEA_0                (0x1u<<0)

// M1ICR Configuration

#define RAMCFG_M1ICR_CDED                   (0x1u<<1)
#define RAMCFG_M1ICR_CSEDC                  (0x1u<<0)

// M1ECCKEYR Configuration

#define RAMCFG_M1ECCKEYR_ECCKEY             (0xFFu<<0)
#define RAMCFG_M1ECCKEYR_ECCKEY_0           (0x1u<<0)

// M6CR Configuration

#define RAMCFG_M6CR_WSC                     (0x3u<<16)
#define RAMCFG_M6CR_WSC_0                   (0x1u<<16)
#define RAMCFG_M6CR_SRAMERRST               (0x1u<<9)
#define RAMCFG_M6CR_SRAMER                  (0x1u<<8)
#define RAMCFG_M6CR_ALE                     (0x1u<<4)
#define RAMCFG_M6CR_ECCE                    (0x1u<<0)

#define RAMCFG_M6CR_WSC_B_0X0               (0x0u<<16)
#define RAMCFG_M6CR_WSC_B_0X1               (0x1u<<16)
#define RAMCFG_M6CR_SRAMERRST_B_0X0         (0x0u<<9)
#define RAMCFG_M6CR_SRAMERRST_B_0X1         (0x1u<<9)
#define RAMCFG_M6CR_SRAMER_B_0X0            (0x0u<<8)
#define RAMCFG_M6CR_SRAMER_B_0X1            (0x1u<<8)
#define RAMCFG_M6CR_ALE_B_0X0               (0x0u<<4)
#define RAMCFG_M6CR_ALE_B_0X1               (0x1u<<4)
#define RAMCFG_M6CR_ECCE_B_0X0              (0x0u<<0)
#define RAMCFG_M6CR_ECCE_B_0X1              (0x1u<<0)

// M6IER Configuration

#define RAMCFG_M6IER_ECCNMI                 (0x1u<<3)
#define RAMCFG_M6IER_DEIE                   (0x1u<<1)
#define RAMCFG_M6IER_SEIE                   (0x1u<<0)

#define RAMCFG_M6IER_ECCNMI_B_0X0           (0x0u<<3)
#define RAMCFG_M6IER_ECCNMI_B_0X1           (0x1u<<3)
#define RAMCFG_M6IER_DEIE_B_0X0             (0x0u<<1)
#define RAMCFG_M6IER_DEIE_B_0X1             (0x1u<<1)
#define RAMCFG_M6IER_SEIE_B_0X0             (0x0u<<0)
#define RAMCFG_M6IER_SEIE_B_0X1             (0x1u<<0)

// M6ISR Configuration

#define RAMCFG_M6ISR_SRAMBUSY               (0x1u<<8)
#define RAMCFG_M6ISR_DED                    (0x1u<<1)
#define RAMCFG_M6ISR_SEDC                   (0x1u<<0)

#define RAMCFG_M6ISR_SRAMBUSY_B_0X0         (0x0u<<8)
#define RAMCFG_M6ISR_SRAMBUSY_B_0X1         (0x1u<<8)
#define RAMCFG_M6ISR_DED_B_0X0              (0x0u<<1)
#define RAMCFG_M6ISR_DED_B_0X1              (0x1u<<1)
#define RAMCFG_M6ISR_SEDC_B_0X0             (0x0u<<0)
#define RAMCFG_M6ISR_SEDC_B_0X1             (0x1u<<0)

// M6SEAR Configuration

#define RAMCFG_M6SEAR_ESEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M6SEAR_ESEA_0                (0x1u<<0)

// M6DEAR Configuration

#define RAMCFG_M6DEAR_EDEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M6DEAR_EDEA_0                (0x1u<<0)

// M6ICR Configuration

#define RAMCFG_M6ICR_CDED                   (0x1u<<1)
#define RAMCFG_M6ICR_CSEDC                  (0x1u<<0)

// M6ECCKEYR Configuration

#define RAMCFG_M6ECCKEYR_ECCKEY             (0xFFu<<0)
#define RAMCFG_M6ECCKEYR_ECCKEY_0           (0x1u<<0)

// M6ERKEYR Configuration

#define RAMCFG_M6ERKEYR_ERASEKEY            (0xFFu<<0)
#define RAMCFG_M6ERKEYR_ERASEKEY_0          (0x1u<<0)

// M6ERRSTKEYR Configuration

#define RAMCFG_M6ERRSTKEYR_ERASERSTKEY      (0xFFu<<0)
#define RAMCFG_M6ERRSTKEYR_ERASERSTKEY_0    (0x1u<<0)

// M7CR Configuration

#define RAMCFG_M7CR_WSC                     (0x3u<<16)
#define RAMCFG_M7CR_WSC_0                   (0x1u<<16)
#define RAMCFG_M7CR_SRAMERRST               (0x1u<<9)
#define RAMCFG_M7CR_SRAMER                  (0x1u<<8)
#define RAMCFG_M7CR_ALE                     (0x1u<<4)
#define RAMCFG_M7CR_ECCE                    (0x1u<<0)

#define RAMCFG_M7CR_WSC_B_0X0               (0x0u<<16)
#define RAMCFG_M7CR_WSC_B_0X1               (0x1u<<16)
#define RAMCFG_M7CR_SRAMERRST_B_0X0         (0x0u<<9)
#define RAMCFG_M7CR_SRAMERRST_B_0X1         (0x1u<<9)
#define RAMCFG_M7CR_SRAMER_B_0X0            (0x0u<<8)
#define RAMCFG_M7CR_SRAMER_B_0X1            (0x1u<<8)
#define RAMCFG_M7CR_ALE_B_0X0               (0x0u<<4)
#define RAMCFG_M7CR_ALE_B_0X1               (0x1u<<4)
#define RAMCFG_M7CR_ECCE_B_0X0              (0x0u<<0)
#define RAMCFG_M7CR_ECCE_B_0X1              (0x1u<<0)

// M7IER Configuration

#define RAMCFG_M7IER_ECCNMI                 (0x1u<<3)
#define RAMCFG_M7IER_DEIE                   (0x1u<<1)
#define RAMCFG_M7IER_SEIE                   (0x1u<<0)

#define RAMCFG_M7IER_ECCNMI_B_0X0           (0x0u<<3)
#define RAMCFG_M7IER_ECCNMI_B_0X1           (0x1u<<3)
#define RAMCFG_M7IER_DEIE_B_0X0             (0x0u<<1)
#define RAMCFG_M7IER_DEIE_B_0X1             (0x1u<<1)
#define RAMCFG_M7IER_SEIE_B_0X0             (0x0u<<0)
#define RAMCFG_M7IER_SEIE_B_0X1             (0x1u<<0)

// M7ISR Configuration

#define RAMCFG_M7ISR_SRAMBUSY               (0x1u<<8)
#define RAMCFG_M7ISR_DED                    (0x1u<<1)
#define RAMCFG_M7ISR_SEDC                   (0x1u<<0)

#define RAMCFG_M7ISR_SRAMBUSY_B_0X0         (0x0u<<8)
#define RAMCFG_M7ISR_SRAMBUSY_B_0X1         (0x1u<<8)
#define RAMCFG_M7ISR_DED_B_0X0              (0x0u<<1)
#define RAMCFG_M7ISR_DED_B_0X1              (0x1u<<1)
#define RAMCFG_M7ISR_SEDC_B_0X0             (0x0u<<0)
#define RAMCFG_M7ISR_SEDC_B_0X1             (0x1u<<0)

// M7SEAR Configuration

#define RAMCFG_M7SEAR_ESEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M7SEAR_ESEA_0                (0x1u<<0)

// M7DEAR Configuration

#define RAMCFG_M7DEAR_EDEA                  (0xFFFFFFFFu<<0)
#define RAMCFG_M7DEAR_EDEA_0                (0x1u<<0)

// M7ICR Configuration

#define RAMCFG_M7ICR_CDED                   (0x1u<<1)
#define RAMCFG_M7ICR_CSEDC                  (0x1u<<0)

// M7ECCKEYR Configuration

#define RAMCFG_M7ECCKEYR_ECCKEY             (0xFFu<<0)
#define RAMCFG_M7ECCKEYR_ECCKEY_0           (0x1u<<0)
