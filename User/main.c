#include "stm32f10x.h"                  // Device header
#include "LED.h"
#include "Delay.h"
#include "PWM.h"
#include "Motor.h"
#include "Car.h"
#include "track.h"
int	main(void)
{
	PWM_Init();
	Motor_Init();
	Car_Init();
	track_Init();
	while(1)
	{
		track_return();
	}
}
