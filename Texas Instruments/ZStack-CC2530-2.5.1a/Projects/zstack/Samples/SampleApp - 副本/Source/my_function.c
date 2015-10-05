/*串口*/
#include "MT_UART.h"
#include "MT.h"
#include "my_function.h"
#include <stdlib.h>
/**************************变量声明************************************/
//extern uint8 Absence_times[3];//={0,0,0};
//uint8 State_data[3]={'0','0','0'};//林山定义了一个状态数组，用于记录各个端点的在线状态，目前先假设有3个端点。
/**************************函数声明************************************/
//void Absence_check(uint8 x);//狗清定义的节点缺席检测函数,有x次签到不到就报警。
//void BT2Z_transmit(uint8 *group);//狗清定义的蓝牙到zigbee信息搬运函数
/**************************函数描述************************************/
void Absence_check(uint8 x)
{
  uint8 i;
  //char string[3];
  for(i=0;i<3;i++)
  {
    if (State_data[i]=='0')
    {
       Absence_times[i]++;
    }
    if (State_data[i]=='1')
    {
      Absence_times[i]=0;
      State_data[i]='0';
    }
    if((Absence_times[i]>=x) && (IgnoreDevice[i]=='0'))
    {
      //itoa(i,string,10);
      HalUARTWrite(0, "device ",7);
      HalUARTWrite(0,&conversion[i],1);
      HalUARTWrite(0, " is offline\n",12);//warning!!
    }
  }
}

void NeverDect(uint8 DeviceID)
{
  IgnoreDevice[DeviceID]='1';
}
void SerialCMD(mtOSALSerialData_t *cmdMsg)
{
  switch(cmdMsg->msg[0])
  {
    case IgnoreEvent:
      HalUARTWrite(0,"get event1\n",12);
      NeverDect((cmdMsg->msg[2])-48);//这个数组的下标应该改成int型。
      break;
    case IgnoreEvent_Cancel:
      HalUARTWrite(0,"get event2\n",12);
      IgnoreDevice[(cmdMsg->msg[2])-48]='0';
    case NvEvent:
      {
      uint8 val=cmdMsg->msg[2]-48;
      uint8 value_read;
      osal_nv_item_init( 0x0202, 1, NULL );
      osal_nv_write( 0x0202, 0, 1, &val);
      osal_nv_read( 0x0202, 0, 1,&value_read  );
      value_read+=48;
      HalUARTWrite(0,&(value_read),1);
      }
  }
  
}
