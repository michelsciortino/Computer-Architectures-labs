#include "lpc17xx.h"
#include "timer.h"

#include "./speaker.h"

uint16_t SinTable[45] =
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};

const int freqs[8]={2120,1890,1684,1592,1417,1263,1125,1062};
/*
262Hz	k=2120		c4
294Hz	k=1890		
330Hz	k=1684		
349Hz	k=1592		
392Hz	k=1417		
440Hz	k=1263		
494Hz	k=1125		
523Hz	k=1062		c5

*/

typedef enum speaker_state{
	_OFF = 0,
	_ON =1
} speaker_state_t;

float _volume=0,_freq=0;
speaker_state_t _state = _OFF;

void speaker_turn_on(void){
	TIMER2_POW_ON();
	_state = _ON;
	speaker_pulse();
}

void speaker_turn_off(void){
	_state = _OFF;
	TIMER2_POW_OFF();
}

void speaker_pulse(void){
	static int ticks=0;
	/* DAC management */	
	LPC_DAC->DACR = (uint16_t)(SinTable[ticks]*_volume)<<6;
	ticks++;
	if(ticks==45) ticks=0;
}

void speaker_set_freq(int freq){
		_freq=freq;
}

void speaker_init(){
	_freq=freqs[0];
	_state= _OFF;
	_volume=7;
}

void speaker_update(){
		if(_state==_OFF)
			return;
		disable_timer(2);
		reset_timer(2);
		init_timer(2,_freq);
		enable_timer(2);
}

void speaker_set_volume(int volume){
	if( volume<0 || volume>7) return;
	_volume = (float)volume/7;
}
