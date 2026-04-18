# Guide CMake pour TinyUSB
## Système de construction modulaire pour les bibliothèques TinyUSB

Ce document décrit le système CMake DRY (Don't Repeat Yourself) pour construire les bibliothèques TinyUSB pour toutes les familles STM32 et Nordic nRF.

## Architecture

### Structure des fichiers

```
Third_Parties/TinyUSB/Library/Family/
├── Mkfiles/
│   ├── TinyUSB.mk          # Makefile commun (original)
│   ├── TinyUSB.cmake       # Module CMake commun (support ST + Nordic)
│   └── common-setup.cmake  # Configuration compilateur commune
├── f2/STM32F207/CMakeLists.txt      # Cortex-M3, soft float
├── h7/STM32H743/CMakeLists.txt      # Cortex-M7
├── h7/STM32H747/CMakeLists.txt      # Cortex-M7 (avec cdc_video)
├── l4/STM32L4R5/CMakeLists.txt      # Cortex-M4
├── n6/STM32N657/CMakeLists.txt      # Cortex-M55 (avec SECURE_S)
├── u5/STM32U5G9/CMakeLists.txt      # Cortex-M33 (avec SECURE_S)
└── nrf/nRF5340/CMakeLists.txt       # Cortex-M33 (Nordic nRF5340)
```

### TinyUSB.cmake - Module commun

Le fichier `Mkfiles/TinyUSB.cmake` contient une fonction réutilisable `add_tinyusb_libraries()` qui encapsule toute la logique de construction :

- Configuration des chemins d'inclusion (provider-specific)
- Collecte des sources TinyUSB (avec sources spécifiques par provider)
- Création des bibliothèques FS (Full Speed) et HS (High Speed)
- Application des flags de compilation
- Strip post-build des bibliothèques
- Support multi-provider (ST et Nordic)

## Utilisation

### Prérequis

1. Variable d'environnement `PATH_GCC_ARM` doit être définie et pointer vers votre toolchain ARM GCC.

```bash
export PATH_GCC_ARM=/path/to/gcc-arm-none-eabi
```

### Construction de base

Pour construire les bibliothèques TinyUSB pour un SOC spécifique :

```bash
# Exemple pour STM32H743
cd Third_Parties/TinyUSB/Library/Family/h7/STM32H743
mkdir build && cd build
cmake ..
cmake --build .
```

Cela construira par défaut tous les profils disponibles (cdc_cdc, cdc_msc, etc.).

### Options de construction

Chaque CMakeLists.txt expose des options pour choisir les profils à construire :

```bash
# Construire uniquement cdc_cdc
cmake -DBUILD_CDC_CDC=ON -DBUILD_CDC_MSC=OFF ..

# Construire uniquement cdc_msc
cmake -DBUILD_CDC_CDC=OFF -DBUILD_CDC_MSC=ON ..

# Pour les SOCs avec cdc_video (H747, N657, U5G9)
cmake -DBUILD_CDC_VIDEO=ON ..
```

### Profils disponibles par SOC

#### Provider ST

| SOC        | Core       | FPU              | Profils disponibles           | Flags spéciaux        |
|------------|------------|------------------|-------------------------------|-----------------------|
| STM32F207  | Cortex-M3  | soft             | cdc_cdc, cdc_msc              | -                     |
| STM32H743  | Cortex-M7  | fpv5-sp-d16      | cdc_cdc, cdc_msc              | -                     |
| STM32H747  | Cortex-M7  | fpv5-sp-d16      | cdc_cdc, cdc_msc, cdc_video   | CORTEX_M7_S, CORE_CM7 |
| STM32L4R5  | Cortex-M4  | fpv4-sp-d16      | cdc_cdc, cdc_msc              | -                     |
| STM32N657  | Cortex-M55 | fpv5-sp-d16      | cdc_cdc, cdc_msc, cdc_video   | SECURE_S              |
| STM32U5G9  | Cortex-M33 | fpv5-sp-d16      | cdc_cdc, cdc_msc, cdc_video   | SECURE_S              |

#### Provider Nordic

| SOC        | Core       | FPU              | Profils disponibles           | Flags spéciaux                                                        |
|------------|------------|------------------|-------------------------------|-----------------------------------------------------------------------|
| nRF5340    | Cortex-M33 | fpv5-sp-d16      | cdc_cdc, cdc_msc              | CORTEX_M33_S, NRF5340_XXAA, NRF5340_XXAA_APPLICATION, SECURE_S, etc. |

### Bibliothèques générées

Pour chaque profil, deux bibliothèques statiques sont générées :

- `libTinyUSB_FS.a` - Version Full Speed (avec `-DSYSTEM_TINYUSB_FS_S`)
- `libTinyUSB_HS.a` - Version High Speed (avec `-DSYSTEM_TINYUSB_HS_S`)

Les bibliothèques sont placées dans les sous-répertoires de chaque profil :
```
STM32H743/
├── cdc_cdc/
│   ├── libTinyUSB_FS.a
│   └── libTinyUSB_HS.a
└── cdc_msc/
    ├── libTinyUSB_FS.a
    └── libTinyUSB_HS.a
```

## Ajout d'un nouveau SOC

Pour ajouter un nouveau SOC, créez un nouveau `CMakeLists.txt` dans le dossier approprié :

```cmake
cmake_minimum_required(VERSION 3.15)

# Configuration du compilateur ARM
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

if(NOT DEFINED CMAKE_C_COMPILER)
    if(DEFINED ENV{PATH_GCC_ARM})
        set(CMAKE_C_COMPILER "$ENV{PATH_GCC_ARM}/bin/arm-none-eabi-gcc")
        set(CMAKE_AR "$ENV{PATH_GCC_ARM}/bin/arm-none-eabi-ar")
        set(CMAKE_RANLIB "$ENV{PATH_GCC_ARM}/bin/arm-none-eabi-ranlib")
        set(CMAKE_STRIP "$ENV{PATH_GCC_ARM}/bin/arm-none-eabi-strip")
    else()
        message(FATAL_ERROR "PATH_GCC_ARM n'est pas défini")
    endif()
endif()

project(TinyUSB_YOUR_SOC C)

# Inclure le module TinyUSB commun
include(${CMAKE_CURRENT_SOURCE_DIR}/../../Mkfiles/TinyUSB.cmake)

# Options pour les profils
option(BUILD_CDC_CDC "Construire le profil cdc_cdc" ON)
option(BUILD_CDC_MSC "Construire le profil cdc_msc" ON)

# Liste des profils
set(PROFILES_TO_BUILD "")
if(BUILD_CDC_CDC)
    list(APPEND PROFILES_TO_BUILD "cdc_cdc")
endif()
if(BUILD_CDC_MSC)
    list(APPEND PROFILES_TO_BUILD "cdc_msc")
endif()

# Appeler la fonction de construction
add_tinyusb_libraries(
    SOC "YOUR_SOC"
    FAMILY "your_family"
    CORE "CORTEX_MX"
    CPU_SPEC "-mcpu=cortex-mx"
    FLAGS_FP "-mfloat-abi=hard -mfpu=fpvX-sp-d16"
    DEFS_UKOS_EXTRA ""  # ou "-DEXTRA_FLAG" si nécessaire
    PROFILES_LIST ${PROFILES_TO_BUILD}
    PROVIDER "st"
)
```

## Avantages de cette approche

1. **DRY** : Toute la logique commune est centralisée dans `TinyUSB.cmake`
2. **Cohérent** : Suit exactement la structure de `TinyUSB.mk`
3. **Maintenable** : Les changements se font à un seul endroit
4. **Flexible** : Options de construction granulaires par profil
5. **Extensible** : Facile d'ajouter de nouveaux SOCs ou profils
6. **Testable** : Chaque SOC peut être construit indépendamment
7. **CMake-native** : Utilise FetchContent pour les dépendances externes (pas de scripts Python)
8. **Automatique** : Téléchargement transparent des dépendances Nordic sans intervention manuelle
9. **Reproductible** : Commits Git figés garantissent des builds identiques

## Compatibilité avec les Makefiles

Les Makefiles originaux restent intacts et fonctionnels. Ce système CMake offre simplement une alternative moderne pour ceux qui préfèrent CMake.

## Support multi-provider

Le système supporte maintenant plusieurs providers de SOC :

### Provider ST (STMicroelectronics)
- Familles : F2, H7, L4, N6, U5
- Utilise les chemins CMSIS standard de ST
- Chemins d'inclusion depuis `Ports/EquatesModels/`

### Provider Nordic
- Famille : nRF
- SOC supporté : nRF5340 (Cortex-M33)
- **Différences clés** :
  - Utilise nrfx (Nordic HAL)
  - Sources additionnelles : `nrfx_usbreg.c`, `nrfx_power.c`, `system_nrf5340_application.c`
  - Fichier `init.c` au niveau du SOC (pas du profil)
  - Flags spécifiques : `NRF5340_XXAA`, `NRF5340_XXAA_APPLICATION`, `CPU_APPLICATION_S`
  - **Dépendances externes gérées automatiquement** : CMake télécharge automatiquement nrfx et CMSIS_5

#### Gestion automatique des dépendances Nordic

Le système CMake utilise `FetchContent` pour télécharger automatiquement les dépendances Nordic si elles ne sont pas présentes :

**Dépendances téléchargées automatiquement :**
- `hw/mcu/nordic/nrfx` - Driver nrfx de Nordic Semiconductor (commit 7c47cc0)
- `lib/CMSIS_5` - CMSIS standard ARM (commit 2b7495b)

**Avantages de cette approche :**
- ✅ Aucune installation manuelle requise
- ✅ Versions exactes garanties (commits figés)
- ✅ Téléchargement incrémental (shallow clone)
- ✅ Réutilisation si déjà téléchargé
- ✅ CMake-native, pas de dépendance Python

#### Exemple de construction Nordic

```bash
# Construction simple - CMake gère tout
cd Third_Parties/TinyUSB/Library/Family/nrf/nRF5340
mkdir build && cd build
cmake ..      # Téléchargera automatiquement nrfx et CMSIS_5 si nécessaire
cmake --build .

# Ou utiliser le script automatique
cd Third_Parties/TinyUSB
./build_with_cmake.sh
```

**Note :** La première compilation nécessite une connexion Internet pour télécharger les dépendances. Les builds suivants réutiliseront les dépendances déjà téléchargées.

## Validation des builds CMake

**Important :** Les builds Make et CMake écrivent dans les mêmes répertoires. Utilisez le script de comparaison automatique :

```bash
cd Third_Parties/TinyUSB

# Comparaison automatique (recommandé)
./compare_all_socs.sh                         # Tous les SOCs
./compare_builds.sh l4 STM32L4R5              # Un SOC, tous profils
./compare_builds.sh h7 STM32H747 cdc_cdc      # Un SOC, profil spécifique
```

Ce script :
1. Construit avec Make et sauvegarde dans un répertoire temporaire
2. Construit avec CMake dans les emplacements normaux
3. Compare les deux builds automatiquement

**Vérification rapide d'une bibliothèque :**
```bash
./quick_symbol_check.sh Library/Family/l4/STM32L4R5/cdc_cdc/libTinyUSB_FS.a
```

Le script de validation vérifie :
- Tailles des fichiers et sections
- Nombre et liste des symboles exportés
- Dépendances externes (symboles indéfinis)
- Nombre de fichiers objets dans l'archive
- Présence d'informations de debug

**Documentation complète** : Voir `VALIDATION.md` pour les détails sur l'interprétation des résultats et le dépannage.

## Support

Pour toute question ou problème, référez-vous à :
- `TinyUSB.mk` pour la logique originale
- `TinyUSB.cmake` pour l'implémentation CMake correspondante
- `VALIDATION.md` pour la validation des builds
