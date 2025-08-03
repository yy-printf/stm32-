#include "stm32f10x.h"                  // Device header
void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	
	GPIO_InitTypeDef GPIO_InitStrature;
	
	GPIO_InitStrature.GPIO_Mode=GPIO_Mode_AF_PP;//要用复用推挽输出
	GPIO_InitStrature.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;//查看引脚表确定引脚
	GPIO_InitStrature.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStrature);
	
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructrue;
	TIM_TimeBaseInitStructrue.TIM_ClockDivision=TIM_CKD_DIV1;//给外部时钟分频
	TIM_TimeBaseInitStructrue.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructrue.TIM_Period=100-1;//ARR
	TIM_TimeBaseInitStructrue.TIM_Prescaler=7200-1;//PCR
	TIM_TimeBaseInitStructrue.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructrue);
	
	TIM_Cmd(TIM2,ENABLE);//不要忘记使能
	
	TIM_OCInitTypeDef TIM_OCInitStrutrue;
	TIM_OCStructInit(&TIM_OCInitStrutrue);
	TIM_OCInitStrutrue.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStrutrue.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStrutrue.TIM_Pulse=0;//CCR
	TIM_OC2Init(TIM2,&TIM_OCInitStrutrue);
	TIM_OC3Init(TIM2,&TIM_OCInitStrutrue);
	
}
void PWM_Left_Change(uint16_t num)
{
	TIM_SetCompare2(TIM2,num);
}
//GPIO_Pin_1作为左侧输出PWM波来源
void PWM_Right_Change(uint16_t num)
{
	TIM_SetCompare3(TIM2,num);
}
//GPIO_Pin_2作为右侧输出PWM波来源