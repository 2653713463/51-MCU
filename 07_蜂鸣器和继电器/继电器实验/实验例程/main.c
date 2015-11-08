/**************************************
  > File Name: �̵���ʵ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 25 ��
***************************************/
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

sbit RELAY=P1^4;              //�̵���λ����
sbit K1=P0^0;                 //����K1λ����

void Delay(uint ms)
{
	uchar i;
	while(ms--)
	{
		for(i=120;i>0;i--);
	}
}
void main()
{
	RELAY=0;                  //�̵�������
	K1=1;
	while(1)
	{
		if(!K1)
		{
			Delay(50);
			if(K1==0)
			{
				while(!K1);   //�ȴ������ͷ�
				RELAY=~RELAY; //�̵���ȡ��
			}
		}
	}
}