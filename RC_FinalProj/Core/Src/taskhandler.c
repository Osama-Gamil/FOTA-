/*
 * taskhandler.c
 *
 *  Created on: May 30, 2023
 *      Author: moham
 */


#include "taskhandler.h"

uint8_t msg[]="Hello there \n";



void Trigger_US_left(void *para){

	while(1){

		/*This function will set the trigger pin high for 10
		microseconds to trigger the ULTRASONIC sensor*/
		Trigger_UltraSonic(TRIG_PORT, &htim1, TRIG_LEFT_PIN);

		/*This task will be delayed for 500 MS */
		vTaskDelay(pdMS_TO_TICKS(200));
		}

}

void Trigger_US_right(void *para){

	while(1){

		/*This function will set the trigger pin high for 10
		microseconds to trigger the ULTRASONIC sensor*/
		Trigger_UltraSonic(TRIG_PORT, &htim1, TRIG_RIGHT_PIN);

		/*This task will be delayed for 500 MS */
		vTaskDelay(pdMS_TO_TICKS(200));
		}

}

void Trigger_US_middle(void *para){


	while(1){

		/*This function will set the trigger pin high for 10
		microseconds to trigger the ULTRASONIC sensor*/
		Trigger_UltraSonic(TRIG_PORT, &htim1, TRIG_MIDDLE_PIN);

		/*This task will be delayed for 500 MS */
		vTaskDelay(pdMS_TO_TICKS(200));
	}
}

void Handle_US_Reading(void *para){

	/*This task is the highest priority so it will run everytime it gets notified*/

	static int distanceL,distanceR,distanceM,ICU_READR,ICU_READL,ICU_READM;
	static int prevR,prevL;

	while(1){

		/*This line is sending this task to the blocked state
		until it gets notified from the ISR of the ICU*/
		xTaskNotifyWait(0,0,NULL,portMAX_DELAY);

		taskDISABLE_INTERRUPTS();

		/*checking which ULTRASONIC started the trigger */
		switch(current_us){
			case LeftUS:
			/*Receiving the data from the queue (ONLY THE ISR is sending data to the queue)*/
				/*the data is the time taken by the US Waves to bounce from the obstacle x2*/
			xQueueReceive(Queue_LeftReading, &ICU_READL, portMAX_DELAY);

			/*Calculating the distance */
			distanceL=(ICU_READL/2)/29;
			prevL=distanceL;
			printf("Left : %d\n",distanceL);
			if(distanceL < 9){
				HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2);
				//xTimerStop(handle_software_timer,0);
				//Move_Right();
				//xTimerStart(handle_software_timer,0);

			}
			else{
				//Do nothing
			}
				break;

			/*SAME Here but for the RIGHT US*/
			case RightUS:
				xQueueReceive(Queue_RightReading, &ICU_READR, portMAX_DELAY);

				distanceR=(ICU_READR/2)/29;
				prevR=distanceR;
				printf("Right : %d\n",distanceR);
					if(distanceR < 9){
						HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
						//xTimerStop(handle_software_timer,0);
						//Move_Left();
						//xTimerStart(handle_software_timer,0);
					}
					else{
						//Do nothing
					}
				break;

			case MiddleUS:

				xQueueReceive(Queue_MiddleReading, &ICU_READM, portMAX_DELAY);

				distanceM=(ICU_READM/2)/29;

				printf("Middle : %d\n",distanceM);
					if(distanceM < 9){
						HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
						//Check left and right
						if(prevL>prevR){
							//xTimerStop(handle_software_timer,0);
							//Move_Left();
							//xTimerStart(handle_software_timer,0);
						}
						else{
							//xTimerStop(handle_software_timer,0);
							//Move_Right();
							//xTimerStart(handle_software_timer,0);
						}
					}
					else{
						/*Do nothing*/
					}
					break;


				}


			taskENABLE_INTERRUPTS();

		}

}


