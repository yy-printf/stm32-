#include "stm32f10x.h"                  // Device header
#include "Car.h"
void track_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11|GPIO_Pin_12;//两个红外传感器，一左一右
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
}
//有光返回为低电平
//无光高电平
//右边轮子反馈
uint8_t right_track_return(void)
{
		return !GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11);
}
//左轮反馈
uint8_t left_track_return(void)
{
		return !GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12);
}
/*
都认为1有光走在正确的路上
0为无光需要调整
*/
//逻辑判断函数
//返回值认为左转为0，右转为1
void track_return(void)
{
	uint8_t right_track_return_num;
	uint8_t left_track_return_num;
	right_track_return_num=right_track_return();
	left_track_return_num=left_track_return();
	// 两个传感器的四种状态处理
if(right_track_return_num==1 && left_track_return_num==1) {
    // 两个传感器都在线上，直行
    Car_Forward();
} else if(right_track_return_num==0 && left_track_return_num==1) {
    // 右传感器偏离线，左转
    Car_Left_turn();
} else if(right_track_return_num==1 && left_track_return_num==0) {
    // 左传感器偏离线，右转
    Car_Right_turn();
} else {
    // 两个传感器都偏离线，可以停止或继续前进
    Car_Forward(); // 或 Car_Stop()
}
}
