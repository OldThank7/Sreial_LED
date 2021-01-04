#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "OBJ.h"



void Serial_Init();
void send_String(uchar *str);
void send_Byte(uchar byte);
uchar getRand_SBUF();



#endif // !__SERAL_H__