/**************************************
  > File Name: �ж�ʵ���շ�����
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2016 �� 3 �� 28 ��
***************************************/
#include <reg51.h>
#include <stdio.h>
#define uchar unsigned char
#define uint unsigned int
	
uint getDate=0;
bit RxTx_Flag=0;
void InitUART(void)
{
    TMOD = 0x20; //���ڹ���ģʽ1
    SCON = 0x50;
    TH1 = 0xFA;  //������9600
    TL1 = TH1;
    PCON = 0x80; //�����ʼӱ�
    EA = 1;      //���ж�
    ES = 1;      //�����ж�
    TR1 = 1;     //��ʱ��1
}

void SendOneByte(unsigned char c)
{
    SBUF = c;
    while(!TI);
    TI = 0;
}

int main()
{
    InitUART();
	while(1)
	{
		if(RxTx_Flag)
		{
			RxTx_Flag=0;
			ES=0;//�����ⲿ�жϣ�������
			TI=1;printf("�����һ��:");while(!TI);TI=0;
			SBUF=getDate;
			while(!TI); //�ȴ����ݷ������
			TI=0;
			TI=1;printf("\n");while(!TI);TI=0;
			TI=1;printf("�Ҹ���һ��ASCII: 0x%x",getDate);while(!TI);TI=0;
			TI=1;printf("\n");while(!TI);TI=0;
			ES=1; //���жϱ�־λ
		}//ֻ�ܷ��ͽ���һ���ֽڵ����ݣ����ֽ����ݻᶪʧ
	}
	return 0;
}

void UARTInterrupt() interrupt 4
{
    if(RI)
    {
        RI = 0;//���ݽ�����ɺ��������
        //add your code here!
		getDate=SBUF;//��ȡ����
		RxTx_Flag=1; //���ձ�־λ
    }
}