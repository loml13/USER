/**
* @par Copyright (C): 2018-2028, Shenzhen Yahboom Tech
* @file         // main.c
* @author       // lly
* @version      // V1.0
* @date         // 240628
* @brief        // 程序入口 Program entry
* @details      
* @par History  // 修改历史记录列表，每条修改记录应包括修改日期、修改者及
*               // 修改内容简述  Modification history list, each modification record should include the modification date, modifier and a brief description of the modification content
*/

#include "AllHeader.h"

u8 key_step = 0;
int16_t Encoder_Left = 0,Encoder_Right = 0; 

int main(void)
{	
	bsp_init();
	
	while(1)
	{
		Encoder_Left+=Read_Encoder(MOTOR_ID_ML);            					//读取左轮编码器的值，前进为正，后退为负 Read the value of the left wheel encoder, forward is positive, backward is negative
		Encoder_Right+=-Read_Encoder(MOTOR_ID_MR);           					//读取右轮编码器的值，前进为正，后退为负 Read the value of the right wheel encoder, forward is positive, backward is negative
		printf("L:%d\t R:%d\r\n",Encoder_Left,Encoder_Right);
		
		if(Key1_State(1))
		{
			printf("Key put down!\r\n"); //打印按键按下 Press the print button
			key_step++;
			if(key_step >=4)
			{
				key_step = 0;
			}
		}
		
		if(key_step == 0) //电机停止 Motor stops
		{
			Set_Pwm(0,0);
		}
		else if(key_step == 1) //电机前进 Motor forward
		{
			Set_Pwm(2400,2400);
		}
		else if(key_step == 2) //电机停止 Motor STOP
		{
			Set_Pwm(0,0);
		}
		else if(key_step == 3) //电机后退 Motor back
		{
			Set_Pwm(-2400,-2400);
		}
		
		delay_ms(200);
		

	}
}



