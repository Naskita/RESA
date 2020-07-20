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
* Creation Date: 2020/6/30
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
#include "r_cg_timer.h"
/* Start user code for include. Do not edit comment generated here */
#include "tm1650.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
unsigned char MS_count;
unsigned char Hundred_MS_count;
unsigned char Sec_count;
unsigned char Min_count;
unsigned char Hour_count;
unsigned char Day_count;
bit Key_Stop_Trg_Flag;
bit Key_Stop_Press_Flag;
bit Key_Stop_Once_Flag;

bit Key_Hips_Trg_Flag;
bit Key_Hips_Press_Flag;
bit Key_Hips_Once_Flag;

bit Key_Women_Trg_Flag;
bit Key_Women_Press_Flag;
bit Key_Women_Once_Flag;

unsigned char Display_Step;
unsigned char  Direction_Mode_Flag;
unsigned char Display_Step_Set(unsigned char min,unsigned char max,unsigned char now,unsigned char notloop,unsigned char foward_flag);
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
    R_TAU0_Channel0_Start();
    Key_Women_Trg_Flag=1;
    while (1U)
    {
	    if(GetMsFlag()){
		    ClearMs();
		    MS_count++;
		    if(MS_count%2==0){
		    }
		    if(MS_count%5==0){
		    }
		    if(MS_count%10==0){			    
			    

			     
		    }
		    if(MS_count%20==0){
			    Key_Stop_Set;
			    if(Key_Stop_Read){
				if(Key_Stop_Once_Flag){
					//Key_Stop_Trg_Flag=Key_Stop_Read&(Key_Stop_Read^Key_Stop_Press_Flag);
					if(0==Key_Stop_Press_Flag){
						Key_Stop_Trg_Flag=1;
					}
					Key_Stop_Press_Flag=1;
					
				}
				else{
				Key_Stop_Once_Flag=1;
				}
			    }
			    else{
				Key_Stop_Once_Flag=0;
				Key_Stop_Press_Flag=0;
			    }
			    
			    Key_Hips_Set;
			    if(Key_Hips_Read){
				if(Key_Hips_Once_Flag){
					if(0==Key_Hips_Press_Flag){
						Key_Hips_Trg_Flag=1;
					}
					Key_Hips_Press_Flag=1;
				}
				else{
				Key_Hips_Once_Flag=1;
				}
			    }
			    else{
				Key_Hips_Once_Flag=0;
				Key_Hips_Press_Flag=0;
			    }
			    
			    if(Key_Women_Read){
				if(Key_Women_Once_Flag){
					if(0==Key_Women_Press_Flag){
						Key_Women_Trg_Flag=1;
					}
					Key_Women_Press_Flag=1;
				}
				else{
				Key_Women_Once_Flag=1;
				}
			    }
			    else{
				Key_Women_Once_Flag=0;
				Key_Women_Press_Flag=0;
			    }
		    }
		    if(MS_count%50==0){
		    }
		    if(MS_count%100==0){
			    MS_count=0;
			    Hundred_MS_count++;
			    if(Key_Stop_Trg_Flag|Key_Hips_Trg_Flag|Key_Women_Trg_Flag){
					    BUZZER_Set;
					    if(Key_Stop_Trg_Flag){
						    Key_Stop_Trg_Flag=0;
						    Display_Step=DISPLAY_TWINKLE;
						    Direction_Mode_Flag=DISPLAY_TWINKLE;
					    }
					    else if(Key_Hips_Trg_Flag){
						    Key_Hips_Trg_Flag=0;
						    Display_Step=DISPLAY_FORWARD;
						    Direction_Mode_Flag=DISPLAY_FORWARD;
					    }
					    else if(Key_Women_Trg_Flag){
						    Key_Women_Trg_Flag=0;
						    Display_Step=DISPLAY_REVERSE;
						    Direction_Mode_Flag=DISPLAY_REVERSE;
					    }
				    }
				    else{
					    BUZZER_Reset;					    
				    } 
			    if(Hundred_MS_count%2==0){
				
				    switch(Display_Step){
					    case DISPLAY_OFF:					    
					    	ALL_OFF;
						break;			    				    
					    case DISPLAY_BREATH:
					    	ALL_OFF;
						break;	
					    case 2:
					    	ALL_OFF;
						break;	
					    case 3:
					    	ALL_LEVEL1_ON;
						break;	
					    case 4:
					    	ALL_LEVEL1_ON;
						break;	
					    case 5:
					    	ALL_LEVEL2_ON;
						break;	
					    case 6:
					    	ALL_LEVEL2_ON;
						break;							
					    case 7:
					    	ALL_LEVEL3_ON;
						break;	
					    case 8:
					    	ALL_LEVEL3_ON;
						break;	
					    case 9:
					    	ALL_LEVEL4_ON;
						break;	
					    case 10:
					    	ALL_LEVEL5_ON;
						break;	
					    case 11:
					    	ALL_LEVEL6_ON;
						break;	
					    case 12:
					    	ALL_LEVEL7_ON;
						break;							
					    case DISPLAY_TWINKLE:	
					    	ALL_LEVEL8_ON;
						break;						    
					    case DISPLAY_FORWARD:
					    	POWER_ON;
						break;	 	
					    case 15:
					    	CHILDREN_ON;
						break;	
					    case 16:
					    	ENERGY_SAVE_ON;
						break;	
					    case 17:
					    	WATER_ON;
						break;	
					    case 18:
					    	TEMPERATURE_ON;
						break;				    
					    case DISPLAY_REVERSE:
					    	ROOM_ON;
						break;	    
					    default:
						
					    break;
					    	
				    }
				    switch(Direction_Mode_Flag){
					    case DISPLAY_OFF:					    
					    	Direction_Mode_Flag=DISPLAY_TWINKLE;	
						Display_Step=DISPLAY_TWINKLE;
						break;			    				    
					    case DISPLAY_BREATH:
					    	Display_Step=Display_Step_Set(DISPLAY_OFF,DISPLAY_TWINKLE,Display_Step,LOOP,FORWARD_STEP_FLAG);
						break;						
					    case DISPLAY_TWINKLE:	
					    	Direction_Mode_Flag=DISPLAY_OFF;
						Display_Step=DISPLAY_OFF;
						break;						    
					    case DISPLAY_FORWARD:
					    	Display_Step=Display_Step_Set(DISPLAY_FORWARD,DISPLAY_REVERSE,Display_Step,NOTLOOP,FORWARD_STEP_FLAG);
						break;						    
					    case DISPLAY_REVERSE:					    
					    	Display_Step=Display_Step_Set(DISPLAY_FORWARD,DISPLAY_REVERSE,Display_Step,NOTLOOP,REVERSE_STEP_FLAG);
						break;	
					    default:
						
					    break;					    	
				    } 
			    
			    }
			    if(Hundred_MS_count%5==0){
				    
				   
				    
			    }

			    if(Hundred_MS_count%10==0){
				   Hundred_MS_count=0£»
				   Sec_count++£»
				   
				   

					if(Sec_count%2==0){
						
					}
					if(Sec_count%5==0){
					
					}
					if(Sec_count%10==0){
						
					}
					if(Sec_count%20==0){
					}
					if(Sec_count%30==0){
					}
				    if(Sec_count%60==0){
					   Sec_count=0£»
					   Min_count++£»
					   if(Min_count%2==0){
						}
						if(Min_count%5==0){
						}
						if(Min_count%10==0){
						}
						if(Min_count%20==0){
						}
						if(Min_count%30==0){
						}
						    if(Min_count%60==0){
							   Min_count=0£»
							   Hour_count++£»
							   if(Hour_count%24==0){
								   Hour_count=0;
								   Day_count++;
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
unsigned char Display_Step_Set(unsigned char min,unsigned char max,unsigned char now,unsigned char notloop,unsigned char foward_flag)
{
	if(now==max){
		if(notloop){
			if(foward_flag){
				return min;
			}
			else{
				return now-1;
			}
		}
		return now-1;
	}
	else if(now==min){
		if(notloop){
			if(foward_flag){
				return now+1;
			}
			else{
				return max;
			}
		}
		return now+1;
	}
	
	if(foward_flag){
		return now+1;
	}
	else{
		return now-1;
	}
	
}
/* End user code. Do not edit comment generated here */
