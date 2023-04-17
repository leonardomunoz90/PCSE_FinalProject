/*
 * API_FSM.c
 *
 *  Created on: Mar 25, 2023
 *      Author: leonardo
 */

#include "API_FSM.h"
#include "API_sht31.h"
#include "string.h"
#include "API_delay.h"

static SensorReadState_t SensorReadState; 	// FSM states
static sht31_t sht31Sensor;					//sensor data variable
static delay_t delaySamplePeriod;			//delay sample period structure
static delay_t delayMeasuring;				//measure time delay structure
static uint8_t buf[MSG_MAX_LENGHT];			//buffer of print messages

void FSM_init() {
	delayInit(&delaySamplePeriod, FSM_SAMPLE_PERIOD);
	delayInit(&delayMeasuring, FSM_MEASURE_WAIT_TIME);
	sht31Sensor.errState=false;
	sht31Sensor.humidity=0;
	sht31Sensor.temperature=0;
	sht31Sensor.readCMD = SS_CLOCK_STR_DIS_HGH_REP;
	SensorReadState = IDLE;					//Initialize FMS and goes to IDLE state
}

void FSM_update() {
	switch (SensorReadState) {
	case IDLE:
		if (delayRead(&delaySamplePeriod)) {
			SensorReadState = NEW_MEASURE;	//When sample period has elapsed, initializes another
		}
		break;
	case NEW_MEASURE:
		initNewMeasure(&sht31Sensor);		//sends new measure command
		if (!sht31Sensor.errState) {
			SensorReadState = MEASURING;	//If read command was sent correctly, waits for it to complete
		}
		else {
			SensorReadState = SEND_DATA; 	//If there is a error, send a error message via UART
		}
		break;
	case MEASURING:
		if (delayRead(&delayMeasuring)) {
			SensorReadState = DATA_READ;	//When measure is ready, goes to sensor measure
		}
		break;
	case DATA_READ:
		readSensorData(&sht31Sensor);		//stores data in sensor structure, whether is correct or not
		SensorReadState = SEND_DATA;		//sends data state
		break;
	case SEND_DATA:
		sensorDataString(&sht31Sensor,buf);	//create string with temperature and humidity
											// creates an error message if errState is asserted
		sendStringUart(buf,(uint8_t) strlen(buf));	//send string via UART
		SensorReadState = IDLE;						//waits for new measure
		break;
	default:
		SensorReadState = IDLE;				//in case states reaches this section, goes back to IDLE state
		break;
	}
}
