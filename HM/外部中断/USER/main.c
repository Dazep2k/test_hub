#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "exti.h" 


 int main(void)
 {	
  vu8 key=0;	
	delay_init();	    	 //��ʱ������ʼ��	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
//	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
	KEY_Init();
 	//EXTIX_Init();		//�ⲿ�жϳ�ʼ��
	
	while(1)
	{	    
	
		key=KEY_Scan(0);	//�õ���ֵ
	   	if(key)
		{						   
			switch(key)
			{				 
				
				case KEY1_PRES:	//����LED1��ת	 
					LED0=1;
					LED1=1;
	        LED2=1;
					LED3=1;
					break;
				case KEY0_PRES:	//ͬʱ����LED0,LED1��ת 
					LED0=0;
					LED1=0;
					LED2=0;
					LED3=0;
					break;
			}
		}else delay_ms(10); 
	} 
}


