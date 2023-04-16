/*
 * port.c
 *
 *  Created on: Apr 13, 2023
 *      Author: leomu
 */

#include "stm32g0xx_hal.h"
#include "i2c.h"
#include "usart.h"

uint32_t GetTick(){
	return HAL_GetTick();
}

int8_t sendI2C_CMD (uint8_t addr, uint8_t * sendCMD,int8_t size){
	 HAL_I2C_Master_Transmit(&hi2c1, addr, sendCMD, size, 100);
	 return 0;
}
int8_t readI2C_Data (uint8_t addr,uint8_t * data,int8_t size){
	HAL_I2C_Master_Receive(&hi2c1, addr, data, size,100);
	return 0;
}

void sendStringUart(uint8_t * buf, uint8_t size){
	HAL_UART_Transmit(&huart2, buf, size, 100);
}

int __io_putchar(int ch) {
	HAL_UART_Transmit(&huart2, (uint8_t*) &ch, 1, 100);
	return ch;
}
