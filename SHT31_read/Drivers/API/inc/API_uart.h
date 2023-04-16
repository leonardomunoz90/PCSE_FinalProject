/*
 * API_uart.h
 *
 *  Created on: Apr 1, 2023
 *      Author: leonardo
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

#include "stdbool.h"
#include "stdint.h"

typedef bool bool_t;

bool_t uartInit();	//Inicialización de UART
void sendStringUart(uint8_t * buf, uint8_t size);

#endif /* API_INC_API_UART_H_ */
