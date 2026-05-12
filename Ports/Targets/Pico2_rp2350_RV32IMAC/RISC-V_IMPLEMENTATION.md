# RISC-V Support for RP2350 (Raspberry Pi Pico 2)

## Overview

This document describes the implementation of RISC-V support for the RP2350 microcontroller
(Raspberry Pi Pico 2) running in RISC-V Hazard3 mode.

In order to prepare this implementation some test files have been developed to get a better
understanding of RP2350 (`/Tools/TestRom/Pico2_rp2350_RV32IMAC/`).

Development is incremental; this document is kept as a living record of decisions,
findings, and phase status.

**Status:** Phase 3.5 implementation complete — full kernel boot linked and building clean. Ready for hardware validation.

**Date:** 2026-05-09

### Target Structure

Implementation of this target `Pico2_rp2350_RV32IMAC` follows the layout used by other targets.
The goal is to port from ARM to RISC-V the code in target `Pico2_rp2350`. Items marked `[done]`
are committed; `[planned]` items are not yet present.

**Location:** `/Ports/Targets/Pico2_rp2350_RV32IMAC/`

```
Pico2_rp2350_RV32IMAC/
├── Base/
│   ├── Lib_kernels/kern/
│   │   └── stub_kern_kernel.c          # [done]    TIMER0 model: 1-ms and 20-ms alarms
│   ├── Lib_peripherals/led/
│   │   └── stub_led.c                  # [done]    LED stub
│   ├── Lib_serials/urt0/
│   │   └── stub_urt0_uart.c            # [done]    UART0 stub
│   ├── Processes/alive/
│   │   └── stub_alive.c                # [done]    alive process stub
│   └── Runtime/
│       ├── picobin.[ch]                # [done]    picobin IMAGE_DEF block (RISC-V variant)
│       ├── crt0.c                      # [done]    C runtime startup (calls main directly)
│       ├── link_p.ld                   # [done]    Main linker script
│       ├── cmns.c                      # [done]    Common serial functions
│       └── exce.c                      # [done]    Exception/interrupt dispatch + coreDump
└── Variant_Test/
    ├── CMakeLists.txt                  # [done]    Build configuration (RISC-V toolchain)
    ├── CMakePresets.json               # [done]    Build presets
    ├── Includes/Board/board.h          # [done]    GPIO/LED/clock definitions
    ├── Processes/startUp/
    │   └── stub_startUp.c             # [done]    startUp stub (UART0 at 460800)
    ├── Runtime/
    │   ├── init.c                      # [done]    PLL + SIO-FIFO helpers + launchCore_1
    │   ├── init_C0.c                   # [done]    GPIO/pad config for core 0
    │   ├── init_C1.c                   # [done]    Core-1 placeholder (enable MIE)
    │   └── init.h                      # [done]    Declarations
    └── main.c                          # [done]    Phase 3.5: delegates to boot()
```

---

## Architecture

The RP2350 is a unique dual-architecture microcontroller that can boot as either:
- **ARM Cortex-M33** (existing `Pico2_rp2350` target)
- **RISC-V Hazard3** (this target: `Pico2_rp2350_RV32IMAC`)

Architecture selection is controlled by the **ARCHSEL** bit in the picobin boot block.

### RISC-V Hazard3 Specifications
- **ISA:** RV32IMAC (32-bit, Integer, Multiply, Atomic, Compressed)
- **Privilege Modes:** Machine (M) and User (U) — Hazard3 omits Supervisor (S)
- **Cores:** Dual-core (Core 0 + Core 1)
- **Memory:** 520 KB SRAM, 4 MB Flash
- **Peripherals:** Identical register map to ARM version

---

## Implementation Choices

The following decisions anchor the port; revisit if hardware or kernel constraints push back.

- **Privilege model.** Hazard3 implements M and U modes (no S), and PMP is available.
  We run **M-mode only** for the initial port, collapsing the upstream µKOS-X
  user/privileged library split (`*_p` / `*_u`) to privileged-only, matching
  `Longan_Nano_F103` and `MAiXDUiNO_K210`. U-mode + PMP for process isolation is
  left as future work.

- **Trap handling.** `mtvec` is set to **DIRECT** mode (`MODE = 0`) — all traps
  (synchronous exceptions and asynchronous interrupts) enter `first_handle_trap`.
  The handler distinguishes exceptions from interrupts via `mcause[31]`, then
  dispatches ecall (cause 11) to the kernel path, other exceptions to
  `first_dispatch_exception`, and interrupts to `first_dispatch_interrupt`.

