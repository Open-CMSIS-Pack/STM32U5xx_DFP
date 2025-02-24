/**
  ******************************************************************************
  * @file    stm32u5xx_hal_pwr_ex.h
  * @author  MCD Application Team
  * @brief   Header file of PWR HAL Extended module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32U5xx_HAL_PWR_EX_H
#define STM32U5xx_HAL_PWR_EX_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal_def.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @addtogroup PWREx
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup PWREx_Exported_Types PWR Extended Exported Types
  * @{
  */

/**
  * @brief  PWR PVM configuration structure definition
  */
typedef struct
{
  uint32_t PVMType;   /*!< Specifies which voltage is monitored.
                           This parameter can be a value of
                           @ref PWREx_PVM_Type.                               */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of
                           @ref PWREx_PVM_Mode.                               */
}PWR_PVMTypeDef;
/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup PWREx_Exported_Constants PWR Extended Exported Constants
  * @{
  */

/** @defgroup PWREx_PVM_Type PWR Extended Voltage Monitoring Type
  * @{
  */
#define PWR_UVM   PWR_SVMCR_UVMEN   /*!< Independent USB voltage monitor (VDDUSB versus 1.2 V)    */
#define PWR_IO2VM PWR_SVMCR_IO2VMEN /*!< Independent VDDIO2 voltage monitor (VDDIO2 versus 0.9 V) */
#define PWR_AVM1  PWR_SVMCR_AVM1EN  /*!< Independent VDDA voltage monitor (VDDA versus 1.6 V)     */
#define PWR_AVM2  PWR_SVMCR_AVM2EN  /*!< Independent VDDA voltage monitor (VDDA versus 1.8 V)     */
/**
  * @}
  */

/** @defgroup PWREx_PVM_Mode PWR Extended PVM Interrupt and Event Mode
  * @{
  */
#define PWR_PVM_MODE_NORMAL               (0x00U) /*!< Basic Mode is used                                                 */
#define PWR_PVM_MODE_IT_RISING            (0x05U) /*!< External Interrupt Mode with Rising edge trigger detection         */
#define PWR_PVM_MODE_IT_FALLING           (0x06U) /*!< External Interrupt Mode with Falling edge trigger detection        */
#define PWR_PVM_MODE_IT_RISING_FALLING    (0x07U) /*!< External Interrupt Mode with Rising/Falling edge trigger detection */
#define PWR_PVM_MODE_EVENT_RISING         (0x09U) /*!< Event Mode with Rising edge trigger detection                      */
#define PWR_PVM_MODE_EVENT_FALLING        (0x0AU) /*!< Event Mode with Falling edge trigger detection                     */
#define PWR_PVM_MODE_EVENT_RISING_FALLING (0x0BU) /*!< Event Mode with Rising/Falling edge trigger detection              */
/**
  * @}
  */

/** @defgroup PWREx_SRD_State PWREx SRD Domain State
  * @{
  */
#define PWR_SRD_DOMAIN_STOP (0U)           /* SRD in STOP mode when system goes to STOP 0/1/2 mode */
#define PWR_SRD_DOMAIN_RUN  PWR_CR2_SRDRUN /* SRD in RUN mode when system goes to STOP 0/1/2 mode  */
/**
  * @}
  */

/** @defgroup PWREx_RAM_Contents_Retention PWR Extended RAM Contents Retention
  * @{
  */
/* SRAM1 pages retention defines */
#define PWR_SRAM1_PAGE1_STOP_RETENTION    (PWR_CR2_SRAM1PDS1)                     /*!< SRAM1 page 1 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE2_STOP_RETENTION    (PWR_CR2_SRAM1PDS2)                     /*!< SRAM1 page 2 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE3_STOP_RETENTION    (PWR_CR2_SRAM1PDS3)                     /*!< SRAM1 page 3 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#if defined(PWR_CR4_SRAM1PDS4)

#define PWR_CR4_FLAG                      0x80000000U                             /*!< Flag to indicate CR4 register must be updated                     */

#define PWR_SRAM1_PAGE4_STOP_RETENTION    (PWR_CR4_SRAM1PDS4  | PWR_CR4_FLAG)     /*!< SRAM1 page 4 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE5_STOP_RETENTION    (PWR_CR4_SRAM1PDS5  | PWR_CR4_FLAG)     /*!< SRAM1 page 5 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE6_STOP_RETENTION    (PWR_CR4_SRAM1PDS6  | PWR_CR4_FLAG)     /*!< SRAM1 page 6 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE7_STOP_RETENTION    (PWR_CR4_SRAM1PDS7  | PWR_CR4_FLAG)     /*!< SRAM1 page 7 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE8_STOP_RETENTION    (PWR_CR4_SRAM1PDS8  | PWR_CR4_FLAG)     /*!< SRAM1 page 8 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE9_STOP_RETENTION    (PWR_CR4_SRAM1PDS9  | PWR_CR4_FLAG)     /*!< SRAM1 page 9 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM1_PAGE10_STOP_RETENTION   (PWR_CR4_SRAM1PDS10 | PWR_CR4_FLAG)     /*!< SRAM1 page 10 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM1_PAGE11_STOP_RETENTION   (PWR_CR4_SRAM1PDS11 | PWR_CR4_FLAG)     /*!< SRAM1 page 11 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM1_PAGE12_STOP_RETENTION   (PWR_CR4_SRAM1PDS12 | PWR_CR4_FLAG)     /*!< SRAM1 page 12 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */

#define PWR_SRAM1_PAGE4_12_STOP_RETENTION (PWR_CR4_SRAM1PDS4 | PWR_CR4_SRAM1PDS5  | PWR_CR4_SRAM1PDS6  | PWR_CR4_SRAM1PDS7  | PWR_CR4_SRAM1PDS8 | \
                                           PWR_CR4_SRAM1PDS9 | PWR_CR4_SRAM1PDS10 | PWR_CR4_SRAM1PDS11 | PWR_CR4_SRAM1PDS12 | PWR_CR4_FLAG)

