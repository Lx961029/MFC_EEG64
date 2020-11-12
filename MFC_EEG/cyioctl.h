/*

Copyright (c) 2003  Cypress Semiconductor Corporation

Module Name:

  CyIoclt.h

Additional Notes:

  THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
  PURPOSE.

*/
#ifndef __IOCTL_H__
#define __IOCTL_H__

#ifndef CTL_CODE
 // #include <devioctl.h>
#endif

#ifndef BM_REQUEST_TYPE
// #include <usb100.h>
#endif

#include <PSHPACK1.H>

#define DIR_HOST_TO_DEVICE 0
#define DIR_DEVICE_TO_HOST 1

#define BYTE_PATTERN          0x00
#define GET_ERROR_COUNT	      0x01
#define RESET_ERROR_COUNT	  0x02
#define TRANSMIT_DATA	      0x03
#define GET_SET_RESPONSE	  0x04
#define SEND_BYTES	          0x05
#define SET_LOOPBACK_ENDPOINT 0x06

#define DO_LOOPBACK(streamObject) (streamObject->LoopbackPipeInfo != NULL)

typedef struct _WORD_SPLIT 
{
    UCHAR lowByte;
    UCHAR hiByte;
} WORD_SPLIT, *PWORD_SPLIT;

typedef struct _BM_REQ_TYPE 
{
    UCHAR   Recipient:2;
    UCHAR   Reserved:3;
    UCHAR   Type:2;
    UCHAR   Direction:1;
} BM_REQ_TYPE, *PBM_REQ_TYPE;

typedef struct _SETUP_PACKET 
{
    
    union 
	{
        BM_REQ_TYPE bmReqType;
        UCHAR bmRequest;
    };

    UCHAR bRequest;
    
    union 
	{
        WORD_SPLIT wVal;
        USHORT wValue;
    };
    
    union 
	{
        WORD_SPLIT wIndx;
        USHORT wIndex;
    };
    
    union 
	{
        WORD_SPLIT wLen;
        USHORT wLength;
    };

	ULONG ulTimeOut;

} SETUP_PACKET, *PSETUP_PACKET;

typedef struct _ISO_PACKET_INFO 
{
    ULONG Status;
    ULONG Length;
} ISO_PACKET_INFO, *PISO_PACKET_INFO;


typedef struct _SINGLE_TRANSFER 
{
    SETUP_PACKET SetupPacket;
    IN BOOLEAN WaitForever;
    UCHAR ucEndpointAddress;
    ULONG NtStatus;
    ULONG UsbdStatus;
    ULONG IsoPacketOffset;
    ULONG IsoPacketLength;
    ULONG BufferOffset;
    ULONG BufferLength;
} SINGLE_TRANSFER, *PSINGLE_TRANSFER;

typedef struct _SET_TRANSFER_SIZE_INFO 
{
	UCHAR EndpointAddress;
	ULONG TransferSize;
} SET_TRANSFER_SIZE_INFO, *PSET_TRANSFER_SIZE_INFO;


//
// Macro to extract function out of the device io control code
//
#ifdef WIN_98_DDK
#define DEVICE_TYPE_FROM_CTL_CODE(ctrlCode)     (((ULONG)(ctrlCode & 0xffff0000)) >> 16)
#endif
#define FUNCTION_FROM_CTL_CODE(ctrlCode)     (((ULONG)(ctrlCode & 0x00003FFC)) >> 2)
#define ACCESS_FROM_CTL_CODE(ctrlCode)       (((ULONG)(ctrlCode & 0x000C0000)) >> 14)
#define METHOD_FROM_CTL_CODE(ctrlCode)       (((ULONG)(ctrlCode & 0x00000003)))


#define IOCTL_ADAPT_INDEX 0x0000

