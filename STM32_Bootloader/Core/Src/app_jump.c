/************************************
 * app_jump.c
 ************************************/
#include "app_jump.h"
#include "stm32f1xx_hal.h"

typedef void (*pFunction)(void);

void Jump_To_Application(uint32_t app_addr){
    uint32_t jump_address = *(__IO uint32_t*)(app_addr + 4);
    pFunction JumpToApplication = (pFunction)jump_address;

    __disable_irq();
    HAL_DeInit();
    __set_MSP(*(__IO uint32_t*)app_addr);
    JumpToApplication();
}