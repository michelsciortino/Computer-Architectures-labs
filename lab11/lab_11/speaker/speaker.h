/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           speaker.h
** Last modified Date:  2019-01-10
** Last Version:        V1.00
** Descriptions:        
** Correlated files:    
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#ifndef __SPEAKER_H
#define __SPEAKER_H

#include "lpc17xx.h"

void speaker_init(void);
void speaker_update(void);
void speaker_pulse(void);
void speaker_set_freq(int freq);
void speaker_set_volume(int volume); /* volume between 0 and 7 */
void speaker_turn_on(void);
void speaker_turn_off(void);

#endif /* end __SPEAKER_H*/
/*****************************************************************************
**                            End Of File
******************************************************************************/
