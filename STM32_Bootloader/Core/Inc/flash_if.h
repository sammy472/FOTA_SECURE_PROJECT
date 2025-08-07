/************************************
 * flash_if.h
 ************************************/
#ifndef FLASH_IF_H
#define FLASH_IF_H

#include <stdint.h>

#define FLASH_PAGE_SIZE     1024U
#define MAX_FW_SIZE         (48 * 1024U) // 48KB max firmware size

void Flash_Erase(uint32_t start_address, uint32_t length);
void Flash_Write(uint32_t address, uint8_t *data, uint32_t length);
void Backup_Current_Firmware(uint32_t src, uint32_t dest);

#endif