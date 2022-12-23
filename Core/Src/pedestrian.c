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
		if(is_button_Pressed(3)){
			pedesStatus = PEDES_ON;
			setTimer5(100);
			setTimer6(100);
		}
		break;
	case PEDES_ON:
		switch(status){
		case AUTO_RED_3s: //khi den traffic do thi den pedestrian mau xanh va vang
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_SET);

			break;
		case AUTO_RED_2s:
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_SET);
			break;
		case AUTO_GREEN: //khi den traffic xanh thi den pedestrian mau do
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_RESET);
			break;
		case AUTO_YELLOW://khi den traffic vang thi den pedestrian mau do
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_RESET);
			break;
			// tuong tu voi cac truong hop manual
		case MAN_RED_GREEN:
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_SET);
			break;
		case MAN_RED_YELLOW:
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_SET);
			break;
		case MAN_GREEN_RED:
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_RESET);
			break;
		case MAN_YELLOW_RED:
			HAL_GPIO_WritePin(Ped_ledA_GPIO_Port, Ped_ledA_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Ped_ledB_GPIO_Port, Ped_ledB_Pin, GPIO_PIN_RESET);
			break;
		}
		if(timer5_flag == 1){
			setTimer5(100);
			pedesLightCountDown--;
		}

		if(timer6_flag == 1){
			if(buzzerStatus == BUZZ_OFF){
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
				buzzerStatus = BUZZ_ON;
				setTimer6(pedesLightCountDown*10);
			}else{
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,100-(pedesLightCountDown/3)*10);
				buzzerStatus = BUZZ_OFF;
				setTimer6(100);
			}
		}

		if(pedesLightCountDown <= 0){
			pedesLightCountDown = LIGHT_TIME;
			pedesStatus = PEDES_OFF;
		}

		if(is_button_Pressed(3)){
			pedesStatus = PEDES_OFF;
			pedesLightCountDown = LIGHT_TIME;
		}
		break;
	default:
		break;
	}
}
