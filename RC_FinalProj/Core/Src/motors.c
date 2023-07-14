/*
 * motors.c
 *
 *  Created on: Jun 2, 2023
 *      Author: moham
 */
#include "motors.h"


void Move_Forward(void){
	  /* Setting Direction of Pins to Move Car Forward */
		/* Right */
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_EN_PIN,SET);

	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_2,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_EN_PIN,SET);
}

void Move_Backward(void){
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_EN_PIN,SET);

	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_2,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_EN_PIN,SET);
}

void Move_Right(void){
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_EN_PIN,SET);

	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_2,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_EN_PIN,SET);
}

void Move_Left(void){
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_EN_PIN,SET);

	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_1,SET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_2,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_EN_PIN,SET);
}

void Stop(void){
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, RIGHT_EN_PIN,RESET);

	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_1,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_PIN_2,RESET);
	HAL_GPIO_WritePin(MOTORS_PORT, LEFT_EN_PIN,RESET);
}
