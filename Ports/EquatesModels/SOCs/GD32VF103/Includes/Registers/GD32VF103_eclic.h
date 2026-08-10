/*
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
 *
 * Generated using the .svd description
 * Goal:     GD32VF103_eclic equates.
 */

#pragma once

#include    <stdint.h>

// ECLIC address definitions
// -------------------------

typedef struct {
    volatile    uint8_t     CLICCFG;
    volatile    uint8_t     RESERVED0[3];
    volatile    uint32_t    CLICINFO;
    volatile    uint8_t     RESERVED1[3];
    volatile    uint8_t     MTH;
    volatile    uint32_t    RESERVED2[1021];
    volatile    uint8_t     CLICINTIP_0;
    volatile    uint8_t     CLICINTIE_0;
    volatile    uint8_t     CLICINTATTR_0;
    volatile    uint8_t     CLICINTCTL_0;
    volatile    uint8_t     CLICINTIP_1;
    volatile    uint8_t     CLICINTIE_1;
    volatile    uint8_t     CLICINTATTR_1;
    volatile    uint8_t     CLICINTCTL_1;
    volatile    uint8_t     CLICINTIP_2;
    volatile    uint8_t     CLICINTIE_2;
    volatile    uint8_t     CLICINTATTR_2;
    volatile    uint8_t     CLICINTCTL_2;
    volatile    uint8_t     CLICINTIP_3;
    volatile    uint8_t     CLICINTIE_3;
    volatile    uint8_t     CLICINTATTR_3;
    volatile    uint8_t     CLICINTCTL_3;
    volatile    uint8_t     CLICINTIP_4;
    volatile    uint8_t     CLICINTIE_4;
    volatile    uint8_t     CLICINTATTR_4;
    volatile    uint8_t     CLICINTCTL_4;
    volatile    uint8_t     CLICINTIP_5;
    volatile    uint8_t     CLICINTIE_5;
    volatile    uint8_t     CLICINTATTR_5;
    volatile    uint8_t     CLICINTCTL_5;
    volatile    uint8_t     CLICINTIP_6;
    volatile    uint8_t     CLICINTIE_6;
    volatile    uint8_t     CLICINTATTR_6;
    volatile    uint8_t     CLICINTCTL_6;
    volatile    uint8_t     CLICINTIP_7;
    volatile    uint8_t     CLICINTIE_7;
    volatile    uint8_t     CLICINTATTR_7;
    volatile    uint8_t     CLICINTCTL_7;
    volatile    uint8_t     CLICINTIP_8;
    volatile    uint8_t     CLICINTIE_8;
    volatile    uint8_t     CLICINTATTR_8;
    volatile    uint8_t     CLICINTCTL_8;
    volatile    uint8_t     CLICINTIP_9;
    volatile    uint8_t     CLICINTIE_9;
    volatile    uint8_t     CLICINTATTR_9;
    volatile    uint8_t     CLICINTCTL_9;
    volatile    uint8_t     CLICINTIP_10;
    volatile    uint8_t     CLICINTIE_10;
    volatile    uint8_t     CLICINTATTR_10;
    volatile    uint8_t     CLICINTCTL_10;
    volatile    uint8_t     CLICINTIP_11;
    volatile    uint8_t     CLICINTIE_11;
    volatile    uint8_t     CLICINTATTR_11;
    volatile    uint8_t     CLICINTCTL_11;
    volatile    uint8_t     CLICINTIP_12;
    volatile    uint8_t     CLICINTIE_12;
    volatile    uint8_t     CLICINTATTR_12;
    volatile    uint8_t     CLICINTCTL_12;
    volatile    uint8_t     CLICINTIP_13;
    volatile    uint8_t     CLICINTIE_13;
    volatile    uint8_t     CLICINTATTR_13;
    volatile    uint8_t     CLICINTCTL_13;
    volatile    uint8_t     CLICINTIP_14;
    volatile    uint8_t     CLICINTIE_14;
    volatile    uint8_t     CLICINTATTR_14;
    volatile    uint8_t     CLICINTCTL_14;
    volatile    uint8_t     CLICINTIP_15;
    volatile    uint8_t     CLICINTIE_15;
    volatile    uint8_t     CLICINTATTR_15;
    volatile    uint8_t     CLICINTCTL_15;
    volatile    uint8_t     CLICINTIP_16;
    volatile    uint8_t     CLICINTIE_16;
    volatile    uint8_t     CLICINTATTR_16;
    volatile    uint8_t     CLICINTCTL_16;
    volatile    uint8_t     CLICINTIP_17;
    volatile    uint8_t     CLICINTIE_17;
    volatile    uint8_t     CLICINTATTR_17;
    volatile    uint8_t     CLICINTCTL_17;
    volatile    uint8_t     CLICINTIP_18;
    volatile    uint8_t     CLICINTIE_18;
    volatile    uint8_t     CLICINTATTR_18;
    volatile    uint8_t     CLICINTCTL_18;
    volatile    uint8_t     CLICINTIP_19;
    volatile    uint8_t     CLICINTIE_19;
    volatile    uint8_t     CLICINTATTR_19;
    volatile    uint8_t     CLICINTCTL_19;
    volatile    uint8_t     CLICINTIP_20;
    volatile    uint8_t     CLICINTIE_20;
    volatile    uint8_t     CLICINTATTR_20;
    volatile    uint8_t     CLICINTCTL_20;
    volatile    uint8_t     CLICINTIP_21;
    volatile    uint8_t     CLICINTIE_21;
    volatile    uint8_t     CLICINTATTR_21;
    volatile    uint8_t     CLICINTCTL_21;
    volatile    uint8_t     CLICINTIP_22;
    volatile    uint8_t     CLICINTIE_22;
    volatile    uint8_t     CLICINTATTR_22;
    volatile    uint8_t     CLICINTCTL_22;
    volatile    uint8_t     CLICINTIP_23;
    volatile    uint8_t     CLICINTIE_23;
    volatile    uint8_t     CLICINTATTR_23;
    volatile    uint8_t     CLICINTCTL_23;
    volatile    uint8_t     CLICINTIP_24;
    volatile    uint8_t     CLICINTIE_24;
    volatile    uint8_t     CLICINTATTR_24;
    volatile    uint8_t     CLICINTCTL_24;
    volatile    uint8_t     CLICINTIP_25;
    volatile    uint8_t     CLICINTIE_25;
    volatile    uint8_t     CLICINTATTR_25;
    volatile    uint8_t     CLICINTCTL_25;
    volatile    uint8_t     CLICINTIP_26;
    volatile    uint8_t     CLICINTIE_26;
    volatile    uint8_t     CLICINTATTR_26;
    volatile    uint8_t     CLICINTCTL_26;
    volatile    uint8_t     CLICINTIP_27;
    volatile    uint8_t     CLICINTIE_27;
    volatile    uint8_t     CLICINTATTR_27;
    volatile    uint8_t     CLICINTCTL_27;
    volatile    uint8_t     CLICINTIP_28;
    volatile    uint8_t     CLICINTIE_28;
    volatile    uint8_t     CLICINTATTR_28;
    volatile    uint8_t     CLICINTCTL_28;
    volatile    uint8_t     CLICINTIP_29;
    volatile    uint8_t     CLICINTIE_29;
    volatile    uint8_t     CLICINTATTR_29;
    volatile    uint8_t     CLICINTCTL_29;
    volatile    uint8_t     CLICINTIP_30;
    volatile    uint8_t     CLICINTIE_30;
    volatile    uint8_t     CLICINTATTR_30;
    volatile    uint8_t     CLICINTCTL_30;
    volatile    uint8_t     CLICINTIP_31;
    volatile    uint8_t     CLICINTIE_31;
    volatile    uint8_t     CLICINTATTR_31;
    volatile    uint8_t     CLICINTCTL_31;
    volatile    uint8_t     CLICINTIP_32;
    volatile    uint8_t     CLICINTIE_32;
    volatile    uint8_t     CLICINTATTR_32;
    volatile    uint8_t     CLICINTCTL_32;
    volatile    uint8_t     CLICINTIP_33;
    volatile    uint8_t     CLICINTIE_33;
    volatile    uint8_t     CLICINTATTR_33;
    volatile    uint8_t     CLICINTCTL_33;
    volatile    uint8_t     CLICINTIP_34;
    volatile    uint8_t     CLICINTIE_34;
    volatile    uint8_t     CLICINTATTR_34;
    volatile    uint8_t     CLICINTCTL_34;
    volatile    uint8_t     CLICINTIP_35;
    volatile    uint8_t     CLICINTIE_35;
    volatile    uint8_t     CLICINTATTR_35;
    volatile    uint8_t     CLICINTCTL_35;
    volatile    uint8_t     CLICINTIP_36;
    volatile    uint8_t     CLICINTIE_36;
    volatile    uint8_t     CLICINTATTR_36;
    volatile    uint8_t     CLICINTCTL_36;
    volatile    uint8_t     CLICINTIP_37;
    volatile    uint8_t     CLICINTIE_37;
    volatile    uint8_t     CLICINTATTR_37;
    volatile    uint8_t     CLICINTCTL_37;
    volatile    uint8_t     CLICINTIP_38;
    volatile    uint8_t     CLICINTIE_38;
    volatile    uint8_t     CLICINTATTR_38;
    volatile    uint8_t     CLICINTCTL_38;
    volatile    uint8_t     CLICINTIP_39;
    volatile    uint8_t     CLICINTIE_39;
    volatile    uint8_t     CLICINTATTR_39;
    volatile    uint8_t     CLICINTCTL_39;
    volatile    uint8_t     CLICINTIP_40;
    volatile    uint8_t     CLICINTIE_40;
    volatile    uint8_t     CLICINTATTR_40;
    volatile    uint8_t     CLICINTCTL_40;
    volatile    uint8_t     CLICINTIP_41;
    volatile    uint8_t     CLICINTIE_41;
    volatile    uint8_t     CLICINTATTR_41;
    volatile    uint8_t     CLICINTCTL_41;
    volatile    uint8_t     CLICINTIP_42;
    volatile    uint8_t     CLICINTIE_42;
    volatile    uint8_t     CLICINTATTR_42;
    volatile    uint8_t     CLICINTCTL_42;
    volatile    uint8_t     CLICINTIP_43;
    volatile    uint8_t     CLICINTIE_43;
    volatile    uint8_t     CLICINTATTR_43;
    volatile    uint8_t     CLICINTCTL_43;
    volatile    uint8_t     CLICINTIP_44;
    volatile    uint8_t     CLICINTIE_44;
    volatile    uint8_t     CLICINTATTR_44;
    volatile    uint8_t     CLICINTCTL_44;
    volatile    uint8_t     CLICINTIP_45;
    volatile    uint8_t     CLICINTIE_45;
    volatile    uint8_t     CLICINTATTR_45;
    volatile    uint8_t     CLICINTCTL_45;
    volatile    uint8_t     CLICINTIP_46;
    volatile    uint8_t     CLICINTIE_46;
    volatile    uint8_t     CLICINTATTR_46;
    volatile    uint8_t     CLICINTCTL_46;
    volatile    uint8_t     CLICINTIP_47;
    volatile    uint8_t     CLICINTIE_47;
    volatile    uint8_t     CLICINTATTR_47;
    volatile    uint8_t     CLICINTCTL_47;
    volatile    uint8_t     CLICINTIP_48;
    volatile    uint8_t     CLICINTIE_48;
    volatile    uint8_t     CLICINTATTR_48;
    volatile    uint8_t     CLICINTCTL_48;
    volatile    uint8_t     CLICINTIP_49;
    volatile    uint8_t     CLICINTIE_49;
    volatile    uint8_t     CLICINTATTR_49;
    volatile    uint8_t     CLICINTCTL_49;
    volatile    uint8_t     CLICINTIP_50;
    volatile    uint8_t     CLICINTIE_50;
    volatile    uint8_t     CLICINTATTR_50;
    volatile    uint8_t     CLICINTCTL_50;
    volatile    uint8_t     CLICINTIP_51;
    volatile    uint8_t     CLICINTIE_51;
    volatile    uint8_t     CLICINTATTR_51;
    volatile    uint8_t     CLICINTCTL_51;
    volatile    uint8_t     CLICINTIP_52;
    volatile    uint8_t     CLICINTIE_52;
    volatile    uint8_t     CLICINTATTR_52;
    volatile    uint8_t     CLICINTCTL_52;
    volatile    uint8_t     CLICINTIP_53;
    volatile    uint8_t     CLICINTIE_53;
    volatile    uint8_t     CLICINTATTR_53;
    volatile    uint8_t     CLICINTCTL_53;
    volatile    uint8_t     CLICINTIP_54;
    volatile    uint8_t     CLICINTIE_54;
    volatile    uint8_t     CLICINTATTR_54;
    volatile    uint8_t     CLICINTCTL_54;
    volatile    uint8_t     CLICINTIP_55;
    volatile    uint8_t     CLICINTIE_55;
    volatile    uint8_t     CLICINTATTR_55;
    volatile    uint8_t     CLICINTCTL_55;
    volatile    uint8_t     CLICINTIP_56;
    volatile    uint8_t     CLICINTIE_56;
    volatile    uint8_t     CLICINTATTR_56;
    volatile    uint8_t     CLICINTCTL_56;
    volatile    uint8_t     CLICINTIP_57;
    volatile    uint8_t     CLICINTIE_57;
    volatile    uint8_t     CLICINTATTR_57;
    volatile    uint8_t     CLICINTCTL_57;
    volatile    uint8_t     CLICINTIP_58;
    volatile    uint8_t     CLICINTIE_58;
    volatile    uint8_t     CLICINTATTR_58;
    volatile    uint8_t     CLICINTCTL_58;
    volatile    uint8_t     CLICINTIP_59;
    volatile    uint8_t     CLICINTIE_59;
    volatile    uint8_t     CLICINTATTR_59;
    volatile    uint8_t     CLICINTCTL_59;
    volatile    uint8_t     CLICINTIP_60;
    volatile    uint8_t     CLICINTIE_60;
    volatile    uint8_t     CLICINTATTR_60;
    volatile    uint8_t     CLICINTCTL_60;
    volatile    uint8_t     CLICINTIP_61;
    volatile    uint8_t     CLICINTIE_61;
    volatile    uint8_t     CLICINTATTR_61;
    volatile    uint8_t     CLICINTCTL_61;
    volatile    uint8_t     CLICINTIP_62;
    volatile    uint8_t     CLICINTIE_62;
    volatile    uint8_t     CLICINTATTR_62;
    volatile    uint8_t     CLICINTCTL_62;
    volatile    uint8_t     CLICINTIP_63;
    volatile    uint8_t     CLICINTIE_63;
    volatile    uint8_t     CLICINTATTR_63;
    volatile    uint8_t     CLICINTCTL_63;
    volatile    uint8_t     CLICINTIP_64;
    volatile    uint8_t     CLICINTIE_64;
    volatile    uint8_t     CLICINTATTR_64;
    volatile    uint8_t     CLICINTCTL_64;
    volatile    uint8_t     CLICINTIP_65;
    volatile    uint8_t     CLICINTIE_65;
    volatile    uint8_t     CLICINTATTR_65;
    volatile    uint8_t     CLICINTCTL_65;
    volatile    uint8_t     CLICINTIP_66;
    volatile    uint8_t     CLICINTIE_66;
    volatile    uint8_t     CLICINTATTR_66;
    volatile    uint8_t     CLICINTCTL_66;
    volatile    uint8_t     CLICINTIP_67;
    volatile    uint8_t     CLICINTIE_67;
    volatile    uint8_t     CLICINTATTR_67;
    volatile    uint8_t     CLICINTCTL_67;
    volatile    uint8_t     CLICINTIP_68;
    volatile    uint8_t     CLICINTIE_68;
    volatile    uint8_t     CLICINTATTR_68;
    volatile    uint8_t     CLICINTCTL_68;
    volatile    uint8_t     CLICINTIP_69;
    volatile    uint8_t     CLICINTIE_69;
    volatile    uint8_t     CLICINTATTR_69;
    volatile    uint8_t     CLICINTCTL_69;
    volatile    uint8_t     CLICINTIP_70;
    volatile    uint8_t     CLICINTIE_70;
    volatile    uint8_t     CLICINTATTR_70;
    volatile    uint8_t     CLICINTCTL_70;
    volatile    uint8_t     CLICINTIP_71;
    volatile    uint8_t     CLICINTIE_71;
    volatile    uint8_t     CLICINTATTR_71;
    volatile    uint8_t     CLICINTCTL_71;
    volatile    uint8_t     CLICINTIP_72;
    volatile    uint8_t     CLICINTIE_72;
    volatile    uint8_t     CLICINTATTR_72;
    volatile    uint8_t     CLICINTCTL_72;
    volatile    uint8_t     CLICINTIP_73;
    volatile    uint8_t     CLICINTIE_73;
    volatile    uint8_t     CLICINTATTR_73;
    volatile    uint8_t     CLICINTCTL_73;
    volatile    uint8_t     CLICINTIP_74;
    volatile    uint8_t     CLICINTIE_74;
    volatile    uint8_t     CLICINTATTR_74;
    volatile    uint8_t     CLICINTCTL_74;
    volatile    uint8_t     CLICINTIP_75;
    volatile    uint8_t     CLICINTIE_75;
    volatile    uint8_t     CLICINTATTR_75;
    volatile    uint8_t     CLICINTCTL_75;
    volatile    uint8_t     CLICINTIP_76;
    volatile    uint8_t     CLICINTIE_76;
    volatile    uint8_t     CLICINTATTR_76;
    volatile    uint8_t     CLICINTCTL_76;
    volatile    uint8_t     CLICINTIP_77;
    volatile    uint8_t     CLICINTIE_77;
    volatile    uint8_t     CLICINTATTR_77;
    volatile    uint8_t     CLICINTCTL_77;
    volatile    uint8_t     CLICINTIP_78;
    volatile    uint8_t     CLICINTIE_78;
    volatile    uint8_t     CLICINTATTR_78;
    volatile    uint8_t     CLICINTCTL_78;
    volatile    uint8_t     CLICINTIP_79;
    volatile    uint8_t     CLICINTIE_79;
    volatile    uint8_t     CLICINTATTR_79;
    volatile    uint8_t     CLICINTCTL_79;
    volatile    uint8_t     CLICINTIP_80;
    volatile    uint8_t     CLICINTIE_80;
    volatile    uint8_t     CLICINTATTR_80;
    volatile    uint8_t     CLICINTCTL_80;
    volatile    uint8_t     CLICINTIP_81;
    volatile    uint8_t     CLICINTIE_81;
    volatile    uint8_t     CLICINTATTR_81;
    volatile    uint8_t     CLICINTCTL_81;
    volatile    uint8_t     CLICINTIP_82;
    volatile    uint8_t     CLICINTIE_82;
    volatile    uint8_t     CLICINTATTR_82;
    volatile    uint8_t     CLICINTCTL_82;
    volatile    uint8_t     CLICINTIP_83;
    volatile    uint8_t     CLICINTIE_83;
    volatile    uint8_t     CLICINTATTR_83;
    volatile    uint8_t     CLICINTCTL_83;
    volatile    uint8_t     CLICINTIP_84;
    volatile    uint8_t     CLICINTIE_84;
    volatile    uint8_t     CLICINTATTR_84;
    volatile    uint8_t     CLICINTCTL_84;
    volatile    uint8_t     RESERVED3;
    volatile    uint8_t     CLICINTIE_85;
    volatile    uint8_t     CLICINTATTR_85;
    volatile    uint8_t     CLICINTCTL_85;
    volatile    uint8_t     CLICINTIP_85;
    volatile    uint8_t     CLICINTIE_86;
    volatile    uint8_t     CLICINTATTR_86;
    volatile    uint8_t     CLICINTCTL_86;
    volatile    uint8_t     CLICINTIP_86;
} ECLIC_TypeDef;

