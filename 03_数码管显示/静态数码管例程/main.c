/***********************************************
   > File Name: ��̬�����
   > Author: pengshp
   > Mail: pengshp3@outlook.com
   > Date: 2015�� 7 �� 17 ��
*************************************************/

#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define GPIO_DIG P0
uchar code DIG_CODE[10]={0x3f,0x06,0x5b,0x4f,0x66,
                         0x6d,0x7d,0x07,0x7f,0x6f};//��ʾ0-9��ֵ
void Delay(uchar);
void main()
{
	uchar i;
	while(1)
	{
		for(i=0;i<10;i++)           //������ʾ0-9
		{
			GPIO_DIG=~DIG_CODE[i];
			Delay(800);  			//��ʱ����
		}
    }
}
void Delay(uchar x)
{
	uint a,b;
	for(a=x;a>0;a--)
	{
		for(b=2000;b>0;b--)
		{
		}
	}
}