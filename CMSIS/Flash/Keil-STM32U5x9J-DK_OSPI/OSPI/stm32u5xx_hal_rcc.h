/**
  ******************************************************************************
  * @file    stm32u5xx_hal_rcc.h
  * @author  MCD Application Team
  * @brief   Header file of RCC HAL  module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32U5xx_HAL_RCC_H
#define __STM32U5xx_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal_def.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @addtogroup RCC
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/** @defgroup RCC_Exported_Types RCC Exported Types
  * @{
  */

/**
  * @brief  RCC PLL configuration structure definition
  */
typedef struct
{
  uint32_t PLLState;   /*!< The new state of the PLL.
                            This parameter can be a value of @ref RCC_PLL_Config                      */

  uint32_t PLLSource;  /*!< RCC_PLLSource: PLL entry clock source.
                            This parameter must be a value of @ref RCC_PLL_Clock_Source               */

  uint32_t PLLM;       /*!< PLLM: Division factor for PLL VCO input clock.
                            This parameter must be a number between Min_Data = 1 and Max_Data = 16    */

  uint32_t PLLN;       /*!< PLLN: Multiplication factor for PLL VCO output clock.
                            This parameter must be a number between Min_Data = 4 and Max_Data = 512   */

  uint32_t PLLP;       /*!< PLLP: Division factor for system clock.
                            This parameter must be a number between Min_Data = 1 and Max_Data = 128
                          odd division factors are not allowed                                        */

  uint32_t PLLQ;       /*!< PLLQ: Division factor for peripheral clocks.
                            This parameter must be a number between Min_Data = 1 and Max_Data = 128   */

  uint32_t PLLR;       /*!< PLLR: Division factor for peripheral clocks.
                            This parameter must be a number between Min_Data = 2 and Max_Data = 128   */

  uint32_t PLLRGE;     /*!< PLLRGE: PLL1 clock Input range
                            This parameter must be a value of @ref RCC_PLL1_VCI_Range                 */

  uint32_t PLLFRACN;   /*!< PLLFRACN: Specifies Fractional Part Of The Multiplication Factor for
                            PLL1 VCO It should be a value between 0 and 32767                         */

} RCC_PLLInitTypeDef;

/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, MSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  uint32_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Config                        */

  uint32_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Config                        */

  uint32_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Config                        */

  uint32_t HSICalibrationValue;  /*!< The calibration trimming value (default is RCC_HSICALIBRATION_DEFAULT).
                                      This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x7F on the other devices */

  uint32_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Config                        */

  uint32_t LSIDiv;               /*!< The division factor of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Div                           */

  uint32_t MSIState;             /*!< The new state of the MSI.
                                      This parameter can be a value of @ref RCC_MSI_Config */

  uint32_t MSICalibrationValue;  /*!< The calibration trimming value (default is RCC_MSICALIBRATION_DEFAULT).
                                      This parameter must be a number between Min_Data = 0x00 and Max_Data = 0xFF */

  uint32_t MSIClockRange;        /*!< The MSI frequency range.
                                      This parameter can be a value of @ref RCC_MSI_Clock_Range                   */

  uint32_t MSIKClockRange;        /*!< The MSIK frequency range.
                                      This parameter can be a value of @ref RCC_MSIK_Clock_Range                  */

  uint32_t HSI48State;             /*!< The new state of the HSI48.
                                        This parameter can be a value of @ref RCC_HSI48_Config                    */

  uint32_t SHSIState;             /*!< The new state of the SHSI.
                                        This parameter can be a value of @ref RCC_SHSI_Config                    */

  uint32_t MSIKState;             /*!< The new state of the MSIK.
                                        This parameter can be a value of @ref RCC_MSIK_Config                     */

  RCC_PLLInitTypeDef PLL;        /*!< Main PLL structure parameters                                               */

} RCC_OscInitTypeDef;