#define PWR_SRAM1_PAGE1_3_STOP_RETENTION  (PWR_CR2_SRAM1PDS1 | PWR_CR2_SRAM1PDS2 | \
                                           PWR_CR2_SRAM1PDS3)

#define PWR_SRAM1_FULL_STOP_RETENTION     (0x40000000U)                           /* SRAM1 full retention in STOP modes requires CR2 and CR4 setting */

#else
#define PWR_SRAM1_FULL_STOP_RETENTION     (PWR_CR2_SRAM1PDS1 | PWR_CR2_SRAM1PDS2 | \
                                           PWR_CR2_SRAM1PDS3)                     /*!< SRAM1 all pages retention in STOP modes (STOP 0, 1, 2, 3)         */
#endif
/* SRAM2 pages retention defines */
#define PWR_SRAM2_PAGE1_STOP_RETENTION    (PWR_CR2_SRAM2PDS1)                     /*!< SRAM2 page 1 (8 KB) retention in STOP modes  (STOP 0, 1, 2)       */
#define PWR_SRAM2_PAGE2_STOP_RETENTION    (PWR_CR2_SRAM2PDS2)                     /*!< SRAM2 page 2 (54 KB) retention in STOP modes (STOP 0, 1, 2)       */
#define PWR_SRAM2_FULL_STOP_RETENTION     (PWR_CR2_SRAM2PDS1 | PWR_CR2_SRAM2PDS2) /*!< SRAM2 all pages retention in STOP modes      (STOP 0, 1, 2)       */
/* SRAM3 pages retention defines */
#define PWR_SRAM3_PAGE1_STOP_RETENTION    (PWR_CR2_SRAM3PDS1)                     /*!< SRAM3 page 1 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE2_STOP_RETENTION    (PWR_CR2_SRAM3PDS2)                     /*!< SRAM3 page 2 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE3_STOP_RETENTION    (PWR_CR2_SRAM3PDS3)                     /*!< SRAM3 page 3 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE4_STOP_RETENTION    (PWR_CR2_SRAM3PDS4)                     /*!< SRAM3 page 4 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE5_STOP_RETENTION    (PWR_CR2_SRAM3PDS5)                     /*!< SRAM3 page 5 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE6_STOP_RETENTION    (PWR_CR2_SRAM3PDS6)                     /*!< SRAM3 page 6 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE7_STOP_RETENTION    (PWR_CR2_SRAM3PDS7)                     /*!< SRAM3 page 7 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE8_STOP_RETENTION    (PWR_CR2_SRAM3PDS8)                     /*!< SRAM3 page 8 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */

#if defined(PWR_CR4_SRAM3PDS9)
#define PWR_SRAM3_PAGE9_STOP_RETENTION    (PWR_CR4_SRAM3PDS9  | PWR_CR4_FLAG)     /*!< SRAM3 page 9 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM3_PAGE10_STOP_RETENTION   (PWR_CR4_SRAM3PDS10 | PWR_CR4_FLAG)     /*!< SRAM3 page 10 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM3_PAGE11_STOP_RETENTION   (PWR_CR4_SRAM3PDS11 | PWR_CR4_FLAG)     /*!< SRAM3 page 11 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM3_PAGE12_STOP_RETENTION   (PWR_CR4_SRAM3PDS12 | PWR_CR4_FLAG)     /*!< SRAM3 page 12 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM3_PAGE13_STOP_RETENTION   (PWR_CR4_SRAM3PDS13 | PWR_CR4_FLAG)     /*!< SRAM3 page 13 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */

#define PWR_SRAM3_PAGE9_13_STOP_RETENTION (PWR_CR4_SRAM3PDS9 | PWR_CR4_SRAM3PDS10  | PWR_CR4_SRAM3PDS11  | PWR_CR4_SRAM3PDS12 | PWR_CR4_SRAM3PDS13 | PWR_CR4_FLAG)

#define PWR_SRAM3_PAGE1_8_STOP_RETENTION  (PWR_CR2_SRAM3PDS1 | PWR_CR2_SRAM3PDS2 | \
                                           PWR_CR2_SRAM3PDS3 | PWR_CR2_SRAM3PDS4 | \
                                           PWR_CR2_SRAM3PDS5 | PWR_CR2_SRAM3PDS6 | \
                                           PWR_CR2_SRAM3PDS7 | PWR_CR2_SRAM3PDS8)

#define PWR_SRAM3_FULL_STOP_RETENTION     (0x20000000U)                           /* SRAM3 full retention in STOP modes requires CR2 and CR4 setting */

#else
#define PWR_SRAM3_FULL_STOP_RETENTION     (PWR_CR2_SRAM3PDS1 | PWR_CR2_SRAM3PDS2 | \
                                           PWR_CR2_SRAM3PDS3 | PWR_CR2_SRAM3PDS4 | \
                                           PWR_CR2_SRAM3PDS5 | PWR_CR2_SRAM3PDS6 | \
                                           PWR_CR2_SRAM3PDS7 | PWR_CR2_SRAM3PDS8) /*!< SRAM3 all pages retention in STOP modes      (STOP 0, 1, 2, 3)    */
#endif
/* SRAM4 page retention defines */
#define PWR_SRAM4_FULL_STOP_RETENTION     (PWR_CR2_SRAM4PDS)                      /*!< SRAM4 retention in STOP modes (STOP 0, 1, 2, 3)                   */

