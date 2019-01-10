/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           semaphores_system.h
** Last modified Date:  2018-12-20
** Last Version:        V1.00
** Descriptions:        header for semaphore_system.c - defines states codes and semaphore colors masks
** Correlated files:    semaphore_system.c
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include <LPC17xx.H>
#include <stdio.h>

#ifndef __SEM_SYS_MAIN_H
#define __SEM_SYS_MAIN_H

#define _15sec	0x165A0BC0
#define _5sec		 0x7735940
#define _500msec  0xBEBC20

extern uint8_t curr_state;

typedef enum input{
	pedestian_request,
	timeout
} input_t;

typedef enum sem_color_mask{
	mask_ped_blinking_off	= 0x20,
	mask_ped_blinking_on	= 0x60,
	mask_ped_green				= 0x60,
	mask_car_green				= 0x88,
	mask_car_yellow				=	0x90	
} sem_color_masks_t;

typedef enum sem_state{
	state_ped_green,
	state_ped_blinking,
	state_car_green,
	state_car_yellow	
} sem_state_t;

typedef enum blink_state{
	OFF, ON
} blink_state_t;

void Semaphore_System_init(void);
void change_state(sem_state_t new_state);
void input_handler(input_t input );
void blink(void);
void exit_management_mode(void);
void enter_management_mode(void);

#endif /*end__SEM_SYS_MAIN_H*/
/*****************************************************************************
**                            End Of File
******************************************************************************/
