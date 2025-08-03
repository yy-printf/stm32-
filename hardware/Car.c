#include "stm32f10x.h"                  // Device header
#include "Motor.h"
void Car_Init(void)
{
	Motor_Init();
}
void Car_Stop(void)
{
	Motor_Set_LeftSpeed(0);
	Motor_Set_RightSpeed(0);
}
void Car_Left_turn(void)
{
	Motor_Set_RightSpeed(0);
	Motor_Set_LeftSpeed(100);
}
void Car_Right_turn(void)
{
	Motor_Set_RightSpeed(100);
	Motor_Set_LeftSpeed(0);
}
void Car_Forward(void)
{
	Motor_Set_RightSpeed(100);
	Motor_Set_LeftSpeed(100); 
}
