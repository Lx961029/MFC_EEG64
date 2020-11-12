#pragma once


// CChannel49_64 对话框
#include "MFC_EEGDlg.h"
class CChannel49To64 : public CDialogEx
{
	DECLARE_DYNAMIC(CChannel49To64)

public:
	CChannel49To64(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChannel49To64();

	int IsReDraw;
	int m_Xcoor;

	// 对话框数据
	enum { IDD = IDD_DIALOG49_64 };
	CBitmap MemBitMap;												//构造一个位图对象;MemDC将图绘制到该内存设备上,而pDC绘制在客户区;
	CDC MemDC;
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	

	

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	void DrawCurve(CDC &MemDC);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck16();
};
