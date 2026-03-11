/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
; rv32_csr.
; =========

;------------------------------------------------------------------------
; Project: uKOS-X
;
; Purpose:
;   rv32_csr equates.
;
;-----
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#pragma once

// User level CSR addresses
// ------------------------

// User Trap Setup

#define RV_CSR_USTATUS                                  0x000U              //
#define RV_CSR_UIE                                      0x004U              //
#define RV_CSR_UTVEC                                    0x005U              //

// User Trap Handling

#define RV_CSR_USCRATCH                                 0x040U              //
#define RV_CSR_UEPC                                     0x041U              //
#define RV_CSR_UCAUSE                                   0x042U              //
#define RV_CSR_UTVAL                                    0x043U              //
#define RV_CSR_UIP                                      0x044U              //

// User Floating-point CSR

#define RV_CSR_FFLAGS                                   0x001U              //
#define RV_CSR_FRM                                      0x002U              //
#define RV_CSR_FCSR                                     0x003U              //

// User Counter/Timers

#define RV_CSR_CYCLE                                    0xC00U              //
#define RV_CSR_TIME                                     0xC01U              //
#define RV_CSR_INSTRET                                  0xC02U              //
#define RV_CSR_HPMCOUNTER3                              0xC03U              //
#define RV_CSR_HPMCOUNTER4                              0xC04U              //
#define RV_CSR_HPMCOUNTER5                              0xC05U              //
#define RV_CSR_HPMCOUNTER6                              0xC06U              //
#define RV_CSR_HPMCOUNTER7                              0xC07U              //
#define RV_CSR_HPMCOUNTER8                              0xC08U              //
#define RV_CSR_HPMCOUNTER9                              0xC09U              //
#define RV_CSR_HPMCOUNTER10                             0xC0AU              //
#define RV_CSR_HPMCOUNTER11                             0xC0BU              //
#define RV_CSR_HPMCOUNTER12                             0xC0CU              //
#define RV_CSR_HPMCOUNTER13                             0xC0DU              //
#define RV_CSR_HPMCOUNTER14                             0xC0EU              //
#define RV_CSR_HPMCOUNTER15                             0xC0FU              //
#define RV_CSR_HPMCOUNTER16                             0xC10U              //
#define RV_CSR_HPMCOUNTER17                             0xC11U              //
#define RV_CSR_HPMCOUNTER18                             0xC12U              //
#define RV_CSR_HPMCOUNTER19                             0xC13U              //
#define RV_CSR_HPMCOUNTER20                             0xC14U              //
#define RV_CSR_HPMCOUNTER21                             0xC15U              //
#define RV_CSR_HPMCOUNTER22                             0xC16U              //
#define RV_CSR_HPMCOUNTER23                             0xC17U              //
#define RV_CSR_HPMCOUNTER24                             0xC18U              //
#define RV_CSR_HPMCOUNTER25                             0xC19U              //
#define RV_CSR_HPMCOUNTER26                             0xC1AU              //
#define RV_CSR_HPMCOUNTER27                             0xC1BU              //
#define RV_CSR_HPMCOUNTER28                             0xC1CU              //
#define RV_CSR_HPMCOUNTER29                             0xC1DU              //
#define RV_CSR_HPMCOUNTER30                             0xC1EU              //
#define RV_CSR_HPMCOUNTER31                             0xC1FU              //
#define RV_CSR_CYCLEH                                   0xC80U              //
#define RV_CSR_TIMEH                                    0xC81U              //
#define RV_CSR_INSTRETH                                 0xC82U              //
#define RV_CSR_HPMCOUNTER3H                             0xC83U              //
#define RV_CSR_HPMCOUNTER4H                             0xC84U              //
#define RV_CSR_HPMCOUNTER5H                             0xC85U              //
#define RV_CSR_HPMCOUNTER6H                             0xC86U              //
#define RV_CSR_HPMCOUNTER7H                             0xC87U              //
#define RV_CSR_HPMCOUNTER8H                             0xC88U              //
#define RV_CSR_HPMCOUNTER9H                             0xC89U              //
#define RV_CSR_HPMCOUNTER10H                            0xC8AU              //
#define RV_CSR_HPMCOUNTER11H                            0xC8BU              //
#define RV_CSR_HPMCOUNTER12H                            0xC8CU              //
#define RV_CSR_HPMCOUNTER13H                            0xC8DU              //
#define RV_CSR_HPMCOUNTER14H                            0xC8EU              //
#define RV_CSR_HPMCOUNTER15H                            0xC8FU              //
#define RV_CSR_HPMCOUNTER16H                            0xC90U              //
#define RV_CSR_HPMCOUNTER17H                            0xC91U              //
#define RV_CSR_HPMCOUNTER18H                            0xC92U              //
#define RV_CSR_HPMCOUNTER19H                            0xC93U              //
#define RV_CSR_HPMCOUNTER20H                            0xC94U              //
#define RV_CSR_HPMCOUNTER21H                            0xC95U              //
#define RV_CSR_HPMCOUNTER22H                            0xC96U              //
#define RV_CSR_HPMCOUNTER23H                            0xC97U              //
#define RV_CSR_HPMCOUNTER24H                            0xC98U              //
#define RV_CSR_HPMCOUNTER25H                            0xC99U              //
#define RV_CSR_HPMCOUNTER26H                            0xC9AU              //
#define RV_CSR_HPMCOUNTER27H                            0xC9BU              //
#define RV_CSR_HPMCOUNTER28H                            0xC9CU              //
#define RV_CSR_HPMCOUNTER29H                            0xC9DU              //
#define RV_CSR_HPMCOUNTER30H                            0xC9EU              //
#define RV_CSR_HPMCOUNTER31H                            0xC9FU              //

