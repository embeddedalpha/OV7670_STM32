#include <stdint.h>
#include "main.h"
#include "I2C.h"
#include "GPIO.h"

//#if !defined(__SOFT_FP__) && defined(__ARM_FP)
//  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
//#endif


void OV7670_Parallel_Port_Init(GPIO_TypeDef *port);
uint8_t OV7670_Parallel_Read(GPIO_TypeDef *port);
void OV7670_Parallel_Write(GPIO_TypeDef *port, uint8_t data);

void OV7670_I2C_Port_Init(I2C_TypeDef *port);




int main(void)
{


	for(;;);
}
