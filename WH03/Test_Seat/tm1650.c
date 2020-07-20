#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_port.h"
#include "r_cg_timer.h"
#include "r_cg_userdefine.h"
#include "tm1650.h"
//#include "LED.h"
//#include "delay.h"





//u8 KEY_EXTI= 0;





///*
//*�������ܣ�����ܰ�����ʼ��
//*��    ʾ��tm1650����4���������ⲿ�жϹ�����������
//*�����������
//*�����������
//*����ֵ  ����
//*/
//void Tube_Key_Init(void)
//{
//    /*�����ⲿ�жϳ�ʼ��*/
//    EXTI_KEY_Init();
//
//    /*TM1650��ʼ��*/
//    TM1650_Init();
//}
//
///*
//*�������ܣ�TM1650��ʼ��
//*��    ʾ��tm1650����4���������ⲿ�жϹ�����������
//*�����������
//*�����������
//*����ֵ  ����
//*/
void TM1650_Init(void)
{
    IIC_Init();

    Delay_mS(50);

    TM1650_Wr_RAM(0x48,0x00);//�ر���ʾ
}
//
///*
//*�������ܣ��������ʾ����
//*��    ʾ����4λ֧������
//*���������u16 Num:��ʾ������
//*�����������
//*����ֵ  ����
//*/
//const u8 NUM[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//�������ʾ0~9��Ӧ��ֵ
//void Tube_DisNum(u16 Num)
//{
//    u8 Temp[4];
//
//    /*���ݷ���*/
//    Temp[0] = Num%10000/1000;
//    Temp[1] = Num%1000/100;
//    Temp[2] = Num%100/10;
//    Temp[3] = Num%10;
//
//    /*��ʾ*/
//    TM1650_Wr_RAM(0x68, NUM[Temp[0]]);
//    TM1650_Wr_RAM(0x6A, NUM[Temp[1]]);
//    TM1650_Wr_RAM(0x6C, NUM[Temp[2]]);
//    TM1650_Wr_RAM(0x6E, NUM[Temp[3]]);
//}


///*
//*�������ܣ��������ʾ����
//*��    ʾ��0��ʾ������� 1��С
//*���������u8 State:0�ر�, 1����; u8 Brightness:���� 8 1 2-7
//*�����������
//*����ֵ  ����
//*/
//void Tube_CMD(u8 State, u8 Brightness)
//{
//    if(State)
//    {
//        TM1650_Wr_RAM(0x48,Brightness*16+1);//������ʾ
//    }
//    else
//    {
//        TM1650_Wr_RAM(0x48,0x00);//�ر���ʾ
//    }
//}

//
///*
//*�������ܣ�������tm1650�ϰ���ɨ��
//*��    ʾ����
//*���������
//*�����������
//*����ֵ  ����
//*/
//static u8 KEYtm_Scan(void)
//{
//    u8 Temp = 0;
//
//    /*��ȡ����ֵ*/
//    IIC_Start();
//    IIC_Wr_Byte(0x49);
//    IIC_Wait_Ack();
//    Temp = IIC_Rd_Byte();
//    IIC_Ack();
//    IIC_Stop();
//
//    /*�������*/
//    if(Temp == 0x5C)
//    {
//        return KEY_Mode_Press;
//    }
//    else if(Temp == 0x5D)
//    {
//        return KEY_Up_Press;
//    }
//    else if(Temp == 0x5E)
//    {
//        return KEY_Down_Press;
//    }
//    else if(Temp == 0x5F)
//    {
//        return KEY_Run_Press;
//    }
//    else
//    {
//        return 0;
//    }
//}
//
//
///*
//*�������ܣ�����ɨ��
//*��    ʾ����
//*���������
//*�����������
//*����ֵ  ��u8:��⵽�İ���ֵ
//*/
//u8 KEY_Read(void)
//{
//    u8 Temp = 0;
//
//    if(KEY_EXTI != 0)
//    {
//        Temp = KEY_EXTI;
//        KEY_EXTI = 0;
//        return Temp;
//    }
//
//    Temp = KEYtm_Scan();
//    if(Temp != 0)
//    {
//        return Temp;
//    }
//
//    return 0;
//}
//
//

//
///*
//*�������ܣ�TM1650ͨѶIIC��ʼ��
//*��    ʾ��tm1650����4���������ⲿ�жϹ�����������
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_Init(void)
{
    /*����״̬*/
    SCL_Set;
    SDA_Set;
}


///*
//*�������ܣ�IIC��ʼ
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_Start(void)
{
    SCL_Set;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
    SDA_Reset;
    Delay_uS(IIC_uS);
    SCL_Reset;
    Delay_uS(IIC_uS);
}

///*
//*�������ܣ�IIC����
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_Stop(void)
{

    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Reset;
    Delay_uS(IIC_uS);
    SCL_Set;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
}


