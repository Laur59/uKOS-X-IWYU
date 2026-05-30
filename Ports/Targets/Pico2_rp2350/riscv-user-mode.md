# SUB-TASK (do first): RISC-V `CPU_FEATURES` processing in `proj_config.cmake`

> Prerequisite/enabler for the parked full plan below. It **replaces** that plan's bespoke
> `SOC_HAS_UMODE` capability flag with a `user_mode` entry in the existing `CPU_FEATURES`
> mechanism. When the full plan resumes, its "mechanism 1" gate must read the new
> `RISCV_FEATURE_UMODE` instead of `SOC_HAS_UMODE`.

## Context

`Ports/cmake/proj_config.cmake` already documents RISC-V `CPU_FEATURES` (`zicsr`, `zifencei`)
in its header (lines 84-90), and the ARM path `configure_arm_core()` fully parses
`CPU_FEATURES` per core (e.g. CORTEX_M33, lines 215-228). But `configure_riscv_core()`
(lines 357-431) **ignores `CPU_FEATURES`** and hardcodes the ISA:
`MARCH_GNU="rv32imac_zicsr_zifencei"`, `MARCH_LLVM="rv32imac"` — note Clang silently omits the
Z-extensions (an existing GNU/LLVM asymmetry). So the documented RISC-V features are a no-op,
there is no way to add further extensions, and there is no capability mechanism for the
upcoming user/privileged split.

This sub-task makes `configure_riscv_core()` consume `CPU_FEATURES` in two categories:
- **ISA extensions** — `zicsr`, `zifencei`, and any further `z*` (zba, zbb, zbs, zicond, …),
  appended to `-march` for **both** GNU and Clang.
- **Capabilities** — `user_mode` (Hazard3 implements M+U+PMP), which drives the privilege-split
  gate at line 29.

## Approach

1. **Minimal base ISA + parsed extensions.** In `configure_riscv_core()` replace the hardcoded
   `MARCH_*` (lines 365-394) with a base (`rv32imac` / `rv64imafdc`) plus a suffix built from
   `CPU_FEATURES`:
   - `foreach(feature IN LISTS CPU_FEATURES)`: if `feature MATCHES "^z[0-9a-z]+$"` →
     `string(APPEND _zext "_${feature}")`; elseif `feature STREQUAL "user_mode"` → skip
     (capability, handled by the gate); else → `message(FATAL_ERROR "Unknown RISC-V CPU
     feature: ${feature}")`.
   - `set(MARCH_GNU "${_base}${_zext}")` and `set(MARCH_LLVM "${_base}${_zext}")` — identical
     extension set for both toolchains (fixes the LLVM omission). With targets declaring
     `zicsr;zifencei`, the GNU march is byte-identical to today.
2. **Capability pre-scan for the gate (ordering fix).** The gate is at line 29 but RISC-V
   feature parsing only happens when `configure_riscv_core()` is called (line 437). Add a tiny
   pre-scan after the toolchain include and before line 29:
   ```cmake
   set(RISCV_FEATURE_UMODE OFF)
   if(CMAKE_SYSTEM_PROCESSOR STREQUAL "RISCV" AND DEFINED CPU_FEATURES AND ("user_mode" IN_LIST CPU_FEATURES))
       set(RISCV_FEATURE_UMODE ON)
   endif()
   ```
   Gate becomes:
   `if(${USER_MODE} AND ((CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM") OR RISCV_FEATURE_UMODE))`.
3. **Declare features in the three RISC-V targets** (before `include(proj_config)`):
   `Longan_Nano_F103` and `MAiXDUiNO_K210` → `set(CPU_FEATURES "zicsr;zifencei")` (preserves
   their march); `Pico2_rp2350` RISC-V branch → `set(CPU_FEATURES "zicsr;zifencei;user_mode")`.
   No silent default is added (rejected: it would mask a forgotten declaration); an omitted
   `zicsr` instead fails loudly at assembly, and unknown features hit the FATAL_ERROR.
