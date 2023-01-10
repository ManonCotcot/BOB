#include <stdint.h>
#include "gpio.h"

static volatile uint16_t pos = 0;
int i = 0;
void motor_set (uint16_t degrees){
	pos = (degrees * 400) / 360;
}

void motor_irq_cb(void){
	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)== 0){
			if(i <= pos){
				if (i % 2 ==0){
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,GPIO_PIN_SET);
				i++;
			}
			else{
				HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,GPIO_PIN_RESET);
				i++;
				}
			}
	}
}
