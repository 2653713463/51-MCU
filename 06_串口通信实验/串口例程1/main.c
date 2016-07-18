/**************************************
  > File Name: ����ͨ��ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 21 ��
***************************************/
#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int

uchar flag,i;
/*���ڳ�ʼ������*/
void init_uart()
{
	SCON=0x50;  //����Ϊ������ʽ1
	TMOD=0x20;  //���ü�����������ʽ2
	PCON=0x80;  //�����ʼӱ�
	TH1=0xF3;   //��������ʼֵ��������Ϊ4800
	TL1=0xF3;
	EA=1;       //�����ж�
	ES=1;       //�򿪽����ж�
	TR1=1;      //�򿪼�����
}

void main()
{
	init_uart();
	while(1)
	{
		if(flag==1)
		{
			ES=0;      //�رմ����ж�
			flag=0;
			SBUF=i;    //���ܵ�������д��SBUF
			while(!TI);//�ж��Ƿ�����
			TI=0;
			ES=1;      //�򿪴����ж�
		 }
	 }
}	

void serial() interrupt 4
{
	RI=0;              //���ܱ�־λ����
	i=SBUF;            //��SBUF������
	flag=1;            //˵�����ܵ�����
}