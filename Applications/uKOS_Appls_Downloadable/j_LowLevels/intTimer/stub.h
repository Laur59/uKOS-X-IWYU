/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Contract between the intTimer application and its board specific stubs.
 */

#pragma once

#include    <stdint.h>

// Provided by the board stub, used by the application

extern  void    stub_intr_timer_init(void);

// Provided by the application, used by the board stub

extern  volatile    uint32_t    vTimer;
extern  void    aTimer_callBack(void);
