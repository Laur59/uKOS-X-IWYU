# About uKOS-X

uKOS-X is a lightweight real-time operating system for embedded microcontroller and DSP-based systems.

This repository is a fork of the open-source project, with a focus on modern development practices, consistent source-file headers, and long-term maintainability, while preserving the technical and historical identity of the original work.

## Heritage

uKOS-X originates from the work of Edo. Franzi, founder and BDFL of the original project.

The historical source headers included an ASCII signature block that formed part of the project's identity:

```text
                                             __ ______  _____
  Edo. Franzi                         __  __/ //_/ __ \/ ___/
  5-Route de Cheseaux                / / / / ,< / / / /\__ \
  CH 1400 Cheseaux-Noreaz           / /_/ / /| / /_/ /___/ /
                                    \__,_/_/ |_\____//____/
  edo.franzi@ukos.ch
```

Upstream still carries this block in its source headers, together with the file-name
banner, the `Author:` / `Modifs:` lines and the full MIT licence text. This fork preserves
the decorative material here instead of repeating it in every file.

## Licensing

The licence is unchanged by this fork: uKOS-X is MIT, © Edo. Franzi. No licence term is
added, removed or reinterpreted here.

Licence information is centralised upstream, and the fork inherits that layout:

| Location | Contents |
|---|---|
| `LICENSE.md` | the project licence (MIT) |
| `LICENSES/` | the licence texts of uKOS-X and of every vendored third-party component |
| `THIRD_PARTY_NOTICES.md` | per-component origin, version, licence and copyright |
| `sbom.spdx.json` | SPDX software bill of materials |

Two differences with respect to upstream:

- the directory is `LICENSES/`, without the leading comma of upstream's `,LICENSES/`;
- `LICENSES/MIT.txt` is added, so that the `SPDX-License-Identifier: MIT` tag carried by
  the source files resolves to a licence text stored under its SPDX-conventional file
  name. Upstream's `LICENSES/License_uKOS-X.txt` is retained unchanged.

## Project direction

The project is being modernised with:

- SPDX-based file headers that *replace* the legacy header block, rather than being
  prepended to it as upstream does
- simplified and consistent source formatting
- improved maintainability for public collaboration

The header standard, with the templates for each language, is
[CONTRIBUTING.md](Documentation/USER_GUIDES/CONTRIBUTING.md) — "File header" section.

## Credits

- Edo. Franzi: original project founder and BDFL
- Laurent von Allmen: maintainer and contributor to forked repository
