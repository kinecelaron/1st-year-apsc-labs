#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <stdint.h>

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * Adjust these settings according to your hardware and application requirements.
 *----------------------------------------------------------*/

 /* Basic configurations */
#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCPU_CLOCK_HZ                      ((unsigned long) 48000000) /* Adjust to your MCU clock speed */
#define configTICK_RATE_HZ                      ((TickType_t) 1000) /* 1 ms tick */
#define configMAX_PRIORITIES                    5 /* Set based on your task needs */
#define configMINIMAL_STACK_SIZE                ((uint16_t) 128) /* Adjust to your MCU memory constraints */
#define configTOTAL_HEAP_SIZE                   ((size_t) (10 * 1024)) /* 8 KB heap for dynamic allocations */
#define configMAX_TASK_NAME_LEN                 16
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1

/* Queue and Semaphore settings */
#define configQUEUE_REGISTRY_SIZE               10 /* For debugging queues */

/* Debugging and runtime checks */
#define configCHECK_FOR_STACK_OVERFLOW          2 /* Enable stack overflow checking */
#define configUSE_MALLOC_FAILED_HOOK            1 /* Handle malloc failures */

/* Hook function usage */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configUSE_TRACE_FACILITY                1 /* For debugging task execution */
#define configGENERATE_RUN_TIME_STATS           0 /* Set to 1 if runtime stats are needed */

/* Software timer settings */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               (configMAX_PRIORITIES - 1)
#define configTIMER_QUEUE_LENGTH                5
#define configTIMER_TASK_STACK_DEPTH            configMINIMAL_STACK_SIZE

/* Co-routines */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         2

/* Mutexes and semaphores */
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_ALTERNATIVE_API               0 /* Deprecated */

/* API function inclusions */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           0
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1

/* Cortex-M specific configurations (if applicable) */
#ifdef __NVIC_PRIO_BITS
#define configPRIO_BITS                     __NVIC_PRIO_BITS
#else
#define configPRIO_BITS                     4 /* Default: 15 priority levels */
#endif

/* Priority configurations for NVIC interrupts */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5
#define configKERNEL_INTERRUPT_PRIORITY         (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))

/* Assertions */
#define configASSERT(x)                         if ((x) == 0) { taskDISABLE_INTERRUPTS(); for (;;) ; }

/* FreeRTOS Port Configuration */
#define vPortSVCHandler                         SVC_Handler
#define xPortPendSVHandler                      PendSV_Handler
#define xPortSysTickHandler                     SysTick_Handler

#define configSUPPORT_DYNAMIC_ALLOCATION 1


#endif /* FREERTOS_CONFIG_H */
