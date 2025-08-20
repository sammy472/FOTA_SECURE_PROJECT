/************************************
 * uart_if.c
 ************************************/
#include "uart_if.h"


void UART_Send_String(const char *str, UART_HandleTypeDef* huart1)
{
    HAL_UART_Transmit(huart1, (uint8_t*)str, strlen(str), HAL_MAX_DELAY);
}

uint32_t UART_Receive_Firmware(uint8_t *buffer, UART_HandleTypeDef* huart1)
{
    uint32_t total = 0;
    HAL_UART_Receive(huart1, (uint8_t*)&total, sizeof(uint32_t), UART_TIMEOUT);
    HAL_UART_Receive(huart1, buffer, total, UART_TIMEOUT);
    return total;
}