#ifdef __cplusplus
#define ECLIC   reinterpret_cast<ECLIC_TypeDef *>(0xD2000000U)

#else
#define ECLIC   ((ECLIC_TypeDef *)0xD2000000U)
#endif

// CLICCFG Configuration

#define ECLIC_CLICCFG_NLBITS                    (0xFU<<1U)
#define ECLIC_CLICCFG_NLBITS_0                  (0x1U<<1U)

// CLICINFO Configuration

#define ECLIC_CLICINFO_CLICINTCTLBITS           (0xFU<<21U)
#define ECLIC_CLICINFO_CLICINTCTLBITS_0         (0x1U<<21U)
#define ECLIC_CLICINFO_VERSION                  (0xFFU<<13U)
#define ECLIC_CLICINFO_VERSION_0                (0x1U<<13U)
#define ECLIC_CLICINFO_NUM_INTERRUPT            (0x1FFFU<<0U)
#define ECLIC_CLICINFO_NUM_INTERRUPT_0          (0x1U<<0U)

// MTH Configuration

#define ECLIC_MTH_MTH                           (0xFFU<<0U)
#define ECLIC_MTH_MTH_0                         (0x1U<<0U)

// CLICINTIP_0 Configuration

#define ECLIC_CLICINTIP_0_IP                    (0x1U<<0U)

