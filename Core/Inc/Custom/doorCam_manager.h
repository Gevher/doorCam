/*
 * doorCam_manager.h
 *
 *	Header file with all whats needed for managing doorCam project with freeRTOS
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */

#ifndef INC_CUSTOM_DOORCAM_MANAGER_H_
#define INC_CUSTOM_DOORCAM_MANAGER_H_

#include "Custom/GPIOHandler.h"
#include "Custom/SystemClockConfig.h"
#include "Custom/SPIHandler.h"
#include "Custom/proxSensHandler.h"

#include <stm32f0xx_hal.h>
#include <stdint.h>
#include "cmsis_os.h"



QueueHandle_t qProxTrigQueue;
BaseType_t defaultTaskHandle;

void doorCamProcesing(void);
void doorCamInit(void);
void vSPITestTask(void* pvParameters);
void vPoroxSensMeasureTask(void* pvParameters);
void StartDefaultTask(void* pvParameters);



//Arbitrary value, when higher camera might record for longer after loosing signal from porximity sensor
#define QUEUE_LENGHT 5

//range defined by freeRTOS setting, higher number == higher priority
#define DEFAULT_TASK_PRIORITY 1

//Size of stack memory taken by task, not including Task Control Block. Arbitrary.
#define DEFAULT_TASK_SIZE 12

#endif /* INC_CUSTOM_DOORCAM_MANAGER_H_ */
