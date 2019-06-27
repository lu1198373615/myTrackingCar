#ifndef __KEY_H
#define	__KEY_H

#include "stm32f10x.h"

//  ���Ŷ���
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


 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define Black	1
#define White	0

void Key_GPIO_Config(void);//�����к궨���˵Ĵ���������������Ϊ��������ģʽ
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin);//����ض��������������ŵĵ�ƽ�ߵͣ�����0��1
uint8_t ReadFrontSig(void);//ͨ������Key_Scan���������ǰ�ô�������8�����ţ�����λ����õ��޷���8λ��������
int32_t FrontIndex(uint8_t value);//ͨ���鿴8λ�����ַ�����FrontSig��һλΪ1��ȷ��С��λ��
uint8_t ReadBackSig(void);//��ReadFrontSig���ƣ������������������û���õ�

#endif /* __KEY_H */

