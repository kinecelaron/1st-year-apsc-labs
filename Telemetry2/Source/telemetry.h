#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "FreeRTOS.h"
#include "queue.h"

// Telemetry Data Structure
typedef struct {
    int temperature;
    int voltage;
} TelemetryData;

// Function Declarations
void TelemetryTask(void* pvParameters);
void TransmitTask(void* pvParameters);

// External Variables
extern QueueHandle_t telemetryQueue;

#endif // TELEMETRY_H

