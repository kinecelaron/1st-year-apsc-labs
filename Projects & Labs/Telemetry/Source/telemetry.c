#include "telemetry.h"
#include "task.h"
#include "FreeRTOS.h"
#include <stdio.h>
#include <stdlib.h>

// Queue for telemetry data
QueueHandle_t telemetryQueue;

void TelemetryTask(void* pvParameters) {
    TelemetryData data;
    for (;;) {
        data.temperature = rand() % 100;  // Simulate temperature
        data.voltage = rand() % 5 + 3;   // Simulate voltage (3-7V)
        xQueueSend(telemetryQueue, &data, portMAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay 1 second

    }
}

void TransmitTask(void* pvParameters) {
    TelemetryData data;
    for (;;) {
        if (xQueueReceive(telemetryQueue, &data, portMAX_DELAY)) {
            printf("Transmitting: Temp=%d, Voltage=%d\n",
                data.temperature, data.voltage);
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
