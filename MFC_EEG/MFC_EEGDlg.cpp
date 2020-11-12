
// MFC_EEGDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_EEG.h"
#include "MFC_EEGDlg.h"
#include "afxdialogex.h"
#include <conio.h>
#include <string>


using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define IIR_L 20 ////1KHz
float IIRBuffer[64][IIR_L + 1] = { 0 };//
static float *p0 = &IIRBuffer[0][0];
static float *p1 = &IIRBuffer[1][0];
static float *p2 = &IIRBuffer[2][0];
static float *p3 = &IIRBuffer[3][0];
static float *p4 = &IIRBuffer[4][0];
static float *p5 = &IIRBuffer[5][0];
static float *p6 = &IIRBuffer[6][0];
static float *p7 = &IIRBuffer[7][0];
static float *p8 = &IIRBuffer[8][0];
static float *p9 = &IIRBuffer[9][0];
static float *p10 = &IIRBuffer[10][0];
static float *p11 = &IIRBuffer[11][0];
static float *p12 = &IIRBuffer[12][0];
static float *p13 = &IIRBuffer[13][0];
static float *p14 = &IIRBuffer[14][0];
static float *p15 = &IIRBuffer[15][0];
static float *p16 = &IIRBuffer[16][0];
static float *p17 = &IIRBuffer[17][0];
static float *p18 = &IIRBuffer[18][0];
static float *p19 = &IIRBuffer[19][0];
static float *p20 = &IIRBuffer[20][0];
static float *p21 = &IIRBuffer[21][0];
static float *p22 = &IIRBuffer[22][0];
static float *p23 = &IIRBuffer[23][0];
static float *p24 = &IIRBuffer[24][0];
static float *p25 = &IIRBuffer[25][0];
static float *p26 = &IIRBuffer[26][0];
static float *p27 = &IIRBuffer[27][0];
static float *p28 = &IIRBuffer[28][0];
static float *p29 = &IIRBuffer[29][0];
static float *p30 = &IIRBuffer[30][0];
static float* p31 = &IIRBuffer[31][0];
static float* p32 = &IIRBuffer[32][0];
static float* p33 = &IIRBuffer[33][0];
static float* p34 = &IIRBuffer[34][0];
static float* p35 = &IIRBuffer[35][0];
static float* p36 = &IIRBuffer[36][0];
static float* p37 = &IIRBuffer[37][0];
static float* p38 = &IIRBuffer[38][0];
static float* p39 = &IIRBuffer[39][0];
static float* p40 = &IIRBuffer[40][0];
static float* p41 = &IIRBuffer[41][0];
static float* p42 = &IIRBuffer[42][0];
static float* p43 = &IIRBuffer[43][0];
static float* p44 = &IIRBuffer[44][0];
static float* p45 = &IIRBuffer[45][0];
static float* p46 = &IIRBuffer[46][0];
static float* p47 = &IIRBuffer[47][0];
static float* p48 = &IIRBuffer[48][0];
static float* p49 = &IIRBuffer[49][0];
static float* p50 = &IIRBuffer[50][0];
static float* p51 = &IIRBuffer[51][0];
static float* p52 = &IIRBuffer[52][0];
static float* p53 = &IIRBuffer[53][0];
static float* p54 = &IIRBuffer[54][0];
static float* p55 = &IIRBuffer[55][0];
static float* p56 = &IIRBuffer[56][0];
static float* p57 = &IIRBuffer[57][0];
static float* p58 = &IIRBuffer[58][0];
static float* p59 = &IIRBuffer[59][0];
static float* p60 = &IIRBuffer[60][0];
static float* p61 = &IIRBuffer[61][0];
static float* p62 = &IIRBuffer[62][0];
static float* p63 = &IIRBuffer[63][0];


#define EMG_IIR_L 100 ////5KHz
float EMG_IIRBuffer[32][EMG_IIR_L + 1] = { 0 };//
static float* emg_p0 = &EMG_IIRBuffer[0][0];
static float* emg_p1 = &EMG_IIRBuffer[1][0];
static float* emg_p2 = &EMG_IIRBuffer[2][0];
static float* emg_p3 = &EMG_IIRBuffer[3][0];
static float* emg_p4 = &EMG_IIRBuffer[4][0];
static float* emg_p5 = &EMG_IIRBuffer[5][0];
static float* emg_p6 = &EMG_IIRBuffer[6][0];
static float* emg_p7 = &EMG_IIRBuffer[7][0];
static float* emg_p8 = &EMG_IIRBuffer[8][0];
static float* emg_p9 = &EMG_IIRBuffer[9][0];
static float* emg_p10 = &EMG_IIRBuffer[10][0];
static float* emg_p11 = &EMG_IIRBuffer[11][0];
static float* emg_p12 = &EMG_IIRBuffer[12][0];
static float* emg_p13 = &EMG_IIRBuffer[13][0];
static float* emg_p14 = &EMG_IIRBuffer[14][0];
static float* emg_p15 = &EMG_IIRBuffer[15][0];
static float* emg_p16 = &EMG_IIRBuffer[16][0];
static float* emg_p17 = &EMG_IIRBuffer[17][0];
static float* emg_p18 = &EMG_IIRBuffer[18][0];
static float* emg_p19 = &EMG_IIRBuffer[19][0];
static float* emg_p20 = &EMG_IIRBuffer[20][0];
static float* emg_p21 = &EMG_IIRBuffer[21][0];
static float* emg_p22 = &EMG_IIRBuffer[22][0];
static float* emg_p23 = &EMG_IIRBuffer[23][0];
static float* emg_p24 = &EMG_IIRBuffer[24][0];
static float* emg_p25 = &EMG_IIRBuffer[25][0];
static float* emg_p26 = &EMG_IIRBuffer[26][0];
static float* emg_p27 = &EMG_IIRBuffer[27][0];
static float* emg_p28 = &EMG_IIRBuffer[28][0];
static float* emg_p29 = &EMG_IIRBuffer[29][0];
static float* emg_p30 = &EMG_IIRBuffer[30][0];
static float* emg_p31 = &EMG_IIRBuffer[31][0];








//ԭʼ�˲�����
static float Den = -0.8230;
static float Num = 0.9115;

bool m_channelstatue[EEG_ChannelNum] = {true};
std::vector<std::vector<int>> RecvieveData(64);
std::vector<std::vector<int>> EMG_Data(EMG_ChannelNum);
std::vector<std::vector<int>> EEG_Data(EEG_ChannelNum);
std::vector<std::vector<int>> Model2_EEG_Data(Model2_EEG_ChannelNum);
std::vector<std::vector<int>> Model2_EMG_Data(Model2_EMG_ChannelNum);
std::queue<int> que[64];
std::queue<double> drawque[64];
double m_pBuffer[64][64];                     //���ڻ�ͼ�����ݻ���
double pBufferTemp[64][2]; //˫���滭ͼ

HANDLE m_Com;                            //���ھ��
CString strCom[50];

CChannel17To32* Plot17To32;// = new CChannel17To32();
CChannel33To48* Plot33To48;// = new CChannel33To48();
CChannel49To64* Plot49To64;//= new CChannel49To64();

bool PlotDialogflag[3] = { false };   //�����Ի�����ʾ��־
int m_pointsNumFlag;
long y_scale;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_EEGDlg �Ի���



CMFC_EEGDlg::CMFC_EEGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_EEGDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	p_DrawCurveThread = nullptr;							//���ڱ��濪�����ݴ����߳�ʱ���ص�ָ�����,�˴���Ϊnullptr;
	p_CollectADSThread = nullptr;
	g_hEventForCollect = nullptr;			//Ϊ�ɼ��̶߳���һ���¼�����ֻ�е��ɼ��̵߳ȴ������¼�����ʱ�Ż���вɼ�;
	g_hEventForDrawCurve = nullptr;			//Ϊ��ͼ�̶߳���һ���¼�����ֻ�е���ͼ�̵߳ȴ������¼�����ʱ�Ż���л�ͼ;
	IsbeginThread = false;	
	m_XChange = 1;											//�����������ϵ�����и���;
	y_scale = 8;												//�������������ϵ��;(���Ϊ32����СΪ2)
	m_Xcoor = 0;
	IsReDraw = true;
	period = 0;
	content=0;
	ThreadIsCreate = 0;
	Com_name = "COM1";
	m_pointsNumFlag = 2;                                    //��ʼ��ʱ��ÿ10���㻭������
	DisInOneDlg=TRUE;
	ChannelOffset=0;
	m_CollectTimes = 0;
	m_TotalTime = 0;
	tinerCount = 0;
	ChannelNum = 16;
	CollectComData = false;        //�жϴ��ڲɼ��߳��Ƿ�����
	m_bIsStartofData = false;		//�����ж������Ƿ����
	UsbModel = false;  //USB��������ģʽ
	SelModel = false;  //���ڴ�������ģʽ

	for (int i = 0; i < EEG_ChannelNum+2; i++)
		fp[i] = nullptr;
	for (int i = 0; i < EMG_ChannelNum + 2; i++)
		fp_emg[i] = nullptr;
	for (int i = 0; i < 16; i++)
		m_channelstatue[i] = true;
	for (int i = 0; i < Model2_EEG_ChannelNum + 2; i++)
		fpmodel2_eeg[i] = nullptr;
	for (int i = 0; i < Model2_EMG_ChannelNum + 2; i++)
		fpmodel2_emg[i] = nullptr;

	outfile = nullptr;
	Acquisitionmode = false;//��ʼ��ģʽ��־λΪģʽһ
	DrawModel = false; // ��ʼ��ģʽ��־λΪ�Ե�
}

void CMFC_EEGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_STATE, USB_State);
}

BEGIN_MESSAGE_MAP(CMFC_EEGDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECTAMP, &CMFC_EEGDlg::OnBnClickedConnectamp)
	ON_BN_CLICKED(IDC_START, &CMFC_EEGDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_STOP, &CMFC_EEGDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_XMINUS, &CMFC_EEGDlg::OnBnClickedXminus)
	ON_BN_CLICKED(IDC_XPLUS, &CMFC_EEGDlg::OnBnClickedXplus)
	ON_BN_CLICKED(IDC_YMINUS, &CMFC_EEGDlg::OnBnClickedYminus)
	ON_BN_CLICKED(IDC_YPLUS, &CMFC_EEGDlg::OnBnClickedYplus)
	ON_BN_CLICKED(IDC_CHECK8, &CMFC_EEGDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK7, &CMFC_EEGDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK6, &CMFC_EEGDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK5, &CMFC_EEGDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK4, &CMFC_EEGDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK3, &CMFC_EEGDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK2, &CMFC_EEGDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CMFC_EEGDlg::OnBnClickedCheck1)
	//ON_BN_CLICKED(IDC_SEND, &CMFC_EEGDlg::OnBnClickedSend)
	//ON_BN_CLICKED(IDC_BUTTON_STOPMARK, &CMFC_EEGDlg::OnBnClickedButtonStopmark)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO6, &CMFC_EEGDlg::OnCbnSelchangeCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO6, &CMFC_EEGDlg::OnCbnDropdownCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_EEGDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK16, &CMFC_EEGDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK15, &CMFC_EEGDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK14, &CMFC_EEGDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK13, &CMFC_EEGDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK12, &CMFC_EEGDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK11, &CMFC_EEGDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK10, &CMFC_EEGDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK9, &CMFC_EEGDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK17, &CMFC_EEGDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_EEGDlg::OnBnClickedButton4)

	ON_BN_CLICKED(IDC_BUTTON10, &CMFC_EEGDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_STARTMEG, &CMFC_EEGDlg::OnBnmodel1)
	ON_BN_CLICKED(IDC_IMPEDANCE, &CMFC_EEGDlg::OnBnClickedImpedance)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_EEGDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_EEGDlg::OnBnClickedButton8)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_EEGDlg::OnBnSerialConnection)
END_MESSAGE_MAP()


// CMFC_EEGDlg ��Ϣ�������

