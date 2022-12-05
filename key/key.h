#ifndef __KEY_H__
#define __KEY_H__

#include "stm32f4xx.h"

#define KEY1_GPIO_PORT GPIOA
#define KEY1_GPIO_PIN GPIO_Pin_0
#define KEY1_GPIO_CLK RCC_AHB1Periph_GPIOA
#define KEY2_GPIO_PORT GPIOC
#define KEY2_GPIO_PIN GPIO_Pin_13
#define KEY2_GPIO_CLK RCC_AHB1Periph_GPIOC

#define KEY1_EXTI_PinSource EXTI_PinSource0
#define KEY1_EXTI_PortSource EXTI_PortSourceGPIOA
#define KEY2_EXTI_PortSource EXTI_PortSourceGPIOC
#define KEY2_EXTI_PinSource EXTI_PinSource13

#define KEY_ON 1
#define KEY_OFF 0

void KEY_GPIO_Init(void);
uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin);



#endif /* __KEY_H_*/

