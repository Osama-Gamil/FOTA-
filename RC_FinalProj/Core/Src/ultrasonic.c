/*
 * ultrasonic.c
 *
 *  Created on: May 30, 2023
 *      Author: moham
 */

#include "ultrasonic.h"

void Trigger_UltraSonic(GPIO_TypeDef *pGPIOx , TIM_HandleTypeDef *pHTIMx ,uint16_t PinNumber){

	HAL_GPIO_WritePin(pGPIOx, PinNumber, GPIO_PIN_SET);  // pull the TRIG pin HIGH

	__HAL_TIM_SET_COUNTER(pHTIMx, 0);

	while (__HAL_TIM_GET_COUNTER (pHTIMx) < 10);  // wait for 10 us

	HAL_GPIO_WritePin(pGPIOx, PinNumber, GPIO_PIN_RESET);  // pull the TRIG pin low

}

