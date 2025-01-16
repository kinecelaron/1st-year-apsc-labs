/*
 * FreeRTOS V202212.01
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */


#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

 /* Configurations for MSVC compiler and 32-bit machine */

#define configUSE_PREEMPTION                    1
#define configUSE_TIME_SLICING                 1
#define configCPU_CLOCK_HZ                     (16000000UL)  // Set to your CPU clock rate (16 MHz in this case)
#define configTICK_RATE_HZ                     (1000)        // Tick rate set to 1000Hz (1ms tick)
#define configMAX_PRIORITIES                   (5)           // Max task priorities
#define configMINIMAL_STACK_SIZE               (128)         // Minimal stack size for tasks (128 words)
#define configTOTAL_HEAP_SIZE                  (102400)        // Total heap size (100 KB)
#define configUSE_STATIC_ALLOCATION            1
#define configMAX_TASK_NAME_LEN                (16)          // Maximum task name length
#define configUSE_QUEUE_SETS                  1
#define configUSE_MUTEXES                     1
#define configUSE_COUNTING_SEMAPHORES         1
#define configKERNEL_INTERRUPT_PRIORITY        255
#define configMAX_SYSCALL_INTERRUPT_PRIORITY  191
#define configUSE_TIMERS                       1
#define configTIMER_TASK_PRIORITY              (2)           // Timer task priority
#define configUSE_IDLE_HOOK                   0
#define configCHECK_FOR_STACK_OVERFLOW        1
#define configTIMER_TASK_STACK_DEPTH          (configMINIMAL_STACK_SIZE)
#define configDEFAULT_TASK_PRIORITY           (tskIDLE_PRIORITY)
#define configUSE_16_BIT_TICKS				1
#define configUSE_MALLOC_FAILED_HOOK 1

/* Add this line for the timer queue length */
#define configTIMER_QUEUE_LENGTH               10  // Number of timers that can be queued

/* Add this line for the tick hook */
#define configUSE_TICK_HOOK                   1  // or 1 if you want to use the tick hook

#endif /* FREERTOS_CONFIG_H */

#define INCLUDE_vTaskDelay 1

#define configSUPPORT_DYNAMIC_ALLOCATION 1 // Enable dynamic memory allocation
