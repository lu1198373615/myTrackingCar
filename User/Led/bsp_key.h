#ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"

//  引脚定义
#define    Front1_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front1_GPIO_PORT    GPIOA			   
#define    Front1_GPIO_PIN		 GPIO_Pin_9
#define    Front2_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front2_GPIO_PORT    GPIOA			   
#define    Front2_GPIO_PIN		 GPIO_Pin_11
#define    Front3_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front3_GPIO_PORT    GPIOA			   
#define    Front3_GPIO_PIN		 GPIO_Pin_5
#define    Front4_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front4_GPIO_PORT    GPIOA			   
#define    Front4_GPIO_PIN		 GPIO_Pin_4
#define    Front5_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front5_GPIO_PORT    GPIOA			   
#define    Front5_GPIO_PIN		 GPIO_Pin_3
#define    Front6_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front6_GPIO_PORT    GPIOA			   
#define    Front6_GPIO_PIN		 GPIO_Pin_2
#define    Front7_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front7_GPIO_PORT    GPIOA			   
#define    Front7_GPIO_PIN		 GPIO_Pin_1
#define    Front8_GPIO_CLK     RCC_APB2Periph_GPIOA
#define    Front8_GPIO_PORT    GPIOA			   
#define    Front8_GPIO_PIN		 GPIO_Pin_0


#define    Back1_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    Back1_GPIO_PORT    GPIOB			   
#define    Back1_GPIO_PIN		 GPIO_Pin_5
#define    Back2_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    Back2_GPIO_PORT    GPIOB			   
#define    Back2_GPIO_PIN		 GPIO_Pin_6
#define    Back3_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    Back3_GPIO_PORT    GPIOB			   
#define    Back3_GPIO_PIN		 GPIO_Pin_7
#define    Back4_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    Back4_GPIO_PORT    GPIOB		   
#define    Back4_GPIO_PIN		 GPIO_Pin_8
#define    Back5_GPIO_CLK     RCC_APB2Periph_GPIOB
#define    Back5_GPIO_PORT    GPIOB		   
#define    Back5_GPIO_PIN		 GPIO_Pin_9


 /** 按键按下标置宏
	*  按键按下为高电平，设置 KEY_ON=1， KEY_OFF=0
	*  若按键按下为低电平，把宏设置成KEY_ON=0 ，KEY_OFF=1 即可
	*/
#define Black	1
#define White	0

void Key_GPIO_Config(void);//将所有宏定义了的传感器输入引脚设为浮空输入模式
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);//检查特定传感器输入引脚的电平高低，返回0或1
uint8_t ReadFrontSig(void);//通过调用Key_Scan函数来检查前置传感器的8个引脚，并移位计算得到无符号8位整型数据
int32_t FrontIndex(uint8_t value);//通过查看8位整型字符变量FrontSig哪一位为1来确定小车位置
uint8_t ReadBackSig(void);//和ReadFrontSig类似，但是这个函数后来并没有用到

#endif /* __KEY_H */

