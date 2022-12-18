/*
 * pedestrian.c
 *
 *  Created on: Dec 18, 2022
 *      Author: MINH
 */

#include "pedestrian.h"

int pedesStatus = PEDES_OFF;
int pedesLightCountDown = LIGHT_TIME;
int buzzerStatus = BUZZ_OFF;

void pedestrian_run(){
	switch (pedesStatus){
	case PEDES_OFF:
		HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, RESET);
		HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledB_Pin, RESET);
		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
		if(is_button_Pressed(4)){
			pedesStatus = PEDES_ON;
			setTimer5(100);
			setTimer6(100);
		}
		break;
	case PEDES_ON:
		HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, SET);
		HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledB_Pin, SET);

		if(timer5_flag == 1){
			setTimer5(100);
			pedesLightCountDown--;
		}

		if(timer6_flag == 1){
			if(buzzerStatus == BUZZ_OFF){
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
				buzzerStatus = BUZZ_ON;
				setTimer6(100);
			}else{
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,100-(pedesLightCountDown/3)*10);
				buzzerStatus = BUZZ_OFF;
				setTimer6(pedesLightCountDown*10);
			}
		}

		if(pedesLightCountDown <= 0){
			pedesLightCountDown = LIGHT_TIME;
			pedesStatus = PEDES_OFF;
		}
		break;
	default:
		break;
	}
}
