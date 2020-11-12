// Channel33_48.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_EEG.h"
#include "Channel33To48.h"
#include "afxdialogex.h"


// CChannel33_48 对话框

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
	GetDlgItem(IDC_PICTURE2)->MoveWindow(CRect(10, 9, 1011, 811)); //在窗口左上角显示一个宽100、高100的编辑控件
	return TRUE;                                                   // 除非将焦点设置到控件，否则返回 TRUE
}
//void CChannel33To48::OnPaint()
//{
//	if (IsReDraw)
//	{
//		short xWidth = 1000;// x方向为宽;
//		short yHeight = 800;//y方向为高;
//
//		//双缓存绘图
//		CDC *pDC = GetDC();							 //如果成功,返回指定窗口客户区的设备上下文环境;如果失败,返回值为Null;
//		if (pDC == NULL)							//检查pDC是否有效;
//		{
//			MessageBox(_T("获得客户区指向设备上下文环境指针失败"));		//若pDC无效则输出一条警告信息;
//		}
//		MemDC.CreateCompatibleDC(pDC);							   		//函数参数为NULL表示该函数创建一个与系统显示区兼容的内存设备上下文环境;
//		MemBitMap.CreateCompatibleBitmap(pDC, xWidth, yHeight);			//初始化一个与pDC所指向的设备兼容的位图;
//		MemDC.SelectObject(&MemBitMap);
//		MemDC.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));					//以特定颜色填充目标矩形;
//		pDC->BitBlt(10, 10, xWidth + 10, yHeight + 10, &MemDC, 0, 0, SRCCOPY);				//将MemBitMap中画好的图拷贝到客户区;
//		ReleaseDC(pDC);																	//释放设备上下文;
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


// CChannel33_48 消息处理程序
void CChannel33To48::DrawCurve(CDC &MemDC)
{
	CPen PenForCurve(PS_SOLID, 1, RGB(0, 0, 255));						//构造一个画笔类对象(用于画曲线);
	CPen *poldPen = MemDC.SelectObject(&PenForCurve);					//将画笔选入设备描述表中;

	CBrush bRush(RGB(255, 255, 255));									//构造一个画刷类对象;
	CBrush *poldBrush = MemDC.SelectObject(&bRush);						//将此画刷选入内存DC中;

	COLORREF OldColor = MemDC.SetTextColor(RGB(0, 0, 0));				//设置时间刻度的文本颜色;

	//float y_scale = 18;							//y坐标轴的刻度   90/5
	short xWidth = 1000;								//x方向为宽;
	short yHeight = 800;								//y为绘图区域方向为高;
	short y_maxHeight = 800;
	short gm_nRangeY = yHeight / 16-2;
	short gm_nStartPointy = gm_nRangeY / 2;
	int point_num[4] = { 1, 2, 5, 10 };					//表示每个通道中的10个点取两个点画图;
	//int chanenum = 8;									//表示第几通道0->chan1,1->chan2.....;

	short point1, point2;								//两点的纵坐标;
	int y_base;											//每个通道的基线;
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

	/*m_CollectTimes += 1;								//每次自加1表示当前采集次数;
	short collecttime = 100;							//如果采集了一千次就应该标出时间刻度;
	if (m_CollectTimes == collecttime)
	{
	m_CollectTimes = 0;
	++m_TotalTime;
	int minute = m_TotalTime / 60;					//计算经过了多少分钟;
	int second = m_TotalTime - minute * 60;			//计算秒;
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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	PlotDialogflag[1] = false;
	DestroyWindow();
	CDialogEx::OnClose();
	delete this;
	
}


//void CChannel33To48::OnStnClickedPicture2()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}


void CChannel33To48::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	CDialogEx::OnPaint();
	if (IsReDraw)
	{
		short xWidth = 1000;// x方向为宽;
		short yHeight = 800;//y方向为高;

		//双缓存绘图
		CDC *pDC = GetDC();							 //如果成功,返回指定窗口客户区的设备上下文环境;如果失败,返回值为Null;
		if (pDC == NULL)							//检查pDC是否有效;
		{
			MessageBox(_T("获得客户区指向设备上下文环境指针失败"));		//若pDC无效则输出一条警告信息;
		}
		MemDC.CreateCompatibleDC(pDC);							   		//函数参数为NULL表示该函数创建一个与系统显示区兼容的内存设备上下文环境;
		MemBitMap.CreateCompatibleBitmap(pDC, xWidth, yHeight);			//初始化一个与pDC所指向的设备兼容的位图;
		MemDC.SelectObject(&MemBitMap);
		MemDC.FillSolidRect(0, 0, xWidth, yHeight, RGB(255, 255, 255));					//以特定颜色填充目标矩形;
		pDC->BitBlt(10, 10, xWidth + 10, yHeight + 10, &MemDC, 0, 0, SRCCOPY);				//将MemBitMap中画好的图拷贝到客户区;
		ReleaseDC(pDC);																	//释放设备上下文;
		MemDC.DeleteDC();
		pDC = nullptr;
		IsReDraw = false;
	}
}


void CChannel33To48::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[32] = !m_channelstatue[32];
}


void CChannel33To48::OnBnClickedCheck2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[33] = !m_channelstatue[33];
}


void CChannel33To48::OnBnClickedCheck3()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[34] = !m_channelstatue[34];
}


void CChannel33To48::OnBnClickedCheck4()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[35] = !m_channelstatue[35];
}


void CChannel33To48::OnBnClickedCheck5()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[36] = !m_channelstatue[36];
}


void CChannel33To48::OnBnClickedCheck6()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[37] = !m_channelstatue[37];
}


void CChannel33To48::OnBnClickedCheck7()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[38] = !m_channelstatue[38];
}


void CChannel33To48::OnBnClickedCheck8()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[39] = !m_channelstatue[39];
}


void CChannel33To48::OnBnClickedCheck9()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[40] = !m_channelstatue[40];
}


void CChannel33To48::OnBnClickedCheck10()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[41] = !m_channelstatue[41];
}


void CChannel33To48::OnBnClickedCheck11()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[42] = !m_channelstatue[42];
}


void CChannel33To48::OnBnClickedCheck12()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[43] = !m_channelstatue[43];
}


void CChannel33To48::OnBnClickedCheck13()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[44] = !m_channelstatue[44];
}


void CChannel33To48::OnBnClickedCheck14()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[45] = !m_channelstatue[45];
}


void CChannel33To48::OnBnClickedCheck15()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[46] = !m_channelstatue[46];
}


void CChannel33To48::OnBnClickedCheck16()
{
	// TODO:  在此添加控件通知处理程序代码
	m_channelstatue[47] = !m_channelstatue[47];
}