BOOL CMFC_EEGDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	/////////////////////////////// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	/////////////////////////////CFont UsbEditFont;
	/////////////////////////////const int FontSize = 200;
	/////////////////////////////UsbEditFont.CreatePointFont(FontSize, _T("����"));
	/////////////////////////////USB_State.SetFont(&UsbEditFont);
	/////////////////////////////
	/////////////////////////////ept = USBDevice->ControlEndPt;
	
	//GetDlgItem(IDC_PICTURE)->MoveWindow(CRect(169, 9, 1800, 1000));
	//2020.9.26  Li  ���ø�ѡ���48 64ͨ����������
	CButton* pBtnChecck17 = (CButton*)GetDlgItem(IDC_CHECK17);
	pBtnChecck17->EnableWindow(0);// disable it

	//�������
	ShowWindow(SW_SHOWMAXIMIZED);
	GetWindowRect(ScreeRrect);
	GetDlgItem(IDC_PICTURE)->MoveWindow(CRect(169, 9, ScreeRrect.right-100, ScreeRrect.bottom-50)); //�ڴ������Ͻ���ʾһ����100����100�ı༭�ؼ�
	CWnd* pWnd;
	pWnd = GetDlgItem(IDC_CHECK1);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100)/16, 0, 0, SWP_NOZORDER | SWP_NOSIZE);  
	pWnd = GetDlgItem(IDC_CHECK2);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*2, 0, 0, SWP_NOZORDER | SWP_NOSIZE);  
	pWnd = GetDlgItem(IDC_CHECK3);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*3, 0, 0, SWP_NOZORDER | SWP_NOSIZE);   
	pWnd = GetDlgItem(IDC_CHECK4);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*4, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK5);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*5, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK6);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*6, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK7);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*7, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK8);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*8, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK9);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*9, 0, 0, SWP_NOZORDER | SWP_NOSIZE);   
	pWnd = GetDlgItem(IDC_CHECK10);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*10, 0, 0, SWP_NOZORDER | SWP_NOSIZE);   
	pWnd = GetDlgItem(IDC_CHECK11);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*11, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK12);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*12, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK13);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*13, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK14);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*14, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK15);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*15, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	pWnd = GetDlgItem(IDC_CHECK16);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	pWnd->SetWindowPos(NULL, ScreeRrect.right - 90, (ScreeRrect.bottom - 100) / 16*16, 0, 0, SWP_NOZORDER | SWP_NOSIZE);    
	GetDlgItem(IDC_CHECK17)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK10)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK11)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK12)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK13)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK14)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK15)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHECK16)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_BUTTON2)->ShowWindow(SW_HIDE); GetDlgItem(IDC_COMBO6)->ShowWindow(SW_HIDE);
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_EEGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_EEGDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	if (IsReDraw == true)
	{



		CString strTemp;
		strTemp.Format(_T("%d"), 25);
		SetDlgItemText(IDC_EDIT_COMVALUE, strTemp);
		strTemp.Format(_T("%d"), 30);
		SetDlgItemText(IDC_EDIT_MARKT, strTemp);
		SetDlgItemText(IDC_COMBO6, _T("ѡ��"));
		//���廭���Ŀ����;
		//short xWidth = 1330;// x����Ϊ��;
		//short yHeight = 800;//y����Ϊ��;

		//2020.9.26  Li  ��������Ӧ
		//CRect rect;
		//GetClientRect(&rect);
		//int xWidth = rect.Width()-300;// x����Ϊ��;
		//int yHeight = rect.Height()-50;//y����Ϊ��;
		int xWidth = ScreeRrect.right-280;// x����Ϊ��;
		int yHeight = ScreeRrect.bottom - 60;//y����Ϊ��;


		//˫�����ͼ
		CDC *pDC = GetDC();					       //����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
		if (pDC == NULL)						//���pDC�Ƿ���Ч;
		{
			MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"));	//��pDC��Ч�����һ��������Ϣ;
		}
		MemDC.CreateCompatibleDC(pDC);							   	//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
		MemBitMap.CreateCompatibleBitmap(pDC, xWidth, yHeight);	      //��ʼ��һ����pDC��ָ����豸���ݵ�λͼ;
		MemDC.SelectObject(&MemBitMap);
		MemDC.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));		//���ض���ɫ���Ŀ�����;
		pDC->BitBlt(170, 10, xWidth, yHeight, &MemDC, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		ReleaseDC(pDC);															//�ͷ��豸������;
		MemDC.DeleteDC();

		 pDC = GetDC();					       //����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
		/*if (pDC == NULL)						//���pDC�Ƿ���Ч;
		{
			MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"));	//��pDC��Ч�����һ��������Ϣ;
		}
		MemDC_flash.CreateCompatibleDC(pDC);							   	//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
		MemBitMap_flash.CreateCompatibleBitmap(pDC, 80, 80);	      //��ʼ��һ����pDC��ָ����豸���ݵ�λͼ;
		MemDC_flash.SelectObject(&MemBitMap_flash);
		MemDC_flash.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));		//���ض���ɫ���Ŀ�����;
		pDC->BitBlt(1270, 300, 1350, 380, &MemDC_flash, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		ReleaseDC(pDC);															//�ͷ��豸������;
		MemDC.DeleteDC();*/
		pDC = nullptr;
		IsReDraw = false;
	}

}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_EEGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//USB����
void CMFC_EEGDlg::OnBnClickedConnectamp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (OpenDevice(USBvid, USBpid))
	{
		InEndpt = (CCyUSBEndPoint*)USBDevice->EndPoints[1];	//��CCyUSBEndPoint���ڵ������ݴ��亯���������ݲɼ�,�ö˵�ָ�벻���ڹ��캯���г�ʼ��;
		InEndpt->TimeOut = 10000;
		 CString ShowWord =_T( "�Ѿ����ӷŴ���!");
		SetDlgItemText(IDC_STATIC_STATE,ShowWord);

		CString strvID, strpID,str;
		strvID.Format(_T("VendorID = 0x%x"), USBvid);
		strpID.Format(_T("ProductID = 0x%x"), USBpid);
		str +=strvID + _T("\r\n") + strpID + _T("\r\n");
		USB_State.SetWindowText(str);		//������ʾUSB�豸��״̬��Ϣ;

		CButton *pzBtn = (CButton*)GetDlgItem(IDC_CONNECTAMP);
		pzBtn->EnableWindow(FALSE);
		pzBtn = (CButton*)GetDlgItem(IDC_STOP);
		pzBtn->EnableWindow(FALSE);
		pzBtn = (CButton*)GetDlgItem(IDC_START);
		pzBtn->EnableWindow(true);
		pzBtn = (CButton*)GetDlgItem(IDC_IMPEDANCE);
		pzBtn->EnableWindow(true);

		UsbModel = true;
		CButton* pBtn= (CButton*)GetDlgItem(IDC_BUTTON2);
		pBtn->EnableWindow(0);// disable it
	}
	else
	{
		CString ShowWord = _T("���ӷŴ���ʧ��!");
		SetDlgItemText(IDC_STATIC_STATE, ShowWord);
		MessageBox(_T("δ��⵽�Ե�Ŵ���������������!"), _T("WARNING"), MB_ICONWARNING | MB_OK);
	}
	
}

//��ʼ�ɼ����ͼ
void CMFC_EEGDlg::OnBnClickedStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int ReqCode = 0xA4;                            //��ʼ���͸�FPGA�Ե�ɼ�ָ��
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0x00;
	buf[1] = 0x00;
	buf[2] = 0x00;
	buf[3] = 0x00;
	buf[4] = 0x00;
	WriteParam(ReqCode, Value, Index, buf, buflen);



	if (UsbModel)//USB��������
	{
		if (ThreadIsCreate == 0)
		{
			CString strvID, strpID, str;
			strvID.Format(_T("�Ŵ����Ѿ�����"));
			strpID.Format(_T("���ڽ���ϵͳ��ʼ��"));
			str += strvID + _T("\r\n") + strpID + _T("\r\n");
			USB_State.SetWindowText(str);		//������ʾUSB�豸��״̬��Ϣ

			IsbeginThread = true;
			g_hEventForCollect = CreateEventA(NULL, FALSE, FALSE, NULL);				//����һ���������Զ������¼�����ʹ��Ĭ�ϵİ�ȫ�ԣ�����δ����״̬;
			g_hEventForDrawCurve = CreateEventA(NULL, FALSE, FALSE, NULL);				//����һ���������Զ������¼�����ʹ��Ĭ�ϵİ�ȫ�ԣ�����δ����״̬;
			//SetEvent(g_hEventForCollect);
			p_CollectADSThread = AfxBeginThread(CollectUsbDataFowADSThread, this);	//��ʹ�õ�ADΪADS1278ʱ,ʹ�ô��߳������ݲɼ�;
			p_DrawCurveThread = AfxBeginThread(DrawCurveThread, this);
			ThreadIsCreate = 1;
		}
		else
		{
			IsbeginThread = true;
			CString strvID, strpID, str;
			strvID.Format(_T("�Ŵ����Ѿ�����"));
			strpID.Format(_T("���ڲɼ��Ե�����"));
			str += strvID + _T("\r\n") + strpID + _T("\r\n");
			USB_State.SetWindowText(str);		//������ʾUSB�豸��״̬��Ϣ
			p_CollectADSThread = AfxBeginThread(CollectUsbDataFowADSThread, this);	//ͨ��USB�ɼ�����;
			p_DrawCurveThread = AfxBeginThread(DrawCurveThread, this);
			SetEvent(g_hEventForCollect);
		}
		
	}
	if (SelModel) {
		CollectComData = true;
		m_pCollectADSThread = AfxBeginThread(CollectComDataFowADSThread, this);	//ͨ�����ڲɼ�����;
		//p_DrawCurveThread = AfxBeginThread(DrawCurveThread, this);
	}



	CButton *pzBtn = (CButton*)GetDlgItem(IDC_CONNECTAMP);
	pzBtn->EnableWindow(FALSE);
	pzBtn = (CButton*)GetDlgItem(IDC_STOP);
	pzBtn->EnableWindow(true);
	pzBtn = (CButton*)GetDlgItem(IDC_START);
	pzBtn->EnableWindow(FALSE);
	pzBtn = (CButton*)GetDlgItem(IDC_IMPEDANCE);
	pzBtn->EnableWindow(FALSE);
	pzBtn = (CButton*)GetDlgItem(IDC_STARTMEG);
	pzBtn->EnableWindow(FALSE);
}

void CMFC_EEGDlg::OnBnClickedStop()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	if (WriteParam(0xA2))
//	{
		IsbeginThread = false;

		long bufflen = BufferSize;
		UCHAR pCollectData[BufferSize];					//�ɼ�������������1���ֽ�Ϊ��С;
		InEndpt->TimeOut = 500;

		CString strvID, str;
		strvID.Format(_T("�Ѿ�ֹͣ�ɼ�����"));
		str += strvID + _T("\r\n") + _T("\r\n");
		USB_State.SetWindowText(str);		//������ʾUSB�豸��״̬��Ϣ

		//for (int i = 0; i <= EEG_ChannelNum + 1; i++)
		//{
		//	if (fp[i])
		//		fclose(fp[i]);
		//}
		//for (int i = 0; i <= EMG_ChannelNum + 1; i++)
		//{
		//	if (fp_emg[i])
		//		fclose(fp_emg[i]);
		//}
		//for (int i = 0; i <= Model2_EEG_ChannelNum + 1; i++)
		//{
		//	if (fpmodel2_eeg[i])
		//		fclose(fpmodel2_eeg[i]);
		//}
		//for (int i = 0; i <= Model2_EMG_ChannelNum + 1; i++)
		//{
		//	if (fpmodel2_emg[i])
		//		fclose(fpmodel2_emg[i]);
		//}

		CButton *pzBtn = (CButton*)GetDlgItem(IDC_CONNECTAMP);
		pzBtn->EnableWindow(FALSE);
		pzBtn = (CButton*)GetDlgItem(IDC_STOP);
		pzBtn->EnableWindow(FALSE);
		pzBtn = (CButton*)GetDlgItem(IDC_START);
		pzBtn->EnableWindow(true);
		pzBtn = (CButton*)GetDlgItem(IDC_IMPEDANCE);
		pzBtn->EnableWindow(true);
//	}
}

