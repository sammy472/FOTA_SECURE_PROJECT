/************************************
 * uart_if.h
 ************************************/
#ifndef UART_IF_H
#define UART_IF_H

#include <stdint.h>
#include <string.h>


#define UART_TIMEOUT 5000

void UART_Send_String(const char *str);
uint32_t UART_Receive_Firmware(uint8_t *buffer);

#endif
