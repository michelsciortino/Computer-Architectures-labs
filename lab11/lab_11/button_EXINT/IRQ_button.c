#include "button.h"
#include "lpc17xx.h"

#include "../led/led.h"
#include "../semaphore_system.h"

void EINT0_IRQHandler (void)	  	/* INT0														 */
{
	LPC_SC->EXTINT &= (1 << 0);     /* clear pending interrupt         */
}


void EINT1_IRQHandler (void)	  	/* KEY1														 */
{
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
	input_handler(pedestian_request);
}

void EINT2_IRQHandler (void)	  	/* KEY2														 */
{
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */
	input_handler(pedestian_request);
}


