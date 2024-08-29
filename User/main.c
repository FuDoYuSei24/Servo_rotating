#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "Servo.h"

#define MAX 120
#define MIN 30
uint8_t KeyNum;
float Angle;

int main()
{
	Servo_Init();
	OLED_Init();
	uint8_t Flag=0;

	OLED_ShowString(1,1,"ANGLE:");
	while(1)
	{

		if(Flag==0)
		{
			Angle+=5;
			Delay_ms(20);
			if(Angle>=MAX)
			{
				Flag=1;
			}
		}
		if(Flag==1)
		{
			Angle-=5;
			Delay_ms(20);
			if(Angle<=MIN)
			{
				Flag=0;
			}
		}
		Servo_SetAngle(Angle);
		OLED_ShowNum(1,7,Angle,3);
	}
}
