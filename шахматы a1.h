
// ������� a1.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// C�������a1App:
// � ���������� ������� ������ ��. ������� a1.cpp
//

class C�������a1App : public CWinApp
{
public:
	C�������a1App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern C�������a1App theApp;