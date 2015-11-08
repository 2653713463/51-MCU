/**************************************
  > File Name: LCD1602ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 21 ��
***************************************/
#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

uchar ENCHAR_PuZh[16]=" Pechin Science ";
void main()
{
	uchar i;
	LCD1602_Init();
	while(1)
	{
		LCD1602_WriteCom(0x80);
		for(i=0;i<16;i++)
		{
			LCD1602_WriteData(ENCHAR_PuZh[i]);
		}	
	}
}

/*lcd.h�ļ�*/
#ifndef __LCD_H_
#define __LCD_H_
/**********************************
��ʹ�õ���4λ���ݴ����ʱ����
**********************************/
#define LCD1602_4PINS

#include<reg51.h>
#define uint unsigned int 
#define uchar unsigned char
/**********************************
PIN�ڶ���
**********************************/
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

void Delay1us(uint a);            //��51��Ƭ��12MHZʱ���µ���ʱ����
void LCD1602_WriteCom(uchar com); //LCD1602д��8λ�����Ӻ���	
void LCD1602_WriteData(uchar dat);//LCD1602д��8λ�����Ӻ���		
void LCD1602_Init();              //LCD1602��ʼ���ӳ���					  
#endif

/*LCD.C�ļ�*/
//#include"lcd.h"

/*******************************************************************************
* ������         : Delay1us
* ��������		 : ��ʱ��������ʱ1us
* ����           : a
* ���         	 : ��
*******************************************************************************/

void Delay1us(uint a)
{
	uint b,c;
	for(c=a;c>0;c--)
		for(b=110;b>0;b--);
}
/*******************************************************************************
* ������         : LCD1602_WriteCom
* ��������		 : ��LCDд��һ���ֽڵ�����
* ����           : com
* ���         	 : ��
*******************************************************************************/
#ifndef 	LCD1602_4PINS	     //��û�ж������LCD1602_4PINSʱ
void LCD1602_WriteCom(uchar com) //д������
{
	LCD1602_E=0;
	LCD1602_RS=0;
	LCD1602_RW=0;
	LCD1602_DATAPINS=com;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
}
#else 
void LCD1602_WriteCom(uchar com) //д������
{
	LCD1602_E=0;
	LCD1602_RS=0;
	LCD1602_RW=0;
	LCD1602_DATAPINS=com;	//����4λ�Ľ����ǽӵ�P0�ڵĸ���λ�����Դ��͸���λ���ø�
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
	Delay1us(10);
	LCD1602_DATAPINS=com<<4;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
}
#endif
/*******************************************************************************
* ������         : LCD1602_WriteData
* ��������		 : ��LCDд��һ���ֽڵ�����
* ����           : dat
* ���         	 : ��
*******************************************************************************/		   
#ifndef 	LCD1602_4PINS		   
void LCD1602_WriteData(uchar dat) //д������
{
	LCD1602_E=0;
	LCD1602_RS=1;
	LCD1602_RW=0;
	LCD1602_DATAPINS=dat;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
}
#else
void LCD1602_WriteData(uchar dat) //д������
{
	LCD1602_E=0;
	LCD1602_RS=1;
	LCD1602_RW=0;
	LCD1602_DATAPINS=dat;	//����4λ�Ľ����ǽӵ�P0�ڵĸ���λ�����Դ��͸���λ���ø�
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
	LCD1602_DATAPINS=dat<<4;
	Delay1us(10);
	LCD1602_E=1;
	Delay1us(10);
	LCD1602_E=0;
}
#endif
/*******************************************************************************
* ������         : LCD1602_Init()
* ��������		 : ��ʼ��LCD��
* ����           : ��
* ���         	 : ��
*******************************************************************************/		   
#ifndef		LCD1602_4PINS
void LCD1602_Init()			 //LCD��ʼ���ӳ���
{
 	LCD1602_WriteCom(0x38);  //����ʾ
	LCD1602_WriteCom(0x0c);  //����ʾ����ʾ���
	LCD1602_WriteCom(0x06);  //дһ��ָ���1
	LCD1602_WriteCom(0x01);  //����
	LCD1602_WriteCom(0x80);  //��������ָ�����
}
#else
void LCD1602_Init()			 //LCD��ʼ���ӳ���
{
	LCD1602_WriteCom(0x32);	 //��8λ����תΪ4λ����
	LCD1602_WriteCom(0x28);	 //����λ���µĳ�ʼ��
	LCD1602_WriteCom(0x0c);  //����ʾ����ʾ���
	LCD1602_WriteCom(0x06);  //дһ��ָ���1
	LCD1602_WriteCom(0x01);  //����
	LCD1602_WriteCom(0x80);  //��������ָ�����
}
#endif