#if defined(PWR_CR4_SRAM5PDS1)
#define PWR_SRAM5_PAGE1_STOP_RETENTION    (PWR_CR4_SRAM5PDS1  | PWR_CR4_FLAG)     /*!< SRAM5 page 1 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE2_STOP_RETENTION    (PWR_CR4_SRAM5PDS2  | PWR_CR4_FLAG)     /*!< SRAM5 page 2 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE3_STOP_RETENTION    (PWR_CR4_SRAM5PDS3  | PWR_CR4_FLAG)     /*!< SRAM5 page 3 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE4_STOP_RETENTION    (PWR_CR4_SRAM5PDS4  | PWR_CR4_FLAG)     /*!< SRAM5 page 4 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE5_STOP_RETENTION    (PWR_CR4_SRAM5PDS5  | PWR_CR4_FLAG)     /*!< SRAM5 page 5 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE6_STOP_RETENTION    (PWR_CR4_SRAM5PDS6  | PWR_CR4_FLAG)     /*!< SRAM5 page 6 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE7_STOP_RETENTION    (PWR_CR4_SRAM5PDS7  | PWR_CR4_FLAG)     /*!< SRAM5 page 7 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE8_STOP_RETENTION    (PWR_CR4_SRAM5PDS8  | PWR_CR4_FLAG)     /*!< SRAM5 page 8 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE9_STOP_RETENTION    (PWR_CR4_SRAM5PDS9  | PWR_CR4_FLAG)     /*!< SRAM5 page 9 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)    */
#define PWR_SRAM5_PAGE10_STOP_RETENTION   (PWR_CR4_SRAM5PDS10 | PWR_CR4_FLAG)     /*!< SRAM5 page 10 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM5_PAGE11_STOP_RETENTION   (PWR_CR4_SRAM5PDS11 | PWR_CR4_FLAG)     /*!< SRAM5 page 11 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM5_PAGE12_STOP_RETENTION   (PWR_CR4_SRAM5PDS12 | PWR_CR4_FLAG)     /*!< SRAM5 page 12 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */
#define PWR_SRAM5_PAGE13_STOP_RETENTION   (PWR_CR4_SRAM5PDS13 | PWR_CR4_FLAG)     /*!< SRAM5 page 13 (64 KB) retention in STOP modes (STOP 0, 1, 2, 3)   */

#define PWR_SRAM5_FULL_STOP_RETENTION     (PWR_CR4_SRAM5PDS1  | PWR_CR4_SRAM5PDS2  | PWR_CR4_SRAM5PDS3  | PWR_CR4_SRAM5PDS4 | PWR_CR4_SRAM5PDS5  |\
                                           PWR_CR4_SRAM5PDS6  | PWR_CR4_SRAM5PDS7  | PWR_CR4_SRAM5PDS8  | PWR_CR4_SRAM5PDS9 | PWR_CR4_SRAM5PDS10 |\
                                           PWR_CR4_SRAM5PDS11 | PWR_CR4_SRAM5PDS12 | PWR_CR4_SRAM5PDS13 | PWR_CR4_FLAG) /*!< SRAM5 all pages retention in STOP modes      (STOP 0, 1, 2, 3) */
#endif

/* Cache RAMs retention defines */
#define PWR_ICACHE_FULL_STOP_RETENTION    (PWR_CR2_ICRAMPDS)                      /*!< ICACHE page retention in STOP modes (STOP 0, 1, 2, 3)             */
#define PWR_DCACHE_FULL_STOP_RETENTION    (PWR_CR2_DCRAMPDS)                      /*!< DCACHE page retention in STOP modes (STOP 0, 1, 2, 3)             */

/* DMA2D RAM retention defines */
#define PWR_DMA2DRAM_FULL_STOP_RETENTION  (PWR_CR2_DMA2DRAMPDS)                   /*!< DMA2D ram retention in STOP modes (STOP 0, 1, 2, 3)               */

/* FMAC, FDCAN and USB RAMs retention defines */
#define PWR_PERIPHRAM_FULL_STOP_RETENTION (PWR_CR2_PRAMPDS)                       /*!< FMAC, FDCAN and USB ram retention in STOP modes (STOP 0, 1, 2, 3) */

/* PKA32 RAM retention defines */
#define PWR_PKA32RAM_FULL_STOP_RETENTION  (PWR_CR2_PKARAMPDS)                     /*!< PKA32 RAM retention in STOP modes (STOP 0, 1, 2, 3)               */
/**
  * @}
  */

/** @defgroup PWREx_SRAM2_Contents_Retention PWR Extended SRAM2 Content Retention
  * @{
  */
#define PWR_SRAM2_PAGE1_STNADBY_RETENTION PWR_CR1_RRSB1                   /*!< SRAM2 page 1 (8 KB) retention in STOP 3 and STANDBY modes  */
#define PWR_SRAM2_PAGE2_STNADBY_RETENTION PWR_CR1_RRSB2                   /*!< SRAM2 page 2 (54 KB) retention in STOP 3 and STANDBY modes */
#define PWR_SRAM2_FULL_STNADBY_RETENTION  (PWR_CR1_RRSB1 | PWR_CR1_RRSB2) /*!< SRAM2 all pages retention in STOP 3 and STANDBY modes      */
/**
  * @}
  */

/** @defgroup PWREx_Supply_Configuration PWR Extended Supply Configuration
  * @{
  */
#define PWR_LDO_SUPPLY  (0U)             /* LDO supply  */
#define PWR_SMPS_SUPPLY (PWR_CR3_REGSEL) /* SMPS supply */
/**
  * @}
  */

/** @defgroup PWREx_Regulator_Voltage_Scale PWR Extended Regulator Voltage Scale
  * @{
  */
