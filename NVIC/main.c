/**
 * main.c
 */
#include "nvic.h"
#include "GPIO.h"
#include <stdint.h>

uint32_t state = 0x00;
void toggle(void){

}

void delay(uint32_t haba){
    volatile uint32_t j;
    volatile uint32_t i;
    for(i = 0 ; i< haba; i++){
        for(j = 0 ; j < 850; j++){

        }
    }
}
int main(void)
{
    GPIO_Init();
    NVIC_EnableIRQ(30);
    NVIC_SetPriority(30,0);
    GPIO_SetInterruptEvent(2,EVENT_LOW,MASK_ENABLED);
    while(1){
        delay(2);
        NVIC_SoftwareInterrupt(30);

    }
	return 0;
}