/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type      */

  uint32_t SYSCLKSource;          /*!< The clock source used as system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_System_Clock_Source    */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source       */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB3CLKDivider;        /*!< The APB3 clock (PCLK3) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB3_Clock_Source                        */
} RCC_ClkInitTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_Exported_Constants RCC Exported Constants
  * @{
  */

/** @defgroup RCC_Peripheral_Memory_Mapping Peripheral Memory Mapping
  * @{
  */

/**
  * @}
  */

/** @defgroup RCC_Timeout_Value Timeout Values
  * @{
  */
#define RCC_DBP_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */
#define RCC_LSE_TIMEOUT_VALUE          LSE_STARTUP_TIMEOUT
/**
  * @}
  */

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_NONE        (0x00000000U)   /*!< Oscillator configuration unchanged */
#define RCC_OSCILLATORTYPE_HSE         (0x00000001U)   /*!< HSE to configure */
#define RCC_OSCILLATORTYPE_HSI         (0x00000002U)   /*!< HSI to configure */
#define RCC_OSCILLATORTYPE_LSE         (0x00000004U)   /*!< LSE to configure */
#define RCC_OSCILLATORTYPE_LSI         (0x00000008U)   /*!< LSI to configure */
#define RCC_OSCILLATORTYPE_MSI         (0x00000010U)   /*!< MSI to configure */
#define RCC_OSCILLATORTYPE_HSI48       (0x00000020U)   /*!< HSI48 to configure */
#define RCC_OSCILLATORTYPE_MSIK        (0x00000040U)   /*!< MSIK  to configure */
#define RCC_OSCILLATORTYPE_SHSI        (0x00000080U)   /*!< SHSI  to configure */
/**
  * @}
  */

/** @defgroup RCC_HSE_Config HSE Config
  * @{
  */
#define RCC_HSE_OFF                    (0x00000000U)                     /*!< HSE clock deactivation */
#define RCC_HSE_ON                     RCC_CR_HSEON                               /*!< HSE clock activation */
#define RCC_HSE_BYPASS                 ((uint32_t)(RCC_CR_HSEBYP | RCC_CR_HSEON)) /*!< External clock source for HSE clock */
/**
  * @}
  */

/** @defgroup RCC_LSE_Config LSE Config
  * @{
  */
#define RCC_LSE_OFF                    0U                                                                 /*!< LSE clock deactivation */
#define RCC_LSE_ON_RTC_ONLY            RCC_BDCR_LSEON                                                     /*!< LSE clock activation for RTC only */
#define RCC_LSE_ON                     ((uint32_t)(RCC_BDCR_LSESYSEN | RCC_BDCR_LSEON))                   /*!< LSE clock activation for RCC and peripherals */
#define RCC_LSE_BYPASS_RTC_ONLY        ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSEON))                     /*!< External clock source for LSE clock */
#define RCC_LSE_BYPASS                 ((uint32_t)(RCC_BDCR_LSEBYP | RCC_BDCR_LSESYSEN | RCC_BDCR_LSEON)) /*!< External clock source for LSE clock */
/**
  * @}
  */

/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                    (0x00000000U) /*!< HSI clock deactivation */
#define RCC_HSI_ON                     RCC_CR_HSION           /*!< HSI clock activation */

#define RCC_HSICALIBRATION_DEFAULT     (0x8U)      /* Default HSI calibration trimming value */
/**
  * @}
  */

/** @defgroup RCC_LSI_Config LSI Config
  * @{
  */
#define RCC_LSI_OFF                    (0x00000000U)      /*!< LSI clock deactivation */
#define RCC_LSI_ON                     RCC_BDCR_LSION     /*!< LSI clock activation */
/**
  * @}
  */

/** @defgroup RCC_LSI_Div LSI Div
  * @{
  */
#define RCC_LSI_DIV1                   0U                  /*!< LSI clock is not divided */
#define RCC_LSI_DIV128                 RCC_CSR_LSIPRE      /*!< LSI clock is divided by 128 */
/**
  * @}
  */

/** @defgroup RCC_MSI_Config MSI Config
  * @{
  */
#define RCC_MSI_OFF                    (0x00000000U) /*!< MSI clock deactivation */
#define RCC_MSI_ON                     RCC_CR_MSISON           /*!< MSI clock activation */

#define RCC_MSICALIBRATION_DEFAULT     (0x10U)   /*!< Default MSI calibration trimming value */
/**
  * @}
  */

/** @defgroup RCC_HSI48_Config HSI48 Config
  * @{
  */
#define RCC_HSI48_OFF                  (0x00000000U) /*!< HSI48 clock deactivation */
#define RCC_HSI48_ON                   RCC_CR_HSI48ON      /*!< HSI48 clock activation */
/**
  * @}
  */

/** @defgroup RCC_MSIK_Config MSIK Config
  * @{
  */
#define RCC_MSIK_OFF                  (0x00000000U) /*!< MSIK clock deactivation */
#define RCC_MSIK_ON                   RCC_CR_MSIKON      /*!< MSIK clock activation */
/**
  * @}
  */

/** @defgroup RCC_SHSI_Config SHSI Config
  * @{
  */
#define RCC_SHSI_OFF                  (0x00000000U) /*!< SHSI clock deactivation */
#define RCC_SHSI_ON                   RCC_CR_SHSION      /*!< SHSI clock activation */
/**
  * @}
  */

/** @defgroup RCC_PLL_Config  RCC PLL Config
  * @{
  */
#define RCC_PLL_NONE                 (0x00000000U)
#define RCC_PLL_OFF                  (0x00000001U)
#define RCC_PLL_ON                   (0x00000002U)

/**
  * @}
  */




/** @defgroup RCC_PLL_Clock_Output  RCC PLL Clock Output
  * @{
  */
#define RCC_PLL1_DIVP                RCC_PLL1CFGR_PLL1PEN
#define RCC_PLL1_DIVQ                RCC_PLL1CFGR_PLL1QEN
#define RCC_PLL1_DIVR                RCC_PLL1CFGR_PLL1REN

/**
  * @}
  */

/** @defgroup RCC_PLL1_VCI_Range  RCC PLL1 VCI Range
  * @{
  */
#define RCC_PLLVCIRANGE_0              (0x00000000U)
#define RCC_PLLVCIRANGE_1              RCC_PLL1CFGR_PLL1RGE_0
#define RCC_PLLVCIRANGE_2              RCC_PLL1CFGR_PLL1RGE_1
#define RCC_PLLVCIRANGE_3              (RCC_PLL1CFGR_PLL1RGE_0 | RCC_PLL1CFGR_PLL1RGE_1)

/**
  * @}
  */

/** @defgroup RCC_PLL_Clock_Source  RCC PLL Clock Source
  * @{
  */
#define RCC_PLLSOURCE_NONE             (0x00000000U)
#define RCC_PLLSOURCE_MSI              RCC_PLL1CFGR_PLL1SRC_0
#define RCC_PLLSOURCE_HSI              RCC_PLL1CFGR_PLL1SRC_1
#define RCC_PLLSOURCE_HSE              (RCC_PLL1CFGR_PLL1SRC_0 | RCC_PLL1CFGR_PLL1SRC_1)

/**
  * @}
  */


/** @defgroup RCC_MSI_Clock_Range MSI Clock Range
  * @{
  */
#define RCC_MSIRANGE_0                 (0x00000000U)                                                                                      /*!< MSI = 48 MHz    */
#define RCC_MSIRANGE_1                 RCC_ICSCR1_MSISRANGE_0                                                                             /*!< MSI = 24 MHz    */
#define RCC_MSIRANGE_2                 RCC_ICSCR1_MSISRANGE_1                                                                             /*!< MSI = 16 MHz    */
#define RCC_MSIRANGE_3                 (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_1)                                                  /*!< MSI = 12 MHz    */
#define RCC_MSIRANGE_4                 RCC_ICSCR1_MSISRANGE_2                                                                             /*!< MSI = 4 MHz     */
#define RCC_MSIRANGE_5                 (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_2)                                                  /*!< MSI = 2 MHz     */
#define RCC_MSIRANGE_6                 (RCC_ICSCR1_MSISRANGE_1 | RCC_ICSCR1_MSISRANGE_2)                                                  /*!< MSI = 1.33 MHz  */
#define RCC_MSIRANGE_7                 (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_1 | RCC_ICSCR1_MSISRANGE_2)                         /*!< MSI = 1 MHz     */
#define RCC_MSIRANGE_8                 RCC_ICSCR1_MSISRANGE_3                                                                             /*!< MSI = 3.072 MHz */
#define RCC_MSIRANGE_9                 (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_3)                                                  /*!< MSI = 1.536 MHz */
#define RCC_MSIRANGE_10                (RCC_ICSCR1_MSISRANGE_1 | RCC_ICSCR1_MSISRANGE_3)                                                  /*!< MSI = 1.024 MHz */
#define RCC_MSIRANGE_11                (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_1 | RCC_ICSCR1_MSISRANGE_3)                         /*!< MSI = 768 KHz   */
#define RCC_MSIRANGE_12                (RCC_ICSCR1_MSISRANGE_2 | RCC_ICSCR1_MSISRANGE_3)                                                  /*!< MSI = 400 KHz   */
#define RCC_MSIRANGE_13                (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_2 | RCC_ICSCR1_MSISRANGE_3)                         /*!< MSI = 200 KHz   */
#define RCC_MSIRANGE_14                (RCC_ICSCR1_MSISRANGE_1 | RCC_ICSCR1_MSISRANGE_2 | RCC_ICSCR1_MSISRANGE_3)                         /*!< MSI = 133 KHz   */
#define RCC_MSIRANGE_15                (RCC_ICSCR1_MSISRANGE_0 | RCC_ICSCR1_MSISRANGE_1| RCC_ICSCR1_MSISRANGE_2 | RCC_ICSCR1_MSISRANGE_3) /*!< MSI = 100 KHz   */
/**
  * @}
  */

/** @defgroup RCC_MSIk_Clock_Range MSIK Clock Range
  * @{
  */
#define RCC_MSIKRANGE_0                 (0x00000000U)                                                                                       /*!< MSIk = 48 MHz    */
#define RCC_MSIKRANGE_1                 RCC_ICSCR1_MSIKRANGE_0                                                                              /*!< MSIk = 24 MHz    */
#define RCC_MSIKRANGE_2                 RCC_ICSCR1_MSIKRANGE_1                                                                              /*!< MSIk = 16 MHz    */
#define RCC_MSIKRANGE_3                 (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_1)                                                   /*!< MSIk = 12 MHz    */
#define RCC_MSIKRANGE_4                 RCC_ICSCR1_MSIKRANGE_2                                                                              /*!< MSIk = 4 MHz     */
#define RCC_MSIKRANGE_5                 (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_2)                                                   /*!< MSIk = 2 MHz     */
#define RCC_MSIKRANGE_6                 (RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_2)                                                   /*!< MSIk = 1.33 MHz  */
#define RCC_MSIKRANGE_7                 (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_2)                          /*!< MSIk = 1 MHz     */
#define RCC_MSIKRANGE_8                 RCC_ICSCR1_MSIKRANGE_3                                                                              /*!< MSIk = 3.072 MHz */
#define RCC_MSIKRANGE_9                 (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_3)                                                   /*!< MSIk = 1.536 MHz */
#define RCC_MSIKRANGE_10                (RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_3)                                                   /*!< MSIk = 1.024 MHz */
#define RCC_MSIKRANGE_11                (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_3)                          /*!< MSIk = 768 KHz   */
#define RCC_MSIKRANGE_12                (RCC_ICSCR1_MSIKRANGE_2 | RCC_ICSCR1_MSIKRANGE_3)                                                   /*!< MSIk = 400 KHz   */
#define RCC_MSIKRANGE_13                (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_2 | RCC_ICSCR1_MSIKRANGE_3)                          /*!< MSIk = 200 KHz   */
#define RCC_MSIKRANGE_14                (RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_2 | RCC_ICSCR1_MSIKRANGE_3)                          /*!< MSIk = 133 KHz   */
#define RCC_MSIKRANGE_15                (RCC_ICSCR1_MSIKRANGE_0 | RCC_ICSCR1_MSIKRANGE_1 | RCC_ICSCR1_MSIKRANGE_2 | RCC_ICSCR1_MSIKRANGE_3) /*!< MSIk = 100 KHz   */
/**
  * @}
  */

/** @defgroup SW configuration
  * @{
  */
#define RCC_CFGR1_SW_MSI                      (0x00000000U)                           /*!< MSI oscillator selection as system clock */
#define RCC_CFGR1_SW_HSI                      (0x00000001U)                           /*!< HSI16 oscillator selection as system clock */
#define RCC_CFGR1_SW_HSE                      (0x00000002U)                           /*!< HSE oscillator selection as system clock */
#define RCC_CFGR1_SW_PLL1                     (0x00000003U)                           /*!< PLL selection as system clock */
/**
  * @}
  */

/** @defgroup SWS configuration
  * @{
  */
#define RCC_CFGR1_SWS_MSI                     (0x00000000U)                           /*!< MSI oscillator used as system clock */
#define RCC_CFGR1_SWS_HSI                     (0x00000004U)                           /*!< HSI16 oscillator used as system clock */
#define RCC_CFGR1_SWS_HSE                     (0x00000008U)                           /*!< HSE oscillator used as system clock */
#define RCC_CFGR1_SWS_PLL1                    (0x0000000CU)                           /*!< PLL used as system clock */
/**
  * @}
  */

/** @defgroup CFGR1_MCOPRE configuration
  * @{
  */
#define RCC_CFGR1_MCOPRE_DIV1                 (0x00000000U)                           /*!< MCO is divided by 1 */
#define RCC_CFGR1_MCOPRE_DIV2                 (0x10000000U)                           /*!< MCO is divided by 2 */
#define RCC_CFGR1_MCOPRE_DIV4                 (0x20000000U)                           /*!< MCO is divided by 4 */
#define RCC_CFGR1_MCOPRE_DIV8                 (0x30000000U)                           /*!< MCO is divided by 8 */
#define RCC_CFGR1_MCOPRE_DIV16                (0x40000000U)                           /*!< MCO is divided by 16 */
/**
  * @}
  */

/** @defgroup HPRE configuration
  * @{
  */
#define RCC_CFGR2_HPRE_DIV1                   (0x00000000U)                              /*!< SYSCLK not divided */
#define RCC_CFGR2_HPRE_DIV2                   (0x00000008U)                              /*!< SYSCLK divided by 2 */
#define RCC_CFGR2_HPRE_DIV4                   (0x00000009U)                              /*!< SYSCLK divided by 4 */
#define RCC_CFGR2_HPRE_DIV8                   (0x0000000AU)                              /*!< SYSCLK divided by 8 */
#define RCC_CFGR2_HPRE_DIV16                  (0x0000000BU)                              /*!< SYSCLK divided by 16 */
#define RCC_CFGR2_HPRE_DIV64                  (0x0000000CU)                              /*!< SYSCLK divided by 64 */
#define RCC_CFGR2_HPRE_DIV128                 (0x0000000DU)                              /*!< SYSCLK divided by 128 */
#define RCC_CFGR2_HPRE_DIV256                 (0x0000000EU)                              /*!< SYSCLK divided by 256 */
#define RCC_CFGR2_HPRE_DIV512                 (0x0000000FU)                              /*!< SYSCLK divided by 512 */
/**
  * @}
  */

/** @defgroup PPRE1 configuration
  * @{
  */
#define RCC_CFGR2_PPRE1_DIV1                  (0x00000000U)                              /*!< HCLK not divided */
#define RCC_CFGR2_PPRE1_DIV2                  (0x00000040U)                              /*!< HCLK divided by 2 */
#define RCC_CFGR2_PPRE1_DIV4                  (0x00000050U)                              /*!< HCLK divided by 4 */
#define RCC_CFGR2_PPRE1_DIV8                  (0x00000060U)                              /*!< HCLK divided by 8 */
#define RCC_CFGR2_PPRE1_DIV16                 (0x00000070U)                              /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup PPRE2 configuration
  * @{
  */
#define RCC_CFGR2_PPRE2_DIV1                  (0x00000000U)                              /*!< HCLK not divided */
#define RCC_CFGR2_PPRE2_DIV2                  (0x00000400U)                              /*!< HCLK divided by 2 */
#define RCC_CFGR2_PPRE2_DIV4                  (0x00000500U)                              /*!< HCLK divided by 4 */
#define RCC_CFGR2_PPRE2_DIV8                  (0x00000600U)                              /*!< HCLK divided by 8 */
#define RCC_CFGR2_PPRE2_DIV16                 (0x00000700U)                              /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup PPRE3 configuration
  * @{
  */
#define RCC_CFGR3_PPRE3_DIV1                  (0x00000000U)                              /*!< HCLK not divided */
#define RCC_CFGR3_PPRE3_DIV2                  (0x00000040U)                              /*!< HCLK divided by 2 */
#define RCC_CFGR3_PPRE3_DIV4                  (0x00000050U)                              /*!< HCLK divided by 4 */
#define RCC_CFGR3_PPRE3_DIV8                  (0x00000060U)                              /*!< HCLK divided by 8 */
#define RCC_CFGR3_PPRE3_DIV16                 (0x00000070U)                              /*!< HCLK divided by 16 */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK           (0x00000001U)  /*!< SYSCLK to configure */
#define RCC_CLOCKTYPE_HCLK             (0x00000002U)  /*!< HCLK to configure */
#define RCC_CLOCKTYPE_PCLK1            (0x00000004U)  /*!< PCLK1 to configure */
#define RCC_CLOCKTYPE_PCLK2            (0x00000008U)  /*!< PCLK2 to configure */
#define RCC_CLOCKTYPE_PCLK3            (0x00000010U)  /*!< PCLK3 to configure */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source System Clock Source
  * @{
  */
#define RCC_SYSCLKSOURCE_MSI            RCC_CFGR1_SW_MSI    /*!< MSI selection as system clock */
#define RCC_SYSCLKSOURCE_HSI            RCC_CFGR1_SW_HSI    /*!< HSI selection as system clock */
#define RCC_SYSCLKSOURCE_HSE            RCC_CFGR1_SW_HSE    /*!< HSE selection as system clock */
#define RCC_SYSCLKSOURCE_PLLCLK         RCC_CFGR1_SW_PLL1   /*!< PLL1 selection as system clock */
/**
  * @}
  */

/** @defgroup RCC_System_Clock_Source_Status System Clock Source Status
  * @{
  */
#define RCC_SYSCLKSOURCE_STATUS_MSI     RCC_CFGR1_SWS_MSI   /*!< MSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSI     RCC_CFGR1_SWS_HSI   /*!< HSI used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_HSE     RCC_CFGR1_SWS_HSE   /*!< HSE used as system clock */
#define RCC_SYSCLKSOURCE_STATUS_PLL1CLK RCC_CFGR1_SWS_PLL1  /*!< PLL1 used as system clock */
/**
  * @}
  */

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                RCC_CFGR2_HPRE_DIV1   /*!< SYSCLK not divided */
#define RCC_SYSCLK_DIV2                RCC_CFGR2_HPRE_DIV2   /*!< SYSCLK divided by 2 */
#define RCC_SYSCLK_DIV4                RCC_CFGR2_HPRE_DIV4   /*!< SYSCLK divided by 4 */
#define RCC_SYSCLK_DIV8                RCC_CFGR2_HPRE_DIV8   /*!< SYSCLK divided by 8 */
#define RCC_SYSCLK_DIV16               RCC_CFGR2_HPRE_DIV16  /*!< SYSCLK divided by 16 */
#define RCC_SYSCLK_DIV64               RCC_CFGR2_HPRE_DIV64  /*!< SYSCLK divided by 64 */
#define RCC_SYSCLK_DIV128              RCC_CFGR2_HPRE_DIV128 /*!< SYSCLK divided by 128 */
#define RCC_SYSCLK_DIV256              RCC_CFGR2_HPRE_DIV256 /*!< SYSCLK divided by 256 */
#define RCC_SYSCLK_DIV512              RCC_CFGR2_HPRE_DIV512 /*!< SYSCLK divided by 512 */
/**
  * @}
  */

/** @defgroup RCC_APB1_APB2_Clock_Source APB1 APB2 Clock Source
  * @{
  */
#define RCC_HCLK_DIV1                  RCC_CFGR2_PPRE1_DIV1  /*!< HCLK not divided */
#define RCC_HCLK_DIV2                  RCC_CFGR2_PPRE1_DIV2  /*!< HCLK divided by 2 */
#define RCC_HCLK_DIV4                  RCC_CFGR2_PPRE1_DIV4  /*!< HCLK divided by 4 */
#define RCC_HCLK_DIV8                  RCC_CFGR2_PPRE1_DIV8  /*!< HCLK divided by 8 */
#define RCC_HCLK_DIV16                 RCC_CFGR2_PPRE1_DIV16 /*!< HCLK divided by 16 */

/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Source RTC Clock Source
  * @{
  */
#define RCC_RTCCLKSOURCE_NO_CLK        (0x00000000U) /*!< No clock used as RTC clock */
#define RCC_RTCCLKSOURCE_LSE           RCC_BDCR_RTCSEL_0       /*!< LSE oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_LSI           RCC_BDCR_RTCSEL_1       /*!< LSI oscillator clock used as RTC clock */
#define RCC_RTCCLKSOURCE_HSE_DIV32     RCC_BDCR_RTCSEL         /*!< HSE oscillator clock divided by 32 used as RTC clock */
/**
  * @}
  */

/** @defgroup RCC_MCO_Index MCO Index
  * @{
  */
#define RCC_MCO1                       (0x00000000U)
#define RCC_MCO                        RCC_MCO1               /*!< MCO1 to be compliant with other families with 2 MCOs*/
/**
  * @}
  */

/** @defgroup RCC_MCO1_Clock_Source MCO1 Clock Source
  * @{
  */
#define RCC_MCO1SOURCE_NOCLOCK         (0x00000000U)                           /*!< MCO1 output disabled, no clock on MCO1 */
#define RCC_MCO1SOURCE_SYSCLK          RCC_CFGR1_MCOSEL_0                      /*!< SYSCLK selection as MCO1 source */
#define RCC_MCO1SOURCE_MSI             RCC_CFGR1_MCOSEL_1                      /*!< MSI selection as MCO1 source */
#define RCC_MCO1SOURCE_HSI             (RCC_CFGR1_MCOSEL_0| RCC_CFGR1_MCOSEL_1) /*!< HSI selection as MCO1 source */
#define RCC_MCO1SOURCE_HSE             RCC_CFGR1_MCOSEL_2                      /*!< HSE selection as MCO1 source */
#define RCC_MCO1SOURCE_PLL1CLK         (RCC_CFGR1_MCOSEL_0|RCC_CFGR1_MCOSEL_2)  /*!< PLLCLK selection as MCO1 source */
#define RCC_MCO1SOURCE_LSI             (RCC_CFGR1_MCOSEL_1|RCC_CFGR1_MCOSEL_2)  /*!< LSI selection as MCO1 source */
#define RCC_MCO1SOURCE_LSE             (RCC_CFGR1_MCOSEL_0|RCC_CFGR1_MCOSEL_1|RCC_CFGR1_MCOSEL_2) /*!< LSE selection as MCO1 source */
#define RCC_MCO1SOURCE_HSI48           RCC_CFGR1_MCOSEL_3                      /*!< HSI48 selection as MCO1 source */
#define RCC_MCO1SOURCE_MSIK            (RCC_CFGR1_MCOSEL_3| RCC_CFGR1_MCOSEL_0) /*!< MSIK selection as MCO1 source */
/**
  * @}
  */

/** @defgroup RCC_MCOx_Clock_Prescaler MCO1 Clock Prescaler
  * @{
  */
#define RCC_MCODIV_1                   RCC_CFGR1_MCOPRE_DIV1     /*!< MCO not divided  */
#define RCC_MCODIV_2                   RCC_CFGR1_MCOPRE_DIV2     /*!< MCO divided by 2 */
#define RCC_MCODIV_4                   RCC_CFGR1_MCOPRE_DIV4     /*!< MCO divided by 4 */
#define RCC_MCODIV_8                   RCC_CFGR1_MCOPRE_DIV8     /*!< MCO divided by 8 */
#define RCC_MCODIV_16                  RCC_CFGR1_MCOPRE_DIV16    /*!< MCO divided by 16 */
/**
  * @}
  */

/** @defgroup RCC_Interrupt Interrupts
  * @{
  */
#define RCC_IT_LSIRDY                  RCC_CIFR_LSIRDYF      /*!< LSI Ready Interrupt flag */
#define RCC_IT_LSERDY                  RCC_CIFR_LSERDYF      /*!< LSE Ready Interrupt flag */
#define RCC_IT_MSIRDY                  RCC_CIFR_MSISRDYF     /*!< MSI Ready Interrupt flag */
#define RCC_IT_HSIRDY                  RCC_CIFR_HSIRDYF      /*!< HSI16 Ready Interrupt flag */
#define RCC_IT_HSERDY                  RCC_CIFR_HSERDYF      /*!< HSE Ready Interrupt flag */
#define RCC_IT_HSI48RDY                RCC_CIFR_HSI48RDYF    /*!< HSI48 Ready Interrupt flag */
#define RCC_IT_PLLRDY                  RCC_CIFR_PLL1RDYF     /*!< PLL1 Ready Interrupt flag */
#define RCC_IT_PLL2RDY                 RCC_CIFR_PLL2RDYF     /*!< PLL2 Ready Interrupt flag */
#define RCC_IT_PLL3RDY                 RCC_CIFR_PLL3RDYF     /*!< PLL3 Ready Interrupt flag */
#define RCC_IT_CSS                     RCC_CIFR_CSSF         /*!< Clock Security System Interrupt flag */
#define RCC_IT_MSIKRDY                 RCC_CIFR_MSIKRDYF     /*!< MSIK Ready Interrupt flag */
#define RCC_IT_SHSIRDY                 RCC_CIFR_SHSIRDYF     /*!< SHSI Ready Interrupt flag */
/**
  * @}
  */

/** @defgroup RCC_Flag Flags
  *        Elements values convention: XXXYYYYYb
  *           - YYYYY  : Flag position in the register
  *           - XXX  : Register index
  *                 - 001: CR register
  *                 - 010: BDCR register
  *                 - 011: CSR register
  *                 - 100: CRRCR register
  * @{
  */
/* Flags in the CR register */
#define RCC_FLAG_MSIRDY                ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_MSIRDY_Pos)) /*!< MSI Ready flag */
#define RCC_FLAG_HSIRDY                ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_HSIRDY_Pos)) /*!< HSI Ready flag */
#define RCC_FLAG_HSERDY                ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_HSERDY_Pos)) /*!< HSE Ready flag */
#define RCC_FLAG_PLL1RDY               ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL1RDY_Pos)) /*!< PLL Ready flag */
#define RCC_FLAG_PLL2RDY               ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL2RDY_Pos)) /*!< PLL2 Ready flag */
#define RCC_FLAG_PLL3RDY               ((uint32_t)((CR_REG_INDEX << 5U) | RCC_CR_PLL3RDY_Pos)) /*!< PLL3 Ready flag */

/* Flags in the BDCR register */
#define RCC_FLAG_LSERDY                ((uint32_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSERDY_Pos)) /*!< LSE Ready flag */
#define RCC_FLAG_LSECSSD               ((uint32_t)((BDCR_REG_INDEX << 5U) | RCC_BDCR_LSECSSD_Pos)) /*!< LSE Clock Security System Interrupt flag */

/* Flags in the CSR register */
#define RCC_FLAG_LSIRDY                ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LSIRDY_Pos))   /*!< LSI Ready flag */
#define RCC_FLAG_RMVF                  ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_RMVF_Pos))     /*!< Remove reset flag */
#define RCC_FLAG_OBLRST                ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_OBLRSTF_Pos))  /*!< Option Byte Loader reset flag */
#define RCC_FLAG_PINRST                ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_PINRSTF_Pos))  /*!< PIN reset flag */
#define RCC_FLAG_BORRST                ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_BORRSTF_Pos))  /*!< BOR reset flag */
#define RCC_FLAG_SFTRST                ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_SFTRSTF_Pos))  /*!< Software Reset flag */
#define RCC_FLAG_IWDGRST               ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_IWDGRSTF_Pos)) /*!< Independent Watchdog reset flag */
#define RCC_FLAG_WWDGRST               ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_WWDGRSTF_Pos)) /*!< Window watchdog reset flag */
#define RCC_FLAG_LPWRRST               ((uint32_t)((CSR_REG_INDEX << 5U) | RCC_CSR_LPWRRSTF_Pos)) /*!< Low-Power reset flag */

/* Flags in the CRRCR register */
#define RCC_FLAG_HSI48RDY              ((uint32_t)((CRRCR_REG_INDEX << 5U) | RCC_CRRCR_HSI48RDY_Pos)) /*!< HSI48 Ready flag */
/**
  * @}
  */

/** @defgroup RCC_LSEDrive_Config LSE Drive Config
  * @{
  */
#define RCC_LSEDRIVE_LOW                 (0x00000000U) /*!< LSE low drive capability */
#define RCC_LSEDRIVE_MEDIUMLOW           RCC_BDCR_LSEDRV_0      /*!< LSE medium low drive capability */
#define RCC_LSEDRIVE_MEDIUMHIGH          RCC_BDCR_LSEDRV_1      /*!< LSE medium high drive capability */
#define RCC_LSEDRIVE_HIGH                RCC_BDCR_LSEDRV        /*!< LSE high drive capability */
/**
  * @}
  */

/** @defgroup RCC_Stop_WakeUpClock Wake-Up from STOP Clock
  * @{
  */
#define RCC_STOP_WAKEUPCLOCK_MSI       (0x00000000U)  /*!< MSI selection after wake-up from STOP */
#define RCC_STOP_WAKEUPCLOCK_HSI       RCC_CFGR1_STOPWUCK       /*!< HSI selection after wake-up from STOP */
/**
  * @}
  */

/** @defgroup RCC_Stop_KernelWakeUpClock  RCC Stop KernelWakeUpClock
  * @{
  */
#define RCC_STOP_KERWAKEUPCLOCK_MSI       (0x00000000U)     /*!< MSI kernel clock selection after wake-up from STOP */
#define RCC_STOP_KERWAKEUPCLOCK_HSI        RCC_CFGR1_STOPKERWUCK     /*!< HSI kernel clock selection after wake-up from STOP */

/**
  * @}
  */

/** @defgroup RCC_items RCC items
  * @brief RCC items to configure attributes on
  * @{
  */
#define RCC_HSI                        RCC_SECCFGR_HSISEC
#define RCC_HSE                        RCC_SECCFGR_HSESEC
#define RCC_MSI                        RCC_SECCFGR_MSISEC
#define RCC_LSI                        RCC_SECCFGR_LSISEC
#define RCC_LSE                        RCC_SECCFGR_LSESEC
#define RCC_SYSCLK                     RCC_SECCFGR_SYSCLKSEC
#define RCC_PRESC                      RCC_SECCFGR_PRESCSEC
#define RCC_PLL1                       RCC_SECCFGR_PLL1SEC
#define RCC_PLL2                       RCC_SECCFGR_PLL2SEC
#define RCC_PLL3                       RCC_SECCFGR_PLL3SEC
#define RCC_CLK48M                     RCC_SECCFGR_CLK48MSEC
#define RCC_HSI48                      RCC_SECCFGR_HSI48SEC
#define RCC_RMVF                       RCC_SECCFGR_RMVFSEC
#define RCC_ALL                        (RCC_HSI|RCC_HSE|RCC_MSI|RCC_LSI|RCC_LSE|RCC_HSI48| \
                                        RCC_SYSCLK|RCC_PRESC|RCC_PLL1|RCC_PLL2| \
                                        RCC_PLL3|RCC_CLK48M|RCC_RMVF)
/**
  * @}
  */

/** @defgroup RCC_attributes RCC attributes
  * @brief RCC privilege/non-privilege and secure/non-secure attributes
  * @{
  */
#define RCC_NSEC_PRIV                  0x00000001U        /*!< Non-secure Privilege attribute item     */
#define RCC_NSEC_NPRIV                 0x00000002U        /*!< Non-secure Non-privilege attribute item */
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define RCC_SEC_PRIV                   0x00000010U        /*!< Secure Privilege attribute item         */
#define RCC_SEC_NPRIV                  0x00000020U        /*!< Secure Non-privilege attribute item     */
#endif /* __ARM_FEATURE_CMSE */
/* Exported macros -----------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_AHB1_Peripheral_Clock_Enable_Disable AHB1 Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_GPDMA_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMA1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMA1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_CORDIC_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CORDICEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CORDICEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_FMAC_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FMACEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FMACEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_TSC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_CRC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_RAMCFG_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_RAMCFGEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_RAMCFGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#define __HAL_RCC_FLASH_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_MDF1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_MDF1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_MDF1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DMA2D_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPU2DEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPU2DEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GCACHEEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GCACHEEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GTZC1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GTZC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_BKPSRAM_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_BKPSRAMEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_BKPSRAMEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DCACHE_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DCACHEEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DCACHEEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_SRAM1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_SRAM1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif

#define __HAL_RCC_GPDMA_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMA1EN)

#define __HAL_RCC_CORDIC_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CORDICEN)

#define __HAL_RCC_FMAC_CLK_DISABLE()           CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FMACEN)

#define __HAL_RCC_MDF1_CLK_DISABLE()           CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_MDF1EN)

#define __HAL_RCC_FLASH_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN)

#define __HAL_RCC_CRC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN)

#define __HAL_RCC_TSC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN)

#define __HAL_RCC_RAMCFG_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_RAMCFGEN)

#define __HAL_RCC_DMA2D_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPU2DEN)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GCACHEEN)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_CLK_DISABLE()          CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GTZC1EN)

#define __HAL_RCC_BKPSRAM_CLK_DISABLE()        CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_BKPSRAMEN)

#define __HAL_RCC_DCACHE_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DCACHEEN)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM1_CLK_DISABLE()         CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_SRAM1EN)
#endif


/**
  * @}
  */

/** @defgroup RCC_AHB2_Peripheral_Clock_Enable_Disable AHB2 Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_GPIOA_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOB_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOC_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOD_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOE_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOF_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOG_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOH_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GPIOI_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOJEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOJEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#endif /* GPIOJ */

#define __HAL_RCC_ADC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADC1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DCMI_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMI_PSSIEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMI_PSSIEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_ENABLE()      do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_CLK_ENABLE()      do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGHSEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGHSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* USB_OTG_HS */

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_USBPHYC_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USBPHYCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USBPHYCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif

#if defined(AES)
#define __HAL_RCC_AES_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* HASH */

#define __HAL_RCC_RNG_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_PKA_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SAES_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SAESEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SAESEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OSPIM_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OTFDEC1_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OTFDEC2_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SDMMC1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SDMMC2_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM2_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SRAM3_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif


#define __HAL_RCC_GPIOA_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN)

#define __HAL_RCC_GPIOB_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN)

#define __HAL_RCC_GPIOC_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN)

#define __HAL_RCC_GPIOD_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN)

#define __HAL_RCC_GPIOE_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN)

#define __HAL_RCC_GPIOF_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN)

#define __HAL_RCC_GPIOG_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN)

#define __HAL_RCC_GPIOH_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN)

#define __HAL_RCC_GPIOI_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOJEN)
#endif /* GPIOJ */

#define __HAL_RCC_ADC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADC1EN)

#define __HAL_RCC_DCMI_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMI_PSSIEN)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_DISABLE()     CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_CLK_DISABLE()     CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGHSEN)
#endif /* USB_OTG_HS */

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_USBPHYC_CLK_DISABLE()        CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_USBPHYCEN)
#endif

#if defined(AES)
#define __HAL_RCC_AES_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN);
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN)
#endif /* HASH */

#define __HAL_RCC_RNG_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN)

#define __HAL_RCC_PKA_CLK_DISABLE()            CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN)

#define __HAL_RCC_SAES_CLK_DISABLE()           CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SAESEN)

#define __HAL_RCC_OSPIM_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN)

#define __HAL_RCC_OTFDEC1_CLK_DISABLE()        CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC1EN)

#define __HAL_RCC_OTFDEC2_CLK_DISABLE()        CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC2EN)

#define __HAL_RCC_SDMMC1_CLK_DISABLE()         CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN)

#define __HAL_RCC_SDMMC2_CLK_DISABLE()         CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM2_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM2EN)

#define __HAL_RCC_SRAM3_CLK_DISABLE()          CLEAR_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SRAM3EN)
#endif

/**
  * @}
  */

/** @defgroup RCC_AHB4_Clock_Enable_Disable AHB4 Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB4 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_FMC_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_FMCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_FMCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OSPI1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OSPI2_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSPI1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSPI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* HSPI1 */

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM5_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB4ENR, RCC_AHB4ENR_SRAM5EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_SRAM5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif

#define __HAL_RCC_FMC_CLK_DISABLE()            CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_FMCEN)

#define __HAL_RCC_OSPI1_CLK_DISABLE()          CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI1EN)

#define __HAL_RCC_OSPI2_CLK_DISABLE()          CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI2EN)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_CLK_DISABLE()          CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSPI1EN)
#endif /* HSPI1 */

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM5_CLK_DISABLE()          CLEAR_BIT(RCC->AHB4ENR, RCC_AHB4ENR_SRAM5EN)
#endif

/**
  * @}
  */

/** @defgroup RCC_AHB3_Clock_Enable_Disable AHB3ENR Peripheral Clock Enable Disable
  * @brief  Enable or disable the AHB3ENR peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_LPGPIO_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPGPIOEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPGPIOEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_PWR_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_ADC4_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADC4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADC4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DAC1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DAC1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DAC1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPDMA_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPDMA1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPDMA1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_ADF1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADF1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADF1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_GTZC2_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_GTZC2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_GTZC2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM4_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_SRAM4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_SRAM4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif

#define __HAL_RCC_LPGPIO_CLK_DISABLE()           CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPGPIOEN)

#define __HAL_RCC_PWR_CLK_DISABLE()              CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN)

#define __HAL_RCC_ADC4_CLK_DISABLE()             CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADC4EN)

#define __HAL_RCC_DAC1_CLK_DISABLE()             CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DAC1EN)

#define __HAL_RCC_LPDMA_CLK_DISABLE()            CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPDMA1EN)

#define __HAL_RCC_ADF1_CLK_DISABLE()             CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADF1EN)

#define __HAL_RCC_GTZC2_CLK_DISABLE()            CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_GTZC2EN)

#if defined (STM32U599xx) || defined (STM32U5A9xx)
#define __HAL_RCC_SRAM4_CLK_DISABLE()            CLEAR_BIT(RCC->AHB3ENR, RCC_AHB3ENR_SRAM4EN)
#endif

/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Enable_Disable APB1 Peripheral Clock Enable Disable
  * @brief  Enable or disable the APB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_TIM2_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM3_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM4_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM5_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM6_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM7_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_WWDG_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SPI2_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_USART2_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_USART3_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_UART4_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_UART5_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define  __HAL_RCC_I2C1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define  __HAL_RCC_I2C2_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define  __HAL_RCC_CRS_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(USART6)
#define  __HAL_RCC_USART6_CLK_ENABLE()         do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART6EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART6EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* USART6 */

#define __HAL_RCC_I2C4_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_DTS_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_DTSEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_DTSEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPTIM2_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(I2C5)
#define __HAL_RCC_I2C5_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C5EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C5EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C6EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C6EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_FDCAN1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_FDCAN1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_UCPD_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB1ENR2, RCC_APB1ENR2_UCPDEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_UCPDEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM2_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN)

#define __HAL_RCC_TIM3_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN)

#define __HAL_RCC_TIM4_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN)

#define __HAL_RCC_TIM5_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN)

#define __HAL_RCC_TIM6_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN)

#define __HAL_RCC_TIM7_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN)

#define __HAL_RCC_WWDG_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN)

#define __HAL_RCC_SPI2_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN)

#define __HAL_RCC_USART2_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN)

#define __HAL_RCC_USART3_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN)

#define __HAL_RCC_UART4_CLK_DISABLE()       CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN)

#define __HAL_RCC_UART5_CLK_DISABLE()       CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN)

#define __HAL_RCC_I2C1_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN)

#define __HAL_RCC_I2C2_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN)

#define __HAL_RCC_CRS_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN)

#if defined(USART6)
#define __HAL_RCC_USART6_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART6EN)
#endif /* USART6 */

#define __HAL_RCC_I2C4_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN)

#define __HAL_RCC_DTS_CLK_DISABLE()         CLEAR_BIT(RCC->APB1ENR2 , RCC_APB1ENR2_DTSEN)

#define __HAL_RCC_LPTIM2_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN)

#if defined(I2C5)
#define __HAL_RCC_I2C5_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C5EN)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C6EN)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_CLK_DISABLE()      CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_FDCAN1EN)

#define __HAL_RCC_UCPD_CLK_DISABLE()        CLEAR_BIT(RCC->APB1ENR2, RCC_APB1ENR2_UCPDEN)

/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Enable_Disable APB2 Peripheral Clock Enable Disable
  * @brief  Enable or disable the APB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_TIM1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN); \
                                                 UNUSED(tmpreg); \
                                                 } while(0)

