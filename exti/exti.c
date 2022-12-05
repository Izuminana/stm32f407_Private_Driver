#include "exti.h"
#include "key.h"

 void NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;

    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;

    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;

    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

    NVIC_Init(&NVIC_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;

    NVIC_Init(&NVIC_InitStructure);

}

void EXTI_BEEP_Config(void) 
{
    EXTI_InitTypeDef EXTI_InitStructure;

    KEY_GPIO_Init();

    NVIC_Configuration();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);

    

    SYSCFG_EXTILineConfig(KEY1_EXTI_PortSource,KEY1_EXTI_PinSource);

    EXTI_InitStructure.EXTI_Line = EXTI_Line0 ;

    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;

    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    EXTI_Init(&EXTI_InitStructure);

    SYSCFG_EXTILineConfig(KEY2_EXTI_PortSource,KEY2_EXTI_PinSource);

    EXTI_InitStructure.EXTI_Line = EXTI_Line13 ;

    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;

    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;

    EXTI_InitStructure.EXTI_LineCmd = ENABLE;

    EXTI_Init(&EXTI_InitStructure);

}

