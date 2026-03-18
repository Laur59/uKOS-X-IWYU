/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Goal:     Stack frame management macros (clang version).
 *           This file conains the most sensitive macros
 *           for the uKernel management
 */

#pragma once

// Stack frame macros
// ------------------

// Prepare the stack frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//  +552    x1 ra           =
//  +544    x5 t0           =
//  +536    x6 t1           =
//  +528    x7 t2           =
//  +520    x8 s0 fp        =
//  +512    x10 a0          = process arguments
//  +504    x11 a1          =
//  +496    x12 a2          =
//  +488    x13 a3          =
//  +480    x14 a4          =
//  +472    x15 a5          =
//  +464    x16 a6          =
//  +456    x17 a7          =
//  +448    x28 t3          =
//  +440    x29 t4          =
//  +432    x30 t5          =
//  +424    x31 t6          =
//  +416    ft0             =
//  +408    ft1             =
//  +400    ft2             =
//  +392    ft3             =
//  +384    ft4             =
//  +376    ft5             =
//  +368    ft6             =
//  +360    ft7             =
//  +352    fa0             =
//  +344    fa1             =
//  +336    fa2             =
//  +328    fa3             =
//  +320    fa4             =
//  +312    fa5             =
//  +304    fa6             =
//  +296    fa7             =
//  +288    ft8             =
//  +280    ft9             =
//  +272    ft10            =
//  +264    ft11            =
//  +256    fs0             =
//  +248    fs1             =
//  +240    fs2             =
//  +232    fs3             =
//  +224    fs4             =
//  +216    fs5             =
//  +208    fs6             =
//  +200    fs7             =
//  +192    fs8             =
//  +184    fs9             =
//  +176    fs10            =
//  +168    fs11            =
//  +160    x0 = 0          = Dummy
//  +152    x27 s11         =
//  +144    x26 s10         =
//  +136    x25 s9          =
//  +128    x24 s8          =
//  +120    x23 s7          =
//  +112    x22 s6          =
//  +104    x21 s5          =
//  +96     x20 s4          =
//  +88     x19 s3          =
//  +80     x18 s2          =
//  +72     x9 s1           =
//  +64     x4 tp           =
//  +56     x3 gp           =
//  +48     x0 = 0          =
//  +40     fcsr            =
//  +32     mepc            = process address
//  +24     mcause          =
//  +16     mstatus         =
//  +8      core            =
//  +0      PLIC->mth       = PLIC priority

