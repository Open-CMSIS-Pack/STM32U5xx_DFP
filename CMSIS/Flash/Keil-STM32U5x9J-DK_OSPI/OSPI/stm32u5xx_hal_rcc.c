/**
  ******************************************************************************
  * @file    stm32u5xx_hal_rcc.c
  * @author  MCD Application Team
  * @brief   RCC HAL module driver.
  *          This file provides firmware functions to manage the following
  *          functionalities of the Reset and Clock Control (RCC) peripheral:
  *           + Initialization and de-initialization functions
  *           + Peripheral Control functions
  *
  @verbatim
  ==============================================================================
                      ##### RCC specific features #####
  ==============================================================================
    [..]
      After reset the device is running from Multiple Speed Internal oscillator
      (4 MHz) with Flash 0 wait state. Flash prefetch buffer, D-Cache
      and I-Cache are disabled, and all peripherals are off except internal
      SRAM, Flash and JTAG.

      (+) There is no prescaler on High speed (AHBs) and Low speed (APBs) busses:
          all peripherals mapped on these busses are running at MSI speed.
      (+) The clock for all peripherals is switched off, except the SRAM and FLASH.
      (+) All GPIOs are in analog mode, except the JTAG pins which
          are assigned to be used for debug purpose.

    [..]
      Once the device started from reset, the user application has to:
      (+) Configure the clock source to be used to drive the System clock
          (if the application needs higher frequency/performance)
      (+) Configure the System clock frequency and Flash settings
      (+) Configure the AHB and APB busses prescalers
      (+) Enable the clock for the peripheral(s) to be used
      (+) Configure the clock source(s) for peripherals which clocks are not
          derived from the System clock (SAIx, RTC, ADC, USB OTG FS/SDMMC1/RNG)

  @endverbatim
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
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

/* Includes ------------------------------------------------------------------*/
#include "stm32u5xx_hal.h"

/** @addtogroup STM32U5xx_HAL_Driver
  * @{
  */

/** @defgroup RCC RCC
  * @brief RCC HAL module driver
  * @{
  */

#ifdef HAL_RCC_MODULE_ENABLED

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/** @defgroup RCC_Private_Constants RCC Private Constants
 * @{
 */
#define LSI_TIMEOUT_VALUE          ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
#define HSI48_TIMEOUT_VALUE        ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
#define SHSI_TIMEOUT_VALUE         ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
#define MSIK_TIMEOUT_VALUE         ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
#define PLL_TIMEOUT_VALUE          ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
#define CLOCKSWITCH_TIMEOUT_VALUE  ((uint32_t)5000U) /* 5 s    */
#define EPOD_TIMEOUT_VALUE         ((uint32_t)2U)    /* 2 ms (minimum Tick + 1) */
/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/
/** @defgroup RCC_Private_Macros RCC Private Macros
  * @{
  */

#define __MCO1_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

#define MCO1_GPIO_PORT        GPIOA

#define MCO1_PIN              GPIO_PIN_8

#define RCC_PLL_OSCSOURCE_CONFIG(__HAL_RCC_PLLSOURCE__) \
            (MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC, (uint32_t)(__HAL_RCC_PLLSOURCE__)))
/**
  * @}
  */

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/** @defgroup RCC_Private_Functions RCC Private Functions
  * @{
  */
static HAL_StatusTypeDef RCC_SetFlashLatencyFromMSIRange(uint32_t msirange);
/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/

/** @defgroup RCC_Exported_Functions RCC Exported Functions
  * @{
  */

/** @defgroup RCC_Exported_Functions_Group1 Initialization and de-initialization functions
  *  @brief    Initialization and Configuration functions
  *
  @verbatim
 ===============================================================================
           ##### Initialization and de-initialization functions #####
 ===============================================================================
    [..]
      This section provides functions allowing to configure the internal and external oscillators
      (HSE, HSI, LSE, MSI, LSI, PLL, CSS and MCO) and the System busses clocks (SYSCLK, AHB, APB1
       and APB2).

    [..] Internal/external clock and PLL configuration
         (+) HSI (high-speed internal): 16 MHz factory-trimmed RC used directly or through
             the PLL as System clock source.

         (+) MSI (Mutiple Speed Internal): Its frequency is software trimmable from 100KHZ to 48MHZ.
             It can be used to generate the clock for the USB OTG FS (48 MHz).
             The number of flash wait states is automatically adjusted when MSI range is updated with
             HAL_RCC_OscConfig() and the MSI is used as System clock source.

         (+) LSI (low-speed internal): 32 KHz low consumption RC used as IWDG and/or RTC
             clock source.

         (+) HSE (high-speed external): 4 to 48 MHz crystal oscillator used directly or
             through the PLL as System clock source. Can be used also optionally as RTC clock source.

         (+) LSE (low-speed external): 32.768 KHz oscillator used optionally as RTC clock source.

         (+) PLL (clocked by HSI, HSE or MSI) providing up to three independent output clocks:
           (++) The first output is used to generate the high speed system clock (up to 80MHz).
           (++) The second output is used to generate the clock for the USB OTG FS (48 MHz),
                the random analog generator (<=48 MHz) and the SDMMC1 (<= 48 MHz).
           (++) The third output is used to generate an accurate clock to achieve
                high-quality audio performance on SAI interface.

         (+) PLL2 (clocked by HSI, HSE or MSI) providing up to three independent output clocks:
           (++) The first output is used to generate SAR ADC1 clock.
           (++) The second output is used to generate the clock for the USB OTG FS (48 MHz),
                the random analog generator (<=48 MHz) and the SDMMC1 (<= 48 MHz).
           (++) The Third output is used to generate an accurate clock to achieve
                high-quality audio performance on SAI interface.

         (+) PLL3 (clocked by HSI , HSE or MSI) providing up to two independent output clocks:
           (++) The first output is used to generate SAR ADC2 clock.
           (++) The second  output is used to generate an accurate clock to achieve
                high-quality audio performance on SAI interface.

         (+) CSS (Clock security system): once enabled, if a HSE clock failure occurs
            (HSE used directly or through PLL as System clock source), the System clock
             is automatically switched to HSI and an interrupt is generated if enabled.
             The interrupt is linked to the Cortex-M4 NMI (Non-Maskable Interrupt)
             exception vector.

         (+) MCO (microcontroller clock output): used to output MSI, LSI, HSI, LSE, HSE or
             main PLL clock (through a configurable prescaler) on PA8 pin.

    [..] System, AHB and APB busses clocks configuration
         (+) Several clock sources can be used to drive the System clock (SYSCLK): MSI, HSI,
             HSE and main PLL.
             The AHB clock (HCLK) is derived from System clock through configurable
             prescaler and used to clock the CPU, memory and peripherals mapped
             on AHB bus (DMA, GPIO...). APB1 (PCLK1) and APB2 (PCLK2) clocks are derived
             from AHB clock through configurable prescalers and used to clock
             the peripherals mapped on these busses. You can use
             "HAL_RCC_GetSysClockFreq()" function to retrieve the frequencies of these clocks.

         -@- All the peripheral clocks are derived from the System clock (SYSCLK) except:

           (+@) SAI: the SAI clock can be derived either from a specific PLL (PLL2) or (PLL3) or
                from an external clock mapped on the SAI_CKIN pin.
                You have to use HAL_RCCEx_PeriphCLKConfig() function to configure this clock.
           (+@) RTC: the RTC clock can be derived either from the LSI, LSE or HSE clock
                divided by 2 to 31.
                You have to use __HAL_RCC_RTC_ENABLE() and HAL_RCCEx_PeriphCLKConfig() function
                to configure this clock.
           (+@) USB OTG FS, SDMMC1 and RNG: USB OTG FS requires a frequency equal to 48 MHz
                to work correctly, while the SDMMC1 and RNG peripherals require a frequency
                equal or lower than to 48 MHz. This clock is derived of the main PLL or PLL2
                through PLLQ divider. You have to enable the peripheral clock and use
                HAL_RCCEx_PeriphCLKConfig() function to configure this clock.
           (+@) IWDG clock which is always the LSI clock.


         (+) The maximum frequency of the SYSCLK, HCLK, PCLK1 and PCLK2 is 80 MHz.
             The clock source frequency should be adapted depending on the device voltage range
             as listed in the Reference Manual "Clock source frequency versus voltage scaling" chapter.

  @endverbatim


           Table 1. HCLK clock frequency for STM32U5xx devices
           +-------------------------------------------------------+----------------------------------------+
           | Latency         |                    HCLK clock frequency (MHz) 0.9V-1.2V                      |
           |                 |-------------------------------------|---------------------+------------------|
           |                 | voltage range 1  | voltage range 2  |   voltage range 3   |  voltage range 4 |
           |                 |  1.1 V - 1.2V    |  1.0 V - 1.1V    |    0.9 V - 1.0V     |       0.9V       |
           |-----------------|------------------|------------------|---------------------|------------------|
           |0WS(1 CPU cycles)|  0 < HCLK <= 32  |  0 < HCLK <= 25  |    0 < HCLK <= 12.5 |  0 < HCLK <= 8   |
           |-----------------|------------------|------------------|---------------------|------------------|
           |1WS(2 CPU cycles)| 32 < HCLK <= 64  | 25 < HCLK <= 50  | 12.5 < HCLK <= 25   |  8 < HCLK <= 16  |
           |-----------------|------------------|------------------|---------------------|------------------|
           |2WS(3 CPU cycles)| 64 < HCLK <= 96  | 50 < HCLK <= 75  |  25 < HCLK <= 37.5  | 16 < HCLK <= 24  |
           |-----------------|------------------|------------------|---------------------|------------------|
           |3WS(4 CPU cycles)| 96 < HCLK <= 128 | 75 < HCLK <= 100 |  37.5 < HCLK <= 50  |        -         |
           |-----------------|------------------|------------------|---------------------|------------------|
           |4WS(5 CPU cycles)|128 < HCLK <= 160 |         -        |         -           |        -         |
           +-----------------+------------------+------------------+---------------------+------------------+
  * @{
  */

