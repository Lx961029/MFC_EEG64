#include "stdafx.h"

#include "CyAPI.h"
#include "cyioctl.h"


extern CCyUSBDevice *USBDevice;		//USB设备
extern CCyControlEndPoint  *ept;			//USB控制端点
extern CCyUSBEndPoint *InEndpt;//USB端点 
/**********************************************************
		函数名称：OpenDevice
		功能：打开指定pID和vID号的设备
		返回值：成功返回true，失败返回false
**********************************************************/
bool OpenDevice(int vID,int pID);

/**********************************************************
		函数名称：CloseDevice
		功能：关闭USB设备
**********************************************************/
void CloseDevice();


/**********************************************************
		函数名称：WriteParam
		功能：该函数用于向放大器写入参数。
**********************************************************/
bool WriteParam(int ReqCode, int Value, int Index, PUCHAR buf, LONG buflen);

/**********************************************************
		函数名称：ReadData
		功能：该函数用于读取放大器数据
**********************************************************/
bool ReadData();

/**********************************************************
		函数名称：ReadImpedance
		功能：该函数用于读取放大器阻抗
**********************************************************/
bool ReadImpedance(PUCHAR buf, LONG buflen);



