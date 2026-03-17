/*
; syscallDispatcher.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Edo. Franzi     The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     Syscall dispatcher.
;               - uKernel messages
;               - privilege elevation
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

// svc numbers
// -----------

#define KKERN_MESSAGE           0               // uKernel (messages passing)
#define KPRIV_ELEVATION         1               // priv (privilege elevation)
