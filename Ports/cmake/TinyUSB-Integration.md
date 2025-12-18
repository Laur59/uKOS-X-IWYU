# TinyUSB Integration Guide

## Overview

This document describes the improved TinyUSB integration pattern for uKOS-X projects. The new approach uses CMake package configuration files to automatically manage include paths and compile definitions, eliminating manual configuration and making projects more maintainable.

## What Changed

### Before (Old Approach)

Projects had to manually specify:
- `PROVIDER` (hardware vendor)
- `FAMILY` (processor family)
- All include paths
- Compile definitions

```cmake
# Old approach - lots of manual configuration
set(PROVIDER st)
set(FAMILY l4)
set(SPEED FS)
set(PROFILE cdc_cdc)

set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)
list(APPEND PATH_INCLUDES
    ${PATH_TINYUSB}/uKOS_Interface/Includes/mcu/${PROVIDER}
    ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
    ${PATH_TINYUSB}/uKOS_Interface/OSAL
    ${PATH_TINYUSB}/TinyUSB-current/src
)
add_compile_definitions(SYSTEM_TINYUSB_${SPEED}_S)
find_library(TINYUSB TinyUSB_${SPEED} ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE})
```

**Problems:**
- Hardcoded include paths break when TinyUSB structure changes
- Redundant information (PROVIDER and FAMILY derivable from SOC)
- Error-prone manual configuration
- Poor maintainability

### After (New Approach)

```cmake
# New approach - automatic configuration
set(SOC STM32L4R5)
set(CORE CORTEX_M4)

include(proj_config)

# Derive PROVIDER and FAMILY automatically from SOC
derive_soc_properties(${SOC})

# TinyUSB integration (must be before library definitions)
set(SPEED FS)
set(PROFILE cdc_cdc)
set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)

# Find TinyUSB package (automatically provides include paths and definitions)
find_package(TinyUSB REQUIRED
    PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
    NO_DEFAULT_PATH
)

# Link against the appropriate speed variant
set(TINYUSB TinyUSB::${SPEED})

# Later, when defining libraries that use TinyUSB:
add_library(libx_p ${LIBX_P_SOURCES})
target_link_libraries(libx_p PUBLIC system_compiler_flags ${TINYUSB})

add_library(proc_u ${PROC_U_SOURCES})
target_link_libraries(proc_u PUBLIC system_compiler_flags ${TINYUSB})
```

**Benefits:**
- No manual include path management
- Automatic PROVIDER/FAMILY derivation
- Changes to TinyUSB structure only affect TinyUSBConfig.cmake
- Cleaner, more maintainable code
- CMake-idiomatic approach using imported targets

## Key Components

### 1. `derive_soc_properties()` Function

**Location:** `Ports/cmake/proj_config.cmake`

Automatically determines `PROVIDER` and `FAMILY` from the SoC name.

**Supported SoCs:**
- **STMicroelectronics**: `STM32*` → `PROVIDER=st`, `FAMILY=l4/h7/f4/etc`
- **Nordic Semiconductor**: `nRF*` → `PROVIDER=nordic`, `FAMILY=nrf`
- **NXP**: `MIMXRT*` → `PROVIDER=nxp`, `FAMILY=imxrt`
- **Microchip/Atmel**: `SAM*` → `PROVIDER=microchip`, `FAMILY=samd/same/etc`
- **Raspberry Pi**: `RP2040` → `PROVIDER=raspberrypi`, `FAMILY=rp2`

**Usage:**
```cmake
set(SOC STM32L4R5)
derive_soc_properties(${SOC})
# Now PROVIDER="st" and FAMILY="l4" are automatically set
```

### 2. `TinyUSBConfig.cmake` Generation

**Location:** `Third_Parties/TinyUSB/Library/Family/Mkfiles/TinyUSB.cmake`

The `add_tinyusb_libraries()` function now automatically generates a `TinyUSBConfig.cmake` file for each profile when building TinyUSB libraries.

**Generated files:**
```
Third_Parties/TinyUSB/Library/Family/${FAMILY}/${SOC}/${PROFILE}/
├── libTinyUSB_FS.a
├── libTinyUSB_HS.a
├── tusb_config.h
└── TinyUSBConfig.cmake  ← NEW: Package configuration file
```

**What TinyUSBConfig.cmake provides:**
- Imported targets: `TinyUSB::FS` and `TinyUSB::HS`
- `INTERFACE_INCLUDE_DIRECTORIES` with all required paths
- `INTERFACE_COMPILE_DEFINITIONS` (e.g., `SYSTEM_TINYUSB_FS_S`)
- Provider-specific includes (ST, Nordic, etc.)

### 3. Consumer Project Integration

**Steps:**

1. **Define SOC and CORE** (as before)
   ```cmake
   set(SOC STM32L4R5)
   set(CORE CORTEX_M4)
   ```

