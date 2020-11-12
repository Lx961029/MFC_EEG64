#include "StdAfx.h"
#include "UsbDevice.h"


UsbDevice::UsbDevice(void)
{
	 USBOpen=false;//��ʾUSB���򿪳ɹ���񣬳ɹ����˲�����ȷ�ر�USB
     hDevice=NULL;//����һ���������ʵ��һ��void*��ָ��
	 USBDevice=new CCyUSBDevice(hDevice);					//USB�豸
	 ept=USBDevice->ControlEndPt;							//USB���ƶ˵�
	 InEndpt = (CCyUSBEndPoint *)USBDevice->BulkInEndPt;	//USB�˵�
	 ImpedanceBuf=new UCHAR[150];  
	 for(int i=0;i<150;i++)  //����������迹ֵ
		 ImpedanceBuf[i]=0;
}


UsbDevice::~UsbDevice(void)
{
	delete [] ImpedanceBuf;
}

bool UsbDevice::OpenDevice(int vID,int pID)    //��USB�豸
{
	int devices = USBDevice->DeviceCount();
	int vID_1,pID_1;
	int d = 0;
	
	while(d<devices)//��ǰ��do-while����BUG���ڣ�����û��USB��Ҳ��ȥ��һ�Σ������ǲ��Ե�ɶ
	{ 
		  USBDevice->Open(d);
          vID_1 = USBDevice->VendorID;
	      pID_1 = USBDevice->ProductID;
		  if ((vID_1 == vID) && (pID_1 == pID)){
			  USBOpen = true;
			  return true;
		  }  
		  d++;
	}
	return false;//��������
}
	
void UsbDevice:: CloseDevice()
{
	USBDevice->Close();		//�ر�USB�豸
}

bool UsbDevice::WriteParam(int ReqCode)
{	
	UCHAR buf[64];
	buf[0] = (UCHAR)ReqCode;
	buf[1] = 0x01;
	LONG buflen = 2;
	ept->Target  = TGT_DEVICE; 
    ept->ReqType = REQ_VENDOR; 
    ept->ReqCode = ReqCode;   
    ept->Value   = 0;  
    ept->Index   = 1; 
    ept->Write(buf,buflen); 
	
	return true;
}

void UsbDevice::ReadParam(int ReqCode)
{
	UCHAR buf[64];
	buf[0] = (UCHAR)ReqCode;
	buf[1] = 0x01;
	LONG buflen = 2;
	ept->Target  = TGT_DEVICE; 
    ept->ReqType = REQ_VENDOR; 
	ept->Direction = DIR_FROM_DEVICE;
    ept->ReqCode = ReqCode;   
    ept->Value   = 0;  
    ept->Index   = 1; 	    
   // ept->Read(buf,buflen); 
	ept->XferData(buf, buflen);
}

bool UsbDevice::ReadBulkData(PUCHAR InData,long Length) //��1K�����ݶ���InData�У�����1
{
	InEndpt->TimeOut = 15000;                           //��ʱΪ15�룬����0�������forever
	if(InEndpt->XferData(InData , Length))
		return true;
	else
		return false;
}
PUCHAR UsbDevice::ReadImpedance(int ReqCode1,int ReqCode2)  //�������ζ�ȡ�迹����ֵ
{
	long len=64;
	ept->Target  = TGT_DEVICE; 
    ept->ReqType = REQ_VENDOR; 
	ept->Direction = DIR_FROM_DEVICE;
    ept->ReqCode = ReqCode1;   
    ept->Value   = 0x1;  
    ept->Index   = 0; 	    
   // ept->Read(buf,buflen); 
	ept->XferData(ImpedanceBuf,len);
	for(long i=0;i<100000;i++);

	ept->ReqCode = ReqCode2;   
    ept->Value   = 0x1;  
    ept->Index   = 0; 	    
   // ept->Read(buf,buflen); 
	ept->XferData(ImpedanceBuf+len,len);

	return ImpedanceBuf;

}
bool UsbDevice::IsUSBopen()
{
	return USBOpen;
}