UINT CMFC_EEGDlg::CollectUsbDataFowADSThread(LPVOID pParam)			//���ݲɼ��߳�(��Ҫ���ڽ���USB�ϴ���PC������)(ADS1278�汾�߳�);
{
	CString str;
	CString str1;
	double tempp = 0;
	int model2 = 0; //���ڼ���ģʽ���������
	int get_eeg_num = 0;
	int eeg_flag=0;
	int count;
	CMFC_EEGDlg* p_ADSCollect = (CMFC_EEGDlg*)pParam;					//p_Collect���ڷ�����ķǾ�̬��Ա;
	
	for (int i = 0; i < EEG_ChannelNum; i++)
	{
		char str[100];
		sprintf(str, "EEG_Channel_%d.txt", i + 1);
		p_ADSCollect->fp[i + 1] = fopen(str, "wb");
	}
	p_ADSCollect->fp[17] = fopen("Marker.txt", "wb");
	for (int i = 0; i < EMG_ChannelNum; i++)
	{
		char str[100];
		sprintf(str, "EMG_Channel_%d.txt", i + 1);
	p_ADSCollect->fp_emg[i + 1] = fopen(str, "wb");
	}
	//p_ADSCollect->fp_emg[17] = fopen("EMG_Marker.txt", "wb");
	for (int i = 0; i < Model2_EEG_ChannelNum; i++)
	{
		char str[100];
		sprintf(str, "Model2_EEG_Channel_%d.txt", i + 1);
		p_ADSCollect->fpmodel2_eeg[i + 1] = fopen(str, "wb");
	}
	p_ADSCollect->fpmodel2_eeg[65] = fopen("Model2_Marker.txt", "wb");
	for (int i = 0; i < Model2_EMG_ChannelNum; i++)
	{
		char str[100];
		sprintf(str, "Model2_EMG_Channel_%d.txt", i + 1);
		p_ADSCollect->fpmodel2_emg[i + 1] = fopen(str, "wb");
	}

	long bufflen = BufferSize;
	PUCHAR pCollectData = new UCHAR[BufferSize];					//�ɼ�������������1���ֽ�Ϊ��С;
	int pDataBuffer[64] = { 0 };

	InEndpt->TimeOut = 5000;
	//Sleep(1000);
	count = 0;
	while (p_ADSCollect->IsbeginThread)                                                 /*p_Collect->m_IsCollectAndProcess*/
	{
		//WaitForSingleObject(p_ADSCollect->g_hEventForCollect, INFINITE);	//ֻ���¼������ڷ���״̬ʱ�ú����ŷ���,Ȼ��ִ�б������Ĵ���,�ú���һ���������¼�������δ����״̬;
		bool IsDataColOk = false;	//IsDataColOk���ڱ�ʾ���ݲɼ��Ƿ�ɹ�;
		for (int time = 0; time < package_time;)
		{
			if (pCollectData && pDataBuffer)
			{
				ZeroMemory(pCollectData, BufferSize);						//��մ��ԭʼ���ݻ�����;
				ZeroMemory(pDataBuffer, ArrSize);						//��մ��ƴ�Ӻ�����ݻ�����;

				IsDataColOk = InEndpt->XferData(pCollectData, bufflen);		//��USB����PC��1024�ֽ����ݴ���pCollectDataָ����ڴ���;	
				if (!IsDataColOk)
				{
					p_ADSCollect->USB_State.SetWindowText(_T("���ݲɼ�ʧ��"));
				}
			}
			if (IsDataColOk)													//�ж����ݲɼ��Ƿ�ɹ�;
			{
				
				time++;
				unsigned char TimeChannel = 0;
				unsigned char Timepicture = 0;
				unsigned int index = 0;										//indexΪƴ�Ӻ�������±�����;
				unsigned int j = 0;
				unsigned int channelnum = 0;     //fp�ļ�ָ��ͨ������

					//-----------����ԭʼ���ݵ�Test.txt--------------//
				//for (int i = 0; i < BufferSize; i++) {
				//	fprintf(p_ADSCollect->outfile, "%02x ", pCollectData[i]);
				//}
				//fprintf(p_ADSCollect->outfile, "\n ");
				//�Ե�����
					
				if (p_ADSCollect->Acquisitionmode == false)//ģʽһ
				{
					for (int Datanum = 0; Datanum < 4; Datanum++) {
						if (pCollectData[j] == 0xAA && pCollectData[j + 1] == 0x55) {
							fprintf(p_ADSCollect->fp[17], "%d ", pCollectData[j + 5]);
							j = j + 6;
							for (index = 0; index < EEG_ChannelNum; index++)
							{
								pDataBuffer[index] = pCollectData[j] ^ 0x80;
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								fprintf(p_ADSCollect->fp[index + 1], "%d ", pDataBuffer[index]);
								if (p_ADSCollect->DrawModel == false && Datanum==0) {
									que[index].push(pDataBuffer[index]);
								}
							}
							for (index = 0; index < EMG_ChannelNum; index++)
							{
								pDataBuffer[index] = pCollectData[j] ^ 0x80;
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								fprintf(p_ADSCollect->fp_emg[index + 1], "%d ", pDataBuffer[index]);
								if (p_ADSCollect->DrawModel == true && Datanum == 0) {
									que[index].push(pDataBuffer[index]);
								}
							}
							j = j + 26;
						}
					}
					SetEvent(p_ADSCollect->g_hEventForDrawCurve);
				}
				else if (p_ADSCollect->Acquisitionmode)//ģʽ��
				{
					for (int Datanum = 0; Datanum < 4; Datanum++) {
						if (pCollectData[j] == 0xAA && pCollectData[j+1] == 0x55) {
							if (pCollectData[j+3] == 0x01) {
								
								model2 = 0;
								get_eeg_num = 0;
								//������ͼ��
								if (p_ADSCollect->DrawModel==false) {
									SetEvent(p_ADSCollect->g_hEventForDrawCurve);
								}
							}
							//fprintf(p_ADSCollect->fpmodel2_eeg[65], "%d ", pCollectData[j + 5]);
							j = j + 6;
							for (index = 0; index < Model2_EMG_ChannelNum; index++)
							{
								pDataBuffer[index] = pCollectData[j] ^ 0x80;
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
								++j;
								fprintf(p_ADSCollect->fpmodel2_emg[index + 1], "%d ", pDataBuffer[index]);
								//Model2_EMG_Data[index].push_back(pDataBuffer[index]);
								//��ͼ���ݱ���
								//que[index].push(pDataBuffer[index]);
								if (p_ADSCollect->DrawModel&& Datanum==0) {
									que[index].push(pDataBuffer[index]);
								}
							}
			
							if (model2 < 8)
							{
								for (index = 0; index < 8; index++)
								{
									pDataBuffer[index] = pCollectData[j] ^ 0x80;
									++j;
									pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
									++j;
									pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
									++j;
									//fprintf(p_ADSCollect->fpmodel2_eeg[get_eeg_num + 1], "%d ", pDataBuffer[index]);
									Model2_EEG_Data[get_eeg_num].push_back(pDataBuffer[index]);

									if (p_ADSCollect->DrawModel == false ) {
										que[get_eeg_num].push(pDataBuffer[index]);
									}
									get_eeg_num++;
								}
								j = j + 2;
							}
							else
							{
								j = j + 26;
							}
							model2++;
						}	
					}
					if (p_ADSCollect->DrawModel) {
						SetEvent(p_ADSCollect->g_hEventForDrawCurve);
					}
				}
			}
		}
	}
	pCollectData = nullptr;
	return 0;
}


UINT CMFC_EEGDlg::DrawCurveThread(LPVOID pParam)						//���ݴ����߳�(���ϴ���PC�����ݽ��д���,��Ҫ�ǲ��λ���);
{
	CMFC_EEGDlg *p_DrawThread = (CMFC_EEGDlg *)pParam;
	
	WaitForSingleObject(p_DrawThread->g_hEventForDrawCurve, INFINITE);       //��ʾ�Ѿ��ڽ������ݲɼ���ϵͳ��ʼ���Ѿ������

	CMFC_EEGDlg *p_ADSCollect = (CMFC_EEGDlg *)pParam;					//p_Collect���ڷ�����ķǾ�̬��Ա;

	CString strvID, strpID, str;
	strvID.Format(_T("�Ŵ����Ѿ�����"));
	strpID.Format(_T("���ڲɼ�����"));
	str += strvID + _T("\r\n") + strpID + _T("\r\n");
	p_DrawThread->USB_State.SetWindowText(str);		//������ʾUSB�豸��״̬��Ϣ
	p_DrawThread->outfile = fopen("Test1.txt", "wb");
	float fSum;  //���IIR�������� 
	double tempp = 0;
	float *q;
	CString str1;
	short xWidth = p_DrawThread->ScreeRrect.right - 250;								//x����Ϊ��;
	short yHeight = p_DrawThread->ScreeRrect.bottom - 100;								//y����Ϊ��;
	SetEvent(p_DrawThread->g_hEventForDrawCurve);      //�ٽ��Լ�����Ա㿪ʼ��ʾ����

	while (p_DrawThread->IsbeginThread)
	{
		 WaitForSingleObject(p_DrawThread->g_hEventForDrawCurve, INFINITE);
		//--------------�ɵ����ݴ���-------------------//
		//for (int i = 0; i < p_DrawThread->ChannelNum; i++)
		//{
		//	for (int j = 0; j < que[i].size(); j++)
		//	{
		//		tempp = que[i].front();    //AD�����ĵ�ѹֵ
		//		que[i].pop();
		//		m_pBuffer[i][j] = (double)((tempp-8388608) / 0xFFFFFF * y_scale * (-1));
		//		//fprintf(p_ADSCollect->fpmodel2_eeg[i + 1], "%f ", m_pBuffer[i][j]);
		//		drawque[i].push(m_pBuffer[i][j]);
		//	}
		//}
		//str1.Format(L"%d", que[0].size());
		//str.Append(str1);
		//fprintf(p_DrawThread->outfile, "%d ", que[0].size());
		//p_DrawThread->USB_State.SetWindowText(str);

		if (p_DrawThread->ChannelNum==64)
		{
			p_DrawThread->Filter_One();
		}
		else
		{
			p_DrawThread->Filter_Twenty();
		}
		//˫�����ͼ
		CDC* pDC = p_DrawThread->GetDC();								//����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
		if (pDC == nullptr)											//���pDC�Ƿ���Ч;
		{
			p_DrawThread->MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"), _T("WARNING"), MB_ICONWARNING | MB_OK);	//��pDC��Ч�����һ��������Ϣ;
		}
		p_DrawThread->MemDC.CreateCompatibleDC(pDC);						//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
		p_DrawThread->MemDC.SelectObject(&p_DrawThread->MemBitMap);				//��MemBitMap����ѡ���豸��������;
		p_DrawThread->DrawCurve(p_DrawThread->MemDC);
		pDC->BitBlt(170, 10, xWidth + 170, yHeight + 10, &p_DrawThread->MemDC, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		p_DrawThread->ReleaseDC(pDC);										//�ͷ��豸������;
		pDC = nullptr;
		p_DrawThread->MemDC.DeleteDC();
	}	
	return 0;
}

void CMFC_EEGDlg::DrawCurve(CDC &MemDC)
{
	int addnum=10;
	int j = 0;


	CPen PenForCurve(PS_SOLID, 1, RGB(0, 0, 255));						//����һ�����������(���ڻ�����);
	CBrush bRush(RGB(255, 255, 255));
	CPen* poldPen = MemDC.SelectObject(&PenForCurve);					//������ѡ���豸��������;
	CBrush *poldBrush = MemDC.SelectObject(&bRush);						//���˻�ˢѡ���ڴ�DC��;
	COLORREF OldColor = MemDC.SetTextColor(RGB(0, 0, 0));				//����ʱ��̶ȵ��ı���ɫ;

	//float y_scale = 18;							//y������Ŀ̶�   90/5
	short xWidth = ScreeRrect.right - 280;								//x����Ϊ��;
	short yHeight = ScreeRrect.bottom - 60;									//yΪ��ͼ������Ϊ��;
	short y_maxHeight = ScreeRrect.bottom - 60;
	short gm_nRangeY= (int)(yHeight / (ChannelNum +2));
	short gm_nStartPointy = (gm_nRangeY / 2);
	int point_num[4] = { 1, 2, 5, 10 };					//��ʾÿ��ͨ���е�10����ȡ�����㻭ͼ;
	//int chanenum = 8;									//��ʾ�ڼ�ͨ��0->chan1,1->chan2.....;

	short point1, point2;								//�����������;
	int y_base;											//ÿ��ͨ���Ļ���;
	int index;
	int Xtmp;

	switch (m_pointsNumFlag)
	{
	case POINTONE:
		addnum = 10;
		break;
	case POINTTWO:
		addnum = 5;
		break;
	case POINTFIVE:
		addnum = 2;
		break;
	case POINTTEN:
		addnum = 1;
		break;
	default:
		break;
	}
	Xtmp = drawque[0].size();
	for (int i = 0; i < Xtmp; i += addnum) {
		if (m_Xcoor == 0) {
			RECT rect1;
			rect1.left = 0;
			rect1.top = 0;
			rect1.right = m_Xcoor + 2;
			rect1.bottom = y_maxHeight;
			RECT rect2;
			rect2.left = 0;
			rect2.top = y_maxHeight;
			rect2.right = xWidth;
			rect2.bottom = y_maxHeight;
			MemDC.FillRect(&rect1, &bRush);
			MemDC.FillRect(&rect2, &bRush);
		}
		else {
			RECT rect3;
			rect3.left = m_Xcoor + 1;
			rect3.top = 0;
			rect3.right = m_Xcoor + 2;
			rect3.bottom = y_maxHeight;
			MemDC.FillRect(&rect3, &bRush);
		}
		for (j = 0; j < ChannelNum; j++) {
		//if (!m_channelstatue[j])
		//{
		//	continue;
		//}
		if (drawque[j].size() > 0)
		{
			point1 = pBufferTemp[j][0];
			point2 = drawque[j].front();
			y_base = gm_nStartPointy + gm_nRangeY * (j + 1) - y_scale / 2;
			if (y_base >= yHeight)
				y_base = yHeight;
			MemDC.MoveTo(m_Xcoor, y_base + point1);
			MemDC.LineTo(m_Xcoor + 1, y_base + point2);
			pBufferTemp[j][0] = drawque[j].front();
			//fprintf(fpmodel2_eeg[j + 1], "%f ", pBufferTemp[j][0]);
			drawque[j].pop();
		}
		}
		m_Xcoor += 1;
		if (m_Xcoor == xWidth) {
			m_Xcoor = 0;
		}
	}

	//Xtmp = drawque[0].size();
	//for (int i = 0; i < Xtmp; i += addnum) {
	//	if (m_Xcoor == 0) {
	//		RECT rect1;
	//		rect1.left = 0;
	//		rect1.top = 0;
	//		rect1.right = m_Xcoor + 2;
	//		rect1.bottom = y_maxHeight;
	//		RECT rect2;
	//		rect2.left = 0;
	//		rect2.top = y_maxHeight;
	//		rect2.right = xWidth;
	//		rect2.bottom = y_maxHeight;
	//		MemDC.FillRect(&rect1, &bRush);
	//		MemDC.FillRect(&rect2, &bRush);
	//	}
	//	else {
	//		RECT rect3;
	//		rect3.left = m_Xcoor + 1;
	//		rect3.top = 0;
	//		rect3.right = m_Xcoor + 2;
	//		rect3.bottom = y_maxHeight;
	//		MemDC.FillRect(&rect3, &bRush);
	//	}
	//	for (j = 0; j < ChannelNum; j++) {
	//		//if (!m_channelstatue[j])
	//		//{
	//		//	continue;
	//		//}
	//		if (drawque[j].size()>0)
	//		{
	//			point1 = pBufferTemp[j][0];
	//			point2 = m_pBuffer[j][i];
	//			y_base = gm_nStartPointy + gm_nRangeY * (j + 1) - y_scale / 2;
	//			if (y_base >= yHeight)
	//				y_base = yHeight;
	//			MemDC.MoveTo(m_Xcoor, y_base + point1);
	//			MemDC.LineTo(m_Xcoor + 1, y_base + point2);
	//			pBufferTemp[j][0] = m_pBuffer[j][i];
	//			fprintf(fpmodel2_eeg[j + 1], "%f ", pBufferTemp[j][0]);
	//			drawque[j].pop();
	//		}
	//	}
	//	m_Xcoor += 1;
	//	if (m_Xcoor == xWidth) {
	//		m_Xcoor = 0;
	//	}
	//}


	m_CollectTimes += drawque[0].size();								//ÿ���Լ�1��ʾ��ǰ�ɼ�����;
	if (m_CollectTimes > collecttime || m_CollectTimes == collecttime)
	{
		m_CollectTimes = 0;
		++m_TotalTime;
		int minute = m_TotalTime / 60;					//���㾭���˶��ٷ���;
		int second = m_TotalTime - minute * 60;			//������;
		CString strnull = _T("00");
		CString strminute = _T("");
		CString strsecond = _T("");
		strminute.Format(_T("%d"), minute);
		strsecond.Format(_T("%d"), second);
		CString strtime = strminute + ":" + strsecond;
		MemDC.TextOut(m_Xcoor - 30, y_maxHeight - 20, strtime);
		}

	MemDC.SelectObject(poldPen);
	DeleteObject(PenForCurve);
	MemDC.SelectObject(poldBrush);
	DeleteObject(bRush);
	
	
}

void CMFC_EEGDlg::OnBnClickedXminus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_pointsNumFlag--;
	if (m_pointsNumFlag == 0)
	{
		CButton *pxsBtn = (CButton*)GetDlgItem(IDC_XMINUS);
		pxsBtn->EnableWindow(FALSE);
	}
	else if (m_pointsNumFlag != 3)
	{
		CButton *pxzBtn = (CButton*)GetDlgItem(IDC_XPLUS);
		pxzBtn->EnableWindow(TRUE);
	}
}

