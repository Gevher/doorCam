/*
 * GPIOHandler.h
 *
 *	Pins definitions and needed resources for GPIOHandler.c with handles initialization and hadling GPIO in doorCam project
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */


#ifndef INC_CUSTOM_GPIOHANDLER_H_
#define INC_CUSTOM_GPIOHANDLER_H_

#include <stm32f0xx_hal_spi.h>

//Custom defined pins
//Output pins:
#define LED_PIN GPIO_PIN_9
#define LED2_PIN GPIO_PIN_8
#define ECHO_PIN GPIO_PIN_7

//Input pins:
#define TRIG_PIN GPIO_PIN_6
#define USER_BTN GPIO_PIN_0

//Custom defined ports
#define LED_PIN_GPIO_Port GPIOC
#define LED2_PIN_GPIO_Port GPIOC
#define ECHO_PIN_GPIO_Port GPIOC
#define TRIG_PIN_GPIO_Port GPIOC
#define USER_BTN_GPIO_Port GPIOA

//included methods
void MX_GPIO_Init(void);
void vLEDChangeState(void);
void vErroLEDChangeState(void);
void vTrigChangeState(void);
bool bUserButtonGetState(void);
bool bEchoGetState(void);
bool bTrigGetState(void);


#endif /* INC_CUSTOM_GPIOHANDLER_H_ */
