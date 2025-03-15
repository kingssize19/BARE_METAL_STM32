#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>


#define		GPIOAEN			(1U << 0) 		/*!< Enable clock for GPIOA  					 	*/
#define 	USART2EN		(1U << 17)		/*!< Enable clock for USART2 					 	*/

#define		CR1_TE			(1U << 3)		/*!< Transmitter enable		 					 	*/
#define 	CR1_RE			(1U << 2)		/*!< Receiver enable								*/

#define 	CR1_UE			(1U << 13)		/*!< UART enable			 					 	*/
#define 	SR_TXE			(1U << 7)		/*!< TXE flag : Transmit data register empty	 	*/
#define 	SR_RXNE			(1U << 5)		/*!< RXNE flag : Read data register not empty       */

#define 	SYS_FREQ		16000000		/*!< System clock frequency (16 MHz)			 	*/
#define 	APB1_CLK		SYS_FREQ		/*!< APB1 peripheral clock (same as system clock)	*/

#define 	UART_BAUDRATE	115200			/*!< UART baud rate									*/


void usart2_tx_init(void);
int __io_putchar(int ch);
char usart2_read(void);
void usart2_rxtx_init(void);


#endif
