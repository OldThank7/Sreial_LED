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
        case '3':
            LED3 = ~LED3;
            if (LED3)
                send_String("LED 3: OFF");
            send_String(str3);
            break;
        case '4':
            LED4 = ~LED4;
            if (LED4)
                send_String("LED 4: OFF");
            send_String(str4);
            break;
        case '5':
            LED5 = ~LED5;
            if (LED5)
                send_String("LED 5: OFF");
            send_String(str5);
            break;
        case '6':
            LED6 = ~LED6;
            if (LED6)
                send_String("LED 6: OFF");
            send_String(str6);
            break;
        case '7':
            LED7 = ~LED7;
            if (LED7)
                send_String("LED 7: OFF");
            send_String(str7);
            break;
        case '8':
            LED8 = ~LED8;
            if (LED8)
                send_String("LED 8: OFF");
            send_String(str8);
            break;
        }
    }
}