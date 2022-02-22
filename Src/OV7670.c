/*
 * OV7670.c
 *
 *  Created on: 22-Feb-2022
 *      Author: Kunal
 */

#include "OV7670.h"

static void OV7670_Parallel_Port_Init(GPIO_TypeDef *port){
	GPIO_Pin_Setup(port, 0,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 1,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 2,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 3,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 4,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 5,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 6,INPUT_PULLDW, NONE);
	GPIO_Pin_Setup(port, 7,INPUT_PULLDW, NONE);
}


static uint8_t OV7670_Parallel_Read(GPIO_TypeDef *port){
	uint8_t temp;
	temp = 0x00FF & port->IDR;
	return temp;
}

static void OV7670_Parallel_Write(GPIO_TypeDef *port, uint8_t data){
	port->ODR = 0x00FF & data;
}

static void OV7670_I2C_Port_Init(I2C_TypeDef *port){
	OV7670_I2C.I2C = port;
	OV7670_I2C.mode = I2C_Fast_Mode;
	I2C_Master_Init(OV7670_I2C);
}

static void OV7670_Reset_Init(GPIO_TypeDef *gpio_port)
{
	GPIO_Pin_Setup(gpio_port, 8,GENERAL_PURPOSE_OUTPUT_PUSHPULL_PULLUP, NONE);
}

void OV7670_Reset(GPIO_TypeDef *gpio_port)
{
	GPIO_Pin_Low(gpio_port, 8);
	Delay_ms(1);
	GPIO_Pin_High(gpio_port, 8);
}

void OV7670_Init(GPIO_TypeDef *gpio_port,I2C_TypeDef *i2c_port){
	OV7670_Parallel_Port_Init(gpio_port);
	OV7670_I2C_Port_Init(i2c_port);
	OV7670_Reset_Init(gpio_port);


}


void OV7670_Read_Image_Data(uint8_t *buffer){

}

