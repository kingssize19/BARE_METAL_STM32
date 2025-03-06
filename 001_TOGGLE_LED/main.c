
#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET			(0x0000UL)
#define GPIOA_BASE				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1ENR_OFFSET			(0x30UL)
#define RCC_AHB1ENR				(*(volatile unsigned int *)(RCC_BASE + AHB1ENR_OFFSET))


#define MODER_OFFSET			(0x00UL)
#define GPIOA_MODER				(*(volatile unsigned int *)(GPIOA_BASE + MODER_OFFSET))

#define ODR_OFFSET				(0x14UL)
#define GPIOA_ODR				(*(volatile unsigned int *)(GPIOA_BASE + ODR_OFFSET))


#define GPIOAEN					(1U << 0) // 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN5					(1U << 5)
#define LED_PIN					(PIN5)

/*	GPIO OUTPUT MODE
 *  |= (1U << 10)   // Set bit 10 to 1
 *  &= ~(1U << 11)  // Set bit 11 to 0  */


void Delay(void);

int main(void)
{
	/*	1. Enable clock access to GPIOA */
	RCC_AHB1ENR |= GPIOAEN;
	/*  2. Set PA5 as output pin		*/
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);

	while (1) {

		/*	3. Set PA5 high		*/
		//GPIOA_ODR |= LED_PIN;

		//Delay();

		/*	4. Reset PA5 low	*/
		//GPIOA_ODR &= ~LED_PIN;

		//Delay();

		/*	5. Toggle PA5 high-low */
		GPIOA_ODR ^= LED_PIN;

		Delay();
	}
}

void Delay(void)
{
	for (int i = 1; i < 500000; ++i)
				; // null statement for delay

}