// Supervisor level CSR addresses
// ------------------------------

// Supervisor Trap Setup

#define RV_CSR_SSTATUS                                  0x100U              //
#define RV_CSR_SEDELEG                                  0x102U              //
#define RV_CSR_SIDELEG                                  0x103U              //
#define RV_CSR_SIE                                      0x104U              //
#define RV_CSR_STVEC                                    0x105U              //
#define RV_CSR_SCOUNTEREN                               0x106U              //

// Supervisor Trap Handling

#define RV_CSR_SSCRATCH                                 0x140U              //
#define RV_CSR_SEPC                                     0x141U              //
#define RV_CSR_SCAUSE                                   0x142U              //
#define RV_CSR_SBADADDR                                 0x143U              //
#define RV_CSR_SIP                                      0x144U              //

// Supervisor Protection and Translation

#define RV_CSR_SPTBR                                    0x180U              //

// Hypervisor level CSR addresses
// ------------------------------

// Hypervisor Trap Setup

#define RV_CSR_HSTATUS                                  0x600U              //
#define RV_CSR_HEDELEG                                  0x602U              //
#define RV_CSR_HIDELEG                                  0x603U              //
#define RV_CSR_HIE                                      0x604U              //
#define RV_CSR_HCOUNTEREN                               0x606U              //
#define RV_CSR_HGEIE                                    0x607U              //

// Hypervisor Trap Handling

#define RV_CSR_HTVAL                                    0x643U              //
#define RV_CSR_HIP                                      0x644U              //
#define RV_CSR_HTINST                                   0x64AU              //
#define RV_CSR_HGEIP                                    0xE07U              //

// Hypervisor Protection and Translation

#define RV_CSR_HGATP                                    0x680U              //

// HypervisorCounter/Timers Visualization registers

#define RV_CSR_HTIMEDELTA                               0x605U              //
#define RV_CSR_HTIMEDELTAH                              0x615U              //

// Virtual Supervisor Registers

