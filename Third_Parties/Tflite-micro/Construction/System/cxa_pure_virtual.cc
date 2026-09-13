/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2026 Laurent von Allmen
 *
 * libTFLite.a – Trap on a pure virtual call instead of pulling the C++ runtime.
 *
 * Clang references __cxa_pure_virtual strongly from every vtable that has a pure
 * virtual function; GCC references it weakly, so it never pulled anything in.
 * In a GCC link the strong reference loads libstdc++'s pure.o, whose
 * std::terminate() drags in the exception runtime, the demangler and stdio:
 * about 60 KB, which overflows the Pico2's application region. A pure virtual
 * call is a bug, so trap. Weak, so an application may still provide its own.
 */

extern "C" [[gnu::weak]] [[noreturn]] void __cxa_pure_virtual() {
    __builtin_trap();
}
