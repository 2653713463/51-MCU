/**************************************
  > File Name: �������ݽ���PC->MCU
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2016 �� 3 �� 27 ��
  > ˵�������յ�������ͨ��P2����8��С�Ƶ�����
***************************************/
#include<reg51.h>
#include<stdio.h>
#define uchar unsigned char
#define uint unsigned int

uchar tmp;
void init_UART()
{
	SCON=0x50;
	TMOD=0x20;
	PCON=0x00; //�����ʼӱ�
	TH1=0xFD;  //������9600
	TL1=TH1;
	TR1=1;
}

uchar UART_Rec()
{
	uchar g_Uart_Reval;
	if(RI)//RI=1,˵�����ݽ������
	{
		g_Uart_Reval=SBUF;//��ȡ������������
		RI=0;             //�������
	}
	return g_Uart_Reval;
}
int main()
{
	init_UART();
	/*
	TI=1;
	printf("I love you");
	while(!TI);
	TI=0;
	*/
	
	while(1)
	{
		tmp=UART_Rec();
		if(tmp=='1')
		{
			P2=0xFF;
		}
		else if (tmp=='0')
		{
			P2=0x55;
		}
	}
	return 0;
}

//void UARTInterrupt() interrupt 4
//{
//	if(RI)
//	{
//		RI=0;
//		
//	}
//	else
//		TI=0;
//}