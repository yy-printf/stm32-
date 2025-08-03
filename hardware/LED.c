#include "stm32f10x.h"                  // Device header
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStrature;
	
	GPIO_InitStrature.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStrature.GPIO_Pin=GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5 |GPIO_Pin_7;
	GPIO_InitStrature.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrature);
}

void LED_Turn1_On(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}
void LED_Turn5_On(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
}
void LED_Turn3_On(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_3);
}
void LED_Turn7_On(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
}
void LED_Turn1_Off(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}
void LED_Turn5_Off(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}
void LED_Turn3_Off(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}
void LED_Turn7_Off(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}