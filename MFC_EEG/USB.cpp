#include "stdafx.h"

#include "afxdialogex.h"

#include "CyAPI.h"
#include "cyioctl.h"
#include "USB.h"

HANDLE hDevice = NULL;
CCyUSBDevice *USBDevice = new CCyUSBDevice(hDevice);		//USB�豸
CCyControlEndPoint  *ept;			//USB���ƶ˵�
CCyUSBEndPoint *InEndpt;//USB�˵� 


/**********************************************************
		�������ƣ�OpenDevice
		���ܣ���ָ��pID��vID�ŵ��豸
		����ֵ���ɹ�����true��ʧ�ܷ���false
**********************************************************/
bool OpenDevice(int vID,int pID)
{  
	int devices = USBDevice->DeviceCount();
	int vID_1,pID_1;
	int d = 0;
	
	while(d<devices)//��ǰ��do-while����BUG���ڣ�����û��USB��Ҳ��ȥ��һ�Σ������ǲ��Ե�ɶ
	{ 
		  USBDevice->Open(d);
          vID_1 = USBDevice->VendorID;
	      pID_1 = USBDevice->ProductID;
		  if( (vID_1==vID) && (pID_1==pID) )
			  return true;
		  d++;
	}
	return false;//��������
}

/**********************************************************
		�������ƣ�CloseDevice
		���ܣ��ر�USB�豸
**********************************************************/
void CloseDevice()
{
	USBDevice->Close();		//�ر�USB�豸
}


/**********************************************************
		�������ƣ�WriteParam
		���ܣ��ú���������Ŵ���д�������
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
�������ƣ�ReadData
���ܣ��ú������ڶ�ȡ�Ŵ�������
**********************************************************/
bool ReadData(PUCHAR InData, long Inlen)
{
	return InEndpt->XferData(InData, Inlen);
}


/**********************************************************
�������ƣ�ReadImpedance
���ܣ��ú������ڶ�ȡ�Ŵ����迹
**********************************************************/
bool ReadImpedance(PUCHAR buf, LONG buflen) {
	if (ept->Read(buf, buflen))
		return true;
	else
		return false;
}