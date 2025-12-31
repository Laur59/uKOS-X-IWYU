# Cppcheck for uKOS-X (v.1.0)

Copyright 2025-2026, Laurent von Allmen

## Environment

Cppcheck installed (MacPorts, Homebrew, or from script ukos_cppcheck.sh).

Generation of report in html is perform by a Python command that requires
module Pygments.

Recommendation: install the following virtual environment.

```bash
cd Third_Parties/Cppcheck
python3 -m venv Cppcheck-env
source Cppcheck-env/bin/activate
pip install Pygments
deactivate
```

## Static analysis of a target, ex. Discovery_U5G9 Variant_Test

```bash
# Enter in the Variant_Test of the Discovery_U5G9 target
cd Ports/Targets/Discovery_U5G9/Variant_Test

cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_U5G9/Variant_Test

# Open source version
${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/code_analysis.sh

# Premium version
${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/code_analysis.sh -P
```

## Tricks

Some code sections are difficult to modify (especially in embedded systems). Use the following approach to silence Cppcheck for such sections.

```c
#define EXCLUDE_CPPCHECK
#ifdef EXCLUDE_CPPCHECK

// Portions of code that should be excluded from Cppcheck analysis

#endif
```
