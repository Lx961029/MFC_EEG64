#pragma once
#include"CyAPI.h"
#include"cyioctl.h"
class UsbDevice
{
public:
	UsbDevice(void);
	~UsbDevice(void);
	bool IsUSBopen();
	bool OpenDevice(int vID,int pID);      //打开USB设备
	void CloseDevice();
	bool WriteParam(int ReqCode);

	void ReadParam(int ReqCode);

	bool ReadBulkData(PUCHAR InData,long Lenth);
	PUCHAR ReadImpedance(int ReqCode1,int ReqCode2);
private:
     bool USBOpen;//表示USB被打开成功与否，成功打开了才能正确关闭USB
     HANDLE hDevice;//定义一个句柄，其实是一个void*的指针
	 CCyUSBDevice *USBDevice;		//USB设备
	 CCyControlEndPoint  *ept;			//USB控制端点
	 CCyUSBEndPoint *InEndpt;//USB端点 
	 PUCHAR ImpedanceBuf;
};

