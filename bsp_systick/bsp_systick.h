#ifndef __BSP_SYSTICK_H__
#define __BSP_SYSTICK_H__

#define Delay_ms(x) Delay_us(100*x) 

#include "stm32f4xx.h"
void Systick_Init(void);
void Delay_us(__IO uint32_t us);
void TimingDelay_Decrement(void);


#endif /*__BSP_SYSTICK_H__*/

