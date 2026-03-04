# C Library Selection - Guide

## Overview of Changes

The build system now supports both **newlib** and **picolibc** as C library options, with proper configuration for both GCC and Clang toolchains.

---

## 1. Key Build System Files

### `/Ports/cmake/proj_config_.cmake`
**Key sections modified:**
- Lines 110-111: C library compile definitions

**Override:**
```bash
cmake -DC_LIBRARY=picolibc ...  # Force picolibc
cmake -DC_LIBRARY=newlib ...    # Force newlib
```

### `/Ports/cmake/system.cmake`
**Purpose:** Configures compiler/linker flags based on detected C library and toolchain

**Key sections modified:**
- Lines 95-110: C library compile definitions
- Lines 112-128: C library specs for GCC vs LLVM

---

## 2. Toolchain Configurations

### Standard Toolchains (newlib) - Use default environment
```bash
# These are in your normal PATH or configured in .zshrc
export PATH_GCC_ARM=/opt/embedded/cross/gcc-current/arm
export PATH_LLVM_ARM=/Users/scratch/todelete/embedded/cross/llvm-current/arm-newlib
```

**What they provide:**
- GCC ARM: Standard ARM GCC with newlib
- LLVM ARM: Clang with newlib

**Build command:**
```bash
cd Ports/Targets/Nucleo_L4R5/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF
cmake --build build
```
Result: Builds with newlib

---

### Picolibc Toolchains - Use default environment
```bash
# These are configured in .zshrc
export PATH_GCC_ARM=/opt/embedded/cross/gcc-current/arm
export PATH_LLVM_ARMP=/Users/scratch/todelete/embedded/cross/llvm-current/arm-picolibc
```

**What they provide:**
- **GCC 15.2.0**: Custom-built with picolibc-1.8.10a support
  - Has `picolibc.specs` installed in toolchain
  - Located at: `$PATH_GCC_ARM/lib/gcc/arm-none-eabi/15.2.0/picolibc.specs`

- **Clang 22.1.0-rc1 (pre-release)**: ARM Toolchain for Embedded with picolibc
  - Built-in picolibc support
  - No specs file needed
  - Includes TLS (Thread-Local Storage) support

---

## 3. Build Examples

### Example 1: GCC + newlib (standard)
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/Nucleo_L4R5/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF
cmake --build build
```
**Result:** Uses GCC with newlib (auto-detected from nano.specs)

---

### Example 2: GCC + picolibc
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/Nucleo_L4R5/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF -DC_LIBRARY=picolibc
cmake --build build
```
**Result:** Uses GCC 15.2.0 with picolibc-1.8.10a

**Key flags added by build system:**
- Compilation: `-specs=picolibc.specs`
- Linking: `-specs=picolibc.specs`
- Defines: `CONFIG_MAN_PICOLIBC_S`, `_GNU_SOURCE`, `_REENT_GLOBAL_ERRNO`

---

### Example 3: Clang + picolibc
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/Nucleo_L4R5/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF -DUSE_LLVM=ON -DC_LIBRARY=picolibc
cmake --build build
```
**Result:** Uses Clang 22 with picolibc (built-in)

**Key features:**
- No specs file needed
- Uses LLD linker with custom `.lld` linker scripts
- Includes TLS support for errno and time buffers
- Defines: `CONFIG_MAN_PICOLIBC_S`, `_GNU_SOURCE`, `_REENT_GLOBAL_ERRNO`

---

## 4. Key Differences: GCC vs Clang with picolibc

| Feature | GCC + picolibc | Clang + picolibc |
|---------|----------------|------------------|
| **Toolchain Path** | `/opt/embedded/cross/gcc-current/arm` | `/Users/scratch/todelete/embedded/cross/llvm-current/arm-picolibc` |
| **Specs File** | Uses `-specs=picolibc.specs` | No specs needed |
| **Linker** | GNU ld | LLD |
| **Linker Script** | `.ld` files | `.lld` files |
| **TLS Support** | No (errno is global) | Yes (errno in .tbss) |
| **Binary Size** | ~278 KB | ~291 KB (+13 KB) |
| **errno Implementation** | Global variable | Thread-local storage |

---

## 5. Modified Files Summary

### Build System (1 file)
- **`/Ports/cmake/system.cmake`**
  - Lines 95-110: Added picolibc compile definitions including `_REENT_GLOBAL_ERRNO`
  - Lines 112-128: Added proper `-specs=picolibc.specs` for GCC compilation AND linking

### Linker Scripts - GNU ld (7 files for GCC)
Added `end` and `_end` symbols after BSS section:
- `/Ports/EquatesModels/Cores/CORTEX_M3/Runtime/system_p.ld`
- `/Ports/EquatesModels/Cores/CORTEX_M4/Runtime/system_p.ld`
- `/Ports/EquatesModels/Cores/CORTEX_M7/Runtime/system_p.ld`
- `/Ports/EquatesModels/Cores/CORTEX_M33/Runtime/system_p.ld`
- `/Ports/EquatesModels/Cores/CORTEX_M55/Runtime/system_pu.ld`
- `/Ports/EquatesModels/Cores/RV32IMAC/Runtime/system_p.ld`
- `/Ports/EquatesModels/Cores/RV64IMAFDC/Runtime/system_p.ld`

### Linker Scripts - LLD (6 files for Clang)
Added TLS sections (`.tdata`, `.tbss`) and `end`/`_end` after `.tbss`:
- `/Ports/EquatesModels/Cores/CORTEX_M3/Runtime/system_pu.lld`
- `/Ports/EquatesModels/Cores/CORTEX_M4/Runtime/system_p.lld`
- `/Ports/EquatesModels/Cores/CORTEX_M4/Runtime/system_pu.lld`
- `/Ports/EquatesModels/Cores/CORTEX_M33/Runtime/system_pu.lld`
- `/Ports/EquatesModels/Cores/CORTEX_M55/Runtime/system_pu.lld`
- `/Ports/EquatesModels/Cores/CORTEX_M7/Runtime/system_pu.lld`

### Runtime Code (2 files)
- **`/Ports/EquatesModels/Generic/Runtime/linker.h`**
  - Added `linker_stTBSS`/`linker_enTBSS` declarations (guarded by `#ifdef __clang__`)

