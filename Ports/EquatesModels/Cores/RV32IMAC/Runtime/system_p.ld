/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; system_p.
; =========

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;    Commun Linker description for uKOS-X systems.
;    Privileged only support
;
;                       CODE
; linker_stTEXT         +-----------------+
;                       |                 |
;                       | .restart        |
;                       | .vectors        |
;                       | .text           |
;                       | .rodata         |
; linker_enRODATA       |                 |
;                       +-----------------+
; linker_stSignature    |                 |             DATA
;                       +-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA       |                 |             |                 |
;                       | .data           |             | .data           |
;                       |                 |             |                 | linker_enDATA
;                       +-----------------+ ........... +-----------------+
;                                                       |                 | linker_stBSS
;                                                       | .bss            |
;                                                       | COMMON          |
;                                                       |                 | linker_enBSS
;                                                       +-----------------+
;------------------------------------------------------------------------
*/

SECTIONS {
    .text : {
        KEEP(*(.restart))
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.vectors))
        linker_enVECTORS = ABSOLUTE(.);

        linker_stTEXT = ABSOLUTE(.);
        linker_stTEXT_KERN_p = ABSOLUTE(.);
        libkern_p.a(.text .text.* .text*)
        linker_enTEXT_KERN_p = ABSOLUTE(.);
        *(.text .text.*)
        linker_enTEXT = ABSOLUTE(.);
    } > prgm_code

    .directory : {
        linker_stDirectory = ABSOLUTE(.);
        KEEP(*(.directory))
        LONG(0x00000000)
        LONG(0x00000000)
    } > prgm_code

    .init_array : {
        . = ALIGN(8);
        linker_stInitArray = ABSOLUTE(.);
        KEEP(*(.init .init.* .init*))
        linker_enInitArray = ABSOLUTE(.);
    } > prgm_code

    .fini_array : {
        . = ALIGN(8);
        linker_stFiniArray = ABSOLUTE(.);
        KEEP(*(.fini .fini.* .fini*))
        linker_enFiniArray = ABSOLUTE(.);
    } > prgm_code

    .rodata : {
        . = ALIGN(8);
        linker_stRODATA = ABSOLUTE(.);
        linker_stRODATA_KERN_p = ABSOLUTE(.);
        libkern_p.a(.rodata .rodata.* .rodata*)
        linker_enRODATA_KERN_p = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        . = ALIGN(8);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    . = ALIGN(8);
    linker_stINDATA = ABSOLUTE(.);
    .data : AT (linker_stINDATA) {
        linker_stDATA = ABSOLUTE(.);
        linker_stDATA_KERN_p = ABSOLUTE(.);
        libkern_p.a(.data .data.* .data*)
        linker_enDATA_KERN_p = ABSOLUTE(.);
        *(.rdata)
        *(.sdata .sdata.*)
        *(.data .data.*)
        . = ALIGN(8);
        KEEP(*(.eh_frame))
        linker_enDATA = ABSOLUTE(.);
    } > prgm_data

    .signature (linker_enRODATA + (linker_enDATA - linker_stDATA)) : {
        . = ALIGN(8);
        linker_stSignature = ABSOLUTE(.);
        KEEP(*(.signature))
    } > prgm_code

    .bss (NOLOAD) : {
        . = ALIGN(8);
        linker_stBSS = ABSOLUTE(.);
        KEEP(*(.user))
        linker_stBSS_KERN_p = ABSOLUTE(.);
        libkern_p.a(.bss .bss.* COMMON)
        linker_enBSS_KERN_p = ABSOLUTE(.);
        *(.sbss*)
        *(.bss .bss.*)
        *(COMMON)
        linker_enBSS = ABSOLUTE(.);
        /* Standard symbol used by C library for heap start */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data

    /* Thread-local storage BSS section - treated as regular BSS for bare-metal */
    .tbss (NOLOAD) : {
        linker_stTBSS = ABSOLUTE(.);
        *(.tbss .tbss.*)
        linker_enTBSS = ABSOLUTE(.);
        /* Standard symbol used by C library for heap start */
        /* Placed after .tbss so heap doesn't overlap with TLS data */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data

}
