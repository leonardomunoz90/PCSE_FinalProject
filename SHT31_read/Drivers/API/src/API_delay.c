/*
 * API_delay.c
 *
 *  Created on: Mar 18, 2023
 *      Author: leonardo
 */
#include "API_delay.h"

// Initializes delay structure
void delayInit(delay_t *delay, tick_t duration) {
	delay->duration = duration;
	delay->running = false;
}


bool_t delayRead(delay_t *delay) {
	if(delay->duration == 0)
		return false;						// Checks delay duration
	if (!delay->running) {					//If not running, it starts counting
		delay->running = true;
		delay->startTime = GetTick();		//Uses HAL_GetTick in ports.c
		return false;						//
	} else {
		if ((GetTick() - delay->startTime) >= delay->duration) {
			delay->running = false;
			return true;					// Returns true when the time has elapsed
		} else
			return false;					//returns false when wait period is not over yet
	}
}

void delayWrite(delay_t *delay, tick_t duration) {
	delay->duration = duration;				//Changes delay duration
}

