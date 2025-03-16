#include "adc.h"
#include "uart.h"
#include "systick.h"


#define GPIOAEN			(1U << 0)
#define PIN5			(1U << 5)

#define LED_PIN			PIN5


int main(void)
{

	/* 1. Enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* 2. Set PA5 as output pin */
	GPIOA->MODER |= (1U << 10);
	GPIOA->MODER &= ~(1U << 11);


	usart2_tx_init();


	while (1) {

		printf("A second passed !!\n\r");
		GPIOA->ODR ^= LED_PIN;
		SystickDelayMs(1000);
	}
}


