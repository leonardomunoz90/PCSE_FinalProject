/*
 * API_sht31.c
 *
 *  Created on: Apr 13, 2023
 *      Author: leonardo
 */

#include "API_sht31.h"

int8_t initNewMeasure(sht31_t *sht31Sensor) {
	uint8_t i2cWriteCMD[CMD_BYTES_SIZE];
	i2cWriteCMD[0] = (uint8_t) ((sht31Sensor->readCMD & 0xFF00) >> 8);
	i2cWriteCMD[1] = (uint8_t) (sht31Sensor->readCMD & 0x00FF);
	sendI2C_CMD((DEFAULT_ADDR << 1), i2cWriteCMD, CMD_BYTES_SIZE);
	return 0;
}

int8_t readSensorData(sht31_t *sht31Sensor) {
	uint8_t i2cReadData[DATA_BYTES_SIZE];
	readI2C_Data((DEFAULT_ADDR << 1), i2cReadData, DATA_BYTES_SIZE);
	sht31Sensor->temperature = tempConv((((uint16_t) i2cReadData[0]) << 8) | i2cReadData[1]);
	sht31Sensor->humidity = humConv((((uint16_t) i2cReadData[3]) << 8) | i2cReadData[4]);
	return 0;
}

void sensorDataString(sht31_t *sht31Sensor, uint8_t *buf) {
	if (!sht31Sensor->errState) {
		sprintf(buf, "Temperature:%.2f - Humidity:%.2f\r\n",
				sht31Sensor->temperature, sht31Sensor->humidity);
	} else {
		sprintf(buf, "Sensor error\r\n");
	}
}

float tempConv(uint16_t temp) {
	float temperature = ((float) (temp)) / 65537;
	return (-45 + (temperature * 175));
}

float humConv(uint16_t hum) {
	float humidity = (float) (hum);
	return (100 * humidity / 65537);
}