// Get the driver version
#define IOCTL_ADAPT_GET_DRIVER_VERSION         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get the current USBDI version
#define IOCTL_ADAPT_GET_USBDI_VERSION         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+1, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get the current device alt interface settings from driver
#define IOCTL_ADAPT_GET_ALT_INTERFACE_SETTING CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+2, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Set the device interface and alt interface setting
#define IOCTL_ADAPT_SELECT_INTERFACE          CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+3, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get device address from driver
#define IOCTL_ADAPT_GET_ADDRESS               CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+4, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get number of endpoints for current interface and alt interface setting from driver
#define IOCTL_ADAPT_GET_NUMBER_ENDPOINTS      CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+5, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get the current device power state
#define IOCTL_ADAPT_GET_DEVICE_POWER_STATE    CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+6,   METHOD_BUFFERED, FILE_ANY_ACCESS)

// Set the device power state
#define IOCTL_ADAPT_SET_DEVICE_POWER_STATE    CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+7,   METHOD_BUFFERED, FILE_ANY_ACCESS)

// Send a raw packet to endpoint 0
#define IOCTL_ADAPT_SEND_EP0_CONTROL_TRANSFER CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+8, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Send/receive data to/from nonep0
#define IOCTL_ADAPT_SEND_NON_EP0_TRANSFER     CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+9, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Simulate a disconnect/reconnect
#define IOCTL_ADAPT_CYCLE_PORT                CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+10, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Reset the pipe
#define IOCTL_ADAPT_RESET_PIPE                CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+11, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Reset the device
#define IOCTL_ADAPT_RESET_PARENT_PORT         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+12, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get the current transfer size of an endpoint (in number of bytes)
#define IOCTL_ADAPT_GET_TRANSFER_SIZE         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+13, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Set the transfer size of an endpoint (in number of bytes)
#define IOCTL_ADAPT_SET_TRANSFER_SIZE         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+14, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Return the name of the device
#define IOCTL_ADAPT_GET_DEVICE_NAME    CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+15, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Return the "Friendly Name" of the device
#define IOCTL_ADAPT_GET_FRIENDLY_NAME         CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+16, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Abort all outstanding transfers on the pipe
#define IOCTL_ADAPT_ABORT_PIPE                CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_ADAPT_INDEX+17, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define NUMBER_OF_ADAPT_IOCTLS 18 // Last IOCTL_ADAPT_INDEX + 1


// Addition DVK Build IOCTLs
#ifdef DVK_BUILD

#define MAX_PACKET_DATA_SIZE 4096

typedef struct _START_STREAM_INFO {
    ULONG Flags;   // for loopback, check errors, direction out/in
    UCHAR NumberOfBuffers;
    UCHAR DeviceAddress;
    UCHAR EpAddress;
    UCHAR LoopbackAddress;
} START_STREAM_INFO, *PSTART_STREAM_INFO;

typedef struct _ERROR_STATISTICS {
    ULONG BadPacketErrors;
    ULONG TransmissionErrors;
    ULONG LoopbackTransmissionErrors;
} ERROR_STATISTICS, *PERROR_STATISTICS;

typedef struct _STATISTICS_INFO {
    ERROR_STATISTICS ErrorInfo;
    ULONG PacketsParsed;
    ULONG BytesTransferred;
	UCHAR PacketData[MAX_PACKET_DATA_SIZE];
	ULONG PacketDataLength;
} STATISTICS_INFO, *PSTATISTICS_INFO;


#define IOCTL_DVK_INDEX (IOCTL_ADAPT_INDEX + NUMBER_OF_ADAPT_IOCTLS)

// Start streaming on a block of endpoints
#define IOCTL_DVK_START_STREAMING_BLOCK     CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_DVK_INDEX, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Stop streaming on a block of endpoints
#define IOCTL_DVK_STOP_STREAMING_BLOCK      CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_DVK_INDEX+1, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Get statistics on a block of endpoints
#define IOCTL_DVK_GET_STATISTICS            CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_DVK_INDEX+2, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Clear statistics on a block of endpoints
#define IOCTL_DVK_CLEAR_STATISTICS          CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_DVK_INDEX+3, METHOD_BUFFERED, FILE_ANY_ACCESS)

// Clear statistics on a block of endpoints
#define IOCTL_DVK_GET_PACKET_DATA           CTL_CODE(FILE_DEVICE_UNKNOWN, IOCTL_DVK_INDEX+4, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define NUMBER_OF_DVK_IOCTLS 5

#endif // BUILD_DVK

#include <POPPACK.H>

#endif // __IOCTL_H__
