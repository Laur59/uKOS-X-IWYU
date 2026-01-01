# Generic patches

(c) 2025-2026, Edo. Franzi

## Creating a patch

```bash
cd gcc-x.y.z/xyz
diff -u oldFile newFile > /Scripts/Patches/xyz/xyz.patch
```

## Applying a patch

```bash
cd gcc-x.y.z/xyz
patch -p1 -d . < /Scripts/Patches/xyz/xyz.patch
```

## Patches

1. ~~**cortex**: for multilib fragment code~~ (not necessary for gcc-14.2.0)
2. **gcc**: for gcc-14.1.0 and Xcode 15.3
   1. https://gcc.gnu.org/bugzilla/show_bug.cgi?id=111632

3. **gdb**: for gdb version < 14.0
4. ~~**llvm**: for llvm-17.0.6~~
5. ~~**riscv**: for multilib fragment code~~  (not necessary for gcc-14.2.0)
