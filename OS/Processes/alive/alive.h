/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     alive process; blink a LED.
 */

#pragma once

#include    <stdint.h>

#include    "led/led.h"

#define KLED_ALIVE          KLED_0
#define KTIME_ALIVE_ON      50U
#define KTIME_ALIVE_OFF     950U

// Configuration structure
// -----------------------

typedef struct  aliveCnf    aliveCnf_t;

struct aliveCnf {
            bool        *oKillRequest;                          // Kill request
            uint32_t    oTime[2];                               // Process time
            uint8_t     oLed;                                   // Process Led
};

#if (defined(__cplusplus))
extern  "C" {
#endif

extern  void    stub_alive_process(const void *argument);

#if (defined(__cplusplus))
}
#endif
