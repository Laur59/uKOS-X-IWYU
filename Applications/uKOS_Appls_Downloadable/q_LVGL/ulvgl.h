/*
; ulvgl.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:   Laurent von Allmen      The 2026-02-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     Wrapper for LVGL header file
;           Suppress clang warnings.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
;------------------------------------------------------------------------
*/

#ifdef  __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wimplicit-int-conversion"
#endif

#include    "lvgl.h"

#ifdef  __clang__
#pragma clang diagnostic pop
#endif
