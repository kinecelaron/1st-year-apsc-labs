#include "watchdog.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>

void WatchdogTask(void* pvParameters) {
    for (;;) {
        printf("Watchdog fed.\n");
        vTaskDelay(pdMS_TO_TICKS(2000)); // Delay 2 seconds
    }
}