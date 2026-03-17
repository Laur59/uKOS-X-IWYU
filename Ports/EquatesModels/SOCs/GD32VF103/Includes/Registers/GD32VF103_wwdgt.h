/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
*/

/*
; GD32VF103_wwdgt.
; ================

;------------------------------------------------------------------------
; Author:   Generated using the .svd description    The 2025-01-01
; Modifs:
;
; Project:  uKOS-X
; Goal:     GD32VF103_wwdgt equates.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;------------------------------------------------------------------------
*/

#pragma once

#include    <stdint.h>

// WWDGT address definitions
// -------------------------

typedef struct {
    volatile    uint32_t    CTL;
    volatile    uint32_t    CFG;
    volatile    uint32_t    STAT;
} WWDGT_TypeDef;

#ifdef __cplusplus
#define WWDGT   reinterpret_cast<WWDGT_TypeDef *>(0x40002C00U)

#else
#define WWDGT   ((WWDGT_TypeDef *)0x40002C00U)
#endif

// CTL Configuration

#define WWDGT_CTL_CNT       (0x7FU<<0)
#define WWDGT_CTL_CNT_0     (0x1U<<0)
#define WWDGT_CTL_WDGTEN    (0x1U<<7)

// CFG Configuration

#define WWDGT_CFG_WIN       (0x7FU<<0)
#define WWDGT_CFG_WIN_0     (0x1U<<0)
#define WWDGT_CFG_PSC       (0x3U<<7)
#define WWDGT_CFG_PSC_0     (0x1U<<7)
#define WWDGT_CFG_EWIE      (0x1U<<9)

// STAT Configuration

#define WWDGT_STAT_EWIF     (0x1U<<0)
