/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           funct_joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        High level joystick management functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "joystick.h"
#include "../led/led.h"
#include "../semaphore_system.h"

void Joystick_Handler	(void){		/* Main handler for joystick input	*/
	static int center=0,down=0,left=0,right=0,up=0;
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	/* Joytick SELECT pressed */
		center++;
		if(center==2)
			JCenter_HANDLER();
	}
	else{
			center=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	/* Joytick DOWN pressed */
		down++;
		if(down==2)
			JDown_HANDLER();
	}
	else{
			down=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	/* Joytick LEFT pressed */
		left++;
		if(left==2)
			JLeft_HANDLER();
	}
	else{
			left=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	/* Joytick RIGHT pressed */
		right++;
		if(right==2)
			JRight_HANDLER();
	}
	else{
			right=0;
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	/* Joytick UP pressed */
		up++;
		if(up==2)
			JUp_HANDLER();
	}
	else{
			up=0;
	}	
}

void JCenter_HANDLER	(void){	  /* Joystick CENTER button pressed	*/
}

void JDown_HANDLER		(void){	  	/* Joystick DOWN button pressed		*/
}

void JLeft_HANDLER 		(void){	  	/* Joystick LEFT button pressed		*/
	exit_management_mode();
}

void JRight_HANDLER 	(void){	  /* Joystick RIGHT button pressed	*/
	enter_management_mode();
}

void JUp_HANDLER 			(void){	  		/* Joystick UP button pressed			*/
}

