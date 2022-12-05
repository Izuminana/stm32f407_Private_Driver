#include "key.h"

void KEY_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(KEY1_GPIO_CLK,ENABLE);
    RCC_AHB1PeriphClockCmd(KEY2_GPIO_CLK,ENABLE);

    GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

    GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN;

    GPIO_Init(KEY2_GPIO_PORT,&GPIO_InitStructure);

}

uint8_t Key_Scan(GPIO_TypeDef * GPIOx,uint16_t GPIO_Pin)
{
    if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
        while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
            return KEY_ON;
    else
        return KEY_OFF;

}
