/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( IN1_GPIO_CLK | IN2_GPIO_CLK | IN3_GPIO_CLK | IN4_GPIO_CLK | EN1_GPIO_CLK | EN2_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = IN1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
		GPIO_Init(IN1_GPIO_PORT, &GPIO_InitStructure);//��ʼ��IN1
		
		GPIO_InitStructure.GPIO_Pin = IN2_GPIO_PIN;   //��ʼ��IN2
		GPIO_Init(IN2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = IN3_GPIO_PIN;   //��ʼ��IN3
		GPIO_Init(IN3_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = IN4_GPIO_PIN;   //��ʼ��IN4
		GPIO_Init(IN4_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = EN1_GPIO_PIN;   //��ʼ��EN1
		GPIO_Init(EN1_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = EN2_GPIO_PIN;   //��ʼ��EN2
		GPIO_Init(EN2_GPIO_PORT, &GPIO_InitStructure);
		

		/* �ر�����led��	*/
		//ȫ���ߵ�ƽ
		GPIO_SetBits(IN1_GPIO_PORT, IN1_GPIO_PIN);
		GPIO_SetBits(IN2_GPIO_PORT, IN2_GPIO_PIN);	
		GPIO_SetBits(IN3_GPIO_PORT, IN3_GPIO_PIN);
		GPIO_SetBits(IN4_GPIO_PORT, IN4_GPIO_PIN);	
		GPIO_SetBits(EN1_GPIO_PORT, EN1_GPIO_PIN);
		GPIO_SetBits(EN2_GPIO_PORT, EN2_GPIO_PIN);			
    

}

/*********************************************END OF FILE**********************/
