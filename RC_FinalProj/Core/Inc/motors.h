/*
 * motors.h
 *
 *  Created on: Jun 2, 2023
 *      Author: moham
 */

#ifndef INC_MOTORS_H_
#define INC_MOTORS_H_

#include "main.h"

#define MOTORS_PORT		GPIOC

#define RIGHT_PIN_1		GPIO_PIN_0
#define RIGHT_PIN_2		GPIO_PIN_1

#define RIGHT_EN_PIN	GPIO_PIN_2

#define LEFT_PIN_1		GPIO_PIN_3
#define LEFT_PIN_2		GPIO_PIN_4

#define LEFT_EN_PIN		GPIO_PIN_5

void Stop(void);
void Move_Left(void);
void Move_Right(void);
void Move_Backward(void);
void Move_Forward(void);

#endif /* INC_MOTORS_H_ */
