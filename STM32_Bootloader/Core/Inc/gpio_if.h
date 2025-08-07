/************************************
 * gpio_if.h
 ************************************/
#ifndef GPIO_IF_H
#define GPIO_IF_H

#include <stdbool.h>
#include "stm32f1xx_hal.h"

bool Is_OTA_Triggered(GPIO_TypeDef *port, uint16_t pin);

#endif