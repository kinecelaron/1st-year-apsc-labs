#include "health.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

void HealthTask(void* pvParameters) {
    for (;;) {
        printf("Free Heap: %d bytes\n", xPortGetFreeHeapSize());
        vTaskDelay(pdMS_TO_TICKS(5000)); // Delay 5 seconds
    }
}
