#include "Serial.h"
#include "LED.h"

uchar rand_SBUF;
uchar flag;

void Serial_Init()
{
    TMOD = 0x20;

    SCON = 0x50;

    PCON = 0x80;
    
    TH1 = 0xFF;
    TL1 = TH1;

    TR1 = 1;//������ʱ��1

    ES = 1;
    EA = 1;
    ET1 = 0;
}

uchar getRand_SBUF()
{
    return rand_SBUF;
}

void Serialinterrput() interrupt 4
{
    if (RI)
    {
        RI = 0;
        rand_SBUF = SBUF;
        flag = 1;
    }   
}

void send_Byte(uchar byte)
{
	//���βη��ͳ�ȥ
	SBUF = byte;
	//�ڴ������ݹ�����  TIΪ0
	//���TI == 1,��ȡ��
	while(!TI);
	TI = 0;
}

void send_string(uchar *str)
{
	if (flag)
	{
		while(*str != '\0')
		{
			SBUF = *str++;
			while (!TI);
			TI = 0;
		}
	}
	flag = 0;
}