#define RV_CSR_VSTATUS                                  0x200U              //
#define RV_CSR_VSIE                                     0x204U              //
#define RV_CSR_VSTVEC                                   0x205U              //
#define RV_CSR_VSSCRATCH                                0x240U              //
#define RV_CSR_VSEPC                                    0x241U              //
#define RV_CSR_VSCAUSE                                  0x242U              //
#define RV_CSR_VSTVAL                                   0x243U              //
#define RV_CSR_VSIP                                     0x244U              //
#define RV_CSR_VSATP                                    0x280U              //

// Machine level CSR addresses
// ---------------------------

// Machine Information Registers

#define RV_CSR_MVENDORID                                0xF11U              //
#define RV_CSR_MARCHID                                  0xF12U              //
#define RV_CSR_MIMPID                                   0xF13U              //
#define RV_CSR_MHARTID                                  0xF14U              //

// Machine Trap Setup

#define RV_CSR_MSTATUS                                  0x300U              //
#define RV_CSR_MISA                                     0x301U              //
#define RV_CSR_MEDELEG                                  0x302U              //
#define RV_CSR_MIDELEG                                  0x303U              //
#define RV_CSR_MIE                                      0x304U              //
#define RV_CSR_MTVEC                                    0x305U              //
#define RV_CSR_MCOUNTEREN                               0x306U              //
#define RV_CSR_MSTATUSH                                 0x310U              //

// Machine Trap Handling

#define RV_CSR_MSCRATCH                                 0x340U              //
#define RV_CSR_MEPC                                     0x341U              //
#define RV_CSR_MCAUSE                                   0x342U              //
#define RV_CSR_MBADADDR                                 0x343U              //
#define RV_CSR_MIP                                      0x344U              //
#define RV_CSR_MTINST                                   0x34AU              //
#define RV_CSR_MTVAL2                                   0x34BU              //

// Machine MEMORY Protection

#define RV_CSR_PMPCFG0                                  0x3A0U              //
#define RV_CSR_PMPCFG1                                  0x3A1U              //
#define RV_CSR_PMPCFG2                                  0x3A2U              //
#define RV_CSR_PMPCFG3                                  0x3A3U              //
#define RV_CSR_PMPADDR0                                 0x3B0U              //
#define RV_CSR_PMPADDR1                                 0x3B1U              //
#define RV_CSR_PMPADDR2                                 0x3B2U              //
#define RV_CSR_PMPADDR3                                 0x3B3U              //
#define RV_CSR_PMPADDR4                                 0x3B4U              //
#define RV_CSR_PMPADDR5                                 0x3B5U              //
#define RV_CSR_PMPADDR6                                 0x3B6U              //
#define RV_CSR_PMPADDR7                                 0x3B7U              //
#define RV_CSR_PMPADDR8                                 0x3B8U              //
#define RV_CSR_PMPADDR9                                 0x3B9U              //
#define RV_CSR_PMPADDR10                                0x3BAU              //
#define RV_CSR_PMPADDR11                                0x3BBU              //
#define RV_CSR_PMPADDR12                                0x3BCU              //
#define RV_CSR_PMPADDR13                                0x3BDU              //
#define RV_CSR_PMPADDR14                                0x3BEU              //
#define RV_CSR_PMPADDR15                                0x3BFU              //

// Machine level CSR addresses
// ---------------------------

// Machine Counter/Timers