// CLICINTIE_0 Configuration

#define ECLIC_CLICINTIE_0_IE                    (0x1U<<0U)

// CLICINTATTR_0 Configuration

#define ECLIC_CLICINTATTR_0_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_0_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_0_SHV                 (0x1U<<0U)

// CLICINTCTL_0 Configuration

#define ECLIC_CLICINTCTL_0_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_0_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_1 Configuration

#define ECLIC_CLICINTIP_1_IP                    (0x1U<<0U)

// CLICINTIE_1 Configuration

#define ECLIC_CLICINTIE_1_IE                    (0x1U<<0U)

// CLICINTATTR_1 Configuration

#define ECLIC_CLICINTATTR_1_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_1_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_1_SHV                 (0x1U<<0U)

// CLICINTCTL_1 Configuration

#define ECLIC_CLICINTCTL_1_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_1_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_2 Configuration

#define ECLIC_CLICINTIP_2_IP                    (0x1U<<0U)

// CLICINTIE_2 Configuration

#define ECLIC_CLICINTIE_2_IE                    (0x1U<<0U)

// CLICINTATTR_2 Configuration

#define ECLIC_CLICINTATTR_2_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_2_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_2_SHV                 (0x1U<<0U)

// CLICINTCTL_2 Configuration

#define ECLIC_CLICINTCTL_2_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_2_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_3 Configuration

#define ECLIC_CLICINTIP_3_IP                    (0x1U<<0U)

// CLICINTIE_3 Configuration

#define ECLIC_CLICINTIE_3_IE                    (0x1U<<0U)

// CLICINTATTR_3 Configuration

#define ECLIC_CLICINTATTR_3_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_3_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_3_SHV                 (0x1U<<0U)

// CLICINTCTL_3 Configuration

#define ECLIC_CLICINTCTL_3_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_3_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_4 Configuration

#define ECLIC_CLICINTIP_4_IP                    (0x1U<<0U)

// CLICINTIE_4 Configuration

#define ECLIC_CLICINTIE_4_IE                    (0x1U<<0U)

// CLICINTATTR_4 Configuration

#define ECLIC_CLICINTATTR_4_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_4_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_4_SHV                 (0x1U<<0U)

// CLICINTCTL_4 Configuration

