# System customisation

(c) 2025-20xx, Edo. Franzi, 2025-01-01



The system offers extensive customization capabilities to achieve the desired behavior, with fine-tuning accomplished by strategically modifying the behavioral descriptions within CMakeLists.txt.

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
# Adding the MicroPython support
add_compile_definitions(CONFIG_MAN_MICROPYTHON_S)
find_library(MICROPYTHON MicroPython ${PATH_UKOS}/Third_Parties/MicroPython/Library/${CORE})
file(APPEND "${ARTIFACTS_DIR}/FLASH.cnf" "-DCONFIG_MAN_MICROPYTHON_S ")
...
# Example: adding the MicroPython tool
list(APPEND CLI_U ${PATH_UKOS}/OS/CLI/microPython/microPython.c)
...
# With the MicroPython manager (MicroPython Engine)
UKOS_COMPONENTS += $(MICROPYTHON).a
```

### Adding third party TinyUSB (FS) library

```cmake
# Adding the TinyUSB support
# - Provider (st)
# - Family (nrf)
# - Speed (FS)
# - Profile (cdc_cdc)
set(SPEED FS)
set(PROFILE cdc_cdc)

set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)

# Find TinyUSB package config (automatically provides include paths and definitions)
find_package(TinyUSB REQUIRED
    PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
    NO_DEFAULT_PATH
)

# Link against the appropriate speed variant
# This automatically adds include paths and compile definitions
set(TINYUSB TinyUSB::${SPEED})
...
# With the TinyUSB process
list(APPEND PROC_U
    ${PATH_UKOS}/OS/Processes/TinyUSB/TinyUSB.c
    ${PATH_VARI}/Processes/TinyUSB/stub_TinyUSB.c
)
...
# With the TinyUSB library
UKOS_COMPONENTS += $(TINYUSB).a
```

### Adding third party TinyUSB (HS) library

```cmake
# Adding the TinyUSB support
# - Provider (st)
# - Family (u5)
# - Speed (HS)
# - Profile (cdc_video)
set(SPEED HS)
set(PROFILE cdc_video)

set(PATH_TINYUSB ${PATH_UKOS}/Third_Parties/TinyUSB)

# Find TinyUSB package config (automatically provides include paths and definitions)
find_package(TinyUSB REQUIRED
    PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
    NO_DEFAULT_PATH
)

# Link against the appropriate speed variant
# This automatically adds include paths and compile definitions
set(TINYUSB TinyUSB::${SPEED})
...
# With the TinyUSB process
list(APPEND PROC_U
    ${PATH_UKOS}/OS/Processes/TinyUSB/TinyUSB.c
    ${PATH_VARI}/Processes/TinyUSB/stub_TinyUSB.c
)
...
# With the TinyUSB library
UKOS_COMPONENTS += $(TINYUSB).a
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
