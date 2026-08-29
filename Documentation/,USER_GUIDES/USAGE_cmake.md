<!-- SPDX-License-Identifier: MIT -->
<!-- SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen -->

# CMake Build System Guide

This guide provides comprehensive instructions for building embedded system targets using CMake, supporting both GCC and LLVM toolchains with various configuration options.

## Prerequisites

Before using CMake, ensure the following environment variables are defined:

- `PATH_GCC_ARM` - Path to ARM GCC toolchain
- `PATH_GCC_RVXX` - Path to RISC-V GCC toolchain
- `PATH_LLVM_ARM` - Path to ARM LLVM toolchain
- `PATH_LLVM_RVXX` - Path to RISC-V LLVM toolchain

Optional, required only for the corresponding C library:

- `PATH_LLVM_ARMP` / `PATH_GCC_ARMP` - ARM toolchains for `-DC_LIBRARY=picolibc`
- `PATH_LLVM_RVXXP` / `PATH_GCC_RVXXP` - RISC-V toolchains for `-DC_LIBRARY=picolibc`
- `PATH_LLVM_ARML` / `PATH_LLVM_RVXXL` - LLVM libc toolchains for `-DC_LIBRARY=llvmlibc`

## Quick Start

The simplest way to build a target is to navigate to a **Variant** folder and configure the build:

```shell
mkdir build
cd build
cmake ..
```

This prepares a Unix makefile project. Now you can **build** the firmware and **program** the target:

```shell
make -j
make burn
```

### Complete Example: Nucleo_H743

```shell
cd Ports/Nucleo_H743/Variant_Test
rm -fr build && mkdir build && cd build
cmake ..
make -j
make burn
```

## Build Configuration Options

CMake accepts several build options that control compilation behaviour:

| Option | Default | Description |
|--------|---------|-------------|
| `-DWITH_LISTING=ON/OFF` | OFF | Generate listing and disassembly code from ELF file |
| `-DCANARY=ON/OFF` | ON | Enable/disable canary stack protection |
| `-DUSER_MODE=ON/OFF` | ON | Activate user mode of processor (code protection) |
| `-DUSE_LLVM=ON/OFF` | OFF | Use LLVM toolchain (clang) instead of GCC |
| `-DC_LIBRARY=newlib/picolibc/llvmlibc` | newlib | Select the C library (see below) |
| `-DVERBOSE_LINK=ON/OFF` | OFF | Add verbose option (-v) when linking with lld |

### C Library Selection

The C library is chosen with `-DC_LIBRARY`:

- `newlib` (default) - GCC or Clang, ARM and RISC-V.
- `picolibc` - GCC or Clang, ARM and RISC-V; uses the `PATH_*_ARMP` / `PATH_*_RVXXP`
  toolchains, whose default C library must be picolibc.
- `llvmlibc` - **LLVM/Clang only**, ARM and RISC-V; uses `PATH_LLVM_ARML` /
  `PATH_LLVM_RVXXL` and requires `USE_LLVM=ON`. Combining it with GCC is a
  configuration error.

See **[C-library-selection.md](../USER_GUIDES/C-library-selection.md)** for the full
reference: toolchain requirements, what the build adds per library, and the limitations
of each.

```shell
cmake --preset llvm -DC_LIBRARY=llvmlibc
```

## Using CMake Commands

CMake can handle the entire build process beyond just configuration.

### Advanced Configuration Example

To build a Nucleo_H743 system with user mode disabled and LLVM toolchain:

**Configure the project:**
```shell
cd Ports/Nucleo_H743/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF -DUSE_LLVM=ON
```

**Build the project:**
```shell
cmake --build build --parallel
```

**Program the processor:**
```shell
cmake --build build --target=burn
```

**Build and program in one command:**
```shell
cmake --build build --parallel --target=burn
```

**Clean and rebuild:**
```shell
cmake --build build --parallel --clean-first
```

## Out-of-Source Builds

Projects can be built in any directory outside the source tree:

```shell
cmake -S Ports/Nucleo_H743/Variant_Test -B ${HOME}/mybuilds
cmake --build ${HOME}/mybuilds --parallel
```

Alternatively, you can use traditional make commands:

```shell
cmake -S Ports/Nucleo_H743/Variant_Test -B ${HOME}/mybuilds
cd ${HOME}/mybuilds
make -j
```

## Build Presets

Presets use schema version 10, so **CMake 3.31 or newer is required**.

For convenience, common combinations of build options are available as presets:

```shell
cmake --list-presets
```

Available presets:
- `gcc` - Default GCC build
- `llvm` - Default LLVM build
- `gcc-nocanary` - GCC with user mode, no canary protection
- `gcc-nouser` - GCC without user mode, with canary protection
- `gcc-nouser-nocanary` - GCC without user mode or canary protection
- `llvm-nocanary` - LLVM with user mode, no canary protection
- `llvm-nouser` - LLVM without user mode, with canary protection
- `llvm-nouser-nocanary` - LLVM without user mode or canary protection

### Using Presets

Instead of specifying individual options:
```shell
cmake -B build -DUSE_LLVM=ON -DUSER_MODE=OFF
```

You can use a preset:
```shell
cmake --preset llvm-nouser
```

By default presets use Ninja, therefore there is no need to pass option `--parallel` to build a system.

### Presets for the downloadable applications

The same presets are available from any application board directory, for example:

```shell
cd Applications/uKOS_Appls_Downloadable/p_Specials/test_fatfs/Alastor_H743
cmake --preset llvm
cmake --build build
```

Each application board directory holds a `CMakePresets.json` stub that resolves, through
`Applications/cmake/appPresets.json`, to the same `Ports/cmake/commonPresets.json` used by
the system targets — so there is a single definition of the preset matrix.

Note that `_build.sh` configures applications with explicit `-D` options and therefore uses
the default generator (Unix Makefiles), whereas presets select Ninja. Both build into
`build/`, so run `rm -fr build` before switching between the two in the same directory.

## Build Types Summary

The build system supports two main execution modes:

**Privileged Mode:** All code runs with full processor privileges

```shell
cmake -B build -DUSER_MODE=OFF
```

**User Mode (default):** Enables code protection with separate user and system privileges

```shell
cmake -B build
```

which is equivalent to

```shell
cmake -B build -DUSER_MODE=ON
```

## Toolchain Selection

**GCC Toolchain (default):** Uses ARM/RISC-V GCC compilers

```shell
cmake -B build
```

which is equivalent to

```shell
cmake -B build -DUSE_LLVM=OFF
```

**LLVM Toolchain:** Uses Clang compilers for potentially better optimisation
```shell
cmake -B build -DUSE_LLVM=ON
```

This build system provides flexible options for embedded development, supporting multiple architectures, toolchains, and security configurations to meet various project requirements.