#define ECLIC_CLICINTCTL_4_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_4_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_5 Configuration

#define ECLIC_CLICINTIP_5_IP                    (0x1U<<0U)

// CLICINTIE_5 Configuration

#define ECLIC_CLICINTIE_5_IE                    (0x1U<<0U)

// CLICINTATTR_5 Configuration

#define ECLIC_CLICINTATTR_5_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_5_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_5_SHV                 (0x1U<<0U)

// CLICINTCTL_5 Configuration

#define ECLIC_CLICINTCTL_5_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_5_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_6 Configuration

#define ECLIC_CLICINTIP_6_IP                    (0x1U<<0U)

// CLICINTIE_6 Configuration

#define ECLIC_CLICINTIE_6_IE                    (0x1U<<0U)

// CLICINTATTR_6 Configuration

#define ECLIC_CLICINTATTR_6_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_6_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_6_SHV                 (0x1U<<0U)

// CLICINTCTL_6 Configuration

#define ECLIC_CLICINTCTL_6_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_6_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_7 Configuration

#define ECLIC_CLICINTIP_7_IP                    (0x1U<<0U)

// CLICINTIE_7 Configuration

#define ECLIC_CLICINTIE_7_IE                    (0x1U<<0U)

// CLICINTATTR_7 Configuration

#define ECLIC_CLICINTATTR_7_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_7_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_7_SHV                 (0x1U<<0U)

// CLICINTCTL_7 Configuration

#define ECLIC_CLICINTCTL_7_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_7_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_8 Configuration

#define ECLIC_CLICINTIP_8_IP                    (0x1U<<0U)

// CLICINTIE_8 Configuration

#define ECLIC_CLICINTIE_8_IE                    (0x1U<<0U)

// CLICINTATTR_8 Configuration

#define ECLIC_CLICINTATTR_8_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_8_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_8_SHV                 (0x1U<<0U)

// CLICINTCTL_8 Configuration

#define ECLIC_CLICINTCTL_8_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_8_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_9 Configuration

#define ECLIC_CLICINTIP_9_IP                    (0x1U<<0U)

// CLICINTIE_9 Configuration

#define ECLIC_CLICINTIE_9_IE                    (0x1U<<0U)

// CLICINTATTR_9 Configuration

#define ECLIC_CLICINTATTR_9_TRIG                (0x3U<<1U)
#define ECLIC_CLICINTATTR_9_TRIG_0              (0x1U<<1U)
#define ECLIC_CLICINTATTR_9_SHV                 (0x1U<<0U)

// CLICINTCTL_9 Configuration

#define ECLIC_CLICINTCTL_9_LEVEL_PRIORITY       (0xFFU<<0U)
#define ECLIC_CLICINTCTL_9_LEVEL_PRIORITY_0     (0x1U<<0U)

// CLICINTIP_10 Configuration

#define ECLIC_CLICINTIP_10_IP                   (0x1U<<0U)

// CLICINTIE_10 Configuration

#define ECLIC_CLICINTIE_10_IE                   (0x1U<<0U)

// CLICINTATTR_10 Configuration

#define ECLIC_CLICINTATTR_10_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_10_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_10_SHV                (0x1U<<0U)

// CLICINTCTL_10 Configuration

#define ECLIC_CLICINTCTL_10_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_10_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_11 Configuration

#define ECLIC_CLICINTIP_11_IP                   (0x1U<<0U)

// CLICINTIE_11 Configuration

#define ECLIC_CLICINTIE_11_IE                   (0x1U<<0U)

// CLICINTATTR_11 Configuration

#define ECLIC_CLICINTATTR_11_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_11_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_11_SHV                (0x1U<<0U)

// CLICINTCTL_11 Configuration

#define ECLIC_CLICINTCTL_11_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_11_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_12 Configuration

#define ECLIC_CLICINTIP_12_IP                   (0x1U<<0U)

// CLICINTIE_12 Configuration

#define ECLIC_CLICINTIE_12_IE                   (0x1U<<0U)

// CLICINTATTR_12 Configuration

#define ECLIC_CLICINTATTR_12_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_12_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_12_SHV                (0x1U<<0U)

// CLICINTCTL_12 Configuration

#define ECLIC_CLICINTCTL_12_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_12_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_13 Configuration

#define ECLIC_CLICINTIP_13_IP                   (0x1U<<0U)

// CLICINTIE_13 Configuration

#define ECLIC_CLICINTIE_13_IE                   (0x1U<<0U)

// CLICINTATTR_13 Configuration

#define ECLIC_CLICINTATTR_13_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_13_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_13_SHV                (0x1U<<0U)

// CLICINTCTL_13 Configuration

#define ECLIC_CLICINTCTL_13_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_13_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_14 Configuration

#define ECLIC_CLICINTIP_14_IP                   (0x1U<<0U)

// CLICINTIE_14 Configuration

#define ECLIC_CLICINTIE_14_IE                   (0x1U<<0U)

// CLICINTATTR_14 Configuration

#define ECLIC_CLICINTATTR_14_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_14_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_14_SHV                (0x1U<<0U)

// CLICINTCTL_14 Configuration

#define ECLIC_CLICINTCTL_14_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_14_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_15 Configuration

#define ECLIC_CLICINTIP_15_IP                   (0x1U<<0U)

// CLICINTIE_15 Configuration

#define ECLIC_CLICINTIE_15_IE                   (0x1U<<0U)

// CLICINTATTR_15 Configuration

#define ECLIC_CLICINTATTR_15_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_15_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_15_SHV                (0x1U<<0U)

// CLICINTCTL_15 Configuration

#define ECLIC_CLICINTCTL_15_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_15_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_16 Configuration

#define ECLIC_CLICINTIP_16_IP                   (0x1U<<0U)

// CLICINTIE_16 Configuration

#define ECLIC_CLICINTIE_16_IE                   (0x1U<<0U)

// CLICINTATTR_16 Configuration

#define ECLIC_CLICINTATTR_16_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_16_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_16_SHV                (0x1U<<0U)

// CLICINTCTL_16 Configuration

#define ECLIC_CLICINTCTL_16_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_16_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_17 Configuration

#define ECLIC_CLICINTIP_17_IP                   (0x1U<<0U)

// CLICINTIE_17 Configuration

#define ECLIC_CLICINTIE_17_IE                   (0x1U<<0U)

// CLICINTATTR_17 Configuration

#define ECLIC_CLICINTATTR_17_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_17_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_17_SHV                (0x1U<<0U)

// CLICINTCTL_17 Configuration

#define ECLIC_CLICINTCTL_17_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_17_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_18 Configuration

#define ECLIC_CLICINTIP_18_IP                   (0x1U<<0U)

// CLICINTIE_18 Configuration

#define ECLIC_CLICINTIE_18_IE                   (0x1U<<0U)

// CLICINTATTR_18 Configuration

#define ECLIC_CLICINTATTR_18_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_18_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_18_SHV                (0x1U<<0U)

// CLICINTCTL_18 Configuration

#define ECLIC_CLICINTCTL_18_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_18_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_19 Configuration

#define ECLIC_CLICINTIP_19_IP                   (0x1U<<0U)

// CLICINTIE_19 Configuration

#define ECLIC_CLICINTIE_19_IE                   (0x1U<<0U)

// CLICINTATTR_19 Configuration

#define ECLIC_CLICINTATTR_19_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_19_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_19_SHV                (0x1U<<0U)

// CLICINTCTL_19 Configuration

#define ECLIC_CLICINTCTL_19_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_19_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_20 Configuration

#define ECLIC_CLICINTIP_20_IP                   (0x1U<<0U)

// CLICINTIE_20 Configuration

#define ECLIC_CLICINTIE_20_IE                   (0x1U<<0U)

// CLICINTATTR_20 Configuration

#define ECLIC_CLICINTATTR_20_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_20_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_20_SHV                (0x1U<<0U)

