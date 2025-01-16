#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "telemetry.h"
#include "command.h"
#include "health.h"
#include "watchdog.h"
#include <stdio.h>

QueueHandle_t telemetryQueue;
QueueHandle_t commandQueue;


void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName)
{
    // Log or handle the stack overflow
    for (;;);
}

void vApplicationMallocFailedHook(void) {
    // Handle malloc failure (e.g., log the error and halt the system)
    printf("Malloc failed!\n");
    for (;;);  // Enter an infinite loop to halt execution
}


int main(void) {
    // Create Queues
    telemetryQueue = xQueueCreate(10, sizeof(TelemetryData));
    commandQueue = xQueueCreate(5, sizeof(char[20]));

    if (telemetryQueue == NULL || commandQueue == NULL) {
        printf("Queue creation failed!\n");
        return -1;
    }

    // Create Tasks
    xTaskCreate(TelemetryTask, "Telemetry", 1000, NULL, 1, NULL);
    xTaskCreate(TransmitTask, "Transmit", 1000, NULL, 2, NULL);
    xTaskCreate(HealthTask, "Health", 1000, NULL, 1, NULL);
    xTaskCreate(CommandTask, "Command", 1000, NULL, 2, NULL);
    xTaskCreate(WatchdogTask, "Watchdog", 1000, NULL, 3, NULL);

    // Start Scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
}