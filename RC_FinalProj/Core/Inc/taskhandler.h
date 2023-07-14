/*
 * taskhandler.h
 *
 *  Created on: May 30, 2023
 *      Author: moham
 */

#ifndef INC_TASKHANDLER_H_
#define INC_TASKHANDLER_H_

#include "main.h"
#include "motors.h"
extern state_t current_us;
void Trigger_US_left(void *para);
void Trigger_US_right(void *para);
void Trigger_US_middle(void *para);
void Handle_US_Reading(void *para);

void Go_Right(void);
void Go_Left(void);
void Go_Forward(void);
void SoftwareTimer_Callback(TimerHandle_t xTimer);

#endif /* INC_TASKHANDLER_H_ */
