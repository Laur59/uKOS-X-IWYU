/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Commun Linker description for uKOS-X systems.
 *           Privileged only support
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
 *                       +-----------------+ ........... +-----------------+ linker_stDATA
 * linker_stINDATA       |                 |             |                 |
 *                       | .data           |             | .data           |
 *                       |                 |             |                 | linker_enDATA
 *                       +-----------------+ ........... +-----------------+
 *                                                       |                 | linker_stBSS
 *                                                       | .bss            |
 *                                                       | COMMON          |
 *                                                       |                 | linker_enBSS
 *                                                       +-----------------+
 */

SECTIONS {
    .text : {
        linker_stCODE = ABSOLUTE(.);
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.isr_vector))
        linker_enVECTORS = ABSOLUTE(.);

        linker_stTEXT = ABSOLUTE(.);
        linker_stTEXT_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.text .text.*)
        linker_enTEXT_KERN_p = ABSOLUTE(.);
        *(.text .text.*)
        . = ALIGN(4);
        linker_enTEXT = ABSOLUTE(.);
    } > prgm_code

    .directory : {
        . = ALIGN(4);
        linker_stDirectory = ABSOLUTE(.);
        KEEP(*(.directory))
        LONG(0x00000000)
        LONG(0x00000000)
        . = ALIGN(4);
        linker_enDirectory = ABSOLUTE(.);
    } > prgm_code

    .init_array : {
        . = ALIGN(4);
        linker_stInitArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
        KEEP(*(.init_array))
        . = ALIGN(4);
        linker_enInitArray = ABSOLUTE(.);
    } > prgm_code

    .fini_array : {
        . = ALIGN(4);
        linker_stFiniArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
        KEEP(*(.fini_array))
        . = ALIGN(4);
        linker_enFiniArray = ABSOLUTE(.);
    } > prgm_code

    .ARM.extab : {
        . = ALIGN(4);
        *(.ARM.extab*)
    } > prgm_code

    .ARM.exidx : {
        . = ALIGN(4);
        __exidx_start = ABSOLUTE(.);
        *(.ARM.exidx*)
        __exidx_end = ABSOLUTE(.);
    } > prgm_code

    .rodata : {
        . = ALIGN(4);
        linker_stRODATA = ABSOLUTE(.);
        linker_stRODATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.rodata .rodata.*)
        linker_enRODATA_KERN_p = ABSOLUTE(.);
        *(.rodata .rodata.*)
        . = ALIGN(4);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    .widget : {
        . = ALIGN(4);
        linker_stWIDGET = ABSOLUTE(.);
        KEEP(*(.widget))
        . = ALIGN(4);
        linker_enWIDGET = ABSOLUTE(.);
    } > prgm_code

    .signature : {
        . = ALIGN(4);
        linker_stSignature = ABSOLUTE(.);
        KEEP(*(.signature))
        . = ALIGN(4);
        linker_enCODE = ABSOLUTE(.);
    } > prgm_code

    . = ALIGN(4);
    linker_stINDATA = ABSOLUTE(.);

    .data : AT (linker_stINDATA) {
        . = ALIGN(4);
        linker_stDATA = ABSOLUTE(.);
        linker_stDATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.data .data.*)
        linker_enDATA_KERN_p = ABSOLUTE(.);
        *(.data .data.*)
        *(.tdata .tdata.*)
        . = ALIGN(4);
        *(vtable)
        . = ALIGN(4);
        linker_enDATA = ABSOLUTE(.);
    } > prgm_data

    .bss (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS = ABSOLUTE(.);
        KEEP(*(.user))
        linker_stBSS_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.bss .bss.*)
        linker_enBSS_KERN_p = ABSOLUTE(.);
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        linker_enBSS = ABSOLUTE(.);
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
