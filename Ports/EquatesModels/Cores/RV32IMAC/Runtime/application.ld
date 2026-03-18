/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:     Commun Linker description for uKOS-X applications.
 *           User only support
 *
 *                   CODE
 * linker_stTEXT     +-----------------+
 *                   |                 |
 *                   | .header         |
 *                   | .text           |
 *                   | .ctor           |
 *                   | .dtor           |
 * linker_enCTOR     |                 |
 * linker_enDTOR     |                 |
 * linker_enTEXT     |                 |
 * linker_stRODATA   +-----------------+
 *                   |                 |
 *                   | .rodata         |
 * linker_enRODATA   |                 |
 * linker_stDATA     +-----------------+
 *                   |                 |
 *                   | .data           |
 * linker_enDATA     |                 |
 * linker_stBSS      +-----------------+
 *                   |                 |
 *                   | .bss            |
 * linker_enBSS      | COMMON          |
 *                   |                 |
 * _end              +-----------------+
 */

_lnApplication  = (linker_enDATA - linker_stTEXT);  /* Length of the application    */

SECTIONS {
    .text : {
        linker_stTEXT = ABSOLUTE(.);
        KEEP(*(.header))
        *(.text .text.*)
        linker_enTEXT = ABSOLUTE(.);

        _stCTOR = ABSOLUTE(.);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array))
        linker_enCTOR = ABSOLUTE(.);

        _stDTOR = ABSOLUTE(.);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array))
        linker_enDTOR = ABSOLUTE(.);
    } > prgm_code

    .init_array : {
        . = ALIGN(8);
        *(.init_array .init_array.*)
    } > prgm_code

    .rodata : {
        . = ALIGN(8);
        linker_stRODATA = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        . = ALIGN(8);
        linker_enRODATA = ABSOLUTE(.);
    } > prgm_code

    .data : {
        . = ALIGN(8);
        linker_stDATA = ABSOLUTE(.);
        *(.rdata)
        *(.sdata .sdata.*)
        *(.data .data.*)
        . = ALIGN(8);
        KEEP(*(.eh_frame))
        linker_enDATA = ABSOLUTE(.);
    } > prgm_code

    .bss : {
        . = ALIGN(8);
        linker_stBSS = ABSOLUTE(.);
        KEEP(*(.user))
        _bss = ABSOLUTE(.);
        *(.sbss*)
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(8);
        linker_enBSS = ABSOLUTE(.);
    } > prgm_data

}
