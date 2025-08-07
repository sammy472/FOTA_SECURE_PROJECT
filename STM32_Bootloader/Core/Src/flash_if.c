/************************************
 * flash_if.c
 ************************************/
#include "flash_if.h"
#include "stm32f1xx_hal.h"
#include <string.h>

void Flash_Erase(uint32_t start_address, uint32_t length)
{
    HAL_FLASH_Unlock();
    uint32_t page_error = 0;
    FLASH_EraseInitTypeDef erase = {
        .TypeErase = FLASH_TYPEERASE_PAGES,
        .PageAddress = start_address,
        .NbPages = (length / FLASH_PAGE_SIZE) + 1
    };
    HAL_FLASHEx_Erase(&erase, &page_error);
    HAL_FLASH_Lock();
}

void Flash_Write(uint32_t address, uint8_t *data, uint32_t length)
{
    HAL_FLASH_Unlock();
    for (uint32_t i = 0; i < length; i += 2)
    {
        uint16_t half_word = data[i] | (data[i + 1] << 8);
        HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD, address + i, half_word);
    }
    HAL_FLASH_Lock();
}

void Backup_Current_Firmware(uint32_t src, uint32_t dest)
{
    uint32_t size = MAX_FW_SIZE;
    uint8_t buffer[FLASH_PAGE_SIZE];
    for (uint32_t offset = 0; offset < size; offset += FLASH_PAGE_SIZE)
    {
        memcpy(buffer, (uint8_t *)(src + offset), FLASH_PAGE_SIZE);
        Flash_Erase(dest + offset, FLASH_PAGE_SIZE);
        Flash_Write(dest + offset, buffer, FLASH_PAGE_SIZE);
    }
}