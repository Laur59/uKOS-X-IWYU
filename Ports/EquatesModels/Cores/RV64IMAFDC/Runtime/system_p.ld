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
 *                       | .text           |
 * linker_enTEXT         |                 |
 * linker_stRODATA       +-----------------+
 *                       |                 |
 *                       | .rodata         |
 * linker_enRODATA       |                 |
 * linker_stDATA         +-----------------+
 *                       |                 |
 *                       | .data           |
 * linker_enDATA         |                 |
 *                       +-----------------+
 * linker_stSignature    |                 |
 * linker_stBSS          +-----------------+
 *                       |                 |
 *                       | .bss            |
 * linker_enBSS          | COMMON          |
 *                       |                 |
 * _end                  +-----------------+
 */

SECTIONS {
    .text : {
        INCLUDE     vectors.ld

        linker_stTEXT_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.text .text.*)
        linker_enTEXT_KERN_p = ABSOLUTE(.);
        *(.text .text.*)
        . = ALIGN(8);
        linker_enTEXT = ABSOLUTE(.);
    } > prgm_code

    .directory : {
        . = ALIGN(8);
        linker_stDirectory = ABSOLUTE(.);
        KEEP(*(.directory))
        QUAD(0x0000000000000000)
        QUAD(0x0000000000000000)
        . = ALIGN(8);
        linker_enDirectory = ABSOLUTE(.);
    } > prgm_code

    .init_array : {
        . = ALIGN(8);
        linker_stInitArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
        KEEP(*(.init_array))
        . = ALIGN(8);
        linker_enInitArray = ABSOLUTE(.);
    } > prgm_code

    .fini_array : {
        . = ALIGN(8);
        linker_stFiniArray = ABSOLUTE(.);
        KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
        KEEP(*(.fini_array))
        . = ALIGN(8);
        linker_enFiniArray = ABSOLUTE(.);
    } > prgm_code

    .rodata : {
        . = ALIGN(8);
        linker_stRODATA = ABSOLUTE(.);
        linker_stRODATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.rodata .rodata.*)
        linker_enRODATA_KERN_p = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        *(.rdata .rdata.*)
        . = ALIGN(8);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    .widget : {
        . = ALIGN(8);
        linker_stWIDGET = ABSOLUTE(.);
        KEEP(*(.widget))
        . = ALIGN(8);
        linker_enWIDGET = ABSOLUTE(.);
    } > prgm_code

    .data : {
        . = ALIGN(8);
        linker_stDATA = ABSOLUTE(.);
        linker_stDATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.data .data.*)
        linker_enDATA_KERN_p = ABSOLUTE(.);
        *(.sdata .sdata.*)
        *(.data .data.*)
        . = ALIGN(8);
        linker_enDATA = ABSOLUTE(.);
    } > prgm_code

    .signature : {
        . = ALIGN(8);
        linker_stSignature = ABSOLUTE(.);
        KEEP(*(.signature))
    } > prgm_code

    .bss : {
        . = ALIGN(8);
        linker_stBSS = ABSOLUTE(.);
        linker_stBSS_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.bss .bss.*)
        linker_enBSS_KERN_p = ABSOLUTE(.);
        *(.sbss*)
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(8);
        linker_enBSS = ABSOLUTE(.);

        /* Standard symbol used by C library for heap start */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data

}
