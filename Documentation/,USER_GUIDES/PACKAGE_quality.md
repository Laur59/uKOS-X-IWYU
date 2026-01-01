# Package quality

(c) 2025-2026, Laurent von Allmen



To verify the quality of the software package, three solutions are available: the use of **Cppcheck Premium** (paid version), the use of **Cppcheck (open-source)**, or the use of **Clang-Tidy (open-source).** These tools analyze the source code and verify compliance with major programming standards such as MISRA (supported by Cppcheck Premium), CERT, and many other coding rules. They help detect potential bugs, security vulnerabilities, and violations of best practices, thereby improving the overall reliability, safety, and maintainability of the software. The analysis results are automatically generated in the folder **Static_Analysis** located at `${PATH_UKOS_X_PACKAGE}/Ports/<target>/<variant>` (for example, `Nucleo_H743/Variant_Test`)

### Cppcheck Premium

```makefile
# Be sure to have in your path
PATH=${PATH}:${PATH_TOOLS_GCC}/cross/cppcheckpremium

# Usage
cd ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test
${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/code_analysis.sh -P
```

### Cppcheck (open source)

```makefile
# Be sure to have in your path
PATH=${PATH}:${PATH_TOOLS_GCC}/cross/cppcheck-current/bin

# Usage
cd ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test
${PATH_UKOS_X_PACKAGE}/Third_Parties/Cppcheck/code_analysis.sh
```

### clang-tidy (open source)

```makefile
# Usage
cd ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test
${PATH_UKOS_X_PACKAGE}/Tools/UNIX_Tools/clang-analyser/analyser.sh
```

