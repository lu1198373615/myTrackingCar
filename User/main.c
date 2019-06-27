
#include "bspmethod.h"
#define RightInitial  250
#define  LeftInitial  250
#define  jingsu 0
#define  jiqiao 1
#define  mode jiqiao

uint8_t FrontSig ;
uint8_t FrontSig_zero ;
uint8_t BackSig ; 
uint8_t T_Flag;
uint8_t L_Flag;
int32_t Right=RightInitial;
int32_t Left =LeftInitial;
int32_t Delta=0;

void TSolve(void) {
		//进入这个函数肯定要冲过头一点点
	T_Flag = 0;
	GENERAL_TIM_Init();
	allGoBack();
	confZhankb( RightInitial , LeftInitial );
		//向后退直至刚过线
	while(((FrontSig_zero&224)!=224)&&((FrontSig_zero&7)!=7)) {;;;}
	allStop();
	goLeftFront();
	confZhankb( 360 , 5 );
	while((FrontSig&60)!=0) {;;}
	while((FrontSig&60)==0) {;;}
		//进入了岔路口
	allGoFront();
	confZhankb( 5 , 5 );
	TIM_DeInit(GENERAL_TIM);
		//继续向前冲吧，下面是收尾工作
	SysTick_Delay_Ms( 60 );
	allGoFront();
	LED_GPIO_Config();
	L_Flag = 0;
	T_Flag = 0;
	FrontSig=16;
}

void LSolve(void) {
		//进入这个函数肯定要冲过头一点点
	L_Flag = 0;
	GENERAL_TIM_Init();
	allGoBack();
	confZhankb( RightInitial , LeftInitial );
		//向后退直至刚过线
	while(((FrontSig_zero&224)!=224)&&((FrontSig_zero&7)!=7)) {;;;}
	allStop();
	goRightFront();
	confZhankb(  5, 360 );
	while((FrontSig&60)!=0) {;;}
	while((FrontSig&60)==0) {;;}
		//说明进入了岔路口
	allGoFront();
	confZhankb( 5 , 5 );
	TIM_DeInit(GENERAL_TIM);
		//继续向前冲吧，下面是收尾工作
	SysTick_Delay_Ms( 60 );
	allGoFront();
	LED_GPIO_Config();
	L_Flag = 0;
	T_Flag = 0;
	FrontSig=16;
}


int main(void)
{
	int cnt = 0;
	uint8_t ppp = 0;
	/* key&&led 端口配置 */ 
	LED_GPIO_Config();
	Key_GPIO_Config();
	
	/* 定时器初始化 */
	ADVANCE_TIM_Init();
	
	FrontSig=0;
	BackSig =0;
	T_Flag  =0;
	L_Flag = 0;
	
	//起始开关
	allStop();
	while(FrontSig!=24){;}
	allGoFront();
	T_Flag  =0;
	L_Flag = 0;
	
	if(mode) {
		while(1){
			if((T_Flag==1)||(L_Flag==1)) {
				if(cnt<2) {
					allGoBack();SysTick_Delay_Ms( 50 );FrontSig=24;TSolve();T_Flag = 0;L_Flag = 0;
				}
				if(cnt>1) {
					allGoBack();SysTick_Delay_Ms( 50 );FrontSig=24;LSolve();T_Flag = 0;L_Flag = 0;
				}
				cnt++;
				cnt = cnt%6;
			}
		
			ppp=FrontSig;
			if((ppp&24)!=24){
				if(ppp<24){
					xTurnRight();
				}
				if(ppp>24){
					xTurnLeft();
				}
			}else{
			;;;
			}
		}
	}
	else {
		ppp=FrontSig;
		if((ppp&24)!=24){
			if(ppp<24){
				xTurnRight();
			}
			if(ppp>24){
				xTurnLeft();
			}
		}else{
		;;;
		}
	}
}
/*********************************************END OF FILE**********************/
