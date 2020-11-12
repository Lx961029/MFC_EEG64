
// MFC_EEGDlg.h : ͷ�ļ�
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

//ȫ�ֱ����Ķ���	
#define POINTONE   0
#define POINTTWO   1
#define POINTFIVE  2
#define POINTTEN   3				//һ�λ�ͼʹ�õĵ���


#define EMG_ChannelNum 16
#define EEG_ChannelNum 16
#define Model2_EEG_ChannelNum 64
#define Model2_EMG_ChannelNum 32
#define DialogNum  1
#define BufferSize 512
#define ArrSize 16
#define package_time 1 


#define markerValue 65
#define collecttime 1000						//����ɼ���һǧ�ξ�Ӧ�ñ��ʱ��̶�;
//extern bool m_channelstatue[ChannelNum];
extern bool m_channelstatue[EEG_ChannelNum];
extern std::vector<std::vector<int>> RecvieveData;
extern std::queue<int> que[64];               //����һ����������
extern std::queue<double> drawque[64];

extern std::vector<std::vector<int>> EMG_Data;
extern std::vector<std::vector<int>> EEG_Data;

extern std::vector<std::vector<int>> Model2_EEG_Data;
extern std::vector<std::vector<int>> Model2_EMG_Data;


extern double m_pBuffer[64][64];                     //���ڻ�ͼ�����ݻ���
extern double pBufferTemp[64][2];                   //˫���滭ͼ

extern bool PlotDialogflag[3];
extern int m_pointsNumFlag;
extern long y_scale;


// CMFC_EEGDlg �Ի���
class CMFC_EEGDlg : public CDialogEx
{
// ����
public:
	CMFC_EEGDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_EEG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
public:
	bool Acquisitionmode; //�ɼ�ģʽ��־λ��falseΪģʽһ��trueΪģʽ��
	bool DrawModel;  //��ͼ��־λ��falseΪ�Ե磬trueΪ����
	bool UsbModel;  //Usb����
	bool SelModel;  //���ڴ���

	bool DisInOneDlg;
	int m_CollectTimes;
	int m_TotalTime;
	int ChannelOffset;
	bool ThreadIsCreate;
	UINT_PTR timer;
	int tinerCount;
	CString Com_name;
	int period;
	char content;                                    //���ڵ����ں���Ҫ���͵�����
	int IsReDraw; 
	CEdit USB_State;
	CWinThread *p_DrawCurveThread;									//���ڱ��濪�����ݴ����߳�ʱ���ص�ָ�����;
	int ChannelNum;
	CRect   ScreeRrect;   //��ȡ��ǰ��Ļ��С
	//��̬�����༭���С
	CPtrArray p_MyStatics; 
	CPtrArray p_MyEdits;
	CStatic* p_MyStatic;
	CEdit* p_MyEdit;

	//ѡ�д�������
	CString m_SelCommName;
	// �Ѿ��򿪵Ĵ��ڵľ��
	HANDLE m_CommHandle;
	// �����ݵ��߳�
	CWinThread* m_pCollectADSThread;
	CWinThread *p_CollectADSThread;


	HANDLE g_hEventForCollect;			//Ϊ�ɼ��̶߳���һ���¼�����ֻ�е��ɼ��̵߳ȴ������¼�����ʱ�Ż���вɼ�;
	HANDLE g_hEventForDrawCurve;			//ΪEEG��ͼ�̶߳���һ���¼�����ֻ�е���ͼ�̵߳ȴ������¼�����ʱ�Ż���л�ͼ;
	
	CBitmap MemBitMap_flash;												//����һ��λͼ����;MemDC��ͼ���Ƶ����ڴ��豸��,��pDC�����ڿͻ���;
	CDC MemDC_flash;
	CBitmap MemBitMap;												//����һ��λͼ����;MemDC��ͼ���Ƶ����ڴ��豸��,��pDC�����ڿͻ���;
	CDC MemDC;
	FILE* fp[EEG_ChannelNum+3];                                 //���ڴ洢���ݵ��ļ�ָ��
	FILE* fp_emg[EMG_ChannelNum + 3];                      //���ڴ洢32ͨ��EMG���ݵ��ļ�ָ��
	FILE* outfile;

	FILE* fpmodel2_eeg[Model2_EEG_ChannelNum + 3];                       //���ڴ洢64ͨ��EMG���ݵ��ļ�ָ��
	FILE* fpmodel2_emg[Model2_EMG_ChannelNum + 3];                      //���ڴ洢32ͨ��EMG���ݵ��ļ�ָ��

	bool IsbeginThread;         //�ж�USB�ɼ��߳��Ƿ�����
	bool CollectComData;        //�жϴ��ڲɼ��߳��Ƿ�����
	bool m_bIsStartofData;		//�����ж������Ƿ����

	short m_XChange;			//���Ʋ���X�����ŵ�����ϵ��;
	//short y_scale;			//Y�Შ������ϵ��;
	int m_Xcoor;				//��ʾX����;	
	//int m_pointsNumFlag;		//ȡֵ0,1,2,3�ֱ��ʾ1,2,5,10�������ڻ�ͼ;
	//bool m_channelstatue[ChannelNum];	//��ʾÿ��ͨ����״̬false->0,true->1;
	static UINT CollectUsbDataFowADSThread(LPVOID pParam);			//���ݲɼ��߳�(��Ҫ���ڽ���USB�ϴ���PC������)(ADS1278�汾�߳�);
	static UINT DrawCurveThread(LPVOID pParam);						//���ݴ����߳�(���ϴ���PC�����ݽ��д���,��Ҫ�ǲ��λ���);
					

	
	int ConvertValue(int &SrcData, int *a);							//
	void DrawCurve(CDC &MemDC);										//�����κ���(LineTo);
	INT_PTR GetSerialPort(CString *pNameList, CString *pPortList);


	BOOL m_IsCheckAD1;
	BOOL m_IsCheckAD2;
	BOOL m_IsCheckAD3;
	BOOL m_IsCheckAD4;
	BOOL m_IsCheckAD5;
	BOOL m_IsCheckAD6;
	BOOL m_IsCheckAD7;
	BOOL m_IsCheckAD8;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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


	//��ʼ������
	void InitComm();
	//��ȡ���д���
	int GetCommNames(CStringArray& names);
	//�رմ���
	void CloseComm();
	//���ݲɼ��߳�(��Ҫ���ڽ���USB�ϴ���PC������)(ADS1278�汾�߳�);
	static UINT CollectComDataFowADSThread(LPVOID pParam);
	//�̶߳���������
	UINT  CollectComDataFowADS();




};