// CLICINTCTL_20 Configuration

#define ECLIC_CLICINTCTL_20_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_20_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_21 Configuration

#define ECLIC_CLICINTIP_21_IP                   (0x1U<<0U)

// CLICINTIE_21 Configuration

#define ECLIC_CLICINTIE_21_IE                   (0x1U<<0U)

// CLICINTATTR_21 Configuration

#define ECLIC_CLICINTATTR_21_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_21_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_21_SHV                (0x1U<<0U)

// CLICINTCTL_21 Configuration

#define ECLIC_CLICINTCTL_21_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_21_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_22 Configuration

#define ECLIC_CLICINTIP_22_IP                   (0x1U<<0U)

// CLICINTIE_22 Configuration

#define ECLIC_CLICINTIE_22_IE                   (0x1U<<0U)

// CLICINTATTR_22 Configuration

#define ECLIC_CLICINTATTR_22_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_22_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_22_SHV                (0x1U<<0U)

// CLICINTCTL_22 Configuration

#define ECLIC_CLICINTCTL_22_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_22_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_23 Configuration

#define ECLIC_CLICINTIP_23_IP                   (0x1U<<0U)

// CLICINTIE_23 Configuration

#define ECLIC_CLICINTIE_23_IE                   (0x1U<<0U)

// CLICINTATTR_23 Configuration

#define ECLIC_CLICINTATTR_23_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_23_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_23_SHV                (0x1U<<0U)

// CLICINTCTL_23 Configuration

#define ECLIC_CLICINTCTL_23_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_23_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_24 Configuration

#define ECLIC_CLICINTIP_24_IP                   (0x1U<<0U)

// CLICINTIE_24 Configuration

#define ECLIC_CLICINTIE_24_IE                   (0x1U<<0U)

// CLICINTATTR_24 Configuration

#define ECLIC_CLICINTATTR_24_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_24_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_24_SHV                (0x1U<<0U)

// CLICINTCTL_24 Configuration

#define ECLIC_CLICINTCTL_24_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_24_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_25 Configuration

#define ECLIC_CLICINTIP_25_IP                   (0x1U<<0U)

// CLICINTIE_25 Configuration

#define ECLIC_CLICINTIE_25_IE                   (0x1U<<0U)

// CLICINTATTR_25 Configuration

#define ECLIC_CLICINTATTR_25_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_25_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_25_SHV                (0x1U<<0U)

// CLICINTCTL_25 Configuration

#define ECLIC_CLICINTCTL_25_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_25_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_26 Configuration

#define ECLIC_CLICINTIP_26_IP                   (0x1U<<0U)

// CLICINTIE_26 Configuration

#define ECLIC_CLICINTIE_26_IE                   (0x1U<<0U)

// CLICINTATTR_26 Configuration

#define ECLIC_CLICINTATTR_26_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_26_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_26_SHV                (0x1U<<0U)

// CLICINTCTL_26 Configuration

#define ECLIC_CLICINTCTL_26_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_26_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_27 Configuration

#define ECLIC_CLICINTIP_27_IP                   (0x1U<<0U)

// CLICINTIE_27 Configuration

#define ECLIC_CLICINTIE_27_IE                   (0x1U<<0U)

// CLICINTATTR_27 Configuration

#define ECLIC_CLICINTATTR_27_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_27_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_27_SHV                (0x1U<<0U)

// CLICINTCTL_27 Configuration

#define ECLIC_CLICINTCTL_27_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_27_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_28 Configuration

#define ECLIC_CLICINTIP_28_IP                   (0x1U<<0U)

// CLICINTIE_28 Configuration

#define ECLIC_CLICINTIE_28_IE                   (0x1U<<0U)

// CLICINTATTR_28 Configuration

#define ECLIC_CLICINTATTR_28_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_28_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_28_SHV                (0x1U<<0U)

// CLICINTCTL_28 Configuration

#define ECLIC_CLICINTCTL_28_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_28_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_29 Configuration

#define ECLIC_CLICINTIP_29_IP                   (0x1U<<0U)

// CLICINTIE_29 Configuration

#define ECLIC_CLICINTIE_29_IE                   (0x1U<<0U)

// CLICINTATTR_29 Configuration

#define ECLIC_CLICINTATTR_29_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_29_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_29_SHV                (0x1U<<0U)

// CLICINTCTL_29 Configuration

#define ECLIC_CLICINTCTL_29_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_29_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_30 Configuration

#define ECLIC_CLICINTIP_30_IP                   (0x1U<<0U)

// CLICINTIE_30 Configuration

#define ECLIC_CLICINTIE_30_IE                   (0x1U<<0U)

// CLICINTATTR_30 Configuration

#define ECLIC_CLICINTATTR_30_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_30_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_30_SHV                (0x1U<<0U)

// CLICINTCTL_30 Configuration

#define ECLIC_CLICINTCTL_30_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_30_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_31 Configuration

#define ECLIC_CLICINTIP_31_IP                   (0x1U<<0U)

// CLICINTIE_31 Configuration

#define ECLIC_CLICINTIE_31_IE                   (0x1U<<0U)

// CLICINTATTR_31 Configuration

#define ECLIC_CLICINTATTR_31_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_31_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_31_SHV                (0x1U<<0U)

// CLICINTCTL_31 Configuration

#define ECLIC_CLICINTCTL_31_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_31_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_32 Configuration

#define ECLIC_CLICINTIP_32_IP                   (0x1U<<0U)

// CLICINTIE_32 Configuration

#define ECLIC_CLICINTIE_32_IE                   (0x1U<<0U)

// CLICINTATTR_32 Configuration

#define ECLIC_CLICINTATTR_32_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_32_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_32_SHV                (0x1U<<0U)

// CLICINTCTL_32 Configuration

#define ECLIC_CLICINTCTL_32_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_32_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_33 Configuration

#define ECLIC_CLICINTIP_33_IP                   (0x1U<<0U)

// CLICINTIE_33 Configuration

#define ECLIC_CLICINTIE_33_IE                   (0x1U<<0U)

// CLICINTATTR_33 Configuration

#define ECLIC_CLICINTATTR_33_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_33_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_33_SHV                (0x1U<<0U)

// CLICINTCTL_33 Configuration

#define ECLIC_CLICINTCTL_33_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_33_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_34 Configuration

#define ECLIC_CLICINTIP_34_IP                   (0x1U<<0U)

// CLICINTIE_34 Configuration

#define ECLIC_CLICINTIE_34_IE                   (0x1U<<0U)

// CLICINTATTR_34 Configuration

#define ECLIC_CLICINTATTR_34_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_34_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_34_SHV                (0x1U<<0U)

// CLICINTCTL_34 Configuration

#define ECLIC_CLICINTCTL_34_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_34_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_35 Configuration

#define ECLIC_CLICINTIP_35_IP                   (0x1U<<0U)

// CLICINTIE_35 Configuration

#define ECLIC_CLICINTIE_35_IE                   (0x1U<<0U)

// CLICINTATTR_35 Configuration

#define ECLIC_CLICINTATTR_35_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_35_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_35_SHV                (0x1U<<0U)

// CLICINTCTL_35 Configuration

#define ECLIC_CLICINTCTL_35_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_35_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_36 Configuration

#define ECLIC_CLICINTIP_36_IP                   (0x1U<<0U)

// CLICINTIE_36 Configuration

#define ECLIC_CLICINTIE_36_IE                   (0x1U<<0U)

// CLICINTATTR_36 Configuration

#define ECLIC_CLICINTATTR_36_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_36_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_36_SHV                (0x1U<<0U)

// CLICINTCTL_36 Configuration

#define ECLIC_CLICINTCTL_36_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_36_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_37 Configuration

#define ECLIC_CLICINTIP_37_IP                   (0x1U<<0U)

// CLICINTIE_37 Configuration

#define ECLIC_CLICINTIE_37_IE                   (0x1U<<0U)

// CLICINTATTR_37 Configuration