2. **Include proj_config** (defines the derive_soc_properties function)
   ```cmake
   include(proj_config)
   ```

3. **Derive properties automatically**
   ```cmake
   derive_soc_properties(${SOC})
   ```

4. **Configure TinyUSB** (IMPORTANT: Do this BEFORE defining libraries)
   ```cmake
   set(SPEED FS)              # FS or HS
   set(PROFILE cdc_cdc)       # cdc_cdc, cdc_msc, etc.
   set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)
   
   # Find TinyUSB package
   find_package(TinyUSB REQUIRED
       PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
       NO_DEFAULT_PATH
   )
   
   # Set the target to use
   set(TINYUSB TinyUSB::${SPEED})
   ```

5. **Define your libraries** and link those that use TinyUSB headers:
   ```cmake
   # Example: libx_p uses TinyUSB headers (cdc0.c includes tusb_config.h)
   add_library(libx_p ${LIBX_P})
   target_link_libraries(libx_p PUBLIC system_compiler_flags ${TINYUSB})
   
   # Example: proc_u uses TinyUSB headers (TinyUSB.c includes tusb.h)
   add_library(proc_u ${PROC_U})
   target_link_libraries(proc_u PUBLIC system_compiler_flags ${TINYUSB})
   ```

6. **Add to final components list**
   ```cmake
   set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u proc_p proc_u tool_u ${MICROPYTHON} ${TINYUSB})
   ```

**Important Notes:**
- TinyUSB must be configured **before** library definitions so `${TINYUSB}` is available
- Any library that includes TinyUSB headers (`tusb.h`, `tusb_config.h`, etc.) must link against `${TINYUSB}`
- The `${TINYUSB}` variable contains the imported target (`TinyUSB::FS` or `TinyUSB::HS`)
- Linking provides automatic include paths and compile definitions

## Migration Guide

### For Existing Projects

1. **Add derive_soc_properties() call** after including proj_config:
   ```cmake
   set(SOC STM32L4R5)
   set(CORE CORTEX_M4)
   
   include(proj_config)
   
   derive_soc_properties(${SOC})  # ← ADD THIS
   ```

2. **Move TinyUSB integration BEFORE library definitions:**

   Remove the old section:
   ```cmake
   set(PROVIDER st)
   set(FAMILY l4)
   list(APPEND PATH_INCLUDES ...)
   add_compile_definitions(SYSTEM_TINYUSB_${SPEED}_S)
   find_library(TINYUSB ...)
   ```

   Replace with (BEFORE `# Sources` section):
   ```cmake
   # TinyUSB integration (must be before library definitions)
   set(SPEED FS)
   set(PROFILE cdc_cdc)
   set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)

   find_package(TinyUSB REQUIRED
       PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
       NO_DEFAULT_PATH
   )

   set(TINYUSB TinyUSB::${SPEED})
   ```

3. **Add `${TINYUSB}` to libraries that use TinyUSB headers:**
   ```cmake
   # For any library that includes tusb.h, tusb_config.h, etc.
   target_link_libraries(libx_p PUBLIC system_compiler_flags ${TINYUSB})
   target_link_libraries(proc_u PUBLIC system_compiler_flags ${TINYUSB})
   ```

4. **Rebuild TinyUSB libraries** to generate config files:
   ```bash
   cd Third_Parties/TinyUSB
   rm -rf build
   cmake -B build -GNinja
   cmake --build build
   ```

### For New Projects

Simply follow the "Consumer Project Integration" steps above. No migration needed!

## Troubleshooting

### Error: "Could not derive PROVIDER and FAMILY"

**Cause:** Unsupported SoC naming pattern.

**Solution:** Either:
1. Extend `derive_soc_properties()` in `proj_config.cmake` to support your SoC
2. Manually set `PROVIDER` and `FAMILY` before calling `find_package(TinyUSB)`

### Error: "TinyUSB FS library not found"

**Cause:** TinyUSB libraries not built or config file not generated.

**Solution:** Build TinyUSB libraries for your SoC:
```bash
cd Third_Parties/TinyUSB/Library/Family/${FAMILY}/${SOC}
cmake -B build_cmake
cmake --build build_cmake
```

### Error: "PATH_TINYUSB is not defined"

**Cause:** Using older TinyUSBConfig.cmake or PATH_TINYUSB not set in consumer.

**Solution:**
1. Ensure `set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)` is in your CMakeLists.txt
2. Rebuild TinyUSB libraries to regenerate config files

### Error: "tusb_config.h file not found" or "tusb.h file not found"

**Cause:** Library using TinyUSB headers is not linked against `${TINYUSB}` target.

**Solution:** Add `${TINYUSB}` to the `target_link_libraries()` call for that library:
```cmake
# Example: if cdc0.c in libx_p cannot find tusb_config.h
target_link_libraries(libx_p PUBLIC system_compiler_flags ${TINYUSB})

# Example: if TinyUSB.c in proc_u cannot find tusb.h
target_link_libraries(proc_u PUBLIC system_compiler_flags ${TINYUSB})
```