///*
//*�������ܣ�IIC��Ӧ
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_Ack(void)
{
    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Reset;
    Delay_uS(IIC_uS);
    SCL_Set;
    Delay_uS(Wait_uS);
    SCL_Reset;
    Delay_uS(IIC_uS);
}
//
///*
//*�������ܣ�IIC����Ӧ
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_NoAck(void)
{
    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
    SCL_Set;
    Delay_uS(Wait_uS);
    SCL_Reset;
}


///*
//*�������ܣ�IIC�ȴ���Ӧ
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/

unsigned char IIC_Wait_Ack(void)
{    
    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
    while(SDA_Read == 1)
    {
	IIC_Stop();
	Delay_uS(IIC_uS);
	return 1;
    }
    SCL_Set;
    Delay_uS(IIC_uS);
    SCL_Reset;
    Delay_uS(IIC_uS);
    return 0;
}
//
///*
//*�������ܣ�IICд�ֽ�
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void IIC_Wr_Byte(unsigned char Data)
{
    u8 i = 0;


    for(i = 0; i < 8; i++)
    {
        SCL_Reset;
        Delay_uS(IIC_uS);

        if(Data >> 7)
        {
            SDA_Set;
        }
        else
        {
            SDA_Reset;
        }
        Data <<= 1;
        Delay_uS(IIC_uS);

        SCL_Set;
        Delay_uS(IIC_uS);
    }
    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
}

///*
//*�������ܣ�IIC���ֽ�
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
unsigned char IIC_Rd_Byte(void)
{
    u8 i = 0;
    u8 Temp = 0;

    SCL_Reset;
    Delay_uS(IIC_uS);
    SDA_Set;
    Delay_uS(IIC_uS);
    for(i = 0; i < 8; i++)
    {
        SCL_Reset;
        Delay_uS(IIC_uS);
        Temp <<= 1;
        Temp += SDA_Read;
        SCL_Set;
        Delay_uS(IIC_uS);
    }
    SCL_Reset;
    Delay_uS(IIC_uS);
    return Temp;
}



///*
//*�������ܣ�д�Դ�
//*��    ʾ��
//*�����������
//*�����������
//*����ֵ  ����
//*/
void TM1650_Wr_RAM(unsigned char Address, unsigned char Data)
{
    IIC_Start();
    IIC_Wr_Byte(Address);
    IIC_Wait_Ack();
    IIC_Wr_Byte(Data);
    IIC_Wait_Ack();
    IIC_Stop();
}



























//
///*
//*�������ܣ��ⲿ�жϰ�����ʼ��
//*��    ʾ���ⲿ�жϹ�����������,A15 B15
//*�����������
//*�����������
//*����ֵ  ����
//*/
//static void EXTI_KEY_Init(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//
//    EXTI_InitTypeDef EXTI_InitStructure;
//    NVIC_InitTypeDef NVIC_InitStructure;
//
//
///*����IO����*/
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);
//
//    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;  //STOP
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;  //�ڲ���������
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//
//    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//����B3 B4 B15Ϊ��ͨIOģʽ
//    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3;//LOCK
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;  //�ڲ���������
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//
//
///*�ж�����*/
//    //RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
//
//    /*���Ű�*/
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);
//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource3);
//
//    /*�ж�ģʽ����*/
//    EXTI_InitStructure.EXTI_Line = EXTI_Line15|EXTI_Line3;
//    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
//    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//�½��ش���
//    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//    EXTI_Init(&EXTI_InitStructure);
//
//    /*�ж���Ӧ����*/
//    //STOP
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;			//�����ȼ�1
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
//    NVIC_Init(&NVIC_InitStructure);
//
//    //LOCK
//    NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;		    	//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;			//�����ȼ�1
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;					//ʹ���ⲿ�ж�ͨ��
//    NVIC_Init(&NVIC_InitStructure);
//}
//
//
//
///*
//*�������ܣ��ⲿ�жϰ�����Ӧ����
//*��    ʾ���ⲿ�жϹ�����������,A15 B15
//*�����������
//*�����������
//*����ֵ  ����
//*/
//#define KEY_Stop_Rd GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15)
//#define KEY_Lock_Rd GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3)
///*Stop*/
//void EXTI15_10_IRQHandler(void)
//{
//    if(EXTI_GetITStatus(EXTI_Line15) != RESET)
//    {
//        Delay_mS(10);
//        if(KEY_Stop_Rd == RESET)
//        {
//            KEY_EXTI= KEY_Stop_Press;
//        }
//
//        EXTI_ClearITPendingBit(EXTI_Line15);  //�����·����λ
//    }
//}
///*Lock*/
//void EXTI3_IRQHandler(void)
//{
//
//     Delay_mS(10);
//    if(KEY_Lock_Rd == RESET)
//    {
//        KEY_EXTI= KEY_Lock_Press;
//    }
//
//    EXTI_ClearITPendingBit(EXTI_Line3);  //�����·����λ
//}

