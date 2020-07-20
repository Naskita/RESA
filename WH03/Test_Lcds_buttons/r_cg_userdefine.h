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
* Creation Date: 2020/6/30
***********************************************************************************************************************/

#ifndef _USER_DEF_H
#define _USER_DEF_H

/***********************************************************************************************************************
User definitions
***********************************************************************************************************************/

/* Start user code for function. Do not edit comment generated here */
#define SCL_Set (P6.0=1)//(GPIOB->BSRR = 1<<5)
#define SDA_Set (P6.1=1)//(GPIOB->BSRR = 1<<6)
#define SCL_Reset (P6.0=0)//(GPIOB->BSRR = 1<<(16+5))
#define SDA_Reset (P6.1=0)//(GPIOB->BSRR = 1<<(16+6))
#define SDA_Read (P6.1)


#define Key_Stop_Set (P4.2=1)
#define Key_Hips_Set (P4.1=1)


#define Key_Stop_Read (0==P4.2)
#define Key_Hips_Read (0==P4.1)
#define Key_Women_Read (0==P13.7)

#define BUZZER_Set (P5.4=1)
#define BUZZER_Reset (P5.4=0)

#define DISPLAY_OFF 0
#define DISPLAY_TWINKLE 13
#define DISPLAY_BREATH 1
#define DISPLAY_FORWARD 14
#define DISPLAY_REVERSE 19

#define ALL_OFF {TM1650_Init();TM1650_Wr_RAM(0x48,0x00);}
#define ALL_ON {TM1650_Wr_RAM(0x68,0x7f);TM1650_Wr_RAM(0x6a,0x7f);TM1650_Wr_RAM(0x6c,0x7f);TM1650_Wr_RAM(0x6e,0x0f);}
#define ALL_LEVEL1_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x11);ALL_ON;}
#define ALL_LEVEL2_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x21);ALL_ON;}
#define ALL_LEVEL3_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x31);ALL_ON;}
#define ALL_LEVEL4_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x41);ALL_ON;}
#define ALL_LEVEL5_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x51);ALL_ON;}
#define ALL_LEVEL6_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x61);ALL_ON;}
#define ALL_LEVEL7_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x71);ALL_ON;}
#define ALL_LEVEL8_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);ALL_ON;}

#define POWER_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x00);TM1650_Wr_RAM(0x6a,0x00);TM1650_Wr_RAM(0x6c,0x0c);TM1650_Wr_RAM(0x6e,0x00);}
#define CHILDREN_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x00);TM1650_Wr_RAM(0x6a,0x00);TM1650_Wr_RAM(0x6c,0x30);TM1650_Wr_RAM(0x6e,0x00);}
#define ENERGY_SAVE_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x00);TM1650_Wr_RAM(0x6a,0x00);TM1650_Wr_RAM(0x6c,0x40);TM1650_Wr_RAM(0x6e,0x01);}
#define WATER_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x00);TM1650_Wr_RAM(0x6a,0x00);TM1650_Wr_RAM(0x6c,0x00);TM1650_Wr_RAM(0x6e,0x06);}
#define TEMPERATURE_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x7f);TM1650_Wr_RAM(0x6a,0x7f);TM1650_Wr_RAM(0x6c,0x00);TM1650_Wr_RAM(0x6e,0x08);}
#define ROOM_ON {TM1650_Init();TM1650_Wr_RAM(0x48,0x01);TM1650_Wr_RAM(0x68,0x00);TM1650_Wr_RAM(0x6a,0x00);TM1650_Wr_RAM(0x6c,0x03);TM1650_Wr_RAM(0x6e,0x00);}

#define NOTLOOP 1
#define LOOP 0

#define FORWARD_STEP_FLAG 1
#define REVERSE_STEP_FLAG 0


//#define SCL_Read (GPIO_ReadInputDataBit(GPIOB, P6_bit.no0))
//#define SDA_Read (GPIO_ReadInputDataBit(GPIOB, P6_bit.no1))
#define u8 unsigned char
#define IIC_uS 1
#define Wait_uS 1
/* End user code. Do not edit comment generated here */
#endif
