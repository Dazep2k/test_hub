#ifndef __BSP_SHT2X_H
#define __BSP_SHT2X_H

#include "myiic.h"
#include "sys.h"

extern int RH,TT;
extern int READ_Temp(void);//�¶ȶ�ȡ
extern int READ_HUM(void);//�¶ȶ�ȡ
extern void SHT_CalcRHT(void);
#endif