void CMFC_EEGDlg::OnBnClickedXplus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_pointsNumFlag++;
	if (m_pointsNumFlag == 3)
	{
		CButton *pxzBtn = (CButton*)GetDlgItem(IDC_XPLUS);
		pxzBtn->EnableWindow(FALSE);
	}
	else if (m_pointsNumFlag != 0)
	{
		CButton *pxsBtn = (CButton*)GetDlgItem(IDC_XMINUS);
		pxsBtn->EnableWindow(TRUE);
	}
}

void CMFC_EEGDlg::OnBnClickedYminus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	y_scale /= 2;
	if (y_scale <= 2)
	{
		CButton *pzBtn = (CButton*)GetDlgItem(IDC_YMINUS);
		pzBtn->EnableWindow(FALSE);
	}
	if (y_scale <1024 * 1024)
	{
		CButton *psBtn = (CButton*)GetDlgItem(IDC_YPLUS);
		psBtn->EnableWindow(TRUE);
	}
}

void CMFC_EEGDlg::OnBnClickedYplus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	y_scale *= 2;
	if (y_scale >= 1024 * 1024)
	{
		CButton *pzBtn = (CButton*)GetDlgItem(IDC_YPLUS);
		pzBtn->EnableWindow(FALSE);
	}
	if (y_scale > 2)
	{

		CButton *psBtn = (CButton*)GetDlgItem(IDC_YMINUS);
		psBtn->EnableWindow(TRUE);
	}
}

void CMFC_EEGDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	tinerCount++;
	if (tinerCount > 0xFFFF)
		tinerCount = 0;
	CDC *pDC = GetDC();								//����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
	/*if (pDC == nullptr)											//���pDC�Ƿ���Ч;
	{
		MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"), _T("WARNING"), MB_ICONWARNING | MB_OK);	//��pDC��Ч�����һ��������Ϣ;
	}
	MemDC_flash.CreateCompatibleDC(pDC);						//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
	MemBitMap_flash.CreateCompatibleBitmap(pDC, 80, 80);	      //��ʼ��һ����pDC��ָ����豸���ݵ�λͼ;
	MemDC_flash.SelectObject(&MemBitMap_flash);	*/			//��MemBitMap����ѡ���豸��������;
	if (tinerCount % 3 == 0)
	{
		/*CBrush bRush(RGB(255, 255, 255));  //����ɫ�����ʹ���
		CBrush *poldBrush = MemDC_flash.SelectObject(&bRush);						//���˻�ˢѡ���ڴ�DC��; 
		RECT rect_flash;
		rect_flash.left = 0;
		rect_flash.top = 0;
		rect_flash.right = 80;
		rect_flash.bottom = 80;

		MemDC.FillRect(&rect_flash, &bRush);
		pDC->BitBlt(1270, 300, 1350, 3800, &MemDC_flash, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		ReleaseDC(pDC);										//�ͷ��豸������;
		pDC = nullptr;
		MemDC.DeleteDC();*/
		CRect rt(1270, 300, 1350, 380);
		//pDC->FillSolidRect(&rt, RGB(255, 255, 255));//��ɫ���
		

	}//����һ����ˢ�����;
	else
	{
		/*CBrush bRush(RGB(0, 0, 0));		 //����ɫ
		CBrush *poldBrush = MemDC_flash.SelectObject(&bRush);						//���˻�ˢѡ���ڴ�DC��;  
		RECT rect_flash;
		rect_flash.left = 0;
		rect_flash.top = 0;
		rect_flash.right = 80;
		rect_flash.bottom = 80;

		MemDC.FillRect(&rect_flash, &bRush);

		pDC->BitBlt(1270, 300, 1350, 3800, &MemDC_flash, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		ReleaseDC(pDC);										//�ͷ��豸������;
		pDC = nullptr;
		MemDC.DeleteDC();*/
		CRect rt(1270, 300, 1350, 380);
		//pDC->FillSolidRect(&rt, RGB(0, 0, 0));
		return;
	}
	DWORD  numberOfWrite = 0;
	while(!WriteFile(m_Com, &content, 1, &numberOfWrite, NULL));
	//int i = GetLastError();
	CDialogEx::OnTimer(nIDEvent);
}

//ѡ��
void CMFC_EEGDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CComboBox* h_Comb = (CComboBox*)GetDlgItem(IDC_COMBO6);
	int position=h_Comb->GetCurSel();
	h_Comb->GetLBText(position, m_SelCommName);
	//USB_State.SetWindowText(m_SelCommName);
}

//������ʾ
void CMFC_EEGDlg::OnCbnDropdownCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strTemp;
	HANDLE  hCom;
	CComboBox* h_Comb = (CComboBox*)GetDlgItem(IDC_COMBO6);
	h_Comb->ResetContent();
	int n;
	CStringArray names;
	//����ȡ���ľ����ӵ���������
	n = GetCommNames(names);
	for (int i = 0; i < n; i++) {
		h_Comb->AddString(names.GetAt(i));
	}
}

//�����ͼ��Ӧ��ť
void CMFC_EEGDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//---------ԭ����-------------//
	//if (!DisInOneDlg)
	//{
	//	PlotDialogflag[0] = true;

	//	Plot17To32 = new CChannel17To32();
	//	Plot17To32->IsReDraw = true;
	//	Plot17To32->Create(IDD_DIALOG17_32); //��ģ̬�Ի���ID��
	//	//Plot17To32->OnPaint();
	//	Plot17To32->ShowWindow(SW_SHOW);
	//}
	//else
	//{
	//	ChannelOffset = 16;
	//	CString strTemp;
	//	for (int i = 0; i < 8; i++)
	//	{
	//		strTemp.Format(_T("%d"), i + ChannelOffset + 1);
	//		SetDlgItemText(IDC_CHECK1 + i, strTemp);
	//	}
	//	for (int i = 8; i < 16; i++)
	//	{
	//		strTemp.Format(_T("%d"), i + ChannelOffset + 1);
	//		SetDlgItemText(IDC_CHECK9 + i - 8, strTemp);
	//	}
	//}

	//----------32ͨ�����续ͼ-------------//
	DrawModel = true;
	if (Acquisitionmode == false)
	{
		ChannelNum = 16;
	}
	else
	{
		ChannelNum = 32;
	}
}

void CMFC_EEGDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!DisInOneDlg)
	{
		PlotDialogflag[1] = true;

		Plot33To48 = new CChannel33To48();
		Plot33To48->IsReDraw = true;
		Plot33To48->Create(IDD_DIALOG33_48);   //��ģ̬�Ի���ID��
		//Plot33To48->OnPaint();
		Plot33To48->ShowWindow(SW_SHOW);
	}
	else
	{
		ChannelOffset = 32;
		CString strTemp;
		for (int i = 0; i < 8; i++)
		{
			strTemp.Format(_T("%d"), i + ChannelOffset + 1);
			SetDlgItemText(IDC_CHECK1 + i, strTemp);
		}
		for (int i = 8; i < 16; i++)
		{
			strTemp.Format(_T("%d"), i + ChannelOffset + 1);
			SetDlgItemText(IDC_CHECK9 + i - 8, strTemp);
		}
	}
}

void CMFC_EEGDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!DisInOneDlg)
	{
		PlotDialogflag[2] = true;

		Plot49To64 = new CChannel49To64();
		Plot49To64->IsReDraw = true;
		Plot49To64->Create(IDD_DIALOG49_64); //��ģ̬�Ի���ID��
		//Plot49To64->OnPaint();
		Plot49To64->ShowWindow(SW_SHOW);
	}
	else
	{
		ChannelOffset = 48;
		CString strTemp;
		for (int i = 0; i < 8; i++)
		{
			strTemp.Format(_T("%d"), i + ChannelOffset + 1);
			SetDlgItemText(IDC_CHECK1 + i, strTemp);
		}
		for (int i = 8; i < 16; i++)
		{
			strTemp.Format(_T("%d"), i + ChannelOffset + 1);
			SetDlgItemText(IDC_CHECK9 + i - 8, strTemp);
		}

	}
}

//�Ե��ͼ��Ӧ��ť
void CMFC_EEGDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ChannelOffset = 0;
	CString strTemp;
	for (int i = 0; i < 8; i++)
	{
		strTemp.Format(_T("%d"), i + ChannelOffset + 1);
		SetDlgItemText(IDC_CHECK1 + i, strTemp);
	}
	for (int i = 8; i < 16; i++)
	{
		strTemp.Format(_T("%d"), i + ChannelOffset+1);
		SetDlgItemText(IDC_CHECK9 + i - 8, strTemp);
	}
	
	DrawModel = false;
	if (Acquisitionmode==false)
	{
		ChannelNum = 16;
	}
	else
	{
		ChannelNum = 64;
	}
}

void CMFC_EEGDlg::OnBnClickedCheck17()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	DisInOneDlg = !DisInOneDlg;
	if (DisInOneDlg == false)
		ChannelOffset = 0;

}

void CMFC_EEGDlg::OnBnClickedCheck16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[15] = !m_channelstatue[15];
}

void CMFC_EEGDlg::OnBnClickedCheck15()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[14] = !m_channelstatue[14];
}

void CMFC_EEGDlg::OnBnClickedCheck14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[13] = !m_channelstatue[13];
}

void CMFC_EEGDlg::OnBnClickedCheck13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[12] = !m_channelstatue[12];
}

void CMFC_EEGDlg::OnBnClickedCheck12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[11] = !m_channelstatue[11];
}

void CMFC_EEGDlg::OnBnClickedCheck11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[10] = !m_channelstatue[10];
}

void CMFC_EEGDlg::OnBnClickedCheck10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[9] = !m_channelstatue[9];
}

void CMFC_EEGDlg::OnBnClickedCheck9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[8] = !m_channelstatue[8];
}

void CMFC_EEGDlg::OnBnClickedCheck8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[7] = !m_channelstatue[7];
}

void CMFC_EEGDlg::OnBnClickedCheck7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[6] = !m_channelstatue[6];
}

void CMFC_EEGDlg::OnBnClickedCheck6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[5] = !m_channelstatue[5];
}

void CMFC_EEGDlg::OnBnClickedCheck5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[4] = !m_channelstatue[4];
}

void CMFC_EEGDlg::OnBnClickedCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[3] = !m_channelstatue[3];
}

void CMFC_EEGDlg::OnBnClickedCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[2] = !m_channelstatue[2];
}

void CMFC_EEGDlg::OnBnClickedCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[1] = !m_channelstatue[1];
}

void CMFC_EEGDlg::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[0] = !m_channelstatue[0];
}