#define ECLIC_CLICINTATTR_37_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_37_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_37_SHV                (0x1U<<0U)

// CLICINTCTL_37 Configuration

#define ECLIC_CLICINTCTL_37_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_37_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_38 Configuration

#define ECLIC_CLICINTIP_38_IP                   (0x1U<<0U)

// CLICINTIE_38 Configuration

#define ECLIC_CLICINTIE_38_IE                   (0x1U<<0U)

// CLICINTATTR_38 Configuration

#define ECLIC_CLICINTATTR_38_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_38_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_38_SHV                (0x1U<<0U)

// CLICINTCTL_38 Configuration

#define ECLIC_CLICINTCTL_38_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_38_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_39 Configuration

#define ECLIC_CLICINTIP_39_IP                   (0x1U<<0U)

// CLICINTIE_39 Configuration

#define ECLIC_CLICINTIE_39_IE                   (0x1U<<0U)

// CLICINTATTR_39 Configuration

#define ECLIC_CLICINTATTR_39_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_39_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_39_SHV                (0x1U<<0U)

// CLICINTCTL_39 Configuration

#define ECLIC_CLICINTCTL_39_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_39_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_40 Configuration

#define ECLIC_CLICINTIP_40_IP                   (0x1U<<0U)

// CLICINTIE_40 Configuration

#define ECLIC_CLICINTIE_40_IE                   (0x1U<<0U)

// CLICINTATTR_40 Configuration

#define ECLIC_CLICINTATTR_40_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_40_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_40_SHV                (0x1U<<0U)

// CLICINTCTL_40 Configuration

#define ECLIC_CLICINTCTL_40_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_40_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_41 Configuration

#define ECLIC_CLICINTIP_41_IP                   (0x1U<<0U)

// CLICINTIE_41 Configuration

#define ECLIC_CLICINTIE_41_IE                   (0x1U<<0U)

// CLICINTATTR_41 Configuration

#define ECLIC_CLICINTATTR_41_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_41_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_41_SHV                (0x1U<<0U)

// CLICINTCTL_41 Configuration

#define ECLIC_CLICINTCTL_41_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_41_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_42 Configuration

#define ECLIC_CLICINTIP_42_IP                   (0x1U<<0U)

// CLICINTIE_42 Configuration

#define ECLIC_CLICINTIE_42_IE                   (0x1U<<0U)

// CLICINTATTR_42 Configuration

#define ECLIC_CLICINTATTR_42_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_42_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_42_SHV                (0x1U<<0U)

// CLICINTCTL_42 Configuration

#define ECLIC_CLICINTCTL_42_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_42_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_43 Configuration

#define ECLIC_CLICINTIP_43_IP                   (0x1U<<0U)

// CLICINTIE_43 Configuration

#define ECLIC_CLICINTIE_43_IE                   (0x1U<<0U)

// CLICINTATTR_43 Configuration

#define ECLIC_CLICINTATTR_43_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_43_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_43_SHV                (0x1U<<0U)

// CLICINTCTL_43 Configuration

#define ECLIC_CLICINTCTL_43_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_43_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_44 Configuration

#define ECLIC_CLICINTIP_44_IP                   (0x1U<<0U)

// CLICINTIE_44 Configuration

#define ECLIC_CLICINTIE_44_IE                   (0x1U<<0U)

// CLICINTATTR_44 Configuration

#define ECLIC_CLICINTATTR_44_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_44_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_44_SHV                (0x1U<<0U)

// CLICINTCTL_44 Configuration

#define ECLIC_CLICINTCTL_44_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_44_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_45 Configuration

#define ECLIC_CLICINTIP_45_IP                   (0x1U<<0U)

// CLICINTIE_45 Configuration

#define ECLIC_CLICINTIE_45_IE                   (0x1U<<0U)

// CLICINTATTR_45 Configuration

#define ECLIC_CLICINTATTR_45_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_45_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_45_SHV                (0x1U<<0U)

// CLICINTCTL_45 Configuration

#define ECLIC_CLICINTCTL_45_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_45_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_46 Configuration

#define ECLIC_CLICINTIP_46_IP                   (0x1U<<0U)

// CLICINTIE_46 Configuration

#define ECLIC_CLICINTIE_46_IE                   (0x1U<<0U)

// CLICINTATTR_46 Configuration

#define ECLIC_CLICINTATTR_46_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_46_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_46_SHV                (0x1U<<0U)

// CLICINTCTL_46 Configuration

#define ECLIC_CLICINTCTL_46_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_46_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_47 Configuration

#define ECLIC_CLICINTIP_47_IP                   (0x1U<<0U)

// CLICINTIE_47 Configuration

#define ECLIC_CLICINTIE_47_IE                   (0x1U<<0U)

// CLICINTATTR_47 Configuration

#define ECLIC_CLICINTATTR_47_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_47_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_47_SHV                (0x1U<<0U)

// CLICINTCTL_47 Configuration

#define ECLIC_CLICINTCTL_47_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_47_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_48 Configuration

#define ECLIC_CLICINTIP_48_IP                   (0x1U<<0U)

// CLICINTIE_48 Configuration

#define ECLIC_CLICINTIE_48_IE                   (0x1U<<0U)

// CLICINTATTR_48 Configuration

#define ECLIC_CLICINTATTR_48_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_48_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_48_SHV                (0x1U<<0U)

// CLICINTCTL_48 Configuration

#define ECLIC_CLICINTCTL_48_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_48_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_49 Configuration

#define ECLIC_CLICINTIP_49_IP                   (0x1U<<0U)

// CLICINTIE_49 Configuration

#define ECLIC_CLICINTIE_49_IE                   (0x1U<<0U)

// CLICINTATTR_49 Configuration

#define ECLIC_CLICINTATTR_49_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_49_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_49_SHV                (0x1U<<0U)

// CLICINTCTL_49 Configuration

#define ECLIC_CLICINTCTL_49_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_49_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_50 Configuration

#define ECLIC_CLICINTIP_50_IP                   (0x1U<<0U)

// CLICINTIE_50 Configuration

#define ECLIC_CLICINTIE_50_IE                   (0x1U<<0U)

// CLICINTATTR_50 Configuration

#define ECLIC_CLICINTATTR_50_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_50_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_50_SHV                (0x1U<<0U)

// CLICINTCTL_50 Configuration

#define ECLIC_CLICINTCTL_50_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_50_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_51 Configuration

#define ECLIC_CLICINTIP_51_IP                   (0x1U<<0U)

// CLICINTIE_51 Configuration

#define ECLIC_CLICINTIE_51_IE                   (0x1U<<0U)

// CLICINTATTR_51 Configuration

#define ECLIC_CLICINTATTR_51_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_51_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_51_SHV                (0x1U<<0U)

// CLICINTCTL_51 Configuration

#define ECLIC_CLICINTCTL_51_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_51_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_52 Configuration

#define ECLIC_CLICINTIP_52_IP                   (0x1U<<0U)

// CLICINTIE_52 Configuration

#define ECLIC_CLICINTIE_52_IE                   (0x1U<<0U)

// CLICINTATTR_52 Configuration

#define ECLIC_CLICINTATTR_52_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_52_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_52_SHV                (0x1U<<0U)

// CLICINTCTL_52 Configuration

#define ECLIC_CLICINTCTL_52_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_52_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_53 Configuration

#define ECLIC_CLICINTIP_53_IP                   (0x1U<<0U)

// CLICINTIE_53 Configuration

#define ECLIC_CLICINTIE_53_IE                   (0x1U<<0U)

// CLICINTATTR_53 Configuration

#define ECLIC_CLICINTATTR_53_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_53_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_53_SHV                (0x1U<<0U)

// CLICINTCTL_53 Configuration

#define ECLIC_CLICINTCTL_53_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_53_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_54 Configuration

#define ECLIC_CLICINTIP_54_IP                   (0x1U<<0U)

