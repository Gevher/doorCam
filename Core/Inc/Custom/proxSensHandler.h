/*
 * proxSensHandler.h
 *
 * Definitions and resources needed for  handling and getting state of proximity sensor in doorCam project
 *
 *  Created on: Jun 4, 2024
 *      Author: tomas
 */

#ifndef INC_CUSTOM_PROXSENSHANDLER_H_
#define INC_CUSTOM_PROXSENSHANDLER_H_



enum PROXIMITY_SENOR_STATE{
	SENSOR_READY = 0,
	SENSOR_STARTING = 1,
	SENSOR_MEASURE_IN_PROGRESS = 2,
	SENSOR_MEASURE_FINNISHED = 3,
	SENSOR_ERROR = 4
};

#endif /* INC_CUSTOM_PROXSENSHANDLER_H_ */
