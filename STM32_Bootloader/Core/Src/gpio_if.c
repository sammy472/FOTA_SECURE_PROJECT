/************************************
 * gpio_if.c
 ************************************/
#include "gpio_if.h"

bool Is_OTA_Triggered(GPIO_TypeDef *port, uint16_t pin){

    return (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET);
}
