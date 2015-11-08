/**************************************
  > File Name: LCD1602ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 21 ��
***************************************/
#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

sbit RD_RS=P2^6;
sbit LCDE_E=P2^7;
sbit WR_RW=P2^5;

uchar code table1[]="STC-51 MCU";
uchar code table2[]=" pengshp ";

uchar i,j;
uchar num;
void Delay(uint x)
{
	for(i=x;i>0;i--)
	{
		for(j=120;j>0;j--)
		{
		}
	}
}

/*д�����*/
void write_com(uchar com)
{
	RD_RS=0;
	WR_RW=0;
	LCDE_E=0;
	P0=com;
	LCDE_E=1;
	Delay(5);
	LCDE_E=0;
}

/*д���ݺ���*/
void write_data(uchar dat)
{
	RD_RS=1;
	WR_RW=0;
	LCDE_E=0;
	P0=dat;
	LCDE_E=1;
	Delay(5);
	LCDE_E=0;
}

/*��ʼ������*/
void intt()
{
	write_com(0x38);//��ʾģʽ
	write_com(0x08);//��ʾ�ر�
	write_com(0x01);//��ʾ����
	write_com(0x06);//��ʾ����ƶ�
	write_com(0x0F);//��ʾ�����������
}
	
void main()
{
	intt();
	for(num=0;num<10;num++)
    {
		write_data(table1[num]);
		Delay(300);
    }
	write_com(0x80+0x40);
	for(num=0;num<9;num++)
    {
		write_data(table2[num]);
		Delay(10);
    }
	while(1);
}