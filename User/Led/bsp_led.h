#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
#define IN1_GPIO_PORT    	GPIOB	              /* GPIO�˿� */
#define IN1_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define IN1_GPIO_PIN			GPIO_Pin_12			        

#define IN2_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define IN2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define IN2_GPIO_PIN		  GPIO_Pin_13			        

#define IN3_GPIO_PORT    	GPIOB	              /* GPIO�˿� */
#define IN3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define IN3_GPIO_PIN			GPIO_Pin_14			        

#define IN4_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define IN4_GPIO_CLK 	    RCC_APB2Periph_GPIOB  	/* GPIO�˿�ʱ�� */
#define IN4_GPIO_PIN		  GPIO_Pin_15			  

#define EN1_GPIO_PORT    	GPIOA	              /* GPIO�˿� */
#define EN1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define EN1_GPIO_PIN			GPIO_Pin_6

#define EN2_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define EN2_GPIO_CLK 	    RCC_APB2Periph_GPIOA  	/* GPIO�˿�ʱ�� */
#define EN2_GPIO_PIN		  GPIO_Pin_7



/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define LOW  0
#define HIGH 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
//�����6���������ڶ�����L298��6�����Ž�����λ����
#define IN1(a)	if (a)	\
					GPIO_SetBits(IN1_GPIO_PORT,IN1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(IN1_GPIO_PORT,IN1_GPIO_PIN)

#define IN2(a)	if (a)	\
					GPIO_SetBits(IN2_GPIO_PORT,IN2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(IN2_GPIO_PORT,IN2_GPIO_PIN)
					
#define IN3(a)	if (a)	\
					GPIO_SetBits(IN3_GPIO_PORT,IN3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(IN3_GPIO_PORT,IN3_GPIO_PIN)

#define IN4(a)	if (a)	\
					GPIO_SetBits(IN4_GPIO_PORT,IN4_GPIO_PIN);\
					else		\
					GPIO_ResetBits(IN4_GPIO_PORT,IN4_GPIO_PIN)
					
#define EN1(a)	if (a)	\
					GPIO_SetBits(EN1_GPIO_PORT,EN1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(EN1_GPIO_PORT,EN1_GPIO_PIN)

#define EN2(a)	if (a)	\
					GPIO_SetBits(EN2_GPIO_PORT,EN2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(EN2_GPIO_PORT,EN2_GPIO_PIN)


					
void LED_GPIO_Config(void);//������L298��6��������Ϊ�������

#endif /* __LED_H */
