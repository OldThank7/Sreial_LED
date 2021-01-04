#include "Serial.h"
#include "LED.h"

uchar temp;
uchar *LED1ON = "LED 1:ON\r\n";
uchar *LED1OFF = "LED 1:OFF\r\n";
uchar *LED2ON = "LED 2:ON\r\n";
uchar *LED2OFF = "LED 2:OFF\r\n";
uchar *LED3ON = "LED 3:ON\r\n";
uchar *LED3OFF = "LED 3:OFF\r\n";
uchar *LED4ON = "LED 4:ON\r\n";
uchar *LED4OFF = "LED 4:OFF\r\n";
uchar *LED5ON = "LED 5:ON\r\n";
uchar *LED5OFF = "LED 5:OFF\r\n";
uchar *LED6ON = "LED 6:ON\r\n";
uchar *LED6OFF = "LED 6:OFF\r\n";
uchar *LED7ON = "LED 7:ON\r\n";
uchar *LED7OFF = "LED 7:OFF\r\n";
uchar *LED8ON = "LED 8:ON\r\n";
uchar *LED8OFF = "LED 8:OFF\r\n";

uchar code SMG_duan[] = {
0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,
0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
// uchar code SMG_wei[] = {0xFE,0xFD,0xFB,0xF7};
uchar code SMG_wei[] = {0xEF,0xDF,0xBF,0x7F};

uchar SMG = 0;

void main()
{
    Serial_Init();
    while(1)
    {
        DigDisplay(SMG);
        switch (getRand_SBUF())
        {
        case '1':
            LED1 = ~LED1;
            SMG = 1;
            if (LED1)
            {
                SMG = 0;
                send_String(LED1OFF);
            }
            send_String(LED1ON);
            break;
        case '2':
            LED2 = ~LED2;
            SMG = 2;
            if (LED2)
            {
                send_String(LED2OFF);
                SMG = 0;
            }
            send_String(LED2ON);
            break;
        case '3':
            LED3 = ~LED3;
            SMG = 3;
            if (LED3)
            {
                send_String(LED3OFF);
                SMG = 0;
            }
            send_String(LED3ON);
            break;
        case '4':
            LED4 = ~LED4;
            
            SMG = 4;
            if (LED4)
            {
                send_String(LED4OFF);
                SMG = 0;
            }
            send_String(LED4ON);
            break;
        case '5':
            LED5 = ~LED5;
            
            SMG = 5;
            if (LED5)
            {
                send_String(LED5OFF);
                SMG = 0;
            }
            send_String(LED5ON);
            break;
        case '6':
            LED6 = ~LED6;
            
            SMG = 6;
            if (LED6)
            {
                send_String(LED6OFF);
                SMG = 0;
            }
            send_String(LED6ON);
            break;
        case '7':
            LED7 = ~LED7;
            SMG = 7;
            if (LED7)
            {
                send_String(LED7OFF);
                SMG = 0;
            }
            send_String(LED7ON);
            
            break;
        case '8':
            LED8 = ~LED8;
            SMG = 0;
            if (LED8)
            {
                send_String(LED8OFF);
                SMG = 0;
            }
            send_String(LED8ON);
            break;
        }
    }
}

void DigDisplay(uchar num)
{
	unsigned char i;
	unsigned int j;
	int gewei,shiwei,baiwei,qianwei;
	
	gewei = num % 10;
	shiwei = num / 10 % 10;
	baiwei = num / 100 % 10;
	qianwei = num / 1000;
	
	for(i=0; i<4; i++)
	{
		weixuan = SMG_wei[i];
		duanxuan = 0xff;
		if(i == 3)
		{
			duanxuan = SMG_duan[gewei];
		}
		if(i == 2)
		{
			duanxuan = SMG_duan[shiwei];
        }
		if(i == 1)
		{
			duanxuan = SMG_duan[baiwei];
        }
		if(i == 0)
		{
			duanxuan = SMG_duan[qianwei];
		}
		j=10;
		while(j--);
		duanxuan=0xff;
	}
}