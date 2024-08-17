/*
 * proxSensHandler.c
 *
 * Code for handling and getting state of proximity senor in doorCam project
 *
 *
 *
 *  Created on: Jun 1, 2024
 *      Author: tomas
 */
#include "Custom/GPIOHandler.h"
#include "Custom/proxSensHandler.h"
#include <stdint.h>
#include <stdbool.h>


uint8_t vProxSensMeasure(void);
bool bIsObstacleInRange(uint8_t);



/*Function responsible for checking and switching proximity sensor state using its trigger input and echo output*/
uint8_t vProxSensMeasure(void){
	static uint8_t iMachineState;
	bool bTrigState;

	bTrigState = bTrigGetState();

	if(!iMachineState){
		iMachineState = SENSOR_READY;
	}

	if(iMachineState == SENSOR_READY){
		if(bTrigState){
			vTrigChangeState();
			iMachineState = SENSOR_STARTING;
			return iMachineState;
		}
		else{
			iMachineState = SENSOR_ERROR;
		}
	}

	if(iMachineState == SENSOR_STARTING && bEchoGetState() && bTrigGetState()){
		vTrigChangeState();
		//vLEDOn();
		iMachineState = SENSOR_MEASURE_IN_PROGRESS;
	}
	else if (iMachineState == SENSOR_MEASURE_IN_PROGRESS ) {
		if(bEchoGetState()){
			return SENSOR_MEASURE_IN_PROGRESS;
		}
		else if(!bEchoGetState()){
			iMachineState = SENSOR_READY;
			return SENSOR_MEASURE_FINNISHED;
		}
	}
	else{
		iMachineState = SENSOR_ERROR;
	}

	if(iMachineState == SENSOR_ERROR){
		iMachineState = SENSOR_READY;
		return SENSOR_ERROR;
	}


	return iMachineState;

}

/*Function checking if there is an obstacle in set distance from sensor based on formula provided in HC-SR04 sensor datasheet*/
bool bIsObstacleInRange(uint8_t iMsMeasureTime){
	uint8_t iMeasuredDistance;

	iMeasuredDistance = (iMsMeasureTime*1000)/58;  //Time is multiplicated by 1000 since formula requires nanoseconds, 58 is directly from the forumula 1ms ~ 17cm

	if(iMeasuredDistance < TRIGGER_DISTANCE){

		return true;
	}
	else{
		//vLEDOff();
		return false;
	}
}
