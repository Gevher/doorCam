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

//Functions in source file:
void vDoorCamProciessing(void);
void vDoorCamInit(void);
void vSPITestTask(void *pvParameters);
void vProxSensMeasureTask(void *pvParameters);
void StartDefaultTask(void *pvParameters);

//Arbitrary value, when higher camera might record for longer after loosing signal from porximity sensor
#define QUEUE_LENGHT 15

//range defined by freeRTOS setting, higher number == higher priority
#define DEFAULT_TASK_PRIORITY 1

//Size of stack memory taken by task, not including Task Control Block. Arbitrary.
#define DEFAULT_TASK_SIZE 128

//Default amount of waiting time in ticks
#define DEFAULT_WAIT_TIME 200

//Amount of waiting time in ticks after error
#define ERROR_WAIT_TIME 500

#endif /* INC_CUSTOM_DOORCAM_MANAGER_H_ */