**Important:** TinyUSB integration must be placed BEFORE library definitions in CMakeLists.txt, otherwise `${TINYUSB}` will be undefined when libraries are created.

### Error: "Imported target includes non-existent path"

**Cause:** Generated `TinyUSBConfig.cmake` references paths that don't exist.

**Solution:**
1. Check if the referenced path is needed (e.g., ST CMSIS headers are provided by uKOS-X, not TinyUSB)
2. Rebuild TinyUSB libraries with the updated `TinyUSB.cmake` generator
3. Ensure you're using the latest version of the config generator

## Advanced Usage

### Using Multiple Profiles

```cmake
# Profile 1: CDC+CDC
set(PROFILE_1 cdc_cdc)
find_package(TinyUSB REQUIRED
    PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE_1}
    NO_DEFAULT_PATH
)
set(TINYUSB_CDC_CDC TinyUSB::FS)

# Profile 2: CDC+MSC
set(PROFILE_2 cdc_msc)
find_package(TinyUSB REQUIRED
    PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE_2}
    NO_DEFAULT_PATH
)
set(TINYUSB_CDC_MSC TinyUSB::FS)
```

### Custom Include Path Extensions

If you need additional includes beyond what TinyUSB provides:

```cmake
find_package(TinyUSB REQUIRED ...)
set(TINYUSB TinyUSB::${SPEED})

# Add custom includes to your target
target_include_directories(my_target PRIVATE
    ${CMAKE_SOURCE_DIR}/custom_usb_includes
)
```

## Architecture

```
┌─────────────────────────────────────────────────────┐
│ Consumer Project (e.g., Nucleo_L4R5/Variant_Test)   │
│                                                     │
│  CMakeLists.txt:                                    │
│    set(SOC STM32L4R5)                               │
│    derive_soc_properties(${SOC})                    │
│    find_package(TinyUSB)                            │
│    set(TINYUSB TinyUSB::FS)                         │
└─────────────────────────────────────────────────────┘
                        │
                        │ finds and includes
                        ▼
┌─────────────────────────────────────────────────────┐
│ TinyUSBConfig.cmake                                 │
│ (Generated by TinyUSB.cmake)                        │
│                                                     │
│  Defines:                                           │
│    - TinyUSB::FS (imported target)                  │
│    - TinyUSB::HS (imported target)                  │
│  Sets:                                              │
│    - INTERFACE_INCLUDE_DIRECTORIES                  │
│    - INTERFACE_COMPILE_DEFINITIONS                  │
│    - IMPORTED_LOCATION (libTinyUSB_*.a)             │
└─────────────────────────────────────────────────────┘
                        │
                        │ configured by
                        ▼
┌─────────────────────────────────────────────────────┐
│ TinyUSB.cmake (build function)                      │
│                                                     │
│  add_tinyusb_libraries()                            │
│    - Builds libTinyUSB_FS.a                         │
│    - Builds libTinyUSB_HS.a                         │
│    - Generates TinyUSBConfig.cmake                  │
└─────────────────────────────────────────────────────┘
                        │
                        │ uses
                        ▼
┌─────────────────────────────────────────────────────┐
│ proj_config.cmake                                   │
│                                                     │
│  derive_soc_properties(SOC_NAME)                    │
│    - Parses SOC name                                │
│    - Sets PROVIDER (st, nordic, etc.)               │
│    - Sets FAMILY (l4, h7, nrf, etc.)                │
└─────────────────────────────────────────────────────┘
```

## Benefits Summary

| Aspect | Old Approach | New Approach |
|--------|-------------|--------------|
| **Maintainability** | Poor - hardcoded paths | Excellent - centralized config |
| **Error Prone** | High - manual setup | Low - automatic configuration |
| **Redundancy** | High - PROVIDER/FAMILY manual | None - derived automatically |
| **Coupling** | Tight - depends on internal structure | Loose - depends on interface |
| **CMake Best Practices** | Not followed | Followed (imported targets) |
| **Code Length** | 15+ lines | 8 lines |

## References

- **TinyUSB Build Function**: `Third_Parties/TinyUSB/Library/Family/Mkfiles/TinyUSB.cmake`
- **SoC Property Derivation**: `Ports/cmake/proj_config.cmake`
- **Example Project**: `Ports/Targets/Nucleo_L4R5/Variant_Test/CMakeLists.txt`

## Version History

- **2025-10-20**: Initial implementation
  - Added `derive_soc_properties()` function
  - Added `TinyUSBConfig.cmake` generation
  - Updated Nucleo_L4R5 example project

---

*For questions or issues, please refer to the uKOS-X project documentation or contact the maintainers.*
