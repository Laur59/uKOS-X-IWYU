# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2026 Laurent von Allmen
#
# Pin the HOST compiler. Must be included before project().
#
# This matters: the uKOS-X shell environment puts the embedded cross toolchain
# first in PATH, so a bare "clang" is the ARM cross compiler and CMake would
# happily try to build the host tests with it.

if((NOT DEFINED CMAKE_C_COMPILER) AND (NOT DEFINED ENV{CC}))
    execute_process(COMMAND xcrun --find clang
                    RESULT_VARIABLE _ukos_rc
                    OUTPUT_VARIABLE _ukos_cc
                    OUTPUT_STRIP_TRAILING_WHITESPACE
                    ERROR_QUIET)

    if((NOT _ukos_rc EQUAL 0) OR (NOT EXISTS "${_ukos_cc}"))
        set(_ukos_cc "/usr/bin/cc")
    endif()

    if(NOT EXISTS "${_ukos_cc}")
        message(FATAL_ERROR "No host C compiler found (tried xcrun and /usr/bin/cc)")
    endif()

    set(CMAKE_C_COMPILER "${_ukos_cc}" CACHE FILEPATH "Host C compiler (never the cross toolchain)")
    unset(_ukos_rc)
    unset(_ukos_cc)
endif()
