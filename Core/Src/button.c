/*
 * button.h
 *
 *  Created on: Oct 28, 2022
 *      Author: hieun
 */



#include "button.h"
/* 3 button corresponds to 3 flag of normal press and 3 flag of long press
 * add more button if you need
 * something you must be change if you add more button
 * that place is marked with (*)
 * */
int nor_flag[NUM_OF_BUTTONS] = {0, 0, 0};	// (*)
int long_flag[NUM_OF_BUTTONS] ={0, 0, 0};	// (*)

int KeyReg0[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};	// (*)
int KeyReg1[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};	// (*)
int KeyReg2[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};	// (*)
int KeyReg3[NUM_OF_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};	// (*)

int TimeOutForKeyPress[NUM_OF_BUTTONS] =  {0,0,0};							// (*)

int time_count_up[NUM_OF_BUTTONS] = {TIME_HOLD, TIME_HOLD, TIME_HOLD} ;		// (*)

int is_button_Pressed(int index){
	if(nor_flag[index] == 1){
			nor_flag[index] = 0;
			return 1;
		}
		return 0 ;
}
int is_button_long_Pressed(int index){
	if(long_flag[index] == 1) return 1;
	return 0 ;
}
int is_button_pressed_3s(int index) {
	if(long_flag[index] == 1){
			return 1;
		}
	return 0 ;
}

void subKeyProcess(int index){
	 nor_flag[index] = 1 ;

}

void subKeyLongPress(int index){
	long_flag[index] = 1 ;
}
void getKeyInput(){
	for (int i = 0 ; i < NUM_OF_BUTTONS ; i++){

		KeyReg0[i] = KeyReg1[i];
	  	KeyReg1[i]= KeyReg2[i];

	  	if( i == 0 ) KeyReg2[i] = HAL_GPIO_ReadPin(Button1, B1_PIN);
	  	else if (i == 1) KeyReg2[i] = HAL_GPIO_ReadPin(Button2, B2_PIN);
	  	else if (i == 2) KeyReg2[i] = HAL_GPIO_ReadPin(Button3, B3_PIN);
	  	//else if (i == N) KeyRegN[i] = HAL_GPIO_ReadPin(your_button_port, your_button_pin);  (*)

	  	if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
	  		if (KeyReg3[i] != KeyReg2[i]){
	  	       KeyReg3[i] = KeyReg2[i];
	  	      if (KeyReg2[i] == PRESSED_STATE){
	  	        TimeOutForKeyPress[i] = 0;
	  	        subKeyProcess(i);			// flag = 1
	  	      }
	  	    }
	  	   else{
	  		   if(long_flag[i] == 1){
	 	  		  TimeOutForKeyPress[i]++;
	 	  	       if(TimeOutForKeyPress[i] > TIME_AUTO  ){
	 	  	   // 	subKeyLongPress(i);
	 	  	          KeyReg3[i] = NORMAL_STATE;
	 	  	        }
	  		   }else{
		  		   	TimeOutForKeyPress[i]++;
		  	        if(TimeOutForKeyPress[i] > TIME_HOLD  ){
		  	          subKeyLongPress(i);		// flag = 1
		  	          KeyReg3[i] = NORMAL_STATE;
		  	        }
	  		   }
	  	    }
	  	  }
	  	else{
	  		long_flag[i] = 0;
	  	}
	}

}