- **Ecall frame layout.** The ecall context-switch path saves a full **35-word
  frame** matching `KERN_SAVE_FRAME` / `KERN_PREPARE_FRAME`:

  | Offset | Content           |
  |--------|-------------------|
  | sp[0]  | mepc (pc+4)       |
  | sp[1]  | mcause            |
  | sp[2]  | mstatus           |
  | sp[3]  | priority          |
  | sp[4..16] | s11..s1, tp   |
  | sp[16] | gp (fill: 0x03030303 in new frames) |
  | sp[17] | — (reserved)      |
  | sp[18..34] | t6..t0, a7..a0, s0, ra |

  **Important:** `KERN_PREPARE_FRAME` stores `0x03030303` as a debug fill for `gp`.
  The ecall restore path must **never** reload gp from the frame for new processes;
  instead it always reloads the real global pointer with:
  ```asm
  .option push
  .option norelax
  la  gp, __global_pointer$
  .option pop
  ```
  Without this, gp-relative global variable accesses in the first instruction of any
  new process will silently read or write the wrong address, causing a cascade of
  silent faults that produce no UART output and no LED activity.

- **`csrw mcause` removed from restore path.** The Bumblebee-format
  `KPROCESS_INIT_MCAUSE = 0xB800000B` (bit 31 set) is specific to GD32V/K210 and
  must not be written to Hazard3's `mcause`. The restore path uses only
  `csrw mepc` and `csrw mstatus`.

- **Scheduler guard in timer ISR.** `scheduler_callBackFast()` calls
  `local_updateDynaPriority()`, which unconditionally dereferences
  `vKern_listExec[core].oFirst`. `lists_initialise()` sets `oFirst = nullptr`, so
  calling the scheduler before any process is installed causes a silent NULL-pointer
  crash. The 1-ms ALARM0 ISR is guarded:
  ```c
  if (vKern_listExec[GET_RUNNING_CORE].oNbElements > 0U) {
      scheduler_callBackFast(1U);
  }
  ```
  This makes the timer model safe both during timer-only verification (no processes)
  and during normal kernel operation (idle process installed).

- **Boot path.** `crt0` calls `main()` directly (not `boot()`). `boot.c` is not
  linked in the current phase. The boot chain is:
  ```
  Reset_C0_Handler → (mtvec, sp) → crt0 → init_init() → init_C0_init()
    → cmns_init() → [BSS/data init] → exce_init() → main()
  ```

- **External interrupts.** Routed through the Hazard3 Xh3irq controller using
  custom CSRs (`meiea`, `meipa`, `meipra`, `meinext`, `meicontext`). No standard
  PLIC programming sequence applies. Three independent gates must all be open for
  a peripheral IRQ to reach the core:

  | Gate | CSR/mechanism | API |
  |------|--------------|-----|
  | 1 — Peripheral enable | MEIEA (0xBE0), window-addressed | `h3irq_EnableIRQ(irqn)` |
  | 2 — Machine external enable | `mie.MEIE` (bit 11) | `core_setBitCSR(RV_CSR_MIE, MIE_MEIE)` |
  | 3 — Global interrupt enable | `mstatus.MIE` (bit 3) | `INTERRUPTION_ON_HARD` |

  Missing any one gate produces a silent hang. Gate 2 was the last to be
  identified; `NVIC_EnableIRQ` (now `h3irq_EnableIRQ`) only sets gate 1.

- **h3irq naming.** The interrupt-controller functions in
  `Cores/RV32IMAC/Includes/Registers/nvic.h` are named `h3irq_EnableIRQ`,
  `h3irq_DisableIRQ`, `h3irq_SetPriority`, `h3irq_SetPendingIRQ`,
  `h3irq_ClearPendingIRQ` to reflect the actual Hazard3 Xh3irq hardware.
  Backward-compatible `NVIC_*` aliases are retained for the shared rp2350 model
  files (`model_uart_C0.c_inc` etc.) that also compile against the ARM target.
  RISC-V-only code uses `h3irq_*` directly.

- **Dual-core split.** Core 0 is the primary boot core. Core 1 is not launched in
  the current phase; `main_C1()` initialises MIE and loops on WFI.

- **PMP.** Available, but not configured — deferred until module isolation is needed.

