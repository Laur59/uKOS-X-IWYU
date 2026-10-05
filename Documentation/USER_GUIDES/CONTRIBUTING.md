# Typography

1. Files shall be encoded in UTF-8 and employ UNIX-style line endings (LF).
2. Lines shall terminate without trailing whitespace.
3. Code indentation shall employ 4 spaces.


## File header

All source files in this repository should use a short, modern header based on SPDX identifiers.

### General rules

Use a minimal file header that contains:

1. `SPDX-License-Identifier`
2. One or more `SPDX-FileCopyrightText` lines
3. An optional short description when it adds useful context

Do not include:

- the file name
- author or modification history
- the full licence text
- decorative separator lines
- ASCII art
- personal postal addresses or email addresses

Keep headers short and consistent across the project.

### Required order

Use the following order in all file headers:

1. `SPDX-License-Identifier`
2. `SPDX-FileCopyrightText` line(s)
3. one blank line
4. optional short description

Example:

```c
/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Short file description.
 */
```

### Copyright lines

Use one `SPDX-FileCopyrightText` line per copyright holder.

Do not add a new copyright line for trivial edits such as:

- formatting changes
- small fixes
- renaming
- minor refactoring
- comment-only updates

Add a new copyright line only for substantial authorship, according to the project’s copyright policy.

### Years

Use:

- `2026 Name` for work limited to a single year
- `2025-2026 Name` for work spanning multiple years

Do not update years for every minor change.

### Descriptions

Descriptions are optional.

If used, they should be:

- short
- factual
- written in English
- limited to a single sentence

Good examples:

- `Umbrella header for uKOS-X public includes.`
- `Kernel memory allocation helpers.`
- `Linker script for privileged/user-mode systems.`

Avoid long descriptions, historical notes, and marketing language.

## Language-specific templates

### C and C++ source/header files

Use block comments:

```c
/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Short file description.
 */
```

Applies to files such as:

- `.c`
- `.h`
- `.cpp`
- `.hpp`
- `.cc`
- `.hh`

### Shell scripts

Keep the shebang on the first line, then add SPDX comment lines:

```sh
#!/usr/bin/env sh
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Short file description.
```

### CMake files

Use CMake comments:

```cmake
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Short file description.
```

Applies to:

- `CMakeLists.txt`
- `.cmake`

### Linker scripts

Use block comments:

```c
/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Short file description.
 */
```

Applies to:

- `.ld`
- `.lld`

### Assembly files

Use the native comment style of the assembler syntax used by the file.

Example:

```asm
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
; Short file description.
```

Do not reuse assembly-style comment prefixes in C or C++ files.

### Makefiles

Use `#` comments:

```python
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
# Short file description.
```

### Python

1. shebang (if script)
2. encoding line (only if needed)
3. SPDX / copyright comments
4. blank line
5. module docstring (optional)
6. code

```
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo Franzi

"""
uKOS-X — Generate database files for learning and validation.
Displays both datasets.
"""
```


## Preferred project template

Unless there is a good reason to do otherwise, use this template:

```c
/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 * SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
 *
 * Short file description.
 */
```


## Linker script expressions

Linker scripts are read by both GNU ld and LLVM lld. Write expressions as plain C
expressions, in the subset that both linkers read the same way.

| Rule | Write | Not |
|---|---|---|
| No parentheses around a whole right-hand side | `linker_lnHeap = stm_lnSRAM2 + stm_lnSRAM3;` | `linker_lnHeap = (stm_lnSRAM2 + stm_lnSRAM3);` |
| No parentheses around a single number or symbol | `= 4K;` `a + 128K` `ASSERT(a >= b, "…")` | `= (4K);` `a + (128K)` `ASSERT((a) >= (b), "…")` |
| Inside `+ - * /`, rely on C precedence | `a + b - 1` | `((a + b) - 1)` |
| Parentheses around a compound operand of a shift, bitwise or comparison operator | `1 << (n + 1)` `(x & 7) == 0` `(a + b) <= (c + d)` | `1 << n + 1` `x & 7 == 0` |
| One space on each side of `=` and of every binary operator | `n + 1` | `n+1` |
| Sizes in decimal with an uppercase `K` or `M`, in the largest exact unit; a length is a size | `60K` `16M` `2048M` `1500K` `stm_lnPERIPH = 512M;` | `60k` `16384K` `32 * 1024K` `stm_lnPERIPH = 0x20000000;` |
| Addresses as `0x` followed by 8 uppercase hexadecimal digits | `0x2000C000` | `0x2000c000` |

Assignments are aligned in columns: when editing a line, keep the column of its `=` and of
its trailing comment.

Why:

- Parentheses around a whole expression are a C macro habit. A linker symbol is a value,
  not a text substitution, so they protect nothing.
- Both linkers use the C precedence table. `==` binds tighter than `&`, so `(x & 7) == 0`
  needs its parentheses; the others in that rule are there for the reader.
- Outside an expression both linkers accept `-`, `+` and `=` as part of a name: `A-B` is one
  symbol. Spaces remove the ambiguity.
- `K` and `M` multiply by 1024 and 1024 × 1024. Neither linker has a `G` suffix.

Do not use the forms on which the two linkers disagree:

- a leading zero: `010` is 8 for GNU ld and 10 for lld
- the base suffixes `h`, `o`, `b`, `d` and the `$` prefix: lld reads only `h`
- `K` or `M` on a hexadecimal number: GNU ld only

The board scripts (`Ports/Targets/*/Base*/Runtime/link_*.ld`) and the SoC memory maps
(`Ports/EquatesModels/SOCs/*/Runtime/<SOC>.ld`) follow these rules. Apply them to the other
linker scripts when you touch them.