- **`/Ports/EquatesModels/Generic/Runtime/crt0.c`**
  - Added `.tbss` zero-initialization (guarded by `#ifdef __clang__`)

### Target CMakeLists (7 files)
Added conditional C library selection:
- `/Ports/Targets/Pico2_rp2350/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/Nucleo_F207/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/Longan_Nano_F103/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/Discovery_U5G9/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/Alastor_H743/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/MAiXDUiNO_K210/Variant_Test/CMakeLists.txt`
- `/Ports/Targets/Nucleo_L4R5/Variant_Test/CMakeLists.txt`

### Library Headers (1 file)
- **`/OS/Lib_generics/lib_generics.h`**
  - Added conditional include for newlib vs picolibc headers

---

## 6. Verification Commands

### Check which toolchain is active:
```bash
echo $PATH_GCC_ARM
echo $PATH_LLVM_ARM
echo $PATH_LLVM_ARMP
```

### Check C library in build:
```bash
grep "C_LIBRARY" build/CMakeCache.txt
```

### Check compiler in build:
```bash
grep "CMAKE_C_COMPILER:" build/CMakeCache.txt
```

### Verify picolibc in binary:
```bash
strings build/FLASH.elf | grep -i picolibc
# Should show: "picolibc manager"
```

### Check for TLS sections (Clang only):
```bash
grep "\.tbss" build/FLASH.map
# Clang: Shows .tbss section with errno
# GCC: No output (TLS not used)
```

---

## 7. Common Workflows

### A. Standard Development (newlib)
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/<target>/Variant_Test
cmake -S . -B build
cmake --build build
```

### B. Testing with picolibc (GCC)
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/<target>/Variant_Test
cmake -S . -B build -DC_LIBRARY=picolibc
cmake --build build
```

### C. Testing with picolibc (Clang)
```bash
# Use standard environment
source /Users/lva/Dev/edo-rtos-uKOSX/.zshrc

cd Ports/Targets/<target>/Variant_Test
cmake -S . -B build -DUSE_LLVM=ON -DC_LIBRARY=picolibc
cmake --build build
```

### D. Cleaning and Rebuilding
```bash
# Clean build directory
rm -rf build

# Reconfigure and build
cmake -S . -B build [options]
cmake --build build
```

---

## 8. Quick Reference

| Scenario | Toolchain Env | CMake Options | Result |
|----------|---------------|---------------|---------|
| Standard GCC build | Default (.zshrc) | none | GCC + newlib |
| Standard Clang build | Default (.zshrc) | `-DUSE_LLVM=ON` | Clang 22 + newlib |
| GCC + picolibc | Custom (see §2) | `-DC_LIBRARY=picolibc` | GCC 15.2 + picolibc |
| Clang + picolibc | Custom (see §2) | `-DUSE_LLVM=ON -DC_LIBRARY=picolibc` | Clang 22 + picolibc |

---

## Related Documentation

- **PICOLIBC_PHASE3_REPORT.md** - Detailed Phase 3 implementation report with binary size analysis
- **Phase 4 Regression Testing Results** - phase4-regression.txt (build logs)
