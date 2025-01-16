#include "command.h"
#include "task.h"
#include "FreeRTOS.h"
#include <stdio.h>
#include <string.h>

// Queue for command handling
QueueHandle_t commandQueue;

void NVIC_SystemReset() {
    printf("System Reset Triggered\n");
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
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
