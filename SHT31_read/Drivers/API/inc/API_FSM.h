/*
 * API_FSM.h
 *
 *  Created on: Mar 25, 2023
 *      Author: leonardo
 */

#ifndef API_INC_API_FSM_H_
#define API_INC_API_FSM_H_

#define FSM_MEASURE_WAIT_TIME 20	//sensor wait time
#define FSM_SAMPLE_PERIOD 10000		//sensor measure every 10 seconds
#define MSG_MAX_LENGHT 50			//Output data max length

void FSM_init();
void FSM_update();

typedef enum{
IDLE,					//Waiting for new measure
NEW_MEASURE,			//Sends new measure commands
MEASURING,				//Waiting measure time
DATA_READ,				//Sends read command to sensor
SEND_DATA				//Sends read data to UART
} SensorReadState_t;

#endif /* API_INC_API_FSM_H_ */
