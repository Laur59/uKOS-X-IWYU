/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Edo. Franzi     The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     Low level init interface for target-specific initialization.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#ifdef __cplusplus
extern  "C" {
#endif

void    init_init(void);

#ifdef __cplusplus
}
#endif
