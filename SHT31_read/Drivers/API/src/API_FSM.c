/*
 * API_debounce.c
 *
 *  Created on: Mar 25, 2023
 *      Author: leonardo
 */

#include "API_FSM.h"
#include "API_sht31.h"
#include "API_uart.h"
#include "string.h"

static SensorReadState_t SensorReadState; // Variable interna de maquina de estados
static sht31_t sht31Sensor;
static delay_t delaySamplePeriod;
static delay_t delayMeasuring;
static uint8_t buf[MSG_MAX_LENGHT];

void FSM_init() {
	SensorReadState = IDLE;
	delayInit(&delaySamplePeriod, FSM_SAMPLE_PERIOD);
	delayInit(&delayMeasuring, FSM_MEASURE_WAIT_TIME);
	sht31Sensor.errState=false;
	sht31Sensor.humidity=0;
	sht31Sensor.temperature=0;
	sht31Sensor.readCMD = SS_CLOCK_STR_DIS_HGH_REP;
}

void FSM_update() {
	switch (SensorReadState) {
	case IDLE:
		if (delayRead(&delaySamplePeriod)) {
			SensorReadState = NEW_MEASURE;
		}
		break;
	case NEW_MEASURE:
		initNewMeasure(&sht31Sensor);
		if ( !sht31Sensor.errState) {
			SensorReadState = MEASURING;
		}
		if (sht31Sensor.errState) {
			SensorReadState = SEND_DATA;
		}
		break;
	case MEASURING:
		if (delayRead(&delayMeasuring)) {
			SensorReadState = DATA_READ;
		}
		break;
	case DATA_READ:
		readSensorData(&sht31Sensor);
		SensorReadState = SEND_DATA;
		break;
	case SEND_DATA:
		sensorDataString(&sht31Sensor,buf);
		sendStringUart(buf,(uint8_t) strlen(buf));
		SensorReadState = IDLE;
		break;
	default:
		SensorReadState = IDLE;
		break;
	}
}
