
// шахматы a1Dlg.h : файл заголовка
//

#pragma once
#include "Draw_s.h"
#include "Any_acts.h"
#include "moves.h"
// диалоговое окно Cшахматыa1Dlg
class Cшахматыa1Dlg : public CDialogEx
{
// Создание
public:
	Cшахматыa1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint StartPoint;
	CPoint FinishPoint;
	bool is_taken=0;
	CStatic mybmp_wnd;
	CImage bitmap;
	square Square[8][8];//наше поле
	CDC *dc;
	int whos_turn; //чей ход
//переделать на сортировку по цветам.
	CPoint turns[27];//возможные ходы.
	afx_msg void OnBnClickedStartgame();
	afx_msg void OnBnClickedRestart();
};
