
#ifndef __TUBE_KEY_H
#define __TUBE_KEY_H

//#include "stm32f10x_conf.h"


//#define KEY_Lock_Press 1
//#define KEY_Stop_Press 2
//#define KEY_Up_Press 3
//#define KEY_Down_Press 4
//#define KEY_Mode_Press 5
//#define KEY_Run_Press 6



//void Tube_Key_Init(void);
//void Tube_DisNum(u16 Num);
//void Tube_CMD(u8 State, u8 Brightness);
//u8 KEY_Read(void);

void TM1650_Init(void);
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
void IIC_Ack(void);
void IIC_NoAck(void);
unsigned char IIC_Wait_Ack(void);
void IIC_Wr_Byte(unsigned char Data);
unsigned char IIC_Rd_Byte(void);
void TM1650_Wr_RAM(unsigned char Address, unsigned char Data);
//static u8 KEYtm_Scan(void);






//static void EXTI_KEY_Init(void);


#endif

