/************************************
 * crc_if.h
 ************************************/
#ifndef CRC_IF_H
#define CRC_IF_H

#include <stdint.h>
#include <stdbool.h>
#include"main.h"

CRC_HandleTypeDef hcrc;

uint32_t Calculate_CRC(uint8_t *data, uint32_t len);
bool CRC_Check_Passed(uint8_t *data, uint32_t len);

#endif
