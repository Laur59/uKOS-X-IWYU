/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Goal:	Vectors of the machine.
 *			See the link.ld file
 *
 */

				.section	.text_vectors, "ax", %progbits
				.global		start_base
start_base:		j			1f
				.long		0xdeadbeef
				.align		8

				.global		g_wake_up
g_wake_up:		.dword		1
				.dword		0

1:

// Initialize the trap entry
// Interruptions off

				csrw		mideleg,0
				csrw		medeleg,0
				csrw		mie,0
				csrw		mip,0
				la			t0,trapEntry
				csrw		mtvec,t0

// Read the active core

				csrr		a0,mhartid
				j			Reset_Handler
				.align		8

// Go to the trap handle

				.globl		trapEntry
trapEntry:		j			first_handle_trap

