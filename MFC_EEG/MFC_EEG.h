
// MFC_EEG.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_EEGApp: 
// �йش����ʵ�֣������ MFC_EEG.cpp
//

class CMFC_EEGApp : public CWinApp
{
public:
	CMFC_EEGApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_EEGApp theApp;