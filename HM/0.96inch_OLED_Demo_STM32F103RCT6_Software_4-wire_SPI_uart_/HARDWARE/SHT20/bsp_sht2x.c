#include "bsp_sht2x.h"
#include "stm32f10x.h"
#include "delay.h"
int RH,TT;

int READ_Temp()//温度读取
{
    u8 tmp1 = 0, tmp2 = 0;
    u16 res = 0;
    int  temp = 0.0;   
    
    IIC_Init();
    I2C_Start();
    I2C_Send_Byte(0x80);
    I2C_Stop();    
    delay_ms(20);
    
    I2C_Start();
    I2C_Send_Byte(0x80);
    if(I2C_Wait_Ack() == 0)  
    {
      I2C_Send_Byte(0xf3);   
      if(I2C_Wait_Ack() == 0)
      {
        delay_ms(90);
        I2C_Start();     
        I2C_Send_Byte(0x81);
        if(I2C_Wait_Ack() == 1)
        {
          return(0);
        }
        tmp1 = I2C_Read_Byte(0);
        tmp2 = I2C_Read_Byte(0);
        I2C_Read_Byte(1);
        I2C_Stop(); 
        
        res = (u16)(tmp1<<8)|tmp2;
        res &= ~0x03;
        
        temp = (int)((res*1.0*0.0026813-46.85)*10); 
        
        return temp;       
      } 
    }
    return 0; 
}

int READ_HUM()//温度读取
{
    u8 tmp1 = 0, tmp2 = 0;
    u16 res = 0;
    int  temp = 0.0;   
    
    IIC_Init();
    I2C_Start();
    I2C_Send_Byte(0x80);
    I2C_Stop();    
    delay_ms(20);
    
    I2C_Start();
    I2C_Send_Byte(0x80);
    if(I2C_Wait_Ack() == 0)  
    {
      I2C_Send_Byte(0xf5);   
      if(I2C_Wait_Ack() == 0)
      {
        delay_ms(45);
        I2C_Start();     
        I2C_Send_Byte(0x81);
        if(I2C_Wait_Ack() == 1)
        {
          return(0);
        }
        tmp1 = I2C_Read_Byte(0);
        tmp2 = I2C_Read_Byte(0);
        I2C_Read_Byte(1);
        I2C_Stop(); 
        
        res = (u16)(tmp1<<8)|tmp2;
        res &= ~0x03;
        
        temp = (int)((res*1.0*0.0019073-6)*10); 
        return temp;       
      } 
    }
    return 0; 
}


void SHT_CalcRHT()
{ 
        RH=READ_HUM();//hum	   参照SHT20方程
        TT=READ_Temp();//temp	  参照SHT20方程 
//        if(Temputer_Offest>=100)
//        {
//          TT = TT-(Temputer_Offest-100);
//        }
//        else
//        {
//          TT = TT+Temputer_Offest;        
//        }
//        if(Humidity_Offest>=100)
//        {
//          RH = RH-(Humidity_Offest-100);        
//        }
//        else
//        {
//          RH = RH+Humidity_Offest;
//        }
}

// TT = READ_Temp();
//        RH = READ_HUM();






