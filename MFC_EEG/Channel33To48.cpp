// Channel33_48.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_EEG.h"
#include "Channel33To48.h"
#include "afxdialogex.h"


// CChannel33_48 �Ի���

IMPLEMENT_DYNAMIC(CChannel33To48, CDialogEx)

CChannel33To48::CChannel33To48(CWnd* pParent /*=NULL*/)
: CDialogEx(CChannel33To48::IDD, pParent)
{
	IsReDraw = true;
	m_Xcoor = 0;
}

CChannel33To48::~CChannel33To48()
{
}

void CChannel33To48::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
BOOL CChannel33To48::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_PICTURE2)->MoveWindow(CRect(10, 9, 1011, 811)); //�ڴ������Ͻ���ʾһ����100����100�ı༭�ؼ�
	return TRUE;                                                   // ���ǽ��������õ��ؼ������򷵻� TRUE
}
//void CChannel33To48::OnPaint()
//{
//	if (IsReDraw)
//	{
//		short xWidth = 1000;// x����Ϊ��;
//		short yHeight = 800;//y����Ϊ��;
//
//		//˫�����ͼ
//		CDC *pDC = GetDC();							 //����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
//		if (pDC == NULL)							//���pDC�Ƿ���Ч;
//		{
//			MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"));		//��pDC��Ч�����һ��������Ϣ;
//		}
//		MemDC.CreateCompatibleDC(pDC);							   		//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
//		MemBitMap.CreateCompatibleBitmap(pDC, xWidth, yHeight);			//��ʼ��һ����pDC��ָ����豸���ݵ�λͼ;
//		MemDC.SelectObject(&MemBitMap);
//		MemDC.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));					//���ض���ɫ���Ŀ�����;
//		pDC->BitBlt(10, 10, xWidth + 10, yHeight + 10, &MemDC, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
//		ReleaseDC(pDC);																	//�ͷ��豸������;
//		MemDC.DeleteDC();
//		pDC = nullptr;
//		IsReDraw = false;
//	}
//
//}

BEGIN_MESSAGE_MAP(CChannel33To48, CDialogEx)
	ON_WM_CLOSE()
	
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CHECK1, &CChannel33To48::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CChannel33To48::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CChannel33To48::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CChannel33To48::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CChannel33To48::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CChannel33To48::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CChannel33To48::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CChannel33To48::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CChannel33To48::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CChannel33To48::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CChannel33To48::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CChannel33To48::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CChannel33To48::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &CChannel33To48::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CChannel33To48::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &CChannel33To48::OnBnClickedCheck16)
END_MESSAGE_MAP()


