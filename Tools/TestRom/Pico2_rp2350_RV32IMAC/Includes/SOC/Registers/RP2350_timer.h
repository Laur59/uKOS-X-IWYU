/*
 * SPDX-License-Identifier: MIT
 * Generated using the .svd description The 2025-01-01
 *
 * Goal:        RP2350_timer equates.
 */

#pragma once

#include    <stdint.h>

// TIMER address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    TIMEHW;
    volatile    uint32_t    TIMELW;
    volatile    uint32_t    TIMEHR;
    volatile    uint32_t    TIMELR;
    volatile    uint32_t    ALARM0;
    volatile    uint32_t    ALARM1;
    volatile    uint32_t    ALARM2;
    volatile    uint32_t    ALARM3;
    volatile    uint32_t    ARMED;
    volatile    uint32_t    TIMERAWH;
    volatile    uint32_t    TIMERAWL;
    volatile    uint32_t    DBGPAUSE;
    volatile    uint32_t    PAUSE;
    volatile    uint32_t    LOCKED;
    volatile    uint32_t    SOURCE;
    volatile    uint32_t    INTR;
    volatile    uint32_t    INTE;
    volatile    uint32_t    INTF;
    volatile    uint32_t    INTS;
} TIMER_TypeDef;

#ifdef __cplusplus
#define TIMER0_NS   reinterpret_cast<TIMER_TypeDef *>(0x400B0000U)
#define TIMER0_S    reinterpret_cast<TIMER_TypeDef *>(0x400B0000U)
#define TIMER1_NS   reinterpret_cast<TIMER_TypeDef *>(0x400B8000U)
#define TIMER1_S    reinterpret_cast<TIMER_TypeDef *>(0x400B8000U)
#else
#define TIMER0_NS   ((TIMER_TypeDef *)0x400B0000U)
#define TIMER0_S    ((TIMER_TypeDef *)0x400B0000U)
#define TIMER1_NS   ((TIMER_TypeDef *)0x400B8000U)
#define TIMER1_S    ((TIMER_TypeDef *)0x400B8000U)
#endif

// TIMEHW Configuration

#define TIMER_TIMEHW_TIMEHW             (0xFFFFFFFFU<<0)
#define TIMER_TIMEHW_TIMEHW_0           (0x1U<<0)

// TIMELW Configuration

#define TIMER_TIMELW_TIMELW             (0xFFFFFFFFU<<0)
#define TIMER_TIMELW_TIMELW_0           (0x1U<<0)

// TIMEHR Configuration

#define TIMER_TIMEHR_TIMEHR             (0xFFFFFFFFU<<0)
#define TIMER_TIMEHR_TIMEHR_0           (0x1U<<0)

// TIMELR Configuration

#define TIMER_TIMELR_TIMELR             (0xFFFFFFFFU<<0)
#define TIMER_TIMELR_TIMELR_0           (0x1U<<0)

// ALARM0 Configuration

#define TIMER_ALARM0_ALARM0             (0xFFFFFFFFU<<0)
#define TIMER_ALARM0_ALARM0_0           (0x1U<<0)

// ALARM1 Configuration

#define TIMER_ALARM1_ALARM1             (0xFFFFFFFFU<<0)
#define TIMER_ALARM1_ALARM1_0           (0x1U<<0)

// ALARM2 Configuration

#define TIMER_ALARM2_ALARM2             (0xFFFFFFFFU<<0)
#define TIMER_ALARM2_ALARM2_0           (0x1U<<0)

// ALARM3 Configuration

#define TIMER_ALARM3_ALARM3             (0xFFFFFFFFU<<0)
#define TIMER_ALARM3_ALARM3_0           (0x1U<<0)

// ARMED Configuration

#define TIMER_ARMED_ARMED               (0xFU<<0)
#define TIMER_ARMED_ARMED_0             (0x1U<<0)

// TIMERAWH Configuration

#define TIMER_TIMERAWH_TIMERAWH         (0xFFFFFFFFU<<0)
#define TIMER_TIMERAWH_TIMERAWH_0       (0x1U<<0)

// TIMERAWL Configuration

#define TIMER_TIMERAWL_TIMERAWL         (0xFFFFFFFFU<<0)
#define TIMER_TIMERAWL_TIMERAWL_0       (0x1U<<0)

// DBGPAUSE Configuration

#define TIMER_DBGPAUSE_DBG0             (0x1U<<1)
#define TIMER_DBGPAUSE_DBG1             (0x1U<<2)

// PAUSE Configuration

#define TIMER_PAUSE_PAUSE               (0x1U<<0)

// LOCKED Configuration

#define TIMER_LOCKED_LOCKED             (0x1U<<0)

// SOURCE Configuration

#define TIMER_SOURCE_CLK_SYS            (0x1U<<0)
#define TIMER_SOURCE_CLK_SYS_TICK       (0x0U<<0)
#define TIMER_SOURCE_CLK_SYS_CLK_SYS    (0x1U<<0)

// INTR Configuration

#define TIMER_INTR_ALARM_0              (0x1U<<0)
#define TIMER_INTR_ALARM_1              (0x1U<<1)
#define TIMER_INTR_ALARM_2              (0x1U<<2)
#define TIMER_INTR_ALARM_3              (0x1U<<3)

// INTE Configuration

#define TIMER_INTE_ALARM_0              (0x1U<<0)
#define TIMER_INTE_ALARM_1              (0x1U<<1)
#define TIMER_INTE_ALARM_2              (0x1U<<2)
#define TIMER_INTE_ALARM_3              (0x1U<<3)

// INTF Configuration

#define TIMER_INTF_ALARM_0              (0x1U<<0)
#define TIMER_INTF_ALARM_1              (0x1U<<1)
#define TIMER_INTF_ALARM_2              (0x1U<<2)
#define TIMER_INTF_ALARM_3              (0x1U<<3)

// INTS Configuration

#define TIMER_INTS_ALARM_0              (0x1U<<0)
#define TIMER_INTS_ALARM_1              (0x1U<<1)
#define TIMER_INTS_ALARM_2              (0x1U<<2)
#define TIMER_INTS_ALARM_3              (0x1U<<3)
