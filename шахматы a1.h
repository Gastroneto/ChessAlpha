
// шахматы a1.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// Cшахматыa1App:
// О реализации данного класса см. шахматы a1.cpp
//

class Cшахматыa1App : public CWinApp
{
public:
	Cшахматыa1App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern Cшахматыa1App theApp;