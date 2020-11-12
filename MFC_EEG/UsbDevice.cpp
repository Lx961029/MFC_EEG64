#include "StdAfx.h"
#include "UsbDevice.h"


UsbDevice::UsbDevice(void)
{
	 USBOpen=false;//表示USB被打开成功与否，成功打开了才能正确关闭USB
     hDevice=NULL;//定义一个句柄，其实是一个void*的指针
	 USBDevice=new CCyUSBDevice(hDevice);					//USB设备
	 ept=USBDevice->ControlEndPt;							//USB控制端点
	 InEndpt = (CCyUSBEndPoint *)USBDevice->BulkInEndPt;	//USB端点
	 ImpedanceBuf=new UCHAR[150];  
	 for(int i=0;i<150;i++)  //保存读到的阻抗值
		 ImpedanceBuf[i]=0;
}


UsbDevice::~UsbDevice(void)
{
	delete [] ImpedanceBuf;
}

bool UsbDevice::OpenDevice(int vID,int pID)    //打开USB设备
{
	int devices = USBDevice->DeviceCount();
	int vID_1,pID_1;
	int d = 0;
	
	while(d<devices)//以前的do-while语句的BUG在于，就算没有USB，也会去打开一次，明显是不对的啥
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
	return false;//李鹏霄改
}
	
void UsbDevice:: CloseDevice()
{
	USBDevice->Close();		//关闭USB设备
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

bool UsbDevice::ReadBulkData(PUCHAR InData,long Length) //将1K的数据读到InData中，返回1
{
	InEndpt->TimeOut = 15000;                           //延时为15秒，设置0则可以是forever
	if(InEndpt->XferData(InData , Length))
		return true;
	else
		return false;
}
PUCHAR UsbDevice::ReadImpedance(int ReqCode1,int ReqCode2)  //进行两次读取阻抗检测的值
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