#define PWR_REGULATOR_VOLTAGE_SCALE1 (PWR_VOSR_VOS_0 | PWR_VOSR_VOS_1) /*!< Voltage scaling range 1 */
#define PWR_REGULATOR_VOLTAGE_SCALE2 PWR_VOSR_VOS_1                    /*!< Voltage scaling range 2 */
#define PWR_REGULATOR_VOLTAGE_SCALE3 PWR_VOSR_VOS_0                    /*!< Voltage scaling range 3 */
#define PWR_REGULATOR_VOLTAGE_SCALE4 (0U)                              /*!< Voltage scaling range 4 */
/**
  * @}
  */

/** @defgroup PWREx_VBAT_Battery_Charging_Selection PWR Extended Battery Charging Resistor Selection
  * @{
  */
#define PWR_BATTERY_CHARGING_RESISTOR_5   (0U)           /*!< VBAT charging through a 5 kOhms resistor   */
#define PWR_BATTERY_CHARGING_RESISTOR_1_5 PWR_BDCR2_VBRS /*!< VBAT charging through a 1.5 kOhms resistor */
/**
  * @}
  */

/** @defgroup PWREx_VBAT_Battery_Charging_State PWR Extended Battery Charging State
  * @{
  */
#define PWR_BATTERY_CHARGING_DISABLE (0U)          /* Disable battery charging */
#define PWR_BATTERY_CHARGING_ENABLE  PWR_BDCR2_VBE /* Enable battery charging  */
/**
  * @}
  */

/** @defgroup PWREx_GPIO_Port PWR Extended GPIO Port
  * @{
  */
#define PWR_GPIO_A (0x00U) /*!< GPIO port A */
#define PWR_GPIO_B (0x01U) /*!< GPIO port B */
#define PWR_GPIO_C (0x02U) /*!< GPIO port C */
#define PWR_GPIO_D (0x03U) /*!< GPIO port D */
#define PWR_GPIO_E (0x04U) /*!< GPIO port E */
#define PWR_GPIO_F (0x05U) /*!< GPIO port F */
#define PWR_GPIO_G (0x06U) /*!< GPIO port G */
#define PWR_GPIO_H (0x07U) /*!< GPIO port H */                                        
#define PWR_GPIO_I (0x08U) /*!< GPIO port I */
#if defined(GPIOJ)
#define PWR_GPIO_J (0x09U) /*!< GPIO port J */
#endif                                           
/**
  * @}
  */

/** @defgroup PWREx_GPIO_Pin_Mask PWR Extended GPIO Pin Mask
  * @{
  */
#define PWR_GPIO_BIT_0  (0x0001U) /*!< GPIO port I/O pin 0  */
#define PWR_GPIO_BIT_1  (0x0002U) /*!< GPIO port I/O pin 1  */
#define PWR_GPIO_BIT_2  (0x0004U) /*!< GPIO port I/O pin 2  */
#define PWR_GPIO_BIT_3  (0x0008U) /*!< GPIO port I/O pin 3  */
#define PWR_GPIO_BIT_4  (0x0010U) /*!< GPIO port I/O pin 4  */
#define PWR_GPIO_BIT_5  (0x0020U) /*!< GPIO port I/O pin 5  */
#define PWR_GPIO_BIT_6  (0x0040U) /*!< GPIO port I/O pin 6  */
#define PWR_GPIO_BIT_7  (0x0080U) /*!< GPIO port I/O pin 7  */
#define PWR_GPIO_BIT_8  (0x0100U) /*!< GPIO port I/O pin 8  */
#define PWR_GPIO_BIT_9  (0x0200U) /*!< GPIO port I/O pin 9  */
#define PWR_GPIO_BIT_10 (0x0400U) /*!< GPIO port I/O pin 10 */
#define PWR_GPIO_BIT_11 (0x0800U) /*!< GPIO port I/O pin 11 */
#define PWR_GPIO_BIT_12 (0x1000U) /*!< GPIO port I/O pin 12 */
#define PWR_GPIO_BIT_13 (0x2000U) /*!< GPIO port I/O pin 13 */
#define PWR_GPIO_BIT_14 (0x4000U) /*!< GPIO port I/O pin 14 */
#define PWR_GPIO_BIT_15 (0x8000U) /*!< GPIO port I/O pin 15 */
/**
  * @}
  */