// CLICINTIE_54 Configuration

#define ECLIC_CLICINTIE_54_IE                   (0x1U<<0U)

// CLICINTATTR_54 Configuration

#define ECLIC_CLICINTATTR_54_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_54_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_54_SHV                (0x1U<<0U)

// CLICINTCTL_54 Configuration

#define ECLIC_CLICINTCTL_54_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_54_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_55 Configuration

#define ECLIC_CLICINTIP_55_IP                   (0x1U<<0U)

// CLICINTIE_55 Configuration

#define ECLIC_CLICINTIE_55_IE                   (0x1U<<0U)

// CLICINTATTR_55 Configuration

#define ECLIC_CLICINTATTR_55_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_55_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_55_SHV                (0x1U<<0U)

// CLICINTCTL_55 Configuration

#define ECLIC_CLICINTCTL_55_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_55_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_56 Configuration

#define ECLIC_CLICINTIP_56_IP                   (0x1U<<0U)

// CLICINTIE_56 Configuration

#define ECLIC_CLICINTIE_56_IE                   (0x1U<<0U)

// CLICINTATTR_56 Configuration

#define ECLIC_CLICINTATTR_56_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_56_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_56_SHV                (0x1U<<0U)

// CLICINTCTL_56 Configuration

#define ECLIC_CLICINTCTL_56_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_56_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_57 Configuration

#define ECLIC_CLICINTIP_57_IP                   (0x1U<<0U)

// CLICINTIE_57 Configuration

#define ECLIC_CLICINTIE_57_IE                   (0x1U<<0U)

// CLICINTATTR_57 Configuration

#define ECLIC_CLICINTATTR_57_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_57_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_57_SHV                (0x1U<<0U)

// CLICINTCTL_57 Configuration

#define ECLIC_CLICINTCTL_57_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_57_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_58 Configuration

#define ECLIC_CLICINTIP_58_IP                   (0x1U<<0U)

// CLICINTIE_58 Configuration

#define ECLIC_CLICINTIE_58_IE                   (0x1U<<0U)

// CLICINTATTR_58 Configuration

#define ECLIC_CLICINTATTR_58_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_58_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_58_SHV                (0x1U<<0U)

// CLICINTCTL_58 Configuration

#define ECLIC_CLICINTCTL_58_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_58_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_59 Configuration

#define ECLIC_CLICINTIP_59_IP                   (0x1U<<0U)

// CLICINTIE_59 Configuration

#define ECLIC_CLICINTIE_59_IE                   (0x1U<<0U)

// CLICINTATTR_59 Configuration

#define ECLIC_CLICINTATTR_59_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_59_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_59_SHV                (0x1U<<0U)

// CLICINTCTL_59 Configuration

#define ECLIC_CLICINTCTL_59_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_59_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_60 Configuration

#define ECLIC_CLICINTIP_60_IP                   (0x1U<<0U)

// CLICINTIE_60 Configuration

#define ECLIC_CLICINTIE_60_IE                   (0x1U<<0U)

// CLICINTATTR_60 Configuration

#define ECLIC_CLICINTATTR_60_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_60_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_60_SHV                (0x1U<<0U)

// CLICINTCTL_60 Configuration

#define ECLIC_CLICINTCTL_60_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_60_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_61 Configuration

#define ECLIC_CLICINTIP_61_IP                   (0x1U<<0U)

// CLICINTIE_61 Configuration

#define ECLIC_CLICINTIE_61_IE                   (0x1U<<0U)

// CLICINTATTR_61 Configuration

#define ECLIC_CLICINTATTR_61_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_61_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_61_SHV                (0x1U<<0U)

// CLICINTCTL_61 Configuration

#define ECLIC_CLICINTCTL_61_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_61_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_62 Configuration

#define ECLIC_CLICINTIP_62_IP                   (0x1U<<0U)

// CLICINTIE_62 Configuration

#define ECLIC_CLICINTIE_62_IE                   (0x1U<<0U)

// CLICINTATTR_62 Configuration

#define ECLIC_CLICINTATTR_62_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_62_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_62_SHV                (0x1U<<0U)

// CLICINTCTL_62 Configuration

#define ECLIC_CLICINTCTL_62_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_62_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_63 Configuration

#define ECLIC_CLICINTIP_63_IP                   (0x1U<<0U)

// CLICINTIE_63 Configuration

#define ECLIC_CLICINTIE_63_IE                   (0x1U<<0U)

// CLICINTATTR_63 Configuration

#define ECLIC_CLICINTATTR_63_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_63_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_63_SHV                (0x1U<<0U)

// CLICINTCTL_63 Configuration

#define ECLIC_CLICINTCTL_63_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_63_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_64 Configuration

#define ECLIC_CLICINTIP_64_IP                   (0x1U<<0U)

// CLICINTIE_64 Configuration

#define ECLIC_CLICINTIE_64_IE                   (0x1U<<0U)

// CLICINTATTR_64 Configuration

#define ECLIC_CLICINTATTR_64_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_64_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_64_SHV                (0x1U<<0U)

// CLICINTCTL_64 Configuration

#define ECLIC_CLICINTCTL_64_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_64_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_65 Configuration

#define ECLIC_CLICINTIP_65_IP                   (0x1U<<0U)

// CLICINTIE_65 Configuration

#define ECLIC_CLICINTIE_65_IE                   (0x1U<<0U)

// CLICINTATTR_65 Configuration

#define ECLIC_CLICINTATTR_65_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_65_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_65_SHV                (0x1U<<0U)

// CLICINTCTL_65 Configuration

#define ECLIC_CLICINTCTL_65_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_65_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_66 Configuration

#define ECLIC_CLICINTIP_66_IP                   (0x1U<<0U)

// CLICINTIE_66 Configuration

#define ECLIC_CLICINTIE_66_IE                   (0x1U<<0U)

// CLICINTATTR_66 Configuration

#define ECLIC_CLICINTATTR_66_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_66_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_66_SHV                (0x1U<<0U)

// CLICINTCTL_66 Configuration

#define ECLIC_CLICINTCTL_66_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_66_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_67 Configuration

#define ECLIC_CLICINTIP_67_IP                   (0x1U<<0U)

// CLICINTIE_67 Configuration

#define ECLIC_CLICINTIE_67_IE                   (0x1U<<0U)

// CLICINTATTR_67 Configuration

#define ECLIC_CLICINTATTR_67_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_67_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_67_SHV                (0x1U<<0U)

// CLICINTCTL_67 Configuration

#define ECLIC_CLICINTCTL_67_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_67_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_68 Configuration

#define ECLIC_CLICINTIP_68_IP                   (0x1U<<0U)

// CLICINTIE_68 Configuration

#define ECLIC_CLICINTIE_68_IE                   (0x1U<<0U)

// CLICINTATTR_68 Configuration

#define ECLIC_CLICINTATTR_68_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_68_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_68_SHV                (0x1U<<0U)

// CLICINTCTL_68 Configuration

#define ECLIC_CLICINTCTL_68_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_68_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_69 Configuration

#define ECLIC_CLICINTIP_69_IP                   (0x1U<<0U)

// CLICINTIE_69 Configuration

#define ECLIC_CLICINTIE_69_IE                   (0x1U<<0U)

// CLICINTATTR_69 Configuration

#define ECLIC_CLICINTATTR_69_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_69_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_69_SHV                (0x1U<<0U)

// CLICINTCTL_69 Configuration

#define ECLIC_CLICINTCTL_69_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_69_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_70 Configuration

#define ECLIC_CLICINTIP_70_IP                   (0x1U<<0U)

// CLICINTIE_70 Configuration

#define ECLIC_CLICINTIE_70_IE                   (0x1U<<0U)

// CLICINTATTR_70 Configuration

#define ECLIC_CLICINTATTR_70_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_70_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_70_SHV                (0x1U<<0U)

// CLICINTCTL_70 Configuration

#define ECLIC_CLICINTCTL_70_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_70_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_71 Configuration