#define __HAL_RCC_SPI1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM8_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)


#define __HAL_RCC_USART1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM15_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM16_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_TIM17_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SAI1_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SAI2_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIHOSTEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIHOSTEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)
#endif /* DSI */

#define __HAL_RCC_TIM1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN)

#define __HAL_RCC_SPI1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN)

#define __HAL_RCC_TIM8_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN)

#define __HAL_RCC_USART1_CLK_DISABLE()         CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN)

#define __HAL_RCC_TIM15_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN)

#define __HAL_RCC_TIM16_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN)

#define __HAL_RCC_TIM17_CLK_DISABLE()          CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN)

#define __HAL_RCC_SAI1_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN)

#define __HAL_RCC_SAI2_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN)

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_DISABLE()           CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_DISABLE()            CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIHOSTEN)
#endif /* DSI */

/**
  * @}
  */

/** @defgroup RCC_APB3_Clock_Enable_Disable APB3 Peripheral Clock Enable Disable
  * @brief  Enable or disable the APB3 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_SYSCFGEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SYSCFGEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SPI3_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_SPI3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SPI3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPUART1_CLK_ENABLE()          do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_LPUART1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPUART1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_I2C3_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_I2C3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_I2C3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPTIM1_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM1EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM1EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPTIM3_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM3EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM3EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_LPTIM4_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM4EN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM4EN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_OPAMP_CLK_ENABLE()            do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_OPAMPEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_OPAMPEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_COMP_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_COMPEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_COMPEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_VREF_CLK_ENABLE()             do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_VREFEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_VREFEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_RTCAPB_CLK_ENABLE()           do { \
                                                 __IO uint32_t tmpreg; \
                                                 SET_BIT(RCC->APB3ENR, RCC_APB3ENR_RTCAPBEN); \
                                                 /* Delay after an RCC peripheral clock enabling */ \
                                                 tmpreg = READ_BIT(RCC->APB3ENR, RCC_APB3ENR_RTCAPBEN); \
                                                 UNUSED(tmpreg); \
                                               } while(0)

#define __HAL_RCC_SYSCFG_CLK_DISABLE()         CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_SYSCFGEN)

#define __HAL_RCC_SPI3_CLK_DISABLE()           CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_SPI3EN)

#define __HAL_RCC_LPUART1_CLK_DISABLE()        CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_LPUART1EN)

#define __HAL_RCC_I2C3_CLK_DISABLE()           CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_I2C3EN)

#define __HAL_RCC_LPTIM1_CLK_DISABLE()         CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM1EN)

#define __HAL_RCC_LPTIM3_CLK_DISABLE()         CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM3EN)

#define __HAL_RCC_LPTIM4_CLK_DISABLE()         CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM4EN)

#define __HAL_RCC_OPAMP_CLK_DISABLE()          CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_OPAMPEN)

#define __HAL_RCC_COMP_CLK_DISABLE()           CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_COMPEN)

#define __HAL_RCC_VREF_CLK_DISABLE()           CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_VREFEN)

#define __HAL_RCC_RTCAPB_CLK_DISABLE()         CLEAR_BIT(RCC->APB3ENR, RCC_APB3ENR_RTCAPBEN)

/**
  * @}
  */

/** @defgroup RCC_AHB1_Peripheral_Clock_Enable_Disable_Status AHB1 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the AHB1 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */
#define __HAL_RCC_GPDMA_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMAEN) != RESET)

#define __HAL_RCC_GPDMA_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMAEN) != RESET)

#define __HAL_RCC_MDF1_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_MDF1EN) != RESET)

#define __HAL_RCC_FLASH_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN) != RESET)

#define __HAL_RCC_CRC_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN) != RESET)

#define __HAL_RCC_TSC_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN) != RESET)

#define __HAL_RCC_DMA2D_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN) != RESET)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN) != RESET)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPU2DEN) != RESET)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GCACHEEN) != RESET)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GTZC1EN) != RESET)

#define __HAL_RCC_GPDMA_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMAEN) == RESET)

#define __HAL_RCC_GPDMA_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPDMAEN) == RESET)

#define __HAL_RCC_MDF1_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_MDF1EN) == RESET)

#define __HAL_RCC_FLASH_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_FLASHEN) == RESET)

#define __HAL_RCC_CRC_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_CRCEN) == RESET)

#define __HAL_RCC_TSC_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_TSCEN) == RESET)

#define __HAL_RCC_DMA2D_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_DMA2DEN) == RESET)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GFXMMUEN) == RESET)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPU2DEN) == RESET)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GCACHEEN) == RESET)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GTZC1EN) == RESET)
/**
  * @}
  */

/** @defgroup RCC_AHB2_Peripheral_Clock_Enable_Disable_Status AHB2 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the AHB2 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */

#define __HAL_RCC_GPIOA_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN) != RESET)

#define __HAL_RCC_GPIOB_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN) != RESET)

#define __HAL_RCC_GPIOC_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN) != RESET)

#define __HAL_RCC_GPIOD_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN) != RESET)

#define __HAL_RCC_GPIOE_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN) != RESET)

#define __HAL_RCC_GPIOF_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN) != RESET)

#define __HAL_RCC_GPIOG_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN) != RESET)

#define __HAL_RCC_GPIOH_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN) != RESET)

#define __HAL_RCC_GPIOI_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN) != RESET)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOJEN) != RESET)
#endif /* GPIOJ */

#define __HAL_RCC_ADC_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADC1EN) != RESET)

#define __HAL_RCC_DCMI_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN) != RESET)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_ENABLED()   (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN) != RESET)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_ENABLED()   (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGHSEN) != RESET)
#endif /* USB_OTG_HS */

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) != RESET);
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN) != RESET)
#endif /* HASH */

#define __HAL_RCC_RNG_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN) != RESET)

#define __HAL_RCC_PKA_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN) != RESET)

#define __HAL_RCC_SAES_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SAESEN) != RESET)

#define __HAL_RCC_OSPIM_IS_CLK_ENABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN) != RESET)

#define __HAL_RCC_OTFDEC1_IS_CLK_ENABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC1EN) != RESET)

#define __HAL_RCC_OTFDEC2_IS_CLK_ENABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC2EN) != RESET)

#define __HAL_RCC_SDMMC1_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN) != RESET)

#define __HAL_RCC_SDMMC2_IS_CLK_ENABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN) != RESET)


#define __HAL_RCC_GPIOA_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN) == RESET)

#define __HAL_RCC_GPIOB_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN) == RESET)

#define __HAL_RCC_GPIOC_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOCEN) == RESET)

#define __HAL_RCC_GPIOD_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIODEN) == RESET)

#define __HAL_RCC_GPIOE_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOEEN) == RESET)

#define __HAL_RCC_GPIOF_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN) == RESET)

#define __HAL_RCC_GPIOG_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOGEN) == RESET)

#define __HAL_RCC_GPIOH_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOHEN) == RESET)

#define __HAL_RCC_GPIOI_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOIEN) == RESET)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOJEN) == RESET)
#endif /* GPIOJ */

#define __HAL_RCC_ADC_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_ADC1EN) == RESET)

#define __HAL_RCC_DCMI_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_DCMIEN) == RESET)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_IS_CLK_DISABLED()  (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGFSEN) == RESET)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_IS_CLK_DISABLED()  (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTGHSEN) == RESET)
#endif /* USB_OTG_HS */

#if defined(AES)
#define __HAL_RCC_AES_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_AESEN) == RESET);
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_HASHEN) == RESET)
#endif /* HASH */

#define __HAL_RCC_RNG_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_RNGEN) == RESET)

#define __HAL_RCC_PKA_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_PKAEN) == RESET)

#define __HAL_RCC_SAES_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SAESEN) == RESET)

#define __HAL_RCC_OSPIM_IS_CLK_DISABLED()       (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OSPIMEN) == RESET)

#define __HAL_RCC_OTFDEC1_IS_CLK_DISABLED()     (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC1EN) == RESET)

#define __HAL_RCC_OTFDEC2_IS_CLK_DISABLED()     (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_OTFDEC2EN) == RESET)

#define __HAL_RCC_SDMMC1_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC1EN) == RESET)

#define __HAL_RCC_SDMMC2_IS_CLK_DISABLED()      (READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_SDMMC2EN) == RESET)

/**
  * @}
  */

/** @defgroup RCC_AHB4_Peripheral_Clock_Enable_Disable_Status AHB4 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the AHB4 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */



#define __HAL_RCC_FMC_IS_CLK_ENABLED()            (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_FMCEN) != RESET)

#define __HAL_RCC_OSPI1_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI1EN) != RESET)

#define __HAL_RCC_OSPI2_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI2EN) != RESET)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSPI1EN) != RESET)
#endif /* HSPI1 */

#define __HAL_RCC_FMC_IS_CLK_DISABLED()           (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_FMCEN) == RESET)

#define __HAL_RCC_OSPI1_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI1EN) == RESET)

#define __HAL_RCC_OSPI2_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_OSPI2EN) == RESET)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB4ENR, RCC_AHB4ENR_HSPI1EN) == RESET)
#endif /* HSPI1 */

/**
  * @}
  */

/** @defgroup RCC_AHB3_Peripheral_Clock_Enable_Disable_Status AHB3 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the AHB3 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */



#define __HAL_RCC_LPGPIO_IS_CLK_ENABLED()         (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPGPIOEN) != RESET)

#define __HAL_RCC_PWR_IS_CLK_ENABLED()            (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN) != RESET)

#define __HAL_RCC_ADC4_IS_CLK_ENABLED()           (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADC4EN) != RESET)

#define __HAL_RCC_DAC1_IS_CLK_ENABLED()           (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DAC1EN) != RESET)

#define __HAL_RCC_LPDMA_IS_CLK_ENABLED()          (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPDMAEN) != RESET)

#define __HAL_RCC_ADF1_IS_CLK_ENABLED()           (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADF1EN) != RESET)

#define __HAL_RCC_TZSC_IS_CLK_ENABLED()           (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_TZSCEN) != RESET)

#define __HAL_RCC_LPGPIO_IS_CLK_DISABLED()        (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPGPIOEN) == RESET)

#define __HAL_RCC_PWR_IS_CLK_DISABLED()           (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_PWREN) == RESET)

#define __HAL_RCC_ADC4_IS_CLK_DISABLED()          (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADC4EN) == RESET)

#define __HAL_RCC_DAC1_IS_CLK_DISABLED()          (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_DAC1EN) == RESET)

#define __HAL_RCC_LPDMA_IS_CLK_DISABLED()         (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_LPDMAEN) == RESET)

#define __HAL_RCC_ADF1_IS_CLK_DISABLED()          (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_ADF1EN) == RESET)

#define __HAL_RCC_TZSC_IS_CLK_DISABLED()          (READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_TZSCEN) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB1_Peripheral_Clock_Enable_Disable_Status APB1 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the APB1 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */


#define __HAL_RCC_TIM2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN) != RESET)

#define __HAL_RCC_TIM3_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN) != RESET)

#define __HAL_RCC_TIM4_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN) != RESET)

#define __HAL_RCC_TIM5_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN) != RESET)

#define __HAL_RCC_TIM6_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN) != RESET)

#define __HAL_RCC_TIM7_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN) != RESET)

#define __HAL_RCC_WWDG_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_WWDGEN) != RESET)

#define __HAL_RCC_SPI2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN) != RESET)

#define __HAL_RCC_USART2_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN) != RESET)

#define __HAL_RCC_USART3_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN) != RESET)

#define __HAL_RCC_UART4_IS_CLK_ENABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN) != RESET)

#define __HAL_RCC_UART5_IS_CLK_ENABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN) != RESET)

#define __HAL_RCC_I2C1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN) != RESET)

#define __HAL_RCC_I2C2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN) != RESET)

#define __HAL_RCC_CRS_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN) != RESET)

#if defined(USART6)
#define __HAL_RCC_USART6_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART6EN) != RESET)
#endif /* USART6 */

#define __HAL_RCC_I2C4_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN) != RESET)

#define __HAL_RCC_DTS_IS_CLK_ENABLED()         (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_DTSEN) != RESET)

#define __HAL_RCC_LPTIM2_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN) != RESET)

#if defined(I2C5)
#define __HAL_RCC_I2C5_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C5EN) != RESET)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C6EN) != RESET)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_FDCAN1EN) != RESET)

#define __HAL_RCC_UCPD_IS_CLK_ENABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_UCPDEN) != RESET)

#define __HAL_RCC_TIM2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM2EN) == RESET)

#define __HAL_RCC_TIM3_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM3EN) == RESET)

#define __HAL_RCC_TIM4_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM4EN) == RESET)

#define __HAL_RCC_TIM5_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM5EN) == RESET)

#define __HAL_RCC_TIM6_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM6EN) == RESET)

#define __HAL_RCC_TIM7_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_TIM7EN) == RESET)

#define __HAL_RCC_SPI2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_SPI2EN) == RESET)

#define __HAL_RCC_USART2_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART2EN) == RESET)

#define __HAL_RCC_USART3_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART3EN) == RESET)

#define __HAL_RCC_UART4_IS_CLK_DISABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART4EN) == RESET)

