# uKOS-X: preliminary package

(c) 2025-20xx, Edo. Franzi, 2025-12-12

## Assumptions

- All the manager will be implement with the user/privileged separation
- In the User mode, the memory structures of privileged managers (e.g. µKernel) cannot be accessed
- In the User mode, the peripherals cannot be accessed
- Processes can be run in user/privileged modes (via the macro PRIVIEGE_ELEVATION)

## Work done

- Preliminary package; supported targets
  - Alastor_H743
  - Asmodee_H747
  - DevKit_nRF5340
  - Discovery_U5G9
  - Longan_Nano_F103
  - MAiXDUiNO_K210 (multi-cores)
  - Nucleo_F207
  - Nucleo_H743
  - Nucleo_L4R5
  - Nucleo_N657
  - Pico2_rp2350 (multi-cores)
  - Better description of the init.c files (use .h)
- Improved the Ozone plugin for uKOS-X
- Better memo_malloc API
- Support of Ubuntu-25.04 LTS
- C++ support
- TFLite support (prepared for LiteRT )
- Newlib fully integrated
- Removed iotx_printf (replaced by dprintf)
- Tested the newlib memory allocation interface
- Removed statistic API from memo
- Removed all the .py special tools for the make
- Improved the main make (system.mk & application.mk)
- Better TinyUSB integration
- Included the newlib UTC support
- New project organisation
- Only one file containing the error codes (KERR_KERN_xyz, KERR_DEVI_xyz, KERR_GENE_xyz)
- Removed all the volatile used by the kernel objects
- Implemented the RTC example (see the H7 targets)
- Removed the LME (embedded Sysquake)
- Added init/reset handles to the MODULE macro
- Removed Lib_engines
- Terminate the example with the process "temperature"
- All the sqe neural network programs replaced by the python ones
- Removed the strg manager
- Improved *.ld to support STM32CubeProgrammer
- Start cleaning
- pdf and Doxygen documentation
- Better rnd tool
- I2C by interruption
- Renamed the interruption priorities (specially the kernel timer priorities)
- Solved the issue with the H743 and the RTC
- Separated manager for LED & switches
- Merged syos & global -> system
- Uniform Lib_storage API (sdcard + flash)
- Integratred the FatFs package
- On line documentation
- Supported Pico2_rp2350 (1 core), with TinyUSB
- Supported Pico2_rp2350 (2 core), with TinyUSB & microPython
- Corrected the Pico2_rp2350 uart managers
- Impleemented the Pico2_rp2350 Inter-core ommunications
- Cleaned the package (MISRA "u" alignement)
- Terminate the preliminary simple web site to redirect in direction of the Github
- Cleaned the package with cleaned-tidy
- Cleaned & verified the package (with cppcheck)
- Corrected the RTC summer time problem
- **READY TO DISTRIBUTE**

## Remaining work

- ~~spi not blocking by the internal semaphore~~
- ~~Add a cnvt manager (handle all the conversions; e.g. time, physical, etc.)~~
- ~~Pool have to be moved from the kernel to memo (difficult!)~~
- Bloc the cdcx applications for the applications running with the core > 0
- The Tensorflow lite for ARM Ubuntu does not build RISC-V libraries
- Sometimes we have a double uKOS-X > prompt
  - GetXYZ/putXYZ for API that return information

  - ReadXYZ/writeXYZ for API that return data
- More Tests