- **Flashing.** `picotool load -f -x FLASH.elf` is the sole flashing method.
  UF2 files are not used for this target.

---

## Roadmap

### Phase 0 — File scaffolding [done]

Directory layout established. Source files copied from the TestRom
(`/Tools/TestRom/Pico2_rp2350_RV32IMAC/`) and from neighbouring targets to seed
the build.

### Phase 1 — Minimal bootable build [done]

**Goal.** Produce `FLASH.elf` that the RP2350 bootrom accepts in RISC-V mode and
reaches a visible LED + UART state, with no kernel modules linked.

**Outcome.**
- `cmake --preset llvm` and `cmake --build build` complete cleanly.
- `picotool load -f -x FLASH.elf` succeeds.
- Bootrom accepts the image — no boot fault.
- LED on GPIO25 blinks; smoke message `"Phase 1 alive\r\n"` appears on UART0 at
  460800 baud.

### Phase 2 — Init restructure + exce.c with coreDump [done]

**Goal.** Split `init.c` into three files; add `exce.c` with coreDump; wire
`exce_init()` into `crt0.c`.

**Outcome.**
- `init.c` — PLL setup, SIO-FIFO helpers, `init_launchCore_1()`.
- `init_C0.c` — GPIO/pad config for core 0 (LEDs, UART mux).
- `init_C1.c` — core-1 placeholder (enable `mstatus.MIE`).
- `exce.c` — vector tables, four coreDump model includes, `exce_init()`.
- A deliberate bad-address write confirmed coreDump fires on UART0 showing
  `mepc`, `mcause`, and register state.

### Phase 3.1–3.3 — Kernel wiring (ecall path) [done]

**Goal.** Wire the ecall context-switch path so `kern_switchFast()` can transfer
control to the first process.

**Key findings and fixes.**

1. **28-word vs 35-word frame mismatch.**  
   The original ecall handler saved only 16 caller-saved registers (a 16-word partial
   frame). `KERN_PREPARE_FRAME` lays out a 35-word frame; `KERN_NEW_FRAME` restores
   from that layout. The first `mret` landed at `mepc = 0x14141414` (the fill pattern
   for the callee-saved region), causing an illegal-instruction trap that was caught
   by coreDump.  
   **Fix:** rewrote the ecall path to save all 35 words in `KERN_SAVE_FRAME` order
   before dispatching to `first_dispatch_ecall`.

2. **gp = 0x03030303 cascade fault.**  
   After fixing the frame layout, `mret` executed correctly but UART and LEDs went
   dark. Root cause: `KERN_PREPARE_FRAME` stores `0x03030303` as a debug fill for gp
   (slot sp[16]). After the context switch, every gp-relative global variable access
   in the new process hit the wrong address. coreDump itself also crashed (it uses
   gp-relative accesses), producing complete silence.  
   **Fix:** the ecall restore path loads `gp` with `la gp, __global_pointer$` (with
   `.option norelax`) instead of restoring from the frame.

3. **`csrw mcause` removed.**  
   The Bumblebee-specific `csrw mcause, t0` (with `KPROCESS_INIT_MCAUSE = 0xB800000B`)
   was removed from the restore sequence. Hazard3 does not use the Bumblebee mcause
   encoding and writing bit 31 may have side effects.

### Phase 3.4 — Timer interrupt validation [done]

**Goal.** Prove the complete hardware interrupt path end-to-end using a bare-metal
`main()` (no kernel, no scheduler) before engaging any kernel code.

**Rationale.** An earlier iteration validated timer hardware by polling
`TIMER0->TIMERAWL` directly, which bypasses the entire interrupt path. That is
insufficient: the interrupt chain (`first_handle_trap` interrupt branch →
`first_dispatch_interrupt` → Xh3irq `meinext` demux → ISR → `mret`) must be
proven on hardware before the scheduler can rely on it.

**Boot path.**  
`boot.c` removed from the build. `crt0` calls `main()` directly. `cmns_init()` is
called unconditionally (no `CONFIG_MAN_SERIAL_S` gate) — same as the ARM target.