#define __HAL_RCC_UART5_IS_CLK_DISABLED()      (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_UART5EN) == RESET)

#define __HAL_RCC_I2C1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C1EN) == RESET)

#define __HAL_RCC_I2C2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_I2C2EN) == RESET)

#define __HAL_RCC_CRS_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_CRSEN) == RESET)

#if defined(USART6)
#define __HAL_RCC_USART6_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR1, RCC_APB1ENR1_USART6EN) == RESET)
#endif /* USART6 */

#define __HAL_RCC_I2C4_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C4EN) == RESET)

#define __HAL_RCC_DTS_IS_CLK_DISABLED()        (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_DTSEN) == RESET)

#define __HAL_RCC_LPTIM2_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_LPTIM2EN) == RESET)

#if defined(I2C5)
#define __HAL_RCC_I2C5_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C5EN) == RESET)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_I2C6EN) == RESET)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_FDCAN1EN) == RESET)

#define __HAL_RCC_UCPD_IS_CLK_DISABLED()       (READ_BIT(RCC->APB1ENR2, RCC_APB1ENR2_UCPDEN) == RESET)

/**
  * @}
  */

/** @defgroup RCC_APB2_Peripheral_Clock_Enable_Disable_Status APB2 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the APB2 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */


#define __HAL_RCC_TIM1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN) != RESET)

#define __HAL_RCC_SPI1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN) != RESET)

#define __HAL_RCC_TIM8_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN) != RESET)

#define __HAL_RCC_USART1_IS_CLK_ENABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN) != RESET)

#define __HAL_RCC_TIM15_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN) != RESET)

#define __HAL_RCC_TIM16_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN) != RESET)

#define __HAL_RCC_TIM17_IS_CLK_ENABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN) != RESET)

#define __HAL_RCC_SAI1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN) != RESET)

#define __HAL_RCC_SAI2_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN) != RESET)

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_ENABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN) != RESET)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_ENABLED()         (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIHOSTEN) != RESET)
#endif /* DSI */

#define __HAL_RCC_TIM1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM1EN) == RESET)

#define __HAL_RCC_SPI1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN) == RESET)

#define __HAL_RCC_TIM8_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM8EN) == RESET)

#define __HAL_RCC_USART1_IS_CLK_DISABLED()     (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_USART1EN) == RESET)

#define __HAL_RCC_TIM15_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM15EN) == RESET)

#define __HAL_RCC_TIM16_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM16EN) == RESET)

#define __HAL_RCC_TIM17_IS_CLK_DISABLED()      (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_TIM17EN) == RESET)

#define __HAL_RCC_SAI1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI1EN) == RESET)

#define __HAL_RCC_SAI2_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SAI2EN) == RESET)

#if defined(LTDC)
#define __HAL_RCC_LTDC_IS_CLK_DISABLED()       (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_LTDCEN) == RESET)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_IS_CLK_DISABLED()        (READ_BIT(RCC->APB2ENR, RCC_APB2ENR_DSIHOSTEN) == RESET)
#endif /* DSI */

/**
  * @}
  */

/** @defgroup RCC_APB3_Peripheral_Clock_Enable_Disable_Status APB3 Peripheral Clock Enabled or Disabled Status
  * @brief  Check whether the APB3 peripheral clock is enabled or not.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before
  *         using it.
  * @{
  */


#define __HAL_RCC_SYSCFG_IS_CLK_ENABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SYSCFGEN) != RESET)

#define __HAL_RCC_SPI3_IS_CLK_ENABLED()           (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SPI3EN) != RESET)

#define __HAL_RCC_LPUART1_IS_CLK_ENABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPUART1EN) != RESET)

#define __HAL_RCC_I2C3_IS_CLK_ENABLED()           (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_I2C3EN) != RESET)

#define __HAL_RCC_LPTIM1_IS_CLK_ENABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM1EN) != RESET)

#define __HAL_RCC_LPTIM3_IS_CLK_ENABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM3EN) != RESET)

#define __HAL_RCC_LPTIM4_IS_CLK_ENABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM4EN) != RESET)

#define __HAL_RCC_OPAMP_IS_CLK_ENABLED()          (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_OPAMPEN) != RESET)

#define __HAL_RCC_COMP_IS_CLK_ENABLED()           (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_COMPEN) != RESET)

#define __HAL_RCC_VREF_IS_CLK_ENABLED()           (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_VREFEN) != RESET)

#define __HAL_RCC_RTCAPB_IS_CLK_ENABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_RTCAPBEN) != RESET)

#define __HAL_RCC_SYSCFG_IS_CLK_DISABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SYSCFGEN) == RESET)

#define __HAL_RCC_SPI3_IS_CLK_DISABLED()          (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_SPI3EN) == RESET)

#define __HAL_RCC_LPUART1_IS_CLK_DISABLED()       (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPUART1EN) == RESET)

#define __HAL_RCC_I2C3_IS_CLK_DISABLED()          (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_I2C3EN) == RESET)

#define __HAL_RCC_LPTIM1_IS_CLK_DISABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM1EN) == RESET)

#define __HAL_RCC_LPTIM3_IS_CLK_DISABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM3EN) == RESET)

#define __HAL_RCC_LPTIM4_IS_CLK_DISABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_LPTIM4EN) == RESET)

#define __HAL_RCC_OPAMP_IS_CLK_DISABLED()         (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_OPAMPEN) == RESET)

#define __HAL_RCC_COMP_IS_CLK_DISABLED()          (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_COMPEN) == RESET)

#define __HAL_RCC_VREF_IS_CLK_DISABLED()          (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_VREFEN) == RESET)

#define __HAL_RCC_RTCAPB_IS_CLK_DISABLED()        (READ_BIT(RCC->APB3ENR, RCC_APB3ENR_RTCAPBEN) == RESET)


/**
  * @}
  */

/** @defgroup RCC_AHB1_Force_Release_Reset AHB1 Peripheral Force Release Reset
  * @brief  Force or release AHB1 peripheral reset.
  * @{
  */

#define __HAL_RCC_AHB1_FORCE_RESET()      WRITE_REG(RCC->AHB1RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_GPDMA_FORCE_RESET()     SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPDMA1RST)

#define __HAL_RCC_CORDIC_FORCE_RESET()    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CORDICRST)

#define __HAL_RCC_FMAC_FORCE_RESET()      SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FMACRST)

#define __HAL_RCC_MDF1_FORCE_RESET()      SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_MDF1RST)

#define __HAL_RCC_FLASH_FORCE_RESET()     SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FLASHRST)

#define __HAL_RCC_CRC_FORCE_RESET()       SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CRCRST)

#define __HAL_RCC_TSC_FORCE_RESET()       SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_TSCRST)

#define __HAL_RCC_RAMCFG_FORCE_RESET()    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_RAMCFGRST)

#define __HAL_RCC_DMA2D_FORCE_RESET()     SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2DRST)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_FORCE_RESET()    SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GFXMMURST)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_FORCE_RESET()     SET_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPU2DRST)
#endif /* GPU2D */

#define __HAL_RCC_AHB1_RELEASE_RESET()    WRITE_REG(RCC->AHB1RSTR, 0x00000000U)

#define __HAL_RCC_GPDMA_RELEASE_RESET()   CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPDMA1RST)

#define __HAL_RCC_CORDIC_RELEASE_RESET()   CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CORDICRST)

#define __HAL_RCC_FMAC_RELEASE_RESET()     CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FMACRST)

#define __HAL_RCC_MDF1_RELEASE_RESET()    CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_MDF1RST)

#define __HAL_RCC_FLASH_RELEASE_RESET()   CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_FLASHRST)

#define __HAL_RCC_CRC_RELEASE_RESET()     CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_CRCRST)

#define __HAL_RCC_TSC_RELEASE_RESET()     CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_TSCRST)

#define __HAL_RCC_RAMCFG_RELEASE_RESET()  CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_RAMCFGRST)

#define __HAL_RCC_DMA2D_RELEASE_RESET()   CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_DMA2DRST)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_RELEASE_RESET()  CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GFXMMURST)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_RELEASE_RESET()   CLEAR_BIT(RCC->AHB1RSTR, RCC_AHB1RSTR_GPU2DRST)
#endif /* GPU2D */

/**
  * @}
  */

/** @defgroup RCC_AHB2_Force_Release_Reset AHB2 Peripheral Force Release Reset
  * @brief  Force or release AHB2 peripheral reset.
  * @{
  */

#define __HAL_RCC_AHB2_FORCE_RESET()      WRITE_REG(RCC->AHB2RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_GPIOA_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOARST)

#define __HAL_RCC_GPIOB_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOBRST)

#define __HAL_RCC_GPIOC_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOCRST)

#define __HAL_RCC_GPIOD_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIODRST)

#define __HAL_RCC_GPIOE_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOERST)

#define __HAL_RCC_GPIOF_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOFRST)

#define __HAL_RCC_GPIOG_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOGRST)

#define __HAL_RCC_GPIOH_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOHRST)

#define __HAL_RCC_GPIOI_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOIRST)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOJRST)
#endif /* GPIOJ */

#define __HAL_RCC_ADC1_FORCE_RESET()      SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_ADC1RST)

#define __HAL_RCC_DCMI_FORCE_RESET()      SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_DCMI_PSSIRST)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_FORCE_RESET() SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGFSRST)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_FORCE_RESET() SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGHSRST)
#endif /* USB_OTG_HS */

#define __HAL_RCC_AES_FORCE_RESET()       SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_AESRST)

#define __HAL_RCC_HASH_FORCE_RESET()      SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_HASHRST)

#define __HAL_RCC_RNG_FORCE_RESET()       SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_RNGRST)

#define __HAL_RCC_PKA_FORCE_RESET()       SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_PKARST)

#define __HAL_RCC_SAES_FORCE_RESET()      SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SAESRST)

#define __HAL_RCC_OSPIM_FORCE_RESET()     SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OSPIMRST)

#define __HAL_RCC_OTFDEC1_FORCE_RESET()   SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTFDEC1RST)

#define __HAL_RCC_OTFDEC2_FORCE_RESET()   SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTFDEC2RST)

#define __HAL_RCC_SDMMC1_FORCE_RESET()    SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC1RST)

#define __HAL_RCC_SDMMC2_FORCE_RESET()    SET_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC2RST)

#define __HAL_RCC_AHB2_RELEASE_RESET()    WRITE_REG(RCC->AHB2RSTR, 0x00000000U)

#define __HAL_RCC_GPIOA_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOARST)

#define __HAL_RCC_GPIOB_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOBRST)

#define __HAL_RCC_GPIOC_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOCRST)

#define __HAL_RCC_GPIOD_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIODRST)

#define __HAL_RCC_GPIOE_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOERST)

#define __HAL_RCC_GPIOF_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOFRST)

#define __HAL_RCC_GPIOG_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOGRST)

#define __HAL_RCC_GPIOH_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOHRST)

#define __HAL_RCC_GPIOI_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOIRST)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_GPIOJRST)
#endif /* GPIOJ */

#define __HAL_RCC_ADC1_RELEASE_RESET()    CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_ADC1RST)

#define __HAL_RCC_DCMI_RELEASE_RESET()    CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_DCMI_PSSIRST)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_RELEASE_RESET() CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGFSRST)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_RELEASE_RESET() CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTGHSRST)
#endif /* USB_OTG_HS */

#define __HAL_RCC_AES_RELEASE_RESET()     CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_AESRST)

#define __HAL_RCC_HASH_RELEASE_RESET()    CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_HASHRST)

#define __HAL_RCC_RNG_RELEASE_RESET()     CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_RNGRST)

#define __HAL_RCC_PKA_RELEASE_RESET()     CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_PKARST)

#define __HAL_RCC_SAES_RELEASE_RESET()    CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SAESRST)

#define __HAL_RCC_OSPIM_RELEASE_RESET()   CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OSPIMRST)

#define __HAL_RCC_OTFDEC1_RELEASE_RESET() CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTFDEC1RST)

#define __HAL_RCC_OTFDEC2_RELEASE_RESET() CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_OTFDEC2RST)

#define __HAL_RCC_SDMMC1_RELEASE_RESET()  CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC1RST)

#define __HAL_RCC_SDMMC2_RELEASE_RESET()  CLEAR_BIT(RCC->AHB2RSTR, RCC_AHB2RSTR_SDMMC2RST)



/**
  * @}
  */

/** @defgroup RCC_AHB4_Force_Release_Reset AHB4 Peripheral Force Release Reset
  * @brief  Force or release AHB4 peripheral reset.
  * @{
  */

#define __HAL_RCC_AHB4_FORCE_RESET()      WRITE_REG(RCC->AHB4RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_FMC_FORCE_RESET()       SET_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_FMCRST)

#define __HAL_RCC_OSPI1_FORCE_RESET()     SET_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_OSPI1RST)

#define __HAL_RCC_OSPI2_FORCE_RESET()     SET_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_OSPI2RST)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_FORCE_RESET()     SET_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_HSPI1RST)
#endif /* HSPI1 */

#define __HAL_RCC_AHB4_RELEASE_RESET()    WRITE_REG(RCC->AHB4RSTR, 0x00000000U)

#define __HAL_RCC_FMC_RELEASE_RESET()     CLEAR_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_FMCRST)

#define __HAL_RCC_OSPI1_RELEASE_RESET()   CLEAR_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_OSPI1RST)

#define __HAL_RCC_OSPI2_RELEASE_RESET()   CLEAR_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_OSPI2RST)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_RELEASE_RESET()   CLEAR_BIT(RCC->AHB4RSTR, RCC_AHB4RSTR_HSPI1RST)
#endif /* HSPI1 */

/**
  * @}
  */

/** @defgroup RCC_AHB3_Force_Release_Reset AHB3 Peripheral Force Release Reset
  * @brief  Force or release AHB3 peripheral reset.
  * @{
  */

#define __HAL_RCC_AHB3_FORCE_RESET()         WRITE_REG(RCC->AHB3RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_LPGPIO_FORCE_RESET()       SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_LPGPIORST)

#define __HAL_RCC_ADC4_FORCE_RESET()         SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_ADC4RST)

#define __HAL_RCC_DAC1_FORCE_RESET()         SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_DAC1RST)

#define __HAL_RCC_LPDMA_FORCE_RESET()        SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_LPDMA1RST)

#define __HAL_RCC_ADF1_FORCE_RESET()         SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_ADF1RST)

#define __HAL_RCC_GTZC2_FORCE_RESET()        SET_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_GTZC2RST)

#define __HAL_RCC_AHB3_RELEASE_RESET()       WRITE_REG(RCC->AHB3RSTR, 0x00000000U)

#define __HAL_RCC_LPGPIO_RELEASE_RESET()     CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_LPGPIORST)

#define __HAL_RCC_ADC4_RELEASE_RESET()       CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_ADC4RST)

#define __HAL_RCC_DAC1_RELEASE_RESET()       CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_DAC1RST)

#define __HAL_RCC_LPDMA_RELEASE_RESET()      CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_LPDMA1RST)

#define __HAL_RCC_ADF1_RELEASE_RESET()       CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_ADF1RST)

#define __HAL_RCC_GTZC2_RELEASE_RESET()      CLEAR_BIT(RCC->AHB3RSTR, RCC_AHB3RSTR_GTZC2RST)


/**
  * @}
  */

/** @defgroup RCC_APB1_Force_Release_Reset APB1 Peripheral Force Release Reset
  * @brief  Force or release APB1 peripheral reset.
  * @{
  */

#define __HAL_RCC_APB1_FORCE_RESET()     do { \
                                                 WRITE_REG(RCC->APB1RSTR1, 0xFFFFFFFFU); \
                                                   WRITE_REG(RCC->APB1RSTR2, 0xFFFFFFFFU); \
                                               } while(0)

#define __HAL_RCC_TIM2_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM2RST)

#define __HAL_RCC_TIM3_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM3RST)

#define __HAL_RCC_TIM4_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM4RST)

#define __HAL_RCC_TIM5_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM5RST)

#define __HAL_RCC_TIM6_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM6RST)

#define __HAL_RCC_TIM7_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM7RST)

#define __HAL_RCC_SPI2_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI2RST)

#define __HAL_RCC_USART2_FORCE_RESET()   SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART2RST)

#define __HAL_RCC_USART3_FORCE_RESET()   SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART3RST)

#define __HAL_RCC_UART4_FORCE_RESET()    SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART4RST)

#define __HAL_RCC_UART5_FORCE_RESET()    SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART5RST)

#define __HAL_RCC_I2C1_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C1RST)

#define __HAL_RCC_I2C2_FORCE_RESET()     SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C2RST)

#define __HAL_RCC_CRS_FORCE_RESET()      SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CRSRST)

#if defined(USART6)
#define __HAL_RCC_USART6_FORCE_RESET()   SET_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART6RST)
#endif /* USART6 */

#define __HAL_RCC_I2C4_FORCE_RESET()     SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C4RST)

#define __HAL_RCC_DTS_FORCE_RESET()      SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_DTSRST)

#define __HAL_RCC_LPTIM2_FORCE_RESET()   SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPTIM2RST)

#if defined(I2C5)
#define __HAL_RCC_I2C5_FORCE_RESET()     SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C5RST)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_FORCE_RESET()     SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C6RST)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_FORCE_RESET()   SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_FDCAN1RST)

#define __HAL_RCC_UCPD_FORCE_RESET()     SET_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_UCPD1RST)

#define __HAL_RCC_APB1_RELEASE_RESET()   do { \
                                                 WRITE_REG(RCC->APB1RSTR1, 0x00000000U); \
                                                   WRITE_REG(RCC->APB1RSTR2, 0x00000000U); \
                                               } while(0)

#define __HAL_RCC_TIM2_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM2RST)

#define __HAL_RCC_TIM3_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM3RST)

#define __HAL_RCC_TIM4_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM4RST)

#define __HAL_RCC_TIM5_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM5RST)

#define __HAL_RCC_TIM6_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM6RST)

#define __HAL_RCC_TIM7_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_TIM7RST)

#define __HAL_RCC_SPI2_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_SPI2RST)

#define __HAL_RCC_USART2_RELEASE_RESET()  CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART2RST)

#define __HAL_RCC_USART3_RELEASE_RESET()  CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART3RST)

#define __HAL_RCC_UART4_RELEASE_RESET()   CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART4RST)

#define __HAL_RCC_UART5_RELEASE_RESET()   CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_UART5RST)

#define __HAL_RCC_I2C1_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C1RST)

#define __HAL_RCC_I2C2_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_I2C2RST)

#define __HAL_RCC_CRS_RELEASE_RESET()     CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_CRSRST)

#if defined(USART6)
#define __HAL_RCC_USART6_RELEASE_RESET()  CLEAR_BIT(RCC->APB1RSTR1, RCC_APB1RSTR1_USART6RST)
#endif /* USART6 */

#define __HAL_RCC_I2C4_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C4RST)

#define __HAL_RCC_DTS_RELEASE_RESET()     CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_DTSRST)

#define __HAL_RCC_LPTIM2_RELEASE_RESET()  CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_LPTIM2RST)

#if defined(I2C5)
#define __HAL_RCC_I2C5_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C5RST)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_I2C6RST)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_RELEASE_RESET()  CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_FDCAN1RST)

#define __HAL_RCC_UCPD_RELEASE_RESET()    CLEAR_BIT(RCC->APB1RSTR2, RCC_APB1RSTR2_UCPD1RST)