/**
  * @}
  */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup PWREx_Exported_Macros PWR Extended Exported Macros
 * @{
 */

/**
  * @brief  Enable the UVM Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_ENABLE_IT() SET_BIT(EXTI->IMR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Disable the UVM Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_DISABLE_IT() CLEAR_BIT(EXTI->IMR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Enable the UVM Event Line.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_ENABLE_EVENT() SET_BIT(EXTI->EMR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Disable the UVM Event Line.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_DISABLE_EVENT() CLEAR_BIT(EXTI->EMR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Enable the UVM Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_ENABLE_RISING_EDGE() SET_BIT(EXTI->RTSR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Disable the UVM Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_DISABLE_RISING_EDGE() CLEAR_BIT(EXTI->RTSR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Enable the UVM Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_ENABLE_FALLING_EDGE() SET_BIT(EXTI->FTSR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Disable the UVM Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_DISABLE_FALLING_EDGE() CLEAR_BIT(EXTI->FTSR1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Enable the UVM Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_ENABLE_RISING_FALLING_EDGE() \
do                                                      \
{                                                       \
  __HAL_PWR_UVM_EXTI_ENABLE_RISING_EDGE();              \
  __HAL_PWR_UVM_EXTI_ENABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Disable the UVM Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_DISABLE_RISING_FALLING_EDGE() \
do                                                       \
{                                                        \
  __HAL_PWR_UVM_EXTI_DISABLE_RISING_EDGE();              \
  __HAL_PWR_UVM_EXTI_DISABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Generate a Software Interrupt on UVM EXTI Line.
  * @retval None
  */
#define __HAL_PWR_UVM_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER1, PWR_EXTI_LINE_UVM)

/**
  * @brief  Check whether the specified UVM EXTI flag is set or not.
  * @retval EXTI UVM Line Status.
  */
#define __HAL_PWR_UVM_EXTI_GET_FLAG() ((EXTI->RPR1 | EXTI->FPR1) & PWR_EXTI_LINE_UVM)

/**
  * @brief  Clear the UVM EXTI flag.
  * @retval None.
  */
#define __HAL_PWR_UVM_EXTI_CLEAR_FLAG()     \
do                                          \
{                                           \
  WRITE_REG(EXTI->RPR1, PWR_EXTI_LINE_UVM); \
  WRITE_REG(EXTI->FPR1, PWR_EXTI_LINE_UVM); \
} while(0)

/**
  * @brief  Enable the IO2VM Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_ENABLE_IT() SET_BIT(EXTI->IMR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Disable the IO2VM Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_DISABLE_IT() CLEAR_BIT(EXTI->IMR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Enable the IO2VM Event Line.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_ENABLE_EVENT() SET_BIT(EXTI->EMR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Disable the IO2VM Event Line.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_DISABLE_EVENT() CLEAR_BIT(EXTI->EMR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Enable the IO2VM Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_ENABLE_RISING_EDGE() SET_BIT(EXTI->RTSR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Disable the IO2VM Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_DISABLE_RISING_EDGE() CLEAR_BIT(EXTI->RTSR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Enable the IO2VM Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_ENABLE_FALLING_EDGE() SET_BIT(EXTI->FTSR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Disable the IO2VM Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_DISABLE_FALLING_EDGE() CLEAR_BIT(EXTI->FTSR1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Enable the IO2VM Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_ENABLE_RISING_FALLING_EDGE() \
do                                                        \
{                                                         \
  __HAL_PWR_IO2VM_EXTI_ENABLE_RISING_EDGE();              \
  __HAL_PWR_IO2VM_EXTI_ENABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Disable the IO2VM Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_DISABLE_RISING_FALLING_EDGE() \
do                                                         \
{                                                          \
  __HAL_PWR_IO2VM_EXTI_DISABLE_RISING_EDGE();              \
  __HAL_PWR_IO2VM_EXTI_DISABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Generate a Software Interrupt on IO2VM EXTI Line.
  * @retval None
  */
#define __HAL_PWR_IO2VM_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER1, PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Check whether the specified IO2VM EXTI flag is set or not.
  * @retval EXTI IO2VM Line Status.
  */
#define __HAL_PWR_IO2VM_EXTI_GET_FLAG() ((EXTI->RPR1 | EXTI->FPR1) & PWR_EXTI_LINE_IO2VM)

/**
  * @brief  Clear the IO2VM EXTI flag.
  * @retval None.
  */
#define __HAL_PWR_IO2VM_EXTI_CLEAR_FLAG()     \
do                                            \
{                                             \
  WRITE_REG(EXTI->RPR1, PWR_EXTI_LINE_IO2VM); \
  WRITE_REG(EXTI->FPR1, PWR_EXTI_LINE_IO2VM); \
} while(0)

/**
  * @brief  Enable the AVM1 Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_ENABLE_IT() SET_BIT(EXTI->IMR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Disable the AVM1 Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_DISABLE_IT() CLEAR_BIT(EXTI->IMR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Enable the AVM1 Event Line.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_ENABLE_EVENT() SET_BIT(EXTI->EMR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Disable the AVM1 Event Line.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_DISABLE_EVENT() CLEAR_BIT(EXTI->EMR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Enable the AVM1 Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_ENABLE_RISING_EDGE() SET_BIT(EXTI->RTSR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Disable the AVM1 Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_DISABLE_RISING_EDGE() CLEAR_BIT(EXTI->RTSR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Enable the AVM1 Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_ENABLE_FALLING_EDGE() SET_BIT(EXTI->FTSR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Disable the AVM1 Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_DISABLE_FALLING_EDGE() CLEAR_BIT(EXTI->FTSR1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Enable the AVM1 Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_ENABLE_RISING_FALLING_EDGE() \
do                                                       \
{                                                        \
  __HAL_PWR_AVM1_EXTI_ENABLE_RISING_EDGE();              \
  __HAL_PWR_AVM1_EXTI_ENABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Disable the AVM1 Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_DISABLE_RISING_FALLING_EDGE() \
do                                                        \
{                                                         \
  __HAL_PWR_AVM1_EXTI_DISABLE_RISING_EDGE();              \
  __HAL_PWR_AVM1_EXTI_DISABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Generate a Software Interrupt on AVM1 EXTI Line.
  * @retval None
  */
#define __HAL_PWR_AVM1_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER1, PWR_EXTI_LINE_AVM1)

/**
  * @brief  Check whether the specified AVM1 EXTI flag is set or not.
  * @retval EXTI AVM1 Line Status.
  */
#define __HAL_PWR_AVM1_EXTI_GET_FLAG() ((EXTI->RPR1 | EXTI->FPR1) & PWR_EXTI_LINE_AVM1)

/**
  * @brief  Clear the AVM1 EXTI flag.
  * @retval None.
  */
#define __HAL_PWR_AVM1_EXTI_CLEAR_FLAG()     \
do                                           \
{                                            \
  WRITE_REG(EXTI->RPR1, PWR_EXTI_LINE_AVM1); \
  WRITE_REG(EXTI->FPR1, PWR_EXTI_LINE_AVM1); \
} while(0)

/**
  * @brief  Enable the AVM2 Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_ENABLE_IT() SET_BIT(EXTI->IMR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Disable the AVM2 Extended Interrupt Line.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_DISABLE_IT() CLEAR_BIT(EXTI->IMR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Enable the AVM2 Event Line.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_ENABLE_EVENT() SET_BIT(EXTI->EMR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Disable the AVM2 Event Line.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_DISABLE_EVENT() CLEAR_BIT(EXTI->EMR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Enable the AVM2 Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_ENABLE_RISING_EDGE() SET_BIT(EXTI->RTSR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Disable the AVM2 Extended Interrupt Rising Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_DISABLE_RISING_EDGE() CLEAR_BIT(EXTI->RTSR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Enable the AVM2 Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_ENABLE_FALLING_EDGE() SET_BIT(EXTI->FTSR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Disable the AVM2 Extended Interrupt Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_DISABLE_FALLING_EDGE() CLEAR_BIT(EXTI->FTSR1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Enable the AVM2 Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_ENABLE_RISING_FALLING_EDGE() \
do                                                       \
{                                                        \
  __HAL_PWR_AVM2_EXTI_ENABLE_RISING_EDGE();              \
  __HAL_PWR_AVM2_EXTI_ENABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Disable the AVM2 Extended Interrupt Rising & Falling Trigger.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_DISABLE_RISING_FALLING_EDGE() \
do                                                        \
{                                                         \
  __HAL_PWR_AVM2_EXTI_DISABLE_RISING_EDGE();              \
  __HAL_PWR_AVM2_EXTI_DISABLE_FALLING_EDGE();             \
} while(0)

/**
  * @brief  Generate a Software Interrupt on AVM2 EXTI Line.
  * @retval None
  */
#define __HAL_PWR_AVM2_EXTI_GENERATE_SWIT() SET_BIT(EXTI->SWIER1, PWR_EXTI_LINE_AVM2)

/**
  * @brief  Check whether the specified AVM2 EXTI flag is set or not.
  * @retval EXTI AVM2 Line Status.
  */
#define __HAL_PWR_AVM2_EXTI_GET_FLAG() ((EXTI->RPR1 | EXTI->FPR1) & PWR_EXTI_LINE_AVM2)

/**
  * @brief  Clear the AVM2 EXTI flag.
  * @retval None.
  */
#define __HAL_PWR_AVM2_EXTI_CLEAR_FLAG()     \
do                                           \
{                                            \
  WRITE_REG(EXTI->RPR1, PWR_EXTI_LINE_AVM2); \
  WRITE_REG(EXTI->FPR1, PWR_EXTI_LINE_AVM2); \
} while(0)

/**
  * @brief Configure the main internal regulator output voltage.
  * @note  This macro is similar to HAL_PWREx_ControlVoltageScaling() API but
  *        doesn't check whether or not VOSREADY flag is set. User may resort
  *        to __HAL_PWR_GET_FLAG() macro to check VOSF bit state.
  * @param  __REGULATOR__ : Specifies the regulator output voltage to achieve a
  *                         tradeoff between performance and power consumption.
  *                         This parameter can be one of the following values :
  *                         @arg @ref PWR_REGULATOR_VOLTAGE_SCALE1 : Regulator voltage output scale 1.
  *                                                                  Provides a typical output voltage at 1.2 V.
  *                                                                  Used when system clock frequency is up to 160 MHz.
  *                         @arg @ref PWR_REGULATOR_VOLTAGE_SCALE2 : Regulator voltage output scale 2.
  *                                                                  Provides a typical output voltage at 1.1 V.
  *                                                                  Used when system clock frequency is up to 100 MHz.
  *                         @arg @ref PWR_REGULATOR_VOLTAGE_SCALE3 : Regulator voltage output scale 3.
  *                                                                  Provides a typical output voltage at 1.0 V.
  *                                                                  Used when system clock frequency is up to 50 MHz.
  *                         @arg @ref PWR_REGULATOR_VOLTAGE_SCALE4 : Regulator voltage output scale 4.
  *                                                                  Provides a typical output voltage at 0.9 V.
  *                                                                  Used when system clock frequency is up to 24 MHz.
  * @retval None.
  */
#define __HAL_PWR_VOLTAGESCALING_CONFIG(__REGULATOR__)  \
do                                                      \
{                                                       \
  __IO uint32_t tmpreg;                                 \
  MODIFY_REG(PWR->VOSR, PWR_VOSR_VOS, (__REGULATOR__)); \
  /* Delay after an RCC peripheral clock enabling */    \
  tmpreg = READ_BIT(PWR->VOSR, PWR_VOSR_VOS);           \
  UNUSED(tmpreg);                                       \
} while(0)
/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/

/** @addtogroup PWREx_Private_Constants PWR Extended Private Constants
  * @{
  */
/* PVM extended interrupts and event lines defines */
#define PWR_EXTI_LINE_UVM   (0x00080000UL) /*!< UVM EXTI Line   */
#define PWR_EXTI_LINE_IO2VM (0x00100000UL) /*!< IO2VM EXTI Line */
#define PWR_EXTI_LINE_AVM1  (0x00200000UL) /*!< AVM1 EXTI Line  */
#define PWR_EXTI_LINE_AVM2  (0x00400000UL) /*!< AVM2 EXTI Line  */

/* All available RAM retention define */
#if defined(PWR_CR4_SRAM1PDS4)
#define PWR_ALL_RAM_STOP_RETENTION_MASK_1 (PWR_SRAM1_PAGE1_3_STOP_RETENTION | PWR_SRAM2_FULL_STOP_RETENTION     | \
                                           PWR_SRAM3_PAGE1_8_STOP_RETENTION | PWR_SRAM4_FULL_STOP_RETENTION     | \
                                           PWR_ICACHE_FULL_STOP_RETENTION   | PWR_DCACHE_FULL_STOP_RETENTION    | \
                                           PWR_DMA2DRAM_FULL_STOP_RETENTION | PWR_PERIPHRAM_FULL_STOP_RETENTION | \
                                           PWR_PKA32RAM_FULL_STOP_RETENTION | PWR_SRAM1_FULL_STOP_RETENTION     | \
                                           PWR_SRAM3_FULL_STOP_RETENTION)

