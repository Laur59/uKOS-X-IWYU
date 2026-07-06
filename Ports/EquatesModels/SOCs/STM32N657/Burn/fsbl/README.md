# STM32N657 FSBL - Build Instructions

This package contains a pre-configured First Stage Boot Loader (FSBL) project for the STM32N657 in Load-and-Run mode. It supports two boards:

| Board | CMake `BOARD` value | NOR flash chip |
|-------|---------------------|----------------|
| **NUCLEO-N657X0-Q** | `NUCLEO` | MX25UM51245G (512 Mbit) |
| **Discovery_N657 (STM32N6570-DK)** | `DISCOVERY_N657` | MX66UW1G45G (1 Gbit) |

`BOARD` is mandatory — no default. Use one of the presets below.

**Key Feature:** This project builds directly from STM32CubeN6 sources without copying files, making it easy to update to new STM32Cube versions.

## What is this?

The FSBL is a bootloader that runs from AXISRAM2 (address 0x3418_0400) and copies your application from external NOR flash to internal SRAM before jumping to it. This is required because the STM32N657 has no internal flash.

The build produces an unsigned `fsbl.bin`. The Boot ROM requires a trusted header; signing is done at flash time by the programmer script, not by this CMake build.

## Prerequisites

Install the following tools:

| Tool | Version | Installation |
|------|---------|--------------|
| **arm-none-eabi-gcc** | 12+ | ARM GCC toolchain with Cortex-M55 support |
| **CMake** | 3.22+ | `brew install cmake` (macOS) or package manager |
| **Ninja** | Latest | `brew install ninja` (macOS) or package manager |
| **STM32CubeProgrammer** | 2.18+ | Download from [st.com](https://www.st.com/en/development-tools/stm32cubeprog.html) |
| **Git** | Any | For cloning STM32CubeN6 |

**Note:** You do NOT need STM32CubeIDE.

### Toolchain not in PATH?

If `arm-none-eabi-gcc` is installed to a non-standard location, pass its `bin/` directory via `TOOLCHAIN_PATH`:

```bash
cmake --preset nucleo -DTOOLCHAIN_PATH=/opt/embedded/cross/gcc-16.1.0/arm/bin
```

The value is cached after the first configure, so subsequent builds don't need it.

For a permanent machine-local override, create `CMakeUserPresets.json` (already gitignored):

```json
{
    "version": 6,
    "configurePresets": [
        {
            "name": "local-toolchain",
            "hidden": true,
            "cacheVariables": {
                "TOOLCHAIN_PATH": "/opt/embedded/cross/gcc-16.1.0/arm/bin"
            }
        },
        { "name": "nucleo-l",    "inherits": ["nucleo",    "local-toolchain"] },
        { "name": "discovery-l", "inherits": ["discovery", "local-toolchain"] }
    ],
    "buildPresets": [
        { "name": "nucleo-l",    "configurePreset": "nucleo-l" },
        { "name": "discovery-l", "configurePreset": "discovery-l" }
    ]
}
```

Then use `cmake --preset nucleo-l` (the `-l` suffix avoids the CMake v6 restriction on reusing project preset names).

## Quick Start

### NUCLEO-N657X0-Q

```bash
# 1. Clone STM32CubeN6 inside the project
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git

# 2. Configure and build
cmake --preset nucleo
cmake --build build/nucleo

# 3. Flash (signing is done by the flash programmer)
./scripts/flash_fsbl.sh build/nucleo
```

### Discovery_N657 (STM32N6570-DK)

```bash
# 1. Clone STM32CubeN6 inside the project
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git

# 2. Configure and build
cmake --preset discovery
cmake --build build/discovery

# 3. Flash (signing is done by the flash programmer)
./scripts/flash_fsbl.sh build/discovery
```

The flash script automatically searches for the correct external loader
(`MX66UW1G45G_STM32N6570-DK.stldr` or `MX25UM51245G_STM32N6570-NUCLEO.stldr`)
in the standard STM32CubeProgrammer installation paths.

## Available Presets

| Preset | Board | Build type |
|--------|-------|------------|
| `nucleo` | NUCLEO-N657X0-Q | Release |
| `discovery` | Discovery_N657 (STM32N6570-DK) | Release |

```bash
cmake --preset nucleo    && cmake --build build/nucleo
cmake --preset discovery && cmake --build build/discovery
```

## Configuring STM32CubeN6 Location

Three ways to specify STM32CubeN6, in priority order:

```bash
# 1. CMake command line (highest priority)
cmake --preset nucleo -DCUBE_ROOT=/path/to/STM32CubeN6

# 2. Environment variable
export STM32CUBEN6_ROOT=/path/to/STM32CubeN6
cmake --preset nucleo

# 3. Default — clone into the project directory (lowest priority)
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git
cmake --preset nucleo
```

> **Important:** Always use `--recursive` when cloning STM32CubeN6 to get the CMSIS submodules.

## Build Artifacts

After a successful build:

| File | Description |
|------|-------------|
| `fsbl.elf` | ELF with debug symbols |
| `fsbl.bin` | Raw binary (unsigned) |
| `fsbl.hex` | Intel HEX format |
| `fsbl.map` | Linker map file |

## Boot Switch Configuration

Both boards use the same switch positions:

| Mode | BOOT0 | BOOT1 | Use case |
|------|-------|-------|----------|
| DEV (debug/flash) | — | 2-3 | Flashing via SWD |
| External flash | 1-2 | 1-2 | Normal boot |

## Using the FSBL with Your Firmware

The FSBL copies your application from external NOR flash to internal SRAM at boot.

**Critical setting** in `fsbl/inc/stm32_extmem_conf.h`:

```c
#define EXTMEM_LRUN_SOURCE_SIZE  (your_application_size_in_bytes)
```

This must be >= your actual application binary size. The default (64 KB) is often too small.

**Flash memory layout:**

| Component | Address | Notes |
|-----------|---------|-------|
| FSBL | 0x7000_0000 | External NOR flash start |
| Your application | 0x7010_0000 | Configurable via `EXTMEM_LRUN_SOURCE_ADDRESS` |

## Updating to New STM32CubeN6 Versions

```bash
cd STM32CubeN6 && git pull && git submodule update --init --recursive && cd ..
cmake --build build/nucleo --clean-first
```

## Configuration Files

| File | Purpose |
|------|---------|
| `fsbl/inc/stm32_extmem_conf.h` | ExtMem Manager — set `EXTMEM_LRUN_SOURCE_SIZE` here |
| `fsbl/inc/stm32n6xx_hal_conf.h` | HAL module enable/disable |
| `fsbl/inc/stm32n6570_discovery_conf.h` | Discovery BSP configuration |
| `fsbl/inc/stm32n6xx_nucleo_conf.h` | NUCLEO BSP configuration |

## Troubleshooting

**"STM32CubeN6 not found"**
```bash
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git
```

**"CMSIS submodules not initialized"**
```bash
cd STM32CubeN6 && git submodule update --init --recursive
```

**"arm-none-eabi-gcc not found"**
Pass the toolchain bin directory:
```bash
cmake --preset nucleo -DTOOLCHAIN_PATH=/path/to/arm-none-eabi/bin
```

**"undefined reference to HAL_XXX"**
Add the corresponding driver to `CMakeLists.txt` `HAL_SOURCES` and enable it in `stm32n6xx_hal_conf.h`.

**Application doesn't boot**
Check `EXTMEM_LRUN_SOURCE_SIZE` — it must be >= your application size.

**Binary too large (> 511 KB)**
Remove unused HAL drivers.

## Project Structure

```
stm32n657-fsbl/
├── CMakeLists.txt              # Build config — BOARD option here
├── CMakePresets.json           # Presets: nucleo / discovery
├── CMakeUserPresets.json       # Machine-local overrides (gitignored — create if needed)
│
├── cmake/
│   └── arm-none-eabi-gcc.cmake # Toolchain (supports TOOLCHAIN_PATH variable)
│
├── fsbl/
│   ├── src/                    # main.c, hal_msp, it, extmem, system_init
│   └── inc/
│       ├── stm32n6xx_hal_conf.h          # HAL module selection
│       ├── stm32_extmem_conf.h           # ⚠️ Set EXTMEM_LRUN_SOURCE_SIZE here
│       ├── stm32n6570_discovery_conf.h   # Discovery BSP config
│       ├── stm32n6xx_nucleo_conf.h       # NUCLEO BSP config
│       ├── mx66uw1g45g_conf.h            # Discovery NOR flash config
│       ├── mx25um51245g_conf.h           # NUCLEO NOR flash config
│       └── aps256xx_conf.h               # Discovery PSRAM config (unused by FSBL)
│
├── startup/
│   └── startup_stm32n657xx.s
├── linker/
│   └── STM32N657XX_AXISRAM2_fsbl.ld
│
├── scripts/
│   ├── sign_fsbl.sh            # Standalone signing utility (optional, for manual use)
│   └── flash_fsbl.sh           # Flash via STM32CubeProgrammer (auto-detects board loader)
│
└── STM32CubeN6/               # Clone separately (not committed)
```

## Additional Resources

- **CLAUDE.md** — Comprehensive technical documentation
- [STM32N6 FSBL explained](https://community.st.com/t5/stm32-mcus/stm32n6-fsbl-explained/ta-p/764307)
- [How to create an STM32N6 FSBL](https://community.st.com/t5/stm32-mcus/how-to-create-an-stm32n6-fsbl-load-and-run/ta-p/768206)
- [STM32CubeN6 GitHub](https://github.com/STMicroelectronics/STM32CubeN6)