/**
  * @}
  */

/** @defgroup RCC_APB2_Force_Release_Reset APB2 Peripheral Force Release Reset
  * @brief  Force or release APB2 peripheral reset.
  * @{
  */

#define __HAL_RCC_APB2_FORCE_RESET()          WRITE_REG(RCC->APB2RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_TIM1_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM1RST)

#define __HAL_RCC_SPI1_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SPI1RST)

#define __HAL_RCC_TIM8_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM8RST)

#define __HAL_RCC_USART1_FORCE_RESET()        SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST)

#define __HAL_RCC_TIM15_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM15RST)

#define __HAL_RCC_TIM16_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM16RST)

#define __HAL_RCC_TIM17_FORCE_RESET()         SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM17RST)

#define __HAL_RCC_SAI1_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI1RST)

#define __HAL_RCC_SAI2_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI2RST)

#if defined(LTDC)
#define __HAL_RCC_LTDC_FORCE_RESET()          SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_LTDCRST)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_FORCE_RESET()           SET_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DSIHOSTRST)
#endif /* DSI */

#define __HAL_RCC_APB2_RELEASE_RESET()        WRITE_REG(RCC->APB2RSTR, 0x00000000U)

#define __HAL_RCC_TIM1_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM1RST)

#define __HAL_RCC_SPI1_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SPI1RST)

#define __HAL_RCC_TIM8_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM8RST)

#define __HAL_RCC_USART1_RELEASE_RESET()      CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_USART1RST)

#define __HAL_RCC_TIM15_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM15RST)

#define __HAL_RCC_TIM16_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM16RST)

#define __HAL_RCC_TIM17_RELEASE_RESET()       CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_TIM17RST)

#define __HAL_RCC_SAI1_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI1RST)

#define __HAL_RCC_SAI2_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_SAI2RST)

#if defined(LTDC)
#define __HAL_RCC_LTDC_RELEASE_RESET()        CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_LTDCRST)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_RELEASE_RESET()         CLEAR_BIT(RCC->APB2RSTR, RCC_APB2RSTR_DSIHOSTRST)
#endif /* DSI */


/**
  * @}
  */

/** @defgroup RCC_APB3_Force_Release_Reset APB3 Peripheral Force Release Reset
  * @brief  Force or release APB3 peripheral reset.
  * @{
  */

#define __HAL_RCC_APB3_FORCE_RESET()        WRITE_REG(RCC->APB3RSTR, 0xFFFFFFFFU)

#define __HAL_RCC_SYSCFG_FORCE_RESET()         SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_SYSCFGRST)

#define __HAL_RCC_SPI3_FORCE_RESET()           SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_SPI3RST)

#define __HAL_RCC_LPUART1_FORCE_RESET()        SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPUART1RST)

#define __HAL_RCC_I2C3_FORCE_RESET()           SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_I2C3RST)

#define __HAL_RCC_LPTIM1_FORCE_RESET()         SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM1RST)

#define __HAL_RCC_LPTIM3_FORCE_RESET()         SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM3RST)

#define __HAL_RCC_LPTIM4_FORCE_RESET()         SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM4RST)

#define __HAL_RCC_OPAMP_FORCE_RESET()          SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_OPAMPRST)

#define __HAL_RCC_COMP_FORCE_RESET()           SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_COMPRST)

#define __HAL_RCC_VREF_FORCE_RESET()           SET_BIT(RCC->APB3RSTR, RCC_APB3RSTR_VREFRST)

#define __HAL_RCC_APB3_RELEASE_RESET()      WRITE_REG(RCC->APB3RSTR, 0x00000000U)

#define __HAL_RCC_SYSCFG_RELEASE_RESET()       CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_SYSCFGRST)

#define __HAL_RCC_SPI3_RELEASE_RESET()         CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_SPI3RST)

#define __HAL_RCC_LPUART1_RELEASE_RESET()      CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPUART1RST)

#define __HAL_RCC_I2C3_RELEASE_RESET()         CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_I2C3RST)

#define __HAL_RCC_LPTIM1_RELEASE_RESET()       CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM1RST)

#define __HAL_RCC_LPTIM3_RELEASE_RESET()       CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM3RST)

#define __HAL_RCC_LPTIM4_RELEASE_RESET()       CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_LPTIM4RST)

#define __HAL_RCC_OPAMP_RELEASE_RESET()        CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_OPAMPRST)

#define __HAL_RCC_COMP_RELEASE_RESET()         CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_COMPRST)

#define __HAL_RCC_VREF_RELEASE_RESET()         CLEAR_BIT(RCC->APB3RSTR, RCC_APB3RSTR_VREFRST)

/* Exported macros -----------------------------------------------------------*/

/** @defgroup RCC_Exported_Macros RCC Exported Macros
  * @{
  */

/** @defgroup RCC_AHB1_Peripheral_Clock_Sleep_Enable_Disable AHB1 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the AHB1 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */


#define __HAL_RCC_GPDMA_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GPDMA1SMEN)

#define __HAL_RCC_CORDIC_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CORDICSMEN)

#define __HAL_RCC_FMAC_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FMACSMEN)

#define __HAL_RCC_MDF1_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_MDF1SMEN)

#define __HAL_RCC_FLASH_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN)

#define __HAL_RCC_CRC_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN)

#define __HAL_RCC_TSC_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN)

#define __HAL_RCC_DMA2D_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GPU2DSMEN)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GCACHESMEN)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GTZC1SMEN)

#define __HAL_RCC_BKPSRAM_CLK_SLEEP_ENABLE()        SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_BKPSRAMSMEN)

#define __HAL_RCC_ICACHE_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_ICACHESMEN)

#define __HAL_RCC_DCACHE_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DCACHESMEN)

#define __HAL_RCC_SRAM1_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN)

#define __HAL_RCC_GPDMA_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GPDMA1SMEN)

#define __HAL_RCC_CORDIC_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CORDICSMEN)

#define __HAL_RCC_FMAC_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FMACSMEN)

#define __HAL_RCC_MDF1_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_MDF1SMEN)

#define __HAL_RCC_FLASH_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_FLASHSMEN)

#define __HAL_RCC_CRC_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_CRCSMEN)

#define __HAL_RCC_TSC_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_TSCSMEN)

#define __HAL_RCC_DMA2D_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DMA2DSMEN)

#if defined(GFXMMU)
#define __HAL_RCC_GFXMMU_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GFXMMUSMEN)
#endif /* GFXMMU */

#if defined(GPU2D)
#define __HAL_RCC_GPU2D_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GPU2DSMEN)
#endif /* GPU2D */

#if defined(GCACHE)
#define __HAL_RCC_GCACHE_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GCACHESMEN)
#endif /* GCACHE */

#define __HAL_RCC_GTZC1_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_GTZC1SMEN)

#define __HAL_RCC_BKPSRAM_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_BKPSRAMSMEN)

#define __HAL_RCC_ICACHE_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_ICACHESMEN)

#define __HAL_RCC_DCACHE_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_DCACHESMEN)

#define __HAL_RCC_SRAM1_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB1SMENR, RCC_AHB1SMENR_SRAM1SMEN)

/**
  * @}
  */

/** @defgroup RCC_AHB2_Peripheral_Clock_Sleep_Enable_Disable AHB2 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the AHB2 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */

#define __HAL_RCC_GPIOA_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN)

#define __HAL_RCC_GPIOB_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN)

#define __HAL_RCC_GPIOC_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN)

#define __HAL_RCC_GPIOD_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN)

#define __HAL_RCC_GPIOE_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN)

#define __HAL_RCC_GPIOF_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN)

#define __HAL_RCC_GPIOG_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN)

#define __HAL_RCC_GPIOH_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN)

#define __HAL_RCC_GPIOI_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOJSMEN)
#endif /* GPIOJ */

#define __HAL_RCC_ADC_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADC1SMEN)

#define __HAL_RCC_DCMI_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMI_PSSISMEN)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_ENABLE()     SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGHSSMEN)
#endif /* USB_OTG_HS */

#if defined(AES)
#define __HAL_RCC_AES_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN);
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN)
#endif /* HASH */

#define __HAL_RCC_RNG_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN)

#define __HAL_RCC_PKA_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN)

#define __HAL_RCC_SAES_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SAESSMEN)

#define __HAL_RCC_OSPIM_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN)

#define __HAL_RCC_OTFDEC1_CLK_SLEEP_ENABLE()        SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTFDEC1SMEN)

#define __HAL_RCC_OTFDEC2_CLK_SLEEP_ENABLE()        SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTFDEC2SMEN)

#define __HAL_RCC_SDMMC1_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN)

#define __HAL_RCC_SDMMC2_CLK_SLEEP_ENABLE()         SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN)

#define __HAL_RCC_SRAM2_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN)

#define __HAL_RCC_SRAM3_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN)

#define __HAL_RCC_GPIOA_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOASMEN)

#define __HAL_RCC_GPIOB_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOBSMEN)

#define __HAL_RCC_GPIOC_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOCSMEN)

#define __HAL_RCC_GPIOD_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIODSMEN)

#define __HAL_RCC_GPIOE_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOESMEN)

#define __HAL_RCC_GPIOF_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOFSMEN)

#define __HAL_RCC_GPIOG_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOGSMEN)

#define __HAL_RCC_GPIOH_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOHSMEN)

#define __HAL_RCC_GPIOI_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOISMEN)

#if defined(GPIOJ)
#define __HAL_RCC_GPIOJ_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_GPIOJSMEN)
#endif /* GPIOJ */

#define __HAL_RCC_ADC_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_ADC1SMEN)

#define __HAL_RCC_DCMI_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_DCMI_PSSISMEN)

#if defined(USB_OTG_FS)
#define __HAL_RCC_USB_OTG_FS_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGFSSMEN)
#endif /* USB_OTG_FS */

#if defined(USB_OTG_HS)
#define __HAL_RCC_USB_OTG_HS_CLK_SLEEP_DISABLE()    CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTGHSSMEN)
#endif /* USB_OTG_HS */

#if defined(AES)
#define __HAL_RCC_AES_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_AESSMEN);
#endif /* AES */

#if defined(HASH)
#define __HAL_RCC_HASH_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_HASHSMEN)
#endif /* HASH */

#define __HAL_RCC_RNG_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_RNGSMEN)

#define __HAL_RCC_PKA_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_PKASMEN)

#define __HAL_RCC_SAES_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SAESSMEN)

#define __HAL_RCC_OSPIM_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OSPIMSMEN)

#define __HAL_RCC_OTFDEC1_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTFDEC1SMEN)

#define __HAL_RCC_OTFDEC2_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_OTFDEC2SMEN)

#define __HAL_RCC_SDMMC1_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC1SMEN)

#define __HAL_RCC_SDMMC2_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SDMMC2SMEN)

#define __HAL_RCC_SRAM2_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM2SMEN)

#define __HAL_RCC_SRAM3_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB2SMENR, RCC_AHB2SMENR_SRAM3SMEN)

/**
  * @}
  */

/** @defgroup RCC_AHB4_Clock_Sleep_Enable_Disable AHB4 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the AHB4 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */

#define __HAL_RCC_FMC_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_FMCSMEN)

#define __HAL_RCC_OSPI1_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_OSPI1SMEN)

#define __HAL_RCC_OSPI2_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_OSPI2SMEN)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_HSPI1SMEN)
#endif /* HSPI1 */

#if defined(SRAM5_BASE)
#define __HAL_RCC_SRAM5_CLK_SLEEP_ENABLE()          SET_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_SRAM5SMEN)
#endif /* SRAM5_BASE */

#define __HAL_RCC_FMC_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_FMCSMEN)

#define __HAL_RCC_OSPI1_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_OSPI1SMEN)

#define __HAL_RCC_OSPI2_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_OSPI2SMEN)

#if defined(HSPI1)
#define __HAL_RCC_HSPI1_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_HSPI1SMEN)
#endif /* HSPI1 */

#if defined(SRAM5_BASE)
#define __HAL_RCC_SRAM5_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->AHB4SMENR, RCC_AHB4SMENR_SRAM5SMEN)
#endif /* SRAM5_BASE */

/**
  * @}
  */

/** @defgroup RCC_AHB3_Clock_Sleep_Enable_Disable AHB3SMENR Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the AHB3SMENR peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */

#define __HAL_RCC_LPGPIO_CLK_SLEEP_ENABLE()           SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_LPGPIOSMEN)

#define __HAL_RCC_PWR_CLK_SLEEP_ENABLE()              SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_PWRSMEN)

#define __HAL_RCC_ADC4_CLK_SLEEP_ENABLE()             SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_ADC4SMEN)

#define __HAL_RCC_DAC1_CLK_SLEEP_ENABLE()             SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_DAC1SMEN)

#define __HAL_RCC_LPDMA_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_LPDMA1SMEN)

#define __HAL_RCC_ADF1_CLK_SLEEP_ENABLE()             SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_ADF1SMEN)

#define __HAL_RCC_GTZC2_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_GTZC2SMEN)

#define __HAL_RCC_SRAM4_CLK_SLEEP_ENABLE()            SET_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_SRAM4SMEN)

#define __HAL_RCC_LPGPIO_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_LPGPIOSMEN)

#define __HAL_RCC_PWR_CLK_SLEEP_DISABLE()             CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_PWRSMEN)

#define __HAL_RCC_ADC4_CLK_SLEEP_DISABLE()            CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_ADC4SMEN)

#define __HAL_RCC_DAC1_CLK_SLEEP_DISABLE()            CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_DAC1SMEN)

#define __HAL_RCC_LPDMA_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_LPDMA1SMEN)

#define __HAL_RCC_ADF1_CLK_SLEEP_DISABLE()            CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_ADF1SMEN)

#define __HAL_RCC_GTZC2_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_GTZC2SMEN)

#define __HAL_RCC_SRAM4_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->AHB3SMENR, RCC_AHB3SMENR_SRAM4SMEN)

/**
  * @}
  */

/** @defgroup RCC_APB1_Clock_Sleep_Enable_Disable APB1 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the APB1 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */

#define __HAL_RCC_TIM2_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN)

#define __HAL_RCC_TIM3_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN)

#define __HAL_RCC_TIM4_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN)

#define __HAL_RCC_TIM5_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN)

#define __HAL_RCC_TIM6_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN)

#define __HAL_RCC_TIM7_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN)

#define __HAL_RCC_WWDG_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN)

#define __HAL_RCC_SPI2_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN)

#define __HAL_RCC_USART2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN)

#define __HAL_RCC_USART3_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN)

#define __HAL_RCC_UART4_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN)

#define __HAL_RCC_UART5_CLK_SLEEP_ENABLE()       SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN)

#define __HAL_RCC_I2C1_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN)

#define __HAL_RCC_I2C2_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN)

#define __HAL_RCC_CRS_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN)

#if defined(USART6)
#define __HAL_RCC_USART6_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART6SMEN)
#endif /* USART6 */

#define __HAL_RCC_I2C4_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN)

#define __HAL_RCC_DTS_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_DTSSMEN)

#define __HAL_RCC_LPTIM2_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN)

#if defined(I2C5)
#define __HAL_RCC_I2C5_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C5SMEN)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C6SMEN)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_CLK_SLEEP_ENABLE()      SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_FDCAN1SMEN)

#define __HAL_RCC_UCPD_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_UCPDSMEN)

#define __HAL_RCC_TIM2_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM2SMEN)

#define __HAL_RCC_TIM3_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM3SMEN)

#define __HAL_RCC_TIM4_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM4SMEN)

#define __HAL_RCC_TIM5_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM5SMEN)

#define __HAL_RCC_TIM6_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM6SMEN)

#define __HAL_RCC_TIM7_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_TIM7SMEN)

#define __HAL_RCC_WWDG_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_WWDGSMEN)

#define __HAL_RCC_SPI2_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_SPI2SMEN)

#define __HAL_RCC_USART2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART2SMEN)

#define __HAL_RCC_USART3_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART3SMEN)

#define __HAL_RCC_UART4_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART4SMEN)

#define __HAL_RCC_UART5_CLK_SLEEP_DISABLE()      CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_UART5SMEN)

#define __HAL_RCC_I2C1_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C1SMEN)

#define __HAL_RCC_I2C2_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_I2C2SMEN)

#define __HAL_RCC_CRS_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_CRSSMEN)

#if defined(USART6)
#define __HAL_RCC_USART6_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR1, RCC_APB1SMENR1_USART6SMEN)
#endif /* USART6 */

#define __HAL_RCC_I2C4_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C4SMEN)

#define __HAL_RCC_DTS_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_DTSSMEN)

#define __HAL_RCC_LPTIM2_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_LPTIM2SMEN)

#if defined(I2C5)
#define __HAL_RCC_I2C5_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C5SMEN)
#endif /* I2C5 */

#if defined(I2C6)
#define __HAL_RCC_I2C6_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_I2C6SMEN)
#endif /* I2C6 */

#define __HAL_RCC_FDCAN1_CLK_SLEEP_DISABLE()     CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_FDCAN1SMEN)

#define __HAL_RCC_UCPD_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB1SMENR2, RCC_APB1SMENR2_UCPDSMEN)

/**
  * @}
  */

/** @defgroup RCC_APB2_Clock_Sleep_Enable_Disable APB2 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the APB2 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */
#define __HAL_RCC_TIM1_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN)

#define __HAL_RCC_SPI1_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN)

#define __HAL_RCC_TIM8_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN)

#define __HAL_RCC_USART1_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN)

#define __HAL_RCC_TIM15_CLK_SLEEP_ENABLE()          SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN)

#define __HAL_RCC_TIM16_CLK_SLEEP_ENABLE()          SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN)

#define __HAL_RCC_TIM17_CLK_SLEEP_ENABLE()          SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN)

#define __HAL_RCC_SAI1_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN)

#define __HAL_RCC_SAI2_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN)

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_SLEEP_ENABLE()            SET_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSIHOSTSMEN)
#endif /* DSI */

#define __HAL_RCC_TIM1_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM1SMEN)

#define __HAL_RCC_SPI1_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SPI1SMEN)

#define __HAL_RCC_TIM8_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM8SMEN)

#define __HAL_RCC_USART1_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_USART1SMEN)

#define __HAL_RCC_TIM15_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM15SMEN)

#define __HAL_RCC_TIM16_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM16SMEN)

#define __HAL_RCC_TIM17_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_TIM17SMEN)

#define __HAL_RCC_SAI1_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI1SMEN)

#define __HAL_RCC_SAI2_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_SAI2SMEN)

#if defined(LTDC)
#define __HAL_RCC_LTDC_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_LTDCSMEN)
#endif /* LTDC */

#if defined(DSI)
#define __HAL_RCC_DSI_CLK_SLEEP_DISABLE()           CLEAR_BIT(RCC->APB2SMENR, RCC_APB2SMENR_DSIHOSTSMEN)
#endif /* DSI */

/**
  * @}
  */

/** @defgroup RCC_APB3_Clock_Sleep_Enable_Disable APB3 Peripheral Clock Sleep Enable Disable
  * @brief  Enable or disable the APB3 peripheral clock during Low Power (Sleep) mode.
  * @note   After wakeup from SLEEP mode, the peripheral clock is enabled again.
  * @note   By default, all peripheral clocks are enabled during SLEEP mode.
  * @{
  */
#define __HAL_RCC_SYSCFG_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_SYSCFGSMEN)

#define __HAL_RCC_SPI3_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_SPI3SMEN)

