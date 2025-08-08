/************************************
 * error_handler.c
 ************************************/
#include "fota_error_handler.h"
#include "main.h"

void FOTA_Error_Handler(void)
{
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
        HAL_Delay(1000);
    }
}
