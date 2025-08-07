/************************************
 * crc_if.c
 ************************************/
#include "crc_if.h"
#include "crc.h"
#include "usart.h"

uint32_t Calculate_CRC(uint8_t *data, uint32_t len){

    return HAL_CRC_Calculate(&hcrc, (uint32_t*)data, len / 4);
}

bool CRC_Check_Passed(uint8_t *data, uint32_t len){
    uint32_t received_crc;
    HAL_UART_Receive(&huart1, (uint8_t*)&received_crc, sizeof(uint32_t), HAL_MAX_DELAY);
    uint32_t calc_crc = Calculate_CRC(data, len);
    return (calc_crc == received_crc);
}