#ifndef KERN_PREPARE_FRAME
#define KERN_PREPARE_FRAME(stack, code, core, argument, priority)                                                               \
                                *(--stack) = (uintptr_t)exit_terminate;     /*  +552    x1 ra       */                          \
                                *(--stack) = 0x05050505U;                   /*  +544    x5 t0       */                          \
                                *(--stack) = 0x06060606U;                   /*  +536    x6 t1       */                          \
                                *(--stack) = 0x07070707U;                   /*  +528    x7 t2       */                          \
                                *(--stack) = 0x08080808U;                   /*  +520    x8 s0 fp    */                          \
                                *(--stack) = (uintptr_t)argument;           /*  +512    x10 a0      */                          \
                                *(--stack) = 0x11111111U;                   /*  +504    x11 a1      */                          \
                                *(--stack) = 0x12121212U;                   /*  +496    x12 a2      */                          \
                                *(--stack) = 0x13131313U;                   /*  +488    x13 a3      */                          \
                                *(--stack) = 0x14141414U;                   /*  +480    x14 a4      */                          \
                                *(--stack) = 0x15151515U;                   /*  +472    x15 a5      */                          \
                                *(--stack) = 0x16161616U;                   /*  +464    x16 a6      */                          \
                                *(--stack) = 0x17171717U;                   /*  +456    x17 a7      */                          \
                                *(--stack) = 0x28282828U;                   /*  +448    x28 t3      */                          \
                                *(--stack) = 0x29292929U;                   /*  +440    x29 t4      */                          \
                                *(--stack) = 0x30303030U;                   /*  +432    x30 t5      */                          \
                                *(--stack) = 0x31313131U;                   /*  +424    x31 t6      */                          \
                                *(--stack) = 0xF00F00F0U;                   /*  +416    ft0         */                          \
                                *(--stack) = 0xF01F01F0U;                   /*  +408    ft1         */                          \
                                *(--stack) = 0xF02F02F0U;                   /*  +400    ft2         */                          \
                                *(--stack) = 0xF03F03F0U;                   /*  +392    ft3         */                          \
                                *(--stack) = 0xF04F04F0U;                   /*  +384    ft4         */                          \
                                *(--stack) = 0xF05F05F0U;                   /*  +376    ft5         */                          \
                                *(--stack) = 0xF06F06F0U;                   /*  +368    ft6         */                          \
                                *(--stack) = 0xF07F07F0U;                   /*  +360    ft7         */                          \
                                *(--stack) = 0xFA0FA0F0U;                   /*  +352    fa0         */                          \
                                *(--stack) = 0xFA1FA1F0U;                   /*  +344    fa1         */                          \
                                *(--stack) = 0xFA2FA2F0U;                   /*  +336    fa2         */                          \
                                *(--stack) = 0xFA3FA3F0U;                   /*  +328    fa3         */                          \
                                *(--stack) = 0xFA4FA4F0U;                   /*  +320    fa4         */                          \
                                *(--stack) = 0xFA5FA5F0U;                   /*  +312    fa5         */                          \
                                *(--stack) = 0xFA6FA6F0U;                   /*  +304    fa6         */                          \
                                *(--stack) = 0xFA7FA7F0U;                   /*  +296    fa7         */                          \
                                *(--stack) = 0xF08F08F0U;                   /*  +288    ft8         */                          \
                                *(--stack) = 0xF09F09F0U;                   /*  +280    ft9         */                          \
                                *(--stack) = 0xF0AF0AF0U;                   /*  +272    ft10        */                          \
                                *(--stack) = 0xF0BF0BF0U;                   /*  +264    ft11        */                          \
                                *(--stack) = 0xFF0FF0F0U;                   /*  +256    fs0         */                          \
                                *(--stack) = 0xFF1FF1F0U;                   /*  +248    fs1         */                          \
                                *(--stack) = 0xFF2FF2F0U;                   /*  +240    fs2         */                          \
                                *(--stack) = 0xFF3FF3F0U;                   /*  +232    fs3         */                          \
                                *(--stack) = 0xFF4FF4F0U;                   /*  +224    fs4         */                          \
                                *(--stack) = 0xFF5FF5F0U;                   /*  +216    fs5         */                          \
                                *(--stack) = 0xFF6FF6F0U;                   /*  +208    fs6         */                          \
                                *(--stack) = 0xFF7FF7F0U;                   /*  +200    fs7         */                          \
                                *(--stack) = 0xFF8FF8F0U;                   /*  +192    fs8         */                          \
                                *(--stack) = 0xFF9FF9F0U;                   /*  +184    fs9         */                          \
                                *(--stack) = 0xFFAFFAF0U;                   /*  +176    fs10        */                          \
                                *(--stack) = 0xFFBFFBF0U;                   /*  +168    fs11        */                          \
                                *(--stack) = 0x00000000U;                   /*  +160    dummy       */                          \
                                *(--stack) = 0x27272727U;                   /*  +152    x27 s11     */                          \
                                *(--stack) = 0x26262626U;                   /*  +144    x26 s10     */                          \
                                *(--stack) = 0x25252525U;                   /*  +136    x25 s9      */                          \
                                *(--stack) = 0x24242424U;                   /*  +128    x24 s8      */                          \
                                *(--stack) = 0x23232324U;                   /*  +120    x23 s7      */                          \
                                *(--stack) = 0x22222222U;                   /*  +112    x22 s6      */                          \
                                *(--stack) = 0x21212121U;                   /*  +104    x21 s5      */                          \
                                *(--stack) = 0x20202020U;                   /*  +96     x20 s4      */                          \
                                *(--stack) = 0x19191919U;                   /*  +88     x19 s3      */                          \
                                *(--stack) = 0x18181818U;                   /*  +80     x18 s2      */                          \
                                *(--stack) = 0x09090909U;                   /*  +72     x9 s1       */                          \
                                *(--stack) = 0x04040404U;                   /*  +64     x4 tp       */                          \
                                *(--stack) = 0x03030303U;                   /*  +56     x3 gp       */                          \
                                *(--stack) = 0x00000000U;                   /*  +48     x0 = 0      */                          \
                                *(--stack) = 0x00000000U;                   /*  +40     fcsr        */                          \
                                *(--stack) = (uintptr_t)code;               /*  +32     mepc        */                          \
                                *(--stack) = KPROCESS_INIT_MCAUSE;          /*  +24     mcause      */                          \
                                *(--stack) = KSTATUS;                       /*  +16     mstatus     */                          \
                                *(--stack) = core;                          /*  +8      core        */                          \
                                *(--stack) = priority;                      /*  +0      PLIC->mth   */
