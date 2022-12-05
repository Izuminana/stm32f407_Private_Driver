//bsp :board support package 板级支持包

#include "bsp_led.h"

void LED_GPIO_Config(void)
{
	/*第一步：开启GPIO外设时钟*/
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOF,ENABLE);
	
	/*第二步：定义一个GPIO初始化结构体*/
	GPIO_InitTypeDef GPIO_InitStruct_RED;
	GPIO_InitTypeDef GPIO_InitStruct_BLUE;
	GPIO_InitTypeDef GPIO_InitStruct_GREEN;
	/*第三步：配置结构体初始化成员*/
	GPIO_InitStruct_RED.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStruct_RED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct_RED.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct_RED.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct_RED.GPIO_Speed = GPIO_Low_Speed;
	
	GPIO_InitStruct_BLUE.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStruct_BLUE.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct_BLUE.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct_BLUE.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct_BLUE.GPIO_Speed = GPIO_Low_Speed;
	
	GPIO_InitStruct_GREEN.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct_GREEN.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct_GREEN.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStruct_GREEN.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct_GREEN.GPIO_Speed = GPIO_Low_Speed;
	
	/*第四步：调用GPIO初始化函数，把配置好的结构体成员的参数写入寄存器*/
	
	GPIO_Init(GPIOF, &GPIO_InitStruct_RED);
	GPIO_Init(GPIOF, &GPIO_InitStruct_BLUE);
	GPIO_Init(GPIOF, &GPIO_InitStruct_GREEN);
	
	
	GPIO_SetBits(GPIOF,GPIO_Pin_8);
	GPIO_SetBits(GPIOF,GPIO_Pin_7);
	GPIO_SetBits(GPIOF,GPIO_Pin_6);
}


