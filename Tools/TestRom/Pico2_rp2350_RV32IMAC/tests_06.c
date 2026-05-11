/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Test of a preliminary pico kernel: cooperative scheduling driven by
 * ecall, dispatched through the non-vectored first_handle_trap path
 * in first_riscv.c. Three messages select the next process to run.
 *
 * Expected on hardware:
 * - UART0 Tx prints "Running first!!!" once at startup, then loops on
 *   "Run P0\n" and "Run P1\n" alternating, with kernel "Kernel ..."
 *   debug lines from the verbose scheduler showing the stack swap
 *   between processes
 * - RED   (GPIO13) is on while P0 is the active process (~100 ms on,
 *   ~100 ms off, then the scheduler hands over to P1)
 * - GREEN (GPIO12) is on while P1 is the active process, with the
 *   same on/off cadence
 */

#include    <inttypes.h>
#include    <stdint.h>
#include    <stdio.h>

#include    "board.h"
#include    "cmns.h"
#include    "macros_core.h"
#include    "macros_soc.h"
#include    "types.h"

void    (*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void    (*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
bool    vExce_isException[KNB_CORES] = MCSET(false);

#define VERBOSE_S

// Ecall context-switch support (defined in first_rv.c, used by the trap handler)

extern  volatile    uintptr_t   vSaveStack;
extern  volatile    uint32_t    vMessage;

#define MESSAGE(msg)    __asm volatile (                \
                        "li     a0,%0           \n"     \
                        "ecall                  \n"     \
                        "fence                  \n"     \
                        :                               \
                        : "i" (msg)                     \
                        : "a0"                          \
                        )

#define KMSGFIRST       0xA0                                                // Message (run P0)
#define KMSGRUNP0       0xA1                                                // Message (run P0)
#define KMSGRUNP1       0xA2                                                // Message (run P1)

#if (defined(VERBOSE_S))
static      char_t      vString[20];
#endif

volatile    uintptr_t   vStackP0[200] __attribute__ ((aligned (16)));       //
volatile    uintptr_t   vStackP1[200] __attribute__ ((aligned (16)));       //
volatile    uintptr_t   vStackCurFs;                                        //
volatile    uintptr_t   vStackCurP0;                                        //
volatile    uintptr_t   vStackCurP1;                                        //

// Prototypes

static  void    process_0(uintptr_t *argument);
static  void    process_1(uintptr_t *argument);
static  void    local_scheduler(void);

/*
 * \brief test_06
 *
 * - Test of a preliminary pico kernel (with messages ecall)
 *
 * Stack layout for a suspended process (28 words, 112 bytes):
 *   [0..11]  s0-s11  (callee-saved, saved by ecall path)
 *   [12..27] trap frame: ra, t0-t2, a0-a7, mcause, mepc, pad, pad
 *
 */
static  void    test_06(void) {
    volatile    uintptr_t   *stack;

    cmns_init();

// Initialise the stack-frame for the process P0

    stack = &vStackP0[200];                     // Stack of the process 0

    *(--stack) = 0x00000000;                    // pad (15)
    *(--stack) = 0x00000000;                    // pad (14)
    *(--stack) = (uintptr_t)process_0;          // mepc (13) - process entry point
    *(--stack) = 0x00000000;                    // mcause (12)
    *(--stack) = 0x17171717;                    // a7 (11)
    *(--stack) = 0x16161616;                    // a6 (10)
    *(--stack) = 0x15151515;                    // a5 (9)
    *(--stack) = 0x14141414;                    // a4 (8)
    *(--stack) = 0x13131313;                    // a3 (7)
    *(--stack) = 0x12121212;                    // a2 (6)
    *(--stack) = 0x11111111;                    // a1 (5)
    *(--stack) = 0x00000000;                    // a0 (4) - process arguments
    *(--stack) = 0x07070707;                    // t2 (3)
    *(--stack) = 0x06060606;                    // t1 (2)
    *(--stack) = 0x05050505;                    // t0 (1)
    *(--stack) = 0xDEADBEEF;                    // ra (0)

    *(--stack) = 0x27272727;                    // s11
    *(--stack) = 0x26262626;                    // s10
    *(--stack) = 0x25252525;                    // s9
    *(--stack) = 0x24242424;                    // s8
    *(--stack) = 0x23232323;                    // s7
    *(--stack) = 0x22222222;                    // s6
    *(--stack) = 0x21212121;                    // s5
    *(--stack) = 0x20202020;                    // s4
    *(--stack) = 0x19191919;                    // s3
    *(--stack) = 0x18181818;                    // s2
    *(--stack) = 0x09090909;                    // s1
    *(--stack) = 0x08080808;                    // s0

    vStackCurP0 = (uintptr_t)stack;             // Stack of the process 0

// Initialise the stack-frame for the process P1

    stack = &vStackP1[200];                     // Stack of the process 1

    *(--stack) = 0x00000000;                    // pad (15)
    *(--stack) = 0x00000000;                    // pad (14)
    *(--stack) = (uintptr_t)process_1;          // mepc (13) - process entry point
    *(--stack) = 0x00000000;                    // mcause (12)
    *(--stack) = 0x17171717;                    // a7 (11)
    *(--stack) = 0x16161616;                    // a6 (10)
    *(--stack) = 0x15151515;                    // a5 (9)
    *(--stack) = 0x14141414;                    // a4 (8)
    *(--stack) = 0x13131313;                    // a3 (7)
    *(--stack) = 0x12121212;                    // a2 (6)
    *(--stack) = 0x11111111;                    // a1 (5)
    *(--stack) = 0x00000000;                    // a0 (4) - process arguments
    *(--stack) = 0x07070707;                    // t2 (3)
    *(--stack) = 0x06060606;                    // t1 (2)
    *(--stack) = 0x05050505;                    // t0 (1)
    *(--stack) = 0xDEADBEEF;                    // ra (0)

    *(--stack) = 0x27272727;                    // s11
    *(--stack) = 0x26262626;                    // s10
    *(--stack) = 0x25252525;                    // s9
    *(--stack) = 0x24242424;                    // s8
    *(--stack) = 0x23232323;                    // s7
    *(--stack) = 0x22222222;                    // s6
    *(--stack) = 0x21212121;                    // s5
    *(--stack) = 0x20202020;                    // s4
    *(--stack) = 0x19191919;                    // s3
    *(--stack) = 0x18181818;                    // s2
    *(--stack) = 0x09090909;                    // s1
    *(--stack) = 0x08080808;                    // s0

    vStackCurP1 = (uintptr_t)stack;             // Stack of the process 1

// Register the ecall handler (exception code 11 = ecall from M-mode)

    EXCEPTION_VECTOR(11, local_scheduler);

// Waiting for the multitasking

    INTERRUPTION_ON_HARD;

    MESSAGE(KMSGFIRST);
    while (true) {
        cmns_send(KURT0, "Running first!!!\n");
    }
}

/*
 * \brief process_0
 *
 * - Blink the RED Led
 *
 */
static  void    process_0([[maybe_unused]] uintptr_t *argument) {

    cmns_send(KURT0, "Enter P0\n");

    while (true) {
        cmns_send(KURT0, "Run P0\n");
        LED_RED_ON;
        cmns_wait(100000);
        LED_RED_OFF;
        cmns_wait(100000);
        MESSAGE(KMSGRUNP1);
    }
}

/*
 * \brief process_1
 *
 * - Blink the GREEN Led
 *
 */
static  void    process_1([[maybe_unused]] uintptr_t *argument) {

    cmns_send(KURT0, "Enter P1\n");

    while (true) {
        cmns_send(KURT0, "Run P1\n");
        LED_GREEN_ON;
        cmns_wait(100000);
        LED_GREEN_OFF;
        cmns_wait(100000);
        MESSAGE(KMSGRUNP0);
    }
}

/*
 * \brief local_scheduler
 *
 * - Pico scheduler
 *
 */
[[gnu::noinline]]
static  void    local_scheduler(void) {
    int len;

    switch (vMessage) {
        default:

// Request to leave the Process First
// - Save the stack
// - Prepare for running the process 0

        case KMSGFIRST: {

            #if (defined(VERBOSE_S))
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vSaveStack);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel First    Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP0);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel First    Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            #endif

            vStackCurFs = vSaveStack;
            vSaveStack  = vStackCurP0;
            break;
        }

// Request to run the Process P0
// - Save the stack
// - Prepare for running the process 0

        case KMSGRUNP0: {

            #if (defined(VERBOSE_S))
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vSaveStack);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel go to P0 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP0);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel go to P0 Stack P0 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            #endif

            vStackCurP1 = vSaveStack;
            vSaveStack  = vStackCurP0;
            break;
        }

// Request to run the Process P1
// - Save the stack
// - Prepare for running the process 1

        case KMSGRUNP1: {

            #if (defined(VERBOSE_S))
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vSaveStack);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel go to P1 Stack SV 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            len = snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vStackCurP1);
            if (len >= 0) {
                cmns_send(KURT0, "Kernel go to P1 Stack P1 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
            }
            #endif

            vStackCurP0 = vSaveStack;
            vSaveStack  = vStackCurP1;
            break;
        }
    }
}

/*
 * \brief main
 *
 * - Execute the test
 *
 */
int     main([[maybe_unused]] int argc, [[maybe_unused]] const char_t *argv[]) {
    test_06();
}
