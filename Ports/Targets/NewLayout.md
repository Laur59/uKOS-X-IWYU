L'organisation des fichiers ressemble à :

```
├── Alastor_H743
│   ├── Base
│   │   ├── CLI
│   │   ├── Lib_cryptographics
│   │   ├── Lib_generics
│   │   ├── Lib_kernels
│   │   ├── Lib_peripherals
│   │   ├── Lib_serials
│   │   ├── Lib_storages
│   │   ├── Processes
│   │   └── Runtime
│   └── Variant_Test
│       ├── CMakeLists.txt
│       ├── Includes
│       ├── Lib_peripherals
│       ├── Processes
│       ├── Runtime
│       └── Shared
├── Discovery_U5G9
│   ├── Base
│   │   ├── Lib_cryptographics
│   │   ├── Lib_generics
│   │   ├── Lib_kernels
│   │   ├── Lib_peripherals
│   │   ├── Lib_serials
│   │   ├── Processes
│   │   └── Runtime
│   └── Variant_Test
│       ├── CMakeLists.txt
│       ├── Includes
│       ├── Processes
│       └── Runtime
├── Firefly_H743
│   ├── Base
│   │   ├── Lib_cryptographics
│   │   ├── Lib_generics
│   │   ├── Lib_kernels
│   │   ├── Lib_peripherals
│   │   ├── Lib_serials
│   │   ├── Processes
│   │   └── Runtime
│   └── Variant_Test
│       ├── CMakeLists.txt
│       ├── Includes
│       ├── Processes
│       ├── Runtime
│       └── System
├── Longan_Nano_F103
│   ├── Base
│   │   ├── Lib_cryptographics
│   │   ├── Lib_generics
│   │   ├── Lib_kernels
│   │   ├── Lib_peripherals
│   │   ├── Lib_serials
│   │   ├── Processes
│   │   └── Runtime
│   └── Variant_Test
│       ├── CMakeLists.txt
│       ├── Includes
│       ├── Processes
│       └── Runtime
```

C'est un héritage du upstream qui utilise des makefiles dans le dossier  `Variant_Test/System`. Comme le fork abandonne l'usage de make au profit de CMake, il semblerait judicieux de monter d'un niveau les fichiers  `CMakeLists.txt`.



C'est une bonne question de cohérence architecturale. La réponse dépend de ce que représente `Variant_Test` dans votre modèle.

------

**Argument pour monter d'un niveau (recommandé)**

La structure actuelle est un artefact de la cohabitation Make/CMake : `Variant_Test/` était un pair de `System/` (qui contenait les Makefiles). Sans Make, cette hiérarchie n'a plus de justification.

Le niveau naturel du `CMakeLists.txt` racine est le **board** (`Alastor_H743/`), car c'est l'unité logique de build. La structure deviendrait :

```
Alastor_H743/
├── CMakeLists.txt          ← racine du projet board
├── Base/
│   ├── CMakeLists.txt      ← bibliothèques partagées
│   └── ...
└── Variant_Test/
    ├── CMakeLists.txt      ← cible variant (add_subdirectory depuis la racine)
    └── ...
```

`Base/` devient un `add_subdirectory()` explicite depuis le CMakeLists.txt racine, ce qui le rend visible dans le graphe de build — actuellement il est structurellement "invisible" pour CMake.

------

**Le seul argument contre**

Si plusieurs variants coexistent à terme (`Variant_Production/`, `Variant_Debug/`...), et que chacun est une cible de build indépendante, on pourrait vouloir un `CMakeLists.txt` par variant **sans** racine board. Mais dans ce cas, un board-level CMakeLists.txt qui coordonne les variants reste plus propre que l'absence de racine.

------

**Conclusion**

Montez le `CMakeLists.txt` au niveau board. C'est cohérent avec la convention CMake (la racine = le périmètre du projet), cela supprime l'artefact Make, et cela rend `Base/` un citoyen de première classe du build via `add_subdirectory()`.

Est-ce que le CMakeLists.txt de la racine pourrait coordoner le cas que vous mentionner : 
```
├── Alastor_H743 
│   ├── CMakeLists.txt`
│   ├── Base 
│   │   ├── CMakeLists.txt 
│   │   ├──  
│   ├── Variant_Test 
│   │   ├── CMakeLists.txt 
│   │   ├──  
│   └── Variant_Production 
│       ├── CMakeLists.txt 
│       ├──  
```

Oui, tout à fait. Voici comment le CMakeLists.txt racine du board pourrait orchestrer cela :

cmake

```cmake
# Alastor_H743/CMakeLists.txt
cmake_minimum_required(VERSION 3.25)
project(Alastor_H743 C CXX ASM)

# Base est toujours inclus — bibliothèques partagées par tous les variants
add_subdirectory(Base)

# Sélection du variant via -DUKOS_VARIANT=Test|Production
set(UKOS_VARIANT "Test" CACHE STRING "Build variant")
set_property(CACHE UKOS_VARIANT PROPERTY STRINGS Test Production)

if(UKOS_VARIANT STREQUAL "Test")
    add_subdirectory(Variant_Test)
elseif(UKOS_VARIANT STREQUAL "Production")
    add_subdirectory(Variant_Production)
else()
    message(FATAL_ERROR "Unknown variant: ${UKOS_VARIANT}")
endif()
```

L'invocation CMake devient alors :

bash

```bash
# Variant Test (défaut)
cmake -B build/test -DUKOS_VARIANT=Test

# Variant Production
cmake -B build/production -DUKOS_VARIANT=Production
```

------

**Ce que gagne chaque niveau :**

`Base/CMakeLists.txt` — déclare les bibliothèques statiques partagées :

cmake

```cmake
add_library(ukos_base STATIC
    Lib_kernels/...
    Lib_generics/...
    ...
)
```

`Variant_Test/CMakeLists.txt` — déclare la cible finale et lie contre `Base` :

cmake

```cmake
add_executable(ukos_test ...)
target_link_libraries(ukos_test PRIVATE ukos_base)
```

