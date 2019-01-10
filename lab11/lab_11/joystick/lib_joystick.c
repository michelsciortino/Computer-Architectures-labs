/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           joystick.h
** Last modified Date:  2018-12-30
** Last Version:        V1.00
** Descriptions:        Atomic joystick init functions
** Correlated files:    lib_joystick.c, funct_joystick.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/

#include "lpc17xx.h"
#include "joystick.h"

uint8_t center, down, left, right, up;


/*----------------------------------------------------------------------------
  Function that initializes joysticks and switch them off
 *----------------------------------------------------------------------------*/

void joystick_init(void){
	//enabling center key
  LPC_PINCON->PINSEL3 &= ~(3<<18);	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR		&= ~(1<<25);	//P1.25 Input (joysticks on PORT1 defined as Input)
	
	//enabling down key
	LPC_PINCON->PINSEL3 &= ~(3<<20);	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR		&= ~(1<<26);	//P1.25 Input (joysticks on PORT1 defined as Input)
	
	//enabling left key
	LPC_PINCON->PINSEL3 &= ~(3<<22);	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR		&= ~(1<<27);	//P1.25 Input (joysticks on PORT1 defined as Input)
	
	//enabling right 
	LPC_PINCON->PINSEL3 &= ~(3<<24);	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR		&= ~(1<<28);	//P1.25 Input (joysticks on PORT1 defined as Input)
	
	//enabling up key
	LPC_PINCON->PINSEL3 &= ~(3<<26);	//PIN mode GPIO (00b value per P1.25)
	LPC_GPIO1->FIODIR		&= ~(1<<29);	//P1.25 Input (joysticks on PORT1 defined as Input)
}