void Handle_UART_Reading(void *param){
uint8_t state;
	while(1){
		xQueueReceive(Queue_UARTStatus, (void*)&state, portMAX_DELAY);

		switch(state){

		case 'L':
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
			//Move_Forward();
			break;

		case 'R':
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_2);
			//Move_Right();
			break;

		case 'F':
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_3);
			//Move_Left();
			break;

		case 'W':
			HAL_TIM_IC_Stop_IT(&htim2, TIM_CHANNEL_2);
			HAL_TIM_IC_Stop_IT(&htim3, TIM_CHANNEL_1);
			HAL_TIM_IC_Stop_IT(&htim4, TIM_CHANNEL_1);
			break;

		case 'w':
			HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_2);
			HAL_TIM_IC_Start_IT(&htim3, TIM_CHANNEL_1);
			HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_1);
			break;

		case 'k':
			break;

		}

	}
}



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t counterL=0,counterR=0,counterM;
	static	uint32_t first_readL,second_readL;
	static	uint32_t first_readR,second_readR;
	static	uint32_t first_readM,second_readM;
	static uint32_t readingL,readingR,readingM;



	/*First if condition is checking which timer
	caused the input capture unit to interrupt*/
	if(htim->Instance==TIM2){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2){
			if(counterL==0)
			{
				/*Getting the timer counter at which the RISING edge happened at the ICU Pin*/
				first_readL= __HAL_TIM_GET_COMPARE(htim , TIM_CHANNEL_2);
				counterL++;

			}
			else if(counterL==1)
			{
				/*Getting the timer counter at which the FALLING edge happened at the ICU Pin*/
				second_readL= __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_2);
				counterL=0;

				if(second_readL>=first_readL){
					readingL=second_readL-first_readL;
				}
				else{
					readingL=(0xFFFFFFFF-second_readL)+first_readL;
				}

				current_us=LeftUS;

				/*	Sending the time difference between the falling and rising
		  	  	  * 	which defines the time taken to bounce*/
				xQueueSendFromISR(Queue_LeftReading,(void*)&readingL,NULL);

				xTaskNotifyFromISR(handle_ReadingUS,0,eNoAction,NULL);
			}
		}
	}

	/*same here but for TIMER3*/
	else if(htim->Instance ==TIM3){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){
			if(counterR==0)
			{
				first_readR= __HAL_TIM_GET_COMPARE(htim , TIM_CHANNEL_1);
				counterR++;

			}
			else if(counterR==1)
			{
				second_readR= __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1);
				counterR=0;

				if(second_readR>=first_readR){
					readingR=second_readR-first_readR;
				}
				else{
					readingR=(0xFFFF-second_readR)+first_readR;
				}
				current_us=RightUS;
				xQueueSendFromISR(Queue_RightReading,(void*)&readingR,NULL);

				xTaskNotifyFromISR(handle_ReadingUS,0,eNoAction,NULL);
			}
		}
	}
	else if(htim->Instance==TIM4){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){
			if(counterM==0)
			{
				first_readM= __HAL_TIM_GET_COMPARE(htim , TIM_CHANNEL_1);
				counterM++;

			}
			else if(counterM==1)
			{
				second_readM= __HAL_TIM_GET_COMPARE(htim,TIM_CHANNEL_1);
				counterM=0;

				if(second_readM>=first_readM){
					readingM=second_readM-first_readM;
				}
				else{
					readingM=(0xFFFF-second_readM)+first_readM;
				}
				current_us=MiddleUS;
				xQueueSendFromISR(Queue_MiddleReading,(void*)&readingM,NULL);

				xTaskNotifyFromISR(handle_ReadingUS,0,eNoAction,NULL);
			}

		}
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

	xQueueSendFromISR(Queue_UARTStatus,(void*)&RxBuffer,NULL);

	HAL_UART_Receive_IT(&huart3, &RxBuffer, 1);
}