4. **Doc + validation parity.** Update the header doc block (lines 84-90) to list `user_mode`.
   RISC-V now errors on unknown features (intentionally stricter than ARM's silent-ignore); no
   legacy RISC-V options exist, so no conflict block is needed.

## Files
- `Ports/cmake/proj_config.cmake` — early capability pre-scan; gate (line 29);
  `configure_riscv_core()` feature parsing (replaces hardcoded ISA, lines 365-394); header doc.
- `Ports/Targets/Pico2_rp2350/Variant_Test/CMakeLists.txt` — `set(CPU_FEATURES
  "zicsr;zifencei;user_mode")` in the RISC-V branch.
- `Ports/Targets/Longan_Nano_F103/Variant_Test/CMakeLists.txt`,
  `Ports/Targets/MAiXDUiNO_K210/Variant_Test/CMakeLists.txt` — `set(CPU_FEATURES "zicsr;zifencei")`.

## Verification
- rp2350: `cmake --preset gcc-nouser -DCORE=RV32IMAC` configures; inspect
  `build/compile_commands.json` (or build `VERBOSE=1`) → GNU march still
  `-march=rv32imac_zicsr_zifencei`, `-mabi=ilp32` (no regression); an LLVM preset now shows
  `-march=rv32imac_zicsr_zifencei` too.
- `gcc -DCORE=RV32IMAC` (USER_MODE=ON) on rp2350 selects `MODE=_pu` (via `RISCV_FEATURE_UMODE`);
  the same on Longan/K210 stays `_p` (config-only check — no GD32/K210 flashing).
- Negative: `CPU_FEATURES "bogus"` → FATAL_ERROR.
- The M-mode rp2350 build (`gcc-nouser -DCORE=RV32IMAC`) stays green. (A `_pu` *link* is not
  expected to succeed yet — that needs the parked plan's R1 scripts; only `MODE`/march wiring
  is validated here.)

---

# PARKED (approved): Add a User/Privileged-mode split build to Pico2_rp2350 RISC-V (RV32IMAC / Hazard3)

## Context

The ARM (Cortex-M33) build of the Pico2_rp2350 target supports privilege separation
via `USER_MODE=ON/OFF`: privileged libraries (`*_p`) and user libraries (`*_u`) are
linked into separate memory regions (`link_p.ld` / `link_pu.ld`), the MPU is programmed
once at init to make kernel RAM/peripherals privileged-only, and the CPU drops user
processes to unprivileged Thread mode via `CONTROL.nPRIV`. The RISC-V build of the same
board currently runs **machine-mode only** — `USER_MODE` is forced to `_p` for all
RISC-V targets and the privilege macros are no-ops.

The rp2350 RISC-V cores (Hazard3) implement **M and U privilege modes plus PMP**, so the
ARM privilege model can be reproduced. This plan adds a user/privileged split build for
rp2350 RISC-V that **mirrors the ARM model**: a *static* two-domain PMP partition (kernel
vs user) set once at init, with `mstatus.MPP` toggled per context switch. Per-process PMP
isolation is explicitly **out of scope** (it remains future work in
`RISC-V_IMPLEMENTATION.md`).

Outcome: `cmake --preset riscv` (no extra flags) eventually produces a U-mode image where
user processes run unprivileged under PMP and privileged daemons run in M-mode, matching
the ARM `USER_MODE=ON` default — reached through hardware-verified sub-phases that never
regress the currently-working M-mode build.

## Hardware facts that shape the design (verified against the vendored SDK)

Source of truth: `Third_Parties/TinyUSB/TinyUSB-current/lib/pico-sdk/src/rp2350/hardware_regs/include/hardware/regs/rvcsr.h`.

- **PMP `cfg` byte bits are transposed (RP2350-E6):** `R = bit 2`, `W = bit 1`, `X = bit 0`,
  `A = bits[4:3]`, `L = bit 7`. A textbook PMP macro (`R=bit0,X=bit2`) is wrong on this chip.
  *(Verified: `R_LSB=2`, `W_LSB=1`, `X_LSB=0` in rvcsr.h.)*
- **TOR is not supported.** The A-field enumerates only `OFF(0)`, `NA4(2)`, `NAPOT(3)`;
  writing TOR sets the region OFF. **All regions must use NAPOT** (naturally-aligned
  power-of-two) — this forces a power-of-two RISC-V memory map, unlike the ARM map.
- **8 dynamic PMP regions (0–7)** are configurable; the relaxed user-grant table uses 3.
  Treat the exact count/behaviour as a hardware-verify item (dump PMP CSRs on first boot).
- **Standard PMP semantics (no `mseccfg`/Smepmp):** M-mode with no matching region is
  *allowed*; U-mode with no match is *denied*. So the dynamic table is a **U-grant list**:
  kernel RAM simply gets *no* region and is U-inaccessible automatically.

Other confirmed structural facts:
- The `_p`/`_u` libraries (`kern_p/kern_u`, `libx_p/libx_u`, `proc_p/proc_u`, `tool_u`,
  `privileges.c` in `kern_u`) are **already built for RISC-V** in `Variant_Test/CMakeLists.txt`
  — no library-list change needed; only `MODE` and `PRIVILEGED_USER_S` are arch-gated today.
- `Longan_Nano_F103` is also `CORE RV32IMAC` and `MAiXDUiNO_K210` is `RV64IMAFDC`; **both must
  stay privileged-only**. The CMake gate must key on a board/SoC capability flag, not on `CORE`.
- `first.c` already saves a 35-word frame and has working per-hart M-mode ecall paths
  (`vMessage[hart]`, `vSaveStack[hart]`) but **runs the handler on the process stack** (no
  `mscratch` swap).

## Approach (the six mechanisms)

1. **CMake gate (capability-keyed) — no new presets.** `Ports/cmake/proj_config.cmake:29` —
   extend the condition so `MODE=_pu` + `PRIVILEGED_USER_S` also applies when a board opts in:
   `if(${USER_MODE} AND ((CMAKE_SYSTEM_PROCESSOR STREQUAL "ARM") OR SOC_HAS_UMODE))`.
   `SOC_HAS_UMODE ON` is set **only** in the rp2350 `Variant_Test/CMakeLists.txt` RISC-V
   branch, before `include(proj_config)`; other RISC-V boards never set it. It is a **static
   board capability** (Hazard3 has M+U+PMP), so it is set from the start — *not* a rollout
   toggle. The `USER_MODE` on/off axis is already supplied by the **existing inherited
   presets** in `Ports/cmake/commonPresets.json` (`gcc`/`llvm` = ON, `gcc-nouser`/
   `llvm-nouser` = OFF); do **not** add a new preset. RISC-V is selected with `-DCORE=RV32IMAC`.
   Hence: M-mode = `gcc-nouser -DCORE=RV32IMAC` (`USER_MODE=OFF` → `_p`); U-mode =
   `gcc -DCORE=RV32IMAC` (`USER_MODE=ON` → `_pu`) — exactly the ARM convention.

2. **Per-process privilege via `mstatus.MPP`.** RISC-V has no persistent per-context
   privilege register; privilege is whatever `mret` consumes from the frame's `mstatus`.
   - `KERN_PREPARE_FRAME` (`Cores/RV32IMAC/.../macros_core_stackFrame.h:163`): seed
     `MPP=0` (U) under `PRIVILEGED_USER_S`, keep `MPP=3` (M) otherwise.
   - Implement `SET_USER_MODE`/`SET_PRIVILEGED_MODE` (`Cores/RV32IMAC/.../macros_core.h:67-73`)
     to edit the `mstatus` word (`sp[2]`) of the next process's saved frame
     (`vKern_stackProc[core]`).
   - Inject the **same decision block ARM uses** into `model_kernel_tim0_ecall_C0.c_inc`
     and `model_kernel_tim1_ecall_C1.c_inc`, after `scheduler_callBackTrap` and before the
     `vSaveStack` write-back: privileged if `oSpecification.oMode==KPROC_PRIVILEGED` or the
     `BPROC_PRIV_ELEVATED` state bit is set, else user. (Mirrors
     `model_kernel_tim_0_a0_a1_svc_C0.c_inc:296-299`.)

3. **Trap from U-mode + protected M-mode trap stack.** In `first.c`/`first_handle_trap`:
   - Branch to the kernel-message/ecall path on **both `mcause==8` (ECallUser) and `==11`
     (ECallMachine)**.
   - Add an `mscratch` stack swap (`csrrw sp,mscratch,sp`) on trap entry/exit so the handler
     runs on a dedicated per-hart M-mode stack (reuse the currently-unused
     `linker_topStackSystem_C0/_C1`), while the 35-word *process* frame is still built on the
     process stack recovered from `mscratch`. `mscratch` **complements** `vSaveStack` (handler
     stack vs. saved process-frame pointer); it does not replace it. Initialize `mscratch` in
     both reset handlers. Gate the whole swap on `PRIVILEGED_USER_S` so the verified `_p` path
     is untouched.

4. **Static PMP partition (mirrors the ARM MPU table).** Add a NAPOT `SET_PMP_REGION` macro
   (analogue of `SET_MPU8_REGION`, same `linker_##name` symbol convention) in the RISC-V
   `Cores/RV32IMAC/.../core_addendum.h`, using the **E6-transposed** R/W/X bits. Program it
   once per core at init from the RISC-V half of `Variant_Test/Runtime/init.c` (today it has
   no MPU/PMP call). Relaxed U-grant table: user RAM (RWX), shared RAM (RW), flash (RX);
   kernel RAM gets no region → U-denied by default.

5. **Linker `_pu` scripts for RISC-V.** Create RISC-V-specific, explicitly-named scripts to
   avoid the `-L` ordering collision with the ARM `system_pu.ld`:
   `Cores/RV32IMAC/Runtime/system_pu_rv.ld` (sections; drop `.ARM.*`, keep
   `.sdata/.sbss/.srodata`, keep `__global_pointer$`, keep the `lib*_p.a:*` /
   `EXCLUDE_FILE(lib*_p.a:*)` split) and `Base/Runtime/link_pu_rv.ld` (a **NAPOT-aligned**
   memory map: kernel block 64 KiB @ `0x20000000`, user block 256 KiB @ `0x20010000`, shared
   at a 64 KiB-aligned base). Select it via the existing `LINKS_LD` hook
   (`system.cmake:211`) in the RISC-V `_pu` branch. Add LLD `ASSERT`s for NAPOT alignment.

6. **gp / small-data hazard mitigation.** With a `_p`/`_u` split, privileged and user
   small-data land in regions far apart, but `gp` reaches only ±2 KiB — gp-relative access to
   the other domain would silently hit the wrong address. Mitigate by compiling the `_pu`
   build with **`-msmall-data-limit=0`** (no `.sdata/.sbss`; globals addressed absolutely),
   set in `proj_config.cmake` `configure_riscv_core()` when `MODE==_pu`. The load-bearing
   `KERN_NEW_FRAME` `la gp,__global_pointer$` reload stays and is harmless.

## Staged implementation (each phase builds, flashes, and is verified on real Pico2 hardware)

No new presets. Staging is driven entirely by which **existing** preset is built: the verified
M-mode image is `gcc-nouser -DCORE=RV32IMAC` (`USER_MODE=OFF` → `_p`) and stays green every
phase, while the U-mode image under construction is `gcc -DCORE=RV32IMAC` (`USER_MODE=ON` →
`_pu`). `SOC_HAS_UMODE` is set in the target from R0 (static capability); because the M-mode
build is reached via the `*-nouser` presets, it is never the thing being changed. Verification
primitives:
USB-CDC0 CLI (`list`, `man`, `dumplog`), LED blink (C0 GPIO25, C1 green), and coreDump on a
deliberate fault.

- **R0 — CMake scaffolding (no behavioural change).** Capability gate (mechanism 1),
  `SOC_HAS_UMODE ON` in the rp2350 RISC-V branch, `-msmall-data-limit=0` conditioned on
  `MODE==_pu`. No new presets. *Verified:* `gcc-nouser -DCORE=RV32IMAC` (M-mode RISC-V) and
  the ARM `gcc` (`_pu`) build, flash and reach CLI exactly as before; `gcc -DCORE=RV32IMAC`
  now selects `_pu` (linker scripts land in R1, so it is not expected to link yet).

- **R1 — Linker `_pu` scripts + small-data off, still M-mode at runtime.** Create
  `system_pu_rv.ld` and `link_pu_rv.ld`; wire `LINKS_LD`. Keep `MPP=3` seeding (no PMP / no
  U-mode yet). *Verified:* `_pu` build links; `readelf -S` shows NAPOT-aligned `prgm_data_p/_u`
  and empty `.sdata/.sbss`; on hardware boots to CLI, `list`/LEDs identical to M-mode.

- **R2 — `mscratch` trap-stack swap (still all M-mode).** Add `mscratch` init in both reset
  handlers + entry/exit swap and process-stack frame build in `first_handle_trap`; branch on
  `mcause 8|11`. All `PRIVILEGED_USER_S`-gated. *Verified:* `_pu` build with all processes
  still M-mode boots to CLI, both cores run, ASMP works, coreDump fires; temporary LOG
  confirms the handler runs on the System stack (swap behaviourally invisible).

- **R3 — PMP programming, processes still M-mode.** Add `SET_PMP_REGION`/attrs/`disable-all`,
  `local_PMP_Configuration()` in the RISC-V `init.c` half + per-core call, NAPOT
  `linker_ST_*`/`K_LOG2_*` equates in `link_pu_rv.ld`. Program the relaxed table; processes
  still `MPP=3` so M-mode bypasses PMP. *Verified:* boots unchanged; temporary CLI/LOG dump of
  `pmpcfg0/1`+`pmpaddr0..7` confirms NAPOT actually latched (guards against silent TOR→OFF) on
  real silicon **before** enforcement is trusted.

- **R4 — Flip processes to U-mode (core milestone).** Add the per-context M/U decision to both
  `_inc` models; implement `SET_USER_MODE`/`SET_PRIVILEGED_MODE`; confirm `KERN_PREPARE_FRAME`
  seeds `MPP=0` under `PRIVILEGED_USER_S`. `proc_u` runs U-mode under PMP; `proc_p` daemons run
  M-mode. *Verified:* boots to CLI over USB-CDC0; `list`/`man`/`dumplog` work; LEDs blink on
  both cores (startUp is U-mode → proves ecall-from-U + mscratch + PMP together); a deliberate
  U-mode write to `0x20000000` faults to coreDump (`mcause=7`), proving isolation is live.

- **R5 — Strict peripheral isolation (optional) + privilege elevation.** Optionally add PMP
  deny regions for SoC peripherals (carefully — kernel MMIO must still work from M-mode); wire
  the RISC-V privilege-elevation macros (`PRIVILEGE_ELEVATE`, `RIGHTS_ELEVATION`,
  `CALL_FNCT_ELEVATION`, `KERN_RETURN_ELEVATION`, `GET_ADDRESS_ELEVATION_CALLER`) so
  `kern_setPrivilegeMode`/`kern_privilegeElevate` work — the RISC-V analogue of ARM `svc #1`,
  honouring the `BPROC_PRIV_ELEVATED` bit already consulted in R4. *Verified:* a U process can
  elevate, touch a privileged resource, and drop back; misuse faults to coreDump.

- **R6 — Finalize parity with ARM (last).** No code "flip" remains (the `USER_MODE=ON` presets
  already select `_pu` for RISC-V once R0–R5 land). Confirm `LINKS_LD` selection is automatic
  for `_pu`, then update `RISC-V_IMPLEMENTATION.md` (remove "M-mode only / PMP deferred"; fix
  the stale `first-riscv.c`/separate-target references) and document the build matrix.
  *Verified:* plain `cmake --preset gcc -DCORE=RV32IMAC && cmake --build build` yields a U-mode
  image that boots on both cores — identical convention to ARM; `gcc-nouser -DCORE=RV32IMAC`
  still yields the M-mode image; ARM `_pu` and the other two RISC-V boards still build
  (regression check).

## Key risks

1. **PMP semantics on Hazard3** — NAPOT-only (TOR silently→OFF), **R/X transposed (E6)**,
   peripherals U-accessible by default. A textbook macro is subtly wrong. Use the SDK field
   layout; dump+verify PMP CSRs on hardware (R3) before trusting enforcement (R4).
2. **Trap-stack reentrancy** — `csrrw sp,mscratch,sp` is non-nestable; safe only because traps
   mask interrupts and kernel paths run masked. A synchronous fault *inside* the handler would
   clobber. Keep the handler fault-free (coreDump backstop); stage it alone in R2.
3. **gp / small-data** — cross-domain ±2 KiB window → silent wrong-address access (same class
   as the documented `0x03030303` gp-fill bug). Mitigate with `-msmall-data-limit=0`; verify
   with `readelf -S`.
4. **NAPOT linker alignment** — the ARM non-power-of-two map (88K/92K/392K) cannot be reused;
   re-derive a power-of-two, naturally-aligned RISC-V `_pu` map. Guard with `.ld` `ASSERT`s.
5. **Dual-core C0/C1 symmetry** — PMP and `mscratch` are per-hart; both reset handlers, both
   `local_PMP_Configuration()` calls, and **both** `_inc` models need the change with the
   correct `KCORE_*`. The existing per-hart `vSaveStack`/`vMessage` arrays are the template.
6. **Build-matrix clarity** — `USER_MODE` is preset-driven, so once `SOC_HAS_UMODE` is set,
   `gcc`/`llvm` presets select `_pu` for RISC-V and `gcc-nouser`/`llvm-nouser` select `_p`.
   During R1–R3 a `gcc`-preset RISC-V image links `_pu` but still runs M-mode at runtime (no
   enforcement until R4) — intended, not a regression, since the verified path is the
   `*-nouser` (M-mode) build. Keep that distinction explicit in commit messages so a `_pu`
   image is never mistaken for "isolation is live" before R4.

## Critical files

- `Ports/EquatesModels/SOCs/rp2350/Runtime/first.c` — mcause 8|11 branch, `mscratch` swap,
  per-hart ecall save/restore, `mscratch` init in reset handlers.
- `Ports/EquatesModels/Cores/RV32IMAC/Includes/macros_core_stackFrame.h` — `KERN_PREPARE_FRAME`
  `mstatus`/MPP seeding (line 163).
- `Ports/EquatesModels/Cores/RV32IMAC/Includes/macros_core.h` — `SET_USER_MODE`/
  `SET_PRIVILEGED_MODE` + elevation macros (lines 55–89).
- `Ports/EquatesModels/Cores/RV32IMAC/Includes/Registers/core_addendum.h` — new
  `SET_PMP_REGION` macro + permission attrs (E6 bit layout).
- `Ports/EquatesModels/SOCs/rp2350/Models/model_kernel_tim0_ecall_C0.c_inc` and
  `model_kernel_tim1_ecall_C1.c_inc` — per-context M/U decision at switch time.
- `Ports/cmake/proj_config.cmake` — capability gate (line 29) + `-msmall-data-limit=0`.
- `Ports/Targets/Pico2_rp2350/Variant_Test/CMakeLists.txt` — `SOC_HAS_UMODE`, `LINKS_LD`.
- `Ports/Targets/Pico2_rp2350/Variant_Test/Runtime/init.c` — RISC-V half:
  `local_PMP_Configuration()` + per-core call.
- New: `Ports/EquatesModels/Cores/RV32IMAC/Runtime/system_pu_rv.ld`,
  `Ports/Targets/Pico2_rp2350/Base/Runtime/link_pu_rv.ld`.

## Reuse (do not reinvent)

- `SET_MPU8_REGION` (`CORTEX_M33/.../core_addendum.h`) and its `init.c:788-794` call table —
  the structural template for `SET_PMP_REGION` and `local_PMP_Configuration()`.
- The ARM per-context privilege decision block (`model_kernel_tim_0_a0_a1_svc_C0.c_inc:296-299`)
  — copy verbatim into the RISC-V `_inc` models.
- The existing per-hart `vSaveStack[hart]`/`vMessage[hart]` mechanism in `first.c` — the
  template for per-hart `mscratch` handling and dual-core symmetry.
- The ARM `link_pu.ld` / `system_pu.ld` pair and the RISC-V `system_p.ld` — bases for the new
  RISC-V `_pu` scripts (region symbols, `lib*_p.a` split, `__global_pointer$`).
- `OS/Lib_kernels/kern/privileges.c` (`kern_setPrivilegeMode`/`kern_privilegeElevate`, already
  `PRIVILEGED_USER_S`-gated and in `kern_u`) — the elevation entry points to wire in R5.

## Verification (end to end)

Build both flavours from `Ports/Targets/Pico2_rp2350/Variant_Test` using the existing presets:
`cmake --preset gcc-nouser -DCORE=RV32IMAC` (M-mode, must stay green every phase) and
`cmake --preset gcc -DCORE=RV32IMAC` (U-mode `_pu`). After each phase: `cmake --build build`, inspect
`readelf -S FLASH.elf` where relevant, `picotool load -f -x FLASH.elf`, then over USB-CDC0 run
`list` (processes/daemons present), `man`, `dumplog`, and confirm LED blink on both cores.
Isolation acceptance (R4): a temporary CLI command writing to kernel RAM `0x20000000` must
trap to coreDump with `mcause=7`, while privileged daemons keep running. ARM `_pu` and the
other two RISC-V boards must still build at R6 (regression check).
