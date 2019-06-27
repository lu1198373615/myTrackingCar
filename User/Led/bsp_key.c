/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   按键应用bsp（扫描模式）
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "bsp_key.h"

//各个传感器的接口信息封装在数组里
u16 const     Pin_Front_List[13] 	= {Front1_GPIO_PIN	,Front2_GPIO_PIN	,Front3_GPIO_PIN	,Front4_GPIO_PIN	,Front5_GPIO_PIN	,Front6_GPIO_PIN	,Front7_GPIO_PIN	,Front8_GPIO_PIN  ,Back1_GPIO_PIN	 ,Back2_GPIO_PIN	,Back3_GPIO_PIN	 ,Back4_GPIO_PIN	,Back5_GPIO_PIN };	
GPIO_TypeDef* Port_Front_List[13] = {Front1_GPIO_PORT ,Front2_GPIO_PORT ,Front3_GPIO_PORT ,Front4_GPIO_PORT ,Front5_GPIO_PORT ,Front6_GPIO_PORT ,Front7_GPIO_PORT ,Front8_GPIO_PORT ,Back1_GPIO_PORT ,Back2_GPIO_PORT ,Back3_GPIO_PORT ,Back4_GPIO_PORT ,Back5_GPIO_PORT};	
u32 const     RCC_Front_List[13] 	= {Front1_GPIO_CLK	,Front2_GPIO_CLK	,Front3_GPIO_CLK	,Front4_GPIO_CLK	,Front5_GPIO_CLK	,Front6_GPIO_CLK	,Front7_GPIO_CLK	,Front8_GPIO_CLK  ,Back1_GPIO_CLK	 ,Back2_GPIO_CLK	,Back3_GPIO_CLK	 ,Back4_GPIO_CLK	,Back5_GPIO_CLK };	
/**
  * @brief  配置按键用到的I/O口
  * @param  无
  * @retval 无
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
//	/*开启按键端口的时钟*/
//	RCC_APB2PeriphClockCmd(Front1_GPIO_CLK,ENABLE);	
//	//选择按键的引脚
//	GPIO_InitStructure.GPIO_Pin = Front1_GPIO_PIN; 
//	// 设置按键的引脚为浮空输入
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
//	//使用结构体初始化按键
//	GPIO_Init(Front1_GPIO_PORT, &GPIO_InitStructure);
//	
//}

 /*
 * 函数名：Key_Scan
 * 描述  ：检测是否有按键按下
 * 输入  ：GPIOx：x 可以是 A，B，C，D或者 E
 *		     GPIO_Pin：待读取的端口位 	
 * 输出  ：KEY_OFF(没按下按键)、KEY_ON（按下按键）
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*检测是否有按键按下 */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Black )  
	{	 
		/*等待按键释放 */
		//while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == Black);   
		return 	Black;	 
	}
	else
		return White;
}

//返回的value是左边为低位右边为高位的8位向量
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
