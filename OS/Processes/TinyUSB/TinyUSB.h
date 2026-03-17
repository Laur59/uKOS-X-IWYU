/*
; TinyUSB.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Laurent von Allmen      The 2026-02-02
; Modifs:
;
; Project:  uKOS-X
; Goal:     "TinyUSB" management.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
;------------------------------------------------------------------------
*/

#pragma once

#ifdef __cplusplus
extern  "C" {
#endif

extern  void    stub_TinyUSB_init(void);
extern  void    stub_TinyUSB_cyclic(void);

#ifdef __cplusplus
}
#endif
