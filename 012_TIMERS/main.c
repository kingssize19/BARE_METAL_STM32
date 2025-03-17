#include "tim.h"

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

	tim2_1hz_init();


	while (1) {

		/* Wait for UIF */
		while (!(TIM2->SR & SR_UIF));

		/* Clear UIF */
		TIM2->SR &= ~SR_UIF;

		GPIOA->ODR ^= LED_PIN;

	}
}