#endif

// Save the frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//  +552    x1 ra           =
//  +544    x5 t0           =
//  +536    x6 t1           =
//  +528    x7 t2           =
//  +520    x8 s0 fp        =
//  +512    x10 a0          = process arguments
//  +504    x11 a1          =
//  +496    x12 a2          =
//  +488    x13 a3          =
//  +480    x14 a4          =
//  +472    x15 a5          =
//  +464    x16 a6          =
//  +456    x17 a7          =
//  +448    x28 t3          =
//  +440    x29 t4          =
//  +432    x30 t5          =
//  +424    x31 t6          =
//  +416    ft0             =
//  +408    ft1             =
//  +400    ft2             =
//  +392    ft3             =
//  +384    ft4             =
//  +376    ft5             =
//  +368    ft6             =
//  +360    ft7             =
//  +352    fa0             =
//  +344    fa1             =
//  +336    fa2             =
//  +328    fa3             =
//  +320    fa4             =
//  +312    fa5             =
//  +304    fa6             =
//  +296    fa7             =
//  +288    ft8             =
//  +280    ft9             =
//  +272    ft10            =
//  +264    ft11            =
//  +256    fs0             =
//  +248    fs1             =
//  +240    fs2             =
//  +232    fs3             =
//  +224    fs4             =
//  +216    fs5             =
//  +208    fs6             =
//  +200    fs7             =
//  +192    fs8             =
//  +184    fs9             =
//  +176    fs10            =
//  +168    fs11            =
//  +160    x0 = 0          = Dummy
//  +152    x27 s11         =
//  +144    x26 s10         =
//  +136    x25 s9          =
//  +128    x24 s8          =
//  +120    x23 s7          =
//  +112    x22 s6          =
//  +104    x21 s5          =
//  +96     x20 s4          =
//  +88     x19 s3          =
//  +80     x18 s2          =
//  +72     x9 s1           =
//  +64     x4 tp           =
//  +56     x3 gp           =
//  +48     x0 = 0          =
//  +40     fcsr            =
//  +32     mepc            = process address
//  +24     mcause          =
//  +16     mstatus         =
//  +8      core            =
//  +0      PLIC->mth       = PLIC priority
//
// Prepare for the model
//
// a0 -> core
// a1 -> parameter
// a2 -> *threshold
// a3 -> *stack

