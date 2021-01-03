#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "OBJ.h"

void Serial_Init();
void send_Byte(uchar byte);
void send_String(uchar *str);
uchar getRand_SBUF();



#endif // !__SERAL_H__