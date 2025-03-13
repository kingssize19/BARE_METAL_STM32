#include "uart.h"


static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate);
static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate);
static void usart2_write(int ch);

void usart2_rxtx_init(void)
{
	/****************Configure uart gpio pin****************/
	RCC->AHB1ENR |= GPIOAEN;

	/* Set PA2 mode to alternate function */
	GPIOA->MODER &= ~(1U << 4);
	GPIOA->MODER |= (1U << 5);

	/* Set PA2 alternate function type to UART_TX (AF07) */
	GPIOA->AFR[0] |= (1U << 8);
	GPIOA->AFR[0] |= (1U << 9);
	GPIOA->AFR[0] |= (1U << 10);
	GPIOA->AFR[0] &= ~(1U << 11);

	/* Set PA3 mode to alternate funciton */
	GPIOA->MODER &= ~(1U << 6);
	GPIOA->MODER |= (1U << 7);

	/* Set PA3 alternate function type to UART_RX (AF07) */
	GPIOA->AFR[0] |= (1U << 12);
	GPIOA->AFR[0] |= (1U << 13);
	GPIOA->AFR[0] |= (1U << 14);
	GPIOA->AFR[0] &= ~(1U << 15);




	/****************Configure uart module****************/

	/* Enable clock access to uart2	*/
	RCC->APB1ENR |= USART2EN;

	/* Configure baudrate */
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

	/* Configure the transfer direction */
	USART2->CR1 = (CR1_TE | CR1_RE);

	/* Enable UART module */
	USART2->CR1 |= CR1_UE;
}





void usart2_tx_init(void)
{
		/****************Configure uart gpio pin****************/

		/* Enable clock access to GPIOA */
		RCC->AHB1ENR |= GPIOAEN;

		/* Set PA2 mode to alternate function mode */
		GPIOA->MODER &= ~(1U << 4);
		GPIOA->MODER |= (1U << 5);

		/* Set PA2 alternate function type to UART_TX (AF07) */
		GPIOA->AFR[0] |= (1U << 8);
		GPIOA->AFR[0] |= (1U << 9);
		GPIOA->AFR[0] |= (1U << 10);
		GPIOA->AFR[0] &= ~(1U << 11);


		/****************Configure uart module****************/

		/* Enable clock access to USART2 */
		RCC->APB1ENR |= USART2EN;

		/* Configure baudrate */
		uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);

		/* Configure the transfer direction */
		USART2->CR1 = CR1_TE;	// clear other bits in the same time

		/* Enable UART module */
		USART2->CR1 |= CR1_UE;  // but this time set to 1 only uart enable bit
}

char usart2_read(void)
{
	/* Make sure the receive data register is not empty */
	while (!(USART2->SR & SR_RXNE));

	/* Read data */
	return USART2->DR;
}



int __io_putchar(int ch)
{
	usart2_write(ch);
	return ch;
}

static void usart2_write(int ch)
{
	/* Make sure the transmit data register is empty	*/
	while (!(USART2->SR & SR_TXE));

	/* Write to transmit data register					*/
	USART2->DR = (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BaudRate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, BaudRate);
}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t BaudRate)
{
	return ((PeriphClk + (BaudRate/2U)) / BaudRate);
}

