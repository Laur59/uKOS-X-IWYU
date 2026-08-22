/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Pico2_rp2350 – Linker memory regions, privileged/user mode.
 *
 *                       CODE
 * linker_stTEXT         +-----------------+
 *                       |                 |
 *                       | .isr_vector     |
 *                       | .text           |
 *                       | .rodata         |
 * linker_enRODATA       |                 |
 *                       +-----------------+
 * linker_stSignature    |                 |             DATA
 *                       +-----------------+ ........... +-----------------+ linker_stDATA_p
 * linker_stINDATA_p     |                 |             |                 |
 *                       | .data_p         |             | .data_p         |
 *                       |                 |             |                 | linker_enDATA_p
 * linker_stINDATA_u     |                 |             |                 | linker_stDATA_u
 *                       | .data_u         |             | .data_u         |
 *                       |                 |             |                 | linker_enDATA_u
 *                       +-----------------+ ........... +-----------------+
 *                                                       |                 | linker_stBSS_p
 *                                                       | .bss_p          |
 *                                                       | COMMON          |
 *                                                       |                 | linker_enBSS_p
 *                                                       |                 | linker_stBSS_u
 *                                                       | .bss_u          |
 *                                                       |                 | linker_enBSS_u
 *                                                       +-----------------+
 */

ENTRY(Reset_C0_Handler)

INCLUDE     rp2350.ld

/* Mapping:                                                 */
/*                                                          */
/* SRAM:     Stack System        0x20000000  (Protected)    */
/*            └ 8K                                          */
/*           Program Data        0x20002000  (Protected)    */
/*            └ 88K                                         */
/*           Stack First         0x20018000  (User)         */
/*            └ 4K                                          */
/*           Program Data        0x20019000  (User)         */
/*            └ 92K                                         */
/*           Heap                0x20030000  (User)         */
/*            └ 128K                                        */
/*           User Memory         0x20050000  (User)         */
/*            └ 136K                                        */
/*           Share               0x20072000  (User)         */
/*            └ 64K                                         */

