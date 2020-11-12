
// MFC_EEGDlg.h : 头文件
//

#pragma once
#include"USB.h"
#include<vector>
#include"winbase.h"

#include"Channel17To32.h"
#include"Channel33To48.h"
#include"Channel49To64.h"
#include<queue>

#define USBpid (0x8613l)
#define USBvid (0x04B4l)

//全局变量的定义	
#define POINTONE   0
#define POINTTWO   1
#define POINTFIVE  2
#define POINTTEN   3				//一次绘图使用的点数


#define EMG_ChannelNum 16
#define EEG_ChannelNum 16
#define Model2_EEG_ChannelNum 64
#define Model2_EMG_ChannelNum 32
#define DialogNum  1
#define BufferSize 512
#define ArrSize 16
#define package_time 1 


#define markerValue 65
#define collecttime 1000						//如果采集了一千次就应该标出时间刻度;
//extern bool m_channelstatue[ChannelNum];
extern bool m_channelstatue[EEG_ChannelNum];
extern std::vector<std::vector<int>> RecvieveData;
extern std::queue<int> que[64];               //设置一个队列数组
extern std::queue<double> drawque[64];

extern std::vector<std::vector<int>> EMG_Data;
extern std::vector<std::vector<int>> EEG_Data;

extern std::vector<std::vector<int>> Model2_EEG_Data;
extern std::vector<std::vector<int>> Model2_EMG_Data;


extern double m_pBuffer[64][64];                     //用于画图的数据缓冲
extern double pBufferTemp[64][2];                   //双缓存画图

extern bool PlotDialogflag[3];
extern int m_pointsNumFlag;
extern long y_scale;


// CMFC_EEGDlg 对话框
class CMFC_EEGDlg : public CDialogEx
{
// 构造
public:
	CMFC_EEGDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_EEG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
public:
	bool Acquisitionmode; //采集模式标志位，false为模式一，true为模式二
	bool DrawModel;  //画图标志位，false为脑电，true为肌电
	bool UsbModel;  //Usb传输
	bool SelModel;  //串口传输

	bool DisInOneDlg;
	int m_CollectTimes;
	int m_TotalTime;
	int ChannelOffset;
	bool ThreadIsCreate;
	UINT_PTR timer;
	int tinerCount;
	CString Com_name;
	int period;
	char content;                                    //串口的周期和需要发送的数据
	int IsReDraw; 
	CEdit USB_State;
	CWinThread *p_DrawCurveThread;									//用于保存开启数据处理线程时返回的指针对象;
	int ChannelNum;
	CRect   ScreeRrect;   //获取当前屏幕大小
	//动态创建编辑框大小
	CPtrArray p_MyStatics; 
	CPtrArray p_MyEdits;
	CStatic* p_MyStatic;
	CEdit* p_MyEdit;

	//选中串口名字
	CString m_SelCommName;
	// 已经打开的串口的句柄
	HANDLE m_CommHandle;
	// 读数据的线程
	CWinThread* m_pCollectADSThread;
	CWinThread *p_CollectADSThread;


	HANDLE g_hEventForCollect;			//为采集线程定义一个事件对象，只有当采集线程等待到此事件对象时才会进行采集;
	HANDLE g_hEventForDrawCurve;			//为EEG绘图线程定义一个事件对象，只有当绘图线程等待到此事件对象时才会进行绘图;
	
	CBitmap MemBitMap_flash;												//构造一个位图对象;MemDC将图绘制到该内存设备上,而pDC绘制在客户区;
	CDC MemDC_flash;
	CBitmap MemBitMap;												//构造一个位图对象;MemDC将图绘制到该内存设备上,而pDC绘制在客户区;
	CDC MemDC;
	FILE* fp[EEG_ChannelNum+3];                                 //用于存储数据的文件指针
	FILE* fp_emg[EMG_ChannelNum + 3];                      //用于存储32通道EMG数据的文件指针
	FILE* outfile;

	FILE* fpmodel2_eeg[Model2_EEG_ChannelNum + 3];                       //用于存储64通道EMG数据的文件指针
	FILE* fpmodel2_emg[Model2_EMG_ChannelNum + 3];                      //用于存储32通道EMG数据的文件指针

	bool IsbeginThread;         //判断USB采集线程是否启动
	bool CollectComData;        //判断串口采集线程是否启动
	bool m_bIsStartofData;		//用于判断数据是否对齐

	short m_XChange;			//控制波形X轴缩放的缩放系数;
	//short y_scale;			//Y轴波形缩放系数;
	int m_Xcoor;				//表示X坐标;	
	//int m_pointsNumFlag;		//取值0,1,2,3分别表示1,2,5,10个点用于绘图;
	//bool m_channelstatue[ChannelNum];	//表示每个通道的状态false->0,true->1;
	static UINT CollectUsbDataFowADSThread(LPVOID pParam);			//数据采集线程(主要用于接收USB上传到PC的数据)(ADS1278版本线程);
	static UINT DrawCurveThread(LPVOID pParam);						//数据处理线程(对上传到PC的数据进行处理,主要是波形绘制);
					

	
	int ConvertValue(int &SrcData, int *a);							//
	void DrawCurve(CDC &MemDC);										//画波形函数(LineTo);
	INT_PTR GetSerialPort(CString *pNameList, CString *pPortList);


	BOOL m_IsCheckAD1;
	BOOL m_IsCheckAD2;
	BOOL m_IsCheckAD3;
	BOOL m_IsCheckAD4;
	BOOL m_IsCheckAD5;
	BOOL m_IsCheckAD6;
	BOOL m_IsCheckAD7;
	BOOL m_IsCheckAD8;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedConnectamp();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedXminus();
	afx_msg void OnBnClickedXplus();
	afx_msg void OnBnClickedYminus();
	afx_msg void OnBnClickedYplus();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedButtonStopmark();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnDropdownCombo1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedButton4();
	//afx_msg void OnBnClickedtes();
	//afx_msg void OnBnClickedVep();
	//afx_msg void OnBnClickedLep();
	//afx_msg void OnBnClickedButton5();
	//afx_msg void OnBnClickedButton6();
	//afx_msg void OnBnClickedButton9();
	//afx_msg void OnBnClickedButton7();
	//afx_msg void OnBnClickedButton8();
	afx_msg void OnCbnSelchangeCombo2();
	//afx_msg void OnBnClickedStartmeg();
	void Filter_One();
	void Filter_Twenty();

	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnmodel1();
	afx_msg void OnBnClickedImpedance();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnSerialConnection();


	//初始化串口
	void InitComm();
	//读取所有串口
	int GetCommNames(CStringArray& names);
	//关闭串口
	void CloseComm();
	//数据采集线程(主要用于接收USB上传到PC的数据)(ADS1278版本线程);
	static UINT CollectComDataFowADSThread(LPVOID pParam);
	//线程读串口数据
	UINT  CollectComDataFowADS();




};
