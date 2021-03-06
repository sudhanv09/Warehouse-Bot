/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

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
#define IN1_Pin GPIO_PIN_0
#define IN1_GPIO_Port GPIOH
#define IN2_Pin GPIO_PIN_1
#define IN2_GPIO_Port GPIOH
#define ENC_2_A_Pin GPIO_PIN_0
#define ENC_2_A_GPIO_Port GPIOC
#define ENC_1_A_Pin GPIO_PIN_1
#define ENC_1_A_GPIO_Port GPIOC
#define ENC_1_B_Pin GPIO_PIN_2
#define ENC_1_B_GPIO_Port GPIOC
#define ENC_1_B_EXTI_IRQn EXTI2_IRQn
#define ENC_2_B_Pin GPIO_PIN_3
#define ENC_2_B_GPIO_Port GPIOC
#define ENC_2_B_EXTI_IRQn EXTI3_IRQn
#define IN3_Pin GPIO_PIN_1
#define IN3_GPIO_Port GPIOA
#define IN4_Pin GPIO_PIN_4
#define IN4_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_6
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_7
#define EN2_GPIO_Port GPIOA
#define INPUT2_Pin GPIO_PIN_5
#define INPUT2_GPIO_Port GPIOC
#define CS_Pin GPIO_PIN_10
#define CS_GPIO_Port GPIOB
#define INPUT1_Pin GPIO_PIN_6
#define INPUT1_GPIO_Port GPIOC
#define ENABLE1_Pin GPIO_PIN_8
#define ENABLE1_GPIO_Port GPIOC
#define RST_Pin GPIO_PIN_10
#define RST_GPIO_Port GPIOA
#define DIR_Pin GPIO_PIN_10
#define DIR_GPIO_Port GPIOC
#define STEP_Pin GPIO_PIN_11
#define STEP_GPIO_Port GPIOC
#define CLK_Pin GPIO_PIN_3
#define CLK_GPIO_Port GPIOB
#define RS_Pin GPIO_PIN_4
#define RS_GPIO_Port GPIOB
#define SDI_Pin GPIO_PIN_5
#define SDI_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
