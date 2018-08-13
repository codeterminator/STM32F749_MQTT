/**
  @page FLASH_EraseProgram FLASH Erase and Program application
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    FLASH/FLASH_EraseProgram/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the FLASH Erase and Program example.
  ******************************************************************************
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
  @endverbatim

@par Application Description 

How to configure and use the FLASH HAL API to erase and program the internal
Flash memory.
  
At the beginning of the main program the HAL_Init() function is called to reset 
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock (SYSCLK) 
to run at 216 MHz. 

After Reset, the Flash memory Program/Erase Controller is locked. A dedicated function
is used to enable the FLASH control register access.
Before programming the desired addresses, an erase operation is performed using 
the flash erase sector feature. The erase procedure is done by filling the erase init 
structure giving the starting erase sector and the number of sectors to erase.
At this stage, all these sectors will be erased one by one separately.

@note: if problem occurs on a sector, erase will be stopped and faulty sector will 
be returned to user (through variable 'sectorError').

Once this operation is finished, sector word programming operation will be performed 
in the FLASH memory. The written data is then read back and checked.

The NUCLEO-746ZG Rev.B board LEDs can be used to monitor the transfer status:
 - LED1 is ON when there are no errors detected after programmation
 - LED1 is blinking with a 1s period when there are errors dectected after programmation
 - LED1 is blinking (100ms on, 2s off) when there is an issue during erase or program procedure

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Memory, FLASH, Erase, Program, Sector, Mass Erase

@Note�If the user code size exceeds the DTCM-RAM size or starts from internal cacheable memories (SRAM1 and SRAM2),that is shared between several processors,
 �����then it is highly recommended to enable the CPU cache and maintain its coherence at application level.
      In case of constraints it is possible to configure the MPU as "Write through/not shareable" to guarantee the cache coherence at write access but the user
	  has to ensure the cache maintenance at read access though.
������The address and the size of cacheable buffers (shared between CPU and other masters)  must be properly updated to be aligned to cache line size (32 bytes).

@Note It is recommended to enable the cache and maintain its coherence, but depending on the use case
����� It is also possible to configure the MPU as "Write through", to guarantee the write access coherence.
������In that case, the MPU must be configured as Cacheable/Bufferable/Not Shareable.
������Even though the user must manage the cache coherence for read accesses.
������Please refer to the AN4838 �Managing memory protection unit (MPU) in STM32 MCUs�
������Please refer to the AN4839 �Level 1 cache on STM32F7 Series�

@par Directory contents 

  - FLASH/FLASH_EraseProgram/Inc/stm32f7xx_hal_conf.h        HAL Configuration file  
  - FLASH/FLASH_EraseProgram/Inc/stm32f7xx_it.h              Header for stm32f7xx_it.c
  - FLASH/FLASH_EraseProgram/Inc/main.h                      Header for main.c module 
  - FLASH/FLASH_EraseProgram/Src/stm32f7xx_it.c              Interrupt handlers
  - FLASH/FLASH_EraseProgram/Src/main.c                      Main program
  - FLASH/FLASH_EraseProgram/Src/system_stm32f7xx.c          STM32F7xx system clock configuration file

@par Hardware and Software environment

  - This application runs on STM32F746xG devices.
    
  - This application has been tested with NUCLEO-746ZG Rev.B board and can be
    easily tailored to any other supported device and development board.
      
@par How to use it ? 

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the application


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
