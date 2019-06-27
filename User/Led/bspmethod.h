
#include "stm32f10x.h"
#include <stdio.h>

#include "bsp_key.h"
#include "bsp_led.h"  

#include "bsp_SysTick.h"
#include "bsp_GeneralTim.h"  
#include "bsp_AdvanceTim.h" 


//�����5��������ͨ����L298��������������λʵ��
void allStop(void);//���ֶ�ͣ
void allGoFront(void);//���ֶ���ǰ
void allGoBack(void);//���ֶ����
void goLeftFront(void);//����ǰ���ߣ���������������ǰ
void goRightFront(void);//����ǰ���ߣ�����ͣ��������ǰ
//�������������Ҳ��ͨ����L298��������������λʵ��
void volveLeft(int aaa);//����ֹͣ�����ֺ��ˣ��ﵽ������ת��Ч�������ڶԷ����������ʱ��ɲ��
void volveRight(int aaa);//����ֹͣ�����ֺ��ˣ��ﵽ������ת��Ч�������ڶԷ����������ʱ��ɲ��
//����������ӳٺ����������ڴ������źŸı�ʱ�ᱻ��ǰ��ֹ˯��
void FlexibleDelay(__IO uint32_t ms,uint8_t ppp);
//�����4��������ͨ����L298��PWM������λʵ�֣���Ҫ����volveLeft��volveRight��ɲ��
void dTurnLeft(void);//����ֹͣ���������٣��Ӷ�����ת
void dTurnRight(void);//����ֹͣ���������٣��Ӷ�����ת
void xTurnLeft(void);//���ּ��٣�����ȫ�٣��Ӷ�����ת
void xTurnRight(void);//���ּ��٣��������٣��Ӷ�����ת


