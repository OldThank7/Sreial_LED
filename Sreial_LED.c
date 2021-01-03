#include "Serial.h"
#include "LED.h"

uchar temp;
uchar *str1 = "LED 1:ON";
uchar *str2 = "LED 2:ON";
uchar *str3 = "LED 3:ON";
uchar *str4 = "LED 4:ON";
uchar *str5 = "LED 5:ON";
uchar *str6 = "LED 6:ON";
uchar *str7 = "LED 7:ON";
uchar *str8 = "LED 8:ON";

void main()
{
    Serial_Init();
    while(1)
    {
        switch (getRand_SBUF())
        {
        case '1':
            LED1 = ~LED1;
            if (LED1)
                send_String("LED 1: OFF");
            send_String(str1);
            break;
        case '2':
            LED2 = ~LED2;
            if (LED2)
                send_String("LED 2: OFF");
            send_String(str2);
            break;
        }
    }
}