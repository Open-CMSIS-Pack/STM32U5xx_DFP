/**
  ******************************************************************************
  * @file    stm32u5xx.h
  * @author  MCD Application Team
  * @brief   CMSIS STM32U5xx Device Peripheral Access Layer Header File.
  *
  *          The file is the unique include file that the application programmer
  *          is using in the C source code, usually in main.c. This file contains:
  *           - Configuration section that allows to select:
  *              - The STM32U5xx device used in the target application
  *              - To use or not the peripheral�s drivers in application code(i.e.
  *                code will be based on direct access to peripheral�s registers
  *                rather than drivers API), this option is controlled by
  *                "#define USE_HAL_DRIVER"
  *
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32u5xx
  * @{
  */

#ifndef STM32U5xx_H
#define STM32U5xx_H

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

/** @addtogroup Library_configuration_section
  * @{
  */

/**
  * @brief STM32 Family
  */
#if !defined (STM32U5)
#define STM32U5
#endif /* STM32U5 */

/* Uncomment the line below according to the target STM32U5 device used in your
   application
  */

#if !defined (STM32U575xx)  && !defined (STM32U585xx) \
    && !defined (STM32U599xx)  && !defined (STM32U5A9xx)
  /* #define STM32U575xx */   /*!< STM32U575xx Devices */
  /* #define STM32U585xx */   /*!< STM32U585xx Devices */
  /* #define STM32U599xx */   /*!< STM32U599xx Devices */
  /* #define STM32U5A9xx */   /*!< STM32U5A9xx Devices */    
#endif

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler preprocessor.
  */
#if !defined  (USE_HAL_DRIVER)
/**
 * @brief Comment the line below if you will not use the peripherals drivers.
   In this case, these drivers will not be included and the application code will
   be based on direct access to peripherals registers
   */
  /*#define USE_HAL_DRIVER */
#endif /* USE_HAL_DRIVER */

/**
  * @brief CMSIS Device version number 0.2.0
  */
#define __STM32U5_CMSIS_VERSION_MAIN   (0x00) /*!< [31:24] main version */
#define __STM32U5_CMSIS_VERSION_SUB1   (0x02) /*!< [23:16] sub1 version */
#define __STM32U5_CMSIS_VERSION_SUB2   (0x00) /*!< [15:8]  sub2 version */
#define __STM32U5_CMSIS_VERSION_RC     (0x00) /*!< [7:0]  release candidate */
#define __STM32U5_CMSIS_VERSION        ((__STM32U5_CMSIS_VERSION_MAIN << 24U)\
                                       |(__STM32U5_CMSIS_VERSION_SUB1 << 16U)\
                                       |(__STM32U5_CMSIS_VERSION_SUB2 << 8U )\
                                       |(__STM32U5_CMSIS_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Device_Included
  * @{
  */

#if defined(STM32U575xx)
  #include "stm32u575xx.h"
#elif defined(STM32U585xx)
  #include "stm32u585xx.h"
#elif defined(STM32U599xx)
  #include "stm32u599xx.h"
#elif defined(STM32U5A9xx)
  #include "stm32u5a9xx.h"
#else
 #error "Please select first the target STM32U5xx device used in your application (in stm32u5xx.h file)"
#endif

/**
  * @}
  */

/** @addtogroup Exported_types
  * @{
  */
typedef enum
{
  RESET = 0,
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum
{
  SUCCESS = 0,
  ERROR = !SUCCESS
} ErrorStatus;

/**
  * @}
  */


/** @addtogroup Exported_macros
  * @{
  */
#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))


/**
  * @}
  */

#if defined (USE_HAL_DRIVER)
 #include "stm32u5xx_hal.h"
#endif /* USE_HAL_DRIVER */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STM32U5xx_H */
/**
  * @}
  */

/**
  * @}
  */




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
