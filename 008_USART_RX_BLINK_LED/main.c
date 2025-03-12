#include "stm32f4xx.h"
#include <stdint.h>
#include "uart.h"

#define GPIOAEN		(1U << 0)
#define GPIOA_5		(1U << 5)

#define LED_PIN		GPIOA_5


char key;

int main(void)
{

	RCC->AHB1ENR |= GPIOAEN;

	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);


	usart2_rxtx_init();

	while (1) {

		key = usart2_read();

		if (key == '1') {
			GPIOA->ODR |= LED_PIN;
		}
		else {
			GPIOA->ODR &= ~LED_PIN;
		}
	}
}


