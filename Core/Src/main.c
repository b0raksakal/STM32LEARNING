/*
 * main.c
 *
 *  Created on: Jun 23, 2025
 *      Author: bora
 */

#include "stm32f4xx_hal.h"

void GPIOA_Config(void);
void GPIOC_Config(void);
void delay(uint32_t delayVal);

int main(void){

	GPIOA_Config();
	GPIOC_Config();
	int flag = 1;

	while(1){
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 1 && flag == 1){
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			//delay(50000);
			flag = 0;
		}
		else if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == 0){
			flag = 1;
		}
	}
}

void GPIOA_Config(){
	 __HAL_RCC_GPIOA_CLK_ENABLE();

	 GPIO_InitTypeDef GPIOA_Init = {};

	 GPIOA_Init.Pin = GPIO_PIN_5;
	 GPIOA_Init.Mode = GPIO_MODE_OUTPUT_PP;

	 HAL_GPIO_Init(GPIOA, &GPIOA_Init);
}

void GPIOC_Config(){
	 __HAL_RCC_GPIOC_CLK_ENABLE();

	 GPIO_InitTypeDef GPIOC_Init = {};

	 GPIOC_Init.Pin = GPIO_PIN_13;
	 GPIOC_Init.Mode = GPIO_MODE_INPUT;
	 GPIOC_Init.Pull = GPIO_NOPULL;
	 HAL_GPIO_Init(GPIOC, &GPIOC_Init);
}


void delay(uint32_t delayVal){
	uint32_t i;
	for (i = 0; i < delayVal; i++){
	}
}
