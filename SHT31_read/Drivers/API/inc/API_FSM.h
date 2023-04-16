/*
 * API_debounce.h
 *
 *  Created on: Mar 25, 2023
 *      Author: leonardo
 */

#ifndef API_INC_API_FSM_H_
#define API_INC_API_FSM_H_

#include "API_delay.h"
#include "API_sht31.h"

#define FSM_MEASURE_WAIT_TIME 20
#define FSM_SAMPLE_PERIOD 10000
#define MSG_MAX_LENGHT 50

void FSM_init();
void FSM_update();

typedef enum{
IDLE,
NEW_MEASURE,
MEASURING,
DATA_READ,
SEND_DATA
} SensorReadState_t;

#endif /* API_INC_API_FSM_H_ */
