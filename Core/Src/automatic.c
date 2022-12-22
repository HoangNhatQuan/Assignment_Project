/*
 * automatic.c
 *
 *  Created on: Dec 6, 2022
 *      Author: Asus
 */

#include "automatic.h"

int status = INIT;
void automatic_run(){
	switch(status){
		case INIT:
			//tracffic 1
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);
			if(timer1_flag == 1){
				status = AUTO_RED_3s;
				setTimer1(time_green);
			}
			//sau 1s se doi trang thai
			break;
		case AUTO_RED_3s:
			//tracffic 1 do
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_RESET);
			//tracffic 2 xanh
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);

			if(timer1_flag == 1){
				status = AUTO_RED_2s;
				setTimer1(time_yellow);
			}
			if(is_button_Pressed(0)) {
				status = MAN_RED_GREEN ;
				setTimer4(TIME_BACK_AUTO) ;
			}
			break;
		case AUTO_RED_2s:
			//tracffic 1 do
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_RESET);
			//tracffic 2 vang
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);

			if(timer1_flag == 1){
				status = AUTO_GREEN;
				setTimer1(time_green);
			}
			if(is_button_Pressed(0)) {
				setTimer4(TIME_BACK_AUTO) ;
				status = MAN_RED_YELLOW ;
			}
			break;
		case AUTO_GREEN:
			//tracffic 1 xanh
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 do
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_RESET);
			if(timer1_flag == 1){
				status = AUTO_YELLOW;
				setTimer1(time_yellow);
			}
			if(is_button_Pressed(0)) {
				status = MAN_GREEN_RED ;
				setTimer4(TIME_BACK_AUTO) ;
			}
			break;
		case AUTO_YELLOW:
			//tracffic 1 vang
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 do
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_RESET);
			if(timer1_flag == 1){
				status = AUTO_RED_3s;
				setTimer1(time_green);
			}
			if(is_button_Pressed(0)) {
				status = MAN_YELLOW_RED;
				setTimer4(TIME_BACK_AUTO) ;
			}
			break;
		default:
			break;
	}
}
