#ifndef __EXTI_H__
#define __EXTI_H__
#include "stm32f4xx.h"

#define KEY1_IRQHandler EXTI0_IRQHandler
#define KEY2_IRQHandler EXTI15_10_IRQnHandler



void NVIC_Configuration(void);
void EXTI_BEEP_Config(void) ;


#endif /*__EXTI_H__*/

