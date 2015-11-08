/**************************************
  > File Name: ��ʱ���ж�
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 8 �� 1 ��
***************************************/
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

unsigned char code LedChar[]={
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
	};      //�������������ֵ��
uchar LedBuff[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uchar i=0;
uchar flagls=0;
uint cnt=0;

void main()
{
	unsigned long sec=0;
	
	EA=1;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x18;           //1ms�����
	ET0=1;              //��ʱ��0ʹ���ж�
	TR0=1;              //�򿪶�ʱ��0
	while(1)
	{
		if(flagls==1)
		{
			flagls=0;
			sec++;
			LedBuff[0] = ~LedChar[sec%10];
			LedBuff[1] = ~LedChar[sec/10%10];
			LedBuff[2] = ~LedChar[sec/100%10];
			LedBuff[3] = ~LedChar[sec/1000%10];
			LedBuff[4] = ~LedChar[sec/10000%10];
			LedBuff[5] = ~LedChar[sec/100000%10];
			LedBuff[6] = ~LedChar[sec/1000000%10];
			LedBuff[7] = ~LedChar[sec/10000000%10];
		}
	}
}

/*��ʱ��0�ж�ʹ�ܺ���*/
void InterruptTimer0()  interrupt 1
{
	TH0=0xFC;
	TL0=0x18;
	cnt++;
	if(cnt>=1000)       //�ж�1000�Σ���1s
	{
		cnt=0;
		flagls=1;
	}
	P1=0x00;            //���������
	for(;i<8;i++)
	{
		P0=~LedChar[i];
		P1=LedBuff[i];
	}
}