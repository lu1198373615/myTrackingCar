/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����Ӧ��bsp��ɨ��ģʽ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:���� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_key.h"

//�����������Ľӿ���Ϣ��װ��������
u16 const     Pin_Front_List[13] 	= {Front1_GPIO_PIN	,Front2_GPIO_PIN	,Front3_GPIO_PIN	,Front4_GPIO_PIN	,Front5_GPIO_PIN	,Front6_GPIO_PIN	,Front7_GPIO_PIN	,Front8_GPIO_PIN  ,Back1_GPIO_PIN	 ,Back2_GPIO_PIN	,Back3_GPIO_PIN	 ,Back4_GPIO_PIN	,Back5_GPIO_PIN };	
GPIO_TypeDef* Port_Front_List[13] = {Front1_GPIO_PORT ,Front2_GPIO_PORT ,Front3_GPIO_PORT ,Front4_GPIO_PORT ,Front5_GPIO_PORT ,Front6_GPIO_PORT ,Front7_GPIO_PORT ,Front8_GPIO_PORT ,Back1_GPIO_PORT ,Back2_GPIO_PORT ,Back3_GPIO_PORT ,Back4_GPIO_PORT ,Back5_GPIO_PORT};	
u32 const     RCC_Front_List[13] 	= {Front1_GPIO_CLK	,Front2_GPIO_CLK	,Front3_GPIO_CLK	,Front4_GPIO_CLK	,Front5_GPIO_CLK	,Front6_GPIO_CLK	,Front7_GPIO_CLK	,Front8_GPIO_CLK  ,Back1_GPIO_CLK	 ,Back2_GPIO_CLK	,Back3_GPIO_CLK	 ,Back4_GPIO_CLK	,Back5_GPIO_CLK };	
/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void)
{
	u8 m;
	GPIO_InitTypeDef  GPIO_InitStructure;

	for(m=0;m<13;m++)
	{
		RCC_APB2PeriphClockCmd(RCC_Front_List[m], ENABLE);
		GPIO_InitStructure.GPIO_Pin 	= Pin_Front_List[m];
		GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
		GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_IN_FLOATING;	
		GPIO_Init(Port_Front_List[m], &GPIO_InitStructure);
	}
}
//void Key_GPIO_Config(void)
//{
//	GPIO_InitTypeDef GPIO_InitStructure;
//	
//	/*���������˿ڵ�ʱ��*/
//	RCC_APB2PeriphClockCmd(Front1_GPIO_CLK,ENABLE);	
//	//ѡ�񰴼�������
//	GPIO_InitStructure.GPIO_Pin = Front1_GPIO_PIN; 
//	// ���ð���������Ϊ��������
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
//	//ʹ�ýṹ���ʼ������
//	GPIO_Init(Front1_GPIO_PORT, &GPIO_InitStructure);
//	
//}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Black )  
	{	 
		/*�ȴ������ͷ� */
		//while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Black);   
		return 	Black;	 
	}
	else
		return White;
}

//���ص�value�����Ϊ��λ�ұ�Ϊ��λ��8λ����
uint8_t ReadFrontSig(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 8; i++)
	{
		value <<= 1;
		if( Key_Scan(Port_Front_List[i],Pin_Front_List[i]) == Black  ) value++;
	}
	return value;
}

uint8_t ReadBackSig(void)
{
	uint8_t i;
	uint8_t value;

	value = 0;
	for (i = 0; i < 5; i++)
	{
		value <<= 1;
		if( Key_Scan(Port_Front_List[i+8],Pin_Front_List[i+8]) == Black  ) value++;
	}
	return value;
}

int32_t FrontIndex(uint8_t value)
{

	if(value&129){
		return 0;
	};
	if(value&66){
		return 1;
	};
	if(value&36){
		return 2;
	};
	return 3;
}



/*********************************************END OF FILE**********************/