#define PWR_ALL_RAM_STOP_RETENTION_MASK_2 (PWR_SRAM1_PAGE4_12_STOP_RETENTION | PWR_SRAM3_PAGE9_13_STOP_RETENTION | \
                                           PWR_SRAM5_FULL_STOP_RETENTION)
#else
#define PWR_ALL_RAM_STOP_RETENTION_MASK (PWR_SRAM1_FULL_STOP_RETENTION    | PWR_SRAM2_FULL_STOP_RETENTION     | \
                                         PWR_SRAM3_FULL_STOP_RETENTION    | PWR_SRAM4_FULL_STOP_RETENTION     | \
                                         PWR_ICACHE_FULL_STOP_RETENTION   | PWR_DCACHE_FULL_STOP_RETENTION    | \
                                         PWR_DMA2DRAM_FULL_STOP_RETENTION | PWR_PERIPHRAM_FULL_STOP_RETENTION | \
                                         PWR_PKA32RAM_FULL_STOP_RETENTION)
#endif
/**
  * @}
  */

/* Private macros --------------------------------------------------------*/

/** @addtogroup PWREx_Private_Macros PWR Extended Private Macros
  * @{
  */
/* PVM type check macro */
#define IS_PWR_PVM_TYPE(TYPE)                    (((TYPE) == PWR_UVM )  ||\
                                                  ((TYPE) == PWR_IO2VM) ||\
                                                  ((TYPE) == PWR_AVM1)  ||\
                                                  ((TYPE) == PWR_AVM2))

