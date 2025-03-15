#include "adc.h"
#include "uart.h"

uint32_t sensor_value = 0;

int main(void)
{
	usart2_tx_init();

	adc_init();

	start_conversion();

	while (1) {

		sensor_value = adc_read();
		printf("Sensor Value : %lu\n\r", sensor_value);
		for(int i = 0; i < 300000; ++i);
	}
}