#define __HAL_RCC_LPUART1_CLK_SLEEP_ENABLE()        SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPUART1SMEN)

#define __HAL_RCC_I2C3_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_I2C3SMEN)

#define __HAL_RCC_LPTIM1_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM1SMEN)

#define __HAL_RCC_LPTIM3_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM3SMEN)

#define __HAL_RCC_LPTIM4_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM4SMEN)

#define __HAL_RCC_OPAMP_CLK_SLEEP_ENABLE()          SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_OPAMPSMEN)

#define __HAL_RCC_COMP_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_COMPSMEN)

#define __HAL_RCC_VREF_CLK_SLEEP_ENABLE()           SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_VREFSMEN)

#define __HAL_RCC_RTCAPB_CLK_SLEEP_ENABLE()         SET_BIT(RCC->APB3SMENR, RCC_APB3SMENR_RTCAPBSMEN)

#define __HAL_RCC_SYSCFG_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_SYSCFGSMEN)

#define __HAL_RCC_SPI3_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_SPI3SMEN)

#define __HAL_RCC_LPUART1_CLK_SLEEP_DISABLE()       CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPUART1SMEN)

#define __HAL_RCC_I2C3_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_I2C3SMEN)

#define __HAL_RCC_LPTIM1_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM1SMEN)

#define __HAL_RCC_LPTIM3_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM3SMEN)

#define __HAL_RCC_LPTIM4_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_LPTIM4SMEN)

#define __HAL_RCC_OPAMP_CLK_SLEEP_DISABLE()         CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_OPAMPSMEN)

#define __HAL_RCC_COMP_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_COMPSMEN)

#define __HAL_RCC_VREF_CLK_SLEEP_DISABLE()          CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_VREFSMEN)

#define __HAL_RCC_RTCAPB_CLK_SLEEP_DISABLE()        CLEAR_BIT(RCC->APB3SMENR, RCC_APB3SMENR_RTCAPBSMEN)

/**
  * @}
  */

/* @brief  Enable or disable peripheral bus clock  when SRD domain is in DRUN //TBC
 * @note   After reset, peripheral  clock is disabled when CPUs are in CSTOP //TBC
 * @{
 */

#define __HAL_RCC_SPI3_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_SPI3AMEN)

#define __HAL_RCC_LPUART1_CLKAM_ENABLE()          SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPUART1AMEN)

#define __HAL_RCC_I2C3_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_I2C3AMEN)

#define __HAL_RCC_LPTIM1_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM1AMEN)

#define __HAL_RCC_LPTIM3_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM3AMEN)

#define __HAL_RCC_LPTIM4_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM4AMEN)

#define __HAL_RCC_OPAMP_CLKAM_ENABLE()            SET_BIT(RCC->SRDAMR , RCC_SRDAMR_OPAMPAMEN)

#define __HAL_RCC_COMP12_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_COMPAMEN)

#define __HAL_RCC_ADC4_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_ADC4AMEN)

#define __HAL_RCC_VREF_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_VREFAMEN)

#define __HAL_RCC_RTCAPB_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_RTCAPBAMEN)

#define __HAL_RCC_DTS_CLKAM_ENABLE()              SET_BIT(RCC->SRDAMR , RCC_SRDAMR_DTSAMEN)

#define __HAL_RCC_LPGPIO_CLKAM_ENABLE()           SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPGPIOAMEN)

#define __HAL_RCC_DAC1_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_DAC1AMEN)

#define __HAL_RCC_LPDMA_CLKAM_ENABLE()            SET_BIT(RCC->SRDAMR , RCC_SRDAMR_LPDMA1AMEN)

#define __HAL_RCC_ADF1_CLKAM_ENABLE()             SET_BIT(RCC->SRDAMR , RCC_SRDAMR_ADF1AMEN)

#define __HAL_RCC_SRAM4_CLKAM_ENABLE()            SET_BIT(RCC->SRDAMR , RCC_SRDAMR_SRAM4AMEN)


#define __HAL_RCC_SPI3_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_SPI3AMEN)

#define __HAL_RCC_LPUART1_CLKAM_DISABLE()         CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPUART1AMEN)

#define __HAL_RCC_I2C3_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_I2C3AMEN)

#define __HAL_RCC_LPTIM1_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM1AMEN)

#define __HAL_RCC_LPTIM3_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM3AMEN)

#define __HAL_RCC_LPTIM4_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPTIM4AMEN)

#define __HAL_RCC_OPAMP_CLKAM_DISABLE()           CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_OPAMPAMEN)

#define __HAL_RCC_COMP12_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_COMPAMEN)

#define __HAL_RCC_ADC4_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_ADC4AMEN)

#define __HAL_RCC_VREF_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_VREFAMEN)

#define __HAL_RCC_RTCAPB_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_RTCAPBAMEN)

#define __HAL_RCC_DTS_CLKAM_DISABLE()             CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_DTSAMEN)

#define __HAL_RCC_LPGPIO_CLKAM_DISABLE()          CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPGPIOAMEN)

#define __HAL_RCC_DAC1_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_DAC1AMEN)

#define __HAL_RCC_LPDMA_CLKAM_DISABLE()           CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_LPDMA1AMEN)

#define __HAL_RCC_ADF1_CLKAM_DISABLE()            CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_ADF1AMEN)

#define __HAL_RCC_SRAM4_CLKAM_DISABLE()           CLEAR_BIT(RCC->SRDAMR , RCC_SRDAMR_SRAM4AMEN)

/**
  * @}
  */


/** @defgroup RCC_Backup_Domain_Reset RCC Backup Domain Reset
  * @{
  */

/** @brief  Macros to force or release the Backup domain reset.
  * @note   This function resets the RTC peripheral (including the backup registers)
  *         and the RTC clock source selection in RCC_CSR register.
  * @note   The BKPSRAM is not affected by this reset.
  * @retval None
  */
#define __HAL_RCC_BACKUPRESET_FORCE()   SET_BIT(RCC->BDCR, RCC_BDCR_BDRST)

#define __HAL_RCC_BACKUPRESET_RELEASE() CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST)

/**
  * @}
  */

/** @defgroup RCC_RTC_Clock_Configuration RCC RTC Clock Configuration
  * @{
  */

/** @brief  Macros to enable or disable the RTC clock.
  * @note   As the RTC is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         HAL_PWR_EnableBkUpAccess() function before to configure the RTC
  *         (to be done once after reset).
  * @note   These macros must be used after the RTC clock source was selected.
  * @retval None
  */
#define __HAL_RCC_RTC_ENABLE()         SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

#define __HAL_RCC_RTC_DISABLE()        CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN)

/**
  * @}
  */

/** @brief  Macros to enable or disable the Internal High Speed 16MHz oscillator (HSI).
  * @note   The HSI is stopped by hardware when entering STOP and STANDBY modes.
  *         It is used (enabled by hardware) as system clock source after startup
  *         from Reset, wakeup from STOP and STANDBY mode, or in case of failure
  *         of the HSE used directly or indirectly as system clock (if the Clock
  *         Security System CSS is enabled).
  * @note   HSI can not be stopped if it is used as system clock source. In this case,
  *         you have to select another source of the system clock then stop the HSI.
  * @note   After enabling the HSI, the application software should wait on HSIRDY
  *         flag to be set indicating that HSI clock is stable and can be used as
  *         system clock source.
  *         This parameter can be: ENABLE or DISABLE.
  * @note   When the HSI is stopped, HSIRDY flag goes low after 6 HSI oscillator
  *         clock cycles.
  * @retval None
  */
#define __HAL_RCC_HSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_HSION)

#define __HAL_RCC_HSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_HSION)

/** @brief  Macro to adjust the Internal High Speed 16MHz oscillator (HSI) calibration value.
  * @note   The calibration is used to compensate for the variations in voltage
  *         and temperature that influence the frequency of the internal HSI RC.
  * @param  __HSICALIBRATIONVALUE__: specifies the calibration trimming value
  *         (default is RCC_HSICALIBRATION_DEFAULT).
  *         This parameter must be a number between 0 and 0x7F.
  * @retval None
  */
#define __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(__HSICALIBRATIONVALUE__) \
                  MODIFY_REG(RCC->ICSCR3, RCC_ICSCR3_HSITRIM, (uint32_t)(__HSICALIBRATIONVALUE__) << RCC_ICSCR3_HSITRIM_Pos)


/**
  * @brief    Macros to enable or disable the force of the Internal High Speed oscillator (HSI)
  *           in STOP mode to be quickly available as kernel clock for USARTs, LPUART and I2Cs.
  * @note     Keeping the HSI ON in STOP mode allows to avoid slowing down the communication
  *           speed because of the HSI startup time.
  * @note     The enable of this function has not effect on the HSION bit.
  *           This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#define __HAL_RCC_HSISTOP_ENABLE()     SET_BIT(RCC->CR, RCC_CR_HSIKERON)

#define __HAL_RCC_HSISTOP_DISABLE()    CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON)

/**
  * @brief  Macros to enable or disable the Internal Multi Speed oscillator (MSI).
  * @note     The MSI is stopped by hardware when entering STOP and STANDBY modes.
  *           It is used (enabled by hardware) as system clock source after
  *           startup from Reset, wakeup from STOP and STANDBY mode, or in case
  *           of failure of the HSE used directly or indirectly as system clock
  *           (if the Clock Security System CSS is enabled).
  * @note     MSI can not be stopped if it is used as system clock source.
  *           In this case, you have to select another source of the system
  *           clock then stop the MSI.
  * @note     After enabling the MSI, the application software should wait on
  *           MSIRDY flag to be set indicating that MSI clock is stable and can
  *           be used as system clock source.
  * @note   When the MSI is stopped, MSIRDY flag goes low after 6 MSI oscillator
  *         clock cycles.
  * @retval None
  */
#define __HAL_RCC_MSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_MSISON)

#define __HAL_RCC_MSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_MSISON)

/**
  * @brief  Macro configures the Internal Multi Speed oscillator (MSI) clock range in run mode
  * @note     After restart from Reset , the MSI clock is around 4 MHz.
  *           After stop the startup clock can be MSI (at any of its possible
  *           frequencies, the one that was used before entering stop mode) or HSI.
  *          After Standby its frequency can be selected between 4 possible values
  *          (1, 3.072, 4 or 8 MHz).
  * @note     MSIRANGE can be modified when MSI is OFF (MSION=0) or when MSI is ready
  *          (MSIRDY=1).
  * @note    The MSI clock range after reset can be modified on the fly.
  * @param  __MSIRANGEVALUE__: specifies the MSI clock range.
  *         This parameter must be one of the following values:
  *            @arg @ref RCC_MSIRANGE_0  MSI clock is around 100 KHz
  *            @arg @ref RCC_MSIRANGE_1  MSI clock is around 400 KHz
  *            @arg @ref RCC_MSIRANGE_2  MSI clock is around 1 MHz
  *            @arg @ref RCC_MSIRANGE_3  MSI clock is around 3.072 MHz
  *            @arg @ref RCC_MSIRANGE_4  MSI clock is around 4 MHz (default after Reset)
  *            @arg @ref RCC_MSIRANGE_5  MSI clock is around 16 MHz
  *            @arg @ref RCC_MSIRANGE_6  MSI clock is around 24 MHz
  *            @arg @ref RCC_MSIRANGE_7  MSI clock is around 48 MHz
  * @retval None
  */
#define __HAL_RCC_MSI_RANGE_CONFIG(__MSIRANGEVALUE__) \
                  do {                                                         \
                    SET_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL);                         \
                    MODIFY_REG(RCC->ICSCR1, RCC_ICSCR1_MSISRANGE, (__MSIRANGEVALUE__)); \
                  } while(0)
/**

* @brief  Macro configures the Internal Multi Speed kernel oscillator (MSIK) clock range in run mode
* @note     After restart from Reset , the MSIK clock is around 4 MHz.
*           After stop the startup clock can be MSIK (at any of its possible
*           frequencies, the one that was used before entering stop mode) or HSI.
*          After Standby its frequency can be selected between 4 possible values
*          (1, 3.072, 4 or 8 MHz).
* @note     MSIKRANGE can be modified when MSI is OFF (MSIKON=0) or when MSIK is ready
*          (MSIKRDY=1).
* @note    The MSI clock range after reset can be modified on the fly.
* @param  __MSIRANGEVALUE__: specifies the MSI clock range.
*         This parameter must be one of the following values:
*            @arg @ref RCC_MSIKRANGE_0  MSIK clock is around 100 KHz
*            @arg @ref RCC_MSIKRANGE_1  MSIK clock is around 400 KHz
*            @arg @ref RCC_MSIKRANGE_2  MSIK clock is around 1 MHz
*            @arg @ref RCC_MSIKRANGE_3  MSIK clock is around 3.072 MHz
*            @arg @ref RCC_MSIKRANGE_4  MSIK clock is around 4 MHz (default after Reset)
*            @arg @ref RCC_MSIKRANGE_5  MSIK clock is around 16 MHz
*            @arg @ref RCC_MSIKRANGE_6  MSIK clock is around 24 MHz
*            @arg @ref RCC_MSIKRANGE_7  MSIk clock is around 48 MHz
* @retval None
*/

#define __HAL_RCC_MSIK_RANGE_CONFIG(__MSIKRANGEVALUE__) \
                  do {                                                         \
                    SET_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL);                         \
                    MODIFY_REG(RCC->ICSCR1, RCC_ICSCR1_MSIKRANGE, (__MSIKRANGEVALUE__)); \
                  } while(0)

/**
  * @brief  Macro configures the Internal Multi Speed oscillator (MSI) clock range after Standby mode
  *         After Standby its frequency can be selected between 3 possible values (1, 3.072 or 4 MHz).
  * @param  __MSIRANGEVALUE__: specifies the MSI clock range.
  *         This parameter must be one of the following values:
  *            @arg @ref RCC_MSIRANGE_2  MSI clock is around 1 MHz
  *            @arg @ref RCC_MSIRANGE_3  MSI clock is around 3.072 MHz
  *            @arg @ref RCC_MSIRANGE_4  MSI clock is around 4 MHz (default after Reset)
  * @retval None
  */
#define __HAL_RCC_MSI_STANDBY_RANGE_CONFIG(__MSIRANGEVALUE__) \
                  do {                                                         \
                    SET_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL);                         \
                    MODIFY_REG(RCC->CSR, RCC_CSR_MSISSRANGE, (__MSIRANGEVALUE__) >> (RCC_ICSCR1_MSISRANGE_Pos - RCC_CSR_MSISSRANGE_Pos)); \
                  } while(0)

/** @brief  Macro to get the Internal Multi Speed oscillator (MSI) clock range in run mode
  * @retval MSI clock range.
  *         This parameter must be one of the following values:
  *            @arg @ref RCC_MSIRANGE_0 MSI clock is around 100 KHz
  *            @arg @ref RCC_MSIRANGE_1 MSI clock is around 400 KHz
  *            @arg @ref RCC_MSIRANGE_2 MSI clock is around 1 MHz
  *            @arg @ref RCC_MSIRANGE_3 MSI clock is around 3.072 MHz
  *            @arg @ref RCC_MSIRANGE_4 MSI clock is around 4 MHz  (default after Reset)
  *            @arg @ref RCC_MSIRANGE_5 MSI clock is around 16 MHz
  *            @arg @ref RCC_MSIRANGE_6 MSI clock is around 24 MHz
  *            @arg @ref RCC_MSIRANGE_7 MSI clock is around 48 MHz
  */
#define __HAL_RCC_GET_MSI_RANGE()                                              \
                  ((READ_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL) != RESET) ?             \
                   (uint32_t)(READ_BIT(RCC->ICSCR1, RCC_ICSCR1_MSISRANGE)) :            \
                   (uint32_t)(READ_BIT(RCC->CSR, RCC_CSR_MSISSRANGE) << (RCC_ICSCR1_MSISRANGE_Pos - RCC_CSR_MSISSRANGE_Pos)))

/** @brief  Macro to get the Internal Multi Speed kernel oscillator (MSIK) clock range in run mode
  * @retval MSIK clock range.
  *         This parameter must be one of the following values:
  *            @arg @ref RCC_MSIKRANGE_0 MSIK clock is around 100 KHz
  *            @arg @ref RCC_MSIKRANGE_1 MSIK clock is around 400 KHz
  *            @arg @ref RCC_MSIKRANGE_2 MSIK clock is around 1 MHz
  *            @arg @ref RCC_MSIKRANGE_3 MSIK clock is around 3.072 MHz
  *            @arg @ref RCC_MSIKRANGE_4 MSIK clock is around 4 MHz  (default after Reset)
  *            @arg @ref RCC_MSIKRANGE_5 MSIK clock is around 16 MHz
  *            @arg @ref RCC_MSIKRANGE_6 MSIK clock is around 24 MHz
  *            @arg @ref RCC_MSIKRANGE_7 MSIK clock is around 48 MHz
  */
#define __HAL_RCC_GET_MSIK_RANGE()                                              \
                  ((READ_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL) != RESET) ?             \
                   (uint32_t)(READ_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIKRANGE)) :            \
                   (uint32_t)(READ_BIT(RCC->CSR, RCC_CSR_MSIKSRANGE) << (RCC_ICSCR1_MSIKRANGE_Pos - RCC_CSR_MSIKSRANGE_Pos)))

/** @brief  Macros to enable or disable the Internal Low Speed oscillator (LSI).
  * @note   After enabling the LSI, the application software should wait on
  *         LSIRDY flag to be set indicating that LSI clock is stable and can
  *         be used to clock the IWDG and/or the RTC.
  * @note   LSI can not be disabled if the IWDG is running.
  * @note   When the LSI is stopped, LSIRDY flag goes low after 6 LSI oscillator
  *         clock cycles.
  * @retval None
  */
#define __HAL_RCC_LSI_ENABLE()         SET_BIT(RCC->BDCR, RCC_BDCR_LSION)

#define __HAL_RCC_LSI_DISABLE()        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSION)

/**
  * @brief  Macro to configure the External High Speed oscillator (HSE).
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this macro. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  * @note   After enabling the HSE (RCC_HSE_ON or RCC_HSE_Bypass), the application
  *         software should wait on HSERDY flag to be set indicating that HSE clock
  *         is stable and can be used to clock the PLL and/or system clock.
  * @note   HSE state can not be changed if it is used directly or through the
  *         PLL as system clock. In this case, you have to select another source
  *         of the system clock then change the HSE state (ex. disable it).
  * @note   The HSE is stopped by hardware when entering STOP and STANDBY modes.
  * @note   This function reset the CSSON bit, so if the clock security system(CSS)
  *         was previously enabled you have to enable it again after calling this
  *         function.
  * @param  __STATE__: specifies the new state of the HSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_HSE_OFF  Turn OFF the HSE oscillator, HSERDY flag goes low after
  *                              6 HSE oscillator clock cycles.
  *            @arg @ref RCC_HSE_ON  Turn ON the HSE oscillator.
  *            @arg @ref RCC_HSE_BYPASS  HSE oscillator bypassed with external clock.
  * @retval None
  */
#define __HAL_RCC_HSE_CONFIG(__STATE__)                      \
                    do {                                     \
                      if((__STATE__) == RCC_HSE_ON)          \
                      {                                      \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);      \
                      }                                      \
                      else if((__STATE__) == RCC_HSE_BYPASS) \
                      {                                      \
                        SET_BIT(RCC->CR, RCC_CR_HSEBYP);     \
                        SET_BIT(RCC->CR, RCC_CR_HSEON);      \
                      }                                      \
                      else                                   \
                      {                                      \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEON);    \
                        CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);   \
                      }                                      \
                    } while(0)