/* PVM mode check macro */
#define IS_PWR_PVM_MODE(MODE)                    (((MODE) == PWR_PVM_MODE_NORMAL)            ||\
                                                  ((MODE) == PWR_PVM_MODE_IT_RISING)         ||\
                                                  ((MODE) == PWR_PVM_MODE_IT_FALLING)        ||\
                                                  ((MODE) == PWR_PVM_MODE_IT_RISING_FALLING) ||\
                                                  ((MODE) == PWR_PVM_MODE_EVENT_RISING)      ||\
                                                  ((MODE) == PWR_PVM_MODE_EVENT_FALLING)     ||\
                                                  ((MODE) == PWR_PVM_MODE_EVENT_RISING_FALLING))

/* SRD state check macro */
#define IS_PWR_SRD_STATE(SRD_STATE)              (((SRD_STATE) == PWR_SRD_DOMAIN_STOP) ||\
                                                  ((SRD_STATE) == PWR_SRD_DOMAIN_RUN))

/* Supply selection check macro */
#define IS_PWR_SUPPLY(PWR_SOURCE)                (((PWR_SOURCE) == PWR_LDO_SUPPLY) ||\
                                                  ((PWR_SOURCE) == PWR_SMPS_SUPPLY))

/* Voltage scaling range check macro */
#define IS_PWR_VOLTAGE_SCALING_RANGE(RANGE)      (((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE1) ||\
                                                  ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE2) ||\
                                                  ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE3) ||\
                                                  ((RANGE) == PWR_REGULATOR_VOLTAGE_SCALE4))

/* Battery charging resistor selection check macro */
#define IS_PWR_BATTERY_RESISTOR_SELECT(RESISTOR) (((RESISTOR) == PWR_BATTERY_CHARGING_RESISTOR_5) ||\
                                                  ((RESISTOR) == PWR_BATTERY_CHARGING_RESISTOR_1_5))

/* Battery charging activation check macro */
#define IS_PWR_BATTERY_CHARGING(CHARGING)        (((CHARGING) == PWR_BATTERY_CHARGING_DISABLE) ||\
                                                  ((CHARGING) == PWR_BATTERY_CHARGING_ENABLE))

/* GPIO port check macro */
#if defined(GPIOJ)
#define IS_PWR_GPIO_PORT(GPIO_PORT)              (((GPIO_PORT) == PWR_GPIO_A) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_B) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_C) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_D) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_E) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_F) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_G) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_H) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_I) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_J))
#else
#define IS_PWR_GPIO_PORT(GPIO_PORT)              (((GPIO_PORT) == PWR_GPIO_A) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_B) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_C) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_D) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_E) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_F) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_G) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_H) ||\
                                                  ((GPIO_PORT) == PWR_GPIO_I))
#endif

/* GPIO pin mask check macro */
#define IS_PWR_GPIO_PIN_MASK(BIT_MASK)           ((((BIT_MASK) & GPIO_PIN_MASK) != 0U) && ((BIT_MASK) <= GPIO_PIN_MASK))

/* SRAM2 rentention in STANDBY mode check macro */
#define IS_PWR_SRAM2_STANDBY_RETENTION(CONTENT)  (((CONTENT) == PWR_SRAM2_PAGE1_STNADBY_RETENTION) ||\
                                                  ((CONTENT) == PWR_SRAM2_PAGE2_STNADBY_RETENTION) ||\
                                                  ((CONTENT) == PWR_SRAM2_FULL_STNADBY_RETENTION))

/* RAMs rentention in STOP mode check macro */
#if defined(PWR_CR4_SRAM1PDS4)
#define IS_PWR_RAM_STOP_RETENTION(RAMCONTENT)                                                                         \
  ( (((RAMCONTENT) & PWR_CR4_FLAG) == PWR_CR4_FLAG) ? (((RAMCONTENT) & (~PWR_ALL_RAM_STOP_RETENTION_MASK_2)) == 0U) : \
                                                      (((RAMCONTENT) & (~PWR_ALL_RAM_STOP_RETENTION_MASK_1)) == 0U)) 