//�˲�1K������
void CMFC_EEGDlg::Filter_One()
{
	float fSum;  //���IIR�������� 
	double tempp = 0;
	float* q;
	//// TODO: �ڴ˴����ʵ�ִ���.
	for (int i = 0; i < ChannelNum ; i++)
	{
			for (int j = 0; j < que[i].size(); j++)
			{
				tempp = que[i].front();    //AD�����ĵ�ѹֵ
				que[i].pop();
				switch (i)
				{
				case 0: {
					q = p0 + 1;
					if (q > & IIRBuffer[0][IIR_L])//
						q = q - IIR_L - 1;//
					*p0 = tempp - (*q) * (Den);
					fSum = (*p0) * Num + (*q) * (-Num);
					p0++;
					if (p0 > & IIRBuffer[0][IIR_L])//
						p0 = &IIRBuffer[0][0];
					break;
				}
				case 1: {
					q = p1 + 1;
					if (q > & IIRBuffer[1][IIR_L])
						q = q - IIR_L - 1;
					*p1 = tempp - (*q) * (Den);
					fSum = (*p1) * Num + (*q) * (-Num);
					p1++;
					if (p1 > & IIRBuffer[1][IIR_L])
						p1 = &IIRBuffer[1][0];
					break;
				}
				case 2: {
					q = p2 + 1;
					if (q > & IIRBuffer[2][IIR_L])
						q = q - IIR_L - 1;
					*p2 = tempp - (*q) * (Den);
					fSum = (*p2) * Num + (*q) * (-Num);
					p2++;
					if (p2 > & IIRBuffer[2][IIR_L])
						p2 = &IIRBuffer[2][0];
					break;
				}
				case 3: {
					q = p3 + 1;
					if (q > & IIRBuffer[3][IIR_L])
						q = q - IIR_L - 1;
					*p3 = tempp - (*q) * (Den);
					fSum = (*p3) * Num + (*q) * (-Num);
					p3++;
					if (p3 > & IIRBuffer[3][IIR_L])
						p3 = &IIRBuffer[3][0];
					break;
				}
				case 4: {
					q = p4 + 1;
					if (q > & IIRBuffer[4][IIR_L])
						q = q - IIR_L - 1;
					*p4 = tempp - (*q) * (Den);
					fSum = (*p4) * Num + (*q) * (-Num);
					p4++;
					if (p4 > & IIRBuffer[4][IIR_L])
						p4 = &IIRBuffer[4][0];
					break;
				}
				case 5: {
					q = p5 + 1;
					if (q > & IIRBuffer[5][IIR_L])
						q = q - IIR_L - 1;
					*p5 = tempp - (*q) * (Den);
					fSum = (*p5) * Num + (*q) * (-Num);
					p5++;
					if (p5 > & IIRBuffer[5][IIR_L])
						p5 = &IIRBuffer[5][0];
					break;
				}
				case 6: {
					q = p6 + 1;
					if (q > & IIRBuffer[6][IIR_L])
						q = q - IIR_L - 1;
					*p6 = tempp - (*q) * (Den);
					fSum = (*p6) * Num + (*q) * (-Num);
					p6++;
					if (p6 > & IIRBuffer[6][IIR_L])
						p6 = &IIRBuffer[6][0];
					break;
				}
				case 7: {
					q = p7 + 1;
					if (q > & IIRBuffer[7][IIR_L])
						q = q - IIR_L - 1;
					*p7 = tempp - (*q) * (Den);
					fSum = (*p7) * Num + (*q) * (-Num);
					p7++;
					if (p7 > & IIRBuffer[7][IIR_L])
						p7 = &IIRBuffer[7][0];
					break;
				}
				case 8: {
					q = p8 + 1;
					if (q > & IIRBuffer[8][IIR_L])
						q = q - IIR_L - 1;
					*p8 = tempp - (*q) * (Den);
					fSum = (*p8) * Num + (*q) * (-Num);
					p8++;
					if (p8 > & IIRBuffer[8][IIR_L])
						p8 = &IIRBuffer[8][0];
					break;
				}
				case 9: {
					q = p9 + 1;
					if (q > & IIRBuffer[9][IIR_L])
						q = q - IIR_L - 1;
					*p9 = tempp - (*q) * (Den);
					fSum = (*p9) * Num + (*q) * (-Num);
					p9++;
					if (p9 > & IIRBuffer[9][IIR_L])
						p9 = &IIRBuffer[9][0];
					break;
				}
				case 10: {
					q = p10 + 1;
					if (q > & IIRBuffer[10][IIR_L])
						q = q - IIR_L - 1;
					*p10 = tempp - (*q) * (Den);
					fSum = (*p10) * Num + (*q) * (-Num);
					p10++;
					if (p10 > & IIRBuffer[10][IIR_L])
						p10 = &IIRBuffer[10][0];
					break;
				}
				case 11: {
					q = p11 + 1;
					if (q > & IIRBuffer[11][IIR_L])
						q = q - IIR_L - 1;
					*p11 = tempp - (*q) * (Den);
					fSum = (*p11) * Num + (*q) * (-Num);
					p11++;
					if (p11 > & IIRBuffer[11][IIR_L])
						p11 = &IIRBuffer[11][0];
					break;
				}
				case 12: {
					q = p12 + 1;
					if (q > & IIRBuffer[12][IIR_L])
						q = q - IIR_L - 1;
					*p12 = tempp - (*q) * (Den);
					fSum = (*p12) * Num + (*q) * (-Num);
					p12++;
					if (p12 > & IIRBuffer[12][IIR_L])
						p12 = &IIRBuffer[12][0];
					break;
				}
				case 13: {
					q = p13 + 1;
					if (q > & IIRBuffer[13][IIR_L])
						q = q - IIR_L - 1;
					*p13 = tempp - (*q) * (Den);
					fSum = (*p13) * Num + (*q) * (-Num);
					p13++;
					if (p13 > & IIRBuffer[13][IIR_L])
						p13 = &IIRBuffer[13][0];
					break;
				}
				case 14: {
					q = p14 + 1;
					if (q > & IIRBuffer[14][IIR_L])
						q = q - IIR_L - 1;
					*p14 = tempp - (*q) * (Den);
					fSum = (*p14) * Num + (*q) * (-Num);
					p14++;
					if (p14 > & IIRBuffer[14][IIR_L])
						p14 = &IIRBuffer[14][0];
					break;
				}
				case 15: {
					q = p15 + 1;
					if (q > & IIRBuffer[15][IIR_L])
						q = q - IIR_L - 1;
					*p15 = tempp - (*q) * (Den);
					fSum = (*p15) * Num + (*q) * (-Num);
					p15++;
					if (p15 > & IIRBuffer[15][IIR_L])
						p15 = &IIRBuffer[15][0];
					break;
				}
				case 16: {
					q = p16 + 1;
					if (q > & IIRBuffer[16][IIR_L])//
						q = q - IIR_L - 1;//
					*p16 = tempp - (*q) * (Den);
					fSum = (*p16) * Num + (*q) * (-Num);
					p16++;
					if (p16 > & IIRBuffer[16][IIR_L])//
						p16 = &IIRBuffer[16][0];
					break;
				}
				case 17: {
					q = p17 + 1;
					if (q > & IIRBuffer[17][IIR_L])
						q = q - IIR_L - 1;
					*p17 = tempp - (*q) * (Den);
					fSum = (*p17) * Num + (*q) * (-Num);
					p17++;
					if (p17 > & IIRBuffer[17][IIR_L])
						p17 = &IIRBuffer[17][0];
					break;
				}
				case 18: {
					q = p18 + 1;
					if (q > & IIRBuffer[18][IIR_L])
						q = q - IIR_L - 1;
					*p18 = tempp - (*q) * (Den);
					fSum = (*p18) * Num + (*q) * (-Num);
					p18++;
					if (p18 > & IIRBuffer[18][IIR_L])
						p18 = &IIRBuffer[18][0];
					break;
				}
				case 19: {
					q = p19 + 1;
					if (q > & IIRBuffer[19][IIR_L])
						q = q - IIR_L - 1;
					*p19 = tempp - (*q) * (Den);
					fSum = (*p19) * Num + (*q) * (-Num);
					p19++;
					if (p19 > & IIRBuffer[19][IIR_L])
						p19 = &IIRBuffer[19][0];
					break;
				}
				case 20: {
					q = p20 + 1;
					if (q > & IIRBuffer[20][IIR_L])
						q = q - IIR_L - 1;
					*p20 = tempp - (*q) * (Den);
					fSum = (*p20) * Num + (*q) * (-Num);
					p20++;
					if (p20 > & IIRBuffer[20][IIR_L])
						p20 = &IIRBuffer[20][0];
					break;
				}
				case 21: {
					q = p21 + 1;
					if (q > & IIRBuffer[21][IIR_L])
						q = q - IIR_L - 1;
					*p21 = tempp - (*q) * (Den);
					fSum = (*p21) * Num + (*q) * (-Num);
					p21++;
					if (p21 > & IIRBuffer[21][IIR_L])
						p21 = &IIRBuffer[21][0];
					break;
				}
				case 22: {
					q = p22 + 1;
					if (q > & IIRBuffer[22][IIR_L])
						q = q - IIR_L - 1;
					*p22 = tempp - (*q) * (Den);
					fSum = (*p22) * Num + (*q) * (-Num);
					p22++;
					if (p22 > & IIRBuffer[22][IIR_L])
						p22 = &IIRBuffer[22][0];
					break;
				}
				case 23: {
					q = p23 + 1;
					if (q > & IIRBuffer[23][IIR_L])
						q = q - IIR_L - 1;
					*p23 = tempp - (*q) * (Den);
					fSum = (*p23) * Num + (*q) * (-Num);
					p23++;
					if (p23 > & IIRBuffer[23][IIR_L])
						p23 = &IIRBuffer[23][0];
					break;
				}
				case 24: {
					q = p24 + 1;
					if (q > & IIRBuffer[24][IIR_L])
						q = q - IIR_L - 1;
					*p24 = tempp - (*q) * (Den);
					fSum = (*p24) * Num + (*q) * (-Num);
					p24++;
					if (p24 > & IIRBuffer[24][IIR_L])
						p24 = &IIRBuffer[24][0];
					break;
				}
				case 25: {
					q = p25 + 1;
					if (q > & IIRBuffer[25][IIR_L])
						q = q - IIR_L - 1;
					*p25 = tempp - (*q) * (Den);
					fSum = (*p25) * Num + (*q) * (-Num);
					p25++;
					if (p25 > & IIRBuffer[25][IIR_L])
						p25 = &IIRBuffer[25][0];
					break;
				}
				case 26: {
					q = p26 + 1;
					if (q > & IIRBuffer[26][IIR_L])
						q = q - IIR_L - 1;
					*p26 = tempp - (*q) * (Den);
					fSum = (*p26) * Num + (*q) * (-Num);
					p26++;
					if (p26 > & IIRBuffer[26][IIR_L])
						p26 = &IIRBuffer[26][0];
					break;
				}
				case 27: {
					q = p27 + 1;
					if (q > & IIRBuffer[27][IIR_L])
						q = q - IIR_L - 1;
					*p27 = tempp - (*q) * (Den);
					fSum = (*p27) * Num + (*q) * (-Num);
					p27++;
					if (p27 > & IIRBuffer[27][IIR_L])
						p27 = &IIRBuffer[27][0];
					break;
				}
				case 28: {
					q = p28 + 1;
					if (q > & IIRBuffer[28][IIR_L])
						q = q - IIR_L - 1;
					*p28 = tempp - (*q) * (Den);
					fSum = (*p28) * Num + (*q) * (-Num);
					p28++;
					if (p28 > & IIRBuffer[28][IIR_L])
						p28 = &IIRBuffer[28][0];
					break;
				}
				case 29: {
					q = p29 + 1;
					if (q > & IIRBuffer[29][IIR_L])
						q = q - IIR_L - 1;
					*p29 = tempp - (*q) * (Den);
					fSum = (*p29) * Num + (*q) * (-Num);
					p29++;
					if (p29 > & IIRBuffer[29][IIR_L])
						p29 = &IIRBuffer[29][0];
					break;
				}
				case 30: {
					q = p30 + 1;
					if (q > & IIRBuffer[30][IIR_L])
						q = q - IIR_L - 1;
					*p30 = tempp - (*q) * (Den);
					fSum = (*p30) * Num + (*q) * (-Num);
					p30++;
					if (p30 > & IIRBuffer[30][IIR_L])
						p30 = &IIRBuffer[30][0];
					break;
				}
				case 31: {
					q = p31 + 1;
					if (q > & IIRBuffer[31][IIR_L])
						q = q - IIR_L - 1;
					*p31 = tempp - (*q) * (Den);
					fSum = (*p31) * Num + (*q) * (-Num);
					p31++;
					if (p31 > & IIRBuffer[31][IIR_L])
						p31 = &IIRBuffer[31][0];
					break;
				}
				case 32: {
					q = p32 + 1;
					if (q > & IIRBuffer[32][IIR_L])
						q = q - IIR_L - 1;
					*p32 = tempp - (*q) * (Den);
					fSum = (*p32) * Num + (*q) * (-Num);
					p32++;
					if (p32 > & IIRBuffer[32][IIR_L])
						p32 = &IIRBuffer[32][0];
					break;
				}
				case 33: {
					q = p33 + 1;
					if (q > & IIRBuffer[33][IIR_L])
						q = q - IIR_L - 1;
					*p33 = tempp - (*q) * (Den);
					fSum = (*p33) * Num + (*q) * (-Num);
					p33++;
					if (p33 > & IIRBuffer[33][IIR_L])
						p33 = &IIRBuffer[33][0];
					break;
				}
				case 34: {
					q = p34 + 1;
					if (q > & IIRBuffer[34][IIR_L])
						q = q - IIR_L - 1;
					*p34 = tempp - (*q) * (Den);
					fSum = (*p34) * Num + (*q) * (-Num);
					p34++;
					if (p34 > & IIRBuffer[34][IIR_L])
						p34 = &IIRBuffer[34][0];
					break;
				}
				case 35: {
					q = p35 + 1;
					if (q > & IIRBuffer[35][IIR_L])
						q = q - IIR_L - 1;
					*p35 = tempp - (*q) * (Den);
					fSum = (*p35) * Num + (*q) * (-Num);
					p35++;
					if (p35 > & IIRBuffer[35][IIR_L])
						p35 = &IIRBuffer[35][0];
					break;
				}
				case 36: {
					q = p36 + 1;
					if (q > & IIRBuffer[36][IIR_L])
						q = q - IIR_L - 1;
					*p36 = tempp - (*q) * (Den);
					fSum = (*p36) * Num + (*q) * (-Num);
					p36++;
					if (p36 > & IIRBuffer[36][IIR_L])
						p36 = &IIRBuffer[36][0];
					break;
				}
				case 37: {
					q = p37 + 1;
					if (q > & IIRBuffer[37][IIR_L])
						q = q - IIR_L - 1;
					*p37 = tempp - (*q) * (Den);
					fSum = (*p37) * Num + (*q) * (-Num);
					p37++;
					if (p37 > & IIRBuffer[37][IIR_L])
						p37 = &IIRBuffer[37][0];
					break;
				}
				case 38: {
					q = p38 + 1;
					if (q > & IIRBuffer[38][IIR_L])
						q = q - IIR_L - 1;
					*p38 = tempp - (*q) * (Den);
					fSum = (*p38) * Num + (*q) * (-Num);
					p38++;
					if (p38 > & IIRBuffer[38][IIR_L])
						p38 = &IIRBuffer[38][0];
					break;
				}
				case 39: {
					q = p39 + 1;
					if (q > & IIRBuffer[39][IIR_L])
						q = q - IIR_L - 1;
					*p39 = tempp - (*q) * (Den);
					fSum = (*p39) * Num + (*q) * (-Num);
					p39++;
					if (p39 > & IIRBuffer[39][IIR_L])
						p39 = &IIRBuffer[39][0];
					break;
				}
				case 40: {
					q = p40 + 1;
					if (q > & IIRBuffer[40][IIR_L])
						q = q - IIR_L - 1;
					*p40 = tempp - (*q) * (Den);
					fSum = (*p40) * Num + (*q) * (-Num);
					p40++;
					if (p40 > & IIRBuffer[40][IIR_L])
						p40 = &IIRBuffer[40][0];
					break;
				}
				case 41: {
					q = p41 + 1;
					if (q > & IIRBuffer[41][IIR_L])
						q = q - IIR_L - 1;
					*p41 = tempp - (*q) * (Den);
					fSum = (*p41) * Num + (*q) * (-Num);
					p41++;
					if (p41 > & IIRBuffer[41][IIR_L])
						p41 = &IIRBuffer[41][0];
					break;
				}
				case 42: {
					q = p42 + 1;
					if (q > & IIRBuffer[42][IIR_L])
						q = q - IIR_L - 1;
					*p42 = tempp - (*q) * (Den);
					fSum = (*p42) * Num + (*q) * (-Num);
					p42++;
					if (p42 > & IIRBuffer[42][IIR_L])
						p42 = &IIRBuffer[42][0];
					break;
				}
				case 43: {
					q = p43 + 1;
					if (q > & IIRBuffer[43][IIR_L])
						q = q - IIR_L - 1;
					*p43 = tempp - (*q) * (Den);
					fSum = (*p43) * Num + (*q) * (-Num);
					p43++;
					if (p43 > & IIRBuffer[43][IIR_L])
						p43 = &IIRBuffer[43][0];
					break;
				}
				case 44: {
					q = p44 + 1;
					if (q > & IIRBuffer[44][IIR_L])
						q = q - IIR_L - 1;
					*p44 = tempp - (*q) * (Den);
					fSum = (*p44) * Num + (*q) * (-Num);
					p44++;
					if (p44 > & IIRBuffer[44][IIR_L])
						p44 = &IIRBuffer[44][0];
					break;
				}
				case 45: {
					q = p45 + 1;
					if (q > & IIRBuffer[45][IIR_L])
						q = q - IIR_L - 1;
					*p45 = tempp - (*q) * (Den);
					fSum = (*p45) * Num + (*q) * (-Num);
					p45++;
					if (p45 > & IIRBuffer[45][IIR_L])
						p45 = &IIRBuffer[45][0];
					break;
				}
				case 46: {
					q = p46 + 1;
					if (q > & IIRBuffer[46][IIR_L])
						q = q - IIR_L - 1;
					*p46 = tempp - (*q) * (Den);
					fSum = (*p46) * Num + (*q) * (-Num);
					p46++;
					if (p46 > & IIRBuffer[46][IIR_L])
						p46 = &IIRBuffer[46][0];
					break;
				}
				case 47: {
					q = p47 + 1;
					if (q > & IIRBuffer[47][IIR_L])
						q = q - IIR_L - 1;
					*p47 = tempp - (*q) * (Den);
					fSum = (*p47) * Num + (*q) * (-Num);
					p47++;
					if (p47 > & IIRBuffer[47][IIR_L])
						p47 = &IIRBuffer[47][0];
					break;
				}
				case 48: {
					q = p48 + 1;
					if (q > & IIRBuffer[48][IIR_L])
						q = q - IIR_L - 1;
					*p48 = tempp - (*q) * (Den);
					fSum = (*p48) * Num + (*q) * (-Num);
					p48++;
					if (p48 > & IIRBuffer[48][IIR_L])
						p48 = &IIRBuffer[48][0];
					break;
				}
				case 49: {
					q = p49 + 1;
					if (q > & IIRBuffer[49][IIR_L])
						q = q - IIR_L - 1;
					*p49 = tempp - (*q) * (Den);
					fSum = (*p49) * Num + (*q) * (-Num);
					p49++;
					if (p49 > & IIRBuffer[49][IIR_L])
						p49 = &IIRBuffer[49][0];
					break;
				}
				case 50: {
					q = p50 + 1;
					if (q > & IIRBuffer[50][IIR_L])
						q = q - IIR_L - 1;
					*p50 = tempp - (*q) * (Den);
					fSum = (*p50) * Num + (*q) * (-Num);
					p50++;
					if (p50 > & IIRBuffer[50][IIR_L])
						p50 = &IIRBuffer[50][0];
					break;
				}
				case 51: {
					q = p51 + 1;
					if (q > & IIRBuffer[51][IIR_L])
						q = q - IIR_L - 1;
					*p51 = tempp - (*q) * (Den);
					fSum = (*p51) * Num + (*q) * (-Num);
					p51++;
					if (p51 > & IIRBuffer[51][IIR_L])
						p51 = &IIRBuffer[51][0];
					break;
				}
				case 52: {
					q = p52 + 1;
					if (q > & IIRBuffer[52][IIR_L])
						q = q - IIR_L - 1;
					*p52 = tempp - (*q) * (Den);
					fSum = (*p52) * Num + (*q) * (-Num);
					p52++;
					if (p52 > & IIRBuffer[52][IIR_L])
						p52 = &IIRBuffer[52][0];
					break;
				}
				case 53: {
					q = p53 + 1;
					if (q > & IIRBuffer[53][IIR_L])
						q = q - IIR_L - 1;
					*p53 = tempp - (*q) * (Den);
					fSum = (*p53) * Num + (*q) * (-Num);
					p53++;
					if (p53 > & IIRBuffer[53][IIR_L])
						p53 = &IIRBuffer[53][0];
					break;
				}
				case 54: {
					q = p55 + 1;
					if (q > & IIRBuffer[55][IIR_L])
						q = q - IIR_L - 1;
					*p55 = tempp - (*q) * (Den);
					fSum = (*p55) * Num + (*q) * (-Num);
					p55++;
					if (p55 > & IIRBuffer[55][IIR_L])
						p55 = &IIRBuffer[55][0];
					break;
				}
				case 55: {
					q = p55 + 1;
					if (q > & IIRBuffer[55][IIR_L])
						q = q - IIR_L - 1;
					*p55 = tempp - (*q) * (Den);
					fSum = (*p55) * Num + (*q) * (-Num);
					p55++;
					if (p55 > & IIRBuffer[55][IIR_L])
						p55 = &IIRBuffer[55][0];
					break;
				}
				case 56: {
					q = p56 + 1;
					if (q > & IIRBuffer[56][IIR_L])
						q = q - IIR_L - 1;
					*p56 = tempp - (*q) * (Den);
					fSum = (*p56) * Num + (*q) * (-Num);
					p56++;
					if (p56 > & IIRBuffer[56][IIR_L])
						p56 = &IIRBuffer[56][0];
					break;
				}
				case 57: {
					q = p57 + 1;
					if (q > & IIRBuffer[57][IIR_L])
						q = q - IIR_L - 1;
					*p57 = tempp - (*q) * (Den);
					fSum = (*p57) * Num + (*q) * (-Num);
					p57++;
					if (p57 > & IIRBuffer[57][IIR_L])
						p57 = &IIRBuffer[57][0];
					break;
				}
				case 58: {
					q = p58 + 1;
					if (q > & IIRBuffer[58][IIR_L])
						q = q - IIR_L - 1;
					*p58 = tempp - (*q) * (Den);
					fSum = (*p58) * Num + (*q) * (-Num);
					p58++;
					if (p58 > & IIRBuffer[58][IIR_L])
						p58 = &IIRBuffer[58][0];
					break;
				}
				case 59: {
					q = p59 + 1;
					if (q > & IIRBuffer[59][IIR_L])
						q = q - IIR_L - 1;
					*p59 = tempp - (*q) * (Den);
					fSum = (*p59) * Num + (*q) * (-Num);
					p59++;
					if (p59 > & IIRBuffer[59][IIR_L])
						p59 = &IIRBuffer[59][0];
					break;
				}
				case 60: {
					q = p60 + 1;
					if (q > & IIRBuffer[60][IIR_L])
						q = q - IIR_L - 1;
					*p60 = tempp - (*q) * (Den);
					fSum = (*p60) * Num + (*q) * (-Num);
					p60++;
					if (p60 > & IIRBuffer[60][IIR_L])
						p60 = &IIRBuffer[60][0];
					break;
				}
				case 61: {
					q = p61 + 1;
					if (q > & IIRBuffer[61][IIR_L])
						q = q - IIR_L - 1;
					*p61 = tempp - (*q) * (Den);
					fSum = (*p61) * Num + (*q) * (-Num);
					p61++;
					if (p61 > & IIRBuffer[61][IIR_L])
						p61 = &IIRBuffer[61][0];
					break;
				}
				case 62: {
					q = p62 + 1;
					if (q > & IIRBuffer[62][IIR_L])
						q = q - IIR_L - 1;
					*p62 = tempp - (*q) * (Den);
					fSum = (*p62) * Num + (*q) * (-Num);
					p62++;
					if (p62 > & IIRBuffer[62][IIR_L])
						p62 = &IIRBuffer[62][0];
					break;
				}
				case 63: {
					q = p63 + 1;
					if (q > & IIRBuffer[63][IIR_L])
						q = q - IIR_L - 1;
					*p63 = tempp - (*q) * (Den);
					fSum = (*p63) * Num + (*q) * (-Num);
					p63++;
					if (p63 > & IIRBuffer[63][IIR_L])
						p63 = &IIRBuffer[63][0];
					break;
				}
				   defult: {
					   fSum = tempp;
					   break;
				}
				}
				m_pBuffer[i][j] = (double)((fSum - 8388608) / 0xFFFFFF * y_scale * (-1));
				//fprintf(fpmodel2_eeg[i + 1], "%f ", m_pBuffer[i][j]);
				drawque[i].push(m_pBuffer[i][j]);
			}
	}
}

