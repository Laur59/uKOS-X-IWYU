# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
#
# Copies TinyUSB public headers from TinyUSB-current/ into
# Library/Include/TinyUSB-current/, preserving the directory tree but
# keeping only .h files.  This makes Library/ self-contained so that
# TinyUSB-current/ can be deleted after the build without breaking
# consumers that use find_package(TinyUSB).
#
# Invoked by the top-level CMakeLists.txt via:
#   cmake -DSRC=<abs-path-to-TinyUSB-current>
#         -DDST=<abs-path-to-Library/Include/TinyUSB-current>
#         -P install_headers.cmake

if(NOT DEFINED SRC OR NOT DEFINED DST)
    message(FATAL_ERROR
        "install_headers.cmake requires -DSRC=<TinyUSB-current> "
        "-DDST=<Library/Include/TinyUSB-current>")
endif()

message(STATUS "TinyUSB: installing public headers")
message(STATUS "  From: ${SRC}")
message(STATUS "  To:   ${DST}")

# src/ — covers all providers: core TinyUSB API, class headers,
#         and portable drivers (rp2040, etc.)
file(COPY "${SRC}/src"
    DESTINATION "${DST}"
    FILES_MATCHING PATTERN "*.h"
)

# hw/ — covers Nordic nrfx drivers and BSP headers
if(EXISTS "${SRC}/hw")
    file(COPY "${SRC}/hw"
        DESTINATION "${DST}"
        FILES_MATCHING PATTERN "*.h"
    )
endif()

message(STATUS "TinyUSB: headers installed to ${DST}")
