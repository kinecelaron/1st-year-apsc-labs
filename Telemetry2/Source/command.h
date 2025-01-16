#ifndef COMMAND_H
#define COMMAND_H

#include "FreeRTOS.h"
#include "queue.h"

// Function Declarations
void CommandTask(void* pvParameters);

// External Variables
extern QueueHandle_t commandQueue;

#endif // COMMAND_H

