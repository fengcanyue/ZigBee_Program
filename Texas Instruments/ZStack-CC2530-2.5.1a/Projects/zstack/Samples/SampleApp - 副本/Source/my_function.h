#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H
#define DeviceNum 3
#define IgnoreEvent        '0'
#define IgnoreEvent_Cancel '1'  
#define NvEvent            '2'
/*************************变量声明*************************************/
uint16 f;
uint8 conversion[DeviceNum]={'0','1','2'};
uint8 State_data[DeviceNum]={'0','0','0'};//林山定义了一个状态数组，用于记录各个端点的在线状态，目前先假设有3个端点。
uint8 Absence_times[3];
uint8 IgnoreDevice[DeviceNum]={'0','0','0'};
/**************************函数声明************************************/
void Absence_check(uint8 x);//狗清定义的节点缺席检测函数,有x次签到不到就报警。
void BT2Z_transmit(uint8 *group);//狗清定义的蓝牙到zigbee信息搬运函数
void NeverDect(uint8 DeviceID);//这个函数的功能就是不再检查某个设备在不在线，也就是忽略，也就是不检查反正一样 狗清定义的
void SerialCMD(mtOSALSerialData_t *cmdMsg);//
/*Nv函数*/
extern uint8 osal_nv_item_init( uint16 id, uint16 len, void *buf );//是我们在使用Nv时，初始化某个条目，如osal_nv_item_init(TEST_NV,1,NULL);
extern uint8 osal_nv_read( uint16 id, uint16 offset, uint16 len, void *buf );//Nv读取某一个条目的数据，将其存储在buf中
extern  uint8 osal_nv_write( uint16 id, uint16 offset, uint16 len, void *buf );//创建一个Nv条目（如果条目的ID不存在，如果存在，就将原来的item数据部分覆盖），并向其中写入数据
extern  uint16 osal_nv_item_len( uint16 id );//是查询某一个item的数据长度。

#endif