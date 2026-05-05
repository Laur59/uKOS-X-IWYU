/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * Goal:     Common Linker description for uKOS-X systems.
 *           Privileged / user support
 *
 *                       CODE
 * linker_stTEXT         +-----------------+
 *                       |                 |
 *                       | .isr_vector     |
 *                       | .text           |
 *                       | .rodata         |
 * linker_enRODATA       |                 |
 *                       +-----------------+
 * linker_stSignature    |                 |
 *                       +-----------------+
 * linker_stINDATA_p     |                 |             DATA
 *                       | .data_p (init)  | ........... +-----------------+ linker_stDATA_p
 *                       |                 |             | .data_p         |
 * linker_stINDATA_u     |                 |             |                 | linker_enDATA_p
 *                       | .data_u (init)  | ........... +-----------------+ linker_stDATA_u
 *                       |                 |             | .data_u         |
 * linker_enCODE         |                 |             |                 | linker_enDATA_u
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

SECTIONS {
    . = ORIGIN(prgm_code);

    .vectors ALIGN(512) : {
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.isr_vector))
        linker_enVECTORS = ABSOLUTE(.);
    } > prgm_code

    .picobin_block ALIGN(8) : {
        KEEP(*(.picobin_block))
    } > prgm_code

    .text : {
        linker_stCODE = ABSOLUTE(.);
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
    linker_stINDATA_p = ABSOLUTE(.);

    .data_p : AT (linker_stINDATA_p) {
        . = ALIGN(4);
        linker_stDATA_p = ABSOLUTE(.);
        linker_stDATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.data .data.*)
        linker_enDATA_KERN_p = ABSOLUTE(.);
        lib*_p.a:*(.data .data.*)
        . = ALIGN(4);
        linker_enDATA_p = ABSOLUTE(.);
    } > prgm_data_p

    .bss_p (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS_p = ABSOLUTE(.);
        KEEP(*(.privileged))
        linker_stBSS_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.bss .bss.*)
        linker_enBSS_KERN_p = ABSOLUTE(.);
        lib*_p.a:*(.bss .bss.*)
        . = ALIGN(4);
        linker_enBSS_p = ABSOLUTE(.);
    } > prgm_data_p AT> prgm_data_p

    linker_stINDATA_u = LOADADDR(.data_p) + SIZEOF(.data_p);

    .data_u : AT (linker_stINDATA_u) {
        . = ALIGN(4);
        linker_stDATA_u = ABSOLUTE(.);
        *(EXCLUDE_FILE (lib*_p.a:*) .data .data.*)
        *(.tdata .tdata.*)
        . = ALIGN(4);
        *(vtable)
        . = ALIGN(4);
        linker_enDATA_u = ABSOLUTE(.);
    } > prgm_data_u

    .bss_u (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS_u = ABSOLUTE(.);
        KEEP(*(.user))
        *(EXCLUDE_FILE (lib*_p.a:*) .bss .bss.*)

/* COMMON cannot be split reliably between _p and _u here. */

        *(COMMON)
        . = ALIGN(4);
        linker_enBSS_u = ABSOLUTE(.);
    } > prgm_data_u AT> prgm_data_u

    /* Thread-local storage BSS section - treated as regular BSS for bare-metal */
    .tbss (NOLOAD) : {
        linker_stTBSS = ABSOLUTE(.);
        *(.tbss .tbss.*)
        linker_enTBSS = ABSOLUTE(.);
        /* Standard symbol used by C library for heap start */
        /* Placed after .tbss so heap doesn't overlap with TLS data */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data_u

/* Fail if some BSS/DATA still escape into orphan sections */

    .orphans_check (NOLOAD) : {
        *(.bss)
        *(.bss.*)
        *(.gnu.linkonce.b.*)
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d.*)
    } > prgm_data_u

    ASSERT(SIZEOF(.orphans_check) == 0, "Unexpected orphan .bss/.data sections: _p/_u split is incomplete")
}
