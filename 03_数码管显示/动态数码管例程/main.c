/**************************************
  >File Name: ��̬�������ʾ
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 17 ��
***************************************/

#include<reg51.h>
#define GPIO_DIG   P0	//��ѡ
#define GPIO_PLACE P1	//λѡ
#define uchar unsigned char
#define uint unsigned char
	
uchar code DIG_PLACE[8] = {0xfe,0xfd,0xfb,0xf7,
                           0xef,0xdf,0xbf,0x7f};//λѡ����   ���ķ�������
uint code DIG_CODE[17] = {0x3f,0x06,0x5b,0x4f, //0��1��2��3
	                      0x66,0x6d,0x7d,0x07, //4��5��6��7
                          0x7f,0x6f,0x77,0x7c, //8��9��A��B
                          0x39,0x5e,0x79,0x71};//C��D��E��F
uchar DisplayDate[8]=0; //���Ҫ��ʾ��8λ����
void DigDisplay();
void main()
{
	uchar i;
	for(i=0;i<8;i++)
	{
		DisplayDate[i]=DIG_CODE[i];
	}
	while(1)
	{
		DigDisplay();
	}
}

void DigDisplay()
{
	uchar i;
	uint j;
	for(i=0;i<8;i++)
	{
		GPIO_PLACE = DIG_PLACE[i];	 //����λѡ,����Ҫ���������
		GPIO_DIG = DisplayDate[i];   //���Ͷ��룬��ʾ��Ӧ������
		j = 10;						 //ɨ����ʱ���趨
		while(j--);	
		GPIO_DIG = 0x00;             //����
	}
}