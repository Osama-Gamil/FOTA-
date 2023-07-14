/*
 * ultrasonic.h
 *
 *  Created on: May 30, 2023
 *      Author: moham
 */

#ifndef INC_ULTRASONIC_H_
#define INC_ULTRASONIC_H_
#include "main.h"

void Trigger_UltraSonic(GPIO_TypeDef *pGPIOx,TIM_HandleTypeDef *pHTIMx,uint16_t PinNumber);

#endif /* INC_ULTRASONIC_H_ */
