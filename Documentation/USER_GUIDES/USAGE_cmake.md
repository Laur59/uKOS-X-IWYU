# CMake Build System Guide

This guide provides comprehensive instructions for building embedded system targets using
CMake, supporting both LLVM and GCC toolchains with various configuration options.

**CMake 3.31 or newer is required** — the presets use schema version 10.

## Prerequisites

Before using CMake, ensure the following environment variables are defined:

- `PATH_LLVM_ARM` - Path to ARM LLVM toolchain
- `PATH_LLVM_RVXX` - Path to RISC-V LLVM toolchain
- `PATH_GCC_ARM` - Path to ARM GCC toolchain
- `PATH_GCC_RVXX` - Path to RISC-V GCC toolchain

If one of these is unset, the toolchain selector falls back to a `clang`,
`arm-none-eabi-gcc` or `riscv64-unknown-elf-gcc` found in `PATH`.

Optional, required only for the corresponding C library — these have **no** fallback:

- `PATH_LLVM_ARMP` / `PATH_GCC_ARMP` - ARM toolchains for `-DC_LIBRARY=picolibc`
- `PATH_LLVM_RVXXP` / `PATH_GCC_RVXXP` - RISC-V toolchains for `-DC_LIBRARY=picolibc`
- `PATH_LLVM_ARML` / `PATH_LLVM_RVXXL` - LLVM libc toolchains for `-DC_LIBRARY=llvmlibc`

## Quick Start

Navigate to a **Variant** folder and configure with a preset:

```shell
cmake --preset llvm
cmake --build build
```

The preset selects the Ninja generator and puts the build tree in `build/`, so
`--parallel` is unnecessary. To program the target:

```shell
cmake --build build --target burn
```

### Complete Example: Nucleo_H743

```shell
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset llvm
cmake --build build
cmake --build build --target burn
```

### Without a preset

Presets are the normal path, but any variant can be configured directly. Use the
`-S` (source) and `-B` (build) options rather than creating the build directory by hand:

```shell
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake -S . -B build
cmake --build build --parallel
```

Without a preset CMake uses its default generator — Unix Makefiles on macOS and Linux —
so `--parallel` is needed, and `make -j` inside `build/` works as well. A `build/`
directory configured by one generator cannot be reused by the other: run `rm -fr build`
before switching between a preset and a plain `cmake -S . -B build`.

## Build Configuration Options

CMake accepts several cache options that control compilation behaviour. Pass them after
the preset, for example `cmake --preset llvm -DWITH_LISTING=ON`.

| Option | Default | Description |
|--------|---------|-------------|
| `-DUSE_LLVM=ON/OFF` | ON | Use the LLVM toolchain (clang); `OFF` selects GCC |
| `-DUSER_MODE=ON/OFF` | ON | Activate user mode of processor (code protection) |
| `-DCANARY=ON/OFF` | ON | Enable/disable canary stack protection |
| `-DC_LIBRARY=newlib/picolibc/llvmlibc` | newlib | Select the C library (see below) |
| `-DCONSTANT_SIG=ON/OFF` | OFF | Embed an all-zero signature instead of the SHA-256 of the image |
| `-DWITH_LISTING=ON/OFF` | OFF | Generate listing and disassembly code from ELF file |
| `-DVERBOSE_LINK=ON/OFF` | OFF | Add verbose option (-v) when linking |
| `-DCSTANDARD=<std>` | c23 | C language standard |
| `-DCXXSTANDARD=<std>` | c++23 | C++ language standard |
| `-DCFLAGS_APPEND=<flags>` | — | Extra compile flags appended to the common set |
| `-DARTEFACTS_DIR=<dir>` | `$PWD/Artefacts` | Where the final images are copied |
| `-DLINKS_LD=<file>` | `${PATH_BASE}/Runtime/link${MODE}.ld` | Linker script |
| `-DLLVMLIBC_CONFIG=<file>` | — | `--config=` file for overlay LLVM-libc installs |

The first four are what the presets set; the rest have no preset and are passed by hand.

### C Library Selection

The C library is chosen with `-DC_LIBRARY`:

- `newlib` (default) - GCC or Clang, ARM and RISC-V.
- `picolibc` - GCC or Clang, ARM and RISC-V; uses the `PATH_*_ARMP` / `PATH_*_RVXXP`
  toolchains, whose default C library must be picolibc.
- `llvmlibc` - **LLVM/Clang only**, ARM and RISC-V; uses `PATH_LLVM_ARML` /
  `PATH_LLVM_RVXXL` and requires `USE_LLVM=ON`. Combining it with GCC is a
  configuration error.

Three presets cover the non-default libraries, so the option is rarely typed by hand:

```shell
cmake --preset llvm-picolibc      # equivalent to: cmake --preset llvm -DC_LIBRARY=picolibc
```

See **[C-library-selection.md](C-library-selection.md)** for the full reference: toolchain
requirements, what the build adds per library, and the limitations of each.

## Using CMake Commands

CMake can handle the entire build process beyond just configuration.

### Advanced Configuration Example

To build a Nucleo_H743 system with user mode disabled and the LLVM toolchain, either use
the matching preset or pass the options:

```shell
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake --preset llvm-nouser
```

```shell
cd Ports/Targets/Nucleo_H743/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF -DUSE_LLVM=ON
```

**Build the project:**
```shell
cmake --build build --parallel
```

**Program the processor:**
```shell
cmake --build build --target burn
```

**Build and program in one command:**
```shell
cmake --build build --parallel --target burn
```

**Clean and rebuild:**
```shell
cmake --build build --parallel --clean-first
```

**Install the images:**
```shell
cmake --install build --prefix <dir>
```

## Out-of-Source Builds

The build tree can live anywhere outside the source tree:

```shell
cmake -S Ports/Targets/Nucleo_H743/Variant_Test -B ${HOME}/mybuilds
cmake --build ${HOME}/mybuilds --parallel
```

> **Note:** `ARTEFACTS_DIR` defaults to `$PWD/Artefacts`, where `$PWD` is the directory
> **the configure command was run from** — not the build directory given to `-B`. Running
> the command above from the repository root therefore leaves the final images in
> `<repo>/Artefacts/`. Pass `-DARTEFACTS_DIR=${HOME}/mybuilds/Artefacts` to keep them
> beside the build tree.

## Build Presets

For convenience, common combinations of build options are available as presets:

```shell
cmake --list-presets
```

Available presets:

| Preset | Toolchain | User mode | Canary | C library |
|---|---|---|---|---|
| `gcc` | GCC | on | on | newlib |
| `llvm` | LLVM | on | on | newlib |
| `gcc-picolibc` | GCC | on | on | picolibc |
| `llvm-picolibc` | LLVM | on | on | picolibc |
| `llvm-llvmlibc` | LLVM | on | on | llvmlibc |
| `gcc-nocanary` | GCC | on | off | newlib |
| `gcc-nouser` | GCC | off | on | newlib |
| `gcc-nouser-nocanary` | GCC | off | off | newlib |
| `llvm-nocanary` | LLVM | on | off | newlib |
| `llvm-nouser` | LLVM | off | on | newlib |
| `llvm-nouser-nocanary` | LLVM | off | off | newlib |

All of them inherit a hidden `base` preset that selects the Ninja generator, sets
`binaryDir` to `build`, and turns on `CMAKE_EXPORT_COMPILE_COMMANDS` — so every configured
variant has a `build/compile_commands.json` to point clangd or IWYU at.

### Using Presets

Instead of specifying individual options:
```shell
cmake -S . -B build -DUSE_LLVM=ON -DUSER_MODE=OFF
```

You can use a preset:
```shell
cmake --preset llvm-nouser
```

Because presets use Ninja, there is no need to pass `--parallel` when building.

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

An application links against the system image of its board, so build the matching
`Ports/Targets/<Board>/Variant_*` first; otherwise the configure step stops on a missing
`Artefacts/FLASH.cnf`. Build both with the same `C_LIBRARY`.

Note that `_build.sh` configures applications with explicit `-D` options and therefore uses
the default generator (Unix Makefiles), whereas presets select Ninja. Both build into
`build/`, so run `rm -fr build` before switching between the two in the same directory.

## Build Types Summary

The build system supports two main execution modes:

**User Mode (default):** Enables code protection with separate user and system privileges

```shell
cmake -S . -B build                     # equivalent to -DUSER_MODE=ON
```

**Privileged Mode:** All code runs with full processor privileges

```shell
cmake -S . -B build -DUSER_MODE=OFF     # or: cmake --preset llvm-nouser
```

On RISC-V the privileged/user split is opt-in per core: it is enabled only when
`user_mode` is listed in the variant's `CPU_FEATURES`. Without it a RISC-V target is
always built privileged-only, even with `-DUSER_MODE=ON`.

## Toolchain Selection

**LLVM toolchain (default):** Uses the Clang compilers

```shell
cmake -S . -B build                     # equivalent to -DUSE_LLVM=ON
```

**GCC toolchain:**

```shell
cmake -S . -B build -DUSE_LLVM=OFF      # or: cmake --preset gcc
```

This build system provides flexible options for embedded development, supporting multiple
architectures, toolchains, and security configurations to meet various project
requirements.