/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE).
  * @note   Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not
  *         supported by this macro. User should request a transition to LSE Off
  *         first and then LSE On or LSE Bypass.
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  * @note   After enabling the LSE (RCC_LSE_ON or RCC_LSE_BYPASS), the application
  *         software should wait on LSERDY flag to be set indicating that LSE clock
  *         is stable and can be used to clock the RTC.
  * @param  __STATE__: specifies the new state of the LSE.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_LSE_OFF  Turn OFF the LSE oscillator, LSERDY flag goes low after
  *                              6 LSE oscillator clock cycles.
  *            @arg @ref RCC_LSE_ON  Turn ON the LSE oscillator.
  *            @arg @ref RCC_LSE_BYPASS  LSE oscillator bypassed with external clock.
  * @retval None
  */

#define __HAL_RCC_LSE_CONFIG(__STATE__)                                                \
                  do {                                                                 \
                    if((__STATE__) == RCC_LSE_ON)                                      \
                    {                                                                  \
                      SET_BIT(RCC->BDCR, (RCC_BDCR_LSESYSEN | RCC_BDCR_LSEON));    \
                    }                                                                  \
                    else if((__STATE__) == RCC_LSE_BYPASS)                             \
                    {                                                                  \
                      SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                         \
                      SET_BIT(RCC->BDCR, (RCC_BDCR_LSESYSEN | RCC_BDCR_LSEON));    \
                    }                                                                  \
                    else                                                               \
                    {                                                                  \
                      if(READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN) == RESET)          \
                      {                                                                \
                        SET_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN);                     \
                      }                                                                \
                      CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);                        \
                      CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);                       \
                    }                                                                  \
                  } while(0)

/** @brief  Macros to enable or disable the Internal High Speed 48MHz oscillator (HSI48).
  * @note   The HSI48 is stopped by hardware when entering STOP and STANDBY modes.
  * @note   After enabling the HSI48, the application software should wait on HSI48RDY
  *         flag to be set indicating that HSI48 clock is stable.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#define __HAL_RCC_HSI48_ENABLE()  SET_BIT(RCC->CR, RCC_CR_HSI48ON)

#define __HAL_RCC_HSI48_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_HSI48ON)

/** @brief  Macros to enable or disable the Internal multi-speed RC oscillator clock (MSIK).
  * @note   if the peripheral requests its kernel clock in Stop 0 or Stop 1 mode,MSIK is woken up
  * @note   After enabling the MSIK, the application software should wait on MSIKRDY
  *         flag to be set indicating that MSIK clock is stable.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#define __HAL_RCC_MSIK_ENABLE()  SET_BIT(RCC->CR, RCC_CR_MSIKON)

#define __HAL_RCC_MSIK_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_MSIKON)

/** @brief  Macros to enable or disable the secure Internal High Speed oscillator (SHSI).
  * @note   The SHSI is stopped by hardware when entering STOP and STANDBY modes.
  * @note   After enabling the SHSI, the application software should wait on SHSI
  *         flag to be set indicating that SHSI clock is stable.
  *         This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
#define __HAL_RCC_SHSI_ENABLE()  SET_BIT(RCC->CR, RCC_CR_SHSION)

#define __HAL_RCC_SHSI_DISABLE() CLEAR_BIT(RCC->CR, RCC_CR_SHSION)

/** @brief  Macros to configure the RTC clock (RTCCLK).
  * @note   As the RTC clock configuration bits are in the Backup domain and write
  *         access is denied to this domain after reset, you have to enable write
  *         access using the Power Backup Access macro before to configure
  *         the RTC clock source (to be done once after reset).
  * @note   Once the RTC clock is configured it cannot be changed unless the
  *         Backup domain is reset using __HAL_RCC_BACKUPRESET_FORCE() macro, or by
  *         a Power On Reset (POR).
  *
  * @param  __RTC_CLKSOURCE__: specifies the RTC clock source.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK  No clock selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSE  LSE selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSI  LSI selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV32  HSE clock divided by 32 selected
  *
  * @note   If the LSE or LSI is used as RTC clock source, the RTC continues to
  *         work in STOP and STANDBY modes, and can be used as wakeup source.
  *         However, when the HSE clock is used as RTC clock source, the RTC
  *         cannot be used in STOP and STANDBY modes.
  * @note   The maximum input clock frequency for RTC is 1MHz (when using HSE as
  *         RTC clock source).
  * @retval None
  */
#define __HAL_RCC_RTC_CONFIG(__RTC_CLKSOURCE__)  \
                  MODIFY_REG( RCC->BDCR, RCC_BDCR_RTCSEL, (__RTC_CLKSOURCE__))


/** @brief  Macro to get the RTC clock source.
  * @retval The returned value can be one of the following:
  *            @arg @ref RCC_RTCCLKSOURCE_NO_CLK  No clock selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSE  LSE selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_LSI  LSI selected as RTC clock.
  *            @arg @ref RCC_RTCCLKSOURCE_HSE_DIV32  HSE clock divided by 32 selected
  */
#define  __HAL_RCC_GET_RTC_SOURCE() ((uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL)))

/** @brief  Macros to enable or disable the main PLL.
  * @note   After enabling the main PLL, the application software should wait on
  *         PLLRDY flag to be set indicating that PLL clock is stable and can
  *         be used as system clock source.
  * @note   The main PLL can not be disabled if it is used as system clock source
  * @note   The main PLL is disabled by hardware when entering STOP and STANDBY modes.
  */
#define __HAL_RCC_PLL_ENABLE()         SET_BIT(RCC->CR, RCC_CR_PLL1ON)
#define __HAL_RCC_PLL_DISABLE()        CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON)

/**
  * @brief  Enables or disables each clock output (PLL_P_CLK, PLL_Q_CLK, PLL_R_CLK)
  * @note   Enabling/disabling  Those Clocks can be any time  without the need to stop the PLL,
  *        (except the ck_pll_r of the System PLL that cannot be stopped if used as System
  *         Clock.This is mainly used to save Power.
  * @param  __PLL1_CLOCKOUT__: specifies the PLL clock to be outputted
  *          This parameter can be one of the following values:
  *            @arg RCC_PLL1_DIVP: This clock is used to generate an accurate clock to achieve,
  *                                   high-quality audio performance on SAI interface.
  *            @arg RCC_PLL1_DIVQ: This Clock is used to generate the clock for the USB FS(48 MHz),
  *                                the random analog generator (<=48 MHz) and the OCTOSPI1/2.
  *            @arg RCC_PLL1_DIVR: This Clock is used to generate the high speed system clock (up to 160MHz)
  * @retval None
  *
  */
#define __HAL_RCC_PLLCLKOUT_ENABLE(__PLL1_CLOCKOUT__)   SET_BIT(RCC->PLL1CFGR, (__PLL1_CLOCKOUT__))

#define __HAL_RCC_PLLCLKOUT_DISABLE(__PLL1_CLOCKOUT__)  CLEAR_BIT(RCC->PLL1CFGR, (__PLL1_CLOCKOUT__))

/**
  * @brief  Macro to get the PLL clock output enable status.
  * @param  __PLL_CLOCKOUT__ specifies the PLL1 clock to be output.
  *         This parameter can be one of the following values:
  *            @arg RCC_PLL1_DIVP: This clock is used to generate an accurate clock to achieve,
  *                                   high-quality audio performance on SAI interface.
  *            @arg RCC_PLL1_DIVQ: This Clock is used to generate the clock for the USB FS(48 MHz),
  *                                the random analog generator (<=48 MHz) and the OCTOSPI1/2.
  *            @arg RCC_PLL1_DIVR: This Clock is used to generate the high speed system clock (up to 160MHz)
  * @retval SET / RESET
  */
#define __HAL_RCC_GET_PLLCLKOUT_CONFIG(__PLL1_CLOCKOUT__)  READ_BIT(RCC->PLL1CFGR, (__PLL1_CLOCKOUT__))

/**
  * @brief  Enables or disables Fractional Part Of The Multiplication Factor of PLL1 VCO
  * @note   Enabling/disabling  Fractional Part can be any time  without the need to stop the PLL1
  * @retval None
  */
#define __HAL_RCC_PLLFRACN_ENABLE()   SET_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1FRACEN)

#define __HAL_RCC_PLLFRACN_DISABLE()  CLEAR_BIT(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1FRACEN)

/**
  * @brief  Macro to configures the main PLL clock source, multiplication and division factors.
  * @note   This function must be used only when the main PLL is disabled.
  *
  * @param  __PLLSOURCE__: specifies the PLL entry clock source.
  *          This parameter can be one of the following values:
  *            @arg RCC_PLLSOURCE_MSI: MSI oscillator clock selected as PLL clock entry
  *            @arg RCC_PLLSOURCE_HSI: HSI oscillator clock selected as PLL clock entry
  *            @arg RCC_PLLSOURCE_HSE: HSE oscillator clock selected as PLL clock entry
  * @note   This clock source (__PLLSource__) is common for the main PLL1 (main PLL) and PLL2 & PLL3 .
  *
  * @param  __PLLM1__: specifies the division factor for PLL VCO input clock
  *          This parameter must be a number between 1 and 63.
  * @note   You have to set the PLLM parameter correctly to ensure that the VCO input
  *         frequency ranges from 1 to 16 MHz.
  *
  * @param  __PLLN1__: specifies the multiplication factor for PLL VCO output clock
  *          This parameter must be a number between 4 and 512.
  * @note   You have to set the PLLN parameter correctly to ensure that the VCO
  *         output frequency is between 150 and 420 MHz (when in medium VCO range) or
  *         between 192 and 836 MHZ (when in wide VCO range)
  *
  * @param  __PLLP1__: specifies the division factor for system  clock.
  *          This parameter must be a number between 2 and 128 (where odd numbers not allowed)
  *
  * @param  __PLLQ1__: specifies the division factor for peripheral kernel clocks
  *          This parameter must be a number between 1 and 128
  *
  * @param  __PLLR1__: specifies the division factor for peripheral kernel clocks
  *          This parameter must be a number between 1 and 128
  *
  * @retval None
  */

#define __HAL_RCC_PLL_CONFIG(__PLL1SOURCE__, __PLL1M__, __PLL1N__, __PLL1P__, __PLL1Q__, __PLL1R__) \
                  do{ WRITE_REG(RCC->PLL1CFGR, ((__PLL1SOURCE__) << RCC_PLL1CFGR_PLL1SRC_Pos) | (((__PLL1M__) - 1U) << RCC_PLL1CFGR_PLL1M_Pos));\
                      WRITE_REG(RCC->PLL1DIVR , ( (((__PLL1N__) - 1U ) & RCC_PLL1DIVR_PLL1N) | ((((__PLL1P__) -1U ) << RCC_PLL1DIVR_PLL1P_Pos) & RCC_PLL1DIVR_PLL1P) | \
                                   ((((__PLL1Q__) -1U) << RCC_PLL1DIVR_PLL1Q_Pos) & RCC_PLL1DIVR_PLL1Q) | ((((__PLL1R__)- 1U) << RCC_PLL1DIVR_PLL1R_Pos) & RCC_PLL1DIVR_PLL1R))); \
                       } while(0)

/** @brief  Macro to configure the PLLs clock source.
  * @note   This function must be used only when all PLLs are disabled.
  * @param  __PLLSOURCE__: specifies the PLLs entry clock source.
  *         This parameter can be one of the following values:
  *            @arg RCC_PLLSOURCE_MSI: MSI oscillator clock selected as PLL clock entry
  *            @arg RCC_PLLSOURCE_HSI: HSI oscillator clock selected as PLL clock entry
  *            @arg RCC_PLLSOURCE_HSE: HSE oscillator clock selected as PLL clock entry
  *
  */
#define __HAL_RCC_PLL_PLLSOURCE_CONFIG(__PLLSOURCE__) MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1SRC, (__PLLSOURCE__))

/** @brief  Macro to configure the PLL1 input clock division factor M.
  *
  * @note   This function must be used only when the PLL1 is disabled.
  * @note   PLL1 clock source is common with the main PLL (configured through
  *         __HAL_RCC_PLL_CONFIG() macro)
  *
  * @param  __PLL1M__ specifies the division factor for PLL1 clock.
  *         This parameter must be a number between Min_Data = 1 and Max_Data = 16.
  *
  * @retval None
  */
#define __HAL_RCC_PLL_DIVM_CONFIG(__PLL1M__) \
                  MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1M, ((__PLL1M__) - 1U) << RCC_PLL1CFGR_PLL1M_Pos)

/**
  * @brief  Macro to configures the main PLL clock Fractional Part Of The Multiplication Factor
  *
  * @note   These bits can be written at any time, allowing dynamic fine-tuning of the PLL1 VCO
  *
  * @param  __PLL1FRACN__: specifies Fractional Part Of The Multiplication Factor for PLL1 VCO
  *                            It should be a value between 0 and 8191
  * @note   Warning: The software has to set correctly these bits to insure that the VCO
  *                  output frequency is between its valid frequency range, which is:
  *                   192 to 836 MHz if PLL1VCOSEL = 0
  *                   150 to 420 MHz if PLL1VCOSEL = 1.
  *
  *
  * @retval None
  */
#define  __HAL_RCC_PLLFRACN_CONFIG(__PLL1FRACN__) MODIFY_REG(RCC->PLL1FRACR, RCC_PLL1FRACR_PLL1FRACN, (uint32_t)(__PLL1FRACN__) << RCC_PLL1FRACR_PLL1FRACN_Pos)

/** @brief  Macro to select  the PLL1  reference frequency range.
  * @param  __PLL1VCIRange__: specifies the PLL1 input frequency range
  *         This parameter can be one of the following values:
  *            @arg RCC_PLLVCIRANGE_0: Range frequency is between 2 and 4 MHz
  *            @arg RCC_PLLVCIRANGE_1: Range frequency is between 2 and 4 MHz
  *            @arg RCC_PLLVCIRANGE_2: Range frequency is between 4 and 8 MHz
  *            @arg RCC_PLLVCIRANGE_3: Range frequency is between 8 and 16 MHz
  * @retval None
  */
#define __HAL_RCC_PLL_VCIRANGE(__PLL1VCIRange__) \
                  MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1RGE, (__PLL1VCIRange__))

/** @brief  Macro to get the oscillator used as PLL1 clock source.
  * @retval The oscillator used as PLL1 clock source. The returned value can be one
  *         of the following:
  *              - RCC_PLLSOURCE_NONE: No oscillator is used as PLL clock source.
  *              - RCC_PLLSOURCE_MSI: MSI oscillator is used as PLL clock source.
  *              - RCC_PLLSOURCE_HSI: HSI oscillator is used as PLL clock source.
  *              - RCC_PLLSOURCE_HSE: HSE oscillator is used as PLL clock source.
  */
#define __HAL_RCC_GET_PLL_OSCSOURCE() ((uint32_t)(RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1SRC))

/**
  * @brief  Macro to configure the system clock source.
  * @param  __SYSCLKSOURCE__: specifies the system clock source.
  *          This parameter can be one of the following values:
  *              - RCC_SYSCLKSOURCE_MSI: MSI oscillator is used as system clock source.
  *              - RCC_SYSCLKSOURCE_HSI: HSI oscillator is used as system clock source.
  *              - RCC_SYSCLKSOURCE_HSE: HSE oscillator is used as system clock source.
  *              - RCC_SYSCLKSOURCE_PLLCLK: PLL output is used as system clock source.
  * @retval None
  */
#define __HAL_RCC_SYSCLK_CONFIG(__SYSCLKSOURCE__) \
                  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_SW, (__SYSCLKSOURCE__))

/** @brief  Macro to get the clock source used as system clock.
  * @retval The clock source used as system clock. The returned value can be one
  *         of the following:
  *              - RCC_SYSCLKSOURCE_MSI: MSI used as system clock.
  *              - RCC_SYSCLKSOURCE_HSI: HSI used as system clock.
  *              - RCC_SYSCLKSOURCE_HSE: HSE used as system clock.
  *              - RCC_SYSCLKSOURCE_PLLCLK: PLL used as system clock.
  */
#define __HAL_RCC_GET_SYSCLK_SOURCE() ((uint32_t)(RCC->CFGR1 & RCC_CFGR1_SWS))

/**
  * @brief  Macro to configure the External Low Speed oscillator (LSE) drive capability.
  * @note   As the LSE is in the Backup domain and write access is denied to
  *         this domain after reset, you have to enable write access using
  *         HAL_PWR_EnableBkUpAccess() function before to configure the LSE
  *         (to be done once after reset).
  * @param  __LSEDRIVE__: specifies the new state of the LSE drive capability.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_LSEDRIVE_LOW  LSE oscillator low drive capability.
  *            @arg @ref RCC_LSEDRIVE_MEDIUMLOW  LSE oscillator medium low drive capability.
  *            @arg @ref RCC_LSEDRIVE_MEDIUMHIGH  LSE oscillator medium high drive capability.
  *            @arg @ref RCC_LSEDRIVE_HIGH  LSE oscillator high drive capability.
  * @retval None
  */
#define __HAL_RCC_LSEDRIVE_CONFIG(__LSEDRIVE__) \
                  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, (uint32_t)(__LSEDRIVE__))

/**
  * @brief  Macro to configure the wake up from stop clock.
  * @param  __STOPWUCLK__: specifies the clock source used after wake up from stop.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_STOP_WAKEUPCLOCK_MSI  MSI selected as system clock source
  *            @arg @ref RCC_STOP_WAKEUPCLOCK_HSI  HSI selected as system clock source
  * @retval None
  */
#define __HAL_RCC_WAKEUPSTOP_CLK_CONFIG(__STOPWUCLK__) \
                  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_STOPWUCK, (__STOPWUCLK__))

/**
  * @brief  Macro to configure the Kernel wake up from stop clock.
  * @param  __RCC_STOPKERWUCLK__: specifies the Kernel clock source used after wake up from stop
  *         This parameter can be one of the following values:
  *            @arg RCC_STOP_KERWAKEUPCLOCK_MSI: MSI selected as Kernel clock source
  *            @arg RCC_STOP_KERWAKEUPCLOCK_HSI: HSI selected as Kernel clock source
  * @retval None
  */
#define __HAL_RCC_KERWAKEUPSTOP_CLK_CONFIG(__RCC_STOPKERWUCLK__) \
                  MODIFY_REG(RCC->CFGR1, RCC_CFGR1_STOPKERWUCK, (__RCC_STOPKERWUCLK__))

/** @brief  Macro to configure the MCO clock.
  * @param  __MCOCLKSOURCE__ specifies the MCO clock source.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK  MCO output disabled
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  System  clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_MSI  MSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSI  HSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSE  HSE clock selected as MCO sourcee
  *            @arg @ref RCC_MCO1SOURCE_PLLCLK  Main PLL clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_LSI  LSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_LSE  LSE clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSI48  HSI48 clock selected as MCO source for devices with HSI48
  * @param  __MCODIV__ specifies the MCO clock prescaler.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1   MCO clock source is divided by 1
  *            @arg @ref RCC_MCODIV_2   MCO clock source is divided by 2
  *            @arg @ref RCC_MCODIV_4   MCO clock source is divided by 4
  *            @arg @ref RCC_MCODIV_8   MCO clock source is divided by 8
  *            @arg @ref RCC_MCODIV_16  MCO clock source is divided by 16
  */
