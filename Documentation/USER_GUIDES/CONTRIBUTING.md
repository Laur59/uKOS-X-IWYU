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
