# PLAN — Split `crt0.c`

**Status:** proposal, awaiting go/no-go.
**Scope:** `Ports/EquatesModels/Generic/Runtime/crt0.c`.
**Author note:** this is a two-phase refactor. Phase 1 is purely mechanical (split the file). Phase 2 is the substantive part (decouple `crt0.c` from the kernel) and is the reason Phase 1 is worth doing at all.

---

## 1. Motivation

`crt0.c` today mixes two concerns in one translation unit:

1. **C-runtime bootstrap** — `crt0()` does BSS init, data copy, heap init, RNG seed, stack-guard install, then calls `exit(boot())`. Runs *before* the kernel exists.
2. **Process exit & panic handling** — `crt0_exit()`, `exit_terminate()`, the `local_panic*` handlers. These run *after* the kernel is up and dereference kernel internals (`vKern_runProc[core]->oSpecification.oIdentifier`, etc.).

This mix has two practical costs:

- **Fragility on the panic path.** `local_panicStackUnderflow()` allocates a 201-byte buffer on the stack while reporting a stack underflow ([crt0.c:354](crt0.c#L354)). The other panic handlers dereference `vKern_runProc[core]` — if kernel state is corrupted enough to trigger the panic, the handler can fault again before printing anything. (See the analysis we did before this plan.)
- **`crt0.c` is not reusable.** Because the same file pulls in `kern/kern.h`, `kern/private/private_processes.h`, `serial/serial.h`, the C-runtime startup cannot be linked into a binary that uses a different kernel, or no kernel at all (e.g. minimal test ROMs, secure boot stubs).

Splitting addresses the second cost directly and is a precondition for fixing the first cleanly.

---

## 2. Phase 1 — Mechanical split

**Goal:** `crt0.c` contains only the C-runtime bootstrap. Everything else moves to a sibling TU. **No behavioural change.**

### 2.1 What stays in `crt0.c`

- `crt0()` — startup ([crt0.c:151](crt0.c#L151))
- `init_relocate()` weak default ([crt0.c:237](crt0.c#L237))
- `vCrt0_randomSeed` definition, `KSTACK_GUARD_VALUE` macro
- `__wrap___stack_chk_fail()` ([crt0.c:253](crt0.c#L253)) — *judgment call.* Coupled to the canary that crt0 installs, but behaves like a panic handler. Default proposal: keep here. Open for review.

### 2.2 What moves to new file `crt0_exit.c`

- `crt0_exit()`, `exit_terminate()`
- `local_killProcess()`, `local_panicMallocBroken()`, `local_panicStackUnderflow()`, `local_panicNoSystemCall()`, `local_panicElevation()`, `local_panicGeneral()`
- The trace/log dump on the exit path. Originally `#include "model_coreDump_tracing.c_inc"`;
  since superseded by calls to `record_printTrace()` / `record_printLog()`, now compiled once in
  `OS/Lib_generics/record/recordDump.c` instead of being textually included by both `crt0_exit.c`
  and every board `exce.c`.
- The kernel/serial/private-process includes that only this code needs (`kern/kern.h`, `kern/private/private_processes.h`, `serial/serial.h`)

### 2.3 What does not change

- **`crt0.h` is untouched.** `crt0_exit` and `exit_terminate` remain externally linkable from a different TU. No header split needed — every existing caller continues to compile unchanged:
  - `OS/Lib_generics/newlib/newlib.c:553` (`crt0_exit`)
  - `OS/Lib_generics/picolibc/picolibc.c:424` (`crt0_exit`)
  - All `Tools/TestRom/*/Includes/Core/macros_core_stackFrame.h` (`exit_terminate`)
- Public symbol names and signatures are preserved.

### 2.4 Sub-decisions to confirm before starting

1. **`MODULE()` declaration.** `crt0.c` carries `MODULE(Crt0, …, KNUM_CRT0, …)`. The new TU needs either:
   - **(a)** its own `MODULE(Crt0_exit, …, KNUM_CRT0_EXIT, …)` with a new identifier in `modules.h`, or
   - **(b)** no `MODULE()` block (if registration is per-feature, not per-TU).

   Default proposal: **(b)**.

2. **`__wrap___stack_chk_fail()` placement.** Stay with `crt0.c` (canary affinity) or move to `crt0_exit.c` (panic affinity)?

   Default proposal: stay with `crt0.c`.

3. **Mirror to `crt0_r_mc.c`.** Same split into `crt0_r_mc_exit.c`, in the same change set, so the two stay in sync.

   Default proposal: no.

4. **TestRom copies.** `Tools/TestRom/*/Runtime/crt0.c` and `Ports/Targets/Pico2_rp2350_RVXX/Variant_Test-xx/Runtime/crt0.c` are independent copies.

   Default proposal: leave alone for now. Per `CLAUDE.md` "ignore Tools/" and the in-flight RVXX-Test-xx variant.

### 2.5 Build-system impact

`grep` finds **21** `CMakeLists.txt` files that compile `crt0.c` or `crt0_r_mc.c` by full path:

- 19 use `crt0.c`: Nucleo_H743, Nucleo_L4R5, Nucleo_F207, Nucleo_N657, Discovery_U5G9, Discovery_V873, Alastor_H743, Asmodee_H747 (×2), DevKit_nRF5340 (×2), Longan_Nano_F103, Pico2_rp2350, Pico2_rp2350_RVXX/Variant_Test, Pico2_rp2350_RVXX/Variant_Test-xx (a copy, skip per §2.4(4)), plus 4 TestRom (skip).
- 1 use `crt0_r_mc.c`: MAiXDUiNO_K210/Variant_Test.

Each of these needs a sibling line for the new `_exit.c` file. No globs in the build system, so this is mechanical but unavoidable.

### 2.6 Phase 1 execution order

1. Create `crt0_exit.c` (with chosen MODULE() decision applied, trimmed includes).
2. Strip moved code (and now-unused includes) from `crt0.c`.
3. Update **one** target's `CMakeLists.txt` (proposed: `Ports/Targets/Nucleo_H743/Variant_Test`) and verify it builds.
4. Roll out the `CMakeLists.txt` change to the remaining 18 single-core targets.
5. Smoke-test one ARM target and one RISC-V target end-to-end (build + boot).

### 2.7 Phase 1 risks

- **Touch surface:** every variant's `CMakeLists.txt` is edited — easy to miss one and get a link error for `crt0_exit`.
- **`MODULE()` identifier collision** if both TUs declare `KNUM_CRT0` — must be resolved per §2.4(1) before linking.
- **No functional change is intended;** if regressions appear, they'll most likely be from include-order differences (a header transitively pulled in via `kern/*.h` no longer reaches `crt0.c`).

---

## 3. Phase 2 — Make `crt0.c` kernel-agnostic

**Goal:** after Phase 1, `crt0.c` no longer references kernel internals, but still depends on a handful of project-wide symbols. Phase 2 nails that contract down so the same `crt0.c` can be linked into:

- the full uKOS-X system (current behaviour),
- a different kernel (replace the contract implementation),
- a bare-metal binary with no kernel (provide minimal stubs).

### 3.1 Define "the crt0 contract"

The minimal set of symbols `crt0.c` is allowed to reference. Everything else is a layering violation.

| Symbol | Purpose | Today's source |
|---|---|---|
| `init_init()` | Low-level pre-init (no statics) | `init.h` |
| `exce_init()` | Install ISR/exception vectors | declared in `crt0.h` |
| `init_relocate()` (weak) | Vector-table relocation hook | `crt0.c` itself |
| `boot()` | Returns `int`, called as `exit(boot())` | `crt0.h` |
| `console_send(channel, str)` | Used by `__wrap___stack_chk_fail` | currently `cmns_send` |
| `EXIT_OS_PANIC` | Stack-smash exit code | currently kernel-side enum |
| Linker symbols | `linker_stDATA`, `linker_stBSS`, `linker_stHeap`, `__stack_chk_guard`, etc. | `linker.h` |
| `GET_RUNNING_CORE`, `KCORE_0` | Multicore guard in `crt0()` | `macros_soc.h` |

Anything outside this list (kernel APIs, process structs, `vKern_*` globals, `serial/*.h`, `kern/*.h`) must not appear in `crt0.c`.

### 3.2 Concrete changes

1. **Decouple console output.** Replace the direct `cmns_send(KSYST, …)` call in `__wrap___stack_chk_fail` with a small abstraction — either:
   - a weak `crt0_console_send(const char *)` defined in `crt0.c` that delegates to `cmns_send` by default and can be overridden, or
   - keep `cmns_send` but document it as part of the contract (cheaper if `cmns` is meant to be the project-wide console anyway).

2. **Promote `EXIT_OS_PANIC` out of the kernel.** Move the `EXIT_OS_*` enum (or just the subset crt0 uses) to a kernel-independent header — e.g. a new `crt0_exitcodes.h`, or a section of `crt0.h`. Kernel-side panic codes can stay where they are. **Move-and-include, not copy** — duplication will drift.

3. **Make `MODULE()` optional.** Today the `MODULE(Crt0, …)` block hard-couples `crt0.c` to `modules.h` and the registration mechanism. Two options:
   - **(a)** wrap it in `#ifndef CRT0_NO_MODULE` so non-uKOS builds compile out the registration, or
   - **(b)** move the `MODULE()` block to a separate `crt0_module.c` (one-liner TU) only linked into uKOS builds.

   Default proposal: **(b)** — keeps `crt0.c` clean of the registration mechanism entirely.

4. **Guard the privileged/USER_MODE branches.** The `#ifdef PRIVILEGED_USER_S` split inside `crt0()` and the `KCORE_0` multicore guard are runtime-model assumptions. Two options:
   - **(a)** compile-time selection via `#ifdef CRT0_MULTICORE` / `#ifdef CRT0_USER_MODE`, or
   - **(b)** keep `crt0.c` (single-core, privileged-only) as the "minimal" reference and let `crt0_r_mc.c` continue to be the multicore variant.

   Default proposal: **(b)** — closer to today's structure, less churn.

5. **Provide a `crt0_stubs.c`** for the "no kernel" case — empty `init_init`, empty `exce_init`, default `boot()` returning `0`, etc. Lives outside `Generic/Runtime/` (e.g. in a `Generic/Runtime/Stubs/` directory) so its presence is opt-in per build.

### 3.3 Phase 2 execution order

1. Land Phase 1 first; verify all 21 targets still build and one ARM + one RISC-V target boots.
2. Move (or copy) `EXIT_OS_PANIC` into a kernel-independent header.
3. Extract `MODULE()` out of `crt0.c` into `crt0_module.c`. Update affected `CMakeLists.txt`.
4. Decide on the console abstraction (weak override vs. document `cmns_send` as contract). Apply.
5. *Optional:* add `crt0_stubs.c` and a documented "minimal build" recipe.

### 3.4 What Phase 2 does **not** do

- Doesn't touch `crt0_exit.c` — that file is *intended* to be kernel-coupled, since process/panic handling is kernel territory. Keeping the split clean is the whole point.
- Doesn't try to make `crt0_r_mc.c` reusable — multicore startup is inherently SoC-specific. Treat it as a uKOS-only file.
- Doesn't change `crt0.h` public symbols — `crt0()`, `crt0_exit()`, `exit_terminate()`, `vCrt0_randomSeed` keep the same names and signatures.

### 3.5 Phase 2 risks

- **Scope creep.** "Make it generic" is open-ended. The contract table in §3.1 is the brake — anything not in that table is out of scope.
- **`EXIT_OS_*` duplication** if codes are copied rather than moved.
- **`MODULE()` extraction** can silently lose the module from `man`/discovery output if a target's build forgets the new `crt0_module.c`. Verify after extraction by checking the registered module list at runtime.

---

## 4. Why also fix the panic-path fragility?

Phase 1 does **not** by itself fix the issues we identified in `local_panicStackUnderflow` (201-byte stack buffer during a stack underflow) or the kernel-pointer dereferences in the other panic handlers. Those are *content* problems inside `crt0_exit.c`, not *structure* problems. They can be fixed:

- **before Phase 1** — same-file edit, low risk;
- **after Phase 1** — easier, because the panic handlers now live alone in a focused TU;
- **never** — accept the fragility.

Default proposal: defer to a separate ticket, prioritised after Phase 2. Listed here for visibility.

---

## 5. Decision points for the team

1. **Approve Phase 1 split as described in §2?** (yes / change scope / no)
2. **`__wrap___stack_chk_fail()` placement** — `crt0.c` or `crt0_exit.c`? (§2.4(2))
3. **`MODULE()` for the new TU** — own MODULE() with new `KNUM_CRT0_EXIT`, or no MODULE() at all? (§2.4(1))
4. **Mirror split to `crt0_r_mc.c` in the same PR?** (§2.4(3))
5. **Approve Phase 2 in principle?** (defer concrete sub-decisions until Phase 1 lands)
6. **Panic-path content fixes** — separate ticket or fold into Phase 1? (§4)

---

## 6. Estimated effort (rough)

| Item | Effort |
|---|---|
| Phase 1, single-core (`crt0.c` → `crt0_exit.c`) incl. CMake rollout | 0.5 day |
| Phase 1, multicore (`crt0_r_mc.c` → `crt0_r_mc_exit.c`) | 0.25 day |
| Phase 1 build sweep + ARM + RISC-V smoke test | 0.25 day |
| Phase 2.1–2.4 (contract, exit codes, MODULE extraction, console) | 1 day |
| Phase 2.5 stubs + minimal build recipe (optional) | 0.5 day |

Total: ~2 days for Phases 1+2, +0.5 day if optional stubs are in scope. Excludes time to fix panic-path content issues (§4).
