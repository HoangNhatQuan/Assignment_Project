/*
 * tunning_mode.c
 *
 *  Created on: Dec 16, 2022
 *      Author: hieun
 */

#include "tunning_mode.h"
void tunning_mode(){
	switch (status) {
		case TUNING_YELLOW:
			//tracffic 1 vang
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 vang
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);
			if(!is_button_long_Pressed(2)){
				if(is_button_Pressed(2)) time_yellow += 100 ;
			}else if(is_button_long_Pressed(2)){
				if(is_button_Pressed(2)) time_yellow -= 100 ;
				if(time_yellow <= 100) time_yellow = 100 ;
			}
			if(is_button_Pressed(1)) status = TUNING_GREEN ;
			if(is_button_Pressed(0)) {
				status = AUTO_RED_3s ;
			}
			break;
		case TUNING_GREEN:
			//tracffic 1 xanh
			HAL_GPIO_WritePin(Tracffic_1A_GPIO_Port, Tracffic_1A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_1B_GPIO_Port, Tracffic_1B_Pin, GPIO_PIN_SET);
			//tracffic 2 xanh
			HAL_GPIO_WritePin(Tracffic_2A_GPIO_Port, Tracffic_2A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(Tracffic_2B_GPIO_Port, Tracffic_2B_Pin, GPIO_PIN_SET);
			if(!is_button_long_Pressed(2)){
				if(is_button_Pressed(2)) time_green += 100 ;
			}else if(is_button_long_Pressed(2)){
				if(is_button_Pressed(2)) time_green -= 100 ;
				if(time_green <= 100) time_green = 100 ;
			}
			if(is_button_Pressed(1)) status = TUNING_YELLOW;
			if(is_button_Pressed(0)) {
				status = AUTO_RED_3s ;
			}
			break;
		default:
			break;
	}
}
