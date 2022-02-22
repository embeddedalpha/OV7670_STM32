/*
 * OV7670.h
 *
 *  Created on: 22-Feb-2022
 *      Author: Kunal
 */

#ifndef OV7670_H_
#define OV7670_H_

#include "main.h"
#include "GPIO.h"
#include "I2C.h"
#include "OV7670_REG.h"

I2C_Config OV7670_I2C;


void OV7670_Init(GPIO_TypeDef *gpio_port,I2C_TypeDef *i2c_port);
void OV7670_Read_Image_Data(uint8_t *buffer);


#endif /* OV7670_H_ */
