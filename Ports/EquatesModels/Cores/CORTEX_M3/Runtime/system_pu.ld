/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; system_pu.
; ==========

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;    Commun Linker description for uKOS-X systems.
;    Privileged / user support
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

SECTIONS {
	.text : {
		linker_stPRIV = ABSOLUTE(.);
		linker_stVECTORS = ABSOLUTE(.);
		KEEP(*(.isr_vector))
		linker_enVECTORS = ABSOLUTE(.);

		linker_stTEXT = ABSOLUTE(.);
		lib*_p.a(.text .text.* .text*)
		linker_stTEXT_KERN_p = ABSOLUTE(.);
		libkern_p.a(.text .text.* .text*)
		linker_enTEXT_KERN_p = ABSOLUTE(.);
		linker_enPRIV = ABSOLUTE(.);
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
		. = ALIGN(4);
		linker_stInitArray = ABSOLUTE(.);
		KEEP(*(.init .init.* .init*))
		linker_enInitArray = ABSOLUTE(.);
	} > prgm_code

	.fini_array : {
		. = ALIGN(4);
		linker_stFiniArray = ABSOLUTE(.);
		KEEP(*(.fini .fini.* .fini*))
		linker_enFiniArray = ABSOLUTE(.);
	} > prgm_code

	/* New dedicated sections for ARM exception handling */
	.ARM.extab : {
		*(.ARM.extab*)
	} > prgm_code

	.ARM.exidx : {
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} > prgm_code

	.rodata : {
		. = ALIGN(4);
		linker_stRODATA = ABSOLUTE(.);
		linker_stRODATA_KERN_p = ABSOLUTE(.);
		libkern_p.a(.rodata .rodata.* .rodata*)
		linker_enRODATA_KERN_p = ABSOLUTE(.);
		*(.rodata .rodata.*)
		. = ALIGN(4);
		linker_enRODATA = ABSOLUTE(.);
	} > prgm_code

	. = ALIGN(4);
	linker_stINDATA_p = ABSOLUTE(.);
	.data_p : AT (linker_stINDATA_p) {
		linker_stDATA_p = ABSOLUTE(.);
		lib*_p.a(.data .data.* .data*)
		linker_stDATA_KERN_p = ABSOLUTE(.);
		libkern_p.a(.data .data.* .data*)
		linker_enDATA_KERN_p = ABSOLUTE(.);
		linker_enDATA_p = ABSOLUTE(.);
	} > prgm_data_p

	.bss_p (NOLOAD) : {
		. = ALIGN(4);
		linker_stBSS_p = ABSOLUTE(.);
		KEEP(*(.privileged))
		lib*_p.a(.bss .bss.* COMMON)
		linker_stBSS_KERN_p = ABSOLUTE(.);
		libkern_p.a(.bss .bss.* COMMON)
		linker_enBSS_KERN_p = ABSOLUTE(.);
		linker_enBSS_p = ABSOLUTE(.);
	} > prgm_data_p

	linker_stINDATA_u = linker_stINDATA_p + SIZEOF(.data_p);
    . = ALIGN(4);
	.data_u : AT (linker_stINDATA_u) {
		linker_stDATA_u = ABSOLUTE(.);
		liblibx_u.a(.data .data.* .data*)
		libproc_u.a(.data .data.* .data*)
		libtool_u.a(.data .data.* .data*)
		*(EXCLUDE_FILE (first.o* *librtcb_p.a *libkern_p.a *liblibx_p.a *libshar_p.a) .data .data.* .data*)
		. = ALIGN(4);
		*(vtable)
		. = ALIGN(4);
		KEEP(*(.eh_frame))
		linker_enDATA_u = ABSOLUTE(.);
	} > prgm_data_u

	. = ALIGN(4);
    .signature (linker_enRODATA + (linker_enDATA_p - linker_stDATA_p) + (linker_enDATA_u - linker_stDATA_u)) : {
        linker_stSignature = ABSOLUTE(.);
        KEEP(*(.signature))
    } > prgm_code

    .bss_u (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS_u = ABSOLUTE(.);
        KEEP(*(.user))
        liblibx_u.a(.bss .bss.* COMMON)
        libproc_u.a(.bss .bss.* COMMON)
        libtool_u.a(.bss .bss.* COMMON)
        *(EXCLUDE_FILE (first.o* *librtcb_p.a *libkern_p.a *liblibx_p.a *libshar_p.a) .bss .bss.* .bss*)
        linker_enBSS_u = ABSOLUTE(.);
        /* Standard symbol used by C library for heap start */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data_u

}
