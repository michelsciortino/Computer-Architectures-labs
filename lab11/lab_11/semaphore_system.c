#include <stdio.h>
#include "LPC17xx.H"                    /* LPC17xx definitions                */
#include "led/led.h"
#include "button_EXINT/button.h"
#include "timer/timer.h"
#include "semaphore_system.h"

uint8_t curr_state;
blink_state_t blink_state;

void input_handler(input_t input){
	switch(curr_state)
	{
		case state_ped_green:
			if(input == timeout)
				change_state(state_ped_blinking);
			else if(input == pedestian_request)
				change_state(state_ped_green);			
			break;
			
		case state_ped_blinking:
				if(input == pedestian_request)
					change_state(state_ped_green);
				else if(input == timeout)
					change_state(state_car_green);					
			break;
				
		case state_car_green:	
				if(input == timeout)
					change_state(state_car_yellow);
				else if(input == pedestian_request)
					reset_timer(0);
					init_timer(0,_5sec);
					enable_timer(0);	
			break;
				
		case state_car_yellow:
				if(input == pedestian_request)
					break; //NOP					
				else if(input == timeout)
					change_state(state_ped_green);
			break;
		
		default:break;
	}
}

void change_state(sem_state_t new_state){
	switch(new_state){
		case state_ped_green:
				if(curr_state==state_ped_blinking){
					disable_timer(1);
					reset_timer(1);					
				}
				curr_state=state_ped_green;
				reset_timer(0);
				init_timer(0,_15sec);
				LED_Out(mask_ped_green);
				enable_timer(0);
				break;
			
		case state_ped_blinking:
				curr_state=state_ped_blinking;
				reset_timer(0);
				init_timer(0,_5sec);
				blink_state= ON;
				blink();
				enable_timer(0);
			break;
				
		case state_car_green:
				reset_timer(1);
				reset_timer(0);
				disable_timer(0);
				disable_timer(1);
				curr_state=state_car_green;				
				LED_Out(mask_car_green);
			break;
				
		case state_car_yellow:
				reset_timer(0);
				init_timer(0,_5sec);
				curr_state=state_car_yellow;				
				LED_Out(mask_car_yellow);
				enable_timer(0);
			break;
	}
}

void Semaphore_System_init(void){
	curr_state=state_ped_green;
	init_timer(0,_15sec);							/* TIMER0 Initialization              */
	LED_Out(mask_ped_green);
	enable_timer(0);
}

void blink(void){
	reset_timer(1);
	init_timer(1,_500msec);
	
	switch(blink_state){
		case OFF:
			blink_state=ON;
			LED_Out(mask_ped_blinking_on);
			break;
		case ON:
			blink_state=OFF;
			LED_Out(mask_ped_blinking_off);
			break;
	}
	enable_timer(1);
}

void exit_management_mode(void){
	
}

void enter_management_mode(void){
	
}
