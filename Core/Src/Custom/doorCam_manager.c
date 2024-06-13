/*
 * doorCam_menager.c
 *
 *  Source code for managing doorCam project with freeRTOS
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */

#include "Custom/doorCam_manager.h"



void doorCamInit(void){
	MX_GPIO_Init();
	SystemClock_Config();
	MX_SPI1_Init();
}


void doorCamProcesing(void){

	qProxTrigQueue = xQueueCreate(QUEUE_LENGHT, sizof(uint8_t));


	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	if(qProxTrigQueue != NULL){
		xTaskCreate(vSPITestTask, 			 /* Pointer to the function that implements the task.*/
					"SPI testing task",		 /* Text name for the task. */
					DEFAULT_TASK_SIZE,		 /* Size of task stack memory in words*/
					NULL,					 /* Task parameter if used */
					DEFAULT_TASK_PRIORITY,	 /* This task will run at priority 1. */
					NULL					 /* Task handle for future API calls if needed*/
					);

		xTaskCreate(vPoroxSensMeasureTask, 						 /* Pointer to the function that implements the task.*/
					"Proximity sensor measurement task",		 /* Text name for the task. */
					DEFAULT_TASK_SIZE,							 /* Size of task stack memory in words*/
					NULL,										 /* Task parameter if used */
					DEFAULT_TASK_PRIORITY,	 					 /* This task will run at priority 1. */
					NULL					 					 /* Task handle for future API calls if needed*/
					);
	}
	else{
		vErroLEDChangeState();
	}


	osKernelStart();


}

void vSPITestTask(void* pvParameters) {

}



void vPoroxSensMeasureTask(void* pvParameters) {

}

void StartDefaultTask(void* pvParameters)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */
}