#define RV_CSR_MCYCLE                                   0xB00U              //
#define RV_CSR_MINSTRET                                 0xB02U              //
#define RV_CSR_MHPMCOUNTER3                             0xB03U              //
#define RV_CSR_MHPMCOUNTER4                             0xB04U              //
#define RV_CSR_MHPMCOUNTER5                             0xB05U              //
#define RV_CSR_MHPMCOUNTER6                             0xB06U              //
#define RV_CSR_MHPMCOUNTER7                             0xB07U              //
#define RV_CSR_MHPMCOUNTER8                             0xB08U              //
#define RV_CSR_MHPMCOUNTER9                             0xB09U              //
#define RV_CSR_MHPMCOUNTER10                            0xB0AU              //
#define RV_CSR_MHPMCOUNTER11                            0xB0BU              //
#define RV_CSR_MHPMCOUNTER12                            0xB0CU              //
#define RV_CSR_MHPMCOUNTER13                            0xB0DU              //
#define RV_CSR_MHPMCOUNTER14                            0xB0EU              //
#define RV_CSR_MHPMCOUNTER15                            0xB0FU              //
#define RV_CSR_MHPMCOUNTER16                            0xB10U              //
#define RV_CSR_MHPMCOUNTER17                            0xB11U              //
#define RV_CSR_MHPMCOUNTER18                            0xB12U              //
#define RV_CSR_MHPMCOUNTER19                            0xB13U              //
#define RV_CSR_MHPMCOUNTER20                            0xB14U              //
#define RV_CSR_MHPMCOUNTER21                            0xB15U              //
#define RV_CSR_MHPMCOUNTER22                            0xB16U              //
#define RV_CSR_MHPMCOUNTER23                            0xB17U              //
#define RV_CSR_MHPMCOUNTER24                            0xB18U              //
#define RV_CSR_MHPMCOUNTER25                            0xB19U              //
#define RV_CSR_MHPMCOUNTER26                            0xB1AU              //
#define RV_CSR_MHPMCOUNTER27                            0xB1BU              //
#define RV_CSR_MHPMCOUNTER28                            0xB1CU              //
#define RV_CSR_MHPMCOUNTER29                            0xB1DU              //
#define RV_CSR_MHPMCOUNTER30                            0xB1EU              //
#define RV_CSR_MHPMCOUNTER31                            0xB1FU              //
#define RV_CSR_MCYCLEH                                  0xB80U              //
#define RV_CSR_MINSTRETH                                0xB82U              //
#define RV_CSR_MHPMCOUNTER3H                            0xB83U              //
#define RV_CSR_MHPMCOUNTER4H                            0xB84U              //
#define RV_CSR_MHPMCOUNTER5H                            0xB85U              //
#define RV_CSR_MHPMCOUNTER6H                            0xB86U              //
#define RV_CSR_MHPMCOUNTER7H                            0xB87U              //
#define RV_CSR_MHPMCOUNTER8H                            0xB88U              //
#define RV_CSR_MHPMCOUNTER9H                            0xB89U              //
#define RV_CSR_MHPMCOUNTER10H                           0xB8AU              //
#define RV_CSR_MHPMCOUNTER11H                           0xB8BU              //
#define RV_CSR_MHPMCOUNTER12H                           0xB8CU              //
#define RV_CSR_MHPMCOUNTER13H                           0xB8DU              //
#define RV_CSR_MHPMCOUNTER14H                           0xB8EU              //
#define RV_CSR_MHPMCOUNTER15H                           0xB8FU              //
#define RV_CSR_MHPMCOUNTER16H                           0xB90U              //
#define RV_CSR_MHPMCOUNTER17H                           0xB91U              //
#define RV_CSR_MHPMCOUNTER18H                           0xB92U              //
#define RV_CSR_MHPMCOUNTER19H                           0xB93U              //
#define RV_CSR_MHPMCOUNTER20H                           0xB94U              //
#define RV_CSR_MHPMCOUNTER21H                           0xB95U              //
#define RV_CSR_MHPMCOUNTER22H                           0xB96U              //
#define RV_CSR_MHPMCOUNTER23H                           0xB97U              //
#define RV_CSR_MHPMCOUNTER24H                           0xB98U              //
#define RV_CSR_MHPMCOUNTER25H                           0xB99U              //
#define RV_CSR_MHPMCOUNTER26H                           0xB9AU              //
#define RV_CSR_MHPMCOUNTER27H                           0xB9BU              //
#define RV_CSR_MHPMCOUNTER28H                           0xB9CU              //
#define RV_CSR_MHPMCOUNTER29H                           0xB9DU              //
#define RV_CSR_MHPMCOUNTER30H                           0xB9EU              //
#define RV_CSR_MHPMCOUNTER31H                           0xB9FU              //

