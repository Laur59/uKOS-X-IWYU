/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     addendum equates.
 */

#pragma once

// Unique device ID register base address
// --------------------------------------

#define UID_BASE                        0x1FF1E800U

// rtc additional definitions
// --------------------------

#define RTC_WPR_UNLOCK_KEY1             0x000000CAU
#define RTC_WPR_UNLOCK_KEY2             0x00000053U
#define RTC_WPR_LOCK_KEY                0x000000FFU

// iwdg additional definitions
// ---------------------------

// KR Configuration

#define IWDG_KR_DISABLE                 0x5555U
#define IWDG_KR_START                   0xCCCCU
#define IWDG_KR_RELOAD                  0xAAAAU

// PR Configuration

#define IWDG_PR_1_4                     0x0000U
#define IWDG_PR_1_8                     0x0001U
#define IWDG_PR_1_16                    0x0002U
#define IWDG_PR_1_32                    0x0003U
#define IWDG_PR_1_64                    0x0004U
#define IWDG_PR_1_128                   0x0005U
#define IWDG_PR_1_256                   0x0006U

// i2c additional definitions
// --------------------------

// CR2 Configuration

#define I2C_CR2_SADD_0                  (0x1U<<0U)