**`main.c` sequence (no kernel functions):**
```c
// Reset TIMER0
REG(RESETS)->RESET &= ~RESETS_RESET_TIMER0; /* wait done */
TIMER_C0->INTR = 0xFFFFFFFFU;

// Wire ISR — stores into vExce_indIntVectors via INTERRUPT_VECTOR macro
INTERRUPT_VECTOR(TIMER0_IRQ_0_C0_IRQn, local_alarm0_isr);

h3irq_SetPriority(TIMER0_IRQ_0_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);  // Gate 1a: MEIPRA
h3irq_EnableIRQ  (TIMER0_IRQ_0_C0_IRQn);                             // Gate 1b: MEIEA
core_setBitCSR(RV_CSR_MIE, MIE_MEIE);                                // Gate 2: mie.MEIE

TIMER_C0->ALARM0 = TIMER_C0->TIMERAWL + KTIC_DELTA;
TIMER_C0->INTE   = TIMER_C0->INTE | TIMER_INTE_ALARM_0;

INTERRUPTION_ON_HARD;                                                 // Gate 3: mstatus.MIE

// WFI loop
```

**ISR (`local_alarm0_isr`):**
```c
TIMER_C0->INTR   = TIMER_INTR_ALARM_0;          // acknowledge
TIMER_C0->ALARM0 = TIMER_C0->TIMERAWL + KTIC_DELTA;  // rearm
vTick++;
if ((vTick % 500U) == 0U) { LED_SYSTEM_TOGGLE; cmns_send(KURT0, "tick\r\n"); }
```

**Key finding — three interrupt gates.**  
Hazard3 requires three independent enables. Gate 2 (`mie.MEIE`) was missing from
the earlier kernel model (`model_kernel_runKernel_C0`); added as
`core_setBitCSR(RV_CSR_MIE, MIE_MEIE)` after the `h3irq_EnableIRQ` calls.

**Outcome.**  
`"Phase 3.4: timer armed\r\n"` followed by `"tick\r\n"` every 500 ms confirmed on
UART0. LED_SYSTEM toggles in sync. Full interrupt path validated on hardware.

### Phase 3.4b — Dual-peripheral meinext demux validation [done]

**Outcome.** TIMER0 ALARM0 + UART0 Rx both fire correctly under DIRECT mtvec.
`first_dispatch_interrupt` + `meinext` demux validated for two concurrent peripheral
IRQ sources. LED_SYSTEM blinks every 500 ms; each received character echoes and
triggers `"\r\nrx interrupt\r\n"` + LED_GREEN toggle.

**Goal.** Extend Phase 3.4 to add a second concurrent peripheral IRQ source (UART0 Rx)
to prove that `first_dispatch_interrupt` + `meinext` correctly demux two simultaneous
peripheral interrupts under DIRECT mtvec mode.

**`main.c` additions (on top of Phase 3.4):**
```c
// UART0 Rx interrupt
INTERRUPT_VECTOR(UART0_IRQ_C0_IRQn, local_uart0_rx_isr);
h3irq_SetPriority(UART0_IRQ_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);   // priority 2
h3irq_EnableIRQ  (UART0_IRQ_C0_IRQn);
REG(UART0)->UARTIMSC = UART_UARTIMSC_RXIM | UART_UARTIMSC_RTIM;
```

**ISR (`local_uart0_rx_isr`):**
```c
// drain RX, echo each byte, clear interrupt flags, toggle LED_GREEN
while (RXFE not set) { echo UARTDR; }
UARTICR = RXIC | RTIC;
LED_GREEN_TOGGLE;
cmns_send(KURT0, "\r\nrx interrupt\r\n");
```

**Pass criteria.**
- Timer path unchanged: LED_SYSTEM toggles, `"tick"` every 500 ms.
- Typing any character: byte echoed + `"\r\nrx interrupt\r\n"` on UART0, LED_GREEN toggles.
- Both IRQs fire concurrently without corrupting each other.

### Phase 3.4c — Cooperative context-switch validation [done]

**Goal.** Validate the complete `ecall → first_dispatch_ecall → mret` path using a
hand-written mini-scheduler (adapted from `tests_06.c`), with no kernel symbols
referenced. This directly de-risks the `kern_switchFast` Phase 3.5 blocker.

**Key adaptation from `tests_06.c`:** that test uses a 28-word frame; `first_riscv.c`
saves and restores a 35-word `KERN_SAVE_FRAME`. `init_process_frame()` was written to
match the 35-word layout exactly.

**Observed output (hardware confirmed):**
```
Phase 3.4c: cooperative context-switch
Kernel First    SV 0x2000074C
Kernel First    P0 0x200084D4
Enter P0
Run P0
Kernel go to P1 SV 0x200084B4
Kernel go to P1 P1 0x200087F4
Enter P1
Run P1
Kernel go to P0 SV 0x200087D4
Kernel go to P0 P0 0x200084B4
Run P0
...  (stable steady-state alternation)
```

