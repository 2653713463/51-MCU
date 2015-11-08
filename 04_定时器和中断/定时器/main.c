/**************************************
  > File Name: ��ʱ��ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 19 ��
***************************************/
#include<reg51.h>
#include<intrins.h>
#define GPIO_LED P2
unsigned char Time;

void main()
{
	Time=0;
	GPIO_LED=0x01;   //�����һ������
	TMOD = 0x01;     //ѡ����ģʽ1
	TH0 = 0x3C;	     //���ó�ʼֵ,��ʱ50ms
	TL0 = 0xB0; 
	TR0 = 1;		 //������ʱ��0
	while(1)
	{
		if(TF0==1)                          //�ж�T0�Ƿ����
		{
			TF0=0;                          //T0����������жϱ�־
			TH0 = 0x3C;
            TL0 = 0xB0; 
			Time++;                         //����ֵ�Լ�1
			if(Time==20)                    //20*50ms=1s
			{
				GPIO_LED=_crol_(GPIO_LED,1);//����һλ
				Time=0;                     //������0
			}
		 }
	 }
 }