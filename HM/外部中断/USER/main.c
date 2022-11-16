#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "exti.h" 


 int main(void)
 {	
  vu8 key=0;	
	delay_init();	    	 //延时函数初始化	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// 设置中断优先级分组2
//	uart_init(9600);	 //串口初始化为9600
	LED_Init();		  	 //初始化与LED连接的硬件接口 
	KEY_Init();
 	//EXTIX_Init();		//外部中断初始化
	
	while(1)
	{	    
	
		key=KEY_Scan(0);	//得到键值
	   	if(key)
		{						   
			switch(key)
			{				 
				
				case KEY1_PRES:	//控制LED1翻转	 
					LED0=1;
					LED1=1;
	        LED2=1;
					LED3=1;
					break;
				case KEY0_PRES:	//同时控制LED0,LED1翻转 
					LED0=0;
					LED1=0;
					LED2=0;
					LED3=0;
					break;
			}
		}else delay_ms(10); 
	} 
}


