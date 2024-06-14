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

/*Method responsible for checking and switching proximity sensor state using its trigger input and echo output*/
uint8_t vProxSensMeasure(void){
	static uint8_t iMachineState;

	if(iMachineState == SENSOR_READY){
		if(!bTrigGetState()){
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
		vErroLEDChangeState();
		return SENSOR_ERROR;
	}


	return iMachineState;

}