#ifndef KERN_SAVE_FRAME
#define KERN_SAVE_FRAME         __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(12*8)                                                                    \n \
                                fsd         fs11,11*8(sp)                                                                    \n \
                                fsd         fs10,10*8(sp)                                                                    \n \
                                fsd         fs9,9*8(sp)                                                                      \n \
                                fsd         fs8,8*8(sp)                                                                      \n \
                                fsd         fs7,7*8(sp)                                                                      \n \
                                fsd         fs6,6*8(sp)                                                                      \n \
                                fsd         fs5,5*8(sp)                                                                      \n \
                                fsd         fs4,4*8(sp)                                                                      \n \
                                fsd         fs3,3*8(sp)                                                                      \n \
                                fsd         fs2,2*8(sp)                                                                      \n \
                                fsd         fs1,1*8(sp)                                                                      \n \
                                fsd         fs0,0*8(sp)"                                                                        \
                                );                                                                                              \
                                                                                                                                \
                                __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(14*8)                                                                    \n \
                                sd          s11,13*8(sp)                                                                     \n \
                                sd          s10,12*8(sp)                                                                     \n \
                                sd          s9,11*8(sp)                                                                      \n \
                                sd          s8,10*8(sp)                                                                      \n \
                                sd          s7,9*8(sp)                                                                       \n \
                                sd          s6,8*8(sp)                                                                       \n \
                                sd          s5,7*8(sp)                                                                       \n \
                                sd          s4,6*8(sp)                                                                       \n \
                                sd          s3,5*8(sp)                                                                       \n \
                                sd          s2,4*8(sp)                                                                       \n \
                                sd          s1,3*8(sp)                                                                       \n \
                                sd          tp,2*8(sp)                                                                       \n \
                                sd          gp,1*8(sp)                                                                       \n \
                                sd          x0,0*8(sp)"                                                                         \
                                );                                                                                              \
                                                                                                                                \
                                __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(6*8)                                                                     \n \
                                frcsr       t0                                                                               \n \
                                sw          t0,5*8(sp)                                                                       \n \
                                csrr        t0,mepc                                                                          \n \
                                sd          t0,4*8(sp)                                                                       \n \
                                csrr        t0,mcause                                                                        \n \
                                sd          t0,3*8(sp)                                                                       \n \
                                csrr        t0,mstatus                                                                       \n \
                                sd          t0,2*8(sp)                                                                       \n \
                                add         t0,x0,a0                                                                         \n \
                                sd          t0,1*8(sp)                                                                       \n \
                                add         t0,x0,x0                                                                         \n \
                                sd          t0,0*8(sp)                                                                       \n \
                                add         a2,x0,sp                                                                         \n \
                                add         a2,a2,0*8                                                                        \n \
                                add         a3,x0,sp"                                                                           \
                                )
#endif

// New frame
//
// The stack has to be aligned on boundary of 16-bytes
// In this case the (552 + 8) mod 16 has to be 0
//
//  +552    x1 ra           =
//  +544    x5 t0           =
//  +536    x6 t1           =
//  +528    x7 t2           =
//  +520    x8 s0 fp        =
//  +512    x10 a0          = process arguments
//  +504    x11 a1          =
//  +496    x12 a2          =
//  +488    x13 a3          =
//  +480    x14 a4          =
//  +472    x15 a5          =
//  +464    x16 a6          =
//  +456    x17 a7          =
//  +448    x28 t3          =
//  +440    x29 t4          =
//  +432    x30 t5          =
//  +424    x31 t6          =
//  +416    ft0             =
//  +408    ft1             =
//  +400    ft2             =
//  +392    ft3             =
//  +384    ft4             =
//  +376    ft5             =
//  +368    ft6             =
//  +360    ft7             =
//  +352    fa0             =
//  +344    fa1             =
//  +336    fa2             =
//  +328    fa3             =
//  +320    fa4             =
//  +312    fa5             =
//  +304    fa6             =
//  +296    fa7             =
//  +288    ft8             =
//  +280    ft9             =
//  +272    ft10            =
//  +264    ft11            =
//  +256    fs0             =
//  +248    fs1             =
//  +240    fs2             =
//  +232    fs3             =
//  +224    fs4             =
//  +216    fs5             =
//  +208    fs6             =
//  +200    fs7             =
//  +192    fs8             =
//  +184    fs9             =
//  +176    fs10            =
//  +168    fs11            =
//  +160    x0 = 0          = Dummy
//  +152    x27 s11         =
//  +144    x26 s10         =
//  +136    x25 s9          =
//  +128    x24 s8          =
//  +120    x23 s7          =
//  +112    x22 s6          =
//  +104    x21 s5          =
//  +96     x20 s4          =
//  +88     x19 s3          =
//  +80     x18 s2          =
//  +72     x9 s1           =
//  +64     x4 tp           =
//  +56     x3 gp           =
//  +48     x0 = 0          =
//  +40     fcsr            =
//  +32     mepc            = process address
//  +24     mcause          =
//  +16     mstatus         =
//  +8      core            =
//  +0      PLIC->mth       = PLIC priority
//
// Prepare for the model
//
// a1 -> *newStack