/**
  * @brief  Reset the RCC clock configuration to the default reset state.
  * @note   The default reset state of the clock configuration is given below:
  *            - MSI ON and used as system clock source
  *            - HSE, HSI, PLL, PLL2 and PLLISAI2 OFF
  *            - AHB, APB1 and APB2 prescaler set to 1.
  *            - CSS, MCO1 OFF
  *            - All interrupts disabled
  * @note   This function doesn't modify the configuration of the
  *            - Peripheral clocks
  *            - LSI, LSE and RTC clocks
  * @retval None
  */

HAL_StatusTypeDef HAL_RCC_DeInit(void)
{
  uint32_t tickstart;

  /* Increasing the CPU frequency */
  if (FLASH_LATENCY_DEFAULT  > __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_DEFAULT);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLASH_LATENCY_DEFAULT)
    {
      return HAL_ERROR;
    }

  }

  /* Get start tick*/
  tickstart = HAL_GetTick();

  /* Set MSION bit */
  SET_BIT(RCC->CR, RCC_CR_MSISON);

  /* Insure MSIRDY bit is set before writing default MSIRANGE value */
  while (READ_BIT(RCC->CR, RCC_CR_MSISRDY) == RESET)
  {
    if ((HAL_GetTick() - tickstart) > MSI_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Set MSIRANGE default value */
  MODIFY_REG(RCC->ICSCR1, RCC_ICSCR1_MSISRANGE, RCC_MSIRANGE_4);

  /* Set MSITRIM default value */
  WRITE_REG(RCC->ICSCR2, 0x00084210U);

  /* Set MSIKRANGE default value */
  MODIFY_REG(RCC->ICSCR1, RCC_ICSCR1_MSIKRANGE, RCC_MSIKRANGE_4);

  /* Set MSIRGSEL default value */
  MODIFY_REG(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL, 0x0U);

  /* Get start tick*/
  tickstart = HAL_GetTick();

  /* Reset CFGR register (MSI is selected as system clock source) */
  CLEAR_REG(RCC->CFGR1);
  CLEAR_REG(RCC->CFGR2);

  /* Wait till clock switch is ready */
  while (READ_BIT(RCC->CFGR1, RCC_CFGR1_SWS) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Reset MSIKON, HSECSSON , HSEON, HSEBYP, HSION, HSIKERON, PLL1ON, PLL2ON, PLL3ON bits */
  CLEAR_BIT(RCC->CR, RCC_CR_MSIKON | RCC_CR_MSIPLLSEL | RCC_CR_MSIPLLFAST | RCC_CR_MSIKERON | RCC_CR_CSSON |  RCC_CR_HSION | RCC_CR_HSIKERON | RCC_CR_PLL1ON | RCC_CR_PLL2ON | RCC_CR_PLL3ON | RCC_CR_HSI48ON | RCC_CR_HSEON  | RCC_CR_SHSION);

  /* Reset HSEBYP & HSEEXT bits */
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP | RCC_CR_HSEEXT);

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Clear PLL1ON bit */
  CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON);

  /* Wait till PLL1 is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_PLL1RDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Reset PLL2N bit */
  CLEAR_BIT(RCC->CR, RCC_CR_PLL2ON);

  /* Wait till PLL2 is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_PLL2RDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Get Start Tick */
  tickstart = HAL_GetTick();

  /* Reset PLL3 bit */
  CLEAR_BIT(RCC->CR, RCC_CR_PLL3ON);

  /* Wait till PLL3 is disabled */
  while (READ_BIT(RCC->CR, RCC_CR_PLL3RDY) != RESET)
  {
    if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
    {
      return HAL_TIMEOUT;
    }
  }

  /* Reset PLL1CFGR register */
  CLEAR_REG(RCC->PLL1CFGR);

  /* Reset PLL1DIVR register */
  WRITE_REG(RCC->PLL1DIVR, 0x01010280U);

  /* Reset PLL1FRACR register */
  CLEAR_REG(RCC->PLL1FRACR);

  /* Reset PLL2CFGR register */
  CLEAR_REG(RCC->PLL2CFGR);

  /* Reset PLL2DIVR register */
  WRITE_REG(RCC->PLL2DIVR, 0x01010280U);

  /* Reset PLL2FRACR register */
  CLEAR_REG(RCC->PLL2FRACR);

  /* Reset PLL3CFGR register */
  CLEAR_REG(RCC->PLL3CFGR);

  /* Reset PLL3DIVR register */
  WRITE_REG(RCC->PLL3DIVR, 0x01010280U);

  /* Reset PLL3FRACR register */
  CLEAR_REG(RCC->PLL3FRACR);

  /* Disable all interrupts */
  CLEAR_REG(RCC->CIER);

  /* Clear all interrupt flags */
  WRITE_REG(RCC->CICR, 0xFFFFFFFFU);

  /* Reset all CSR flags */
  SET_BIT(RCC->CSR, RCC_CSR_RMVF);

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = MSI_VALUE;

  /* Decreasing the number of wait states because of lower CPU frequency */
  if (FLASH_LATENCY_DEFAULT  < __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_DEFAULT);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLASH_LATENCY_DEFAULT)
    {
      return HAL_ERROR;
    }
  }

  /* Adapt Systick interrupt period */
  if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
  {
    return HAL_ERROR;
  }
  else
  {
    return HAL_OK;
  }
}

