/*
; cmns.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Edo. Franzi     The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     Some common routines used in many modules.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

#include    "serial/serial.h"
#include    "types.h"

#ifdef __cplusplus
extern  "C" {
#endif

void    cmns_init(void);
void    cmns_send(serialManager_t serialManager, const char_t *ascii);
void    cmns_receive(serialManager_t serialManager, char_t *data);
void    cmns_wait(uint32_t us);

#ifdef __cplusplus
}
#endif
