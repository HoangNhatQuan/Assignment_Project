/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern TIM_HandleTypeDef htim3;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Ped_But_Pin GPIO_PIN_0
#define Ped_But_GPIO_Port GPIOA
#define Button_1_Pin GPIO_PIN_1
#define Button_1_GPIO_Port GPIOA
#define Button_2_Pin GPIO_PIN_4
#define Button_2_GPIO_Port GPIOA
#define Button_3_Pin GPIO_PIN_0
#define Button_3_GPIO_Port GPIOB
#define Ped_ledA_Pin GPIO_PIN_10
#define Ped_ledA_GPIO_Port GPIOB
#define Ped_ledB_Pin GPIO_PIN_8
#define Ped_ledB_GPIO_Port GPIOA
#define Tracffic_1A_Pin GPIO_PIN_10
#define Tracffic_1A_GPIO_Port GPIOA
#define Tracffic_1B_Pin GPIO_PIN_3
#define Tracffic_1B_GPIO_Port GPIOB
#define Tracffic_2B_Pin GPIO_PIN_4
#define Tracffic_2B_GPIO_Port GPIOB
#define Tracffic_2A_Pin GPIO_PIN_5
#define Tracffic_2A_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