/**
  * @brief  Initialize the RCC Oscillators according to the specified parameters in the
  *         RCC_OscInitTypeDef.
  * @param  RCC_OscInitStruct  pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC Oscillators.
  * @note   The PLL is not disabled when used as system clock.
  * @note   Transitions LSE Bypass to LSE On and LSE On to LSE Bypass are not
  *         supported by this macro. User should request a transition to LSE Off
  *         first and then LSE On or LSE Bypass.
  * @note   Transition HSE Bypass to HSE On and HSE On to HSE Bypass are not
  *         supported by this macro. User should request a transition to HSE Off
  *         first and then HSE On or HSE Bypass.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  uint32_t tickstart = 0;

  /* Check the parameters */
  assert_param(RCC_OscInitStruct != NULL);
  assert_param(IS_RCC_OSCILLATORTYPE(RCC_OscInitStruct->OscillatorType));

  /*----------------------------- MSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_MSI) == RCC_OSCILLATORTYPE_MSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_MSI(RCC_OscInitStruct->MSIState));
    assert_param(IS_RCC_MSICALIBRATION_VALUE(RCC_OscInitStruct->MSICalibrationValue));
    assert_param(IS_RCC_MSI_CLOCK_RANGE(RCC_OscInitStruct->MSIClockRange));

    /* When the MSI is used as system clock it will not be disabled */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_MSI))
    {
      if ((READ_BIT(RCC->CR, RCC_CR_MSISRDY) != RESET) && (RCC_OscInitStruct->MSIState == RCC_MSI_OFF))
      {
        return HAL_ERROR;
      }

      /* Otherwise, just the calibration and MSI range change are allowed */
      else
      {
        /* To correctly read data from FLASH memory, the number of wait states (LATENCY)
           must be correctly programmed according to the frequency of the CPU clock
           (HCLK) and the supply voltage of the device. */
        if (RCC_OscInitStruct->MSIClockRange > __HAL_RCC_GET_MSI_RANGE())
        {
          /* First increase number of wait states update if necessary */
          if (RCC_SetFlashLatencyFromMSIRange(RCC_OscInitStruct->MSIClockRange) != HAL_OK)
          {
            return HAL_ERROR;
          }

          /* Selects the Multiple Speed oscillator (MSI) clock range .*/
          __HAL_RCC_MSI_RANGE_CONFIG(RCC_OscInitStruct->MSIClockRange);
          /* Adjusts the Multiple Speed oscillator (MSI) calibration value.*/
          __HAL_RCC_MSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->MSICalibrationValue, RCC_OscInitStruct->MSIClockRange);
        }
        else
        {
          /* Else, keep current flash latency while decreasing applies */
          /* Selects the Multiple Speed oscillator (MSI) clock range .*/
          __HAL_RCC_MSI_RANGE_CONFIG(RCC_OscInitStruct->MSIClockRange);
          /* Adjusts the Multiple Speed oscillator (MSI) calibration value.*/
          __HAL_RCC_MSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->MSICalibrationValue, RCC_OscInitStruct->MSIClockRange);

          /* Decrease number of wait states update if necessary */
          if (RCC_SetFlashLatencyFromMSIRange(RCC_OscInitStruct->MSIClockRange) != HAL_OK)
          {
            return HAL_ERROR;
          }
        }

        /* Update the SystemCoreClock global variable */
        SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR2 & RCC_CFGR2_HPRE) >> RCC_CFGR2_HPRE_Pos];

        /* Configure the source of time base considering new system clocks settings*/
        HAL_InitTick(uwTickPrio);
      }
    }
    else
    {
      /* Check the MSI State */
      if (RCC_OscInitStruct->MSIState != RCC_MSI_OFF)
      {
        /* Enable the Internal High Speed oscillator (MSI). */
        __HAL_RCC_MSI_ENABLE();

        /* Get timeout */
        tickstart = HAL_GetTick();

        /* Wait till MSI is ready */
        while (READ_BIT(RCC->CR, RCC_CR_MSISRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > MSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
        /* Selects the Multiple Speed oscillator (MSI) clock range .*/
        __HAL_RCC_MSI_RANGE_CONFIG(RCC_OscInitStruct->MSIClockRange);
        /* Adjusts the Multiple Speed oscillator (MSI) calibration value.*/
        __HAL_RCC_MSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->MSICalibrationValue, RCC_OscInitStruct->MSIClockRange);

      }
      else
      {
        /* Disable the Internal High Speed oscillator (MSI). */
        __HAL_RCC_MSI_DISABLE();

        /* Get timeout */
        tickstart = HAL_GetTick();

        /* Wait till MSI is ready */
        while (READ_BIT(RCC->CR, RCC_CR_MSISRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > MSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*------------------------------- HSE Configuration ------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSE) == RCC_OSCILLATORTYPE_HSE)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSE(RCC_OscInitStruct->HSEState));

    /* When the HSE is used as system clock or clock source for PLL in these cases it is not allowed to be disabled */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_HSE) ||
        ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_PLL1) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSE)))
    {
      if ((READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET) && (RCC_OscInitStruct->HSEState == RCC_HSE_OFF))
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* Set the new HSE configuration ---------------------------------------*/
      __HAL_RCC_HSE_CONFIG(RCC_OscInitStruct->HSEState);

      /* Check the HSE State */
      if (RCC_OscInitStruct->HSEState != RCC_HSE_OFF)
      {
        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSE is ready */
        while (READ_BIT(RCC->CR, RCC_CR_HSERDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSE is disabled */
        while (READ_BIT(RCC->CR, RCC_CR_HSERDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*----------------------------- HSI Configuration --------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI) == RCC_OSCILLATORTYPE_HSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI(RCC_OscInitStruct->HSIState));
    assert_param(IS_RCC_HSI_CALIBRATION_VALUE(RCC_OscInitStruct->HSICalibrationValue));

    /* Check if HSI is used as system clock or as PLL source when PLL is selected as system clock */
    if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_HSI) ||
        ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_PLL1) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_HSI)))
    {
      /* When HSI is used as system clock it will not be disabled */
      if ((READ_BIT(RCC->CR, RCC_CR_HSIRDY) != RESET) && (RCC_OscInitStruct->HSIState == RCC_HSI_OFF))
      {
        return HAL_ERROR;
      }
      /* Otherwise, just the calibration is allowed */
      else
      {
        /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
    }
    else
    {
      /* Check the HSI State */
      if (RCC_OscInitStruct->HSIState != RCC_HSI_OFF)
      {
        /* Enable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_ENABLE();

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSI is ready */
        while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        /* Adjusts the Internal High Speed oscillator (HSI) calibration value.*/
        __HAL_RCC_HSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->HSICalibrationValue);
      }
      else
      {
        /* Disable the Internal High Speed oscillator (HSI). */
        __HAL_RCC_HSI_DISABLE();

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till HSI is disabled */
        while (READ_BIT(RCC->CR, RCC_CR_HSIRDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > HSI_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }
  /*------------------------------ LSI Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSI) == RCC_OSCILLATORTYPE_LSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_LSI(RCC_OscInitStruct->LSIState));

    FlagStatus       pwrclkchanged = RESET;

    /* Update LSI configuration in Backup Domain control register    */
    /* Requires to enable write access to Backup Domain of necessary */
    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->DBPR, PWR_DBPR_DBP))
    {
      /* Enable write access to Backup domain */
      SET_BIT(PWR->DBPR, PWR_DBPR_DBP);

      /* Wait for Backup domain Write protection disable */
      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->DBPR, PWR_DBPR_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    /* Check the LSI State */
    if (RCC_OscInitStruct->LSIState != RCC_LSI_OFF)
    {
      /* Enable the Internal Low Speed oscillator (LSI). */
      __HAL_RCC_LSI_ENABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till LSI is ready */
      while (READ_BIT(RCC->BDCR, RCC_BDCR_LSIRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal Low Speed oscillator (LSI). */
      __HAL_RCC_LSI_DISABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till LSI is disabled */
      while (READ_BIT(RCC->BDCR, RCC_BDCR_LSIRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > LSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    /* Restore clock configuration if changed */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }
  /*------------------------------ LSE Configuration -------------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_LSE) == RCC_OSCILLATORTYPE_LSE)
  {
    FlagStatus       pwrclkchanged = RESET;

    /* Check the parameters */
    assert_param(IS_RCC_LSE(RCC_OscInitStruct->LSEState));

    /* Update LSE configuration in Backup Domain control register    */
    /* Requires to enable write access to Backup Domain of necessary */
    if (__HAL_RCC_PWR_IS_CLK_DISABLED())
    {
      __HAL_RCC_PWR_CLK_ENABLE();
      pwrclkchanged = SET;
    }

    if (HAL_IS_BIT_CLR(PWR->DBPR, PWR_DBPR_DBP))
    {
      /* Enable write access to Backup domain */
      SET_BIT(PWR->DBPR, PWR_DBPR_DBP);

      /* Wait for Backup domain Write protection disable */
      tickstart = HAL_GetTick();

      while (HAL_IS_BIT_CLR(PWR->DBPR, PWR_DBPR_DBP))
      {
        if ((HAL_GetTick() - tickstart) > RCC_DBP_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }

    /* Set the new LSE configuration -----------------------------------------*/
    if ((RCC_OscInitStruct->LSEState & RCC_BDCR_LSEON) != 0U)
    {
      if ((RCC_OscInitStruct->LSEState & RCC_BDCR_LSEBYP) != 0U)
      {
        /* LSE oscillator bypass enable */
        SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
      }
      else
      {
        /* LSE oscillator enable */
        SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
      }
    }
    else
    {
      CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);
      CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
    }

    /* Check the LSE State */
    if (RCC_OscInitStruct->LSEState != RCC_LSE_OFF)
    {
      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till LSE is ready */
      while (READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == 0U)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }

      /* Enable LSESYS additionnally if requested */
      if ((RCC_OscInitStruct->LSEState & RCC_BDCR_LSESYSEN) != 0U)
      {
        SET_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN);

        /* Wait till LSESYS is ready */
        while (READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSRDY) == 0U)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Make sure LSESYSEN/LSESYSRDY are reset */
        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN);

        /* Wait till LSESYSRDY is cleared */
        while (READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSRDY) != 0U)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {
      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till LSE is disabled */
      while (READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) != 0U)
      {
        if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }

      if (READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN) != 0U)
      {
        /* Reset LSESYSEN once LSE is disabled */
        CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSESYSEN);

        /* Wait till LSESYSRDY is cleared */
        while (READ_BIT(RCC->BDCR, RCC_BDCR_LSESYSRDY) != 0U)
        {
          if ((HAL_GetTick() - tickstart) > RCC_LSE_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }

    /* Restore clock configuration if changed */
    if (pwrclkchanged == SET)
    {
      __HAL_RCC_PWR_CLK_DISABLE();
    }
  }
  /*------------------------------ HSI48 Configuration -----------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_HSI48) == RCC_OSCILLATORTYPE_HSI48)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI48(RCC_OscInitStruct->HSI48State));

    /* Check the LSI State */
    if (RCC_OscInitStruct->HSI48State != RCC_HSI48_OFF)
    {
      /* Enable the Internal Low Speed oscillator (HSI48). */
      __HAL_RCC_HSI48_ENABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till HSI48 is ready */
      while (READ_BIT(RCC->CR, RCC_CR_HSI48RDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > HSI48_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal Low Speed oscillator (HSI48). */
      __HAL_RCC_HSI48_DISABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till HSI48 is disabled */
      while (READ_BIT(RCC->CRRCR, RCC_CR_HSI48RDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > HSI48_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }

  /*------------------------------ SHSI Configuration -----------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_SHSI) == RCC_OSCILLATORTYPE_SHSI)
  {
    /* Check the parameters */
    assert_param(IS_RCC_HSI48(RCC_OscInitStruct->HSI48State));

    /* Check the LSI State */
    if (RCC_OscInitStruct->SHSIState != RCC_SHSI_OFF)
    {
      /* Enable the Internal Low Speed oscillator (HSI48). */
      __HAL_RCC_SHSI_ENABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till HSI48 is ready */
      while (READ_BIT(RCC->CR, RCC_CR_SHSIRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > SHSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal Low Speed oscillator (HSI48). */
      __HAL_RCC_SHSI_DISABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till HSI48 is disabled */
      while (READ_BIT(RCC->CRRCR, RCC_CR_SHSIRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > SHSI_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }
  /*------------------------------ MSIK Configuration -----------------------*/
  if (((RCC_OscInitStruct->OscillatorType) & RCC_OSCILLATORTYPE_MSIK) == RCC_OSCILLATORTYPE_MSIK)
  {
    /* Check the parameters */
    assert_param(IS_RCC_MSIK(RCC_OscInitStruct->MSIKState));
    assert_param(IS_RCC_MSIK_CLOCK_RANGE(RCC_OscInitStruct->MSIKClockRange));
    assert_param(IS_RCC_MSICALIBRATION_VALUE(RCC_OscInitStruct->MSICalibrationValue));

    /* Check the MSIK State */
    if (RCC_OscInitStruct->MSIKState != RCC_MSIK_OFF)
    {

      /* Selects the Multiple Speed oscillator (MSIK) clock range .*/
      __HAL_RCC_MSIK_RANGE_CONFIG(RCC_OscInitStruct->MSIKClockRange);
      /* Adjusts the Multiple Speed kernel oscillator (MSIK) calibration value.*/
      __HAL_RCC_MSI_CALIBRATIONVALUE_ADJUST(RCC_OscInitStruct->MSICalibrationValue, RCC_OscInitStruct->MSIClockRange);
      /* Enable the Internal Low Speed oscillator (MSIK). */
      __HAL_RCC_MSIK_ENABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till MSIK is ready */
      while (READ_BIT(RCC->CR, RCC_CR_MSIKRDY) == RESET)
      {
        if ((HAL_GetTick() - tickstart) > MSIK_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      /* Disable the Internal Low Speed oscillator (MSIK). */
      __HAL_RCC_MSIK_DISABLE();

      /* Get Start Tick*/
      tickstart = HAL_GetTick();

      /* Wait till MSIK is disabled */
      while (READ_BIT(RCC->CRRCR, RCC_CR_MSIKRDY) != RESET)
      {
        if ((HAL_GetTick() - tickstart) > MSIK_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
  }
  /*-------------------------------- PLL Configuration -----------------------*/
  /* Check the parameters */
  assert_param(IS_RCC_PLL(RCC_OscInitStruct->PLL.PLLState));

  if ((RCC_OscInitStruct->PLL.PLLState) != RCC_PLL_NONE)
  {
    /* Check if the PLL is used as system clock or not */
    if (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR1_SWS_PLL1)
    {
      if ((RCC_OscInitStruct->PLL.PLLState) == RCC_PLL_ON)
      {
        /* Check the parameters */
        assert_param(IS_RCC_PLLSOURCE(RCC_OscInitStruct->PLL.PLLSource));
        assert_param(IS_RCC_PLLM_VALUE(RCC_OscInitStruct->PLL.PLLM));
        assert_param(IS_RCC_PLLN_VALUE(RCC_OscInitStruct->PLL.PLLN));
        assert_param(IS_RCC_PLLP_VALUE(RCC_OscInitStruct->PLL.PLLP));
        assert_param(IS_RCC_PLLQ_VALUE(RCC_OscInitStruct->PLL.PLLQ));
        assert_param(IS_RCC_PLLR_VALUE(RCC_OscInitStruct->PLL.PLLR));

        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till PLL is ready */
        while (READ_BIT(RCC->CR, RCC_CR_PLL1RDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }

        /* Configure the main PLL clock source, multiplication and division factors. */
        __HAL_RCC_PLL_CONFIG(RCC_OscInitStruct->PLL.PLLSource,
                             RCC_OscInitStruct->PLL.PLLM,
                             RCC_OscInitStruct->PLL.PLLN,
                             RCC_OscInitStruct->PLL.PLLP,
                             RCC_OscInitStruct->PLL.PLLQ,
                             RCC_OscInitStruct->PLL.PLLR);

        assert_param(IS_RCC_PLLFRACN_VALUE(RCC_OscInitStruct->PLL.PLLFRACN));

        /* Disable PLL1FRACN . */
        __HAL_RCC_PLLFRACN_DISABLE();

        /* Configure PLL  PLL1FRACN */
        __HAL_RCC_PLLFRACN_CONFIG(RCC_OscInitStruct->PLL.PLLFRACN);

        /* Enable PLL1FRACN . */
        __HAL_RCC_PLLFRACN_ENABLE();

        assert_param(IS_RCC_PLLRGE_VALUE(RCC_OscInitStruct->PLL.PLLRGE));

        /* Select PLL1 input reference frequency range: VCI */
        __HAL_RCC_PLL_VCIRANGE(RCC_OscInitStruct->PLL.PLLRGE) ;

        /* Enable PLL System Clock output. */
        __HAL_RCC_PLLCLKOUT_ENABLE(RCC_PLL1_DIVR);

        /* Enable the main PLL. */
        __HAL_RCC_PLL_ENABLE();

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till PLL is ready */
        while (READ_BIT(RCC->CR, RCC_CR_PLL1RDY) == RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        /* Disable the main PLL. */
        __HAL_RCC_PLL_DISABLE();

        /* Disable all PLL outputs to save power if no PLLs on */
        if ((READ_BIT(RCC->CR, RCC_CR_PLL2RDY) == RESET)
            &&
            (READ_BIT(RCC->CR, RCC_CR_PLL3RDY) == RESET)
           )
        {
          MODIFY_REG(RCC->PLL1CFGR, RCC_PLL1CFGR_PLL1SRC, RCC_PLLSOURCE_NONE);
        }

        __HAL_RCC_PLLCLKOUT_DISABLE(RCC_PLL1_DIVP | RCC_PLL1_DIVQ | RCC_PLL1_DIVR);

        /* Get Start Tick*/
        tickstart = HAL_GetTick();

        /* Wait till PLL is disabled */
        while (READ_BIT(RCC->CR, RCC_CR_PLL1RDY) != RESET)
        {
          if ((HAL_GetTick() - tickstart) > PLL_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
    else
    {
      return HAL_ERROR;
    }
  }
  return HAL_OK;
}

/**
  * @brief  Initialize the CPU, AHB and APB busses clocks according to the specified
  *         parameters in the RCC_ClkInitStruct.
  * @param  RCC_ClkInitStruct  pointer to an RCC_OscInitTypeDef structure that
  *         contains the configuration information for the RCC peripheral.
  * @param  FLatency  FLASH Latency
  *          This parameter can be one of the following values:
  *            @arg FLASH_LATENCY_0   FLASH 0 Latency cycle
  *            @arg FLASH_LATENCY_1   FLASH 1 Latency cycle
  *            @arg FLASH_LATENCY_2   FLASH 2 Latency cycles
  *            @arg FLASH_LATENCY_3   FLASH 3 Latency cycles
  *            @arg FLASH_LATENCY_4   FLASH 4 Latency cycles
  *            @arg FLASH_LATENCY_5   FLASH 5 Latency cycles

  @endif
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency
  *         and updated by HAL_RCC_GetHCLKFreq() function called within this function
  *
  * @note   The MSI is used by default as system clock source after
  *         startup from Reset, wake-up from STANDBY mode. After restart from Reset,
  *         the MSI frequency is set to its default value 4 MHz.
  *
  * @note   The HSI can be selected as system clock source after
  *         from STOP modes or in case of failure of the HSE used directly or indirectly
  *         as system clock (if the Clock Security System CSS is enabled).
  *
  * @note   A switch from one clock source to another occurs only if the target
  *         clock source is ready (clock stable after startup delay or PLL locked).
  *         If a clock source which is not yet ready is selected, the switch will
  *         occur when the clock source is ready.
  *
  * @note   You can use HAL_RCC_GetClockConfig() function to know which clock is
  *         currently used as system clock source.
  *
  * @note   Depending on the device voltage range, the software has to set correctly
  *         HPRE[3:0] bits to ensure that HCLK not exceed the maximum allowed frequency
  *         (for more details refer to section above "Initialization/de-initialization functions")
  * @retval None
  */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency)
{
  HAL_StatusTypeDef halstatus;
  uint32_t tickstart = 0;

  /* Check the parameters */
  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(IS_RCC_CLOCKTYPE(RCC_ClkInitStruct->ClockType));
  assert_param(IS_FLASH_LATENCY(FLatency));

  /* To correctly read data from FLASH memory, the number of wait states (LATENCY)
    must be correctly programmed according to the frequency of the CPU clock
    (HCLK) and the supply voltage of the device. */

  /* Increasing the number of wait states because of higher CPU frequency */
  if (FLatency > __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLatency);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      return HAL_ERROR;
    }
  }

  /* Increasing the BUS frequency divider */
  /*-------------------------- PCLK3 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK3) == RCC_CLOCKTYPE_PCLK3)
  {
    if ((RCC_ClkInitStruct->APB3CLKDivider) > (RCC->CFGR3 & RCC_CFGR3_PPRE3))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB3CLKDivider));
      MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PPRE3, RCC_ClkInitStruct->APB3CLKDivider);
    }
  }
  /*-------------------------- PCLK2 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
  {
    if ((RCC_ClkInitStruct->APB2CLKDivider) > (RCC->CFGR2 & RCC_CFGR2_PPRE2))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB2CLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PPRE2, ((RCC_ClkInitStruct->APB2CLKDivider) << 4));
    }
  }

  /*-------------------------- PCLK1 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
  {
    if ((RCC_ClkInitStruct->APB1CLKDivider) > (RCC->CFGR2 & RCC_CFGR2_PPRE1))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB1CLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PPRE1, RCC_ClkInitStruct->APB1CLKDivider);
    }
  }

  /*-------------------------- HCLK Configuration --------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {
    if ((RCC_ClkInitStruct->AHBCLKDivider) > (RCC->CFGR2 & RCC_CFGR2_HPRE))
    {
      assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
    }
  }

  /*------------------------- SYSCLK Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_SYSCLK) == RCC_CLOCKTYPE_SYSCLK)
  {
    assert_param(IS_RCC_SYSCLKSOURCE(RCC_ClkInitStruct->SYSCLKSource));

    /* PLL is selected as System Clock Source */
    if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {
      __HAL_RCC_PWR_CLK_ENABLE();

      /* Check if EPOD is enabled */
      if (READ_BIT(PWR->VOSR, PWR_VOSR_BOOSTEN) != RESET)
      {
        /* Wait till BOOST is ready */
        while(READ_BIT(PWR->VOSR, PWR_VOSR_BOOSTRDY) == RESET)
        {
          if((HAL_GetTick() - tickstart) > EPOD_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }

      __HAL_RCC_PWR_CLK_DISABLE();

      /* Check the PLL ready flag */
      if (READ_BIT(RCC->CR, RCC_CR_PLL1RDY) == RESET)
      {
        return HAL_ERROR;
      }
    }
    else
    {
      /* HSE is selected as System Clock Source */
      if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
      {
        /* Check the HSE ready flag */
        if (READ_BIT(RCC->CR, RCC_CR_HSERDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* MSI is selected as System Clock Source */
      else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_MSI)
      {
        /* Check the MSI ready flag */
        if (READ_BIT(RCC->CR, RCC_CR_MSISRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
      /* HSI is selected as System Clock Source */
      else
      {
        /* Check the HSI ready flag */
        if (READ_BIT(RCC->CR, RCC_CR_HSIRDY) == RESET)
        {
          return HAL_ERROR;
        }
      }
    }

    MODIFY_REG(RCC->CFGR1, RCC_CFGR1_SW, RCC_ClkInitStruct->SYSCLKSource);

    /* Get Start Tick*/
    tickstart = HAL_GetTick();

    if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_PLLCLK)
    {
      while (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR1_SWS_PLL1)
      {
        if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
        {
          return HAL_TIMEOUT;
        }
      }
    }
    else
    {
      if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_HSE)
      {
        while (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR1_SWS_HSE)
        {
          if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else if (RCC_ClkInitStruct->SYSCLKSource == RCC_SYSCLKSOURCE_MSI)
      {
        while (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR1_SWS_MSI)
        {
          if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
      else
      {
        while (__HAL_RCC_GET_SYSCLK_SOURCE() != RCC_CFGR1_SWS_HSI)
        {
          if ((HAL_GetTick() - tickstart) > CLOCKSWITCH_TIMEOUT_VALUE)
          {
            return HAL_TIMEOUT;
          }
        }
      }
    }
  }

  /* Decreasing the BUS frequency divider */
  /*-------------------------- HCLK Configuration --------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_HCLK) == RCC_CLOCKTYPE_HCLK)
  {
    if ((RCC_ClkInitStruct->AHBCLKDivider) < (RCC->CFGR2 & RCC_CFGR2_HPRE))
    {
      assert_param(IS_RCC_HCLK(RCC_ClkInitStruct->AHBCLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_HPRE, RCC_ClkInitStruct->AHBCLKDivider);
    }
  }

  /* Decreasing the number of wait states because of lower CPU frequency */
  if (FLatency < __HAL_FLASH_GET_LATENCY())
  {
    /* Program the new number of wait states to the LATENCY bits in the FLASH_ACR register */
    __HAL_FLASH_SET_LATENCY(FLatency);

    /* Check that the new number of wait states is taken into account to access the Flash
    memory by reading the FLASH_ACR register */
    if (__HAL_FLASH_GET_LATENCY() != FLatency)
    {
      return HAL_ERROR;
    }
  }

  /*-------------------------- PCLK1 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK1) == RCC_CLOCKTYPE_PCLK1)
  {
    if ((RCC_ClkInitStruct->APB1CLKDivider) < (RCC->CFGR2 & RCC_CFGR2_PPRE1))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB1CLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PPRE1, RCC_ClkInitStruct->APB1CLKDivider);
    }
  }

  /*-------------------------- PCLK2 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK2) == RCC_CLOCKTYPE_PCLK2)
  {
    if ((RCC_ClkInitStruct->APB2CLKDivider) < (RCC->CFGR2 & RCC_CFGR2_PPRE2))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB2CLKDivider));
      MODIFY_REG(RCC->CFGR2, RCC_CFGR2_PPRE2, ((RCC_ClkInitStruct->APB2CLKDivider) << 4));
    }
  }

  /*-------------------------- PCLK3 Configuration ---------------------------*/
  if (((RCC_ClkInitStruct->ClockType) & RCC_CLOCKTYPE_PCLK3) == RCC_CLOCKTYPE_PCLK3)
  {
    if ((RCC_ClkInitStruct->APB3CLKDivider) < (RCC->CFGR3 & RCC_CFGR3_PPRE3))
    {
      assert_param(IS_RCC_PCLK(RCC_ClkInitStruct->APB3CLKDivider));
      MODIFY_REG(RCC->CFGR3, RCC_CFGR3_PPRE3, RCC_ClkInitStruct->APB3CLKDivider);
    }
  }

  /* Update the SystemCoreClock global variable */
  SystemCoreClock = HAL_RCC_GetSysClockFreq() >> AHBPrescTable[(RCC->CFGR2 & RCC_CFGR2_HPRE) >> RCC_CFGR2_HPRE_Pos];

  /* Configure the source of time base considering new system clocks settings*/
  halstatus = HAL_InitTick(uwTickPrio);

  return halstatus;
}

/**
  * @}
  */

/** @defgroup RCC_Exported_Functions_Group2 Peripheral Control functions
 *  @brief   RCC clocks control functions
 *
@verbatim
 ===============================================================================
                      ##### Peripheral Control functions #####
 ===============================================================================
    [..]
    This subsection provides a set of functions allowing to:

    (+) Ouput clock to MCO pin.
    (+) Retrieve current clock frequencies.
    (+) Enable the Clock Security System.

@endverbatim
  * @{
  */

/**
  * @brief  Select the clock source to output on MCO pin(PA8).
  * @note   PA8 should be configured in alternate function mode.
  * @param  RCC_MCOx  specifies the output direction for the clock source.
  *          For STM32U5xx family this parameter can have only one value:
  *            @arg @ref RCC_MCO1  Clock source to output on MCO1 pin(PA8).
  * @param  RCC_MCOSource  specifies the clock source to output.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCO1SOURCE_NOCLOCK  MCO output disabled, no clock on MCO
  *            @arg @ref RCC_MCO1SOURCE_SYSCLK  system  clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_MSI  MSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSI  HSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSE  HSE clock selected as MCO sourcee
  *            @arg @ref RCC_MCO1SOURCE_PLL1CLK  main PLL clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_LSI  LSI clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_LSE  LSE clock selected as MCO source
  *            @arg @ref RCC_MCO1SOURCE_HSI48  HSI48 clock selected as MCO source for devices with HSI48
  @endif
  * @param  RCC_MCODiv  specifies the MCO prescaler.
  *          This parameter can be one of the following values:
  *            @arg @ref RCC_MCODIV_1  no division applied to MCO clock
  *            @arg @ref RCC_MCODIV_2  division by 2 applied to MCO clock
  *            @arg @ref RCC_MCODIV_4  division by 4 applied to MCO clock
  *            @arg @ref RCC_MCODIV_8  division by 8 applied to MCO clock
  *            @arg @ref RCC_MCODIV_16  division by 16 applied to MCO clock
  * @retval None
  */
void HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  /* Check the parameters */
  assert_param(IS_RCC_MCO(RCC_MCOx));
  assert_param(IS_RCC_MCODIV(RCC_MCODiv));
  assert_param(IS_RCC_MCO1SOURCE(RCC_MCOSource));

  /* MCO Clock Enable */
  __MCO1_CLK_ENABLE();

  /* Configue the MCO1 pin in alternate function mode */
  GPIO_InitStruct.Pin = MCO1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
  HAL_GPIO_Init(MCO1_GPIO_PORT, &GPIO_InitStruct);

  /* Mask MCOSEL[] and MCOPRE[] bits then set MCO1 clock source and prescaler */
  MODIFY_REG(RCC->CFGR1, (RCC_CFGR1_MCOSEL | RCC_CFGR1_MCOPRE), (RCC_MCOSource | RCC_MCODiv));
}

/**
  * @brief  Return the SYSCLK frequency.
  *
  * @note   The system frequency computed by this function is not the real
  *         frequency in the chip. It is calculated based on the predefined
  *         constant and the selected clock source:
  * @note     If SYSCLK source is MSI, function returns values based on MSI
  *             Value as defined by the MSI range.
  * @note     If SYSCLK source is HSI, function returns values based on HSI_VALUE(*)
  * @note     If SYSCLK source is HSE, function returns values based on HSE_VALUE(**)
  * @note     If SYSCLK source is PLL, function returns values based on HSE_VALUE(**),
  *           HSI_VALUE(*) or MSI Value multiplied/divided by the PLL factors.
  * @note     (*) HSI_VALUE is a constant defined in stm32u5xx_hal_conf.h file (default value
  *               16 MHz) but the real value may vary depending on the variations
  *               in voltage and temperature.
  * @note     (**) HSE_VALUE is a constant defined in stm32u5xx_hal_conf.h file (default value
  *                8 MHz), user has to ensure that HSE_VALUE is same as the real
  *                frequency of the crystal used. Otherwise, this function may
  *                have wrong result.
  *
  * @note   The result of this function could be not correct when using fractional
  *         value for HSE crystal.
  *
  * @note   This function can be used by the user application to compute the
  *         baudrate for the communication peripherals or configure other parameters.
  *
  * @note   Each time SYSCLK changes, this function must be called to update the
  *         right SYSCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  *
  * @retval SYSCLK frequency
  */
uint32_t HAL_RCC_GetSysClockFreq(void)
{
  uint32_t msirange = 0U, pllsource = 0U, pllr = 2U, pllm = 2U, pllfracen = 0U, sysclockfreq = 0U;
  float fracn1, pllvco = 0U;

  if ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_MSI) ||
      ((__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_PLL1) && (__HAL_RCC_GET_PLL_OSCSOURCE() == RCC_PLLSOURCE_MSI)))
  {
    /* MSI or PLL with MSI source used as system clock source */

    /* Get SYSCLK source */
    if (READ_BIT(RCC->ICSCR1, RCC_ICSCR1_MSIRGSEL) == RESET)
    {
      /* MSISRANGE from RCC_CSR applies */
      msirange = (RCC->CSR & RCC_CSR_MSISSRANGE) >> RCC_CSR_MSISSRANGE_Pos;
    }
    else
    {
      /* MSIRANGE from RCC_CR applies */
      msirange = (RCC->ICSCR1 & RCC_ICSCR1_MSISRANGE) >> RCC_ICSCR1_MSISRANGE_Pos;
    }
    /*MSI frequency range in HZ*/
    msirange = MSIRangeTable[msirange];

    if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_MSI)
    {
      /* MSI used as system clock source */
      sysclockfreq = msirange;
    }
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_HSI)
  {
    /* HSI used as system clock source */
    sysclockfreq = HSI_VALUE;
  }
  else if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_HSE)
  {
    /* HSE used as system clock source */
    sysclockfreq = HSE_VALUE;
  }

  if (__HAL_RCC_GET_SYSCLK_SOURCE() == RCC_CFGR1_SWS_PLL1)
  {
    /* PLL used as system clock  source */

    /* PLL_VCO = (HSE_VALUE or HSI_VALUE or MSI_VALUE/ PLLM) * PLLN
    SYSCLK = PLL_VCO / PLLR
    */
    pllsource = (RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1SRC);
    pllm = ((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1M) >> RCC_PLL1CFGR_PLL1M_Pos) + 1U  ;
    pllfracen = ((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1FRACEN) >> RCC_PLL1CFGR_PLL1FRACEN_Pos);
    fracn1 = (pllfracen * ((RCC->PLL1FRACR & RCC_PLL1FRACR_PLL1FRACN) >> RCC_PLL1FRACR_PLL1FRACN_Pos));

    if (pllm != 0)
    {
      switch (pllsource)
      {
        case RCC_PLLSOURCE_HSI:  /* HSI used as PLL clock source */
          pllvco = (HSI_VALUE / pllm) * ((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1N) + (fracn1 / 0x2000) + 1U);
          break;

        case RCC_PLLSOURCE_HSE:  /* HSE used as PLL clock source */
          pllvco = (HSE_VALUE / pllm) * ((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1N) + (fracn1 / 0x2000) + 1U);
          break;

        case RCC_PLLSOURCE_MSI:  /* MSI used as PLL clock source */
        default:
          pllvco = (msirange / pllm) * ((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1N) + (fracn1 / 0x2000) + 1U);
          break;
      }

      pllr = (((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1R) >> RCC_PLL1DIVR_PLL1R_Pos) + 1U);
      sysclockfreq = (uint32_t)(pllvco / pllr);
    }
    else
    {
      sysclockfreq = 0;
    }
  }

  return sysclockfreq;
}

/**
  * @brief  Return the HCLK frequency.
  * @note   Each time HCLK changes, this function must be called to update the
  *         right HCLK value. Otherwise, any configuration based on this function will be incorrect.
  *
  * @note   The SystemCoreClock CMSIS variable is used to store System Clock Frequency.
  * @retval HCLK frequency in Hz
  */
uint32_t HAL_RCC_GetHCLKFreq(void)
{
  return SystemCoreClock;
}

/**
  * @brief  Return the PCLK1 frequency.
  * @note   Each time PCLK1 changes, this function must be called to update the
  *         right PCLK1 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK1 frequency in Hz
  */
uint32_t HAL_RCC_GetPCLK1Freq(void)
{
  /* Get HCLK source and Compute PCLK1 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR2 & RCC_CFGR2_PPRE1) >> RCC_CFGR2_PPRE1_Pos]);
}

/**
  * @brief  Return the PCLK2 frequency.
  * @note   Each time PCLK2 changes, this function must be called to update the
  *         right PCLK2 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK2 frequency in Hz
  */
uint32_t HAL_RCC_GetPCLK2Freq(void)
{
  /* Get HCLK source and Compute PCLK2 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR2 & RCC_CFGR2_PPRE2) >> RCC_CFGR2_PPRE2_Pos]);
}

/**
  * @brief  Return the PCLK3 frequency.
  * @note   Each time PCLK3 changes, this function must be called to update the
  *         right PCLK3 value. Otherwise, any configuration based on this function will be incorrect.
  * @retval PCLK3 frequency in Hz
  */
uint32_t HAL_RCC_GetPCLK3Freq(void)
{
  /* Get HCLK source and Compute PCLK2 frequency ---------------------------*/
  return (HAL_RCC_GetHCLKFreq() >> APBPrescTable[(RCC->CFGR3 & RCC_CFGR3_PPRE3) >> RCC_CFGR3_PPRE3_Pos]);
}
/**
  * @brief  Configure the RCC_OscInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_OscInitStruct  pointer to an RCC_OscInitTypeDef structure that
  *         will be configured.
  * @retval None
  */
void HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct)
{
  /* Check the parameters */
  assert_param(RCC_OscInitStruct != NULL);

  /* Set all possible values for the Oscillator type parameter ---------------*/
  RCC_OscInitStruct->OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_MSI | \
                                      RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_HSI48;

  /* Get the HSE configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSEBYP) == RCC_CR_HSEBYP)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_BYPASS;
  }
  else if ((RCC->CR & RCC_CR_HSEON) == RCC_CR_HSEON)
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_ON;
  }
  else
  {
    RCC_OscInitStruct->HSEState = RCC_HSE_OFF;
  }

  /* Get the MSI configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_MSISON) == RCC_CR_MSISON)
  {
    RCC_OscInitStruct->MSIState = RCC_MSI_ON;
  }
  else
  {
    RCC_OscInitStruct->MSIState = RCC_MSI_OFF;
  }

  RCC_OscInitStruct->MSIClockRange = (uint32_t)((RCC->CR & RCC_ICSCR1_MSISRANGE));
  if (RCC_OscInitStruct->MSIClockRange >= RCC_MSIRANGE_12)
  {
    RCC_OscInitStruct->MSICalibrationValue = (uint32_t)((RCC->ICSCR2 & RCC_ICSCR2_MSITRIM3) >> RCC_ICSCR2_MSITRIM3_Pos);
  }
  else if (RCC_OscInitStruct->MSIClockRange >= RCC_MSIRANGE_8)
  {
    RCC_OscInitStruct->MSICalibrationValue = (uint32_t)((RCC->ICSCR2 & RCC_ICSCR2_MSITRIM2) >> RCC_ICSCR2_MSITRIM2_Pos);
  }
  else if (RCC_OscInitStruct->MSIClockRange >= RCC_MSIRANGE_4)
  {
    RCC_OscInitStruct->MSICalibrationValue = (uint32_t)((RCC->ICSCR2 & RCC_ICSCR2_MSITRIM1) >> RCC_ICSCR2_MSITRIM1_Pos);
  }
  else /*if(RCC_OscInitStruct->MSIClockRange >= RCC_MSIRANGE_0)*/
  {
    RCC_OscInitStruct->MSICalibrationValue = (uint32_t)((RCC->ICSCR2 & RCC_ICSCR2_MSITRIM0) >> RCC_ICSCR2_MSITRIM0_Pos);
  }

  /* Get the HSI configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSION) == RCC_CR_HSION)
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_ON;
  }
  else
  {
    RCC_OscInitStruct->HSIState = RCC_HSI_OFF;
  }

  RCC_OscInitStruct->HSICalibrationValue = (uint32_t)((RCC->ICSCR3 & RCC_ICSCR3_HSITRIM) >> RCC_ICSCR3_HSITRIM_Pos);

  /* Get the LSE configuration -----------------------------------------------*/
  if ((RCC->BDCR & RCC_BDCR_LSEBYP) == RCC_BDCR_LSEBYP)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_BYPASS;
  }
  else if ((RCC->BDCR & RCC_BDCR_LSEON) == RCC_BDCR_LSEON)
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_ON;
  }
  else
  {
    RCC_OscInitStruct->LSEState = RCC_LSE_OFF;
  }

  /* Get the LSI configuration -----------------------------------------------*/
  if ((RCC->BDCR & RCC_BDCR_LSION) == RCC_BDCR_LSION)
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_ON;
  }
  else
  {
    RCC_OscInitStruct->LSIState = RCC_LSI_OFF;
  }

  /* Get the HSI48 configuration ---------------------------------------------*/
  if ((RCC->CR & RCC_CR_HSI48ON) == RCC_CR_HSI48ON)
  {
    RCC_OscInitStruct->HSI48State = RCC_HSI48_ON;
  }
  else
  {
    RCC_OscInitStruct->HSI48State = RCC_HSI48_OFF;
  }

  /* Get the PLL configuration -----------------------------------------------*/
  if ((RCC->CR & RCC_CR_PLL1ON) == RCC_CR_PLL1ON)
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_ON;
  }
  else
  {
    RCC_OscInitStruct->PLL.PLLState = RCC_PLL_OFF;
  }
  RCC_OscInitStruct->PLL.PLLSource = (uint32_t)(RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1SRC);
  RCC_OscInitStruct->PLL.PLLM = (uint32_t)(((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1M) >> RCC_PLL1CFGR_PLL1M_Pos) + 1U);
  RCC_OscInitStruct->PLL.PLLN = (uint32_t)(((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1N) >> RCC_PLL1DIVR_PLL1N_Pos) + 1U);
  RCC_OscInitStruct->PLL.PLLQ = (uint32_t)(((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1Q) >> RCC_PLL1DIVR_PLL1Q_Pos) + 1U);
  RCC_OscInitStruct->PLL.PLLR = (uint32_t)(((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1R) >> RCC_PLL1DIVR_PLL1R_Pos) + 1U);
  RCC_OscInitStruct->PLL.PLLP = (uint32_t)(((RCC->PLL1DIVR & RCC_PLL1DIVR_PLL1P) >> RCC_PLL1DIVR_PLL1P_Pos) + 1U);
  RCC_OscInitStruct->PLL.PLLRGE = (uint32_t)((RCC->PLL1CFGR & RCC_PLL1CFGR_PLL1RGE));
  RCC_OscInitStruct->PLL.PLLFRACN = (uint32_t)(((RCC->PLL1FRACR & RCC_PLL1FRACR_PLL1FRACN) >> RCC_PLL1FRACR_PLL1FRACN_Pos));
}

/**
  * @brief  Configure the RCC_ClkInitStruct according to the internal
  *         RCC configuration registers.
  * @param  RCC_ClkInitStruct  pointer to an RCC_ClkInitTypeDef structure that
  *         will be configured.
  * @param  pFLatency  Pointer on the Flash Latency.
  * @retval None
  */
void HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency)
{
  /* Check the parameters */
  assert_param(RCC_ClkInitStruct != NULL);
  assert_param(pFLatency != NULL);

  /* Set all possible values for the Clock type parameter --------------------*/
  RCC_ClkInitStruct->ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3;

  /* Get the SYSCLK configuration --------------------------------------------*/
  RCC_ClkInitStruct->SYSCLKSource = (uint32_t)(RCC->CFGR1 & RCC_CFGR1_SW);

  /* Get the HCLK configuration ----------------------------------------------*/
  RCC_ClkInitStruct->AHBCLKDivider = (uint32_t)(RCC->CFGR2 & RCC_CFGR2_HPRE);

  /* Get the APB1 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APB1CLKDivider = (uint32_t)(RCC->CFGR2 & RCC_CFGR2_PPRE1);

  /* Get the APB2 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APB2CLKDivider = (uint32_t)((RCC->CFGR2 & RCC_CFGR2_PPRE2) >> 4);

  /* Get the APB3 configuration ----------------------------------------------*/
  RCC_ClkInitStruct->APB3CLKDivider = (uint32_t)(RCC->CFGR3 & RCC_CFGR3_PPRE3);

  /* Get the Flash Wait State (Latency) configuration ------------------------*/
  *pFLatency = (uint32_t)(FLASH->ACR & FLASH_ACR_LATENCY);
}

/**
  * @brief  Enable the Clock Security System.
  * @note   If a failure is detected on the HSE oscillator clock, this oscillator
  *         is automatically disabled and an interrupt is generated to inform the
  *         software about the failure (Clock Security System Interrupt, CSSI),
  *         allowing the MCU to perform rescue operations. The CSSI is linked to
  *         the Cortex-M4 NMI (Non-Maskable Interrupt) exception vector.
  * @note   The Clock Security System can only be cleared by reset.
  * @retval None
  */
void HAL_RCC_EnableCSS(void)
{
  SET_BIT(RCC->CR, RCC_CR_CSSON);
}

/**
  * @brief Handle the RCC Clock Security System interrupt request.
  * @note This API should be called under the NMI_Handler().
  * @retval None
  */
void HAL_RCC_NMI_IRQHandler(void)
{
  /* Check RCC CSSF interrupt flag  */
  if (__HAL_RCC_GET_IT(RCC_IT_CSS))
  {
    /* RCC Clock Security System interrupt user callback */
    HAL_RCC_CSSCallback();

    /* Clear RCC CSS pending bit */
    __HAL_RCC_CLEAR_IT(RCC_IT_CSS);
  }
}

/**
  * @brief  RCC Clock Security System interrupt callback.
  * @retval none
  */
__weak void HAL_RCC_CSSCallback(void)
{
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_RCC_CSSCallback should be implemented in the user file
   */
}

/**
  * @}
  */
/** @defgroup RCC_Exported_Functions_Group3 Attributes management functions
 *  @brief Attributes management functions.
 *
@verbatim
 ===============================================================================
                       ##### RCC attributes functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
  * @brief  Configure the RCC item attribute(s).
  * @note   Available attributes are to secure items and set RCC as privileged.
  * @param  Item Item(s) to set attributes on.
  *         This parameter can be a one or a combination of @ref RCC_items
  * @param  Attributes specifies the RCC secure/privilege attributes.
  *         This parameter can be a value of @RCC_attribute
  * @retval None
  */
void HAL_RCC_ConfigAttributes(uint32_t Item, uint32_t Attributes)
{
  /* Check the parameters */
  assert_param(IS_RCC_ITEM_ATTRIBUTES(Item));
  assert_param(IS_RCC_ATTRIBUTES(Attributes));

  switch (Attributes)
  {
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    /* Secure Privilege attribute */
    case RCC_SEC_PRIV:
      SET_BIT(RCC->SECCFGR, Item);
      SET_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_SPRIV);
      break;
    /* Secure Non-Privilege attribute */
    case RCC_SEC_NPRIV:
      SET_BIT(RCC->SECCFGR, Item);
      CLEAR_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_SPRIV);
      break;
    /* Non-secure Privilege attribute */
    case RCC_NSEC_PRIV:
      CLEAR_BIT(RCC->SECCFGR, Item);
      SET_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_NSPRIV);
      break;
    /* Non-secure Non-Privilege attribute */
    case RCC_NSEC_NPRIV:
      CLEAR_BIT(RCC->SECCFGR, Item);
      CLEAR_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_NSPRIV);
      break;
#else
    /* Non-secure Privilege attribute */
    case RCC_NSEC_PRIV:
      SET_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_NSPRIV);
      break;
    /* Non-secure Non-Privilege attribute */
    case RCC_NSEC_NPRIV:
      CLEAR_BIT(RCC->PRIVCFGR, RCC_PRIVCFGR_NSPRIV);
      break;
#endif /* __ARM_FEATURE_CMSE */
    default:
      /* Nothing to do */
      break;
  }
}
/**
  * @}
  */

/**
  * @brief  Get the attribute of a RCC item.
  * @note   Secure and non-secure attributes are only available from secure state
  *         when the system implements the security (TZEN=1)
  * @param  Item Single item to get secure/non-secure and privilege/non-privilege attribute from.
  *         This parameter can be a one value of @ref RCC_items except RCC_ALL.
  * @param  pAttributes pointer to return the attributes.
  * @retval HAL Status.
  */
HAL_StatusTypeDef HAL_RCC_GetConfigAttributes(uint32_t Item, uint32_t *pAttributes)
{
  uint32_t attributes = 0U;

  /* Check null pointer */
  if (pAttributes == NULL)
  {
    return HAL_ERROR;
  }

  /* Check the parameters */
  assert_param(IS_RCC_ITEM_ATTRIBUTES(Item));

#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)

  /* Check item security */
  if ((RCC->SECCFGR & Item) == Item)
  {
    /* Get Secure privileges attribute */
    attributes = ((RCC->PRIVCFGR & RCC_PRIVCFGR_SPRIV) == 0U) ? RCC_SEC_NPRIV : RCC_SEC_PRIV;
  }
  else
  {
    /* Get Non-Secure privileges attribute */
    attributes = ((RCC->PRIVCFGR & RCC_PRIVCFGR_NSPRIV) == 0U) ? RCC_NSEC_NPRIV : RCC_NSEC_PRIV;
  }
#else
  /* Get Non-Secure privileges attribute */
  attributes = ((RCC->PRIVCFGR & RCC_PRIVCFGR_NSPRIV) == 0U) ? RCC_NSEC_NPRIV : RCC_NSEC_PRIV;
#endif /* __ARM_FEATURE_CMSE */

  /* return value */
  *pAttributes = attributes;

  return HAL_OK;
}
/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @addtogroup RCC_Private_Functions
  * @{
  */
/**
  * @brief  Update number of Flash wait states in line with MSI range and current
            voltage range.
  * @param  msirange  MSI range value from RCC_MSIRANGE_0 to RCC_MSIRANGE_15
  * @retval HAL status
  */
static HAL_StatusTypeDef RCC_SetFlashLatencyFromMSIRange(uint32_t msirange)
{
  uint32_t vos = 0;
  uint32_t latency = FLASH_LATENCY_0;  /* default value 0WS */

  if (__HAL_RCC_PWR_IS_CLK_ENABLED())
  {
    vos = HAL_PWREx_GetVoltageRange();
  }
  else
  {
    __HAL_RCC_PWR_CLK_ENABLE();
    vos = HAL_PWREx_GetVoltageRange();
    __HAL_RCC_PWR_CLK_DISABLE();
  }

  if ((vos == PWR_REGULATOR_VOLTAGE_SCALE1) || (vos == PWR_REGULATOR_VOLTAGE_SCALE2))
  {
    /* MSI > 16Mhz */
    if (msirange > RCC_MSIRANGE_2)
    {
      /* MSI > 24Mhz */
      if (msirange > RCC_MSIRANGE_1)
      {
        /* MSI 48Mhz */
        latency = FLASH_LATENCY_2; /* 2WS */
      }
      else
      {
        /* MSI 24Mhz  */
        latency = FLASH_LATENCY_1; /* 1WS */
      }
    }
    /* else MSI <= 16Mhz default FLASH_LATENCY_0 0WS */
  }
  else
  {
    if (msirange > RCC_MSIRANGE_1)
    {
      /* MSI > 24Mhz */
      latency = FLASH_LATENCY_3; /* 3WS */
    }
    else
    {
      if (msirange == RCC_MSIRANGE_1)
      {
        /* MSI 24Mhz */
        latency = FLASH_LATENCY_2; /* 2WS */
      }
      else if (msirange == RCC_MSIRANGE_2)
      {
        /* MSI 16Mhz */
        latency = FLASH_LATENCY_1; /* 1WS */
      }
      /* else MSI < 8Mhz default FLASH_LATENCY_0 0WS */
    }
  }

  __HAL_FLASH_SET_LATENCY(latency);

  /* Check that the new number of wait states is taken into account to access the Flash
     memory by reading the FLASH_ACR register */
  if ((FLASH->ACR & FLASH_ACR_LATENCY) != latency)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}

/**
  * @}
  */
#endif /* HAL_RCC_MODULE_ENABLED */
/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
