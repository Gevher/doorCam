/*
 * doorCam_menager.c
 *
 * 	Main source file responsible for handling logic and initialisation of particular components
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */
#include <Custom/GPIOHandler.h>
#include "cmsis_os.h"
#include "SystemClockConfig.h"
#include "SPIHandler.h"
#include "proxSensHandler.h"


void doorCamInit(void){
	MX_GPIO_Init();
	SystemClock_Config();
	MX_SPI1_Init();
}