#ifndef KERN_NEW_FRAME
#define KERN_NEW_FRAME    __asm volatile ("           \n \
                          add    sp,x0,a1             \n \
                          ld     t0,2*8(sp)           \n \
                          csrw   mstatus,t0           \n \
                          ld     t0,3*8(sp)           \n \
                          csrw   mcause,t0            \n \
                          ld     t0,4*8(sp)           \n \
                          csrw   mepc,t0              \n \
                          lw     t0,5*8(sp)           \n \
                          fscsr  t0                   \n \
                          addi   sp,sp,(6*8)"            \
                          );                             \
                                                         \
                          __asm volatile ("           \n \
                          ld     x0,0*8(sp)           \n \
                          ld     gp,1*8(sp)           \n \
                          ld     tp,2*8(sp)           \n \
                          ld     s1,3*8(sp)           \n \
                          ld     s2,4*8(sp)           \n \
                          ld     s3,5*8(sp)           \n \
                          ld     s4,6*8(sp)           \n \
                          ld     s5,7*8(sp)           \n \
                          ld     s6,8*8(sp)           \n \
                          ld     s7,9*8(sp)           \n \
                          ld     s8,10*8(sp)          \n \
                          ld     s9,11*8(sp)          \n \
                          ld     s10,12*8(sp)         \n \
                          ld     s11,13*8(sp)         \n \
                          addi   sp,sp,(14*8)"           \
                          );                             \
                                                         \
                          __asm volatile ("           \n \
                          ld     ra,49*8(sp)          \n \
                          ld     t0,48*8(sp)          \n \
                          ld     t1,47*8(sp)          \n \
                          ld     t2,46*8(sp)          \n \
                          ld     s0,45*8(sp)          \n \
                          ld     a0,44*8(sp)          \n \
                          ld     a1,43*8(sp)          \n \
                          ld     a2,42*8(sp)          \n \
                          ld     a3,41*8(sp)          \n \
                          ld     a4,40*8(sp)          \n \
                          ld     a5,39*8(sp)          \n \
                          ld     a6,38*8(sp)          \n \
                          ld     a7,37*8(sp)          \n \
                          ld     t3,36*8(sp)          \n \
                          ld     t4,35*8(sp)          \n \
                          ld     t5,34*8(sp)          \n \
                          ld     t6,33*8(sp)          \n \
                          fld    ft0,32*8(sp)         \n \
                          fld    ft1,31*8(sp)         \n \
                          fld    ft2,30*8(sp)         \n \
                          fld    ft3,29*8(sp)         \n \
                          fld    ft4,28*8(sp)         \n \
                          fld    ft5,27*8(sp)         \n \
                          fld    ft6,26*8(sp)         \n \
                          fld    ft7,25*8(sp)         \n \
                          fld    fa0,24*8(sp)         \n \
                          fld    fa1,23*8(sp)         \n \
                          fld    fa2,22*8(sp)         \n \
                          fld    fa3,21*8(sp)         \n \
                          fld    fa4,20*8(sp)         \n \
                          fld    fa5,19*8(sp)         \n \
                          fld    fa6,18*8(sp)         \n \
                          fld    fa7,17*8(sp)         \n \
                          fld    ft8,16*8(sp)         \n \
                          fld    ft9,15*8(sp)         \n \
                          fld    ft10,14*8(sp)        \n \
                          fld    ft11,13*8(sp)        \n \
                          fld    fs0,12*8(sp)         \n \
                          fld    fs1,11*8(sp)         \n \
                          fld    fs2,10*8(sp)         \n \
                          fld    fs3,9*8(sp)          \n \
                          fld    fs4,8*8(sp)          \n \
                          fld    fs5,7*8(sp)          \n \
                          fld    fs6,6*8(sp)          \n \
                          fld    fs7,5*8(sp)          \n \
                          fld    fs8,4*8(sp)          \n \
                          fld    fs9,3*8(sp)          \n \
                          fld    fs10,2*8(sp)         \n \
                          fld    fs11,1*8(sp)         \n \
                          addi   sp,sp,(50*8)"           \
                          )
