/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_userdefine.h
* Version      : CodeGenerator for RL78/G13 V2.05.04.02 [20 Nov 2019]
* Device(s)    : R5F100LE
* Tool-Chain   : CA78K0R
* Description  : This file includes user definition.
* Creation Date: 2020/7/16
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
typedef  void (*fp)(); 
typedef bit Bit;
typedef bit Bool;
typedef unsigned char Byte;
typedef unsigned int Word;
typedef unsigned long Long;
typedef unsigned char uchar;
typedef unsigned int uint;

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

#define HIBYTE_REF(addr)			(* ((Byte *) & (addr)) )
#define LOBYTE_REF(addr)			(* ((Byte *) & (addr) +(1)) )
#define MAKEWORD(v1,v2)				( ( ( (Word) (v1))<<(8) )+(Word) (v2))
#define HIBYTE(v1)					( (Byte) ( (v1) >> (8)) )
#define LOBYTE(v1)					( (Byte) ( (v1) & (0xff)) )

#define MICROSECOND_100_CARRY {US_count=0;Hundred_US_count++;}
#define MILLISECOND_1_CARRY {Hundred_US_count=0;MS_count++;}
#define MILLISECOND_100_CARRY {MS_count=0;Hundred_MS_count++;}
#define SECOND_1_CARRY {Hundred_MS_count=0;Sec_count++;}
#define MINUTER_1_CARRY {Sec_count=0;Min_count++;}
#define HOUR_1_CARRY {Min_count=0;Hour_count++;}
#define DAY_1_CARRY {Hour_count=0;Day_count++;}

#define EACH_1_US (GetUsFlag())
#define EACH_2_US (US_count%2==0)
#define EACH_3_US (US_count%3==0)
#define EACH_4_US (US_count%4==0)
#define EACH_5_US (US_count%5==0)
#define EACH_6_US (US_count%6==0)
#define EACH_7_US (US_count%7==0)
#define EACH_8_US (US_count%8==0)
#define EACH_9_US (US_count%9==0)
#define EACH_10_US (US_count%10==0)
#define EACH_11_US (US_count%11==0)
#define EACH_12_US (US_count%12==0)
#define EACH_13_US (US_count%13==0)
#define EACH_14_US (US_count%14==0)
#define EACH_15_US (US_count%15==0)
#define EACH_16_US (US_count%16==0)
#define EACH_17_US (US_count%17==0)
#define EACH_18_US (US_count%18==0)
#define EACH_19_US (US_count%19==0)
#define EACH_20_US (US_count%20==0)
#define EACH_25_US (US_count%25==0)
#define EACH_30_US (US_count%30==0)
#define EACH_40_US (US_count%40==0)
#define EACH_50_US (US_count%50==0)
#define EACH_60_US (US_count%60==0)
#define EACH_70_US (US_count%70==0)
#define EACH_80_US (US_count%80==0)
#define EACH_90_US (US_count%90==0)
#define EACH_100_US (US_count%100==0)
#define EACH_200_US (Hundred_US_count%2==0)
#define EACH_300_US (Hundred_US_count%3==0)
#define EACH_400_US (Hundred_US_count%4==0)
#define EACH_500_US (Hundred_US_count%5==0)
#define EACH_600_US (Hundred_US_count%6==0)
#define EACH_700_US (Hundred_US_count%7==0)
#define EACH_800_US (Hundred_US_count%8==0)
#define EACH_900_US (Hundred_US_count%9==0)