// CChannel33_48 ��Ϣ�������
void CChannel33To48::DrawCurve(CDC &MemDC)
{
	CPen PenForCurve(PS_SOLID, 1, RGB(0, 0, 255));						//����һ�����������(���ڻ�����);
	CPen *poldPen = MemDC.SelectObject(&PenForCurve);					//������ѡ���豸��������;

	CBrush bRush(RGB(255, 255, 255));									//����һ����ˢ�����;
	CBrush *poldBrush = MemDC.SelectObject(&bRush);						//���˻�ˢѡ���ڴ�DC��;

	COLORREF OldColor = MemDC.SetTextColor(RGB(0, 0, 0));				//����ʱ��̶ȵ��ı���ɫ;

	//float y_scale = 18;							//y������Ŀ̶�   90/5
	short xWidth = 1000;								//x����Ϊ��;
	short yHeight = 800;								//yΪ��ͼ������Ϊ��;
	short y_maxHeight = 800;
	short gm_nRangeY = yHeight / 16-2;
	short gm_nStartPointy = gm_nRangeY / 2;
	int point_num[4] = { 1, 2, 5, 10 };					//��ʾÿ��ͨ���е�10����ȡ�����㻭ͼ;
	//int chanenum = 8;									//��ʾ�ڼ�ͨ��0->chan1,1->chan2.....;

	short point1, point2;								//�����������;
	int y_base;											//ÿ��ͨ���Ļ���;
	int index;
	switch (m_pointsNumFlag)
	{
	case POINTONE:
		for (int i = 0; i < RecvieveData[0].size(); i += 10)
		{
			if (m_Xcoor == 0)
			{
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
			else
			{
				RECT rect3;
				rect3.left = m_Xcoor + 1;
				rect3.top = 0;
				rect3.right = m_Xcoor + 2;
				rect3.bottom = y_maxHeight;

				MemDC.FillRect(&rect3, &bRush);
				/*for (int marker = 0; marker < 10; marker++)
				{
					if (i>marker && RecvieveData[ChannelNum][i - marker] != 0)
					{
						MemDC.MoveTo(m_Xcoor, 10);
						MemDC.LineTo(m_Xcoor, 810);
					}
				}*/
			}
			for (int j = 32; j < 48; ++j)
			{
				if (!m_channelstatue[j])
				{
					continue;
				}
				point1 = pBufferTemp[j][0] ;
				point2 = m_pBuffer[j][i] ;
				y_base = gm_nStartPointy + gm_nRangeY * (j - 32) + 30/*+ 0.5 + 170*/;
				MemDC.MoveTo(m_Xcoor, y_base + point1);
				MemDC.LineTo(m_Xcoor + 1, y_base + point2);
				pBufferTemp[j][0] = m_pBuffer[j][i];
			}
			m_Xcoor += 1;
			if (m_Xcoor == xWidth)
			{
				m_Xcoor = 0;
			}
		}
		break;
	case POINTTWO:
		for (int i = 0; i < RecvieveData[0].size(); i += 5)
		{
			if (m_Xcoor == 0)
			{
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
			else
			{
				RECT rect3;
				rect3.left = m_Xcoor + 1;
				rect3.top = 0;
				rect3.right = m_Xcoor + 2;
				rect3.bottom = y_maxHeight;

				MemDC.FillRect(&rect3, &bRush);
				/*for (int marker = 0; marker < 5; marker++)
				{
					if (i>marker && RecvieveData[ChannelNum][i - marker] != 0)
					{
						MemDC.MoveTo(m_Xcoor, 10);
						MemDC.LineTo(m_Xcoor, 810);
					}
				}*/
			}
			for (int j = 32; j < 48; ++j)
			{
				if (!m_channelstatue[j])
				{
					continue;
				}
				//index = i * 5 * ChannelNum + j;

				point1 = pBufferTemp[j][0] ;
				point2 = m_pBuffer[j][i] ;
				y_base = gm_nStartPointy + gm_nRangeY * (j - 32) + 30;
				MemDC.MoveTo(m_Xcoor, y_base + point1);
				MemDC.LineTo(m_Xcoor + 1, y_base + point2);
				pBufferTemp[j][0] = m_pBuffer[j][i];
			}
			m_Xcoor += 1;
			if (m_Xcoor == xWidth)
			{
				m_Xcoor = 0;
			}
		}
		break;
	case POINTFIVE:
		for (int i = 0; i < RecvieveData[0].size(); i += 2)
		{
			if (m_Xcoor == 0)
			{
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
			else
			{
				RECT rect3;
				rect3.left = m_Xcoor + 1;
				rect3.top = 0;
				rect3.right = m_Xcoor + 2;
				rect3.bottom = y_maxHeight;

				MemDC.FillRect(&rect3, &bRush);
				/*for (int marker = 0; marker < 2; marker++)
				{
					if (i>marker && RecvieveData[ChannelNum][i - marker] != 0)
					{
						MemDC.MoveTo(m_Xcoor, 10);
						MemDC.LineTo(m_Xcoor, 810);
					}
				}*/
			}
			for (int j = 32; j < 48; ++j)
			{
				if (!m_channelstatue[j])
				{
					continue;
				}
				point1 = pBufferTemp[j][0] ;
				//index = i * 2 * ChannelNum + j;
				point2 = m_pBuffer[j][i] ;
				y_base = (float)gm_nStartPointy + gm_nRangeY* (j - 32) + 30;
				MemDC.MoveTo(m_Xcoor, y_base + point1);
				MemDC.LineTo(m_Xcoor + 1, y_base + point2);
				pBufferTemp[j][0] = m_pBuffer[j][i];
			}
			m_Xcoor += 1;
			if (m_Xcoor == xWidth)
			{
				m_Xcoor = 0;
			}
		}
		break;
	case POINTTEN:
		for (int i = 0; i < RecvieveData[0].size(); i += 1)
		{
			if (m_Xcoor == 0)
			{
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
			else
			{
				RECT rect3;
				rect3.left = m_Xcoor + 1;
				rect3.top = 0;
				rect3.right = m_Xcoor + 2;
				rect3.bottom = y_maxHeight;

				MemDC.FillRect(&rect3, &bRush);
				/*if (RecvieveData[ChannelNum][i] != 0)
				{
					MemDC.MoveTo(m_Xcoor, 10);
					MemDC.LineTo(m_Xcoor, 810);
				}*/
			}
			for (int j = 32; j < 48; ++j)
			{
				if (!m_channelstatue[j])
				{
					continue;
				}
				point1 = pBufferTemp[j][0] ;
				//index = i * ChannelNum + j;
				point2 = m_pBuffer[j][i];
				y_base = (float)gm_nStartPointy + gm_nRangeY * (j - 32) + 30;
				MemDC.MoveTo(m_Xcoor, y_base + point1);
				MemDC.LineTo(m_Xcoor + 1, y_base + point2);
				pBufferTemp[j][0] = m_pBuffer[j][i];
			}
			m_Xcoor += 1;
			if (m_Xcoor == xWidth)
			{
				m_Xcoor = 0;
			}
		}
		break;
	default:
		break;
	}

	/*for (int i = 0; i != point_num; ++i)
	{
	if (m_Xcoor == 0)
	{
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
	else
	{
	RECT rect3;
	rect3.left = m_Xcoor + 1;
	rect3.top = 0;
	rect3.right = m_Xcoor + 2;
	rect3.bottom = y_maxHeight;

	MemDC.FillRect(&rect3, &bRush);
	}
	for (int j = 0; j != chanenum ; ++j)
	{
	point1 = pBufferTemp[j] * y_scale;
	index = i * 5 * chanenum + j;
	point2 = m_pBuffer[index] * y_scale;
	y_base = (float)gm_nStartPointy + gm_nRangeY * j + 0.5 + 170;
	MemDC.MoveTo(m_Xcoor, y_base + point1);
	MemDC.LineTo(m_Xcoor + 1, y_base + point2);
	pBufferTemp[j] = m_pBuffer[index];
	}
	m_Xcoor += 1;
	if (m_Xcoor == xWidth)
	{
	m_Xcoor = 0;
	}
	}*/

	/*m_CollectTimes += 1;								//ÿ���Լ�1��ʾ��ǰ�ɼ�����;
	short collecttime = 100;							//����ɼ���һǧ�ξ�Ӧ�ñ��ʱ��̶�;
	if (m_CollectTimes == collecttime)
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
	MemDC.TextOut(m_Xcoor - 50, y_maxHeight - 100, strtime);
	}*/
	MemDC.SelectObject(poldPen);
	MemDC.SelectObject(poldBrush);
	DeleteObject(bRush);
	DeleteObject(PenForCurve);
}

void CChannel33To48::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	PlotDialogflag[1] = false;
	DestroyWindow();
	CDialogEx::OnClose();
	delete this;
	
}


//void CChannel33To48::OnStnClickedPicture2()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


void CChannel33To48::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	CDialogEx::OnPaint();
	if (IsReDraw)
	{
		short xWidth = 1000;// x����Ϊ��;
		short yHeight = 800;//y����Ϊ��;

		//˫�����ͼ
		CDC *pDC = GetDC();							 //����ɹ�,����ָ�����ڿͻ������豸�����Ļ���;���ʧ��,����ֵΪNull;
		if (pDC == NULL)							//���pDC�Ƿ���Ч;
		{
			MessageBox(_T("��ÿͻ���ָ���豸�����Ļ���ָ��ʧ��"));		//��pDC��Ч�����һ��������Ϣ;
		}
		MemDC.CreateCompatibleDC(pDC);							   		//��������ΪNULL��ʾ�ú�������һ����ϵͳ��ʾ�����ݵ��ڴ��豸�����Ļ���;
		MemBitMap.CreateCompatibleBitmap(pDC, xWidth, yHeight);			//��ʼ��һ����pDC��ָ����豸���ݵ�λͼ;
		MemDC.SelectObject(&MemBitMap);
		MemDC.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));					//���ض���ɫ���Ŀ�����;
		pDC->BitBlt(10, 10, xWidth + 10, yHeight + 10, &MemDC, 0, 0, SRCCOPY);				//��MemBitMap�л��õ�ͼ�������ͻ���;
		ReleaseDC(pDC);																	//�ͷ��豸������;
		MemDC.DeleteDC();
		pDC = nullptr;
		IsReDraw = false;
	}
}


