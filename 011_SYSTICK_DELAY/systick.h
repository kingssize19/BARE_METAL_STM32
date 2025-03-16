#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

#define SYSTICK_LOAD_VAL			16000
#define CTRL_ENABLE					(1U << 0)
#define CTRL_CLKSRC					(1U << 2)
#define CTRL_COUNTFLAG				(1U << 16)

void SystickDelayMs(int n);

#endif /* SYSTICK_H_ */
