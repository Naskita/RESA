
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
* Creation Date: 2020/7/17
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
void AdcTenTimesAverage(void);
void OnSeatScan(void);
void KeyHandle(void);
void DisplayHandle(void);
void Tube_DisNum(unsigned char Num);


unsigned char CheckAdcDat(void);
unsigned char TM1650_Init(void);
unsigned char IIC_Start(void);
unsigned char IIC_Stop(void);
unsigned char IIC_Ack(void);
unsigned char IIC_NoAck(void);
unsigned char IIC_Wait_Ack(void);
unsigned char IIC_Wr_Byte(unsigned char Data);
unsigned char IIC_Rd_Byte(unsigned char* Temp);
unsigned char TM1650_Wr_RAM(unsigned char Address, unsigned char Data);
unsigned char TM1650_Refresh(void);

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
	R_UART1_Start();
	Once_TM1650_Init_Flag=1;
	P1.6=1;
    while (1U)
    {
		if(EACH_1_US){
			
			
	    }
		
		if(EACH_1_MS){
			MS_count++;
			if(EACH_10_MS){				
					R_TAU0_Channel0_Start();//this timer just for the i2c,the timer should be shut down when the i2c is not working.

	    	}
			
			if(EACH_20_MS){
	    	}
			if(EACH_50_MS){
								
	    	}			
			if(EACH_100_MS){	    
				MILLISECOND_100_CARRY;
				if(EACH_200_MS){
				}
				if(EACH_300_MS){					
				}
				if(EACH_1_S){
					SECOND_1_CARRY;						
					
					if(EACH_1_MIN){
						MINUTER_1_CARRY;
						if(EACH_1_HOUR){
							HOUR_1_CARRY;
							if(EACH_1_DAY){
								DAY_1_CARRY;
							}
						}
					}
				}
			}
	    }		
		
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
void OnSeatScan(void)
{
	if(OnSeat_Read){
		if(OnSeat_Once_Flag){
			if(0==OnSeat_Press_Flag){
				OnSeat_Trg_Flag=1;
			}
			OnSeat_Press_Flag=1;
		}else{
			OnSeat_Once_Flag=1;
		}
	}else{
		OnSeat_Once_Flag=0;
		OnSeat_Press_Flag=0;
	}
}

void KeyHandle(void)
{
    if(Key_Stop_Trg_Flag|Key_Hips_Trg_Flag|Key_Women_Trg_Flag){
	    BUZZER_Set;
	}else{
	    BUZZER_Reset;
    }
}

void DisplayHandle(void)
{
	static unsigned char i;
	static unsigned char function_steps;
	
	i++;
	if(i>=5){
		TM1650_BRIGHTNESS_LEVEL_1;
		Start_To_Display_Flag=0;
		i=0;
		return;
	}
	TM1650_BRIGHTNESS_LEVEL_8;
	switch(function_steps){
	case 0:
		if(Seat_Pad_Wrong_Flag){
			ENERGY_SAVE_ON;
		}
		else if(Seat_Pad_19_Flag){
			ROOM_ON;
			ENERGY_SAVE_ON;
		}
		else if(Seat_Pad_20_Flag){
			WATER_ON;
			ENERGY_SAVE_ON;
		}
		
		if(Seat_Temp_Wrong_Flag){
			CHILDREN_ON;
			TEMPERATURE_ON;
		}
		else{
			CHILDREN_ON;
			TEMPERATURE_ON;
		}
		
		if(OnSeat_Press_Flag){
			POWER_ON;			
		}
		else{
			POWER_OFF;
		}
		function_steps++;
		break;
	case 1:
		if(Seat_Pad_Wrong_Flag){
			i=0;
			ROOM_OFF;
			WATER_OFF;
			ENERGY_SAVE_OFF;
		}
		else if(Seat_Pad_19_Flag){
			ROOM_ON;
			ENERGY_SAVE_ON;
		}
		else if(Seat_Pad_20_Flag){
			WATER_ON;
			ENERGY_SAVE_ON;
		}
		
		if(Seat_Temp_Wrong_Flag){
			i=0;
			CHILDREN_OFF;
			TEMPERATURE_OFF;
		}
		else{
			CHILDREN_ON;
			TEMPERATURE_ON;
		}
		
		if(OnSeat_Press_Flag){
			i=0;
			POWER_OFF;
		}		
		function_steps=0;
		break;
	default:
		function_steps=0;
		break;
	}
}

void Tube_DisNum(unsigned char Num)
{
    unsigned char Temp[2];
    Temp[0] = Num%100/10;
    Temp[1] = Num%10;
	TM1650_Instruction[1]=NUM[Temp[0]];
	TM1650_Instruction[2]=NUM[Temp[1]];
}

unsigned char TM1650_Init(void)
{
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Set;
    	SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
		break;
	case 1:
		function_steps=0;
		return STATE_OK;
		break;
	default:
		function_steps=0;
		return STATE_WRONG;
		break;
	}	
}

