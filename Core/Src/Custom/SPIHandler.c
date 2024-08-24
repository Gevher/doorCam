/*
 * SPIHandler.c
 *
 *	Hanling everyhing related fo SPI communication
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */

#include <Custom/SPIHandler.h>
#include <stdbool.h>

//Default handle for SPI1
SPI_HandleTypeDef hspi1;

bool bSPITransmisionTest(void);
void MX_SPI1_Init(void);

//SPI initialization method
void MX_SPI1_Init(void) {

	hspi1.Instance = SPI1;
	hspi1.Init.Mode = SPI_MODE_MASTER;
	hspi1.Init.Direction = SPI_DIRECTION_2LINES;
	hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi1.Init.NSS = SPI_NSS_HARD_INPUT;
	hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
	hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi1.Init.CRCPolynomial = 7;
	hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
	hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
	if (HAL_SPI_Init(&hspi1) != HAL_OK) {
		Error_Handler();
	}

}

/*SPI transition test, returns true if HAL_OK(0x00U), returns false if HAL_ERROR    = 0x01U,
 HAL_BUSY     = 0x02U,
 HAL_TIMEOUT  = 0x03U,
 TODO:Prepare ESP32S3 microcontroller and test communication*/
bool bSPITransmisionTest(void) {

	//Transition test
	bool bTransmitionState;
	//A variable holding data just for test
	uint8_t iDummyData = 1;

	bTransmitionState = HAL_SPI_Transmit(&hspi1, &iDummyData, SIZE_OF_PACKAGE, DEFAULT_TIMEOUT);

	/*Returning negation of bTransmitionState since for HAL_SPI_Transmit HALL_OK = 0x00U*/
	return !bTransmitionState;

}