// Machine Counter Setup

#define RV_CSR_MUCOUNTEREN                              0x320U              //
#define RV_CSR_MSCOUNTEREN                              0x321U              //
#define RV_CSR_MHPMEVENT3                               0x323U              //
#define RV_CSR_MHPMEVENT4                               0x324U              //
#define RV_CSR_MHPMEVENT5                               0x325U              //
#define RV_CSR_MHPMEVENT6                               0x326U              //
#define RV_CSR_MHPMEVENT7                               0x327U              //
#define RV_CSR_MHPMEVENT8                               0x328U              //
#define RV_CSR_MHPMEVENT9                               0x329U              //
#define RV_CSR_MHPMEVENT10                              0x32AU              //
#define RV_CSR_MHPMEVENT11                              0x32BU              //
#define RV_CSR_MHPMEVENT12                              0x32CU              //
#define RV_CSR_MHPMEVENT13                              0x32DU              //
#define RV_CSR_MHPMEVENT14                              0x32EU              //
#define RV_CSR_MHPMEVENT15                              0x32FU              //
#define RV_CSR_MHPMEVENT16                              0x330U              //
#define RV_CSR_MHPMEVENT17                              0x331U              //
#define RV_CSR_MHPMEVENT18                              0x332U              //
#define RV_CSR_MHPMEVENT19                              0x333U              //
#define RV_CSR_MHPMEVENT20                              0x334U              //
#define RV_CSR_MHPMEVENT21                              0x335U              //
#define RV_CSR_MHPMEVENT22                              0x336U              //
#define RV_CSR_MHPMEVENT23                              0x337U              //
#define RV_CSR_MHPMEVENT24                              0x338U              //
#define RV_CSR_MHPMEVENT25                              0x339U              //
#define RV_CSR_MHPMEVENT26                              0x33AU              //
#define RV_CSR_MHPMEVENT27                              0x33BU              //
#define RV_CSR_MHPMEVENT28                              0x33CU              //
#define RV_CSR_MHPMEVENT29                              0x33DU              //
#define RV_CSR_MHPMEVENT30                              0x33EU              //
#define RV_CSR_MHPMEVENT31                              0x33FU              //

// Debug/Trace Registers (shared with Debug Mode)

#define RV_CSR_TSELECT                                  0x7A0U              //
#define RV_CSR_TDATA1                                   0x7A1U              //
#define RV_CSR_TDATA2                                   0x7A2U              //
#define RV_CSR_TDATA3                                   0x7A3U              //

// Debug Modee Register

#define RV_CSR_DCSR                                     0x7B0U              //
#define RV_CSR_DPC                                      0x7B1U              //
#define RV_CSR_DSCRATCH                                 0x7B2U              //

// Bits in registers
// -----------------

#define MSTATUS_UIE                                     (1U<<0)             //
#define MSTATUS_SIE                                     (1U<<1)             //
#define MSTATUS_HIE                                     (1U<<2)             //
#define MSTATUS_MIE                                     (1U<<3)             //
#define MSTATUS_UPIE                                    (1U<<4)             //
#define MSTATUS_SPIE                                    (1U<<5)             //
#define MSTATUS_HPIE                                    (1U<<6)             //
#define MSTATUS_MPIE                                    (1U<<7)             //
#define MSTATUS_SPP                                     (1U<<8)             //
#define MSTATUS_MPP                                     (3U<<11)            //
#define MSTATUS_FS                                      (3U<<13)            //
#define MSTATUS_XS                                      (3U<<15)            //
#define MSTATUS_MPRV                                    (1U<<17)            //
#define MSTATUS_PUM                                     (1U<<18)            //
#define MSTATUS_MXR                                     (1U<<19)            //
#define MSTATUS_VM                                      0x1F000000U         //
#define MSTATUS32_SD                                    0x80000000U         //
#define MSTATUS64_SD                                    0x8000000000000000U //

