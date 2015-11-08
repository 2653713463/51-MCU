/**************************************
  > File Name: ������ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 25 ��
***************************************/
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

sbit BUZZ = P1^5;

unsigned char T0RH=0;
unsigned char T0RL=0;
void OpenBuzz(unsigned int frequ); 
void StopBuzz();

void main()
{
	unsigned int i;
	EA =1;                          //ʹ��ȫ���ж�
	TMOD = 0x01;                    //����T0����ģʽ1

	while(1)
	{
		OpenBuzz(4000);             //��4KHZƵ������������
		for(i=0; i<40000; i++);
		StopBuzz();                 //ֹͣ������
		for(i=0; i<40000; i++);
		OpenBuzz(1000);             //��1KHZƵ������������
		for(i=0; i<40000; i++);
		StopBuzz();
		for(i=0; i<40000; i++);

	}
}

void OpenBuzz(unsigned int frequ)
{
	unsigned int reload;            //�������趨ʱ������ֵ

	reload = 65536 - (11059200/12)/(frequ*2); 
	T0RH = (unsigned char)(reload >>8);
	T0RL = (unsigned char)reload;

	TH0 = 0xFF;
	TL0 = 0xFE;

	ET0 = 1;                        //ʹ��T0�ж�
	TR0 = 1;                        //����T0
}

void StopBuzz()
{
	ET0 = 0;
	TR0 = 0;
}

void InterruptTimer0() interrupt 1
{
	TH0 = T0RH;
	TL0 = T0RL;
	BUZZ = ~BUZZ;
}