#define ECLIC_CLICINTIP_71_IP                   (0x1U<<0U)

// CLICINTIE_71 Configuration

#define ECLIC_CLICINTIE_71_IE                   (0x1U<<0U)

// CLICINTATTR_71 Configuration

#define ECLIC_CLICINTATTR_71_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_71_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_71_SHV                (0x1U<<0U)

// CLICINTCTL_71 Configuration

#define ECLIC_CLICINTCTL_71_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_71_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_72 Configuration

#define ECLIC_CLICINTIP_72_IP                   (0x1U<<0U)

// CLICINTIE_72 Configuration

#define ECLIC_CLICINTIE_72_IE                   (0x1U<<0U)

// CLICINTATTR_72 Configuration

#define ECLIC_CLICINTATTR_72_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_72_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_72_SHV                (0x1U<<0U)

// CLICINTCTL_72 Configuration

#define ECLIC_CLICINTCTL_72_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_72_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_73 Configuration

#define ECLIC_CLICINTIP_73_IP                   (0x1U<<0U)

// CLICINTIE_73 Configuration

#define ECLIC_CLICINTIE_73_IE                   (0x1U<<0U)

// CLICINTATTR_73 Configuration

#define ECLIC_CLICINTATTR_73_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_73_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_73_SHV                (0x1U<<0U)

// CLICINTCTL_73 Configuration

#define ECLIC_CLICINTCTL_73_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_73_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_74 Configuration

#define ECLIC_CLICINTIP_74_IP                   (0x1U<<0U)

// CLICINTIE_74 Configuration

#define ECLIC_CLICINTIE_74_IE                   (0x1U<<0U)

// CLICINTATTR_74 Configuration

#define ECLIC_CLICINTATTR_74_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_74_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_74_SHV                (0x1U<<0U)

// CLICINTCTL_74 Configuration

#define ECLIC_CLICINTCTL_74_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_74_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_75 Configuration

#define ECLIC_CLICINTIP_75_IP                   (0x1U<<0U)

// CLICINTIE_75 Configuration

#define ECLIC_CLICINTIE_75_IE                   (0x1U<<0U)

// CLICINTATTR_75 Configuration

#define ECLIC_CLICINTATTR_75_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_75_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_75_SHV                (0x1U<<0U)

// CLICINTCTL_75 Configuration

#define ECLIC_CLICINTCTL_75_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_75_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_76 Configuration

#define ECLIC_CLICINTIP_76_IP                   (0x1U<<0U)

// CLICINTIE_76 Configuration

#define ECLIC_CLICINTIE_76_IE                   (0x1U<<0U)

// CLICINTATTR_76 Configuration

#define ECLIC_CLICINTATTR_76_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_76_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_76_SHV                (0x1U<<0U)

// CLICINTCTL_76 Configuration

#define ECLIC_CLICINTCTL_76_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_76_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_77 Configuration

#define ECLIC_CLICINTIP_77_IP                   (0x1U<<0U)

// CLICINTIE_77 Configuration

#define ECLIC_CLICINTIE_77_IE                   (0x1U<<0U)

// CLICINTATTR_77 Configuration

#define ECLIC_CLICINTATTR_77_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_77_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_77_SHV                (0x1U<<0U)

// CLICINTCTL_77 Configuration

#define ECLIC_CLICINTCTL_77_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_77_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_78 Configuration

#define ECLIC_CLICINTIP_78_IP                   (0x1U<<0U)

// CLICINTIE_78 Configuration

#define ECLIC_CLICINTIE_78_IE                   (0x1U<<0U)

// CLICINTATTR_78 Configuration

#define ECLIC_CLICINTATTR_78_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_78_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_78_SHV                (0x1U<<0U)

// CLICINTCTL_78 Configuration

#define ECLIC_CLICINTCTL_78_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_78_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_79 Configuration

#define ECLIC_CLICINTIP_79_IP                   (0x1U<<0U)

// CLICINTIE_79 Configuration

#define ECLIC_CLICINTIE_79_IE                   (0x1U<<0U)

// CLICINTATTR_79 Configuration

#define ECLIC_CLICINTATTR_79_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_79_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_79_SHV                (0x1U<<0U)

// CLICINTCTL_79 Configuration

#define ECLIC_CLICINTCTL_79_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_79_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_80 Configuration

#define ECLIC_CLICINTIP_80_IP                   (0x1U<<0U)

// CLICINTIE_80 Configuration

#define ECLIC_CLICINTIE_80_IE                   (0x1U<<0U)

// CLICINTATTR_80 Configuration

#define ECLIC_CLICINTATTR_80_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_80_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_80_SHV                (0x1U<<0U)

// CLICINTCTL_80 Configuration

#define ECLIC_CLICINTCTL_80_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_80_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_81 Configuration

#define ECLIC_CLICINTIP_81_IP                   (0x1U<<0U)

// CLICINTIE_81 Configuration

#define ECLIC_CLICINTIE_81_IE                   (0x1U<<0U)

// CLICINTATTR_81 Configuration

#define ECLIC_CLICINTATTR_81_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_81_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_81_SHV                (0x1U<<0U)

// CLICINTCTL_81 Configuration

#define ECLIC_CLICINTCTL_81_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_81_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_82 Configuration

#define ECLIC_CLICINTIP_82_IP                   (0x1U<<0U)

// CLICINTIE_82 Configuration

#define ECLIC_CLICINTIE_82_IE                   (0x1U<<0U)

// CLICINTATTR_82 Configuration

#define ECLIC_CLICINTATTR_82_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_82_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_82_SHV                (0x1U<<0U)

// CLICINTCTL_82 Configuration

#define ECLIC_CLICINTCTL_82_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_82_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_83 Configuration

#define ECLIC_CLICINTIP_83_IP                   (0x1U<<0U)

// CLICINTIE_83 Configuration

#define ECLIC_CLICINTIE_83_IE                   (0x1U<<0U)

// CLICINTATTR_83 Configuration

#define ECLIC_CLICINTATTR_83_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_83_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_83_SHV                (0x1U<<0U)

// CLICINTCTL_83 Configuration

#define ECLIC_CLICINTCTL_83_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_83_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_84 Configuration

#define ECLIC_CLICINTIP_84_IP                   (0x1U<<0U)

// CLICINTIE_84 Configuration

#define ECLIC_CLICINTIE_84_IE                   (0x1U<<0U)

// CLICINTATTR_84 Configuration

#define ECLIC_CLICINTATTR_84_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_84_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_84_SHV                (0x1U<<0U)

// CLICINTCTL_84 Configuration

#define ECLIC_CLICINTCTL_84_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_84_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIE_85 Configuration

#define ECLIC_CLICINTIE_85_IE                   (0x1U<<0U)

// CLICINTATTR_85 Configuration

#define ECLIC_CLICINTATTR_85_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_85_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_85_SHV                (0x1U<<0U)

// CLICINTCTL_85 Configuration

#define ECLIC_CLICINTCTL_85_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_85_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_85 Configuration

#define ECLIC_CLICINTIP_85_IP                   (0x1U<<0U)

// CLICINTIE_86 Configuration

#define ECLIC_CLICINTIE_86_IE                   (0x1U<<0U)

// CLICINTATTR_86 Configuration

#define ECLIC_CLICINTATTR_86_TRIG               (0x3U<<1U)
#define ECLIC_CLICINTATTR_86_TRIG_0             (0x1U<<1U)
#define ECLIC_CLICINTATTR_86_SHV                (0x1U<<0U)

// CLICINTCTL_86 Configuration

#define ECLIC_CLICINTCTL_86_LEVEL_PRIORITY      (0xFFU<<0U)
#define ECLIC_CLICINTCTL_86_LEVEL_PRIORITY_0    (0x1U<<0U)

// CLICINTIP_86 Configuration

#define ECLIC_CLICINTIP_86_IP                   (0x1U<<0U)
