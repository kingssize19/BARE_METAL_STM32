#include "stm32f4xx.h"
#include <stdint.h>
#include "uart.h"


int main(void)
{

	usart2_tx_init();

	while (1) {

		printf("Hello, World!!!\n\r");
		for(uint32_t i = 0; i < 100000; ++i);
	}
}