#define EACH_1_MS (GetMsFlag())
#define EACH_2_MS (MS_count%2==0)
#define EACH_3_MS (MS_count%3==0)
#define EACH_4_MS (MS_count%4==0)
#define EACH_5_MS (MS_count%5==0)
#define EACH_6_MS (MS_count%6==0)
#define EACH_7_MS (MS_count%7==0)
#define EACH_8_MS (MS_count%8==0)
#define EACH_9_MS (MS_count%9==0)
#define EACH_10_MS (MS_count%10==0)
#define EACH_11_MS (MS_count%11==0)
#define EACH_12_MS (MS_count%12==0)
#define EACH_13_MS (MS_count%13==0)
#define EACH_14_MS (MS_count%14==0)
#define EACH_15_MS (MS_count%15==0)
#define EACH_16_MS (MS_count%16==0)
#define EACH_17_MS (MS_count%17==0)
#define EACH_18_MS (MS_count%18==0)
#define EACH_19_MS (MS_count%19==0)
#define EACH_20_MS (MS_count%20==0)
#define EACH_25_MS (MS_count%25==0)
#define EACH_30_MS (MS_count%30==0)
#define EACH_40_MS (MS_count%40==0)
#define EACH_50_MS (MS_count%50==0)
#define EACH_60_MS (MS_count%60==0)
#define EACH_70_MS (MS_count%70==0)
#define EACH_80_MS (MS_count%80==0)
#define EACH_90_MS (MS_count%90==0)
#define EACH_100_MS (MS_count%100==0)
#define EACH_200_MS (Hundred_MS_count%2==0)
#define EACH_300_MS (Hundred_MS_count%3==0)
#define EACH_400_MS (Hundred_MS_count%4==0)
#define EACH_500_MS (Hundred_MS_count%5==0)
#define EACH_600_MS (Hundred_MS_count%6==0)
#define EACH_700_MS (Hundred_MS_count%7==0)
#define EACH_800_MS (Hundred_MS_count%8==0)
#define EACH_900_MS (Hundred_MS_count%9==0)
#define EACH_1_S (Hundred_MS_count%10==0)
#define EACH_2_S (Sec_count%2==0)
#define EACH_3_S (Sec_count%3==0)
#define EACH_4_S (Sec_count%4==0)
#define EACH_5_S (Sec_count%5==0)
#define EACH_6_S (Sec_count%6==0)
#define EACH_7_S (Sec_count%7==0)
#define EACH_8_S (Sec_count%8==0)
#define EACH_9_S (Sec_count%9==0)
#define EACH_10_S (Sec_count%10==0)
#define EACH_11_S (Sec_count%11==0)
#define EACH_12_S (Sec_count%12==0)
#define EACH_13_S (Sec_count%13==0)
#define EACH_14_S (Sec_count%14==0)
#define EACH_15_S (Sec_count%15==0)
#define EACH_16_S (Sec_count%16==0)
#define EACH_17_S (Sec_count%17==0)
#define EACH_18_S (Sec_count%18==0)
#define EACH_19_S (Sec_count%19==0)
#define EACH_20_S (Sec_count%20==0)
#define EACH_25_S (Sec_count%25==0)
#define EACH_30_S (Sec_count%30==0)
#define EACH_40_S (Sec_count%40==0)
#define EACH_50_S (Sec_count%50==0)
#define EACH_1_MIN (Sec_count%60==0)
#define EACH_2_MIN (Min_count%2==0)
#define EACH_3_MIN (Min_count%3==0)
#define EACH_4_MIN (Min_count%4==0)
#define EACH_5_MIN (Min_count%5==0)
#define EACH_6_MIN (Min_count%6==0)
#define EACH_7_MIN (Min_count%7==0)
#define EACH_8_MIN (Min_count%8==0)
#define EACH_9_MIN (Min_count%9==0)
#define EACH_10_MIN (Min_count%10==0)
#define EACH_15_MIN (Min_count%15==0)
#define EACH_20_MIN (Min_count%20==0)
#define EACH_25_MIN (Min_count%25==0)
#define EACH_30_MIN (Min_count%30==0)
#define EACH_1_HOUR (Min_count%60==0)
#define EACH_2_HOUR (Hour_count%2==0)
#define EACH_3_HOUR (Hour_count%3==0)
#define EACH_4_HOUR (Hour_count%4==0)
#define EACH_5_HOUR (Hour_count%5==0)
#define EACH_6_HOUR (Hour_count%6==0)
#define EACH_7_HOUR (Hour_count%7==0)
#define EACH_8_HOUR (Hour_count%8==0)
#define EACH_9_HOUR (Hour_count%9==0)
#define EACH_10_HOUR (Hour_count%10==0)
#define EACH_11_HOUR (Hour_count%11==0)
#define EACH_12_HOUR (Hour_count%12==0)
#define EACH_1_DAY (Hour_count%24==0)

