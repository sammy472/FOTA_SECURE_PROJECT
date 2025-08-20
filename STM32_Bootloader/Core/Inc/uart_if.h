/************************************
 * uart_if.h
 ************************************/
#ifndef UART_IF_H
#define UART_IF_H
#include "main.h"
#include <stdint.h>
#include <string.h>


#define UART_TIMEOUT 5000

void UART_Send_String(const char *str, UART_HandleTypeDef* huart1);
uint32_t UART_Receive_Firmware(uint8_t *buffer, UART_HandleTypeDef* huart1);

#endif
