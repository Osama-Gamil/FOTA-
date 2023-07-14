/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include <string.h>
#include <stdio.h>

#include "ultrasonic.h"
#include "motors.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef enum{
	MiddleUS=0,
	RightUS,
	LeftUS,
}state_t;


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

extern void Trigger_US_left(void *para);
extern void Trigger_US_right(void *para);
extern void Trigger_US_middle(void *para);

extern void Handle_US_Reading(void *para);

extern void Handle_UART_Reading(void *param);
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

extern uint8_t RxBuffer;

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
#define TRIG_LEFT_PIN 			GPIO_PIN_9
#define TRIG_RIGHT_PIN 			GPIO_PIN_8
#define TRIG_MIDDLE_PIN			GPIO_PIN_11

#define TRIG_PORT				GPIOC

/*extern state_t current_us;*/

extern TaskHandle_t handle_leftUS;
extern TaskHandle_t handle_rightUS;
extern TaskHandle_t handle_middleUS;
extern TaskHandle_t handle_ReadingUS;

extern SemaphoreHandle_t US_Sema;

extern QueueHandle_t Queue_LeftReading;
extern QueueHandle_t Queue_RightReading;
extern QueueHandle_t Queue_MiddleReading;
extern QueueHandle_t Queue_UARTStatus;
extern TimerHandle_t handle_software_timer;
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
