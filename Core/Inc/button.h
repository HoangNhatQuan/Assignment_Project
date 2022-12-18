/*
 * button.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hieun
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
//-------------define port button----------------
#define Button1 	Button_1_GPIO_Port
#define Button2		Button_2_GPIO_Port
#define Button3		Button_3_GPIO_Port
#define PedBut		Ped_But_GPIO_Port
//#define button N...

//-------------define pin button----------------
#define B1_PIN		Button_1_Pin
#define B2_PIN		Button_2_Pin
#define B3_PIN		Button_3_Pin
#define PB_PIN		Ped_But_Pin
//#define button N...

//------------------ do not change code line from here-----------------
#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define TIME_HOLD 100
#define TIME_AUTO 100
//----- to here---

//----- number of button------------- <can change>
#define NUM_OF_BUTTONS 4

//normal press
int is_button_Pressed(int index) ;
//long press
int is_button_long_Pressed(int index) ;
int is_button_pressed_3s(int index) ;
void getKeyInput();


#endif /* INC_BUTTON_H_ */
