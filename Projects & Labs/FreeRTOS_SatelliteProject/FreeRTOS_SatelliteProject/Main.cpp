#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Data structure for telemetry
typedef struct {
    int temperature;
    int voltage;
} TelemetryData;

// Global queues
QueueHandle_t telemetryQueue;
QueueHandle_t commandQueue;

// Simulated system reset
void NVIC_SystemReset() {
    printf("System Reset Triggered\n");
}

// Tasks
void TelemetryTask(void* pvParameters) {
    TelemetryData data;
    for (;;) {
        data.temperature = rand() % 100;  // Simulate temperature
        data.voltage = rand() % 5 + 3;   // Simulate voltage (3-7V)
        xQueueSend(telemetryQueue, &data, portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1 second
    }
}

void CommandTask(void* pvParameters) {
    char command[20];
    for (;;) {
        if (xQueueReceive(commandQueue, &command, portMAX_DELAY)) {
            if (strcmp(command, "RESET") == 0) {
                NVIC_SystemReset();
            }
            else if (strcmp(command, "STATUS") == 0) {
                printf("System is operational.\n");
            }
        }
    }
}

void HealthTask(void* pvParameters) {
    for (;;) {
        printf("Free Heap: %d bytes\n", xPortGetFreeHeapSize());
        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay 5 seconds
    }
}

void TransmitTask(void* pvParameters) {
    TelemetryData data;
    for (;;) {
        if (xQueueReceive(telemetryQueue, &data, portMAX_DELAY)) {
            printf("Transmitting: Temp=%d, Voltage=%d\n",
                data.temperature, data.voltage);
        }
    }
}

void WatchdogTask(void* pvParameters) {
    for (;;) {
        printf("Watchdog fed.\n");
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay 2 seconds
    }
}

void vApplicationTickHook(void) {
    // Optional: Add code to execute on each tick (e.g., statistics)
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char* pcTaskName) {
    // Handle stack overflow (log or reset)
    printf("Stack overflow in task: %s\n", pcTaskName);
    for (;;); // Halt system
}

void vApplicationMallocFailedHook(void) {
    // Handle malloc failure (log or reset)
    printf("Malloc failed\n");
    for (;;); // Halt system
}

int main(void) {
    // Create queues
    telemetryQueue = xQueueCreate(10, sizeof(TelemetryData));
    commandQueue = xQueueCreate(5, sizeof(char[20]));

    if (telemetryQueue == NULL || commandQueue == NULL) {
        printf("Queue creation failed!\n");
        return -1;
    }

    // Create tasks
    xTaskCreate(TelemetryTask, "Telemetry", 1000, NULL, 1, NULL);
    xTaskCreate(CommandTask, "Command", 1000, NULL, 2, NULL);
    xTaskCreate(HealthTask, "Health", 1000, NULL, 1, NULL);
    xTaskCreate(TransmitTask, "Transmit", 1000, NULL, 2, NULL);
    xTaskCreate(WatchdogTask, "Watchdog", 1000, NULL, 3, NULL);

    // Start scheduler
    vTaskStartScheduler();

    // Should never reach here
    for (;;);
}