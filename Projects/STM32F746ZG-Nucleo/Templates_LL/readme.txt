/**
  @page Templates_LL  Description of the Templates_LL example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    Templates_LL/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the Templates_LL example.
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

This projects provides a reference template through the LL API that can be used to build any firmware application.

This project LL template provides:
 - Inclusion of all LL drivers (include files in "main.h" and LL sources files in IDE environment, with option "USE_FULL_LL_DRIVER" in IDE environment)
   Note: If optimization is needed afterwards, user can perform a cleanup by removing unused drivers.
 - Definition of LEDs and user button (file: main.h)
   Note: User button name printed on board may differ from naming "user button" in code: "key button", ...
 - Clock configuration (file: main.c)

This project LL template does not provide:
 - Functions to initialize and control LED and user button
 - Functions to manage IRQ handler of user button

To port a LL example to the targeted board:
1. Select the LL example to port.
   To find the board on which LL examples are deployed, refer to LL examples list in "STM32CubeProjectsList.html", table section "Examples_LL"
   or AN4731: STM32Cube firmware examples for STM32F7 Series

2. Replace source files of the LL template by the ones of the LL example, except code specific to board.
   Note: Code specific to board is specified between tags:
         /* ==============   BOARD SPECIFIC CONFIGURATION CODE BEGIN    ============== */
         /* ==============   BOARD SPECIFIC CONFIGURATION CODE END      ============== */
         
   - Replace file main.h, with updates:
     - Keep LED and user button definition of the LL template under tags
    
   - Replace file main.c, with updates:
     - Keep clock configuration of the LL template: function "SystemClock_Config()"
     - Depending of LED availability, replace LEDx_PIN by another LEDx (number) available in file main.h
     
   - Replace file stm32f7xx_it.h
   - Replace file stm32f7xx_it.c


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

  - Templates_LL/Inc/stm32f7xx_it.h          Interrupt handlers header file
  - Templates_LL/Inc/main.h                  Header for main.c module
  - Templates_LL/Inc/stm32_assert.h          Template file to include assert_failed function
  - Templates_LL/Src/stm32f7xx_it.c          Interrupt handlers
  - Templates_LL/Src/main.c                  Main program
  - Templates_LL/Src/system_stm32F7xx.c      STM32F7x system source file


@par Hardware and Software environment

  - This template runs on STM32F746xx devices.
    
  - This template has been tested with STM32F746ZG-Nucleo revB board 
    and can be easily tailored to any other supported device and development board


@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example

In order to load the Flash_ITCM configuration, you must follow the instructions below :
 - Open SW4STM32 toolchain
 - Rebuild all files
 - Open STM32 ST-Link Utility V4.1.0
 - Connect the STM32xx board to PC with USB cable through CN1
 - Use the hex file generated to program ITCM Flash using ST-Link Utility

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
