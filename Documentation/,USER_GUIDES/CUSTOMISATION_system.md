<!-- SPDX-License-Identifier: MIT -->
<!-- SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen -->

# System customisation

The system offers extensive customization capabilities to achieve the desired behaviour, with fine-tuning accomplished by strategically modifying the behavioural descriptions within CMakeLists.txt.

### Adding console tools or processes

```cmake
# Example: adding the man tool
list(APPEND CLI_U ${PATH_UKOS}/OS/CLI/man/man.c)

# Example: adding the process alive
list(APPEND PROC_U
    ${PATH_UKOS}/OS/Processes/alive/alive.c
    ${PATH_BASE}/Processes/alive/stub_alive.c
)
```

### Adding managers

```cmake
# Example: adding the urt0 manager
add_source_with_define(LIBX_P ${PATH_UKOS}/OS/Lib_serials/urt0/urt0.c CONFIG_MAN_URT0_S)
```

### Adding third party MicroPython library

```cmake
# Example: adding the MicroPython tool
list(APPEND CLI_U ${PATH_UKOS}/OS/CLI/microPython/microPython.c)
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
list(APPEND PROC_U
    ${PATH_UKOS}/OS/Processes/TinyUSB/TinyUSB.c
    ${PATH_VARI}/Processes/TinyUSB/stub_TinyUSB.c
)
```

### Adding third party FatFs library

```cmake
# FATFS (File system) integration
add_compile_definitions(CONFIG_MAN_FATFS_S)
find_library(FATFS FatFs ${PATH_UKOS}/Third_Parties/FatFs/Library/${CORE})
file(APPEND "${ARTIFACTS_DIR}/FLASH.cnf" "-DCONFIG_MAN_FATFS_S ")
...
# With the FATFS manager (File system)
UKOS_COMPONENTS += $(FATFS).a
```

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