unsigned char IIC_Start(void)
{
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SDA_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 4:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
    
}
unsigned char IIC_Stop(void)
{
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 4:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}

unsigned char IIC_Ack(void)
{
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 4:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
unsigned char IIC_NoAck(void)
{
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 4:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
unsigned char IIC_Wait_Ack(void)
{    
	static unsigned char i;
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Set;
		PM6 = _00_PMn0_MODE_OUTPUT | _02_PMn1_MODE_INPUT | _04_PMn2_NOT_USE | _00_PMn3_MODE_OUTPUT | _F0_PM6_DEFAULT;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		if(SDA_Read == 1){
			if(i>=100){
				i=0;
				PM6 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _04_PMn2_NOT_USE | _00_PMn3_MODE_OUTPUT | _F0_PM6_DEFAULT;
				function_steps=0;
				return STATE_WRONG;
			}
			i++;
			return STATE_NOTREADY;			
		}
		
		PM6 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _04_PMn2_NOT_USE | _00_PMn3_MODE_OUTPUT | _F0_PM6_DEFAULT;
		function_steps++;
		return STATE_NOTREADY;
	
	case 4:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 5:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
unsigned char IIC_Wr_Byte(unsigned char Data)
{
    static unsigned char i = 0;
	static unsigned char function_steps;
	static unsigned char Data_temp;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		if(Data&(0x01<<(7-i)))
        {
            SDA_Set;
        }
        else
        {
            SDA_Reset;
        }
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Set;
		if(i>=7){
			i=0;
			function_steps++;
			return STATE_NOTREADY;
			
		}
		else{
			i++;
			function_steps=0;
			return STATE_NOTREADY;
		}		
	case 3:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 4:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 5:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
unsigned char IIC_Rd_Byte(unsigned char* Temp)
{
    static unsigned char i = 0;
	static unsigned char function_steps;
	switch(function_steps){
	case 0:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 1:
		SDA_Set;
		function_steps++;
		return STATE_NOTREADY;
	case 2:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 3:
		*Temp <<= 1;
        *Temp += SDA_Read;
        SCL_Set;
		if(i>=7){
			i=0;
			function_steps++;
			return STATE_NOTREADY;
			
		}
		else{
			i++;
			function_steps=2;
			return STATE_NOTREADY;
		}		
	case 4:
		SCL_Reset;
		function_steps++;
		return STATE_NOTREADY;
	case 5:
		function_steps=0;
		return STATE_OK;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
unsigned char TM1650_Wr_RAM(unsigned char Address, unsigned char Data)
{
	static unsigned char function_steps;
	
	switch(function_steps){
	case 0:
		state=IIC_Start();
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 1:
		state=IIC_Wr_Byte(Address);
		if(STATE_OK==state){
			
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 2:	
		state=IIC_Wait_Ack();
		if(STATE_OK==state){
			
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=5;
			return STATE_NOTREADY;
		}
		return STATE_NOTREADY;
	case 3:
		state=IIC_Wr_Byte(Data);
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 4:
		state=IIC_Wait_Ack();
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=5;
			return STATE_NOTREADY;
		}
		return STATE_NOTREADY;
	case 5:
		state=IIC_Stop();
		if(STATE_OK==state){
			function_steps=0;
			return STATE_OK;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}

unsigned char TM1650_Refresh(void)
{
	static unsigned char function_steps;
		
	switch(function_steps){
	case 0:
		state=TM1650_Wr_RAM(0x48,TM1650_Instruction[0]);
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 1:
		state=TM1650_Wr_RAM(0x68,TM1650_Instruction[1]);
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 2:	
		state=TM1650_Wr_RAM(0x6A,TM1650_Instruction[2]);
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 3:
		state=TM1650_Wr_RAM(0x6C,TM1650_Instruction[3]);
		if(STATE_OK==state){
			function_steps++;
			return STATE_NOTREADY;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	case 4:
		state=TM1650_Wr_RAM(0x6E,TM1650_Instruction[4]);
		if(STATE_OK==state){
			function_steps=0;
			return STATE_OK;
		}
		else if(STATE_WRONG==state){
			function_steps=0;
			return STATE_WRONG;
		}
		return STATE_NOTREADY;
	default:
		function_steps=0;
		return STATE_WRONG;
	}
}
/* End user code. Do not edit comment generated here */
