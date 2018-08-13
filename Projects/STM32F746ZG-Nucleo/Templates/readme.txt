/**
  @page Templates  Description of the Templates example
  
  @verbatim
  ******************************************************************************
  * @file    Templates/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Templates example.
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

@par Example Description

This directory provides a reference template project that can be used to build any firmware application for
STM32F756xx/STM32F746xx devices using STM32CubeF7 HAL and running on NUCLEO-746ZG Rev.B board from STMicroelectronics. 

This template provides two workspaces:
 - NUCLEO-746ZG Rev.B(AXIM-FLASH): using the Flash AXIM interface (Cache & MPU features) 
 - NUCLEO-746ZG Rev.B(ITCM-FLASH): using the Flash ITCM interface (ART Accelerator)
 
The template includes also function used to enable the CPU Cache : CPU_CACHE_Enable().
This function is provided as template implementation that User may integrate in his application, 
to enhance the performance in case of use of AXI interface with several masters.

@note Some code parts can be executed in the ITCM-RAM (16 KB) which decrease critical task execution time, compared  
      to code execution from Flash memory. This feature can be activated using '#pragma location = ".itcmram"' to be 
      placed above function declaration, or using the toolchain GUI (file options) to execute a whole source file in
	  the ITCM-RAM.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


@par Keywords

Reference, Template, MPU, CPU Cache

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

  - Templates/Src/main.c                 Main program
  - Templates/Src/system_stm32f7xx.c     STM32F7xx system clock configuration file
  - Templates/Src/stm32f7xx_it.c         Interrupt handlers 
  - Templates/Src/stm32f7xx_hal_msp.c    HAL MSP module
  - Templates/Inc/main.h                 Main program header file  
  - Templates/Inc/stm32f7xx_hal_conf.h   HAL Configuration file
  - Templates/Inc/stm32f7xx_it.h         Interrupt handlers header file

        
@par Hardware and Software environment  

  - This example runs on STM32F756xx/STM32F746xx devices.
    
  - This example has been tested with STMicroelectronics NUCLEO-746ZG Rev.B 
    boards and can be easily tailored to any other supported device 
    and development board.


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

In order to load the Flash_ITCM configuration, you must follow the instructions below :
- Open SW4STM32 toolchain
- Rebuild all files
- Open STM32 ST-Link Utility V3.9.0 and later
- Connect the STM32F746ZG_Nucleo board to PC with USB cable through CN1
- Use the corresponding hex file with ST-Link Utility to program ITCM Flash :
- SW4STM32: "STM32F746ZG_Nucleo_FLAH_ITCM.hex"

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */