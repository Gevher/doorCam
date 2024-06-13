/*
 * SPIHandler.h
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */

#include <stdbool.h>
#include <stm32f0xx_hal.h>


#ifndef INC_CUSTOM_SPIHANDLER_H_
#define INC_CUSTOM_SPIHANDLER_H_

//Default SPI handle used by STM32
SPI_HandleTypeDef hspi1;


void MX_SPI1_Init(void);

//Default timeout time
#define TIMEOUT_TIME 1000

//Default size of sended data in amount of bytes/words(size of chunk defined by hspi1.Init.DataSize)
#define SIZE_OF_PACKAGE 2

#endif /* INC_CUSTOM_SPIHANDLER_H_ */
