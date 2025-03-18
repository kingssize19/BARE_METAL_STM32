#include "tim.h"
#include "uart.h"

uint32_t timestamp = 0;

/* Set up : Connect a jumper wire from PA5 to PA6 */

int main(void)
{
	usart2_tx_init();

	tim2_pa5_output_compare();
	tim3_pa6_input_capture();

	while (1) {

		/* Wait until edge is captured */
		while (!(TIM3->SR & SR_CC1IF));

		/* Read captured Value */
		timestamp = TIM3->CCR1;
		printf("timestamp : %lu\r\n", timestamp);

	}
}