**Key findings:**
- Steady-state saved-sp values are identical every round trip (no stack drift).
- `0x200084D4 − 0x200084B4 = 0x20` (8 words): C stack consumed by `cmns_send` /
  `cmns_wait` while the process runs — consistent with correct register save/restore.
- gp reload from `__global_pointer$` works: `cmns_send` and `snprintf` execute
  correctly in every process context switch.
- The 35-word frame layout, `mret` path, and `vSaveStack` swap mechanism are all
  correct. Phase 3.5 is unblocked.

### Phase 3.5 — Full kernel boot [in progress — builds clean, awaiting hardware]

**Goal.** Call `kern_init()`, install idle + launcher via `boot.c`, enable timers
with `kern_runKernel()`, then perform the first context switch with
`kern_switchFast()`.

**Implementation.**  
`main()` now delegates directly to `boot()` (46 bytes vs. 9 KB Phase 3.4c).
`boot.c` is added to `proc_p`; it:
1. calls `kern_init()`
2. sets KURT0 as the default serial manager
3. installs idle via `system_getModuleName("idle")` → `kern_createProcess(idle_fn)`
4. installs launcher via `system_getModuleName("launcher")` → `kern_createProcess(launcher_fn)`
5. calls `kern_runKernel()` → enables TIMER0 ALARM0/ALARM1, sets mie.MEIE
6. calls `INTERRUPTION_ON_HARD` → sets mstatus.MIE
7. calls `kern_switchFast()` → first ecall, mret into idle

The launcher then creates all `KID_FAM_PROCESSES` modules (startUp, alive) and
all `KID_FAM_DAEMONS` modules (stimer), then exits. `stub_startUp_launch()` calls
`kern_suspendProcess(500)`, configures UART0 at 460800, and loops with 500 ms ticks.

**Build result.** Clean, zero warnings. Binary: 119 KB (+17 KB vs. Phase 3.4c).

**Acceptance criteria.**
- `kern_switchFast()` completes and the idle process runs.
- `kern_suspendProcess(N)` suspends for N milliseconds ± 1 ms.
- At least two processes running (idle + startUp), with `dprintf` output on UART0.
- Phase 2 coreDump still fires on a deliberate fault.

---

## Flashing

`picotool` is used directly — UF2 files are not used for this target.

```bash
# From Variant_Test/
cmake --preset llvm
cmake --build build --parallel
picotool load -f -x Artefacts/FLASH.elf
```

The board must be in BOOTSEL mode or picotool must have USB access (`picotool` with
`--family rp2350-riscv` or detected automatically).

---

## Verification Points

1. **Serial Console**
   - Port: UART0 (GPIO16 = TX, GPIO17 = RX)
   - Baud: 460800 8N1
   - Phase 3.5 expected output: logo + signature + `"Phase 3.5: scheduler running"`,
     then `"tick N"` every 500 ms

2. **LED Indicator**
   - LED_SYSTEM (GPIO25): toggles every 500 ms (driven by startUp process)

3. **Picobin Block**
   ```bash
   hexdump -C Artefacts/FLASH.bin | grep "d3 de ff ff"
   # Expected: d3 de ff ff 42 01 11 10
   #                             ^^ 0x11 = RISC-V boot item flag
   ```

---

## Reference Documentation

### RP2350 Hazard3 Core
- **ISA:** RISC-V RV32IMAC
- **Privilege Modes:** Machine (M) and User (U) — no Supervisor (S)
- **Standard CSRs:** mstatus, mtvec, mcause, mepc, mie, mip, mhartid
- **Hazard3 custom CSRs (external IRQ ctrl):** meiea, meifa, meipa, meipra, meinext, meicontext
- **Interrupts:** Hazard3-specific external interrupt controller — *not* standard PLIC
- **Features:** Physical Memory Protection (PMP), DIRECT-mode trap entry

---

## Related Targets

- **Pico2_rp2350** — ARM Cortex-M33 version (working reference)
- **Longan_Nano_F103** — RV32IMAC reference (GD32VF103)
- **MAiXDUiNO_K210** — RV64IMAFDC dual-core reference

---

## License

SPDX-License-Identifier: MIT

See main project LICENSE file.