#define SSTATUS_UIE                                     0x00000001U         //
#define SSTATUS_SIE                                     0x00000002U         //
#define SSTATUS_UPIE                                    0x00000010U         //
#define SSTATUS_SPIE                                    0x00000020U         //
#define SSTATUS_SPP                                     0x00000100U         //
#define SSTATUS_FS                                      0x00006000U         //
#define SSTATUS_XS                                      0x00018000U         //
#define SSTATUS_PUM                                     0x00040000U         //
#define SSTATUS32_SD                                    0x80000000U         //
#define SSTATUS64_SD                                    0x8000000000000000U //

#define MCAUSE_INTERRUPT                                0x80000000U         //
#define MCAUSE_CAUSE                                    0x7FFFFFFFU         //

#define MCAUSE_EXC_CODE_INSTRUCTION_ADDRESS_MISALIGNED  0U                  //
#define MCAUSE_EXC_CODE_INSTRUCTION_ACCESS_FAULT        1U                  //
#define MCAUSE_EXC_CODE_ILLEGAL_INSTRUCTION             2U                  //
#define MCAUSE_EXC_CODE_BREAKPOINT                      3U                  //
#define MCAUSE_EXC_CODE_LOAD_ADDRESS_MISALIGNED         4U                  //
#define MCAUSE_EXC_CODE_LOAD_ACCESS_FAULT               5U                  //
#define MCAUSE_EXC_CODE_STORE_AMO_ADDRESS_MISALIGNED    6U                  //
#define MCAUSE_EXC_CODE_STORE_AMO_ACCESS_FAULT          7U                  //
#define MCAUSE_EXC_CODE_ENV_CALL_FROM_U_MODE            8U                  //
#define MCAUSE_EXC_CODE_ENV_CALL_FROM_S_MODE            9U                  //
#define MCAUSE_EXC_CODE_ENV_CALL_FROM_M_MODE            11U                 //
#define MCAUSE_EXC_CODE_INSTRUCTION_PAGE_FAULT          12U                 //
#define MCAUSE_EXC_CODE_LOAD_PAGE_FAULT                 13U                 //
#define MCAUSE_EXC_CODE_STORE_AMO_PAGE_FAULT            15U                 //

#define CSR_SETBITS(reg, mask) \
    ({ \
        uint32_t    __tmp; \
        if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32)) { \
            __asm volatile ("csrrs %0, " #reg ", %1" : "=r" (__tmp) : "i" (mask)); \
        } \
        else { \
            __asm volatile ("csrrs %0, " #reg ", %1" : "=r" (__tmp) : "r" (mask)); \
        } \
        __tmp; \
    })

#define CSR_CLEARBITS(reg, mask) \
    ({ \
        uint32_t    __tmp; \
        if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32)) { \
            __asm volatile ("csrrc %0, " #reg ", %1" : "=r" (__tmp) : "i" (mask)); \
        } \
        else { \
            __asm volatile ("csrrc %0, " #reg ", %1" : "=r" (__tmp) : "r" (mask)); \
        } \
        __tmp; \
    })

#define CSR_WRITE(reg, value) \
    ({ \
        if (__builtin_constant_p(value) && ((uint32_t)(value) < 32)) { \
            __asm volatile ("csrw " #reg ", %0" :: "i" (value)); \
        } \
        else { \
            __asm volatile ("csrw " #reg ", %0" :: "r" (value)); \
        } \
    })

#define CSR_READ(reg) \
    ({ \
        uint32_t    __tmp;  \
        __asm volatile ("csrr %0, " #reg : "=r" (__tmp)); \
        __tmp; \
    })
