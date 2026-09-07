# The stub port layer

Stand-ins for the per-core and per-SoC headers, so that a CLI module needing
nothing from them but a couple of macros can be host-tested.

Only what is currently exercised lives here; a stub arrives with the first
module that needs it.

This is the **only** place the harness departs from "every project header is the
real one". It is deliberately narrow, and what it does *not* assert matters as
much as what it does.

## What each stub provides

| Stub | Defines | Replaces |
|---|---|---|
| `macros_core.h` | `PRIVILEGE_ELEVATE`, `PRIVILEGE_RESTORE` | `Cores/<CORE>/Includes/macros_core.h` — 9 variants, almost entirely inline assembly |
| `macros_soc.h` | `KNB_CORES`, `KCORE_0`, `GET_RUNNING_CORE`, `MCSET(v)` | `SOCs/<SOC>/Includes/macros_soc.h` — 11 variants |
| `macros_core_stackFrame.h` | `KKERN_SZ_STACK_SS` | the context-switch frame layout |
| `linker.h` + `linker_symbols.c` | the eight `linker_*_KERN_p` symbols, as **pointers** | `Generic/Runtime/linker.h` |


Everything the real headers additionally define is **deliberately absent**, so a
module that reaches for one fails to build rather than silently testing a
fiction.

## What the privilege stub proves, and what it does not

`PRIVILEGE_ELEVATE` and `PRIVILEGE_RESTORE` are copied verbatim from
`Cores/CORTEX_M7/Includes/macros_core.h`, so under `PRIVILEGED_USER_S` they call
the real `kern_setPrivilegeMode()`. `run-tests.sh` diffs the copy against that
original and aborts on divergence; it also compares the same block across the
other cores and warns if they drift apart.

That copy makes it possible to assert **pairing and count** — that a module
elevates before touching a kernel table and restores on *every* return path,
including early error exits.

It asserts nothing about **effect**. Not that `CONTROL.nPRIV` changes, not that
the SVC dispatch is correct, not that an unelevated access faults, not that the
MPU is configured, not that `kern_setPrivilegeMode()` is even implemented on the
target. All of that belongs to the board.

Each tier-2 module is built twice — with `PRIVILEGED_USER_S` and without — so
both arms of the real header are covered. The `_nouser` target is the second.

## Why `linker.h` declares pointers

The real header is generic and declaration-only, so it looks portable. It is
stubbed anyway, because the declarations carry over but the *semantics* do not:
the symbols are placed by the linker script, and two of their properties cannot
be reproduced by defining host arrays.

- `szkern` computes `en - st` for four section pairs. Two independently defined
  host arrays have no guaranteed relative placement; the difference is whatever
  the Mach-O linker happens to produce, and can be negative.
- `hexloader` and `sloader` read `linker_lnUMemo`'s **address as a length**. No
  C definition can give a symbol a chosen address.

Declaring pointers instead, with `ukos_fake_setKernelImage()` as the setter,
reproduces both. Every use in the affected modules is an immediate cast —
`(uintptr_t)`, `(uint8_t *)`, `(size_t)` — so the module source and its
observable behaviour are unchanged; only the declaration form differs.

This is what lets a test place the kernel image where it likes and then assert
the printed addresses, and what makes `szkern`'s `en < st` case reachable at all
— on a target the linker guarantees it cannot happen.

## Other divergences worth knowing

- `GET_RUNNING_CORE` is a settable function rather than a constant, so the
  `vXxx[core]` subscripts are exercised. On a real multi-core SoC it is an MMIO
  read.
- `KNB_CORES` is `1U`, matching every shipped SoC. A suite may raise it through
  `DEFINES` to exercise the per-core loops, but that configuration runs on **no
  board** and must be commented at the call site.
- Host `uintptr_t` is 64-bit. `dump` formats addresses with `0x%016X`, which is
  correct for the target and truncates here, so no test asserts the address
  column. See `../DEFECTS.md`.

## Adding a module to this tier

```cmake
ukos_add_cli_module_test(PORT_STUB
    NAME          ukos_tests_port_<module>
    MODULE_SOURCE ${UKOS_ROOT}/OS/CLI/<module>/<module>.c
    TEST_SOURCE   cli/port/test_<module>.c
    DEFINES       PRIVILEGED_USER_S)
```

`PORT_STUB` links `ukos_port_support` instead of `ukos_test_support`, which is
what puts `port/` on the include path. Tier-2 executables are named
`ukos_tests_port_*`, their sources live in `cli/port/`, and they print
`[port stubs: …]` under the suite name — so a run against stubs is
self-labelling and never has to be remembered.

If a stub is missing something the module needs, **add it to the stub only if it
is genuinely inert on a host**. A macro whose real definition does work — an
interrupt mask, a memory barrier, a context-switch frame — must not be stubbed
into a no-op; that module belongs on the board instead.

### The one sanctioned exception, and why it is not a no-op

`INTERRUPTION_OFF` / `INTERRUPTION_RESTORE` are in this header even though an
interrupt mask is named above. Every kernel file masks — `lists.c`, the cleanest
of them, masks twice — so tier 3 would otherwise not exist at all.

They are **not** stubbed into no-ops. `INTERRUPTION_OFF` returns a token and
`INTERRUPTION_RESTORE` checks it, so the fake counts the scopes and verifies
they unwind LIFO. An early `return` that skips its restore leaves the depth
non-zero and fails the test. That is a real bug class and the reason the pair is
worth having: `pools.c` alone has 26 restore sites across six error-heavy
functions, and dropping one from an error arm is caught.

The honesty limit is the same as `PRIVILEGE_ELEVATE` next door: **pairing and
order, never effect**. Nothing here asserts that a mask is applied, that a
BASEPRI is written, or that an interrupt is actually deferred.

They live in `macros_soc.h` rather than `macros_core.h` because `lists.c` and
`scheduler.c` guard that include with `#ifdef __arm__`, which is false under
Apple clang — so `macros_soc.h` is the only port header they see on a host, and
every `kern/*.c` includes it. Being a mirror of
`Cores/CORTEX_M7/Includes/macros_core.h:166-176` rather than a copy, the block
cannot be drift-checked; `kern/test_kernenv.c` pins the contract instead.
