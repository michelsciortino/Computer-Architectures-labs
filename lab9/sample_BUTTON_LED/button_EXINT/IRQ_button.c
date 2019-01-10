#include "button.h"
#include "lpc17xx.h"

#include "../led/led.h"
extern unsigned int unique_on_led;

void EINT0_IRQHandler (void)	  
{
	unsigned int led = (unique_on_led + 1) % 8;
	Unique_Led_On(led);
  	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  
{
  	unsigned int led = (unique_on_led - 1) % 8;
	Unique_Led_On(led);
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  
{
	LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


