/**************************************
  > File Name: ������ˮ��
  > Author: pengshp
  > Mail: pengshp3@outlook.com
  > Date: 2015�� 7 �� 13 ��
***************************************/
#include<reg51.h>

void delay500ms(void)          //��� 0us
{
    unsigned char a,b,c;
    for(c=23;c>0;c--)
        for(b=152;b>0;b--)
            for(a=70;a>0;a--);
}

void main()
{
	unsigned char cnt=0;
	P2=0x00;
	while(1)
	{	
		for(;cnt<8;cnt++)
		{
			P2=(0x01<<cnt);//0000 0001����
			delay500ms();
		}
		cnt=0;
		for(;cnt<8;cnt++)
		{
			P2=(0x80>>cnt);//1000 0000����
			delay500ms();
		}
		cnt=0;	
	}	
}