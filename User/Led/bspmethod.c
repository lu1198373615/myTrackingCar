
#include "bspmethod.h"

extern uint8_t FrontSig ; // ms º∆ ±±‰¡ø 	


void allStop(){
	IN1(HIGH);
	IN2(HIGH);
	IN3(HIGH);
	IN4(HIGH);
}

void allGoFront(){
	IN1(LOW);
	IN2(HIGH);
	IN3(LOW);
	IN4(HIGH);
}

void goLeftFront(){
	IN1(LOW);
	IN2(HIGH);
	IN3(LOW);
	IN4(LOW);
}

void goRightFront(){
	IN1(LOW);
	IN2(LOW);
	IN3(LOW);
	IN4(HIGH);
}

void allGoBack(){
	IN1(HIGH);
	IN2(LOW);
	IN3(HIGH);
	IN4(LOW);
}

void volveLeft(int aaa){
	IN1(HIGH);
	IN2(HIGH);
	IN3(HIGH);
	IN4(LOW);
	
	EN1(HIGH);
	EN2(HIGH);
	SysTick_Delay_Ms(aaa);
	allGoFront();
}

void volveRight(int aaa){
	IN1(HIGH);
	IN2(LOW);
	IN3(HIGH);
	IN4(HIGH);
	
	EN1(HIGH);
	EN2(HIGH);
	SysTick_Delay_Ms(aaa);
	allGoFront();
}

void FlexibleDelay(__IO uint32_t ms,uint8_t ppp){
	uint32_t i;
	uint8_t pppBuf=ppp;
	SysTick_Config(SystemCoreClock/1000);
	
	for(i=0;i<ms;i++)
	{
		while( !((SysTick->CTRL)&(1<<16)) )
		{
			if(FrontSig!=pppBuf) break;
		};
		if(FrontSig!=pppBuf) break;
	}
	SysTick->CTRL &=~ SysTick_CTRL_ENABLE_Msk;
}

void xTurnLeft(){
	//printf("\n◊Û¬÷ºıÀŸ¿≤");
	int shData=0;
	int sheet[4]={70,69,60,30};
	uint8_t ppp;

	while((FrontSig&24)!=24){
		ppp=FrontSig;
		if(ppp&15) break;
		if((ppp&128)) {dTurnLeft();break;}
		EN2(LOW);
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(shData,ppp);
		EN2(HIGH);
		ppp=FrontSig;
		if(ppp&15) break;
		if((ppp&128)) {dTurnLeft();break;}
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(100-shData,ppp);
	}
	EN2(HIGH);volveRight(sheet[FrontIndex(FrontSig)]+5);
}

void xTurnRight(){
	//printf("\n”“¬÷ºıÀŸ¿≤");
	int shData=0;
	int sheet[4]={70,59,52,30};
	uint8_t ppp;

	while((FrontSig&24)!=24){
		ppp=FrontSig;
		if(ppp&240) break;
		if((ppp&1)) {dTurnRight();break;}
		EN1(LOW);
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(shData,ppp);
		EN1(HIGH);
		ppp=FrontSig;
		if(ppp&240) break;
		if((ppp&1)) {dTurnRight();break;}
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(100-shData,ppp);
	}
	EN1(HIGH);volveLeft(sheet[FrontIndex(FrontSig)]+5);
}


void dTurnLeft(){
	//printf("\n◊Û¬÷ºıÀŸ¿≤");
	int sheet[4]={63,60,70,80};
	int shData=0;
	uint8_t ppp;
	EN2(LOW);
	while(FrontSig&129){
		ppp=FrontSig;
		if(ppp&31) break;
		EN1(LOW);
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(shData,ppp);
		EN1(HIGH);
		ppp=FrontSig;
		if(ppp&31) break;
		FlexibleDelay(100-shData,ppp);
	}
	EN1(HIGH);EN2(HIGH);volveLeft(40);
}

void dTurnRight(){
	//printf("\n”“¬÷ºıÀŸ¿≤");
	int sheet[4]={63,60,70,80};
	int shData=0;
	uint8_t ppp;
	EN1(LOW);
	while(FrontSig&1){
		ppp=FrontSig;
		if(ppp&248) break;
		EN2(LOW);
		shData=sheet[FrontIndex(ppp)];
		FlexibleDelay(shData,ppp);
		ppp=FrontSig;
		EN2(HIGH);
		if(ppp&248) break;
		FlexibleDelay(100-shData,ppp);
	}
	EN1(HIGH);EN2(HIGH);volveLeft(40);
}





