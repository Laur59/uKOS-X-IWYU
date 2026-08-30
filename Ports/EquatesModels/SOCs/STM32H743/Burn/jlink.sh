#!/usr/bin/env zsh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# STM32H743 - Burn the image into the flash with J-Link.

echo if swd >jlink.cmd
echo speed 10000 >>jlink.cmd
echo device stm32h743ii >>jlink.cmd
echo connect >>jlink.cmd
echo r h >>jlink.cmd
echo loadfile FLASH.elf >>jlink.cmd
echo r g >>jlink.cmd
echo q >>jlink.cmd
JLinkExe jlink.cmd
