/*
 * main.c
 *
 *  Created on: Jun 23, 2025
 *      Author: bora
 */

#include "stm32f4xx_hal.h"

void GPIO_Config(void);
void delay(uint32_t delayVal);

int main(void){

	GPIO_Config();

	while(1){

		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		delay(500000);
	}
}

void GPIO_Config(){
	 __HAL_RCC_GPIOA_CLK_ENABLE();

	 GPIO_InitTypeDef GPIOA_Init = {};

	 GPIOA_Init.Pin = GPIO_PIN_5;
	 GPIOA_Init.Mode = GPIO_MODE_OUTPUT_PP;

	 HAL_GPIO_Init(GPIOA, &GPIOA_Init);
}

void delay(uint32_t delayVal){
	uint32_t i;
	for (i = 0; i < delayVal; i++){
	}
}
