

/**
 * main.c
 */
#include "GPIO.h"

int main(void)
{
	GPIO_Init();
	uint8_t input1,input2;
	while(1){
	    GPIO_Read(2,&input1);
	    GPIO_Read(1,&input2);
	    if(input2 == 0x00){
	        GPIO_Write(0,0xff);
	    }else if(input1 == 0x00){
	        GPIO_Write(0,0x00);
	    }
	}
    return 0;
}