linker_sizeStackSystem_C0   = (4K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                         /* Length of the First stack                                */
linker_sizeStackSystem_C1   = (4K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C1    = (2K);                                                         /* Length of the First stack                                */
config_sizeData_p           = (88K);
config_sizeData_u           = (92K);
config_sizeHeap             = (128K);
config_sizeUserMemory       = (136K);
config_sizeShare            = (64K);

/* IMPORTANT:                                               */
/* all the stacks have to be maintained aligned             */
/* on a boundary of 8-bytes                                 */

linker_lowStackSystem_C0    = rp_stSRAM;                                                    /* 0x20000000: start of the System stack                    */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;     /* 0x20000ff8                                               */

linker_lowStackSystem_C1    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x20001000: start of the System stack                    */
linker_topStackSystem_C1    = linker_lowStackSystem_C1 + linker_sizeStackSystem_C1 - 8;     /* 0x20001ff8                                               */

linker_lowStackFirst_C0     = linker_lowStackSystem_C1 + linker_sizeStackSystem_C1
                                + config_sizeData_p;                                        /* 0x20018000: start of the First stack                     */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;       /* 0x200107f8                                               */

linker_lowStackFirst_C1     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x20018800: start of the First stack                     */
linker_topStackFirst_C1     = linker_lowStackFirst_C1 + linker_sizeStackFirst_C1 - 8;       /* 0x20018FF8                                               */

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_lowStackSystem_C1 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_topStackSystem_C1 & 7) == 0, "Stack system must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C1 & 7)  == 0, "Stack user must be 8-byte aligned")
ASSERT((linker_topStackFirst_C1 & 7)  == 0, "Stack user must be 8-byte aligned")

/* IMPORTANT:                                               */
/* External memory, User (download application) and shared  */

linker_stEXRAM              = 0;                                                            /* 0x00000000: EXRAM, start of the external memory          */
linker_lnEXRAM              = (0);                                                          /* Length of the external memory                            */

linker_stUMemo              = (linker_stHeap + linker_lnHeap);                              /* 0x20050000: UMemo, start of the user memory              */
linker_lnUMemo              = config_sizeUserMemory;                                        /* 0x00022000: Length of the user memory                    */

linker_stShare              = (linker_stUMemo + linker_lnUMemo);                            /* 0x20072000: Share, start of the multicore shared memory  */
linker_lnShare              = config_sizeShare;                                             /* 0x00010000: Length of the user multicore shared memory   */

/* IMPORTANT:                                               */
/* The heap has to be maintained aligned                    */
/* on a boundary of 8-bytes                                 */

linker_stHeap               = (linker_stPrgmData_u + linker_lnPrgmData_u);                  /* 0x20030000: start of the heap                            */
linker_lnHeap               = config_sizeHeap;                                              /* 0x00020000: Length of the heap                           */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = rp_stINTFLASH;                                                /* 0x10000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = rp_lnINTFLASH;                                                /* 0x00400000: Length of the the Flash                      */

linker_stPrgmData_p         = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0
                                + linker_sizeStackSystem_C1;                                /* 0x20002000: start of protected program data              */
linker_lnPrgmData_p         = config_sizeData_p;                                            /* 0x00016000: (88K) Length of protected program data       */

linker_stPrgmData_u         = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0
                                + linker_sizeStackFirst_C1;                                 /* 0x20019000: start of unprotected program data            */
linker_lnPrgmData_u         = config_sizeData_u;                                            /* 0x00017000: (92k) Length of unprotected program data */

/* IMPORTANT:                                               */
/* equates necessary for the arm_v8 MPU regions             */
/* for the arm_v8 MPU the regions have to be 32-B aligned   */

linker_ST_FLASH_INT_0       = rp_stINTFLASH;                                                /* 0x10000000: Privileged/User FLASH                        */
linker_EN_FLASH_INT_0       = (rp_stINTFLASH + rp_lnINTFLASH - 1);                          /* 0x103FFFFF: 4-M                                          */

linker_ST_RAM_INT_0_OS      = rp_stSRAM;                                                    /* 0x20000000: Privileged RAM                               */
linker_EN_RAM_INT_0_OS      = (rp_stSRAM + config_sizeData_p + linker_sizeStackSystem_C0
                                + linker_sizeStackSystem_C1 - 1);                           /* 0x2000FFFF: 64-K                                         */

linker_ST_RAM_INT_0         = (linker_lowStackFirst_C0);                                    /* 0x20010000: Privileged/User RAM                          */
local_sizeRAM_INT_0         = config_sizeData_u + linker_sizeStackFirst_C0 + linker_sizeStackFirst_C1
                                + config_sizeHeap + config_sizeUserMemory;
linker_EN_RAM_INT_0         = (linker_lowStackFirst_C0 + local_sizeRAM_INT_0 - 1);          /* 0x20071FFF: 392-K                                        */

linker_ST_RAM_INT_0_SHARED  = linker_stShare;                                               /* 0x20072000: Privileged/User RAM                          */
linker_EN_RAM_INT_0_SHARED  = (linker_stShare + config_sizeShare - 1);                      /* 0x20081FFF: 64-K                                         */

linker_ST_PERIPH_SOC        = rp_stPERIPH_NS;                                               /* 0x40000000: Privileged PERIPHERALS                       */
linker_EN_PERIPH_SOC        = (rp_stPERIPH_NS + 524288K - 1);                               /* 0x5FFFFFFF: 2 x 256-M (_S & _NS)                         */

linker_ST_EXTERNAL          = rp_stEXTERNAL;                                                /* 0x60000000: EXTERNAL                                     */
linker_EN_EXTERNAL          = (rp_stEXTERNAL + 2097152K - 1);                               /* 0xDFFFFFFF: 1 x 2048-M (_S & _NS)                        */

linker_ST_PERIPH_CORE       = rp_stCORE;                                                    /* 0xE0000000: Privileged core PERIPHERALS                  */
linker_EN_PERIPH_CORE       = (rp_stCORE + 262144K - 1);                                    /* 0xEFFFFFFF: 256-M                                        */

MEMORY {
    prgm_code (rx)      : ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
    prgm_data_p (rwx)   : ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
    prgm_data_u (rwx)   : ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

ASSERT((linker_stPrgmData_p) >= (linker_ST_RAM_INT_0_OS), "Start address of data outside (below) protected region")
ASSERT((linker_stPrgmData_p) < (linker_EN_RAM_INT_0_OS), "Start address of data outside (above) protected region")
ASSERT((linker_stPrgmData_p + linker_lnPrgmData_p - 1) <= (linker_EN_RAM_INT_0_OS), "End address of data outside protected region")

INCLUDE     system_pu.ld
