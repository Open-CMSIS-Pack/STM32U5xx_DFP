/***********************************************************************/
/*  This file is part of the ARM Toolchain package                     */
/*  Copyright (c) 2020 Keil - An ARM Company. All rights reserved.     */
/***********************************************************************/
/*                                                                     */
/*  FlashPrg.c:  Flash Programming Functions adapted for               */
/*               ST Microelectronics STM32U585I_IOT02A Flash           */
/*                                                                     */
/***********************************************************************/

#include "..\FlashOS.h"        
#include "STM32U5OSPI.h"

/*
 *  Initialize Flash Programming Functions
 *    Parameter:      adr:  Device Base Address
 *                    clk:  Clock Frequency (Hz)
 *                    fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#if defined FLASH_MEM || defined FLASH_OTP
int Init (unsigned long adr, unsigned long clk, unsigned long fnc)
{
  if (Init_OSPI() !=0)
    return 0;
  else 
    return 1;
}
#endif


/*
 *  De-Initialize Flash Programming Functions
 *    Parameter:      fnc:  Function Code (1 - Erase, 2 - Program, 3 - Verify)
 *    Return Value:   0 - OK,  1 - Failed
 */

#if defined FLASH_MEM || defined FLASH_OTP
int UnInit (unsigned long fnc)
{
  return (0);
}
#endif


/*
 *  Erase complete Flash Memory
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseChip (void)
{
  if (MassErase() !=0)
    return 0;
  else
    return 1;
}
#endif


/*
 *  Erase Sector in Flash Memory
 *    Parameter:      adr:  Sector Address
 *    Return Value:   0 - OK,  1 - Failed
 */

#ifdef FLASH_MEM
int EraseSector (unsigned long adr)
{
  uint32_t block_start = adr;
  uint32_t block_size  = 0x10000;

  if (SectorErase ((uint32_t) block_start & 0xffffffff ,((uint32_t) block_start & 0xffffffff) + block_size) !=0)
    return 0;   
  else 
    return 1;
}
#endif


/*
 *  Program Page in Flash Memory
 *    Parameter:      adr:  Page Start Address
 *                    sz:   Page Size
 *                    buf:  Page Data
 *    Return Value:   0 - OK,  1 - Failed
 */

#if defined FLASH_MEM || defined FLASH_OTP
int ProgramPage (unsigned long block_start, unsigned long size, unsigned char *buffer)
{
  if (Write(block_start ,size, buffer) !=0)
    return 0;
  else
    return 1;
}


/*
 *  Verify Flash Contents
 *    Parameter:      adr:  Start Address
 *                    sz:   Size (in bytes)
 *                    buf:  Data
 *    Return Value:   (adr+sz) - OK, Failed Address
 */
unsigned long Verify (unsigned long adr, unsigned long sz, unsigned char *buf)
{
  while (sz-- > 0)
  {
    if (*(char*)adr++ != *((char*)buf++))
      return (adr);
  }

  return adr;
}
#endif
