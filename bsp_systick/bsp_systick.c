#include "bsp_systick.h"

static __IO  uint32_t TimingDelay;

void Systick_Init(void)
{
    /* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次
	 */
    if(SysTick_Config(SystemCoreClock/100000))
    while(1);
}

void Delay_us(__IO uint32_t us)
{
    TimingDelay = us;
    while(TimingDelay!=0);
}

void TimingDelay_Decrement(void)
{
    if(TimingDelay!=0x00)
    TimingDelay--;
}
