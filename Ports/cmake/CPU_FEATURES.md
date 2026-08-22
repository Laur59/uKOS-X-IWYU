# CPU Features Configuration Guide

## Overview

`CPU_FEATURES` is a CMake list that declares the optional capabilities of the target core. It is read by `Ports/cmake/proj_config.cmake` (the system build) and translated into compiler and linker flags and, for Clang, the target triple. Feature names are **case-sensitive**.

The application build (`Applications/cmake/proj_config.cmake`) uses fixed per-core flags and does not read `CPU_FEATURES`.

## Quick Start

1. Identify the core of your target (`CORE`, e.g. `CORTEX_M55`)
2. Pick features from the list valid for that core (see [Feature Reference](#feature-reference))
3. Set `CPU_FEATURES` before `include(proj_config)`:

```cmake
set(SOC STM32N657)
set(CORE CORTEX_M55)
set(CPU_FEATURES "Helium;Double")
include(proj_config)
```

The list form `"Helium;Double"` and the multi-argument form `"Helium" "Double"` are equivalent.

## Feature Reference

`-mthumb` is always added on ARM cores and is omitted from the tables below. Every flag listed is applied to both the compiler and the linker.

### ARM Cortex-M3

No configurable features.

| Configuration | Flags | LLVM triple |
|---|---|---|
| Default | `-mcpu=cortex-m3 -mfloat-abi=soft` | `thumbv7m-unknown-none-eabi` |

### ARM Cortex-M4

**nofp** - Disable the FPU
- Soft-float ABI, no `-mfpu`
- Use case: variants without an FPU, smallest code size

| Configuration | Flags | LLVM triple |
|---|---|---|
| Default | `-mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16` | `thumbv7em-unknown-none-eabihf` |
| `"nofp"` | `-mcpu=cortex-m4+nofp -mfloat-abi=soft` | `thumbv7em-unknown-none-eabi` |

### ARM Cortex-M7

**Double** - Double-precision FPU
- Selects `-mfpu=fpv5-d16` instead of the single-precision `fpv5-sp-d16`

**nofp** - Disable the FPU
- Soft-float ABI, no `-mfpu`
- Takes precedence over `Double`

| Configuration | Flags | LLVM triple |
|---|---|---|
| Default | `-mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16` | `thumbv7em-unknown-none-eabihf` |
| `"Double"` | `-mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16` | `thumbv7em-unknown-none-eabihf` |
| `"nofp"` | `-mcpu=cortex-m7+nofp -mfloat-abi=soft` | `thumbv7em-unknown-none-eabi` |

### ARM Cortex-M33

**nodsp** - Disable the DSP instructions
- Appends `+nodsp` to `-mcpu`
- Use case: cores synthesised without the DSP extension

**nofp** - Disable the FPU
- Appends `+nofp`, soft-float ABI, no `-mfpu`
- Use case: network core of dual-core SoCs (nRF5340)

The `+` suffixes are appended in the order the features are listed. The LLVM triple stays `thumbv8m.main-unknown-none-eabihf` for every M33 configuration; Clang honours `-mfloat-abi=soft` and selects the soft-float multilib.

| Configuration | Flags |
|---|---|
| Default | `-mcpu=cortex-m33 -mfloat-abi=hard -mfpu=fpv5-sp-d16` |
| `"nodsp"` | `-mcpu=cortex-m33+nodsp -mfloat-abi=hard -mfpu=fpv5-sp-d16` |
| `"nofp"` | `-mcpu=cortex-m33+nofp -mfloat-abi=soft` |
| `"nodsp;nofp"` | `-mcpu=cortex-m33+nodsp+nofp -mfloat-abi=soft` |

```cmake
# nRF5340 network core (Ports/Targets/DevKit_nRF5340/Variant_Test_Net)
set(SOC nRF5340)
set(CORE CORTEX_M33)
set(CPU_FEATURES "nodsp;nofp")
include(proj_config)
```

### ARM Cortex-M55

Cortex-M55 and Cortex-M85 are configured with `-march=armv8.1-m.main+...` only, **without `-mcpu=`**, because GCC and Clang use incompatible `-mcpu=` feature syntaxes (GCC subtractive, Clang additive). `-mfpu` is never emitted for these cores; the FPU/MVE configuration is carried entirely by the `-march` extensions.

**Helium** - Arm Helium M-Profile Vector Extension (MVE)
- Appends `+mve.fp`: integer and single-precision floating-point vector processing (implies the scalar single-precision FPU)
- Use case: machine learning, neural networks, signal processing

**Double** - Double-precision FPU
- Appends `+fp.dp`; combines with `Helium`

**nofp** - Disable the FPU
- Appends `+nofp`, soft-float ABI, LLVM triple switches to `...-eabi`

Precedence: `Helium` > `Double` > `nofp`. `nofp` is ignored when `Helium` or `Double` is also listed.

| Configuration | Flags | LLVM triple |
|---|---|---|
| Default | `-march=armv8.1-m.main+fp -mfloat-abi=hard` | `thumbv8.1m.main-unknown-none-eabihf` |
| `"Helium"` | `-march=armv8.1-m.main+mve.fp -mfloat-abi=hard` | `thumbv8.1m.main-unknown-none-eabihf` |
| `"Helium;Double"` | `-march=armv8.1-m.main+mve.fp+fp.dp -mfloat-abi=hard` | `thumbv8.1m.main-unknown-none-eabihf` |
| `"Double"` | `-march=armv8.1-m.main+fp.dp -mfloat-abi=hard` | `thumbv8.1m.main-unknown-none-eabihf` |
| `"nofp"` | `-march=armv8.1-m.main+nofp -mfloat-abi=soft` | `thumbv8.1m.main-unknown-none-eabi` |

```cmake
# STM32N657 (Ports/Targets/Nucleo_N657 and Discovery_N657)
set(SOC STM32N657)
set(CORE CORTEX_M55)
set(CPU_FEATURES "Helium;Double")
include(proj_config)
```

### ARM Cortex-M85

Same features, flags and precedence as Cortex-M55, plus:

**PACBTI** - Pointer Authentication and Branch Target Identification
- Appends `+pacbti` (always last) and adds `-mbranch-protection=standard`
- Orthogonal to `Helium` and `Double`; ignored when `nofp` is listed (PACBTI requires the FPU)
- Use case: security-critical applications (protection against ROP/JOP attacks)

| Configuration | Flags |
|---|---|
| Default | `-march=armv8.1-m.main+fp -mfloat-abi=hard` |
| `"Helium;PACBTI"` | `-march=armv8.1-m.main+mve.fp+pacbti -mfloat-abi=hard -mbranch-protection=standard` |
| `"Helium;Double;PACBTI"` | `-march=armv8.1-m.main+mve.fp+fp.dp+pacbti -mfloat-abi=hard -mbranch-protection=standard` |
| `"nofp;PACBTI"` | `-march=armv8.1-m.main+nofp -mfloat-abi=soft` (PACBTI dropped) |

```cmake
# STM32V873 (Ports/Targets/Discovery_V873)
set(SOC STM32V873)
set(CORE CORTEX_M85)
set(CPU_FEATURES "Helium;PACBTI")
include(proj_config)
```

### ARM Cortex-A7

No configurable features. Flags: `-mcpu=cortex-a7`. No LLVM target triple is defined for this core (a warning is issued when building with LLVM).

### RISC-V Cores

The base ISA and the ABI are fixed per core; `CPU_FEATURES` adds ISA extensions and capabilities on top of them.

| Core | Base `-march` | `-mabi` | Other flags | LLVM triple |
|---|---|---|---|---|
| RV32IMAC | `rv32imac` | `ilp32` | `-gdwarf-4` | `riscv32-unknown-elf` |
| RV32IMAFDC | `rv32imafdc` | `ilp32d` | `-gdwarf-4` | `riscv32-unknown-elf` |
| RV32EMAC | `rv32emac` | `ilp32e` | `-gdwarf-4` | `riscv32-unknown-elf` |
| RV64IMAFC | `rv64imafc` | `lp64f` | `-mcmodel=medany -gdwarf-4` | `riscv64-unknown-elf` |
| RV64IMAFDC | `rv64imafdc` | `lp64d` | `-mcmodel=medany -gdwarf-4 -ffast-math -fno-math-errno -fno-zero-initialized-in-bss -Wno-format -Wno-format-security` (GCC also: `-fstrict-volatile-bitfields -ffunction-sections -fdata-sections`) | `riscv64-unknown-elf` |

**`z...`** - Any RISC-V Z-extension (`zicsr`, `zifencei`, `zba`, `zbb`, `zbs`, `zbkb`, `zca`, `zcb`, `zcmp`, ...)
- Every token matching `z[0-9a-z]+` is appended to `-march` as `_<ext>`, in the listed order, identically for GCC and Clang
- Requesting any `zc*` code-size extension drops the monolithic `c` from the base ISA (Zca/Zcb/Zcmp supersede C; list `zca` to keep compression). This follows the RP2350 datasheet recommendation and avoids older assemblers rejecting `c` together with `zcmp`
- Extension names are not checked against the toolchain: an extension the compiler does not know fails at compile time

**user_mode** - Privileged/user split capability (not an ISA extension)
- No effect on `-march`
- Enables the privileged/user build (`MODE _pu`, `PRIVILEGED_USER_S` defined, `-msmall-data-limit=0`) when `USER_MODE` is `ON`. Without it a RISC-V target is always built privileged-only (`_p`), even with `-DUSER_MODE=ON`
- Requires M+U mode and PMP support in the core and in the port (e.g. RP2350 Hazard3)

Any other token is rejected with `Unknown RISC-V CPU feature: '<name>' (CORE=<core>)`.

| Core | `CPU_FEATURES` | Resulting flags |
|---|---|---|
| RV32IMAC (Longan Nano) | `"zicsr;zifencei"` | `-march=rv32imac_zicsr_zifencei -mabi=ilp32` |
| RV64IMAFDC (MAiXDUiNO K210) | `"zicsr;zifencei"` | `-march=rv64imafdc_zicsr_zifencei -mabi=lp64d -mcmodel=medany` |
| RV32IMAC (Pico2 RP2350) | `"zicsr;zifencei;zba;zbb;zbs;zbkb;user_mode"` | `-march=rv32imac_zicsr_zifencei_zba_zbb_zbs_zbkb -mabi=ilp32`, `_pu` build |
| RV32IMAC | `"zicsr;zifencei;zca;zcb;zcmp"` | `-march=rv32ima_zicsr_zifencei_zca_zcb_zcmp -mabi=ilp32` |

## Behind the Scenes

### What CPU_FEATURES Does

`include(proj_config)` calls `configure_arm_core()` or `configure_riscv_core()` depending on `CMAKE_SYSTEM_PROCESSOR`. The function:

1. **Rejects legacy mixes** (ARM): specifying `CPU_FEATURES` together with `NOFPU` or `CPU_SPEC` is a fatal error
2. **Builds the compiler flags** from the core and its features: `-mcpu=` or `-march=`, `-mfloat-abi=`, `-mfpu=` (where used), `-mbranch-protection=standard` for PACBTI, and the RISC-V `-mabi=` / `-mcmodel=`
3. **Applies the same flags to the linker** (`add_link_options`)
4. **Selects the LLVM target triple** (`CMAKE_C_COMPILER_TARGET`, `CMAKE_CXX_COMPILER_TARGET`; RISC-V also `CMAKE_ASM_COMPILER_TARGET`) when building with Clang
5. **Gates the privileged/user split** on RISC-V through the `user_mode` capability

The compile flags are attached to the `core_compiler_flags` interface library that every system target links against. No compile definition is derived from `CPU_FEATURES`.

### Validation

- **ARM cores**: an unknown or misspelt feature (`"helium"`, `"mve"`, `"pacbti"`, ...) is a fatal configuration error that lists the valid names; cores without features (Cortex-M3, Cortex-A7) reject any name
- **RISC-V cores**: an unknown token is a fatal configuration error
- **Feature interactions** are resolved by precedence, not by errors: Cortex-M7 `nofp` > `Double`; Cortex-M55/M85 `Helium` > `Double` > `nofp`; Cortex-M85 `PACBTI` is dropped when `nofp` is listed

### Legacy Variables

- **`NOFPU`** - when *defined* (with any value) `-mfpu` is omitted from the ARM flags. Do not use it; set `CPU_FEATURES "nofp"` to disable the FPU
- **`CPU_SPEC`** - not consumed by the system build; it is only checked for the conflict with `CPU_FEATURES`

No deprecation warning is emitted for either variable.

## Troubleshooting

### Error: Unknown ARM CPU feature

```
CMake Error: Unknown ARM CPU feature: 'mve' (CORE=CORTEX_M55)
Valid features for CORTEX_M55: Helium, Double, nofp
```

Names are case-sensitive: use `Helium`, `Double`, `PACBTI`, `nodsp` and `nofp` exactly as written (see [From the Former Feature Names](#from-the-former-feature-names)).

### Error: Unknown RISC-V CPU feature

```
CMake Error: Unknown RISC-V CPU feature: 'xyz' (CORE=RV32IMAC)
```

Only `z...` extension names and `user_mode` are accepted on RISC-V cores. Check the spelling.

### Error: Cannot specify both CPU_FEATURES and legacy options

```
CMake Error: Cannot specify both CPU_FEATURES and legacy options (NOFPU/CPU_SPEC).
Please use only CPU_FEATURES for feature configuration.
```

Remove `NOFPU` / `CPU_SPEC` and express the configuration with `CPU_FEATURES` (see [Migration Guide](#migration-guide)).

### Linker errors or wrong multilib

All objects and libraries of a build must share the same `CPU_FEATURES`: the flags select the toolchain multilib (Clang picks `armv8.1m.main_hard_fpdp_nomve_...` for `"Helium;Double"`, `armv8m.main_soft_nofp_...` for M33 `"nodsp;nofp"`), and mixing hard/soft float or MVE/non-MVE objects fails at link time or at run time.

### Performance

- `Helium` on its own does not vectorise anything: the compiler auto-vectorises suitable loops at `-O2`/`-O3`, otherwise MVE intrinsics are required
- `nofp` with floating-point code falls back to soft-float emulation, which is very slow
- `nodsp` disables the saturating/SIMD instructions used by optimised DSP library functions

## Migration Guide

### From NOFPU

```cmake
# OLD
set(NOFPU ON)

# NEW: keep the FPU (the default) - remove the line entirely,
# or disable the FPU completely:
set(CPU_FEATURES "nofp")
```

### From CPU_SPEC

```cmake
# OLD
set(CPU_SPEC "-mcpu=cortex-m33+nodsp+nofp")
# NEW
set(CPU_FEATURES "nodsp;nofp")

# OLD
set(CPU_SPEC "-march=armv8.1-m.main+mve.fp+fp.dp")
# NEW
set(CPU_FEATURES "Helium;Double")

# OLD
set(CPU_SPEC "-mcpu=cortex-m33")
# NEW: remove the line - the default M33 configuration is correct
```

### From the Former Feature Names

Earlier revisions of this guide used the names `mve`, `mve.fp` and `pacbti`. The implementation rejects them with `Unknown ARM CPU feature`; map them as follows:

| Former name | Current name |
|---|---|
| `mve`, `mve.fp` | `Helium` |
| `pacbti` | `PACBTI` (Cortex-M85 only) |

## Verification

### Checking Compiler Flags

```bash
cd Ports/Targets/Your_Target/Variant_xxx
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
grep -o -E -- '-m(cpu|arch|fpu|float-abi|abi|cmodel|branch-protection)=[^ "]+' build/compile_commands.json | sort -u
```

or, on an existing build, `cmake --build build --verbose 2>&1 | grep -E -- '-m(cpu|arch|fpu|float-abi)'`.

### Expected Flag Patterns

| Core / features | Flags |
|---|---|
| Cortex-M55 `"Helium;Double"` | `-mthumb -march=armv8.1-m.main+mve.fp+fp.dp -mfloat-abi=hard` |
| Cortex-M55 default | `-mthumb -march=armv8.1-m.main+fp -mfloat-abi=hard` |
| Cortex-M85 `"Helium;PACBTI"` | `-mthumb -march=armv8.1-m.main+mve.fp+pacbti -mfloat-abi=hard -mbranch-protection=standard` |
| Cortex-M33 `"nodsp;nofp"` | `-mthumb -mcpu=cortex-m33+nodsp+nofp -mfloat-abi=soft` |
| Cortex-M7 default | `-mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-sp-d16` |
| RV32IMAC `"zicsr;zifencei"` | `-march=rv32imac_zicsr_zifencei -mabi=ilp32` |

### Build Verification

```bash
cd Ports/Targets/Your_Target/Variant_xxx
rm -rf build
cmake -S . -B build && cmake --build build          # GCC
rm -rf build
cmake --preset llvm && cmake --build build          # LLVM/Clang
```

## Adding a Feature

There is no table-driven feature database: each core's features are hard-coded in `configure_arm_core()` / `configure_riscv_core()` in `Ports/cmake/proj_config.cmake`.

1. ARM: add the name to the core's `<CORE>_VALID_FEATURES` list at the top of `configure_arm_core()`, then to the `foreach(feature IN LISTS CPU_FEATURES)` loop of the core, and set the flag variables (`MCPU` / `MARCH`, `MFLOAT_ABI`, `MFPU`, `LLVM_TARGET`, `EXTRA_COMPILE_FLAGS`). RISC-V: extend the token parser in `configure_riscv_core()`
2. Update the `VALID FEATURES BY CORE` comment at the top of `proj_config.cmake` and the per-core `features:` comment next to the loop
3. Document the feature in this guide and in the `CPU Features Configuration` section of `CLAUDE.md`
4. Verify the generated flags and a full build with both GCC and LLVM
5. Check that the corresponding `Ports/Mkfiles/{gcc,llvm}_system_<CORE>.mk` (fixed per-core `CPU_SPEC`) still agree with the CMake flags

## See Also

- `Ports/cmake/proj_config.cmake` - implementation (`configure_arm_core()`, `configure_riscv_core()`)
- `Ports/Mkfiles/gcc_system_<CORE>.mk`, `llvm_system_<CORE>.mk` - Make build equivalents
- `CLAUDE.md` - project overview and the short form of this guide
- Arm Cortex-M55 / Cortex-M85 Technical Reference Manuals - Helium/MVE and PACBTI
- RISC-V ISA manual - Zc* code-size extensions
