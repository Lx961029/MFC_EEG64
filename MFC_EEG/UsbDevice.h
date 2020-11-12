#pragma once
#include"CyAPI.h"
#include"cyioctl.h"
class UsbDevice
{
public:
	UsbDevice(void);
	~UsbDevice(void);
	bool IsUSBopen();
	bool OpenDevice(int vID,int pID);      //��USB�豸
	void CloseDevice();
	bool WriteParam(int ReqCode);

	void ReadParam(int ReqCode);

	bool ReadBulkData(PUCHAR InData,long Lenth);
	PUCHAR ReadImpedance(int ReqCode1,int ReqCode2);
private:
     bool USBOpen;//��ʾUSB���򿪳ɹ���񣬳ɹ����˲�����ȷ�ر�USB
     HANDLE hDevice;//����һ���������ʵ��һ��void*��ָ��
	 CCyUSBDevice *USBDevice;		//USB�豸
	 CCyControlEndPoint  *ept;			//USB���ƶ˵�
	 CCyUSBEndPoint *InEndpt;//USB�˵� 
	 PUCHAR ImpedanceBuf;
};

