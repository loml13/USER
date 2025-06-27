/**
* @par Copyright (C): 2018-2028, Shenzhen Yahboom Tech
* @file         // main.c
* @author       // lly
* @version      // V1.0
* @date         // 240628
* @brief        // ������� Program entry
* @details      
* @par History  // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼�
*               // �޸����ݼ���  Modification history list, each modification record should include the modification date, modifier and a brief description of the modification content
*/

#include "AllHeader.h"

u8 key_step = 0;
int16_t Encoder_Left = 0,Encoder_Right = 0; 

int main(void)
{	
	bsp_init();
	
	while(1)
	{
		Encoder_Left+=Read_Encoder(MOTOR_ID_ML);            					//��ȡ���ֱ�������ֵ��ǰ��Ϊ��������Ϊ�� Read the value of the left wheel encoder, forward is positive, backward is negative
		Encoder_Right+=-Read_Encoder(MOTOR_ID_MR);           					//��ȡ���ֱ�������ֵ��ǰ��Ϊ��������Ϊ�� Read the value of the right wheel encoder, forward is positive, backward is negative
		printf("L:%d\t R:%d\r\n",Encoder_Left,Encoder_Right);
		
		if(Key1_State(1))
		{
			printf("Key put down!\r\n"); //��ӡ�������� Press the print button
			key_step++;
			if(key_step >=4)
			{
				key_step = 0;
			}
		}
		
		if(key_step == 0) //���ֹͣ Motor stops
		{
			Set_Pwm(0,0);
		}
		else if(key_step == 1) //���ǰ�� Motor forward
		{
			Set_Pwm(2400,2400);
		}
		else if(key_step == 2) //���ֹͣ Motor STOP
		{
			Set_Pwm(0,0);
		}
		else if(key_step == 3) //������� Motor back
		{
			Set_Pwm(-2400,-2400);
		}
		
		delay_ms(200);
		

	}
}



