/*
 * SPIHandler.c
 *
 *	Hanling everyhing related fo SPI communication
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */
#include <stdbool.h>



//Default SPI handle used by STM32
SPI_HandleTypeDef hspi1;



static void MX_SPI1_Init(void);


//SPI initialization method
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
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
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}


/*SPI transmition test, returns true if HAL_OK(0x00U), returns false if HAL_ERROR    = 0x01U,
																		HAL_BUSY     = 0x02U,
																		HAL_TIMEOUT  = 0x03U,*/
bool bSPITransmisionTest(void* pvParameters){
	bool bTransmitionState;

	bTransmitionState = HAL_SPI_Transmit(&hspi1, &iQueueValue, SIZE_OF_PACKAGE, TIMEOUT_TIME);

	if(!bTransmitionState){
		return true;
	}
	else{
		return false;
	}

}
