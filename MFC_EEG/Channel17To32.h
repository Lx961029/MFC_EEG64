#pragma once


// CChannel17_32 �Ի���
#include "MFC_EEGDlg.h"
class CChannel17To32 : public CDialogEx
{
	DECLARE_DYNAMIC(CChannel17To32)

public:
	CChannel17To32(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChannel17To32();

	int IsReDraw;
	int m_Xcoor;

// �Ի�������
	enum { IDD = IDD_DIALOG17_32 };
	CBitmap MemBitMap;												//����һ��λͼ����;MemDC��ͼ���Ƶ����ڴ��豸��,��pDC�����ڿͻ���;
	CDC MemDC;
protected:
	HICON m_hIcon;
	
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//afx_msg void OnPaint();

	

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
