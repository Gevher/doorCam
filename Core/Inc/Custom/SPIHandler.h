/*
 * SPIHandler.h
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */
#include <stm32f0xx_hal_spi.h>


#ifndef INC_CUSTOM_SPIHANDLER_H_
#define INC_CUSTOM_SPIHANDLER_H_

//Default timeout time
#define TIMEOUT_TIME 1000

//Default size of sended data in amount of bytes/words(size of chunk defined by hspi1.Init.DataSize)
#define SIZE_OF_PACKAGE 2

#endif /* INC_CUSTOM_SPIHANDLER_H_ */
