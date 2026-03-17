/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; hard.
; =====

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     hard manager.
;
;-----
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// Prototypes

extern  void    hard_onLed(uint32_t ledNb);
extern  void    hard_offLed(uint32_t ledNb);
extern  void    hard_toggleLed(uint32_t ledNb);
