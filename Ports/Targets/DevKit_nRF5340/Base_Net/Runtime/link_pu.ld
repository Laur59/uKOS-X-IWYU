/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; link_pu.
; ========

;------------------------------------------------------------------------
; Project:  uKOS-X
; Goal:     Linker description for the uKOS-X system.
;           Privileged / user support
;
;                       CODE
; linker_stTEXT         +-----------------+
;                       |                 |
;                       | .isr_vector     |
;                       | .text           |
;                       | .rodata         |
; linker_enRODATA       |                 |
;                       +-----------------+
; linker_stSignature    |                 |             DATA
;                       +-----------------+ ........... +-----------------+ linker_stDATA_p
; linker_stINDATA_p     |                 |             |                 |
;                       | .data_p         |             | .data_p         |
;                       |                 |             |                 | linker_enDATA_p
; linker_stINDATA_u     |                 |             |                 | linker_stDATA_u
;                       | .data_u         |             | .data_u         |
;                       |                 |             |                 | linker_enDATA_u
;                       +-----------------+ ........... +-----------------+
;                                                       |                 | linker_stBSS_p
;                                                       | .bss_p          |
;                                                       | COMMON          |
;                                                       |                 | linker_enBSS_p
;                                                       |                 | linker_stBSS_u
;                                                       | .bss_u          |
;                                                       |                 | linker_enBSS_u
;                                                       +-----------------+
;------------------------------------------------------------------------
*/

ENTRY(Reset_C0_Handler)

INCLUDE     nRF5340xx.ld

/* Mapping:                                                 */
/*                                                          */
/* RAM_NET: Protected           0x21000000                  */
/*            Stack System      0x21000000                  */
/*            4K                                            */
/*            Program Data (P)  0x21001000                  */
/*            20K                                           */
/*          Unprotected         0x21006000                  */
/*            Stack First       0x21006000                  */
/*            2K                                            */
/*            Program Data (U)  0x21006800                  */
/*            38K                                           */
/* RAM:     For NET cpu         0x20070000                  */
/*            Heap              0x20070000                  */
/*          32K                                             */
/*          Share               0x20078000                  */
/*          32K                                             */

linker_sizeStackSystem_C0   = (4K);                                                 /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                 /* Length of the First stack                                */
config_sizeData_p           = (20K);
config_sizeData_u           = (38K);
config_sizeHeap             = (32K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackSystem_C0    = nrf_stSRAM_NET;                                       /* 0x21000000:                                              */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;

linker_lowStackFirst_C0     = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0
                            + config_sizeData_p;                                    /* 0x21006000:                                              */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                    /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                  /* Length of the external memory                            */

linker_stUMemo              = 0;                                                    /* 0x20060000: UMemo, start of the user memory              */
linker_lnUMemo              = (0);                                                  /* Length of the user memory                                */

linker_stFoNet              = 0x20070000;                                           /* 0x20070000: Share, start of the multicore shared memory  */
linker_lnFNet               = (32K);                                                /* Length of the user multicore shared memory               */

linker_stShare              = (linker_stFoNet + linker_lnFNet);                     /* 0x20078000: Share, start of the multicore shared memory  */
linker_lnShare              = (32K);                                                /* Length of the user multicore shared memory               */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = linker_stFoNet;                                       /* 0x20070000: start of the heap                            */
linker_lnHeap               = linker_lnFNet;                                        /* Length of the heap                                       */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = nrf_stINTFLASH_NET;                                   /* 0x01000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = nrf_lnINTFLASH_NET;                                   /* Length of the the Flash                                  */

linker_stPrgmData_p         = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0; /* 0x21001000: start of protected program data              */
linker_lnPrgmData_p         = config_sizeData_p;                                    /* Length of protected program data                         */

linker_stPrgmData_u         = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;   /* 0x21006800: start of unprotected program data            */
linker_lnPrgmData_u         = config_sizeData_u;                                    /* Length of unprotected program data                       */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = nrf_stINTFLASH_NET;                                   /* 0x01000000: Privileged/User FLASH                        */
linker_EN_FLASH_INT_0       = (nrf_stINTFLASH_NET + nrf_lnINTFLASH_NET - 1);        /* 0x01040000: 256-M                                        */

linker_ST_RAM_INT_0_OS      = nrf_stSRAM_NET;                                       /* 0x21000000: Privileged RAM                               */
linker_EN_RAM_INT_0_OS      = (nrf_stSRAM_NET + 24K - 1);                           /* 0x21005FFF: 24-K                                         */

linker_ST_RAM_INT_0         = linker_stPrgmData_u;                                  /* 0x21006000: Privileged/User RAM                          */
linker_EN_RAM_INT_0         = (linker_stPrgmData_u + linker_lnPrgmData_u - 1);      /* 0x2100FFFF: 40-K                                         */

linker_ST_RAM_INT_1         = linker_stFoNet;                                       /* 0x20070000: Privileged/User RAM                          */
linker_EN_RAM_INT_1         = linker_lnFNet;                                        /* 0x20077FFF: 32-K                                         */

linker_ST_RAM_INT_1_SHARED  = linker_stShare;                                       /* 0x20078000: Privileged/User RAM                          */
linker_EN_RAM_INT_1_SHARED  = (linker_stShare + linker_lnShare - 1);                /* 0x2007FFFF: 32-K                                         */

linker_ST_PERIPH_SOC        = nrf_stPERIPH_NS;                                      /* 0x40000000: Privileged PERIPHERALS                       */
linker_EN_PERIPH_SOC        = (nrf_stPERIPH_NS + 524288K - 1);                      /* 0x5FFFFFFF: 2 x 256-M (_S & _NS)                         */

linker_ST_PERIPH_CORE       = nrf_stCORE;                                           /* 0xE0000000: Privileged core PERIPHERALS                  */
linker_EN_PERIPH_CORE       = (nrf_stCORE + 262144K - 1);                           /* 0xEFFFFFFF: 256-M                                        */

MEMORY {
    prgm_code (rx)      : ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
    prgm_data_p (rwx)   : ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
    prgm_data_u (rwx)   : ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

INCLUDE     system_pu.ld
