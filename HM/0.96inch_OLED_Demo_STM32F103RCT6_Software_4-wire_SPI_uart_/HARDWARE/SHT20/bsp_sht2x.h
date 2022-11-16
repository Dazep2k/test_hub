#ifndef __BSP_SHT2X_H
#define __BSP_SHT2X_H

#include "myiic.h"
#include "sys.h"

extern int RH,TT;
extern int READ_Temp(void);//温度读取
extern int READ_HUM(void);//温度读取
extern void SHT_CalcRHT(void);
#endif
