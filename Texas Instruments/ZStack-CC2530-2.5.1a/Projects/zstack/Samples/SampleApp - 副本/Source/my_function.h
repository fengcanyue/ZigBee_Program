#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H
#define DeviceNum 3
#define IgnoreEvent        '0'
#define IgnoreEvent_Cancel '1'  
#define NvEvent            '2'
/*************************��������*************************************/
uint16 f;
uint8 conversion[DeviceNum]={'0','1','2'};
uint8 State_data[DeviceNum]={'0','0','0'};//��ɽ������һ��״̬���飬���ڼ�¼�����˵������״̬��Ŀǰ�ȼ�����3���˵㡣
uint8 Absence_times[3];
uint8 IgnoreDevice[DeviceNum]={'0','0','0'};
/**************************��������************************************/
void Absence_check(uint8 x);//���嶨��Ľڵ�ȱϯ��⺯��,��x��ǩ�������ͱ�����
void BT2Z_transmit(uint8 *group);//���嶨���������zigbee��Ϣ���˺���
void NeverDect(uint8 DeviceID);//��������Ĺ��ܾ��ǲ��ټ��ĳ���豸�ڲ����ߣ�Ҳ���Ǻ��ԣ�Ҳ���ǲ���鷴��һ�� ���嶨���
void SerialCMD(mtOSALSerialData_t *cmdMsg);//
/*Nv����*/
extern uint8 osal_nv_item_init( uint16 id, uint16 len, void *buf );//��������ʹ��Nvʱ����ʼ��ĳ����Ŀ����osal_nv_item_init(TEST_NV,1,NULL);
extern uint8 osal_nv_read( uint16 id, uint16 offset, uint16 len, void *buf );//Nv��ȡĳһ����Ŀ�����ݣ�����洢��buf��
extern  uint8 osal_nv_write( uint16 id, uint16 offset, uint16 len, void *buf );//����һ��Nv��Ŀ�������Ŀ��ID�����ڣ�������ڣ��ͽ�ԭ����item���ݲ��ָ��ǣ�����������д������
extern  uint16 osal_nv_item_len( uint16 id );//�ǲ�ѯĳһ��item�����ݳ��ȡ�

#endif