
// CDCLab.h : CDCLab ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCDCLabApp:
// �� Ŭ������ ������ ���ؼ��� CDCLab.cpp�� �����Ͻʽÿ�.
//

class CCDCLabApp : public CWinApp
{
public:
	CCDCLabApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCDCLabApp theApp;
