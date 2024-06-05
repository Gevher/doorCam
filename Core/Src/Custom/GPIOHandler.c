/*
 * GPIOHandler.h
 	 *
 *
 *	GPIO handling and initialization code for doorCam project
 *
 *  Created on: Jun 2, 2024
 *      Author: tomas
 */
#include <Custom/GPIOHandler.h>
#include <stdbool.h>


//GPIO initialization method, no changes made, as auto-generated
void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();


  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7|LED_PIN_Pin|LED2_PIN, GPIO_PIN_RESET);

  /*Configure GPIO input pins using GPIOA : USER_BTN */
  GPIO_InitStruct.Pin = USER_BTN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_BTN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO output pins using GPIOC : ECHO_PIN, LED_PIN, LED2_PIN */
  GPIO_InitStruct.Pin = ECHO_PIN|LED_PIN|LED2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(ECHO_PIN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO input pins using GPIOC : TRIG_PIN */
  GPIO_InitStruct.Pin = TRIG_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TRIG_PIN_GPIO_Port, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/*Changes build-in  LED state*/
void vLEDChangeState(void){
	if(HAL_GPIO_ReadPin(LED_PIN_GPIO_Port, LED_PIN)){
		HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN, GPIO_STATE_RESET);
	}
	else if(!HAL_GPIO_ReadPin(LED_PIN_GPIO_Port, LED_PIN)){
		HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN, GPIO_STATE_SET);
	}
}

/*Changes build-in LED2 state*/
void vErroLEDChangeState(void){
		if(HAL_GPIO_ReadPin(LED2_PIN_GPIO_Port, LED2_PIN)){
			HAL_GPIO_WritePin(LED2_PIN_GPIO_Port, LED2_PIN, GPIO_STATE_RESET);
		}
		else if(!HAL_GPIO_ReadPin(LED2_PIN_GPIO_Port, LED2_PIN)){
			HAL_GPIO_WritePin(LED2_PIN_GPIO_Port, LED2_PIN, GPIO_STATE_SET);
		}
}

/*Changes proximity sensor TRIG pin state*/
void vTrigChangeState(void){
		if(HAL_GPIO_ReadPin(TRIG_PIN_GPIO_Port, TRIG_PIN)){
				HAL_GPIO_WritePin(TRIG_PIN_GPIO_Port, TRIG_PIN, GPIO_STATE_RESET);
		}
		else if(!HAL_GPIO_ReadPin(TRIG_PIN_GPIO_Port, TRIG_PIN)){
				HAL_GPIO_WritePin(TRIG_PIN_GPIO_Port, TRIG_PIN, GPIO_STATE_SET);
		}
}

/*Gets build-in user button state*/
bool bUserButtonGetState(void){
	if(HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN))
		return true;
	else
		return false;
}

/*Gets proximity sensor echo pin state*/
bool bEchoGetState(void){
	if(HAL_GPIO_ReadPin(ECHO_PIN_GPIO_Port, ECHO_PIN))
		return true;
	else
		return false;
}

/*Grts proximity sensor trigger pin state*/
bool bEchoGetState(void){
	if(HAL_GPIO_ReadPin(TRIG_PIN_GPIO_Port, TRIG_PIN))
		return true;
	else
		return false;
}
