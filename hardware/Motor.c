#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//这里四根线控制小车轮前后移动
	//4，5==AIN1,AIN2,6,7==BIN1,BIN2
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	PWM_Init();//1，3PWM线
}
void Motor_Set_RightSpeed(uint32_t Speed)//右侧轮我们接4，5
{
	if(Speed==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5);//同时高电平不让轮胎转
	}
	else if(Speed>0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		//AIN1高电平，AIN2低电平，认为向前
		PWM_Right_Change(Speed);
	}
	else{
		GPIO_SetBits(GPIOA,GPIO_Pin_5);
		GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		//AIN1低电平，AIN2高电平，认为向后
		PWM_Right_Change(-Speed);
	}
}
void Motor_Set_LeftSpeed(uint32_t Speed)//右侧轮我们接4，5
{
	if(Speed==0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6|GPIO_Pin_7);//同时高电平不让轮胎转
	}
	else if(Speed>0)
	{
		GPIO_SetBits(GPIOA,GPIO_Pin_6);
		GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		//BIN1高电平，BIN2低电平，认为向前
		PWM_Left_Change(Speed);
	}
	else{
		GPIO_SetBits(GPIOA,GPIO_Pin_7);
		GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		//BIN1低电平，BIN2高电平，认为向后
		PWM_Left_Change(-Speed);
	}
}