#endif

// Return to a new context

#ifndef KERN_RETURN
#define KERN_RETURN             __asm volatile ("                                                                            \n \
                                mret"                                                                                           \
                                )
#endif

// Messages: _I (immediate) _M (memory)

#ifndef GOTO_KERN_I
#define GOTO_KERN_I(msg)        __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(1*8)                                                                     \n \
                                sd          a0,0*8(sp)                                                                       \n \
                                add         a0,x0,%0                                                                         \n \
                                ecall                                                                                        \n \
                                ld          a0,0*8(sp)                                                                       \n \
                                addi        sp,sp,(1*8)"                                                                        \
                                :                                                                                               \
                                : "r" (msg)                                                                                     \
                                :                                                                                               \
                                )
#endif

#ifndef GOTO_KERN_M
#define GOTO_KERN_M(msg)        __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(1*8)                                                                     \n \
                                sd          a0,0*8(sp)                                                                       \n \
                                add         a0,x0,%0                                                                         \n \
                                ecall                                                                                        \n \
                                ld          a0,0*8(sp)                                                                       \n \
                                addi        sp,sp,(1*8)"                                                                        \
                                :                                                                                               \
                                : "r" (msg)                                                                                     \
                                :                                                                                               \
                                )
#endif

// Core dump register collection

//  +560    x1 ra           =
//  +552    x5 t0           =
//  +544    x6 t1           =
//  +536    x7 t2           =
//  +528    x8 s0 fp        =
//  +520    x10 a0          = process arguments
//  +512    x11 a1          =
//  +504    x12 a2          =
//  +496    x13 a3          =
//  +488    x14 a4          =
//  +480    x15 a5          =
//  +472    x16 a6          =
//  +464    x17 a7          =
//  +456    x28 t3          =
//  +448    x29 t4          =
//  +440    x30 t5          =
//  +432    x31 t6          =
//  +424    ft0             =
//  +416    ft1             =
//  +408    ft2             =
//  +400    ft3             =
//  +392    ft4             =
//  +384    ft5             =
//  +376    ft6             =
//  +368    ft7             =
//  +360    fa0             =
//  +352    fa1             =
//  +344    fa2             =
//  +336    fa3             =
//  +328    fa4             =
//  +320    fa5             =
//  +312    fa6             =
//  +304    fa7             =
//  +296    ft8             =
//  +288    ft9             =
//  +280    ft10            =
//  +272    ft11            =
//  +264    fs0             =
//  +256    fs1             =
//  +248    fs2             =
//  +240    fs3             =
//  +232    fs4             =
//  +224    fs5             =
//  +216    fs6             =
//  +208    fs7             =
//  +200    fs8             =
//  +192    fs9             =
//  +184    fs10            =
//  +176    fs11            =
//  +168    x0 = 0          = Dummy
//  +160    x27 s11         =
//  +152    x26 s10         =
//  +144    x25 s9          =
//  +136    x24 s8          =
//  +128    x23 s7          =
//  +120    x22 s6          =
//  +112    x21 s5          =
//  +104    x20 s4          =
//  +96     x19 s3          =
//  +88     x18 s2          =
//  +80     x9 s1           =
//  +72     x4 tp           =
//  +64     x3 gp           =
//  +56     x0 = 0          =
//  +48     fcsr            =
//  +40     mepc            = process address
//  +32     mcause          =
//  +24     mstatus         =
//  +16     core            =
//  +8      Reserve         =
//  +0      sp              =
//
// Prepare for the core dump
//
// a0 -> core
// a1 -> number
// a2 -> *stackBefore
// a3 -> *stackAfter

