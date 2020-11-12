#include "stdafx.h"

#include "afxdialogex.h"

#include "CyAPI.h"
#include "cyioctl.h"
#include "USB.h"

HANDLE hDevice = NULL;
CCyUSBDevice *USBDevice = new CCyUSBDevice(hDevice);		//USB设备
CCyControlEndPoint  *ept;			//USB控制端点
CCyUSBEndPoint *InEndpt;//USB端点 


/**********************************************************
		函数名称：OpenDevice
		功能：打开指定pID和vID号的设备
		返回值：成功返回true，失败返回false
**********************************************************/
bool OpenDevice(int vID,int pID)
{  
	int devices = USBDevice->DeviceCount();
	int vID_1,pID_1;
	int d = 0;
	
	while(d<devices)//以前的do-while语句的BUG在于，就算没有USB，也会去打开一次，明显是不对的啥
	{ 
		  USBDevice->Open(d);
          vID_1 = USBDevice->VendorID;
	      pID_1 = USBDevice->ProductID;
		  if( (vID_1==vID) && (pID_1==pID) )
			  return true;
		  d++;
	}
	return false;//李鹏霄改
}

/**********************************************************
		函数名称：CloseDevice
		功能：关闭USB设备
**********************************************************/
void CloseDevice()
{
	USBDevice->Close();		//关闭USB设备
}


/**********************************************************
		函数名称：WriteParam
		功能：该函数用于向放大器写入参数。
**********************************************************/
bool WriteParam(int ReqCode, int Value, int Index, PUCHAR buf, LONG buflen)
{ 
	//UCHAR buf[2];
	//long bufflen = 2;
	//buf[0] = (UCHAR)ReqCode;
	//buf[1] = 1;
	ept = USBDevice->ControlEndPt;	
	ept->Target  = TGT_DEVICE; 
    ept->ReqType = REQ_VENDOR; 
    ept->ReqCode = ReqCode;   
    ept->Value   = Value;  
    ept->Index   = Index; 
//	ept->Write(buf, buflen);
	if (ept->Write(buf, buflen))
		return true;
	else
		return false;
}
/**********************************************************
函数名称：ReadData
功能：该函数用于读取放大器数据
**********************************************************/
bool ReadData(PUCHAR InData, long Inlen)
{
	return InEndpt->XferData(InData, Inlen);
}


/**********************************************************
函数名称：ReadImpedance
功能：该函数用于读取放大器阻抗
**********************************************************/
bool ReadImpedance(PUCHAR buf, LONG buflen) {
	if (ept->Read(buf, buflen))
		return true;
	else
		return false;
}