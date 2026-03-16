/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; soc_addendum_CM4.
; =================

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     addendum equates.
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
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

#define I2C_CR2_SADD_0                  (0x1U<<0)