#else
#define IS_PWR_RAM_STOP_RETENTION(RAMCONTENT)    (((RAMCONTENT) & (~PWR_ALL_RAM_STOP_RETENTION_MASK)) == 0U)
#endif
/**
  * @}
  */

/** @addtogroup PWREx_Exported_Functions PWR Extended Exported Functions
  * @{
  */

/** @addtogroup PWREx_Exported_Functions_Group1 Power Supply Control Functions
* @{
*/
uint32_t          HAL_PWREx_GetVoltageRange      (void);
HAL_StatusTypeDef HAL_PWREx_ControlVoltageScaling(uint32_t VoltageScaling);
HAL_StatusTypeDef HAL_PWREx_ConfigSupply         (uint32_t SupplySource);
uint32_t          HAL_PWREx_GetSupplyConfig      (void);
void              HAL_PWREx_EnableFastSoftStart  (void);
void              HAL_PWREx_DisableFastSoftStart (void);
#if defined(PWR_CR2_FPWM)
void              HAL_PWREx_EnableSMPSPWMMode(void);
void              HAL_PWREx_DisableSMPSPWMMode(void);
#endif
/**
* @}
*/

/** @addtogroup PWREx_Exported_Functions_Group2 Low Power Control Functions
  * @{
  */
void HAL_PWREx_EnterSTOP1Mode          (uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP2Mode          (uint8_t STOPEntry);
void HAL_PWREx_EnterSTOP3Mode          (uint8_t STOPEntry);
void HAL_PWREx_EnterSHUTDOWNMode       (void);
void HAL_PWREx_ConfigSRDDomain         (uint32_t SRDState);
void HAL_PWREx_EnableUltraLowPowerMode (void);
void HAL_PWREx_DisableUltraLowPowerMode(void);
void HAL_PWREx_S3WU_IRQHandler         (uint32_t WakeUpPin);
void HAL_PWREx_S3WUCallback            (uint32_t WakeUpPin);
/**
  * @}
  */

/** @addtogroup PWREx_Exported_Functions_Group3 Voltage Monitoring Functions
  * @{
  */
void              HAL_PWREx_EnableBatteryCharging   (uint32_t ResistorSelection);
void              HAL_PWREx_DisableBatteryCharging  (void);
void              HAL_PWREx_EnableVddUSB            (void);
void              HAL_PWREx_DisableVddUSB           (void);
void              HAL_PWREx_EnableVddIO2            (void);
void              HAL_PWREx_DisableVddIO2           (void);
void              HAL_PWREx_EnableVddA              (void);
void              HAL_PWREx_DisableVddA             (void);
void              HAL_PWREx_EnableUVM               (void);
void              HAL_PWREx_DisableUVM              (void);
void              HAL_PWREx_EnableIO2VM             (void);
void              HAL_PWREx_DisableIO2VM            (void);
void              HAL_PWREx_EnableAVM1              (void);
void              HAL_PWREx_DisableAVM1             (void);
void              HAL_PWREx_EnableAVM2              (void);
void              HAL_PWREx_DisableAVM2             (void);
HAL_StatusTypeDef HAL_PWREx_ConfigPVM               (PWR_PVMTypeDef *sConfigPVM);
void              HAL_PWREx_EnableMonitoring        (void);
void              HAL_PWREx_DisableMonitoring       (void);
void              HAL_PWREx_EnableUCPDStandbyMode   (void);
void              HAL_PWREx_DisableUCPDStandbyMode  (void);
void              HAL_PWREx_EnableUCPDDeadBattery   (void);
void              HAL_PWREx_DisableUCPDDeadBattery  (void);
void              HAL_PWREx_PVD_PVM_IRQHandler      (void);
void              HAL_PWREx_UVMCallback             (void);
void              HAL_PWREx_IO2VMCallback           (void);
void              HAL_PWREx_AVM1Callback            (void);
void              HAL_PWREx_AVM2Callback            (void);
/**
  * @}
  */

/** @addtogroup PWREx_Exported_Functions_Group4 Memories Retention Functions
  * @{
  */
void              HAL_PWREx_EnableSRAM2ContentRetention (uint32_t SRAM2Pages);
void              HAL_PWREx_DisableSRAM2ContentRetention(void);
void              HAL_PWREx_EnableRAMsContentRetention  (uint32_t RAMSelection);
void              HAL_PWREx_DisableRAMsContentRetention (uint32_t RAMSelection);
void              HAL_PWREx_EnableFlashFastWakeUp       (void);
void              HAL_PWREx_DisableFlashFastWakeUp      (void);
HAL_StatusTypeDef HAL_PWREx_EnableBkupRAMRetention      (void);
void              HAL_PWREx_DisableBkupRAMRetention     (void);

#if defined(PWR_CR2_RLPSN)
void              HAL_PWREx_EnableRAMsLowPowerMode(void);
void              HAL_PWREx_DisableRAMsLowPowerMode(void);
#endif
/**
  * @}
  */

/** @addtogroup PWREx_Exported_Functions_Group5 I/O Pull-Up Pull-Down Configuration Functions
  * @{
  */
void              HAL_PWREx_EnablePullUpPullDownConfig  (void);
void              HAL_PWREx_DisablePullUpPullDownConfig (void);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullUp            (uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullUp           (uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_EnableGPIOPullDown          (uint32_t GPIO_Port, uint32_t GPIO_Pin);
HAL_StatusTypeDef HAL_PWREx_DisableGPIOPullDown         (uint32_t GPIO_Port, uint32_t GPIO_Pin);
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* STM32U5xx_HAL_PWR_EX_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
