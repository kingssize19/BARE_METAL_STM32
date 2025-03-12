#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"
#include <stdint.h>

#define GPIOAEN				(1U << 0)
#define ADC1EN				(1U << 8)
#define ADC1_CH1			(1U << 0)
#define ADC_SEQ_LEN_1		(0x00)
#define CR2_ADON			(1U << 0)

#define CR2_SWSTART			(1U << 30)
#define SR_EOC				(1U << 1)

void adc_init(void);	// for PA1 (ADC1 Channel 1)
void start_conversion(void);
uint32_t adc_read(void);

#endif /* ADC_H_ */
