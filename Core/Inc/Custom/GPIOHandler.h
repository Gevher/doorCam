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

#include <stdbool.h>
#include <stm32f0xx_hal.h>

//Functions in source file:
void MX_GPIO_Init(void);
void vLEDOn(void);
void vLEDOff(void);
void vErrorLEDOn(void);
void vErrorLEDOff(void);
void vTrigChangeState(void);
bool bUserButtonGetState(void);
bool bEchoGetState(void);
bool bTrigGetState(void);
bool bLEDGetState(void);
bool bErrorLEDGetState(void);

//Custom defined pins
//Output pins:
//LD3
#define LED_PIN GPIO_PIN_9
//LD4
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

#endif /* INC_CUSTOM_GPIOHANDLER_H_ */
