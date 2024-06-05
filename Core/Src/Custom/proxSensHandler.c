/*
 * proxSensHandler.c
 *
 *  Created on: Jun 1, 2024
 *      Author: tomas
 */
#include <Custom/GPIOHandler.h>



void vProxSensMeasure(void* pvParameters){
	TickType_t xSensorMeasureTimeStart;
	TickType_t xSensorMeasureTime;
	uint8_t iMeasureStarted = 0;
	uint8_t iMeasurmentInCm;
	BaseType_t xStatus;

	while(1){

		if(!iMeasureStarted){
			HAL_GPIO_WritePin(TRIG_PIN_GPIO_Port, TRIG_PIN, GPIO_PIN_SET);
		}


		if(!iMeasureStarted && HAL_GPIO_ReadPin(ECHO_PIN_GPIO_Port, ECHO_PIN) == GPIO_PIN_SET){
			xSensorMeasureTimeStart = xTaskGetTickCount();
			HAL_GPIO_WritePin(TRIG_PIN_GPIO_Port, TRIG_PIN, GPIO_PIN_RESET);
			iMeasureStarted = 1;
		}
		else if(iMeasureStarted && HAL_GPIO_ReadPin(ECHO_PIN_GPIO_Port, ECHO_PIN) == GPIO_PIN_RESET){
			xSensorMeasureTime = xTaskGetTickCount() - xSensorMeasureTimeStart;
			iMeasurmentInCm = (xSensorMeasureTime*portTICK_RATE_MS)*17;
		}

		if(iMeasurmentInCm < 100 && iMeasureStarted == 1){
			xStatus = xQueueSendToBack(xSPITransferQueue, &iMeasurmentInCm, 200);
				if(xStatus == pdPASS){
					HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
					iMeasureStarted = 0;
					vTaskDelay(pdMS_TO_TICKS(100));
				}
		}

	}
}




