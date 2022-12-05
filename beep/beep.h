#ifndef __BEEP_H
#define __BEEP_H

#include "stm32f4xx.h"

#define BEEP_GPIO_PORT GPIOG
#define BEEP_GPIO_PIN GPIO_Pin_7
#define BEEP_GPIO_CLK RCC_AHB1Periph_GPIOG

#define ON 1
#define OFF 0

#define	digitalHi(p,i)			{p->BSRRL=i;}			  //设置为高电平		
#define digitalLo(p,i)			{p->BSRRH=i;}				//输出低电平
#define digitalToggle(p,i)	{p->ODR ^=i;}			//输出反转状态

#define BEEP_ON digitalHi(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_OFF digitalLo(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define BEEP_Toggle digitalToggle(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_GPIO_Init(void);

#endif /* __BEEP_H */