//�˲�20K������
void CMFC_EEGDlg::Filter_Twenty()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	float fSum;  //���IIR�������� 
	double tem = 0;
	float* q;

	if (que[0].size()>0)
	{
		for (int i = 0; i < ChannelNum; i++)
		{
			for (int j = 0; j < que[i].size(); j++)
			{
				tem = que[i].front();    //AD�����ĵ�ѹֵ
				que[i].pop();
				switch (i)
				{
				case 0: {
					q = emg_p0 + 1;
					if (q > & EMG_IIRBuffer[0][EMG_IIR_L])//
						q = q - EMG_IIR_L - 1;//
					*emg_p0 = tem - (*q) * (Den);
					fSum = (*emg_p0) * Num + (*q) * (-Num);
					emg_p0++;
					if (emg_p0 > & EMG_IIRBuffer[0][EMG_IIR_L])//
						emg_p0 = &EMG_IIRBuffer[0][0];
					break;
				}
				case 1: {
					q = emg_p1 + 1;
					if (q > & EMG_IIRBuffer[1][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p1 = tem - (*q) * (Den);
					fSum = (*emg_p1) * Num + (*q) * (-Num);
					emg_p1++;
					if (emg_p1 > & EMG_IIRBuffer[1][EMG_IIR_L])
						emg_p1 = &EMG_IIRBuffer[1][0];
					break;
				}
				case 2: {
					q = emg_p2 + 1;
					if (q > & EMG_IIRBuffer[2][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p2 = tem - (*q) * (Den);
					fSum = (*emg_p2) * Num + (*q) * (-Num);
					emg_p2++;
					if (emg_p2 > & EMG_IIRBuffer[2][EMG_IIR_L])
						emg_p2 = &EMG_IIRBuffer[2][0];
					break;
				}
				case 3: {
					q = emg_p3 + 1;
					if (q > & EMG_IIRBuffer[3][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p3 = tem - (*q) * (Den);
					fSum = (*emg_p3) * Num + (*q) * (-Num);
					emg_p3++;
					if (emg_p3 > & EMG_IIRBuffer[3][EMG_IIR_L])
						emg_p3 = &EMG_IIRBuffer[3][0];
					break;
				}
				case 4: {
					q = emg_p4 + 1;
					if (q > & EMG_IIRBuffer[4][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p4 = tem - (*q) * (Den);
					fSum = (*emg_p4) * Num + (*q) * (-Num);
					emg_p4++;
					if (emg_p4 > & EMG_IIRBuffer[4][EMG_IIR_L])
						emg_p4 = &EMG_IIRBuffer[4][0];
					break;
				}
				case 5: {
					q = emg_p5 + 1;
					if (q > & EMG_IIRBuffer[5][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p5 = tem - (*q) * (Den);
					fSum = (*emg_p5) * Num + (*q) * (-Num);
					emg_p5++;
					if (emg_p5 > & EMG_IIRBuffer[5][EMG_IIR_L])
						emg_p5 = &EMG_IIRBuffer[5][0];
					break;
				}
				case 6: {
					q = emg_p6 + 1;
					if (q > & EMG_IIRBuffer[6][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p6 = tem - (*q) * (Den);
					fSum = (*emg_p6) * Num + (*q) * (-Num);
					emg_p6++;
					if (emg_p6 > & EMG_IIRBuffer[6][EMG_IIR_L])
						emg_p6 = &EMG_IIRBuffer[6][0];
					break;
				}
				case 7: {
					q = emg_p7 + 1;
					if (q > & EMG_IIRBuffer[7][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p7 = tem - (*q) * (Den);
					fSum = (*emg_p7) * Num + (*q) * (-Num);
					emg_p7++;
					if (emg_p7 > & EMG_IIRBuffer[7][EMG_IIR_L])
						emg_p7 = &EMG_IIRBuffer[7][0];
					break;
				}
				case 8: {
					q = emg_p8 + 1;
					if (q > & EMG_IIRBuffer[8][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p8 = tem - (*q) * (Den);
					fSum = (*emg_p8) * Num + (*q) * (-Num);
					emg_p8++;
					if (emg_p8 > & EMG_IIRBuffer[8][EMG_IIR_L])
						emg_p8 = &EMG_IIRBuffer[8][0];
					break;
				}
				case 9: {
					q = emg_p9 + 1;
					if (q > & EMG_IIRBuffer[9][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p9 = tem - (*q) * (Den);
					fSum = (*emg_p9) * Num + (*q) * (-Num);
					emg_p9++;
					if (emg_p9 > & EMG_IIRBuffer[9][EMG_IIR_L])
						emg_p9 = &EMG_IIRBuffer[9][0];
					break;
				}
				case 10: {
					q = emg_p10 + 1;
					if (q > & EMG_IIRBuffer[10][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p10 = tem - (*q) * (Den);
					fSum = (*emg_p10) * Num + (*q) * (-Num);
					emg_p10++;
					if (emg_p10 > & EMG_IIRBuffer[10][EMG_IIR_L])
						emg_p10 = &EMG_IIRBuffer[10][0];
					break;
				}
				case 11: {
					q = emg_p11 + 1;
					if (q > & EMG_IIRBuffer[11][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p11 = tem - (*q) * (Den);
					fSum = (*emg_p11) * Num + (*q) * (-Num);
					emg_p11++;
					if (emg_p11 > & EMG_IIRBuffer[11][EMG_IIR_L])
						emg_p11 = &EMG_IIRBuffer[11][0];
					break;
				}
				case 12: {
					q = emg_p12 + 1;
					if (q > & EMG_IIRBuffer[12][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p12 = tem - (*q) * (Den);
					fSum = (*emg_p12) * Num + (*q) * (-Num);
					emg_p12++;
					if (emg_p12 > & EMG_IIRBuffer[12][EMG_IIR_L])
						emg_p12 = &EMG_IIRBuffer[12][0];
					break;
				}
				case 13: {
					q = emg_p13 + 1;
					if (q > & EMG_IIRBuffer[13][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p13 = tem - (*q) * (Den);
					fSum = (*emg_p13) * Num + (*q) * (-Num);
					emg_p13++;
					if (emg_p13 > & EMG_IIRBuffer[13][EMG_IIR_L])
						emg_p13 = &EMG_IIRBuffer[13][0];
					break;
				}
				case 14: {
					q = emg_p14 + 1;
					if (q > & EMG_IIRBuffer[14][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p14 = tem - (*q) * (Den);
					fSum = (*emg_p14) * Num + (*q) * (-Num);
					emg_p14++;
					if (emg_p14 > & EMG_IIRBuffer[14][EMG_IIR_L])
						emg_p14 = &EMG_IIRBuffer[14][0];
					break;
				}
				case 15: {
					q = emg_p15 + 1;
					if (q > & EMG_IIRBuffer[15][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p15 = tem - (*q) * (Den);
					fSum = (*emg_p15) * Num + (*q) * (-Num);
					emg_p15++;
					if (emg_p15 > & EMG_IIRBuffer[15][EMG_IIR_L])
						emg_p15 = &EMG_IIRBuffer[15][0];
					break;
				}
				case 16: {
					q = emg_p16 + 1;
					if (q > & EMG_IIRBuffer[16][EMG_IIR_L])//
						q = q - EMG_IIR_L - 1;//
					*emg_p16 = tem - (*q) * (Den);
					fSum = (*emg_p16) * Num + (*q) * (-Num);
					emg_p16++;
					if (emg_p16 > & EMG_IIRBuffer[16][EMG_IIR_L])//
						emg_p16 = &EMG_IIRBuffer[16][0];
					break;
				}
				case 17: {
					q = emg_p17 + 1;
					if (q > & EMG_IIRBuffer[17][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p17 = tem - (*q) * (Den);
					fSum = (*emg_p17) * Num + (*q) * (-Num);
					emg_p17++;
					if (emg_p17 > & EMG_IIRBuffer[17][EMG_IIR_L])
						emg_p17 = &EMG_IIRBuffer[17][0];
					break;
				}
				case 18: {
					q = emg_p18 + 1;
					if (q > & EMG_IIRBuffer[18][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p18 = tem - (*q) * (Den);
					fSum = (*emg_p18) * Num + (*q) * (-Num);
					emg_p18++;
					if (emg_p18 > & EMG_IIRBuffer[18][EMG_IIR_L])
						emg_p18 = &EMG_IIRBuffer[18][0];
					break;
				}
				case 19: {
					q = emg_p19 + 1;
					if (q > & EMG_IIRBuffer[19][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p19 = tem - (*q) * (Den);
					fSum = (*emg_p19) * Num + (*q) * (-Num);
					emg_p19++;
					if (emg_p19 > & EMG_IIRBuffer[19][EMG_IIR_L])
						emg_p19 = &EMG_IIRBuffer[19][0];
					break;
				}
				case 20: {
					q = emg_p20 + 1;
					if (q > & EMG_IIRBuffer[20][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p20 = tem - (*q) * (Den);
					fSum = (*emg_p20) * Num + (*q) * (-Num);
					emg_p20++;
					if (emg_p20 > & EMG_IIRBuffer[20][EMG_IIR_L])
						emg_p20 = &EMG_IIRBuffer[20][0];
					break;
				}
				case 21: {
					q = emg_p21 + 1;
					if (q > & EMG_IIRBuffer[21][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p21 = tem - (*q) * (Den);
					fSum = (*emg_p21) * Num + (*q) * (-Num);
					emg_p21++;
					if (emg_p21 > & EMG_IIRBuffer[21][EMG_IIR_L])
						emg_p21 = &EMG_IIRBuffer[21][0];
					break;
				}
				case 22: {
					q = emg_p22 + 1;
					if (q > & EMG_IIRBuffer[22][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p22 = tem - (*q) * (Den);
					fSum = (*emg_p22) * Num + (*q) * (-Num);
					emg_p22++;
					if (emg_p22 > & EMG_IIRBuffer[22][EMG_IIR_L])
						emg_p22 = &EMG_IIRBuffer[22][0];
					break;
				}
				case 23: {
					q = emg_p23 + 1;
					if (q > & EMG_IIRBuffer[23][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p23 = tem - (*q) * (Den);
					fSum = (*emg_p23) * Num + (*q) * (-Num);
					emg_p23++;
					if (emg_p23 > & EMG_IIRBuffer[23][EMG_IIR_L])
						emg_p23 = &EMG_IIRBuffer[23][0];
					break;
				}
				case 24: {
					q = emg_p24 + 1;
					if (q > & EMG_IIRBuffer[24][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p24 = tem - (*q) * (Den);
					fSum = (*emg_p24) * Num + (*q) * (-Num);
					emg_p24++;
					if (emg_p24 > & EMG_IIRBuffer[24][EMG_IIR_L])
						emg_p24 = &EMG_IIRBuffer[24][0];
					break;
				}
				case 25: {
					q = emg_p25 + 1;
					if (q > & EMG_IIRBuffer[25][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p25 = tem - (*q) * (Den);
					fSum = (*emg_p25) * Num + (*q) * (-Num);
					emg_p25++;
					if (emg_p25 > & EMG_IIRBuffer[25][EMG_IIR_L])
						emg_p25 = &EMG_IIRBuffer[25][0];
					break;
				}
				case 26: {
					q = emg_p26 + 1;
					if (q > & EMG_IIRBuffer[26][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p26 = tem - (*q) * (Den);
					fSum = (*emg_p26) * Num + (*q) * (-Num);
					emg_p26++;
					if (emg_p26 > & EMG_IIRBuffer[26][EMG_IIR_L])
						emg_p26 = &EMG_IIRBuffer[26][0];
					break;
				}
				case 27: {
					q = emg_p27 + 1;
					if (q > & EMG_IIRBuffer[27][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p27 = tem - (*q) * (Den);
					fSum = (*emg_p27) * Num + (*q) * (-Num);
					emg_p27++;
					if (emg_p27 > & EMG_IIRBuffer[27][EMG_IIR_L])
						emg_p27 = &EMG_IIRBuffer[27][0];
					break;
				}
				case 28: {
					q = emg_p28 + 1;
					if (q > & EMG_IIRBuffer[28][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p28 = tem - (*q) * (Den);
					fSum = (*emg_p28) * Num + (*q) * (-Num);
					emg_p28++;
					if (emg_p28 > & EMG_IIRBuffer[28][EMG_IIR_L])
						emg_p28 = &EMG_IIRBuffer[28][0];
					break;
				}
				case 29: {
					q = emg_p29 + 1;
					if (q > & EMG_IIRBuffer[29][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p29 = tem - (*q) * (Den);
					fSum = (*emg_p29) * Num + (*q) * (-Num);
					emg_p29++;
					if (emg_p29 > & EMG_IIRBuffer[29][EMG_IIR_L])
						emg_p29 = &EMG_IIRBuffer[29][0];
					break;
				}
				case 30: {
					q = emg_p30 + 1;
					if (q > & EMG_IIRBuffer[30][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p30 = tem - (*q) * (Den);
					fSum = (*emg_p30) * Num + (*q) * (-Num);
					emg_p30++;
					if (emg_p30 > & EMG_IIRBuffer[30][EMG_IIR_L])
						emg_p30 = &EMG_IIRBuffer[30][0];
					break;
				}
				case 31: {
					q = emg_p31 + 1;
					if (q > & EMG_IIRBuffer[31][EMG_IIR_L])
						q = q - EMG_IIR_L - 1;
					*emg_p31 = tem - (*q) * (Den);
					fSum = (*emg_p31) * Num + (*q) * (-Num);
					emg_p31++;
					if (emg_p31 > & EMG_IIRBuffer[31][EMG_IIR_L])
						emg_p31 = &EMG_IIRBuffer[31][0];
					break;
				}


				}
				m_pBuffer[i][j] = (double)((fSum - 8388608) / 0xFFFFFF * y_scale * (-1));
				drawque[i].push(m_pBuffer[i][j]);
			}
		}
	}
	
}

//ģʽ��
void CMFC_EEGDlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Acquisitionmode = true;
	//CButton* pBtnmodel2 = (CButton*)GetDlgItem(IDC_BUTTON10);
	//pBtnmodel2->EnableWindow(0);// disable it

	//CButton* pBtnmodel1 = (CButton*)GetDlgItem(IDC_STARTMEG);
	//pBtnmodel1->EnableWindow(0);// disable it

	int ReqCode = 0xA2;                            //��ʼ���͸�FPGAģʽһ����
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0xA2;
	buf[1] = 0xA2;
	buf[2] = 0xA2;
	buf[3] = 0xA2;
	buf[4] = 0xA2;
	WriteParam(ReqCode, Value, Index, buf, buflen);
	ChannelNum =64;

}

//ģʽһ
void CMFC_EEGDlg::OnBnmodel1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Acquisitionmode = false;
	//CButton* pBtnmodel1 = (CButton*)GetDlgItem(IDC_STARTMEG);
	//pBtnmodel1->EnableWindow(0);// disable it
	//CButton* pBtnmodel2 = (CButton*)GetDlgItem(IDC_BUTTON10);
	//pBtnmodel2->EnableWindow(0);// disable it

	int ReqCode = 0xA1;                            //��ʼ���͸�FPGAģʽһ����
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0xA1;
	buf[1] = 0xA1;
	buf[2] = 0xA1;
	buf[3] = 0xA1;
	buf[4] = 0xA1;
	WriteParam(ReqCode, Value, Index, buf, buflen);

}

//��ɼ��巢���迹���ָ��
void CMFC_EEGDlg::OnBnClickedImpedance()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ReqCode = 0xA3;                            //��ʼ���͸�FPGAģʽһ����
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0xA3;
	buf[1] = 0xA3;
	buf[2] = 0xA3;
	buf[3] = 0xA3;
	buf[4] = 0xA3;
	WriteParam(ReqCode, Value, Index, buf, buflen);

	//�����༭��
	CString m_staticCaption;
	int m_counts;
	if (Acquisitionmode == false) {
		m_counts = 16;
	}
	else {
		m_counts = 64;
	}
	int perWidth = (ScreeRrect.right - 90) / 5;
	int perHeight = (ScreeRrect.bottom-100 ) / m_counts;


	for (int i = 0; i < m_counts; i++)
	{
		p_MyStatic = new CStatic();
		p_MyEdit = new CEdit();
		m_staticCaption.Format(_T("��%dͨ��:"), i + 1);
		if (i % 2 == 0)
		{
			p_MyStatic->Create(m_staticCaption, WS_CHILD | WS_VISIBLE | SS_CENTER| SS_CENTERIMAGE, CRect(200, 50+i * perHeight + 5, perWidth, 60+(i + 1) * perHeight + 5), this);
			p_MyEdit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | SS_CENTERIMAGE, CRect(200+perWidth, 50+i * perHeight + 5, perWidth * 2, 55+(i + 1) * perHeight + 5), this, IDC_EDIT_STATE + i);
			if (p_MyStatic != NULL)
			{
				p_MyStatics.Add((void*)p_MyStatic);
			}
			if (p_MyEdit != NULL)
			{
				p_MyEdits.Add((void*)p_MyEdit);
			}
		}
		else
		{
			p_MyStatic->Create(m_staticCaption, WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, CRect(200+perWidth * 2, 50+(i - 1) * perHeight + 5, perWidth * 3, 60+i * perHeight + 5), this);
			p_MyEdit->Create(WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER | SS_CENTERIMAGE, CRect(200+perWidth * 3, 50+(i - 1) * perHeight + 5, perWidth * 4, 55+i * perHeight + 5), this, IDC_EDIT_STATE + i);
			if (p_MyStatic != NULL)
			{
				p_MyStatics.Add((void*)p_MyStatic);
			}
			if (p_MyEdit != NULL)
			{
				p_MyEdits.Add((void*)p_MyEdit);
			}
		}
	}

}

//ÿ�ζ�ȡ�ɼ��巢�͵��迹
void CMFC_EEGDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString m_staticCaption;
	long bufflen = BufferSize;
	UCHAR pCollectData[BufferSize];					//�ɼ�������������1���ֽ�Ϊ��С;
	int pDataBuffer[64] = { 0 };
	outfile = fopen("Test1.txt", "wb");
	
	int ReqCode = 0xA5;                            //��ʼ���͸�FPGAģʽһ����
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0xA5;
	buf[1] = 0xA5;
	buf[2] = 0xA5;
	buf[3] = 0xA5;
	buf[4] = 0xA5;
	WriteParam(ReqCode, Value, Index, buf, buflen);


	
	bool IsDataColOk = false;	//IsDataColOk���ڱ�ʾ���ݲɼ��Ƿ�ɹ�;
	if (pCollectData && pDataBuffer)
	{
		ZeroMemory(pCollectData, BufferSize);						//��մ��ԭʼ���ݻ�����;
		ZeroMemory(pDataBuffer, ArrSize);						//��մ��ƴ�Ӻ�����ݻ�����
		IsDataColOk = InEndpt->XferData(pCollectData, bufflen);
		//IsDataColOk = ReadImpedance(pCollectData, 64);
		if (!IsDataColOk)
		{
			USB_State.SetWindowText(_T("�迹��ȡʧ��"));
		}
		else {
			int j = 0;
			//ģʽһ�迹
			j = j + 2;
			for (int index = 0; index < 64; index++)
			{
				pDataBuffer[index] = pCollectData[j] ^ 0x80;
				++j;
				pDataBuffer[index] = (pDataBuffer[index] << 8) | pCollectData[j];
				++j;
			}
			for (int j = 0; j < 512; j++)
			{
				fprintf(outfile, "%X ", pCollectData[j]);
			}
		}
	}
	int n = p_MyEdits.GetSize();
	for (int i = 0; i < n; i++)
	{
		m_staticCaption.Format(L"%d K", pDataBuffer[i]);//(int)(pDataBuffer[i]/655));
		//USB_State.SetWindowText(m_staticCaption);
		CEdit* pEdit = (CEdit*)p_MyEdits.GetAt(i);
		if (pEdit != NULL)
		{
			pEdit->SetWindowText(m_staticCaption);
		}
	}
}

//ֹͣ�迹���
void CMFC_EEGDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int ReqCode = 0xA6;                            //��ʼ���͸�FPGAģʽһ����
	int Value = 0;
	int Index = 0;
	PUCHAR buf = new UCHAR[5];

	ZeroMemory(buf, 5);
	LONG buflen = 5;
	buf[0] = 0xA6;
	buf[1] = 0xA6;
	buf[2] = 0xA6;
	buf[3] = 0xA6;
	buf[4] = 0xA6;
	WriteParam(ReqCode, Value, Index, buf, buflen);
	

	int n = p_MyStatics.GetSize();
	for (int i = 0; i < n; i++)
	{
		CStatic* pStatic = (CStatic*)p_MyStatics.GetAt(i);
		if (pStatic != NULL)
			delete pStatic;
		p_MyStatics[i] = NULL;
	}
	p_MyStatics.RemoveAll();
	n = p_MyEdits.GetSize();
	for (int i = 0; i < n; i++)
	{
		CEdit* pEdit = (CEdit*)p_MyEdits.GetAt(i);
		if (pEdit != NULL)
			delete pEdit;
		p_MyEdits[i] = NULL;
	}
	p_MyEdits.RemoveAll();



}


HBRUSH CMFC_EEGDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	HBRUSH hBrush;

	hBrush = CreateSolidBrush(RGB(255, 255, 255)); //����ɫ
	
	// TODO:  �ڴ˸��� DC ���κ�����
	if (nCtlColor == CTLCOLOR_STATIC)

	{
		pDC->SetBkColor(RGB(255, 255, 255)); //���屳��ɫ 
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hBrush;
}

//����ѡ����Ӧ��ť
void CMFC_EEGDlg::OnBnSerialConnection()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	InitComm();
	SelModel = true;
	CButton* pBtn = (CButton*)GetDlgItem(IDC_CONNECTAMP);
	pBtn->EnableWindow(0);// disable it
}

//��ȡ��������
int CMFC_EEGDlg::GetCommNames(CStringArray& names)
{
	int tmp;
	if (names.GetCount() > 0)
		names.RemoveAll();
	CString strTemp;
	HANDLE  hCom;

	int j = 0;
	for (int i = 0; i < 10; i++)
	{
		strTemp.Format(_T("COM%d"), i + 1);
		hCom = CreateFile(strTemp, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (INVALID_HANDLE_VALUE == hCom)
			continue;
		else {
			names.Add(strTemp);
			j++;
		}
		CloseHandle(hCom);
	}
	for (int i = 10; i < 20; i++)
	{
		strTemp.Format(_T("\\\\.\\COM%d"), i);
		hCom = CreateFile(strTemp, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
		if (INVALID_HANDLE_VALUE == hCom)
			continue;
		else {
			names.Add(strTemp);
			j++;
		}
		CloseHandle(hCom);
	}
	tmp = (int)names.GetCount();
	return tmp;
}

//��ʼ������
void CMFC_EEGDlg::InitComm()
{
	m_CommHandle = CreateFile(m_SelCommName,                             //�򿪴���
		GENERIC_READ | GENERIC_WRITE, //�������д
		0, NULL, OPEN_EXISTING, //�򿪶����Ǵ���
		0,/*FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,*/ //�첽��ʽ
		NULL);

	if (m_CommHandle == INVALID_HANDLE_VALUE)//(HANDLE)-1) 
	{
		AfxMessageBox(_T("��COMʧ��"), MB_OKCANCEL | MB_ICONQUESTION, 0);
	}

	if (!SetupComm(m_CommHandle, 1024, 1024))   //���뻺����������������Ĵ�С����1024
	{
		AfxMessageBox(_T("���ڻ���������ʧ��"), MB_OKCANCEL | MB_ICONQUESTION, 0);
	}
	COMMTIMEOUTS TimeOuts;
	//�趨����ʱ
	TimeOuts.ReadIntervalTimeout = 100;
	TimeOuts.ReadTotalTimeoutMultiplier = 500;
	TimeOuts.ReadTotalTimeoutConstant = 500;
	//�趨д��ʱ
	TimeOuts.WriteTotalTimeoutMultiplier = 500;
	TimeOuts.WriteTotalTimeoutConstant = 2000;
	if (!SetCommTimeouts(m_CommHandle, &TimeOuts))	 //���ó�ʱ
	{
		AfxMessageBox(_T("�򿪴���ʧ��"), MB_OKCANCEL | MB_ICONQUESTION, 0);
	}

	DCB dcb;
	GetCommState(m_CommHandle, &dcb);
	dcb.fDtrControl = DTR_CONTROL_DISABLE;
	dcb.fRtsControl = RTS_CONTROL_DISABLE;
	dcb.BaudRate = 921600; //������Ϊ921600
	dcb.ByteSize = 8; //ÿ���ֽ���8λ
	dcb.Parity = NOPARITY; //����żУ��λ
	dcb.StopBits = ONESTOPBIT; //һ��ֹͣλ
	bool state = SetCommState(m_CommHandle, &dcb);
	if (state != true)
	{
		AfxMessageBox(_T("�������ݸ�ʽ����ʧ��"), MB_OKCANCEL | MB_ICONQUESTION, 0);
	}
	int i = GetLastError();
	GetCommState(m_CommHandle, &dcb);

	PurgeComm(m_CommHandle, PURGE_TXCLEAR | PURGE_RXCLEAR);//�ڶ�д����֮ǰ����Ҫ��PurgeComm()������ջ��������ú���ԭ�ͣ�
	//timer = SetTimer(1, period, NULL);          //���ö�ʱ��1�Ķ�ʱ���

}
//���ڲɼ��߳�
UINT CMFC_EEGDlg::CollectComDataFowADSThread(LPVOID pParam)
{
	CMFC_EEGDlg* comm = (CMFC_EEGDlg*)pParam;
	return comm->CollectComDataFowADS();
}

UINT  CMFC_EEGDlg::CollectComDataFowADS()
{
	unsigned char pCollectData[BufferSize] = { 0 };					//�ɼ�������������1���ֽ�Ϊ��С;
	UINT pDataBuffer[Model2_EEG_ChannelNum] = { 0 };
	double EEGBuffer[Model2_EEG_ChannelNum] = { 0 };
	CString str;
	double EEGBufferTemp[Model2_EEG_ChannelNum];

	while (CollectComData)                                                
	{
		//		WaitForSingleObject(m_hEventForCollect, INFINITE);	//ֻ���¼������ڷ���״̬ʱ�ú����ŷ���,Ȼ��ִ�б������Ĵ���,�ú���һ���������¼�������δ����״̬;
		bool IsDataColOk = false;	//IsDataColOk���ڱ�ʾ���ݲɼ��Ƿ�ɹ�;
		unsigned char Plot_time = 0;					//�ɼ�������������1���ֽ�Ϊ��С;
		DWORD readcount = 0;

		for (int time = 0; time < 1; time++)
		{
			if (pCollectData && pDataBuffer)
			{
				ZeroMemory(pCollectData, BufferSize);						//��մ��ԭʼ���ݻ�����;
				ZeroMemory(pDataBuffer, Model2_EEG_ChannelNum);						//��մ��ƴ�Ӻ�����ݻ�����;

			}
			if (!m_bIsStartofData)
			{
				ZeroMemory(pCollectData, 1);
				IsDataColOk = ReadFile(m_CommHandle, pCollectData, 1, &readcount, NULL);
				if (IsDataColOk)
				{
					if (pCollectData[0] == 0xaa)
					{
						ZeroMemory(pCollectData, 2);
						IsDataColOk = ReadFile(m_CommHandle, pCollectData, 2, &readcount, NULL);
						if (IsDataColOk)
						{
							if (pCollectData[0] == 0x55)
							{
								m_bIsStartofData = true;
								ZeroMemory(pCollectData, BufferSize - 3);
								IsDataColOk = ReadFile(m_CommHandle, pCollectData,192, &readcount, NULL);
								if (IsDataColOk)
								{
									unsigned int j = 0;
									unsigned int index = 0;
									for (int i = 0; i < 64; i++)
									{
										pDataBuffer[index] = pCollectData[j];
										pDataBuffer[index] <<= 8;
										++j;
										pDataBuffer[index] |= pCollectData[j];
										pDataBuffer[index] <<= 8;
										++j;
										pDataBuffer[index] |= pCollectData[j];
										++j;
										EEGBufferTemp[index] = (float)((long)(((pDataBuffer[index] - 8388608) / 8388608)) * 2500000);  //No Gain
										str.Format(_T("%10.4f "), (double)EEGBuffer[index] / 1e6);
										
									}
								}
							}
						}
					}
				}
			}
			else
			{
				if (pCollectData && pDataBuffer)
				{
					ZeroMemory(pCollectData, BufferSize);						//��մ��ԭʼ���ݻ�����;
					ZeroMemory(pDataBuffer, Model2_EEG_ChannelNum);						//��մ��ƴ�Ӻ�����ݻ�����;
					IsDataColOk = ReadFile(m_CommHandle, pCollectData, BufferSize, &readcount, NULL);
				}
				if (IsDataColOk)													//�ж����ݲɼ��Ƿ�ɹ�;
				{
					unsigned int j = 0;
					if (!((pCollectData[j] == 0xaa) && pCollectData[j + 1] == 0x55))   //Ѱ�Ұ������λ��
					{
						m_bIsStartofData = false;
						//p_ADSCollect->SetDlgItemText(IDC_EDIT1, _T("���ݶ��벻׼Data_Wrong"));
					}
					else
					{
						// marker = pCollectData[j + 2];
						for (Plot_time = 0; Plot_time < (BufferSize / 27); Plot_time++)
						{
							j = j + 3;
							unsigned int index = 0;										//indexΪƴ�Ӻ�������±�����;
							// fprintf(p_ADSCollect->fmaker, "%d ", pCollectData[j - 1]);
							for (index = 0; index < Model2_EEG_ChannelNum; index++)									//���´���Ϊ����ƴ�ӷ���;
							{
								pDataBuffer[index] = pCollectData[j] ^ 0x80;
								pDataBuffer[index] <<= 8;
								++j;
								pDataBuffer[index] |= pCollectData[j];
								pDataBuffer[index] <<= 8;
								++j;
								pDataBuffer[index] |= pCollectData[j];
								++j;
								EEGBufferTemp[index] = (float)((((pDataBuffer[index] - 8388608) / 8388608)) * 2500000);  //No Gain
								//filter_IIR[index]->filterData(EEGBufferTemp[index], &EEGBuffer[index]);
								//m_data.AddValue(index, EEGBuffer[index] / 1e6);
								//EEGBuffer[index] * 1000;
								str.Format(_T("%10.4f "), (double)EEGBuffer[index] / 1e6);
							
							}
						}
					}
				}
			}
		}
	}
	return 0;
}