
#include "stm32f10x.h"
#include <stdio.h>

#include "bsp_key.h"
#include "bsp_led.h"  

#include "bsp_SysTick.h"
#include "bsp_GeneralTim.h"  
#include "bsp_AdvanceTim.h" 


//下面的5个函数是通过对L298方向输入引脚置位实现
void allStop(void);//俩轮都停
void allGoFront(void);//俩轮都向前
void allGoBack(void);//俩轮都向后
void goLeftFront(void);//向左前方走，左轮听，右轮向前
void goRightFront(void);//向右前方走，右轮停，左轮向前
//下面的两个函数也是通过对L298方向输入引脚置位实现
void volveLeft(int aaa);//右轮停止，左轮后退，达到向左旋转的效果，用于对方向矫正过度时的刹车
void volveRight(int aaa);//左轮停止，右轮后退，达到向右旋转的效果，用于对方向矫正过度时的刹车
//下面这个是延迟函数，但是在传感器信号改变时会被提前终止睡眠
void FlexibleDelay(__IO uint32_t ms,uint8_t ppp);
//下面的4个函数是通过对L298的PWM引脚置位实现，需要调用volveLeft和volveRight来刹车
void dTurnLeft(void);//左轮停止，右轮慢速，从而向左转
void dTurnRight(void);//右轮停止，左轮慢速，从而向右转
void xTurnLeft(void);//左轮减速，右轮全速，从而向左转
void xTurnRight(void);//右轮减速，左轮慢速，从而向右转


