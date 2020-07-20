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
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G13 V2.05.04.02 [20 Nov 2019]
* Device(s)    : R5F100LE
* Tool-Chain   : CA78K0R
* Description  : This file implements main function.
* Creation Date: 2020/7/16
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_serial.h"
#include "r_cg_adc.h"
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
#include<math.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
const u8 NUM[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//数码管显示0~9对应的值

unsigned char TM1650_Address[5]={0x48,0x68,0x6A,0x6c,0x6E};
unsigned char TM1650_Instruction[5]={0x00,0x00,0x00,0x00,0x00};
unsigned char tx_dat[44];
bit Key_Stop_Trg_Flag;
bit Key_Stop_Press_Flag;
bit Key_Stop_Once_Flag;
unsigned int temp_i;
unsigned int temp_j;
unsigned int temp_k;
bit Key_Hips_Trg_Flag;
bit Key_Hips_Press_Flag;
bit Key_Hips_Once_Flag;

bit Key_Women_Trg_Flag;
bit Key_Women_Press_Flag;
bit Key_Women_Once_Flag;
unsigned char Temp_Value;
bit OnSeat_Trg_Flag;
bit OnSeat_Press_Flag;
bit OnSeat_Once_Flag;

bit Seat_Pad_19_Flag;
bit Seat_Pad_20_Flag;

bit Seat_Pad_Wrong_Flag;
bit Seat_Temp_Wrong_Flag;
bit Seat_Induction_Wrong_Flag;

bit Start_To_Display_Flag;
bit Once_TM1650_Init_Flag;
bit TM1650_Ready_To_Write_Flag;
bit TM1650_Writing_Flag;
unsigned char state;


void Send_RemoteControl_Signal(unsigned char ButtonX,unsigned char ButtonY,unsigned long PressTimes);

/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_MAIN_UserInit();
    /* Start user code. Do not edit comment generated here */
    TM1650_Address[0]=0x48;
	TM1650_Address[1]=0x68;
	TM1650_Address[2]=0x6A;
	TM1650_Address[3]=0x6C;
	TM1650_Address[4]=0x6E;
	R_TAU0_Channel1_Start();
	R_TAU0_Channel0_Start();
	//R_UART1_Start();
	//Once_TM1650_Init_Flag=1;
	Delay_mS(2000);
	Send_RemoteControl_Signal(Button_TingZhi,0,5000);
	Delay_mS(10000);
    while (1U)
    {
		Send_RemoteControl_Signal(Button_DianYuan,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_Yedeng,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_DianYuan,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_ChongShui,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_Yedeng,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_FanGai,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_Yedeng,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_FanQuan,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_Yedeng,0,100);
		Delay_mS(3000);
		for(temp_i=0;temp_i<3;temp_i++){
			Send_RemoteControl_Signal(Button_ChongShui,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_JieNeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_ShuiWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_ZuoWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_FengWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<20;temp_j++){
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}	
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_TunXi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			Send_RemoteControl_Signal(Button_TingZhi,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_FuXi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			Send_RemoteControl_Signal(Button_TingZhi,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_ZhuBian,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			for(temp_j=0;temp_j<3;temp_j++){
				Send_RemoteControl_Signal(Button_HongGan,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_TingZhi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}			
		}
		for(temp_i=0;temp_i<3;temp_i++){
			Send_RemoteControl_Signal(Button_ChongShui,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_ErTong,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_ShuiWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_ZuoWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_FengWen,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<20;temp_j++){
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}	
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_TunXi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			Send_RemoteControl_Signal(Button_TingZhi,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_FuXi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			Send_RemoteControl_Signal(Button_TingZhi,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			Send_RemoteControl_Signal(Button_Yedeng,0,100);
			Delay_mS(3000);
			for(temp_j=0;temp_j<8;temp_j++){
				Send_RemoteControl_Signal(Button_ZhuBian,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QianYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_HouYi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_QiangDu,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
			for(temp_j=0;temp_j<3;temp_j++){
				Send_RemoteControl_Signal(Button_HongGan,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_TingZhi,0,100);
				Delay_mS(3000);
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}					
			
		}
		for(temp_i=0;temp_i<20;temp_i++){
				Send_RemoteControl_Signal(Button_Yedeng,0,100);
				Delay_mS(3000);
			}
		Send_RemoteControl_Signal(Button_ChongShui,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_Yedeng,0,100);
		Delay_mS(3000);
		Send_RemoteControl_Signal(Button_DianYuan,0,5000);
		temp_k++;
		if(temp_k>=30){
			temp_k=0;
			Delay_mS(30*60000);
		}
		Delay_mS(60000);
	}
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
void Send_RemoteControl_Signal(unsigned char ButtonX,unsigned char ButtonY,unsigned long PressTimes)
{
	unsigned int u16_DelayForUs;
	unsigned long u32_DelayForMs;	
	unsigned int i;
	DATA_Reset;	
	u16_DelayForUs=6000;
	Delay_uS(u16_DelayForUs);
	DATA_Set;
	u16_DelayForUs=3000;
	Delay_uS(u16_DelayForUs);	
	for(i=0;i<8;i++){
		DATA_Reset;	
		u16_DelayForUs=400;
		Delay_uS(u16_DelayForUs);
		DATA_Set;
		if(ButtonY&((0x01)<<i)){
			u16_DelayForUs=1200;
		}
		else{
			u16_DelayForUs=400;
		}
		Delay_uS(u16_DelayForUs);
	}
	for(i=0;i<8;i++){
		DATA_Reset;	
		u16_DelayForUs=400;
		Delay_uS(u16_DelayForUs);
		DATA_Set;
		if(ButtonX&((0x01)<<i)){
			u16_DelayForUs=1200;
		}
		else{
			u16_DelayForUs=400;
		}
		Delay_uS(u16_DelayForUs);
	}
	DATA_Reset;	
	u32_DelayForMs=PressTimes;	
	Delay_mS(u32_DelayForMs);
	DATA_Set;
}



/* End user code. Do not edit comment generated here */
