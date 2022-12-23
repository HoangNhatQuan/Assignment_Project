/*
 * manual.c
 *
 *  Created on: Dec 8, 2022
 *      Author: hieun
 */
#include "manual.h"

void manual_run(){
	switch (status) {
		case MAN_RED_GREEN:
			//tracffic 1 do
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_RESET);
			//tracffic 2 xanh
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);
			if(is_button_Pressed(0)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = TUNING_GREEN ;
			}
			if(is_button_Pressed(1)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = MAN_RED_YELLOW;
			}
			if(timer4_flag >= 1) {
				status = AUTO_RED_3s ;
			}
			break;
		case MAN_RED_YELLOW:
			//tracffic 1 do
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_RESET);
			//tracffic 2 vang
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);
			if(is_button_Pressed(0)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = TUNING_GREEN ;
			}
			if(is_button_Pressed(1)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = MAN_GREEN_RED;
			}
			if(timer4_flag >= 1) {
				status = AUTO_RED_2s ;
			}
			break;
		case MAN_GREEN_RED:
			//tracffic 1 xanh
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 do
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_RESET);
			if(is_button_Pressed(0)){
				setTimer4(TIME_BACK_AUTO) ;
				status = TUNING_GREEN ;
			}
			if(is_button_Pressed(1)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = MAN_YELLOW_RED;
			}
			if(timer4_flag >= 1) {
				status = AUTO_GREEN ;
			}
			break;
		case MAN_YELLOW_RED:
			//tracffic 1 vang
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 do
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_RESET);
			if(is_button_Pressed(0)){
				setTimer4(TIME_BACK_AUTO) ;
				status = TUNING_GREEN ;
			}
			if(is_button_Pressed(1)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = MAN_RED_GREEN;
			}
			if(timer4_flag >= 1) {
				status = AUTO_YELLOW ;
			}
			break;
		default:
			break;
	}
}

