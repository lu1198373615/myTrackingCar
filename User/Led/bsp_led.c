/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   led应用函数接口
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( IN1_GPIO_CLK | IN2_GPIO_CLK | IN3_GPIO_CLK | IN4_GPIO_CLK | EN1_GPIO_CLK | EN2_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = IN1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
		GPIO_Init(IN1_GPIO_PORT, &GPIO_InitStructure);//初始化IN1
		
		GPIO_InitStructure.GPIO_Pin = IN2_GPIO_PIN;   //初始化IN2
		GPIO_Init(IN2_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = IN3_GPIO_PIN;   //初始化IN3
		GPIO_Init(IN3_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = IN4_GPIO_PIN;   //初始化IN4
		GPIO_Init(IN4_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = EN1_GPIO_PIN;   //初始化EN1
		GPIO_Init(EN1_GPIO_PORT, &GPIO_InitStructure);
		
		GPIO_InitStructure.GPIO_Pin = EN2_GPIO_PIN;   //初始化EN2
		GPIO_Init(EN2_GPIO_PORT, &GPIO_InitStructure);
		

		/* 关闭所有led灯	*/
		//全部高电平
		GPIO_SetBits(IN1_GPIO_PORT, IN1_GPIO_PIN);
		GPIO_SetBits(IN2_GPIO_PORT, IN2_GPIO_PIN);	
		GPIO_SetBits(IN3_GPIO_PORT, IN3_GPIO_PIN);
		GPIO_SetBits(IN4_GPIO_PORT, IN4_GPIO_PIN);	
		GPIO_SetBits(EN1_GPIO_PORT, EN1_GPIO_PIN);
		GPIO_SetBits(EN2_GPIO_PORT, EN2_GPIO_PIN);			
    

}

/*********************************************END OF FILE**********************/
