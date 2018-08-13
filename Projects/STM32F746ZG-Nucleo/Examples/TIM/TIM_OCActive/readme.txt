/**
  @page TIM_OCActive TIM_OCActive example
  
  @verbatim
  ******************** (C) COPYRIGHT 2016 STMicroelectronics *******************
  * @file    TIM/TIM_OCActive/readme.txt 
  * @author  MCD Application Team
  * @brief   This example shows how to configure the Timer to generate four 
  *          delayed signals.
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

Configuration of the TIM peripheral in Output Compare Active mode 
(when the counter matches the capture/compare register, the corresponding output 
pin is set to its active state).

  The TIM3 frequency is set to SystemCoreClock, and the objective is
  to get TIM3 counter clock at 10 kHz so the Prescaler is computed as following:
     - Prescaler = (TIM3CLK /TIM3 counter clock) - 1
   
  SystemCoreClock is set to 216 MHz for STM32F7xx Devices.

  The TIM3 CCR1 register value is equal to 10000:
  TIM3_CH1 delay = CCR1_Val/TIM3 counter clock  = 1s
  so the TIM3 Channel 1 generates a signal with a delay equal to 1s.

  The TIM3 CCR2 register value is equal to 5000:
  TIM3_CH2 delay = CCR2_Val/TIM3 counter clock = 500 ms
  so the TIM3 Channel 2 generates a signal with a delay equal to 500 ms.

  The TIM3 CCR3 register value is equal to 2500:
  TIM3_CH3 delay = CCR3_Val/TIM3 counter clock = 250 ms
  so the TIM3 Channel 3 generates a signal with a delay equal to 250 ms.

  The TIM3 CCR4 register value is equal to 1250:
  TIM3_CH4 delay = CCR4_Val/TIM3 counter clock = 125 ms
  so the TIM3 Channel 4 generates a signal with a delay equal to 125 ms.

  The delay correspond to the time difference between PB.07 edge and
  TIM3_CHx signal rising edges.

  - LED1 is always ON because it is configured on PB.OO pin 
  - LED2 is used as trigger refference to calculate the delay values 
  - LED3 is ON when an error occurs  


@note Delay values mentioned above are theoretical (obtained when the system clock frequency 
      is exactly 216 MHz). Since the generated system clock frequency may vary from one board to another observed
      delay might be slightly different.
	  
@note Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.
      
@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Timers, Output, Compare, Active, Signals, 

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

  - TIM/TIM_OCActive/Inc/stm32f7xx_hal_conf.h    HAL configuration file
  - TIM/TIM_OCActive/Inc/stm32f7xx_it.h          Interrupt handlers header file
  - TIM/TIM_OCActive/Inc/main.h                  Header for main.c module  
  - TIM/TIM_OCActive/Src/stm32f7xx_it.c          Interrupt handlers
  - TIM/TIM_OCActive/Src/main.c                  Main program
  - TIM/TIM_OCActive/Src/stm32f7xx_hal_msp.c     HAL MSP file
  - TIM/TIM_OCActive/Src/system_stm32f7xx.c      STM32F7xx system source file


@par Hardware and Software environment

  - This example runs on STM32F746xx devices.
    
  - This example has been tested with STMicroelectronics NUCLEO-746ZG Rev.B
    board Rev.B and can be easily tailored to any other supported device 
    and development board.      

  - NUCLEO-746ZG Rev.B board Set-up
   Connect the following pins to an oscilloscope to monitor the different waveforms:
      - Use LED2 connected to PB.07 (pin 21 on CN11 Connector)(Reference)
      - PB.04: (TIM3_CH1) (connected to PB.04 (pin 19 in CN7 connector))
      - PB.05: (TIM3_CH2) (connected to PB.05 (pin 13 in CN7 connector))
      - PB.00: (TIM3_CH3) (connected to PB.00 (pin 31 in CN10 connector))
      - PB.01: (TIM3_CH4) (connected to PB.01 (pin 7 in CN10 connector))

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example
 
 
You should see these waveforms on oscilloscope :

 CH1                                                            ________________
 _______________________________________________________________|
           <---------------------- 1sec------------------------->
           
 CH2                                   __________________________________________
 ______________________________________|
           <------------500ms--------->
 
 CH3                        _____________________________________________________
 ___________________________|
           <----250ms------->
 
 CH4                  ____________________________________________________________
 _____________________|
           <--125ms--->

 TRIG      ______________________________________________________________________
 __________|


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