#define STATE_WRONG			(0x02)
#define STATE_OK			(0x01)
#define STATE_NOTREADY		(0x00)

#define SCL_Set {P6.0=1;}
#define SDA_Set {P6.1=1;}
#define SCL_Reset {P6.0=0;}
#define SDA_Reset {P6.1=0;}
#define SDA_Read (P6.1)



#define OnSeat_Set {P12.1=1;}
#define OnSeat_Read (0==P12.1)


#define Key_Stop_Set {P4.2=1;}
#define Key_Hips_Set {P4.1=1;}


#define Key_Stop_Read (0==P4.2)
#define Key_Hips_Read (0==P4.1)
#define Key_Women_Read (0==P13.7)

#define BUZZER_Set {P5.4=1;}
#define BUZZER_Reset {P5.4=0;}

#define DISPLAY_OFF 0
#define DISPLAY_TWINKLE 13
#define DISPLAY_BREATH 1
#define DISPLAY_FORWARD 14
#define DISPLAY_REVERSE 19



#define TM1650_BRIGHTNESS_LEVEL_0 {TM1650_Instruction[0]=0x00;}
#define TM1650_BRIGHTNESS_LEVEL_1 {TM1650_Instruction[0]=0x11;}
#define TM1650_BRIGHTNESS_LEVEL_2 {TM1650_Instruction[0]=0x21;}
#define TM1650_BRIGHTNESS_LEVEL_3 {TM1650_Instruction[0]=0x31;}
#define TM1650_BRIGHTNESS_LEVEL_4 {TM1650_Instruction[0]=0x41;}
#define TM1650_BRIGHTNESS_LEVEL_5 {TM1650_Instruction[0]=0x51;}
#define TM1650_BRIGHTNESS_LEVEL_6 {TM1650_Instruction[0]=0x61;}
#define TM1650_BRIGHTNESS_LEVEL_7 {TM1650_Instruction[0]=0x71;}
#define TM1650_BRIGHTNESS_LEVEL_8 {TM1650_Instruction[0]=0x01;}




#define ROOM_ON {TM1650_Instruction[3]=TM1650_Instruction[3]|0x03;}
#define ROOM_OFF {TM1650_Instruction[3]=TM1650_Instruction[3]&0xFC;}

#define POWER_ON {TM1650_Instruction[3]=TM1650_Instruction[3]|0x0C;}
#define POWER_OFF {TM1650_Instruction[3]=TM1650_Instruction[3]&0xF3;}

#define CHILDREN_ON {TM1650_Instruction[3]=TM1650_Instruction[3]|0x30;}
#define CHILDREN_OFF {TM1650_Instruction[3]=TM1650_Instruction[3]&0xCF;}

#define ENERGY_SAVE_ON {TM1650_Instruction[3]=TM1650_Instruction[3]|0x40;TM1650_Instruction[4]=TM1650_Instruction[4]|0x01;}
#define ENERGY_SAVE_OFF {TM1650_Instruction[3]=TM1650_Instruction[3]&0xBF;TM1650_Instruction[4]=TM1650_Instruction[4]&0xFE;}

#define WATER_ON {TM1650_Instruction[4]=TM1650_Instruction[4]|0x06;}
#define WATER_OFF {TM1650_Instruction[4]=TM1650_Instruction[4]&0xF9;}

#define TEMPERATURE_ON {TM1650_Instruction[4]=TM1650_Instruction[4]|0x08;}
#define TEMPERATURE_OFF {TM1650_Instruction[1]=0x00;TM1650_Instruction[2]=0x00;TM1650_Instruction[4]=TM1650_Instruction[4]&0xF7;}



#define NOTLOOP 1
#define LOOP 0

#define FORWARD_STEP_FLAG 1
#define REVERSE_STEP_FLAG 0


#define u8		unsigned char
#define IIC_uS 1
#define Wait_uS 1


/* End user code. Do not edit comment generated here */
#endif
