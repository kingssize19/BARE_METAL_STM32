#include "stm32f4xx.h"

#define GPIOAEN		(1U << 0)
#define GPIOCEN		(1U << 2)

#define PIN5		(1U << 5)
#define PIN13		(1U << 13)

#define LED_PIN		PIN5
#define BTN_PIN		PIN13

uint8_t button_count = 0;

int main(void)
{

	/* Enable clock access to GPIOA and GPIOC */
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	// GPIOA output (01) mode
	GPIOA->MODER |= (1 << 10);
	GPIOA->MODER &= ~(1 << 11);

	// GPIOC input (00) mode
	GPIOC->MODER &= ~(1 << 26);
	GPIOC->MODER &= ~(1 << 27);

	/*GPIOC pull down */
	GPIOC->PUPDR &= ~(1U << 26);
	GPIOC->PUPDR |= (1U << 27);

	/*Firstly led is OFF*/
	GPIOA->BSRR = (1U << 21);

	while (1) {

		if (!(GPIOC->IDR & BTN_PIN)) {

			/*Turn on led*/
			GPIOA->BSRR = LED_PIN;
			++button_count;

			while (!(GPIOC->IDR & BTN_PIN)); // Debouncing (Buton arkı için)

		}
		else {

			/*Turn off led*/
			GPIOA->BSRR = (1U << 21);



		}

	}
}
