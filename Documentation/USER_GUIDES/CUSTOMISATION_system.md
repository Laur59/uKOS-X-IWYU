# System customisation

The system offers extensive customization capabilities to achieve the desired behaviour, with fine-tuning accomplished by strategically modifying the behavioural descriptions within CMakeLists.txt.

### Adding console tools or processes

```cmake
# Example: adding the man tool to the CLI library
target_sources(tool_u PRIVATE
    ${PATH_OSYS}/CLI/man/man.c
)

# Example: adding the process alive
target_sources(proc_u PRIVATE
    ${PATH_OSYS}/Processes/alive/alive.c
    ${PATH_BASE}/Processes/alive/stub_alive.c
)
```

### Adding managers

```cmake
# Example: adding the urt0 manager
add_source_with_define(libx_p ${PATH_OSYS}/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
```

### Adding third party MicroPython library

```cmake
# Example: adding the MicroPython tool
target_sources(tool_u PRIVATE
    ${PATH_OSYS}/CLI/microPython/microPython.c
)
...
# All library components
set(UKOS_COMPONENTS rtcb_p kern_p kern_u libx_p libx_u proc_p proc_u tool_u ${TINYUSB})

# Optional manager
add_MicroPython()
```

### Adding third party TinyUSB library

```cmake
# TinyUSB integration (must be before library definitions)
add_TinyUSB(
    SPEED FS
    PROFILE cdc_cdc
)
...
# With the TinyUSB process
target_sources(proc_u PRIVATE
    ${PATH_OSYS}/Processes/TinyUSB/TinyUSB.c
    ${PATH_BASE}/Processes/TinyUSB/stub_TinyUSB.c
)
```

### Adding third party FatFs library

```cmake
# FatFs (file system) integration. STORAGE is flash, sdcard or sdcard_flash and
# selects Third_Parties/FatFs/Library/${CORE}/${STORAGE}/libFatFs.a
add_FatFs(STORAGE sdcard_flash)
```

### Adding third party LVGL library

```cmake
# Graphic library integration. DISPLAY names the panel and selects
# Third_Parties/LVGL/Library/${DISPLAY}/${CORE}/libLVGL.a
add_LVGL(DISPLAY WKS43WV067_5_Inches)
```

That one line is all the system image needs. The drawing code and the panel headers
(`lcd_display.h`, `lv_conf.h`) belong to the downloadable `q_LVGL` applications, which
put `Library/${DISPLAY}` and `Library/${DISPLAY}/${CORE}` on their own include paths.

The archive has to exist for the panel *and* the variant's core:

| Panel | Cores built |
| ----- | ----------- |
| `RK050HR18_5_Inches` | `CORTEX_M55`, `CORTEX_M85` |
| `TFT_2_4_Inches` | `RV64IMAFDC` |
| `WaveShare_2_Inches` | `CORTEX_M55` |
| `WKS43WV067_5_Inches` | `CORTEX_M7` |

To add a pairing, extend `SUPPORTED_CORES` / `CORE_DISPLAY` in
`Third_Parties/LVGL/CMakeLists.txt` and create `Construction/<panel>/<core>/` with its
own `CMakeLists.txt` and `lv_conf.h`.

### Adding third party TensorFlow Lite Micro library

```cmake
# Locates Library/${CORE}/libTFLite.a, adds the TFLite-micro, flatbuffers and
# gemmlowp include directories, and defines SYSTEM_TFLITE_S
add_Tflite()
```

**No target variant currently calls this.** TFLite is used only by the downloadable
`l_MLPs` applications, which wire it themselves rather than through the macro:

```cmake
set(PATH_INCLUDES
    ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/Generic/CORTEX_M_generic
    ...
)
find_library(MYLIB TFLite ${PATH_UKOS}/Third_Parties/Tflite-micro/Library/${CORE})
```

The macro picks the generic header tree from the architecture, not the core:
`Library/Generic/CORTEX_M_generic` on ARM and `Library/Generic/RISCV64_generic` on
RISC-V, the latter being ISA-independent and serving rv32 as well as rv64 despite its
name.

One thing it cannot do for you: the RV32 and RV64 archives are built release, with the
error strings stripped, so a consumer must also compile with `TF_LITE_STRIP_ERROR_STRINGS`
and `NDEBUG` or its op-resolver will reference the `MicroPrintf` that is no longer there.

Models are committed as `.xxd` hex dumps, not as `.tflite`:
`ukos_add_tflite_models(<target> <model>.xxd ...)` regenerates `<model>.c_inc` from the
dump and needs `xxd`. The application build already calls it, in
`Applications/cmake/application.cmake`.

`add_MicroPython()`, `add_FatFs()`, `add_LVGL()` and `add_Tflite()` all **append** to
`UKOS_COMPONENTS`, so they have to come after the `set(UKOS_COMPONENTS ...)` line and
before `include(system)`. `add_TinyUSB()` is the exception: it has to run before the
library definitions, because `${TINYUSB}` is also named in their
`target_link_libraries()`.

### Customising the kernel

By construction, the kernel is set with the following configuration:

| Argument          |  Description                                                    |
| ----------------- | --------------------------------------------------------------- |
| KKERN_WITH_STATISTICS_S = true | Include the statistics |
| KKERN_WITH_DEBUG_S = true | Include the stop |
| KKERN_WITH_TRTC_S = true | Support the hardware RTC              |
| KKERN_NB_PROCESSES = 48 | Max. 48 processes                |
| KKERN_NB_MAILBOXES = 48 | Max. 48 mailboxes |
| KKERN_NB_SEMAPHORES = 48 | Max. 48 semaphores       |
| KKERN_NB_MUTEXES = 48 | Max. 48 mutexes |
| KKERN_NB_SOFTWARE_TIMERS = 8 | Max. 8 software timers |
| KKERN_NB_SIGNALS = 8 | Max. 8 signals |
| KKERN_NB_POOLS = 8 | Max. 8 pool regions    |
| KKERN_NB_PRECISE_SIGNALS = 8 | Max. 8 precise signals |

Adaptation example

```cmake
# Modifying the number of objects

add_compile_definitions(
    KKERN_NB_MAILBOXES=8
    KKERN_NB_MUTEXES=8
    KKERN_NB_PROCESSES=8
    KKERN_NB_SEMAPHORES=8
    KKERN_NB_SIGNALS=2
)
...
# Modifying the behaviour of the kernel

# Remove the statistics
add_compile_definitions(KKERN_WITH_STATISTICS_S=false)
```

### Customising the libraries

By construction, the libraries are set with the following configuration:

| Argument                  | Description                                  |
| ------------------------- | -------------------------------------------- |
| KGLOBAL_WITH_MMX1_S = false | Without the support of an external SPI FLASH |
| KGLOBAL_RND_SOFT_S = true   | With a software random generator             |

Adaptation example

```cmake
# Adding the support of the MMX
add_compile_definitions(KGLOBAL_WITH_MMX1_S=true)
```