enum {
        sp = 0U,                                                        // sp + 0
        Reserve,                                                        // sp + 1
        coreId,                                                         // sp + 2
        statusm, causem, pcm,                                           // sp + 3..5
        fcsr,                                                           // sp + 6
        dummy_1,                                                        // sp + 7
        gp, tp,                                                         // sp + 8..9
        s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11,                   // sp + 10..20
        dummy_2,                                                        // sp + 21
        fs11, fs10, fs9, fs8, fs7, fs6, fs5, fs4, fs3, fs2, fs1, fs0,   // sp + 22..33
        ft11, ft10, ft9, ft8,                                           // sp + 34..37
        fa7, fa6, fa5, fa4, fa3, fa2, fa1, fa0,                         // sp + 38..45
        ft7, ft6, ft5, ft4, ft3, ft2, ft1, ft0,                         // sp + 46..53
        t6, t5, t4, t3,                                                 // sp + 54..57
        a7, a6, a5, a4, a3, a2, a1, a0,                                 // sp + 58..65
        s0,                                                             // sp + 66
        t2, t1, t0,                                                     // sp + 67..69
        ra,                                                             // sp + 70
        ENDREG                                                          // sp + 71
};

// IMPORTANT! This macro HAS to prepare a0, a1, a2, a3 with
// the value of the core, the number, the stack before and after the stacking
// to comply with the ABI of local_processIntInt(uint32_t core, uint64_t number, uintptr_t *stackBefore, uintptr_t *stackAfter)
// a0 & a1 are provided by the first.c

#ifndef CORE_DUMP_SAVE_STACK_FRAME
#define CORE_DUMP_SAVE_STACK_FRAME                                                                                              \
                                __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(12*8)                                                                    \n \
                                fsd         fs11,11*8(sp)                                                                    \n \
                                fsd         fs10,10*8(sp)                                                                    \n \
                                fsd         fs9,9*8(sp)                                                                      \n \
                                fsd         fs8,8*8(sp)                                                                      \n \
                                fsd         fs7,7*8(sp)                                                                      \n \
                                fsd         fs6,6*8(sp)                                                                      \n \
                                fsd         fs5,5*8(sp)                                                                      \n \
                                fsd         fs4,4*8(sp)                                                                      \n \
                                fsd         fs3,3*8(sp)                                                                      \n \
                                fsd         fs2,2*8(sp)                                                                      \n \
                                fsd         fs1,1*8(sp)                                                                      \n \
                                fsd         fs0,0*8(sp)"                                                                        \
                                );                                                                                              \
                                                                                                                                \
                                __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(14*8)                                                                    \n \
                                sd          s11,13*8(sp)                                                                     \n \
                                sd          s10,12*8(sp)                                                                     \n \
                                sd          s9,11*8(sp)                                                                      \n \
                                sd          s8,10*8(sp)                                                                      \n \
                                sd          s7,9*8(sp)                                                                       \n \
                                sd          s6,8*8(sp)                                                                       \n \
                                sd          s5,7*8(sp)                                                                       \n \
                                sd          s4,6*8(sp)                                                                       \n \
                                sd          s3,5*8(sp)                                                                       \n \
                                sd          s2,4*8(sp)                                                                       \n \
                                sd          s1,3*8(sp)                                                                       \n \
                                sd          tp,2*8(sp)                                                                       \n \
                                sd          gp,1*8(sp)                                                                       \n \
                                sd          x0,0*8(sp)"                                                                         \
                                );                                                                                              \
                                                                                                                                \
                                __asm volatile ("                                                                            \n \
                                addi        sp,sp,-(7*8)                                                                     \n \
                                frcsr       t0                                                                               \n \
                                sw          t0,6*8(sp)                                                                       \n \
                                csrr        t0,mepc                                                                          \n \
                                sd          t0,5*8(sp)                                                                       \n \
                                csrr        t0,mcause                                                                        \n \
                                sd          t0,4*8(sp)                                                                       \n \
                                csrr        t0,mstatus                                                                       \n \
                                sd          t0,3*8(sp)                                                                       \n \
                                add         t0,x0,a0                                                                         \n \
                                sd          t0,2*8(sp)                                                                       \n \
                                add         t0,x0,x0                                                                         \n \
                                sd          t0,1*8(sp)                                                                       \n \
                                add         t0,x0,sp                                                                         \n \
                                sd          t0,0*8(sp)                                                                       \n \
                                add         t0,x0,sp                                                                         \n \
                                addi        a2,t0,((7 + 14 + 12 + 38)*8)                                                     \n \
                                add         a3,x0,sp"                                                                           \
                                )
#endif
