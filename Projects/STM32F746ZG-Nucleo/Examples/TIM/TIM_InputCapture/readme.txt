/**
  @page TIM_InputCapture Input Capture example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_InputCapture/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the TIM_InputCapture example.
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

Use of the TIM peripheral to measure an external signal frequency.

  The TIM3CLK frequency is set to SystemCoreClock (Hz), the Prescaler is 0,
  so the TIM3 counter clock is SystemCoreClock (Hz).
  SystemCoreClock is set to 216 MHz for STM32F746xG Devices.

  TIM3 is configured in Input Capture Mode: the external signal is connected to 
  TIM3 Channel2 used as input pin.
  To measure the frequency we use the TIM3 CC2 interrupt request, so in the 
  TIM3_IRQHandler routine, the frequency of the external signal is computed.

  The "uwFrequency" variable contains the external signal frequency:
  uwFrequency = TIM3 counter clock / uwDiffCapture (Hz),
  where "uwDiffCapture" is the difference between two consecutive TIM3 captures.


  The minimum frequency value to measure is TIM3 counter clock / CCR MAX
                                              = 216 MHz / 65535

  Due to TIM3_IRQHandler processing time (around 2.5us), the maximum
  frequency value to measure is around 400kHz.

@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Timers, DMA, Frequency, Input, Capture, External Signal, Measurement

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

  - TIM/TIM_InputCapture/Inc/stm32f7xx_hal_conf.h    HAL configuration file
  - TIM/TIM_InputCapture/Inc/stm32f7xx_it.h          Interrupt handlers header file
  - TIM/TIM_InputCapture/Inc/main.h                  Header for main.c module  
  - TIM/TIM_InputCapture/Src/stm32f7xx_it.c          Interrupt handlers
  - TIM/TIM_InputCapture/Src/main.c                  Main program
  - TIM/TIM_InputCapture/Src/stm32f7xx_hal_msp.c     HAL MSP file
  - TIM/TIM_InputCapture/Src/system_stm32f7xx.c      STM32F7xx system source file


@par Hardware and Software environment

  - This example runs on STM32F746xx devices.
  - In this example, the clock is set to 216 MHz.
    
  - This example has been tested with STMicroelectronics NUCLEO-746ZG
    Rev.B board and can be easily tailored to any other supported device 
    and development board.      
   
  - LED3 is ON when an error occurs.

  - NUCLEO-746ZG Rev.B board Set-up
    - Connect the external signal to measure to the TIM3 CH2 pin (PB.05). 
    - TIM3 CH2 pin (PB.05) PB5 is connected to pin 13 on CN7 Connector .

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