void CChannel33To48::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[32] = !m_channelstatue[32];
}


void CChannel33To48::OnBnClickedCheck2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[33] = !m_channelstatue[33];
}


void CChannel33To48::OnBnClickedCheck3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[34] = !m_channelstatue[34];
}


void CChannel33To48::OnBnClickedCheck4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[35] = !m_channelstatue[35];
}


void CChannel33To48::OnBnClickedCheck5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[36] = !m_channelstatue[36];
}


void CChannel33To48::OnBnClickedCheck6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[37] = !m_channelstatue[37];
}


void CChannel33To48::OnBnClickedCheck7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[38] = !m_channelstatue[38];
}


void CChannel33To48::OnBnClickedCheck8()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[39] = !m_channelstatue[39];
}


void CChannel33To48::OnBnClickedCheck9()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[40] = !m_channelstatue[40];
}


void CChannel33To48::OnBnClickedCheck10()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[41] = !m_channelstatue[41];
}


void CChannel33To48::OnBnClickedCheck11()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[42] = !m_channelstatue[42];
}


void CChannel33To48::OnBnClickedCheck12()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[43] = !m_channelstatue[43];
}


void CChannel33To48::OnBnClickedCheck13()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[44] = !m_channelstatue[44];
}


void CChannel33To48::OnBnClickedCheck14()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[45] = !m_channelstatue[45];
}


void CChannel33To48::OnBnClickedCheck15()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[46] = !m_channelstatue[46];
}


void CChannel33To48::OnBnClickedCheck16()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_channelstatue[47] = !m_channelstatue[47];
}
