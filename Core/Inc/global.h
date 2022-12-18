/*
 * global.h
 *
 *  Created on: Dec 6, 2022
 *      Author: Asus
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "main.h"

extern int status;

#define 	INIT 				1
#define 	AUTO_RED_3s 		2
#define 	AUTO_RED_2s 		3
#define 	AUTO_GREEN	 		4
#define 	AUTO_YELLOW 		5

#define 	MAN_RED_GREEN		10
#define 	MAN_RED_YELLOW		11
#define 	MAN_YELLOW_RED		12
#define 	MAN_GREEN_RED		13

#define		TUNING_GREEN		20
#define 	TUNING_YELLOW		21




extern int time_red ;
extern int time_yellow ;
extern int time_green ;
#endif /* INC_GLOBAL_H_ */