#define __HAL_RCC_MCO1_CONFIG(__MCOCLKSOURCE__, __MCODIV__) \
                 MODIFY_REG(RCC->CFGR1, (RCC_CFGR1_MCOSEL | RCC_CFGR1_MCOPRE), ((__MCOCLKSOURCE__) | (__MCODIV__)))

/** @defgroup RCC_Flags_Interrupts_Management Flags Interrupts Management
  * @brief macros to manage the specified RCC Flags and interrupts.
  * @{
  */

/** @brief  Enable RCC interrupt (Perform Byte access to RCC_CIR[14:8] bits to enable
  *         the selected interrupts).
  * @param  __INTERRUPT__: specifies the RCC interrupt sources to be enabled.
  *         This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY  LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY  LSE ready interrupt
  *            @arg @ref RCC_IT_MSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY  HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY  Main PLL ready interrupt
  *            @arg @ref RCC_IT_PLL2RDY  PLL2 ready interrupt
  *            @arg @ref RCC_IT_PLL3RDY  PLL3 ready interrupt
  *            @arg @ref RCC_IT_HSI48RDY  HSI48 ready interrupt
  * @retval None
  */
#define __HAL_RCC_ENABLE_IT(__INTERRUPT__) SET_BIT(RCC->CIER, (__INTERRUPT__))

/** @brief Disable RCC interrupt (Perform Byte access to RCC_CIR[14:8] bits to disable
  *        the selected interrupts).
  * @param  __INTERRUPT__: specifies the RCC interrupt sources to be disabled.
  *         This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY  LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY  LSE ready interrupt
  *            @arg @ref RCC_IT_MSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY  HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY  Main PLL ready interrupt
  *            @arg @ref RCC_IT_PLL2RDY  PLL2 ready interrupt
  *            @arg @ref RCC_IT_PLL3RDY  PLL3 ready interrupt
  *            @arg @ref RCC_IT_LSECSS  LSE Clock security system interrupt
  *            @arg @ref RCC_IT_HSI48RDY  HSI48 ready interrupt
  * @retval None
  */
#define __HAL_RCC_DISABLE_IT(__INTERRUPT__) CLEAR_BIT(RCC->CIER, (__INTERRUPT__))

/** @brief  Clear the RCC's interrupt pending bits (Perform Byte access to RCC_CIR[23:16]
  *         bits to clear the selected interrupt pending bits.
  * @param  __INTERRUPT__: specifies the interrupt pending bit to clear.
  *         This parameter can be any combination of the following values:
  *            @arg @ref RCC_IT_LSIRDY  LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY  LSE ready interrupt
  *            @arg @ref RCC_IT_MSIRDY  MSI ready interrupt
  *            @arg @ref RCC_IT_HSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY  HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY  Main PLL ready interrupt
  *            @arg @ref RCC_IT_PLL2RDY  PLL2 ready interrupt
  *            @arg @ref RCC_IT_PLL3RDY  PLL3 ready interrupt
  *            @arg @ref RCC_IT_CSS  HSE Clock security system interrupt
  *            @arg @ref RCC_IT_LSECSS  LSE Clock security system interrupt
  *            @arg @ref RCC_IT_HSI48RDY  HSI48 ready interrupt
  * @retval None
  */
#define __HAL_RCC_CLEAR_IT(__INTERRUPT__) WRITE_REG(RCC->CICR, (__INTERRUPT__))

/** @brief  Check whether the RCC interrupt has occurred or not.
  * @param  __INTERRUPT__: specifies the RCC interrupt source to check.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_IT_LSIRDY  LSI ready interrupt
  *            @arg @ref RCC_IT_LSERDY  LSE ready interrupt
  *            @arg @ref RCC_IT_MSIRDY  MSI ready interrupt
  *            @arg @ref RCC_IT_HSIRDY  HSI ready interrupt
  *            @arg @ref RCC_IT_HSERDY  HSE ready interrupt
  *            @arg @ref RCC_IT_PLLRDY  Main PLL ready interrupt
  *            @arg @ref RCC_IT_PLL2RDY  PLL2 ready interrupt
  *            @arg @ref RCC_IT_PLL3RDY  PLL3 ready interrupt
  *            @arg @ref RCC_IT_CSS  HSE Clock security system interrupt
  *            @arg @ref RCC_IT_LSECSS  LSE Clock security system interrupt
  *            @arg @ref RCC_IT_HSI48RDY HSI48 ready interrupt
  * @retval The new state of __INTERRUPT__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_IT(__INTERRUPT__)  ((RCC->CIFR & (__INTERRUPT__)) == (__INTERRUPT__))

/** @brief Set RMVF bit to clear the reset flags.
  *        The reset flags are: RCC_FLAG_FWRRST, RCC_FLAG_OBLRST, RCC_FLAG_PINRST, RCC_FLAG_BORRST,
  *        RCC_FLAG_SFTRST, RCC_FLAG_IWDGRST, RCC_FLAG_WWDGRST and RCC_FLAG_LPWRRST.
  * @retval None
 */
#define __HAL_RCC_CLEAR_RESET_FLAGS() (RCC->CSR |= RCC_CSR_RMVF)

/** @brief  Check whether the selected RCC flag is set or not.
  * @param  __FLAG__: specifies the flag to check.
  *         This parameter can be one of the following values:
  *            @arg @ref RCC_FLAG_MSIRDY  MSI oscillator clock ready
  *            @arg @ref RCC_FLAG_HSIRDY  HSI oscillator clock ready
  *            @arg @ref RCC_FLAG_HSERDY  HSE oscillator clock ready
  *            @arg @ref RCC_FLAG_PLL1RDY  Main PLL1 clock ready
  *            @arg @ref RCC_FLAG_PLL2RDY  PLL2 clock ready
  *            @arg @ref RCC_FLAG_PLL3RDY  PLL3 clock ready
  *            @arg @ref RCC_FLAG_HSI48RDY  HSI48 clock ready
  *            @arg @ref RCC_FLAG_LSERDY  LSE oscillator clock ready
  *            @arg @ref RCC_FLAG_LSECSSD  Clock security system failure on LSE oscillator detection
  *            @arg @ref RCC_FLAG_LSIRDY  LSI oscillator clock ready
  *            @arg @ref RCC_FLAG_BORRST  BOR reset
  *            @arg @ref RCC_FLAG_OBLRST  OBLRST reset
  *            @arg @ref RCC_FLAG_PINRST  Pin reset
  *            @arg @ref RCC_FLAG_RMVF  Remove reset Flag
  *            @arg @ref RCC_FLAG_SFTRST  Software reset
  *            @arg @ref RCC_FLAG_IWDGRST  Independent Watchdog reset
  *            @arg @ref RCC_FLAG_WWDGRST  Window Watchdog reset
  *            @arg @ref RCC_FLAG_LPWRRST  Low Power reset
  * @retval The new state of __FLAG__ (TRUE or FALSE).
  */
#define __HAL_RCC_GET_FLAG(__FLAG__) (((((((__FLAG__) >> 5U) == 1U) ? RCC->CR :                       \
                                        ((((__FLAG__) >> 5U) == 4U) ? RCC->CRRCR :                    \
                                        ((((__FLAG__) >> 5U) == 2U) ? RCC->BDCR :                     \
                                        ((((__FLAG__) >> 5U) == 3U) ? RCC->CSR : RCC->CIFR)))) &  \
                                          (1U << ((__FLAG__) & RCC_FLAG_MASK))) != RESET) \
                                            ? 1U : 0U)
/**
  * @}
  */

/**
  * @}
  */

/* Private constants ---------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
  * @{
  */
#define HSE_TIMEOUT_VALUE          HSE_STARTUP_TIMEOUT
#define HSI_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */
#define MSI_TIMEOUT_VALUE          (2U)    /* 2 ms (minimum Tick + 1) */

/* Defines used for Flags */
#define CR_REG_INDEX              (1U)
#define BDCR_REG_INDEX            (2U)
#define CSR_REG_INDEX             (3U)
#define CRRCR_REG_INDEX           (4U)

#define RCC_FLAG_MASK             (0x1FU)
/**
  * @}
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RCC_Private_Macros
  * @{
  */

#define IS_RCC_OSCILLATORTYPE(__OSCILLATOR__) (((__OSCILLATOR__) == RCC_OSCILLATORTYPE_NONE)                               || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSE)   == RCC_OSCILLATORTYPE_HSE)   || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI)   == RCC_OSCILLATORTYPE_HSI)   || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_HSI48) == RCC_OSCILLATORTYPE_HSI48) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_MSI)   == RCC_OSCILLATORTYPE_MSI)   || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_MSIK)   == RCC_OSCILLATORTYPE_MSIK) || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSI)   == RCC_OSCILLATORTYPE_LSI)   || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_SHSI)  == RCC_OSCILLATORTYPE_SHSI)   || \
                                               (((__OSCILLATOR__) & RCC_OSCILLATORTYPE_LSE)   == RCC_OSCILLATORTYPE_LSE))


#define IS_RCC_HSE(__HSE__)  (((__HSE__) == RCC_HSE_OFF) || ((__HSE__) == RCC_HSE_ON) || \
                              ((__HSE__) == RCC_HSE_BYPASS))

#define IS_RCC_LSE(__LSE__)  (((__LSE__) == RCC_LSE_OFF)                                              || \
                              ((__LSE__) == RCC_LSE_ON)     || ((__LSE__) == RCC_LSE_ON_RTC_ONLY)     || \
                              ((__LSE__) == RCC_LSE_BYPASS) || ((__LSE__) == RCC_LSE_BYPASS_RTC_ONLY))

#define IS_RCC_HSI(__HSI__)  (((__HSI__) == RCC_HSI_OFF) || ((__HSI__) == RCC_HSI_ON))

#define IS_RCC_HSI_CALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= (uint32_t)( RCC_ICSCR3_HSITRIM  >>  RCC_ICSCR3_HSITRIM_Pos))

#define IS_RCC_LSI(__LSI__)  (((__LSI__) == RCC_LSI_OFF) || ((__LSI__) == RCC_LSI_ON))

#define IS_RCC_MSI(__MSI__)  (((__MSI__) == RCC_MSI_OFF) || ((__MSI__) == RCC_MSI_ON))

#define IS_RCC_MSICALIBRATION_VALUE(__VALUE__) ((__VALUE__) <= 255U)

#define IS_RCC_HSI48(__HSI48__)  (((__HSI48__) == RCC_HSI48_OFF) || ((__HSI48__) == RCC_HSI48_ON))

#define IS_RCC_SHSI(__SHSI__)  (((__SHSI__) == RCC_SHSI_OFF) || ((__SHSI__) == RCC_SHSI_ON))

#define IS_RCC_MSIK(__MSIK__)  (((__MSIK__) == RCC_MSIK_OFF) || ((__MSIK__) == RCC_MSIK_ON))

#define IS_RCC_PLL(PLL) (((PLL) == RCC_PLL_NONE) ||((PLL) == RCC_PLL_OFF) || \
                         ((PLL) == RCC_PLL_ON))

#define IS_RCC_PLLSOURCE(SOURCE) (((SOURCE) == RCC_PLLSOURCE_MSI)  || \
                                  ((SOURCE) == RCC_PLLSOURCE_HSI)  || \
                                  ((SOURCE) == RCC_PLLSOURCE_NONE) || \
                                  ((SOURCE) == RCC_PLLSOURCE_HSE))

#define IS_RCC_PLLM_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 16U))
#define IS_RCC_PLLN_VALUE(VALUE) ((4 <= (VALUE)) && ((VALUE) <= 512U))
#define IS_RCC_PLLP_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 128U))
#define IS_RCC_PLLQ_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 128U))
#define IS_RCC_PLLR_VALUE(VALUE) ((1 <= (VALUE)) && ((VALUE) <= 128U))

#define IS_RCC_PLLCLOCKOUT_VALUE(VALUE) (((VALUE) == RCC_PLL1_DIVP) || \
                                         ((VALUE) == RCC_PLL1_DIVQ) || \
                                         ((VALUE) == RCC_PLL1_DIVR))


#define IS_RCC_PLLRGE_VALUE(VALUE) (((VALUE) == RCC_PLLVCIRANGE_0) || \
                                    ((VALUE) == RCC_PLLVCIRANGE_1) || \
                                    ((VALUE) == RCC_PLLVCIRANGE_2) || \
                                    ((VALUE) == RCC_PLLVCIRANGE_3))

#define IS_RCC_PLLFRACN_VALUE(VALUE) ((VALUE) <= 8191U)

#define IS_RCC_MSI_CLOCK_RANGE(__RANGE__) (((__RANGE__) == RCC_MSIRANGE_0)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_1)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_2)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_3)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_4)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_5)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_6)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_7)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_8)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_9)  || \
                                           ((__RANGE__) == RCC_MSIRANGE_10) || \
                                           ((__RANGE__) == RCC_MSIRANGE_11) || \
                                           ((__RANGE__) == RCC_MSIRANGE_12) || \
                                           ((__RANGE__) == RCC_MSIRANGE_13) || \
                                           ((__RANGE__) == RCC_MSIRANGE_14) || \
                                           ((__RANGE__) == RCC_MSIRANGE_15))

#define IS_RCC_MSI_STANDBY_CLOCK_RANGE(__RANGE__) (((__RANGE__) == RCC_MSIRANGE_4)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_5)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_6)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_7)  || \
                                                   ((__RANGE__) == RCC_MSIRANGE_8))

#define IS_RCC_MSIK_CLOCK_RANGE(__RANGE__) (((__RANGE__) == RCC_MSIKRANGE_0)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_1)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_2)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_3)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_4)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_5)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_6)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_7)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_8)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_9)  || \
                                            ((__RANGE__) == RCC_MSIKRANGE_10) || \
                                            ((__RANGE__) == RCC_MSIKRANGE_11) || \
                                            ((__RANGE__) == RCC_MSIKRANGE_12) || \
                                            ((__RANGE__) == RCC_MSIKRANGE_13) || \
                                            ((__RANGE__) == RCC_MSIKRANGE_14) || \
                                            ((__RANGE__) == RCC_MSIKRANGE_15))

#define IS_RCC_CLOCKTYPE(CLK) ((1 <= (CLK)) && ((CLK) <= 0x1FU))

#define IS_RCC_SYSCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_SYSCLKSOURCE_MSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSI) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_HSE) || \
                                         ((__SOURCE__) == RCC_SYSCLKSOURCE_PLLCLK))

#define IS_RCC_HCLK(__HCLK__) (((__HCLK__) == RCC_SYSCLK_DIV1)   || ((__HCLK__) == RCC_SYSCLK_DIV2)   || \
                               ((__HCLK__) == RCC_SYSCLK_DIV4)   || ((__HCLK__) == RCC_SYSCLK_DIV8)   || \
                               ((__HCLK__) == RCC_SYSCLK_DIV16)  || ((__HCLK__) == RCC_SYSCLK_DIV64)  || \
                               ((__HCLK__) == RCC_SYSCLK_DIV128) || ((__HCLK__) == RCC_SYSCLK_DIV256) || \
                               ((__HCLK__) == RCC_SYSCLK_DIV512))

#define IS_RCC_PCLK(__PCLK__) (((__PCLK__) == RCC_HCLK_DIV1) || ((__PCLK__) == RCC_HCLK_DIV2) || \
                               ((__PCLK__) == RCC_HCLK_DIV4) || ((__PCLK__) == RCC_HCLK_DIV8) || \
                               ((__PCLK__) == RCC_HCLK_DIV16))

#define IS_RCC_RTCCLKSOURCE(__SOURCE__) (((__SOURCE__) == RCC_RTCCLKSOURCE_NO_CLK) || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_LSE)    || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_LSI)    || \
                                         ((__SOURCE__) == RCC_RTCCLKSOURCE_HSE_DIV32))

#define IS_RCC_MCO(__MCOX__) ((__MCOX__) == RCC_MCO1)

#define IS_RCC_MCO1SOURCE(__SOURCE__) (((__SOURCE__) == RCC_MCO1SOURCE_NOCLOCK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_SYSCLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_MSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSE) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_PLL1CLK) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSI) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_LSE) || \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_HSI48)|| \
                                       ((__SOURCE__) == RCC_MCO1SOURCE_MSIK))

#define IS_RCC_MCODIV(__DIV__) (((__DIV__) == RCC_MCODIV_1) || ((__DIV__) == RCC_MCODIV_2) || \
                                ((__DIV__) == RCC_MCODIV_4) || ((__DIV__) == RCC_MCODIV_8) || \
                                ((__DIV__) == RCC_MCODIV_16))

#define IS_RCC_LSE_DRIVE(__DRIVE__) (((__DRIVE__) == RCC_LSEDRIVE_LOW)        || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMLOW)  || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_MEDIUMHIGH) || \
                                     ((__DRIVE__) == RCC_LSEDRIVE_HIGH))

#define IS_RCC_STOP_WAKEUPCLOCK(__SOURCE__) (((__SOURCE__) == RCC_STOP_WAKEUPCLOCK_MSI) || \
                                             ((__SOURCE__) == RCC_STOP_WAKEUPCLOCK_HSI))

#define IS_RCC_STOP_KERWAKEUPCLOCK(SOURCE) (((SOURCE) == RCC_STOP_KERWAKEUPCLOCK_MSI) || \
                                          ((SOURCE) == RCC_STOP_KERWAKEUPCLOCK_HSI))

#define IS_RCC_ITEM_ATTRIBUTES(ITEM) ((0U < (ITEM)) && ((ITEM) <= 0x1FFFU))


#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define IS_RCC_ATTRIBUTES(ATTRIBUTES) (((ATTRIBUTES) == RCC_SEC_PRIV)  || \
                                      ((ATTRIBUTES)  == RCC_SEC_NPRIV) || \
                                      ((ATTRIBUTES)  == RCC_NSEC_PRIV) || \
                                      ((ATTRIBUTES)  == RCC_NSEC_NPRIV))
#else
#define IS_RCC_ATTRIBUTES(ATTRIBUTES) (((ATTRIBUTES) == RCC_NSEC_NPRIV) || ((ATTRIBUTES) == RCC_NSEC_PRIV))
#endif /* __ARM_FEATURE_CMSE */
/**
  * @}
  */

/* Include RCC HAL Extended module */
#include "stm32u5xx_hal_rcc_ex.h"

/* Exported functions --------------------------------------------------------*/
/** @addtogroup RCC_Exported_Functions
  * @{
  */

/** @addtogroup RCC_Exported_Functions_Group1
  * @{
  */

/* Initialization and de-initialization functions  ******************************/
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency);

/**
  * @}
  */

/** @addtogroup RCC_Exported_Functions_Group2
  * @{
  */

/* Peripheral Control functions  **********************************************/
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
uint32_t          HAL_RCC_GetPCLK3Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t *pFLatency);
/* CSS NMI IRQ handler */
void              HAL_RCC_NMI_IRQHandler(void);
/* User Callbacks in non blocking mode (IT mode) */
void              HAL_RCC_CSSCallback(void);

/**
  * @}
  */

/* Attributes management functions ********************************************/
void              HAL_RCC_ConfigAttributes(uint32_t Item, uint32_t Attributes);
HAL_StatusTypeDef HAL_RCC_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes);

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
#endif

#endif /* __STM32U5xx_HAL_RCC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
