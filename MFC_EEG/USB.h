#include "stdafx.h"

#include "CyAPI.h"
#include "cyioctl.h"


extern CCyUSBDevice *USBDevice;		//USB�豸
extern CCyControlEndPoint  *ept;			//USB���ƶ˵�
extern CCyUSBEndPoint *InEndpt;//USB�˵� 
/**********************************************************
		�������ƣ�OpenDevice
		���ܣ���ָ��pID��vID�ŵ��豸
		����ֵ���ɹ�����true��ʧ�ܷ���false
**********************************************************/
bool OpenDevice(int vID,int pID);

/**********************************************************
		�������ƣ�CloseDevice
		���ܣ��ر�USB�豸
**********************************************************/
void CloseDevice();


/**********************************************************
		�������ƣ�WriteParam
		���ܣ��ú���������Ŵ���д�������
**********************************************************/
bool WriteParam(int ReqCode, int Value, int Index, PUCHAR buf, LONG buflen);

/**********************************************************
		�������ƣ�ReadData
		���ܣ��ú������ڶ�ȡ�Ŵ�������
**********************************************************/
bool ReadData();

/**********************************************************
		�������ƣ�ReadImpedance
		���ܣ��ú������ڶ�ȡ�Ŵ����迹
**********************************************************/
bool ReadImpedance(PUCHAR buf, LONG buflen);


